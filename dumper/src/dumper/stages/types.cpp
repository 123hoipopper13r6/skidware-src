#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include <cstring>
#include <spdlog/spdlog.h>
#include <unordered_map>

namespace dumper::stages::types {

    auto dump() -> bool {
        const uintptr_t base = process::g_process.get_module_base();
        if (!base)
            return false;

        const auto data_section = process::g_process.get_section(".data");
        if (!data_section)
            return false;

        const uintptr_t section_base = data_section->first;
        const size_t section_size = data_section->second;
        const uintptr_t module_end = base + 0x10000000;

        constexpr size_t kChunk = 0x100000;

        for (uintptr_t addr = section_base; addr < section_base + section_size - 16;
             addr += kChunk) {
            const size_t to_read = (std::min)(kChunk, section_base + section_size - addr);
            const auto buf = process::Memory::read_bytes(addr, to_read);
            if (buf.empty())
                continue;

            for (size_t off = 0; off + 16 <= to_read; off += 0x8) {
                uintptr_t begin_ptr = 0, end_ptr = 0;
                std::memcpy(&begin_ptr, buf.data() + off, 8);
                std::memcpy(&end_ptr, buf.data() + off + 8, 8);

                if (!begin_ptr || !end_ptr || end_ptr <= begin_ptr)
                    continue;
                if (begin_ptr < 0x10000)
                    continue;
                if (begin_ptr >= base && begin_ptr < module_end)
                    continue;

                size_t count = (end_ptr - begin_ptr) / 8;
                if (count < 100 || count > 1000)
                    continue;

                auto first_type = process::Memory::read<uintptr_t>(begin_ptr);
                if (!first_type || !*first_type)
                    continue;

                auto name_ptr = process::Memory::read<uintptr_t>(*first_type + 0x8);
                if (!name_ptr || !*name_ptr)
                    continue;

                auto name = process::Memory::read_sso_string(*name_ptr);
                if (!name || *name != "Instance")
                    continue;

                auto second_type = process::Memory::read<uintptr_t>(begin_ptr + 8);
                if (!second_type || !*second_type)
                    continue;

                auto name_ptr2 = process::Memory::read<uintptr_t>(*second_type + 0x8);
                if (!name_ptr2 || !*name_ptr2)
                    continue;

                auto name2 = process::Memory::read_sso_string(*name_ptr2);
                if (!name2 || *name2 != "null")
                    continue;

                dumper::g_dumper.add_offset("Types", "AllTypes", (addr + off) - base);

                std::unordered_map<int, std::string> seen_types;
                std::unordered_map<int, int> seen_counts;

                for (size_t i = 0; i < count; i++) {
                    auto type_ptr = process::Memory::read<uintptr_t>(begin_ptr + i * 8);
                    if (!type_ptr || !*type_ptr)
                        continue;

                    auto type_name_ptr = process::Memory::read<uintptr_t>(*type_ptr + 0x8);
                    if (!type_name_ptr || !*type_name_ptr)
                        continue;

                    auto type_name = process::Memory::read_sso_string(*type_name_ptr);
                    if (!type_name || type_name->empty())
                        continue;

                    std::string capitalized = *type_name;
                    if (!capitalized.empty() && capitalized[0] >= 'a' && capitalized[0] <= 'z')
                        capitalized[0] -= 32;

                    auto reflection_type_id = process::Memory::read<uint32_t>(*type_ptr + 0x30);
                    if (!reflection_type_id)
                        continue;

                    int id = static_cast<int>(*reflection_type_id);
                    if (seen_types.find(id) == seen_types.end()) {
                        seen_types[id] = capitalized;
                    }
                    seen_counts[id]++;
                }

                for (auto& [id, name] : seen_types) {
                    if (seen_counts[id] > 10) {
                        if (id == 0x21)
                            name = "Enum";
                        else
                            name = "RefType";
                    }
                }

                for (const auto& [id, name] : seen_types) {
                    dumper::g_dumper.add_enum("ReflectionType", name, id);
                }

                spdlog::info("Types: Dumped {} ReflectionType entries", count);
                return true;
            }
        }

        spdlog::error("Types: Failed to find AllTypes vector");
        return false;
    }

} // namespace dumper::stages::types

REGISTER_STAGE(types)
