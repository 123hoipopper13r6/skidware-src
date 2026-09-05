#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <functional>
#include <spdlog/spdlog.h>
#include <unordered_map>

namespace dumper::stages::spawn_location {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->spawn_locations.empty()) {
            spdlog::warn("No spawn location properties from bridge");
            return false;
        }

        const auto& by_name = dumper::g_dumper.m_workspace_index;

        std::vector<uintptr_t> addrs;
        std::vector<const bridge::SpawnLocationProperty*> entries;
        for (const auto& s : props->spawn_locations) {
            const auto it = by_name.find(s.name);
            if (it == by_name.end())
                continue;
            addrs.push_back(it->second);
            entries.push_back(&s);
        }
        if (addrs.empty()) {
            spdlog::warn("SpawnLocation instance not found");
            return false;
        }

        const auto path = "DataModel>Workspace>SkidSpawn";

        if (auto off = process::helpers::find_offset_with_getter<float>(
                addrs, [&](size_t i) { return entries[i]->duration; }, 0x800, 0x4)) {
            g_dumper.add_offset("SpawnLocation", "Duration", *off, path, FieldType::Float);
        } else {
            spdlog::warn("SpawnLocation::Duration not found (continuing)");
        }

        if (auto off = process::helpers::find_offset_with_getter<uint8_t>(
                addrs, [&](size_t i) { return entries[i]->neutral ? 1 : 0; }, 0x800, 0x1)) {
            g_dumper.add_offset("SpawnLocation", "Neutral", *off, path, FieldType::Bool);
        } else {
            spdlog::warn("SpawnLocation::Neutral not found (continuing)");
        }

        return true;
    }

} // namespace dumper::stages::spawn_location

REGISTER_STAGE(spawn_location)
