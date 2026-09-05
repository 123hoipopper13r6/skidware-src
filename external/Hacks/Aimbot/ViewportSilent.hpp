#pragma once
#include "../../Includes.hpp"

namespace Hacks::ViewportSilent
{
	void SetActive(bool on, const SDK::Vector3& world_target = {});
	void Restore();
	void Shutdown();
	bool Aiming();
}