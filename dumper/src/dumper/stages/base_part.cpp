#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/macros.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include "process/memory/memory.h"
#include "process/rtti/rtti.h"
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>

namespace dumper::stages::base_part {

    struct PartData {
        std::string name;
        uintptr_t address;
        uintptr_t primitive_address;
        bridge::PartProperty props;
    };

    static auto get_part_data(const bridge::PartPropertiesInfo& props, size_t primitive_offset)
        -> std::optional<std::vector<PartData>> {
        std::vector<PartData> part_data;

        for (const auto& prop : props.parts) {
            const auto part = dumper::g_workspace->find_first_child(prop.name);
            if (!part->is_valid()) {
                spdlog::error("Failed to find part: {}", prop.name);
                return std::nullopt;
            }

            auto primitive_ptr =
                process::Memory::read<uintptr_t>(part->get_address() + primitive_offset);

            if (!primitive_ptr) {
                spdlog::error("Failed to read Primitive pointer for {}", prop.name);
                return std::nullopt;
            }

            PartData data{.name = prop.name,
                          .address = part->get_address(),
                          .primitive_address = *primitive_ptr,
                          .props = prop};

            part_data.push_back(data);
        }

        return part_data;
    }

    static auto find_primitive_offset() -> std::optional<size_t> {
        auto initial_props = bridge::g_bridge.read_parts_information();
        if (!initial_props || initial_props->parts.empty()) {
            spdlog::error("Failed to get part properties from bridge");
            return std::nullopt;
        }

        auto first_part = dumper::g_workspace->find_first_child(initial_props->parts[0].name);
        if (!first_part->is_valid()) {
            spdlog::error("Failed to find part: {}", initial_props->parts[0].name);
            return std::nullopt;
        }

        const auto primitive_offset =
            process::Rtti::find(first_part->get_address(), "Primitive@RBX");

        if (!primitive_offset) {
            spdlog::error("Failed to find Primitive offset in BasePart");
            return std::nullopt;
        }

        return primitive_offset;
    }

    static auto find_flags_offset(const std::vector<uintptr_t>& addrs,
                                  const std::vector<bridge::PartProperty>& props)
        -> std::optional<size_t> {
        for (size_t offset = 0; offset < 0x300; offset += 0x1) {
            bool all_match = true;
            bool found_variation = false;

            std::vector<uint8_t> flag_values;

            for (size_t i = 0; i < addrs.size(); i++) {
                auto flags = process::Memory::read<uint8_t>(addrs[i] + offset);

                if (!flags) {
                    all_match = false;
                    break;
                }

                flag_values.push_back(*flags);

                bool is_anchored = (*flags & 0x2) != 0;
                bool is_can_collide = (*flags & 0x8) != 0;
                bool is_can_touch = (*flags & 0x10) != 0;

                if (is_anchored != props[i].anchored || is_can_collide != props[i].can_collide ||
                    is_can_touch != props[i].can_touch) {
                    all_match = false;
                    break;
                }
            }

            if (!all_match) {
                continue;
            }

            for (size_t i = 1; i < flag_values.size(); i++) {
                if (flag_values[i] != flag_values[0]) {
                    found_variation = true;
                    break;
                }
            }

            if (all_match && found_variation) {
                return offset;
            }
        }

        return std::nullopt;
    }

    auto dump() -> bool {
        const auto primitive_offset = find_primitive_offset();
        if (!primitive_offset) {
            return false;
        }
        dumper::g_dumper.add_offset("BasePart", "Primitive", *primitive_offset, "",
                                    FieldType::Pointer);

        const auto part_props = bridge::g_bridge.read_parts_information();
        if (!part_props) {
            spdlog::error("Failed to get part properties from bridge");
            return false;
        }

        if (part_props->parts.size() < 3) {
            spdlog::error("Not enough parts found (need at least 3)");
            return false;
        }

        const auto parts = get_part_data(*part_props, *primitive_offset);
        if (!parts) {
            return false;
        }

        std::vector<uintptr_t> part_addrs, primitive_addrs;
        std::vector<bridge::PartProperty> props_vec;
        for (const auto& p : *parts) {
            part_addrs.push_back(p.address);
            primitive_addrs.push_back(p.primitive_address);
            props_vec.push_back(p.props);
        }

        const auto flags_offset = find_flags_offset(primitive_addrs, props_vec);
        if (!flags_offset) {
            spdlog::error("Failed to find PrimitiveFlags offset");
            return false;
        }
        dumper::g_dumper.add_offset("Primitive", "PrimitiveFlags", *flags_offset, "",
                                    FieldType::UInt8);

        // part-relative flags byte: prefer a direct match on the part, else via the Primitive
        auto part_flags_offset = find_flags_offset(part_addrs, props_vec);
        if (!part_flags_offset)
            part_flags_offset = *primitive_offset + *flags_offset;
        dumper::g_dumper.add_offset("BasePart", "PrimitiveFlags", *part_flags_offset, "",
                                    FieldType::UInt8);
        dumper::g_dumper.add_offset("PrimitiveFlags", "Anchored", 0x2);
        dumper::g_dumper.add_offset("PrimitiveFlags", "CanCollide", 0x8);
        dumper::g_dumper.add_offset("PrimitiveFlags", "CanTouch", 0x10);
        dumper::g_dumper.add_offset("PrimitiveFlags", "CanQuery", 0x20);

        const auto position_offset =
            process::helpers::find_vec3_offset_multi<glm::vec3>(primitive_addrs, [&](size_t i) {
                const auto& p = (*parts)[i].props;
                return glm::vec3(p.pos_x, p.pos_y, p.pos_z);
            });
        if (!position_offset) {
            spdlog::error("Failed to find Position offset");
            return false;
        }
        dumper::g_dumper.add_offset("Primitive", "Position", *position_offset);

        const auto cframe_offset = *position_offset - 36;
        dumper::g_dumper.add_offset("Primitive", "CFrame", cframe_offset, "", FieldType::CFrame);
        dumper::g_dumper.add_offset("Primitive", "Rotation", cframe_offset);
        dumper::g_dumper.add_offset("Primitive", "Orientation", cframe_offset);

        const auto size_offset =
            process::helpers::find_vec3_offset_multi<glm::vec3>(primitive_addrs, [&](size_t i) {
                const auto& p = (*parts)[i].props;
                return glm::vec3(p.size_x, p.size_y, p.size_z);
            });
        if (!size_offset) {
            spdlog::error("Failed to find Size offset");
            return false;
        }
        dumper::g_dumper.add_offset("Primitive", "Size", *size_offset, "", FieldType::Vector3);

        const auto material_offset = process::helpers::find_offset_with_getter<uint16_t>(
            primitive_addrs, [&](size_t i) { return (*parts)[i].props.material; }, 0x600, 0x2);
        if (!material_offset) {
            spdlog::error("Failed to find Material offset");
            return false;
        }
        dumper::g_dumper.add_offset("Primitive", "Material", *material_offset, "",
                                    FieldType::UInt16);

        const auto color_offset = process::helpers::find_color3_offset(part_addrs, [&](size_t i) {
            const auto& p = (*parts)[i].props;
            return std::make_tuple(p.color_r, p.color_g, p.color_b);
        });
        if (!color_offset) {
            spdlog::error("Failed to find Color3 offset");
            return false;
        }
        dumper::g_dumper.add_offset("BasePart", "Color3", *color_offset, "",
                                    FieldType::Color3Float);

        const auto transparency_offset = process::helpers::find_offset_with_getter<float>(
            part_addrs, [&](size_t i) { return (*parts)[i].props.transparency; }, 0x300, 0x4);
        if (!transparency_offset) {
            spdlog::error("Failed to find Transparency offset");
            return false;
        }
        dumper::g_dumper.add_offset("BasePart", "Transparency", *transparency_offset, "",
                                    FieldType::Float);

        const auto reflectance_offset = process::helpers::find_offset_with_getter<float>(
            part_addrs, [&](size_t i) { return (*parts)[i].props.reflectance; }, 0x300, 0x4);
        if (!reflectance_offset) {
            spdlog::error("Failed to find Reflectance offset");
            return false;
        }
        dumper::g_dumper.add_offset("BasePart", "Reflectance", *reflectance_offset, "",
                                    FieldType::Float);

        const auto cast_shadow_offset = process::helpers::find_offset_with_getter<uint8_t>(
            part_addrs, [&](size_t i) { return (*parts)[i].props.cast_shadow ? 1 : 0; }, 0x300,
            0x1);
        if (!cast_shadow_offset) {
            spdlog::error("Failed to find CastShadow offset");
            return false;
        }
        dumper::g_dumper.add_offset("BasePart", "CastShadow", *cast_shadow_offset, "",
                                    FieldType::Bool);

        const auto locked_offset = process::helpers::find_offset_with_getter<uint8_t>(
            part_addrs, [&](size_t i) { return (*parts)[i].props.locked ? 1 : 0; }, 0x300, 0x1);
        if (!locked_offset) {
            spdlog::error("Failed to find Locked offset");
            return false;
        }
        dumper::g_dumper.add_offset("BasePart", "Locked", *locked_offset, "", FieldType::Bool);

        const auto shape_offset = process::helpers::find_offset_with_getter<uint8_t>(
            part_addrs, [&](size_t i) { return (*parts)[i].props.shape; }, 0x300, 0x1);
        if (!shape_offset) {
            spdlog::error("Failed to find Shape offset");
            return false;
        }
        dumper::g_dumper.add_offset("BasePart", "Shape", *shape_offset, "", FieldType::UInt8);

        const auto massless_offset = process::helpers::find_offset_with_getter<uint8_t>(
            part_addrs, [&](size_t i) { return (*parts)[i].props.massless ? 1 : 0; }, 0x300, 0x1);
        if (!massless_offset) {
            spdlog::error("Failed to find Massless offset");
            return false;
        }
        dumper::g_dumper.add_offset("BasePart", "Massless", *massless_offset, "", FieldType::Bool);

        const auto linear_velocity_offset =
            process::helpers::find_vec3_offset_multi<glm::vec3>(
                primitive_addrs,
                [&](size_t i) {
                    const auto& p = (*parts)[i].props;
                    return glm::vec3(p.vel_x, p.vel_y, p.vel_z);
                },
                0x200, 0.01f);

        if (!linear_velocity_offset) {
            spdlog::error("Failed to find AssemblyLinearVelocity offset");
            return false;
        }

        dumper::g_dumper.add_offset("Primitive", "AssemblyLinearVelocity",
                                    *linear_velocity_offset, "", FieldType::Vector3);

        const auto angular_velocity_offset =
            process::helpers::find_vec3_offset_multi<glm::vec3>(
                primitive_addrs,
                [&](size_t i) {
                    const auto& p = (*parts)[i].props;
                    return glm::vec3(p.angvel_x, p.angvel_y, p.angvel_z);
                },
                0x200, 0.01f);

        if (!angular_velocity_offset) {
            spdlog::error("Failed to find AssemblyAngularVelocity offset");
            return false;
        }

        dumper::g_dumper.add_offset("Primitive", "AssemblyAngularVelocity",
                                    *angular_velocity_offset, "", FieldType::Vector3);

        const auto com_getter = [&](size_t i) {
            const auto& p = (*parts)[i].props;
            return glm::vec3(p.center_of_mass_x, p.center_of_mass_y, p.center_of_mass_z);
        };

        if (!process::helpers::vec3_scan_has_signal<glm::vec3>(primitive_addrs, com_getter)) {
            spdlog::warn(
                "AssemblyCenterOfMass ground truth degenerate (anchored parts report zero), "
                "skipping scan");
        } else {
            const auto center_of_mass_offset =
                process::helpers::find_vec3_offset_multi<glm::vec3>(
                    primitive_addrs, com_getter, 0x200, 0.01f);

            if (center_of_mass_offset) {
                dumper::g_dumper.add_offset("Primitive", "AssemblyCenterOfMass",
                                            *center_of_mass_offset, "", FieldType::Vector3);
            } else {
                spdlog::warn("Failed to find AssemblyCenterOfMass offset (continuing)");
            }
        }

        // Attributes: DataModel > Workspace > TestPartN > SetAttribute ground truth.
        // Storage layout varies (inline vs pointer-to-container, f32 vs f64 payload);
        // try each candidate shape and keep the first that verifies across ALL parts.
        {
            const auto& p0 = (*parts)[0].props;

            auto verify_all =
                [&](size_t container_off, size_t value_off, bool deref, bool as_double) {
                    for (size_t i = 0; i < parts->size(); i++) {
                        uintptr_t base = part_addrs[i] + container_off;
                        if (deref) {
                            const auto storage = process::Memory::read<uintptr_t>(base);
                            if (!storage)
                                return false;
                            base = *storage;
                        }
                        if (as_double) {
                            const auto v = process::Memory::read<double>(base + value_off);
                            if (!v || std::abs(*v - (double)(*parts)[i].props.attr_num) >
                                          0.01)
                                return false;
                        } else {
                            const auto v =
                                process::Memory::read<float>(base + value_off);
                            if (!v || std::abs(*v - (*parts)[i].props.attr_num) > 0.01f)
                                return false;
                        }
                    }
                    return true;
                };

            struct AttrHit {
                size_t container;
                size_t value;
                bool deref;
                bool as_double;
                const char* label;
            };
            std::optional<AttrHit> hit;

            const auto try_shape = [&](bool deref, bool as_double, const char* label) {
                if (hit)
                    return;
                for (size_t container_off = 0; container_off <= 0x800; container_off += 8) {
                    // candidate payload location
                    uintptr_t probe_base = part_addrs[0] + container_off;
                    if (deref) {
                        const auto storage =
                            process::Memory::read<uintptr_t>(probe_base);
                        if (!storage)
                            continue;
                        probe_base = *storage;
                    }
                    const size_t max_probe = 0x400;
                    for (size_t value_off = 0; value_off <= max_probe; value_off += 4) {
                        bool match = false;
                        if (as_double) {
                            const auto v =
                                process::Memory::read<double>(probe_base + value_off);
                            match = v && std::abs(*v - (double)p0.attr_num) <= 0.01;
                        } else {
                            const auto v =
                                process::Memory::read<float>(probe_base + value_off);
                            match = v && std::abs(*v - p0.attr_num) <= 0.01f;
                        }
                        if (match &&
                            verify_all(container_off, value_off, deref, as_double)) {
                            hit = AttrHit{container_off, value_off, deref, as_double,
                                          label};
                            return;
                        }
                    }
                }
            };

            try_shape(true, false, "container ptr > f32");
            try_shape(true, true, "container ptr > f64");
            try_shape(false, false, "inline f32");
            try_shape(false, true, "inline f64");

            if (hit) {
                dumper::g_dumper.add_offset(
                    "Instance", "AttributeContainer", hit->container,
                    "DataModel>Workspace>TestPartN (SetAttribute)",
                    FieldType::Pointer);
                dumper::g_dumper.add_offset(
                    "AttributeContainer", "Number", hit->value,
                    std::string("Instance>") +
                        (hit->deref ? "AttributeContainer" : "inline") +
                        (hit->as_double ? " as f64" : " as f32"),
                    FieldType::Double);
            } else {
                spdlog::warn("Failed to locate attribute number storage in any known "
                             "layout (continuing)");
            }

            const auto str_attr = process::helpers::find_sso_string_offset_in_pointer(
                part_addrs[0], p0.attr_str, 0x800, 0x400, 0x8, 0x8);

            if (!str_attr) {
                spdlog::warn("Failed to locate attribute string storage (continuing)");
            } else {
                bool consistent = true;
                for (size_t i = 0; i < parts->size() && consistent; i++) {
                    const auto storage =
                        process::Memory::read<uintptr_t>(part_addrs[i] + str_attr->first);
                    if (!storage) {
                        consistent = false;
                        break;
                    }
                    const auto s =
                        process::Memory::read_sso_string(*storage + str_attr->second);
                    if (!s || *s != (*parts)[i].props.attr_str)
                        consistent = false;
                }

                if (consistent) {
                    dumper::g_dumper.add_offset("AttributeContainer", "String",
                                                str_attr->second,
                                                "Instance>AttributeContainer",
                                                FieldType::Pointer);
                } else {
                    spdlog::warn("Attribute string storage inconsistent across parts "
                                 "(continuing)");
                }
            }
        }

        const auto part_offset = process::Rtti::find(primitive_addrs[0], "Part@RBX", 0x400);

        if (!part_offset) {
            spdlog::error("Failed to find Part offset in Primitive");
            return false;
        }

        dumper::g_dumper.add_offset("Primitive", "Part", *part_offset, "", FieldType::Pointer);

        dumper::g_dumper.add_offset("BasePart", "Velocity",
                                    *primitive_offset + *linear_velocity_offset,
                                    "DataModel>Workspace>TestPartN>BasePart>Primitive",
                                    FieldType::Vector3);
        dumper::g_dumper.add_offset("BasePart", "AngularVelocity",
                                    *primitive_offset + *angular_velocity_offset,
                                    "DataModel>Workspace>TestPartN>BasePart>Primitive",
                                    FieldType::Vector3);

        return true;
    }

} // namespace dumper::stages::base_part

REGISTER_STAGE(base_part)
