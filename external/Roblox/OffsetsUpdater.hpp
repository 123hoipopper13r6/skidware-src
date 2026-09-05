#pragma once
#include "../Libs/Logging.h"
#include "../Roblox/Offsets.hpp"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdint>
#include <WinHttp.h>
#include <winver.h>
#pragma comment(lib, "version.lib")
#pragma comment(lib, "winhttp.lib")

namespace OffsetsUpdater
{
    inline std::string DownloadUrl(const std::wstring& host, const std::wstring& path)
    {
        std::string result;
        HINTERNET hSession = WinHttpOpen(L"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, NULL, NULL, 0);
        if (!hSession) { Logging::Log(Logging::LogType::ERR, xorstr_("[OffsetsUpdater] WinHttpOpen failed: %d"), GetLastError()); return result; }

        WinHttpSetTimeouts(hSession, 5000, 5000, 15000, 15000);
        HINTERNET hConnect = WinHttpConnect(hSession, host.c_str(), INTERNET_DEFAULT_HTTPS_PORT, 0);
        if (!hConnect) { Logging::Log(Logging::LogType::ERR, xorstr_("[OffsetsUpdater] WinHttpConnect failed: %d"), GetLastError()); WinHttpCloseHandle(hSession); return result; }
        HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"GET", path.c_str(), NULL, NULL, NULL, WINHTTP_FLAG_SECURE);
        if (!hRequest) { Logging::Log(Logging::LogType::ERR, xorstr_("[OffsetsUpdater] WinHttpOpenRequest failed: %d"), GetLastError()); WinHttpCloseHandle(hConnect); WinHttpCloseHandle(hSession); return result; }

        WinHttpAddRequestHeaders(hRequest, L"Accept: */*\r\n", -1, WINHTTP_ADDREQ_FLAG_ADD);
        if (!WinHttpSendRequest(hRequest, NULL, 0, NULL, 0, 0, 0)) {
            Logging::Log(Logging::LogType::ERR, xorstr_("[OffsetsUpdater] WinHttpSendRequest failed: %d"), GetLastError());
            WinHttpCloseHandle(hRequest); WinHttpCloseHandle(hConnect); WinHttpCloseHandle(hSession); return result;
        }
        if (!WinHttpReceiveResponse(hRequest, NULL)) {
            Logging::Log(Logging::LogType::ERR, xorstr_("[OffsetsUpdater] WinHttpReceiveResponse failed: %d"), GetLastError());
            WinHttpCloseHandle(hRequest); WinHttpCloseHandle(hConnect); WinHttpCloseHandle(hSession); return result;
        }

        DWORD statusCode = 0;
        DWORD statusLen = sizeof(statusCode);
        if (WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, NULL, &statusCode, &statusLen, NULL))
            Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] HTTP status: %d"), statusCode);
        else
            Logging::Log(Logging::LogType::ERR, xorstr_("[OffsetsUpdater] Failed to get status code"));

        DWORD size = 0;
        while (WinHttpQueryDataAvailable(hRequest, &size) && size > 0) {
            std::vector<char> buf(size);
            DWORD read = 0;
            if (WinHttpReadData(hRequest, buf.data(), size, &read))
                result.append(buf.data(), read);
        }
        WinHttpCloseHandle(hRequest); WinHttpCloseHandle(hConnect); WinHttpCloseHandle(hSession);

        if (!result.empty()) {
            std::string preview = result.substr(0, std::min<size_t>(result.size(), 200));
            Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] Response preview (%zu/%zu bytes): %s"), preview.size(), result.size(), preview.c_str());
        }
        return result;
    }

    inline std::string FlattenOffsets(const std::string& content)
    {
        std::string result = "#pragma once\n#include <cstdint>\n\nnamespace SDK::Offsets\n{\n";
        std::istringstream stream(content);
        std::string line;
        int depth = 0;

        while (std::getline(stream, line))
        {
            std::string trimmed = line;
            trimmed.erase(0, trimmed.find_first_not_of(" \t\r\n"));
            trimmed.erase(trimmed.find_last_not_of(" \t\r\n") + 1);

            if (trimmed.empty()) continue;
            if (trimmed.find("/*") == 0 || trimmed.find("*") == 0 || trimmed.find("*/") == 0) continue;
            if (trimmed.find("#pragma") == 0 || trimmed.find("#include") == 0) continue;

            if (trimmed.find("namespace ") == 0)
            {
                depth++;
                continue;
            }

            if (trimmed[0] == '}')
            {
                depth--;
                if (depth <= 0) break;
                continue;
            }

            if (trimmed.find("constexpr") != std::string::npos)
                result += "    " + trimmed + "\n";
        }
        result += "}\n";
        return result;
    }

    inline void LoadRuntimeOffsets(const std::string& flat);
    inline void ApplyRawNamespaceOverrides(const std::string& raw);
    inline void ReportCriticalOffsets();

    inline bool FetchAndSaveOffsets()
    {
        try {
            Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] Fetching offsets from offsets.imtheo.lol..."));

            std::string content = DownloadUrl(L"offsets.imtheo.lol", L"/offsets.hpp");
            if (content.empty()) {
                Logging::Log(Logging::LogType::ERR, xorstr_("[OffsetsUpdater] Failed to download offsets (0 bytes)"));
                return false;
            }

            Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] Downloaded %zu bytes"), content.size());

            std::string flat = FlattenOffsets(content);

            if (!CreateDirectoryW(L"C:\\Skidware", NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
                Logging::Log(Logging::LogType::ERR, xorstr_("[OffsetsUpdater] CreateDirectory failed: %d"), GetLastError());

            // Save flattened copy to C:\Skidware\Offsets.h
            {
                std::ofstream file("C:\\Skidware\\Offsets.h");
                if (!file.is_open()) {
                    Logging::Log(Logging::LogType::ERR, xorstr_("[OffsetsUpdater] Failed to write C:\\Skidware\\Offsets.h"));
                } else {
                    file << flat;
                    Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] Saved flattened to C:\\Skidware\\Offsets.h (%zu bytes)"), flat.size());
                }
            }

            // Load into runtime variables
            if (!flat.empty())
                LoadRuntimeOffsets(flat);

            // Apply namespace-aware overrides from raw content (Pointer etc.)
            ApplyRawNamespaceOverrides(content);

            ReportCriticalOffsets();

            Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] Done"));
            return true;
        } catch (const std::exception& e) {
            Logging::Log(Logging::LogType::ERR, xorstr_("[OffsetsUpdater] Exception: %s"), e.what());
            return false;
        }
    }

    inline void ApplyRawNamespaceOverrides(const std::string& raw)
    {
        auto findInNS = [&](const std::string& ns, const std::string& var) -> uintptr_t {
            size_t pos = 0;
            while (true) {
                auto nsPos = raw.find("namespace " + ns, pos);
                if (nsPos == std::string::npos) break;
                auto brace = raw.find('{', nsPos);
                if (brace == std::string::npos) break;
                auto close = raw.find('}', brace);
                if (close == std::string::npos) break;
                auto varPos = raw.find(var, brace);
                if (varPos != std::string::npos && varPos < close) {
                    auto eq = raw.find('=', varPos);
                    if (eq != std::string::npos && eq < close) {
                        auto sc = raw.find(';', eq);
                        if (sc != std::string::npos && sc < close) {
                            std::string vs = raw.substr(eq + 1, sc - eq - 1);
                            vs.erase(0, vs.find_first_not_of(" \t\r\n"));
                            vs.erase(vs.find_last_not_of(" \t\r\n") + 1);
                            if (!vs.empty()) return (uintptr_t)std::stoull(vs, nullptr, 0);
                        }
                    }
                }
                pos = close + 1;
            }
            return 0;
        };
        uintptr_t v;
        v = findInNS("FakeDataModel", "Pointer");
        if (v) { SDK::Offsets::FakeDataModelPointer = v; Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] Raw: FakeDataModel::Pointer -> FakeDataModelPointer = 0x%llX"), v); }
        v = findInNS("FakeDataModel", "RealDataModel");
        if (v) { SDK::Offsets::FakeDataModelToDataModel = v; Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] Raw: FakeDataModel::RealDataModel -> FakeDataModelToDataModel = 0x%llX"), v); }
        v = findInNS("VisualEngine", "Pointer");
        if (v) { SDK::Offsets::VisualEnginePointer = v; Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] Raw: VisualEngine::Pointer -> VisualEnginePointer = 0x%llX"), v); }
        // Primitive namespace overrides for offsets that collide with other namespaces after flattening
        v = findInNS("Primitive", "Position");
        if (v) { SDK::Offsets::Position = v; Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] Raw: Primitive::Position -> Position = 0x%llX"), v); }
        v = findInNS("Primitive", "Rotation");
        if (v) { SDK::Offsets::Rotation = v; Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] Raw: Primitive::Rotation -> Rotation = 0x%llX"), v); }
        v = findInNS("Primitive", "Size");
        if (v) { SDK::Offsets::PartSize = v; Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] Raw: Primitive::Size -> PartSize = 0x%llX"), v); }
        v = findInNS("Humanoid", "CameraOffset");
        if (v) { SDK::Offsets::CameraOffset = v; Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] Raw: Humanoid::CameraOffset -> CameraOffset = 0x%llX"), v); }
    }

    inline void ReportCriticalOffsets()
    {
        struct Off { const char* label; uintptr_t val; const char* def; };
        std::vector<Off> list = {
            { "ChildrenStart",   SDK::Offsets::ChildrenStart,   "0x70" },
            { "ChildrenEnd",     SDK::Offsets::ChildrenEnd,     "0x8" },
            { "Name",            SDK::Offsets::Name,            "0x8" },
            { "Parent",          SDK::Offsets::Parent,          "0x68" },
            { "ClassDescriptor", SDK::Offsets::ClassDescriptor, "0x18" },
            { "FakeDataModelPointer", SDK::Offsets::FakeDataModelPointer, "0x0" },
            { "FakeDataModelToDataModel", SDK::Offsets::FakeDataModelToDataModel, "0x0" },
            { "VisualEnginePointer", SDK::Offsets::VisualEnginePointer, "0x0" },
            { "ViewMatrix",      SDK::Offsets::ViewMatrix,      "0x0" },
            { "Dimensions",      SDK::Offsets::Dimensions,      "0x0" },
            { "FOV",             SDK::Offsets::FOV,             "0x0" },
            { "Position",        SDK::Offsets::Position,        "0x0" },
            { "Velocity",        SDK::Offsets::Velocity,        "0x0" },
            { "DataModel",       SDK::Offsets::DataModel,       "0x0" },
            { "LocalPlayer",     SDK::Offsets::LocalPlayer,     "0x0" },
            { "GameId",          SDK::Offsets::GameId,          "0x0" },
        };
        for (const auto& o : list)
        {
            if (o.val == 0)
                Logging::Log(Logging::LogType::WARNING, xorstr_("[OffsetsUpdater] CRITICAL offset '%s' is ZERO (stale/missing)!"), o.label);
            else
                Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] %s = 0x%llX"), o.label, o.val);
        }
    }

    inline void LoadRuntimeOffsets(const std::string& flat)
    {
        std::istringstream stream(flat);
        std::string line;
        int loaded = 0;
        int lineNum = 0;

        // Track which variables have been set (first occurrence wins)
        bool set_Adornee = false, set_Anchored = false, set_AnchoredMask = false, set_AnimationId = false;
        bool set_AttributeToNext = false, set_AttributeToValue = false, set_AutoJumpEnabled = false;
        bool set_AutoRotate = false, set_BanningEnabled = false, set_BeamBrightness = false;
        bool set_BeamColor = false, set_BeamLightEmission = false, set_BeamLightInfuence = false;
        bool set_CFrame = false, set_Camera = false, set_CameraMaxZoomDistance = false;
        bool set_CameraMinZoomDistance = false, set_CameraMode = false, set_CameraPos = false;
        bool set_CameraOffset = false;
        bool set_CameraRotation = false, set_CameraSubject = false, set_CameraType = false;
        bool set_CanCollide = false, set_CanCollideMask = false, set_CanTouch = false;
        bool set_CanTouchMask = false, set_Character = false, set_Children = false;
        bool set_ChildrenEnd = false, set_ChildrenStart = false, set_ClassDescriptor = false;
        bool set_ClassName = false, set_CreatorId = false, set_CurrentCamera = false;
        bool set_DataModel = false, set_Dimensions = false, set_DisplayName = false;
        bool set_FOV = false, set_FakeDataModelPointer = false, set_FakeDataModelToDataModel = false;
        bool set_FieldOfView = false, set_FramePositionOffsetX = false, set_FramePositionOffsetY = false;
        bool set_GameId = false, set_GameLoaded = false, set_Health = false, set_HipHeight = false;
        bool set_Humanoid = false, set_HumanoidDisplayName = false, set_HumanoidRootPart = false;
        bool set_JobId = false, set_JumpPower = false, set_LocalPlayer = false;
        bool set_MaterialType = false, set_MaxHealth = false, set_MeshPartColor3 = false;
        bool set_ModelInstance = false, set_MousePosition = false, set_Name = false;
        bool set_NextGenReplicatorEnabledWrite4 = false, set_Parent = false, set_PartSize = false;
        bool set_PlaceId = false, set_Player = false, set_Position = false, set_Primitive = false;
        bool set_RigType = false, set_Rotation = false, set_Size = false, set_Team = false;
        bool set_TeamColor = false, set_Transparency = false, set_UserId = false, set_Value = false;
        bool set_Velocity = false, set_ViewMatrix = false, set_ViewportInt16 = false;
        bool set_ViewportSize = false, set_VisualEngine = false, set_VisualEnginePointer = false;
        bool set_VisualEngineToDataModel1 = false, set_VisualEngineToDataModel2 = false;
        bool set_WalkSpeed = false, set_WalkSpeedCheck = false, set_Workspace = false;
        bool set_WorkspaceToWorld = false, set_viewmatrix = false;

        while (std::getline(stream, line))
        {
            lineNum++;
            std::string trimmed = line;
            trimmed.erase(0, trimmed.find_first_not_of(" \t"));
            trimmed.erase(trimmed.find_last_not_of(" \t\r\n") + 1);

            size_t eq = trimmed.find('=');
            size_t sc = trimmed.find(';');
            if (eq == std::string::npos || sc == std::string::npos)
                continue;

            try {
                size_t idEnd = eq;
                while (idEnd > 0 && (trimmed[idEnd - 1] == ' ' || trimmed[idEnd - 1] == '\t'))
                    idEnd--;
                if (idEnd == 0) continue;
                size_t idStart = trimmed.find_last_of(" \t", idEnd - 1);
                if (idStart == std::string::npos) idStart = 0;
                else idStart++;

                std::string name = trimmed.substr(idStart, idEnd - idStart);
                uintptr_t val = (uintptr_t)std::stoull(trimmed.substr(eq + 1, sc - eq - 1), nullptr, 0);

                #define SETONCE(n) if (!set_##n && name == #n) { SDK::Offsets::n = val; set_##n = true; loaded++; }
                #define SETALIAS(newName, oldName) if (!set_##oldName && name == newName) { SDK::Offsets::oldName = val; set_##oldName = true; loaded++; }

                SETONCE(Adornee) SETONCE(Anchored) SETONCE(AnchoredMask) SETONCE(AnimationId)
                SETONCE(AttributeToNext) SETONCE(AttributeToValue) SETONCE(AutoJumpEnabled)
                SETONCE(AutoRotate) SETONCE(BanningEnabled) SETONCE(BeamBrightness)
                SETONCE(BeamColor) SETONCE(BeamLightEmission) SETONCE(BeamLightInfuence)
                SETONCE(CFrame) SETONCE(Camera) SETONCE(CameraMaxZoomDistance)
                SETONCE(CameraMinZoomDistance) SETONCE(CameraMode) SETONCE(CameraPos)
                SETONCE(CameraOffset)
                SETONCE(CameraRotation) SETONCE(CameraSubject) SETONCE(CameraType)
                SETONCE(CanCollide) SETONCE(CanCollideMask) SETONCE(CanTouch)
                SETONCE(CanTouchMask) SETONCE(Character) SETONCE(Children)
                SETONCE(ChildrenEnd) SETONCE(ChildrenStart) SETONCE(ClassDescriptor)
                SETONCE(ClassName) SETONCE(CreatorId) SETONCE(CurrentCamera)
                SETONCE(DataModel) SETONCE(Dimensions) SETONCE(DisplayName)
                SETONCE(FOV) SETONCE(FakeDataModelPointer) SETONCE(FakeDataModelToDataModel)
                SETONCE(FieldOfView) SETONCE(FramePositionOffsetX) SETONCE(FramePositionOffsetY)
                SETONCE(GameId) SETONCE(GameLoaded) SETONCE(Health) SETONCE(HipHeight)
                SETONCE(Humanoid) SETONCE(HumanoidDisplayName) SETONCE(HumanoidRootPart)
                SETONCE(JobId) SETONCE(JumpPower) SETONCE(LocalPlayer)
                SETONCE(MaterialType) SETONCE(MaxHealth) SETONCE(MeshPartColor3)
                SETONCE(ModelInstance) SETONCE(MousePosition) SETONCE(Name)
                SETONCE(NextGenReplicatorEnabledWrite4) SETONCE(Parent) SETONCE(PartSize)
                SETONCE(PlaceId) SETONCE(Player) SETONCE(Position) SETONCE(Primitive)
                SETONCE(RigType) SETONCE(Rotation) SETONCE(Size) SETONCE(Team)
                SETONCE(TeamColor) SETONCE(Transparency) SETONCE(UserId) SETONCE(Value)
                SETONCE(Velocity) SETONCE(ViewMatrix) SETONCE(ViewportInt16)
                SETONCE(ViewportSize) SETONCE(VisualEngine) SETONCE(VisualEnginePointer)
                SETONCE(VisualEngineToDataModel1) SETONCE(VisualEngineToDataModel2)
                SETONCE(WalkSpeed) SETONCE(WalkSpeedCheck) SETONCE(Workspace)
                SETONCE(WorkspaceToWorld) SETONCE(viewmatrix)

                // Aliases for offsets with different names (same concept)
                SETALIAS("Walkspeed", WalkSpeed)
                SETALIAS("WalkspeedCheck", WalkSpeedCheck)
                SETALIAS("FieldOfView", FOV)

                #undef SETONCE
                #undef SETALIAS
            } catch (const std::exception& e) {
                Logging::Log(Logging::LogType::ERR, xorstr_("[OffsetsUpdater] Parse error line %d: %s - '%s'"), lineNum, e.what(), trimmed.c_str());
            }
        }
        Logging::Log(Logging::LogType::INFO, xorstr_("[OffsetsUpdater] Loaded %d runtime offsets"), loaded);
    }
};

// Provide a file-based reload for later use
inline void ReloadOffsetsFromDisk()
{
    std::ifstream file("C:\\Skidware\\Offsets.h");
    if (!file.is_open()) return;
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    if (!content.empty())
        OffsetsUpdater::LoadRuntimeOffsets(content);
}

// Version checking
inline std::string GetRobloxVersion()
{
    try {
        wchar_t path[MAX_PATH];
        DWORD pid = SDK::GetProcessId(xorstr_("RobloxPlayerBeta.exe"));
        if (!pid) return "";
        HANDLE hProc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
        if (!hProc) return "";
        DWORD len = MAX_PATH;
        if (!QueryFullProcessImageNameW(hProc, 0, path, &len)) { CloseHandle(hProc); return ""; }
        CloseHandle(hProc);
        DWORD dummy;
        DWORD verSize = GetFileVersionInfoSizeW(path, &dummy);
        if (!verSize) return "";
        std::vector<char> buf(verSize);
        if (!GetFileVersionInfoW(path, 0, verSize, buf.data())) return "";
        VS_FIXEDFILEINFO* fi = nullptr;
        UINT fiLen = 0;
        if (!VerQueryValueW(buf.data(), L"\\", (void**)&fi, &fiLen)) return "";
        char v[64];
        sprintf_s(v, "%d.%d.%d.%d", HIWORD(fi->dwFileVersionMS), LOWORD(fi->dwFileVersionMS), HIWORD(fi->dwFileVersionLS), LOWORD(fi->dwFileVersionLS));
        return v;
    } catch (...) { return ""; }
}

inline std::string FetchCurrentRobloxVersion()
{
    try {
        std::string json = OffsetsUpdater::DownloadUrl(L"weao.xyz", L"/api/versions/current");
        if (json.empty()) return "";
        // Try WindowsResponse.version first (dot-separated like local version)
        auto resp = json.find("\"WindowsResponse\":");
        if (resp != std::string::npos) {
            auto ver = json.find("\"version\":\"", resp + 18);
            if (ver != std::string::npos) {
                ver += 11;
                auto end = json.find("\"", ver);
                if (end != std::string::npos)
                    return json.substr(ver, end - ver);
            }
        }
        // Fallback to Windows field (build ID)
        auto pos = json.find("\"Windows\":\"");
        if (pos == std::string::npos) return "";
        pos += 10;
        auto end = json.find("\"", pos);
        if (end == std::string::npos) return "";
        return json.substr(pos, end - pos);
    } catch (...) { return ""; }
}

inline bool CheckRobloxVersion()
{
    try {
        std::string current = FetchCurrentRobloxVersion();
        if (current.empty()) {
            Logging::Log(Logging::LogType::WARNING, xorstr_("[VersionCheck] Could not fetch current version from weao.xyz"));
            return true;
        }
        std::string local = GetRobloxVersion();
        if (local.empty()) {
            Logging::Log(Logging::LogType::WARNING, xorstr_("[VersionCheck] Could not determine local Roblox version"));
            return true;
        }
        Logging::Log(Logging::LogType::INFO, xorstr_("[VersionCheck] Local: %s  Current: %s"), local.c_str(), current.c_str());
        // Compare only first 3 segments (major.minor.build); patch field varies independently
        std::string localPrefix = local.substr(0, local.rfind('.'));
        std::string currentPrefix = current.substr(0, current.rfind('.'));
        if (localPrefix != currentPrefix) {
            Logging::Log(Logging::LogType::WARNING, xorstr_("[VersionCheck] Version mismatch: local=%s current=%s"), local.c_str(), current.c_str());
            int ret = MessageBoxA(NULL, xorstr_("the current offset updater is not ready for the new version pls wait thx"), xorstr_("Version Mismatch"), MB_OKCANCEL | MB_ICONWARNING);
            return (ret == IDOK);
        }
        return true;
    } catch (const std::exception& e) {
        Logging::Log(Logging::LogType::WARNING, xorstr_("[VersionCheck] Exception: %s"), e.what());
        return true;
    }
}
