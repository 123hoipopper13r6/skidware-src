#pragma once
#include "../../Includes.hpp"
namespace SDK::Cache
{
	void PlayerCache();
	void PlayerInfoUpdate();
	struct CachedConvexHull
	{
		std::vector<ImVec2> Hull;
	};
	struct WayPoint
	{
		std::string Name;
		//SDK::Instance Instance;
		ImVec2 ScreenPosition;
		SDK::Vector3 WorldPosition;
	};
	struct Item
	{
		std::string Name;
		uintptr_t Address;
		SDK::Vector3 WorldPosition;
		ImVec2 ScreenPosition;
	};
	struct Flag
	{
		ImColor Color;
		std::string Flag;
	};
	struct Bone {
		std::string Name;
		SDK::Instance Object;
		SDK::Vector3 WorldPosition;
		SDK::Vector2 ScreenPosition;
		SDK::Vector3 Size;
		SDK::Matrix3 Rotation;
		CachedConvexHull Hull;
		bool CacheSize = true;

	};
	struct BoneConnection
	{
		ImVec2 Bone1;
		ImVec2 Bone2;
	};
	struct Player
	{
		std::string PlayerName;
		std::string DisplayName;
		float Health;
		float MaxHealth;
		std::vector<SDK::Cache::Bone> Bones;
		SDK::Cache::Bone Head;
		SDK::Cache::Bone HumanoidRootPart;
		SDK::Cache::Bone LeftArm;
		SDK::Cache::Bone RightArm;
		SDK::Cache::Bone LeftLeg;
		SDK::Cache::Bone RightLeg;
		SDK::Instance CharacterObject;
		SDK::Player PlayerObject;
		uintptr_t PlayerObjectAddress;
		uintptr_t CharacterObjectAddress;
		SDK::Humanoid Humanoid;
		int RigType;
		int Distance;
		ImVec2 BoxMin;
		ImVec2 BoxMax;
		std::string Weapon;
		std::string Role;
		ImColor TeamColor;
		std::vector<SDK::Cache::Flag> Flags;
		uintptr_t Team;
		Clipper2Lib::PathsD HighlightSolution;
	};
	void RecomputeHulls(Player& player);
	inline std::vector<SDK::Cache::Player> Players;
	inline SDK::Cache::Player LocalPlayer;
	inline std::vector<SDK::Cache::WayPoint> Waypoints;
	struct PlayerAvatar {
		ID3D11ShaderResourceView* Texture;
		std::string PlayerName;
	};
	inline std::mutex PlayersMutex;
	inline std::mutex LoadedAvatarsMutex;
	inline std::vector<PlayerAvatar> LoadedAvatars;
	inline std::vector<SDK::Cache::Item> Items;
	inline std::mutex ItemsMutex;
}