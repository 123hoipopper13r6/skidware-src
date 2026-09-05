#include "Esp.h"
#include "../../Includes.hpp"
#include <unordered_map>
ImColor FTC(float* color) {
    return ImColor(color[0], color[1], color[2], color[3]);
}
ImColor FTCNoAlpha(float* color) {
    return ImColor(color[0], color[1], color[2], color[3]);
}
ImColor TeamOverride(SDK::Cache::Player& player, float* fallback) {
    if (Globals::Esp::Team && Globals::Esp::TeamMode >= 1 && player.TeamColor.Value.w > 0.f) {
        ImColor tc = player.TeamColor;
        return ImColor(tc.Value.x, tc.Value.y, tc.Value.z, fallback[3]);
    }
    return FTC(fallback);
}

SDK::Vector2 RawProject(SDK::Vector3 WorldPosition)
{
    SDK::Matrix4 ViewMatrix = SDK::VisualEngineCache::ViewMatrix;
    SDK::Vector2 Dimensions = SDK::VisualEngineCache::Dimensions;
    SDK::Vector4 Q;
    Q.x = (WorldPosition.x * ViewMatrix.data[0]) + (WorldPosition.y * ViewMatrix.data[1]) + (WorldPosition.z * ViewMatrix.data[2]) + ViewMatrix.data[3];
    Q.y = (WorldPosition.x * ViewMatrix.data[4]) + (WorldPosition.y * ViewMatrix.data[5]) + (WorldPosition.z * ViewMatrix.data[6]) + ViewMatrix.data[7];
    Q.z = (WorldPosition.x * ViewMatrix.data[8]) + (WorldPosition.y * ViewMatrix.data[9]) + (WorldPosition.z * ViewMatrix.data[10]) + ViewMatrix.data[11];
    Q.w = (WorldPosition.x * ViewMatrix.data[12]) + (WorldPosition.y * ViewMatrix.data[13]) + (WorldPosition.z * ViewMatrix.data[14]) + ViewMatrix.data[15];
    if (Q.w < 0.1f || std::isnan(Q.w) || std::isinf(Q.w))
    {
        Q.x = -Q.x; Q.y = -Q.y;
    }
    SDK::Vector3 NDC;
    NDC.x = Q.x / Q.w;
    NDC.y = Q.y / Q.w;
    SDK::Vector2 ScreenPosition =
    {
        (Dimensions.x / 2 * NDC.x) + (Dimensions.x / 2),
        -(Dimensions.y / 2 * NDC.y) + (Dimensions.y / 2),
    };
    return ScreenPosition;
}
struct PlayerESPState {
    float smoothHealth = 0.0f;
};

std::unordered_map<std::uintptr_t, PlayerESPState> playerESPStates;
struct HitMarker
{
    Hacks::Esp::HitMarker3D Start;
    Hacks::Esp::HitMarker3D End;
    std::chrono::steady_clock::time_point TimeInserted;
};
std::vector<HitMarker> RegisteredHits = {};
void Hacks::Esp::InsertHitMarker(HitMarker3D Start, HitMarker3D End)
{
    HitMarker Hit;
    SDK::Vector2 One = SDK::WorldToScreen(SDK::Vector3(Start.x, Start.y, Start.z));
    SDK::Vector2 Two = SDK::WorldToScreen(SDK::Vector3(End.x, End.y, End.z));
    Hit.Start = Start;
    Hit.End = End;
    Hit.TimeInserted = std::chrono::steady_clock::now();
    RegisteredHits.push_back(Hit);
}
void RenderHits(ImDrawList* Draw)
{
    if (RegisteredHits.size() == 0)
        return;

    std::chrono::steady_clock::time_point CurrentTime = std::chrono::steady_clock::now();

    for (int i = 0; i < RegisteredHits.size(); ++i)
    {
        std::chrono::milliseconds ElapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - RegisteredHits[i].TimeInserted);
        if (ElapsedTime.count() >= 10000) {
            RegisteredHits.erase(RegisteredHits.begin() + i);
            --i;
            continue;
        }
        SDK::Vector2 One = SDK::WorldToScreen(SDK::Vector3(RegisteredHits[i].Start.x, RegisteredHits[i].Start.y, RegisteredHits[i].Start.z));
        SDK::Vector2 Two = SDK::WorldToScreen(SDK::Vector3(RegisteredHits[i].End.x, RegisteredHits[i].End.y, RegisteredHits[i].End.z));
        if (One.x == -1 || Two.x == -1)
            continue;
        if (Globals::Aimbot::Hits::HitTracers)
        {
            Draw->AddLine(
                { One.x, One.y },
                { Two.x, Two.y },
                ImColor(0, 0, 0),
                3.0f
            );
            Draw->AddLine(
                { One.x, One.y },
                { Two.x, Two.y },
                FTCNoAlpha(Globals::Aimbot::Hits::HitTracersColor),
                2.0f
            );
        }
        float gap = 2.0f;
        float half = 6.0f;

        if (Globals::Aimbot::Hits::HitMarkers)
        {
            Draw->AddLine(
                { Two.x - half, Two.y - half },
                { Two.x - gap,  Two.y - gap },
                ImColor(0, 0, 0),
                2.0f
            );
            Draw->AddLine(
                { Two.x - half, Two.y - half },
                { Two.x - gap,  Two.y - gap },
                FTCNoAlpha(Globals::Aimbot::Hits::HitMarkersColor)
            );
            Draw->AddLine(
                { Two.x + gap,  Two.y + gap },
                { Two.x + half, Two.y + half },
                ImColor(0, 0, 0),
                2.0f
            );
            Draw->AddLine(
                { Two.x + gap,  Two.y + gap },
                { Two.x + half, Two.y + half },
                FTCNoAlpha(Globals::Aimbot::Hits::HitMarkersColor)
            );
            Draw->AddLine(
                { Two.x - half, Two.y + half },
                { Two.x - gap,  Two.y + gap },
                ImColor(0, 0, 0),
                2.0f
            );
            Draw->AddLine(
                { Two.x - half, Two.y + half },
                { Two.x - gap,  Two.y + gap },
                FTCNoAlpha(Globals::Aimbot::Hits::HitMarkersColor)
            );
            Draw->AddLine(
                { Two.x + gap,  Two.y - gap },
                { Two.x + half, Two.y - half },
                ImColor(0, 0, 0),
                2.0f
            );
            Draw->AddLine(
                { Two.x + gap,  Two.y - gap },
                { Two.x + half, Two.y - half },
                FTCNoAlpha(Globals::Aimbot::Hits::HitMarkersColor)
            );
        }
    }
}
void Hacks::Esp::RenderRaycastPreview(ImDrawList* Draw)
{
    if (!Globals::Raycast::Preview || !Globals::Raycast::Enabled)
        return;
    try
    {
        SDK::Camera Cam = (SDK::Camera)Globals::Workspace.FindFirstChildOfClass("Camera");
        if (!Cam.Address)
            return;
        SDK::Vector3 camPos;
        try { camPos = Cam.CameraPosition(); } catch (...) { return; }
        if (std::isnan(camPos.x) || std::isnan(camPos.y) || std::isnan(camPos.z))
            return;

        // camera look direction, used only to give the line a valid start point
        // (projecting the exact camera position sits on the near plane and
        // WorldToScreen rejects it, which hid the line in first person)
        SDK::Vector3 camForward(0.0f, 0.0f, 1.0f);
        try
        {
            SDK::Matrix3 CamRot = Cam.CameraRotation();
            camForward = SDK::Vector3(CamRot.data[2], CamRot.data[2 + 3], CamRot.data[2 + 6]);
        }
        catch (...)
        {
            camForward = SDK::Vector3(0.0f, 0.0f, 1.0f);
        }

        POINT cursor_point;
        if (!GetCursorPos(&cursor_point) || !Globals::RobloxWindow)
            return;
        if (!ScreenToClient(Globals::RobloxWindow, &cursor_point))
            return;
        SDK::Vector2 cursor = { static_cast<float>(cursor_point.x), static_cast<float>(cursor_point.y) };

        float min_dist = 9e9f;
        SDK::Cache::Player* Best = nullptr;
        SDK::Vector3 headPos{};
        uintptr_t ignoreA = 0, ignoreB = 0;
        std::string targetName;
        SDK::Cache::PlayersMutex.lock();
        for (SDK::Cache::Player& Player : SDK::Cache::Players)
        {
            if (!Player.PlayerObjectAddress || !Player.HumanoidRootPart.Object.Address)
                continue;
            if (Player.PlayerObject.Address == SDK::Cache::LocalPlayer.PlayerObject.Address)
                continue;
            float Health = 0;
            try { Health = Player.Health; } catch (...) { continue; }
            if (Health <= 0)
                continue;
            SDK::Vector2 screenPos = Player.HumanoidRootPart.ScreenPosition;
            if (screenPos.x == -1 || screenPos.y == -1)
                continue;
            float Distance = screenPos.distance(cursor);
            if (std::isnan(Distance) || std::isinf(Distance))
                continue;
            if (Distance < min_dist)
            {
                min_dist = Distance;
                Best = &Player;
            }
        }
        if (Best)
        {
            headPos = Best->Head.WorldPosition;
            ignoreA = SDK::Cache::LocalPlayer.HumanoidRootPart.Object.Primitive().Address;
            ignoreB = Best->Head.Object.Primitive().Address;
            targetName = Best->DisplayName.empty() ? Best->PlayerName : Best->DisplayName;
        }
        SDK::Cache::PlayersMutex.unlock();
        if (Best)
        {
            bool visible = Hacks::Raycast::IsVisible(camPos, headPos, ignoreA, ignoreB);
            float dist = camPos.distance(headPos);
            Globals::Raycast::PreviewVisible = visible;
            Globals::Raycast::PreviewDistance = dist;
            Globals::Raycast::PreviewTargetName = targetName;

            SDK::Vector2 Two = SDK::WorldToScreen(headPos);
            if (Two.x != -1)
            {
                // start point: prefer the camera position itself, then a point
                // slightly ahead of it (near-plane safe), then the screen center
                ImVec2 One;
                SDK::Vector2 start = SDK::WorldToScreen(camPos);
                if (start.x == -1)
                    start = SDK::WorldToScreen(camPos + camForward * 2.0f);
                if (start.x != -1)
                    One = { start.x, start.y };
                else
                {
                    ImVec2 disp = ImGui::GetIO().DisplaySize;
                    One = { disp.x * 0.5f, disp.y * 0.5f };
                }
                ImColor lineCol = visible ? ImColor(0, 255, 0) : ImColor(255, 60, 60);
                Draw->AddLine({ One.x, One.y }, { Two.x, Two.y }, ImColor(0, 0, 0), 3.0f + 1.0f);
                Draw->AddLine({ One.x, One.y }, { Two.x, Two.y }, lineCol, 2.0f);
                Draw->AddCircleFilled({ Two.x, Two.y }, 4.0f, ImColor(0, 0, 0), 12);
                Draw->AddCircleFilled({ Two.x, Two.y }, 3.0f, lineCol, 12);
            }
        }
    }
    catch (...) {}
}

void Hacks::Esp::Render()
{
    try
    {
        static auto lastGateLog = std::chrono::steady_clock::now();
        auto nowG = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(nowG - lastGateLog).count() >= 5)
        {
            lastGateLog = nowG;
            Logging::Log(Logging::LogType::INFO, ("[dbg] ESP gate enabled=" + std::to_string(Globals::Esp::Enabled) + " workspace=" + std::to_string(Globals::DataModel.FindFirstChildOfClass("Workspace").Address != 0) + " cacheSize=" + std::to_string(SDK::Cache::Players.size())).c_str());
        }
    }
    catch (...) {}
    if (!Globals::DataModel.FindFirstChildOfClass("Workspace").Address)
        return;
    SDK::VisualEngineCache::ViewMatrix = Globals::VisualEngine.ViewMatrix();
    POINT cursor_point;
    GetCursorPos(&cursor_point);
    ScreenToClient(Globals::RobloxWindow, &cursor_point);
    ImDrawList* Draw = ImGui::GetBackgroundDrawList();
    if (!Draw) return;

    Draw->Flags = ImDrawFlags_None | ImDrawListFlags_AntiAliasedLines;
    RenderHits(Draw);
    RenderRaycastPreview(Draw);
    if (SDK::Cache::Waypoints.size() != 0)
    {
        for (SDK::Cache::WayPoint& W : SDK::Cache::Waypoints)
        {
            SDK::Vector2 Screen = SDK::WorldToScreen(W.WorldPosition);
            W.ScreenPosition = { Screen.x, Screen.y };
            if (Globals::World::Waypoints::WaypointName)
            {
                Draw->AddText(
                    W.ScreenPosition,
                    FTC(Globals::World::Waypoints::Colors::WaypointName),
                    W.Name.c_str()
                );
            }
            if (Globals::World::Waypoints::WaypointDistance)
            {
                Draw->AddText(
                    W.ScreenPosition + ImVec2(0,1 + ImGui::CalcTextSize((std::to_string((int)SDK::Cache::LocalPlayer.HumanoidRootPart.WorldPosition.distance(W.WorldPosition)) + "m").c_str()).y),
                    FTC(Globals::World::Waypoints::Colors::WaypointDistance),
                    (std::to_string((int)SDK::Cache::LocalPlayer.HumanoidRootPart.WorldPosition.distance(W.WorldPosition)) + "m").c_str()
                );
            }
        }
    }
    if (SDK::Cache::Items.size() != 0)
    {
        std::lock_guard<std::mutex> lock(SDK::Cache::ItemsMutex);
        for (SDK::Cache::Item& Item : SDK::Cache::Items)
        {
            SDK::Vector2 Screen = SDK::WorldToScreen(Item.WorldPosition);
            Item.ScreenPosition = { Screen.x, Screen.y };
            if (Item.ScreenPosition.x == -1 && Item.ScreenPosition.y == -1)
                continue;
            if (Item.Name == "Gun" && Globals::Esp::DroppedGun)
            {
                ImU32 col = ImColor(Globals::Esp::Colors::DroppedGun[0], Globals::Esp::Colors::DroppedGun[1], Globals::Esp::Colors::DroppedGun[2], Globals::Esp::Colors::DroppedGun[3]);
                Draw->AddCircle({ Item.ScreenPosition.x, Item.ScreenPosition.y }, 12.0f, col, 24, 2.0f);
                Draw->AddCircle({ Item.ScreenPosition.x, Item.ScreenPosition.y }, 13.0f, IM_COL32(0, 0, 0, 200), 24, 1.0f);
                Draw->AddText({ Item.ScreenPosition.x + 16.0f, Item.ScreenPosition.y - ImGui::CalcTextSize("Gun").y / 2 }, col, "Gun");
                float dist = SDK::Cache::LocalPlayer.HumanoidRootPart.WorldPosition.distance(Item.WorldPosition);
                Draw->AddText({ Item.ScreenPosition.x + 16.0f, Item.ScreenPosition.y + ImGui::CalcTextSize("Gun").y / 2 }, ImColor(255, 255, 255, 180), (std::to_string((int)dist) + "m").c_str());
            }
        }
    }
    if (Globals::Aimbot::DrawFOV && Globals::Aimbot::EnableFOV)
    {
        float fov = Globals::Aimbot::FOV;
        bool fullscreen = (fov >= 1000);
        float radius = fullscreen ? 0.0f : fov;

        if (fullscreen)
        {
            ImVec2 displaySize = ImGui::GetIO().DisplaySize;
            if (Globals::Aimbot::FovSettings::FillFov)
            {
                Draw->AddRectFilled({ 0, 0 }, displaySize, FTC(Globals::Aimbot::FovSettings::FillColor));
            }
            Draw->AddRect({ 0, 0 }, displaySize, ImColor(0, 0, 0), 0.0f, 0, 3.0f);
            Draw->AddRect({ 0, 0 }, displaySize, FTCNoAlpha(Globals::Aimbot::FovColor), 0.0f, 0, 2.0f);
        }
        else
        {
            Draw->AddCircle(
                { static_cast<float>(cursor_point.x), static_cast<float>(cursor_point.y) },
                radius,
                ImColor(0, 0, 0),
                0.0f,
                3.0f
            );
            Draw->AddCircle(
                { static_cast<float>(cursor_point.x), static_cast<float>(cursor_point.y) },
                radius,
                FTCNoAlpha(Globals::Aimbot::FovColor),
                0.0f,
                2.0f
            );
            if (Globals::Aimbot::FovSettings::FillFov)
            {
                Draw->AddCircleFilled({ static_cast<float>(cursor_point.x), static_cast<float>(cursor_point.y) }, radius - 1, FTC(Globals::Aimbot::FovSettings::FillColor));
            }
        }
    }
    if (Globals::Misc::DesyncedPostion != SDK::Vector3(-1, -1, -1))
    {
        SDK::Vector2 S = SDK::WorldToScreen(Globals::Misc::DesyncedPostion);
        Draw->AddText({ S.x, S.y }, ImColor(255, 255, 255), "Ur client pos");
    }
    if (!Globals::Esp::Enabled)
        return;
    auto espWaitT0 = std::chrono::steady_clock::now();
    // ponytail: never block the render thread on the cache lock. on contention,
    // skip this frame (the draw list is the normal background list; a cached
    // ImDrawList crashed in PrimReserve when box enabled).
    std::unique_lock<std::mutex> cacheGuard(SDK::Cache::PlayersMutex, std::try_to_lock);
    if (!cacheGuard.owns_lock())
    {
        static uint64_t dbgLockFails = 0;
        static std::chrono::steady_clock::time_point lastFailLog{};
        dbgLockFails++;
        auto now8 = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(now8 - lastFailLog).count() >= 5)
        {
            lastFailLog = now8;
            Logging::Log(Logging::LogType::INFO, ("[dbg] ESP lock failed total=" + std::to_string(dbgLockFails) + " enabled=" + std::to_string(Globals::Esp::Enabled) + " cacheSize=" + std::to_string(SDK::Cache::Players.size())).c_str());
        }
        return;
    }
    {
        auto espWaitMs = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - espWaitT0).count();
        static auto lastEspWaitLog = std::chrono::steady_clock::now();
        auto now5 = std::chrono::steady_clock::now();
        if (espWaitMs > 5 && std::chrono::duration_cast<std::chrono::seconds>(now5 - lastEspWaitLog).count() >= 5)
        {
            lastEspWaitLog = now5;
            Logging::Log(Logging::LogType::INFO, ("[perf] ESP render lock wait=" + std::to_string(espWaitMs) + "ms").c_str());
        }
    }
    static int dbgCount = 0;
    int dbgChar = 0, dbgHead = 0, dbgHealth = 0, dbgDrawn = 0;
    for (auto& Player : SDK::Cache::Players)
    {
        Player.Head.ScreenPosition = SDK::WorldToScreen(Player.Head.WorldPosition);
        Player.HumanoidRootPart.ScreenPosition = SDK::WorldToScreen(Player.HumanoidRootPart.WorldPosition);
        for (auto& Bone : Player.Bones)
            Bone.ScreenPosition = SDK::WorldToScreen(Bone.WorldPosition);
        {
            float left = FLT_MAX, top = FLT_MAX, right = -FLT_MAX, bottom = -FLT_MAX;
            for (auto& Bone : Player.Bones)
            {
                if (!Bone.Object.Address || Bone.Name == "HumanoidRootPart") continue;
                SDK::Vector3 pos = Bone.WorldPosition;
                float hx = Bone.Size.x * 0.5f, hy = Bone.Size.y * 0.5f, hz = Bone.Size.z * 0.5f;
                SDK::Vector3 corners[8] = {
                    {pos.x - hx, pos.y - hy, pos.z - hz}, {pos.x + hx, pos.y - hy, pos.z - hz},
                    {pos.x - hx, pos.y + hy, pos.z - hz}, {pos.x + hx, pos.y + hy, pos.z - hz},
                    {pos.x - hx, pos.y - hy, pos.z + hz}, {pos.x + hx, pos.y - hy, pos.z + hz},
                    {pos.x - hx, pos.y + hy, pos.z + hz}, {pos.x + hx, pos.y + hy, pos.z + hz}
                };
                for (int i = 0; i < 8; ++i) {
                    SDK::Vector2 screen = SDK::WorldToScreen(corners[i]);
                    if (screen.x != -1 && screen.y != -1) {
                        if (screen.x < left) left = screen.x;
                        if (screen.y < top) top = screen.y;
                        if (screen.x > right) right = screen.x;
                        if (screen.y > bottom) bottom = screen.y;
                    }
                }
            }
            if (left < right && top < bottom &&
                std::isfinite(left) && std::isfinite(top) &&
                std::isfinite(right) && std::isfinite(bottom)) {
                Player.BoxMin = ImVec2(std::floor(left), std::floor(top));
                Player.BoxMax = ImVec2(std::floor(right), std::floor(bottom));
            }
        }
        SDK::Cache::RecomputeHulls(Player);
        if (!Player.CharacterObjectAddress) { dbgChar++; continue; }
        if (Player.Head.ScreenPosition.x == -1 && Player.HumanoidRootPart.ScreenPosition.x == -1) { dbgHead++; continue; }
        if (Player.Health <= 0) { dbgHealth++; continue; }
        dbgDrawn++;
        if (!Globals::Esp::LocalPlayerESP && Player.PlayerObjectAddress == SDK::Cache::LocalPlayer.PlayerObjectAddress)
            continue;
        
        // ponytail: no per-bone behind-camera cull. The old `x==-1||x==0||x<50`
        // (any bone) loop hid players at glancing angles; the head filter above
        // already handles fully-behind players.
        if (Globals::Esp::MaxDistance && Player.Distance > Globals::Esp::MaxDistanceValue)
            continue;
        if (Globals::Esp::Box)
        {
            float thickness = (float)Globals::Esp::BoxThickness;
            if (Globals::Esp::CornerBox)
            {
                const ImVec2 a = Player.BoxMin, b = Player.BoxMax;
                const float len = (b.x - a.x) * 0.25f;
                ImU32 col = TeamOverride(Player, Globals::Esp::Colors::Box);
                ImU32 dark = ImColor(0, 0, 0);
                auto corner = [&](const ImVec2& base, float dx, float dy) {
                    ImVec2 h1(base.x + dx * len, base.y);
                    ImVec2 h2(base.x, base.y + dy * len);
                    Draw->AddLine(base, h1, dark, thickness + 2);
                    Draw->AddLine(base, h2, dark, thickness + 2);
                    Draw->AddLine(base, h1, col, thickness);
                    Draw->AddLine(base, h2, col, thickness);
                };
                corner(a, 1, 1);
                corner(ImVec2(b.x, a.y), -1, 1);
                corner(ImVec2(a.x, b.y), 1, -1);
                corner(b, -1, -1);
            }
            else
            {
                Draw->AddRect(Player.BoxMin, Player.BoxMax, TeamOverride(Player, Globals::Esp::Colors::Box), 0.0f, 0, thickness);
                Draw->AddRect(Player.BoxMin + ImVec2(1, 1), Player.BoxMax - ImVec2(1, 1), ImColor(0, 0, 0), 0.0f, 0, thickness);
                Draw->AddRect(Player.BoxMin - ImVec2(1, 1), Player.BoxMax + ImVec2(1, 1), ImColor(0, 0, 0), 0.0f, 0, thickness);
            }
            
        }
        if (Globals::Esp::BoxGlow) {
            Draw->AddShadowRect(Player.BoxMin + ImVec2(2, 2), Player.BoxMax - ImVec2(2, 2), TeamOverride(Player, Globals::Esp::Colors::BoxGlow), 50.0f, { 0,0 });
        }
        
        if (Globals::Esp::Tracers)
        {
            ImVec2 StartPostion = { static_cast<float>(cursor_point.x), static_cast<float>(cursor_point.y) };
            if (Globals::Esp::TracersPosition == 2)
            {
                StartPostion = ImVec2(SDK::VisualEngineCache::Dimensions.x / 2, 0);
            }
            if (Globals::Esp::TracersPosition == 1)
            {
                StartPostion = ImVec2(SDK::VisualEngineCache::Dimensions.x / 2, SDK::VisualEngineCache::Dimensions.y);
            }
            Draw->AddLine(
                { Player.Head.ScreenPosition.x,Player.Head.ScreenPosition.y },
                StartPostion,
                ImColor(0,0,0),
                (float)Globals::Esp::TracerThickness + 1.0f
            );
            Draw->AddLine(
                { Player.Head.ScreenPosition .x,Player.Head.ScreenPosition .y},
                StartPostion,
                TeamOverride(Player, Globals::Esp::Colors::Tracers),
                (float)Globals::Esp::TracerThickness
            );
        }
        


        if (Globals::Esp::Name)
        {
            std::string Name = Globals::Esp::UseDisplayName ? Player.DisplayName : Player.PlayerName;
            if (!Name.empty())
            {
                ImVec2 Size = ImGui::CalcTextSize(Name.c_str());
                ImVec2 NamePosition = ImVec2(Player.BoxMin.x + (Player.BoxMax.x - Player.BoxMin.x) / 2 - Size.x / 2, Player.BoxMin.y - 1 - Size.y);
                
                Draw->AddText(NamePosition, TeamOverride(Player, Globals::Esp::Colors::Name), Name.c_str());
            }
        }
        if (Globals::Esp::Distance)
        {
            std::string DistanceText = std::to_string(Player.Distance) + "m";
            ImVec2 Size = ImGui::CalcTextSize(DistanceText.c_str());
            ImVec2 TextPosition = ImVec2(Player.BoxMin.x + (Player.BoxMax.x - Player.BoxMin.x) / 2 - Size.x / 2, Player.BoxMax.y + 1);

            if (Globals::Esp::Tool && !Player.Weapon.empty()) {
                TextPosition = ImVec2(Player.BoxMin.x + (Player.BoxMax.x - Player.BoxMin.x) / 2 - Size.x / 2, Player.BoxMax.y + ImGui::CalcTextSize(Player.Weapon.c_str()).y + 2);
            }

            Draw->AddText(TextPosition, TeamOverride(Player, Globals::Esp::Colors::Distance), DistanceText.c_str());
        }
        if (Globals::Esp::Tool && !Player.Weapon.empty())
        {
            ImVec2 Size = ImGui::CalcTextSize(Player.Weapon.c_str());
            ImVec2 TextPosition = ImVec2(Player.BoxMin.x + (Player.BoxMax.x - Player.BoxMin.x) / 2 - Size.x / 2, Player.BoxMax.y + 1);
                Draw->AddText(TextPosition, TeamOverride(Player, Globals::Esp::Colors::Tool), Player.Weapon.c_str());
        }
        if (Globals::Esp::Avatar)
        {
            std::lock_guard<std::mutex> lock(SDK::Cache::LoadedAvatarsMutex);
            for (SDK::Cache::PlayerAvatar Avatar : SDK::Cache::LoadedAvatars)
            {
                if (Avatar.PlayerName == Player.PlayerName)
                {
                    int iconSize = Globals::Esp::IconSize;
                    float offsetAboveBox = Globals::Esp::OffsetOffBoxAvatar;

                    float centerX = (Player.BoxMin.x + Player.BoxMax.x) / 2.0f;

                    ImVec2 iconMin = ImVec2(
                        centerX - iconSize / 2.0f,
                        Player.BoxMin.y - iconSize - offsetAboveBox
                    );

                    ImVec2 iconMax = ImVec2(
                        centerX + iconSize / 2.0f,
                        Player.BoxMin.y - offsetAboveBox
                    );

                    ImU32 iconTint = IM_COL32(255, 255, 255, 255);
                    if (Globals::Esp::Chams)
                        iconTint = TeamOverride(Player, Globals::Esp::Colors::Chams);
                    ImGui::GetBackgroundDrawList()->AddImage(
                        (ImTextureID)Avatar.Texture,
                        iconMin,
                        iconMax,
                        ImVec2(0, 0),
                        ImVec2(1, 1),
                        iconTint
                    );
                    break;
        }
    }
}
        if (Globals::Esp::Chams || Globals::Esp::ChamsOutlines || Globals::Esp::ChamsGlow)
        {
            if (Globals::Esp::ChamsType == 0)
            {
                static const char* KnownChamsNames[] = {
                    "Right Arm", "Left Arm", "Right Leg", "Left Leg", "Head", "Torso",
                    "UpperTorso", "LowerTorso",
                    "LeftUpperArm", "LeftLowerArm", "LeftHand",
                    "RightUpperArm", "RightLowerArm", "RightHand",
                    "LeftUpperLeg", "LeftLowerLeg", "LeftFoot",
                    "RightUpperLeg", "RightLowerLeg", "RightFoot"
                };

                for (const auto& Bone : Player.Bones)
                {
                    if (Globals::Esp::FilterUnknownChamsParts)
                    {
                        bool known = false;
                        for (const char* k : KnownChamsNames)
                        {
                            if (Bone.Name == k) { known = true; break; }
                        }
                        if (!known) continue;
                    }

                    const std::vector<ImVec2>& Hull = Bone.Hull.Hull;
                    int HullSize = static_cast<int>(Hull.size());
                    if (HullSize <= 0 || Bone.Name == "HumanoidRootPart")
                        continue;
                    bool hullValid = true;
                    for (int i = 0; i < HullSize; i++)
                        if (Hull[i].x == -1 || Hull[i].x == 0 || std::isnan(Hull[i].x) || std::isinf(Hull[i].x)) { hullValid = false; break; }
                    if (!hullValid)
                        continue;
                    if (Globals::Esp::ChamsOutlines)
                    {
                        for (int i = 0; i < HullSize; i++)
                            Draw->AddLine(Hull[i], Hull[(i + 1) % HullSize], TeamOverride(Player, Globals::Esp::Colors::ChamsOutlines), Globals::Esp::ChamsOutlineThickness);
                    }
                    if (Globals::Esp::Chams)
                    {
                        ImColor color = TeamOverride(Player, Globals::Esp::Colors::Chams);
                        if (Globals::Esp::InheritBodyColorChams)
                        {
                            ImU32 V = SDK::Memory->Read<ImU32>(Bone.Object.Address + SDK::Offsets::MeshPartColor3);
                            ImVec4 codlor = ImGui::ColorConvertU32ToFloat4(V);
                            color = ImColor(codlor.x, codlor.y, codlor.z, Globals::Esp::Colors::Chams[3]);
                        }
                        Draw->AddConvexPolyFilled(Hull.data(), HullSize, color);
                    }
                    if (Globals::Esp::ChamsGlow)
                    {
                        Draw->AddShadowConvexPoly(Hull.data(), HullSize, TeamOverride(Player, Globals::Esp::Colors::ChamsGlow), 30.0f, { 0,0 });
                    }
                }
            }
            else if (Globals::Esp::ChamsType == 1)
            {
                auto filterPoints = [](const auto& path) -> std::vector<ImVec2> {
                    std::vector<ImVec2> out;
                    out.reserve(path.size());
                    for (auto& p : path) {
                        ImVec2 v((float)p.x, (float)p.y);
                        if (v.x == -1 || v.x == 0 || std::isnan(v.x) || std::isinf(v.x)) continue;
                        out.push_back(v);
                    }
                    return out;
                };
                if (Globals::Esp::Chams)
                {
                    for (const auto& path : Player.HighlightSolution) {
                        std::vector<ImVec2> points = filterPoints(path);
                        if (points.size() < 2) continue;
                        ImGui::GetBackgroundDrawList()->AddConcavePolyFilled(points.data(), (int)points.size(), TeamOverride(Player, Globals::Esp::Colors::Chams));
                    }
                }
                
                if (Globals::Esp::ChamsOutlines)
                {
                    for (const auto& path : Player.HighlightSolution) {
                        std::vector<ImVec2> points = filterPoints(path);
                        if (points.size() < 2) continue;
                        ImGui::GetBackgroundDrawList()->AddPolyline(points.data(), (int)points.size(), TeamOverride(Player, Globals::Esp::Colors::ChamsOutlines), ImDrawFlags_Closed, Globals::Esp::ChamsOutlineThickness);
                    }
                }
            }
            
            
            
        }
        if (Globals::Esp::Skeleton)
        {
            if (Player.RigType == 0)
            {
                ImVec2 Head, Torso, RightArm, LeftArm, RightLeg, LeftLeg;
                for (const auto& Bone : Player.Bones)
                {
                    if (Bone.Name == "Head")
                        Head = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "Torso")
                        Torso = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "Left Leg")
                        LeftLeg = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "Right Leg")
                        RightLeg = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "Right Arm")
                        RightArm = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "Left Arm")
                        LeftArm = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                }

                ImColor skelColor = TeamOverride(Player, Globals::Esp::Colors::Skeleton);
                if (Head.x != -1 && Torso.x != -1)
                    Draw->AddLine(Head, Torso, skelColor, (float)Globals::Esp::SkeletonThickness);
                if (RightArm.x != -1 && Torso.x != -1)
                    Draw->AddLine(RightArm, Torso, skelColor, (float)Globals::Esp::SkeletonThickness);
                if (LeftArm.x != -1 && Torso.x != -1)
                    Draw->AddLine(LeftArm, Torso, skelColor, (float)Globals::Esp::SkeletonThickness);
                if (RightLeg.x != -1 && Torso.x != -1)
                    Draw->AddLine(RightLeg, Torso, skelColor, (float)Globals::Esp::SkeletonThickness);
                if (LeftLeg.x != -1 && Torso.x != -1)
                    Draw->AddLine(LeftLeg, Torso, skelColor, (float)Globals::Esp::SkeletonThickness);
            }

            if (Player.RigType == 1)
            {
                ImVec2 Head, UpperTorso, LowerTorso;
                ImVec2 LeftUpperArm, LeftLowerArm, LeftHand;
                ImVec2 RightUpperArm, RightLowerArm, RightHand;
                ImVec2 LeftUpperLeg, LeftLowerLeg, LeftFoot;
                ImVec2 RightUpperLeg, RightLowerLeg, RightFoot;

                for (const auto& Bone : Player.Bones)
                {
                    if (Bone.Name == "Head")
                        Head = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "UpperTorso")
                        UpperTorso = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "LowerTorso")
                        LowerTorso = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };

                    if (Bone.Name == "LeftUpperArm")
                        LeftUpperArm = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "LeftLowerArm")
                        LeftLowerArm = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "LeftHand")
                        LeftHand = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };

                    if (Bone.Name == "RightUpperArm")
                        RightUpperArm = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "RightLowerArm")
                        RightLowerArm = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "RightHand")
                        RightHand = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };

                    if (Bone.Name == "LeftUpperLeg")
                        LeftUpperLeg = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "LeftLowerLeg")
                        LeftLowerLeg = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "LeftFoot")
                        LeftFoot = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };

                    if (Bone.Name == "RightUpperLeg")
                        RightUpperLeg = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "RightLowerLeg")
                        RightLowerLeg = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                    if (Bone.Name == "RightFoot")
                        RightFoot = { Bone.ScreenPosition.x, Bone.ScreenPosition.y };
                }

                auto Line = [&](ImVec2 a, ImVec2 b)
                    {
                        if (a.x != -1 && b.x != -1)
                            Draw->AddLine(a, b, TeamOverride(Player, Globals::Esp::Colors::Skeleton), (float)Globals::Esp::SkeletonThickness);
                    };

                Line(Head, UpperTorso);
                Line(UpperTorso, LowerTorso);

                Line(UpperTorso, LeftUpperArm);
                Line(LeftUpperArm, LeftLowerArm);
                Line(LeftLowerArm, LeftHand);

                Line(UpperTorso, RightUpperArm);
                Line(RightUpperArm, RightLowerArm);
                Line(RightLowerArm, RightHand);

                Line(LowerTorso, LeftUpperLeg);
                Line(LeftUpperLeg, LeftLowerLeg);
                Line(LeftLowerLeg, LeftFoot);

                Line(LowerTorso, RightUpperLeg);
                Line(RightUpperLeg, RightLowerLeg);
                Line(RightLowerLeg, RightFoot);
            }
        } // shit code
        if (Globals::Esp::HealthBar) {
            float rawHealth = Player.Health;
            float playerMaxHealth = Player.MaxHealth;
            
            PlayerESPState& state = playerESPStates[Player.PlayerObjectAddress];
            state.smoothHealth += (rawHealth - state.smoothHealth) * 0.01f;
            state.smoothHealth = ImClamp(state.smoothHealth, 0.0f, playerMaxHealth);
            double playerHealth = state.smoothHealth;
            double healthPercentage = (playerMaxHealth > 0.0) ? (playerHealth / playerMaxHealth) : 0.0;
            float healthBarHeight = Player.BoxMax.y - Player.BoxMin.y;
            float filledHealthBarHeight = healthBarHeight * healthPercentage;
            float emptyBarHeight = healthBarHeight - filledHealthBarHeight;
            float filledHealthMaxY = Player.BoxMin.y + emptyBarHeight;
            ImVec2 health_min = ImVec2(std::floor(Player.BoxMin.x - 5.0f), std::floor(filledHealthMaxY));
            ImVec2 health_max = ImVec2(std::floor(Player.BoxMin.x - 3.0f), std::floor(Player.BoxMax.y));

            if (Globals::Esp::HealthBarBackGround) {
                Draw->AddRectFilled({ health_min.x, Player.BoxMin.y }, { health_max.x, health_max.y }, ImColor(0, 0, 0, 187));
            }

            ImColor Color = FTC(Globals::Esp::Colors::HealthBar);
            if (Globals::Esp::HealthBarColorType == 1) {
                Color = ImColor(94, 235, 52);
                if (healthPercentage < 0.2f) Color = ImColor(235, 52, 52);
                else if (healthPercentage < 0.4f) Color = ImColor(235, 168, 52);
                else if (healthPercentage < 0.7f) Color = ImColor(192, 235, 52);
            }

            Draw->AddRectFilled(health_min, health_max, Color);

            if (Globals::Esp::HealthBarGlow) {
                Draw->AddShadowRect(health_min, health_max, Color, 50.0f, { 0,0 });
            }

            
             if (Globals::Esp::HealthBarBackGround) {
                 Draw->AddRect({ health_min.x - 1, Player.BoxMin.y - 1 }, { health_max.x + 1, health_max.y + 1 }, ImColor(0, 0, 0));
             }
             else {
                 Draw->AddRect(health_min - ImVec2(1, 1), health_max + ImVec2(1, 1), ImColor(0, 0, 0));
             }
            

            if (Globals::Esp::HealthNumber && (int)std::ceil(playerHealth) != playerMaxHealth) {
                std::string healthText = std::to_string((int)std::ceil(playerHealth)) + "%";
                ImVec2 healthTextPos = health_min - ImVec2(ImGui::CalcTextSize(healthText.c_str()).x - 2, 4);

               
                Draw->AddText(healthTextPos, FTC(Globals::Esp::Colors::HealthNumber), healthText.c_str());
                
            }
        }
        {
            int offset = 0;
            
            for (const auto& Flag : Player.Flags) {
                if (Globals::Esp::Team && Globals::Esp::TeamMode >= 2 && !Player.Role.empty() && Flag.Flag == Player.Role)
                    continue;
                Draw->AddText(ImVec2(Player.BoxMax.x + 3, Player.BoxMin.y + offset), Flag.Color, Flag.Flag.c_str());
                offset += ImGui::CalcTextSize(Flag.Flag.c_str()).y + 2;
            }
        }
    }
    if (Globals::Esp::OffscreenArrows)
    {
        SDK::Vector2 center = { ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2 };
        for (auto& Player : SDK::Cache::Players)
        {
            if (!Player.CharacterObjectAddress || Player.Health <= 0)
                continue;
            if (!Globals::Esp::LocalPlayerESP && Player.PlayerObjectAddress == SDK::Cache::LocalPlayer.PlayerObjectAddress)
                continue;
            if (Player.Distance < Globals::Esp::OffscreenArrowMinDist)
                continue;
            SDK::Vector2 screenPos = Player.HumanoidRootPart.ScreenPosition;
            if (screenPos.x != -1 && screenPos.x > 0 && screenPos.x < ImGui::GetIO().DisplaySize.x &&
                screenPos.y > 0 && screenPos.y < ImGui::GetIO().DisplaySize.y)
                continue;
            SDK::Vector2 projected = RawProject(Player.HumanoidRootPart.WorldPosition);
            SDK::Vector2 dir = { projected.x - center.x, projected.y - center.y };
            float len = sqrtf(dir.x * dir.x + dir.y * dir.y);
            if (len < 0.001f) continue;
            dir.x /= len; dir.y /= len;
            float arrowSize = Globals::Esp::OffscreenArrowSize;
            float padding = Globals::Esp::OffscreenArrowPadding;
            float cx = ImGui::GetIO().DisplaySize.x / 2;
            float cy = ImGui::GetIO().DisplaySize.y / 2;
            float halfW = cx - padding;
            float halfH = cy - padding;
            float angle = atan2f(dir.y, dir.x);
            float t = 1.0f;
            float tx = cosf(angle);
            float ty = sinf(angle);
            float absTx = fabsf(tx);
            float absTy = fabsf(ty);
            if (absTx > 0.001f && absTy > 0.001f)
            {
                float txHalfW = halfW / absTx;
                float tyHalfH = halfH / absTy;
                t = min(txHalfW, tyHalfH);
            }
            else if (absTx > 0.001f)
                t = halfW / absTx;
            else if (absTy > 0.001f)
                t = halfH / absTy;
            float arrowX = cx + tx * t;
            float arrowY = cy + ty * t;
            float angleDeg = angle * 180.0f / 3.14159265f;
            float a1 = (angleDeg + 25.0f) * 3.14159265f / 180.0f;
            float a2 = (angleDeg - 25.0f) * 3.14159265f / 180.0f;
            ImVec2 tip = { arrowX, arrowY };
            ImVec2 left = { arrowX - arrowSize * cosf(a1), arrowY - arrowSize * sinf(a1) };
            ImVec2 right = { arrowX - arrowSize * cosf(a2), arrowY - arrowSize * sinf(a2) };
            ImU32 arrowCol = ImColor(Globals::Esp::OffscreenArrowColor[0], Globals::Esp::OffscreenArrowColor[1], Globals::Esp::OffscreenArrowColor[2], Globals::Esp::OffscreenArrowColor[3]);
            Draw->AddTriangleFilled(tip, left, right, arrowCol);
            Draw->AddTriangle(tip, left, right, ImColor(0, 0, 0, (int)(Globals::Esp::OffscreenArrowColor[3] * 255)), 1.5f);
        }
    }
    auto espDrawMs = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - espWaitT0).count();
    cacheGuard.unlock();
    if (++dbgCount % 300 == 0)
    {
        Logging::Log(Logging::LogType::INFO, ("[dbg] ESP players=" + std::to_string(SDK::Cache::Players.size()) + " skipChar=" + std::to_string(dbgChar) + " skipHead=" + std::to_string(dbgHead) + " skipHealth=" + std::to_string(dbgHealth) + " drawn=" + std::to_string(dbgDrawn)).c_str());
    }
    {
        static auto lastEspDrawLog = std::chrono::steady_clock::now();
        auto now7 = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(now7 - lastEspDrawLog).count() >= 5)
        {
            lastEspDrawLog = now7;
            Logging::Log(Logging::LogType::INFO, ("[perf] ESP render total_lockhold=" + std::to_string(espDrawMs) + "ms").c_str());
        }
    }
    if (Globals::World::Movement::Peek && Globals::World::Movement::PeekActive)
    {
        SDK::Vector2 circlePos = SDK::WorldToScreen(Globals::World::Movement::PeekPosition);
        if (circlePos.x != -1)
        {
            float radius = Globals::World::Movement::PeekRadius * 10.0f;
            ImU32 col = ImColor(Globals::World::Movement::PeekColor[0], Globals::World::Movement::PeekColor[1], Globals::World::Movement::PeekColor[2], Globals::World::Movement::PeekColor[3]);
            Draw->AddCircle({ circlePos.x, circlePos.y }, radius, col, 32, 2.0f);
            Draw->AddCircle({ circlePos.x, circlePos.y }, radius - 1.0f, IM_COL32(0, 0, 0, 100), 32, 1.0f);
        }
    }
}
