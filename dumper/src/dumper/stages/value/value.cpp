#include "value.h"
#include "dumper/dumper.h"
#include "process/helpers/helpers.h"
#include "process/memory/memory.h"
#include "process/rtti/rtti.h"
#include "roblox/offsets.h"
#include <spdlog/spdlog.h>

namespace dumper::stages::value {
    auto dump() -> bool {
        // RTTI field scan first (robust on Studio multi-datamodel), child iteration fallback
        std::optional<roblox::Instance> replicated_storage;

        const auto rs_off =
            process::Rtti::find(dumper::g_data_model_addr, "ReplicatedStorage@RBX", 0x1000);
        if (rs_off) {
            const auto rs_addr =
                process::Memory::read<uintptr_t>(dumper::g_data_model_addr + *rs_off);
            if (rs_addr && *rs_addr > 0x10000) {
                replicated_storage = roblox::Instance(*rs_addr);
            }
        }

        if (!replicated_storage) {
            replicated_storage = dumper::g_data_model.find_first_child_of_class("ReplicatedStorage");
        }

        if (!replicated_storage) {
            spdlog::error("Failed to find ReplicatedStorage in DataModel");
            return false;
        }

        const auto string_value = replicated_storage->find_first_child("TestValue");

        if (!string_value) {
            spdlog::error("Failed to find 'TestValue' StringValue in ReplicatedStorage");
            return false;
        }

        const auto value_offset = process::helpers::find_sso_string_offset(
            string_value->get_address(), "Test123", 0x100, 0x8, true);

        if (!value_offset) {
            spdlog::error("Failed to find Value offset for StringValue");
            return false;
        }

        dumper::g_dumper.add_offset("Value", "Value", *value_offset);
        roblox::offsets::Value::Value = *value_offset;

        return true;
    }
} // namespace dumper::stages::value
