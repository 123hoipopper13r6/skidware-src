#include "property_descriptors.h"
#include "dumper/dumper.h"
#include "process/helpers/helpers.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include "process/rtti/rtti.h"
#include "roblox/offsets.h"
#include <spdlog/spdlog.h>

namespace dumper::stages::property_descriptors {

    static auto find_list_by_rtti(uintptr_t class_desc, const std::string& rtti_needle,
                                  size_t skip_off = 0) -> std::optional<size_t> {
        for (size_t off = 0x20; off < 0x100; off += 0x8) {
            if (off == skip_off)
                continue;

            auto list_ptr = process::Memory::read<uintptr_t>(class_desc + off);
            if (!list_ptr || *list_ptr < 0x10000)
                continue;

            auto first = process::Memory::read<uintptr_t>(*list_ptr);
            if (!first || *first < 0x10000)
                continue;

            auto rtti = process::Rtti::scan_rtti(*first);
            if (rtti && rtti->name.find(rtti_needle) != std::string::npos)
                return off;
        }
        return std::nullopt;
    }

    static auto find_entry_by_name(uintptr_t list_start, size_t name_off, const std::string& target)
        -> uintptr_t {
        uintptr_t current = list_start;
        for (int i = 0; i < 500; i++) {
            auto entry = process::Memory::read<uintptr_t>(current);
            if (!entry || !*entry)
                break;

            auto name_ptr = process::Memory::read<uintptr_t>(*entry + name_off);
            if (name_ptr && *name_ptr > 0x10000) {
                auto name = process::Memory::read_sso_string(*name_ptr);
                if (name && *name == target)
                    return *entry;
            }
            current += 0x10;
        }
        return 0;
    }

    static auto find_name_offset(uintptr_t descriptor) -> std::optional<size_t> {
        for (size_t off = 0; off < 0x40; off += 0x8) {
            auto ptr = process::Memory::read<uintptr_t>(descriptor + off);
            if (!ptr || *ptr < 0x10000)
                continue;

            auto str = process::Memory::read_sso_string(*ptr);
            if (str && !str->empty() && str->length() < 64)
                return off;
        }
        return std::nullopt;
    }

    static void find_property_sub_offsets(uintptr_t prop_desc) {
        for (size_t off = 0; off < 0x100; off += 0x8) {
            auto val = process::Memory::read<uintptr_t>(prop_desc + off);
            if (!val || *val < 0x10000)
                continue;

            auto rtti = process::Rtti::scan_rtti(*val);
            if (!rtti)
                continue;

            if (rtti->name.find("TType") != std::string::npos)
                dumper::g_dumper.add_offset("PropertyDescriptor", "TType", off, "",
                                            FieldType::Pointer);
            else if (rtti->name.find("GetSetImpl") != std::string::npos ||
                     rtti->name.find("GetImpl") != std::string::npos)
                dumper::g_dumper.add_offset("PropertyDescriptor", "GetSetImpl", off, "",
                                            FieldType::Pointer);
        }
    }

    auto dump() -> bool {
        const auto workspace_addr = process::Memory::read<uintptr_t>(
            dumper::g_data_model_addr + *dumper::g_dumper.get_offset("DataModel", "Workspace"));
        if (!workspace_addr) {
            spdlog::error("PropertyDescriptors: Failed to read Workspace");
            return false;
        }

        const auto class_desc_off = dumper::g_dumper.get_offset("Instance", "ClassDescriptor");
        if (!class_desc_off) {
            spdlog::error("PropertyDescriptors: ClassDescriptor offset not available");
            return false;
        }

        auto class_desc = process::Memory::read<uintptr_t>(*workspace_addr + *class_desc_off);
        if (!class_desc) {
            spdlog::error("PropertyDescriptors: Failed to read ClassDescriptor");
            return false;
        }

        auto prop_off = find_list_by_rtti(*class_desc, "PropDescriptor");
        if (!prop_off) {
            spdlog::error("PropertyDescriptors: Failed to find PropertyDescriptors list");
            return false;
        }
        dumper::g_dumper.add_offset("ClassDescriptor", "PropertyDescriptors", *prop_off, "",
                                    FieldType::Pointer);

        auto event_off = find_list_by_rtti(*class_desc, "EventDesc", *prop_off);
        if (event_off)
            dumper::g_dumper.add_offset("ClassDescriptor", "EventDescriptors", *event_off, "",
                                        FieldType::Pointer);

        auto func_off = find_list_by_rtti(*class_desc, "BoundFuncDesc", *prop_off);
        if (!func_off)
            func_off = find_list_by_rtti(*class_desc, "FuncDesc", *prop_off);
        if (func_off)
            dumper::g_dumper.add_offset("ClassDescriptor", "FunctionDescriptors", *func_off, "",
                                        FieldType::Pointer);

        auto prop_list = process::Memory::read<uintptr_t>(*class_desc + *prop_off);
        if (!prop_list || !*prop_list) {
            spdlog::error("PropertyDescriptors: PropertyDescriptors list is empty");
            return false;
        }

        auto first_prop = process::Memory::read<uintptr_t>(*prop_list);
        if (!first_prop || !*first_prop) {
            spdlog::error("PropertyDescriptors: First property entry is null");
            return false;
        }

        auto name_off = find_name_offset(*first_prop);
        if (!name_off) {
            spdlog::error("PropertyDescriptors: Failed to find Descriptor::Name offset");
            return false;
        }
        dumper::g_dumper.add_offset("Descriptor", "Name", *name_off, "", FieldType::Pointer);

        find_property_sub_offsets(*first_prop);

        if (func_off) {
            auto func_list = process::Memory::read<uintptr_t>(*class_desc + *func_off);
            if (func_list && *func_list) {
                uintptr_t raycast = find_entry_by_name(*func_list, *name_off, "Raycast");
                if (raycast) {
                    auto base = process::g_process.get_module_base();
                    auto text = process::g_process.get_section(".text");

                    size_t fn_off = 0x80;
                    for (size_t off : {0x70ul, 0x78ul, 0x80ul, 0x88ul, 0x90ul}) {
                        auto addr = process::Memory::read<uintptr_t>(raycast + off);
                        if (addr && *addr > 0x10000 && text &&
                            process::helpers::is_in_section(*addr, *text)) {
                            fn_off = off;
                            break;
                        }
                    }

                    dumper::g_dumper.add_offset("WorldRoot", "RaycastBoundDesc", raycast - base,
                                                "", FieldType::Pointer);
                    dumper::g_dumper.add_offset("WorldRoot", "RaycastBoundFn", fn_off, "",
                                                FieldType::UInt64);
                    dumper::g_dumper.add_offset("FunctionDescriptor", "Function", fn_off, "",
                                                FieldType::Pointer);

                    {
                        auto dump_func_rva = [&](const std::string& func_name) {
                            uintptr_t desc = find_entry_by_name(*func_list, *name_off, func_name);
                            if (!desc)
                                return;
                            auto addr = process::Memory::read<uintptr_t>(desc + fn_off);
                            if (addr && *addr > 0x10000)
                                dumper::g_dumper.add_offset(
                                    "Functions", func_name, *addr - base,
                                    "better to resolve at runtime via func descriptors");
                        };

                        dump_func_rva("Clone");
                        dump_func_rva("Destroy");
                        dump_func_rva("Raycast");
                        dump_func_rva("FindPartOnRay");
                        dump_func_rva("FindPartOnRayWithIgnoreList");
                        dump_func_rva("FindPartOnRayWithWhitelist");
                        dump_func_rva("Shapecast");
                    }
                } else {
                    spdlog::error("PropertyDescriptors: 'Raycast' not found in functions list");
                }
            }
        }

        if (auto v = dumper::g_dumper.get_offset("ClassDescriptor", "PropertyDescriptors"))
            roblox::offsets::ClassDescriptor::PropertyDescriptors = *v;
        if (auto v = dumper::g_dumper.get_offset("ClassDescriptor", "EventDescriptors"))
            roblox::offsets::ClassDescriptor::EventDescriptors = *v;
        if (auto v = dumper::g_dumper.get_offset("ClassDescriptor", "FunctionDescriptors"))
            roblox::offsets::ClassDescriptor::FunctionDescriptors = *v;
        if (auto v = dumper::g_dumper.get_offset("Descriptor", "Name"))
            roblox::offsets::Descriptor::Name = *v;
        if (auto v = dumper::g_dumper.get_offset("FunctionDescriptor", "Function"))
            roblox::offsets::FunctionDescriptor::Function = *v;

        return true;
    }

} // namespace dumper::stages::property_descriptors
