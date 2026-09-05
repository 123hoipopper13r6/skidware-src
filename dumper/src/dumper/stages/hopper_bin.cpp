#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include "process/memory/memory.h"
#include <spdlog/spdlog.h>

namespace dumper::stages::hopper_bin {

    auto dump() -> bool {
        auto folder = dumper::g_workspace->find_first_child("HopperBins");
        if (!folder || !folder->is_valid()) {
            spdlog::error("HopperBin: 'HopperBins' folder not found in Workspace");
            return false;
        }

        auto clone_bin = folder->find_first_child("CloneBin");
        auto hammer_bin = folder->find_first_child("HammerBin");
        auto grab_bin = folder->find_first_child("GrabBin");
        if (!clone_bin || !hammer_bin || !grab_bin) {
            spdlog::error("HopperBin: test bins not found");
            return false;
        }

        for (size_t off = 0x100; off < 0x600; off += 0x4) {
            auto v1 = process::Memory::read<uint32_t>(clone_bin->get_address() + off);
            auto v2 = process::Memory::read<uint32_t>(hammer_bin->get_address() + off);
            auto v3 = process::Memory::read<uint32_t>(grab_bin->get_address() + off);

            if (v1 && v2 && v3 && *v1 == 3 && *v2 == 4 && *v3 == 2) {
                dumper::g_dumper.add_offset("HopperBin", "BinType", off, "", FieldType::UInt32);
                return true;
            }
        }

        spdlog::error("HopperBin: Failed to find BinType offset");
        return false;
    }

} // namespace dumper::stages::hopper_bin

REGISTER_STAGE(hopper_bin)
