#pragma once
#include "Includes.hpp"
#include "Roblox/Classes/MouseService.hpp"
#include <mutex>
#include <chrono>

inline float SteadyNow()
{
	return (float)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() / 1000.0f;
}

struct NotificationQueue
{
	std::vector<std::pair<std::string, float>> items;
	std::mutex mtx;
};

inline NotificationQueue& GetNotificationQueue()
{
	static NotificationQueue q;
	return q;
}

inline void PushNotification(const std::string& msg)
{
	auto& q = GetNotificationQueue();
	std::lock_guard<std::mutex> lock(q.mtx);
	q.items.push_back({ msg, SteadyNow() });
}

namespace Globals
{
	inline SDK::DataModel DataModel;
	inline SDK::VisualEngine VisualEngine;
	inline SDK::Player LocalPlayer;
	inline SDK::Players Players;
	inline SDK::Instance Workspace;
	inline SDK::Instance Lighting;
	inline SDK::MouseService MouseService;
	inline HWND RobloxWindow;
	inline uintptr_t GameID;
	inline bool Watermark;
	inline bool ShowDebugLog = false;
	inline bool ShowMetrics = false;
	inline bool Notifications = true;

	inline bool RobloxFocused()
	{
		return RobloxWindow && GetForegroundWindow() == RobloxWindow;
	}
	inline ID3D11Device* g_pd3dDevice = nullptr;
	inline ID3D11DeviceContext* g_pd3dDeviceContext = nullptr;
	namespace Auth
	{
		inline std::string Username = "0";
		inline std::string Password = "0";
		inline bool Authenticated = false;
		inline std::string Token;
		inline std::string Email;
		inline std::string HWID;
		inline std::string StatusMessage = "";
		inline bool LoginInProgress = false;
	}
	inline bool Vsync = false;
	namespace Esp
	{
		inline bool Enabled = false;
		inline bool Box = false;
		inline bool BoxGlow = false;
		inline bool Name = false;
		inline bool UseDisplayName = false;
		inline bool Distance = false;
		inline bool Tool = false;
		inline bool Chams = false;
		inline bool Avatar = false;
		inline int IconSize = 32;
		inline int OffsetOffBoxAvatar = 11;
		inline int ChamsType = 0;
		inline bool ChamsGlow = false;
		inline bool ChamsOutlines = false;
		inline bool HealthBar = false;
		inline bool HealthNumber = false;
		inline bool HealthBarBackGround = false;
		inline bool HealthBarGlow = false;
		inline int HealthBarColorType = 0;
		inline bool Team = false;
		inline int TeamMode = 0;
		inline bool Leaderstats = false;
		inline bool Region = false;
		inline bool LocalPlayerESP = false;
		inline int Font = 0;
		inline bool MaxDistance = false;
		inline int MaxDistanceValue = 1000;
		inline bool KeybindList = false;
		inline int ChamsOutlineThickness = 1.0f;
		inline bool InheritBodyColorChams = false;
		inline bool FilterUnknownChamsParts = false;
		inline bool Tracers = false;
		inline bool Skeleton = false;
		inline int TracersPosition = 0;
		inline int ChamsMaterial = 0;
		inline bool OffscreenArrows = false;
		inline float OffscreenArrowColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		inline float OffscreenArrowSize = 20.0f;
		inline float OffscreenArrowPadding = 50.0f;
		inline int OffscreenArrowMinDist = 5;
		inline int SkeletonThickness = 2;
		inline int TracerThickness = 2;
		inline int BoxThickness = 1;
		inline bool CornerBox = false;
		namespace Colors
		{
			inline float Skeleton[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float Tracers[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float Box[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float BoxGlow[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float Name[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float Distance[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float Tool[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float Chams[4] = { 1.0f,1.0f,1.0f,0.5f };
			inline float ChamsGlow[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float ChamsOutlines[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float HealthBarGlow[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float HealthBar[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float HealthNumber[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float Region[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float LeaderStats[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float Murderer[4] = { 1.0f,0.0f,0.0f,1.0f };
			inline float Sheriff[4] = { 0.0f,0.5f,1.0f,1.0f };
			inline float Innocent[4] = { 0.0f,1.0f,0.0f,1.0f };
			inline float DroppedGun[4] = { 0.0f,0.7f,1.0f,1.0f };
		}
		inline bool DroppedGun = false;
	}
	namespace Misc
	{
		inline bool RiskyFunctions = false;
		inline bool TeamCheck = false;
		inline bool StreamProof = false;

		inline bool Desync = false;
		inline CKeybind DesyncBind{ "Desync", CKeybind::TOGGLE };
		inline SDK::Vector3 DesyncedPostion(-1, -1, -1);

	}
	namespace Raycast
	{
		inline bool Enabled = false;
		inline int Method = 0;
		inline int Delay = 50;
		inline bool VisibleCheck = false;
		inline int AimMode = 0;
		inline bool Preview = false;
		inline bool PreviewVisible = false;
		inline float PreviewDistance = 0.0f;
		inline std::string PreviewTargetName = "";
	}
	namespace Aimbot
	{
		namespace Rage
		{
			inline bool SpamTP = false;
			inline bool Orbit = false;
			inline bool MagicBullet = false;
			inline bool RageBot = false;
			inline int RageBotMode = 0;
			namespace OrbitSettings {
				inline float radius = 1.0f;
				inline float orbitSpeed = 100.0f;
				inline float heightOffset = 10.0f;
			};
		}
		inline bool Enabled = false;
		inline bool VisibleCheck = false;
		inline CKeybind AimbotKey{ "Aimbot", CKeybind::HOLD, 0x00 };
		inline int Hitbox = 0;
		inline int AimType = 0;
		inline int SilentMode = 0;
		inline bool StickyTarget = false;
		inline int TargetPriority = 0;
		inline bool Humanize = false;
		inline float HumanizeStrength = 0.3f;
		inline bool Prediction = false;
		inline float PredictionX = 1;
		inline float PredictionY = 1;
		inline bool EnableFOV = false;
		inline bool DrawFOV = true;
		inline float FovColor[4] = { 1.0f,1.0f,1.0f,1.0f };
		namespace FovSettings
		{
			inline bool FillFov = false;
			inline float FillColor[4] = { 1.0f,1.0f,1.0f, 0.3f }; 
			
		}
		inline int FOV = 60;
		inline bool Smoothning = false;
		inline float SmoothingValue = 0.1f;
		namespace Target {
			inline bool HaveTarget = false;
			inline std::string Name = "";
			inline std::string DisplayName = "";
			inline std::string Tool = "";
			inline std::string Distance = "";
			inline int Health = 0;
			inline int MaxHealth = 100;
		}
		namespace Hits
		{
			inline bool HitSounds = false;
			inline int HitSound = 0;
			inline bool HitTracers = false;
			inline bool HitMarkers = false;
			inline float HitTracersColor[4] = { 1.0f,1.0f,1.0f,1.0f };
			inline float HitMarkersColor[4] = { 1.0f,1.0f,1.0f,1.0f };
		}
		inline SDK::Vector2 SilentMousePosition = { 0,0 };
		inline bool SilentCrosshair = false;
		inline bool SilentCrosshairTracer = false;
		inline float SilentCrosshairTracerColor[4] = { 1.0f,1.0f,1.0f,1.0f };
		inline bool IsThereATarget = false;
	}
	namespace TriggerBot
	{
		inline bool Enabled = false;
		inline bool VisibleCheck = false;
		inline CKeybind Key{ "TriggerBot" };
		inline int Delay = 0;
		inline int Threshold = 0;
		inline bool ToolCheck = false;
	}
	namespace Exploits
	{
		inline bool AnimationEnabled = false;
		inline int AnimationPack = 0;
		inline int AnimationIdle = 0;
		inline int AnimationRun = 0;
		inline int AnimationWalk = 0;
		inline int AnimationJump = 0;
		inline int AnimationFall = 0;
		inline int AnimationClimb = 0;
		inline int AnimationSwim = 0;
	}
	namespace World
	{
		inline float AmbientColor[3] = { 1.0f,1.0f,1.0f };
		inline float OutdoorAmbientColor[3] = { 1.0f,1.0f,1.0f };
		inline bool LocalPlayerForceField = false;
		namespace Waypoints
		{
			inline bool WaypointName = false;
			inline bool WaypointDistance = false;
			namespace Colors
			{
				inline float WaypointName[4] = { 1.0f,1.0f,1.0f,1.0f };
				inline float WaypointDistance[4] = { 1.0f,1.0f,1.0f,1.0f };
			}
		}
		inline bool CameraFOV = false;
		inline int CameraFOVValue = 90;
		inline bool Zoom = false;
		inline CKeybind ZoomKey{ "Zoom", CKeybind::TOGGLE };
		inline int ZoomValue = 30;
		inline bool TimeManipulation = false;
		inline float TimeManipulationValue = 240.0f;
		namespace Movement
		{
			inline bool InfiniteJump = false;
			namespace  InfiniteJumpNameSpace
			{
				inline bool CustomJumpPower = false;
				inline float CustomJumpPowerValue = 50.0f;
			}
			inline int FlyMethod = 0;
			inline bool Fly = false;
			inline CKeybind FlyKey{ "##Fly", CKeybind::TOGGLE };
			inline float FlySpeed = 1.0f;

			inline int SpeedMethod = 0;
			inline bool Speed = false;
			inline CKeybind SpeedKey{ "##Speed", CKeybind::TOGGLE };
			inline float SpeedValue = 1.0f;

			inline bool Noclip = false;
			inline CKeybind NoclipKey{ "##Noclip", CKeybind::TOGGLE };

			inline bool Freecam = false;
			inline CKeybind FreecamKey{ "##Freecam", CKeybind::TOGGLE };
			inline float FreecamSpeed = 0.01f;

			inline bool ThirdPerson = false;
			inline CKeybind ThirdPersonKey{ "ThirdPerson", CKeybind::TOGGLE };
			inline float ThirdPersonX = 0.0f;
			inline float ThirdPersonY = 3.0f;
			inline float ThirdPersonZ = 3.0f;

			inline bool Spinbot = false;
			inline CKeybind AntiAimKey{ "Anti-Aim", CKeybind::TOGGLE };
			inline int SpinbotSpeed = 5;
			inline bool UpsideDown = false;
			inline bool WalkSpeed = false;
			inline float WalkSpeedValue = 16.0f;
			inline int AntiAimPitch = 0;
			inline int AntiAimYaw = 0;
			inline bool Peek = false;
			inline CKeybind PeekKey{ "##Peek", CKeybind::TOGGLE };
			inline float PeekRadius = 5.0f;
			inline float PeekColor[4] = { 1.0f, 1.0f, 1.0f, 0.5f };
			inline bool PeekClickTP = false;
			inline bool PeekActive = false;
			inline SDK::Vector3 PeekPosition = { 0,0,0 };
		}
	}

	namespace Explorer
	{
		inline uintptr_t SelectedAddress = 0;
		inline std::string SelectedName = "";
		inline std::string SelectedClass = "";
		inline std::string SelectedPath = "";
		inline char SearchBuf[128] = "";
		inline bool TeleportRequest = false;
		inline uintptr_t TeleportAddress = 0;
		inline bool Paused = false;
		inline int ClassFilterIndex = 0;
		inline char ClassFilterBuf[128] = "";
		inline uintptr_t FocusAddress = 0;
		inline std::string FocusPath = "";
	}

	inline bool DockBar_Home = true;
	inline bool DockBar_Style = false;
	inline bool DockBar_EspPreview = false;
	inline bool DockBar_TargetHud = false;
	inline bool DockBar_Explorer = false;
	inline bool DockBar_Players = false;
	inline bool DockBar_Keybinds = false;
	inline bool DockBar_Anims = false;

	// Loader & misc
	inline bool LoaderAttached = false;
	inline HANDLE RobloxProcessHandle = NULL;
	inline bool ShowConsole = false;
	inline bool DebugMode = false;
}