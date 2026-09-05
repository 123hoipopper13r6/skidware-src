#include "instance.h"
#include "dumper/dumper.h"
#include "process/helpers/helpers.h"
#include "process/memory/memory.h"
#include "process/rtti/rtti.h"
#include "roblox/offsets.h"
#include <spdlog/spdlog.h>

namespace dumper::stages::instance {

    static auto find_children_offsets(uintptr_t instance, size_t parent_offset)
        -> std::optional<std::pair<size_t, size_t>> {
        std::optional<std::pair<size_t, size_t>> best;
        size_t best_count = 0;

        for (size_t start_off = 0; start_off < 0x200; start_off += 0x8) {
            if (start_off == parent_offset) {
                continue;
            }

            auto start_ptr = process::Memory::read<uintptr_t>(instance + start_off);
            if (!start_ptr || *start_ptr < 0x10000) {
                continue;
            }

            for (size_t end_off = 0; end_off < 0x20; end_off += 0x8) {
                auto end_ptr = process::Memory::read<uintptr_t>(*start_ptr + end_off);
                if (!end_ptr || *end_ptr < 0x10000) {
                    continue;
                }

                size_t count = 0;
                auto node_opt = process::Memory::read<uintptr_t>(*start_ptr);
                if (!node_opt) {
                    continue;
                }

                uintptr_t node = *node_opt;
                for (int i = 0; i < 1000 && node != *end_ptr; i++, node += 0x10) {
                    auto child = process::Memory::read<uintptr_t>(node);
                    if (!child || *child < 0x10000) {
                        break;
                    }

                    auto vtable = process::Memory::read<uintptr_t>(*child);
                    if (!vtable || *vtable < 0x10000) {
                        break;
                    }

                    count++;
                }

                if (count > best_count) {
                    best_count = count;
                    best = std::make_pair(start_off, end_off);
                }
            }
        }

        if (best && best_count >= 10)
            return best;

        return std::nullopt;
    }

    auto dump() -> bool {
        const auto workspace_addr = process::Memory::read<uintptr_t>(
            dumper::g_data_model_addr + *dumper::g_dumper.get_offset("DataModel", "Workspace"));

        if (!workspace_addr) {
            spdlog::error("Failed to read Workspace from Datamodel");
            return false;
        }

        const auto instance_name =
            process::helpers::find_sso_string_offset_in_pointer(*workspace_addr, "Workspace");

        if (!instance_name) {
            spdlog::error("Failed to find Name");
            return false;
        }

        dumper::g_dumper.add_offset("Instance", "NameContainer", instance_name->first, "", FieldType::Pointer);
        dumper::g_dumper.add_offset("Instance", "Name", instance_name->second);

        const auto class_descriptor =
            process::Rtti::find(*workspace_addr, "ClassDescriptor@Reflection@RBX");

        if (!class_descriptor) {
            spdlog::error("Failed to get ClassDescriptor for Instance");
            return false;
        }

        dumper::g_dumper.add_offset("Instance", "ClassDescriptor", *class_descriptor, "", FieldType::Pointer);

        const auto class_descriptor_addr =
            process::Memory::read<uintptr_t>(*workspace_addr + *class_descriptor);

        if (!class_descriptor_addr) {
            spdlog::error("Failed to read ClassDescriptor for Instance");
            return false;
        }

        const auto class_name =
            process::helpers::find_sso_string_offset(*class_descriptor_addr, "Workspace");

        if (!class_name) {
            spdlog::error("Failed to get ClassName for Instance");
            return false;
        }

        dumper::g_dumper.add_offset("ClassDescriptor", "ClassName", *class_name);

        const auto parent = process::Rtti::find(*workspace_addr, "DataModel@RBX");

        if (!parent) {
            spdlog::error("Failed to get Parent for Instance");
            return false;
        }

        dumper::g_dumper.add_offset("Instance", "Parent", *parent, "", FieldType::Pointer);

        const auto children = find_children_offsets(*workspace_addr, *parent);

        if (!children) {
            spdlog::error("Failed to find Children offsets");
            return false;
        }

        dumper::g_dumper.add_offset("Instance", "ChildrenStart", children->first, "", FieldType::Pointer);
        dumper::g_dumper.add_offset("Instance", "ChildrenEnd", children->second);

        roblox::offsets::Instance::NameContainer = instance_name->first;
        roblox::offsets::Instance::Name = instance_name->second;
        roblox::offsets::Instance::ClassDescriptor = *class_descriptor;
        roblox::offsets::ClassDescriptor::ClassName = *class_name;
        roblox::offsets::Instance::Parent = *parent;
        roblox::offsets::Instance::ChildrenStart = children->first;
        roblox::offsets::Instance::ChildrenEnd = children->second;

        dumper::g_workspace = roblox::Instance(*workspace_addr);

        return true;
    }
} // namespace dumper::stages::instance
