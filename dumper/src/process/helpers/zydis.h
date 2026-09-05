#pragma once
#include "process/memory/memory.h"
#include <Zydis/Zydis.h>

namespace process::helpers::zydis {

    inline auto is_cmp_mem_zero(const ZydisDecodedInstruction& inst, const ZydisDecodedOperand* ops,
                                ZydisRegister base, size_t min_disp = 0) -> bool {
        return inst.mnemonic == ZYDIS_MNEMONIC_CMP && ops[0].type == ZYDIS_OPERAND_TYPE_MEMORY &&
               ops[0].mem.base == base && ops[0].mem.disp.has_displacement &&
               ops[0].mem.disp.value > min_disp && ops[1].type == ZYDIS_OPERAND_TYPE_IMMEDIATE &&
               ops[1].imm.value.u == 0;
    }

    inline auto is_movzx_mem(const ZydisDecodedInstruction& inst, const ZydisDecodedOperand* ops,
                             ZydisRegister base, size_t min_disp = 0) -> bool {
        return inst.mnemonic == ZYDIS_MNEMONIC_MOVZX && ops[1].type == ZYDIS_OPERAND_TYPE_MEMORY &&
               ops[1].mem.base == base && ops[1].mem.disp.has_displacement &&
               ops[1].mem.disp.value > min_disp;
    }

    inline auto is_test_mem_imm(const ZydisDecodedInstruction& inst, const ZydisDecodedOperand* ops,
                                ZydisRegister base, size_t min_disp = 0) -> bool {
        return inst.mnemonic == ZYDIS_MNEMONIC_TEST && ops[0].type == ZYDIS_OPERAND_TYPE_MEMORY &&
               ops[0].mem.base == base && ops[0].mem.disp.has_displacement &&
               ops[0].mem.disp.value > min_disp && ops[1].type == ZYDIS_OPERAND_TYPE_IMMEDIATE;
    }

    inline auto resolve_rip_mov(uintptr_t addr, size_t pre = 0x50, size_t total = 0x300)
        -> std::optional<uintptr_t> {
        auto buffer = process::Memory::read_bytes(addr - pre, total);
        if (buffer.empty())
            return std::nullopt;

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

            if (insn.mnemonic == ZYDIS_MNEMONIC_MOV) {
                for (size_t i = 0; i < insn.operand_count; i++) {
                    auto& op = ops[i];

                    if (op.type == ZYDIS_OPERAND_TYPE_MEMORY && op.mem.base == ZYDIS_REGISTER_RIP) {
                        ZyanU64 absolute = 0;

                        if (ZYAN_SUCCESS(ZydisCalcAbsoluteAddress(&insn, &op, addr - pre + offset,
                                                                  &absolute))) {
                            return static_cast<uintptr_t>(absolute);
                        }
                    }
                }
            }

            offset += insn.length;
        }

        return std::nullopt;
    }

    template <typename Visitor>
    inline auto scan_instructions(uintptr_t start_addr, const std::vector<uint8_t>& buffer,
                                  Visitor&& visitor) -> std::optional<uintptr_t> {
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

            if (visitor(start_addr + offset, insn, ops))
                return start_addr + offset;

            offset += insn.length;
        }
        return std::nullopt;
    }

    inline auto is_mov_mem_imm32(const ZydisDecodedInstruction& insn,
                                 const ZydisDecodedOperand* ops, int64_t disp, uint64_t imm_value)
        -> bool {
        return insn.mnemonic == ZYDIS_MNEMONIC_MOV && ops[0].type == ZYDIS_OPERAND_TYPE_MEMORY &&
               ops[0].mem.disp.has_displacement && ops[0].mem.disp.value == disp &&
               ops[0].element_size == 32 && ops[1].type == ZYDIS_OPERAND_TYPE_IMMEDIATE &&
               ops[1].imm.value.u == imm_value;
    }

    inline auto is_mov_rcx_deref(const ZydisDecodedInstruction& insn,
                                 const ZydisDecodedOperand* ops) -> ZydisRegister {
        if (insn.mnemonic == ZYDIS_MNEMONIC_MOV && ops[0].type == ZYDIS_OPERAND_TYPE_REGISTER &&
            ops[0].reg.value == ZYDIS_REGISTER_RCX && ops[1].type == ZYDIS_OPERAND_TYPE_MEMORY &&
            !ops[1].mem.disp.has_displacement && ops[1].mem.index == ZYDIS_REGISTER_NONE) {
            return ops[1].mem.base;
        }
        return ZYDIS_REGISTER_NONE;
    }

    inline auto resolve_relative_call(const ZydisDecodedInstruction& insn,
                                      const ZydisDecodedOperand* ops, uintptr_t insn_addr)
        -> std::optional<uintptr_t> {
        if (insn.mnemonic == ZYDIS_MNEMONIC_CALL && ops[0].type == ZYDIS_OPERAND_TYPE_IMMEDIATE &&
            ops[0].imm.is_relative) {
            ZyanU64 target = 0;
            if (ZYAN_SUCCESS(ZydisCalcAbsoluteAddress(&insn, &ops[0], insn_addr, &target)))
                return static_cast<uintptr_t>(target);
        }
        return std::nullopt;
    }

} // namespace process::helpers::zydis