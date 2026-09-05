#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <functional>
#include <spdlog/spdlog.h>
#include <unordered_map>

namespace dumper::stages::fire {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->fires.empty()) {
            spdlog::warn("No fire properties from bridge");
            return false;
        }

        const auto& by_name = dumper::g_dumper.m_workspace_index;

        std::vector<uintptr_t> addrs;
        std::vector<const bridge::FireProperty*> entries;
        for (const auto& f : props->fires) {
            const auto it = by_name.find(f.name);
            if (it == by_name.end())
                continue;
            addrs.push_back(it->second);
            entries.push_back(&f);
        }
        if (addrs.size() < 3) {
            spdlog::warn("Not enough Fire instances found ({})", addrs.size());
            return false;
        }

        const auto path = "DataModel>Workspace>TestPartN>SkidFireN";

        if (auto off = process::helpers::find_offset_with_getter<float>(
                addrs, [&](size_t i) { return entries[i]->size; }, 0x800, 0x4)) {
            g_dumper.add_offset("Fire", "Size", *off, path, FieldType::Float);
        } else {
            spdlog::warn("Fire::Size not found (continuing)");
        }

        if (auto off = process::helpers::find_offset_with_getter<float>(
                addrs, [&](size_t i) { return entries[i]->heat; }, 0x800, 0x4)) {
            g_dumper.add_offset("Fire", "Heat", *off, path, FieldType::Float);
        } else {
            spdlog::warn("Fire::Heat not found (continuing)");
        }

        return true;
    }

} // namespace dumper::stages::fire

REGISTER_STAGE(fire)
