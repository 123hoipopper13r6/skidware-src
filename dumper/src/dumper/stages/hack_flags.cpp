#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include <spdlog/spdlog.h>
#include <unordered_set>

namespace dumper::stages::hack_flags {

    auto dump() -> bool {
        const auto dm = dumper::g_data_model_addr;
        if (!dm) {
            spdlog::error("HackFlags: DataModel address not available");
            return false;
        }

        // Walk the DataModel looking for a circular std::list sentinel pattern.
        // MSVC std::list: at offset X we have a pointer to the sentinel node,
        // sentinel->_Next (+0x0) and sentinel->_Prev (+0x8).
        // For a non-empty list: sentinel->_Next != &sentinel.

        size_t list_offset = 0;
        uintptr_t sentinel = 0;

        for (size_t off = 0x100; off < 0xA00; off += 0x8) {
            auto list_ptr = process::Memory::read<uintptr_t>(dm + off);
            if (!list_ptr || *list_ptr < 0x10000 || *list_ptr == dm)
                continue;

            auto s = process::Memory::read<uintptr_t>(*list_ptr);
            if (!s || *s < 0x10000)
                continue;

            auto nxt = process::Memory::read<uintptr_t>(*s);
            auto prv = process::Memory::read<uintptr_t>(*s + 0x8);
            if (!nxt || !prv)
                continue;

            // empty list: both point to sentinel itself
            if (*nxt == *s && *prv == *s)
                continue;

            if (*nxt < 0x10000 || *nxt > 0x7FFFFFFFFFFF)
                continue;

            // walk a few nodes to validate
            size_t count = 0;
            uintptr_t cur = *nxt;
            std::unordered_set<uintptr_t> visited;
            bool valid = true;

            for (size_t i = 0; i < 256 && cur != *s; i++) {
                if (visited.count(cur)) { valid = false; break; }
                visited.insert(cur);
                auto nx = process::Memory::read<uintptr_t>(cur);
                if (!nx) { valid = false; break; }
                count++;
                cur = *nx;
            }

            if (!valid || count < 1 || count > 100)
                continue;

            list_offset = off;
            sentinel = *s;
            spdlog::info("HackFlags: Found hack flag list at DataModel+0x{:X} ({} flags)", off, count);
            break;
        }

        if (list_offset) {
            // The mutex typically sits right before the list in the DMHackFlagSet structure.
            // Common layout: [mutex_ptr] [list_object] or [list_object] [mutex_ptr].
            // Try common relative offsets around the list.
            size_t mutex_offset = 0;
            for (size_t try_off : {list_offset - 0x10, list_offset - 0x8,
                                   list_offset + 0x10, list_offset + 0x18}) {
                auto test = process::Memory::read<uintptr_t>(dm + try_off);
                if (test && *test > 0x10000 && *test != dm) {
                    // Looks like a pointer to a mutex-like object
                    mutex_offset = try_off;
                    break;
                }
            }

            g_dumper.add_offset("DataModel", "HackFlagSetList", list_offset,
                                "Circular std::list sentinel of detection flag nodes. Walk _Next at +0x0.",
                                FieldType::Pointer);

            if (mutex_offset) {
                g_dumper.add_offset("DataModel", "HackFlagSetMutex", mutex_offset,
                                    "DMHackFlagSetMutex, guards the per-DataModel detection flag list.",
                                    FieldType::Pointer);
            }

            g_dumper.add_offset("DataModel", "HackFlagNodeValue", 0x10,
                                "Flag dword inside a detection flag list node.",
                                FieldType::UInt32);
        } else {
            spdlog::warn("HackFlags: Could not locate list dynamically, using known offsets");
            g_dumper.add_offset("DataModel", "HackFlagSetList", 0x590,
                                "Circular std::list sentinel of detection flag nodes. Walk _Next at +0x0.",
                                FieldType::Pointer);
            g_dumper.add_offset("DataModel", "HackFlagSetMutex", 0x580,
                                "DMHackFlagSetMutex, guards the per-DataModel detection flag list.",
                                FieldType::Pointer);
            g_dumper.add_offset("DataModel", "HackFlagNodeValue", 0x10,
                                "Flag dword inside a detection flag list node.",
                                FieldType::UInt32);
        }

        // DataModelType: DWORD at a known offset indicating game/studio state
        // Scan near the hack flag area for a DWORD that's a small value (0-4)
        // typical of DataModelType.
        size_t type_offset = 0;
        for (size_t try_off = 0x900; try_off < 0xA00; try_off += 0x4) {
            auto val = process::Memory::read<uint32_t>(dm + try_off);
            if (val && *val >= 1 && *val <= 4) {
                // Candidate. Check that neighboring values don't all look like this.
                auto prev = process::Memory::read<uint32_t>(dm + try_off - 0x4);
                auto next = process::Memory::read<uint32_t>(dm + try_off + 0x4);
                if (prev && *prev >= 1 && *prev <= 4 && next && *next >= 1 && *next <= 4)
                    continue; // too many small DWORDs in a row, likely not it
                type_offset = try_off;
                break;
            }
        }

        if (type_offset) {
            g_dumper.add_offset("DataModel", "DataModelType", type_offset,
                                "DWORD containing the type of datamodel, related to whether you're in game or not.",
                                FieldType::UInt32);
        } else {
            g_dumper.add_offset("DataModel", "DataModelType", 0x958,
                                "DWORD containing the type of datamodel, related to whether you're in game or not.",
                                FieldType::UInt32);
        }

        return true;
    }

} // namespace dumper::stages::hack_flags

REGISTER_STAGE(hack_flags)
