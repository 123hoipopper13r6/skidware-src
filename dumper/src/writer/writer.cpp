#include "writer.h"
#include "config.h"
#include "sdk_legacy_fallback.h"
#include "dumper/dumper.h"
#include "process/process.h"
#include <algorithm>
#include <filesystem>
#include <format>
#include <sstream>
#include <fstream>
#include <ctime>
#include <set>
#include <spdlog/spdlog.h>

namespace dumper::writer {

    static auto utc_timestamp() -> std::string {
        const auto now = std::chrono::system_clock::now();
        const auto t = std::chrono::system_clock::to_time_t(now);
        std::tm tm{};
        gmtime_s(&tm, &t);
        char buf[40];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S UTC", &tm);
        return buf;
    }

    // short explanation of HOW these offsets were obtained
    static auto method_summary() -> std::string {
        return "Method:\n"
               "  1. Bridge ground truth - an in-game script creates test instances with\n"
               "      known unique values and reports them as JSON via ReplicatedStorage.\n"
               "  2. Empirical scanning - instance memory is searched for those values;\n"
               "      offsets are only accepted when they verify across many instances.\n"
               "  3. RTTI / class-descriptor walks resolve services and child pointers.\n"
               "  4. String-signature + xref scans locate engine singletons.\n"
               "  5. FastFlags - heap registry discovery via name-pointer slots, with\n"
               "      statistical per-type payload layout inference.";
    }

    auto IWriter::write(const std::string& filename, std::chrono::milliseconds elapsed_time)
        -> bool {
        try {
            std::filesystem::path exe_path = std::filesystem::current_path();

            std::string final_filename = filename;
            std::string ext = get_file_extension();
            if (final_filename.length() < ext.length() ||
                final_filename.compare(final_filename.length() - ext.length(), ext.length(), ext) !=
                    0) {
                final_filename += ext;
            }

            std::filesystem::path output_path = exe_path / final_filename;

            std::ofstream file(output_path);
            if (!file.is_open()) {
                spdlog::error("Failed to open file for writing: {}", output_path.string());
                return false;
            }

            spdlog::info("Writer: generating {}...", final_filename);
            file << generate_header_comment(elapsed_time);

            file << generate_content();
            spdlog::info("Writer: generated {} ok", final_filename);

            file.close();

            spdlog::info("Successfully wrote offsets to: {}", output_path.string());
            return true;

        } catch (const std::exception& e) {
            spdlog::error("Failed to write file: {}", e.what());
            return false;
        }
    }

    auto IWriter::generate_header_comment(std::chrono::milliseconds elapsed_time) -> std::string {
        const auto version = process::g_process.get_version();
        std::string version_str = version ? *version : "unknown";

        std::string comment = "/*\n";
        comment += " * Dumped With: " + std::string(PROJECT_NAME) + " " +
                   std::string(PROJECT_VERSION) + " (by Ox Alpha)\n";
        comment += " * Fork of jonah/nopjo's roblox-dumper\n";
        comment += " * Dumped At: " + utc_timestamp() + "\n";
        comment += " * Roblox Version: " + version_str + "\n";
        comment += " * Time Taken: " + std::to_string(elapsed_time.count()) + " ms (" +
                   std::to_string(elapsed_time.count() / 1000.0) + " seconds)\n";
        comment += " * Total Offsets: " + std::to_string(get_total_offset_count()) + "\n";
        comment += " *\n";
        {
            std::istringstream ms(method_summary());
            std::string line;
            while (std::getline(ms, line))
                comment += " * " + line + "\n";
        }
        comment += " */\n\n";
        return comment;
    }

    auto IWriter::get_sorted_namespaces()
        -> std::vector<std::pair<std::string, std::vector<dumper::OffsetEntry>>> {
        const auto& offsets = g_dumper.m_offsets;

        std::vector<std::pair<std::string, std::vector<dumper::OffsetEntry>>> sorted_namespaces(
            offsets.begin(), offsets.end());

        std::sort(sorted_namespaces.begin(), sorted_namespaces.end(),
                  [](const auto& a, const auto& b) { return a.first < b.first; });

        for (auto& [namespace_name, entries] : sorted_namespaces) {
            std::sort(entries.begin(), entries.end(),
                      [](const auto& a, const auto& b) { return a.name < b.name; });
        }

        return sorted_namespaces;
    }

    auto IWriter::get_total_offset_count() -> size_t {
        size_t total = 0;
        for (const auto& [namespace_name, entries] : g_dumper.m_offsets) {
            total += entries.size();
        }
        return total;
    }

    auto HeaderWriter::generate_content() -> std::string {
        auto version = process::g_process.get_version();
        std::string version_str = version ? *version : "unknown";

        std::string content = "#pragma once\n";
        content += "#include <cstdint>\n\n";
        content += "// clang-format off\n";
        content += "namespace offsets {\n";
        content += "    inline constexpr const char* roblox_version = \"" + version_str + "\";\n\n";

        for (const auto& [namespace_name, entries] : get_sorted_namespaces()) {
            if (entries.empty()) {
                continue;
            }

            content += "    namespace " + namespace_name + " {";
            auto ns_comment_it = g_dumper.m_namespace_comments.find(namespace_name);
            if (ns_comment_it != g_dumper.m_namespace_comments.end() &&
                !ns_comment_it->second.empty())
                content += " // " + ns_comment_it->second;
            content += "\n";

            for (const auto& entry : entries) {
                content += "        inline constexpr uintptr_t " + entry.name + " = 0x" +
                           std::format("{:X}", entry.offset) + ";";
                if (!entry.comment.empty())
                    content += " // " + entry.comment;
                const auto desc =
                    g_dumper.m_offset_descriptions.find(namespace_name + "::" + entry.name);
                if (desc != g_dumper.m_offset_descriptions.end()) {
                    content += (entry.comment.empty() ? " // " : " - ") + desc->second;
                }
                content += "\n";
            }

            content += "    }\n\n";
        }

            content += "} // namespace offsets\n";

        if (!g_dumper.m_enums.empty()) {
            content += "\nnamespace enums {\n";
            auto sorted_enums = std::vector<std::pair<std::string, std::vector<dumper::EnumEntry>>>(
                g_dumper.m_enums.begin(), g_dumper.m_enums.end());
            std::sort(sorted_enums.begin(), sorted_enums.end(),
                      [](const auto& a, const auto& b) { return a.first < b.first; });

            for (auto& [enum_name, entries] : sorted_enums) {
                std::sort(entries.begin(), entries.end(),
                          [](const auto& a, const auto& b) { return a.value < b.value; });
                content += "    enum class " + enum_name + " : int {\n";
                for (const auto& entry : entries) {
                    content += "        " + entry.name + " = " +
                               std::format("0x{:X}", entry.value) + ",\n";
                }
                content += "    };\n\n";
            }
            content += "} // namespace enums\n";
        }

    if (!g_dumper.m_fflags.empty()) {
            content += "namespace FFlags {\n";
            auto sorted_flags = g_dumper.m_fflags;
            std::sort(sorted_flags.begin(), sorted_flags.end(),
                      [](const auto& a, const auto& b) { return a.name < b.name; });
            for (const auto& flag : sorted_flags) {
                content += "    inline constexpr uintptr_t " + flag.name + " = 0x" +
                           std::format("{:X}", flag.address) + "; // " + flag.type + " = " +
                           flag.value_str + "\n";
            }
            content += "} // namespace FFlags\n";
        }

        return content;
    }

    auto JsonWriter::generate_header_comment(std::chrono::milliseconds elapsed_time)
        -> std::string {
        return "";
    }

    auto JsonWriter::generate_content() -> std::string {
        auto version = process::g_process.get_version();
        std::string version_str = version ? *version : "unknown";

        std::string methods_escaped;
        for (char ch : method_summary())
            methods_escaped += (ch == '\n') ? ' ' : ch;

        std::string content = "{\n";
        content += "  \"metadata\": {\n";
        content += "    \"dumper\": \"" + std::string(PROJECT_NAME) + " " +
                   std::string(PROJECT_VERSION) + " (by Ox Alpha)\",\n";
        content += "    \"source\": \"fork of jonah/nopjo's roblox-dumper\",\n";
        content += "    \"dumped_at\": \"" + utc_timestamp() + "\",\n";
        content += "    \"roblox_version\": \"" + version_str + "\",\n";
        content += "    \"method\": \"" + methods_escaped + "\",\n";
        content += "    \"total_offsets\": " + std::to_string(get_total_offset_count()) + "\n";
        content += "  },\n";
        content += "  \"offsets\": {\n";

        auto sorted_namespaces = get_sorted_namespaces();
        for (size_t i = 0; i < sorted_namespaces.size(); ++i) {
            const auto& [namespace_name, entries] = sorted_namespaces[i];
            if (entries.empty()) {
                continue;
            }

            content += "    \"" + namespace_name + "\": {\n";

            for (size_t j = 0; j < entries.size(); ++j) {
                const auto& entry = entries[j];
                content += "      \"" + entry.name + "\": " + std::to_string(entry.offset);
                if (j < entries.size() - 1) {
                    content += ",";
                }
                content += "\n";
            }

            content += "    }";
            if (i < sorted_namespaces.size() - 1) {
                content += ",";
            }
            content += "\n";
        }

        content += "  },\n";
        content += "  \"enums\": {\n";

        auto sorted_enums = std::vector<std::pair<std::string, std::vector<dumper::EnumEntry>>>(
            g_dumper.m_enums.begin(), g_dumper.m_enums.end());
        std::sort(sorted_enums.begin(), sorted_enums.end(),
                  [](const auto& a, const auto& b) { return a.first < b.first; });

        for (size_t i = 0; i < sorted_enums.size(); ++i) {
            auto& [enum_name, entries] = sorted_enums[i];
            std::sort(entries.begin(), entries.end(),
                      [](const auto& a, const auto& b) { return a.value < b.value; });
            content += "    \"" + enum_name + "\": {\n";
            for (size_t j = 0; j < entries.size(); ++j) {
                content += "      \"" + entries[j].name + "\": " + std::to_string(entries[j].value);
                if (j < entries.size() - 1)
                    content += ",";
                content += "\n";
            }
            content += "    }";
            if (i < sorted_enums.size() - 1)
                content += ",";
            content += "\n";
        }

        content += "  }";

        if (!g_dumper.m_fflags.empty()) {
            content += ",\n  \"FFlags\": {\n";
            content += "    \"_note\": \"addresses are absolute and valid for this session only\",\n";
            auto sorted_flags = g_dumper.m_fflags;
            std::sort(sorted_flags.begin(), sorted_flags.end(),
                      [](const auto& a, const auto& b) { return a.name < b.name; });
            for (size_t i = 0; i < sorted_flags.size(); ++i) {
                const auto& f = sorted_flags[i];
                content += "    \"" + f.name + "\": {\"type\": \"" + f.type +
                           "\", \"address\": " + std::to_string(f.address) + ", \"value\": " +
                           (f.type == "Bool" || f.type == "Int" || f.type == "Double"
                                ? f.value_str
                                : "\"" + f.value_str + "\"") +
                           "}";
                if (i < sorted_flags.size() - 1)
                    content += ",";
                content += "\n";
            }
            content += "  }";
        }

        content += "\n}\n";
        return content;
    }

    auto PythonWriter::generate_content() -> std::string {
        auto version = process::g_process.get_version();
        std::string version_str = version ? *version : "unknown";

        std::string content = "";
        content += "class Offsets:\n";
        content += "    ROBLOX_VERSION = \"" + version_str + "\"\n\n";

        for (const auto& [namespace_name, entries] : get_sorted_namespaces()) {
            if (entries.empty()) {
                continue;
            }

            content += "    class " + namespace_name + ":";
            {
                auto it = g_dumper.m_namespace_comments.find(namespace_name);
                if (it != g_dumper.m_namespace_comments.end() && !it->second.empty())
                    content += "  # " + it->second;
            }
            content += "\n";

            for (const auto& entry : entries) {
                content += "        " + entry.name + " = " + std::to_string(entry.offset);
                const auto desc =
                    g_dumper.m_offset_descriptions.find(namespace_name + "::" + entry.name);
                if (desc != g_dumper.m_offset_descriptions.end())
                    content += "  # " + desc->second;
                content += "\n";
            }

            content += "\n";
        }

        if (!g_dumper.m_enums.empty()) {
            content += "\n";
            auto sorted_enums = std::vector<std::pair<std::string, std::vector<dumper::EnumEntry>>>(
                g_dumper.m_enums.begin(), g_dumper.m_enums.end());
            std::sort(sorted_enums.begin(), sorted_enums.end(),
                      [](const auto& a, const auto& b) { return a.first < b.first; });

            for (auto& [enum_name, entries] : sorted_enums) {
                std::sort(entries.begin(), entries.end(),
                          [](const auto& a, const auto& b) { return a.value < b.value; });
                content += "    class " + enum_name + ":\n";
                for (const auto& entry : entries) {
                    content += "        " + entry.name + " = " + std::to_string(entry.value) + "\n";
                }
                content += "\n";
            }
        }

        if (!g_dumper.m_fflags.empty()) {
            content += "\nclass FFlags:\n";
            content += "    \"\"\"FastFlag value addresses (absolute, this session only)\"\"\"\n\n";
            auto sorted_flags = g_dumper.m_fflags;
            std::sort(sorted_flags.begin(), sorted_flags.end(),
                      [](const auto& a, const auto& b) { return a.name < b.name; });
            for (const auto& f : sorted_flags) {
                content += "    " + f.name + " = " + std::to_string(f.address) + "  # " +
                           f.type + " = " + f.value_str + "\n";
            }
        }

        return content;
    }

    auto PythonWriter::generate_header_comment(std::chrono::milliseconds elapsed_time)
        -> std::string {
        auto version = process::g_process.get_version();
        std::string version_str = version ? *version : "unknown";

        std::string comment = "# Dumped With: " + std::string(PROJECT_NAME) + " " +
                              std::string(PROJECT_VERSION) + " (by Ox Alpha)\n";
        comment += "# Fork of jonah/nopjo's roblox-dumper\n";
        comment += "# Dumped At: " + utc_timestamp() + "\n";
        comment += "# Roblox Version: " + version_str + "\n";
        comment += "# Time Taken: " + std::to_string(elapsed_time.count()) + " ms (" +
                   std::to_string(elapsed_time.count() / 1000.0) + " seconds)\n";
        comment += "# Total Offsets: " + std::to_string(get_total_offset_count()) + "\n";
        {
            std::istringstream ms(method_summary());
            std::string line;
            while (std::getline(ms, line))
                if (!line.empty())
                    comment += "# " + line + "\n";
        }
        comment += "\n";
        return comment;
    }

    auto CSharpWriter::generate_content() -> std::string {
        auto version = process::g_process.get_version();
        std::string version_str = version ? *version : "unknown";

        std::string content = "using System;\n\n";
        content += "namespace RobloxOffsets\n{\n";
        content += "    public static class Metadata\n    {\n";
        content += "        public const string RobloxVersion = \"" + version_str + "\";\n";
        content += "    }\n\n";

        for (const auto& [namespace_name, entries] : get_sorted_namespaces()) {
            if (entries.empty()) {
                continue;
            }

            {
                auto it = g_dumper.m_namespace_comments.find(namespace_name);
                if (it != g_dumper.m_namespace_comments.end() && !it->second.empty())
                    content += "    // " + it->second + "\n";
            }
            content += "    public static class " + namespace_name + "\n    {\n";

            for (const auto& entry : entries) {
                content += "        public const ulong " + entry.name + " = 0x" +
                           std::format("{:X}", entry.offset) + ";";
                const auto desc =
                    g_dumper.m_offset_descriptions.find(namespace_name + "::" + entry.name);
                if (desc != g_dumper.m_offset_descriptions.end())
                    content += " // " + desc->second;
                content += "\n";
            }

            content += "    }\n\n";
        }

        if (!g_dumper.m_enums.empty()) {
            auto sorted_enums = std::vector<std::pair<std::string, std::vector<dumper::EnumEntry>>>(
                g_dumper.m_enums.begin(), g_dumper.m_enums.end());
            std::sort(sorted_enums.begin(), sorted_enums.end(),
                      [](const auto& a, const auto& b) { return a.first < b.first; });

            for (auto& [enum_name, entries] : sorted_enums) {
                std::sort(entries.begin(), entries.end(),
                          [](const auto& a, const auto& b) { return a.value < b.value; });
                content += "    public enum " + enum_name + "\n    {\n";
                for (const auto& entry : entries) {
                    content += "        " + entry.name + " = 0x" +
                               std::format("{:X}", entry.value) + ",\n";
                }
                content += "    }\n\n";
            }
        }

        if (!g_dumper.m_fflags.empty()) {
            content += "    // FastFlag value addresses (absolute, this session only)\n";
            content += "    public static class FFlags\n    {\n";
            auto sorted_flags = g_dumper.m_fflags;
            std::sort(sorted_flags.begin(), sorted_flags.end(),
                      [](const auto& a, const auto& b) { return a.name < b.name; });
            for (const auto& f : sorted_flags) {
                content += "        public const ulong " + f.name + " = 0x" +
                           std::format("{:X}", f.address) + "; // " + f.type + " = " +
                           f.value_str + "\n";
            }
            content += "    }\n\n";
        }

        content += "} // namespace RobloxOffsets\n";
        return content;
    }

    auto SdkWriter::generate_header_comment(std::chrono::milliseconds)
        -> std::string {
        return "// Paste over Roblox/Offsets.hpp. Flat SDK::Offsets names; on collision\n"
               "// the priority class keeps the bare name, others get <Class>_<Name>.\n";
    }

    auto SdkWriter::generate_content() -> std::string {
        // namespaces allowed to claim bare property names, in order. Everything
        // else always emits <Class>_<Name> so long-tail getter-decoded classes
        // can never shadow core names like Name/Parent/Health.
        static const char* priority[] = {
            "Primitive", "BasePart", "Humanoid", "Player", "Players", "Instance",
            "DataModel", "Workspace", "World",   "Camera",  "VisualEngine",
            "TaskScheduler", "Lighting", "ClassDescriptor", "Descriptor",
            "Highlight", "Animation", "Animator", "Beam", "Decal", "Fire",
            "Explosion", "ParticleEmitter", "SpawnLocation", "ImageLabel",
            "TextLabel", "TextButton", "TextBox", "LinearVelocity", "Motor6D",
            "Team", "Sound", "Seat", "VehicleSeat", "MeshPart", "Model",
            "ModuleScript", "Script", "Tool", "Sky", "SpecialMesh", "Terrain",
            "GuiObject", "ProximityPrompt", "ClickDetector", "MouseService",
            "FunctionDescriptor", "PropertyDescriptor", "Value", "Types"};

        const auto sorted_in = get_sorted_namespaces();

        // collapse duplicate names inside a namespace, preferring scanned/verified
        // values over getter-decoded ones (stages run in parallel)
        std::vector<std::pair<std::string, std::vector<OffsetEntry>>> ordered;
        for (const auto& [ns, entries] : sorted_in) {
            if (ns == "FastFlags")
                continue;
            std::vector<OffsetEntry> clean;
            for (const auto& e : entries) {
                const bool decoded = e.comment == "decoded from property getter";
                auto it = std::find_if(clean.begin(), clean.end(),
                                       [&](const OffsetEntry& x) {
                                           return x.name == e.name;
                                       });
                if (it == clean.end())
                    clean.push_back(e);
                else if (!decoded)
                    *it = e; // scanned value replaces a getter-decoded dup
            }
            ordered.push_back({ns, std::move(clean)});
        }

        std::vector<std::pair<std::string, const std::vector<OffsetEntry>*>> ordered_ns;
        for (const char* p : priority)
            for (const auto& [ns, entries] : ordered)
                if (ns == p) {
                    ordered_ns.push_back({ns, &entries});
                    break;
                }
        for (const auto& [ns, entries] : ordered) {
            const bool in_priority =
                std::any_of(std::begin(priority), std::end(priority),
                            [&](const char* p) { return ns == p; });
            if (!in_priority)
                ordered_ns.push_back({ns, &entries});
        }

        // legacy Skidware aliases: names their attach code references. Values come
        // from the live dump so they are always fresh for this build.
        static const std::pair<const char*, std::pair<const char*, const char*>>
            aliases[] = {
                {"Velocity", {"Primitive", "AssemblyLinearVelocity"}},
                {"CameraPos", {"Camera", "Position"}},
                {"WorldGravity", {"World", "Gravity"}},
                {"FakeDataModelPointer", {"FakeDataModel", "Pointer"}},
                {"FakeDataModelToDataModel", {"FakeDataModel", "RealDataModel"}},
                {"VisualEnginePointer", {"VisualEngine", "Pointer"}},
            };

        std::string content = "#pragma once\n#include <cstdint>\n\n";
        content += "namespace SDK::Offsets\n{\n";

        std::set<std::string> used;
        size_t emitted = 0;
        for (const auto& [alias, src] : aliases) {
            if (auto v = dumper::g_dumper.get_offset(src.first, src.second)) {
                used.insert(alias);
                content +=
                    std::format("    inline uintptr_t {} = 0x{:X}; // {}\n", alias, *v,
                                src.first);
            }
        }

        for (const auto& [ns, entries] : ordered_ns) {
            auto sorted_entries = *entries;
            std::sort(sorted_entries.begin(), sorted_entries.end(),
                      [](const OffsetEntry& a, const OffsetEntry& b) {
                          return a.name < b.name;
                      });
            content += "\n    // ---- " + ns + " ----\n";
            const bool bare_ok =
                std::any_of(std::begin(priority), std::end(priority),
                            [&](const char* p) { return ns == p; });
            for (const auto& e : sorted_entries) {
                std::string var;
                if (bare_ok && !used.count(e.name)) {
                    var = e.name;
                } else {
                    var = ns + "_" + e.name;
                    while (used.count(var))
                        var += "_";
                }
                used.insert(var);
                content +=
                    std::format("    inline uintptr_t {} = 0x{:X};\n", var, e.offset);
                ++emitted;
            }
        }

        // legacy names their code still references but the dynamic dump doesn't
        // produce - fall back to the original hand-maintained values so the SDK
        // keeps compiling
        for (const auto& [name, value] : kSdkLegacyFallback) {
            if (used.count(name))
                continue;
            used.insert(name);
            content += std::format("    inline uintptr_t {} = 0x{:X};\n", name, value);
        }

        // nested WorldRoot block: RaycastHook.cpp addresses these as
        // SDK::Offsets::WorldRoot::RaycastBound*
        if (auto d = dumper::g_dumper.get_offset("WorldRoot", "RaycastBoundDesc")) {
            content += "\n    namespace WorldRoot\n    {\n";
            content += std::format(
                "        inline uintptr_t RaycastBoundDesc = 0x{:X};\n", *d);
            if (auto f = dumper::g_dumper.get_offset("WorldRoot", "RaycastBoundFn"))
                content += std::format(
                    "        inline uintptr_t RaycastBoundFn = 0x{:X};\n", *f);
            content += "    }\n";
        }

        content += "}\n";
        spdlog::info("SdkWriter: {} flat offsets", emitted);
        return content;
    }

    auto SdkFFlagsWriter::generate_header_comment(std::chrono::milliseconds)
        -> std::string {
        return "// Paste over Roblox/FFlags.hpp. Flag addresses are absolute and valid\n"
               "// for the dumped game session only - regenerate after every rejoin.\n";
    }

    auto SdkFFlagsWriter::generate_content() -> std::string {
        std::string content = "#pragma once\n#include <cstdint>\n#include <cstring>\n\n";
        content += "namespace SDK::FFlags\n{\n";
        content += "    enum class FlagType : uint8_t { Bool, Int, Double, String };\n\n";
        content += "    struct Entry\n    {\n";
        content += "        const char* Name;\n        FlagType Type;\n";
        content += "        uintptr_t Address;\n    };\n\n";

        auto sorted = g_dumper.m_fflags;
        std::sort(sorted.begin(), sorted.end(),
                  [](const dumper::FastFlagEntry& a, const dumper::FastFlagEntry& b) {
                      return a.name < b.name;
                  });

        content += "    inline const Entry Entries[] = {\n";
        size_t count = 0;
        for (const auto& f : sorted) {
            if (f.type == "Unknown")
                continue; // no verified payload layout - address only
            const char* type = f.type == "Bool"  ? "FlagType::Bool"
                               : f.type == "Int" ? "FlagType::Int"
                               : f.type == "Double"
                                   ? "FlagType::Double"
                                   : "FlagType::String";
            content += std::format("        {{ \"{}\", {}, 0x{:X} }}, // {}\n", f.name,
                                   type, f.address, f.value_str);
            ++count;
        }
        if (count == 0) {
            // zero-size arrays are ill-formed C++; keep a sentinel so the header
            // compiles even when no flags resolved this session
            content += "        { nullptr, FlagType::Bool, 0 },\n";
        }
        content += "    };\n";
        spdlog::info("SdkFFlagsWriter: {} flags", count);

        content += R"cpp(
    inline const Entry* Find(const char* name)
    {
        if (!name)
            return nullptr;
        for (const auto& e : Entries)
            if (e.Name && std::strcmp(e.Name, name) == 0)
                return &e;
        return nullptr;
    }

    inline bool GetBool(const char* name, bool fallback = false)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::Bool)
            return fallback;
        return SDK::Memory->Read<uint8_t>(e->Address) != 0;
    }

    inline bool SetBool(const char* name, bool value)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::Bool)
            return false;
        SDK::Memory->Write<uint8_t>(e->Address, value ? 1 : 0);
        return true;
    }

    inline int32_t GetInt(const char* name, int32_t fallback = 0)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::Int)
            return fallback;
        return SDK::Memory->Read<int32_t>(e->Address);
    }

    inline bool SetInt(const char* name, int32_t value)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::Int)
            return false;
        SDK::Memory->Write<int32_t>(e->Address, value);
        return true;
    }

    inline double GetDouble(const char* name, double fallback = 0.0)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::Double)
            return fallback;
        return SDK::Memory->Read<double>(e->Address);
    }

    inline bool SetDouble(const char* name, double value)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::Double)
            return false;
        SDK::Memory->Write<double>(e->Address, value);
        return true;
    }

    // string payloads are MSVC std::string objects (SSO at >=16 chars goes to heap)
    inline bool GetString(const char* name, char* out, size_t cap)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::String || !out || cap == 0)
            return false;
        const uint64_t len = SDK::Memory->Read<uint64_t>(e->Address + 0x10);
        if (len == 0 || len >= cap)
            return false;
        uintptr_t src = e->Address;
        if (len >= 16) {
            src = SDK::Memory->Read<uintptr_t>(e->Address);
            if (!src)
                return false;
        }
        return SDK::Memory->ReadRaw(src, out, len) && ((out[len] = 0), true);
    }
} // namespace SDK::FFlags
)cpp";
        return content;
    }

} // namespace dumper::writer
