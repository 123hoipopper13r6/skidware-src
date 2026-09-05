#pragma once
#include "../../Includes.hpp"
#include <vector>
#include <unordered_set>
#include <chrono>

namespace Hacks::Raycast
{
	struct Occluder
	{
		uintptr_t Primitive = 0;
		SDK::Vector3 Center{};
		SDK::Vector3 Size{};
		SDK::Matrix3 Rotation{};
	};

	void Setup();
	bool IsVisible(const SDK::Vector3& From, const SDK::Vector3& To, uintptr_t IgnoreA = 0, uintptr_t IgnoreB = 0);
	void TestSegment(const SDK::Vector3& From, const SDK::Vector3& To, std::vector<Occluder>& Out);

	inline bool ScanNeeded()
	{
		return Globals::Raycast::Enabled
			|| Globals::Aimbot::VisibleCheck
			|| Globals::TriggerBot::VisibleCheck;
	}
}