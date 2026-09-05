#pragma once
#include "../../Includes.hpp"

namespace Hacks::RaycastHook
{
	bool Install();
	void Remove();
	void Ensure(bool want = true);

	void SetActive(bool on, const SDK::Vector3& world_target = {}, bool wallbang = false);

	bool Ready();
	bool Aiming();
	bool WallbangMode();
	uintptr_t OriginalHandler();
}