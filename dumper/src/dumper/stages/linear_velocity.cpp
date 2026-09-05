#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>
#include <functional>
#include <unordered_map>

namespace dumper::stages::linear_velocity {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->linear_velocities.empty()) {
            spdlog::warn("No linear velocity properties from bridge");
            return false;
        }

        const auto& by_name = dumper::g_dumper.m_workspace_index;

        std::vector<uintptr_t> addrs;
        std::vector<const bridge::LinearVelocityProperty*> entries;
        for (const auto& l : props->linear_velocities) {
            const auto it = by_name.find(l.name);
            if (it == by_name.end())
                continue;
            addrs.push_back(it->second);
            entries.push_back(&l);
        }
        if (addrs.size() < 3) {
            spdlog::warn("Not enough LinearVelocity instances found ({})", addrs.size());
            return false;
        }

        const auto path = "DataModel>Workspace>SkidLinVelN";

        if (auto off = process::helpers::find_offset_with_getter<float>(
                addrs, [&](size_t i) { return entries[i]->max_force; }, 0x800, 0x4)) {
            g_dumper.add_offset("LinearVelocity", "MaxForce", *off, path, FieldType::Float);
        } else {
            spdlog::warn("LinearVelocity::MaxForce not found (continuing)");
        }

        if (auto off = process::helpers::find_vec3_offset_multi<glm::vec3>(
                addrs,
                [&](size_t i) {
                    const auto& l = *entries[i];
                    return glm::vec3(l.vel_x, l.vel_y, l.vel_z);
                },
                0x800, 0.01f)) {
            g_dumper.add_offset("LinearVelocity", "VectorVelocity", *off, path,
                                FieldType::Vector3);
        } else {
            spdlog::warn("LinearVelocity::VectorVelocity not found (continuing)");
        }

        return true;
    }

} // namespace dumper::stages::linear_velocity

REGISTER_STAGE(linear_velocity)
