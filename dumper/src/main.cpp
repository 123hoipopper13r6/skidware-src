#include "config.h"
#include "dumper/dumper.h"
#include "logger/logger.h"
#include "process/process.h"
#include "writer/struct_writer.h"
#include "writer/writer.h"
#include <Windows.h>
#include <chrono>
#include <filesystem>
#include <format>
#include <iostream>
#include <spdlog/spdlog.h>


auto main() -> int {
    logger::initialize();

    const auto title = std::format("{} {}", PROJECT_NAME, PROJECT_VERSION);

    spdlog::info("{} - skidware dumper (fork of jonah/nopjo's roblox-dumper, by Ox Alpha)", title);

    if (!process::g_process.attach("RobloxPlayerBeta.exe")) {
        spdlog::warn("RobloxPlayerBeta.exe not found, trying RobloxStudioBeta.exe (testing mode)");
        if (!process::g_process.attach("RobloxStudioBeta.exe")) {
            MessageBoxA(
                nullptr,
                "Failed to attach to Roblox, please rerun the Dumper when Roblox has fully loaded.",
                title.c_str(), MB_OK | MB_ICONERROR);
            return 1;
        }
    }

    spdlog::info("Attached to Roblox. PID: {}\n", process::g_process.get_pid());

    const auto start_time = std::chrono::steady_clock::now();
    dumper::g_dumper.start();

    const auto end_time = std::chrono::steady_clock::now();
    const auto elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    spdlog::info("Finished in {} ms ({:.2f} seconds)", elapsed.count(), elapsed.count() / 1000.0);

    dumper::writer::g_header_writer.write("offsets", elapsed);
    dumper::writer::g_json_writer.write("offsets", elapsed);
    dumper::writer::g_python_writer.write("offsets", elapsed);
    dumper::writer::g_csharp_writer.write("offsets", elapsed);
    dumper::writer::g_sdk_writer.write("sdk_offsets", elapsed);
    dumper::writer::g_sdk_fflags_writer.write("sdk_fflags", elapsed);
    dumper::writer::g_struct_writer.write("structs", elapsed);

    // drop the SDK headers straight into the Skidware project - no manual renaming
    {
        const std::filesystem::path sdk_dir =
            "D:\\skidware\\skidware-external\\skidware\\Roblox";
        const std::pair<const char*, const char*> deploy[] = {
            {"sdk_offsets.hpp", "Offsets.hpp"},
            {"sdk_fflags.hpp", "FFlags.hpp"},
        };
        for (const auto& [src, dst] : deploy) {
            std::error_code ec;
            std::filesystem::copy_file(src, sdk_dir / dst,
                                       std::filesystem::copy_options::overwrite_existing,
                                       ec);
            if (ec)
                spdlog::warn("Deploy: {} -> {} failed ({})", src, (sdk_dir / dst).string(),
                             ec.message());
            else
                spdlog::info("Deploy: {} -> {}", src, (sdk_dir / dst).string());
        }
    }

    logger::print_error_summary();

    return 0;
}
