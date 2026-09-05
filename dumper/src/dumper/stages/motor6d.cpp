#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>
#include <functional>
#include <unordered_map>
#include <spdlog/spdlog.h>

namespace dumper::stages::motor6d {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->motors.empty()) {
            spdlog::warn("No motor properties from bridge");
            return false;
        }

        const auto& by_name = dumper::g_dumper.m_workspace_index;

        std::vector<uintptr_t> addrs;
        for (const auto& m : props->motors) {
            const auto it = by_name.find(m.name);
            if (it != by_name.end())
                addrs.push_back(it->second);
        }

        if (addrs.size() < 3) {
            spdlog::warn("Not enough Motor6D instances found ({})", addrs.size());
            return false;
        }

        const auto c0_getter = [&](size_t i) {
            const auto& m = (*props).motors[i];
            return glm::vec3(m.c0_x, m.c0_y, m.c0_z);
        };

        // try inline first, then pointer-chase (CFrame may live in a sub-structure)
        auto c0 = process::helpers::find_vec3_offset_multi<glm::vec3>(addrs, c0_getter,
                                                                      0x800, 0.01f);
        std::optional<size_t> container_off;

        if (!c0) {
            for (size_t p = 0; p < 0x800 && !c0; p += 8) {
                std::vector<uintptr_t> bases;
                bool pointers_ok = true;
                for (size_t i = 0; i < addrs.size(); i++) {
                    const auto b = process::Memory::read<uintptr_t>(addrs[i] + p);
                    if (!b || *b < 0x10000) {
                        pointers_ok = false;
                        break;
                    }
                    bases.push_back(*b);
                }
                if (!pointers_ok)
                    continue;

                auto inner = process::helpers::find_vec3_offset_multi<glm::vec3>(
                    bases, c0_getter, 0x400, 0.01f);
                if (inner) {
                    container_off = p;
                    c0 = inner;
                }
            }

            if (!c0) {
                spdlog::warn("Motor6D::C0 not found");
                return false;
            }

            g_dumper.add_offset("Motor6D", "C0Container", *container_off,
                                "DataModel>Workspace>TestPartN>SkidMotorN",
                                FieldType::Pointer);
            g_dumper.add_offset("Motor6D", "C0", *c0,
                                "Motor6D>C0Container", FieldType::Vector3);
            g_dumper.add_offset("Motor6D", "C1", *c0 + 48, "CFrame stride from C0",
                                FieldType::Vector3);
            return true;
        }

        g_dumper.add_offset("Motor6D", "C0", *c0, "DataModel>Workspace>TestPartN>SkidMotorN",
                            FieldType::Vector3);
        g_dumper.add_offset("Motor6D", "C1", *c0 + 48, "CFrame stride from C0",
                            FieldType::Vector3);
        return true;
    }

} // namespace dumper::stages::motor6d

REGISTER_STAGE(motor6d)
