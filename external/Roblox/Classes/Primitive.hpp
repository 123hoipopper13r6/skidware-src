#pragma once
#include "../../Includes.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
namespace SDK
{
	class Primitive
	{
	public:
		uintptr_t Address;
		void ReadAll(SDK::Matrix3& rot, SDK::Vector3& pos, SDK::Vector3& size)
		{
			rot = SDK::Matrix3();
			pos = SDK::Vector3(0, 0, 0);
			size = SDK::Vector3(0, 0, 0);
			if (!this->Address)
				return;
			uintptr_t a = (std::min)((std::min)(SDK::Offsets::Rotation, SDK::Offsets::Position), SDK::Offsets::PartSize);
			uintptr_t b = (std::max)((std::max)(SDK::Offsets::Rotation, SDK::Offsets::Position), SDK::Offsets::PartSize);
			size_t span = (size_t)(b - a) + sizeof(SDK::Vector3);
			if (span > 0x200)
			{
				rot = Rotation();
				pos = Position();
				size = Size();
				return;
			}
			unsigned char buf[0x200] = {};
			SDK::Memory->ReadRaw(this->Address + a, buf, span);
			auto grab = [&](uintptr_t off, void* out, size_t n) {
				if (off >= a && off + n <= a + span)
					memcpy(out, buf + (off - a), n);
			};
			grab(SDK::Offsets::Rotation, &rot, sizeof(SDK::Matrix3));
			grab(SDK::Offsets::Position, &pos, sizeof(SDK::Vector3));
			grab(SDK::Offsets::PartSize, &size, sizeof(SDK::Vector3));
		}
		SDK::Vector3 Position()
		{
			if (!this->Address)
				return SDK::Vector3(0, 0, 0);
			return SDK::Memory->Read<SDK::Vector3>(this->Address + SDK::Offsets::Position);
		}
		SDK::Vector3 Size()
		{
			if (!this->Address)
				return SDK::Vector3(0, 0, 0);
			return SDK::Memory->Read<SDK::Vector3>(this->Address + SDK::Offsets::PartSize);
		}
		SDK::Vector3 Velocity()
		{
			if (!this->Address)
				return SDK::Vector3(0, 0, 0);
			return SDK::Memory->Read<SDK::Vector3>(this->Address + SDK::Offsets::Velocity);
		}
		SDK::Matrix3 Rotation()
		{
			if (!this->Address)
				return SDK::Matrix3();
			return SDK::Memory->Read<SDK::Matrix3>(this->Address + SDK::Offsets::Rotation);
		}
		void SetRotation(SDK::Matrix3 Value)
		{
			if (!this->Address)
				return;
			SDK::Memory->Write<SDK::Matrix3>(this->Address + SDK::Offsets::Rotation, Value);
		}
		void SetPosition(SDK::Vector3 Value)
		{
			if (!this->Address)
				return;
			SDK::Memory->Write<SDK::Vector3>(this->Address + SDK::Offsets::Position, Value);
		}
		void SetSize(SDK::Vector3 Value)
		{
			if (!this->Address)
				return;
			SDK::Memory->Write<SDK::Vector3>(this->Address + SDK::Offsets::PartSize, Value);
		}
		void SetVelocity(SDK::Vector3 Value)
		{
			if (!this->Address)
				return;
			SDK::Memory->Write<SDK::Vector3>(this->Address + SDK::Offsets::Velocity, Value);
		}
		void SetCFrame(SDK::CFrame& cframe)
		{
			if (!this->Address) return;
			SDK::Memory->Write<SDK::CFrame>(this->Address + SDK::Offsets::CFrame, cframe);
		}
		void SetAssemblyLinearVelocity(SDK::Vector3 Value)
		{
			if (!this->Address) return;
			SDK::Memory->Write<SDK::Vector3>(this->Address + SDK::Offsets::AssemblyLinearVelocity, Value);
		}
		void SetAngularVelocity(SDK::Vector3 Value)
		{
			if (!this->Address) return;
			SDK::Memory->Write<SDK::Vector3>(this->Address + SDK::Offsets::AssemblyAngularVelocity, Value);
		}
		int Material()
		{
			if (!this->Address)
				return 0;
			return SDK::Memory->Read<int>(this->Address + SDK::Offsets::MaterialType);
		}
		void SetMaterial(int Material)
		{
			
			if (!this->Address)
				return;
			
			SDK::Memory->Write<int>(this->Address + SDK::Offsets::MaterialType, Material);
			
		}
		float Transparency()
		{
			if (!this->Address)
				return 0.0f;
			return SDK::Memory->Read<float>(this->Address + SDK::Offsets::Transparency);
		}
		void SetTransparency(float Value)
		{
			if (!this->Address)
				return;
			SDK::Memory->Write<float>(this->Address + SDK::Offsets::Transparency, Value);
		}

	};
}