#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <functional>
#include <unordered_map>
#include <spdlog/spdlog.h>

namespace dumper::stages::sound {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->sounds.empty()) {
            spdlog::warn("No sound properties from bridge");
            return false;
        }

        // extras are nested inside the anchor TestParts -> build a recursive name map
        const auto& by_name = dumper::g_dumper.m_workspace_index;

        std::vector<uintptr_t> addrs;
        for (const auto& s : props->sounds) {
            const auto it = by_name.find(s.name);
            if (it != by_name.end())
                addrs.push_back(it->second);
        }

        if (addrs.size() < 3) {
            spdlog::warn("Not enough Sound instances found ({})", addrs.size());
            return false;
        }

        const auto path = "DataModel>Workspace>TestPartN>SkidSoundN";

        const std::pair<const char*, size_t> float_props[] = {
            {"Volume", 0}, {"PlaybackSpeed", 1}, {"MaxDistance", 2}, {"RollOffMinDistance", 3}};

        for (const auto& [name, idx] : float_props) {
            const auto offset = process::helpers::find_offset_with_getter<float>(
                addrs,
                [&](size_t i) -> float {
                    const auto& s = (*props).sounds[i];
                    switch (idx) {
                        case 0: return s.volume;
                        case 1: return s.playback_speed;
                        case 2: return s.max_distance;
                        default: return s.rolloff_min;
                    }
                },
                0x800, 0x4);

            if (!offset) {
                spdlog::warn("Sound::{} not found (continuing)", name);
                continue;
            }
            g_dumper.add_offset("Sound", name, *offset, path, FieldType::Float);
        }

        const auto looped = process::helpers::find_offset_with_getter<uint8_t>(
            addrs, [&](size_t i) { return (*props).sounds[i].looped ? 1 : 0; }, 0x800, 0x1);

        if (looped) {
            g_dumper.add_offset("Sound", "Looped", *looped, path, FieldType::Bool);
        } else {
            spdlog::warn("Sound::Looped not found (continuing)");
        }

        return true;
    }

} // namespace dumper::stages::sound

REGISTER_STAGE(sound)
