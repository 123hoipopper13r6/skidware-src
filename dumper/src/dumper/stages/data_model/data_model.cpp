#include "data_model.h"
#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/macros.h"
#include "process/helpers/helpers.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include "process/rtti/rtti.h"
#include "spdlog/spdlog.h"
#include <cstring>

namespace dumper::stages::data_model {

    static auto dump_real_data_model() -> bool {
        const auto fake_data_model = process::Memory::read<uintptr_t>(
            g_visual_engine + *dumper::g_dumper.get_offset("VisualEngine", "FakeDataModel"));

        if (!fake_data_model) {
            spdlog::error("Failed to read FakeDataModel pointer.");
            return false;
        }

        // NOTE: child-array heuristics can't validate candidates here (children field
        // offset is itself dynamic per class/build); classic behaviour resolves the
        // correct DM on the real client.
        const auto real_data_model = process::Rtti::find(*fake_data_model, "DataModel@RBX");

        if (!real_data_model) {
            spdlog::error("Failed to get real DataModel.");
            return false;
        }

        const auto data_model =
            process::Memory::read<uintptr_t>(*fake_data_model + *real_data_model);

        if (!data_model) {
            spdlog::error("Failed to get real DataModel.");
            return false;
        }

        dumper::g_dumper.add_offset("FakeDataModel", "RealDataModel", *real_data_model,
                                    "*(*FakeDataModelPtr)", FieldType::Pointer);
        dumper::g_data_model_addr = *data_model;

        // locate the global holding the fake DataModel pointer so external tools
        // can rebuild the attach chain: *(base + Pointer) -> fake -> +RealDataModel
        {
            const auto data_sec = process::g_process.get_section(".data");
            if (data_sec && data_sec->second) {
                auto buf = process::Memory::read_bytes(data_sec->first, data_sec->second);
                const uintptr_t needle = *fake_data_model;
                bool found = false;
                for (size_t off = 0; off + 8 <= buf.size(); off += 8) {
                    uintptr_t v;
                    std::memcpy(&v, buf.data() + off, 8);
                    if (v == needle) {
                        dumper::g_dumper.add_offset(
                            "FakeDataModel", "Pointer",
                            data_sec->first + off - process::g_process.get_module_base(),
                            "global holding the fake DataModel instance - external "
                            "attach chain entry",
                            FieldType::Pointer);
                        found = true;
                        break;
                    }
                }
                if (!found)
                    spdlog::warn("FakeDataModel pointer global not found in .data");
            }
        }

        return true;
    }

    auto dump_ptr() -> bool {
        if (!dump_real_data_model()) {
            return false;
        }

        const auto workspace_offset =
            process::Rtti::find(dumper::g_data_model_addr, "Workspace@RBX");

        if (!workspace_offset) {
            spdlog::error("Failed to get Workspace from DataModel");
            return false;
        }

        dumper::g_dumper.add_offset("DataModel", "Workspace", *workspace_offset,
                                    "DataModel instance > Workspace service child",
                                    FieldType::Pointer);

        return true;
    }

    auto dump() -> bool {
        const auto data = bridge::g_bridge.read_game_information();

        if (!data) {
            spdlog::error("Failed to receive DataModel information via bridge.");
            return false;
        }

        FIND_AND_ADD_OFFSET(dumper::g_data_model_addr, DataModel, int64_t, PlaceId, data->place_id,
                            0x1000, 0x8, FieldType::UInt64);
        FIND_AND_ADD_OFFSET(dumper::g_data_model_addr, DataModel, int64_t, GameId, data->game_id,
                            0x1000, 0x8, FieldType::UInt64);
        FIND_AND_ADD_OFFSET(dumper::g_data_model_addr, DataModel, int64_t, CreatorId,
                            data->creator_id, 0x1000, 0x8, FieldType::UInt64);

        const auto job_id = process::helpers::find_string_offset(dumper::g_data_model_addr,
                                                                 data->job_id, 0x1000, 8);

        if (!job_id) {
            spdlog::error("Failed to get JobId from DataModel");
            return false;
        }

        dumper::g_dumper.add_offset("DataModel", "JobId", *job_id, "", FieldType::Pointer);

        FIND_AND_ADD_OFFSET(dumper::g_data_model_addr, DataModel, uint32_t, GameLoaded, 31, 0x1000,
                            0x4, FieldType::UInt32);

        const auto ip_address = process::helpers::find_string_by_regex(
            dumper::g_data_model_addr, R"(\d+\.\d+\.\d+\|\d+)", 0x800, 0x8);

        if (!ip_address) {
            spdlog::warn("ServerIP not found (singleplayer/Studio play has no remote server?)");
        } else {
            dumper::g_dumper.add_offset("DataModel", "ServerIP", *ip_address,
                                        "DataModel instance, regex <ip>|<port> string",
                                        FieldType::Pointer);
        }

        return true;
    }
} // namespace dumper::stages::data_model
