#pragma once
#include "process/memory/memory.h"
#include <cmath>
#include <functional>
#include <optional>
#include <regex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace process::helpers {
    auto find_pointer_by_rtti(std::string_view section_name,
                              const std::vector<std::string>& class_names, size_t alignment = 8)
        -> std::unordered_map<std::string, std::optional<size_t>>;

    auto find_sso_string_offset(uintptr_t base_address, const std::string& target_string,
                                size_t max_offset = 0x1000, size_t alignment = 8,
                                bool direct = false) -> std::optional<size_t>;

    auto find_string_offset(uintptr_t base_address, const std::string& target_string,
                            size_t max_offset = 0x1000, size_t alignment = 8,
                            size_t max_string_length = 256, bool direct = false)
        -> std::optional<size_t>;

    auto find_string_by_regex(uintptr_t base_address, const std::string& regex_pattern,
                              size_t max_offset = 0x1000, size_t alignment = 8,
                              size_t max_string_length = 256, bool direct = false)
        -> std::optional<size_t>;

    auto find_pointer_offset(uintptr_t base_address, uintptr_t target_pointer,
                             size_t max_offset = 0x1000, size_t alignment = 8)
        -> std::optional<size_t>;

    auto find_color3_offset(const std::vector<uintptr_t>& addresses,
                            std::function<std::tuple<uint8_t, uint8_t, uint8_t>(size_t)> get_rgb,
                            size_t max_offset = 0x300) -> std::optional<size_t>;

    template <typename T>
    auto find_offset(uintptr_t base_address, const T& value, size_t max_offset = 0x1000,
                     size_t alignment = 8) -> std::optional<size_t> {
        for (size_t offset = 0; offset < max_offset; offset += alignment) {
            auto read_value = Memory::read<T>(base_address + offset);
            if (read_value && read_value.value() == value) {
                return offset;
            }
        }
        return std::nullopt;
    }

    // allow tolerance for floats instead of using the generic func
    template <>
    inline auto find_offset<float>(uintptr_t base_address, const float& value, size_t max_offset,
                                   size_t alignment) -> std::optional<size_t> {
        constexpr float TOLERANCE = 0.0001f;

        for (size_t offset = 0; offset < max_offset; offset += alignment) {
            auto read_value = Memory::read<float>(base_address + offset);

            if (!read_value) {
                continue;
            }

            if (std::isnan(*read_value) || std::isinf(*read_value)) {
                continue;
            }

            if (std::abs(*read_value - value) < TOLERANCE) {
                return offset;
            }
        }

        return std::nullopt;
    }

    template <typename VecType>
    auto find_vec_offset(uintptr_t base_address, const VecType& value, size_t max_offset = 0x1000,
                         float tolerance = 5.0f, size_t alignment = 4) -> std::optional<size_t> {
        constexpr size_t components = VecType::length();

        for (size_t offset = 0; offset < max_offset; offset += alignment) {
            bool all_match = true;

            for (size_t i = 0; i < components; i++) {
                auto component_value = Memory::read<float>(base_address + offset + (i * 4));

                if (!component_value || std::isnan(*component_value) ||
                    std::isinf(*component_value)) {
                    all_match = false;
                    break;
                }

                if (std::abs(*component_value - value[i]) >= tolerance) {
                    all_match = false;
                    break;
                }
            }

            if (all_match) {
                return offset;
            }
        }

        return std::nullopt;
    }

    template <typename T>
    auto find_offset_with_getter(const std::vector<uintptr_t>& addresses,
                                 std::function<T(size_t)> get_expected_value, size_t max_offset,
                                 size_t alignment,
                                 const std::unordered_set<size_t>& ignored_offsets = {})
        -> std::optional<size_t> {
        for (size_t offset = 0; offset < max_offset; offset += alignment) {
            if (ignored_offsets.contains(offset)) {
                continue;
            }

            bool all_match = true;

            for (size_t i = 0; i < addresses.size(); i++) {
                auto read_value = Memory::read<T>(addresses[i] + offset);
                T expected = get_expected_value(i);

                if (!read_value || *read_value != expected) {
                    all_match = false;
                    break;
                }
            }

            if (all_match) {
                return offset;
            }
        }

        return std::nullopt;
    }

    template <typename VecType>
    auto find_vec3_offset_multi(const std::vector<uintptr_t>& addresses,
                                std::function<VecType(size_t)> get_expected_vec,
                                size_t max_offset = 0x1000, float tolerance = 0.01f)
        -> std::optional<size_t> {
        for (size_t offset = 0; offset < max_offset; offset += 4) {
            bool all_match = true;

            for (size_t i = 0; i < addresses.size(); i++) {
                VecType expected = get_expected_vec(i);

                auto x = Memory::read<float>(addresses[i] + offset);
                auto y = Memory::read<float>(addresses[i] + offset + 4);
                auto z = Memory::read<float>(addresses[i] + offset + 8);

                if (!x || !y || !z || std::abs(*x - expected.x) > tolerance ||
                    std::abs(*y - expected.y) > tolerance ||
                    std::abs(*z - expected.z) > tolerance) {
                    all_match = false;
                    break;
                }
            }

            if (all_match) {
                return offset;
            }
        }

        return std::nullopt;
    }

    // guards multi-scans against degenerate ground truth (all instances sharing one
    // value, e.g. zero CenterOfMass on anchored parts -> would bind a garbage offset)
    template <typename VecType>
    auto vec3_scan_has_signal(const std::vector<uintptr_t>& addresses,
                              std::function<VecType(size_t)> get_expected_vec,
                              float tolerance = 0.01f)
        -> bool {
        const VecType first = get_expected_vec(0);
        for (size_t i = 1; i < addresses.size(); i++) {
            const VecType e = get_expected_vec(i);
            if (std::abs(e.x - first.x) > tolerance || std::abs(e.y - first.y) > tolerance ||
                std::abs(e.z - first.z) > tolerance) {
                return true;
            }
        }
        return false;
    }

    template <typename T>
    auto find_offset_in_pointer(uintptr_t base_address, const T& value,
                                size_t max_pointer_offset = 0x1000,
                                size_t max_value_offset = 0x1000, size_t pointer_alignment = 8,
                                size_t value_alignment = 4)
        -> std::optional<std::pair<size_t, size_t>> {
        for (size_t ptr_offset = 0; ptr_offset < max_pointer_offset;
             ptr_offset += pointer_alignment) {
            auto ptr = Memory::read<uintptr_t>(base_address + ptr_offset);
            if (!ptr || *ptr < 0x10000) {
                continue;
            }

            auto value_offset = find_offset<T>(*ptr, value, max_value_offset, value_alignment);
            if (value_offset) {
                return std::make_pair(ptr_offset, *value_offset);
            }
        }

        return std::nullopt;
    }

    auto find_sso_string_offset_in_pointer(uintptr_t base_address, const std::string& target_string,
                                           size_t max_pointer_offset = 0x1000,
                                           size_t max_string_offset = 0x1000,
                                           size_t pointer_alignment = 8,
                                           size_t string_alignment = 8)
        -> std::optional<std::pair<size_t, size_t>>;

    inline auto find_function_start(uintptr_t addr) -> std::optional<uintptr_t> {
        constexpr size_t search_size = 0x1000;
        uintptr_t region_start = addr - search_size;
        auto buffer = Memory::read_bytes(region_start, search_size);
        if (buffer.empty())
            return std::nullopt;

        for (size_t i = buffer.size() - 1; i > 1; i--) {
            if (buffer[i] == 0xCC && buffer[i - 1] == 0xCC) {
                while (i < buffer.size() && buffer[i] == 0xCC)
                    i++;
                return region_start + i;
            }
        }

        return std::nullopt;
    }

    inline auto estimate_function_size(uintptr_t func_addr, size_t max_scan = 0x2000) -> size_t {
        auto buffer = Memory::read_bytes(func_addr, max_scan);
        if (buffer.empty())
            return 0;

        for (size_t i = 1; i < buffer.size(); i++) {
            if (buffer[i] == 0xCC && buffer[i - 1] == 0xCC)
                return i - 1;
        }

        return max_scan;
    }

    inline auto function_is_at_least(uintptr_t func_addr, size_t min_size) -> bool {
        auto buffer = Memory::read_bytes(func_addr, min_size);
        if (buffer.size() < min_size)
            return false;

        for (size_t i = 1; i < buffer.size(); i++) {
            if (buffer[i] == 0xCC && buffer[i - 1] == 0xCC)
                return false;
        }
        return true;
    }

    inline auto is_in_section(uintptr_t ptr, const std::pair<uintptr_t, size_t>& section) -> bool {
        return ptr >= section.first && ptr < section.first + section.second;
    }

} // namespace process::helpers