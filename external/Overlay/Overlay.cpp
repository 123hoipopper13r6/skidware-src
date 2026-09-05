#include "Overlay.hpp"
#include "../Includes.hpp"
#include <dwmapi.h>
#include <WinHttp.h>
#pragma comment(lib, "winhttp.lib")
#pragma comment(lib, "version.lib")
#include "ImGui/imgui_freetype.h"

// was in the removed OffsetsUpdater - read the client version straight from the
// running Roblox binary instead
static std::string GetRobloxVersion()
{
	std::string result = "unknown";
	if (!SDK::Memory || !SDK::Memory->Handle)
		return result;
	char path[MAX_PATH]{};
	if (!GetModuleFileNameExA(SDK::Memory->Handle, nullptr, path, MAX_PATH))
		return result;
	DWORD handle = 0;
	const DWORD size = GetFileVersionInfoSizeA(path, &handle);
	if (!size)
		return result;
	std::vector<char> block(size);
	if (!GetFileVersionInfoA(path, 0, size, block.data()))
		return result;
	VS_FIXEDFILEINFO* ffi = nullptr;
	UINT len = 0;
	if (VerQueryValueA(block.data(), "\\", (void**)&ffi, &len) && ffi) {
		char buf[64];
		sprintf_s(buf, "%u.%u.%u.%u",
			HIWORD(ffi->dwFileVersionMS), LOWORD(ffi->dwFileVersionMS),
			HIWORD(ffi->dwFileVersionLS), LOWORD(ffi->dwFileVersionLS));
		result = buf;
	}
	return result;
}
#include "Fonts/smallestpixel.h"

static ImColor PreviewTeamColor(float* fallback) {
    if (Globals::Esp::Team && Globals::Esp::TeamMode >= 1 && SDK::Cache::LocalPlayer.TeamColor.Value.w > 0.f) {
        ImColor tc = SDK::Cache::LocalPlayer.TeamColor;
        return ImColor(tc.Value.x, tc.Value.y, tc.Value.z, fallback[3]);
    }
    return ImColor(fallback[0], fallback[1], fallback[2], fallback[3]);
}
#include "Fonts/visitor1.h"
#include "Fonts/LatoBold.h"
#include "Json.hpp"
#include "../Hacks/Aimbot/hitsounds.h"
#include "Images/BladeeRaw.h"
#include "Avatar3D.hpp"
#include "PreviewRenderer.hpp"
#include "preview_model_obj.h"
#include "preview_model_texture.h"
#include <fstream>
#include <filesystem>
#include "Fonts/Icons/IconsFontAwesome6.h"
#include "Fonts/Icons/IconsFontAwesome6_Bytes.h"
#include "cfg.hpp"
#ifndef SKIDWARE_BUILD_TAG
#define SKIDWARE_BUILD_TAG "Dev"
#endif
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace Overlay
{
    inline ID3D11Device* g_pd3dDevice = nullptr;
    inline ID3D11DeviceContext* g_pd3dDeviceContext = nullptr;
    inline IDXGISwapChain* g_pSwapChain = nullptr;
    inline bool                     g_SwapChainOccluded = false;
    inline UINT                     g_ResizeWidth = 0, g_ResizeHeight = 0;
    inline ID3D11RenderTargetView* g_mainRenderTargetView = nullptr;
    inline bool g_MenuOpen = false;
    static bool g_NeedsReposition = false;
    void CreateRenderTarget()
    {
        ID3D11Texture2D* pBackBuffer;
        g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
        g_pd3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, &g_mainRenderTargetView);
        pBackBuffer->Release();
    }
    bool CreateDeviceD3D(HWND hWnd)
    {

        DXGI_SWAP_CHAIN_DESC sd;
        ZeroMemory(&sd, sizeof(sd));
        sd.BufferCount = 2;
        sd.BufferDesc.Width = 0;
        sd.BufferDesc.Height = 0;
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.BufferDesc.RefreshRate.Numerator = 60;
        sd.BufferDesc.RefreshRate.Denominator = 1;
        sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
        sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.OutputWindow = hWnd;
        sd.SampleDesc.Count = 1;
        sd.SampleDesc.Quality = 0;
        sd.Windowed = TRUE;
        sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

        UINT createDeviceFlags = 0;

        D3D_FEATURE_LEVEL featureLevel;
        const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
        HRESULT res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext);
        if (res == DXGI_ERROR_UNSUPPORTED)
            res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext);
        if (res != S_OK)
            return false;

        CreateRenderTarget();
        return true;
    }
    void CleanupRenderTarget()
    {
        if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = nullptr; }
    }
    void CleanupDeviceD3D()
    {
        CleanupRenderTarget();
        if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = nullptr; }
        if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = nullptr; }
        if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = nullptr; }
    }

    // Makes a NoTitleBar panel draggable via its header band (leaving the
    // right side free for the close button). Must be called right after Begin.
    static void DragHeader(const char* id, float headerHeight = 25.0f)
    {
        ImGui::SetCursorPos({ 0, 0 });
        ImGui::InvisibleButton(id, { ImGui::GetWindowSize().x - 30.0f, headerHeight });
        if (ImGui::IsItemActive() && ImGui::IsMouseDragging(ImGuiMouseButton_Left))
            ImGui::SetWindowPos(ImGui::GetWindowPos() + ImGui::GetIO().MouseDelta);
        ImGui::SetCursorPos({ 0, 0 });
    }




    
    // ImGui buttons function


    LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
            return true;

        switch (msg)
        {
        case WM_NCHITTEST:
        {
            // While the loader is up the HWND is sized to exactly the loader
            // box (see the main loop), so the whole window is the loader and
            // every click on it belongs to the UI. Clicks outside the window
            // never reach us in the first place - they hit whatever is below.
            if (!Globals::LoaderAttached)
                return HTCLIENT;
            // After attach, only swallow input when hovering one of the ImGui
            // panels (menu open); everywhere else let clicks fall through to
            // the game so it never gets blocked by the invisible overlay.
            if (g_MenuOpen)
            {
                ImGuiContext* ctx = ImGui::GetCurrentContext();
                if (ctx)
                {
                    POINT pt = { (LONG)(short)LOWORD(lParam), (LONG)(short)HIWORD(lParam) };
                    ScreenToClient(hWnd, &pt);
                    const ImVec2 m((float)pt.x, (float)pt.y);
                    for (int i = 0; i < ctx->Windows.Size; ++i)
                    {
                        const ImGuiWindow* w = ctx->Windows[i];
                        if (w && w->Active && !(w->Flags & ImGuiWindowFlags_NoMouseInputs))
                        {
                            if (m.x >= w->Pos.x && m.x <= w->Pos.x + w->Size.x &&
                                m.y >= w->Pos.y && m.y <= w->Pos.y + w->Size.y)
                                return HTCLIENT;
                        }
                    }
                }
                return HTTRANSPARENT;
            }
            return HTTRANSPARENT;
        }
        case WM_SIZE:
            if (wParam == SIZE_MINIMIZED)
                return 0;
            g_ResizeWidth = (UINT)LOWORD(lParam);
            g_ResizeHeight = (UINT)HIWORD(lParam);
            return 0;
        case WM_SYSCOMMAND:
            if ((wParam & 0xfff0) == SC_KEYMENU)
                return 0;
            break;
        case WM_DESTROY:
            ::PostQuitMessage(0);
            return 0;
        }
        return ::DefWindowProcW(hWnd, msg, wParam, lParam);
    }
    bool full_screen(HWND windowHandle)
    {
        MONITORINFO monitorInfo = { sizeof(MONITORINFO) };
        if (GetMonitorInfo(MonitorFromWindow(windowHandle, MONITOR_DEFAULTTOPRIMARY), &monitorInfo))
        {
            RECT windowRect;
            if (GetWindowRect(windowHandle, &windowRect))
            {
                return windowRect.left == monitorInfo.rcMonitor.left
                    && windowRect.right == monitorInfo.rcMonitor.right
                    && windowRect.top == monitorInfo.rcMonitor.top
                    && windowRect.bottom == monitorInfo.rcMonitor.bottom;
            }
        }
    }


    void move_window(HWND hw)
    {
        HWND target = Globals::RobloxWindow;
        HWND foregroundWindow = GetForegroundWindow();

        if (target != foregroundWindow && hw != foregroundWindow)
        {
            MoveWindow(hw, 0, 0, 0, 0, true);
            return;
        }

        RECT rect;
        if (!GetWindowRect(target, &rect))
        {
            std::cout << "[Athena]  GetWindowRect() Failed." << std::endl;
            return;
        }

        int rsize_x = rect.right - rect.left - 17;
        int rsize_y = rect.bottom - rect.top;

        if (full_screen(target))
        {
            rsize_x += 16;
        }
        else
        {
            rsize_y -= 39;
            rect.left += 4 + 5;
            rect.top += 31;
        }

        if (!MoveWindow(hw, rect.left, rect.top, rsize_x, rsize_y, TRUE))
        {
            std::cout << "[Athena]  Could not move window." << std::endl;
        }


    }

    ID3D11ShaderResourceView* g_AvatarPreviewTex = nullptr;
    std::string g_AvatarPreviewError = "";
    bool g_AvatarPreviewLoading = false;
    int64_t g_AvatarPreviewUserId = 0;
    Hacks::Preview::PreviewRenderer g_avatarPreview;
    ID3D11ShaderResourceView* CreateTextureFromRGBA(unsigned char* data, int w, int h)
    {
        if (!data || w <= 0 || h <= 0) return nullptr;
        D3D11_TEXTURE2D_DESC desc = {};
        desc.Width = w;
        desc.Height = h;
        desc.MipLevels = 1;
        desc.ArraySize = 1;
        desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        desc.SampleDesc.Count = 1;
        desc.Usage = D3D11_USAGE_DEFAULT;
        desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
        desc.CPUAccessFlags = 0;
        D3D11_SUBRESOURCE_DATA initData = {};
        initData.pSysMem = data;
        initData.SysMemPitch = w * 4;
        ID3D11Texture2D* tex = nullptr;
        ID3D11ShaderResourceView* srv = nullptr;
        if (SUCCEEDED(g_pd3dDevice->CreateTexture2D(&desc, &initData, &tex))) {
            g_pd3dDevice->CreateShaderResourceView(tex, nullptr, &srv);
            if (tex) tex->Release();
        }
        return srv;
    }
    std::string HttpGet(const std::wstring& host, const std::wstring& path, bool secure = true)
    {
        std::string result;
        HINTERNET hSession = WinHttpOpen(L"Skidware/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, NULL, NULL, 0);
        if (!hSession) return result;
        WinHttpSetTimeouts(hSession, 5000, 5000, 10000, 10000);
        HINTERNET hConnect = WinHttpConnect(hSession, host.c_str(), secure ? INTERNET_DEFAULT_HTTPS_PORT : INTERNET_DEFAULT_HTTP_PORT, 0);
        if (hConnect) {
            HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"GET", path.c_str(), NULL, NULL, NULL, secure ? WINHTTP_FLAG_SECURE : 0);
            if (hRequest) {
                if (WinHttpSendRequest(hRequest, NULL, 0, NULL, 0, 0, 0)) {
                    if (WinHttpReceiveResponse(hRequest, NULL)) {
                        DWORD size = 0;
                        while (WinHttpQueryDataAvailable(hRequest, &size) && size > 0) {
                            std::vector<char> buf(size);
                            DWORD read = 0;
                            if (WinHttpReadData(hRequest, buf.data(), size, &read)) {
                                result.append(buf.data(), read);
                            }
                        }
                    }
                }
                WinHttpCloseHandle(hRequest);
            }
            WinHttpCloseHandle(hConnect);
        }
        WinHttpCloseHandle(hSession);
        return result;
    }
    void FetchAvatarPreview(int64_t userId)
    {
        if (g_AvatarPreviewLoading) return;
        if (userId <= 0) { g_AvatarPreviewError = "Invalid UserId"; return; }
        g_AvatarPreviewLoading = true;
        g_AvatarPreviewError = "";
        if (g_AvatarPreviewTex) { g_AvatarPreviewTex->Release(); g_AvatarPreviewTex = nullptr; }
        std::string json = HttpGet(L"thumbnails.roblox.com", L"/v1/users/avatar?userIds=" + std::to_wstring(userId) + L"&size=420x420&format=Png&isCircular=false");
        if (json.empty()) { g_AvatarPreviewError = "Failed to contact thumbnail API"; g_AvatarPreviewLoading = false; return; }
        try {
            auto j = nlohmann::json::parse(json);
            auto& data = j["data"];
            if (data.is_array() && !data.empty()) {
                std::string imageUrl = data[0]["imageUrl"];
                if (imageUrl.empty()) { g_AvatarPreviewError = "No image URL in response"; g_AvatarPreviewLoading = false; return; }
                size_t pos = imageUrl.find("://");
                std::wstring rest = std::wstring(imageUrl.begin() + (pos + 3), imageUrl.end());
                size_t slash = rest.find(L'/');
                std::wstring imgHost = rest.substr(0, slash);
                std::wstring imgPath = rest.substr(slash);
                std::string imgData = HttpGet(imgHost, imgPath, imgHost.find(L".roblox.com") != std::wstring::npos);
                if (imgData.empty()) { g_AvatarPreviewError = "Failed to download image"; g_AvatarPreviewLoading = false; return; }
                int w, h, ch;
                unsigned char* pixels = stbi_load_from_memory((unsigned char*)imgData.data(), (int)imgData.size(), &w, &h, &ch, 4);
                if (!pixels) { g_AvatarPreviewError = std::string("stbi failed: ") + (stbi_failure_reason() ? stbi_failure_reason() : "unknown"); g_AvatarPreviewLoading = false; return; }
                g_AvatarPreviewTex = CreateTextureFromRGBA(pixels, w, h);
                stbi_image_free(pixels);
                if (!g_AvatarPreviewTex) { g_AvatarPreviewError = "Failed to create texture"; }
                else { g_AvatarPreviewUserId = userId; g_AvatarPreviewError = ""; }
            } else {
                g_AvatarPreviewError = "No avatar data available";
            }
        } catch (const std::exception& e) {
            g_AvatarPreviewError = std::string("JSON parse: ") + e.what();
        }
        g_AvatarPreviewLoading = false;
    }
}
static const char* KeyNames[] = {
    "OFF",
    "LBUTTON",
    "RBUTTON",
    "CANCEL",
    "MBUTTON",
    "XBUTTON1",
    "XBUTTON2",
    "Unknown",
    "BACK",
    "TAB",
    "Unknown",
    "Unknown",
    "CLEAR",
    "RETURN",
    "Unknown",
    "Unknown",
    "SHIFT",
    "CONTROL",
    "MENU",
    "PAUSE",
    "CAPITAL",
    "KANA",
    "Unknown",
    "JUNJA",
    "FINAL",
    "KANJI",
    "Unknown",
    "ESCAPE",
    "CONVERT",
    "NONCONVERT",
    "ACCEPT",
    "MODECHANGE",
    "SPACE",
    "PRIOR",
    "NEXT",
    "END",
    "HOME",
    "LEFT",
    "UP",
    "RIGHT",
    "DOWN",
    "SELECT",
    "PRINT",
    "EXECUTE",
    "SNAPSHOT",
    "INSERT",
    "DELETE",
    "HELP",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "LWIN",
    "RWIN",
    "APPS",
    "Unknown",
    "SLEEP",
    "NUMPAD0",
    "NUMPAD1",
    "NUMPAD2",
    "NUMPAD3",
    "NUMPAD4",
    "NUMPAD5",
    "NUMPAD6",
    "NUMPAD7",
    "NUMPAD8",
    "NUMPAD9",
    "MULTIPLY",
    "ADD",
    "SEPARATOR",
    "SUBTRACT",
    "DECIMAL",
    "DIVIDE",
    "F1",
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "F11",
    "F12",
    "F13",
    "F14",
    "F15",
    "F16",
    "F17",
    "F18",
    "F19",
    "F20",
    "F21",
    "F22",
    "F23",
    "F24",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "NUMLOCK",
    "SCROLL",
    "OEM_NEC_EQUAL",
    "OEM_FJ_MASSHOU",
    "OEM_FJ_TOUROKU",
    "OEM_FJ_LOYA",
    "OEM_FJ_ROYA",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "LSHIFT",
    "RSHIFT",
    "LCONTROL",
    "RCONTROL",
    "LMENU",
    "RMENU"
};
static const int KeyCodes[] = {
    0x0,  //Undefined
    0x01,
    0x02,
    0x03,
    0x04,
    0x05,
    0x06,
    0x07, //Undefined
    0x08,
    0x09,
    0x0A, //Reserved
    0x0B, //Reserved
    0x0C,
    0x0D,
    0x0E, //Undefined
    0x0F, //Undefined
    0x10,
    0x11,
    0x12,
    0x13,
    0x14,
    0x15,
    0x16, //IME On
    0x17,
    0x18,
    0x19,
    0x1A, //IME Off
    0x1B,
    0x1C,
    0x1D,
    0x1E,
    0x1F,
    0x20,
    0x21,
    0x22,
    0x23,
    0x24,
    0x25,
    0x26,
    0x27,
    0x28,
    0x29,
    0x2A,
    0x2B,
    0x2C,
    0x2D,
    0x2E,
    0x2F,
    0x30,
    0x31,
    0x32,
    0x33,
    0x34,
    0x35,
    0x36,
    0x37,
    0x38,
    0x39,
    0x3A, //Undefined
    0x3B, //Undefined
    0x3C, //Undefined
    0x3D, //Undefined
    0x3E, //Undefined
    0x3F, //Undefined
    0x40, //Undefined
    0x41,
    0x42,
    0x43,
    0x44,
    0x45,
    0x46,
    0x47,
    0x48,
    0x49,
    0x4A,
    0x4B,
    0x4C,
    0x4B,
    0x4E,
    0x4F,
    0x50,
    0x51,
    0x52,
    0x53,
    0x54,
    0x55,
    0x56,
    0x57,
    0x58,
    0x59,
    0x5A,
    0x5B,
    0x5C,
    0x5D,
    0x5E, //Rservered
    0x5F,
    0x60, //Numpad1
    0x61, //Numpad2
    0x62, //Numpad3
    0x63, //Numpad4
    0x64, //Numpad5
    0x65, //Numpad6
    0x66, //Numpad7
    0x67, //Numpad8
    0x68, //Numpad8
    0x69, //Numpad9
    0x6A,
    0x6B,
    0x6C,
    0x6D,
    0x6E,
    0x6F,
    0x70, //F1
    0x71, //F2
    0x72, //F3
    0x73, //F4
    0x74, //F5
    0x75, //F6
    0x76, //F7
    0x77, //F8
    0x78, //F9
    0x79, //F10
    0x7A, //F11
    0x7B, //F12
    0x7C, //F13
    0x7D, //F14
    0x7E, //F15
    0x7F, //F16
    0x80, //F17
    0x81, //F18
    0x82, //F19
    0x83, //F20
    0x84, //F21
    0x85, //F22
    0x86, //F23
    0x87, //F24
    0x88, //Unkown
    0x89, //Unkown
    0x8A, //Unkown
    0x8B, //Unkown
    0x8C, //Unkown
    0x8D, //Unkown
    0x8E, //Unkown
    0x8F, //Unkown
    0x90,
    0x91,
    0x92, //OEM Specific
    0x93, //OEM Specific
    0x94, //OEM Specific
    0x95, //OEM Specific
    0x96, //OEM Specific
    0x97, //Unkown
    0x98, //Unkown
    0x99, //Unkown
    0x9A, //Unkown
    0x9B, //Unkown
    0x9C, //Unkown
    0x9D, //Unkown
    0x9E, //Unkown 
    0x9F, //Unkown
    0xA0,
    0xA1,
    0xA2,
    0xA3,
    0xA4,
    0xA5
};

#include <map>

void Hotkey(int* k, const ImVec2& size_arg = ImVec2(0, 0), int id = 0)
{
    // Use a unique static variable for each hotkey instance
    static std::map<int, bool> waitingForKeyMap;

    // Initialize if not present
    if (waitingForKeyMap.find(id) == waitingForKeyMap.end()) {
        waitingForKeyMap[id] = false;
    }

    bool& waitingforkey = waitingForKeyMap[id];

    if (!waitingforkey) {
        std::string txt = std::string(KeyNames[*k]) + "##" + std::to_string(id);
        ImVec4 windowBgColor = ImGui::GetStyleColorVec4(ImGuiCol_WindowBg);

        // Darken the base color a bit for the button's border and background
        ImVec4 darker;
        darker.x = (windowBgColor.x - 0.04f < 0.0f) ? 0.0f : windowBgColor.x - 0.04f;
        darker.y = (windowBgColor.y - 0.04f < 0.0f) ? 0.0f : windowBgColor.y - 0.04f;
        darker.z = (windowBgColor.z - 0.04f < 0.0f) ? 0.0f : windowBgColor.z - 0.04f;
        darker.w = windowBgColor.w;

        // Using the original and darkened colors for button
        ImVec4 borderColor = darker;  // Using darker color for the border
        ImVec4 backgroundColor = windowBgColor;
        ImGui::PushStyleColor(ImGuiCol_Border, ImColor(12, 12, 12).Value);// Using the base color for the button's background
        if (ImGui::Button(txt.c_str(), size_arg))
        {
            waitingforkey = true;
        }
        ImGui::PopStyleColor();
    }
    else {
        std::string txt = "...##" + std::to_string(id);
        // Get base color from ImGui style (WindowBg)
        ImVec4 windowBgColor = ImGui::GetStyleColorVec4(ImGuiCol_WindowBg);

        // Darken the base color a bit for the button's border and background
        ImVec4 darker;
        darker.x = (windowBgColor.x - 0.04f < 0.0f) ? 0.0f : windowBgColor.x - 0.04f;
        darker.y = (windowBgColor.y - 0.04f < 0.0f) ? 0.0f : windowBgColor.y - 0.04f;
        darker.z = (windowBgColor.z - 0.04f < 0.0f) ? 0.0f : windowBgColor.z - 0.04f;
        darker.w = windowBgColor.w;

        // Using the original and darkened colors for button
        ImVec4 borderColor = darker;  // Using darker color for the border
        ImVec4 backgroundColor = windowBgColor;  // Using the base color for the button's background

        // Call to ColoredButtonV1 with adjusted colors
        ImGui::PushStyleColor(ImGuiCol_Border, ImColor(12, 12, 12).Value);
        ImGui::Button(txt.c_str(), size_arg);
        ImGui::PopStyleColor();

        // Check for key presses
        for (auto& Key : KeyCodes)
        {
            if (GetAsyncKeyState(Key) & 0x8000) {
                *k = Key;
                waitingforkey = false;
                break;
            }
        }
    }
}
namespace ImGui
{
    bool ColoredButtonV1(const char* label, const ImVec2& size, ImU32 text_color, ImU32 bg_color_1, ImU32 bg_color_2, bool border = false);
}
bool ImGui::ColoredButtonV1(const char* label, const ImVec2& size_arg, ImU32 text_color, ImU32 bg_color_1, ImU32 bg_color_2, bool border)
{
    ImGuiWindow* window = GetCurrentWindow();
    if (window->SkipItems)
        return false;

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = CalcTextSize(label, NULL, true);

    ImVec2 pos = window->DC.CursorPos;
    ImVec2 size = CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

    const ImRect bb(pos, pos + size);
    ItemSize(size, style.FramePadding.y);
    if (!ItemAdd(bb, id))
        return false;

    ImGuiButtonFlags flags = ImGuiButtonFlags_None;
    // if (g.LastItemData.InFlags & ImGuiItemFlags_ButtonRepeat)
     //    flags |= ImGuiButtonFlags_Repeat;

    bool hovered, held;
    bool pressed = ButtonBehavior(bb, id, &hovered, &held, flags);

    // Render
    const bool is_gradient = bg_color_1 != bg_color_2;
    if (held || hovered)
    {
        // Modify colors (ultimately this can be prebaked in the style)
        float h_increase = (held && hovered) ? 0.02f : 0;
        float v_increase = (held && hovered) ? 0.20f : 0;

        ImVec4 bg1f = ColorConvertU32ToFloat4(bg_color_1);
        ColorConvertRGBtoHSV(bg1f.x, bg1f.y, bg1f.z, bg1f.x, bg1f.y, bg1f.z);
        bg1f.x = ImMin(bg1f.x + h_increase, 1.0f);
        bg1f.z = ImMin(bg1f.z + v_increase, 1.0f);
        ColorConvertHSVtoRGB(bg1f.x, bg1f.y, bg1f.z, bg1f.x, bg1f.y, bg1f.z);
        bg_color_1 = GetColorU32(bg1f);
        if (is_gradient)
        {
            ImVec4 bg2f = ColorConvertU32ToFloat4(bg_color_2);
            ColorConvertRGBtoHSV(bg2f.x, bg2f.y, bg2f.z, bg2f.x, bg2f.y, bg2f.z);
            bg2f.z = ImMin(bg2f.z + h_increase, 1.0f);
            bg2f.z = ImMin(bg2f.z + v_increase, 1.0f);
            ColorConvertHSVtoRGB(bg2f.x, bg2f.y, bg2f.z, bg2f.x, bg2f.y, bg2f.z);
            bg_color_2 = GetColorU32(bg2f);
        }
        else
        {
            bg_color_2 = bg_color_1;
        }
    }
    RenderNavHighlight(bb, id);

#if 0
    // V1 : faster but prevents rounding
    window->DrawList->AddRectFilledMultiColor(bb.Min, bb.Max, bg_color_1, bg_color_1, bg_color_2, bg_color_2);
    if (g.Style.FrameBorderSize > 0.0f)
        window->DrawList->AddRect(bb.Min, bb.Max, GetColorU32(ImGuiCol_Border), 0.0f, 0, g.Style.FrameBorderSize);
#endif

    // V2
    int vert_start_idx = window->DrawList->VtxBuffer.Size;
    window->DrawList->AddRectFilled(bb.Min, bb.Max, bg_color_1, g.Style.FrameRounding);
    int vert_end_idx = window->DrawList->VtxBuffer.Size;
    if (is_gradient)
        ShadeVertsLinearColorGradientKeepAlpha(window->DrawList, vert_start_idx, vert_end_idx, bb.Min, bb.GetBL(), bg_color_1, bg_color_2);
    if (g.Style.FrameBorderSize > 0.0f)
        window->DrawList->AddRect(bb.Min, bb.Max, GetColorU32(ImGuiCol_Border), g.Style.FrameRounding, 0, g.Style.FrameBorderSize);
    if (border)
    {
        window->DrawList->AddRect(bb.Min, bb.Max, GetColorU32(ImGuiCol_ScrollbarGrabHovered), g.Style.FrameRounding, 0, g.Style.FrameBorderSize);
        window->DrawList->AddRect(bb.Min + ImVec2(1, 1), bb.Max - ImVec2(1, 1), GetColorU32(ImGuiCol_ScrollbarGrabActive), g.Style.FrameRounding, 0, g.Style.FrameBorderSize);
    }
    if (g.LogEnabled)
        LogSetNextTextDecoration("[", "]");
    PushStyleColor(ImGuiCol_Text, text_color);
    RenderTextClipped(bb.Min + style.FramePadding, bb.Max - style.FramePadding, label, NULL, &label_size, style.ButtonTextAlign, &bb);
    PopStyleColor();

    IMGUI_TEST_ENGINE_ITEM_INFO(id, label, g.LastItemData.StatusFlags);
    return pressed;
}
ImColor VecToColor(ImVec4 Color)
{
    return ImColor(
        (int)(Color.x * 255.0f),
        (int)(Color.y * 255.0f),
        (int)(Color.z * 255.0f),
        (int)(Color.w * 255.0f)
    );
}
ImVec4 ColorFromFloat(const float color[3], float alpha = 1.0f)
{
    return ImVec4(color[0], color[1], color[2], alpha);
}
ImColor FloatToColor(float* lol)
{
    return ImColor(lol[0], lol[1], lol[2]);
}
bool Keybind(CKeybind* keybind, const ImVec2& size_arg = ImVec2(0, 0), bool clicked = false, ImGuiButtonFlags flags = 0)
{
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return false;

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(keybind->get_name().c_str());
    const ImVec2 label_size = ImGui::CalcTextSize(keybind->get_name().c_str(), NULL, true);

    ImVec2 pos = window->DC.CursorPos;
    if ((flags & ImGuiButtonFlags_AlignTextBaseLine) &&
        style.FramePadding.y < window->DC.CurrLineTextBaseOffset)
    {
        pos.y += window->DC.CurrLineTextBaseOffset - style.FramePadding.y;
    }
    ImVec2 size = ImVec2(30.0f, 14.0f);

    const ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));
    ImGui::ItemSize(size, style.FramePadding.y);
    if (!ImGui::ItemAdd(bb, id))
        return false;
    if (g.CurrentItemFlags & ImGuiItemFlags_ButtonRepeat)
    {
        ImGui::PushItemFlag(ImGuiItemFlags_ButtonRepeat, true);
    }
    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, flags);
    bool value_changed = false;
    int key = keybind->key;
    auto io = ImGui::GetIO();
    std::string name = keybind->get_key_name();
    if (keybind->waiting_for_input)
        name = "";
    if (ImGui::IsMouseClicked(ImGuiMouseButton_Left) && hovered)
    {
        if (g.ActiveId == id)
        {
            keybind->waiting_for_input = true;
        }
    }
    else if (ImGui::IsMouseClicked(ImGuiMouseButton_Right) && hovered)
    {
        ImGui::OpenPopup(keybind->get_name().c_str());
    }
    else if (ImGui::IsMouseClicked(ImGuiMouseButton_Left) && !hovered)
    {
        if (g.ActiveId == id)
            ImGui::ClearActiveID();
    }
    if (keybind->waiting_for_input)
    {
        if (ImGui::IsMouseClicked(ImGuiMouseButton_Left) && !hovered)
        {
            keybind->key = VK_LBUTTON;
            ImGui::ClearActiveID();
            keybind->waiting_for_input = false;
        }
        else
        {
            if (keybind->set_key())
            {
                ImGui::ClearActiveID();
                keybind->waiting_for_input = false;
            }
        }
    }
    //ImGui::PushFont(font::lexend_regular);

    ImVec4 textcolor = ImLerp(ImVec4(201 / 255.f, 204 / 255.f, 210 / 255.f, 1.f), ImVec4(1.0f, 1.0f, 1.0f, 1.f), 1.f);


    //window->DrawList->AddRectFilled(bb.Min, bb.Max, ImColor(33 / 255.0f, 33 / 255.0f, 33 / 255.0f, 0.5f), 2.f);
    window->DrawList->AddRectFilled(
        bb.Min, bb.Max,
        ImColor(ImGui::GetStyleColorVec4(ImGuiCol_WindowBg))
    );
    window->DrawList->AddRect(
        bb.Min, bb.Max,
        ImColor(ImGui::GetStyleColorVec4(ImGuiCol_ScrollbarGrabActive))
    );
    window->DrawList->AddRect(
        bb.Min + ImVec2(1, 1), bb.Max - ImVec2(1,1),
        ImColor(ImGui::GetStyleColorVec4(ImGuiCol_ScrollbarGrabHovered))
    );


    ImVec2 text_pos = bb.Min + ImVec2(
        size_arg.x / 2 - ImGui::CalcTextSize(name.c_str()).x / 2,
        size_arg.y / 2 - ImGui::CalcTextSize(name.c_str()).y / 2);

    window->DrawList->AddText(text_pos - ImVec2(0,1), ImGui::GetColorU32(textcolor), name.c_str());
    ImGui::PushStyleColor(ImGuiCol_PopupBg, ImGui::GetStyleColorVec4(ImGuiCol_WindowBg));
    ImGui::PushStyleColor(ImGuiCol_Border, ImGui::GetStyleColorVec4(ImGuiCol_Border));
    
    if (ImGui::BeginPopup(keybind->get_name().c_str()))
    {
        //ImGui::BeginGroup();
       
       
        if (ImGui::Selectable("Hold", keybind->type == CKeybind::HOLD))
            keybind->type = CKeybind::HOLD;
        if (ImGui::Selectable("Toggle", keybind->type == CKeybind::TOGGLE))
            keybind->type = CKeybind::TOGGLE;
        if (ImGui::Selectable("Always", keybind->type == CKeybind::ALWAYS))
            keybind->type = CKeybind::ALWAYS;
        if (ImGui::Selectable("Disabled", keybind->type == CKeybind::DISABLED))
            keybind->type = CKeybind::DISABLED;
        //ImGui::EndGroup();
      
       
        ImGui::EndPopup();
    }
  
    ImGui::PopStyleColor(2);
    if (g.CurrentItemFlags & ImGuiItemFlags_ButtonRepeat)
    {
        ImGui::PushItemFlag(ImGuiItemFlags_ButtonRepeat, false);
    }
    return pressed;
}
struct DockButton
{
    bool Enabled;
    const char* Icon;
};
std::vector<std::string> ConfigListSaved = {  };
void RefreshConfigs()
{
    ConfigListSaved.clear();
    for (const auto& entry : std::filesystem::directory_iterator("C:\\Skidware\\Configs")) {
        if (entry.is_regular_file()) {
            std::string filename = entry.path().filename().string();
            if (filename.size() >= 6 && filename.substr(filename.size() - 6) == ".rocks") {
                ConfigListSaved.push_back(filename.substr(0, filename.size() - 6));
            }
        }
    }
}

struct WindowState {
    ImVec2 pos = { 100, 100 };
    ImVec2 size = { 300, 300 };
};

namespace SavedPositions {
    inline WindowState Home;
    inline WindowState Preview;
    inline WindowState Explorer;
    inline WindowState TargetHud;
    inline WindowState Players;
    inline WindowState Keybinds;
}

void Overlay::Setup()
{
    RefreshConfigs();
    ConfigManager::LoadGlobalSettings();
    Logging::Log(Logging::LogType::DEBUG, "Overlay Started ");
    WNDCLASSEXW wc = { sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"ImGui Example", nullptr };
    ::RegisterClassExW(&wc);
    const HWND hwnd = CreateWindowExW(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_NOACTIVATE, wc.lpszClassName, (L"sdwdadsgf"),
        WS_POPUP, 0, 0, GetSystemMetrics(0), GetSystemMetrics(1), nullptr, nullptr, wc.hInstance, nullptr);
    const MARGINS margin = { -1 };
    DwmExtendFrameIntoClientArea(hwnd, &margin);
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        exit(0);
    }
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    io.IniFilename = "C:\\Skidware\\imgui.ini";
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);
    
    ImGuiStyle* style = &ImGui::GetStyle();
    bool done = false;
    bool draw = true;
    static int g_PreloadFrames = 0;
    static bool g_RestoreOverlay = false;
    ImFontConfig font_config;
    font_config.FontBuilderFlags = ImGuiFreeTypeBuilderFlags_Monochrome | ImGuiFreeTypeBuilderFlags_MonoHinting;
    font_config.PixelSnapH = true;
    font_config.SizePixels = 13.0f;
    font_config.RasterizerMultiply = 1.0f;
    io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\tahoma.ttf", 13.0f, &font_config);
    static float AccentColorF[3] = { 156.0f / 255.0, 199.0f / 255.0, 40.0f / 255.0 };
    static float WindowColorF[3] = { 20.0f / 255.0, 20.0f / 255.0, 20.0f / 255.0 };
    static float ChildColorF[3] = { 12.0f / 255.0, 12.0f / 255.0, 12.0f / 255.0 };
    static float OutlineF[3] = { 12.0f / 255.0, 12.0f / 255.0, 12.0f / 255.0 };
    static float TextTitleF[3] = { 195.0f / 255.0, 195.0f / 255.0, 195.0f / 255.0 };
    static float TextF[3] = { 205.0f / 255.0, 205.0f / 255.0, 205.0f / 255.0 };
    static float UnsafeTextF[3] = { 172.0f / 255.0, 177.0f / 255.0, 123.0f / 255.0 };
    static float InlineF[3] = { 48.0f / 255.0, 48.0f / 255.0, 48.0f / 255.0 };
    static bool MenuGlow = true;
    static bool Crosshair = false;
    static float MenuGlowFloat = 30.0f;
    static ImVec2 g_LoaderSize(320, 360);
    ImColor AccentColor = FloatToColor(AccentColorF);
    ImColor WindowColor = FloatToColor(WindowColorF);
    ImColor ChildColor = FloatToColor(ChildColorF);
    ImColor Outline = FloatToColor(OutlineF);
    ImColor TextTitle = FloatToColor(TextTitleF);
    ImColor Text = FloatToColor(TextF);
    ImColor UnsafeText = FloatToColor(UnsafeTextF);
    ImColor Inline = FloatToColor(InlineF);
    {
        const char* clipboardText = "";
        std::string content;

        if (std::filesystem::exists("C:\\Skidware\\Theme.json"))
        {
            std::ifstream file("C:\\Skidware\\Theme.json");
            content = std::string((std::istreambuf_iterator<char>(file)),
                std::istreambuf_iterator<char>());
        }
        clipboardText = content.c_str();
        if (clipboardText && strlen(clipboardText) > 0)
        {
            try
            {
                nlohmann::json config = nlohmann::json::parse(clipboardText);

                auto u32_to_rgb = [](ImU32 colorU32, float out[3]) {
                    ImVec4 color = ImGui::ColorConvertU32ToFloat4(colorU32);
                    out[0] = color.x;
                    out[1] = color.y;
                    out[2] = color.z;
                    };

                if (config.contains("Accent"))       u32_to_rgb(config["Accent"], AccentColorF);
                if (config.contains("Window"))       u32_to_rgb(config["Window"], WindowColorF);
                if (config.contains("Child"))        u32_to_rgb(config["Child"], ChildColorF);
                if (config.contains("Outline"))      u32_to_rgb(config["Outline"], OutlineF);
                if (config.contains("DarkText"))     u32_to_rgb(config["DarkText"], TextTitleF);
                if (config.contains("Text"))         u32_to_rgb(config["Text"], TextF);
                if (config.contains("UnsafeText"))   u32_to_rgb(config["UnsafeText"], UnsafeTextF);
                if (config.contains("Inline"))       u32_to_rgb(config["Inline"], InlineF);

                if (config.contains("MenuGlow"))     MenuGlow = config["MenuGlow"].get<bool>();
                if (config.contains("GlowAmount"))   MenuGlowFloat = config["GlowAmount"].get<float>();
                if (config.contains("Crosshair"))   Crosshair = config["Crosshair"].get<bool>();
                if (config.contains("WinPosX")) SavedPositions::Home.pos.x = config["WinPosX"].get<float>();
                if (config.contains("WinPosY")) SavedPositions::Home.pos.y = config["WinPosY"].get<float>();
                if (config.contains("WinSizeX")) SavedPositions::Home.size.x = config["WinSizeX"].get<float>();
                if (config.contains("WinSizeY")) SavedPositions::Home.size.y = config["WinSizeY"].get<float>();
                auto LoadWinState = [](nlohmann::json& j, const char* key, WindowState& ws) {
                    if (j.contains(key))
                    {
                        auto& s = j[key];
                        if (s.contains("pos"))
                        {
                            ws.pos.x = s["pos"][0].get<float>();
                            ws.pos.y = s["pos"][1].get<float>();
                        }
                        if (s.contains("size"))
                        {
                            ws.size.x = s["size"][0].get<float>();
                            ws.size.y = s["size"][1].get<float>();
                        }
                    }
                };
                if (config.contains("Sections"))
                {
                    auto& sec = config["Sections"];
                    LoadWinState(sec, "Home", SavedPositions::Home);
                    LoadWinState(sec, "Preview", SavedPositions::Preview);
                    LoadWinState(sec, "Explorer", SavedPositions::Explorer);
                    LoadWinState(sec, "TargetHud", SavedPositions::TargetHud);
                    LoadWinState(sec, "Players", SavedPositions::Players);
                    LoadWinState(sec, "Keybinds", SavedPositions::Keybinds);
                }
                if (config.contains("DockBar"))
                {
                    auto& db = config["DockBar"];
                    if (db.contains("Home")) Globals::DockBar_Home = db["Home"];
                    if (db.contains("Style")) Globals::DockBar_Style = db["Style"];
                    if (db.contains("EspPreview")) Globals::DockBar_EspPreview = db["EspPreview"];
                    if (db.contains("TargetHud")) Globals::DockBar_TargetHud = db["TargetHud"];
                    if (db.contains("Explorer")) Globals::DockBar_Explorer = db["Explorer"];
                    if (db.contains("Players")) Globals::DockBar_Players = db["Players"];
                    if (db.contains("Keybinds")) Globals::DockBar_Keybinds = db["Keybinds"];
                    if (db.contains("Anims")) Globals::DockBar_Anims = db["Anims"];
                }
            }
            catch (const std::exception& e)
            {
                
            }
        }
    }
    ImFont* BoldFont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\verdanab.ttf", 13.0f);
    ImFont* SmallestPixel = io.Fonts->AddFontFromMemoryTTF(
        SmallestPixelRaw,
        sizeof(SmallestPixelRaw),
        9.0f
    );
    ImFont* Visitor = io.Fonts->AddFontFromMemoryTTF(
        VisitorRaw,
        sizeof(VisitorRaw),
        9.0f
    );
    ImFont* LatoBold = io.Fonts->AddFontFromMemoryTTF(
        LatoBoldRaw,
        sizeof(LatoBoldRaw),
        15.0f
    );
    ID3D11ShaderResourceView* BladeeT = nullptr;
    {
        int width, height, channels;
        unsigned char* imageData = stbi_load_from_memory(
            BladeeRaw,
            sizeof(BladeeRaw),
            &width,
            &height,
            &channels,
            4
        );
        if (imageData && width > 0 && height > 0) {
            D3D11_TEXTURE2D_DESC desc = {};
            desc.Width = width;
            desc.Height = height;
            desc.MipLevels = 1;
            desc.ArraySize = 1;
            desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            desc.SampleDesc.Count = 1;
            desc.Usage = D3D11_USAGE_DEFAULT;
            desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
            desc.CPUAccessFlags = 0;

            D3D11_SUBRESOURCE_DATA initData = {};
            initData.pSysMem = imageData;
            initData.SysMemPitch = width * 4;

            ID3D11Texture2D* texture = nullptr;
            if (SUCCEEDED(g_pd3dDevice->CreateTexture2D(&desc, &initData, &texture))) {
                g_pd3dDevice->CreateShaderResourceView(texture, nullptr, &BladeeT);
                if (texture) texture->Release();
            }
            stbi_image_free(imageData);
        }
    }
    static const ImWchar icon_ranges[]{ ICON_MIN_FA, ICON_MAX_FA, 0 };

    ImFontConfig icon_config;

    icon_config.PixelSnapH = true;
    icon_config.OversampleH = 3;
    icon_config.OversampleV = 3;
    ImFont* iconsfont = io.Fonts->AddFontFromMemoryCompressedTTF(fa6_solid_compressed_data, fa6_solid_compressed_size, 13.0f, &icon_config, icon_ranges);
    auto LastThemeSave = std::chrono::steady_clock::now();

    DockButton Home;
    Home.Icon = ICON_FA_HOUSE;
    Home.Enabled = Globals::DockBar_Home;

    DockButton EspPreview;
    EspPreview.Icon = ICON_FA_PERSON;
    EspPreview.Enabled = Globals::DockBar_EspPreview;

    DockButton Style;
    Style.Icon = ICON_FA_PALETTE;
    Style.Enabled = Globals::DockBar_Style;

    DockButton TargetHud;
    TargetHud.Icon = ICON_FA_CROSSHAIRS;
    TargetHud.Enabled = Globals::DockBar_TargetHud;

    DockButton Explorer;
    Explorer.Icon = ICON_FA_LIST;
    Explorer.Enabled = Globals::DockBar_Explorer;

    DockButton Players;
    Players.Icon = ICON_FA_USERS;
    Players.Enabled = Globals::DockBar_Players;

    DockButton Keybinds;
    Keybinds.Icon = ICON_FA_KEYBOARD;
    Keybinds.Enabled = Globals::DockBar_Keybinds;

    DockButton Anims;
    Anims.Icon = ICON_FA_WAND_MAGIC_SPARKLES;
    Anims.Enabled = Globals::DockBar_Anims;

    Globals::g_pd3dDevice = Overlay::g_pd3dDevice;
    Globals::g_pd3dDeviceContext = Overlay::g_pd3dDeviceContext;

    

    std::vector<DockButton> DockButtons = { Home, Style, EspPreview, TargetHud, Explorer, Players, Keybinds, Anims };

    while (!done)
    {
        auto frameT0 = std::chrono::steady_clock::now();
        static long long totalFrameUs = 0, totalEspUs = 0, totalPresentUs = 0;
        static int framesLogged = 0;
        {
            auto now = std::chrono::steady_clock::now();
            if (duration_cast<std::chrono::seconds>(now - LastThemeSave).count() >= 3) {
                nlohmann::json config;
                config["Accent"] = ImGui::GetColorU32(AccentColor.Value);
                config["Window"] = ImGui::GetColorU32(WindowColor.Value);
                config["Child"] = ImGui::GetColorU32(ChildColor.Value);
                config["Outline"] = ImGui::GetColorU32(Outline.Value);
                config["DarkText"] = ImGui::GetColorU32(TextTitle.Value);
                config["Text"] = ImGui::GetColorU32(Text.Value);
                config["UnsafeText"] = ImGui::GetColorU32(UnsafeText.Value);
                config["Inline"] = ImGui::GetColorU32(Inline.Value);
                config["MenuGlow"] = MenuGlow;
                config["GlowAmount"] = MenuGlowFloat;
                config["Crosshair"] = Crosshair;
                config["WinPosX"] = SavedPositions::Home.pos.x;
                config["WinPosY"] = SavedPositions::Home.pos.y;
                config["WinSizeX"] = SavedPositions::Home.size.x;
                config["WinSizeX"] = SavedPositions::Home.size.x;
                config["WinSizeY"] = SavedPositions::Home.size.y;
                auto SaveWinState = [](nlohmann::json& j, const char* key, const WindowState& ws) {
                    j[key]["pos"] = { ws.pos.x, ws.pos.y };
                    j[key]["size"] = { ws.size.x, ws.size.y };
                };
                SaveWinState(config["Sections"], "Home", SavedPositions::Home);
                SaveWinState(config["Sections"], "Preview", SavedPositions::Preview);
                SaveWinState(config["Sections"], "Explorer", SavedPositions::Explorer);
                SaveWinState(config["Sections"], "TargetHud", SavedPositions::TargetHud);
                SaveWinState(config["Sections"], "Players", SavedPositions::Players);
                SaveWinState(config["Sections"], "Keybinds", SavedPositions::Keybinds);
                config["DockBar"]["Home"] = Globals::DockBar_Home;
                config["DockBar"]["Style"] = Globals::DockBar_Style;
                config["DockBar"]["EspPreview"] = Globals::DockBar_EspPreview;
                config["DockBar"]["TargetHud"] = Globals::DockBar_TargetHud;
                config["DockBar"]["Explorer"] = Globals::DockBar_Explorer;
                config["DockBar"]["Players"] = Globals::DockBar_Players;
                config["DockBar"]["Keybinds"] = Globals::DockBar_Keybinds;
                config["DockBar"]["Anims"] = Globals::DockBar_Anims;
                std::ofstream file("C:\\Skidware\\Theme.json");
                file << config.dump();
                RefreshConfigs();
                LastThemeSave = now; 
            }
        }
        MSG msg;

        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;
        // While the loader is up, keep the real HWND sized to the loader box
        // instead of covering the whole screen. Clicks anywhere outside the box
        // then go to whatever is underneath with zero hit-testing tricks, and
        // the loader still gets full input. The D3D swapchain is resized via
        // WM_SIZE -> g_ResizeWidth/Height below.
        if (!Globals::LoaderAttached)
        {
            const bool authedNow = Globals::Auth::Authenticated;
            const int lw = (int)g_LoaderSize.x;
            const int lh = (int)g_LoaderSize.y;
            RECT wr;
            GetWindowRect(hwnd, &wr);
            if (wr.right - wr.left != lw || wr.bottom - wr.top != lh)
            {
                int sw = GetSystemMetrics(SM_CXSCREEN);
                int sh = GetSystemMetrics(SM_CYSCREEN);
                MoveWindow(hwnd, (sw - lw) / 2, (sh - lh) / 2, lw, lh, TRUE);
            }
        }
        g_SwapChainOccluded = false;
        if (g_ResizeWidth != 0 && g_ResizeHeight != 0)
        {
            CleanupRenderTarget();
            g_pSwapChain->ResizeBuffers(0, g_ResizeWidth, g_ResizeHeight, DXGI_FORMAT_UNKNOWN, 0);
            g_ResizeWidth = g_ResizeHeight = 0;
            CreateRenderTarget();
        }
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        auto getbg = GetForegroundWindow();
        AccentColor = FloatToColor(AccentColorF);
        WindowColor = FloatToColor(WindowColorF);
        ChildColor = FloatToColor(ChildColorF);
        Outline = FloatToColor(OutlineF);
        TextTitle = FloatToColor(TextTitleF);
        Text = FloatToColor(TextF);
        UnsafeText = FloatToColor(UnsafeTextF);
        Inline = FloatToColor(InlineF);
        ImGuiStyle* style = &ImGui::GetStyle();
        style->ScrollbarSize = 0.0f;
        style->WindowPadding = { 6,6 };
        style->FramePadding = { 0,0 };
        style->Colors[ImGuiCol_ResizeGrip] = ImColor(0, 0, 0, 0).Value;
        style->Colors[ImGuiCol_ResizeGripActive] = ImColor(0, 0, 0, 0).Value;
        style->Colors[ImGuiCol_ResizeGripHovered] = ImColor(0, 0, 0, 0).Value;
        style->Colors[ImGuiCol_WindowBg] = WindowColor.Value;
        style->Colors[ImGuiCol_PopupBg] = WindowColor.Value;
        style->Colors[ImGuiCol_ChildBg] = ChildColor.Value;
        style->Colors[ImGuiCol_ScrollbarGrab] = ChildColor.Value;
        style->Colors[ImGuiCol_ScrollbarGrabActive] = Outline.Value;
        style->Colors[ImGuiCol_ScrollbarGrabHovered] = Inline.Value;
        style->Colors[ImGuiCol_Border] = Outline.Value;
        style->Colors[ImGuiCol_CheckMark] = AccentColor.Value;
        style->Colors[ImGuiCol_Text] = Text.Value;
        style->WindowShadowSize = 0.0f;
        style->WindowBorderSize = 1.0f;
        if (Globals::LoaderAttached)
        {
        if (getbg == Globals::RobloxWindow || getbg == hwnd)
        {
            Overlay::move_window(hwnd);
            static auto lastToggle = std::chrono::steady_clock::time_point{};
            auto nowToggle = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::milliseconds>(nowToggle - lastToggle).count() > 200)
            {
                if (GetAsyncKeyState(VK_INSERT) & 1)
                { draw = !draw; lastToggle = nowToggle; }
                if (GetAsyncKeyState(VK_F1) & 1)
                { draw = !draw; lastToggle = nowToggle; }
            }
            // hidden warmup: render the full menu a few frames right after attach
            // so ImGui bakes all fonts/glyphs/layout once, killing the first-open
            // stutter, then auto-hide again
            bool uiRender = draw;
            if (g_PreloadFrames > 0)
            {
                g_PreloadFrames--;
                SetLayeredWindowAttributes(hwnd, 0, 0, LWA_ALPHA);
                uiRender = true;
                if (g_PreloadFrames == 0)
                    g_RestoreOverlay = true;
            }
            if (g_RestoreOverlay)
            {
                g_RestoreOverlay = false;
                SetLayeredWindowAttributes(hwnd, 0, 255, LWA_ALPHA);
            }
            if (Globals::Esp::Font == 1)
                ImGui::PushFont(Visitor);
            if (Globals::Esp::Font == 2)
                ImGui::PushFont(SmallestPixel);
            if (Globals::Esp::Font == 3)
                ImGui::PushFont(BoldFont);
            if (Globals::Esp::Font == 4)
                ImGui::PushFont(LatoBold);
            try
            {
                auto espT0 = std::chrono::steady_clock::now();
                Hacks::Esp::Render();
                totalEspUs += std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - espT0).count();
            }
            catch (...)
            {
                Logging::Log(Logging::LogType::ERR, "Caught crash at ESP");
            }

            if (Globals::Esp::Font != 0)
                ImGui::PopFont();
            
            if (uiRender || Globals::Aimbot::Target::HaveTarget)
            {
				// Target HUD
                if (DockButtons[3].Enabled)
                {
                    ImGui::SetNextWindowPos(SavedPositions::TargetHud.pos, ImGuiCond_Appearing);
                    ImGui::SetNextWindowSize({ 332, 177 });
                    ImGui::Begin("##TargetHud", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
                    SavedPositions::TargetHud.pos = ImGui::GetWindowPos();
                    SavedPositions::TargetHud.size = ImGui::GetWindowSize();
                    DragHeader("##drag_targethud");
                    ImGui::GetWindowDrawList()->AddRectFilledMultiColor(ImGui::GetWindowPos(), ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x, 25), ChildColor, ChildColor, WindowColor, WindowColor);

                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor);
                    if (MenuGlow)
                        ImGui::GetBackgroundDrawList()->AddShadowRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor, MenuGlowFloat, { 0,0 });
                    ImGui::SetCursorPos(ImVec2(6, 3));
                    ImGui::TextColored(AccentColor.Value, "Indicator ");
                    style->Colors[ImGuiCol_Border] = Inline.Value;
                    ImGui::BeginChild("##c", ImGui::GetContentRegionAvail(), true);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Outline
                    );
                    style->Colors[ImGuiCol_ChildBg] = WindowColor.Value;
                    style->Colors[ImGuiCol_Border] = Outline.Value;
                    ImGui::BeginChild("##b", ImGui::GetContentRegionAvail(), true);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Inline
                    );
                    style->Colors[ImGuiCol_ChildBg] = ChildColor;
                    style->Colors[ImGuiCol_Border] = Inline.Value;
                    ImGui::BeginChild("##1", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, true);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Outline
                    );
                    ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                        ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                        AccentColor
                    );
                    ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                        ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                        ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                    );
                    ImGui::TextColored(TextTitle.Value, "Info");
                    style->Colors[ImGuiCol_ChildBg] = WindowColor.Value;
                    style->Colors[ImGuiCol_Border] = Outline.Value;
                    ImGui::BeginChild("##pfp", { ImGui::GetContentRegionAvail().y, ImGui::GetContentRegionAvail().y }, true);

                    ImGui::GetWindowDrawList()->AddRectFilledMultiColor(ImGui::GetWindowPos(), ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x, ImGui::GetWindowSize().y), WindowColor, WindowColor, ChildColor, ChildColor);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Inline
                    );
                    if (Globals::Aimbot::Target::HaveTarget)
                    {
                        std::lock_guard<std::mutex> lock(SDK::Cache::LoadedAvatarsMutex);
                        for (SDK::Cache::PlayerAvatar Avatar : SDK::Cache::LoadedAvatars)
                        {
                            if (Avatar.PlayerName == Globals::Aimbot::Target::Name)
                            {
                                ImGui::GetWindowDrawList()->AddImage(
                                    (ImTextureID)Avatar.Texture,
                                    ImGui::GetWindowPos() + ImVec2(1, 1),
                                    ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1)
                                );
                                break;
                            }
                        }
                    }
                    style->Colors[ImGuiCol_ChildBg] = ChildColor;
                    style->Colors[ImGuiCol_Border] = Inline.Value;
                    ImGui::EndChild();
                    ImGui::SameLine();
                    ImGui::BeginChild("##Information", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, false);
                    if (Globals::Aimbot::Target::HaveTarget)
                    {
                        ImGui::Text("Name:");
                        ImGui::SameLine(ImGui::GetContentRegionAvail().x - ImGui::CalcTextSize(Globals::Aimbot::Target::Name.c_str()).x, 0.0f);
                        ImGui::Text(Globals::Aimbot::Target::Name.c_str());

                        ImGui::Text("Display Name:");
                        ImGui::SameLine(ImGui::GetContentRegionAvail().x - ImGui::CalcTextSize(Globals::Aimbot::Target::DisplayName.c_str()).x, 0.0f);
                        ImGui::Text(Globals::Aimbot::Target::DisplayName.c_str());
                        for (SDK::Cache::Player Player : SDK::Cache::Players)
                        {
                            if (Player.PlayerName == Globals::Aimbot::Target::Name)
                            {
                                ImGui::Text("Tool:");
                                if (Player.Weapon.empty())
                                {
                                    ImGui::SameLine(ImGui::GetContentRegionAvail().x - ImGui::CalcTextSize("None").x, 0.0f);
                                    ImGui::Text("None");
                                }
                                else
                                {
                                    ImGui::SameLine(ImGui::GetContentRegionAvail().x - ImGui::CalcTextSize(Player.Weapon.c_str()).x, 0.0f);
                                    ImGui::Text(Player.Weapon.c_str());
                                }


                                ImGui::Text("Distance:");
                                ImGui::SameLine(ImGui::GetContentRegionAvail().x - ImGui::CalcTextSize(std::string(std::to_string(Player.Distance) + "m").c_str()).x, 0.0f);
                                ImGui::Text(std::string(std::to_string(Player.Distance) + "m").c_str());

                                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10);

                                int health = Player.Health;
                                ImGui::SliderInt("##hleath", &health, 0, Player.MaxHealth, "%d", ImGuiSliderFlags_ReadOnly);
                                break;
                            }
                        }
                        
                    }
                    else
                    {
                        ImGui::Text("Name:");
                        ImGui::SameLine(ImGui::GetContentRegionAvail().x - ImGui::CalcTextSize("None").x, 0.0f);
                        ImGui::Text("None");
                        ImGui::Text("Display Name:");
                        ImGui::SameLine(ImGui::GetContentRegionAvail().x - ImGui::CalcTextSize("None").x, 0.0f);
                        ImGui::Text("None");
                        ImGui::Text("Tool:");
                        ImGui::SameLine(ImGui::GetContentRegionAvail().x - ImGui::CalcTextSize("None").x, 0.0f);
                        ImGui::Text("None");

                        ImGui::Text("Distance:");
                        ImGui::SameLine(ImGui::GetContentRegionAvail().x - ImGui::CalcTextSize("0m").x, 0.0f);
                        ImGui::Text("0m");

                        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10);

                        int health = 0;
                        ImGui::SliderInt("##hleath", &health, 0, 100, "%d", ImGuiSliderFlags_ReadOnly);
                    }
                    ImGui::EndChild();
                    ImGui::EndChild();
                    ImGui::EndChild();
                    ImGui::EndChild();
                    ImGui::End();
                }
            }
            if (uiRender)
            {
                // Explorer
                if (DockButtons[4].Enabled)
                {
                    ImGui::SetNextWindowPos(SavedPositions::Explorer.pos, ImGuiCond_Appearing);
                    ImGui::SetNextWindowSize(SavedPositions::Explorer.size, ImGuiCond_Appearing);
                    ImGui::SetNextWindowSizeConstraints({  300, 500 }, {FLT_MAX, FLT_MAX});
                    ImGui::Begin("##Explorer", nullptr, ImGuiWindowFlags_NoTitleBar);
                    SavedPositions::Explorer.pos = ImGui::GetWindowPos();
                    SavedPositions::Explorer.size = ImGui::GetWindowSize();
                    DragHeader("##drag_explorer");
                    ImGui::GetWindowDrawList()->AddRectFilledMultiColor(ImGui::GetWindowPos(), ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x, 25), ChildColor, ChildColor, WindowColor, WindowColor);

                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor);
                    if (MenuGlow)
                        ImGui::GetBackgroundDrawList()->AddShadowRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor, MenuGlowFloat, { 0,0 });
                    ImGui::SetCursorPos(ImVec2(6, 3));
                    ImGui::TextColored(AccentColor.Value, "Explorer ");
                    ImGui::SameLine(ImGui::GetWindowContentRegionMax().x - 10);
                    ImGui::TextColored(AccentColor.Value, "x");
                    if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0))
                    {
                        DockButtons[4].Enabled = false;
                    }
                    style->Colors[ImGuiCol_Border] = Inline.Value;
                    
                    Hacks::Explorer::Render();
                    
                    static const char* classNames[] = {
                        "All", "Part", "MeshPart", "UnionOperation", "Model", "Script",
                        "LocalScript", "ModuleScript", "Folder", "Humanoid", "Camera",
                        "Tool", "Sound", "Decal", "Texture", "SpecialMesh", "SpotLight",
                        "SurfaceLight", "Seat", "ScreenGui", "Frame",
                        "TextLabel", "ImageLabel", "ViewportFrame"
                    };
                    static const int classNamesCount = sizeof(classNames) / sizeof(classNames[0]);

                    ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
                    ImGui::Combo("##ClassFilter", &Globals::Explorer::ClassFilterIndex, classNames, classNamesCount);
                    Globals::Explorer::ClassFilterBuf[0] = '\0';
                    if (Globals::Explorer::ClassFilterIndex > 0 && Globals::Explorer::ClassFilterIndex < classNamesCount)
                        strcpy_s(Globals::Explorer::ClassFilterBuf, sizeof(Globals::Explorer::ClassFilterBuf), classNames[Globals::Explorer::ClassFilterIndex]);

                    ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x - 70);
                    ImGui::InputText("##Search", Globals::Explorer::SearchBuf, IM_ARRAYSIZE(Globals::Explorer::SearchBuf));
                    ImGui::SameLine();
                    {
                        const char* pauseLabel = Globals::Explorer::Paused ? "Resume" : "Pause";
                        if (ImGui::SmallButton(pauseLabel))
                        {
                            if (!Globals::Explorer::Paused)
                            {
                                CacheTree();
                            }
                            Globals::Explorer::Paused = !Globals::Explorer::Paused;
                        }
                        ImGui::SameLine();
                        if (ImGui::SmallButton("Clear"))
                        {
                            Globals::Explorer::SearchBuf[0] = '\0';
                            Globals::Explorer::ClassFilterIndex = 0;
                            Globals::Explorer::ClassFilterBuf[0] = '\0';
                        }
                    }

                    ImGui::BeginChild("##c", ImGui::GetContentRegionAvail(), true);

                    ImGui::GetWindowDrawList()->AddRect(
                        ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Outline
                    );
                    
                    if (!Globals::Explorer::Paused)
                    {
                        Hacks::Explorer::RenderTree();
                    }
                    else
                    {
                        RenderPausedTree();
                    }
                    Globals::Explorer::FocusAddress = 0;
                    Globals::Explorer::FocusPath.clear();
                    
                    ImGui::EndChild();

                    ImGui::End();
                }
                if (DockButtons[5].Enabled)
                {
                    ImGui::SetNextWindowPos(SavedPositions::Players.pos, ImGuiCond_Appearing);
                    ImGui::SetNextWindowSize(SavedPositions::Players.size, ImGuiCond_Appearing);
                    ImGui::SetNextWindowSizeConstraints({ 300, 400 }, { FLT_MAX, FLT_MAX });
                    ImGui::Begin("##Players", nullptr, ImGuiWindowFlags_NoTitleBar);
                    SavedPositions::Players.pos = ImGui::GetWindowPos();
                    SavedPositions::Players.size = ImGui::GetWindowSize();
                    DragHeader("##drag_players");
                    ImGui::GetWindowDrawList()->AddRectFilledMultiColor(ImGui::GetWindowPos(), ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x, 25), ChildColor, ChildColor, WindowColor, WindowColor);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor);
                    if (MenuGlow)
                        ImGui::GetBackgroundDrawList()->AddShadowRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor, MenuGlowFloat, { 0,0 });
                    ImGui::SetCursorPos(ImVec2(6, 3));
                    ImGui::TextColored(AccentColor.Value, "Players ");
                    ImGui::SameLine(ImGui::GetContentRegionAvail().x);
                    ImGui::Text("x");
                    if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0))
                        DockButtons[5].Enabled = false;
                    style->Colors[ImGuiCol_Border] = Inline.Value;
                    ImGui::BeginChild("##c", ImGui::GetContentRegionAvail(), true);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Outline
                    );
                    style->Colors[ImGuiCol_ChildBg] = WindowColor.Value;
                    style->Colors[ImGuiCol_Border] = Outline.Value;
                    ImGui::BeginChild("##b", ImGui::GetContentRegionAvail(), true);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Inline
                    );
                    style->Colors[ImGuiCol_ChildBg] = ChildColor;
                    style->Colors[ImGuiCol_Border] = Inline.Value;
                    style->Colors[ImGuiCol_ChildBg] = WindowColor;
                    style->Colors[ImGuiCol_Border] = Outline;
                    ImGui::BeginChild("##Players", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y - 80 }, true);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Inline
                    );
                    static SDK::Cache::Player SelectedPlayer;
                    style->Colors[ImGuiCol_ChildBg] = ChildColor;
                    style->Colors[ImGuiCol_Border] = Inline;
                    for (SDK::Cache::Player Player : SDK::Cache::Players)
                    {
                        ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize(Player.PlayerName.c_str()).x) / 2);
                        if (SelectedPlayer.PlayerObjectAddress == Player.PlayerObjectAddress)
                            ImGui::TextColored(AccentColor.Value, Player.PlayerName.c_str());
                        else
                            ImGui::Text(Player.PlayerName.c_str());
                        if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0))
                            SelectedPlayer = Player;
                        ImGui::Separator();
                    }
                    ImGui::EndChild();
                    float ButtonHeight = ImGui::GetContentRegionAvail().y / 3 - 3;
                    if (ImGui::Button("Teleport", { ImGui::GetContentRegionAvail().x, ButtonHeight }))
                    {
                        while (SelectedPlayer.HumanoidRootPart.Object.Primitive().Position() != SDK::Cache::LocalPlayer.HumanoidRootPart.Object.Primitive().Position())
                        {
                            SDK::Cache::LocalPlayer.HumanoidRootPart.Object.Primitive().SetPosition(SelectedPlayer.HumanoidRootPart.Object.Primitive().Position());
                        }
                    }
                    if (ImGui::Button("Spectate", { ImGui::GetContentRegionAvail().x, ButtonHeight }))
                    {
                        SDK::Camera Camera = (SDK::Camera)Globals::Workspace.FindFirstChildOfClass("Camera");
                        Camera.SpectateHumanoid(SelectedPlayer.Humanoid);
                    }
                    if (ImGui::Button("Unspectate", { ImGui::GetContentRegionAvail().x, ButtonHeight }))
                    {
                        SDK::Camera Camera = (SDK::Camera)Globals::Workspace.FindFirstChildOfClass("Camera");
                        Camera.SpectateHumanoid(SDK::Cache::LocalPlayer.Humanoid);
                    }
                    ImGui::EndChild();
                    ImGui::EndChild();
                    ImGui::End();
                }
                ImGui::Begin("##DockBar", nullptr, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
                ImVec2 wp = ImGui::GetWindowPos();


                ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                    ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                    Inline
                );
                ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                    ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                    AccentColor
                );
                ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                    ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                    ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                );
                ImGui::PushFont(iconsfont);
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 2);
                for (DockButton& BT : DockButtons)
                {
                    bool ENABLED = BT.Enabled;
                    if (ENABLED)
                        ImGui::PushStyleColor(ImGuiCol_Text, AccentColor.Value);
                    if (ImGui::ColoredButtonV1(BT.Icon, { 25,25 }, ImGui::GetColorU32(ImGuiCol_Text), ChildColor, WindowColor, true))
                        BT.Enabled = !BT.Enabled;
                    if (ENABLED)
                        ImGui::PopStyleColor();
                    ImGui::SameLine();
                }
                Globals::DockBar_Home = DockButtons[0].Enabled;
                Globals::DockBar_Style = DockButtons[1].Enabled;
                Globals::DockBar_EspPreview = DockButtons[2].Enabled;
                Globals::DockBar_TargetHud = DockButtons[3].Enabled;
                Globals::DockBar_Explorer = DockButtons[4].Enabled;
                Globals::DockBar_Players = DockButtons[5].Enabled;
                Globals::DockBar_Keybinds = DockButtons[6].Enabled;
                Globals::DockBar_Anims = DockButtons[7].Enabled;

                ImGui::PopFont();

                ImGui::SetWindowPos({ io.DisplaySize.x / 2 - ImGui::GetWindowSize().x / 2, 20 });

                ImGui::End();
                
                if (DockButtons[0].Enabled)
                {
                    if (g_NeedsReposition) {
                        if (SavedPositions::Home.pos.x != 0 || SavedPositions::Home.pos.y != 0) {
                            ImGui::SetNextWindowPos(SavedPositions::Home.pos, ImGuiCond_Always);
                            ImGui::SetNextWindowSize(SavedPositions::Home.size, ImGuiCond_Always);
                        }
                        g_NeedsReposition = false; // Reset so user can drag it again
                    }
                    else {
                        // Normal behavior: only set if no .ini data exists
                        ImGui::SetNextWindowPos(SavedPositions::Home.pos, ImGuiCond_Appearing);
                        ImGui::SetNextWindowSize(SavedPositions::Home.size, ImGuiCond_Appearing);
                    }

                    ImGui::SetNextWindowSizeConstraints({ 300, 300 }, { FLT_MAX, FLT_MAX });
                    ImGui::Begin("##Home", nullptr, ImGuiWindowFlags_NoTitleBar);
                    SavedPositions::Home.pos = ImGui::GetWindowPos();
                    SavedPositions::Home.size = ImGui::GetWindowSize();
                    DragHeader("##drag_home", 30.0f);
                    ImGui::GetWindowDrawList()->AddRectFilledMultiColor(ImGui::GetWindowPos(), ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x, 25), ChildColor, ChildColor, WindowColor, WindowColor);

                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor);
                    if (MenuGlow)
                        ImGui::GetBackgroundDrawList()->AddShadowRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor, MenuGlowFloat, { 0,0 });
                    ImGui::SetCursorPos({ 8, 4 });
                    ImGui::TextColored(AccentColor.Value, "Skidware");
                    ImGui::SameLine(ImGui::GetContentRegionAvail().x);
                    ImGui::Text("x");
                    if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0))
                    {
                        DockButtons[0].Enabled = false;
                    }
                    style->Colors[ImGuiCol_Border] = Inline.Value;
                    ImGui::BeginChild("##c", ImGui::GetContentRegionAvail(), true);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Outline
                    );
                    style->Colors[ImGuiCol_ChildBg] = WindowColor.Value;
                    style->Colors[ImGuiCol_Border] = Outline.Value;
                    ImGui::BeginChild("##b", ImGui::GetContentRegionAvail(), true);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Inline
                    );

                    std::string tabs[] = { "Aimbot", "Anti Aim", "Visuals", "Exploits", "Misc" };
                    static std::string currenttab = "Aimbot";
                    float totalWidth = ImGui::GetWindowSize().x;
                    size_t tabCount = sizeof(tabs) / sizeof(tabs[0]);
                    float spacing = 4.0f;
                    ImVec2 SelectedMin;
                    ImVec2 SelectedMax;
                    ImVec2 LastMin;
                    ImVec2 LastMax;
                    ImVec2 CurrentMin;
                    ImVec2 CurrentMax;


                    float buttonWidth = (totalWidth - spacing * (tabCount - 1)) / tabCount;

                    for (size_t i = 0; i < tabCount; ++i) {

                        if (i == 0) {
                            ImGui::SetCursorPos({ 2, 2 });
                        }
                        ImVec4 color = WindowColor;


                        ImVec4 darker;
                        darker.x = (color.x - 0.04f < 0.0f) ? 0.0f : color.x - 0.04f;
                        darker.y = (color.y - 0.04f < 0.0f) ? 0.0f : color.y - 0.04f;
                        darker.z = (color.z - 0.04f < 0.0f) ? 0.0f : color.z - 0.04f;
                        darker.w = color.w;

                        if (tabs[i] == currenttab) {

                            if (ImGui::ColoredButtonV1(tabs[i].c_str(), { buttonWidth - 1, 20 }, AccentColor, ImColor(darker), WindowColor)) {
                                currenttab = tabs[i];
                            }
                            SelectedMin = ImGui::GetItemRectMin();
                            SelectedMax = ImGui::GetItemRectMax();






                        }
                        else {
                            if (ImGui::ColoredButtonV1(tabs[i].c_str(), { buttonWidth - 1, 20 }, TextTitle, WindowColor, ChildColor)) {
                                currenttab = tabs[i];
                            }

                        }


                        CurrentMin = { std::floor(ImGui::GetItemRectMin().x), std::floor(ImGui::GetItemRectMin().y) };
                        CurrentMax = { std::floor(ImGui::GetItemRectMax().x), std::floor(ImGui::GetItemRectMax().y) };


                        if (i == 0) {
                            ImGui::GetForegroundDrawList()->AddLine(ImVec2(CurrentMax.x - 1, CurrentMin.y), CurrentMax - ImVec2(1, 0), Inline);
                            ImGui::GetForegroundDrawList()->AddLine(ImVec2(CurrentMax.x, CurrentMin.y - 1), CurrentMax, Outline);
                        }
                        if (i > 0) {



                            ImVec2 fillStart = ImVec2(LastMax.x, LastMin.y - 2);
                            ImVec2 fillEnd = ImVec2(CurrentMin.x, CurrentMax.y - 1);
                            ImGui::GetWindowDrawList()->AddRectFilled(fillStart, fillEnd, ChildColor);
                            ImGui::GetForegroundDrawList()->AddRectFilled(fillStart + ImVec2(1, 0), ImVec2(fillEnd.x, fillStart.y + 1), ChildColor);
                            ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(fillStart.x, fillEnd.y - 1), fillEnd, Outline);



                            ImGui::GetForegroundDrawList()->AddLine(CurrentMin, ImVec2(CurrentMin.x, CurrentMax.y), Inline);
                            ImGui::GetForegroundDrawList()->AddLine(CurrentMin - ImVec2(1, 2), ImVec2(CurrentMin.x - 1, CurrentMax.y), Outline);

                            if (i < tabCount - 1) {
                                ImGui::GetForegroundDrawList()->AddLine(ImVec2(CurrentMax.x - 1, CurrentMin.y), CurrentMax - ImVec2(1, 0), Inline);
                                ImGui::GetForegroundDrawList()->AddLine(ImVec2(CurrentMax.x - 1, CurrentMin.y), CurrentMax - ImVec2(1, 0), Inline);
                               
                            }
                            
                        }


                        LastMin = CurrentMin;
                        LastMax = CurrentMax;


                        if (i < tabCount - 1) {
                            ImGui::SameLine(0.00f, spacing);
                        }
                    }
                    wp = ImGui::GetWindowPos();

                    ImGui::GetForegroundDrawList()->AddLine(
                        { wp.x + 1, wp.y + 21 },
                        { SelectedMin.x, wp.y + 21 },
                        Inline
                    );
                    ImGui::GetForegroundDrawList()->AddLine(
                        { SelectedMax.x - 1, wp.y + 21 },
                        { wp.x + totalWidth - 1, wp.y + 21 },
                        Inline
                    );
                    style->Colors[ImGuiCol_ChildBg] = WindowColor;

                    if (currenttab == "Visuals")
                    {
                        ImGui::BeginChild("##1F", { ImGui::GetContentRegionAvail().x / 2, ImGui::GetContentRegionAvail().y }, false);

                        style->Colors[ImGuiCol_ChildBg] = ChildColor;
                        style->Colors[ImGuiCol_Border] = Inline.Value;
                        ImGui::BeginChild("##1", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Outline
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                            AccentColor
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                            ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                        );
                        ImGui::TextColored(TextTitle.Value, "Player ESP");
                        ImGui::Checkbox("Enabled", &Globals::Esp::Enabled);
                        ImGui::Checkbox("Box", &Globals::Esp::Box); ImGui::SameLine();
                        ImGui::ColorEdit4("##Box Color", Globals::Esp::Colors::Box, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

                        ImGui::Checkbox("Box Glow", &Globals::Esp::BoxGlow); ImGui::SameLine();
                        ImGui::ColorEdit4("##Box Glow Color", Globals::Esp::Colors::BoxGlow, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

                        ImGui::Checkbox("Name", &Globals::Esp::Name); ImGui::SameLine();
                        ImGui::ColorEdit4("##Name Color", Globals::Esp::Colors::Name, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

                        ImGui::Checkbox("Distance", &Globals::Esp::Distance); ImGui::SameLine();
                        ImGui::ColorEdit4("##Distance Color", Globals::Esp::Colors::Distance, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

                        ImGui::Checkbox("Tool", &Globals::Esp::Tool); ImGui::SameLine();
                        ImGui::ColorEdit4("##Tool Color", Globals::Esp::Colors::Tool, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

                        ImGui::Checkbox("Chams", &Globals::Esp::Chams); ImGui::SameLine();
                        ImGui::ColorEdit4("##Chams Color", Globals::Esp::Colors::Chams, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

                        ImGui::Checkbox("Chams Outlines", &Globals::Esp::ChamsOutlines); ImGui::SameLine();
                        ImGui::ColorEdit4("##Chams Outlines", Globals::Esp::Colors::ChamsOutlines, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

                        ImGui::Checkbox("Chams Glow", &Globals::Esp::ChamsGlow); ImGui::SameLine();
                        ImGui::ColorEdit4("##Chams Glow", Globals::Esp::Colors::ChamsGlow, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

                        ImGui::Checkbox("Health Bar", &Globals::Esp::HealthBar); ImGui::SameLine();
                        ImGui::ColorEdit4("##Health Bar", Globals::Esp::Colors::HealthBar, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

                        ImGui::Checkbox("Health Bar Glow", &Globals::Esp::HealthBarGlow);

                        ImGui::Checkbox("Team", &Globals::Esp::Team);
                        if (Globals::Esp::Team)
                        {
                            const char* teamModeItems[] = { "Team Sign", "Team Colored ESP", "Team Colored ESP (No Title)" };
                            ImGui::Combo("##TeamMode", &Globals::Esp::TeamMode, teamModeItems, 3);
                        }

                        ImGui::Checkbox("Leaderstats", &Globals::Esp::Leaderstats); ImGui::SameLine();
                        ImGui::ColorEdit4("##LeaderStats", Globals::Esp::Colors::LeaderStats, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

                        //ImGui::Checkbox("Region", &Globals::Esp::Region); ImGui::SameLine();
                        //ImGui::ColorEdit4("##Region", Globals::Esp::Colors::Region, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

                        ImGui::Checkbox("Tracers", &Globals::Esp::Tracers); ImGui::SameLine();
                        ImGui::ColorEdit4("##Tracers", Globals::Esp::Colors::Tracers, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

                        ImGui::Checkbox("Skeleton", &Globals::Esp::Skeleton); ImGui::SameLine();
                        ImGui::ColorEdit4("##Skeleton", Globals::Esp::Colors::Skeleton, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
                        ImGui::Checkbox("Avatar", &Globals::Esp::Avatar);
                        if (Globals::Esp::Avatar)
                        {
                            ImGui::Text("Avatar Size");
                            ImGui::SliderInt("##Avatar Size", &Globals::Esp::IconSize, 1, 50);
                            ImGui::Text("Avatar Offset");
                            ImGui::SliderInt("##Avatar Offset", &Globals::Esp::OffsetOffBoxAvatar, 1, 50);
                        }
                        ImGui::Checkbox("Offscreen Arrows", &Globals::Esp::OffscreenArrows); ImGui::SameLine();
                        ImGui::ColorEdit4("##OffscreenArrow", Globals::Esp::OffscreenArrowColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
                        if (Globals::Esp::OffscreenArrows)
                        {
                            ImGui::Text("Arrow Size");
                            ImGui::SliderFloat("##ArrowSize", &Globals::Esp::OffscreenArrowSize, 5.0f, 50.0f);
                            ImGui::Text("Edge Padding");
                            ImGui::SliderFloat("##ArrowPadding", &Globals::Esp::OffscreenArrowPadding, 5.0f, 150.0f);
                            ImGui::Text("Min Distance");
                            ImGui::SliderInt("##ArrowMinDist", &Globals::Esp::OffscreenArrowMinDist, 1, 50);
                        }
                        ImGui::EndChild();
                        ImGui::EndChild();
                        ImGui::SameLine();
                        ImGui::BeginChild("##2F", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, false);

                        style->Colors[ImGuiCol_ChildBg] = ChildColor;
                        style->Colors[ImGuiCol_Border] = Inline.Value;
                        ImGui::BeginChild("##1", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Outline
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                            AccentColor
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                            ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                        );
                        ImGui::TextColored(TextTitle.Value, "Visual Settings");

                        ImGui::Checkbox("Use display name", &Globals::Esp::UseDisplayName);
                        ImGui::Checkbox("Health Number", &Globals::Esp::HealthNumber); ImGui::SameLine();
                        ImGui::ColorEdit4("##Health Number", Globals::Esp::Colors::HealthNumber, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
                        ImGui::Checkbox("Healthbar Background", &Globals::Esp::HealthBarBackGround);
                        {
                            static const char* Options[] = { "Static", "Health-Based" };
                            ImGui::Text("Health bar color Type");
                            ImGui::Combo("Health bar color type", &Globals::Esp::HealthBarColorType, Options, IM_ARRAYSIZE(Options));
                        }



                        {
                            static const char* Options[] = { "Default","Visitor", "Smallest Pixel Font", "Bold verdana", "Lato Bold" };
                            ImGui::Text("Font");
                            ImGui::Combo("Font", &Globals::Esp::Font, Options, IM_ARRAYSIZE(Options));
                        }
                        ImGui::Checkbox("Local ESP", &Globals::Esp::LocalPlayerESP);

                        ImGui::Checkbox("Max Distance", &Globals::Esp::MaxDistance);
                        ImGui::SliderInt("##MaxDistanceV", &Globals::Esp::MaxDistanceValue, 10, 30000);
                        ImGui::Text("Chams Outline Thickness");
                        ImGui::SliderInt("##ChamsThickness", &Globals::Esp::ChamsOutlineThickness, 1, 5);
                        ImGui::Checkbox("Inherit Body Colors Chams", &Globals::Esp::InheritBodyColorChams);
                        ImGui::Checkbox("Filter Unknown Cham Parts", &Globals::Esp::FilterUnknownChamsParts);
                        {
                            static const char* Options[] = { "Convex","Highlight" };
                            ImGui::Text("Chams type");
                            ImGui::Combo("Chams type", &Globals::Esp::ChamsType, Options, IM_ARRAYSIZE(Options));
                        }
                        {
                            static const char* Options[] = { "Cursor","Bottom", "Top"};
                            ImGui::Text("Tracer Postion");
                            ImGui::Combo("Tracer Postion", &Globals::Esp::TracersPosition, Options, IM_ARRAYSIZE(Options));
                        }
                        ImGui::Checkbox("Corner Box", &Globals::Esp::CornerBox);
                        ImGui::Text("Box Thickness");
                        ImGui::SliderInt("##BoxThickness", &Globals::Esp::BoxThickness, 1, 5);
                        ImGui::Text("Skeleton Thickness");
                        ImGui::SliderInt("##SkeletonThickness", &Globals::Esp::SkeletonThickness, 1, 5);
                        ImGui::Text("Tracer Thickness");
                        ImGui::SliderInt("##TracerThickness", &Globals::Esp::TracerThickness, 1, 5);

                        if (Globals::GameID == SDK::Games::MurderMystery2)
                        {
                            GameSupport::Render(TextTitle);
                        }

                        ImGui::EndChild();
                        ImGui::EndChild();
                    }
                    if (currenttab == "Aimbot")
                    {

                        ImGui::BeginChild("##1F", { ImGui::GetContentRegionAvail().x / 2, ImGui::GetContentRegionAvail().y }, false);

                        style->Colors[ImGuiCol_ChildBg] = ChildColor;
                        style->Colors[ImGuiCol_Border] = Inline.Value;
                        ImGui::BeginChild("##1", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y * 0.55f }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Outline
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                            AccentColor
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                            ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                        );
                        ImGui::TextColored(TextTitle.Value, "Aimbot");
                        ImGui::Checkbox("Enabled", &Globals::Aimbot::Enabled);
                        ImGui::SameLine(ImGui::GetWindowSize().x - 36);
                        Keybind(&Globals::Aimbot::AimbotKey, { 30,14 });
                        ImGui::Checkbox("Visible Check", &Globals::Aimbot::VisibleCheck);
                        ImGui::Checkbox("Sticky Target", &Globals::Aimbot::StickyTarget);
                        {
                            static const char* Options[] = { "Mouse","Memory", "Silent" };
                            ImGui::Text("Aim Type");
                            ImGui::Combo("Aim Type", &Globals::Aimbot::AimType, Options, IM_ARRAYSIZE(Options));
                        }
                        if (Globals::Aimbot::AimType == 2)
                        {
                            static const char* SilentOptions[] = { "Viewport", "Mouse", "Raycast", "Magic Bullet", "Phantom" };
                            ImGui::Text("Silent Mode");
                            ImGui::Combo("Silent Mode", &Globals::Aimbot::SilentMode, SilentOptions, IM_ARRAYSIZE(SilentOptions));
                        }
                        {
                            static const char* Options[] = { "Head", "HumanoidRootPart", "Closest", "Left Arm", "Right Arm", "Left Leg", "Right Leg", "All Bones" };
                            ImGui::Text("Hitbox");
                            ImGui::Combo("Hitbox", &Globals::Aimbot::Hitbox, Options, IM_ARRAYSIZE(Options));
                        }
                        {
                            static const char* Options[] = { "Crosshair", "Character", "Lowest HP", "Highest HP" };
                            ImGui::Text("Priority");
                            ImGui::Combo("Priority", &Globals::Aimbot::TargetPriority, Options, IM_ARRAYSIZE(Options));
                        }
                        ImGui::Checkbox("Prediction", &Globals::Aimbot::Prediction);
                        if (Globals::Aimbot::Prediction)
                        {
                            ImGui::Text("Prediction X");
                            ImGui::SliderFloat("##X", &Globals::Aimbot::PredictionX, 1.0f, 15.0f);
                            ImGui::Text("Prediction Y");
                            ImGui::SliderFloat("##Y", &Globals::Aimbot::PredictionY, 1.0f, 15.0f);
                        }

                        ImGui::Checkbox("Smoothning", &Globals::Aimbot::Smoothning);
                        if (Globals::Aimbot::Smoothning)
                            ImGui::SliderFloat("##SmoothningV", &Globals::Aimbot::SmoothingValue, 0.1f, 1.0f);
                        ImGui::Checkbox("Humanize", &Globals::Aimbot::Humanize);
                        if (Globals::Aimbot::Humanize)
                            ImGui::SliderFloat("##HumanizeV", &Globals::Aimbot::HumanizeStrength, 0.05f, 1.0f);
                        ImGui::EndChild();
                        ImGui::BeginChild("##2", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y  }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Outline
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                            AccentColor
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                            ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                        );
                        ImGui::TextColored(TextTitle.Value, "Rage");
                        if (Globals::Misc::RiskyFunctions)
                        {
                            ImGui::Checkbox("Target Loop TP", &Globals::Aimbot::Rage::SpamTP);
                            ImGui::Checkbox("Target Orbit", &Globals::Aimbot::Rage::Orbit);
                            if (Globals::Aimbot::Rage::Orbit)
                            {
                                ImGui::Text("Orbit Speed");
                                ImGui::SliderFloat("Speed##Orbit", &Globals::Aimbot::Rage::OrbitSettings::orbitSpeed, 1.0f, 100.0f);
                                ImGui::Text("Orbit Radius");
                                ImGui::SliderFloat("Radius##Orbit", &Globals::Aimbot::Rage::OrbitSettings::radius, 1.0f, 50.0f);
                                ImGui::Text("Orbit Height");
                                ImGui::SliderFloat("Height##Orbit", &Globals::Aimbot::Rage::OrbitSettings::heightOffset, -20.0f, 20.0f);
                            }
                        }

                        ImGui::Separator();
                        ImGui::Checkbox("Magic Bullet", &Globals::Aimbot::Rage::MagicBullet);
                        if (Globals::Raycast::Enabled)
                        {
                            ImGui::Checkbox("Beta RageBot", &Globals::Aimbot::Rage::RageBot);
                            if (Globals::Aimbot::Rage::RageBot)
                            {
                                static const char* RageBotModes[] = { "Memory", "Silent" };
                                ImGui::Text("RageBot Mode");
                                ImGui::Combo("##RageBotMode", &Globals::Aimbot::Rage::RageBotMode, RageBotModes, IM_ARRAYSIZE(RageBotModes));
                            }
                        }
                        else
                        {
                            ImGui::TextDisabled("Enable Raycast for RageBot");
                        }

                        ImGui::EndChild();
                        ImGui::EndChild();
                        ImGui::SameLine();
                        style->Colors[ImGuiCol_ChildBg] = WindowColor;
                        ImGui::BeginChild("##2F", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, false);

                        style->Colors[ImGuiCol_ChildBg] = ChildColor;
                        style->Colors[ImGuiCol_Border] = Inline.Value;
                        ImGui::BeginChild("##1", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y / 2 }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Outline
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                            AccentColor
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                            ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                        );
                        ImGui::TextColored(TextTitle.Value, "Settings");
                        ImGui::Checkbox("Enable FOV", &Globals::Aimbot::EnableFOV);
                        if (Globals::Aimbot::EnableFOV)
                        {
                            ImGui::SliderInt("##FovValue", &Globals::Aimbot::FOV, 10, 1000,
                                Globals::Aimbot::FOV >= 1000 ? "Fullscreen" : "%d");
                            ImGui::Checkbox("Draw FOV", &Globals::Aimbot::DrawFOV); ImGui::SameLine();
                            ImGui::ColorEdit4("##DrawFOV", Globals::Aimbot::FovColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

                            ImGui::Checkbox("Fill FOV", &Globals::Aimbot::FovSettings::FillFov); ImGui::SameLine();
                            ImGui::ColorEdit4("##FillFOV", Globals::Aimbot::FovSettings::FillColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
                        }
                       



                        ImGui::Checkbox("HitSounds", &Globals::Aimbot::Hits::HitSounds);
                        if (Globals::Aimbot::Hits::HitSounds)
                        {
                            static const char* Options[] = { ("amongus"), ("skeet"),("beep"), ("bonk"), ("bubble"), ("cod"), ("csgo"), ("fairy"), ("fatality"), ("osu"), ("rust"), ("bameware") };
                            ImGui::Combo("HitSound", &Globals::Aimbot::Hits::HitSound, Options, IM_ARRAYSIZE(Options));
                        }
                        ImGui::Checkbox("Hit tracers", &Globals::Aimbot::Hits::HitTracers); ImGui::SameLine();
                        ImGui::ColorEdit4("##Hit tracers", Globals::Aimbot::Hits::HitTracersColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
                        ImGui::Checkbox("Hit Markers", &Globals::Aimbot::Hits::HitMarkers); ImGui::SameLine();
                        ImGui::ColorEdit4("##Hit Markers", Globals::Aimbot::Hits::HitMarkersColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
                        if (Crosshair && Globals::Aimbot::AimType == 2)
                        {
                            ImGui::Checkbox("Silent Crosshair", &Globals::Aimbot::SilentCrosshair);
                            if (Globals::Aimbot::SilentCrosshair)
                            {
                                ImGui::Checkbox("Silent Crosshair Tracer", &Globals::Aimbot::SilentCrosshairTracer); ImGui::SameLine();
                                ImGui::ColorEdit4("##Silent Tracer Color", Globals::Aimbot::SilentCrosshairTracerColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
                            }

                        }
                        ImGui::EndChild();
                        ImGui::BeginChild("##2", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Outline
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                            AccentColor
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                            ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                        );
                        ImGui::TextColored(TextTitle.Value, "Triggerbot");
                        ImGui::Checkbox("Enabled", &Globals::TriggerBot::Enabled);
                        ImGui::SameLine(ImGui::GetWindowSize().x - 36);
                        Keybind(&Globals::TriggerBot::Key, { 30,14 });
                        ImGui::Checkbox("Visible Check##TB", &Globals::TriggerBot::VisibleCheck);
                        ImGui::Text("Delay");
                        ImGui::SliderInt("##D", &Globals::TriggerBot::Delay, 0, 1000);
                        ImGui::Text("Threshold");
                        ImGui::SliderInt("##T", &Globals::TriggerBot::Threshold, 0, 1000);
                        ImGui::Checkbox("Tool Check", &Globals::TriggerBot::ToolCheck);
                        ImGui::EndChild();
                        ImGui::EndChild();
                    }
                    if (currenttab == "Anti Aim")
                    {
                        if (Globals::Misc::RiskyFunctions)
                        {
                        ImGui::BeginChild("##1F", { ImGui::GetContentRegionAvail().x / 2, ImGui::GetContentRegionAvail().y }, false);

                        style->Colors[ImGuiCol_ChildBg] = ChildColor;
                        style->Colors[ImGuiCol_Border] = Inline.Value;
                        ImGui::BeginChild("##1", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Outline
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                            AccentColor
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                            ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                        );
                        ImGui::TextColored(TextTitle.Value, "Main");
                        ImGui::Checkbox("Enabled", &Globals::World::Movement::Spinbot);
                        static const char* YawOptions[] = { "Default", "Spinbot", "Backward", "Jitter", "Random" };
                        ImGui::Text("Yaw");
                        ImGui::Combo("##Yaw", &Globals::World::Movement::AntiAimYaw, YawOptions, IM_ARRAYSIZE(YawOptions));
                        if (Globals::World::Movement::AntiAimYaw == 1)
                        {
                            ImGui::SliderInt("##SpinBotSpeed", &Globals::World::Movement::SpinbotSpeed, 1, 100);
                            ImGui::Checkbox("Upside down", &Globals::World::Movement::UpsideDown);
                        }
                        static const char* PitchOptions[] = { "Default", "Down", "Up", "Jitter" };
                        ImGui::Text("Pitch");
                        ImGui::Combo("##Pitch", &Globals::World::Movement::AntiAimPitch, PitchOptions, IM_ARRAYSIZE(PitchOptions));
                        ImGui::EndChild();
                        ImGui::EndChild();
                        ImGui::SameLine();
                        style->Colors[ImGuiCol_ChildBg] = WindowColor;
                        ImGui::BeginChild("##2F", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, false);

                        style->Colors[ImGuiCol_ChildBg] = ChildColor;
                        style->Colors[ImGuiCol_Border] = Inline.Value;
                        ImGui::BeginChild("##2", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Outline
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                            AccentColor
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                            ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                        );
                        ImGui::TextColored(TextTitle.Value, "Other");
                        ImGui::Checkbox("Desync##AntiAim", &Globals::Misc::Desync);
                        ImGui::SameLine(ImGui::GetWindowSize().x - 36);
                        Keybind(&Globals::Misc::DesyncBind, { 30,14 });
                        ImGui::Checkbox("Peek", &Globals::World::Movement::Peek);
                        ImGui::SameLine(ImGui::GetWindowSize().x - 36);
                        Keybind(&Globals::World::Movement::PeekKey, { 30,14 });
                        if (Globals::World::Movement::Peek)
                        {
                            ImGui::Text("Radius");
                            ImGui::SliderFloat("##PeekRadius", &Globals::World::Movement::PeekRadius, 1.0f, 20.0f);
                            ImGui::ColorEdit4("##PeekColor", Globals::World::Movement::PeekColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
                            ImGui::Checkbox("TP on Click", &Globals::World::Movement::PeekClickTP);
                        }
                        ImGui::EndChild();
                        ImGui::EndChild();
                        }
                        else
                        {
                            ImGui::TextColored(TextTitle.Value, "Anti-Aim");
                            ImGui::Separator();
                            ImGui::TextColored(ImVec4(1.0f, 0.3f, 0.3f, 1.0f), "Anti-Aim is a risky feature.\nEnable \"Risky Functions\"\nin Misc to configure it.");
                        }
                    }
                    if (currenttab == "Exploits")
                    {
                        ImGui::BeginChild("##1F", { ImGui::GetContentRegionAvail().x / 2, ImGui::GetContentRegionAvail().y }, false);

                        style->Colors[ImGuiCol_ChildBg] = ChildColor;
                        style->Colors[ImGuiCol_Border] = Inline.Value;
                        ImGui::BeginChild("##1", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Outline
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                            AccentColor
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                            ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                        );
                        ImGui::TextColored(TextTitle.Value, "Movement");

                        if (Globals::Misc::RiskyFunctions)
                        {
                        ImGui::Checkbox("Fly", &Globals::World::Movement::Fly);
                        ImGui::SameLine(ImGui::GetWindowSize().x - 36);
                        Keybind(&Globals::World::Movement::FlyKey, { 30,14 });
                        if (Globals::World::Movement::Fly)
                        {
                            static const char* FlyMethods[] = { "CFrame", "Velocity" };
                            ImGui::Combo("##FlyMethod", &Globals::World::Movement::FlyMethod, FlyMethods, IM_ARRAYSIZE(FlyMethods));
                            ImGui::SliderFloat("##FlySpeed", &Globals::World::Movement::FlySpeed, 1.0f, 100.0f);
                        }

                        ImGui::Checkbox("Speed", &Globals::World::Movement::Speed);
                        ImGui::SameLine(ImGui::GetWindowSize().x - 36);
                        Keybind(&Globals::World::Movement::SpeedKey, { 30,14 });
                        if (Globals::World::Movement::Speed)
                        {
                            static const char* SpeedMethods[] = { "CFrame", "Velocity" };
                            ImGui::Combo("##SpeedMethod", &Globals::World::Movement::SpeedMethod, SpeedMethods, IM_ARRAYSIZE(SpeedMethods));
                            ImGui::SliderFloat("##SpeedV", &Globals::World::Movement::SpeedValue, 1.0f, 100.0f);
                        }

                        ImGui::Checkbox("Noclip", &Globals::World::Movement::Noclip);
                        ImGui::SameLine(ImGui::GetWindowSize().x - 36);
                        Keybind(&Globals::World::Movement::NoclipKey, { 30,14 });
                        }

                        ImGui::Checkbox("Infinite Jump", &Globals::World::Movement::InfiniteJump);
                        if (Globals::Misc::RiskyFunctions)
                        {
                            if (Globals::World::Movement::InfiniteJump)
                            {
                                ImGui::Checkbox("Jump Power", &Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPower);
                                if (Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPower)
                                    ImGui::SliderFloat("##CustomJumpPower", &Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPowerValue, 1.0f, 300.0f);
                            }
                            ImGui::Checkbox("WalkSpeed", &Globals::World::Movement::WalkSpeed);
                            if (Globals::World::Movement::WalkSpeed)
                                ImGui::SliderFloat("##WalkSpeed", &Globals::World::Movement::WalkSpeedValue, 1.0f, 200.0f);
                        }

                        ImGui::EndChild();
                        ImGui::EndChild();
                        ImGui::SameLine();
                        style->Colors[ImGuiCol_ChildBg] = WindowColor;
                        ImGui::BeginChild("##2F", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, false);

                        float rightColH = ImGui::GetContentRegionAvail().y;
                        style->Colors[ImGuiCol_ChildBg] = ChildColor;
                        style->Colors[ImGuiCol_Border] = Inline.Value;
                        ImGui::BeginChild("##2", { ImGui::GetContentRegionAvail().x, rightColH * 0.68f }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Outline
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                            AccentColor
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                            ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                        );
                        ImGui::TextColored(TextTitle.Value, "Other");
                        if (ImGui::Button("Force reset", { ImGui::GetContentRegionAvail().x, 17 }))
                        {
                            if (SDK::Cache::LocalPlayer.Humanoid.Address)
                                SDK::Memory->Write<float>(SDK::Cache::LocalPlayer.Humanoid.Address + SDK::Offsets::Health, 0.0f);
                        }
                        ImGui::Checkbox("Fov Changer", &Globals::World::CameraFOV);
                        if (Globals::World::CameraFOV)
                            ImGui::SliderInt("##CameraFOV", &Globals::World::CameraFOVValue, 10, 135);
                        ImGui::Checkbox("Zoom##1", &Globals::World::Zoom);
                        ImGui::SameLine(ImGui::GetWindowSize().x - 36);
                        Keybind(&Globals::World::ZoomKey, { 30,14 });
                        if (Globals::World::Zoom)
                            ImGui::SliderInt("##ZoomValue", &Globals::World::ZoomValue, 5, 135);
                        ImGui::Checkbox("Third Person", &Globals::World::Movement::ThirdPerson);
                        ImGui::SameLine(ImGui::GetWindowSize().x - 36);
                        Keybind(&Globals::World::Movement::ThirdPersonKey, { 30,14 });
                        if (Globals::World::Movement::ThirdPerson)
                        {
                            ImGui::SliderFloat("##ThirdPersonX", &Globals::World::Movement::ThirdPersonX, -15.0f, 15.0f, "X: %.1f");
                            ImGui::SliderFloat("##ThirdPersonY", &Globals::World::Movement::ThirdPersonY, -15.0f, 15.0f, "Y: %.1f");
                            ImGui::SliderFloat("##ThirdPersonZ", &Globals::World::Movement::ThirdPersonZ, -15.0f, 15.0f, "Z: %.1f");
                        }
                        ImGui::Checkbox("Freecam", &Globals::World::Movement::Freecam);
                        ImGui::SameLine(ImGui::GetWindowSize().x - 36);
                        Keybind(&Globals::World::Movement::FreecamKey, { 30,14 });
                        if (Globals::World::Movement::Freecam)
                            ImGui::SliderFloat("##FreecamSpeed", &Globals::World::Movement::FreecamSpeed, 0.001f, 0.5f);

                        ImGui::EndChild();

                        style->Colors[ImGuiCol_ChildBg] = ChildColor;
                        style->Colors[ImGuiCol_Border] = Inline.Value;
                        ImGui::BeginChild("##3", { ImGui::GetContentRegionAvail().x, 0 }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Outline
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                            AccentColor
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                            ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                        );
                        ImGui::TextColored(TextTitle.Value, "Exploits");
                        if (Globals::Misc::RiskyFunctions)
                        {
                            ImGui::Checkbox("Time Manipulation", &Globals::World::TimeManipulation);
                            if (Globals::World::TimeManipulation)
                                ImGui::SliderFloat("##TimeManipulation", &Globals::World::TimeManipulationValue, 80.0f, 720.0f, "%.0f FPS");
                        }

                        ImGui::EndChild();
                        ImGui::EndChild();
                    }
                    if (currenttab == "Misc")
                    {
                        ImGui::BeginChild("##1F", { ImGui::GetContentRegionAvail().x / 2, ImGui::GetContentRegionAvail().y / 1.5f }, false);

                        style->Colors[ImGuiCol_ChildBg] = ChildColor;
                        style->Colors[ImGuiCol_Border] = Inline.Value;
                        ImGui::BeginChild("##1", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Outline
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                            AccentColor
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                            ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                        );
                        ImGui::TextColored(TextTitle.Value, "Configs");
                        style->Colors[ImGuiCol_ChildBg] = WindowColor;
                        style->Colors[ImGuiCol_Border] = Outline;
                        ImGui::BeginChild("##Waypoints", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y - 105 }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Inline
                        );
                        static std::string SelectedConfig;
                        static char ConfigName[158] = "";

                        style->Colors[ImGuiCol_ChildBg] = ChildColor;
                        style->Colors[ImGuiCol_Border] = Inline;

                        for (const std::string& Config : ConfigListSaved)
                        {
                            ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize(Config.c_str()).x) / 2);

                            if (SelectedConfig == Config)
                                ImGui::TextColored(AccentColor.Value, Config.c_str());
                            else
                                ImGui::Text(Config.c_str());

                            if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0)) {
                                SelectedConfig = Config;
                                strncpy_s(ConfigName, Config.c_str(), IM_ARRAYSIZE(ConfigName));
                            }

                            ImGui::Separator();
                        }

                        ImGui::EndChild();

                        ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
                        ImGui::InputText("##SelectedConfig", ConfigName, IM_ARRAYSIZE(ConfigName));

                        std::string SelectedconfigPath = "C:\\Skidware\\Configs\\" + SelectedConfig + ".rocks";
                        std::string configPath = "C:\\Skidware\\Configs\\" + std::string(ConfigName) + ".rocks";

                        if (ImGui::Button("Load", { ImGui::GetContentRegionAvail().x, 17 }))
                        {
                            if (!SelectedConfig.empty() && std::filesystem::exists(SelectedconfigPath)) {
                                std::ifstream in(SelectedconfigPath);
                                std::string data((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
                                Config::Load(data);
                            }
                        }

                        if (ImGui::Button("Save", { ImGui::GetContentRegionAvail().x, 17 }))
                        {
                            if (!SelectedConfig.empty()) {
                                std::string data = Config::Save();
                                std::ofstream out(SelectedconfigPath);
                                out << data;
                            }
                        }

                        if (ImGui::Button("Delete", { ImGui::GetContentRegionAvail().x, 17 }))
                        {
                            if (!SelectedConfig.empty()) {
                                std::filesystem::remove(SelectedconfigPath);
                                RefreshConfigs();
                                SelectedConfig.clear();
                            }
                        }

                        if (ImGui::Button("Create", { ImGui::GetContentRegionAvail().x, 17 }))
                        {
                            if (strlen(ConfigName) > 0) {
                                std::string data = Config::Create();
                                std::string name = ConfigName;
                                std::string fullPath = "C:\\Skidware\\Configs\\" + name + ".rocks";

                                std::ofstream out(fullPath);
                                out << data;

                                RefreshConfigs();
                                SelectedConfig = name;
                            }
                        }

                        ImGui::EndChild();

                        ImGui::EndChild();
                        ImGui::SameLine();
                        ImGui::BeginChild("##2F", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, false);

                        style->Colors[ImGuiCol_ChildBg] = ChildColor;
                        style->Colors[ImGuiCol_Border] = Inline.Value;
                        ImGui::BeginChild("##1", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, true);
                        ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                            Outline
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                            AccentColor
                        );
                        ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                            ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                            ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                        );
                        ImGui::TextColored(TextTitle.Value, "Cheat Settings");
                        ImGui::Separator();
                        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.3f, 0.3f, 1.0f));
                        if (ImGui::Checkbox("Risky Functions", &Globals::Misc::RiskyFunctions))
                        {
                            if (!Globals::Misc::RiskyFunctions)
                                ConfigManager::DisableAllRiskyFeatures();
                            ConfigManager::SaveGlobalSettings();
                        }
                        ImGui::PopStyleColor();
                        if (ImGui::IsItemHovered())
                            ImGui::SetTooltip("RISKY - these will very likely get you banned IN-GAME (not from Roblox itself).\nGates: Fly, Speed, WalkSpeed, Jump Power, Anti-Aim, Noclip, Target Loop TP, Orbit.");
                        ImGui::TextColored(ImVec4(1.0f, 0.3f, 0.3f, 1.0f), "[!] Use at your own risk");

                        ImGui::Separator();
                        ImGui::Checkbox("Teamcheck", &Globals::Misc::TeamCheck);
                        ImGui::Checkbox("Vsync", &Globals::Vsync);
                        ImGui::Checkbox("Streamproof", &Globals::Misc::StreamProof);
                        ImGui::Checkbox("Watermark", &Globals::Watermark);
                        ImGui::Checkbox("Notifications", &Globals::Notifications);

                        ImGui::Separator();
                        ImGui::Checkbox("Raycast", &Globals::Raycast::Enabled);
                        if (Globals::Raycast::Enabled)
                        {
                            static const char* RayMethods[] = { "External", "Internal" };
                            ImGui::Text("Raycast Method");
                            ImGui::Combo("##RayMethod", &Globals::Raycast::Method, RayMethods, IM_ARRAYSIZE(RayMethods));
                            ImGui::Text("Delay (ms)");
                            ImGui::SliderInt("##RayDelay", &Globals::Raycast::Delay, 50, 2000);
                            ImGui::Checkbox("Preview", &Globals::Raycast::Preview);
                        }

                        if (ImGui::Button("Rescan", { ImGui::GetContentRegionAvail().x, 17 }))
                        {
                            SDK::Scan();
                        }

                        if (ImGui::Button("Exit", { ImGui::GetContentRegionAvail().x, 17 }))
                        {
                            exit(0);
                        }

                        ImGui::EndChild();
                        ImGui::EndChild();
                    }
                    
                    

                    ImGui::EndChild();
                    ImGui::EndChild();
                    ImGui::End();
                }
                if (DockButtons[2].Enabled)
                {


                    ImGui::SetNextWindowPos(SavedPositions::Preview.pos, ImGuiCond_Appearing);
                    ImGui::SetNextWindowSize({ 322,391 });
                    ImGui::Begin("Preview ", nullptr, ImGuiWindowFlags_NoTitleBar
                        | ImGuiWindowFlags_NoResize);
                    SavedPositions::Preview.pos = ImGui::GetWindowPos();
                    SavedPositions::Preview.size = ImGui::GetWindowSize();
                    DragHeader("##drag_preview");
                    ImGui::GetWindowDrawList()->AddRectFilledMultiColor(ImGui::GetWindowPos(), ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x, 25), ChildColor, ChildColor, WindowColor, WindowColor);
                    //ImGui::GetBackgroundDrawList()->AddShadowRect(ImGui::GetWindowPos(), ImGui::GetWindowPos() + ImGui::GetWindowSize(), ThemeColor, 30, { 0,0 });
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor);
                    if (MenuGlow)
                        ImGui::GetBackgroundDrawList()->AddShadowRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor, MenuGlowFloat, { 0,0 });
                    ImGui::SetCursorPos(ImVec2(6, 3));
                    ImGui::TextColored(AccentColor.Value, "Preview ");
                    ImGui::SameLine(ImGui::GetContentRegionAvail().x);
                    ImGui::Text("x");
                    if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0))
                    {
                        DockButtons[2].Enabled = false;
                    }
                    style->Colors[ImGuiCol_Border] = Inline.Value;
                    ImGui::BeginChild("##c", ImGui::GetContentRegionAvail(), true);
                    ImVec2 p = ImGui::GetWindowPos();
                    ImVec2 s = ImGui::GetWindowSize();
                    ImVec2 i = ImGui::GetContentRegionAvail();
                    i.x = (std::max)(i.x, 220.0f);
                    i.y = (std::max)(i.y, 300.0f);
                    ImVec2 pos = p + (s - i) * 0.5f;
                    pos = ImVec2(std::floor(pos.x), std::floor(pos.y));
                    ImGui::GetWindowDrawList()->AddRect(p + ImVec2(1, 1), p + s - ImVec2(1, 1), Outline);

                    static bool s_Preview3DInit = false;
                    if (!s_Preview3DInit)
                    {
                        s_Preview3DInit = true;
                        if (g_avatarPreview.Initialize(g_pd3dDevice, g_pd3dDeviceContext, (unsigned)i.x, (unsigned)i.y))
                        {
                            g_avatarPreview.LoadModelFromMemory(g_PreviewModelOBJData, g_PreviewModelOBJSize);
                            g_avatarPreview.LoadTextureFromMemory(g_PreviewModelTexture, g_PreviewModelTextureSize);
                            g_avatarPreview.SetAutoSpin(true);
                        }
                    }

                    ImGuiIO& io = ImGui::GetIO();

                    int64_t localUid = 0;
                    if (Globals::LocalPlayer.Address)
                    {
                        try { localUid = Globals::LocalPlayer.UserId(); }
                        catch (...) { localUid = 0; }
                    }
                    if (Globals::Esp::Avatar && localUid > 0 && g_AvatarPreviewUserId != localUid)
                        FetchAvatarPreview(localUid);

                    if (g_avatarPreview.IsReady() && g_avatarPreview.GetTextureID() != nullptr)
                    {
                        ImGui::InvisibleButton("##preview3d", i);
                        bool hv = ImGui::IsItemHovered();
                        if (hv && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
                            g_avatarPreview.SetAutoSpin(!g_avatarPreview.IsAutoSpinning());
                        if (ImGui::IsItemActive() && ImGui::IsMouseDragging(ImGuiMouseButton_Left, 3.0f))
                        {
                            g_avatarPreview.SetAutoSpin(false);
                            g_avatarPreview.AddRotationDelta(io.MouseDelta.x * (3.14f / 180.0f) * 0.6f, io.MouseDelta.y * (3.14f / 180.0f) * 0.6f);
                        }
                        if (hv && io.MouseWheel != 0.0f)
                            g_avatarPreview.AddZoom(io.MouseWheel * 0.18f);

                        const ImVec4 bg = style->Colors[ImGuiCol_ChildBg];
                        g_avatarPreview.SetClearColor(bg.x, bg.y, bg.z);
                        if (Globals::Esp::Chams)
                            g_avatarPreview.SetTint(PreviewTeamColor(Globals::Esp::Colors::Chams).Value.x, PreviewTeamColor(Globals::Esp::Colors::Chams).Value.y, PreviewTeamColor(Globals::Esp::Colors::Chams).Value.z);
                        else
                            g_avatarPreview.SetTint(1.0f, 1.0f, 1.0f);
                        g_avatarPreview.SetSolid(Globals::Esp::Chams);
                        g_avatarPreview.Update(io.DeltaTime);
                        ImGui::GetWindowDrawList()->AddImage((ImTextureID)g_avatarPreview.GetTextureID(), pos, pos + i, ImVec2(0, 0), ImVec2(1, 1));
                    }
                    else
                    {
                        const char* msg = Globals::LocalPlayer.Address ? "waiting for character..." : "in game to show avatar";
                        ImVec2 ts = ImGui::CalcTextSize(msg);
                        ImVec2 tp = p + (s - ts) * 0.5f;
                        ImGui::GetWindowDrawList()->AddText(ImVec2(std::floor(tp.x), std::floor(tp.y)), ImColor(180, 180, 180), msg);
                    }
                    ImVec2 BoxMin, BoxMax;
                    {
                        float minU = 1e9f, minV = 1e9f, maxU = -1e9f, maxV = -1e9f;
                        bool ok = false;
                        if (g_avatarPreview.IsReady() && g_avatarPreview.GetProjectedUVBounds(minU, minV, maxU, maxV))
                        {
                            if (maxU > minU && maxV > minV)
                            {
                                BoxMin = pos + ImVec2(minU * i.x, minV * i.y);
                                BoxMax = pos + ImVec2(maxU * i.x, maxV * i.y);
                                ok = true;
                            }
                        }
                        if (!ok)
                        {
                            const float bw = 124.0f, bh = 311.0f;
                            const ImVec2 c = pos + i * 0.5f;
                            BoxMin = c - ImVec2(bw * 0.5f, bh * 0.5f);
                            BoxMax = c + ImVec2(bw * 0.5f, bh * 0.5f);
                        }
                    }
                    if (Globals::Esp::Skeleton)
                    {
                        std::vector<float> segs;
                        if (g_avatarPreview.IsReady() && g_avatarPreview.GetProjectedR6Skeleton(segs))
                        {
                            ImDrawList* dl = ImGui::GetWindowDrawList();
                            for (size_t k = 0; k + 3 < segs.size(); k += 4)
                            {
                                const ImVec2 a = pos + ImVec2(segs[k] * i.x, segs[k + 1] * i.y);
                                const ImVec2 b = pos + ImVec2(segs[k + 2] * i.x, segs[k + 3] * i.y);
                                dl->AddLine(a, b, PreviewTeamColor(Globals::Esp::Colors::Skeleton));
                            }
                        }
                    }
                    if (Globals::Esp::ChamsOutlines)
                    {
                        std::vector<std::array<std::pair<float, float>, 8>> partBoxes;
                        if (g_avatarPreview.IsReady() && g_avatarPreview.GetProjectedPartBoxes(partBoxes))
                        {
                            static const int edges[12][2] = {
                                { 0, 4 }, { 1, 5 }, { 2, 6 }, { 3, 7 },
                                { 0, 2 }, { 1, 3 }, { 4, 6 }, { 5, 7 },
                                { 0, 1 }, { 2, 3 }, { 4, 5 }, { 6, 7 }
                            };
                            const ImColor oc = PreviewTeamColor(Globals::Esp::Colors::ChamsOutlines);
                            ImDrawList* dl = ImGui::GetWindowDrawList();
                            for (const auto& b : partBoxes)
                            {
                                for (int e = 0; e < 12; ++e)
                                {
                                    const ImVec2 a = pos + ImVec2(b[edges[e][0]].first * i.x, b[edges[e][0]].second * i.y);
                                    const ImVec2 c2 = pos + ImVec2(b[edges[e][1]].first * i.x, b[edges[e][1]].second * i.y);
                                    dl->AddLine(a, c2, oc, Globals::Esp::ChamsOutlineThickness);
                                }
                            }
                        }
                    }
                    if (Globals::Esp::Box)
                    {
                        ImGui::GetWindowDrawList()->AddRect(
                            BoxMin + ImVec2(1, 1),
                            BoxMax - ImVec2(1, 1),
                            ImColor(0, 0, 0)
                        );
                        ImGui::GetWindowDrawList()->AddRect(
                            BoxMin - ImVec2(1, 1),
                            BoxMax + ImVec2(1, 1),
                            ImColor(0, 0, 0)
                        );
                        ImGui::GetWindowDrawList()->AddRect(
                            BoxMin,
                            BoxMax,
                            PreviewTeamColor(Globals::Esp::Colors::Box)
                        );
                    }
                    if (Globals::Esp::BoxGlow)
                    {
                        ImGui::GetWindowDrawList()->AddShadowRect(
                            BoxMin + ImVec2(2, 2),
                            BoxMax - ImVec2(2, 2),
                            PreviewTeamColor(Globals::Esp::Colors::BoxGlow),
                            50.0f,
                            { 0,0 }
                        );
                    }
                    if (Globals::Esp::Tracers)
                    {
                        ImVec2 head = ImVec2((BoxMin.x + BoxMax.x) / 2, BoxMin.y);
                        ImVec2 startPos = ImVec2(p.x + s.x / 2, p.y + s.y / 2);
                        if (Globals::Esp::TracersPosition == 2)
                            startPos = ImVec2(p.x + s.x / 2, p.y);
                        if (Globals::Esp::TracersPosition == 1)
                            startPos = ImVec2(p.x + s.x / 2, p.y + s.y);
                        ImGui::GetWindowDrawList()->AddLine(head, startPos, ImColor(0, 0, 0), 3.0f);
                        ImGui::GetWindowDrawList()->AddLine(head, startPos,
                            PreviewTeamColor(Globals::Esp::Colors::Tracers), 2.0f);
                    }
                    if (Globals::Esp::Avatar && g_AvatarPreviewTex && g_AvatarPreviewUserId == localUid)
                    {
                        int iconSize = Globals::Esp::IconSize;
                        float offsetAboveBox = Globals::Esp::OffsetOffBoxAvatar;
                        float centerX = (BoxMin.x + BoxMax.x) / 2.0f;
                        ImVec2 iconMin = ImVec2(centerX - iconSize / 2.0f, BoxMin.y - iconSize - offsetAboveBox);
                        ImVec2 iconMax = ImVec2(centerX + iconSize / 2.0f, BoxMin.y - offsetAboveBox);
                        ImGui::GetWindowDrawList()->AddImage((ImTextureID)g_AvatarPreviewTex, iconMin, iconMax);
                    }
                    if (Globals::Esp::Font == 1)
                        ImGui::PushFont(Visitor);
                    if (Globals::Esp::Font == 2)
                        ImGui::PushFont(SmallestPixel);
                    if (Globals::Esp::Font == 3)
                        ImGui::PushFont(BoldFont);
                    if (Globals::Esp::Font == 4)
                        ImGui::PushFont(LatoBold);
                    if (Globals::Esp::Name)
                    {
                        std::string previewName = Globals::LocalPlayer.Address ? Globals::LocalPlayer.Name() : "Player";
                        ImVec2 Size = ImGui::CalcTextSize(previewName.c_str());
                        ImVec2 NamePosition = ImVec2(BoxMin.x + (BoxMax.x - BoxMin.x) / 2 - Size.x / 2, BoxMin.y - 1 - Size.y);
                        ImGui::GetWindowDrawList()->AddText(NamePosition, PreviewTeamColor(Globals::Esp::Colors::Name), previewName.c_str());
                    }
                    if (Globals::Esp::Tool)
                    {
                        ImVec2 Size = ImGui::CalcTextSize("Tool");
                        ImVec2 TextPosition = ImVec2(BoxMin.x + (BoxMax.x - BoxMin.x) / 2 - Size.x / 2, BoxMax.y + 1);
                        ImGui::GetWindowDrawList()->AddText(TextPosition, PreviewTeamColor(Globals::Esp::Colors::Tool), "Tool");
                    }
                    if (Globals::Esp::Distance)
                    {
                        std::string DistanceText = "100m";
                        ImVec2 Size = ImGui::CalcTextSize(DistanceText.c_str());
                        ImVec2 TextPosition = ImVec2(BoxMin.x + (BoxMax.x - BoxMin.x) / 2 - Size.x / 2, BoxMax.y + 1);

                        if (Globals::Esp::Tool) {
                            TextPosition = ImVec2(BoxMin.x + (BoxMax.x - BoxMin.x) / 2 - Size.x / 2, BoxMax.y + ImGui::CalcTextSize("Tool").y + 2);
                        }

                        ImGui::GetWindowDrawList()->AddText(TextPosition, PreviewTeamColor(Globals::Esp::Colors::Distance), DistanceText.c_str());
                    }
                    int ESPPREVIEWOFFSET = 0;
                    if (Globals::Esp::Team && Globals::Esp::TeamMode <= 1)
                    {



                        ImGui::GetWindowDrawList()->AddText(ImVec2(BoxMax.x + 3, BoxMin.y + ESPPREVIEWOFFSET), ImColor(255, 255, 255), "Team");
                        ESPPREVIEWOFFSET += ImGui::CalcTextSize("Team").y + 2;

                    }
                    if (Globals::Esp::Leaderstats)
                    {



                        ImGui::GetWindowDrawList()->AddText(ImVec2(BoxMax.x + 3, BoxMin.y + ESPPREVIEWOFFSET), ImColor(Globals::Esp::Colors::LeaderStats[0], Globals::Esp::Colors::LeaderStats[1], Globals::Esp::Colors::LeaderStats[2]), "Cash: 1000");
                        ESPPREVIEWOFFSET += ImGui::CalcTextSize("Cash: 1000").y + 2;

                    }
                    if (Globals::Esp::HealthBar) {
                        float rawHealth = 50;
                        float playerMaxHealth = 100;


                        double playerHealth = 50;
                        double healthPercentage = (playerMaxHealth > 0.0) ? (playerHealth / playerMaxHealth) : 0.0;
                        float healthBarHeight = BoxMax.y - BoxMin.y;
                        float filledHealthBarHeight = healthBarHeight * healthPercentage;
                        float emptyBarHeight = healthBarHeight - filledHealthBarHeight;
                        float filledHealthMaxY = BoxMin.y + emptyBarHeight;
                        ImVec2 health_min = ImVec2(std::floor(BoxMin.x - 5.0f), std::floor(filledHealthMaxY));
                        ImVec2 health_max = ImVec2(std::floor(BoxMin.x - 3.0f), std::floor(BoxMax.y));

                        if (Globals::Esp::HealthBarBackGround) {
                            ImGui::GetWindowDrawList()->AddRectFilled({ health_min.x, BoxMin.y }, { health_max.x, health_max.y }, ImColor(0, 0, 0, 187));
                        }

                        ImColor Color = ImColor(Globals::Esp::Colors::HealthBar[0], Globals::Esp::Colors::HealthBar[1], Globals::Esp::Colors::HealthBar[2]);
                        if (Globals::Esp::HealthBarColorType == 1) {
                            Color = ImColor(94, 235, 52);
                            if (healthPercentage < 0.2f) Color = ImColor(235, 52, 52);
                            else if (healthPercentage < 0.4f) Color = ImColor(235, 168, 52);
                            else if (healthPercentage < 0.7f) Color = ImColor(192, 235, 52);
                        }

                        ImGui::GetWindowDrawList()->AddRectFilled(health_min, health_max, Color);

                        if (Globals::Esp::HealthBarGlow) {
                            ImGui::GetWindowDrawList()->AddShadowRect(health_min, health_max, Color, 50.0f, { 0,0 });
                        }


                        if (Globals::Esp::HealthBarBackGround) {
                            ImGui::GetWindowDrawList()->AddRect({ health_min.x - 1, BoxMin.y - 1 }, { health_max.x + 1, health_max.y + 1 }, ImColor(0, 0, 0));
                        }
                        else {
                            ImGui::GetWindowDrawList()->AddRect(health_min - ImVec2(1, 1), health_max + ImVec2(1, 1), ImColor(0, 0, 0));
                        }


                        if (Globals::Esp::HealthNumber && (int)std::ceil(playerHealth) != playerMaxHealth) {
                            std::string healthText = std::to_string((int)std::ceil(playerHealth)) + "%";
                            ImVec2 healthTextPos = health_min - ImVec2(ImGui::CalcTextSize(healthText.c_str()).x - 2, 4);


                            ImGui::GetWindowDrawList()->AddText(healthTextPos, ImColor(Globals::Esp::Colors::HealthNumber[0], Globals::Esp::Colors::HealthNumber[1], Globals::Esp::Colors::HealthNumber[2]), healthText.c_str());
                        }
                    }

                    if (Globals::Esp::Font != 0)
                        ImGui::PopFont();

                    ImGui::EndChild();
                    ImGui::End();
                }

				// Style Window

                if (DockButtons[1].Enabled)
                {
                    ImGui::SetNextWindowSize({ 363,415 });
                    ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x / 2 - 181, io.DisplaySize.y / 2 - 207), ImGuiCond_FirstUseEver);
                    ImGui::Begin("##Style", nullptr, ImGuiWindowFlags_NoTitleBar
                        | ImGuiWindowFlags_NoResize);
                    DragHeader("##drag_style");
                    ImGui::GetWindowDrawList()->AddRectFilledMultiColor(ImGui::GetWindowPos(), ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x, 25), ChildColor, ChildColor, WindowColor, WindowColor);
                    //ImGui::GetBackgroundDrawList()->AddShadowRect(ImGui::GetWindowPos(), ImGui::GetWindowPos() + ImGui::GetWindowSize(), ThemeColor, 30, { 0,0 });
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor);
                    if (MenuGlow)
                        ImGui::GetBackgroundDrawList()->AddShadowRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor, MenuGlowFloat, { 0,0 });
                    ImGui::SetCursorPos(ImVec2(6, 3));
                    ImGui::TextColored(AccentColor.Value, "Style ");
                    ImGui::SameLine(ImGui::GetContentRegionAvail().x);
                    ImGui::TextColored(AccentColor.Value, "x");
                    if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0))
                    {
                        DockButtons[1].Enabled = false;
                    }
                    style->Colors[ImGuiCol_Border] = Inline.Value;
                    ImGui::BeginChild("##c", ImGui::GetContentRegionAvail(), true);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Outline
                    );
                    style->Colors[ImGuiCol_ChildBg] = WindowColor.Value;
                    style->Colors[ImGuiCol_Border] = Outline.Value;
                    ImGui::BeginChild("##b", ImGui::GetContentRegionAvail(), true);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Inline
                    );
                    style->Colors[ImGuiCol_ChildBg] = ChildColor;
                    style->Colors[ImGuiCol_Border] = Inline.Value;
                    ImGui::BeginChild("##1", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y / 2 }, true);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Outline
                    );
                    ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                        ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                        AccentColor
                    );
                    ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                        ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                        ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                    );
                    ImGui::TextColored(TextTitle.Value, "Theme");

                    ImGui::Text("Window color"); ImGui::SameLine();
                    ImGui::ColorEdit3("##wc", WindowColorF, ImGuiColorEditFlags_NoInputs);

                    ImGui::Text("Accent color"); ImGui::SameLine();
                    ImGui::ColorEdit3("##ac", AccentColorF, ImGuiColorEditFlags_NoInputs);

                    ImGui::Text("Child color"); ImGui::SameLine();
                    ImGui::ColorEdit3("##cc", ChildColorF, ImGuiColorEditFlags_NoInputs);

                    ImGui::Text("Outline color"); ImGui::SameLine();
                    ImGui::ColorEdit3("##oc", OutlineF, ImGuiColorEditFlags_NoInputs);



                    ImGui::Text("Dark text color"); ImGui::SameLine();
                    ImGui::ColorEdit3("##tc", TextTitleF, ImGuiColorEditFlags_NoInputs);

                    ImGui::Text("Text color"); ImGui::SameLine();
                    ImGui::ColorEdit3("##wttc", TextF, ImGuiColorEditFlags_NoInputs);

                    ImGui::Text("Unsafe text color"); ImGui::SameLine();
                    ImGui::ColorEdit3("##sdfgdfgdfgfd", UnsafeTextF, ImGuiColorEditFlags_NoInputs);

                    ImGui::Text("Inline color"); ImGui::SameLine();
                    ImGui::ColorEdit3("##wtgfdgdfgdfgdftc", InlineF, ImGuiColorEditFlags_NoInputs);


                    ImGui::EndChild();
                    ImGui::BeginChild("##2", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y }, true);
                    ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                        ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                        Outline
                    );
                    ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                        ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                        AccentColor
                    );
                    ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                        ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                        ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                    );
                    ImGui::TextColored(TextTitle.Value, "Other");

                    ImGui::Checkbox("Crosshair", &Crosshair);
                    ImGui::Checkbox("ImGui Debug Log", &Globals::ShowDebugLog);
                    ImGui::Checkbox("ImGui Metrics", &Globals::ShowMetrics);
                    ImGui::Checkbox("Menu Glow", &MenuGlow);
                    ImGui::Text("Glow Size");
                    ImGui::SliderFloat("##menuglowfloat", &MenuGlowFloat, 5.0f, 100.0f);
                    if (ImGui::Button("Import", { ImGui::GetContentRegionAvail().x / 2, 17 }))
                    {
                        const char* clipboardText = ImGui::GetClipboardText();
                        if (clipboardText && strlen(clipboardText) > 0)
                        {
                            try
                            {
                                nlohmann::json config = nlohmann::json::parse(clipboardText);

                                auto u32_to_rgb = [](ImU32 colorU32, float out[3]) {
                                    ImVec4 color = ImGui::ColorConvertU32ToFloat4(colorU32);
                                    out[0] = color.x;
                                    out[1] = color.y;
                                    out[2] = color.z;
                                    };

                                if (config.contains("Accent"))       u32_to_rgb(config["Accent"], AccentColorF);
                                if (config.contains("Window"))       u32_to_rgb(config["Window"], WindowColorF);
                                if (config.contains("Child"))        u32_to_rgb(config["Child"], ChildColorF);
                                if (config.contains("Outline"))      u32_to_rgb(config["Outline"], OutlineF);
                                if (config.contains("DarkText"))     u32_to_rgb(config["DarkText"], TextTitleF);
                                if (config.contains("Text"))         u32_to_rgb(config["Text"], TextF);
                                if (config.contains("UnsafeText"))   u32_to_rgb(config["UnsafeText"], UnsafeTextF);
                                if (config.contains("Inline"))       u32_to_rgb(config["Inline"], InlineF);

                                if (config.contains("MenuGlow"))     MenuGlow = config["MenuGlow"].get<bool>();
                                if (config.contains("GlowAmount"))   MenuGlowFloat = config["GlowAmount"].get<float>();
                            }
                            catch (const std::exception& e)
                            {
                                //ImGui::InsertNotification({ ImGuiToastType_None, 3000, "Unable to import" });
                            }
                        }
                    }

                    ImGui::SameLine(0.0f, 4.0f);
                    if (ImGui::Button("Export", { ImGui::GetContentRegionAvail().x, 17 }))
                    {
                        nlohmann::json config;
                        config["Accent"] = ImGui::GetColorU32(AccentColor.Value);
                        config["Window"] = ImGui::GetColorU32(WindowColor.Value);
                        config["Child"] = ImGui::GetColorU32(ChildColor.Value);
                        config["Outline"] = ImGui::GetColorU32(Outline.Value);
                        config["DarkText"] = ImGui::GetColorU32(TextTitle.Value);
                        config["Text"] = ImGui::GetColorU32(Text.Value);
                        config["UnsafeText"] = ImGui::GetColorU32(UnsafeText.Value);
                        config["Inline"] = ImGui::GetColorU32(Inline.Value);
                        config["MenuGlow"] = MenuGlow;
                        config["GlowAmount"] = MenuGlowFloat;
                        ImGui::SetClipboardText(config.dump().c_str());

                    }
                    if (ImGui::Button("Reset GUI Size", { ImGui::GetContentRegionAvail().x / 2 - 2, 17 }))
                    {
                        SavedPositions::Home.size = ImVec2(0, 0);
                    }
                    ImGui::SameLine(0.0f, 4.0f);
                    if (ImGui::Button("Reset GUI Pos", { ImGui::GetContentRegionAvail().x, 17 }))
                    {
                        SavedPositions::Home.pos = ImVec2(0, 0);
                    }
                    static const char* PresetThemes[] = { "Default", "Cherry", "Blue", "Purplish", "Onetap", "Assembly", "DavidHook", "Midnight" };
                    static int SelectedTheme = 0;
                    ImGui::Text("Preset");
                    ImGui::Combo("##RR", &SelectedTheme, PresetThemes, IM_ARRAYSIZE(PresetThemes));
                    if (ImGui::Button("Load Theme", { ImGui::GetContentRegionAvail().x, 17 }))
                    {
                        if (SelectedTheme == 0)
                        {
                            static float AccentColorFp[3] = { 156.0f / 255.0, 199.0f / 255.0, 40.0f / 255.0 };
                            static float WindowColorFp[3] = { 20.0f / 255.0, 20.0f / 255.0, 20.0f / 255.0 };
                            static float ChildColorFp[3] = { 12.0f / 255.0, 12.0f / 255.0, 12.0f / 255.0 };
                            static float OutlineFp[3] = { 12.0f / 255.0, 12.0f / 255.0, 12.0f / 255.0 };
                            static float TextTitleFp[3] = { 195.0f / 255.0, 195.0f / 255.0, 195.0f / 255.0 };
                            static float TextFp[3] = { 205.0f / 255.0, 205.0f / 255.0, 205.0f / 255.0 };
                            static float UnsafeTextFp[3] = { 172.0f / 255.0, 177.0f / 255.0, 123.0f / 255.0 };
                            static float InlineFp[3] = { 48.0f / 255.0, 48.0f / 255.0, 48.0f / 255.0 };
                            static bool MenuGlowp = true;
                            static float MenuGlowFloatp = 30.0f;

                            for (int i = 0; i < 3; i++) {
                                AccentColorF[i] = AccentColorFp[i];
                                WindowColorF[i] = WindowColorFp[i];
                                ChildColorF[i] = ChildColorFp[i];
                                OutlineF[i] = OutlineFp[i];
                                TextTitleF[i] = TextTitleFp[i];
                                TextF[i] = TextFp[i];
                                UnsafeTextF[i] = UnsafeTextFp[i];
                                InlineF[i] = InlineFp[i];
                            }
                            MenuGlow = MenuGlowp;
                            MenuGlowFloat = MenuGlowFloatp;
                        }
                        if (SelectedTheme == 1)
                        {
                            static float AccentColorFp[3] = { 175.0f / 255.0, 50.0f / 255.0, 100.0f / 255.0 };
                            static float WindowColorFp[3] = { 30.0f / 255.0, 6.0f / 255.0, 16.0f / 255.0 };
                            static float ChildColorFp[3] = { 22.0f / 255.0, 4.0f / 255.0, 12.0f / 255.0 };
                            static float OutlineFp[3] = { 15.0f / 255.0, 2.0f / 255.0, 7.0f / 255.0 };
                            static float TextTitleFp[3] = { 136.0f / 255.0, 136.0f / 255.0, 136.0f / 255.0 };
                            static float TextFp[3] = { 180.0f / 255.0, 180.0f / 255.0, 180.0f / 255.0 };
                            static float UnsafeTextFp[3] = { 174.0f / 255.0, 50.0f / 255.0, 99.0f / 255.0 };
                            static float InlineFp[3] = { 38.0f / 255.0, 9.0f / 255.0, 21.0f / 255.0 };
                            static bool MenuGlowp = false;
                            static float MenuGlowFloatp = 30.0f;
                            for (int i = 0; i < 3; i++) {
                                AccentColorF[i] = AccentColorFp[i];
                                WindowColorF[i] = WindowColorFp[i];
                                ChildColorF[i] = ChildColorFp[i];
                                OutlineF[i] = OutlineFp[i];
                                TextTitleF[i] = TextTitleFp[i];
                                TextF[i] = TextFp[i];
                                UnsafeTextF[i] = UnsafeTextFp[i];
                                InlineF[i] = InlineFp[i];
                            }
                            MenuGlow = MenuGlowp;
                            MenuGlowFloat = MenuGlowFloatp;
                        }
                        if (SelectedTheme == 2)
                        {
                            static float AccentColorFp[3] = { 42.0f / 255.0, 122.0f / 255.0, 222.0f / 255.0 };
                            static float WindowColorFp[3] = { 0.0f / 255.0, 2.0f / 255.0, 23.0f / 255.0 };
                            static float ChildColorFp[3] = { 3.0f / 255.0, 1.0f / 255.0, 18.0f / 255.0 };
                            static float OutlineFp[3] = { 0.0f / 255.0, 0.0f / 255.0, 0.0f / 255.0 };
                            static float TextTitleFp[3] = { 210.0f / 255.0, 210.0f / 255.0, 210.0f / 255.0 };
                            static float TextFp[3] = { 210.0f / 255.0, 210.0f / 255.0, 210.0f / 255.0 };
                            static float UnsafeTextFp[3] = { 42.0f / 255.0, 122.0f / 255.0, 222.0f / 255.0 };
                            static float InlineFp[3] = { 28.0f / 255.0, 41.0f / 255.0, 64.0f / 255.0 };
                            static bool MenuGlowp = false;
                            static float MenuGlowFloatp = 30.0f;
                            for (int i = 0; i < 3; i++) {
                                AccentColorF[i] = AccentColorFp[i];
                                WindowColorF[i] = WindowColorFp[i];
                                ChildColorF[i] = ChildColorFp[i];
                                OutlineF[i] = OutlineFp[i];
                                TextTitleF[i] = TextTitleFp[i];
                                TextF[i] = TextFp[i];
                                UnsafeTextF[i] = UnsafeTextFp[i];
                                InlineF[i] = InlineFp[i];
                            }
                            MenuGlow = MenuGlowp;
                            MenuGlowFloat = MenuGlowFloatp;
                        }

                        if (SelectedTheme == 3)
                        {
                            static float AccentColorFp[3] = { 155.0f / 255.0, 125.0f / 255.0, 175.0f / 255.0 };
                            static float WindowColorFp[3] = { 42.0f / 255.0, 42.0f / 255.0, 56.0f / 255.0 };
                            static float ChildColorFp[3] = { 36.0f / 255.0, 36.0f / 255.0, 48.0f / 255.0 };
                            static float OutlineFp[3] = { 32.0f / 255.0, 32.0f / 255.0, 38.0f / 255.0 };
                            static float TextTitleFp[3] = { 180.0f / 255.0, 180.0f / 255.0, 180.0f / 255.0 };
                            static float TextFp[3] = { 180.0f / 255.0, 180.0f / 255.0, 180.0f / 255.0 };
                            static float UnsafeTextFp[3] = { 155.0f / 255.0, 125.0f / 255.0, 175.0f / 255.0 };
                            static float InlineFp[3] = { 60.0f / 255.0, 55.0f / 255.0, 75.0f / 255.0 };
                            static bool MenuGlowp = true;
                            static float MenuGlowFloatp = 30.0f;
                            for (int i = 0; i < 3; i++) {
                                AccentColorF[i] = AccentColorFp[i];
                                WindowColorF[i] = WindowColorFp[i];
                                ChildColorF[i] = ChildColorFp[i];
                                OutlineF[i] = OutlineFp[i];
                                TextTitleF[i] = TextTitleFp[i];
                                TextF[i] = TextFp[i];
                                UnsafeTextF[i] = UnsafeTextFp[i];
                                InlineF[i] = InlineFp[i];
                            }
                            MenuGlow = MenuGlowp;
                            MenuGlowFloat = MenuGlowFloatp;
                        }

                        if (SelectedTheme == 4)
                        {
                            static float AccentColorFp[3] = { 156.0f / 255.0, 199.0f / 255.0, 40.0f / 255.0 };
                            static float WindowColorFp[3] = { 20.0f / 255.0, 20.0f / 255.0, 20.0f / 255.0 };
                            static float ChildColorFp[3] = { 12.0f / 255.0, 12.0f / 255.0, 12.0f / 255.0 };
                            static float OutlineFp[3] = { 12.0f / 255.0, 12.0f / 255.0, 12.0f / 255.0 };
                            static float TextTitleFp[3] = { 195.0f / 255.0, 195.0f / 255.0, 195.0f / 255.0 };
                            static float TextFp[3] = { 205.0f / 255.0, 205.0f / 255.0, 205.0f / 255.0 };
                            static float UnsafeTextFp[3] = { 172.0f / 255.0, 177.0f / 255.0, 123.0f / 255.0 };
                            static float InlineFp[3] = { 48.0f / 255.0, 48.0f / 255.0, 48.0f / 255.0 };
                            static bool MenuGlowp = false;
                            static float MenuGlowFloatp = 30.0f;
                            for (int i = 0; i < 3; i++) {
                                AccentColorF[i] = AccentColorFp[i];
                                WindowColorF[i] = WindowColorFp[i];
                                ChildColorF[i] = ChildColorFp[i];
                                OutlineF[i] = OutlineFp[i];
                                TextTitleF[i] = TextTitleFp[i];
                                TextF[i] = TextFp[i];
                                UnsafeTextF[i] = UnsafeTextFp[i];
                                InlineF[i] = InlineFp[i];
                            }
                            MenuGlow = MenuGlowp;
                            MenuGlowFloat = MenuGlowFloatp;
                        }
                        if (SelectedTheme == 5)
                        {
                            static float AccentColorFp[3] = { 252.0f / 255.0, 154.0f / 255.0, 29.0f / 255.0 };
                            static float WindowColorFp[3] = { 30.0f / 255.0, 29.0f / 255.0, 34.0f / 255.0 };
                            static float ChildColorFp[3] = { 18.0f / 255.0, 17.0f / 255.0, 22.0f / 255.0 };
                            static float OutlineFp[3] = { 13.0f / 255.0, 12.0f / 255.0, 17.0f / 255.0 };
                            static float TextTitleFp[3] = { 184.0f / 255.0, 183.0f / 255.0, 188.0f / 255.0 };
                            static float TextFp[3] = { 233.0f / 255.0, 232.0f / 255.0, 237.0f / 255.0 };
                            static float UnsafeTextFp[3] = { 250.0f / 255.0, 161.0f / 255.0, 33.0f / 255.0 };
                            static float InlineFp[3] = { 68.0f / 255.0, 67.0f / 255.0, 72.0f / 255.0 };
                            static bool MenuGlowp = false;
                            static float MenuGlowFloatp = 10.0f;
                            for (int i = 0; i < 3; i++) {
                                AccentColorF[i] = AccentColorFp[i];
                                WindowColorF[i] = WindowColorFp[i];
                                ChildColorF[i] = ChildColorFp[i];
                                OutlineF[i] = OutlineFp[i];
                                TextTitleF[i] = TextTitleFp[i];
                                TextF[i] = TextFp[i];
                                UnsafeTextF[i] = UnsafeTextFp[i];
                                InlineF[i] = InlineFp[i];
                            }
                            MenuGlow = MenuGlowp;
                            MenuGlowFloat = MenuGlowFloatp;
                        }
                        if (SelectedTheme == 6)
                        {
                            static float AccentColorFp[3] = { 139.0f / 255.0, 152.0f / 255.0, 199.0f / 255.0 };
                            static float WindowColorFp[3] = { 25.0f / 255.0, 28.0f / 255.0, 37.0f / 255.0 };
                            static float ChildColorFp[3] = { 10.0f / 255.0, 11.0f / 255.0, 16.0f / 255.0 };
                            static float OutlineFp[3] = { 0.0f / 255.0, 0.0f / 255.0, 0.0f / 255.0 };
                            static float TextTitleFp[3] = { 221.0f / 255.0, 234.0f / 255.0, 246.0f / 255.0 };
                            static float TextFp[3] = { 221.0f / 255.0, 234.0f / 255.0, 246.0f / 255.0 };
                            static float UnsafeTextFp[3] = { 139.0f / 255.0, 142.0f / 255.0, 199.0f / 255.0 };
                            static float InlineFp[3] = { 43.0f / 255.0, 48.0f / 255.0, 64.0f / 255.0 };
                            static bool MenuGlowp = true;
                            static float MenuGlowFloatp = 10.0f;
                            for (int i = 0; i < 3; i++) {
                                AccentColorF[i] = AccentColorFp[i];
                                WindowColorF[i] = WindowColorFp[i];
                                ChildColorF[i] = ChildColorFp[i];
                                OutlineF[i] = OutlineFp[i];
                                TextTitleF[i] = TextTitleFp[i];
                                TextF[i] = TextFp[i];
                                UnsafeTextF[i] = UnsafeTextFp[i];
                                InlineF[i] = InlineFp[i];
                            }
                            MenuGlow = MenuGlowp;
                            MenuGlowFloat = MenuGlowFloatp;
                        }
                        if (SelectedTheme == 7)
                        {
                            static float AccentColorFp[3] = { 152.0f / 255.0, 122.0f / 255.0, 173.0f / 255.0 };
                            static float WindowColorFp[3] = { 25.0f / 255.0, 25.0f / 255.0, 25.0f / 255.0 };
                            static float ChildColorFp[3] = { 14.0f / 255.0, 15.0f / 255.0, 14.0f / 255.0 };
                            static float OutlineFp[3] = { 10.0f / 255.0, 10.0f / 255.0, 13.0f / 255.0 };
                            static float TextTitleFp[3] = { 120.0f / 255.0, 121.0f / 255.0, 121.0f / 255.0 };
                            static float TextFp[3] = { 254.0f / 255.0, 255.0f / 255.0, 254.0f / 255.0 };
                            static float UnsafeTextFp[3] = { 162.0f / 255.0, 134.0f / 255.0, 180.0f / 255.0 };
                            static float InlineFp[3] = { 30.0f / 255.0, 30.0f / 255.0, 30.0f / 255.0 };
                            static bool MenuGlowp = true;
                            static float MenuGlowFloatp = 100.0f;
                            for (int i = 0; i < 3; i++) {
                                AccentColorF[i] = AccentColorFp[i];
                                WindowColorF[i] = WindowColorFp[i];
                                ChildColorF[i] = ChildColorFp[i];
                                OutlineF[i] = OutlineFp[i];
                                TextTitleF[i] = TextTitleFp[i];
                                TextF[i] = TextFp[i];
                                UnsafeTextF[i] = UnsafeTextFp[i];
                                InlineF[i] = InlineFp[i];
                            }
                            MenuGlow = MenuGlowp;
                            MenuGlowFloat = MenuGlowFloatp;
                        }
                        if (SelectedTheme == 8)
                        {
                            static float AccentColorFp[3] = { 130.0f / 255.0, 50.0f / 255.0, 250.0f / 255.0 };
                            static float WindowColorFp[3] = { 10.0f / 255.0, 10.0f / 255.0, 15.0f / 255.0 };
                            static float ChildColorFp[3] = { 5.0f / 255.0, 5.0f / 255.0, 8.0f / 255.0 };
                            static float OutlineFp[3] = { 0.0f / 255.0, 0.0f / 255.0, 0.0f / 255.0 };
                            static float TextTitleFp[3] = { 140.0f / 255.0, 140.0f / 255.0, 150.0f / 255.0 };
                            static float TextFp[3] = { 200.0f / 255.0, 200.0f / 255.0, 220.0f / 255.0 };
                            static float UnsafeTextFp[3] = { 250.0f / 255.0, 50.0f / 255.0, 50.0f / 255.0 };
                            static float InlineFp[3] = { 30.0f / 255.0, 30.0f / 255.0, 40.0f / 255.0 };
                            static bool MenuGlowp = true;
                            static float MenuGlowFloatp = 45.0f;

                            for (int i = 0; i < 3; i++) {
                                AccentColorF[i] = AccentColorFp[i];
                                WindowColorF[i] = WindowColorFp[i];
                                ChildColorF[i] = ChildColorFp[i];
                                OutlineF[i] = OutlineFp[i];
                                TextTitleF[i] = TextTitleFp[i];
                                TextF[i] = TextFp[i];
                                UnsafeTextF[i] = UnsafeTextFp[i];
                                InlineF[i] = InlineFp[i];
                            }
                            MenuGlow = MenuGlowp;
                            MenuGlowFloat = MenuGlowFloatp;
                        }
                    }

                    ImGui::EndChild();
                    ImGui::EndChild();
                    ImGui::EndChild();
                    ImGui::End();
                }
            }
            
            static float alpha = 0.0f;
            static bool increasing = true;
            static float angle = 0.0f;
            static float animX = 0.0f;
            static float animY = 0.0f;
            if (Crosshair)
            {
                float dt = ImGui::GetIO().DeltaTime;

                
                float alphaSpeed = 1.44f;
                if (increasing) {
                    alpha += alphaSpeed * dt;
                    if (alpha >= 1.0f) {
                        alpha = 1.0f;
                        increasing = false;
                    }
                }
                else {
                    alpha -= alphaSpeed * dt;
                    if (alpha <= 0.0f) {
                        alpha = 0.0f;
                        increasing = true;
                    }
                }

               
                angle += 4.0f * dt;
                if (angle > IM_PI * 2.0f) angle -= IM_PI * 2.0f;

                
                POINT cursor_point;
                GetCursorPos(&cursor_point);
                ScreenToClient(hwnd, &cursor_point);

                SDK::Vector2 realcursor = { static_cast<float>(cursor_point.x), static_cast<float>(cursor_point.y) };

                if (Globals::Aimbot::IsThereATarget && Globals::Aimbot::SilentCrosshair && Globals::Aimbot::AimType == 2)
                {
                    cursor_point.x = static_cast<LONG>(Globals::Aimbot::SilentMousePosition.x);
                    cursor_point.y = static_cast<LONG>(Globals::Aimbot::SilentMousePosition.y);
                }
              
                if (animX == 0.0f) animX = static_cast<float>(cursor_point.x);
                if (animY == 0.0f) animY = static_cast<float>(cursor_point.y);

                float lerpFactor = 1.0f;

                if (Globals::Aimbot::Smoothning)
                {
                    // Inverse scaling so 0.1 is smooth/slow and 1.0 is snappy:
                    // 0.1 -> smoothing = 5.0f   (smooth)
                    // 1.0 -> smoothing = 50.0f  (very fast)
                    float smoothing = Globals::Aimbot::SmoothingValue * 50.0f;
                    lerpFactor = 1.0f - expf(-smoothing * dt);
                }

                animX += (static_cast<float>(cursor_point.x) - animX) * lerpFactor;
                animY += (static_cast<float>(cursor_point.y) - animY) * lerpFactor;

                if (Globals::Aimbot::IsThereATarget && Globals::Aimbot::SilentCrosshair && Globals::Aimbot::AimType == 2)
                {

                    
                    if (Globals::Aimbot::SilentCrosshairTracer)
                    {
                        ImGui::GetBackgroundDrawList()->AddLine(
                            { realcursor.x, realcursor.y },
                            { static_cast<float>(animX),static_cast<float>(animY) },
                            ImColor(0, 0, 0),
                            3.0f
                        );
                        ImGui::GetBackgroundDrawList()->AddLine(
                            { realcursor.x, realcursor.y },
                            { static_cast<float>(animX),static_cast<float>(animY) },
                            ImColor(Globals::Aimbot::SilentCrosshairTracerColor[0], Globals::Aimbot::SilentCrosshairTracerColor[1], Globals::Aimbot::SilentCrosshairTracerColor[2], Globals::Aimbot::SilentCrosshairTracerColor[3]),
                            2.0f
                        );
                    }
                }

                ImDrawList* draw_list = ImGui::GetForegroundDrawList();
                ImVec2 center(animX, animY);
                ImColor crosshairColor = ImColor(255, 255, 255);

                float size = 10.0f;
                float thickness = 1.5f;
                float gap = 5.0f;

               
                ImVec2 lines[4][2] = {
                    { ImVec2(center.x - size - gap, center.y), ImVec2(center.x - gap, center.y) },
                    { ImVec2(center.x + gap, center.y), ImVec2(center.x + size + gap, center.y) },
                    { ImVec2(center.x, center.y - size - gap), ImVec2(center.x, center.y - gap) },
                    { ImVec2(center.x, center.y + gap), ImVec2(center.x, center.y + size + gap) }
                };

               
                float s = sin(angle);
                float c = cos(angle);
                for (int i = 0; i < 4; ++i) {
                    
                    ImVec2 p1 = lines[i][0], p2 = lines[i][1];
                    float p1x = p1.x - center.x;
                    float p1y = p1.y - center.y;
                    float p2x = p2.x - center.x;
                    float p2y = p2.y - center.y;

                    ImVec2 rp1(p1x * c - p1y * s + center.x, p1x * s + p1y * c + center.y);
                    ImVec2 rp2(p2x * c - p2y * s + center.x, p2x * s + p2y * c + center.y);

                   
                    draw_list->AddLine(ImVec2(rp1.x - 1, rp1.y), ImVec2(rp2.x - 1, rp2.y), IM_COL32(0, 0, 0, 255), 1.0f);
                    draw_list->AddLine(ImVec2(rp1.x + 1, rp1.y), ImVec2(rp2.x + 1, rp2.y), IM_COL32(0, 0, 0, 255), 1.0f);
                    draw_list->AddLine(ImVec2(rp1.x, rp1.y - 1), ImVec2(rp2.x, rp2.y - 1), IM_COL32(0, 0, 0, 255), 1.0f);
                    draw_list->AddLine(ImVec2(rp1.x, rp1.y + 1), ImVec2(rp2.x, rp2.y + 1), IM_COL32(0, 0, 0, 255), 1.0f);

                    
                    draw_list->AddLine(rp1, rp2, crosshairColor, thickness);
                }

              
                ImVec2 textSize = ImGui::CalcTextSize("Skidware");
                ImVec2 nemesisSize = ImGui::CalcTextSize("Skid");

                draw_list->AddText(ImVec2(center.x - textSize.x / 2, center.y + size + gap + 5.0f), IM_COL32(255, 255, 255, 255), "Skid");

                draw_list->AddText(ImVec2(center.x - textSize.x / 2 + nemesisSize.x, center.y + size + gap + 5.0f), ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, alpha), "ware");
            }
            if (Globals::Notifications)
            {
                ImDrawList* draw_list = ImGui::GetForegroundDrawList();
                auto& q = GetNotificationQueue();
                std::lock_guard<std::mutex> lock(q.mtx);
                float now = SteadyNow();
                float lifetime = 4.5f;
                float screenW = ImGui::GetIO().DisplaySize.x;
                float screenH = ImGui::GetIO().DisplaySize.y;
                if (screenW < 100.0f || screenH < 100.0f) { /* skip if overlay not ready */ }
                else
                {
                    float startY = 50.0f;
                    for (size_t i = 0; i < q.items.size();)
                    {
                        float age = now - q.items[i].second;
                        if (age > lifetime)
                        {
                            q.items.erase(q.items.begin() + i);
                            continue;
                        }
                        float alpha = (age > 4.0f) ? 1.0f - (age - 4.0f) / 0.5f : 1.0f;
                        if (alpha < 0.0f) alpha = 0.0f;
                        std::string& msg = q.items[i].first;
                        ImVec2 sz = ImGui::CalcTextSize(msg.c_str());
                        float padX = 14.0f, padY = 8.0f;
                        float boxW = (sz.x < 20.0f ? 100.0f : sz.x) + padX * 2;
                        float boxH = sz.y + padY * 2;
                        float bx = screenW - boxW - 10.0f;
                        if (bx < 2.0f) bx = 2.0f;
                        if (bx + boxW > screenW - 2.0f) bx = screenW - boxW - 2.0f;
                        float by = startY;
                        if (by + boxH > screenH - 2.0f) by = screenH - boxH - 2.0f;
                        if (by < 2.0f) by = 2.0f;
                        ImVec2 bmin(bx, by);
                        ImVec2 bmax(bx + boxW, by + boxH);
                        ImU32 bg = IM_COL32(12, 12, 12, (int)(235 * alpha));
                        ImU32 border = IM_COL32(48, 48, 48, (int)(255 * alpha));
                        ImU32 accent = IM_COL32(156, 199, 40, (int)(255 * alpha));
                        ImU32 accentDim = IM_COL32(156, 199, 40, (int)(128 * alpha));
                        ImU32 txt = IM_COL32(255, 255, 255, (int)(255 * alpha));
                        draw_list->AddRectFilled(bmin, bmax, bg);
                        draw_list->AddRect(bmin, bmax, border);
                        float lineEndX = bmin.x + 3 + (bmax.x - bmin.x - 6) * (1.0f - age / lifetime);
                        if (lineEndX < bmin.x + 3) lineEndX = bmin.x + 3;
                        draw_list->AddLine(ImVec2(bmin.x + 3, bmin.y + 3), ImVec2(lineEndX, bmin.y + 3), accent, 2.0f);
                        draw_list->AddLine(ImVec2(bmin.x + 3, bmin.y + 5), ImVec2(lineEndX, bmin.y + 5), accentDim, 1.0f);
                        draw_list->AddText(ImVec2(bmin.x + padX, bmin.y + padY), txt, msg.c_str());
                        startY += boxH + 10.0f;
                        i++;
                    }
                }
            }
            if (Globals::Watermark)
            {
                style->Colors[ImGuiCol_WindowBg] = WindowColor.Value;
                style->Colors[ImGuiCol_ChildBg] = ChildColor.Value;
                style->Colors[ImGuiCol_Border] = Inline.Value;
                
                std::string WatermarkText = "skidware.SON | " + Globals::Auth::Username + " | Build: " SKIDWARE_BUILD_TAG + " | FPS: " + std::to_string((int)ImGui::GetIO().Framerate);
                ImGui::SetNextWindowSize(ImGui::CalcTextSize(WatermarkText.c_str()) + ImVec2(30,30));
                ImGui::Begin("LOLLLLLLLLLXDDDDDDWATERMARK", nullptr, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
                ImGui::BeginChild("##1", { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y}, true);
                ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                    ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                    Outline
                );
                ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                    ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                    AccentColor
                );
                ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                    ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                    ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                );
                ImGui::SetCursorPos(
                    {
                        (ImGui::GetWindowSize().x - ImGui::CalcTextSize(WatermarkText.c_str()).x) / 2,
                        (ImGui::GetWindowSize().y - ImGui::CalcTextSize(WatermarkText.c_str()).y) / 2
                    }
                );
                ImGui::Text(WatermarkText.c_str());
                ImGui::EndChild();
                ImGui::End();
            }
            if (Globals::ShowDebugLog)
                ImGui::ShowDebugLogWindow(&Globals::ShowDebugLog);
            if (Globals::ShowMetrics)
                ImGui::ShowMetricsWindow(&Globals::ShowMetrics);

            if (Globals::DebugMode && Globals::LoaderAttached)
            {
                ImGui::Begin("Debug", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings);
                style->Colors[ImGuiCol_WindowBg] = WindowColor.Value;
                style->Colors[ImGuiCol_Border] = Outline.Value;
                style->Colors[ImGuiCol_TitleBg] = WindowColor.Value;
                style->Colors[ImGuiCol_TitleBgActive] = WindowColor.Value;
                style->Colors[ImGuiCol_TitleBgCollapsed] = WindowColor.Value;
                ImGui::Text("GameID: %llu", (unsigned long long)Globals::GameID);
                ImGui::Text("DataModel: 0x%llX", (unsigned long long)Globals::DataModel.Address);
                ImGui::Text("Workspace: 0x%llX", (unsigned long long)Globals::Workspace.Address);
                ImGui::Text("LocalPlayer: 0x%llX", (unsigned long long)Globals::LocalPlayer.Address);
                ImGui::Separator();
                {
                    SDK::Cache::PlayersMutex.lock();
                    ImGui::Text("Cached Players: %zu", SDK::Cache::Players.size());
                    ImGui::Text("Local HRP: 0x%llX", (unsigned long long)SDK::Cache::LocalPlayer.HumanoidRootPart.Object.Address);
                    ImGui::Text("Local Name: %s", SDK::Cache::LocalPlayer.PlayerName.c_str());
                    ImGui::Text("Local Health: %.0f/%.0f", SDK::Cache::LocalPlayer.Health, SDK::Cache::LocalPlayer.MaxHealth);
                    int alive = 0;
                    for (auto& p : SDK::Cache::Players)
                        if (p.Health > 0) alive++;
                    ImGui::Text("Alive Players: %d", alive);
                    SDK::Cache::PlayersMutex.unlock();
                }
                ImGui::Separator();
                ImGui::Text("Offsets:");
                ImGui::Text("  Name=0x%llX NameContainer=0x%llX", (unsigned long long)SDK::Offsets::Name, (unsigned long long)SDK::Offsets::NameContainer);
                ImGui::Text("  ChildrenStart=0x%llX", (unsigned long long)SDK::Offsets::ChildrenStart);
                ImGui::Text("  DisplayName=0x%llX Character=0x%llX", (unsigned long long)SDK::Offsets::DisplayName, (unsigned long long)SDK::Offsets::Character);
                ImGui::Text("Game Version: %s", GetRobloxVersion().c_str());
                ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
                ImGui::End();
            }

            static auto lastConfigSave = std::chrono::steady_clock::now();
            auto now2 = std::chrono::steady_clock::now();
            if (duration_cast<std::chrono::seconds>(now2 - lastConfigSave).count() >= 30) {
                lastConfigSave = now2;
                if (ConfigManager::CurrentGameId)
                    ConfigManager::SaveConfig(ConfigManager::CurrentGameId);
            }

			// Keybinds Window

            if (DockButtons[6].Enabled)
            {
                std::vector<CKeybind> AllKeybinds = {Globals::Misc::DesyncBind, Globals::Aimbot::AimbotKey, Globals::TriggerBot::Key, Globals::World::Movement::SpeedKey, Globals::World::Movement::FlyKey,Globals::World::Movement::FreecamKey,Globals::World::Movement::ThirdPersonKey, Globals::World::Movement::NoclipKey, Globals::World::ZoomKey };
                auto isFeatureEnabled = [](size_t j) -> bool {
                    if (j == 0) return Globals::Misc::Desync && Globals::Misc::RiskyFunctions;
                    if (j == 1) return Globals::Aimbot::Enabled;
                    if (j == 2) return Globals::TriggerBot::Enabled;
                    if (j == 3) return Globals::World::Movement::Speed && Globals::Misc::RiskyFunctions;
                    if (j == 4) return Globals::World::Movement::Fly && Globals::Misc::RiskyFunctions;
                    if (j == 5) return Globals::World::Movement::Freecam;
                    if (j == 6) return Globals::World::Movement::ThirdPerson;
                    if (j == 7) return Globals::World::Movement::Noclip && Globals::Misc::RiskyFunctions;
                    if (j == 8) return Globals::World::Zoom;
                    return true;
                };
                int visibleCount = 0;
                for (size_t j = 0; j < AllKeybinds.size(); j++)
                {
                    if (AllKeybinds[j].key == 0 && AllKeybinds[j].type != CKeybind::ALWAYS)
                        continue;
                    if (!isFeatureEnabled(j))
                        continue;
                    visibleCount++;
                }
                ImGui::SetNextWindowPos(SavedPositions::Keybinds.pos, ImGuiCond_Appearing);
                ImGui::SetNextWindowSize({ 209.0f, (17.0f * static_cast<float>(visibleCount)) + 24.0f + 9.0f});
                style->Colors[ImGuiCol_WindowBg] = style->Colors[ImGuiCol_ChildBg];
                style->Colors[ImGuiCol_Border] = Outline.Value;
                style->Colors[ImGuiCol_Separator] = Inline.Value;
                ImGui::Begin("##Keybinds",nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
                SavedPositions::Keybinds.pos = ImGui::GetWindowPos();
                SavedPositions::Keybinds.size = ImGui::GetWindowSize();
                ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                    ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                    Inline
                );
                ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                    ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                    AccentColor
                );
                ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                    ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                    ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                );
                ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize("Keybinds").x) / 2);
                ImGui::Text("Keybinds");
                ImGui::Separator();
                for (size_t j = 0; j < AllKeybinds.size(); j++)
                {
                    CKeybind& KB = AllKeybinds[j];
                    if (KB.key == 0 && KB.type != CKeybind::ALWAYS)
                        continue;
                    if (!isFeatureEnabled(j))
                        continue;
                    std::string keyType = KB.get_type();
                    if (KB.enabled)
                        ImGui::PushStyleColor(ImGuiCol_Text, AccentColor.Value);
                    std::string displayName = KB.name.c_str() + (KB.name.find("##") == 0 ? 2 : 0);
                    float windowWidth = ImGui::GetWindowSize().x;
                    float availableForName = windowWidth - ImGui::CalcTextSize("[] ").x - ImGui::CalcTextSize(KB.get_type().c_str()).x - 5;
                    if (availableForName < 10.0f) availableForName = 10.0f;
                    ImVec2 nameSize = ImGui::CalcTextSize(displayName.c_str());
                    if (nameSize.x > availableForName)
                        displayName = displayName.substr(0, static_cast<int>(displayName.size() * availableForName / nameSize.x)) + "..";
                    ImGui::Text("[ %s ] %s", keyType.c_str(), displayName.c_str());
                    std::string keyName = KB.get_key_name();
                    if (KB.type == CKeybind::ALWAYS && KB.key == 0)
                        keyName = "Always";
                    ImGui::SameLine(ImGui::GetWindowSize().x - ImGui::CalcTextSize(keyName.c_str()).x - 5);
                    ImGui::Text(keyName.c_str());
                    if (KB.enabled)
                        ImGui::PopStyleColor();
                }
                ImGui::End();
            }

            if (uiRender && Globals::Raycast::Preview && Globals::Raycast::Enabled)
            {
                ImGui::SetNextWindowSize({ 180.0f, 0.0f });
                style->Colors[ImGuiCol_WindowBg] = style->Colors[ImGuiCol_ChildBg];
                style->Colors[ImGuiCol_Border] = Inline.Value;
                style->Colors[ImGuiCol_Separator] = Inline.Value;
                ImGui::Begin("##RaycastPreview", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
                ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                    ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                    Inline
                );
                ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                    ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                    AccentColor
                );
                ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize("Raycast Preview").x) / 2);
                ImGui::Text("Raycast Preview");
                ImGui::Separator();
                ImGui::Text("Target: %s", Globals::Raycast::PreviewTargetName.empty() ? "-" : Globals::Raycast::PreviewTargetName.c_str());
                ImGui::Text("Distance: %.1f m", Globals::Raycast::PreviewDistance);
                if (Globals::Raycast::PreviewVisible)
                    ImGui::TextColored(ImColor(0, 255, 0).Value, "Visible: Yes");
                else
                    ImGui::TextColored(ImColor(255, 60, 60).Value, "Visible: No");
                ImGui::End();
            }

			// Animations Window

            if (uiRender && DockButtons[7].Enabled)
            {
                static const char* PackNames[] = { "Custom", "Astronaut", "Bubbly", "Cartoony", "Elder", "Knight", "Levitation", "Mage", "Ninja", "Pirate", "Robot", "Rthro", "Stylish", "Superhero", "Toy", "Vampire", "Werewolf", "Zombie" };
                ImGui::SetNextWindowSize({ 230.0f, 0.0f });
                style->Colors[ImGuiCol_WindowBg] = style->Colors[ImGuiCol_ChildBg];
                style->Colors[ImGuiCol_Border] = Inline.Value;
                style->Colors[ImGuiCol_Separator] = Inline.Value;
                ImGui::Begin("##AnimsMenu", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
                ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1),
                    ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1),
                    Inline
                );
                ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 2),
                    ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 2),
                    AccentColor
                );
                ImGui::GetWindowDrawList()->AddLine(ImGui::GetWindowPos() + ImVec2(2, 3),
                    ImGui::GetWindowPos() + ImVec2(ImGui::GetWindowSize().x - 2, 3),
                    ImColor(AccentColor.Value.x, AccentColor.Value.y, AccentColor.Value.z, 0.5f)
                );
                ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize("Animations").x) / 2);
                ImGui::Text("Animations");
                ImGui::Separator();

                bool r15Only = false;
                try
                {
                    SDK::Humanoid H = static_cast<SDK::Humanoid>(Globals::LocalPlayer.Character().FindFirstChildOfClass("Humanoid"));
                    r15Only = H.Address && H.RigType() == 1;
                }
                catch (...)
                {
                    r15Only = false;
                }

                if (!r15Only)
                {
                    ImGui::BeginDisabled();
                    Globals::Exploits::AnimationEnabled = false;
                }
                ImGui::Checkbox("Animation Changer (R15)", &Globals::Exploits::AnimationEnabled);
                if (!r15Only)
                {
                    ImGui::EndDisabled();
                    ImGui::TextDisabled("Requires an R15 character");
                }

                if (ImGui::Combo("Pack", &Globals::Exploits::AnimationPack, PackNames, IM_ARRAYSIZE(PackNames)))
                {
                    if (Globals::Exploits::AnimationPack > 0)
                    {
                        Globals::Exploits::AnimationIdle = Globals::Exploits::AnimationPack;
                        Globals::Exploits::AnimationRun = Globals::Exploits::AnimationPack;
                        Globals::Exploits::AnimationWalk = Globals::Exploits::AnimationPack;
                        Globals::Exploits::AnimationJump = Globals::Exploits::AnimationPack;
                        Globals::Exploits::AnimationFall = Globals::Exploits::AnimationPack;
                        Globals::Exploits::AnimationClimb = Globals::Exploits::AnimationPack;
                        Globals::Exploits::AnimationSwim = Globals::Exploits::AnimationPack;
                    }
                }
                ImGui::Separator();
                ImGui::Combo("Idle", &Globals::Exploits::AnimationIdle, PackNames, IM_ARRAYSIZE(PackNames));
                ImGui::Combo("Run", &Globals::Exploits::AnimationRun, PackNames, IM_ARRAYSIZE(PackNames));
                ImGui::Combo("Walk", &Globals::Exploits::AnimationWalk, PackNames, IM_ARRAYSIZE(PackNames));
                ImGui::Combo("Jump", &Globals::Exploits::AnimationJump, PackNames, IM_ARRAYSIZE(PackNames));
                ImGui::Combo("Fall", &Globals::Exploits::AnimationFall, PackNames, IM_ARRAYSIZE(PackNames));
                ImGui::Combo("Climb", &Globals::Exploits::AnimationClimb, PackNames, IM_ARRAYSIZE(PackNames));
                ImGui::Combo("Swim", &Globals::Exploits::AnimationSwim, PackNames, IM_ARRAYSIZE(PackNames));
                // Keep the pack selector in sync: once a single anim is changed,
                // the selection is no longer a full pack, so show "Custom".
                if (Globals::Exploits::AnimationPack > 0)
                {
                    bool allMatch = Globals::Exploits::AnimationIdle == Globals::Exploits::AnimationPack
                        && Globals::Exploits::AnimationRun == Globals::Exploits::AnimationPack
                        && Globals::Exploits::AnimationWalk == Globals::Exploits::AnimationPack
                        && Globals::Exploits::AnimationJump == Globals::Exploits::AnimationPack
                        && Globals::Exploits::AnimationFall == Globals::Exploits::AnimationPack
                        && Globals::Exploits::AnimationClimb == Globals::Exploits::AnimationPack
                        && Globals::Exploits::AnimationSwim == Globals::Exploits::AnimationPack;
                    if (!allMatch)
                        Globals::Exploits::AnimationPack = 0;
                }
                ImGui::End();
            }
        }
        }
        else
        {
            static char EmailBuf[128] = "";
            static char PassBuf[128] = "";
            static bool FirstAuthCheck = true;
            static bool AuthChecked = false;

            // Kick off a background session validation on first frame so saved
            // logins auto-authenticate without blocking the UI.
            if (FirstAuthCheck)
            {
                FirstAuthCheck = false;
                std::thread([]() {
                    if (Backend::Auth::Validate())
                    {
                        Globals::Auth::Authenticated = true;
                        Globals::Auth::Username = Backend::Auth::Current().username;
                        Globals::Auth::Email = Backend::Auth::Current().email;
                        Globals::Auth::HWID = Backend::Auth::Current().hwid;
                    }
                    AuthChecked = true;
                }).detach();
            }

            ImVec2 cs = ImGui::GetIO().DisplaySize;
            const bool authed = Globals::Auth::Authenticated;
            // The loader HWND is sized to exactly this box by the main loop, so
            // draw the ImGui window filling it from (0,0).
            ImVec2 winSize = authed ? ImVec2(320, 380) : ImVec2(320, 360);
            winSize.y = g_LoaderSize.y;
            ImGui::SetNextWindowSize(winSize);
            ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
            ImGui::Begin("Loader", nullptr, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
            style->Colors[ImGuiCol_WindowBg] = WindowColor.Value;
            style->Colors[ImGuiCol_Border] = Outline.Value;
            style->Colors[ImGuiCol_TitleBg] = WindowColor.Value;
            style->Colors[ImGuiCol_TitleBgActive] = WindowColor.Value;
            style->Colors[ImGuiCol_TitleBgCollapsed] = WindowColor.Value;
            ImGui::GetWindowDrawList()->AddRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor);
            if (MenuGlow)
                ImGui::GetBackgroundDrawList()->AddShadowRect(ImGui::GetWindowPos() + ImVec2(1, 1), ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(1, 1), AccentColor, MenuGlowFloat, { 0,0 });

            if (!authed)
            {
                // ── LOGIN FORM ──
                ImGui::SetCursorPosX((winSize.x - ImGui::CalcTextSize("SKIDWARE").x) / 2);
                ImGui::TextColored(AccentColor.Value, "SKIDWARE");
                ImGui::Separator();

                ImGui::Text("Email");
                ImGui::SetNextItemWidth(winSize.x - 32);
                ImGui::InputText("##login_email", EmailBuf, sizeof(EmailBuf));

                ImGui::Text("Password");
                ImGui::SetNextItemWidth(winSize.x - 32);
                ImGui::InputText("##login_pass", PassBuf, sizeof(PassBuf), ImGuiInputTextFlags_Password);

                ImGui::Separator();
                if (Globals::Auth::LoginInProgress)
                {
                    ImGui::SetCursorPosX((winSize.x - ImGui::CalcTextSize("Logging in...").x) / 2);
                    ImGui::TextColored(UnsafeText.Value, "Logging in...");
                }
                else if (!Globals::Auth::StatusMessage.empty())
                {
                    ImGui::SetCursorPosX((winSize.x - ImGui::CalcTextSize(Globals::Auth::StatusMessage.c_str()).x) / 2);
                    ImGui::TextColored(ImColor(220, 80, 80).Value, "%s", Globals::Auth::StatusMessage.c_str());
                }
                else if (!AuthChecked)
                {
                    ImGui::SetCursorPosX((winSize.x - ImGui::CalcTextSize("Checking session...").x) / 2);
                    ImGui::TextColored(UnsafeText.Value, "Checking session...");
                }
                else
                {
                    ImGui::Spacing();
                }

                ImGui::SetCursorPosX((winSize.x - 248) / 2);
                if (ImGui::Button("Login", { 120, 28 }) && !Globals::Auth::LoginInProgress)
                {
                    Globals::Auth::LoginInProgress = true;
                    Globals::Auth::StatusMessage.clear();
                    std::string email = EmailBuf;
                    std::string pass = PassBuf;
                    std::thread([email, pass]() {
                        std::string err;
                        bool ok = Backend::Auth::Login(email, pass, err);
                        if (ok)
                        {
                            Globals::Auth::Authenticated = true;
                            Globals::Auth::Username = Backend::Auth::Current().username;
                            Globals::Auth::Email = Backend::Auth::Current().email;
                            Globals::Auth::HWID = Backend::Auth::Current().hwid;
                            Globals::Auth::StatusMessage = "Logged in as " + Backend::Auth::Current().username;
                        }
                        else
                        {
                            Globals::Auth::StatusMessage = err;
                        }
                        Globals::Auth::LoginInProgress = false;
                    }).detach();
                }
                ImGui::SameLine();
                ImGui::PushStyleColor(ImGuiCol_Button, ImColor(88, 101, 242).Value);
                ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor(105, 118, 255).Value);
                ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor(75, 86, 220).Value);
                if (ImGui::Button("Discord", { 120, 28 }) && !Globals::Auth::LoginInProgress)
                {
                    Globals::Auth::LoginInProgress = true;
                    Globals::Auth::StatusMessage.clear();
                    std::thread([]() {
                        std::string err;
                        bool ok = Backend::Auth::LoginWithDiscord(err);
                        if (ok)
                        {
                            Globals::Auth::Authenticated = true;
                            Globals::Auth::Username = Backend::Auth::Current().username;
                            Globals::Auth::Email = Backend::Auth::Current().email;
                            Globals::Auth::HWID = Backend::Auth::Current().hwid;
                            Globals::Auth::StatusMessage = "Logged in as " + Backend::Auth::Current().username;
                        }
                        else
                        {
                            Globals::Auth::StatusMessage = err;
                        }
                        Globals::Auth::LoginInProgress = false;
                    }).detach();
                }
                ImGui::PopStyleColor(3);
                ImGui::SetCursorPosX((winSize.x - ImGui::CalcTextSize("No account? Register on the website").x) / 2);
                ImGui::TextDisabled("No account? Register on the website");
            }
            else
            {
                // ── AUTHENTICATED LOADER ──
                ImGui::SetCursorPosX((winSize.x - ImGui::CalcTextSize("SKIDWARE").x) / 2);
                ImGui::TextColored(AccentColor.Value, "SKIDWARE");
                ImGui::Separator();
                ImGui::Text("Logged in as: %s", Globals::Auth::Username.c_str());
                {
                    std::string hwid = Globals::Auth::HWID;
                    if (hwid.size() > 20)
                        hwid = hwid.substr(0, 20) + "...";
                    ImGui::TextDisabled("HWID: %s", hwid.c_str());
                }

                ImGui::Separator();
                DWORD pid = SDK::GetProcessId(xorstr_("RobloxPlayerBeta.exe"));
                ImGui::Text("Process: RobloxPlayerBeta.exe");
                ImGui::SameLine();
                if (pid)
                    ImGui::TextColored(ImColor(80, 220, 80).Value, "Running");
                else
                    ImGui::TextColored(ImColor(220, 80, 80).Value, "Not found");
                ImGui::Separator();
                if (ImGui::Checkbox("Console", &Globals::ShowConsole))
                {
                    if (Globals::ShowConsole)
                        ShowWindow(GetConsoleWindow(), SW_SHOW);
                    else
                        ShowWindow(GetConsoleWindow(), SW_HIDE);
                }
                if (ImGui::Checkbox("Debug", &Globals::DebugMode))
                    Logging::g_DebugEnabled = Globals::DebugMode;
                ImGui::Separator();
                if (!pid)
                {
                    ImGui::SetCursorPosX((winSize.x - ImGui::CalcTextSize("Roblox not running").x) / 2);
                    ImGui::TextColored(ImColor(220, 80, 80).Value, "Roblox not running");
                }
                ImGui::SetCursorPosX((winSize.x - 120) / 2);
                if (ImGui::Button(pid ? "Attach" : "Retry", { 120, 28 }))
                {
                    if (pid) {
                        auto mem = new SDK::MemoryClass();
                        mem->Handle = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_QUERY_INFORMATION, 0, pid);
                        if (mem->Handle)
                        {
                            Globals::RobloxProcessHandle = OpenProcess(SYNCHRONIZE, FALSE, pid);
                            SDK::Memory = mem;
                            SDK::RobloxBase = mem->GetModule(xorstr_("RobloxPlayerBeta.exe"));
                            if (SDK::Initialize()) {
#ifdef SKIDWARE_MASTER_ENABLED
                                std::thread(SDK::Cache::PlayerCache).detach();
                                std::thread(SDK::Cache::PlayerInfoUpdate).detach();
                                std::thread(Hacks::Aimbot::Setup).detach();
                                std::thread(Hacks::Misc::Setup).detach();
#endif
                                Globals::LoaderAttached = true;
                                g_NeedsReposition = true;
                                draw = false;
                                g_PreloadFrames = 3;
                                SetWindowLong(hwnd, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED | WS_EX_TOOLWINDOW);
                            }
                        }
                    }
                }
            }
            ImGui::Separator();
            ImGui::SetCursorPosX((winSize.x - 60) / 2);
            if (ImGui::Button("Close", { 60, 28 }))
                TerminateProcess(GetCurrentProcess(), 0);
            // Fit the loader box tightly around its content so there's no dead
            // space under the buttons; the main loop resizes the HWND to match
            // (1-frame convergence, then stable).
            float loaderEndY = ImGui::GetWindowPos().y
                + ImGui::GetWindowContentRegionMin().y + ImGui::GetCursorPosY();
            g_LoaderSize.y = (loaderEndY + style->WindowPadding.y + style->WindowBorderSize)
                - ImGui::GetWindowPos().y;
            g_LoaderSize.x = 320;
            ImGui::End();
        }
        if (!Globals::LoaderAttached)
        {
            // Loader mode: the HWND is already sized to the loader box by the
            // main loop, so the whole window is the loader. No transparency or
            // hit-test games needed - clicks outside the box never reach us.
            // No WS_EX_NOACTIVATE: the loader needs keyboard focus for text input.
            SetWindowLong(hwnd, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TOOLWINDOW);
        }
        else
        {
            // Attached overlay: keep it click-through unless the menu is open.
            // While open we drop WS_EX_TRANSPARENT so ImGui receives the mouse,
            // and WM_NCHITTEST (above) passes non-panel areas through to Roblox.
            g_MenuOpen = draw;
            DWORD ex = WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TOOLWINDOW;
            if (!g_MenuOpen)
                ex |= WS_EX_TRANSPARENT;
            SetWindowLong(hwnd, GWL_EXSTYLE, ex);
        }
        if (Globals::Misc::StreamProof)
        {
            SetWindowDisplayAffinity(hwnd, WDA_EXCLUDEFROMCAPTURE);
        }
        else
        {
            SetWindowDisplayAffinity(hwnd, WDA_NONE);
        }
        ImGui::Render();
        const float clear_color_with_alpha[4] = { 0, 0, 0, 0 };
        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, nullptr);
        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
        int vsyncison = Globals::Vsync ? 1 : 0;
        auto presT0 = std::chrono::steady_clock::now();
        HRESULT hr = g_pSwapChain->Present(vsyncison, 0);
        totalPresentUs += std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - presT0).count();
        if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
        {
            CleanupDeviceD3D();
            while (!CreateDeviceD3D(hwnd))
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            ImGui_ImplDX11_CreateDeviceObjects();
            g_SwapChainOccluded = false;
        }
        else
        {
            g_SwapChainOccluded = (hr == DXGI_STATUS_OCCLUDED);
        }
        totalFrameUs += std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - frameT0).count();
        if (!vsyncison)
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        if (++framesLogged >= 120)
        {
            Logging::Log(Logging::LogType::INFO, ("[perf] frame avg=" + std::to_string(totalFrameUs / framesLogged) + "us esp=" + std::to_string(totalEspUs / framesLogged) + "us present=" + std::to_string(totalPresentUs / framesLogged) + "us").c_str());
            framesLogged = 0;
            totalFrameUs = totalEspUs = totalPresentUs = 0;
        }
    }
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
    if (ConfigManager::CurrentGameId)
        ConfigManager::SaveConfig(ConfigManager::CurrentGameId);
    exit(0);
}
