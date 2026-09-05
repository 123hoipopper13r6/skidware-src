#include "Misc.h"
#include "../Animations/AnimationCatalog.hpp"
#include "../../Includes.hpp"
#include <unordered_map>
#include <functional>
#include <chrono>
#include <windows.h>
#define M_PI 3.14159265358979323846

static bool IsValidPtr(uintptr_t addr)
{
	MEMORY_BASIC_INFORMATION mbi;
	return VirtualQueryEx(SDK::Memory->Handle, (LPCVOID)addr, &mbi, sizeof(mbi)) &&
		mbi.State == MEM_COMMIT &&
		(mbi.Protect & (PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READWRITE));
}
SDK::Vector3 LookVector(const SDK::Matrix3& rotationMatrix) {
	return { rotationMatrix.data[2], rotationMatrix.data[2 + 3], rotationMatrix.data[2 + 6] };
}

SDK::Vector3 RightVector(const SDK::Matrix3& rotationMatrix) {
	return { rotationMatrix.data[0], rotationMatrix.data[0 + 3], rotationMatrix.data[0 + 6] };
}
// Flatten to horizontal (y=0) and renormalize for consistent speed regardless of camera tilt
static SDK::Vector3 FlattenDir(const SDK::Vector3& v) {
	if (v.x == 0 && v.z == 0) return { 0, 0, 0 };
	SDK::Vector3 flat = { v.x, 0, v.z };
	float mag = sqrtf(flat.x * flat.x + flat.z * flat.z);
	if (mag < 0.0001f) return { 0, 0, 0 };
	return { flat.x / mag, 0, flat.z / mag };
}

static SDK::Primitive FindTorsoPrim(SDK::Instance Character)
{
	if (!Character.Address) return {};
	SDK::Instance Torso = Character.FindFirstChild("Torso");
	if (Torso.Address) return Torso.Primitive();
	return {};
}

void FlyHack()
{
	/*
	static bool gravityZeroed = false;
	static float gravityBackup = 0.0f;

	auto getWorld = []() -> uintptr_t {
		uintptr_t ws = Globals::Workspace.Address;
		if (!ws)
			return 0;
		return SDK::Memory->Read<uintptr_t>(ws + SDK::Offsets::WorkspaceToWorld);
	};

	auto zeroGravity = [&](bool zero) {
		uintptr_t world = getWorld();
		if (!world)
			return;
		if (zero)
		{
			if (!gravityZeroed)
			{
				gravityBackup = SDK::Memory->Read<float>(world + SDK::Offsets::WorldGravity);
				gravityZeroed = true;
			}
			SDK::Memory->Write<float>(world + SDK::Offsets::WorldGravity, 0.0f);
		}
		else
		{
			if (gravityZeroed)
			{
				SDK::Memory->Write<float>(world + SDK::Offsets::WorldGravity, gravityBackup);
				gravityZeroed = false;
			}
		}
	};
	*/

	while (true)
	{
		Globals::World::Movement::FlyKey.update();
		if (Globals::Misc::RiskyFunctions && Globals::World::Movement::Fly && Globals::World::Movement::FlyKey.enabled)
		{
			SDK::Cache::Bone HRP;
			SDK::Humanoid Humanoid;
			{
				std::lock_guard<std::mutex> cacheLock(SDK::Cache::PlayersMutex);
				HRP = SDK::Cache::LocalPlayer.HumanoidRootPart;
				Humanoid = SDK::Cache::LocalPlayer.Humanoid;
			}
			if (!HRP.Object.Address || !Humanoid.Address || !IsValidPtr(Humanoid.Address))
				continue;

			// camera
			SDK::Camera Camera = (SDK::Camera)Globals::Workspace.FindFirstChildOfClass("Camera");
			if (!Camera.Address) continue;
			//zeroGravity(true);
			SDK::Vector3 Forward = Camera.Forward();
			SDK::Vector3 Right = Camera.Right();
			SDK::Vector3 Up = Camera.Up();

			SDK::Vector3 Dir(0, 0, 0);
			// keys
			if (GetAsyncKeyState('W') & 0x8000) Dir = Dir - Forward;
			if (GetAsyncKeyState('S') & 0x8000) Dir = Dir + Forward;
			if (GetAsyncKeyState('A') & 0x8000) Dir = Dir - Right;
			if (GetAsyncKeyState('D') & 0x8000) Dir = Dir + Right;
			if (GetAsyncKeyState(VK_SPACE) & 0x8000) Dir = Dir + Up;
			if (GetAsyncKeyState(VK_CONTROL) & 0x8000) Dir = Dir - Up;

			if (Dir.magnitude() > 0) Dir = Dir.normalize();

			auto prim = HRP.Object.Primitive();
			if (prim.Address)
			{
				if (!SDK::Memory->IsValid(prim.Address)) continue;
				if (Globals::World::Movement::FlyMethod == 0)
				{
					// cframe
					SDK::Vector3 newPos = prim.Position() + Dir * Globals::World::Movement::FlySpeed;
					SDK::CFrame cframe(Camera.CameraRotation(), newPos);
					SDK::Primitive TorsoPrim = FindTorsoPrim(Globals::LocalPlayer.Character());
					if (TorsoPrim.Address && !SDK::Memory->IsValid(TorsoPrim.Address)) TorsoPrim.Address = 0;
					for (int i = 0; i < 1000; i++)
					{
						prim.SetAssemblyLinearVelocity(SDK::Vector3(0, 0, 0));
						prim.SetCFrame(cframe);
						if (TorsoPrim.Address)
							TorsoPrim.SetCFrame(cframe);
					}
				}
				else
				{
					// velocity
					SDK::Primitive TorsoPrim = FindTorsoPrim(Globals::LocalPlayer.Character());
					if (TorsoPrim.Address && !SDK::Memory->IsValid(TorsoPrim.Address)) TorsoPrim.Address = 0;
					for (int i = 0; i < 1000; i++)
					{
						prim.SetAssemblyLinearVelocity(Dir * Globals::World::Movement::FlySpeed * 10.0f);
						if (TorsoPrim.Address)
							TorsoPrim.SetAssemblyLinearVelocity(Dir * Globals::World::Movement::FlySpeed * 10.0f);
					}

				}
			}
		}

		/*
		else
		{
			if (gravityZeroed)
			{
				SDK::Primitive prim;
				{
					std::lock_guard<std::mutex> cacheLock(SDK::Cache::PlayersMutex);
					prim = SDK::Cache::LocalPlayer.HumanoidRootPart.Object.Primitive();
				}
				if (prim.Address)
					prim.SetVelocity(SDK::Vector3(0, 0, 0));
				//zeroGravity(false);
			}
			//std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		*/
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void CFrame()
{
	while (true)
	{
		Globals::World::Movement::SpeedKey.update();
		if (Globals::Misc::RiskyFunctions && Globals::World::Movement::Speed && Globals::World::Movement::SpeedKey.enabled)
		{
			SDK::Cache::Bone HRP;
			SDK::Humanoid Humanoid;
			{
				std::lock_guard<std::mutex> cacheLock(SDK::Cache::PlayersMutex);
				HRP = SDK::Cache::LocalPlayer.HumanoidRootPart;
				Humanoid = SDK::Cache::LocalPlayer.Humanoid;
			}
			if (!HRP.Object.Address || !Humanoid.Address || !IsValidPtr(Humanoid.Address))
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(2));
				continue;
			}
			// SDK::Memory->Write<bool>(Humanoid.Address + SDK::Offsets::AutoRotate, false);

			SDK::Camera Camera = (SDK::Camera)Globals::Workspace.FindFirstChildOfClass("Camera");
			SDK::Vector3 LookVec = Camera.FlatForward();
			SDK::Vector3 RightVec = Camera.Right();
			RightVec.y = 0;
			if (RightVec.magnitude() > 0.0001f) RightVec = RightVec.normalize();

			SDK::Vector3 Direction(0, 0, 0);
			if (GetAsyncKeyState('W') & 0x8000) Direction = Direction - LookVec;
			if (GetAsyncKeyState('S') & 0x8000) Direction = Direction + LookVec;
			if (GetAsyncKeyState('A') & 0x8000) Direction = Direction - RightVec;
			if (GetAsyncKeyState('D') & 0x8000) Direction = Direction + RightVec;

			if (Direction.magnitude() > 0) Direction = Direction.normalize();

			auto prim = HRP.Object.Primitive();
			if (prim.Address && SDK::Memory->IsValid(prim.Address) && Direction.magnitude() > 0)
			{
				if (Globals::World::Movement::SpeedMethod == 0)
				{
					SDK::Primitive TorsoPrim = FindTorsoPrim(Globals::LocalPlayer.Character());
					if (TorsoPrim.Address && !SDK::Memory->IsValid(TorsoPrim.Address)) TorsoPrim.Address = 0;
					for (int i = 0; i < 1000; i++)
					{
						SDK::CFrame cframe(prim.Rotation(), prim.Position() + Direction * Globals::World::Movement::SpeedValue * 0.0001f);
						prim.SetCFrame(cframe);
						if (TorsoPrim.Address)
						{
							SDK::CFrame torsoCf(TorsoPrim.Rotation(), TorsoPrim.Position() + Direction * Globals::World::Movement::SpeedValue * 0.0001f);
							TorsoPrim.SetCFrame(torsoCf);
						}
					}
				}
				else if (Globals::World::Movement::SpeedMethod == 1)
				{
					SDK::Primitive TorsoPrim = FindTorsoPrim(Globals::LocalPlayer.Character());
					if (TorsoPrim.Address && !SDK::Memory->IsValid(TorsoPrim.Address)) TorsoPrim.Address = 0;
					for (int i = 0; i < 1000; i++)
					{
						prim.SetAssemblyLinearVelocity(prim.Velocity() + Direction * Globals::World::Movement::SpeedValue * 0.0001f);
						if (TorsoPrim.Address)
							TorsoPrim.SetAssemblyLinearVelocity(TorsoPrim.Velocity() + Direction * Globals::World::Movement::SpeedValue * 0.0001f);
					}
				}
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(2));
		}
		else
		{
			SDK::Humanoid Humanoid = SDK::Cache::LocalPlayer.Humanoid;
			if (Humanoid.Address && IsValidPtr(Humanoid.Address));
				//SDK::Memory->Write<bool>(Humanoid.Address + SDK::Offsets::AutoRotate, true);
			//std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
}



SDK::Vector3 UpVector(const SDK::Matrix3& rotationMatrix) {
	return { rotationMatrix.data[1], rotationMatrix.data[1 + 3], rotationMatrix.data[1 + 6] };
}

void FreeCam()
{
	SDK::Vector3 CurrentPos(0, 0, 0);
	bool FirstFrame = true;

	while (true)
	{
		Globals::World::Movement::FreecamKey.update();
		if (Globals::World::Movement::Freecam && Globals::World::Movement::FreecamKey.enabled)
		{
			SDK::Camera Camera = (SDK::Camera)Globals::Workspace.FindFirstChildOfClass("Camera");
			if (!Camera.Address) continue;

			SDK::Vector3 LookVec = Camera.Forward();
			SDK::Vector3 RightVec = Camera.Right();
			SDK::Vector3 UpVec = Camera.Up();

			if (FirstFrame)
			{
				CurrentPos = Camera.CameraPosition();
				FirstFrame = false;
			}

			SDK::Vector3 Direction(0, 0, 0);
			if (GetAsyncKeyState('S') & 0x8000) Direction += LookVec;
			if (GetAsyncKeyState('W') & 0x8000) Direction -= LookVec;
			if (GetAsyncKeyState('A') & 0x8000) Direction -= RightVec;
			if (GetAsyncKeyState('D') & 0x8000) Direction += RightVec;
			if (GetAsyncKeyState(VK_SPACE) & 0x8000) Direction += UpVec;
			if (GetAsyncKeyState(VK_CONTROL) & 0x8000) Direction -= UpVec;

			if (Direction.magnitude() > 0.0001f) Direction = Direction.normalize();

			CurrentPos += Direction * Globals::World::Movement::FreecamSpeed;
			Camera.SetCameraPosition(CurrentPos);
		}
		else
		{
			FirstFrame = true;
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}
	}
}

void ThirdPerson()
{
	SDK::Vector3 OldOffset(0, 0, 0);
	bool GotOld = false;
	bool WasOn = false;
	uintptr_t HumAddr = 0;

	while (true)
	{
		Globals::World::Movement::ThirdPersonKey.update();
		bool want = Globals::World::Movement::ThirdPerson && Globals::World::Movement::ThirdPersonKey.enabled;

		SDK::Humanoid Hum = SDK::Cache::LocalPlayer.Humanoid;
		uintptr_t hum = Hum.Address && IsValidPtr(Hum.Address) ? Hum.Address : 0;

		if (want && hum)
		{
			if (!WasOn || HumAddr != hum)
			{
				try { OldOffset = SDK::Memory->Read<SDK::Vector3>(hum + SDK::Offsets::CameraOffset); } catch (...) { OldOffset = SDK::Vector3(0, 0, 0); }
				GotOld = true;
				HumAddr = hum;
				WasOn = true;
			}

			float ox = Globals::World::Movement::ThirdPersonX;
			float oy = Globals::World::Movement::ThirdPersonY;
			float oz = Globals::World::Movement::ThirdPersonZ;

			try
			{
				SDK::Memory->Write<SDK::Vector3>(hum + SDK::Offsets::CameraOffset,
					SDK::Vector3(OldOffset.x + ox, OldOffset.y + oy, OldOffset.z + oz));
			}
			catch (...)
			{
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		else
		{
			if (WasOn)
			{
				// give the camera back to the game (back to first person)
				if (GotOld && hum)
				{
					try { SDK::Memory->Write<SDK::Vector3>(hum + SDK::Offsets::CameraOffset, OldOffset); } catch (...) {}
				}
				WasOn = false;
				GotOld = false;
				HumAddr = 0;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}
	}
}

void InfiniteJump()
{
	while (true)
	{
		
		if (Globals::World::Movement::InfiniteJump)
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
				SDK::Cache::Bone HRP = SDK::Cache::LocalPlayer.HumanoidRootPart;
				SDK::Humanoid Humanoid = SDK::Cache::LocalPlayer.Humanoid;
				if (!HRP.Object.Address || !Humanoid.Address)
				{
					
					std::this_thread::sleep_for(std::chrono::milliseconds(5));
					continue;
				}
				float YVelocity = SDK::Memory->Read<float>(Humanoid.Address + SDK::Offsets::JumpPower);
				if (Globals::Misc::RiskyFunctions && Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPower)
				{
					YVelocity = Globals::World::Movement::InfiniteJumpNameSpace::CustomJumpPowerValue;
				}
				SDK::Vector3 Velocity = HRP.Object.Primitive().Velocity();
				SDK::Vector3 NewVelocity(
					Velocity.x,
					YVelocity,
					Velocity.z
				);
			
				HRP.Object.Primitive().SetVelocity(NewVelocity);
			}
		}
		else
		{
			
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
		}
	}
}

SDK::Vector3 CrossProduct(SDK::Vector3 v1, SDK::Vector3 v2)
{
	return SDK::Vector3(
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	);
}

void Spinbot()
{
	float Angle = 0.0f;
	float JitterAngle = 0.0f;
	bool JitterFlip = false;

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1)); // keep CPU low

		Globals::World::Movement::AntiAimKey.update();
		bool anyMode = Globals::World::Movement::AntiAimYaw != 0 || Globals::World::Movement::AntiAimPitch != 0;
		bool anyActive = Globals::Misc::RiskyFunctions && anyMode && Globals::World::Movement::Spinbot;

		if (anyActive)
		{
			SDK::Cache::Bone HRP = SDK::Cache::LocalPlayer.HumanoidRootPart;
			SDK::Humanoid Humanoid = SDK::Cache::LocalPlayer.Humanoid;

			if (!HRP.Object.Address || !Humanoid.Address || !IsValidPtr(Humanoid.Address))
				continue;

			// SDK::Memory->Write<bool>(Humanoid.Address + SDK::Offsets::AutoRotate, false);

			float yawAngle = 0.0f;
			if (Globals::World::Movement::AntiAimYaw == 1) // Spinbot
			{
				Angle += Globals::World::Movement::SpinbotSpeed * 0.005f;
				if (Angle > 6.2831855f) Angle -= 6.2831855f;
				yawAngle = Angle;
			}
			else if (Globals::World::Movement::AntiAimYaw == 2) // Backward
			{
				yawAngle = 3.14159265f;
			}
			else if (Globals::World::Movement::AntiAimYaw == 3) // Jitter
			{
				JitterAngle += 0.1f;
				if (JitterAngle > 0.5f) { JitterAngle = -0.5f; JitterFlip = !JitterFlip; }
				yawAngle = JitterFlip ? 3.14159f + JitterAngle : JitterAngle;
			}
			else if (Globals::World::Movement::AntiAimYaw == 4) // Random
			{
				yawAngle = (rand() % 6283) / 1000.0f;
			}

			float pitchAngle = 0.0f;
			if (Globals::World::Movement::AntiAimPitch == 1) // Down
				pitchAngle = -0.6f;
			else if (Globals::World::Movement::AntiAimPitch == 2) // Up
				pitchAngle = 0.6f;
			else if (Globals::World::Movement::AntiAimPitch == 3) // Jitter
			{
				static float pitchJitter = 0.0f;
				pitchJitter += 0.05f;
				if (pitchJitter > 0.6f) pitchJitter = -0.6f;
				pitchAngle = pitchJitter;
			}

			// Build look vector
			float cosPitch = cosf(pitchAngle);
			SDK::Vector3 look = { sinf(yawAngle) * cosPitch, sinf(pitchAngle), cosf(yawAngle) * cosPitch };
			float lookLen = sqrtf(look.x * look.x + look.y * look.y + look.z * look.z);
			if (lookLen > 0.001f) { look.x /= lookLen; look.y /= lookLen; look.z /= lookLen; }

			SDK::Vector3 worldUp = { 0.0f, 1.0f, 0.0f };
			if (Globals::World::Movement::UpsideDown && Globals::World::Movement::AntiAimYaw == 1)
			{
				worldUp.y = -1.0f;
				look = { -look.x, -look.y, -look.z };
			}

			SDK::Vector3 right = CrossProduct(worldUp, look);
			float rLen = sqrtf(right.x * right.x + right.y * right.y + right.z * right.z);
			if (rLen < 0.001f) right = { 1.0f, 0.0f, 0.0f };
			else { right.x /= rLen; right.y /= rLen; right.z /= rLen; }
			SDK::Vector3 correctedUp = CrossProduct(look, right);

			SDK::Matrix3 rotationMatrix;
			rotationMatrix.data[0] = right.x;
			rotationMatrix.data[3] = right.y;
			rotationMatrix.data[6] = right.z;
			rotationMatrix.data[1] = correctedUp.x;
			rotationMatrix.data[4] = correctedUp.y;
			rotationMatrix.data[7] = correctedUp.z;
			rotationMatrix.data[2] = look.x;
			rotationMatrix.data[5] = look.y;
			rotationMatrix.data[8] = look.z;

			SDK::Cache::Bone primBone = SDK::Cache::LocalPlayer.HumanoidRootPart;
			if (IsValidPtr(primBone.Object.Address))
			{
				SDK::Primitive prim = primBone.Object.Primitive();
				if (IsValidPtr(prim.Address))
				{
					for (int i = 0; i < 100; i++)
					{
						SDK::Memory->Write<SDK::Matrix3>(prim.Address + SDK::Offsets::Rotation, rotationMatrix);
					}
				}
			}
		}
		else
		{
			/*
			SDK::Humanoid Humanoid = SDK::Cache::LocalPlayer.Humanoid;
			if (Humanoid.Address && IsValidPtr(Humanoid.Address))
				SDK::Memory->Write<bool>(Humanoid.Address + SDK::Offsets::AutoRotate, true);
			*/

			Angle = 0.0f;
			JitterAngle = 0.0f;
			JitterFlip = false;
		}
	}
}

void Peek()
{
	while (true)
	{
		Globals::World::Movement::PeekKey.update();
		if (Globals::Misc::RiskyFunctions && Globals::World::Movement::Peek && Globals::World::Movement::PeekKey.enabled)
		{
			auto hrp = SDK::Cache::LocalPlayer.HumanoidRootPart;
			if (hrp.Object.Address && IsValidPtr(hrp.Object.Address))
			{
				SDK::Primitive prim = hrp.Object.Primitive();
				if (IsValidPtr(prim.Address))
				{
					if (!Globals::World::Movement::PeekActive)
					{
						Globals::World::Movement::PeekPosition = prim.Position();
						Globals::World::Movement::PeekActive = true;
					}
					bool shouldTP = (!Globals::World::Movement::PeekKey.enabled);
					if (!shouldTP && Globals::World::Movement::PeekClickTP && (GetAsyncKeyState(VK_LBUTTON) & 0x8000))
						shouldTP = true;
					if (shouldTP)
					{
						for (int i = 0; i < 100; i++)
						{
							prim.SetPosition(Globals::World::Movement::PeekPosition);
						}
						Globals::World::Movement::PeekActive = false;
					}
				}
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		else
		{
			Globals::World::Movement::PeekActive = false;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
}

void Zoom()
{
	float OldFOV = 0;
	bool FirstFrame = false;
	while (true)
	{
		Globals::World::ZoomKey.update();
		if (Globals::World::Zoom && Globals::World::ZoomKey.enabled)
		{
			
			
			FirstFrame = true;
			if (Globals::Workspace.FindFirstChildOfClass("Camera").Address)
				SDK::Memory->Write<float>(Globals::Workspace.FindFirstChildOfClass("Camera").Address + SDK::Offsets::FOV, (Globals::World::ZoomValue * 0.0174533f));
			
		}
		else
		{
			if (FirstFrame)
			{
				if (Globals::Workspace.FindFirstChildOfClass("Camera").Address)
					SDK::Memory->Write<float>(Globals::Workspace.FindFirstChildOfClass("Camera").Address + SDK::Offsets::FOV, OldFOV);
				FirstFrame = false;
			}
			if (Globals::Workspace.FindFirstChildOfClass("Camera").Address)
				OldFOV = SDK::Memory->Read<float>(Globals::Workspace.FindFirstChildOfClass("Camera").Address + SDK::Offsets::FOV);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
}

void SpamTP()
{
	while (true)
	{
		if (Globals::Misc::RiskyFunctions && Globals::Aimbot::Rage::SpamTP && Globals::Aimbot::Target::HaveTarget)
		{
			
			SDK::Cache::Player Target;
			SDK::Cache::PlayersMutex.lock();
			for (SDK::Cache::Player Player : SDK::Cache::Players)
			{
				if (Player.PlayerName == Globals::Aimbot::Target::Name)
				{
					Target = Player;
					break;
				}
			}
			SDK::Cache::PlayersMutex.unlock();
			if (Target.CharacterObjectAddress != 0)
			{
				SDK::Cache::Bone HRP = SDK::Cache::LocalPlayer.HumanoidRootPart;
				SDK::Cache::Bone HRPT = Target.HumanoidRootPart;
				if (!HRP.Object.Address || !HRPT.Object.Address)
				{

					std::this_thread::sleep_for(std::chrono::milliseconds(100));
					continue;
				}
				if (Globals::Aimbot::Target::HaveTarget)
					HRP.Object.Primitive().SetPosition(HRPT.Object.Primitive().Position());
				
				//std::this_thread::sleep_for(std::chrono::milliseconds(5));
			}
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
}

void Orbit()
{
	auto start_time = std::chrono::high_resolution_clock::now();

	while (true)
	{
		if (Globals::Misc::RiskyFunctions && Globals::Aimbot::Rage::Orbit && Globals::Aimbot::Target::HaveTarget)
		{
			SDK::Cache::Player Target;
			bool found = false;

			SDK::Cache::PlayersMutex.lock();
			for (const auto& Player : SDK::Cache::Players)
			{
				if (Player.PlayerName == Globals::Aimbot::Target::Name)
				{
					Target = Player;
					found = true;
					break;
				}
			}
			SDK::Cache::PlayersMutex.unlock();

			if (found && Target.CharacterObjectAddress != 0)
			{
				SDK::Cache::Bone HRP = SDK::Cache::LocalPlayer.HumanoidRootPart;
				SDK::Cache::Bone HRPT = Target.HumanoidRootPart;

				if (HRP.Object.Address && HRPT.Object.Address)
				{
					float speed = Globals::Aimbot::Rage::OrbitSettings::orbitSpeed;
					float radius = Globals::Aimbot::Rage::OrbitSettings::radius;
					float offset = Globals::Aimbot::Rage::OrbitSettings::heightOffset;

					SDK::Vector3 target_pos = HRPT.Object.Primitive().Position();

					auto current_time = std::chrono::high_resolution_clock::now();
					float time_elapsed = std::chrono::duration_cast<std::chrono::duration<float>>(current_time - start_time).count();

					float angle = speed * time_elapsed;
					float new_x = target_pos.x + radius * cos(angle);
					float new_z = target_pos.z + radius * sin(angle);

					SDK::Vector3 new_pos = { new_x, target_pos.y + offset, new_z };
					HRP.Object.Primitive().SetPosition(new_pos);
				}
			}
			// std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
}



void Desync()
{
	bool WasActive = false;
	uintptr_t fflagAddr = SDK::RobloxBase + SDK::Offsets::NextGenReplicatorEnabledWrite4;
	while (true)
	{
		Globals::Misc::DesyncBind.update();
		bool active = Globals::Misc::RiskyFunctions && Globals::Misc::DesyncBind.enabled && Globals::Misc::Desync;

		if (active && !WasActive)
		{
			SDK::Cache::Bone HRP = SDK::Cache::LocalPlayer.HumanoidRootPart;
			if (HRP.Object.Address)
				Globals::Misc::DesyncedPostion = HRP.WorldPosition;
			SDK::Memory->Write<int>(fflagAddr, 1);
			WasActive = true;
		}
		else if (!active && WasActive)
		{
			SDK::Memory->Write<int>(fflagAddr, 0);
			Globals::Misc::DesyncedPostion = SDK::Vector3(-1, -1, -1);
			WasActive = false;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(30));
	}
}

void Noclip()
{
	bool prev = false;
	while (true)
	{
		Globals::World::Movement::NoclipKey.update();
		bool enable = Globals::Misc::RiskyFunctions && Globals::World::Movement::Noclip && Globals::World::Movement::NoclipKey.enabled;
		// ponytail: when off and was off, don't touch the cache or write memory at
		// all. the old code locked PlayersMutex every 30ms and did per-bone
		// VirtualQueryEx + read/write syscalls under the lock (~128 bones), starving
		// the render's try_lock (ESP drew ~2 frames then died).
		if (!enable && !prev)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			continue;
		}
		std::vector<uintptr_t> prims;
		{
			std::lock_guard<std::mutex> cacheLock(SDK::Cache::PlayersMutex);
			prims.reserve(SDK::Cache::LocalPlayer.Bones.size());
			for (auto& bone : SDK::Cache::LocalPlayer.Bones)
				if (bone.Object.Address)
					prims.push_back(bone.Object.Primitive().Address);
		}
		for (uintptr_t p : prims)
		{
			if (!p || !IsValidPtr(p))
				continue;
			uint8_t flags = SDK::Memory->Read<uint8_t>(p + SDK::Offsets::CanCollide);
			flags = enable ? (uint8_t)(flags & ~(uint8_t)SDK::Offsets::CanCollideMask) : (uint8_t)(flags | (uint8_t)SDK::Offsets::CanCollideMask);
			SDK::Memory->Write<uint8_t>(p + SDK::Offsets::CanCollide, flags);
		}
		prev = enable;
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
	}
}


void WalkSpeedThread()
{
	while (true)
	{
		SDK::Humanoid Humanoid = SDK::Cache::LocalPlayer.Humanoid;
		if (Globals::Misc::RiskyFunctions && Globals::World::Movement::WalkSpeed && Humanoid.Address && IsValidPtr(Humanoid.Address))
		{
			Humanoid.SetWalkSpeed(Globals::World::Movement::WalkSpeedValue);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void AnimationChanger()
{
	auto &IdleSel = Globals::Exploits::AnimationIdle;
	auto &RunSel = Globals::Exploits::AnimationRun;
	auto &WalkSel = Globals::Exploits::AnimationWalk;
	auto &JumpSel = Globals::Exploits::AnimationJump;
	auto &FallSel = Globals::Exploits::AnimationFall;
	auto &ClimbSel = Globals::Exploits::AnimationClimb;
	auto &SwimSel = Globals::Exploits::AnimationSwim;

	const auto& packs = AnimationCatalog::Packs();

	while (true)
	{
		if (!Globals::Exploits::AnimationEnabled)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			continue;
		}

		try
		{
			SDK::Player LocalPlayer = Globals::LocalPlayer;
			SDK::Instance Character = LocalPlayer.Character();
			if (!Character.Address || !IsValidPtr(Character.Address))
			{
				LocalPlayer = (SDK::Player)Globals::Players.LocalPlayer();
				Character = LocalPlayer.Character();
				if (!Character.Address || !IsValidPtr(Character.Address))
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
					continue;
				}
			}

			SDK::Humanoid Humanoid = static_cast<SDK::Humanoid>(Character.FindFirstChildOfClass("Humanoid"));
			if (Humanoid.Address)
			{
				if (Humanoid.RigType() != 1)
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(300));
					continue;
				}
			}

			SDK::Instance Animate = Character.FindFirstChild("Animate");
			if (!Animate.Address)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				continue;
			}

			SDK::Instance FallAnim = Animate.FindFirstChild("fall").FindFirstChild("FallAnim");
			SDK::Instance JumpAnim = Animate.FindFirstChild("jump").FindFirstChild("JumpAnim");
			SDK::Instance RunAnim = Animate.FindFirstChild("run").FindFirstChild("RunAnim");
			SDK::Instance WalkAnim = Animate.FindFirstChild("walk").FindFirstChild("WalkAnim");
			SDK::Instance Idle1 = Animate.FindFirstChild("idle").FindFirstChild("Animation1");
			SDK::Instance Idle2 = Animate.FindFirstChild("idle").FindFirstChild("Animation2");
			SDK::Instance ClimbAnim = Animate.FindFirstChild("climb").FindFirstChild("ClimbAnim");
			SDK::Instance SwimAnim = Animate.FindFirstChild("swim").FindFirstChild("Swim");

			if (IdleSel > 0 && IdleSel <= (int)packs.size())
			{
				std::string id = AnimationCatalog::Url(packs[IdleSel - 1].Idle);
				if (Idle1.Address) Idle1.SetAnimationId(id);
				if (Idle2.Address) Idle2.SetAnimationId(id);
			}
			if (RunSel > 0 && RunSel <= (int)packs.size() && RunAnim.Address)
				RunAnim.SetAnimationId(AnimationCatalog::Url(packs[RunSel - 1].Run));
			if (WalkSel > 0 && WalkSel <= (int)packs.size() && WalkAnim.Address)
				WalkAnim.SetAnimationId(AnimationCatalog::Url(packs[WalkSel - 1].Walk));
			if (JumpSel > 0 && JumpSel <= (int)packs.size() && JumpAnim.Address)
				JumpAnim.SetAnimationId(AnimationCatalog::Url(packs[JumpSel - 1].Jump));
			if (FallSel > 0 && FallSel <= (int)packs.size() && FallAnim.Address)
				FallAnim.SetAnimationId(AnimationCatalog::Url(packs[FallSel - 1].Fall));
			if (ClimbSel > 0 && ClimbSel <= (int)packs.size() && ClimbAnim.Address)
				ClimbAnim.SetAnimationId(AnimationCatalog::Url(packs[ClimbSel - 1].Climb));
			if (SwimSel > 0 && SwimSel <= (int)packs.size() && SwimAnim.Address)
				SwimAnim.SetAnimationId(AnimationCatalog::Url(packs[SwimSel - 1].Swim));
		}
		catch (...)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}

void TimeManipulationThread()
{
	float backupSps = 0.0f;
	bool backedUp = false;

	while (true)
	{
		if (Globals::World::TimeManipulation && Globals::Workspace.Address)
		{
			uintptr_t world = SDK::Memory->Read<uintptr_t>(Globals::Workspace.Address + SDK::Offsets::WorkspaceToWorld);
			if (world)
			{
				if (!backedUp)
				{
					backupSps = SDK::Memory->Read<float>(world + SDK::Offsets::fWorldStepsPerSecond);
					backedUp = true;
				}
				float val = Globals::World::TimeManipulationValue;
				if (val < 1.0f) val = 1.0f;
				SDK::Memory->Write<float>(world + SDK::Offsets::fWorldStepsPerSecond, val);
			}
		}
		else if (backedUp && Globals::Workspace.Address)
		{
			uintptr_t world = SDK::Memory->Read<uintptr_t>(Globals::Workspace.Address + SDK::Offsets::WorkspaceToWorld);
			if (world)
			{
				SDK::Memory->Write<float>(world + SDK::Offsets::fWorldStepsPerSecond, backupSps);
			}
			backedUp = false;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}
}

void Hacks::Misc::Setup()
{
	std::thread(AnimationChanger).detach();
	std::thread(FlyHack).detach();
	std::thread(Zoom).detach();
	std::thread(CFrame).detach();
	std::thread(FreeCam).detach();
	std::thread(ThirdPerson).detach();
	std::thread(InfiniteJump).detach();
	std::thread(Spinbot).detach();
	std::thread(Peek).detach();
	std::thread(SpamTP).detach();
	std::thread(Orbit).detach();
	std::thread(Desync).detach();
	std::thread(Noclip).detach();
	std::thread(WalkSpeedThread).detach();
	std::thread(TimeManipulationThread).detach();
	Hacks::Raycast::Setup();

}
