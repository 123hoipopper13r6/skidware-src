#include "instance.h"
#include "process/memory/memory.h"
#include "roblox/offsets.h"

namespace roblox {
    auto Instance::is_valid() const -> bool { return m_address != 0; }

    auto Instance::get_name() const -> std::optional<std::string> {
        if (!is_valid()) {
            return std::nullopt;
        }

        const auto name_container =
            process::Memory::read<uintptr_t>(m_address + offsets::Instance::NameContainer);

        if (!name_container) {
            return std::nullopt;
        }

        return process::Memory::read_sso_string(*name_container + offsets::Instance::Name);
    }

    auto Instance::get_class_name() const -> std::optional<std::string> {
        if (!is_valid()) {
            return std::nullopt;
        }

        const auto class_descriptor =
            process::Memory::read<uintptr_t>(m_address + offsets::Instance::ClassDescriptor);

        if (!class_descriptor) {
            return std::nullopt;
        }

        const auto class_name_pointer =
            process::Memory::read<uintptr_t>(*class_descriptor + offsets::ClassDescriptor::ClassName);

        if (!class_name_pointer) {
            return std::nullopt;
        }

        return process::Memory::read_sso_string(*class_name_pointer);
    }

    auto Instance::get_children() const -> std::vector<Instance> {
        std::vector<Instance> children;

        if (!is_valid()) {
            return children;
        }

        const auto start =
            process::Memory::read<uintptr_t>(m_address + offsets::Instance::ChildrenStart);
        if (!start) {
            return children;
        }

        const auto end = process::Memory::read<uintptr_t>(*start + offsets::Instance::ChildrenEnd);
        if (!end) {
            return children;
        }

        auto current = process::Memory::read<uintptr_t>(*start);
        if (!current) {
            return children;
        }

        constexpr size_t MAX = 8192;
        size_t iterations = 0;
        auto current_addr = *current;
        const auto end_addr = *end;

        while (current_addr != end_addr && iterations < MAX) {
            auto child_addr = process::Memory::read<uintptr_t>(current_addr);
            if (child_addr && *child_addr) {
                children.emplace_back(*child_addr);
            }

            current_addr += 0x10;
            ++iterations;
        }

        return children;
    }

    auto Instance::get_parent() const -> std::optional<Instance> {
        return process::Memory::read<Instance>(m_address + offsets::Instance::Parent);
    }

    auto Instance::find_first_child(std::string_view name) const -> std::optional<Instance> {
        if (!is_valid()) {
            return std::nullopt;
        }

        for (const auto& child : get_children()) {
            const auto child_name = child.get_name();
            if (child_name && *child_name == name) {
                return child;
            }
        }

        return std::nullopt;
    }

    auto Instance::get_function_address(std::string_view func_name) const
        -> std::optional<uintptr_t> {
        if (!is_valid() || !offsets::ClassDescriptor::FunctionDescriptors ||
            !offsets::Descriptor::Name || !offsets::FunctionDescriptor::Function)
            return std::nullopt;

        auto class_desc =
            process::Memory::read<uintptr_t>(m_address + offsets::Instance::ClassDescriptor);
        if (!class_desc)
            return std::nullopt;

        auto func_list = process::Memory::read<uintptr_t>(
            *class_desc + offsets::ClassDescriptor::FunctionDescriptors);
        if (!func_list || !*func_list)
            return std::nullopt;

        uintptr_t current = *func_list;
        for (int i = 0; i < 500; i++) {
            auto entry = process::Memory::read<uintptr_t>(current);
            if (!entry || !*entry)
                break;

            auto name_ptr =
                process::Memory::read<uintptr_t>(*entry + offsets::Descriptor::Name);
            if (name_ptr && *name_ptr > 0x10000) {
                auto name = process::Memory::read_sso_string(*name_ptr);
                if (name && *name == func_name) {
                    auto addr = process::Memory::read<uintptr_t>(
                        *entry + offsets::FunctionDescriptor::Function);
                    if (addr && *addr > 0x10000)
                        return *addr;
                }
            }

            current += 0x10;
        }

        return std::nullopt;
    }

    auto Instance::get_address() const -> std::uint64_t { return m_address; };

} // namespace roblox
