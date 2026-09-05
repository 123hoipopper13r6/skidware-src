#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include "process/xref/xref.h"
#include <Zydis/Zydis.h>
#include <spdlog/spdlog.h>

namespace dumper::stages::print {

    auto dump() -> bool {
        const auto base = process::g_process.get_module_base();

        const auto string_results = process::Memory::scan_string(
            "SetRoll can only be used on Camera objects with a CameraType of Scriptable", ".rdata");

        if (string_results.empty()) {
            spdlog::error("Print: Failed to find anchor string");
            return false;
        }

        const auto xrefs = process::g_xref.scan(string_results.front());
        if (xrefs.empty()) {
            spdlog::error("Print: No xrefs to anchor string");
            return false;
        }

        for (const auto& xref : xrefs) {
            auto buffer = process::Memory::read_bytes(xref, 0x40);
            if (buffer.empty())
                continue;

            ZydisDecoder decoder;
            ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64);

            size_t offset = 0;
            while (offset < buffer.size()) {
                ZydisDecodedInstruction insn;
                ZydisDecodedOperand ops[ZYDIS_MAX_OPERAND_COUNT];

                if (!ZYAN_SUCCESS(ZydisDecoderDecodeFull(&decoder, buffer.data() + offset,
                                                         buffer.size() - offset, &insn, ops))) {
                    offset++;
                    continue;
                }

                if (insn.mnemonic == ZYDIS_MNEMONIC_CALL &&
                    ops[0].type == ZYDIS_OPERAND_TYPE_IMMEDIATE && ops[0].imm.is_relative) {
                    ZyanU64 target = 0;
                    if (ZYAN_SUCCESS(
                            ZydisCalcAbsoluteAddress(&insn, &ops[0], xref + offset, &target))) {
                        dumper::g_dumper.add_offset("Functions", "Print", target - base);
                        return true;
                    }
                }

                offset += insn.length;
            }
        }

        spdlog::error("Print: Failed to find CALL to print from xref");
        return false;
    }

} // namespace dumper::stages::print

REGISTER_STAGE(print)
