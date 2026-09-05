#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>
#include <functional>
#include <map>
#include <unordered_map>

namespace dumper::stages::value_types {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->values.empty()) {
            spdlog::warn("No value properties from bridge");
            return false;
        }

        const auto& by_name = dumper::g_dumper.m_workspace_index;

        // group instances by value class; each class stores its payload differently
        std::map<std::string, std::vector<uintptr_t>> grouped;
        std::map<std::string, std::vector<const bridge::ValueProperty*>> grouped_props;
        for (const auto& v : props->values) {
            const auto it = by_name.find(v.name);
            if (it == by_name.end())
                continue;
            grouped[v.class_name].push_back(it->second);
            grouped_props[v.class_name].push_back(&v);
        }

        bool any = false;

        if (grouped.count("BoolValue")) {
            const auto& a = grouped["BoolValue"];
            const auto& e = grouped_props["BoolValue"];
            if (a.size() >= 2) {
                if (auto off = process::helpers::find_offset_with_getter<uint8_t>(
                        a, [&](size_t i) { return e[i]->bool_value ? 1 : 0; }, 0x800,
                        0x1)) {
                    g_dumper.add_offset("BoolValue", "Value", *off,
                                        "DataModel>Workspace>SkidValueN", FieldType::Bool);
                    any = true;
                }
            }
        }

        if (grouped.count("IntValue")) {
            const auto& a = grouped["IntValue"];
            const auto& e = grouped_props["IntValue"];
            if (a.size() >= 2) {
                if (auto off = process::helpers::find_offset_with_getter<int32_t>(
                        a, [&](size_t i) { return e[i]->int_value; }, 0x800, 0x4)) {
                    g_dumper.add_offset("IntValue", "Value", *off,
                                        "DataModel>Workspace>SkidValueN", FieldType::Int32);
                    any = true;
                }
            }
        }

        if (grouped.count("NumberValue")) {
            const auto& a = grouped["NumberValue"];
            const auto& e = grouped_props["NumberValue"];
            if (!a.empty()) {
                if (auto off = process::helpers::find_offset<double>(
                        a[0], e[0]->number_value, 0x1000, 0x8)) {
                    g_dumper.add_offset("NumberValue", "Value", *off,
                                        "DataModel>Workspace>SkidValueN",
                                        FieldType::Double);
                    any = true;
                }
            }
        }

        if (grouped.count("Vector3Value")) {
            const auto& a = grouped["Vector3Value"];
            const auto& e = grouped_props["Vector3Value"];
            if (!a.empty()) {
                if (auto off = process::helpers::find_vec_offset<glm::vec3>(
                        a[0],
                        glm::vec3(e[0]->vec_x, e[0]->vec_y, e[0]->vec_z),
                        0x1000)) {
                    g_dumper.add_offset("Vector3Value", "Value", *off,
                                        "DataModel>Workspace>SkidValueN",
                                        FieldType::Vector3);
                    any = true;
                }
            }
        }

        if (grouped.count("StringValue")) {
            const auto& a = grouped["StringValue"];
            const auto& e = grouped_props["StringValue"];
            if (a.size() >= 2) {
                // find the SSO string offset on instance 0, verify on the rest
                const auto off0 = process::helpers::find_sso_string_offset(
                    a[0], e[0]->string_value, 0x800, 0x8);
                if (off0) {
                    bool consistent = true;
                    for (size_t i = 1; i < a.size(); i++) {
                        const auto s =
                            process::Memory::read_sso_string(a[i] + *off0);
                        if (!s || *s != e[i]->string_value)
                            consistent = false;
                    }
                    if (consistent) {
                        g_dumper.add_offset("StringValue", "Value", *off0,
                                            "DataModel>Workspace>SkidValueN",
                                            FieldType::Pointer);
                        any = true;
                    }
                }
            }
        }

        if (grouped.count("CFrameValue")) {
            const auto& a = grouped["CFrameValue"];
            const auto& e = grouped_props["CFrameValue"];
            if (a.size() >= 2) {
                if (auto off = process::helpers::find_vec3_offset_multi<glm::vec3>(
                        a,
                        [&](size_t i) {
                            return glm::vec3(e[i]->cf_x, e[i]->cf_y, e[i]->cf_z);
                        },
                        0x1000, 0.01f)) {
                    g_dumper.add_offset("CFrameValue", "Value", *off,
                                        "DataModel>Workspace>SkidValueN",
                                        FieldType::Vector3);
                    any = true;
                }
            }
        }

        if (!any) {
            spdlog::warn("No value-type offsets resolved");
            return false;
        }

        return true;
    }

} // namespace dumper::stages::value_types

REGISTER_STAGE(value_types)
