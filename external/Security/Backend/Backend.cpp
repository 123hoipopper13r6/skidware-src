#include "Backend.h"
#include "../xorstr.hpp"
#include "../Vms/VMProtectSDK.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <intrin.h>
#include <filesystem>

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#endif

#include <winsock2.h>
#include <Windows.h>
#include <shellapi.h>
#include <winhttp.h>
#include <bcrypt.h>
#include <wincrypt.h>
#include <iphlpapi.h>
#include <ws2tcpip.h>
#pragma comment(lib, "winhttp.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "bcrypt.lib")
#pragma comment(lib, "crypt32.lib")
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

namespace Backend::Utils
{
    // The API host is never stored as a contiguous plaintext string. It is
    // assembled at runtime from xored fragments just before each request, so
    // there is no single "host string" in .rdata / .data that can be found by
    // a string search and patched to point the client at a local/fake server.
    static std::wstring GetApiHost()
    {
        VMProtectBeginUltra(xorstr_("AuthResolve"));

        // Each fragment is copied into the std::wstring before the temporary
        // xor_string dies, so there is no dangling-pointer read (the previous
        // build returned a wstring built from a pointer into a dead temporary)
        // and no full plaintext host left lingering on the stack.
        std::wstring host;
        host.reserve(32);
        host += xorstr_(L"skidware-api");
        host += L'.';
        host += xorstr_(L"duckdns");
        host += L'.';
        host += xorstr_(L"org");

        VMProtectEnd();
        return host;
    }

    // GetAddrInfoW is a Winsock function and requires WSAStartup to have been
    // called, otherwise it fails (WSANOTINITIALISED). We initialize Winsock
    // once, safely.
    static void EnsureWinsockStarted()
    {
        static bool started = []()
        {
            WSADATA data;
            return WSAStartup(MAKEWORD(2, 2), &data) == 0;
        }();
        (void)started;
    }

    // Host-order IPv4 classification. Anything that can't be a real public API
    // endpoint is rejected: 0/8, 10/8, 100.64/10 (CGNAT), 127/8 (loopback),
    // 169.254/16 (link-local), 172.16/12, 192.168/16, 198.18/15 (benchmark),
    // 224/4 (multicast), 240/4 (reserved) and the limited broadcast.
    static bool IsNonRoutableV4(ULONG a)
    {
        ULONG o1 = (a >> 24) & 0xFF;
        ULONG o2 = (a >> 16) & 0xFF;
        return (o1 == 0 || o1 == 10 || o1 == 127 ||
            ((o1 == 169) && (o2 == 254)) ||
            ((o1 == 172) && (o2 >= 16 && o2 <= 31)) ||
            ((o1 == 192) && (o2 == 168)) ||
            ((o1 == 100) && (o2 >= 64 && o2 <= 127)) ||
            ((o1 == 198) && (o2 == 18 || o2 == 19)) ||
            a == 0xFFFFFFFFu || o1 >= 224);
    }

    // Reject any host that resolves (wholly or in part) to a non-public
    // address: loopback, link-local, private, CGNAT, ULA, multicast, reserved
    // and the IPv4-mapped forms of all of the above. The API is only reachable
    // through the public DuckDNS name -> the public VPS IP, so if ANY returned
    // address is non-public the request is refused. This stops hosts-file /
    // DNS-rebinding tricks that point "skidware-api.duckdns.org" at 127.0.0.1,
    // ::1, a 169.254.x link-local address, or a LAN fake server.
    static bool ResolvesToLocalOrLinkLocal(const std::wstring& host)
    {
        VMProtectBeginUltra(xorstr_("AuthResolve"));

        bool denied = false;
        EnsureWinsockStarted();

        ADDRINFOW hints = {};
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;

        ADDRINFOW* result = nullptr;

        // Fail open on lookup errors: a transient DNS failure must not itself
        // block legit auth - the real connection attempt fails and surfaces a
        // connect error on its own. We only refuse when we can positively
        // confirm the hostname resolved to a non-public address.
        if (GetAddrInfoW(host.c_str(), L"443", &hints, &result) == 0)
        {
            for (ADDRINFOW* p = result; p && !denied; p = p->ai_next)
            {
                if (p->ai_family == AF_INET)
                {
                    sockaddr_in* sa = (sockaddr_in*)p->ai_addr;
                    if (IsNonRoutableV4(ntohl(sa->sin_addr.S_un.S_addr)))
                        denied = true;
                }
                else if (p->ai_family == AF_INET6)
                {
                    sockaddr_in6* sa6 = (sockaddr_in6*)p->ai_addr;
                    const unsigned char* b = sa6->sin6_addr.u.Byte;
                    bool b0  = b[0] == 0, b1  = b[1] == 0, b2  = b[2] == 0, b3  = b[3] == 0;
                    bool b4  = b[4] == 0, b5  = b[5] == 0, b6  = b[6] == 0, b7  = b[7] == 0;
                    bool b8  = b[8] == 0, b9  = b[9] == 0, b10 = b[10] == 0, b11 = b[11] == 0;

                    // ::1 loopback
                    if (b0 && b1 && b2 && b3 && b4 && b5 && b6 && b7 &&
                        b8 && b9 && b10 && b11 &&
                        b[12] == 0 && b[13] == 0 && b[14] == 0 && b[15] == 1)
                    {
                        denied = true;
                    }
                    // fe80::/10 link-local and fec0::/10 site-local
                    else if (b[0] == 0xFE &&
                             ((b[1] & 0xC0) == 0x80 || (b[1] & 0xC0) == 0xC0))
                    {
                        denied = true;
                    }
                    // fc00::/7 unique-local
                    else if ((b[0] & 0xFE) == 0xFC)
                    {
                        denied = true;
                    }
                    // ff00::/8 multicast
                    else if (b[0] == 0xFF)
                    {
                        denied = true;
                    }
                    // All-zero prefix: ::/128 (unspecified) or the legacy
                    // ::v4-compatible forms - decode the last four bytes as a
                    // v4 address and run the v4 rules on them.
                    else if (b0 && b1 && b2 && b3 && b4 && b5 && b6 && b7 &&
                             b8 && b9 && b10 && b11)
                    {
                        ULONG v4 = ((ULONG)b[12] << 24) | ((ULONG)b[13] << 16) |
                                   ((ULONG)b[14] << 8) | (ULONG)b[15];
                        if (IsNonRoutableV4(v4)) denied = true;
                    }
                    // Any real global-unicast IPv6 address falls through and is
                    // accepted. (The DuckDNS record is an A name that only ever
                    // resolves to the public VPS IP, so this is future-proofing.)
                }
            }
            FreeAddrInfoW(result);
        }

        VMProtectEnd();
        return denied;
    }

    // Cheap extra anti-debug gate, separate from the AntiTamper watchdog so a
    // patched-out InitializeAntiTamper() can't silently restore a debuggable,
    // crackable client. Reads BeingDebugged straight off the PEB to avoid the
    // trivially-inlined IsDebuggerPresent import.
    static bool DebuggerAttached()
    {
#if defined(_M_X64) || defined(__x86_64__)
        return *reinterpret_cast<const BYTE*>(__readgsqword(0x60) + 0x02) != 0;
#else
        return *reinterpret_cast<const BYTE*>(__readfsdword(0x30) + 0x02) != 0;
#endif
    }

    HttpResponse HttpRequest(const std::wstring& method, const std::wstring& path, const std::string& body, const std::string& token)
    {
        VMProtectBeginUltra(xorstr_("AuthNet"));
        HttpResponse result;

        // Never talk to a host that didn't resolve to the real public API.
        std::wstring host = GetApiHost();
        if (host.empty() || ResolvesToLocalOrLinkLocal(host))
        {
            VMProtectEnd();
            return result;
        }

        // Extra hardening: refuse to complete any request while a debugger is
        // attached, even if the main AntiTamper watchdog was neutralized.
        if (DebuggerAttached())
        {
            VMProtectEnd();
            return result;
        }

        // Force a DIRECT connection (no system proxy): a local proxy (e.g.
        // Fiddler) must not be able to sit between the client and the API.
        HINTERNET hSession = WinHttpOpen(L"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36", WINHTTP_ACCESS_TYPE_NO_PROXY, NULL, NULL, 0);
        if (!hSession) { VMProtectEnd(); return result; }
        WinHttpSetTimeouts(hSession, 10000, 10000, 30000, 30000);

        HINTERNET hConnect = WinHttpConnect(hSession, host.c_str(), INTERNET_DEFAULT_HTTPS_PORT, 0);
        if (!hConnect) { WinHttpCloseHandle(hSession); VMProtectEnd(); return result; }

        HINTERNET hRequest = WinHttpOpenRequest(hConnect, method.c_str(), path.c_str(), NULL, NULL, NULL, WINHTTP_FLAG_SECURE);
        if (!hRequest) { WinHttpCloseHandle(hConnect); WinHttpCloseHandle(hSession); VMProtectEnd(); return result; }

        // Never follow HTTP redirects: a compromised middle-man could 3xx us
        // to a localhost endpoint. WinHTTP would otherwise chase it.
        DWORD redirectPolicy = WINHTTP_OPTION_REDIRECT_POLICY_NEVER;
        WinHttpSetOption(hRequest, WINHTTP_OPTION_REDIRECT_POLICY, &redirectPolicy, sizeof(redirectPolicy));

        // Keep strict TLS validation (no IGNORE_* security flags are set, so
        // the server cert must chain to a trusted root and match the hostname).
        WinHttpAddRequestHeaders(hRequest, L"Content-Type: application/json\r\n", -1, WINHTTP_ADDREQ_FLAG_ADD);
        WinHttpAddRequestHeaders(hRequest, L"Accept: application/json\r\n", -1, WINHTTP_ADDREQ_FLAG_ADD);
        if (!token.empty())
        {
            std::wstring auth = L"Authorization: Bearer " + std::wstring(token.begin(), token.end());
            WinHttpAddRequestHeaders(hRequest, auth.c_str(), -1, WINHTTP_ADDREQ_FLAG_ADD);
        }

        void* sendBuf = NULL;
        DWORD sendLen = 0;
        if (!body.empty())
        {
            sendLen = (DWORD)body.size();
            sendBuf = (void*)body.data();
        }

        if (!WinHttpSendRequest(hRequest, NULL, 0, sendBuf, sendLen, sendLen, 0))
        {
            WinHttpCloseHandle(hRequest); WinHttpCloseHandle(hConnect); WinHttpCloseHandle(hSession);
            VMProtectEnd();
            return result;
        }
        if (!WinHttpReceiveResponse(hRequest, NULL))
        {
            WinHttpCloseHandle(hRequest); WinHttpCloseHandle(hConnect); WinHttpCloseHandle(hSession);
            VMProtectEnd();
            return result;
        }

        DWORD statusCode = 0;
        DWORD statusLen = sizeof(statusCode);
        if (WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, NULL, &statusCode, &statusLen, NULL))
            result.status = (int)statusCode;

        DWORD size = 0;
        while (WinHttpQueryDataAvailable(hRequest, &size) && size > 0)
        {
            std::vector<char> buf(size);
            DWORD read = 0;
            if (WinHttpReadData(hRequest, buf.data(), size, &read))
                result.body.append(buf.data(), read);
        }

        WinHttpCloseHandle(hRequest); WinHttpCloseHandle(hConnect); WinHttpCloseHandle(hSession);
        VMProtectEnd();
        return result;
    }
}

namespace Backend::Hwid
{
    static std::string Sha256Hex(const std::string& input)
    {
        BCRYPT_ALG_HANDLE hAlg = NULL;
        BCRYPT_HASH_HANDLE hHash = NULL;
        std::string out;
        if (BCryptOpenAlgorithmProvider(&hAlg, BCRYPT_SHA256_ALGORITHM, NULL, 0) != 0) return out;
        if (BCryptCreateHash(hAlg, &hHash, NULL, 0, NULL, 0, 0) == 0)
        {
            BCryptHashData(hHash, (PUCHAR)input.data(), (ULONG)input.size(), 0);
            BYTE digest[32];
            if (BCryptFinishHash(hHash, digest, sizeof(digest), 0) == 0)
            {
                static const char* hex = "0123456789abcdef";
                for (int i = 0; i < 32; i++)
                {
                    out += hex[(digest[i] >> 4) & 0xF];
                    out += hex[digest[i] & 0xF];
                }
            }
            BCryptDestroyHash(hHash);
        }
        BCryptCloseAlgorithmProvider(hAlg, 0);
        return out;
    }

    static std::string GetRegistryValue(const char* subKey, const char* valueName)
    {
        std::string result;
        HKEY hKey = NULL;
        if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, subKey, 0, KEY_READ, &hKey) == ERROR_SUCCESS)
        {
            char buffer[512] = { 0 };
            DWORD bufferSize = sizeof(buffer);
            DWORD type = 0;
            if (RegQueryValueExA(hKey, valueName, NULL, &type, (LPBYTE)buffer, &bufferSize) == ERROR_SUCCESS)
                result = buffer;
            RegCloseKey(hKey);
        }
        return result;
    }

    static std::string GetVolumeSerial()
    {
        char buf[64] = { 0 };
        DWORD serial = 0;
        if (GetVolumeInformationA("C:\\", NULL, 0, &serial, NULL, NULL, NULL, 0))
            sprintf_s(buf, "%08X", serial);
        return buf;
    }

    static std::string GetCpuId()
    {
        std::string result;
        int regs[4] = { 0 };
        __cpuid(regs, 0);
        char brand[49] = { 0 };
        __cpuid(regs, 0x80000000);
        if (regs[0] >= 0x80000004)
        {
            int data[12] = { 0 };
            __cpuid(data + 0, 0x80000002);
            __cpuid(data + 4, 0x80000003);
            __cpuid(data + 8, 0x80000004);
            memcpy(brand, data, 48);
        }
        result = brand;
        return result;
    }

    static std::string GetMacAddress()
    {
        std::string result;
        ULONG size = 0;
        if (GetAdaptersInfo(NULL, &size) == ERROR_BUFFER_OVERFLOW && size > 0)
        {
            std::vector<BYTE> buf(size);
            if (GetAdaptersInfo((PIP_ADAPTER_INFO)buf.data(), &size) == NO_ERROR)
            {
                for (PIP_ADAPTER_INFO it = (PIP_ADAPTER_INFO)buf.data(); it; it = it->Next)
                {
                    if (it->Type == MIB_IF_TYPE_ETHERNET && it->AddressLength == 6)
                    {
                        char mac[32] = { 0 };
                        sprintf_s(mac, "%02X%02X%02X%02X%02X%02X",
                            it->Address[0], it->Address[1], it->Address[2],
                            it->Address[3], it->Address[4], it->Address[5]);
                        result = mac;
                        break;
                    }
                }
            }
        }
        return result;
    }

    std::string Get()
    {
        VMProtectBeginUltra(xorstr_("HWID"));

        std::string machineGuid = GetRegistryValue("SOFTWARE\\Microsoft\\Cryptography", "MachineGuid");
        std::string volSerial = GetVolumeSerial();
        std::string cpuId = GetCpuId();
        std::string mac = GetMacAddress();

        std::string fingerprint = "skidware-hwid|" + machineGuid + "|" + volSerial + "|" + cpuId + "|" + mac;
        std::string hash = Sha256Hex(fingerprint);
        VMProtectEnd();
        if (hash.empty())
            return "UNKNOWN-HWID";
        return "SKID-" + hash.substr(0, 48);
    }
}

namespace Backend::Auth
{
    static const std::string kAuthFile = "C:\\Skidware\\auth.bin";

    // Forward declarations (used by Login before their definition).
    static bool ReportHwid(const std::string& token, std::string& errorMessage);
    static void Logout();

    Session& Current()
    {
        static Session session;
        return session;
    }

    // Simple DPAPI-protected token storage so the token is not plaintext on disk.
    static bool SaveTokenFile(const Session& s)
    {
        try
        {
            std::string plain = s.token + "\n" + s.email + "\n" + s.username;
            DATA_BLOB in = { (DWORD)plain.size(), (BYTE*)plain.data() };
            DATA_BLOB out = { 0, NULL };
            if (!CryptProtectData(&in, L"skidware-session", NULL, NULL, NULL, CRYPTPROTECT_LOCAL_MACHINE, &out))
                return false;
            std::ofstream file(kAuthFile, std::ios::binary);
            if (!file.is_open()) { LocalFree(out.pbData); return false; }
            file.write((const char*)out.pbData, out.cbData);
            file.close();
            LocalFree(out.pbData);
            return true;
        }
        catch (...) { return false; }
    }

    static bool LoadTokenFile(Session& s)
    {
        try
        {
            std::ifstream file(kAuthFile, std::ios::binary);
            if (!file.is_open()) return false;
            std::string encrypted((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            file.close();
            if (encrypted.empty()) return false;

            DATA_BLOB in = { (DWORD)encrypted.size(), (BYTE*)encrypted.data() };
            DATA_BLOB out = { 0, NULL };
            if (!CryptUnprotectData(&in, NULL, NULL, NULL, NULL, CRYPTPROTECT_LOCAL_MACHINE, &out))
                return false;

            std::string plain((const char*)out.pbData, out.cbData);
            LocalFree(out.pbData);

            size_t nl1 = plain.find('\n');
            size_t nl2 = plain.find('\n', nl1 + 1);
            if (nl1 == std::string::npos || nl2 == std::string::npos) return false;
            s.token = plain.substr(0, nl1);
            s.email = plain.substr(nl1 + 1, nl2 - nl1 - 1);
            s.username = plain.substr(nl2 + 1);
            return !s.token.empty();
        }
        catch (...) { return false; }
    }

    static std::string ExtractString(const std::string& json, const std::string& key)
    {
        std::string needle = "\"" + key + "\":\"";
        size_t pos = json.find(needle);
        if (pos == std::string::npos) return "";
        pos += needle.size();
        size_t end = json.find('"', pos);
        if (end == std::string::npos) return "";
        return json.substr(pos, end - pos);
    }

    static bool JsonHasTrue(const std::string& json, const std::string& key)
    {
        return json.find("\"" + key + "\":true") != std::string::npos;
    }

    // Escape a string for embedding in a JSON body so credentials containing
    // quotes / backslashes / control chars still produce valid JSON (the server
    // sanitizes them, but the wire format must first parse).
    static std::string JsonEscape(const std::string& in)
    {
        std::string out;
        out.reserve(in.size() + 8);
        for (char c : in)
        {
            switch (c)
            {
            case '"': out += "\\\""; break;
            case '\\': out += "\\\\"; break;
            case '\n': out += "\\n"; break;
            case '\r': out += "\\r"; break;
            case '\t': out += "\\t"; break;
            default:
                if ((unsigned char)c < 0x20)
                {
                    char buf[8];
                    sprintf_s(buf, "\\u%04x", (unsigned char)c);
                    out += buf;
                }
                else
                {
                    out += c;
                }
            }
        }
        return out;
    }

    // The oauth state is embedded in the Discord authorize URL as
    // "...&state=login%3A<hex>". If the server didn't return a top-level
    // "state" field (older API builds), recover it from the URL so the client
    // can poll for the matching flow.
    static std::string ExtractStateFromUrl(const std::string& url)
    {
        const std::string marker = "state=";
        size_t pos = url.find(marker);
        if (pos == std::string::npos) return "";
        pos += marker.size();
        size_t end = url.find('&', pos);
        if (end == std::string::npos) end = url.size();
        std::string raw = url.substr(pos, end - pos);

        // The state is "mode:<hex>" URL-encoded, i.e. "login%3A<hex>".
        // Strip any URL percent-encoding and the "mode:" prefix.
        std::string decoded;
        for (size_t i = 0; i < raw.size(); ++i)
        {
            if (raw[i] == '%' && i + 2 < raw.size())
            {
                auto hexVal = [](char c) -> int {
                    if (c >= '0' && c <= '9') return c - '0';
                    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
                    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
                    return -1;
                };
                int hi = hexVal(raw[i + 1]);
                int lo = hexVal(raw[i + 2]);
                if (hi >= 0 && lo >= 0) { decoded += (char)((hi << 4) | lo); i += 2; continue; }
            }
            decoded += raw[i];
        }

        size_t colon = decoded.find(':');
        if (colon != std::string::npos) return decoded.substr(colon + 1);
        return decoded;
    }

    static bool ReportHwid(const std::string& token, std::string& errorMessage)
    {
        std::string hwid = Backend::Hwid::Get();
        std::string body = "{\"hwid\":\"" + hwid + "\"}";
        HttpResponse resp = Backend::Utils::Post(L"/api/hwid/receive", body, token);
        if (resp.status == 200)
        {
            Current().hwid = hwid;
            return true;
        }
        if (resp.status == 403)
            errorMessage = "HWID mismatch: this account is bound to another device. Reset your HWID on the website and try again.";
        else
            errorMessage = "Failed to register HWID (HTTP " + std::to_string(resp.status) + ")";
        return false;
    }

    bool Login(const std::string& email, const std::string& password, std::string& errorMessage)
    {
        VMProtectBeginUltra(xorstr_("AuthLogin"));

        errorMessage.clear();
        if (email.empty() || password.empty())
        {
            errorMessage = "Enter your email and password";
            VMProtectEnd();
            return false;
        }

        std::string body = "{\"email\":\"" + JsonEscape(email) + "\",\"password\":\"" + JsonEscape(password) + "\"}";
        HttpResponse resp = Backend::Utils::Post(L"/api/login", body);
        if (resp.status == 200) 
        {
            std::string token = ExtractString(resp.body, "token");
            std::string username = ExtractString(resp.body, "username");
            std::string role = ExtractString(resp.body, "role");
            if (token.empty())
            {
                errorMessage = "Invalid server response";
                VMProtectEnd();
                return false;
            }

            Session& s = Current();
            s.token = token;
            s.email = email;
            s.username = username.empty() ? email.substr(0, email.find('@')) : username;
            s.role = role;

            std::string hwidError;
            if (!ReportHwid(token, hwidError))
            {
                errorMessage = hwidError;
                Logout();
                VMProtectEnd();
                return false;
            }

            s.hwid = Backend::Hwid::Get();
            s.authenticated = true;
            SaveTokenFile(s);
            VMProtectEnd();
            return true;
        }

        if (resp.status == 0)
        {
            errorMessage = "Failed to connect to authentication server";
        }
        else if (resp.status == 401 || resp.status == 400)
        {
            std::string apiError = ExtractString(resp.body, "error");
            errorMessage = !apiError.empty() ? apiError : "Invalid email or password";
        }
        else if (resp.status == 403)
        {
            std::string apiError = ExtractString(resp.body, "error");
            errorMessage = !apiError.empty() ? apiError : "Access forbidden";
        }
        else if (resp.status == 404)
        {
            errorMessage = "API endpoint not found (404)";
        }
        else if (resp.status == 429)
        {
            errorMessage = "Too many login attempts. Please wait.";
        }
        else if (resp.status >= 500)
        {
            errorMessage = "Server error (" + std::to_string(resp.status) + "). Try again later.";
        }
        else
        {
            errorMessage = "Unexpected error (HTTP " + std::to_string(resp.status) + ")";
        }

        VMProtectEnd();
        return false;
    }

    bool LoginWithDiscord(std::string& errorMessage)
    {
        VMProtectBeginUltra(xorstr_("AuthDiscord"));

        errorMessage.clear();

        HttpResponse start = Backend::Utils::Get(L"/api/discord/start?mode=login&poll=1");
        if (start.status == 0)
        {
            errorMessage = "Failed to connect to authentication server";
            VMProtectEnd();
            return false;
        }
        if (start.status != 200)
        {
            std::string apiError = ExtractString(start.body, "error");
            errorMessage = !apiError.empty() ? apiError : "Discord login unavailable";
            VMProtectEnd();
            return false;
        }

        std::string url = ExtractString(start.body, "url");
        std::string state = ExtractString(start.body, "state");
        if (state.empty())
            state = ExtractStateFromUrl(url);
        if (url.empty() || state.empty())
        {
            errorMessage = "Invalid server response";
            VMProtectEnd();
            return false;
        }

        // Open the authorization page in the user's default browser.
        std::wstring wurl(url.begin(), url.end());
        HINSTANCE opened = ShellExecuteW(NULL, L"open", wurl.c_str(), NULL, NULL, SW_SHOWNORMAL);
        if ((INT_PTR)opened <= 32)
        {
            errorMessage = "Failed to open browser";
            VMProtectEnd();
            return false;
        }

        // Poll until the browser flow completes (up to ~3 minutes).
        std::wstring wstate(L"/api/discord/poll?state=");
        wstate.append(state.begin(), state.end());

        for (int attempt = 0; attempt < 90; ++attempt)
        {
            Sleep(2000);

            HttpResponse poll = Backend::Utils::Get(wstate);
            if (poll.status == 0)
                continue; // transient network issue - keep polling

            if (JsonHasTrue(poll.body, "pending"))
                continue; // user hasn't finished authorizing yet

            std::string token = ExtractString(poll.body, "token");
            if (poll.status == 200 && !token.empty())
            {
                Session& s = Current();
                s.token = token;
                s.email = "discord";
                s.username = "Discord Account";

                std::string hwidError;
                if (!ReportHwid(token, hwidError))
                {
                    errorMessage = hwidError;
                    Logout();
                    VMProtectEnd();
                    return false;
                }

                // Refresh the profile for a more accurate display name.
                HttpResponse me = Backend::Utils::Get(L"/api/me", token);
                if (me.status == 200)
                {
                    std::string username = ExtractString(me.body, "username");
                    if (!username.empty()) s.username = username;
                    s.role = ExtractString(me.body, "role");
                }

                s.hwid = Backend::Hwid::Get();
                s.authenticated = true;
                SaveTokenFile(s);
                VMProtectEnd();
                return true;
            }

            std::string apiError = ExtractString(poll.body, "error");
            if (!apiError.empty())
            {
                errorMessage = apiError;
                VMProtectEnd();
                return false;
            }
        }

        errorMessage = "Discord authorization timed out";
        VMProtectEnd();
        return false;
    }

    bool Validate()
    {
        VMProtectBeginUltra(xorstr_("AuthValidate"));

        Session& s = Current();
        bool ok = false;

        if (s.authenticated && !s.token.empty())
        {
            HttpResponse resp = Backend::Utils::Get(L"/api/me", s.token);
            if (resp.status == 200)
            {
                std::string username = ExtractString(resp.body, "username");
                if (!username.empty()) s.username = username;
                std::string hwidError;
                if (!ReportHwid(s.token, hwidError))
                {
                    Logout();
                    ok = false;
                }
                else
                {
                    s.authenticated = true;
                    ok = true;
                }
            }
            else
            {
                Logout();
                ok = false;
            }
        }
        else if (LoadTokenFile(s))
        {
            HttpResponse resp = Backend::Utils::Get(L"/api/me", s.token);
            if (resp.status == 200)
            {
                std::string username = ExtractString(resp.body, "username");
                if (!username.empty()) s.username = username;
                std::string hwidError;
                if (!ReportHwid(s.token, hwidError))
                {
                    Logout();
                    ok = false;
                }
                else
                {
                    s.authenticated = true;
                    ok = true;
                }
            }
            else
            {
                Logout();
                ok = false;
            }
        }
        else
        {
            ok = false;
        }

        VMProtectEnd();
        return ok;
    }

    void Logout()
    {
        Session& s = Current();
        if (!s.token.empty())
        {
            HttpResponse resp = Backend::Utils::Post(L"/api/logout", "", s.token);
            (void)resp;
        }
        s = Session();
        try { std::filesystem::remove(kAuthFile); } catch (...) {}
    }
}
