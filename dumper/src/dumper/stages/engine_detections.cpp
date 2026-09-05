#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include <spdlog/spdlog.h>
#include <algorithm>
#include <vector>

namespace dumper::stages::engine_detections {

    struct FlagDef {
        uintptr_t rva;
        const char* note;
    };

    auto dump() -> bool {
        const auto base = process::g_process.get_module_base();
        if (!base) {
            spdlog::error("EngineDetections: no module base");
            return false;
        }

        // Detection flags are static DWORDs consumed by the Hyperion ping/telemetry
        // serializer (RBX::PingItem). The reporting code is virtualized/mutated and
        // the flags carry no bridge-observable ground truth, so these come from
        // static analysis of the matching build (rbxcli reference + IDA cross-check)
        // instead of an empirical scan. Absolute RVAs - re-derive after major updates.
        static const std::vector<FlagDef> flags = {
            {0x7EAD1C8, "PingItem serializer"},
            {0x7EAD1CC, "PingItem serializer"},
            {0x7ED1E3C, "PingItem serializer"},
            {0x7ED217C, "PingItem serializer"},
            {0x7ED3E28, "PingItem serializer"},
            {0x7ED3E2C, "PingItem serializer"},
            {0x7EDDA9C, "PingItem serializer"},
            {0x7EDE2AC, "PingItem serializer"},
            {0x7EDE33C, "PingItem serializer"},
            {0x7EDE538, "PingItem serializer"},
            {0x7EDE53C, "PingItem serializer"},
            {0x7EDEB98, "PingItem serializer"},
            {0x7EDEB9C, "PingItem serializer"},
            {0x7EE6B20, "PingItem serializer"},
            {0x7EE6B24, "PingItem serializer"},
            {0x7EE6B28, "PingItem serializer"},
            {0x7EE6B2C, "PingItem serializer"},
            {0x7EE6B30, "PingItem serializer"},
        };

        g_dumper.set_namespace_comment(
            "EngineDetections",
            "Hyperion detection flag DWORDs reported through the RBX::PingItem telemetry "
            "serializer. Nonzero/non-initial value = that detection fired. Static RVAs "
            "from static analysis of this build - not empirically scanned.");

        size_t readable = 0;
        for (size_t i = 0; i < flags.size(); i++) {
            const uintptr_t addr = base + flags[i].rva;
            std::string comment = std::string("Detection flag #") + std::to_string(i) +
                                  " - referenced by " + flags[i].note +
                                  "; absolute RVA, build-specific";
            g_dumper.add_offset("EngineDetections", "dwDetectionFlag_" + std::to_string(i),
                                flags[i].rva, comment, FieldType::UInt32);

            if (auto v = process::Memory::read<uint32_t>(addr)) {
                readable++;
                spdlog::info("EngineDetections: flag_{:<2} @ RVA 0x{:X} = 0x{:08X}",
                             i, flags[i].rva, *v);
            }
        }

        g_dumper.set_namespace_comment(
            "AntiCheat",
            "Hyperion integrity machinery. Static RVAs from static analysis of this "
            "build - not empirically scanned.");
        g_dumper.add_offset(
            "AntiCheat", "relControlFlowGuardMap", 0x145BA48,
            "Custom CFG-style map encoded over page boundaries; shift address by 0x13 "
            "bytes then set bit to 0xFF to whitelist code outside allowed segments");
        g_dumper.add_offset(
            "AntiCheat", "relFpControlFlowCheck", 0xC53000,
            "Function carrying out the control flow check against the map above");

        if (readable == 0) {
            spdlog::warn("EngineDetections: no flag memory readable - client build may "
                         "differ from the analyzed one; offsets emitted as-is");
            return false;
        }

        spdlog::info("EngineDetections: {} flags emitted, {}/{} readable", flags.size(),
                     readable, flags.size());
        return true;
    }

} // namespace dumper::stages::engine_detections

REGISTER_STAGE(engine_detections)
