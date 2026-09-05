#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include "process/helpers/zydis.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include "process/xref/xref.h"
#include <spdlog/spdlog.h>

namespace dumper::stages::raise_property_changed {

    auto dump() -> bool {
        const auto base = process::g_process.get_module_base();

        const auto string_results = process::Memory::scan_string(
            "Attempted unsafe deferred signal invocation - this signal invocation "
            "isn't safe during parallel execution.",
            ".rdata");

        if (string_results.empty()) {
            spdlog::error("RaisePropertyChanged: Failed to find anchor string in .rdata");
            return false;
        }

        const auto xrefs = process::g_xref.scan(string_results.front());
        if (xrefs.empty()) {
            spdlog::error("RaisePropertyChanged: No xrefs to anchor string");
            return false;
        }

        for (const auto& xref : xrefs) {
            // the zydis linear sweep starts from the lowest address, but a misaligned
            // decode can produce a bogus xref below the real one; take the first that
            // actually resolves to a function start
            auto func_start = process::helpers::find_function_start(xref);
            if (!func_start)
                continue;

            dumper::g_dumper.add_offset("Functions", "RaisePropertyChanged",
                                        *func_start - base);
            return true;
        }

        spdlog::error("RaisePropertyChanged: Could not find function start");
        return false;
    }

} // namespace dumper::stages::raise_property_changed

REGISTER_STAGE(raise_property_changed)
