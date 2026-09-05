#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include "process/memory/memory.h"
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>

namespace dumper::stages::highlight {

    struct HighlightData {
        uintptr_t address;
        uintptr_t adornee_address;
        bridge::HighlightProperty props;
    };

    static auto get_highlight_data(const bridge::HighlightPropertiesInfo& info)
        -> std::optional<std::vector<HighlightData>> {
        std::vector<HighlightData> result;

        auto folder = dumper::g_workspace->find_first_child("Highlights");
        if (!folder || !folder->is_valid())
            return std::nullopt;

        for (const auto& prop : info.highlights) {
            auto part =
                folder->find_first_child("HighlightPart" + prop.name.substr(prop.name.size() - 1));
            if (!part || !part->is_valid())
                continue;

            auto highlight = part->find_first_child(prop.name);
            if (!highlight || !highlight->is_valid()) {
                spdlog::error("Highlight: Failed to find {}", prop.name);
                return std::nullopt;
            }

            result.push_back({highlight->get_address(), part->get_address(), prop});
        }

        return result;
    }

    auto dump() -> bool {
        const auto highlight_info = bridge::g_bridge.read_highlights_information();
        if (!highlight_info || highlight_info->highlights.size() < 3) {
            spdlog::error("Highlight: Not enough highlights from bridge");
            return false;
        }

        const auto highlights = get_highlight_data(*highlight_info);
        if (!highlights || highlights->size() < 3) {
            spdlog::error("Highlight: Failed to get highlight data");
            return false;
        }

        std::vector<uintptr_t> addrs;
        std::vector<uintptr_t> adornee_addrs;
        for (const auto& h : *highlights) {
            addrs.push_back(h.address);
            adornee_addrs.push_back(h.adornee_address);
        }

        auto parent_off = dumper::g_dumper.get_offset("Instance", "Parent");
        size_t skip_off = parent_off ? *parent_off : 0x68;

        std::optional<size_t> adornee_offset;
        for (size_t off = 0x8; off < 0x300; off += 0x8) {
            if (off == skip_off)
                continue;

            auto p1 = process::Memory::read<uintptr_t>(addrs[0] + off);
            auto p2 = process::Memory::read<uintptr_t>(addrs[1] + off);
            if (!p1 || !p2)
                continue;
            if (*p1 == adornee_addrs[0] && *p2 == adornee_addrs[1]) {
                adornee_offset = off;
                break;
            }
        }

        if (adornee_offset)
            dumper::g_dumper.add_offset("Highlight", "Adornee", *adornee_offset, "", FieldType::Pointer);
        else
            spdlog::error("Highlight: Failed to find Adornee offset");

        const auto depth_mode_offset = process::helpers::find_offset_with_getter<uint8_t>(
            addrs, [&](size_t i) { return (*highlights)[i].props.depth_mode; }, 0x300, 0x1);
        if (!depth_mode_offset) {
            spdlog::error("Highlight: Failed to find DepthMode offset");
            return false;
        }
        dumper::g_dumper.add_offset("Highlight", "DepthMode", *depth_mode_offset, "", FieldType::UInt8);

        const auto fill_color_offset =
            process::helpers::find_vec3_offset_multi<glm::vec3>(addrs, [&](size_t i) {
                const auto& p = (*highlights)[i].props;
                return glm::vec3(p.fill_color_r / 255.0f, p.fill_color_g / 255.0f,
                                 p.fill_color_b / 255.0f);
            });
        if (!fill_color_offset) {
            spdlog::error("Highlight: Failed to find FillColor offset");
            return false;
        }
        dumper::g_dumper.add_offset("Highlight", "FillColor", *fill_color_offset, "", FieldType::Color3Float);

        const auto fill_transparency_offset = process::helpers::find_offset_with_getter<float>(
            addrs, [&](size_t i) { return (*highlights)[i].props.fill_transparency; }, 0x300, 0x4);
        if (!fill_transparency_offset) {
            spdlog::error("Highlight: Failed to find FillTransparency offset");
            return false;
        }
        dumper::g_dumper.add_offset("Highlight", "FillTransparency", *fill_transparency_offset, "", FieldType::Float);

        const auto outline_color_offset =
            process::helpers::find_vec3_offset_multi<glm::vec3>(addrs, [&](size_t i) {
                const auto& p = (*highlights)[i].props;
                return glm::vec3(p.outline_color_r / 255.0f, p.outline_color_g / 255.0f,
                                 p.outline_color_b / 255.0f);
            });
        if (!outline_color_offset) {
            spdlog::error("Highlight: Failed to find OutlineColor offset");
            return false;
        }
        dumper::g_dumper.add_offset("Highlight", "OutlineColor", *outline_color_offset, "", FieldType::Color3Float);

        const auto outline_transparency_offset = process::helpers::find_offset_with_getter<float>(
            addrs, [&](size_t i) { return (*highlights)[i].props.outline_transparency; }, 0x300,
            0x4);
        if (!outline_transparency_offset) {
            spdlog::error("Highlight: Failed to find OutlineTransparency offset");
            return false;
        }
        dumper::g_dumper.add_offset("Highlight", "OutlineTransparency",
                                    *outline_transparency_offset, "", FieldType::Float);

        // Scan Enabled after other fields - start past DepthMode to avoid base class bools
        for (size_t off = *depth_mode_offset + 1; off < *depth_mode_offset + 0x20; off += 0x1) {
            bool all_match = true;
            for (size_t i = 0; i < addrs.size(); i++) {
                auto val = process::Memory::read<uint8_t>(addrs[i] + off);
                uint8_t expected = (*highlights)[i].props.enabled ? 1 : 0;
                if (!val || *val != expected) {
                    all_match = false;
                    break;
                }
            }
            if (all_match) {
                dumper::g_dumper.add_offset("Highlight", "Enabled", off, "", FieldType::Bool);
                break;
            }
        }

        return true;
    }

} // namespace dumper::stages::highlight

REGISTER_STAGE(highlight)
