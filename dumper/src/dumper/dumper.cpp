#include "dumper.h"
#include "bridge/bridge.h"
#include "process/memory/memory.h"
#include "stages/data_model/data_model.h"
#include "stages/instance/instance.h"
#include "stages/player/player.h"
#include "stages/property_descriptors/property_descriptors.h"
#include "stages/registry.h"
#include "stages/value/value.h"
#include "stages/visual_engine/visual_engine.h"
#include "stages/workspace/workspace.h"
#include <cctype>
#include <cstring>
#include <fstream>
#include <functional>
#include <spdlog/spdlog.h>
#include <thread>
#include <vector>

namespace dumper {

    // synthesize a human-readable description from a hungarian/camelCase offset
    // name so every emitted offset carries at least a basic explanation
    static auto describe_name(const std::string& name) -> std::string {
        static const char* prefixes[] = {"lp",   "dw",   "sz",    "str",  "rel", "qw",
                                         "enm",  "ch",   "fp",    "vec2", "vec3",
                                         "udim", "cframe", "f2",  "b",    "i",
                                         "u",    "n",    "e",     "c",    "p",   "f"};
        std::string core = name;
        for (const auto* p : prefixes) {
            const size_t len = std::strlen(p);
            if (core.size() > len + 1 && core.compare(0, len, p) == 0 &&
                core[len] >= 'A' && core[len] <= 'Z') {
                core = core.substr(len);
                break;
            }
        }
        std::string out;
        for (size_t i = 0; i < core.size(); i++) {
            const char c = core[i];
            if (c == '_') {
                out += ' ';
                continue;
            }
            const bool prev_lower =
                i > 0 && std::islower(static_cast<unsigned char>(core[i - 1]));
            const bool prev_digit =
                i > 0 && std::isdigit(static_cast<unsigned char>(core[i - 1]));
            const bool next_lower =
                i + 1 < core.size() && std::islower(static_cast<unsigned char>(core[i + 1]));
            if ((prev_lower || prev_digit) && std::isupper(static_cast<unsigned char>(c)))
                out += ' ';
            else if (i > 0 && std::isupper(static_cast<unsigned char>(c)) &&
                     std::isupper(static_cast<unsigned char>(core[i - 1])) && next_lower)
                out += ' ';
            out += c;
        }
        if (!out.empty())
            out[0] = static_cast<char>(
                std::toupper(static_cast<unsigned char>(out[0])));
        return out;
    }

    Dumper::~Dumper() {}

    auto Dumper::start() -> bool {
        spdlog::info("Dumper starting.\n");

        // human-readable descriptions shown as section comments in the output files
        const std::unordered_map<std::string, std::string> ns_comments = {
            {"FakeDataModel", "global entry: *(module + Pointer) = FakeDataModel"},
            {"DataModel", "root game object (place/session info)"},
            {"Instance", "base of every Roblox object"},
            {"Workspace", "3D world container"},
            {"World", "physics simulation container (gravity, sim rate, primitives)"},
            {"AirProperties", "per-workspace wind/air physics"},
            {"Primitive", "per-part physics data (cframe, velocity, size)"},
            {"BasePart", "part instance (aliases into Primitive)"},
            {"PrimitiveFlags", "physics behavior bitfield (anchored/collide/touch/query)"},
            {"Humanoid", "character controller (walk speed, jump, state)"},
            {"Player", "local player info"},
            {"Camera", "view camera"},
            {"Lighting", "lighting/atmosphere settings"},
            {"TaskScheduler", "frame scheduler (fps cap, job list)"},
            {"VisualEngine", "renderer root (view matrix, render view)"},
            {"RenderView", "render target info"},
            {"Sound", "sound instance playback props"},
            {"ClickDetector", "click interaction"},
            {"Attachment", "attach point on a part"},
            {"Decal", "texture on a face"},
            {"Motor6D", "joint between two parts (animation bones)"},
            {"Shirt", "shirt template content"},
            {"Pants", "pants template content"},
            {"Light", "point/surface light source"},
            {"SpotLight", "cone light source"},
            {"Fire", "fire particle effect"},
            {"Explosion", "explosion effect"},
            {"ParticleEmitter", "particle effect emitter"},
            {"SpawnLocation", "player spawn point"},
            {"ImageLabel", "GUI image element"},
            {"LinearVelocity", "physics velocity constraint"},
            {"BoolValue", "bool container"},
            {"IntValue", "int container"},
            {"NumberValue", "double container"},
            {"StringValue", "string container"},
            {"Vector3Value", "vector3 container"},
            {"CFrameValue", "cframe container"},
            {"Highlight", "selection highlight effect"},
            {"Animation", "animation asset reference"},
            {"Team", "team definition"},
            {"ProximityPrompt", "interact prompt"}};
        for (const auto& [ns, c] : ns_comments)
            set_namespace_comment(ns, c);

        // per-offset human descriptions (appended to output file comments)
        const std::unordered_map<std::string, std::string> descriptions = {
            // DataModel / core
            {"DataModel::PlaceId", "ID of the current place"},
            {"DataModel::GameId", "ID of the universe (game) this place belongs to"},
            {"DataModel::CreatorId", "user/group ID of the game creator"},
            {"DataModel::JobId", "server session ID (unique per server join)"},
            {"DataModel::GameLoaded", "non-zero once the place finished loading"},
            {"DataModel::ServerIP", "game server IP as \"ip|port\" string"},
            {"DataModel::Workspace", "pointer to the Workspace service"},
            {"FakeDataModel::RealDataModel", "offset of the real DataModel pointer inside FakeDataModel"},
            {"Instance::Parent", "pointer to the parent instance"},
            {"Instance::NameContainer", "pointer to this instance's name string object"},
            {"Instance::Name", "offset of the name chars inside the name container"},
            {"Instance::ClassDescriptor", "pointer to RTTI class descriptor (per-class static)"},
            {"ClassDescriptor::ClassName", "class name string (e.g. \"Part\")"},
            {"Instance::ChildrenStart", "children vector: array-of-slots pointer"},
            {"Instance::ChildrenEnd", "one-past-end marker inside the children array"},
            {"Instance::AttributeContainer", "pointer to per-instance attribute storage"},
            {"AttributeContainer::Number", "number attribute payload inside attribute storage"},
            {"AttributeContainer::String", "string attribute payload inside attribute storage"},
            // Workspace / physics
            {"Workspace::CurrentCamera", "pointer to the active Camera"},
            {"Workspace::ReadOnlyGravity", "cached gravity value (studs/s^2)"},
            {"Workspace::World", "pointer to the physics World"},
            {"World::Gravity", "live gravity used by the solver (write to change fall speed)"},
            {"World::PhysicsFps", "target physics rate in Hz; writing changes sim speed; +0x4 = dt = 1/fps"},
            {"World::Primitives", "array of every Primitive in the world"},
            {"World::AirProperties", "air density / global wind container"},
            {"AirProperties::GlobalWind", "wind vector applied to unanchored parts"},
            {"AirProperties::AirDensity", "air density for drag calculations"},
            // Primitive / BasePart
            {"Primitive::CFrame", "full rotation matrix + position of the part"},
            {"Primitive::Position", "world position (translation part of CFrame)"},
            {"Primitive::Size", "part dimensions in studs"},
            {"Primitive::Material", "material enum value"},
            {"Primitive::AssemblyLinearVelocity", "linear velocity of the assembly (studs/s)"},
            {"Primitive::AssemblyAngularVelocity", "angular velocity of the assembly (rad/s)"},
            {"Primitive::Part", "back-pointer from Primitive to its BasePart"},
            {"BasePart::Primitive", "pointer from BasePart to its physics Primitive"},
            {"BasePart::Velocity", "convenience alias: Primitive->AssemblyLinearVelocity"},
            {"BasePart::AngularVelocity", "convenience alias: Primitive->AssemblyAngularVelocity"},
            {"PrimitiveFlags::Anchored", "bit: part is immovable"},
            {"PrimitiveFlags::CanCollide", "bit: part participates in collisions"},
            {"PrimitiveFlags::CanTouch", "bit: part fires Touched events"},
            {"PrimitiveFlags::CanQuery", "bit: part is hit by raycasts"},
            // Humanoid
            {"Humanoid::Health", "current health"},
            {"Humanoid::MaxHealth", "maximum health"},
            {"Humanoid::WalkSpeed", "movement speed in studs/s (write to change speed)"},
            {"Humanoid::WalkSpeedCheck", "duplicate WalkSpeed cache used by engine checks"},
            {"Humanoid::JumpPower", "jump impulse strength (legacy mode)"},
            {"Humanoid::JumpHeight", "jump height in studs (modern mode)"},
            {"Humanoid::HipHeight", "distance of torso above the ground"},
            {"Humanoid::MaxSlopeAngle", "steepest walkable slope in degrees"},
            {"Humanoid::AutoRotate", "whether the humanoid turns to face movement direction"},
            {"Humanoid::PlatformStand", "when true the humanoid ignores input (ragdoll-ish)"},
            {"Humanoid::Sit", "whether the humanoid is seated"},
            {"Humanoid::UseJumpPower", "true = use JumpPower, false = use JumpHeight"},
            {"Humanoid::Jump", "jump trigger flag (set true to force a jump)"},
            {"Humanoid::CameraOffset", "camera offset relative to the humanoid head"},
            {"Humanoid::TargetPoint", "current MoveTo target point"},
            {"Humanoid::WalkToPoint", "walk target point (same as TargetPoint usually)"},
            {"Humanoid::MoveDirection", "unit vector of current walk direction"},
            {"Humanoid::RootPart", "pointer to HumanoidRootPart"},
            {"Humanoid::SeatPart", "pointer to the seat being sat on (null if standing)"},
            {"Humanoid::DisplayName", "name shown above the character"},
            {"Humanoid::RequiresNeck", "humanoid dies without a Neck joint when true"},
            {"Humanoid::BreakJointsOnDeath", "joints break on death when true"},
            {"Humanoid::EvaluateStateMachine", "engine state machine enabled"},
            {"Humanoid::AutoJumpEnabled", "auto-jump on obstacles (mobile style)"},
            {"Humanoid::AutomaticScalingEnabled", "auto-scale animations to body proportions"},
            {"Humanoid::HealthDisplayDistance", "max distance at which health bar shows"},
            {"Humanoid::NameDisplayDistance", "max distance at which name shows"},
            {"Humanoid::HealthDisplayType", "when the health bar is displayed"},
            {"Humanoid::NameOcclusion", "name occlusion behaviour behind walls"},
            {"Humanoid::RigType", "R6 or R15 skeleton"},
            // Player
            {"Players::LocalPlayer", "pointer to the local player"},
            {"Player::Character", "pointer to the player's character model"},
            {"Player::UserId", "account user ID"},
            {"Player::AccountAge", "account age in days"},
            {"Player::DisplayName", "display name string"},
            {"Player::LocaleId", "locale string (e.g. en-us)"},
            {"Player::Team", "pointer to current Team"},
            {"Player::TeamColor", "BrickColor enum of the team"},
            {"Player::CameraMaxZoomDistance", "max camera zoom-out distance"},
            {"Player::CameraMinZoomDistance", "min camera zoom-in distance"},
            {"Player::HealthDisplayDistance", "health bar visibility distance"},
            {"Player::NameDisplayDistance", "name visibility distance"},
            // Camera
            {"Camera::FieldOfView", "field of view in degrees (stored as radians here)"},
            {"Camera::CFrame", "camera position + rotation"},
            {"Camera::Position", "camera world position"},
            {"Camera::CameraSubject", "instance the camera follows"},
            {"Camera::ViewportSize", "viewport size in pixels"},
            // Lighting
            {"Lighting::Brightness", "light brightness multiplier"},
            {"Lighting::ClockTime", "time of day in seconds since midnight * 1000000"},
            {"Lighting::FogColor", "fog color"},
            {"Lighting::FogStart", "distance where fog starts"},
            {"Lighting::FogEnd", "distance where fog is fully opaque"},
            {"TaskScheduler::MaxFps", "frame cap as frame-time double (1/fps); write smaller value for higher cap"},
            // Values
            {"Value::Value", "generic ValueBase payload offset"},
            {"BoolValue::Value", "the bool payload"},
            {"IntValue::Value", "the int payload"},
            {"NumberValue::Value", "the double payload"},
            {"StringValue::Value", "SSO string payload offset"},
            {"Vector3Value::Value", "vector3 payload"},
            {"CFrameValue::Value", "cframe translation payload"},
            // Extras
            {"Sound::Volume", "volume 0-10"},
            {"Sound::PlaybackSpeed", "pitch/speed multiplier (1 = normal)"},
            {"Sound::MaxDistance", "audible range in studs"},
            {"Sound::RollOffMinDistance", "distance where volume rolloff begins"},
            {"Sound::Looped", "restart when finished"},
            {"Attachment::Position", "attachment offset from its parent part center"},
            {"ClickDetector::MaxActivationDistance", "max click range in studs"},
            {"Decal::Transparency", "0 = opaque, 1 = invisible"},
            {"Motor6D::C0Container", "pointer to joint coordinate sub-structure"},
            {"Motor6D::C0", "joint offset on Part0 (translation)"},
            {"Motor6D::C1", "joint offset on Part1 (translation)"},
            {"LinearVelocity::MaxForce", "force cap of the constraint"},
            {"LinearVelocity::VectorVelocity", "target velocity vector"},
            {"ParticleEmitter::Rate", "particles spawned per second"},
            {"ParticleEmitter::Enabled", "emitter active flag"},
            {"Fire::Size", "fire effect size"},
            {"Fire::Heat", "fire heat intensity"},
            {"Explosion::BlastRadius", "explosion radius in studs"},
            {"Explosion::BlastPressure", "force applied to parts"},
            {"SpawnLocation::Duration", "forcefield duration on spawn"},
            {"SpawnLocation::Neutral", "usable by any team"},
            {"ImageLabel::ImageTransparency", "0 = opaque image"},
            {"ImageLabel::ImageColor3", "image tint color"},
            {"Team::TeamColor", "BrickColor enum of the team"},
            {"Highlight::Adornee", "instance being highlighted"},
            {"Highlight::FillColor", "highlight fill color"},
            {"Highlight::OutlineColor", "highlight outline color"},
            // Text labels / buttons / boxes (shared GuiObject text layout)
            {"TextLabel::Text", "the rendered text (SSO string)"},
            {"TextLabel::ContentText", "raw text content before rich-text processing"},
            {"TextLabel::LocalizedText", "localized text variant"},
            {"TextLabel::Font", "font enum value"},
            {"TextLabel::TextColor3", "text color"},
            {"TextLabel::TextStrokeColor3", "outline stroke color"},
            {"TextLabel::TextStrokeTransparency", "0 = solid stroke, 1 = off"},
            {"TextLabel::TextTransparency", "0 = opaque text, 1 = invisible"},
            {"TextLabel::TextScaled", "true = scale text to fill the element"},
            {"TextLabel::TextSize", "font size in points when not scaled"},
            {"TextLabel::LineHeight", "line height multiplier"},
            {"TextLabel::MaxVisibleGraphemes", "grapheme reveal limit (-1 = all)"},
            {"TextLabel::RichText", "rich text markup enabled"},
            {"TextLabel::TextTruncate", "truncation mode (none/end/middle)"},
            {"TextLabel::TextWrapped", "wrap text at element bounds"},
            {"TextLabel::TextXAlignment", "horizontal alignment (0 left 1 right 2 center)"},
            {"TextLabel::TextYAlignment", "vertical alignment (0 top 1 bottom 2 center)"},
            {"TextLabel::TextDirection", "text direction (auto/left-to-right/right-to-left)"},
        };
        for (const auto& [key, desc] : descriptions)
            m_offset_descriptions[key] = desc;

        if (!stages::visual_engine::dump()) {
            spdlog::error("Failed to dump VisualEngine (continuing)");
        }

        if (!stages::data_model::dump_ptr()) {
            spdlog::error("Failed to find DataModel pointer");
            return false;
        }

        if (!stages::instance::dump()) {
            spdlog::error("Failed to dump Instance");
            return false;
        }

        g_data_model = roblox::Instance(g_data_model_addr);

        if (!stages::value::dump()) {
            spdlog::error("Failed to dump Value offset (continuing)");
        }

        const auto bridge_ok = bridge::g_bridge.initialize();
        if (!bridge_ok) {
            spdlog::error("Failed to initialize bridge (continuing without bridge data)");
        }

        stages::workspace::dump();

        if (bridge_ok) {
            if (!stages::data_model::dump()) {
                spdlog::error("Failed to dump DataModel");
            }

            if (!stages::player::dump()) {
                spdlog::error("Failed to dump Player");
            }
        }

        g_data_model = roblox::Instance(g_data_model_addr);
        g_lighting = g_data_model.find_first_child_of_class("Lighting");
        g_workspace = g_data_model.find_first_child_of_class("Workspace");

        // build the instance name index ONCE for all stages
        {
            size_t visited = 0;
            std::function<void(const roblox::Instance&, int)> walk =
                [&](const roblox::Instance& inst, int depth) {
                    if (depth > 6 || visited > 60000)
                        return;
                    ++visited;
                    if ((visited % 2000) == 0)
                        spdlog::info("Instance index: {} nodes...", visited);
                    if (auto n = inst.get_name())
                        g_dumper.m_workspace_index.emplace(*n, inst.get_address());
                    for (const auto& c : inst.get_children())
                        walk(c, depth + 1);
                };
            if (g_workspace)
                walk(*g_workspace, 0);
            if (auto rs = g_data_model.find_first_child_of_class("ReplicatedStorage"))
                walk(*rs, 0);
            spdlog::info("Instance index: {} entries ({} visited)",
                         m_workspace_index.size(), visited);
        }

        if (!stages::property_descriptors::dump()) {
            spdlog::error("Failed to dump PropertyDescriptors");
        }

        std::vector<std::thread> threads;
        for (const auto& stage : stages::g_stage_registry) {
            threads.emplace_back([&stage]() {
                if (!stage.dump()) {
                    spdlog::error("Failed to dump {}", stage.name);
                }
            });
        }

        for (auto& thread : threads) {
            thread.join();
        }

        return true;
    }

    auto Dumper::add_offset(const std::string& namespace_name, const std::string& offset_name,
                            size_t offset, const std::string& comment, FieldType type) -> void {
        std::lock_guard<std::mutex> lock(m_offset_mutex);
        m_offsets[namespace_name].push_back({offset_name, offset, comment, type});
        // every offset gets at least a synthesized human description
        m_offset_descriptions.emplace(namespace_name + "::" + offset_name,
                                      describe_name(offset_name));
        const std::string via = comment.empty() ? "" : " - via " + comment;
        spdlog::info("Added offset: {}::{} = 0x{:X} [{}]{}", namespace_name, offset_name, offset,
                     field_type_name(type), via);
    }

    auto Dumper::add_enum(const std::string& enum_name, const std::string& entry_name, int value)
        -> void {
        std::lock_guard<std::mutex> lock(m_offset_mutex);
        m_enums[enum_name].push_back({entry_name, value});
    }

    auto Dumper::set_namespace_comment(const std::string& namespace_name,
                                       const std::string& comment) -> void {
        std::lock_guard<std::mutex> lock(m_offset_mutex);
        m_namespace_comments[namespace_name] = comment;
    }

    auto Dumper::get_offset(const std::string& namespace_name, const std::string& offset_name) const
        -> std::optional<size_t> {
        std::lock_guard<std::mutex> lock(m_offset_mutex);
        auto it = m_offsets.find(namespace_name);
        if (it == m_offsets.end()) {
            return std::nullopt;
        }

        std::optional<size_t> fallback;

        for (const auto& entry : it->second) {
            if (entry.name != offset_name)
                continue;
            // prefer scanned/verified values over getter-decoded duplicates
            // (stages run in parallel; both may briefly coexist)
            if (entry.comment != "decoded from property getter")
                return entry.offset;
            fallback = entry.offset;
        }

        return fallback;
    }

} // namespace dumper
