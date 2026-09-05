#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include "process/helpers/zydis.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include <spdlog/spdlog.h>

namespace dumper::stages::fire_proximity_prompt {

    static auto find_heartbeat() -> std::optional<uintptr_t> {
        auto service = dumper::g_data_model.find_first_child_of_class("ProximityPromptService");
        if (!service || !service->is_valid()) {
            spdlog::error("FireProximityPrompt: ProximityPromptService not found in DataModel");
            return std::nullopt;
        }

        auto text = process::g_process.get_section(".text");
        auto rdata = process::g_process.get_section(".rdata");
        if (!text || !rdata)
            return std::nullopt;

        const uintptr_t addr = service->get_address();

        for (size_t vptr_off = 0; vptr_off < 0x200; vptr_off += 8) {
            auto vptr = process::Memory::read<uintptr_t>(addr + vptr_off);
            if (!vptr || !process::helpers::is_in_section(*vptr, *rdata))
                continue;

            for (size_t slot = 0; slot < 16; slot++) {
                auto func = process::Memory::read<uintptr_t>(*vptr + slot * 8);
                if (!func || !process::helpers::is_in_section(*func, *text))
                    continue;
                if (!process::helpers::function_is_at_least(*func, 0x400))
                    continue;

                auto buf = process::Memory::read_bytes(*func, 0xC00);
                if (buf.empty())
                    continue;

                auto hit = process::helpers::zydis::scan_instructions(
                    *func, buf,
                    [](uintptr_t, const ZydisDecodedInstruction& i, const ZydisDecodedOperand* o) {
                        return process::helpers::zydis::is_mov_mem_imm32(i, o, 0x14, 2);
                    });

                if (hit)
                    return *func;
            }
        }

        spdlog::error("FireProximityPrompt: Heartbeat not found in vtable slots");
        return std::nullopt;
    }

    static auto find_trigger(uintptr_t heartbeat) -> std::optional<uintptr_t> {
        auto buf = process::Memory::read_bytes(heartbeat, 0xC00);
        if (buf.empty())
            return std::nullopt;

        int state = 0;
        ZydisRegister base = ZYDIS_REGISTER_NONE;
        bool want_call = false;
        std::optional<uintptr_t> result;

        process::helpers::zydis::scan_instructions(
            heartbeat, buf,
            [&](uintptr_t ea, const ZydisDecodedInstruction& i, const ZydisDecodedOperand* o) {
                switch (state) {
                    case 0:
                        if (process::helpers::zydis::is_mov_mem_imm32(i, o, 0x14, 2))
                            state = 1;
                        break;

                    case 1:
                        if (auto r = process::helpers::zydis::is_mov_rcx_deref(i, o);
                            r != ZYDIS_REGISTER_NONE) {
                            base = r;
                            want_call = true;
                        } else if (want_call &&
                                   process::helpers::zydis::resolve_relative_call(i, o, ea)) {
                            state = 2;
                            want_call = false;
                        } else {
                            want_call = false;
                        }
                        break;

                    case 2:
                        if (auto r = process::helpers::zydis::is_mov_rcx_deref(i, o); r == base) {
                            want_call = true;
                        } else if (want_call) {
                            if (auto t = process::helpers::zydis::resolve_relative_call(i, o, ea)) {
                                result = t;
                                return true;
                            }
                            want_call = false;
                            state = 1;
                        }
                        break;
                }
                return false;
            });

        if (!result)
            spdlog::error("FireProximityPrompt: trigger() call pattern not found");
        return result;
    }

    auto dump() -> bool {
        const auto base = process::g_process.get_module_base();

        auto heartbeat = find_heartbeat();
        if (!heartbeat)
            return false;

        auto trigger = find_trigger(*heartbeat);
        if (!trigger)
            return false;

        dumper::g_dumper.add_offset("Fire", "FireProximityPrompt", *trigger - base);
        return true;
    }

} // namespace dumper::stages::fire_proximity_prompt

REGISTER_STAGE(fire_proximity_prompt)
