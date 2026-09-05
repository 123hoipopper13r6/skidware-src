#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include "process/memory/memory.h"
#include <spdlog/spdlog.h>

namespace dumper::stages::animation {

    struct AnimationData {
        std::string name;
        uintptr_t address;
        bridge::AnimationProperty props;
    };

    static auto get_animation_data(const bridge::AnimationPropertiesInfo& props)
        -> std::optional<std::vector<AnimationData>> {
        std::vector<AnimationData> animation_data;

        auto animations_folder = dumper::g_workspace->find_first_child("Animations");
        if (!animations_folder->is_valid()) {
            spdlog::error("Failed to find Animations folder");
            return std::nullopt;
        }

        for (const auto& prop : props.animations) {
            const auto anim = animations_folder->find_first_child(prop.name);
            if (!anim->is_valid()) {
                spdlog::error("Failed to find animation: {}", prop.name);
                return std::nullopt;
            }

            AnimationData data{.name = prop.name, .address = anim->get_address(), .props = prop};

            animation_data.push_back(data);
        }

        return animation_data;
    }

    auto dump() -> bool {
        const auto anim_props = bridge::g_bridge.read_animations_information();
        if (!anim_props) {
            spdlog::error("Failed to get animation properties from bridge");
            return false;
        }

        if (anim_props->animations.size() < 3) {
            spdlog::error("Not enough animations found (need at least 3)");
            return false;
        }

        const auto animations = get_animation_data(*anim_props);
        if (!animations) {
            return false;
        }

        std::optional<size_t> animation_id_offset;
        for (const auto& a : *animations) {
            const auto off = process::helpers::find_sso_string_offset(
                a.address, a.props.animation_id, 0x800, 0x8, true);
            if (!off || (animation_id_offset && *animation_id_offset != *off)) {
                animation_id_offset.reset();
                break;
            }
            animation_id_offset = off;
        }

        if (animation_id_offset)
            g_dumper.add_offset("Animation", "AnimationId", *animation_id_offset);
        else
            spdlog::error("Failed to find Animation AnimationId offset");

        return true;
    }

} // namespace dumper::stages::animation

REGISTER_STAGE(animation)