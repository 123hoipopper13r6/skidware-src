#pragma once
#include "../../Includes.hpp"
namespace SDK
{
	class Humanoid : public SDK::Instance
	{
	public:
		SDK::Instance RootPart()
		{
			if (!this->Address)
				return SDK::Instance();
			return SDK::Memory->Read<SDK::Instance>(this->Address + SDK::Offsets::HumanoidRootPart);
		}
		float Health()
		{
			if (!this->Address)
				return 0.0f;
			union Conv
			{
				std::uint64_t hex;
				float f;
			} EasyConvertion;
			uintptr_t Health = SDK::Memory->Read<uintptr_t>(this->Address + SDK::Offsets::Health);
			uintptr_t HealthRead = SDK::Memory->Read<uintptr_t>(Health);
			EasyConvertion.hex = Health ^ HealthRead;
			return EasyConvertion.f;

		}
		float MaxHealth()
		{
			if (!this->Address)
				return 0.0f;
			union Conv
			{
				std::uint64_t hex;
				float f;
			} EasyConvertion;
			uintptr_t Health = SDK::Memory->Read<uintptr_t>(this->Address + SDK::Offsets::MaxHealth);
			uintptr_t HealthRead = SDK::Memory->Read<uintptr_t>(Health);
			EasyConvertion.hex = Health ^ HealthRead;
			return EasyConvertion.f;

		}
		std::string DisplayName()
		{
			if (!this->Address)
				return "?";
			return SDK::Memory->ReadString(this->Address + SDK::Offsets::HumanoidDisplayName);
		}
		void Kill()
		{
			if (!this->Address)
				return;
			SDK::Memory->Write<uintptr_t>(this->Address + SDK::Offsets::Health, 0);
		}
		int RigType()
		{
			if (!this->Address)
				return 0;
			return SDK::Memory->Read<int>(this->Address + SDK::Offsets::RigType);
		}
		float WalkSpeed()
		{
			if (!this->Address)
				return 0.0f;
			return SDK::Memory->Read<float>(this->Address + SDK::Offsets::WalkSpeed);
		}
		float JumpPower()
		{
			if (!this->Address)
				return 0.0f;
			return SDK::Memory->Read<float>(this->Address + SDK::Offsets::JumpPower);
		}
		void SetWalkSpeed(float Value)
		{
			if (!this->Address)
				return;
			SDK::Memory->Write<float>(this->Address + SDK::Offsets::WalkSpeed, Value);
			SDK::Memory->Write<float>(this->Address + SDK::Offsets::WalkSpeedCheck, Value);
		}
		void SetJumpPower(float Value)
		{
			if (!this->Address)
				return;
			SDK::Memory->Write<float>(this->Address + SDK::Offsets::JumpPower, Value);
		}
	};
}
