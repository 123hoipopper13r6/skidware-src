#include "../Includes.hpp"
#include <Json.hpp>

namespace Config
{
    std::string Save()
    {
        nlohmann::json j;

        j["Watermark"] = Globals::Watermark;
        j["Notifications"] = Globals::Notifications;

        j["Esp"]["Enabled"] = Globals::Esp::Enabled;
        j["Esp"]["Box"] = Globals::Esp::Box;
        j["Esp"]["BoxGlow"] = Globals::Esp::BoxGlow;
        j["Esp"]["Name"] = Globals::Esp::Name;
        j["Esp"]["UseDisplayName"] = Globals::Esp::UseDisplayName;
        j["Esp"]["Distance"] = Globals::Esp::Distance;
        j["Esp"]["Tool"] = Globals::Esp::Tool;
        j["Esp"]["Chams"] = Globals::Esp::Chams;
        j["Esp"]["ChamsGlow"] = Globals::Esp::ChamsGlow;
        j["Esp"]["ChamsOutlines"] = Globals::Esp::ChamsOutlines;
        j["Esp"]["HealthBar"] = Globals::Esp::HealthBar;
        j["Esp"]["HealthNumber"] = Globals::Esp::HealthNumber;
        j["Esp"]["HealthBarBackGround"] = Globals::Esp::HealthBarBackGround;
        j["Esp"]["HealthBarGlow"] = Globals::Esp::HealthBarGlow;
        j["Esp"]["HealthBarColorType"] = Globals::Esp::HealthBarColorType;
        j["Esp"]["Team"] = Globals::Esp::Team;
        j["Esp"]["TeamMode"] = Globals::Esp::TeamMode;
        j["Esp"]["Leaderstats"] = Globals::Esp::Leaderstats;
        j["Esp"]["Region"] = Globals::Esp::Region;
        j["Esp"]["LocalPlayerESP"] = Globals::Esp::LocalPlayerESP;
        j["Esp"]["Font"] = Globals::Esp::Font;
        j["Esp"]["MaxDistance"] = Globals::Esp::MaxDistance;
        j["Esp"]["MaxDistanceValue"] = Globals::Esp::MaxDistanceValue;
        j["Esp"]["KeybindList"] = Globals::Esp::KeybindList;
        j["Esp"]["ChamsOutlineThickness"] = Globals::Esp::ChamsOutlineThickness;
        j["Esp"]["InheritBodyColorChams"] = Globals::Esp::InheritBodyColorChams;
        j["Esp"]["FilterUnknownChamsParts"] = Globals::Esp::FilterUnknownChamsParts;
        j["Esp"]["Tracers"] = Globals::Esp::Tracers;
        j["Esp"]["Skeleton"] = Globals::Esp::Skeleton;
        j["Esp"]["TracersPosition"] = Globals::Esp::TracersPosition;

        j["Esp"]["Colors"]["Skeleton"] = { Globals::Esp::Colors::Skeleton[0], Globals::Esp::Colors::Skeleton[1], Globals::Esp::Colors::Skeleton[2], Globals::Esp::Colors::Skeleton[3] };
        j["Esp"]["Colors"]["Tracers"] = { Globals::Esp::Colors::Tracers[0], Globals::Esp::Colors::Tracers[1], Globals::Esp::Colors::Tracers[2], Globals::Esp::Colors::Tracers[3] };
        j["Esp"]["Colors"]["Box"] = { Globals::Esp::Colors::Box[0], Globals::Esp::Colors::Box[1], Globals::Esp::Colors::Box[2], Globals::Esp::Colors::Box[3] };
        j["Esp"]["Colors"]["BoxGlow"] = { Globals::Esp::Colors::BoxGlow[0], Globals::Esp::Colors::BoxGlow[1], Globals::Esp::Colors::BoxGlow[2], Globals::Esp::Colors::BoxGlow[3] };
        j["Esp"]["Colors"]["Name"] = { Globals::Esp::Colors::Name[0], Globals::Esp::Colors::Name[1], Globals::Esp::Colors::Name[2], Globals::Esp::Colors::Name[3] };
        j["Esp"]["Colors"]["Distance"] = { Globals::Esp::Colors::Distance[0], Globals::Esp::Colors::Distance[1], Globals::Esp::Colors::Distance[2], Globals::Esp::Colors::Distance[3] };
        j["Esp"]["Colors"]["Tool"] = { Globals::Esp::Colors::Tool[0], Globals::Esp::Colors::Tool[1], Globals::Esp::Colors::Tool[2], Globals::Esp::Colors::Tool[3] };
        j["Esp"]["Colors"]["Chams"] = { Globals::Esp::Colors::Chams[0], Globals::Esp::Colors::Chams[1], Globals::Esp::Colors::Chams[2], Globals::Esp::Colors::Chams[3] };
        j["Esp"]["Colors"]["ChamsGlow"] = { Globals::Esp::Colors::ChamsGlow[0], Globals::Esp::Colors::ChamsGlow[1], Globals::Esp::Colors::ChamsGlow[2], Globals::Esp::Colors::ChamsGlow[3] };
        j["Esp"]["Colors"]["ChamsOutlines"] = { Globals::Esp::Colors::ChamsOutlines[0], Globals::Esp::Colors::ChamsOutlines[1], Globals::Esp::Colors::ChamsOutlines[2], Globals::Esp::Colors::ChamsOutlines[3] };
        j["Esp"]["Colors"]["HealthBarGlow"] = { Globals::Esp::Colors::HealthBarGlow[0], Globals::Esp::Colors::HealthBarGlow[1], Globals::Esp::Colors::HealthBarGlow[2], Globals::Esp::Colors::HealthBarGlow[3] };
        j["Esp"]["Colors"]["HealthBar"] = { Globals::Esp::Colors::HealthBar[0], Globals::Esp::Colors::HealthBar[1], Globals::Esp::Colors::HealthBar[2], Globals::Esp::Colors::HealthBar[3] };
        j["Esp"]["Colors"]["HealthNumber"] = { Globals::Esp::Colors::HealthNumber[0], Globals::Esp::Colors::HealthNumber[1], Globals::Esp::Colors::HealthNumber[2], Globals::Esp::Colors::HealthNumber[3] };
        j["Esp"]["Colors"]["Region"] = { Globals::Esp::Colors::Region[0], Globals::Esp::Colors::Region[1], Globals::Esp::Colors::Region[2], Globals::Esp::Colors::Region[3] };
        j["Esp"]["Colors"]["LeaderStats"] = { Globals::Esp::Colors::LeaderStats[0], Globals::Esp::Colors::LeaderStats[1], Globals::Esp::Colors::LeaderStats[2], Globals::Esp::Colors::LeaderStats[3] };
        j["Esp"]["Colors"]["Murderer"] = { Globals::Esp::Colors::Murderer[0], Globals::Esp::Colors::Murderer[1], Globals::Esp::Colors::Murderer[2], Globals::Esp::Colors::Murderer[3] };
        j["Esp"]["Colors"]["Sheriff"] = { Globals::Esp::Colors::Sheriff[0], Globals::Esp::Colors::Sheriff[1], Globals::Esp::Colors::Sheriff[2], Globals::Esp::Colors::Sheriff[3] };
        j["Esp"]["Colors"]["Innocent"] = { Globals::Esp::Colors::Innocent[0], Globals::Esp::Colors::Innocent[1], Globals::Esp::Colors::Innocent[2], Globals::Esp::Colors::Innocent[3] };

        j["Esp"]["Avatar"] = Globals::Esp::Avatar;
        j["Esp"]["ChamsType"] = Globals::Esp::ChamsType;
        j["Esp"]["AvatarOffset"] = Globals::Esp::OffsetOffBoxAvatar;
        j["Esp"]["AvatarSize"] = Globals::Esp::IconSize;

        j["Misc"]["TeamCheck"] = Globals::Misc::TeamCheck;

        j["Aimbot"]["Enabled"] = Globals::Aimbot::Enabled;

        j["Aimbot"]["AimbotKey"]["AimKey"] = Globals::Aimbot::AimbotKey.Save();

        j["Aimbot"]["SilentMode"] = Globals::Aimbot::SilentMode;

        j["Aimbot"]["Hitbox"] = Globals::Aimbot::Hitbox;
        j["Aimbot"]["AimType"] = Globals::Aimbot::AimType;
        j["Aimbot"]["Prediction"] = Globals::Aimbot::Prediction;
        j["Aimbot"]["PredictionX"] = Globals::Aimbot::PredictionX;
        j["Aimbot"]["PredictionY"] = Globals::Aimbot::PredictionY;
        j["Aimbot"]["EnableFOV"] = Globals::Aimbot::EnableFOV;
        j["Aimbot"]["DrawFOV"] = Globals::Aimbot::DrawFOV;

        j["Aimbot"]["FillFOV"] = Globals::Aimbot::FovSettings::FillFov;
        j["Aimbot"]["FillColor"] = { Globals::Aimbot::FovSettings::FillColor[0],Globals::Aimbot::FovSettings::FillColor[1],Globals::Aimbot::FovSettings::FillColor[2],Globals::Aimbot::FovSettings::FillColor[3] };

        j["Aimbot"]["FovColor"] = { Globals::Aimbot::FovColor[0], Globals::Aimbot::FovColor[1], Globals::Aimbot::FovColor[2], Globals::Aimbot::FovColor[3] };
        j["Aimbot"]["FOV"] = Globals::Aimbot::FOV;
        j["Aimbot"]["Smoothning"] = Globals::Aimbot::Smoothning;
        j["Aimbot"]["SmoothingValue"] = Globals::Aimbot::SmoothingValue;
        j["Aimbot"]["SilentMousePosition"] = { Globals::Aimbot::SilentMousePosition.x, Globals::Aimbot::SilentMousePosition.y };
        j["Aimbot"]["SilentCrosshair"] = Globals::Aimbot::SilentCrosshair;
        j["Aimbot"]["SilentCrosshairTracer"] = Globals::Aimbot::SilentCrosshairTracer;
        j["Aimbot"]["SilentCrosshairTracerColor"] = { Globals::Aimbot::SilentCrosshairTracerColor[0], Globals::Aimbot::SilentCrosshairTracerColor[1], Globals::Aimbot::SilentCrosshairTracerColor[2], Globals::Aimbot::SilentCrosshairTracerColor[3] };

        j["Aimbot"]["Hits"]["HitSounds"] = Globals::Aimbot::Hits::HitSounds;
        j["Aimbot"]["Hits"]["HitSound"] = Globals::Aimbot::Hits::HitSound;
        j["Aimbot"]["Hits"]["HitTracers"] = Globals::Aimbot::Hits::HitTracers;
        j["Aimbot"]["Hits"]["HitMarkers"] = Globals::Aimbot::Hits::HitMarkers;
        j["Aimbot"]["Hits"]["HitTracersColor"] = { Globals::Aimbot::Hits::HitTracersColor[0], Globals::Aimbot::Hits::HitTracersColor[1], Globals::Aimbot::Hits::HitTracersColor[2], Globals::Aimbot::Hits::HitTracersColor[3] };
        j["Aimbot"]["Hits"]["HitMarkersColor"] = { Globals::Aimbot::Hits::HitMarkersColor[0], Globals::Aimbot::Hits::HitMarkersColor[1], Globals::Aimbot::Hits::HitMarkersColor[2], Globals::Aimbot::Hits::HitMarkersColor[3] };

        j["Aimbot"]["Rage"]["Orbit"] = Globals::Aimbot::Rage::Orbit;
        j["Aimbot"]["Rage"]["OrbitRadius"] = { Globals::Aimbot::Rage::OrbitSettings::radius };
		j["Aimbot"]["Rage"]["OrbitSpeed"] = { Globals::Aimbot::Rage::OrbitSettings::orbitSpeed };
        j["Aimbot"]["Rage"]["OrbitHeightOffset"] = { Globals::Aimbot::Rage::OrbitSettings::heightOffset };
        j["Aimbot"]["Rage"]["SpamTP"] = Globals::Aimbot::Rage::SpamTP;

        j["TriggerBot"]["Enabled"] = Globals::TriggerBot::Enabled;
        j["TriggerBot"]["TriggerBotKey"] = Globals::TriggerBot::Key.Save();
        j["TriggerBot"]["Delay"] = Globals::TriggerBot::Delay;
        j["TriggerBot"]["Threshold"] = Globals::TriggerBot::Threshold;
        j["TriggerBot"]["ToolCheck"] = Globals::TriggerBot::ToolCheck;

        j["World"]["AmbientColor"] = { Globals::World::AmbientColor[0], Globals::World::AmbientColor[1], Globals::World::AmbientColor[2] };
        j["World"]["OutdoorAmbientColor"] = { Globals::World::OutdoorAmbientColor[0], Globals::World::OutdoorAmbientColor[1], Globals::World::OutdoorAmbientColor[2] };
        j["World"]["LocalPlayerForceField"] = Globals::World::LocalPlayerForceField;
        j["World"]["CameraFOV"] = Globals::World::CameraFOV;
        j["World"]["CameraFOVValue"] = Globals::World::CameraFOVValue;
        j["World"]["Zoom"] = Globals::World::Zoom;
        j["World"]["ZoomKey"] = Globals::World::ZoomKey.Save();
        j["World"]["ZoomValue"] = Globals::World::ZoomValue;
        j["World"]["TimeManipulation"] = Globals::World::TimeManipulation;
        j["World"]["TimeManipulationValue"] = Globals::World::TimeManipulationValue;

        j["World"]["Waypoints"]["WaypointName"] = Globals::World::Waypoints::WaypointName;
        j["World"]["Waypoints"]["WaypointDistance"] = Globals::World::Waypoints::WaypointDistance;
        j["World"]["Waypoints"]["Colors"]["WaypointName"] = { Globals::World::Waypoints::Colors::WaypointName[0], Globals::World::Waypoints::Colors::WaypointName[1], Globals::World::Waypoints::Colors::WaypointName[2], Globals::World::Waypoints::Colors::WaypointName[3] };
        j["World"]["Waypoints"]["Colors"]["WaypointDistance"] = { Globals::World::Waypoints::Colors::WaypointDistance[0], Globals::World::Waypoints::Colors::WaypointDistance[1], Globals::World::Waypoints::Colors::WaypointDistance[2], Globals::World::Waypoints::Colors::WaypointDistance[3] };

        j["World"]["Movement"]["InfiniteJump"] = Globals::World::Movement::InfiniteJump;
        j["World"]["Movement"]["InfiniteJumpNameSpace"]["CustomJumpPower"] = Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPower;
        j["World"]["Movement"]["InfiniteJumpNameSpace"]["CustomJumpPowerValue"] = Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPowerValue;
        j["World"]["Movement"]["Fly"] = Globals::World::Movement::Fly;
        j["World"]["Movement"]["FlyMethod"] = Globals::World::Movement::FlyMethod;
        j["World"]["Movement"]["FlyKeybind"] = Globals::World::Movement::FlyKey.Save();
        j["World"]["Movement"]["FlySpeed"] = Globals::World::Movement::FlySpeed;
        j["World"]["Movement"]["Speed"] = Globals::World::Movement::Speed;
        j["World"]["Movement"]["SpeedMethod"] = Globals::World::Movement::SpeedMethod;
        j["World"]["Movement"]["SpeedKeybind"] = Globals::World::Movement::SpeedKey.Save();
        j["World"]["Movement"]["SpeedValue"] = Globals::World::Movement::SpeedValue;
        j["World"]["Movement"]["Noclip"] = Globals::World::Movement::Noclip;
        j["World"]["Movement"]["NoclipKey"] = Globals::World::Movement::NoclipKey.Save();
        j["World"]["Movement"]["Freecam"] = Globals::World::Movement::Freecam;
        j["World"]["Movement"]["FreecamKey"] = Globals::World::Movement::FreecamKey.Save();
        j["World"]["Movement"]["FreecamSpeed"] = Globals::World::Movement::FreecamSpeed;
        j["World"]["Movement"]["ThirdPerson"] = Globals::World::Movement::ThirdPerson;
        j["World"]["Movement"]["ThirdPersonKey"] = Globals::World::Movement::ThirdPersonKey.Save();
        j["World"]["Movement"]["ThirdPersonX"] = Globals::World::Movement::ThirdPersonX;
        j["World"]["Movement"]["ThirdPersonY"] = Globals::World::Movement::ThirdPersonY;
        j["World"]["Movement"]["ThirdPersonZ"] = Globals::World::Movement::ThirdPersonZ;
        j["World"]["Movement"]["Spinbot"] = Globals::World::Movement::Spinbot;
        j["World"]["Movement"]["SpinbotSpeed"] = Globals::World::Movement::SpinbotSpeed;
        j["World"]["Movement"]["UpsideDown"] = Globals::World::Movement::UpsideDown;
        j["World"]["Movement"]["WalkSpeed"] = Globals::World::Movement::WalkSpeed;
        j["World"]["Movement"]["WalkSpeedValue"] = Globals::World::Movement::WalkSpeedValue;

        j["Misc"]["StreamProof"] = Globals::Misc::StreamProof;

        j["Misc"]["Desync"] = Globals::Misc::Desync;
        j["Misc"]["DesyncBind"] = Globals::Misc::DesyncBind.Save();

        j["Raycast"]["Enabled"] = Globals::Raycast::Enabled;
        j["Raycast"]["Method"] = Globals::Raycast::Method;
        j["Raycast"]["Delay"] = Globals::Raycast::Delay;
        j["Raycast"]["VisibleCheck"] = Globals::Raycast::VisibleCheck;
        j["Raycast"]["AimMode"] = Globals::Raycast::AimMode;
        j["Raycast"]["Preview"] = Globals::Raycast::Preview;

        j["Exploits"]["AnimationEnabled"] = Globals::Exploits::AnimationEnabled;
        j["Exploits"]["AnimationPack"] = Globals::Exploits::AnimationPack;
        j["Exploits"]["AnimationIdle"] = Globals::Exploits::AnimationIdle;
        j["Exploits"]["AnimationRun"] = Globals::Exploits::AnimationRun;
        j["Exploits"]["AnimationWalk"] = Globals::Exploits::AnimationWalk;
        j["Exploits"]["AnimationJump"] = Globals::Exploits::AnimationJump;
        j["Exploits"]["AnimationFall"] = Globals::Exploits::AnimationFall;
        j["Exploits"]["AnimationClimb"] = Globals::Exploits::AnimationClimb;
        j["Exploits"]["AnimationSwim"] = Globals::Exploits::AnimationSwim;

        j["Aimbot"]["VisibleCheck"] = Globals::Aimbot::VisibleCheck;
        j["TriggerBot"]["VisibleCheck"] = Globals::TriggerBot::VisibleCheck;
        j["Aimbot"]["Rage"]["MagicBullet"] = Globals::Aimbot::Rage::MagicBullet;
        j["Aimbot"]["Rage"]["RageBot"] = Globals::Aimbot::Rage::RageBot;
        j["Aimbot"]["Rage"]["RageBotMode"] = Globals::Aimbot::Rage::RageBotMode;

        return j.dump(4);
    }

    void Load(const std::string& config)
    {
        try
        {
            nlohmann::json j = nlohmann::json::parse(config);

            if (j.contains("Watermark")) Globals::Watermark = j["Watermark"];
            if (j.contains("Notifications")) Globals::Notifications = j["Notifications"];

            if (j.contains("Esp"))
            {
                if (j["Esp"].contains("Enabled")) Globals::Esp::Enabled = j["Esp"]["Enabled"];
                if (j["Esp"].contains("Box")) Globals::Esp::Box = j["Esp"]["Box"];
                if (j["Esp"].contains("BoxGlow")) Globals::Esp::BoxGlow = j["Esp"]["BoxGlow"];
                if (j["Esp"].contains("Name")) Globals::Esp::Name = j["Esp"]["Name"];
                if (j["Esp"].contains("UseDisplayName")) Globals::Esp::UseDisplayName = j["Esp"]["UseDisplayName"];
                if (j["Esp"].contains("Distance")) Globals::Esp::Distance = j["Esp"]["Distance"];
                if (j["Esp"].contains("Tool")) Globals::Esp::Tool = j["Esp"]["Tool"];
                if (j["Esp"].contains("Chams")) Globals::Esp::Chams = j["Esp"]["Chams"];
                if (j["Esp"].contains("ChamsGlow")) Globals::Esp::ChamsGlow = j["Esp"]["ChamsGlow"];
                if (j["Esp"].contains("ChamsOutlines")) Globals::Esp::ChamsOutlines = j["Esp"]["ChamsOutlines"];
                if (j["Esp"].contains("HealthBar")) Globals::Esp::HealthBar = j["Esp"]["HealthBar"];
                if (j["Esp"].contains("HealthNumber")) Globals::Esp::HealthNumber = j["Esp"]["HealthNumber"];
                if (j["Esp"].contains("HealthBarBackGround")) Globals::Esp::HealthBarBackGround = j["Esp"]["HealthBarBackGround"];
                if (j["Esp"].contains("HealthBarGlow")) Globals::Esp::HealthBarGlow = j["Esp"]["HealthBarGlow"];
                if (j["Esp"].contains("HealthBarColorType")) Globals::Esp::HealthBarColorType = j["Esp"]["HealthBarColorType"];
                if (j["Esp"].contains("Team")) Globals::Esp::Team = j["Esp"]["Team"];
                if (j["Esp"].contains("TeamMode")) Globals::Esp::TeamMode = j["Esp"]["TeamMode"];
                if (j["Esp"].contains("Leaderstats")) Globals::Esp::Leaderstats = j["Esp"]["Leaderstats"];
                if (j["Esp"].contains("Region")) Globals::Esp::Region = j["Esp"]["Region"];
                if (j["Esp"].contains("LocalPlayerESP")) Globals::Esp::LocalPlayerESP = j["Esp"]["LocalPlayerESP"];
                if (j["Esp"].contains("Font")) Globals::Esp::Font = j["Esp"]["Font"];
                if (j["Esp"].contains("MaxDistance")) Globals::Esp::MaxDistance = j["Esp"]["MaxDistance"];
                if (j["Esp"].contains("MaxDistanceValue")) Globals::Esp::MaxDistanceValue = j["Esp"]["MaxDistanceValue"];
                if (j["Esp"].contains("KeybindList")) Globals::Esp::KeybindList = j["Esp"]["KeybindList"];
                if (j["Esp"].contains("ChamsOutlineThickness")) Globals::Esp::ChamsOutlineThickness = j["Esp"]["ChamsOutlineThickness"];
                if (j["Esp"].contains("InheritBodyColorChams")) Globals::Esp::InheritBodyColorChams = j["Esp"]["InheritBodyColorChams"];
                if (j["Esp"].contains("FilterUnknownChamsParts")) Globals::Esp::FilterUnknownChamsParts = j["Esp"]["FilterUnknownChamsParts"];
                if (j["Esp"].contains("Tracers")) Globals::Esp::Tracers = j["Esp"]["Tracers"];
                if (j["Esp"].contains("Skeleton")) Globals::Esp::Skeleton = j["Esp"]["Skeleton"];
                if (j["Esp"].contains("TracersPosition")) Globals::Esp::TracersPosition = j["Esp"]["TracersPosition"];
                if (j["Esp"].contains("Avatar")) Globals::Esp::Avatar = j["Esp"]["Avatar"];
                if (j["Esp"].contains("ChamsType")) Globals::Esp::ChamsType = j["Esp"]["ChamsType"];
                if (j["Esp"].contains("AvatarOffset")) Globals::Esp::OffsetOffBoxAvatar = j["Esp"]["AvatarOffset"];
                if (j["Esp"].contains("AvatarSize")) Globals::Esp::IconSize = j["Esp"]["AvatarSize"];

                if (j["Esp"].contains("Colors"))
                {
                    if (j["Esp"]["Colors"].contains("Skeleton")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::Skeleton[i] = j["Esp"]["Colors"]["Skeleton"][i];
                    if (j["Esp"]["Colors"].contains("Tracers")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::Tracers[i] = j["Esp"]["Colors"]["Tracers"][i];
                    if (j["Esp"]["Colors"].contains("Box")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::Box[i] = j["Esp"]["Colors"]["Box"][i];
                    if (j["Esp"]["Colors"].contains("BoxGlow")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::BoxGlow[i] = j["Esp"]["Colors"]["BoxGlow"][i];
                    if (j["Esp"]["Colors"].contains("Name")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::Name[i] = j["Esp"]["Colors"]["Name"][i];
                    if (j["Esp"]["Colors"].contains("Distance")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::Distance[i] = j["Esp"]["Colors"]["Distance"][i];
                    if (j["Esp"]["Colors"].contains("Tool")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::Tool[i] = j["Esp"]["Colors"]["Tool"][i];
                    if (j["Esp"]["Colors"].contains("Chams")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::Chams[i] = j["Esp"]["Colors"]["Chams"][i];
                    if (j["Esp"]["Colors"].contains("ChamsGlow")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::ChamsGlow[i] = j["Esp"]["Colors"]["ChamsGlow"][i];
                    if (j["Esp"]["Colors"].contains("ChamsOutlines")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::ChamsOutlines[i] = j["Esp"]["Colors"]["ChamsOutlines"][i];
                    if (j["Esp"]["Colors"].contains("HealthBarGlow")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::HealthBarGlow[i] = j["Esp"]["Colors"]["HealthBarGlow"][i];
                    if (j["Esp"]["Colors"].contains("HealthBar")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::HealthBar[i] = j["Esp"]["Colors"]["HealthBar"][i];
                    if (j["Esp"]["Colors"].contains("HealthNumber")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::HealthNumber[i] = j["Esp"]["Colors"]["HealthNumber"][i];
                    if (j["Esp"]["Colors"].contains("Region")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::Region[i] = j["Esp"]["Colors"]["Region"][i];
                    if (j["Esp"]["Colors"].contains("LeaderStats")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::LeaderStats[i] = j["Esp"]["Colors"]["LeaderStats"][i];
                    if (j["Esp"]["Colors"].contains("Murderer")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::Murderer[i] = j["Esp"]["Colors"]["Murderer"][i];
                    if (j["Esp"]["Colors"].contains("Sheriff")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::Sheriff[i] = j["Esp"]["Colors"]["Sheriff"][i];
                    if (j["Esp"]["Colors"].contains("Innocent")) for (int i = 0; i < 4; i++) Globals::Esp::Colors::Innocent[i] = j["Esp"]["Colors"]["Innocent"][i];
                }
            }

            if (j.contains("Misc"))
            {
                if (j["Misc"].contains("TeamCheck")) Globals::Misc::TeamCheck = j["Misc"]["TeamCheck"];
                if (j["Misc"].contains("Desync")) Globals::Misc::Desync = j["Misc"]["Desync"];
                if (j["Misc"].contains("DesyncBind")) Globals::Misc::DesyncBind.Load(j["Misc"]["DesyncBind"]);
            }

            if (j.contains("Aimbot"))
            {
                if (j["Aimbot"].contains("Enabled")) Globals::Aimbot::Enabled = j["Aimbot"]["Enabled"];
                if (j["Aimbot"].contains("VisibleCheck")) Globals::Aimbot::VisibleCheck = j["Aimbot"]["VisibleCheck"];
                if (j["Aimbot"].contains("AimbotKey"))
                {
                    if (j["Aimbot"]["AimbotKey"].contains("AimKey")) Globals::Aimbot::AimbotKey.Load(j["Aimbot"]["AimbotKey"]["AimKey"]);
                }
                if (j["Aimbot"].contains("SilentMode")) Globals::Aimbot::SilentMode = j["Aimbot"]["SilentMode"];
                if (j["Aimbot"].contains("Hitbox")) Globals::Aimbot::Hitbox = j["Aimbot"]["Hitbox"];
                if (j["Aimbot"].contains("AimType")) Globals::Aimbot::AimType = j["Aimbot"]["AimType"];
                if (j["Aimbot"].contains("Prediction")) Globals::Aimbot::Prediction = j["Aimbot"]["Prediction"];
                if (j["Aimbot"].contains("PredictionX")) Globals::Aimbot::PredictionX = j["Aimbot"]["PredictionX"];
                if (j["Aimbot"].contains("PredictionY")) Globals::Aimbot::PredictionY = j["Aimbot"]["PredictionY"];
                if (j["Aimbot"].contains("EnableFOV")) Globals::Aimbot::EnableFOV = j["Aimbot"]["EnableFOV"];


                if (j["Aimbot"].contains("FillFOV")) Globals::Aimbot::FovSettings::FillFov = j["Aimbot"]["FillFOV"];
                if (j["Aimbot"].contains("FillFOV")) Globals::Aimbot::FovSettings::FillFov = j["Aimbot"]["FillFOV"];
                if(j["Aimbot"].contains("FillColor")) for (int i = 0; i < 4; i++) Globals::Aimbot::FovSettings::FillColor[i] = j["Aimbot"]["FillColor"][i];


                if (j["Aimbot"].contains("DrawFOV")) Globals::Aimbot::DrawFOV = j["Aimbot"]["DrawFOV"];
                if (j["Aimbot"].contains("FovColor")) for (int i = 0; i < 4; i++) Globals::Aimbot::FovColor[i] = j["Aimbot"]["FovColor"][i];
                if (j["Aimbot"].contains("FOV")) Globals::Aimbot::FOV = j["Aimbot"]["FOV"];
                if (j["Aimbot"].contains("Smoothning")) Globals::Aimbot::Smoothning = j["Aimbot"]["Smoothning"];
                if (j["Aimbot"].contains("SmoothingValue")) Globals::Aimbot::SmoothingValue = j["Aimbot"]["SmoothingValue"];
                if (j["Aimbot"].contains("SilentMousePosition"))
                {
                    Globals::Aimbot::SilentMousePosition.x = j["Aimbot"]["SilentMousePosition"][0];
                    Globals::Aimbot::SilentMousePosition.y = j["Aimbot"]["SilentMousePosition"][1];
                }
                if (j["Aimbot"].contains("SilentCrosshair")) Globals::Aimbot::SilentCrosshair = j["Aimbot"]["SilentCrosshair"];
                if (j["Aimbot"].contains("SilentCrosshairTracer")) Globals::Aimbot::SilentCrosshairTracer = j["Aimbot"]["SilentCrosshairTracer"];
                if (j["Aimbot"].contains("SilentCrosshairTracerColor")) for (int i = 0; i < 4; i++) Globals::Aimbot::SilentCrosshairTracerColor[i] = j["Aimbot"]["SilentCrosshairTracerColor"][i];
                if (j["Aimbot"].contains("IsThereATarget")) Globals::Aimbot::IsThereATarget = j["Aimbot"]["IsThereATarget"];

                if (j["Aimbot"].contains("Hits"))
                {
                    if (j["Aimbot"]["Hits"].contains("HitSounds")) Globals::Aimbot::Hits::HitSounds = j["Aimbot"]["Hits"]["HitSounds"];
                    if (j["Aimbot"]["Hits"].contains("HitSound")) Globals::Aimbot::Hits::HitSound = j["Aimbot"]["Hits"]["HitSound"];
                    if (j["Aimbot"]["Hits"].contains("HitTracers")) Globals::Aimbot::Hits::HitTracers = j["Aimbot"]["Hits"]["HitTracers"];
                    if (j["Aimbot"]["Hits"].contains("HitMarkers")) Globals::Aimbot::Hits::HitMarkers = j["Aimbot"]["Hits"]["HitMarkers"];
                    if (j["Aimbot"]["Hits"].contains("HitTracersColor")) for (int i = 0; i < 4; i++) Globals::Aimbot::Hits::HitTracersColor[i] = j["Aimbot"]["Hits"]["HitTracersColor"][i];
                    if (j["Aimbot"]["Hits"].contains("HitMarkersColor")) for (int i = 0; i < 4; i++) Globals::Aimbot::Hits::HitMarkersColor[i] = j["Aimbot"]["Hits"]["HitMarkersColor"][i];
                }
                if (j["Aimbot"].contains("Rage"))
                {
                    if (j["Aimbot"]["Rage"].contains("SpamTP")) Globals::Aimbot::Rage::SpamTP = j["Aimbot"]["Rage"]["SpamTP"];
                    if (j["Aimbot"]["Rage"].contains("Orbit")) Globals::Aimbot::Rage::Orbit = j["Aimbot"]["Rage"]["Orbit"];
                    if (j["Aimbot"]["Rage"].contains("MagicBullet")) Globals::Aimbot::Rage::MagicBullet = j["Aimbot"]["Rage"]["MagicBullet"];
                    if (j["Aimbot"]["Rage"].contains("RageBot")) Globals::Aimbot::Rage::RageBot = j["Aimbot"]["Rage"]["RageBot"];
                    if (j["Aimbot"]["Rage"].contains("RageBotMode")) Globals::Aimbot::Rage::RageBotMode = j["Aimbot"]["Rage"]["RageBotMode"];
					if (j["Aimbot"]["Rage"].contains("OrbitSpeed")) Globals::Aimbot::Rage::OrbitSettings::orbitSpeed = j["Aimbot"]["Rage"]["OrbitSpeed"];
					if (j["Aimbot"]["Rage"].contains("OrbitRadius")) Globals::Aimbot::Rage::OrbitSettings::radius = j["Aimbot"]["Rage"]["OrbitRadius"];
					if (j["Aimbot"]["Rage"].contains("OrbitHeightOffset")) Globals::Aimbot::Rage::OrbitSettings::heightOffset = j["Aimbot"]["Rage"]["OrbitHeightOffset"];
                }
            }

            if (j.contains("TriggerBot"))
            {
                if (j["TriggerBot"].contains("Enabled")) Globals::TriggerBot::Enabled = j["TriggerBot"]["Enabled"];
                if (j["TriggerBot"].contains("TriggerBotKey")) Globals::TriggerBot::Key.Load(j["TriggerBot"]["TriggerBotKey"]);
                if (j["TriggerBot"].contains("Delay")) Globals::TriggerBot::Delay = j["TriggerBot"]["Delay"];
                if (j["TriggerBot"].contains("Threshold")) Globals::TriggerBot::Threshold = j["TriggerBot"]["Threshold"];
                if (j["TriggerBot"].contains("ToolCheck")) Globals::TriggerBot::ToolCheck = j["TriggerBot"]["ToolCheck"];
                if (j["TriggerBot"].contains("VisibleCheck")) Globals::TriggerBot::VisibleCheck = j["TriggerBot"]["VisibleCheck"];
            }
            if (j.contains("Misc"))
            {
                if (j["Misc"].contains("StreamProof")) Globals::Misc::StreamProof = j["Misc"]["StreamProof"];
            }
            if (j.contains("Raycast"))
            {
                if (j["Raycast"].contains("Enabled")) Globals::Raycast::Enabled = j["Raycast"]["Enabled"];
                if (j["Raycast"].contains("Method")) Globals::Raycast::Method = j["Raycast"]["Method"];
                if (j["Raycast"].contains("Delay")) Globals::Raycast::Delay = j["Raycast"]["Delay"];
                if (j["Raycast"].contains("VisibleCheck")) Globals::Raycast::VisibleCheck = j["Raycast"]["VisibleCheck"];
                if (j["Raycast"].contains("AimMode")) Globals::Raycast::AimMode = j["Raycast"]["AimMode"];
                if (j["Raycast"].contains("Preview")) Globals::Raycast::Preview = j["Raycast"]["Preview"];
            }
            if (j.contains("World"))
            {
                if (j["World"].contains("AmbientColor")) for (int i = 0; i < 3; i++) Globals::World::AmbientColor[i] = j["World"]["AmbientColor"][i];
                if (j["World"].contains("OutdoorAmbientColor")) for (int i = 0; i < 3; i++) Globals::World::OutdoorAmbientColor[i] = j["World"]["OutdoorAmbientColor"][i];
                if (j["World"].contains("LocalPlayerForceField")) Globals::World::LocalPlayerForceField = j["World"]["LocalPlayerForceField"];
                if (j["World"].contains("CameraFOV")) Globals::World::CameraFOV = j["World"]["CameraFOV"];
                if (j["World"].contains("CameraFOVValue")) Globals::World::CameraFOVValue = j["World"]["CameraFOVValue"];
                if (j["World"].contains("Zoom")) Globals::World::Zoom = j["World"]["Zoom"];
                if (j["World"].contains("ZoomKey")) Globals::World::ZoomKey.Load(j["World"]["ZoomKey"]);
                if (j["World"].contains("ZoomValue")) Globals::World::ZoomValue = j["World"]["ZoomValue"];
                if (j["World"].contains("TimeManipulation")) Globals::World::TimeManipulation = j["World"]["TimeManipulation"];
                if (j["World"].contains("TimeManipulationValue")) Globals::World::TimeManipulationValue = j["World"]["TimeManipulationValue"];

                if (j["World"].contains("Waypoints"))
                {
                    if (j["World"]["Waypoints"].contains("WaypointName")) Globals::World::Waypoints::WaypointName = j["World"]["Waypoints"]["WaypointName"];
                    if (j["World"]["Waypoints"].contains("WaypointDistance")) Globals::World::Waypoints::WaypointDistance = j["World"]["Waypoints"]["WaypointDistance"];

                    if (j["World"]["Waypoints"].contains("Colors"))
                    {
                        if (j["World"]["Waypoints"]["Colors"].contains("WaypointName")) for (int i = 0; i < 4; i++) Globals::World::Waypoints::Colors::WaypointName[i] = j["World"]["Waypoints"]["Colors"]["WaypointName"][i];
                        if (j["World"]["Waypoints"]["Colors"].contains("WaypointDistance")) for (int i = 0; i < 4; i++) Globals::World::Waypoints::Colors::WaypointDistance[i] = j["World"]["Waypoints"]["Colors"]["WaypointDistance"][i];
                    }
                }

                if (j["World"].contains("Movement"))
                {
                    if (j["World"]["Movement"].contains("InfiniteJump")) Globals::World::Movement::InfiniteJump = j["World"]["Movement"]["InfiniteJump"];
                    if (j["World"]["Movement"].contains("Fly")) Globals::World::Movement::Fly = j["World"]["Movement"]["Fly"];
                    if (j["World"]["Movement"].contains("FlyMethod")) Globals::World::Movement::FlyMethod = j["World"]["Movement"]["FlyMethod"];
                    if (j["World"]["Movement"].contains("FlyKeybind")) Globals::World::Movement::FlyKey.Load(j["World"]["Movement"]["FlyKeybind"]);
                    if (j["World"]["Movement"].contains("FlySpeed")) Globals::World::Movement::FlySpeed = j["World"]["Movement"]["FlySpeed"];
                    if (j["World"]["Movement"].contains("Speed")) Globals::World::Movement::Speed = j["World"]["Movement"]["Speed"];
                    if (j["World"]["Movement"].contains("SpeedMethod")) Globals::World::Movement::SpeedMethod = j["World"]["Movement"]["SpeedMethod"];
                    if (j["World"]["Movement"].contains("SpeedKeybind")) Globals::World::Movement::SpeedKey.Load(j["World"]["Movement"]["SpeedKeybind"]);
                    if (j["World"]["Movement"].contains("SpeedValue")) Globals::World::Movement::SpeedValue = j["World"]["Movement"]["SpeedValue"];
                    if (j["World"]["Movement"].contains("Noclip")) Globals::World::Movement::Noclip = j["World"]["Movement"]["Noclip"];
                    if (j["World"]["Movement"].contains("NoclipKey")) Globals::World::Movement::NoclipKey.Load(j["World"]["Movement"]["NoclipKey"]);
                    if (j["World"]["Movement"].contains("Freecam")) Globals::World::Movement::Freecam = j["World"]["Movement"]["Freecam"];
                    if (j["World"]["Movement"].contains("FreecamKey")) Globals::World::Movement::FreecamKey.Load(j["World"]["Movement"]["FreecamKey"]);
                    if (j["World"]["Movement"].contains("FreecamSpeed")) Globals::World::Movement::FreecamSpeed = j["World"]["Movement"]["FreecamSpeed"];
                    if (j["World"]["Movement"].contains("ThirdPerson")) Globals::World::Movement::ThirdPerson = j["World"]["Movement"]["ThirdPerson"];
                    if (j["World"]["Movement"].contains("ThirdPersonKey")) Globals::World::Movement::ThirdPersonKey.Load(j["World"]["Movement"]["ThirdPersonKey"]);
                    if (j["World"]["Movement"].contains("ThirdPersonX")) Globals::World::Movement::ThirdPersonX = j["World"]["Movement"]["ThirdPersonX"];
                    if (j["World"]["Movement"].contains("ThirdPersonY")) Globals::World::Movement::ThirdPersonY = j["World"]["Movement"]["ThirdPersonY"];
                    if (j["World"]["Movement"].contains("ThirdPersonZ")) Globals::World::Movement::ThirdPersonZ = j["World"]["Movement"]["ThirdPersonZ"];
                    if (j["World"]["Movement"].contains("Spinbot")) Globals::World::Movement::Spinbot = j["World"]["Movement"]["Spinbot"];
                    if (j["World"]["Movement"].contains("SpinbotSpeed")) Globals::World::Movement::SpinbotSpeed = j["World"]["Movement"]["SpinbotSpeed"];
                    if (j["World"]["Movement"].contains("UpsideDown")) Globals::World::Movement::UpsideDown = j["World"]["Movement"]["UpsideDown"];
                    if (j["World"]["Movement"].contains("WalkSpeed")) Globals::World::Movement::WalkSpeed = j["World"]["Movement"]["WalkSpeed"];
                    if (j["World"]["Movement"].contains("WalkSpeedValue")) Globals::World::Movement::WalkSpeedValue = j["World"]["Movement"]["WalkSpeedValue"];

                    if (j["World"]["Movement"].contains("InfiniteJumpNameSpace"))
                    {
                        if (j["World"]["Movement"]["InfiniteJumpNameSpace"].contains("CustomJumpPower")) Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPower = j["World"]["Movement"]["InfiniteJumpNameSpace"]["CustomJumpPower"];
                        if (j["World"]["Movement"]["InfiniteJumpNameSpace"].contains("CustomJumpPowerValue")) Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPowerValue = j["World"]["Movement"]["InfiniteJumpNameSpace"]["CustomJumpPowerValue"];
                    }
                }
            }
        if (j.contains("Exploits"))
            {
                if (j["Exploits"].contains("AnimationEnabled")) Globals::Exploits::AnimationEnabled = j["Exploits"]["AnimationEnabled"];
                if (j["Exploits"].contains("AnimationPack")) Globals::Exploits::AnimationPack = j["Exploits"]["AnimationPack"];
                if (j["Exploits"].contains("AnimationIdle")) Globals::Exploits::AnimationIdle = j["Exploits"]["AnimationIdle"];
                if (j["Exploits"].contains("AnimationRun")) Globals::Exploits::AnimationRun = j["Exploits"]["AnimationRun"];
                if (j["Exploits"].contains("AnimationWalk")) Globals::Exploits::AnimationWalk = j["Exploits"]["AnimationWalk"];
                if (j["Exploits"].contains("AnimationJump")) Globals::Exploits::AnimationJump = j["Exploits"]["AnimationJump"];
                if (j["Exploits"].contains("AnimationFall")) Globals::Exploits::AnimationFall = j["Exploits"]["AnimationFall"];
                if (j["Exploits"].contains("AnimationClimb")) Globals::Exploits::AnimationClimb = j["Exploits"]["AnimationClimb"];
                if (j["Exploits"].contains("AnimationSwim")) Globals::Exploits::AnimationSwim = j["Exploits"]["AnimationSwim"];
            }
        }
        catch (...)
        {
        }
    }

    std::string Create()
    {
        nlohmann::json j;

        j["Watermark"] = false;
        j["Notifications"] = true;

        j["Esp"]["Enabled"] = false;
        j["Esp"]["Box"] = false;
        j["Esp"]["BoxGlow"] = false;
        j["Esp"]["Name"] = false;
        j["Esp"]["UseDisplayName"] = false;
        j["Esp"]["Distance"] = false;
        j["Esp"]["Tool"] = false;
        j["Esp"]["Chams"] = false;
        j["Esp"]["ChamsGlow"] = false;
        j["Esp"]["ChamsOutlines"] = false;
        j["Esp"]["HealthBar"] = false;
        j["Esp"]["HealthNumber"] = false;
        j["Esp"]["HealthBarBackGround"] = false;
        j["Esp"]["HealthBarGlow"] = false;
        j["Esp"]["HealthBarColorType"] = 0;
        j["Esp"]["Team"] = false;
        j["Esp"]["Leaderstats"] = false;
        j["Esp"]["Region"] = false;
        j["Esp"]["LocalPlayerESP"] = false;
        j["Esp"]["Font"] = 0;
        j["Esp"]["MaxDistance"] = false;
        j["Esp"]["MaxDistanceValue"] = 1000;
        j["Esp"]["KeybindList"] = false;
        j["Esp"]["ChamsOutlineThickness"] = 1.0f;
        j["Esp"]["InheritBodyColorChams"] = false;
        j["Esp"]["FilterUnknownChamsParts"] = false;
        j["Esp"]["Tracers"] = false;
        j["Esp"]["Skeleton"] = false;
        j["Esp"]["TracersPosition"] = 0;
        j["Esp"]["Avatar"] = false;
        j["Esp"]["ChamsType"] = 0;
        j["Esp"]["AvatarOffset"] = 11;
        j["Esp"]["AvatarSize"] = 32;

        j["Esp"]["Colors"]["Skeleton"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Esp"]["Colors"]["Tracers"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Esp"]["Colors"]["Box"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Esp"]["Colors"]["BoxGlow"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Esp"]["Colors"]["Name"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Esp"]["Colors"]["Distance"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Esp"]["Colors"]["Tool"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Esp"]["Colors"]["Chams"] = { 1.0f, 1.0f, 1.0f, 0.5f };
        j["Esp"]["Colors"]["ChamsGlow"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Esp"]["Colors"]["ChamsOutlines"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Esp"]["Colors"]["HealthBarGlow"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Esp"]["Colors"]["HealthBar"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Esp"]["Colors"]["HealthNumber"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Esp"]["Colors"]["Region"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Esp"]["Colors"]["LeaderStats"] = { 1.0f, 1.0f, 1.0f, 1.0f };

        j["Misc"]["TeamCheck"] = false;
        j["Misc"]["Desync"] = false;
        j["Misc"]["DesyncBind"] = CKeybind("1").Save();

        j["Aimbot"]["Enabled"] = false;

        j["Aimbot"]["AimbotKey"]["AimKey"] = CKeybind("1").Save();

        j["Aimbot"]["SilentMode"] = 0;

        j["Aimbot"]["Hitbox"] = 0;
        j["Aimbot"]["AimType"] = 0;
        j["Aimbot"]["Prediction"] = false;
        j["Aimbot"]["PredictionX"] = 1.0f;
        j["Aimbot"]["PredictionY"] = 1.0f;
        j["Aimbot"]["EnableFOV"] = false;
        j["Aimbot"]["DrawFOV"] = true;

        j["Aimbot"]["FillFOV"] = false;
        j["Aimbot"]["FillColor"] = { 1.0f, 1.0f, 1.0f, 0.3f };

        j["Aimbot"]["FovColor"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Aimbot"]["FOV"] = 60;
        j["Aimbot"]["Smoothning"] = false;
        j["Aimbot"]["SmoothingValue"] = 0.1f;
        j["Aimbot"]["SilentMousePosition"] = { 0.0f, 0.0f };
        j["Aimbot"]["SilentCrosshair"] = false;
        j["Aimbot"]["SilentCrosshairTracer"] = false;
        j["Aimbot"]["SilentCrosshairTracerColor"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Aimbot"]["IsThereATarget"] = false;
        j["Aimbot"]["Rage"]["Orbit"] = false;
        j["Aimbot"]["Rage"]["SpamTP"] = false;

        j["Aimbot"]["Hits"]["HitSounds"] = false;
        j["Aimbot"]["Hits"]["HitSound"] = 0;
        j["Aimbot"]["Hits"]["HitTracers"] = false;
        j["Aimbot"]["Hits"]["HitMarkers"] = false;
        j["Aimbot"]["Hits"]["HitTracersColor"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["Aimbot"]["Hits"]["HitMarkersColor"] = { 1.0f, 1.0f, 1.0f, 1.0f };

        j["TriggerBot"]["Enabled"] = false;
        j["TriggerBot"]["TriggerBotKey"] = CKeybind("1").Save();
        j["TriggerBot"]["Delay"] = 0;
        j["TriggerBot"]["Threshold"] = 0;
        j["TriggerBot"]["ToolCheck"] = false;

        j["World"]["AmbientColor"] = { 1.0f, 1.0f, 1.0f };
        j["World"]["OutdoorAmbientColor"] = { 1.0f, 1.0f, 1.0f };
        j["World"]["LocalPlayerForceField"] = false;
        j["World"]["CameraFOV"] = false;
        j["World"]["CameraFOVValue"] = 90;
        j["World"]["Zoom"] = false;
        j["World"]["ZoomKey"] = CKeybind("1").Save();
        j["World"]["ZoomValue"] = 30;
        j["World"]["TimeManipulation"] = false;
        j["World"]["TimeManipulationValue"] = 240.0f;

        j["World"]["Waypoints"]["WaypointName"] = false;
        j["World"]["Waypoints"]["WaypointDistance"] = false;
        j["World"]["Waypoints"]["Colors"]["WaypointName"] = { 1.0f, 1.0f, 1.0f, 1.0f };
        j["World"]["Waypoints"]["Colors"]["WaypointDistance"] = { 1.0f, 1.0f, 1.0f, 1.0f };

        j["World"]["Movement"]["InfiniteJump"] = false;
        j["World"]["Movement"]["InfiniteJumpNameSpace"]["CustomJumpPower"] = false;
        j["World"]["Movement"]["InfiniteJumpNameSpace"]["CustomJumpPowerValue"] = 50.0f;
        j["World"]["Movement"]["Fly"] = false;
        j["World"]["Movement"]["FlySpeed"] = 1.0f;
        j["World"]["Movement"]["Speed"] = false;
        j["World"]["Movement"]["SpeedMethod"] = 0;
        j["World"]["Movement"]["SpeedValue"] = 1.0f;
        j["World"]["Movement"]["Noclip"] = false;
        j["World"]["Movement"]["Freecam"] = false;
        j["World"]["Movement"]["FreecamSpeed"] = 0.01f;
        j["World"]["Movement"]["ThirdPerson"] = false;
        j["World"]["Movement"]["ThirdPersonX"] = 0.0f;
        j["World"]["Movement"]["ThirdPersonY"] = 3.0f;
        j["World"]["Movement"]["ThirdPersonZ"] = 3.0f;
        j["World"]["Movement"]["Spinbot"] = false;
        j["World"]["Movement"]["SpinbotSpeed"] = 5;
        j["World"]["Movement"]["UpsideDown"] = false;
        j["World"]["Movement"]["WalkSpeed"] = false;
        j["World"]["Movement"]["WalkSpeedValue"] = 16.0f;
        j["Misc"]["StreamProof"] = false;

        j["Raycast"]["Enabled"] = false;
        j["Raycast"]["Method"] = 0;
        j["Raycast"]["Delay"] = 50;
        j["Raycast"]["VisibleCheck"] = false;
        j["Raycast"]["AimMode"] = 0;
        j["Raycast"]["Preview"] = false;

        j["World"]["Movement"]["FlyKeybind"] = CKeybind("1").Save();
        j["World"]["Movement"]["SpeedKeybind"] = CKeybind("1").Save();
        j["World"]["Movement"]["NoclipKey"] = CKeybind("1").Save();
        j["World"]["Movement"]["FreecamKey"] = CKeybind("1").Save();
        j["World"]["Movement"]["ThirdPersonKey"] = CKeybind("1").Save();

        return j.dump(4);
    }
}