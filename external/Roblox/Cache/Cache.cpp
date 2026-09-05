#define NOMINMAX
#include "Cache.h"
#include <cmath>
#include <cctype>
#include "algorithm"
#include <Json.hpp>
#include <winhttp.h>
#include "../Security/xorstr.hpp"
#pragma comment(lib, "winhttp.lib")
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
using namespace Clipper2Lib;
namespace BoneUtils
{
    inline bool ChamsActive() {
        return Globals::Esp::Chams || Globals::Esp::ChamsOutlines || Globals::Esp::ChamsGlow;
    }
    inline PathD BoneHullToPath(const SDK::Cache::Bone bone) {
        PathD path;
        for (const auto& p : bone.Hull.Hull) {
            path.push_back(PointD(p.x, p.y));
        }
        return path;
    }
    inline PathsD UnionAllHulls(const std::vector<SDK::Cache::Bone>& bones) {
        PathsD input;
        for (auto bone : bones) {
            if (bone.Hull.Hull.size() >= 3) {
                input.push_back(BoneHullToPath(bone));
            }
        }
        PathsD solution = Union(input, FillRule::NonZero);
        return solution;
    }
    SDK::Cache::Bone InstanceToBone(SDK::Instance Instance)
    {
        SDK::Cache::Bone Bone;
        Bone.Name = Instance.Name();
        Bone.Object = Instance;
        return Bone;
    }

    std::string Lower(std::string s)
    {
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return (char)std::tolower(c); });
        return s;
    }

    // Look up a character part by any of several candidate names. Falls back to
    // case-insensitive matching, then to a substring match so odd rigs (for
    // example "_Head", "Head1", "HumanoidRootPart_1") still resolve.
    SDK::Instance FindPartByName(SDK::Instance Character, const std::vector<std::string>& names)
    {
        if (!Character.Address) return SDK::Instance();
        std::vector<SDK::Instance> Children = Character.Children();
        for (auto& child : Children)
            for (const auto& name : names)
                if (child.Address && child.Name() == name)
                    return child;
        for (auto& child : Children)
        {
            if (!child.Address) continue;
            std::string lower = Lower(child.Name());
            for (const auto& name : names)
                if (lower == Lower(name))
                    return child;
        }
        for (auto& child : Children)
        {
            if (!child.Address) continue;
            std::string lower = Lower(child.Name());
            for (const auto& name : names)
                if (!name.empty() && lower.find(Lower(name)) != std::string::npos)
                    return child;
        }
        return SDK::Instance();
    }

    // When the standard head/hrp/torso names are all missing we still want to
    // keep the player for esp/chams. This picks a best-guess head (highest part)
    // and root (lowest part) from whatever parts exist so the player remains
    // fully usable.
    void AssignUnknownParts(SDK::Cache::Player& Cache)
    {
        SDK::Cache::Bone* bestHead = nullptr;
        SDK::Cache::Bone* bestRoot = nullptr;
        float topY = -FLT_MAX;
        float bottomY = FLT_MAX;
        for (auto& Bone : Cache.Bones)
        {
            if (!Bone.Object.Address)
                continue;
            if (Bone.WorldPosition.y > topY) { topY = Bone.WorldPosition.y; bestHead = &Bone; }
            if (Bone.WorldPosition.y < bottomY) { bottomY = Bone.WorldPosition.y; bestRoot = &Bone; }
        }
        if (!Cache.Head.Object.Address && bestHead)
            Cache.Head = *bestHead;
        if (!Cache.HumanoidRootPart.Object.Address && bestRoot)
            Cache.HumanoidRootPart = *bestRoot;
    }
    SDK::Cache::CachedConvexHull CalculateBoneConvexHull(SDK::Cache::Bone& Bone)
    {
        if (!Bone.Object.Address)
            return {};
        SDK::Vector3 partpos3d = Bone.WorldPosition;
        SDK::Vector3 partsize = Bone.Size;
        SDK::Matrix3 partrot = Bone.Rotation;
        SDK::Vector3 half_size = { partsize.x / 2, partsize.y / 2, partsize.z / 2 };
        SDK::Vector3 local_corners[8] = {
            {-half_size.x, -half_size.y, -half_size.z}, {half_size.x, -half_size.y, -half_size.z},
            {half_size.x, half_size.y, -half_size.z}, {-half_size.x, half_size.y, -half_size.z},
            {-half_size.x, -half_size.y, half_size.z}, {half_size.x, -half_size.y, half_size.z},
            {half_size.x, half_size.y, half_size.z}, {-half_size.x, half_size.y, half_size.z}
        };
        ImVec2 screen_points[8];
        int valid_points = 0;
        for (int i = 0; i < 8; i++) {
            SDK::Vector3 rotated = {
                partrot.data[0] * local_corners[i].x + partrot.data[1] * local_corners[i].y + partrot.data[2] * local_corners[i].z,
                partrot.data[3] * local_corners[i].x + partrot.data[4] * local_corners[i].y + partrot.data[5] * local_corners[i].z,
                partrot.data[6] * local_corners[i].x + partrot.data[7] * local_corners[i].y + partrot.data[8] * local_corners[i].z
            };
            SDK::Vector3 world_corners = {
                partpos3d.x + rotated.x,
                partpos3d.y + rotated.y,
                partpos3d.z + rotated.z
            };
			SDK::Vector2 screen_pos = SDK::WorldToScreen(world_corners);
			if (screen_pos.x != -1 && screen_pos.y != -1 && !std::isnan(screen_pos.x) && !std::isinf(screen_pos.x)) {
				screen_points[valid_points++] = { screen_pos.x, screen_pos.y };
			}
        }
        if (valid_points < 3) return {};
        std::sort(screen_points, screen_points + valid_points, [](ImVec2 a, ImVec2 b) {
            return a.x < b.x || (a.x == b.x && a.y < b.y);
            });
        ImVec2 hull[16];
        int hull_size = 0;
        for (int i = 0; i < valid_points; ++i) {
            while (hull_size >= 2 && ((hull[hull_size - 1].x - hull[hull_size - 2].x) * (screen_points[i].y - hull[hull_size - 2].y) - (hull[hull_size - 1].y - hull[hull_size - 2].y) * (screen_points[i].x - hull[hull_size - 2].x)) <= 0)
                hull_size--;
            hull[hull_size++] = screen_points[i];
        }
        int lower_hull_size = hull_size;
        for (int i = valid_points - 2; i >= 0; --i) {
            while (hull_size > lower_hull_size && ((hull[hull_size - 1].x - hull[hull_size - 2].x) * (screen_points[i].y - hull[hull_size - 2].y) - (hull[hull_size - 1].y - hull[hull_size - 2].y) * (screen_points[i].x - hull[hull_size - 2].x)) <= 0)
                hull_size--;
            hull[hull_size++] = screen_points[i];
        }
        hull_size--;
        if (hull_size < 3) return {};

        SDK::Cache::CachedConvexHull Hull;
        Hull.Hull.assign(hull, hull + hull_size);
        return Hull;
    }
    
    void UpdateBoneInfo(SDK::Cache::Bone& Bone)
    {
        if (!Bone.Object.Address)
            return;
        SDK::Primitive Primitive = Bone.Object.Primitive();
        SDK::Matrix3 rot; SDK::Vector3 pos, size;
        Primitive.ReadAll(rot, pos, size);
        Bone.Rotation = rot;
        Bone.WorldPosition = pos;
        if (Bone.CacheSize)
            Bone.Size = size;
    }
}

void SDK::Cache::RecomputeHulls(SDK::Cache::Player& player)
{
    if (!BoneUtils::ChamsActive())
        return;
    for (auto& bone : player.Bones)
    {
        if (!bone.Object.Address)
            continue;
        auto hull = BoneUtils::CalculateBoneConvexHull(bone);
        if (hull.Hull.size() >= 3) {
            float minX = hull.Hull[0].x, maxX = minX;
            float minY = hull.Hull[0].y, maxY = minY;
            bool bad = false;
            for (auto& p : hull.Hull) {
                if (std::isnan(p.x) || std::isinf(p.x) || std::isnan(p.y) || std::isinf(p.y)) { bad = true; break; }
                if (p.x < minX) minX = p.x; if (p.x > maxX) maxX = p.x;
                if (p.y < minY) minY = p.y; if (p.y > maxY) maxY = p.y;
            }
            // ALWAYS take the fresh hull, even when tiny. The old "skip under 2px"
            // gate kept the last BIG hull alive, so distant players froze showing
            // stale chams until they got close again.
            if (!bad)
                bone.Hull = hull;
        }
        else {
            bone.Hull.Hull.clear(); // behind-camera / degenerate this frame: hide, don't go stale
        }
    }
    if (Globals::Esp::ChamsType == 1)
        player.HighlightSolution = BoneUtils::UnionAllHulls(player.Bones);
}

void SDK::Cache::PlayerCache()
{
    // ponytail: cache threads are background work; below-normal priority so they
    // never starve the main render thread during the ~1s rebuild
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL);
    while (true)
    {
        if (!Globals::DataModel.FindFirstChildOfClass("Workspace").Address)
        {
            // not attached / still loading - don't busy-spin a core
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
            continue;
        }
        auto buildStart = std::chrono::steady_clock::now();
        try
        {

            // Bad Business
            if (Globals::GameID == SDK::Games::BadBusiness)
            {
                std::vector<SDK::Cache::Player> CacheList;
                SDK::Cache::Player PendingLocalPlayer;
                std::vector<SDK::Instance> Players;
                Players = Globals::Workspace.FindFirstChild("Characters").Children();
                if (Globals::Misc::TeamCheck)
                {
                    Players.clear();
                    for (SDK::Instance Highlight : Globals::LocalPlayer.FindFirstChild("PlayerGui").Children())
                    {
                        if (Highlight.Class() == "Highlight")
                        {
                            SDK::Instance Adornee = SDK::Memory->Read<SDK::Instance>(Highlight.Address + SDK::Offsets::Adornee);
                            if (!Adornee.Address)
                                continue;
                            bool alreadyAdded = false;
                            for (SDK::Instance player : Players) {
                                if (player.Address == Adornee.Address) {
                                    alreadyAdded = true;
                                    break;
                                }
                            }
                            if (!alreadyAdded) {
                                Players.push_back(Adornee);
                            }
                        }
                    }
                }
                for (SDK::Instance Player : Players)
                {
                    if (!Player.Address)
                        continue;
                    SDK::Cache::Player Cache;
                    Cache.PlayerObject = (SDK::Player)Player;
                    Cache.PlayerObjectAddress = Player.Address;
                    Cache.CharacterObject = Player;
                    Cache.CharacterObjectAddress = Cache.CharacterObject.Address;
                   
                    Cache.PlayerName = "Player " + Player.Name();
                    Cache.DisplayName = "Player";
                    Cache.HumanoidRootPart = BoneUtils::InstanceToBone(Cache.CharacterObject.FindFirstChild("Root"));
                    Cache.Humanoid = SDK::Humanoid();
                    Cache.Head = BoneUtils::InstanceToBone(Cache.CharacterObject.FindFirstChild("Body").FindFirstChild("Head"));
                    Cache.LeftArm = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Left Arm", "LeftUpperArm" }));
                    Cache.RightArm = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Right Arm", "RightUpperArm" }));
                    Cache.LeftLeg = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Left Leg", "LeftUpperLeg" }));
                    Cache.RightLeg = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Right Leg", "RightUpperLeg" }));
                    Cache.RigType = 3;
                    Cache.Health = static_cast<float>(SDK::Memory->Read<double>(Cache.CharacterObject.FindFirstChild("Health").Address + SDK::Offsets::Value));
                  
                    Cache.MaxHealth = static_cast<float>(SDK::Memory->Read<double>(Cache.CharacterObject.FindFirstChild("Health").FindFirstChild("MaxHealth").Address + SDK::Offsets::Value));
                   
                    BoneUtils::UpdateBoneInfo(Cache.Head);
                    BoneUtils::UpdateBoneInfo(Cache.HumanoidRootPart);
                    for (SDK::Instance Bone : Cache.CharacterObject.FindFirstChild("Body").Children())
                    {
                        std::string Class = Bone.Class();

                        if (Class != "Part" && Class != "MeshPart")
                            continue;
                        SDK::Cache::Bone NewBone = BoneUtils::InstanceToBone(Bone);
                        BoneUtils::UpdateBoneInfo(NewBone);

                        Cache.Bones.push_back(NewBone);
                    }
                   
                    float left = FLT_MAX, top = FLT_MAX, right = -FLT_MAX, bottom = -FLT_MAX;
                    for (SDK::Cache::Bone& Bone : Cache.Bones)
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
                    if (left < right && top < bottom) {
                        Cache.BoxMin = ImVec2(std::floor(left), std::floor(top));
                        Cache.BoxMax = ImVec2(std::floor(right), std::floor(bottom));
                    }
                    Cache.HighlightSolution = BoneUtils::UnionAllHulls(Cache.Bones);
                    CacheList.push_back(Cache);
                    if (!Cache.CharacterObject.FindFirstChild("Clothes").Address)
                    {
                        PendingLocalPlayer = Cache;
                    }
                }
                for (SDK::Cache::Player& NewPlayer : CacheList)
                {
                    const auto& LP = PendingLocalPlayer.PlayerObjectAddress ? PendingLocalPlayer : SDK::Cache::LocalPlayer;
                    if (LP.PlayerObjectAddress)
                    {
                        NewPlayer.Distance = NewPlayer.HumanoidRootPart.WorldPosition.distance(LP.HumanoidRootPart.WorldPosition);
                    }
                }
                {
                    std::lock_guard<std::mutex> lock(SDK::Cache::PlayersMutex);
                    SDK::Cache::Players = std::move(CacheList);
                    if (PendingLocalPlayer.PlayerObjectAddress)
                        SDK::Cache::LocalPlayer = PendingLocalPlayer;
                }
            }

            // Phantom forces
            else if (Globals::GameID == SDK::Games::PhantomForces)
            {
               
                std::vector<SDK::Cache::Player> CacheList;
                SDK::Cache::Player PendingLocalPlayer;
                std::vector<SDK::Instance> Players;
                std::vector<SDK::Instance> Team1 = Globals::Workspace.FindFirstChild("Players").Children()[0].Children();
                std::vector<SDK::Instance> Team2 = Globals::Workspace.FindFirstChild("Players").Children()[1].Children();
                Players.insert(Players.end(), Team1.begin(), Team1.end());
                Players.insert(Players.end(), Team2.begin(), Team2.end());
                
                Logging::Log(Logging::LogType::WARNING, "Players - %s", std::to_string(Players.size()));

                for (SDK::Instance Player : Players)
                {
                    SDK::Cache::Player Cache;
                    Cache.PlayerName = "Yo";
                    Cache.DisplayName = "YoWSP";
                    Cache.CharacterObject = Player;
                    Cache.CharacterObjectAddress = Player.Address;
                    Cache.PlayerObject = (SDK::Player)Player;
                    Cache.PlayerObjectAddress = Player.Address;
                    Cache.MaxHealth = 100;
                    Cache.Health = 100;
                    Cache.RigType = 0;
                    
                    for (SDK::Instance Bone : Player.Children())
                    {
                        std::string Class = Bone.Class();

                        if (Class != "Part" && Class != "MeshPart" && Class != "TrussPart")
                            continue;
                        SDK::Cache::Bone NewBone = BoneUtils::InstanceToBone(Bone);
                        BoneUtils::UpdateBoneInfo(NewBone);
                        bool IsHead, IsTorso = false;
                        if (Bone.FindFirstChildOfClass("SpotLight").Address)
                        {
                            Cache.HumanoidRootPart = NewBone;
                            NewBone.Size = Vector3(2.0f, 2.0f, 1.0f);
                            NewBone.CacheSize = false;
                            IsTorso = true;
                        }
                        if (Bone.FindFirstChildOfClass("BillboardGui").Address)
                        {
                            Cache.Head = NewBone;
                            std::string Name = SDK::Memory->ReadString(Bone.FindFirstChildOfClass("BillboardGui").FindFirstChildOfClass("TextLabel").Address + 0xdf0);
                            Cache.PlayerName = Name;
                            Cache.DisplayName = Name;
                            NewBone.CacheSize = false;
                            NewBone.Size = SDK::Vector3(1.0f, 1.0f, 1.0f);
                            Cache.Head.WorldPosition = Cache.Head.Object.Primitive().Position();
                            IsHead = true;
                        }
                        if (!(IsHead && IsTorso))
                        {
                           
                            NewBone.CacheSize = false;
                            NewBone.Size = SDK::Vector3(1.0f, 2.0f, 1.0f);
                            if (Bone.FindFirstChildOfClass("BillboardGui").Address)
                            {
                                NewBone.Size = SDK::Vector3(1.0f, 1.0f, 1.0f);
                            }
                        }
                        BoneUtils::UpdateBoneInfo(NewBone);
                        Cache.Bones.push_back(NewBone);
                       
                    }
                    /*
                    for (SDK::Instance Bone : Player.FindFirstChildOfClass("Folder").Children())
                    {
                        std::string Class = Bone.Class();

                        if (Class != "Part" && Class != "MeshPart")
                            continue;
                        SDK::Cache::Bone NewBone = BoneUtils::InstanceToBone(Bone);
                        BoneUtils::UpdateBoneInfo(NewBone);



                        Cache.Bones.push_back(NewBone);
                    }
                    */
                    BoneUtils::UpdateBoneInfo(Cache.Head);
                    BoneUtils::UpdateBoneInfo(Cache.HumanoidRootPart);
                    for (SDK::Instance StupidFag : Globals::Players.Children())
                    {
                        if (StupidFag.Name() == Cache.PlayerName)
                        {
                            Cache.PlayerObject = (SDK::Player)StupidFag;
                            Cache.PlayerObjectAddress = StupidFag.Address;
                        }
                    }
                    Cache.Team = Cache.PlayerObject.Team().Address;
                    if (Globals::Misc::TeamCheck && Cache.Team == Globals::LocalPlayer.Team().Address)
                        continue;
                    float left = FLT_MAX, top = FLT_MAX, right = -FLT_MAX, bottom = -FLT_MAX;
                    for (SDK::Cache::Bone& Bone : Cache.Bones)
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
                    if (left < right && top < bottom) {
                        Cache.BoxMin = ImVec2(std::floor(left), std::floor(top));
                        Cache.BoxMax = ImVec2(std::floor(right), std::floor(bottom));
                    }
                    Cache.HighlightSolution = BoneUtils::UnionAllHulls(Cache.Bones);
                    CacheList.push_back(Cache);
                    
                }
                for (SDK::Cache::Player& NewPlayer : CacheList)
                {
                   
                        NewPlayer.Distance = NewPlayer.Head.Object.Primitive().Position().distance(static_cast<SDK::Camera>(Globals::Workspace.FindFirstChildOfClass("Camera")).CameraPosition());
                    
                }
                if (Globals::Workspace.FindFirstChild("Ignore").FindFirstChildOfClass("Model").Address)
                {
                    SDK::Instance LocalModel = Globals::Workspace.FindFirstChild("Ignore").FindFirstChildOfClass("Model");
                    SDK::Player Player = Globals::LocalPlayer;
                    SDK::Cache::Player Cache;
                    Cache.PlayerObject = Player;
                    Cache.PlayerObjectAddress = Player.Address;
                    Cache.CharacterObject = LocalModel;
                    Cache.CharacterObjectAddress = Cache.CharacterObject.Address;
                   
                    Cache.PlayerName = Player.Name();
                    Cache.DisplayName = Player.DisplayName();
                    Cache.HumanoidRootPart = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "HumanoidRootPart", "RootPart", "Root", "root", "LowerTorso", "Torso", "torso" }));
                    Cache.Head = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Head", "head", "HeadMesh", "Head1" }));
                    Cache.LeftArm = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Left Arm", "LeftUpperArm", "LeftLowerArm", "LeftHand" }));
                    Cache.RightArm = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Right Arm", "RightUpperArm", "RightLowerArm", "RightHand" }));
                    Cache.LeftLeg = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Left Leg", "LeftUpperLeg", "LeftLowerLeg", "LeftFoot" }));
                    Cache.RightLeg = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Right Leg", "RightUpperLeg", "RightLowerLeg", "RightFoot" }));
                    Cache.Humanoid = static_cast<SDK::Humanoid>(Cache.CharacterObject.FindFirstChildOfClass("Humanoid"));
                    Cache.RigType = Cache.Humanoid.RigType();
                    
                    Cache.Health = Cache.Humanoid.Health();
                    Cache.MaxHealth = Cache.Humanoid.MaxHealth();
                    Cache.Team = Cache.PlayerObject.Team().Address;
                    BoneUtils::UpdateBoneInfo(Cache.Head);
                    BoneUtils::UpdateBoneInfo(Cache.HumanoidRootPart);

                    for (SDK::Instance Bone : Cache.CharacterObject.Children())
                    {
                        std::string Class = Bone.Class();

                        if (Class != "Part" && Class != "MeshPart")
                            continue;
                        SDK::Cache::Bone NewBone = BoneUtils::InstanceToBone(Bone);
                        BoneUtils::UpdateBoneInfo(NewBone);

                        Cache.Bones.push_back(NewBone);
                    }
                    Logging::Log(Logging::LogType::WARNING, "LocalPlayer Bones - %s", std::to_string(Cache.Bones.size()));
                    Logging::Log(Logging::LogType::WARNING, "LocalPlayer Head - 0x%llX", Cache.Head.Object.Address);
                    Logging::Log(Logging::LogType::WARNING, "LocalPlayer HumanoidRootPart - 0x%llX", Cache.HumanoidRootPart.Object.Address);
                    Logging::Log(Logging::LogType::WARNING, "LocalPlayer Humanoid - 0x%llX", Cache.Humanoid.Address);
                    Logging::Log(Logging::LogType::WARNING, "LocalPlayer Health - %s/%s", std::to_string(Cache.Health), std::to_string(Cache.MaxHealth));
                    PendingLocalPlayer = Cache;
                    Cache.HighlightSolution = BoneUtils::UnionAllHulls(Cache.Bones);
                    CacheList.push_back(Cache);
                }
                Logging::Log(Logging::LogType::WARNING, "Players Cached - %s", std::to_string(CacheList.size()));
                {
                    std::lock_guard<std::mutex> lock(SDK::Cache::PlayersMutex);
                    SDK::Cache::Players = std::move(CacheList);
                    if (PendingLocalPlayer.PlayerObjectAddress)
                        SDK::Cache::LocalPlayer = PendingLocalPlayer;
                }
                
            }

            // Dead line
            else if (Globals::GameID == SDK::Games::Deadline)
            {
                std::vector<SDK::Cache::Player> CacheList;
                SDK::Cache::Player PendingLocalPlayer;
                SDK::Instance Characters = Globals::Workspace.FindFirstChild("characters");
                SDK::Instance LocalCharacter = Globals::LocalPlayer.Character();
                if (Characters.Address)
                {
                    auto IsIgnored = [&](SDK::Instance Inst) {
                        if (!Inst.Address) return true;
                        SDK::Instance Ancestor = Inst;
                        for (int i = 0; i < 32 && Ancestor.Address; i++)
                        {
                            if (Ancestor.Name() == "ignore")
                                return true;
                            Ancestor = Ancestor.Parent();
                        }
                        return false;
                    };
                    for (SDK::Instance Player : Characters.Children())
                    {
                        if (!Player.Address || Player.Class() != "Model")
                            continue;
                        if (IsIgnored(Player))
                            continue;
                        if (LocalCharacter.Address && Player.Address == LocalCharacter.Address)
                            continue;
                        SDK::Cache::Player Cache;
                        Cache.CharacterObject = Player;
                        Cache.CharacterObjectAddress = Player.Address;
                        Cache.PlayerObjectAddress = Player.Address;
                        Cache.PlayerName = Player.Name();
                        Cache.DisplayName = Player.Name();
                        Cache.HumanoidRootPart = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Player, { "humanoid_root_part"}));
                        Cache.Head = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Player, { "head"}));
                        Cache.LeftArm = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Player, { "left_arm", "Left Arm", "LeftUpperArm", "LeftLowerArm" }));
                        Cache.RightArm = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Player, { "right_arm", "Right Arm", "RightUpperArm", "RightLowerArm" }));
                        Cache.LeftLeg = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Player, { "left_leg", "Left Leg", "LeftUpperLeg", "LeftLowerLeg" }));
                        Cache.RightLeg = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Player, { "right_leg", "Right Leg", "RightUpperLeg", "RightLowerLeg" }));
                        Cache.Health = 100.0f;
                        Cache.MaxHealth = 100.0f;
                        BoneUtils::UpdateBoneInfo(Cache.Head);
                        BoneUtils::UpdateBoneInfo(Cache.HumanoidRootPart);
                        for (SDK::Instance Bone : Player.Children())
                        {
                            std::string Class = Bone.Class();
                            if (Class != "Part" && Class != "MeshPart")
                                continue;
                            SDK::Cache::Bone NewBone = BoneUtils::InstanceToBone(Bone);
                            BoneUtils::UpdateBoneInfo(NewBone);
                            Cache.Bones.push_back(NewBone);
                        }
                        float left = FLT_MAX, top = FLT_MAX, right = -FLT_MAX, bottom = -FLT_MAX;
                        for (SDK::Cache::Bone& Bone : Cache.Bones)
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
                    if (left < right && top < bottom) {
                        Cache.BoxMin = ImVec2(std::floor(left), std::floor(top));
                        Cache.BoxMax = ImVec2(std::floor(right), std::floor(bottom));
                    }
                    BoneUtils::AssignUnknownParts(Cache);
                    Cache.HighlightSolution = BoneUtils::UnionAllHulls(Cache.Bones);
SDK::Instance FirstTool;
                    for (SDK::Instance Bone : Cache.CharacterObject.Children())
                    {
                        std::string Class = Bone.Class();

                        if (Class == "Tool" && !FirstTool.Address)
                            FirstTool = Bone;
                        if (Class != "Part" && Class != "MeshPart")
                            continue;
                        SDK::Cache::Bone NewBone = BoneUtils::InstanceToBone(Bone);
                        Cache.Bones.push_back(NewBone);
                    }
                    // ponytail: weapon captured here (3s) instead of every 60ms tick;
                    // the per-tick children scan held PlayersMutex for 100s of ms
                    if (FirstTool.Address)
                        Cache.Weapon = FirstTool.Name();
                    CacheList.push_back(Cache);
                    }
                }
                if (LocalCharacter.Address)
                {
                    SDK::Cache::Player Cache;
                    Cache.CharacterObject = LocalCharacter;
                    Cache.CharacterObjectAddress = LocalCharacter.Address;
                    Cache.PlayerObjectAddress = Globals::LocalPlayer.Address;
                    Cache.PlayerName = Globals::LocalPlayer.Name();
                    Cache.DisplayName = Globals::LocalPlayer.DisplayName();
                    Cache.HumanoidRootPart = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(LocalCharacter, { "HumanoidRootPart", "humanoid_root_part", "RootPart", "Root", "root", "LowerTorso", "Torso", "torso" }));
                    Cache.Head = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(LocalCharacter, { "Head", "head", "HeadMesh", "Head1" }));
                    Cache.LeftArm = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(LocalCharacter, { "Left Arm", "LeftUpperArm", "LeftLowerArm", "LeftHand" }));
                    Cache.RightArm = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(LocalCharacter, { "Right Arm", "RightUpperArm", "RightLowerArm", "RightHand" }));
                    Cache.LeftLeg = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(LocalCharacter, { "Left Leg", "LeftUpperLeg", "LeftLowerLeg", "LeftFoot" }));
                    Cache.RightLeg = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(LocalCharacter, { "Right Leg", "RightUpperLeg", "RightLowerLeg", "RightFoot" }));
                    Cache.Humanoid = static_cast<SDK::Humanoid>(LocalCharacter.FindFirstChildOfClass("Humanoid"));
                    Cache.RigType = Cache.Humanoid.RigType();
                    Cache.Health = Cache.Humanoid.Health();
                    Cache.MaxHealth = Cache.Humanoid.MaxHealth();
                    BoneUtils::UpdateBoneInfo(Cache.Head);
                    BoneUtils::UpdateBoneInfo(Cache.HumanoidRootPart);
                    for (SDK::Instance Bone : LocalCharacter.Children())
                    {
                        std::string Class = Bone.Class();
                        if (Class != "Part" && Class != "MeshPart")
                            continue;
                        SDK::Cache::Bone NewBone = BoneUtils::InstanceToBone(Bone);
                        BoneUtils::UpdateBoneInfo(NewBone);
                        Cache.Bones.push_back(NewBone);
                    }
                    BoneUtils::AssignUnknownParts(Cache);
                    Cache.HighlightSolution = BoneUtils::UnionAllHulls(Cache.Bones);
                    PendingLocalPlayer = Cache;
                    auto playergui = Globals::LocalPlayer.FindFirstChildOfClass("PlayerGui");
                    if (playergui.Address)
                    {
                        std::lock_guard<std::mutex> crosshairLock(SDK::CrosshairsMutex);
                        SDK::Crosshairs.clear();
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("MainScreenGui").FindFirstChild("Aim"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("Crosshair").FindFirstChild("Main"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("Interface").FindFirstChild("Main").FindFirstChild("Aim"));
                    }
                }
                for (SDK::Cache::Player& NewPlayer : CacheList)
                {
                    const auto& LP = PendingLocalPlayer.PlayerObjectAddress ? PendingLocalPlayer : SDK::Cache::LocalPlayer;
                    if (LP.HumanoidRootPart.Object.Address)
                    {
                        NewPlayer.Distance = NewPlayer.HumanoidRootPart.WorldPosition.distance(LP.HumanoidRootPart.WorldPosition);
                    }
                }
                {
                    std::lock_guard<std::mutex> lock(SDK::Cache::PlayersMutex);
                    SDK::Cache::Players = std::move(CacheList);
                    if (PendingLocalPlayer.PlayerObjectAddress)
                        SDK::Cache::LocalPlayer = PendingLocalPlayer;
                }
            }

            // Games Unite Testing Place
            else if (Globals::GameID == SDK::Games::GamesUniteTestingPlace)
            {
                std::vector<SDK::Cache::Player> CacheList;
                SDK::Cache::Player PendingLocalPlayer;

                SDK::Instance Playermodels = Globals::Workspace.FindFirstChild("Playermodels");
                if (!Playermodels.Address)
                {
                    Logging::Log(Logging::LogType::WARNING, "Playermodels not found in Workspace");
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    continue;
                }

                std::vector<SDK::Instance> PlayerModels = Playermodels.Children();
                //Logging::Log(Logging::LogType::WARNING, "Players found - %zu", PlayerModels.size());

                for (SDK::Instance PlayerModel : PlayerModels)
                {
                    if (!PlayerModel.Address || PlayerModel.Class() != "Model")
                        continue;

                    SDK::Cache::Player Cache;
                    Cache.CharacterObject = PlayerModel;
                    Cache.CharacterObjectAddress = PlayerModel.Address;

                    /* w method */
                    Cache.PlayerName = PlayerModel.Name();
                    Cache.DisplayName = PlayerModel.Name();

                    /* w method x2 */
                    for (SDK::Instance PlayerInst : Globals::Players.Children())
                    {
                        if (!PlayerInst.Address) continue;

                        uint64_t playerUserId = SDK::Memory->Read<uint64_t>(PlayerInst.Address + SDK::Offsets::UserId);
                        if (playerUserId == 0) continue;

                        uint64_t modelUserId = 0;
                        try { modelUserId = std::stoull(PlayerModel.Name()); }
                        catch (...) { continue; }

                        if (playerUserId == modelUserId)
                        {
                            SDK::Player PlayerObj = (SDK::Player)PlayerInst;
                            Cache.PlayerObject = PlayerObj;
                            Cache.PlayerObjectAddress = PlayerInst.Address;
                            Cache.PlayerName = PlayerObj.Name();
                            Cache.DisplayName = PlayerObj.DisplayName();
                            break;
                        }
                    }

                    /* Template */
                    Cache.Health = 100.0f;
                    Cache.MaxHealth = 100.0f;

                    Cache.RigType = 3;

                    // Primary parts: RootPart, Head, UpperTorso, RightHand, LeftHand, LeftFoot, RightFoot
                    std::vector<SDK::Instance> allParts;

                    for (SDK::Instance Child : PlayerModel.Children())
                    {
                        std::string cls = Child.Class();
                        if (cls == "Part" || cls == "MeshPart")
                            allParts.push_back(Child);
                    }

                    // prim parts
                    Cache.HumanoidRootPart = BoneUtils::InstanceToBone(
                        BoneUtils::FindPartByName(PlayerModel, { "RootPart" })
                    );
                    Cache.Head = BoneUtils::InstanceToBone(
                        BoneUtils::FindPartByName(PlayerModel, { "Head" })
                    );
                    Cache.LeftArm = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(PlayerModel, { "Left Arm", "LeftUpperArm" }));
                    Cache.RightArm = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(PlayerModel, { "Right Arm", "RightUpperArm" }));
                    Cache.LeftLeg = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(PlayerModel, { "Left Leg", "LeftUpperLeg" }));
                    Cache.RightLeg = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(PlayerModel, { "Right Leg", "RightUpperLeg" }));

                    // useless humanoid
                    SDK::Instance ClothingManager = PlayerModel.FindFirstChild("ClothingManager");

                    /*
                    if (ClothingManager.Address)
                    {
                        for (SDK::Instance Child : ClothingManager.Children())
                        {
                            std::string cls = Child.Class();
                            if (cls == "Part" || cls == "MeshPart" || cls == "Model")
                                allParts.push_back(Child);
                        }
                    }
                    */

                    // Convert each to Bone and update info, skip if it's the Head or Root (already handled)
                    for (SDK::Instance PartInst : allParts)
                    {
                        if (!PartInst.Address)
                            continue;
                        if (Cache.Head.Object.Address && PartInst.Address == Cache.Head.Object.Address)
                            continue;
                        if (Cache.HumanoidRootPart.Object.Address && PartInst.Address == Cache.HumanoidRootPart.Object.Address)
                            continue;

                        SDK::Cache::Bone NewBone = BoneUtils::InstanceToBone(PartInst);
                        BoneUtils::UpdateBoneInfo(NewBone);
                        Cache.Bones.push_back(NewBone);
                    }

                    BoneUtils::UpdateBoneInfo(Cache.Head);
                    BoneUtils::UpdateBoneInfo(Cache.HumanoidRootPart);

                    Cache.HighlightSolution = BoneUtils::UnionAllHulls(Cache.Bones);

                    Logging::Log(Logging::LogType::WARNING, "Player %s: %zu bones", Cache.DisplayName.c_str(), Cache.Bones.size());

                    uint64_t modelUserId = 0;
                    try {
                        modelUserId = std::stoull(PlayerModel.Name());
                    }
                    catch (...) {}

                    uint64_t localUserId = 0;
                    if (Globals::LocalPlayer.Address) {
                        localUserId = SDK::Memory->Read<uint64_t>(Globals::LocalPlayer.Address + SDK::Offsets::UserId);
                    }

                    bool isLocalPlayer = false;
                    if (localUserId != 0 && modelUserId != 0 && localUserId == modelUserId) {
                        Cache.PlayerObject = Globals::LocalPlayer;
                        Cache.PlayerObjectAddress = Globals::LocalPlayer.Address;
                        Cache.PlayerName = Globals::LocalPlayer.Name();
                        Cache.DisplayName = Globals::LocalPlayer.DisplayName();
                        isLocalPlayer = true;

                        PendingLocalPlayer = Cache;
                    }

                    else {
                        for (SDK::Instance PlayerInst : Globals::Players.Children()) {
                            if (!PlayerInst.Address) continue;
                            if (PlayerInst.Name() == PlayerModel.Name()) {
                                Cache.PlayerObject = (SDK::Player)PlayerInst;
                                Cache.PlayerObjectAddress = PlayerInst.Address;
                                Cache.PlayerName = PlayerInst.Name();
                                Cache.DisplayName = ((SDK::Player)PlayerInst).DisplayName();
                                break;
                            }
                        }
                    }

                    CacheList.push_back(Cache);
                }

                for (SDK::Cache::Player& NewPlayer : CacheList)
                {
                    const auto& LP = PendingLocalPlayer.PlayerObjectAddress ? PendingLocalPlayer : SDK::Cache::LocalPlayer;
                    if (LP.HumanoidRootPart.WorldPosition != SDK::Vector3())
                    {
                        NewPlayer.Distance = NewPlayer.HumanoidRootPart.WorldPosition.distance(
                            LP.HumanoidRootPart.WorldPosition
                        );
                    }
                }

                {
                    std::lock_guard<std::mutex> lock(SDK::Cache::PlayersMutex);
                    SDK::Cache::Players = std::move(CacheList);
                    if (PendingLocalPlayer.PlayerObjectAddress)
                        SDK::Cache::LocalPlayer = PendingLocalPlayer;
                }
            }
            else
            {
                std::vector<SDK::Instance> Roster = Globals::Players.Children();
                std::vector<uintptr_t> CharAddrs;
                CharAddrs.reserve(Roster.size());
                for (SDK::Instance& R : Roster)
                    CharAddrs.push_back(((SDK::Player)R).Character().Address);
                bool changed = true;
                {
                    std::lock_guard<std::mutex> g(SDK::Cache::PlayersMutex);
                    if (Roster.size() == SDK::Cache::Players.size())
                    {
                        changed = false;
                        for (size_t i = 0; i < Roster.size(); ++i)
                        {
                            if (SDK::Cache::Players[i].PlayerObjectAddress != Roster[i].Address ||
                                SDK::Cache::Players[i].CharacterObjectAddress != CharAddrs[i])
                            {
                                changed = true;
                                break;
                            }
                        }
                    }
                }
                if (!changed)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    continue;
                }
                Globals::LocalPlayer = Globals::Players.LocalPlayer();
                std::string LocalPlayerName = Globals::LocalPlayer.Name();
                std::vector<SDK::Cache::Player> CacheList;
                SDK::Cache::Player PendingLocalPlayer;
                for (SDK::Instance Instance : Globals::Players.Children())
                {
                    SDK::Player Player = (SDK::Player)Instance;
                    SDK::Cache::Player Cache;
                    Cache.PlayerObject = Player;
                    Cache.PlayerObjectAddress = Player.Address;
                    Cache.CharacterObject = Player.Character();
                    Cache.CharacterObjectAddress = Cache.CharacterObject.Address;
                    if (!Cache.CharacterObjectAddress)
                        continue;
                    if (!Cache.PlayerObjectAddress)
                        continue;
                    Cache.PlayerName = Player.Name();
                    Cache.DisplayName = Player.DisplayName();
                    Cache.Team = Cache.PlayerObject.Team().Address;

                    Cache.HumanoidRootPart = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "HumanoidRootPart", "RootPart", "Root", "root", "LowerTorso", "Torso", "torso" }));
                    Cache.Head = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Head", "head", "HeadMesh", "Head1" }));
                    Cache.LeftArm = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Left Arm", "LeftUpperArm", "LeftLowerArm", "LeftHand" }));
                    Cache.RightArm = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Right Arm", "RightUpperArm", "RightLowerArm", "RightHand" }));
                    Cache.LeftLeg = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Left Leg", "LeftUpperLeg", "LeftLowerLeg", "LeftFoot" }));
                    Cache.RightLeg = BoneUtils::InstanceToBone(BoneUtils::FindPartByName(Cache.CharacterObject, { "Right Leg", "RightUpperLeg", "RightLowerLeg", "RightFoot" }));
                    Cache.Humanoid = static_cast<SDK::Humanoid>(Cache.CharacterObject.FindFirstChildOfClass("Humanoid"));
                    Cache.RigType = Cache.Humanoid.RigType();
                    SDK::Instance ToolInst = Cache.CharacterObject.FindFirstChildOfClass("Tool");
                    if (ToolInst.Address)
                        Cache.Weapon = ToolInst.Name();

                    if (Globals::GameID == SDK::Games::MurderMystery2)
                    {
                        Cache.Role = "Innocent";
                        Cache.TeamColor = ImColor(Globals::Esp::Colors::Innocent[0], Globals::Esp::Colors::Innocent[1], Globals::Esp::Colors::Innocent[2], Globals::Esp::Colors::Innocent[3]);

                        auto findTool = [](SDK::Instance Container, const std::string& name) -> SDK::Instance {
                            if (!Container.Address) return {};
                            for (SDK::Instance Child : Container.Children())
                            {
                                if (Child.Class() == "Tool" && Child.Name() == name)
                                    return Child;
                            }
                            return {};
                        };

                        SDK::Instance Knife = findTool(Cache.CharacterObject, "Knife");
                        SDK::Instance Gun = findTool(Cache.CharacterObject, "Gun");
                        if (!Knife.Address || !Gun.Address)
                        {
                            SDK::Instance Backpack = Player.FindFirstChildOfClass("Backpack");
                            if (!Knife.Address) Knife = findTool(Backpack, "Knife");
                            if (!Gun.Address) Gun = findTool(Backpack, "Gun");
                        }
                        if (Knife.Address)
                        {
                            Cache.Role = "Murderer";
                            Cache.TeamColor = ImColor(Globals::Esp::Colors::Murderer[0], Globals::Esp::Colors::Murderer[1], Globals::Esp::Colors::Murderer[2], Globals::Esp::Colors::Murderer[3]);
                        }
                        else if (Gun.Address)
                        {
                            Cache.Role = "Sheriff";
                            Cache.TeamColor = ImColor(Globals::Esp::Colors::Sheriff[0], Globals::Esp::Colors::Sheriff[1], Globals::Esp::Colors::Sheriff[2], Globals::Esp::Colors::Sheriff[3]);
                        }

                        if (Globals::Esp::Team && Globals::Esp::TeamMode <= 1)
                        {
                            SDK::Cache::Flag RoleFlag;
                            RoleFlag.Flag = Cache.Role;
                            RoleFlag.Color = Cache.TeamColor;
                            Cache.Flags.push_back(RoleFlag);
                        }
                    }
                    BoneUtils::UpdateBoneInfo(Cache.Head);
                    BoneUtils::UpdateBoneInfo(Cache.HumanoidRootPart);
                    for (SDK::Instance Bone : Cache.CharacterObject.Children())
                    {
                        std::string Class = Bone.Class();
                        if (Class != "Part" && Class != "MeshPart")
                            continue;
                        SDK::Cache::Bone NewBone = BoneUtils::InstanceToBone(Bone);
                        BoneUtils::UpdateBoneInfo(NewBone);
                        Cache.Bones.push_back(NewBone);
                        // ponytail: cap stored parts per player. this game's chars have ~2000 parts;
                        // storing them all made every 20ms tick hold PlayersMutex for 1.5s, blocking the
                        // render. first N children = rig + accessories, covers the silhouette.
                        if (Cache.Bones.size() >= 128)
                            break;
                    }

                   
                    if (Cache.PlayerObjectAddress == Globals::Players.LocalPlayer().Address)
                    {
                        PendingLocalPlayer = Cache;
                        auto playergui = Player.FindFirstChildOfClass("PlayerGui");
                        std::lock_guard<std::mutex> crosshairLock(SDK::CrosshairsMutex);
                        SDK::Crosshairs.clear();
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("MainScreenGui").FindFirstChild("Aim"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("IntellectUi").FindFirstChild("Aim"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("Main Screen").FindFirstChild("Aim"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("Interface").FindFirstChild("Main").FindFirstChild("Aim"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("MouseUnlock").FindFirstChild("Frame"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("Crosshair").FindFirstChild("Main"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("CoreGUI").FindFirstChild("Crosshair"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("Cursor").FindFirstChild("dot"));
                       // SDK::Crosshairs.push_back(playergui.FindFirstChild("ItemGUI").FindFirstChild("Crosshair"));
                    }
                    if (Globals::Misc::TeamCheck && Cache.Team && Cache.Team == Globals::LocalPlayer.Team().Address)
                        continue;
                    if (Globals::Esp::Region)
                    {
                       
                        std::string Flag = SDK::Memory->ReadString(Cache.PlayerObjectAddress + 0xF8);
                        SDK::Cache::Flag FlagObject;
                        FlagObject.Flag = Flag;
                        FlagObject.Color = ImColor(Globals::Esp::Colors::Region[0], Globals::Esp::Colors::Region[1], Globals::Esp::Colors::Region[2], Globals::Esp::Colors::Region[3]);
                        Cache.Flags.push_back(FlagObject);
                    }
                    if (Globals::Esp::Leaderstats)
                    {
                        SDK::Instance LeaderStats = Cache.PlayerObject.FindFirstChild("leaderstats");
                        if (LeaderStats.Address)
                        {
                            for (SDK::Instance Stat : LeaderStats.Children())
                            {
                                if (Stat.Class() == "IntValue")
                                {
                                    int Value = SDK::Memory->Read<int>(Stat.Address + SDK::Offsets::Value);
                                    std::string Name = Stat.Name();
                                    std::string Flag = Name + ": " + std::to_string(Value);
                                    SDK::Cache::Flag FlagObject;
                                    FlagObject.Flag = Flag;
                                    FlagObject.Color = ImColor(Globals::Esp::Colors::LeaderStats[0], Globals::Esp::Colors::LeaderStats[1], Globals::Esp::Colors::LeaderStats[2], Globals::Esp::Colors::LeaderStats[3]);
                                    Cache.Flags.push_back(FlagObject);
                                }
                                if (Stat.Class() == "NumberValue")
                                {
                                    double Value = SDK::Memory->Read<double>(Stat.Address + SDK::Offsets::Value);
                                    std::string Name = Stat.Name();
                                    std::string Flag = Name + ": " + std::to_string(Value);
                                    SDK::Cache::Flag FlagObject;
                                    FlagObject.Flag = Flag;
                                    FlagObject.Color = ImColor(Globals::Esp::Colors::LeaderStats[0], Globals::Esp::Colors::LeaderStats[1], Globals::Esp::Colors::LeaderStats[2], Globals::Esp::Colors::LeaderStats[3]);
                                    Cache.Flags.push_back(FlagObject);
                                }
                                if (Stat.Class() == "BoolValue")
                                {
                                    bool Value = SDK::Memory->Read<bool>(Stat.Address + SDK::Offsets::Value);
                                    std::string Name = Stat.Name();
                                    std::string Flag = Name + ": " + (Value ? "True" : "False");
                                    SDK::Cache::Flag FlagObject;
                                    FlagObject.Flag = Flag;
                                    FlagObject.Color = ImColor(Globals::Esp::Colors::LeaderStats[0], Globals::Esp::Colors::LeaderStats[1], Globals::Esp::Colors::LeaderStats[2], Globals::Esp::Colors::LeaderStats[3]);
                                    Cache.Flags.push_back(FlagObject);
                                }
                                if (Stat.Class() == "StringValue")
                                {
                                    std::string Value = SDK::Memory->ReadString(Stat.Address + SDK::Offsets::Value);
                                    std::string Name = Stat.Name();
                                    std::string Flag = Name + ": " + Value;
                                    SDK::Cache::Flag FlagObject;
                                    FlagObject.Flag = Flag;
                                    FlagObject.Color = ImColor(Globals::Esp::Colors::LeaderStats[0], Globals::Esp::Colors::LeaderStats[1], Globals::Esp::Colors::LeaderStats[2], Globals::Esp::Colors::LeaderStats[3]);
                                    Cache.Flags.push_back(FlagObject);
                                }
                            }
                        }

                    }
                    if (Player.Team().Address && Globals::GameID != SDK::Games::MurderMystery2)
                    {
                        SDK::Color3 TeamCol = Player.Team().TeamColor();
                        Cache.TeamColor = ImColor(TeamCol.r, TeamCol.g, TeamCol.b);
                        if (Globals::Esp::Team && Globals::Esp::TeamMode <= 1)
                        {
                            SDK::Cache::Flag Friendly;
                            Friendly.Flag = Player.Team().Name();
                            Friendly.Color = Cache.TeamColor;
                            Cache.Flags.push_back(Friendly);
                        }
                    }
                    CacheList.push_back(Cache);
                    
                }

                for (SDK::Cache::Player& NewPlayer : CacheList)
                {
                    if (NewPlayer.PlayerObjectAddress == Globals::Players.LocalPlayer().Address)
                    {
                        PendingLocalPlayer = NewPlayer;
                        auto playergui = NewPlayer.PlayerObject.FindFirstChildOfClass("PlayerGui");
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("MainScreenGui").FindFirstChild("Aim"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("IntellectUi").FindFirstChild("Aim"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("Main Screen").FindFirstChild("Aim"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("Interface").FindFirstChild("Main").FindFirstChild("Aim"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("MouseUnlock").FindFirstChild("Frame"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("Crosshair").FindFirstChild("Main"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("CoreGUI").FindFirstChild("Crosshair"));
                        SDK::Crosshairs.push_back(playergui.FindFirstChild("Cursor").FindFirstChild("dot"));
                    }
                    const auto& LP = PendingLocalPlayer.PlayerObjectAddress ? PendingLocalPlayer : SDK::Cache::LocalPlayer;
                    if (LP.PlayerObjectAddress)
                    {
                        NewPlayer.Distance = NewPlayer.HumanoidRootPart.WorldPosition.distance(LP.HumanoidRootPart.WorldPosition);
                    }
                }
                {
                    std::lock_guard<std::mutex> lock(SDK::Cache::PlayersMutex);
                    SDK::Cache::Players = std::move(CacheList);
                    if (PendingLocalPlayer.PlayerObjectAddress)
                        SDK::Cache::LocalPlayer = PendingLocalPlayer;
                }

                if (Globals::GameID == SDK::Games::MurderMystery2 && Globals::Esp::DroppedGun)
                {
                    std::vector<SDK::Cache::Item> newItems;
                    bool sheriffAlive = false;
                    {
                        std::lock_guard<std::mutex> lock(SDK::Cache::PlayersMutex);
                        for (const auto& p : SDK::Cache::Players)
                        {
                            if (p.Role == "Sheriff" && p.Health > 0) { sheriffAlive = true; break; }
                        }
                    }
                    if (!sheriffAlive)
                    {
                        try
                        {
                            SDK::Instance Workspace = Globals::Workspace;
                            for (SDK::Instance Map : Workspace.Children())
                            {
                                SDK::Instance GunDrop = Map.FindFirstChild("GunDrop");
                                if (!GunDrop.Address)
                                {
                                    for (SDK::Instance Sub : Map.Children())
                                    {
                                        GunDrop = Sub.FindFirstChild("GunDrop");
                                        if (GunDrop.Address) break;
                                    }
                                }
                                if (GunDrop.Address)
                                {
                                    SDK::Primitive Prim = GunDrop.Primitive();
                                    if (!Prim.Address)
                                    {
                                        SDK::Instance Part = GunDrop.FindFirstChildOfClass("MeshPart");
                                        if (!Part.Address) Part = GunDrop.FindFirstChildOfClass("Part");
                                        if (Part.Address) Prim = Part.Primitive();
                                    }
                                    if (Prim.Address)
                                    {
                                        SDK::Cache::Item item;
                                        item.Name = "Gun";
                                        item.Address = GunDrop.Address;
                                        item.WorldPosition = Prim.Position();
                                        newItems.push_back(item);
                                    }
                                }
                            }
                        }
                        catch (...) {}
                    }
                    std::lock_guard<std::mutex> lock(SDK::Cache::ItemsMutex);
                    SDK::Cache::Items = std::move(newItems);
                }
                else if (Globals::GameID != SDK::Games::MurderMystery2)
                {
                    std::lock_guard<std::mutex> lock(SDK::Cache::ItemsMutex);
                    SDK::Cache::Items.clear();
                }
            }
        }
        catch (...)
        {
            Logging::Log(Logging::LogType::ERR, "Caught crash at cache");
        }
        {
            static auto lastBuildLog = std::chrono::steady_clock::now();
            auto nowB = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(nowB - lastBuildLog).count() >= 15)
            {
                lastBuildLog = nowB;
                auto buildMs = std::chrono::duration_cast<std::chrono::milliseconds>(nowB - buildStart).count();
                Logging::Log(Logging::LogType::INFO, ("[perf] PlayerCache build=" + std::to_string(buildMs) + "ms players=" + std::to_string(SDK::Cache::Players.size())).c_str());
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}


void UpdatePositions()
{
    // ponytail: normal priority on purpose - this thread holds PlayersMutex, which the
    // render try_locks; below-normal stretched a ~90ms tick into a 1.5s lock hold
    while (true)
    {
        if (!Globals::DataModel.FindFirstChildOfClass("Workspace").Address)
        {
            // not attached / still loading - don't busy-spin a core
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
            continue;
        }
        try
        {
            if (SDK::Cache::Players.size() == 0)
                std::this_thread::sleep_for(std::chrono::seconds(1));
            BoneUtils::UpdateBoneInfo(SDK::Cache::LocalPlayer.HumanoidRootPart);
            BoneUtils::UpdateBoneInfo(SDK::Cache::LocalPlayer.Head);
            SDK::Vector3 camPos{};
            bool haveCam = false;
            try
            {
                SDK::Instance camInst = Globals::Workspace.FindFirstChildOfClass("Camera");
                if (camInst.Address)
                {
                    camPos = ((SDK::Camera)camInst).CameraPosition();
                    haveCam = true;
                }
            }
            catch (...) { }
            static int posTick = 0;
            // ponytail: full bone+box pass every 2nd tick (~40ms, ~25fps boxes).
            // every tick doubled the chance of computing a box from a garbage part
            // read (INF coords -> crash in AddRect when drawn).
            auto tWaitStart = std::chrono::steady_clock::now();
            size_t workSize = 0;
            auto tAcquired = tWaitStart;

            struct BoneSnapshot {
                SDK::Instance obj;
                SDK::Matrix3 rot{};
                SDK::Vector3 pos{};
                SDK::Vector3 size{};
                bool valid = false;
            };
            struct PlayerSnapshot {
                BoneSnapshot head{};
                BoneSnapshot hrp{};
                std::vector<BoneSnapshot> bones{};
                size_t index = 0;
            };

            std::vector<PlayerSnapshot> snaps;
            {
                std::lock_guard<std::mutex> g(SDK::Cache::PlayersMutex);
                tAcquired = std::chrono::steady_clock::now();
                workSize = SDK::Cache::Players.size();
                snaps.reserve(workSize);
                for (size_t i = 0; i < SDK::Cache::Players.size(); i++)
                {
                    auto& Player = SDK::Cache::Players[i];
                    PlayerSnapshot s{};
                    s.index = i;
                    s.head.obj = Player.Head.Object;
                    s.head.valid = s.head.obj.Address != 0;
                    s.hrp.obj = Player.HumanoidRootPart.Object;
                    s.hrp.valid = s.hrp.obj.Address != 0;
                    s.bones.reserve(Player.Bones.size());
                    for (auto& Bone : Player.Bones)
                    {
                        BoneSnapshot bs{};
                        bs.obj = Bone.Object;
                        bs.valid = bs.obj.Address != 0;
                        s.bones.push_back(bs);
                    }
                    snaps.push_back(std::move(s));
                }
            }

            for (auto& s : snaps)
            {
                if (s.head.valid) {
                    SDK::Primitive p = s.head.obj.Primitive();
                    if (p.Address) p.ReadAll(s.head.rot, s.head.pos, s.head.size);
                    else s.head.valid = false;
                }
                if (s.hrp.valid) {
                    SDK::Primitive p = s.hrp.obj.Primitive();
                    if (p.Address) p.ReadAll(s.hrp.rot, s.hrp.pos, s.hrp.size);
                    else s.hrp.valid = false;
                }
                for (auto& bs : s.bones)
                {
                    if (!bs.valid) continue;
                    SDK::Primitive p = bs.obj.Primitive();
                    if (p.Address) p.ReadAll(bs.rot, bs.pos, bs.size);
                    else bs.valid = false;
                }
            }

            {
                std::lock_guard<std::mutex> g(SDK::Cache::PlayersMutex);
                for (auto& s : snaps)
                {
                    if (s.index >= SDK::Cache::Players.size()) continue;
                    auto& Player = SDK::Cache::Players[s.index];
                    if (s.head.valid) {
                        Player.Head.Rotation = s.head.rot;
                        Player.Head.WorldPosition = s.head.pos;
                        if (Player.Head.CacheSize) Player.Head.Size = s.head.size;
                    }
                    if (s.hrp.valid) {
                        Player.HumanoidRootPart.Rotation = s.hrp.rot;
                        Player.HumanoidRootPart.WorldPosition = s.hrp.pos;
                        if (Player.HumanoidRootPart.CacheSize) Player.HumanoidRootPart.Size = s.hrp.size;
                    }
                    for (size_t bi = 0; bi < s.bones.size() && bi < Player.Bones.size(); bi++)
                    {
                        if (!s.bones[bi].valid) continue;
                        auto& Bone = Player.Bones[bi];
                        Bone.Rotation = s.bones[bi].rot;
                        Bone.WorldPosition = s.bones[bi].pos;
                        if (Bone.CacheSize) Bone.Size = s.bones[bi].size;
                    }
                    if (SDK::Cache::LocalPlayer.PlayerObjectAddress && haveCam)
                    {
                        Player.Distance = Player.Head.WorldPosition.distance(camPos);
                    }
                }
            }
            {
                auto tEnd = std::chrono::steady_clock::now();
                auto waitMs = std::chrono::duration_cast<std::chrono::milliseconds>(tAcquired - tWaitStart).count();
                auto holdMs = std::chrono::duration_cast<std::chrono::milliseconds>(tEnd - tAcquired).count();
                static auto lastHoldLog = std::chrono::steady_clock::now();
                auto now4 = std::chrono::steady_clock::now();
                if (std::chrono::duration_cast<std::chrono::seconds>(now4 - lastHoldLog).count() >= 5)
                {
                    lastHoldLog = now4;
                    Logging::Log(Logging::LogType::INFO, ("[perf] UpdatePositions wait=" + std::to_string(waitMs) + "ms hold=" + std::to_string(holdMs) + "ms players=" + std::to_string(workSize)).c_str());
                }
            }
        }
        catch (...)
        {
            Logging::Log(Logging::LogType::ERR, "Caught crash at cache position update");
        }
        try
        {
            if (Globals::Explorer::TeleportRequest)
            {
                Globals::Explorer::TeleportRequest = false;
                SDK::Instance target(Globals::Explorer::TeleportAddress);
                if (target.Address && SDK::Cache::LocalPlayer.HumanoidRootPart.Object.Address)
                {
                    SDK::Vector3 pos{};
                    std::string cls = target.Class();
                    if (cls == "Model")
                    {
                        static auto findPartPos = [](SDK::Instance& inst, auto& self) -> SDK::Vector3 {
                            for (SDK::Instance child : inst.Children())
                            {
                                if (!child.Address) continue;
                                std::string cc = child.Class();
                                if (cc == "Part" || cc == "MeshPart" || cc == "UnionOperation")
                                {
                                    SDK::Vector3 p = child.Primitive().Position();
                                    if (p.x != 0 || p.y != 0 || p.z != 0)
                                        return p;
                                }
                                SDK::Vector3 nested = self(child, self);
                                if (nested.x != 0 || nested.y != 0 || nested.z != 0)
                                    return nested;
                            }
                            return SDK::Vector3(0, 0, 0);
                        };
                        pos = findPartPos(target, findPartPos);
                    }
                    else
                    {
                        pos = target.Primitive().Position();
                    }
                    if (pos.x != 0 || pos.y != 0 || pos.z != 0)
                        SDK::Cache::LocalPlayer.HumanoidRootPart.Object.Primitive().SetPosition(pos);
                }
            }
        }
        catch (...)
        {
            Logging::Log(Logging::LogType::ERR, "Caught crash at cache teleport");
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); // ponytail: 5ms->20ms cut for UI perf; raise if aim tracking feels stale
    }
}
namespace HTTPTHINGS
{
    std::string SecureRequest(const std::string& URL) {
        if (URL.empty()) {
            return "";
        }

        std::string response;
        HINTERNET hSession = NULL;
        HINTERNET hConnect = NULL;
        HINTERNET hRequest = NULL;

        try {
            // Parse URL manually
            std::string url = URL;
            std::string protocol, host, path;
            INTERNET_PORT port = INTERNET_DEFAULT_HTTP_PORT;
            DWORD flags = 0;

            size_t protocolEnd = url.find("://");
            if (protocolEnd != std::string::npos) {
                protocol = url.substr(0, protocolEnd);
                url = url.substr(protocolEnd + 3);
                if (protocol == "https") {
                    port = INTERNET_DEFAULT_HTTPS_PORT;
                    flags = WINHTTP_FLAG_SECURE;
                }
            }

            size_t pathStart = url.find("/");
            if (pathStart != std::string::npos) {
                host = url.substr(0, pathStart);
                path = url.substr(pathStart);
            } else {
                host = url;
                path = "/";
            }

            size_t portStart = host.find(":");
            if (portStart != std::string::npos) {
                port = (INTERNET_PORT)atoi(host.substr(portStart + 1).c_str());
                host = host.substr(0, portStart);
            }

            // Initialize WinHTTP
            hSession = WinHttpOpen(xorstr_(L"SecureClient/1.0"), WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
            if (!hSession) {
                return "";
            }

            WinHttpSetTimeouts(hSession, 10000, 10000, 30000, 30000);

            // Convert to wide string
            std::wstring wHost(host.begin(), host.end());
            std::wstring wPath(path.begin(), path.end());

            // Connect to server
            hConnect = WinHttpConnect(hSession, wHost.c_str(), port, 0);
            if (!hConnect) {
                WinHttpCloseHandle(hSession);
                return "";
            }

            // Create request
            hRequest = WinHttpOpenRequest(hConnect, L"GET", wPath.c_str(), NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, flags);
            if (!hRequest) {
                WinHttpCloseHandle(hConnect);
                WinHttpCloseHandle(hSession);
                return "";
            }

            // Send request
            if (!WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
                WinHttpCloseHandle(hRequest);
                WinHttpCloseHandle(hConnect);
                WinHttpCloseHandle(hSession);
                return "";
            }

            // Wait for response
            if (!WinHttpReceiveResponse(hRequest, NULL)) {
                WinHttpCloseHandle(hRequest);
                WinHttpCloseHandle(hConnect);
                WinHttpCloseHandle(hSession);
                return "";
            }

            // Check status code
            DWORD statusCode = 0;
            DWORD statusCodeSize = sizeof(statusCode);
            WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, NULL, &statusCode, &statusCodeSize, NULL);
            
            if (statusCode >= 400) {
                WinHttpCloseHandle(hRequest);
                WinHttpCloseHandle(hConnect);
                WinHttpCloseHandle(hSession);
                return "";
            }

            // Read response data
            DWORD bytesAvailable = 0;
            do {
                if (!WinHttpQueryDataAvailable(hRequest, &bytesAvailable)) {
                    break;
                }

                if (bytesAvailable == 0) {
                    break;
                }

                char* buffer = new char[bytesAvailable + 1];
                DWORD bytesRead = 0;
                if (WinHttpReadData(hRequest, buffer, bytesAvailable, &bytesRead)) {
                    buffer[bytesRead] = '\0';
                    response.append(buffer, bytesRead);
                }
                delete[] buffer;
            } while (bytesAvailable > 0);

            // Cleanup
            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);

            return response;
        }
        catch (const std::exception& e) {
            if (hRequest) WinHttpCloseHandle(hRequest);
            if (hConnect) WinHttpCloseHandle(hConnect);
            if (hSession) WinHttpCloseHandle(hSession);
            return "";
        }
        catch (...) {
            if (hRequest) WinHttpCloseHandle(hRequest);
            if (hConnect) WinHttpCloseHandle(hConnect);
            if (hSession) WinHttpCloseHandle(hSession);
            return "";
        }
    }

    std::vector<unsigned char> HttpGetBinary(const std::string& URL) {
        if (URL.empty()) {
            return {};
        }

        std::vector<unsigned char> response;
        HINTERNET hSession = NULL;
        HINTERNET hConnect = NULL;
        HINTERNET hRequest = NULL;

        try {
            // Parse URL manually
            std::string url = URL;
            std::string protocol, host, path;
            INTERNET_PORT port = INTERNET_DEFAULT_HTTP_PORT;
            DWORD flags = 0;

            size_t protocolEnd = url.find("://");
            if (protocolEnd != std::string::npos) {
                protocol = url.substr(0, protocolEnd);
                url = url.substr(protocolEnd + 3);
                if (protocol == "https") {
                    port = INTERNET_DEFAULT_HTTPS_PORT;
                    flags = WINHTTP_FLAG_SECURE;
                }
            }

            size_t pathStart = url.find("/");
            if (pathStart != std::string::npos) {
                host = url.substr(0, pathStart);
                path = url.substr(pathStart);
            } else {
                host = url;
                path = "/";
            }

            size_t portStart = host.find(":");
            if (portStart != std::string::npos) {
                port = (INTERNET_PORT)atoi(host.substr(portStart + 1).c_str());
                host = host.substr(0, portStart);
            }

            // Initialize WinHTTP
            hSession = WinHttpOpen(xorstr_(L"SecureClient/1.0"), WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
            if (!hSession) {
                return {};
            }

            WinHttpSetTimeouts(hSession, 10000, 10000, 30000, 30000);

            // Convert to wide string
            std::wstring wHost(host.begin(), host.end());
            std::wstring wPath(path.begin(), path.end());

            // Connect to server
            hConnect = WinHttpConnect(hSession, wHost.c_str(), port, 0);
            if (!hConnect) {
                WinHttpCloseHandle(hSession);
                return {};
            }

            // Create request
            hRequest = WinHttpOpenRequest(hConnect, L"GET", wPath.c_str(), NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, flags);
            if (!hRequest) {
                WinHttpCloseHandle(hConnect);
                WinHttpCloseHandle(hSession);
                return {};
            }

            // Send request
            if (!WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
                WinHttpCloseHandle(hRequest);
                WinHttpCloseHandle(hConnect);
                WinHttpCloseHandle(hSession);
                return {};
            }

            // Wait for response
            if (!WinHttpReceiveResponse(hRequest, NULL)) {
                WinHttpCloseHandle(hRequest);
                WinHttpCloseHandle(hConnect);
                WinHttpCloseHandle(hSession);
                return {};
            }

            // Check status code
            DWORD statusCode = 0;
            DWORD statusCodeSize = sizeof(statusCode);
            WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, NULL, &statusCode, &statusCodeSize, NULL);
            
            if (statusCode >= 400) {
                WinHttpCloseHandle(hRequest);
                WinHttpCloseHandle(hConnect);
                WinHttpCloseHandle(hSession);
                return {};
            }

            // Read response data
            DWORD bytesAvailable = 0;
            do {
                if (!WinHttpQueryDataAvailable(hRequest, &bytesAvailable)) {
                    break;
                }

                if (bytesAvailable == 0) {
                    break;
                }

                unsigned char* buffer = new unsigned char[bytesAvailable];
                DWORD bytesRead = 0;
                if (WinHttpReadData(hRequest, buffer, bytesAvailable, &bytesRead)) {
                    response.insert(response.end(), buffer, buffer + bytesRead);
                }
                delete[] buffer;
            } while (bytesAvailable > 0);

            // Cleanup
            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);

            return response;
        }
        catch (const std::exception& e) {
            if (hRequest) WinHttpCloseHandle(hRequest);
            if (hConnect) WinHttpCloseHandle(hConnect);
            if (hSession) WinHttpCloseHandle(hSession);
            return {};
        }
        catch (...) {
            if (hRequest) WinHttpCloseHandle(hRequest);
            if (hConnect) WinHttpCloseHandle(hConnect);
            if (hSession) WinHttpCloseHandle(hSession);
            return {};
        }
    }
}

std::string GetHeadshotURL(std::uint64_t userID)
{
    if (userID == 0) {
        return "";
    }

    try {
        std::string apiUrl =
            xorstr_("https://thumbnails.roblox.com/v1/users/avatar-headshot?userIds=")
            + std::to_string(userID)
            + xorstr_("&size=420x420&format=Png&isCircular=false");

        std::string jsonResponse = HTTPTHINGS::SecureRequest(apiUrl);
        if (jsonResponse.empty()) {
            return "";
        }

        nlohmann::json parsed;
        try {
            parsed = nlohmann::json::parse(jsonResponse);
        }
        catch (const nlohmann::json::parse_error& e) {
            return "";
        }

        if (parsed.contains(xorstr_("data")) &&
            parsed[xorstr_("data")].is_array() &&
            !parsed[xorstr_("data")].empty() &&
            parsed[xorstr_("data")][0].contains(xorstr_("imageUrl"))) {

            return parsed[xorstr_("data")][0].value(xorstr_("imageUrl"), "");
        }

        return "";
    }
    catch (const std::exception& e) {
        return "";
    }
    catch (...) {
        return "";
    }
}

ID3D11ShaderResourceView* CreateTextureFromPNG(
    ID3D11Device* device,
    ID3D11DeviceContext* context,
    const std::vector<unsigned char>& pngData)
{
    if (!device || pngData.empty()) {
        return nullptr;
    }

    try {
        int width, height, channels;
        unsigned char* imageData = stbi_load_from_memory(
            pngData.data(),
            static_cast<int>(pngData.size()),
            &width,
            &height,
            &channels,
            4
        );

        if (!imageData || width <= 0 || height <= 0) {
            if (imageData) {
                stbi_image_free(imageData);
            }
            return nullptr;
        }

        D3D11_TEXTURE2D_DESC desc = {};
        desc.Width = width;
        desc.Height = height;
        desc.MipLevels = 1;
        desc.ArraySize = 1;
        desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        desc.SampleDesc.Count = 1;
        desc.Usage = D3D11_USAGE_DEFAULT;
        desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
        desc.CPUAccessFlags = 0;

        D3D11_SUBRESOURCE_DATA initData = {};
        initData.pSysMem = imageData;
        initData.SysMemPitch = width * 4;

        ID3D11Texture2D* texture = nullptr;
        HRESULT hr = device->CreateTexture2D(&desc, &initData, &texture);
        if (FAILED(hr)) {
            stbi_image_free(imageData);
            return nullptr;
        }

        ID3D11ShaderResourceView* srv = nullptr;
        hr = device->CreateShaderResourceView(texture, nullptr, &srv);

        if (texture) {
            texture->Release();
        }
        stbi_image_free(imageData);

        if (FAILED(hr)) {
            return nullptr;
        }

        return srv;
    }
    catch (const std::exception& e) {
        return nullptr;
    }
    catch (...) {
        return nullptr;
    }
}

ID3D11ShaderResourceView* LoadAvatarTexture(std::uint64_t userID)
{
    if (userID == 0) {
        return nullptr;
    }

    try {
        std::string imageUrl = GetHeadshotURL(userID);
        if (imageUrl.empty()) {
            return nullptr;
        }

        std::vector<unsigned char> pngData = HTTPTHINGS::HttpGetBinary(imageUrl);
        if (pngData.empty()) {
            return nullptr;
        }

       
        if (!Globals::g_pd3dDevice || !Globals::g_pd3dDeviceContext) {
            return nullptr;
        }

        ID3D11ShaderResourceView* avatarTexture = CreateTextureFromPNG(
            Globals::g_pd3dDevice,
            Globals::g_pd3dDeviceContext,
            pngData
        );

        return avatarTexture;
    }
    catch (const std::exception& e) {
        return nullptr;
    }
    catch (...) {
        return nullptr;
    }
}

void LoadPlayerAvatar(SDK::Cache::Player& Player)
{
    try {
      
        if (Player.PlayerName.empty()) {
            return;
        }

        
        bool already = false;
        {
            std::lock_guard<std::mutex> lock(SDK::Cache::LoadedAvatarsMutex);
            for (const SDK::Cache::PlayerAvatar& AV : SDK::Cache::LoadedAvatars) {
                if (AV.PlayerName == Player.PlayerName) {
                    already = true;
                    break;
                }
            }
        }
        if (already) {
            return;
        }

   
        if (!Player.PlayerObjectAddress) {
            return;
        }

       
        if (!SDK::Memory) {
            return;
        }

        std::uint64_t id = 0;
        try {
            id = SDK::Memory->Read<std::uint64_t>(Player.PlayerObjectAddress + SDK::Offsets::UserId);
        }
        catch (...) {
            return;
        }

        if (id == 0) {
            return;
        }

        SDK::Cache::PlayerAvatar A;
        A.PlayerName = Player.PlayerName;
        A.Texture = LoadAvatarTexture(id);

       
        if (A.Texture) {
            std::lock_guard<std::mutex> lock(SDK::Cache::LoadedAvatarsMutex);
            // ponytail: fixed cap releases the oldest SRV so long sessions don't leak GPU memory
            while (SDK::Cache::LoadedAvatars.size() >= 150) {
                if (SDK::Cache::LoadedAvatars.front().Texture)
                    SDK::Cache::LoadedAvatars.front().Texture->Release();
                SDK::Cache::LoadedAvatars.erase(SDK::Cache::LoadedAvatars.begin());
            }
            SDK::Cache::LoadedAvatars.push_back(A);
        }
    }
    catch (const std::exception& e) {
        if (Logging::Log) {
            Logging::Log(Logging::LogType::ERR, std::string("Exception while loading avatar: " + std::string(e.what())).c_str());
        }
    }
    catch (...) {
        if (Logging::Log) {
            Logging::Log(Logging::LogType::ERR, "Unknown exception while loading avatar");
        }
    }
}

void PlayerAvatarUpdate()
{
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL);
    while (true) {
        if (!Globals::DataModel.FindFirstChildOfClass("Workspace").Address)
        {
            // not attached / still loading - don't busy-spin a core
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
            continue;
        }
        try {
            if (SDK::Cache::Players.empty()) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                continue;
            }

          
            struct AvatarTarget { std::string Name; uintptr_t Address; };
            std::vector<AvatarTarget> targets;
            {
                std::lock_guard<std::mutex> g(SDK::Cache::PlayersMutex);
                targets.reserve(SDK::Cache::Players.size());
                for (const auto& P : SDK::Cache::Players)
                    if (!P.PlayerName.empty())
                        targets.push_back({ P.PlayerName, P.PlayerObjectAddress });
            }
            // ponytail: copy only name+address, not the whole Player (deep hull copies) every 1s

            for (const AvatarTarget& t : targets) {
                try {
                    SDK::Cache::Player P;
                    P.PlayerName = t.Name;
                    P.PlayerObjectAddress = t.Address;
                    std::thread([P]() mutable {
                        try {
                            LoadPlayerAvatar(P);
                        }
                        catch (...) {}
                    }).detach();
                }
                catch (...) {}
            }

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        catch (const std::exception& e) {
            if (Logging::Log) {
                Logging::Log(Logging::LogType::ERR, std::string("Exception in PlayerAvatarUpdate: " + std::string(e.what())).c_str());
            }
            std::this_thread::sleep_for(std::chrono::seconds(5)); 
        }
        catch (...) {
            if (Logging::Log) {
                Logging::Log(Logging::LogType::ERR, "Unknown exception in PlayerAvatarUpdate");
            }
            std::this_thread::sleep_for(std::chrono::seconds(5)); 
        }
    }
}
void SDK::Cache::PlayerInfoUpdate()
{
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL);
    std::thread(UpdatePositions).detach();
    std::thread(PlayerAvatarUpdate).detach();
    while (true)
    {
        if (!Globals::DataModel.FindFirstChildOfClass("Workspace").Address)
        {
            // not attached / still loading - don't busy-spin a core
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
            continue;
        }
        try
        {

            if (SDK::Cache::Players.size() == 0)
                std::this_thread::sleep_for(std::chrono::seconds(1));
            auto holdT1 = std::chrono::steady_clock::now();
            std::chrono::steady_clock::time_point lockT1;

            struct InfoSnap {
                size_t index;
                float health = 0;
                float maxHealth = 0;
                std::string weapon;
                std::string role;
                ImColor teamColor;
            };
            std::vector<InfoSnap> snaps;
            {
                std::lock_guard<std::mutex> g(SDK::Cache::PlayersMutex);
                for (size_t i = 0; i < SDK::Cache::Players.size(); i++)
                {
                    auto& Player = SDK::Cache::Players[i];
                    InfoSnap s{};
                    s.index = i;
                    s.health = Player.Health;
                    s.maxHealth = Player.MaxHealth;
                    s.weapon = Player.Weapon;
                    s.role = Player.Role;
                    s.teamColor = Player.TeamColor;
                    snaps.push_back(std::move(s));
                }
            }

            for (auto& s : snaps)
            {
                if (s.index >= SDK::Cache::Players.size()) continue;
                auto& Player = SDK::Cache::Players[s.index];
                if (!Player.CharacterObjectAddress) continue;

                if (Globals::GameID == SDK::Games::BadBusiness)
                {
                    s.health = static_cast<float>(SDK::Memory->Read<double>(Player.CharacterObject.FindFirstChild("Health").Address + SDK::Offsets::Value));
                    s.maxHealth = static_cast<float>(SDK::Memory->Read<double>(Player.CharacterObject.FindFirstChild("Health").FindFirstChild("MaxHealth").Address + SDK::Offsets::Value));
                }
                else if (Globals::GameID == SDK::Games::PhantomForces)
                {
                    s.health = 100.0f;
                    s.maxHealth = 100.0f;
                }
                else if (Globals::GameID == SDK::Games::Deadline)
                {
                    if (Player.CharacterObject.FindFirstChildOfClass("Humanoid").Address)
                    {
                        s.health = Player.Humanoid.Health();
                        s.maxHealth = Player.Humanoid.MaxHealth();
                    }
                }
                else if (Globals::GameID == SDK::Games::GamesUniteTestingPlace)
                {
                    s.health = 100.0f;
                }
                else
                {
                    s.health = Player.Humanoid.Health();
                    s.maxHealth = Player.Humanoid.MaxHealth();

                    if (Globals::GameID == SDK::Games::MurderMystery2)
                    {
                        s.role = "Innocent";
                        s.teamColor = ImColor(Globals::Esp::Colors::Innocent[0], Globals::Esp::Colors::Innocent[1], Globals::Esp::Colors::Innocent[2], Globals::Esp::Colors::Innocent[3]);

                        auto findTool = [](SDK::Instance Container, const std::string& name) -> SDK::Instance {
                            if (!Container.Address) return {};
                            for (SDK::Instance Child : Container.Children())
                            {
                                if (Child.Class() == "Tool" && Child.Name() == name)
                                    return Child;
                            }
                            return {};
                        };

                        SDK::Instance Knife = findTool(Player.CharacterObject, "Knife");
                        SDK::Instance Gun = findTool(Player.CharacterObject, "Gun");
                        if (!Knife.Address || !Gun.Address)
                        {
                            SDK::Instance Backpack = Player.PlayerObject.FindFirstChildOfClass("Backpack");
                            if (!Knife.Address) Knife = findTool(Backpack, "Knife");
                            if (!Gun.Address) Gun = findTool(Backpack, "Gun");
                        }
                        if (Knife.Address)
                        {
                            s.role = "Murderer";
                            s.teamColor = ImColor(Globals::Esp::Colors::Murderer[0], Globals::Esp::Colors::Murderer[1], Globals::Esp::Colors::Murderer[2], Globals::Esp::Colors::Murderer[3]);
                        }
                        else if (Gun.Address)
                        {
                            s.role = "Sheriff";
                            s.teamColor = ImColor(Globals::Esp::Colors::Sheriff[0], Globals::Esp::Colors::Sheriff[1], Globals::Esp::Colors::Sheriff[2], Globals::Esp::Colors::Sheriff[3]);
                        }
                    }

                    if (std::to_string(Globals::GameID) == "3747388906")
                    {
                        for (SDK::Instance Weapon : Player.CharacterObject.Children())
                        {
                            if (Weapon.Class() != "Model")
                                continue;
                            std::string Name = Weapon.Name();

                            if (Name.find("Armor") == std::string::npos && Name != "Hair" && Name != "HolsterModel")
                            {
                                s.weapon = Name;
                            }
                        }
                    }
                }
            }

            lockT1 = std::chrono::steady_clock::now();
            {
                std::lock_guard<std::mutex> g(SDK::Cache::PlayersMutex);
                for (auto& s : snaps)
                {
                    if (s.index >= SDK::Cache::Players.size()) continue;
                    auto& Player = SDK::Cache::Players[s.index];
                    Player.Health = s.health;
                    Player.MaxHealth = s.maxHealth;
                    Player.Weapon = s.weapon;
                    Player.Role = s.role;
                    Player.TeamColor = s.teamColor;
                }
            }
            {
                auto now9 = std::chrono::steady_clock::now();
                auto waitMs = std::chrono::duration_cast<std::chrono::milliseconds>(lockT1 - holdT1).count();
                auto holdMs = std::chrono::duration_cast<std::chrono::milliseconds>(now9 - lockT1).count();
                static auto lastInfoLog = std::chrono::steady_clock::now();
                auto now6 = std::chrono::steady_clock::now();
                if (std::chrono::duration_cast<std::chrono::seconds>(now6 - lastInfoLog).count() >= 5)
                {
                    lastInfoLog = now6;
                    Logging::Log(Logging::LogType::INFO, ("[perf] PlayerInfoUpdate wait=" + std::to_string(waitMs) + "ms hold=" + std::to_string(holdMs) + "ms players=" + std::to_string(SDK::Cache::Players.size())).c_str());
                }
            }
        }
        catch (...)
        {
            Logging::Log(Logging::LogType::ERR, "Caught crash at cache info update");
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }
}
