#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <functional>
#include <spdlog/spdlog.h>
#include <unordered_map>

namespace dumper::stages::image_label {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->image_labels.empty()) {
            spdlog::warn("No image label properties from bridge");
            return false;
        }

        const auto& by_name = dumper::g_dumper.m_workspace_index;

        std::vector<uintptr_t> addrs;
        std::vector<const bridge::ImageLabelProperty*> entries;
        for (const auto& i : props->image_labels) {
            const auto it = by_name.find(i.name);
            if (it == by_name.end())
                continue;
            addrs.push_back(it->second);
            entries.push_back(&i);
        }
        if (addrs.empty()) {
            spdlog::warn("ImageLabel instance not found");
            return false;
        }

        const auto path = "DataModel>Workspace>SkidImage";

        // single instance: scan for the transparency float, then verify color3 floats nearby
        const float t = entries[0]->image_transparency;
        const auto trans_off = process::helpers::find_offset<float>(addrs[0], t, 0x1000, 0x4);

        if (!trans_off) {
            spdlog::warn("ImageLabel::ImageTransparency not found");
            return false;
        }

        g_dumper.add_offset("ImageLabel", "ImageTransparency", *trans_off, path,
                            FieldType::Float);

        // verify color channels as floats right after (r,g,b in 0..1)
        auto color_ok = [&](size_t off, float expected) {
            const auto v = process::Memory::read<float>(addrs[0] + off);
            return v && std::abs(*v - expected) <= 1.f / 255.f;
        };
        const float r = entries[0]->color_r / 255.f;
        const float g = entries[0]->color_g / 255.f;
        const float b = entries[0]->color_b / 255.f;

        for (size_t delta : {4, 8, 12, 16}) {
            const size_t coff = *trans_off + delta;
            if (color_ok(coff, r) && color_ok(coff + 4, g) && color_ok(coff + 8, b)) {
                g_dumper.add_offset("ImageLabel", "ImageColor3", coff, path,
                                    FieldType::Color3Float);
                break;
            }
        }

        return true;
    }

} // namespace dumper::stages::image_label

REGISTER_STAGE(image_label)
