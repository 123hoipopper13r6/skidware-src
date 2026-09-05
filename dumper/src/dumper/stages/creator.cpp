#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include <algorithm>
#include <cstring>
#include <spdlog/spdlog.h>

namespace dumper::stages::creator {

    static constexpr size_t kBucketSize = 0x10;
    static constexpr size_t kMinBuckets = 16;
    static constexpr size_t kMaxBuckets = 8192;

    static auto is_valid_creator_table(uintptr_t table_start, uintptr_t table_end) -> bool {
        if (table_end <= table_start)
            return false;

        const size_t diff = table_end - table_start;
        const size_t capacity = diff / kBucketSize;

        if (diff % kBucketSize != 0 || capacity < kMinBuckets || capacity > kMaxBuckets)
            return false;

        const auto buf = process::Memory::read_bytes(table_start, diff);
        if (buf.empty())
            return false;

        bool has_part = false;
        bool has_string_value = false;

        for (size_t i = 0; i < capacity; ++i) {
            uintptr_t key = 0;
            std::memcpy(&key, buf.data() + i * kBucketSize, sizeof(uintptr_t));
            if (!key)
                continue;

            const auto name = process::Memory::read_string(key);
            if (!name || name->empty() || name->size() > 64)
                continue;

            if (*name == "Part")
                has_part = true;
            else if (*name == "StringValue")
                has_string_value = true;

            if (has_part && has_string_value)
                return true;
        }

        return false;
    }

    static auto dump_creator_offset(uintptr_t table_start, uintptr_t table_end, uintptr_t base)
        -> void {
        const size_t capacity = (table_end - table_start) / kBucketSize;
        const uintptr_t code_end = base + 0x10000000;

        uintptr_t part_desc = 0;
        uintptr_t sv_desc = 0;

        for (size_t i = 0; i < capacity; ++i) {
            auto k = process::Memory::read<uintptr_t>(table_start + i * kBucketSize);
            auto v = process::Memory::read<uintptr_t>(table_start + i * kBucketSize + 8);
            if (!k || !*k || !v || !*v || *v < 0x10000)
                continue;
            auto name = process::Memory::read_string(*k);
            if (!name)
                continue;
            if (*name == "Part")
                part_desc = *v;
            else if (*name == "StringValue")
                sv_desc = *v;
            if (part_desc && sv_desc)
                break;
        }

        if (!part_desc || !sv_desc) {
            spdlog::error("Creator: Failed to find Part/StringValue in map");
            return;
        }

        auto own_vtable = process::Memory::read<uintptr_t>(part_desc);
        if (!own_vtable)
            return;

        for (size_t off = 0x8; off < 0x500; off += 0x8) {
            auto p1 = process::Memory::read<uintptr_t>(part_desc + off);
            auto p2 = process::Memory::read<uintptr_t>(sv_desc + off);
            if (!p1 || !p2)
                continue;
            if (*p1 < base || *p1 >= code_end)
                continue;
            if (*p2 < base || *p2 >= code_end)
                continue;
            if (*p1 == *own_vtable)
                continue;
            if (*p1 == *p2)
                continue;

            auto v1 = process::Memory::read<uintptr_t>(*p1);
            if (!v1 || *v1 < base || *v1 >= code_end)
                continue;

            int count = 0;
            for (int j = 0; j < 25; j++) {
                auto e = process::Memory::read<uintptr_t>(*p1 + j * 8);
                if (e && *e >= base && *e < code_end)
                    count++;
                else
                    break;
            }
            if (count < 5)
                continue;

            dumper::g_dumper.add_offset("ClassDescriptor", "Creator", off,
                                        "ICreator vtable, [0] = create fn", FieldType::Pointer);

            dumper::g_dumper.add_offset("ICreator", "Create", 0x0);
            return;
        }

        spdlog::error("Creator: Failed to find Creator vtable offset in ClassDescriptor");
    }

    auto dump() -> bool {
        const uintptr_t base = process::g_process.get_module_base();
        if (!base) {
            spdlog::error("Creator: Failed to get module base");
            return false;
        }

        const auto data_section = process::g_process.get_section(".data");
        if (!data_section) {
            spdlog::error("Creator: Failed to find .data section");
            return false;
        }

        const uintptr_t section_base = data_section->first;
        const size_t section_size = data_section->second;
        const uintptr_t module_end = base + 0x10000000;
        const uintptr_t scan_end = section_base + section_size - sizeof(uintptr_t) * 2;

        constexpr size_t kChunk = 0x100000;
        constexpr size_t kStride = 0x8;

        for (uintptr_t addr = section_base; addr < scan_end; addr += kChunk) {
            const size_t to_read = (std::min)(kChunk, static_cast<size_t>(scan_end - addr));
            const auto buf = process::Memory::read_bytes(addr, to_read);
            if (buf.empty())
                continue;

            for (size_t off = 0; off + sizeof(uintptr_t) * 2 <= to_read; off += kStride) {
                uintptr_t ts = 0;
                uintptr_t te = 0;
                std::memcpy(&ts, buf.data() + off, sizeof(uintptr_t));
                std::memcpy(&te, buf.data() + off + sizeof(uintptr_t), sizeof(uintptr_t));

                if (!ts || (ts >= base && ts < module_end))
                    continue;
                if (!te || (te >= base && te < module_end))
                    continue;

                if (!is_valid_creator_table(ts, te))
                    continue;

                dumper::g_dumper.add_offset("Creator", "MapStart", (addr + off) - base);
                dumper::g_dumper.add_offset("Creator", "MapEnd", (addr + off + 0x8) - base);
                dump_creator_offset(ts, te, base);
                return true;
            }
        }

        spdlog::error("Creator: Failed to find Creator map");
        return false;
    }

} // namespace dumper::stages::creator

REGISTER_STAGE(creator)
