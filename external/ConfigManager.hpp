#pragma once
#include "Globals.hpp"
#include "Libs/Logging.h"
#include <Json.hpp>
#include <fstream>
#include <filesystem>

namespace ConfigManager
{
    inline uint64_t CurrentGameId = 0;
    inline uint64_t PreviousGameId = 0;
    inline bool InGame = false;

    inline nlohmann::json SerializeGlobals()
    {
        nlohmann::json j;

        j["Watermark"] = Globals::Watermark;
        j["Vsync"] = Globals::Vsync;

        j["Esp"]["Enabled"] = Globals::Esp::Enabled;
        j["Esp"]["Box"] = Globals::Esp::Box;
        j["Esp"]["BoxGlow"] = Globals::Esp::BoxGlow;
        j["Esp"]["Name"] = Globals::Esp::Name;
        j["Esp"]["UseDisplayName"] = Globals::Esp::UseDisplayName;
        j["Esp"]["Distance"] = Globals::Esp::Distance;
        j["Esp"]["Tool"] = Globals::Esp::Tool;
        j["Esp"]["Chams"] = Globals::Esp::Chams;
        j["Esp"]["Avatar"] = Globals::Esp::Avatar;
        j["Esp"]["IconSize"] = Globals::Esp::IconSize;
        j["Esp"]["OffsetOffBoxAvatar"] = Globals::Esp::OffsetOffBoxAvatar;
        j["Esp"]["ChamsType"] = Globals::Esp::ChamsType;
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
        j["Esp"]["ChamsMaterial"] = Globals::Esp::ChamsMaterial;
        j["Esp"]["OffscreenArrows"] = Globals::Esp::OffscreenArrows;
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["OffscreenArrow"].push_back(Globals::Esp::OffscreenArrowColor[i]);
        j["Esp"]["OffscreenArrowSize"] = Globals::Esp::OffscreenArrowSize;
        j["Esp"]["OffscreenArrowPadding"] = Globals::Esp::OffscreenArrowPadding;
        j["Esp"]["OffscreenArrowMinDist"] = Globals::Esp::OffscreenArrowMinDist;
        j["Esp"]["DroppedGun"] = Globals::Esp::DroppedGun;
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["DroppedGun"].push_back(Globals::Esp::Colors::DroppedGun[i]);

        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["Skeleton"].push_back(Globals::Esp::Colors::Skeleton[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["Tracers"].push_back(Globals::Esp::Colors::Tracers[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["Box"].push_back(Globals::Esp::Colors::Box[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["BoxGlow"].push_back(Globals::Esp::Colors::BoxGlow[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["Name"].push_back(Globals::Esp::Colors::Name[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["Distance"].push_back(Globals::Esp::Colors::Distance[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["Tool"].push_back(Globals::Esp::Colors::Tool[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["Chams"].push_back(Globals::Esp::Colors::Chams[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["ChamsGlow"].push_back(Globals::Esp::Colors::ChamsGlow[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["ChamsOutlines"].push_back(Globals::Esp::Colors::ChamsOutlines[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["HealthBarGlow"].push_back(Globals::Esp::Colors::HealthBarGlow[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["HealthBar"].push_back(Globals::Esp::Colors::HealthBar[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["HealthNumber"].push_back(Globals::Esp::Colors::HealthNumber[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["Region"].push_back(Globals::Esp::Colors::Region[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["LeaderStats"].push_back(Globals::Esp::Colors::LeaderStats[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["Murderer"].push_back(Globals::Esp::Colors::Murderer[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["Sheriff"].push_back(Globals::Esp::Colors::Sheriff[i]);
        for (int i = 0; i < 4; i++) j["Esp"]["Colors"]["Innocent"].push_back(Globals::Esp::Colors::Innocent[i]);

        j["Misc"]["TeamCheck"] = Globals::Misc::TeamCheck;
        j["Misc"]["StreamProof"] = Globals::Misc::StreamProof;
        j["Misc"]["Desync"] = Globals::Misc::Desync;
        j["Misc"]["DesyncBind"] = Globals::Misc::DesyncBind.Save();

        j["Raycast"]["Enabled"] = Globals::Raycast::Enabled;
        j["Raycast"]["Method"] = Globals::Raycast::Method;
        j["Raycast"]["Delay"] = Globals::Raycast::Delay;
        j["Raycast"]["VisibleCheck"] = Globals::Raycast::VisibleCheck;
        j["Raycast"]["AimMode"] = Globals::Raycast::AimMode;
        j["Raycast"]["Preview"] = Globals::Raycast::Preview;

        j["Aimbot"]["Enabled"] = Globals::Aimbot::Enabled;
        j["Aimbot"]["AimbotKey"] = Globals::Aimbot::AimbotKey.Save();
        j["Aimbot"]["Hitbox"] = Globals::Aimbot::Hitbox;
        j["Aimbot"]["VisibleCheck"] = Globals::Aimbot::VisibleCheck;
        j["Aimbot"]["SilentMode"] = Globals::Aimbot::SilentMode;
        j["Aimbot"]["SilentCrosshair"] = Globals::Aimbot::SilentCrosshair;
        j["Aimbot"]["SilentCrosshairTracer"] = Globals::Aimbot::SilentCrosshairTracer;
        for (int i = 0; i < 4; i++) j["Aimbot"]["SilentCrosshairTracerColor"].push_back(Globals::Aimbot::SilentCrosshairTracerColor[i]);
        j["Aimbot"]["AimType"] = Globals::Aimbot::AimType;
        j["Aimbot"]["Prediction"] = Globals::Aimbot::Prediction;
        j["Aimbot"]["PredictionX"] = Globals::Aimbot::PredictionX;
        j["Aimbot"]["PredictionY"] = Globals::Aimbot::PredictionY;
        j["Aimbot"]["EnableFOV"] = Globals::Aimbot::EnableFOV;
        j["Aimbot"]["DrawFOV"] = Globals::Aimbot::DrawFOV;
        j["Aimbot"]["FOV"] = Globals::Aimbot::FOV;
        j["Aimbot"]["Smoothning"] = Globals::Aimbot::Smoothning;
        j["Aimbot"]["SmoothingValue"] = Globals::Aimbot::SmoothingValue;
        for (int i = 0; i < 4; i++) j["Aimbot"]["FovColor"].push_back(Globals::Aimbot::FovColor[i]);
        j["Aimbot"]["FovSettings"]["FillFov"] = Globals::Aimbot::FovSettings::FillFov;
        for (int i = 0; i < 4; i++) j["Aimbot"]["FovSettings"]["FillColor"].push_back(Globals::Aimbot::FovSettings::FillColor[i]);
        j["Aimbot"]["Rage"]["SpamTP"] = Globals::Aimbot::Rage::SpamTP;
        j["Aimbot"]["Rage"]["Orbit"] = Globals::Aimbot::Rage::Orbit;
        j["Aimbot"]["Rage"]["MagicBullet"] = Globals::Aimbot::Rage::MagicBullet;
        j["Aimbot"]["Rage"]["RageBot"] = Globals::Aimbot::Rage::RageBot;
        j["Aimbot"]["Rage"]["RageBotMode"] = Globals::Aimbot::Rage::RageBotMode;
        j["Aimbot"]["Rage"]["OrbitSettings"]["radius"] = Globals::Aimbot::Rage::OrbitSettings::radius;
        j["Aimbot"]["Rage"]["OrbitSettings"]["orbitSpeed"] = Globals::Aimbot::Rage::OrbitSettings::orbitSpeed;
        j["Aimbot"]["Rage"]["OrbitSettings"]["heightOffset"] = Globals::Aimbot::Rage::OrbitSettings::heightOffset;

        j["Aimbot"]["Hits"]["HitSounds"] = Globals::Aimbot::Hits::HitSounds;
        j["Aimbot"]["Hits"]["HitSound"] = Globals::Aimbot::Hits::HitSound;
        j["Aimbot"]["Hits"]["HitTracers"] = Globals::Aimbot::Hits::HitTracers;
        j["Aimbot"]["Hits"]["HitMarkers"] = Globals::Aimbot::Hits::HitMarkers;
        for (int i = 0; i < 4; i++) j["Aimbot"]["Hits"]["HitTracersColor"].push_back(Globals::Aimbot::Hits::HitTracersColor[i]);
        for (int i = 0; i < 4; i++) j["Aimbot"]["Hits"]["HitMarkersColor"].push_back(Globals::Aimbot::Hits::HitMarkersColor[i]);

        j["Exploits"]["Animation"]["Enabled"] = Globals::Exploits::AnimationEnabled;
        j["Exploits"]["AnimationPack"] = Globals::Exploits::AnimationPack;
        j["Exploits"]["Animation"]["Idle"] = Globals::Exploits::AnimationIdle;
        j["Exploits"]["Animation"]["Run"] = Globals::Exploits::AnimationRun;
        j["Exploits"]["Animation"]["Walk"] = Globals::Exploits::AnimationWalk;
        j["Exploits"]["Animation"]["Jump"] = Globals::Exploits::AnimationJump;
        j["Exploits"]["Animation"]["Fall"] = Globals::Exploits::AnimationFall;
        j["Exploits"]["Animation"]["Climb"] = Globals::Exploits::AnimationClimb;
        j["Exploits"]["Animation"]["Swim"] = Globals::Exploits::AnimationSwim;

        j["TriggerBot"]["Enabled"] = Globals::TriggerBot::Enabled;
        j["TriggerBot"]["Key"] = Globals::TriggerBot::Key.Save();
        j["TriggerBot"]["VisibleCheck"] = Globals::TriggerBot::VisibleCheck;
        j["TriggerBot"]["Delay"] = Globals::TriggerBot::Delay;
        j["TriggerBot"]["Threshold"] = Globals::TriggerBot::Threshold;
        j["TriggerBot"]["ToolCheck"] = Globals::TriggerBot::ToolCheck;

        j["World"]["LocalPlayerForceField"] = Globals::World::LocalPlayerForceField;
        j["World"]["Waypoints"]["WaypointName"] = Globals::World::Waypoints::WaypointName;
        j["World"]["Waypoints"]["WaypointDistance"] = Globals::World::Waypoints::WaypointDistance;
        for (int i = 0; i < 4; i++) j["World"]["Waypoints"]["Colors"]["WaypointName"].push_back(Globals::World::Waypoints::Colors::WaypointName[i]);
        for (int i = 0; i < 4; i++) j["World"]["Waypoints"]["Colors"]["WaypointDistance"].push_back(Globals::World::Waypoints::Colors::WaypointDistance[i]);
        j["World"]["CameraFOV"] = Globals::World::CameraFOV;
        j["World"]["CameraFOVValue"] = Globals::World::CameraFOVValue;
        j["World"]["Zoom"] = Globals::World::Zoom;
        j["World"]["ZoomKey"] = Globals::World::ZoomKey.Save();
        j["World"]["ZoomValue"] = Globals::World::ZoomValue;
        j["World"]["AmbientColor"] = { Globals::World::AmbientColor[0], Globals::World::AmbientColor[1], Globals::World::AmbientColor[2] };
        j["World"]["OutdoorAmbientColor"] = { Globals::World::OutdoorAmbientColor[0], Globals::World::OutdoorAmbientColor[1], Globals::World::OutdoorAmbientColor[2] };

        j["World"]["Movement"]["InfiniteJump"] = Globals::World::Movement::InfiniteJump;
        j["World"]["Movement"]["CustomJumpPower"] = Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPower;
        j["World"]["Movement"]["CustomJumpPowerValue"] = Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPowerValue;
        j["World"]["Movement"]["Fly"] = Globals::World::Movement::Fly;
        j["World"]["Movement"]["FlyMethod"] = Globals::World::Movement::FlyMethod;
        j["World"]["Movement"]["FlySpeed"] = Globals::World::Movement::FlySpeed;
        j["World"]["Movement"]["FlyKey"] = Globals::World::Movement::FlyKey.Save();
        j["World"]["Movement"]["Speed"] = Globals::World::Movement::Speed;
        j["World"]["Movement"]["SpeedMethod"] = Globals::World::Movement::SpeedMethod;
        j["World"]["Movement"]["SpeedValue"] = Globals::World::Movement::SpeedValue;
        j["World"]["Movement"]["SpeedKey"] = Globals::World::Movement::SpeedKey.Save();
        j["World"]["Movement"]["Noclip"] = Globals::World::Movement::Noclip;
        j["World"]["Movement"]["NoclipKey"] = Globals::World::Movement::NoclipKey.Save();
        j["World"]["Movement"]["Freecam"] = Globals::World::Movement::Freecam;
        j["World"]["Movement"]["FreecamSpeed"] = Globals::World::Movement::FreecamSpeed;
        j["World"]["Movement"]["FreecamKey"] = Globals::World::Movement::FreecamKey.Save();
        j["World"]["Movement"]["ThirdPerson"] = Globals::World::Movement::ThirdPerson;
        j["World"]["Movement"]["ThirdPersonX"] = Globals::World::Movement::ThirdPersonX;
        j["World"]["Movement"]["ThirdPersonY"] = Globals::World::Movement::ThirdPersonY;
        j["World"]["Movement"]["ThirdPersonZ"] = Globals::World::Movement::ThirdPersonZ;
        j["World"]["Movement"]["ThirdPersonKey"] = Globals::World::Movement::ThirdPersonKey.Save();
        j["World"]["Movement"]["AntiAimKey"] = Globals::World::Movement::AntiAimKey.Save();
        j["World"]["Movement"]["Spinbot"] = Globals::World::Movement::Spinbot;
        j["World"]["Movement"]["SpinbotSpeed"] = Globals::World::Movement::SpinbotSpeed;
        j["World"]["Movement"]["UpsideDown"] = Globals::World::Movement::UpsideDown;
        j["World"]["Movement"]["WalkSpeed"] = Globals::World::Movement::WalkSpeed;
        j["World"]["Movement"]["WalkSpeedValue"] = Globals::World::Movement::WalkSpeedValue;
        j["World"]["Movement"]["AntiAimPitch"] = Globals::World::Movement::AntiAimPitch;
        j["World"]["Movement"]["AntiAimYaw"] = Globals::World::Movement::AntiAimYaw;
        j["World"]["Movement"]["Peek"] = Globals::World::Movement::Peek;
        j["World"]["Movement"]["PeekKey"] = Globals::World::Movement::PeekKey.Save();
        j["World"]["Movement"]["PeekRadius"] = Globals::World::Movement::PeekRadius;
        for (int i = 0; i < 4; i++) j["World"]["Movement"]["PeekColor"].push_back(Globals::World::Movement::PeekColor[i]);
        j["World"]["Movement"]["PeekClickTP"] = Globals::World::Movement::PeekClickTP;
        j["World"]["TimeManipulation"] = Globals::World::TimeManipulation;
        j["World"]["TimeManipulationValue"] = Globals::World::TimeManipulationValue;

        j["DockBar"]["Home"] = Globals::DockBar_Home;
        j["DockBar"]["Style"] = Globals::DockBar_Style;
        j["DockBar"]["EspPreview"] = Globals::DockBar_EspPreview;
        j["DockBar"]["TargetHud"] = Globals::DockBar_TargetHud;
        j["DockBar"]["Explorer"] = Globals::DockBar_Explorer;
        j["DockBar"]["Players"] = Globals::DockBar_Players;
        j["DockBar"]["Keybinds"] = Globals::DockBar_Keybinds;
        j["DockBar"]["Anims"] = Globals::DockBar_Anims;

        return j;
    }

    inline void DeserializeGlobals(const nlohmann::json& j)
    {
        if (j.contains("Watermark")) Globals::Watermark = j["Watermark"];
        if (j.contains("Vsync")) Globals::Vsync = j["Vsync"];

        if (j.contains("Esp")) {
            auto& e = j["Esp"];
            if (e.contains("Enabled")) Globals::Esp::Enabled = e["Enabled"];
            if (e.contains("Box")) Globals::Esp::Box = e["Box"];
            if (e.contains("BoxGlow")) Globals::Esp::BoxGlow = e["BoxGlow"];
            if (e.contains("Name")) Globals::Esp::Name = e["Name"];
            if (e.contains("UseDisplayName")) Globals::Esp::UseDisplayName = e["UseDisplayName"];
            if (e.contains("Distance")) Globals::Esp::Distance = e["Distance"];
            if (e.contains("Tool")) Globals::Esp::Tool = e["Tool"];
            if (e.contains("Chams")) Globals::Esp::Chams = e["Chams"];
            if (e.contains("Avatar")) Globals::Esp::Avatar = e["Avatar"];
            if (e.contains("IconSize")) Globals::Esp::IconSize = e["IconSize"];
            if (e.contains("OffsetOffBoxAvatar")) Globals::Esp::OffsetOffBoxAvatar = e["OffsetOffBoxAvatar"];
            if (e.contains("ChamsType")) Globals::Esp::ChamsType = e["ChamsType"];
            if (e.contains("ChamsGlow")) Globals::Esp::ChamsGlow = e["ChamsGlow"];
            if (e.contains("ChamsOutlines")) Globals::Esp::ChamsOutlines = e["ChamsOutlines"];
            if (e.contains("HealthBar")) Globals::Esp::HealthBar = e["HealthBar"];
            if (e.contains("HealthNumber")) Globals::Esp::HealthNumber = e["HealthNumber"];
            if (e.contains("HealthBarBackGround")) Globals::Esp::HealthBarBackGround = e["HealthBarBackGround"];
            if (e.contains("HealthBarGlow")) Globals::Esp::HealthBarGlow = e["HealthBarGlow"];
            if (e.contains("HealthBarColorType")) Globals::Esp::HealthBarColorType = e["HealthBarColorType"];
            if (e.contains("Team")) Globals::Esp::Team = e["Team"];
            if (e.contains("TeamMode")) Globals::Esp::TeamMode = e["TeamMode"];
            if (e.contains("Leaderstats")) Globals::Esp::Leaderstats = e["Leaderstats"];
            if (e.contains("Region")) Globals::Esp::Region = e["Region"];
            if (e.contains("LocalPlayerESP")) Globals::Esp::LocalPlayerESP = e["LocalPlayerESP"];
            if (e.contains("Font")) Globals::Esp::Font = e["Font"];
            if (e.contains("MaxDistance")) Globals::Esp::MaxDistance = e["MaxDistance"];
            if (e.contains("MaxDistanceValue")) Globals::Esp::MaxDistanceValue = e["MaxDistanceValue"];
            if (e.contains("KeybindList")) Globals::Esp::KeybindList = e["KeybindList"];
            if (e.contains("ChamsOutlineThickness")) Globals::Esp::ChamsOutlineThickness = e["ChamsOutlineThickness"];
            if (e.contains("InheritBodyColorChams")) Globals::Esp::InheritBodyColorChams = e["InheritBodyColorChams"];
            if (e.contains("FilterUnknownChamsParts")) Globals::Esp::FilterUnknownChamsParts = e["FilterUnknownChamsParts"];
            if (e.contains("Tracers")) Globals::Esp::Tracers = e["Tracers"];
            if (e.contains("Skeleton")) Globals::Esp::Skeleton = e["Skeleton"];
            if (e.contains("TracersPosition")) Globals::Esp::TracersPosition = e["TracersPosition"];
            if (e.contains("ChamsMaterial")) Globals::Esp::ChamsMaterial = e["ChamsMaterial"];
            if (e.contains("OffscreenArrows")) Globals::Esp::OffscreenArrows = e["OffscreenArrows"];
            if (e.contains("OffscreenArrowSize")) Globals::Esp::OffscreenArrowSize = e["OffscreenArrowSize"];
            if (e.contains("OffscreenArrowPadding")) Globals::Esp::OffscreenArrowPadding = e["OffscreenArrowPadding"];
            if (e.contains("OffscreenArrowMinDist")) Globals::Esp::OffscreenArrowMinDist = e["OffscreenArrowMinDist"];
            if (e.contains("DroppedGun")) Globals::Esp::DroppedGun = e["DroppedGun"];

            if (e.contains("Colors")) {
                auto& c = e["Colors"];
                auto read4 = [&](const std::string& key, float* arr) {
                    if (c.contains(key) && c[key].is_array() && c[key].size() == 4)
                        for (int i = 0; i < 4; i++) arr[i] = c[key][i];
                };
                read4("Skeleton", Globals::Esp::Colors::Skeleton);
                read4("Tracers", Globals::Esp::Colors::Tracers);
                read4("Box", Globals::Esp::Colors::Box);
                read4("BoxGlow", Globals::Esp::Colors::BoxGlow);
                read4("Name", Globals::Esp::Colors::Name);
                read4("Distance", Globals::Esp::Colors::Distance);
                read4("Tool", Globals::Esp::Colors::Tool);
                read4("Chams", Globals::Esp::Colors::Chams);
                read4("ChamsGlow", Globals::Esp::Colors::ChamsGlow);
                read4("ChamsOutlines", Globals::Esp::Colors::ChamsOutlines);
                read4("HealthBarGlow", Globals::Esp::Colors::HealthBarGlow);
                read4("HealthBar", Globals::Esp::Colors::HealthBar);
                read4("HealthNumber", Globals::Esp::Colors::HealthNumber);
                read4("Region", Globals::Esp::Colors::Region);
                read4("LeaderStats", Globals::Esp::Colors::LeaderStats);
                read4("Murderer", Globals::Esp::Colors::Murderer);
                read4("Sheriff", Globals::Esp::Colors::Sheriff);
                read4("Innocent", Globals::Esp::Colors::Innocent);
                read4("OffscreenArrow", Globals::Esp::OffscreenArrowColor);
                read4("DroppedGun", Globals::Esp::Colors::DroppedGun);
            }
        }

        if (j.contains("Misc")) {
            auto& m = j["Misc"];
            if (m.contains("TeamCheck")) Globals::Misc::TeamCheck = m["TeamCheck"];
            if (m.contains("StreamProof")) Globals::Misc::StreamProof = m["StreamProof"];
            if (m.contains("Desync")) Globals::Misc::Desync = m["Desync"];
            if (m.contains("DesyncBind")) Globals::Misc::DesyncBind.Load(m["DesyncBind"]);
        }

        if (j.contains("Raycast")) {
            auto& r = j["Raycast"];
            if (r.contains("Enabled")) Globals::Raycast::Enabled = r["Enabled"];
            if (r.contains("Method")) Globals::Raycast::Method = r["Method"];
            if (r.contains("Delay")) Globals::Raycast::Delay = r["Delay"];
            if (r.contains("VisibleCheck")) Globals::Raycast::VisibleCheck = r["VisibleCheck"];
            if (r.contains("AimMode")) Globals::Raycast::AimMode = r["AimMode"];
            if (r.contains("Preview")) Globals::Raycast::Preview = r["Preview"];
        }

        if (j.contains("Aimbot")) {
            auto& a = j["Aimbot"];
            if (a.contains("Enabled")) Globals::Aimbot::Enabled = a["Enabled"];
            if (a.contains("AimbotKey")) Globals::Aimbot::AimbotKey.Load(a["AimbotKey"]);
            if (a.contains("Hitbox")) Globals::Aimbot::Hitbox = a["Hitbox"];
            if (a.contains("VisibleCheck")) Globals::Aimbot::VisibleCheck = a["VisibleCheck"];
            if (a.contains("SilentMode")) Globals::Aimbot::SilentMode = a["SilentMode"];
            if (a.contains("SilentCrosshair")) Globals::Aimbot::SilentCrosshair = a["SilentCrosshair"];
            if (a.contains("SilentCrosshairTracer")) Globals::Aimbot::SilentCrosshairTracer = a["SilentCrosshairTracer"];
            if (a.contains("SilentCrosshairTracerColor") && a["SilentCrosshairTracerColor"].is_array() && a["SilentCrosshairTracerColor"].size() == 4)
                for (int i = 0; i < 4; i++) Globals::Aimbot::SilentCrosshairTracerColor[i] = a["SilentCrosshairTracerColor"][i];
            if (a.contains("AimType")) Globals::Aimbot::AimType = a["AimType"];
            if (a.contains("Prediction")) Globals::Aimbot::Prediction = a["Prediction"];
            if (a.contains("PredictionX")) Globals::Aimbot::PredictionX = a["PredictionX"];
            if (a.contains("PredictionY")) Globals::Aimbot::PredictionY = a["PredictionY"];
            if (a.contains("EnableFOV")) Globals::Aimbot::EnableFOV = a["EnableFOV"];
            if (a.contains("DrawFOV")) Globals::Aimbot::DrawFOV = a["DrawFOV"];
            if (a.contains("FOV")) Globals::Aimbot::FOV = a["FOV"];
            if (a.contains("Smoothning")) Globals::Aimbot::Smoothning = a["Smoothning"];
            if (a.contains("SmoothingValue")) Globals::Aimbot::SmoothingValue = a["SmoothingValue"];
            if (a.contains("FovColor") && a["FovColor"].is_array() && a["FovColor"].size() == 4)
                for (int i = 0; i < 4; i++) Globals::Aimbot::FovColor[i] = a["FovColor"][i];
            if (a.contains("FovSettings")) {
                if (a["FovSettings"].contains("FillFov")) Globals::Aimbot::FovSettings::FillFov = a["FovSettings"]["FillFov"];
                if (a["FovSettings"].contains("FillColor") && a["FovSettings"]["FillColor"].is_array() && a["FovSettings"]["FillColor"].size() == 4)
                    for (int i = 0; i < 4; i++) Globals::Aimbot::FovSettings::FillColor[i] = a["FovSettings"]["FillColor"][i];
            }
            if (a.contains("Rage")) {
                if (a["Rage"].contains("SpamTP")) Globals::Aimbot::Rage::SpamTP = a["Rage"]["SpamTP"];
                if (a["Rage"].contains("Orbit")) Globals::Aimbot::Rage::Orbit = a["Rage"]["Orbit"];
                if (a["Rage"].contains("MagicBullet")) Globals::Aimbot::Rage::MagicBullet = a["Rage"]["MagicBullet"];
                if (a["Rage"].contains("RageBot")) Globals::Aimbot::Rage::RageBot = a["Rage"]["RageBot"];
                if (a["Rage"].contains("RageBotMode")) Globals::Aimbot::Rage::RageBotMode = a["Rage"]["RageBotMode"];
                if (a["Rage"].contains("OrbitSettings")) {
                    auto& o = a["Rage"]["OrbitSettings"];
                    if (o.contains("radius")) Globals::Aimbot::Rage::OrbitSettings::radius = o["radius"];
                    if (o.contains("orbitSpeed")) Globals::Aimbot::Rage::OrbitSettings::orbitSpeed = o["orbitSpeed"];
                    if (o.contains("heightOffset")) Globals::Aimbot::Rage::OrbitSettings::heightOffset = o["heightOffset"];
                }
            }
            if (a.contains("Hits")) {
                auto& h = a["Hits"];
                if (h.contains("HitSounds")) Globals::Aimbot::Hits::HitSounds = h["HitSounds"];
                if (h.contains("HitSound")) Globals::Aimbot::Hits::HitSound = h["HitSound"];
                if (h.contains("HitTracers")) Globals::Aimbot::Hits::HitTracers = h["HitTracers"];
                if (h.contains("HitMarkers")) Globals::Aimbot::Hits::HitMarkers = h["HitMarkers"];
                if (h.contains("HitTracersColor") && h["HitTracersColor"].is_array() && h["HitTracersColor"].size() == 4)
                    for (int i = 0; i < 4; i++) Globals::Aimbot::Hits::HitTracersColor[i] = h["HitTracersColor"][i];
                if (h.contains("HitMarkersColor") && h["HitMarkersColor"].is_array() && h["HitMarkersColor"].size() == 4)
                    for (int i = 0; i < 4; i++) Globals::Aimbot::Hits::HitMarkersColor[i] = h["HitMarkersColor"][i];
            }
        }

        if (j.contains("Exploits") && j["Exploits"].contains("Animation")) {
            auto& an = j["Exploits"]["Animation"];
            if (an.contains("Enabled")) Globals::Exploits::AnimationEnabled = an["Enabled"];
            if (an.contains("Idle")) Globals::Exploits::AnimationIdle = an["Idle"];
            if (an.contains("Run")) Globals::Exploits::AnimationRun = an["Run"];
            if (an.contains("Walk")) Globals::Exploits::AnimationWalk = an["Walk"];
            if (an.contains("Jump")) Globals::Exploits::AnimationJump = an["Jump"];
            if (an.contains("Fall")) Globals::Exploits::AnimationFall = an["Fall"];
            if (an.contains("Climb")) Globals::Exploits::AnimationClimb = an["Climb"];
            if (an.contains("Swim")) Globals::Exploits::AnimationSwim = an["Swim"];
        }
        if (j.contains("Exploits") && j["Exploits"].contains("AnimationPack"))
            Globals::Exploits::AnimationPack = j["Exploits"]["AnimationPack"];

        if (j.contains("TriggerBot")) {
            auto& t = j["TriggerBot"];
            if (t.contains("Enabled")) Globals::TriggerBot::Enabled = t["Enabled"];
            if (t.contains("Key")) Globals::TriggerBot::Key.Load(t["Key"]);
            if (t.contains("VisibleCheck")) Globals::TriggerBot::VisibleCheck = t["VisibleCheck"];
            if (t.contains("Delay")) Globals::TriggerBot::Delay = t["Delay"];
            if (t.contains("Threshold")) Globals::TriggerBot::Threshold = t["Threshold"];
            if (t.contains("ToolCheck")) Globals::TriggerBot::ToolCheck = t["ToolCheck"];
        }

        if (j.contains("World")) {
            auto& w = j["World"];
            if (w.contains("LocalPlayerForceField")) Globals::World::LocalPlayerForceField = w["LocalPlayerForceField"];
            if (w.contains("CameraFOV")) Globals::World::CameraFOV = w["CameraFOV"];
            if (w.contains("CameraFOVValue")) Globals::World::CameraFOVValue = w["CameraFOVValue"];
            if (w.contains("Zoom")) Globals::World::Zoom = w["Zoom"];
            if (w.contains("ZoomKey")) Globals::World::ZoomKey.Load(w["ZoomKey"]);
            if (w.contains("ZoomValue")) Globals::World::ZoomValue = w["ZoomValue"];
            if (w.contains("AmbientColor") && w["AmbientColor"].is_array() && w["AmbientColor"].size() == 3)
                for (int i = 0; i < 3; i++) Globals::World::AmbientColor[i] = w["AmbientColor"][i];
            if (w.contains("OutdoorAmbientColor") && w["OutdoorAmbientColor"].is_array() && w["OutdoorAmbientColor"].size() == 3)
                for (int i = 0; i < 3; i++) Globals::World::OutdoorAmbientColor[i] = w["OutdoorAmbientColor"][i];

            if (w.contains("Waypoints")) {
                if (w["Waypoints"].contains("WaypointName")) Globals::World::Waypoints::WaypointName = w["Waypoints"]["WaypointName"];
                if (w["Waypoints"].contains("WaypointDistance")) Globals::World::Waypoints::WaypointDistance = w["Waypoints"]["WaypointDistance"];
                if (w["Waypoints"].contains("Colors")) {
                    auto& wc = w["Waypoints"]["Colors"];
                    if (wc.contains("WaypointName") && wc["WaypointName"].is_array() && wc["WaypointName"].size() == 4)
                        for (int i = 0; i < 4; i++) Globals::World::Waypoints::Colors::WaypointName[i] = wc["WaypointName"][i];
                    if (wc.contains("WaypointDistance") && wc["WaypointDistance"].is_array() && wc["WaypointDistance"].size() == 4)
                        for (int i = 0; i < 4; i++) Globals::World::Waypoints::Colors::WaypointDistance[i] = wc["WaypointDistance"][i];
                }
            }

            if (w.contains("Movement")) {
                auto& m = w["Movement"];
                if (m.contains("InfiniteJump")) Globals::World::Movement::InfiniteJump = m["InfiniteJump"];
                if (m.contains("CustomJumpPower")) Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPower = m["CustomJumpPower"];
                if (m.contains("CustomJumpPowerValue")) Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPowerValue = m["CustomJumpPowerValue"];
                if (m.contains("Fly")) Globals::World::Movement::Fly = m["Fly"];
                if (m.contains("FlyMethod")) Globals::World::Movement::FlyMethod = m["FlyMethod"];
                if (m.contains("FlySpeed")) Globals::World::Movement::FlySpeed = m["FlySpeed"];
                if (m.contains("FlyKey")) Globals::World::Movement::FlyKey.Load(m["FlyKey"]);
                if (m.contains("Speed")) Globals::World::Movement::Speed = m["Speed"];
                if (m.contains("SpeedMethod")) Globals::World::Movement::SpeedMethod = m["SpeedMethod"];
                if (m.contains("SpeedValue")) Globals::World::Movement::SpeedValue = m["SpeedValue"];
                if (m.contains("SpeedKey")) Globals::World::Movement::SpeedKey.Load(m["SpeedKey"]);
                if (m.contains("Noclip")) Globals::World::Movement::Noclip = m["Noclip"];
                if (m.contains("NoclipKey")) Globals::World::Movement::NoclipKey.Load(m["NoclipKey"]);
                if (m.contains("Freecam")) Globals::World::Movement::Freecam = m["Freecam"];
                if (m.contains("FreecamSpeed")) Globals::World::Movement::FreecamSpeed = m["FreecamSpeed"];
                if (m.contains("FreecamKey")) Globals::World::Movement::FreecamKey.Load(m["FreecamKey"]);
                    if (m.contains("ThirdPerson")) Globals::World::Movement::ThirdPerson = m["ThirdPerson"];
                    if (m.contains("ThirdPersonX")) Globals::World::Movement::ThirdPersonX = m["ThirdPersonX"];
                    if (m.contains("ThirdPersonY")) Globals::World::Movement::ThirdPersonY = m["ThirdPersonY"];
                    if (m.contains("ThirdPersonZ")) Globals::World::Movement::ThirdPersonZ = m["ThirdPersonZ"];
                    if (m.contains("ThirdPersonKey")) Globals::World::Movement::ThirdPersonKey.Load(m["ThirdPersonKey"]);
                if (m.contains("AntiAimKey")) Globals::World::Movement::AntiAimKey.Load(m["AntiAimKey"]);
                if (m.contains("Spinbot")) Globals::World::Movement::Spinbot = m["Spinbot"];
                if (m.contains("SpinbotSpeed")) Globals::World::Movement::SpinbotSpeed = m["SpinbotSpeed"];
                if (m.contains("UpsideDown")) Globals::World::Movement::UpsideDown = m["UpsideDown"];
                if (m.contains("WalkSpeed")) Globals::World::Movement::WalkSpeed = m["WalkSpeed"];
                if (m.contains("WalkSpeedValue")) Globals::World::Movement::WalkSpeedValue = m["WalkSpeedValue"];
                if (m.contains("AntiAimPitch")) Globals::World::Movement::AntiAimPitch = m["AntiAimPitch"];
                if (m.contains("AntiAimYaw")) Globals::World::Movement::AntiAimYaw = m["AntiAimYaw"];
                if (m.contains("Peek")) Globals::World::Movement::Peek = m["Peek"];
                if (m.contains("PeekKey")) Globals::World::Movement::PeekKey.Load(m["PeekKey"]);
                if (m.contains("PeekRadius")) Globals::World::Movement::PeekRadius = m["PeekRadius"];
                if (m.contains("PeekColor") && m["PeekColor"].is_array() && m["PeekColor"].size() == 4)
                    for (int i = 0; i < 4; i++) Globals::World::Movement::PeekColor[i] = m["PeekColor"][i];
                if (m.contains("PeekClickTP")) Globals::World::Movement::PeekClickTP = m["PeekClickTP"];
            }
            if (j["World"].contains("TimeManipulation")) Globals::World::TimeManipulation = j["World"]["TimeManipulation"];
            if (j["World"].contains("TimeManipulationValue")) Globals::World::TimeManipulationValue = j["World"]["TimeManipulationValue"];
        }

        if (j.contains("DockBar")) {
            auto& d = j["DockBar"];
            if (d.contains("Home")) Globals::DockBar_Home = d["Home"];
            if (d.contains("Style")) Globals::DockBar_Style = d["Style"];
            if (d.contains("EspPreview")) Globals::DockBar_EspPreview = d["EspPreview"];
            if (d.contains("TargetHud")) Globals::DockBar_TargetHud = d["TargetHud"];
            if (d.contains("Explorer")) Globals::DockBar_Explorer = d["Explorer"];
            if (d.contains("Players")) Globals::DockBar_Players = d["Players"];
            if (d.contains("Keybinds")) Globals::DockBar_Keybinds = d["Keybinds"];
            if (d.contains("Anims")) Globals::DockBar_Anims = d["Anims"];
        }
    }

    inline void SaveGlobalSettings()
    {
        nlohmann::json j;
        j["RiskyFunctions"] = Globals::Misc::RiskyFunctions;
        std::ofstream file("C:\\Skidware\\globals.rocks");
        if (file.is_open()) file << j.dump(4);
    }

    inline void LoadGlobalSettings()
    {
        std::ifstream file("C:\\Skidware\\globals.rocks");
        if (!file.is_open()) return;
        try {
            nlohmann::json j;
            file >> j;
            if (j.contains("RiskyFunctions")) Globals::Misc::RiskyFunctions = j["RiskyFunctions"];
        }
        catch (...) {}
    }

    // Flips every risky feature off so nothing keeps running while the
    // Risky Functions toggle is disabled.
    inline void DisableAllRiskyFeatures()
    {
        Globals::World::Movement::Fly = false;
        Globals::World::Movement::Speed = false;
        Globals::World::Movement::Noclip = false;
        Globals::World::Movement::WalkSpeed = false;
        Globals::World::Movement::Spinbot = false;
        Globals::World::Movement::UpsideDown = false;
        Globals::World::Movement::AntiAimYaw = 0;
        Globals::World::Movement::AntiAimPitch = 0;
        Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPower = false;
        Globals::World::Movement::Peek = false;
        Globals::World::Movement::PeekActive = false;
        Globals::Misc::Desync = false;
        Globals::Aimbot::Rage::SpamTP = false;
        Globals::Aimbot::Rage::Orbit = false;
    }

    inline void SaveConfig(uint64_t gameId)
    {
        if (gameId == 0) return;
        std::string path = "C:\\Skidware\\Configs\\" + std::to_string(gameId) + ".rocks";
        auto j = SerializeGlobals();
        std::ofstream file(path);
        file << j.dump(4);
        PushNotification("Config saved for GameID " + std::to_string(gameId));
        Logging::Log(Logging::LogType::INFO, xorstr_("Config saved for GameID %llu"), gameId);
    }

    inline bool LoadConfig(uint64_t gameId)
    {
        if (gameId == 0) return false;
        std::string path = "C:\\Skidware\\Configs\\" + std::to_string(gameId) + ".rocks";
        if (!std::filesystem::exists(path)) return false;
        PushNotification("Loading config for GameID " + std::to_string(gameId));
        std::ifstream file(path);
        if (!file.is_open()) return false;
        try {
            nlohmann::json j;
            file >> j;
            DeserializeGlobals(j);
            PushNotification("Config loaded for GameID " + std::to_string(gameId));
            Logging::Log(Logging::LogType::INFO, xorstr_("Config loaded for GameID %llu"), gameId);
            return true;
        }
        catch (...) {
            PushNotification("Failed to load config for GameID " + std::to_string(gameId));
            Logging::Log(Logging::LogType::ERR, xorstr_("Failed to load config for GameID %llu"), gameId);
            return false;
        }
    }

    inline void ResetDefaults()
    {
        Globals::Watermark = false;
        Globals::Vsync = false;

        Globals::Esp::Enabled = false;
        Globals::Esp::Box = false;
        Globals::Esp::BoxGlow = false;
        Globals::Esp::Name = false;
        Globals::Esp::UseDisplayName = false;
        Globals::Esp::Distance = false;
        Globals::Esp::Tool = false;
        Globals::Esp::Chams = false;
        Globals::Esp::Avatar = false;
        Globals::Esp::IconSize = 32;
        Globals::Esp::OffsetOffBoxAvatar = 11;
        Globals::Esp::ChamsType = 0;
        Globals::Esp::ChamsGlow = false;
        Globals::Esp::ChamsOutlines = false;
        Globals::Esp::HealthBar = false;
        Globals::Esp::HealthNumber = false;
        Globals::Esp::HealthBarBackGround = false;
        Globals::Esp::HealthBarGlow = false;
        Globals::Esp::HealthBarColorType = 0;
        Globals::Esp::Team = false;
        Globals::Esp::TeamMode = 0;
        Globals::Esp::Leaderstats = false;
        Globals::Esp::Region = false;
        Globals::Esp::LocalPlayerESP = false;
        Globals::Esp::Font = 0;
        Globals::Esp::MaxDistance = false;
        Globals::Esp::MaxDistanceValue = 1000;
        Globals::Esp::KeybindList = false;
        Globals::Esp::ChamsOutlineThickness = 1.0f;
        Globals::Esp::InheritBodyColorChams = false;
        Globals::Esp::FilterUnknownChamsParts = false;
        Globals::Esp::Tracers = false;
        Globals::Esp::Skeleton = false;
        Globals::Esp::TracersPosition = 0;
        Globals::Esp::ChamsMaterial = 0;
        Globals::Esp::OffscreenArrows = false;
        for (int i = 0; i < 4; i++) Globals::Esp::OffscreenArrowColor[i] = 1.0f;
        Globals::Esp::OffscreenArrowSize = 20.0f;
        Globals::Esp::OffscreenArrowPadding = 50.0f;
        Globals::Esp::OffscreenArrowMinDist = 5;
        Globals::Esp::DroppedGun = false;
        for (int i = 0; i < 4; i++) Globals::Esp::Colors::DroppedGun[i] = 1.0f;
        Globals::Esp::Colors::DroppedGun[0] = 0.0f;
        Globals::Esp::Colors::DroppedGun[1] = 0.7f;
        Globals::Esp::Colors::DroppedGun[2] = 1.0f;

        Globals::Misc::TeamCheck = false;
        Globals::Misc::StreamProof = false;
        Globals::Misc::Desync = false;

        Globals::Raycast::Enabled = false;
        Globals::Raycast::Method = 0;
        Globals::Raycast::Delay = 50;
        Globals::Raycast::VisibleCheck = false;
        Globals::Raycast::AimMode = 0;
        Globals::Raycast::Preview = false;

        Globals::Aimbot::Enabled = false;
        Globals::Aimbot::Hitbox = 0;
        Globals::Aimbot::VisibleCheck = false;
        Globals::Aimbot::AimType = 0;
        Globals::Aimbot::SilentMode = 0;
        Globals::Aimbot::SilentCrosshair = false;
        Globals::Aimbot::SilentCrosshairTracer = false;
        for (int i = 0; i < 4; i++) Globals::Aimbot::SilentCrosshairTracerColor[i] = 1.0f;
        Globals::Aimbot::Prediction = false;
        Globals::Aimbot::PredictionX = 1;
        Globals::Aimbot::PredictionY = 1;
        Globals::Aimbot::EnableFOV = false;
        Globals::Aimbot::DrawFOV = true;
        Globals::Aimbot::FOV = 60;
        for (int i = 0; i < 4; i++) Globals::Aimbot::FovColor[i] = 1.0f;
        Globals::Aimbot::Smoothning = false;
        Globals::Aimbot::SmoothingValue = 0.1f;
        Globals::Aimbot::Rage::SpamTP = false;
        Globals::Aimbot::Rage::Orbit = false;
        Globals::Aimbot::Rage::MagicBullet = false;
        Globals::Aimbot::FovSettings::FillFov = false;
        for (int i = 0; i < 4; i++) Globals::Aimbot::FovSettings::FillColor[i] = 1.0f;
        Globals::Aimbot::FovSettings::FillColor[3] = 0.3f;
        Globals::Aimbot::Rage::RageBot = false;
        Globals::Aimbot::Rage::RageBotMode = 0;
        Globals::Aimbot::Rage::OrbitSettings::radius = 1.0f;
        Globals::Aimbot::Rage::OrbitSettings::orbitSpeed = 100.0f;
        Globals::Aimbot::Rage::OrbitSettings::heightOffset = 10.0f;
        Globals::Aimbot::Hits::HitSounds = false;
        Globals::Aimbot::Hits::HitSound = 0;
        Globals::Aimbot::Hits::HitTracers = false;
        Globals::Aimbot::Hits::HitMarkers = false;
        for (int i = 0; i < 4; i++) Globals::Aimbot::Hits::HitTracersColor[i] = 1.0f;
        for (int i = 0; i < 4; i++) Globals::Aimbot::Hits::HitMarkersColor[i] = 1.0f;

        Globals::TriggerBot::Enabled = false;
        Globals::TriggerBot::VisibleCheck = false;
        Globals::TriggerBot::Delay = 0;
        Globals::TriggerBot::Threshold = 0;
        Globals::TriggerBot::ToolCheck = false;

        Globals::Exploits::AnimationEnabled = false;
        Globals::Exploits::AnimationPack = 0;
        Globals::Exploits::AnimationIdle = 0;
        Globals::Exploits::AnimationRun = 0;
        Globals::Exploits::AnimationWalk = 0;
        Globals::Exploits::AnimationJump = 0;
        Globals::Exploits::AnimationFall = 0;
        Globals::Exploits::AnimationClimb = 0;
        Globals::Exploits::AnimationSwim = 0;

        Globals::World::LocalPlayerForceField = false;
        Globals::World::CameraFOV = false;
        Globals::World::CameraFOVValue = 90;
        Globals::World::Zoom = false;
        Globals::World::ZoomValue = 30;
        Globals::World::Waypoints::WaypointName = false;
        Globals::World::Waypoints::WaypointDistance = false;
        for (int i = 0; i < 4; i++) Globals::World::Waypoints::Colors::WaypointName[i] = 1.0f;
        for (int i = 0; i < 4; i++) Globals::World::Waypoints::Colors::WaypointDistance[i] = 1.0f;
        Globals::World::Movement::InfiniteJump = false;
        Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPower = false;
        Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPowerValue = 50.0f;
        Globals::World::Movement::Fly = false;
        Globals::World::Movement::FlyMethod = 0;
        Globals::World::Movement::FlySpeed = 1.0f;
        Globals::World::Movement::Speed = false;
        Globals::World::Movement::SpeedMethod = 0;
        Globals::World::Movement::SpeedValue = 1.0f;
        Globals::World::Movement::Noclip = false;
        Globals::World::Movement::Freecam = false;
        Globals::World::Movement::FreecamSpeed = 0.01f;
        Globals::World::Movement::ThirdPerson = false;
        Globals::World::Movement::ThirdPersonX = 0.0f;
        Globals::World::Movement::ThirdPersonY = 3.0f;
        Globals::World::Movement::ThirdPersonZ = 3.0f;
        Globals::World::Movement::Spinbot = false;
        Globals::World::Movement::SpinbotSpeed = 5;
        Globals::World::Movement::UpsideDown = false;
        Globals::World::Movement::WalkSpeed = false;
        Globals::World::Movement::WalkSpeedValue = 16.0f;
        Globals::World::Movement::AntiAimPitch = 0;
        Globals::World::Movement::AntiAimYaw = 0;
        Globals::World::Movement::Peek = false;
        Globals::World::Movement::PeekRadius = 5.0f;
        for (int i = 0; i < 4; i++) Globals::World::Movement::PeekColor[i] = 1.0f;
        Globals::World::Movement::PeekColor[3] = 0.5f;
        Globals::World::Movement::PeekClickTP = false;
        Globals::World::TimeManipulation = false;
        Globals::World::TimeManipulationValue = 240.0f;

        Globals::DockBar_Home = true;
        Globals::DockBar_Style = false;
        Globals::DockBar_EspPreview = false;
        Globals::DockBar_TargetHud = false;
        Globals::DockBar_Explorer = false;
        Globals::DockBar_Players = false;
        Globals::DockBar_Keybinds = false;
        Globals::DockBar_Anims = false;

        Logging::Log(Logging::LogType::INFO, xorstr_("Config reset to defaults"));
    }

    inline void CheckGameIdChange()
    {
        CurrentGameId = Globals::GameID;

        // Lobby / menu state: we still sit in the DataModel but the gameId is the
        // Roblox menu universe. Track that we are NOT in a real game so we don't
        // load the previous game's config.
        InGame = CurrentGameId != 0;

        if (CurrentGameId != PreviousGameId)
        {
            // Save the config of the game we just left (including back to lobby).
            if (PreviousGameId != 0)
                SaveConfig(PreviousGameId);

            PreviousGameId = CurrentGameId;

            if (CurrentGameId != 0)
            {
                PushNotification("New GameID: " + std::to_string(CurrentGameId));
                if (!LoadConfig(CurrentGameId)) {
                    PushNotification("No saved config, using defaults");
                    Logging::Log(Logging::LogType::INFO, xorstr_("No saved config for GameID %llu, using defaults"), CurrentGameId);
                    ResetDefaults();
                }
            }
            else
            {
                PushNotification("Lobby / not in a game");
                Logging::Log(Logging::LogType::INFO, xorstr_("GameID is 0, in lobby/not in a game"));
                // Leaving a game: unload whatever was loaded so stale settings
                // (risky toggles included) don't linger in the lobby or leak
                // into the next game before its config is applied.
                ResetDefaults();
            }
        }
    }
}
