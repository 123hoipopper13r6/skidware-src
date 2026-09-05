#pragma once

// ================= MASTER SWITCH =================
// Comment this line out and rebuild to produce an inert client: the menu and
// attach still work, but NO cache/aimbot/misc threads are spawned, so no
// feature runs. Build-time only: when disabled, the spawn code is absent from
// the binary, so x64dbg/IDA cannot re-enable it at runtime.
#define SKIDWARE_MASTER_ENABLED

#include <mutex>
#include <clipper2/clipper.h>
#include "Security/Vms/VMProtectSDK.h"
#include "Roblox/Classes/Games.hpp"
#include "Security/Backend/Backend.h"
#include "Security/xorstr.hpp"
#include "Libs/Logging.h"
#include <Windows.h>
#include <iostream>
#include <d3d11.h>
#include "Libs/stb_image.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "ImGui/imgui.h"
#include <ImGui/imgui_internal.h>
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"
#include "CKeybind.hpp"
#include "Overlay/Overlay.hpp"
#include "Roblox/Classes/Materials.hpp"
#include "Roblox/Memory/Memory.hpp"
#include "Roblox/Offsets.hpp"
#include "Roblox/Classes/Math.hpp"
#include "Roblox/Classes/Color3.hpp"
#include "Roblox/Classes/Primitive.hpp"
#include "Roblox/Classes/Instance.hpp"
#include "Roblox/Classes/DataModel.hpp"
#include "Roblox/Classes/Team.hpp"
#include "Roblox/Classes/Player.hpp"
#include "Roblox/Classes/Players.hpp"
#include "Roblox/Classes/VisualEngine.hpp"
#include "Roblox/Classes/Humanoid.hpp"
#include "Roblox/Classes/Camera.hpp"

#include "Globals.hpp"
#include "Roblox/Cache/Cache.h"

#include "Roblox/Classes/MouseService.hpp"
#include <vector>
#include <thread>
#include <bit>
#include "ConfigManager.hpp"
#include "Roblox/FFlags.hpp"
#include "Roblox/SDK.hpp"
#include "Hacks/Esp/Esp.h"
#include "Hacks/Misc/Misc.h"
#include "Hacks/Aimbot/Aimbot.hpp"
#include "Hacks/Aimbot/RaycastHook.hpp"
#include "Hacks/Aimbot/ViewportSilent.hpp"
#include "Hacks/Raycast/Raycast.hpp"
#include "Hacks/Explorer/Explorer.h"
#include "GameSupport.hpp"
