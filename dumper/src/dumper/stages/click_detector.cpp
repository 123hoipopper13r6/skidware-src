#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <functional>
#include <unordered_map>
#include <spdlog/spdlog.h>

namespace dumper::stages::click_detector {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->click_detectors.empty()) {
            spdlog::warn("No click detector properties from bridge");
            return false;
        }

        const auto& by_name = dumper::g_dumper.m_workspace_index;

        std::vector<uintptr_t> addrs;
        for (const auto& c : props->click_detectors) {
            const auto it = by_name.find(c.name);
            if (it != by_name.end())
                addrs.push_back(it->second);
        }

        if (addrs.size() < 3) {
            spdlog::warn("Not enough ClickDetector instances found ({})", addrs.size());
            return false;
        }

        const auto offset = process::helpers::find_offset_with_getter<float>(
            addrs, [&](size_t i) { return (*props).click_detectors[i].max_activation_distance; },
            0x800, 0x4);

        if (!offset) {
            spdlog::warn("ClickDetector::MaxActivationDistance not found");
            return false;
        }

        g_dumper.add_offset("ClickDetector", "MaxActivationDistance", *offset,
                            "DataModel>Workspace>TestPartN>SkidClickN", FieldType::Float);
        return true;
    }

} // namespace dumper::stages::click_detector

REGISTER_STAGE(click_detector)
