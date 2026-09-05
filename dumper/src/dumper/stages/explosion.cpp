#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <functional>
#include <spdlog/spdlog.h>
#include <unordered_map>

namespace dumper::stages::explosion {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->explosions.empty()) {
            spdlog::warn("No explosion properties from bridge");
            return false;
        }

        std::unordered_map<std::string, uintptr_t> by_name;
        // explosions live in ReplicatedStorage (client destroys Workspace ones after
        // detonation), so walk both roots
        std::function<void(const roblox::Instance&, int)> walk = [&](const roblox::Instance& inst, int depth) {
            if (depth > 24)
                return; // guard against cyclic/corrupted child links
            by_name.emplace(inst.get_name().value_or(""), inst.get_address());
            for (const auto& c : inst.get_children())
                walk(c, depth + 1);
        };
        walk(*dumper::g_workspace, 0);
        if (auto rs = dumper::g_data_model.find_first_child_of_class("ReplicatedStorage")) {
            walk(*rs, 0);
        }

        std::vector<uintptr_t> addrs;
        std::vector<const bridge::ExplosionProperty*> entries;
        for (const auto& e : props->explosions) {
            const auto it = by_name.find(e.name);
            if (it == by_name.end())
                continue;
            addrs.push_back(it->second);
            entries.push_back(&e);
        }
        if (addrs.size() < 3) {
            spdlog::warn("Not enough Explosion instances found ({})", addrs.size());
            return false;
        }

        const auto path = "DataModel>Workspace>SkidExplosionN";

        if (auto off = process::helpers::find_offset_with_getter<float>(
                addrs, [&](size_t i) { return entries[i]->blast_radius; }, 0x800, 0x4)) {
            g_dumper.add_offset("Explosion", "BlastRadius", *off, path, FieldType::Float);
        } else {
            spdlog::warn("Explosion::BlastRadius not found (continuing)");
        }

        if (auto off = process::helpers::find_offset_with_getter<float>(
                addrs, [&](size_t i) { return entries[i]->blast_pressure; }, 0x800, 0x4)) {
            g_dumper.add_offset("Explosion", "BlastPressure", *off, path,
                                FieldType::Float);
        } else {
            spdlog::warn("Explosion::BlastPressure not found (continuing)");
        }

        return true;
    }

} // namespace dumper::stages::explosion

REGISTER_STAGE(explosion)
