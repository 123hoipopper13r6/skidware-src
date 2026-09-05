#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <functional>
#include <spdlog/spdlog.h>
#include <unordered_map>

namespace dumper::stages::lights {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->lights.empty()) {
            spdlog::warn("No light properties from bridge");
            return false;
        }

        const auto& by_name = dumper::g_dumper.m_workspace_index;

        std::vector<uintptr_t> addrs;
        std::vector<const bridge::LightProperty*> entries;
        for (const auto& l : props->lights) {
            const auto it = by_name.find(l.name);
            if (it == by_name.end())
                continue;
            addrs.push_back(it->second);
            entries.push_back(&l);
        }
        if (addrs.size() < 3) {
            spdlog::warn("Not enough Light instances found ({})", addrs.size());
            return false;
        }

        const auto path = "DataModel>Workspace>TestPartN>SkidLightN";

        if (auto off = process::helpers::find_offset_with_getter<float>(
                addrs, [&](size_t i) { return entries[i]->brightness; }, 0x800, 0x4)) {
            g_dumper.add_offset("Light", "Brightness", *off, path, FieldType::Float);
        } else {
            spdlog::warn("Light::Brightness not found (continuing)");
        }

        if (auto off = process::helpers::find_offset_with_getter<int32_t>(
                addrs, [&](size_t i) { return entries[i]->range; }, 0x800, 0x4)) {
            g_dumper.add_offset("Light", "Range", *off, path, FieldType::Int32);
        } else if (auto off_f = process::helpers::find_offset_with_getter<float>(
                       addrs,
                       [&](size_t i) { return static_cast<float>(entries[i]->range); },
                       0x800, 0x4)) {
            g_dumper.add_offset("Light", "Range", *off_f, path, FieldType::Float);
        } else {
            spdlog::warn("Light::Range not found (continuing)");
        }

        // Angle only exists on SpotLight
        std::vector<uintptr_t> spot_addrs;
        std::vector<const bridge::LightProperty*> spot_entries;
        for (size_t i = 0; i < entries.size(); i++) {
            if (entries[i]->class_name == "SpotLight") {
                spot_addrs.push_back(addrs[i]);
                spot_entries.push_back(entries[i]);
            }
        }
        if (spot_addrs.size() >= 2) {
            if (auto off = process::helpers::find_offset_with_getter<float>(
                    spot_addrs, [&](size_t i) { return spot_entries[i]->angle; }, 0x800,
                    0x4)) {
                g_dumper.add_offset("SpotLight", "Angle", *off, path, FieldType::Float);
            }
        }

        return true;
    }

} // namespace dumper::stages::lights

REGISTER_STAGE(lights)
