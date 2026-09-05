#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

namespace bridge {
    using json = nlohmann::json;

    struct DataModelInfo {
        uint64_t place_id;
        uint64_t game_id;
        uint64_t creator_id;
        std::string job_id;
    };

    struct WorkspaceInfo {
        uint32_t children_count;
        float gravity;
    };

    struct PlayerInfo {
        uint64_t user_id;
        uint32_t account_age;
        std::string display_name;
        std::string locale_id;
        float camera_max_zoom;
        float camera_min_zoom;
    };

    struct PartProperty {
        std::string name;
        bool anchored;
        bool can_collide;
        bool can_touch;
        bool cast_shadow;
        bool locked;
        bool massless;

        float pos_x, pos_y, pos_z;
        float rotation_x, rotation_y, rotation_z;
        float size_x, size_y, size_z;
        float transparency;
        float reflectance;

        float vel_x, vel_y, vel_z;
        float angvel_x, angvel_y, angvel_z;
        float center_of_mass_x, center_of_mass_y, center_of_mass_z;

        float attr_num;
        std::string attr_str;

        uint8_t color_r, color_g, color_b;

        uint16_t material;
        uint8_t shape;
    };

    struct PartPropertiesInfo {
        std::vector<PartProperty> parts;
    };

    struct HumanoidProperty {
        std::string name;
        std::string display_name;
        float health;
        float max_health;
        float walk_speed;
        float jump_power;
        float jump_height;
        float hip_height;
        float max_slope_angle;
        float health_display_distance;
        float name_display_distance;

        bool auto_jump_enabled;
        bool automatic_scaling_enabled;
        bool auto_rotate;
        bool break_joints_on_death;
        bool evaluate_state_machine;
        bool jump;
        bool requires_neck;
        bool sit;
        bool platform_stand;
        bool use_jump_power;

        float camera_offset_x, camera_offset_y, camera_offset_z;
        float target_point_x, target_point_y, target_point_z;
        float walk_to_point_x, walk_to_point_y, walk_to_point_z;
        float move_dir_x, move_dir_y, move_dir_z;

        uint8_t rig_type;
        uint8_t display_distance_type;
        uint8_t health_display_type;
        uint8_t name_occlusion;
    };

    struct HumanoidPropertiesInfo {
        std::vector<HumanoidProperty> humanoids;
    };

    struct ViewportInfo {
        float viewport_width;
        float viewport_height;
    };

    struct FrameProperty {
        std::string name;
        bool active;
        float anchor_point_x, anchor_point_y;
        uint8_t automatic_size;
        float background_color_r, background_color_g, background_color_b;
        float background_transparency;
        float border_color_r, border_color_g, border_color_b;
        uint8_t border_mode;
        int32_t border_size_pixel;
        bool clips_descendants;
        uint8_t gui_state;
        bool interactable;
        int32_t layout_order;
        float position_x_scale, position_x_offset, position_y_scale, position_y_offset;
        float rotation;
        bool selectable;
        int32_t selection_order;
        float size_x_scale, size_x_offset, size_y_scale, size_y_offset;
        uint8_t size_constraint;
        bool visible;
        int32_t z_index;
    };

    struct FramePropertiesInfo {
        std::vector<FrameProperty> frames;
    };

    struct FrameAbsoluteProperty {
        std::string name;
        float absolute_rotation;
        float absolute_size_x, absolute_size_y;
    };

    struct FrameAbsolutesInfo {
        std::vector<FrameAbsoluteProperty> frames;
    };

    struct CharacterMeshProperty {
        std::string name;
        uint8_t body_part;
        uint64_t base_texture_id;
        uint64_t mesh_id;
        uint64_t overlay_texture_id;
    };

    struct CharacterMeshPropertiesInfo {
        std::vector<CharacterMeshProperty> meshes;
    };

    struct ToolProperty {
        std::string name;
        bool can_be_dropped;
        bool enabled;
        bool manual_activation_only;
        bool requires_handle;
        float grip_pos_x, grip_pos_y, grip_pos_z;
        float grip_forward_x, grip_forward_y, grip_forward_z;
        float grip_right_x, grip_right_y, grip_right_z;
        float grip_up_x, grip_up_y, grip_up_z;
        std::string tool_tip;
    };

    struct ToolPropertiesInfo {
        std::vector<ToolProperty> tools;
    };

    struct ProximityPromptProperty {
        std::string name;
        std::string action_text;
        std::string object_text;
        bool auto_localize;
        bool clickable_prompt;
        bool enabled;
        bool requires_line_of_sight;
        uint8_t exclusivity;
        uint32_t gamepad_key_code;
        uint32_t keyboard_key_code;
        float hold_duration;
        float max_activation_distance;
        float max_indicator_distance;
        uint8_t style;
        float ui_offset_x;
        float ui_offset_y;
    };

    struct ProximityPromptPropertiesInfo {
        std::vector<ProximityPromptProperty> prompts;
    };

    struct TextLabelProperty {
        std::string name;
        std::string content_text;
        uint32_t font;
        uint32_t font_size;
        float line_height;
        std::string localized_text;
        int32_t max_visible_graphemes;
        std::string open_type_features;
        std::string open_type_features_error;
        bool rich_text;
        std::string text;
        float text_bounds_x, text_bounds_y;
        uint8_t text_color_r, text_color_g, text_color_b;
        uint8_t text_direction;
        bool text_fits;
        bool text_scaled;
        float text_size;
        uint8_t text_stroke_color_r, text_stroke_color_g, text_stroke_color_b;
        float text_stroke_transparency;
        float text_transparency;
        uint8_t text_truncate;
        bool text_wrapped;
        uint8_t text_x_alignment;
        uint8_t text_y_alignment;
    };

    struct TextLabelPropertiesInfo {
        std::vector<TextLabelProperty> text_labels;
    };

    struct TextButtonProperty {
        std::string name;
        std::string content_text;
        uint32_t font;
        uint32_t font_size;
        float line_height;
        std::string localized_text;
        int32_t max_visible_graphemes;
        std::string open_type_features;
        std::string open_type_features_error;
        bool rich_text;
        std::string text;
        float text_bounds_x, text_bounds_y;
        uint8_t text_color_r, text_color_g, text_color_b;
        uint8_t text_direction;
        bool text_fits;
        bool text_scaled;
        float text_size;
        uint8_t text_stroke_color_r, text_stroke_color_g, text_stroke_color_b;
        float text_stroke_transparency;
        float text_transparency;
        uint8_t text_truncate;
        bool text_wrapped;
        uint8_t text_x_alignment;
        uint8_t text_y_alignment;
        bool auto_button_color;
        bool modal;
        bool selected;
    };

    struct TextButtonPropertiesInfo {
        std::vector<TextButtonProperty> text_buttons;
    };

    struct HighlightProperty {
        std::string name;
        uint8_t depth_mode;
        bool enabled;
        uint8_t fill_color_r, fill_color_g, fill_color_b;
        float fill_transparency;
        uint8_t outline_color_r, outline_color_g, outline_color_b;
        float outline_transparency;
    };

    struct HighlightPropertiesInfo {
        std::vector<HighlightProperty> highlights;
    };

    struct AnimationProperty {
        std::string name;
        std::string animation_id;
    };

    struct AnimationPropertiesInfo {
        std::vector<AnimationProperty> animations;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(DataModelInfo, place_id, game_id, creator_id, job_id)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(WorkspaceInfo, children_count, gravity)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(PlayerInfo, user_id, account_age, display_name, locale_id,
                                       camera_max_zoom, camera_min_zoom)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(PartProperty, name, anchored, can_collide, can_touch,
                                       cast_shadow, locked, massless, shape, pos_x, pos_y, pos_z,
                                       rotation_x, rotation_y, rotation_z, size_x, size_y, size_z,
                                       color_r, color_g, color_b, transparency, reflectance,
                                       material, vel_x, vel_y, vel_z, angvel_x, angvel_y,
                                       angvel_z, center_of_mass_x, center_of_mass_y,
                                       center_of_mass_z, attr_num, attr_str)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(PartPropertiesInfo, parts)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        HumanoidProperty, name, display_name, health, max_health, walk_speed, jump_power,
        jump_height, hip_height, max_slope_angle, health_display_distance,
        name_display_distance, auto_jump_enabled, automatic_scaling_enabled, auto_rotate,
        break_joints_on_death, evaluate_state_machine, jump, requires_neck, sit,
        platform_stand, use_jump_power,
        camera_offset_x, camera_offset_y, camera_offset_z, target_point_x, target_point_y,
        target_point_z, walk_to_point_x, walk_to_point_y, walk_to_point_z, move_dir_x,
        move_dir_y, move_dir_z, rig_type,
        display_distance_type, health_display_type, name_occlusion)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(HumanoidPropertiesInfo, humanoids)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ViewportInfo, viewport_width, viewport_height)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(FrameProperty, name, active, anchor_point_x, anchor_point_y,
                                       automatic_size, background_color_r, background_color_g,
                                       background_color_b, background_transparency, border_color_r,
                                       border_color_g, border_color_b, border_mode,
                                       border_size_pixel, clips_descendants, gui_state,
                                       interactable, layout_order, position_x_scale,
                                       position_x_offset, position_y_scale, position_y_offset,
                                       rotation, selectable, selection_order, size_x_scale,
                                       size_x_offset, size_y_scale, size_y_offset, size_constraint,
                                       visible, z_index)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(FramePropertiesInfo, frames)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(FrameAbsoluteProperty, name, absolute_rotation,
                                       absolute_size_x, absolute_size_y)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(FrameAbsolutesInfo, frames)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(CharacterMeshProperty, name, body_part, base_texture_id,
                                       mesh_id, overlay_texture_id)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(CharacterMeshPropertiesInfo, meshes)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ToolProperty, name, can_be_dropped, enabled,
                                       manual_activation_only, requires_handle, grip_pos_x,
                                       grip_pos_y, grip_pos_z, grip_forward_x, grip_forward_y,
                                       grip_forward_z, grip_right_x, grip_right_y, grip_right_z,
                                       grip_up_x, grip_up_y, grip_up_z, tool_tip)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ToolPropertiesInfo, tools)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ProximityPromptProperty, name, action_text, object_text,
                                       auto_localize, clickable_prompt, enabled,
                                       requires_line_of_sight, exclusivity, gamepad_key_code,
                                       keyboard_key_code, hold_duration, max_activation_distance,
                                       max_indicator_distance, style, ui_offset_x, ui_offset_y)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ProximityPromptPropertiesInfo, prompts)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TextLabelProperty, name, content_text, font, font_size,
                                       line_height, localized_text, max_visible_graphemes,
                                       open_type_features, open_type_features_error, rich_text,
                                       text, text_bounds_x, text_bounds_y, text_color_r,
                                       text_color_g, text_color_b, text_direction, text_fits,
                                       text_scaled, text_size, text_stroke_color_r,
                                       text_stroke_color_g, text_stroke_color_b,
                                       text_stroke_transparency, text_transparency, text_truncate,
                                       text_wrapped, text_x_alignment, text_y_alignment)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TextLabelPropertiesInfo, text_labels)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        TextButtonProperty, name, content_text, font, font_size, line_height, localized_text,
        max_visible_graphemes, open_type_features, open_type_features_error, rich_text, text,
        text_bounds_x, text_bounds_y, text_color_r, text_color_g, text_color_b, text_direction,
        text_fits, text_scaled, text_size, text_stroke_color_r, text_stroke_color_g,
        text_stroke_color_b, text_stroke_transparency, text_transparency, text_truncate,
        text_wrapped, text_x_alignment, text_y_alignment, auto_button_color, modal, selected)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TextButtonPropertiesInfo, text_buttons)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(HighlightProperty, name, depth_mode, enabled, fill_color_r,
                                       fill_color_g, fill_color_b, fill_transparency,
                                       outline_color_r, outline_color_g, outline_color_b,
                                       outline_transparency)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(HighlightPropertiesInfo, highlights)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AnimationProperty, name, animation_id)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AnimationPropertiesInfo, animations)

    struct SoundProperty {
        std::string name;
        float volume;
        float playback_speed;
        float max_distance;
        float rolloff_min;
        bool looped;
    };

    struct AttachmentProperty {
        std::string name;
        float pos_x, pos_y, pos_z;
    };

    struct ClickDetectorProperty {
        std::string name;
        float max_activation_distance;
    };

    struct DecalProperty {
        std::string name;
        float transparency;
    };

    struct MotorProperty {
        std::string name;
        float c0_x, c0_y, c0_z;
    };

    struct ClothesProperty {
        std::string name;
        std::string template_id;
    };

    struct LightProperty {
        std::string name;
        std::string class_name;
        float brightness;
        int32_t range;
        float angle;
    };

    struct FireProperty {
        std::string name;
        float size;
        float heat;
    };

    struct ExplosionProperty {
        std::string name;
        float blast_radius;
        float blast_pressure;
    };

    struct ParticleEmitterProperty {
        std::string name;
        float rate;
        bool enabled;
    };

    struct SpawnLocationProperty {
        std::string name;
        bool neutral;
        float duration;
    };

    struct ImageLabelProperty {
        std::string name;
        float image_transparency;
        uint8_t color_r, color_g, color_b;
    };

    struct LinearVelocityProperty {
        std::string name;
        float max_force;
        float vel_x, vel_y, vel_z;
    };

    struct ValueProperty {
        std::string name;
        std::string class_name;
        bool bool_value;
        int32_t int_value;
        double number_value;
        std::string string_value;
        float vec_x, vec_y, vec_z;
        float cf_x, cf_y, cf_z;
    };

    struct PropsInfo {
        std::vector<SoundProperty> sounds;
        std::vector<AttachmentProperty> attachments;
        std::vector<ClickDetectorProperty> click_detectors;
        std::vector<DecalProperty> decals;
        std::vector<MotorProperty> motors;
        std::vector<ClothesProperty> clothes;
        std::vector<LightProperty> lights;
        std::vector<FireProperty> fires;
        std::vector<ExplosionProperty> explosions;
        std::vector<ParticleEmitterProperty> particle_emitters;
        std::vector<SpawnLocationProperty> spawn_locations;
        std::vector<ImageLabelProperty> image_labels;
        std::vector<LinearVelocityProperty> linear_velocities;
        std::vector<ValueProperty> values;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(SoundProperty, name, volume, playback_speed,
                                       max_distance, rolloff_min, looped)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AttachmentProperty, name, pos_x, pos_y, pos_z)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ClickDetectorProperty, name, max_activation_distance)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(DecalProperty, name, transparency)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MotorProperty, name, c0_x, c0_y, c0_z)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ClothesProperty, name, template_id)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(LightProperty, name, class_name, brightness, range,
                                       angle)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(FireProperty, name, size, heat)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ExplosionProperty, name, blast_radius, blast_pressure)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ParticleEmitterProperty, name, rate, enabled)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(SpawnLocationProperty, name, neutral, duration)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ImageLabelProperty, name, image_transparency, color_r,
                                       color_g, color_b)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(LinearVelocityProperty, name, max_force, vel_x, vel_y,
                                       vel_z)
    // WITH_DEFAULT: older ControlListener builds may send fewer keys per entry
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(
        ValueProperty, name, class_name, bool_value, int_value,
        number_value, string_value, vec_x, vec_y, vec_z, cf_x, cf_y, cf_z)
    // WITH_DEFAULT: older ControlListener builds may not send newer arrays yet;
    // missing keys deserialize as empty vectors instead of throwing
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(
        PropsInfo, sounds, attachments, click_detectors,
        decals, motors, clothes, lights, fires, explosions,
        particle_emitters, spawn_locations, image_labels,
        linear_velocities, values)

} // namespace bridge
