#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include "process/helpers/zydis.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include "process/xref/xref.h"
#include <spdlog/spdlog.h>

namespace dumper::stages::set_parent {

    auto dump() -> bool {
        const auto base = process::g_process.get_module_base();

        const auto string_results =
            process::Memory::scan_string("Attempt to set {} as its own parent", ".rdata");

        if (string_results.empty()) {
            spdlog::error("SetParent: Failed to find string in .rdata");
            return false;
        }

        uintptr_t validation_func = 0;
        for (const auto& str_addr : string_results) {
            const auto xrefs = process::g_xref.scan(str_addr);
            for (const auto& xref : xrefs) {
                auto func_start = process::helpers::find_function_start(xref);
                if (func_start) {
                    validation_func = *func_start;
                    break;
                }
            }
            if (validation_func)
                break;
        }

        if (!validation_func) {
            spdlog::error("SetParent: Failed to locate validation helper");
            return false;
        }

        const auto caller_xrefs = process::g_xref.scan(validation_func);
        if (caller_xrefs.empty()) {
            spdlog::error("SetParent: No callers to validation helper");
            return false;
        }

        uintptr_t set_parent_internal = 0;
        for (const auto& caller_xref : caller_xrefs) {
            auto func_start = process::helpers::find_function_start(caller_xref);
            if (func_start) {
                set_parent_internal = *func_start;
                break;
            }
        }

        if (!set_parent_internal) {
            spdlog::error("SetParent: Failed to resolve SetParentInternal");
            return false;
        }

        dumper::g_dumper.add_offset("Functions", "SetParentInternal", set_parent_internal - base);

        const auto internal_xrefs = process::g_xref.scan(set_parent_internal);
        if (internal_xrefs.empty()) {
            spdlog::error("SetParent: No callers to SetParentInternal");
            return false;
        }

        auto set_parent = process::helpers::find_function_start(internal_xrefs[0]);
        if (!set_parent) {
            spdlog::error("SetParent: Failed to resolve SetParent");
            return false;
        }

        dumper::g_dumper.add_offset("Functions", "SetParent", *set_parent - base);
        return true;
    }

} // namespace dumper::stages::set_parent

REGISTER_STAGE(set_parent)
