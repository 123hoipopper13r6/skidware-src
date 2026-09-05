#define NOMINMAX
#include "Aimbot.hpp"
#include "../../Includes.hpp"
#include "hitsounds.h"
struct AimbotPlayer
{
	SDK::Cache::Player Player;
	SDK::Cache::Bone BodyPart;
};

AimbotPlayer SavedPlayer;

AimbotPlayer GetClosest()
{
	try
	{
		POINT cursor_point;
		if (!GetCursorPos(&cursor_point) || !Globals::RobloxWindow)
			return {};

		if (!ScreenToClient(Globals::RobloxWindow, &cursor_point))
			return {};

		SDK::Vector2 cursor = {
			static_cast<float>(cursor_point.x),
			static_cast<float>(cursor_point.y)
		};

		float min_dist = 9e9;
		AimbotPlayer Target;

		Target.BodyPart = SDK::Cache::LocalPlayer.HumanoidRootPart;
		SDK::Cache::PlayersMutex.lock();
		for (SDK::Cache::Player& Player : SDK::Cache::Players)
		{
			if (!Player.PlayerObjectAddress || !Player.HumanoidRootPart.Object.Address)
				continue;

			if (Player.PlayerObject.Address == SDK::Cache::LocalPlayer.PlayerObject.Address)
				continue;

			if (Globals::Misc::TeamCheck && Player.Team && Player.Team == SDK::Cache::LocalPlayer.Team)
				continue;

			float Health = 0;
			try {
				Health = Player.Health;
			}
			catch (...) {
				continue;
			}

			if (Health <= 0)
				continue;

			if (Globals::Aimbot::Hitbox == 0 && !Player.Head.Object.Address)
				continue;
			if (Globals::Aimbot::Hitbox == 1 && !Player.HumanoidRootPart.Object.Address)
				continue;

			if (Globals::Aimbot::Hitbox >= 2 && Globals::Aimbot::Hitbox <= 6)
			{
				SDK::Cache::Bone parts[] = { Player.Head, Player.HumanoidRootPart, Player.LeftArm, Player.RightArm, Player.LeftLeg, Player.RightLeg };
				bool anyValid = false;
				for (auto& p : parts) { if (p.Object.Address) { anyValid = true; break; } }
				if (!anyValid) continue;
			}

			if (Globals::Aimbot::Hitbox == 7)
			{
				bool anyValid = false;
				for (auto& b : Player.Bones) { if (b.Object.Address) { anyValid = true; break; } }
				if (!anyValid) continue;
			}

			SDK::Cache::Bone bestPart;
			float bestPartDist = 9e9;

			auto checkPart = [&](SDK::Cache::Bone& part) {
				if (!part.Object.Address) return;
				if (part.ScreenPosition.x == -1 || part.ScreenPosition.y == -1) return;
				float d = part.ScreenPosition.distance(cursor);
				if (std::isnan(d) || std::isinf(d)) return;
				if (d < bestPartDist) { bestPartDist = d; bestPart = part; }
			};

			if (Globals::Aimbot::Hitbox == 0)
				bestPart = Player.Head;
			else if (Globals::Aimbot::Hitbox == 1)
				bestPart = Player.HumanoidRootPart;
			else if (Globals::Aimbot::Hitbox == 2)
			{
				checkPart(Player.Head);
				checkPart(Player.HumanoidRootPart);
				checkPart(Player.LeftArm);
				checkPart(Player.RightArm);
				checkPart(Player.LeftLeg);
				checkPart(Player.RightLeg);
			}
			else if (Globals::Aimbot::Hitbox == 3)
				bestPart = Player.LeftArm;
			else if (Globals::Aimbot::Hitbox == 4)
				bestPart = Player.RightArm;
			else if (Globals::Aimbot::Hitbox == 5)
				bestPart = Player.LeftLeg;
			else if (Globals::Aimbot::Hitbox == 6)
				bestPart = Player.RightLeg;
			else if (Globals::Aimbot::Hitbox == 7)
			{
				for (auto& b : Player.Bones)
					checkPart(b);
			}

			if (!bestPart.Object.Address) continue;

			float ScreenDist;
			if (Globals::Aimbot::Hitbox == 2 || Globals::Aimbot::Hitbox == 7)
			{
				ScreenDist = bestPartDist;
			}
			else
			{
				if (bestPart.ScreenPosition.x == -1 || bestPart.ScreenPosition.y == -1) continue;
				ScreenDist = bestPart.ScreenPosition.distance(cursor);
				if (std::isnan(ScreenDist) || std::isinf(ScreenDist)) continue;
			}

			if (Globals::Aimbot::EnableFOV && ScreenDist > Globals::Aimbot::FOV)
				continue;

			float Score = 0.0f;
			switch (Globals::Aimbot::TargetPriority)
			{
			case 0: Score = ScreenDist; break;
			case 1: Score = (float)Player.Distance; break;
			case 2: Score = Player.Health; break;
			case 3: Score = -Player.Health; break;
			default: Score = ScreenDist; break;
			}

			if (Score < min_dist)
			{
				min_dist = Score;
				Target.BodyPart = bestPart;
				Target.Player = Player;
			}
		}
		SDK::Cache::PlayersMutex.unlock();
		if (!Target.BodyPart.Object.Address || Target.BodyPart.Object.Address == SDK::Cache::LocalPlayer.HumanoidRootPart.Object.Address)
		{
			SavedPlayer.Player.PlayerObject.Address = 0;
			return {};
		}

		return Target;
	}
	catch (...)
	{
		SavedPlayer.Player.PlayerObject.Address = 0;
		return {};
	}
}

namespace MatrixUtils
{
	static SDK::Vector3 normalize(const SDK::Vector3& vec) {
		try {
			float length = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
			if (length > 0.0001f && !std::isnan(length) && !std::isinf(length)) {
				return { vec.x / length, vec.y / length, vec.z / length };
			}
		}
		catch (...) {}
		return { 0, 0, 1 };
	}

	static SDK::Vector3 crossProduct(const SDK::Vector3& vec1, const SDK::Vector3& vec2) {
		try {
			SDK::Vector3 result = {
				vec1.y * vec2.z - vec1.z * vec2.y,
				vec1.z * vec2.x - vec1.x * vec2.z,
				vec1.x * vec2.y - vec1.y * vec2.x
			};

			if (std::isnan(result.x) || std::isnan(result.y) || std::isnan(result.z) ||
				std::isinf(result.x) || std::isinf(result.y) || std::isinf(result.z)) {
				return { 0, 1, 0 };
			}

			return result;
		}
		catch (...) {
			return { 0, 1, 0 };
		}
	}

	static SDK::Matrix3 lerp_rmatrix3(const SDK::Matrix3& a, const SDK::Matrix3& b, float t)
	{
		try {
			SDK::Matrix3 result{};
			t = std::max(0.0f, std::min(1.0f, t));

			for (int i = 0; i < 9; ++i) {
				float lerped = a.data[i] + (b.data[i] - a.data[i]) * t;
				if (std::isnan(lerped) || std::isinf(lerped)) {
					result.data[i] = a.data[i];
				}
				else {
					result.data[i] = lerped;
				}
			}
			return result;
		}
		catch (...) {
			return a;
		}
	}

	static SDK::Matrix3 LookAt(const SDK::Vector3& cameraPosition, const SDK::Vector3& targetPosition) {
		try {
			SDK::Vector3 direction = {
				targetPosition.x - cameraPosition.x,
				targetPosition.y - cameraPosition.y,
				targetPosition.z - cameraPosition.z
			};

			if (std::isnan(direction.x) || std::isnan(direction.y) || std::isnan(direction.z) ||
				std::isinf(direction.x) || std::isinf(direction.y) || std::isinf(direction.z)) {
				return SDK::Matrix3{};
			}

			SDK::Vector3 forward = normalize(direction);
			SDK::Vector3 right = normalize(crossProduct({ 0, 1, 0 }, forward));
			SDK::Vector3 up = crossProduct(forward, right);

			SDK::Matrix3 lookAtMatrix{};
			lookAtMatrix.data[0] = -right.x;   lookAtMatrix.data[1] = up.x;   lookAtMatrix.data[2] = -forward.x;
			lookAtMatrix.data[3] = right.y;    lookAtMatrix.data[4] = up.y;   lookAtMatrix.data[5] = -forward.y;
			lookAtMatrix.data[6] = -right.z;   lookAtMatrix.data[7] = up.z;   lookAtMatrix.data[8] = -forward.z;

			for (int i = 0; i < 9; i++) {
				if (std::isnan(lookAtMatrix.data[i]) || std::isinf(lookAtMatrix.data[i])) {
					return SDK::Matrix3{};
				}
			}

			return lookAtMatrix;
		}
		catch (...) {
			return SDK::Matrix3{};
		}
	}
}
bool IsMouseInBox(ImVec2 mousePos, ImVec2 boxMin, ImVec2 boxMax) {
	return (mousePos.x >= boxMin.x && mousePos.x <= boxMax.x &&
		mousePos.y >= boxMin.y && mousePos.y <= boxMax.y);
}
void TriggerBot()
{
	bool wasTargeting = false;
	while (true)
	{
		Globals::TriggerBot::Key.update();
		if (!Globals::RobloxFocused())
		{
			wasTargeting = false;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			continue;
		}
		if (Globals::TriggerBot::Enabled && Globals::TriggerBot::Key.enabled)
		{
			if (Globals::TriggerBot::ToolCheck && SDK::Cache::LocalPlayer.Weapon.empty()) {
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
				continue;
			}
			POINT cursor_point;
			GetCursorPos(&cursor_point);
			ScreenToClient(Globals::RobloxWindow, &cursor_point);
			ImVec2 MousePos = {
					static_cast<float>(cursor_point.x),
					static_cast<float>(cursor_point.y)
			};

bool isTargeting = false;
			SDK::Vector3 partPos{};
			uintptr_t ignoreA = 0, ignoreB = 0;
			SDK::Cache::PlayersMutex.lock();
			for (const auto& Player : SDK::Cache::Players)
			{
				if (!Player.PlayerObjectAddress || Player.Health <= 0)
					continue;
				if (Player.PlayerObject.Address == SDK::Cache::LocalPlayer.PlayerObject.Address)
					continue;
				if (Player.BoxMin.x == 0 && Player.BoxMin.y == 0 && Player.BoxMax.x == 0 && Player.BoxMax.y == 0)
					continue;

				if (IsMouseInBox(MousePos, Player.BoxMin, Player.BoxMax))
				{
					if (Globals::TriggerBot::VisibleCheck)
					{
						try
						{
							partPos = Player.Head.WorldPosition;
							ignoreA = SDK::Cache::LocalPlayer.HumanoidRootPart.Object.Primitive().Address;
							ignoreB = Player.Head.Object.Address;
						}
						catch (...)
						{
							continue;
						}
					}
					isTargeting = true;
					break;
				}
			}
			SDK::Cache::PlayersMutex.unlock();
			if (isTargeting && Globals::TriggerBot::VisibleCheck)
			{
				try
				{
					SDK::Camera Camera = (SDK::Camera)Globals::Workspace.FindFirstChildOfClass("Camera");
					SDK::Vector3 camPos = Camera.CameraPosition();
					if (!Hacks::Raycast::IsVisible(camPos, partPos, ignoreA, ignoreB))
						isTargeting = false;
				}
				catch (...)
				{
					isTargeting = false;
				}
			}
			if (isTargeting && !wasTargeting)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(Globals::TriggerBot::Delay));
				INPUT inputs[2] = {};
				inputs[0].type = INPUT_MOUSE;
				inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
				inputs[1].type = INPUT_MOUSE;
				inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
				SendInput(2, inputs, sizeof(INPUT));
			}

			wasTargeting = isTargeting;
			std::this_thread::sleep_for(std::chrono::milliseconds(Globals::TriggerBot::Threshold + 1));
		}
		else
		{
			wasTargeting = false;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
}
void RageBot()
{
	bool wasFiring = false;
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		if (!Globals::RobloxFocused())
		{
			wasFiring = false;
			continue;
		}
		if (!Globals::Aimbot::Enabled || !Globals::Raycast::Enabled)
		{
			wasFiring = false;
			continue;
		}
		if (!Globals::Aimbot::Rage::RageBot)
		{
			wasFiring = false;
			continue;
		}

		AimbotPlayer target = GetClosest();
		if (!target.BodyPart.Object.Address)
		{
			wasFiring = false;
			continue;
		}

		SDK::Vector3 partPos;
		try {
			partPos = target.BodyPart.Object.Primitive().Position();
		}
		catch (...) {
			wasFiring = false;
			continue;
		}

		SDK::Instance CameraInstance = Globals::Workspace.FindFirstChildOfClass("Camera");
		if (!CameraInstance.Address)
		{
			wasFiring = false;
			continue;
		}
		SDK::Camera Camera = (SDK::Camera)CameraInstance;

		SDK::Vector3 camPos;
		try {
			camPos = Camera.CameraPosition();
		}
		catch (...) {
			wasFiring = false;
			continue;
		}

		bool visible = false;
		try {
			uintptr_t ignoreA = SDK::Cache::LocalPlayer.HumanoidRootPart.Object.Primitive().Address;
			uintptr_t ignoreB = target.BodyPart.Object.Primitive().Address;
			visible = Hacks::Raycast::IsVisible(camPos, partPos, ignoreA, ignoreB);
		}
		catch (...) {
			wasFiring = false;
			continue;
		}

		// Memory aim: snap the camera to the target when the target is visible
		if (Globals::Aimbot::Rage::RageBotMode == 0 && visible)
		{
			SDK::Matrix3 Matrix = MatrixUtils::LookAt(camPos, partPos);
			try {
				Camera.SetCameraRotation(Matrix);
			}
			catch (...) {}
		}

		// Silent aim: aim the mouse at the target when visible
		SDK::Vector2 Bot2D = SDK::WorldToScreen(partPos);
		if (Bot2D.x != -1 && Bot2D.y != -1 && Globals::Aimbot::Rage::RageBotMode == 1 && visible)
		{
			POINT cursor_point;
			GetCursorPos(&cursor_point);
			ScreenToClient(Globals::RobloxWindow, &cursor_point);
			Globals::MouseService.SilentAim(Bot2D, { static_cast<float>(cursor_point.x), static_cast<float>(cursor_point.y) });
		}

		// Auto-fire when the target is visible
		if (visible && !wasFiring)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds((std::max)(0, Globals::TriggerBot::Delay)));
			INPUT inputs[2] = {};
			inputs[0].type = INPUT_MOUSE;
			inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
			inputs[1].type = INPUT_MOUSE;
			inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
			SendInput(2, inputs, sizeof(INPUT));
		}
		wasFiring = visible;
	}
}

void HitSounds()
{
	auto lastClickTime = std::chrono::steady_clock::now();
	std::string lastTargetName = "";
	float lastTargetHealth = -1.0f;

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			lastClickTime = std::chrono::steady_clock::now();

		bool clickedRecently = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - lastClickTime).count() < 100;
		if (!clickedRecently)
			continue;

		if (!Globals::Aimbot::Target::HaveTarget)
		{
			lastTargetName = "";
			lastTargetHealth = -1.0f;
			continue;
		}

		std::string currentTarget = Globals::Aimbot::Target::Name;
		float currentHealth = Globals::Aimbot::Target::Health;

		if (currentTarget != lastTargetName)
		{
			lastTargetName = currentTarget;
			lastTargetHealth = currentHealth;
			continue;
		}

		if (lastTargetHealth < 0.0f)
		{
			lastTargetHealth = currentHealth;
			continue;
		}

		if (currentHealth < lastTargetHealth && (lastTargetHealth - currentHealth) > 5.0f)
		{
			if (Globals::Aimbot::Hits::HitTracers || Globals::Aimbot::Hits::HitMarkers)
			{
				SDK::Cache::PlayersMutex.lock();
				for (auto& player : SDK::Cache::Players)
				{
					if (player.PlayerName == currentTarget && player.CharacterObjectAddress)
					{
						Hacks::Esp::HitMarker3D pos1 = { SDK::Cache::LocalPlayer.Head.WorldPosition.x, SDK::Cache::LocalPlayer.Head.WorldPosition.y, SDK::Cache::LocalPlayer.Head.WorldPosition.z };
						Hacks::Esp::HitMarker3D pos2 = { player.Head.WorldPosition.x, player.Head.WorldPosition.y, player.Head.WorldPosition.z };
						Hacks::Esp::InsertHitMarker(pos1, pos2);
						break;
					}
				}
				SDK::Cache::PlayersMutex.unlock();
			}
			if (Globals::Aimbot::Hits::HitSounds)
			{
				int s = Globals::Aimbot::Hits::HitSound;
				if (s == 0) PlaySoundA(reinterpret_cast<char*>(amongus), NULL, SND_ASYNC | SND_MEMORY);
				else if (s == 1) PlaySoundA(reinterpret_cast<char*>(skeet_sound), NULL, SND_ASYNC | SND_MEMORY);
				else if (s == 2) PlaySoundA(reinterpret_cast<char*>(beep), NULL, SND_ASYNC | SND_MEMORY);
				else if (s == 3) PlaySoundA(reinterpret_cast<char*>(bonk), NULL, SND_ASYNC | SND_MEMORY);
				else if (s == 4) PlaySoundA(reinterpret_cast<char*>(bubble), NULL, SND_ASYNC | SND_MEMORY);
				else if (s == 5) PlaySoundA(reinterpret_cast<char*>(cod), NULL, SND_ASYNC | SND_MEMORY);
				else if (s == 6) PlaySoundA(reinterpret_cast<char*>(csgo), NULL, SND_ASYNC | SND_MEMORY);
				else if (s == 7) PlaySoundA(reinterpret_cast<char*>(fairy), NULL, SND_ASYNC | SND_MEMORY);
				else if (s == 8) PlaySoundA(reinterpret_cast<char*>(fatality), NULL, SND_ASYNC | SND_MEMORY);
				else if (s == 9) PlaySoundA(reinterpret_cast<char*>(osu), NULL, SND_ASYNC | SND_MEMORY);
				else if (s == 10) PlaySoundA(reinterpret_cast<char*>(rust), NULL, SND_ASYNC | SND_MEMORY);
				else if (s == 11) PlaySoundA(reinterpret_cast<char*>(bameware), NULL, SND_ASYNC | SND_MEMORY);
			}
		}

		lastTargetHealth = currentHealth;
	}
}
void Hacks::Aimbot::Setup()
{
	std::thread(TriggerBot).detach();
	std::thread(HitSounds).detach();
	std::thread(RageBot).detach();
	int retargetCounter = 0;
	while (true)
	{
		Globals::Aimbot::AimbotKey.update();

		if (!Globals::RobloxFocused())
		{
			retargetCounter = 0;
			SavedPlayer.Player.PlayerObject.Address = 0;
			Globals::Aimbot::IsThereATarget = false;
			Globals::Aimbot::Target::HaveTarget = false;
			Hacks::RaycastHook::Ensure(false);
			Hacks::RaycastHook::SetActive(false);
			Hacks::ViewportSilent::SetActive(false);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			continue;
		}

		if (Globals::Aimbot::Enabled && Globals::Aimbot::AimbotKey.enabled)
		{
			POINT cursor_point;
			GetCursorPos(&cursor_point);
			ScreenToClient(Globals::RobloxWindow, &cursor_point);

			// Re-acquire closest target every ~200ms to switch when a closer target appears
			if (++retargetCounter >= 40)
			{
				retargetCounter = 0;
				if (Globals::Aimbot::StickyTarget && SavedPlayer.BodyPart.Object.Address)
				{
					bool targetStillValid = false;
					SDK::Cache::PlayersMutex.lock();
					for (auto& p : SDK::Cache::Players)
					{
						if (p.PlayerObjectAddress == SavedPlayer.Player.PlayerObjectAddress && p.Health > 0 && p.HumanoidRootPart.Object.Address)
						{
							targetStillValid = true;
							SavedPlayer.Player = p;
							if (Globals::Aimbot::Hitbox == 0 && p.Head.Object.Address)
								SavedPlayer.BodyPart = p.Head;
							else if (Globals::Aimbot::Hitbox == 1)
								SavedPlayer.BodyPart = p.HumanoidRootPart;
							else if (Globals::Aimbot::Hitbox == 3 && p.LeftArm.Object.Address)
								SavedPlayer.BodyPart = p.LeftArm;
							else if (Globals::Aimbot::Hitbox == 4 && p.RightArm.Object.Address)
								SavedPlayer.BodyPart = p.RightArm;
							else if (Globals::Aimbot::Hitbox == 5 && p.LeftLeg.Object.Address)
								SavedPlayer.BodyPart = p.LeftLeg;
							else if (Globals::Aimbot::Hitbox == 6 && p.RightLeg.Object.Address)
								SavedPlayer.BodyPart = p.RightLeg;
							break;
						}
					}
					SDK::Cache::PlayersMutex.unlock();
					if (!targetStillValid)
						SavedPlayer = GetClosest();
				}
				else
				{
					SavedPlayer = GetClosest();
				}
			}
			else if (SavedPlayer.Player.PlayerObject.Address == 0 || !SavedPlayer.BodyPart.Object.Address)
			{
				SavedPlayer = GetClosest();
			}

			if (!SavedPlayer.BodyPart.Object.Address) {
				Globals::Aimbot::Target::HaveTarget = false;
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
				continue;
			}

			if (!Globals::Workspace.Address) {
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				continue;
			}

			SDK::Instance CameraInstance = Globals::Workspace.FindFirstChildOfClass("Camera");
			if (!CameraInstance.Address) {
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				continue;
			}

			SDK::Camera Camera = (SDK::Camera)CameraInstance;

			SDK::Vector3 PartPosition;
			try {
				PartPosition = SavedPlayer.BodyPart.Object.Primitive().Position();
			}
			catch (...) {
				SavedPlayer.Player.PlayerObject.Address = 0;
				Globals::Aimbot::Target::HaveTarget = false;
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
				continue;
			}
			Globals::Aimbot::Target::HaveTarget = true;
			Globals::Aimbot::Target::Name = SavedPlayer.Player.PlayerName;
			Globals::Aimbot::Target::DisplayName = SavedPlayer.Player.DisplayName;
			Globals::Aimbot::Target::Tool = SavedPlayer.Player.Weapon;
			Globals::Aimbot::Target::Distance = std::to_string(SavedPlayer.Player.Distance) + "m";
			Globals::Aimbot::Target::Health = SavedPlayer.Player.Health;
			Globals::Aimbot::Target::MaxHealth = SavedPlayer.Player.MaxHealth;


			if (Globals::Aimbot::Prediction)
			{
				SDK::Vector3 Velocity = SavedPlayer.BodyPart.Object.Primitive().Velocity();
				Velocity = SDK::Vector3(Velocity.x / (15.0f - Globals::Aimbot::PredictionX), Velocity.y / (15.0f - Globals::Aimbot::PredictionY),0);
				PartPosition = PartPosition + Velocity;
			}
			SDK::Vector2 PartPosition2D = SDK::WorldToScreen(PartPosition);
			if (PartPosition2D.x == -1 || PartPosition2D.y == -1)
			{
				SavedPlayer.Player.PlayerObject.Address = 0;
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
				continue;
			}

			if (SavedPlayer.BodyPart.Object.Address == SDK::Cache::LocalPlayer.HumanoidRootPart.Object.Address) {
				SavedPlayer.Player.PlayerObject.Address = 0;
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
				continue;
			}
			SDK::Vector2 relative = { 0, 0 };
			relative.x = (PartPosition2D.x - cursor_point.x) * 0.1f / 0.1f;
			relative.y = (PartPosition2D.y - cursor_point.y) * 0.1f / 0.1f;
			if (Globals::Aimbot::Smoothning)
			{

				relative.x = (PartPosition2D.x - cursor_point.x) * 0.1f / (Globals::Aimbot::SmoothingValue);
				relative.y = (PartPosition2D.y - cursor_point.y) * 0.1f / (Globals::Aimbot::SmoothingValue);
			}

			if (Globals::Aimbot::VisibleCheck && !(Globals::Aimbot::AimType == 2 && (Globals::Aimbot::SilentMode == 2 || Globals::Aimbot::SilentMode == 3)) && !Globals::Aimbot::Rage::MagicBullet)
			{
				SDK::Vector3 camPos;
				try {
					camPos = Camera.CameraPosition();
				}
				catch (...) {
					std::this_thread::sleep_for(std::chrono::milliseconds(50));
					continue;
				}
				uintptr_t ignoreA = SDK::Cache::LocalPlayer.HumanoidRootPart.Object.Primitive().Address;
				uintptr_t ignoreB = SavedPlayer.BodyPart.Object.Primitive().Address;
				if (!Hacks::Raycast::IsVisible(camPos, PartPosition, ignoreA, ignoreB))
				{
					SavedPlayer.Player.PlayerObject.Address = 0;
					std::this_thread::sleep_for(std::chrono::milliseconds(50));
					continue;
				}
			}

			if (Globals::Aimbot::AimType == 0)
			{
				if (relative.x != -1 && relative.y != -1) {
					if (Globals::Aimbot::Humanize)
					{
						float str = Globals::Aimbot::HumanizeStrength;
						float jx = ((float)(rand() % 1000) / 1000.0f - 0.5f) * 2.0f * str;
						float jy = ((float)(rand() % 1000) / 1000.0f - 0.5f) * 2.0f * str;
						relative.x += jx;
						relative.y += jy;
					}
					INPUT input{};
					input.mi.time = 0;
					input.type = INPUT_MOUSE;
					input.mi.mouseData = 0;
					input.mi.dx = relative.x;
					input.mi.dy = relative.y;
					input.mi.dwFlags = MOUSEEVENTF_MOVE;
					SendInput(1, &input, sizeof(input));
					std::this_thread::sleep_for(std::chrono::milliseconds(2));
				}
			}
			if (Globals::Aimbot::AimType == 1)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(2));
				SDK::Matrix3 CameraRotation;
				SDK::Vector3 CameraPosition;

				try {
					CameraRotation = Camera.CameraRotation();
					CameraPosition = Camera.CameraPosition();
				}
				catch (...) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
					continue;
				}

				if (Globals::Aimbot::Humanize)
				{
					float str = Globals::Aimbot::HumanizeStrength;
					PartPosition.x += ((float)(rand() % 1000) / 1000.0f - 0.5f) * 2.0f * str;
					PartPosition.y += ((float)(rand() % 1000) / 1000.0f - 0.5f) * 2.0f * str;
					PartPosition.z += ((float)(rand() % 1000) / 1000.0f - 0.5f) * 2.0f * str;
				}

				SDK::Matrix3 Matrix = MatrixUtils::LookAt(CameraPosition, PartPosition);
				float lerpFactor = 1.0f;
				if (Globals::Aimbot::Smoothning) {
					lerpFactor = 1.0f - Globals::Aimbot::SmoothingValue;
					Matrix = MatrixUtils::lerp_rmatrix3(CameraRotation, Matrix, lerpFactor);
				}

				try {
					Camera.SetCameraRotation(Matrix);
				}
				catch (...) {
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
					continue;
				}

			}
			if (Globals::Aimbot::AimType == 2)
			{
				Globals::Aimbot::IsThereATarget = true;
				Globals::Aimbot::SilentMousePosition = PartPosition2D;

				const bool viewportMode = Globals::Aimbot::SilentMode == 0;
				const bool hookMode = Globals::Aimbot::SilentMode == 2 || Globals::Aimbot::SilentMode == 3;
				const bool forcedWallbang = Globals::Aimbot::SilentMode == 3 || Globals::Aimbot::Rage::MagicBullet;

				Hacks::RaycastHook::Ensure(hookMode);
				if (!viewportMode)
					Hacks::ViewportSilent::SetActive(false);

				if (viewportMode)
				{
					Hacks::ViewportSilent::SetActive(true, PartPosition);
				}
				else if (hookMode)
				{
					static auto firstFail = std::chrono::steady_clock::time_point{};
					static bool warned = false;
					if (Hacks::RaycastHook::Ready())
						Hacks::RaycastHook::SetActive(true, PartPosition, forcedWallbang);
					else
					{
						Hacks::RaycastHook::SetActive(false);
						if (firstFail.time_since_epoch().count() == 0)
							firstFail = std::chrono::steady_clock::now();
						else if (!warned &&
							std::chrono::steady_clock::now() - firstFail > std::chrono::seconds(3))
						{
							warned = true;
							Logging::Log(Logging::LogType::ERR, "[Aimbot] RaycastHook persistently unavailable - Raycast/MagicBullet silent aim disabled (WorldRoot offset may be stale)");
						}
					}
				}
				else
				{
					if (Globals::Aimbot::SilentMode == 1)
					{
						Globals::MouseService.SilentAim(
							PartPosition2D,
							{
							static_cast<float>(cursor_point.x),
							static_cast<float>(cursor_point.y)
							}
						);
					}
					// SilentMode == 4 (Phantom) is reserved / not implemented: no-op
				}
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}
		else
		{
			retargetCounter = 0;
			SavedPlayer.Player.PlayerObject.Address = 0;
			Globals::Aimbot::IsThereATarget = false;
			Globals::Aimbot::Target::HaveTarget = false;
			Hacks::RaycastHook::Ensure(false);
			Hacks::RaycastHook::SetActive(false);
			Hacks::ViewportSilent::SetActive(false);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
}
