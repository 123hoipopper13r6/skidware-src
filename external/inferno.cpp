#include "Includes.hpp"
#include "Security/AntiTamper/AntiTamperLib.h"
#include <filesystem>
#include <fstream>
#include <Json.hpp>

#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

static void ForceCrashLog(const char* msg)
{
    if (!msg) return;

    static bool firstLaunch = true;

    char path[MAX_PATH];
    if (ExpandEnvironmentStringsA("%LOCALAPPDATA%\\Temp\\Skidware\\Skidware_crash.log", path, MAX_PATH) == 0) {
        return;
    }

    std::filesystem::path filePath(path);
    std::error_code ec;
    std::filesystem::create_directories(filePath.parent_path(), ec);

    DWORD creationDisposition = firstLaunch ? CREATE_ALWAYS : OPEN_ALWAYS;

    HANDLE hFile = CreateFileA(
        path,
        GENERIC_WRITE,
        FILE_SHARE_READ,
        NULL,
        creationDisposition,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile != INVALID_HANDLE_VALUE) {
        if (firstLaunch) {
            firstLaunch = false;
        }
        else {
            SetFilePointer(hFile, 0, NULL, FILE_END);
        }

        DWORD written = 0;
        WriteFile(hFile, msg, static_cast<DWORD>(strlen(msg)), &written, NULL);
        WriteFile(hFile, "\r\n", 2, &written, NULL);

        FlushFileBuffers(hFile);
        CloseHandle(hFile);
    }
}

static void TerminateHandler()
{
    ForceCrashLog("[TERMINATE] std::terminate called");
    std::abort();
}

LONG WINAPI CrashHandler(EXCEPTION_POINTERS* pExceptionInfo)
{
    char buf[256];
    sprintf_s(buf, "UNHANDLED EXCEPTION: Code=0x%08lX Address=0x%p",
        pExceptionInfo->ExceptionRecord->ExceptionCode,
        pExceptionInfo->ExceptionRecord->ExceptionAddress);
    ForceCrashLog(buf);
    return EXCEPTION_CONTINUE_SEARCH;
}

static void UpdateDimensionsSEH()
{
    __try {
        SDK::VisualEngineCache::Dimensions = Globals::VisualEngine.Dimensions();
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        ForceCrashLog("[SEH] Exception reading VisualEngine dimensions");
    }
}

int main()
{
    SetUnhandledExceptionFilter(CrashHandler);
    std::set_terminate(TerminateHandler);

    ForceCrashLog("[INIT] main() started");

    VMProtectBeginUltra(xorstr_("Main()"));

    ForceCrashLog("[INIT] before checks");
    InitializeAntiTamper();
    ForceCrashLog("[INIT] after checks");

    if (!std::filesystem::exists("C:\\Skidware")) {
        std::filesystem::create_directory("C:\\Skidware");
    }
    if (!std::filesystem::exists("C:\\Skidware\\Configs")) {
        std::filesystem::create_directory("C:\\Skidware\\Configs");
    }

    ForceCrashLog("[INIT] Skidware dirs created at C:\\Skidware");

    AllocConsole();
    FILE* fDummy;
    freopen_s(&fDummy, "CONOUT$", "w", stdout);
    freopen_s(&fDummy, "CONOUT$", "w", stderr);
    std::cout << "[DEBUG] Console allocated" << std::endl;
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    Logging::Log(Logging::LogType::INFO, xorstr_("Hello World!"));
    PushNotification("Starting...");

    // Start the overlay (loader will show first, attach happens when user clicks Attach)
    std::thread(Overlay::Setup).detach();
    ForceCrashLog("[INIT] overlay thread detached");

    int tick = 0;
    while (true)
    {
        Globals::RobloxWindow = FindWindowA(0, xorstr_("Roblox"));

        if (Globals::LoaderAttached)
        {
            if (Globals::RobloxWindow == NULL) {
                ForceCrashLog("[MAIN] Roblox window not found");
                Logging::Log(Logging::LogType::WARNING, xorstr_("Roblox window not found, exiting..."));
                break;
            }
            if (Globals::RobloxProcessHandle && WaitForSingleObject(Globals::RobloxProcessHandle, 0) != WAIT_TIMEOUT) {
                ForceCrashLog("[MAIN] Roblox process exited");
                Logging::Log(Logging::LogType::WARNING, xorstr_("Roblox process exited"));
                break;
            }
            ForceCrashLog("[MAIN] Roblox window found");
            UpdateDimensionsSEH();
            ForceCrashLog("[MAIN] dimensions updated");
            tick++;
            if ((tick % 5) == 0) {
                ForceCrashLog("[MAIN] Heartbeat - main loop alive");
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    if (Globals::RobloxProcessHandle)
        CloseHandle(Globals::RobloxProcessHandle);
    exit(0);
    VMProtectEnd();
}
