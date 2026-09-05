#pragma once
#include "../../Includes.hpp"
namespace SDK
{
	class Camera : public SDK::Instance
	{
	public:
		SDK::Vector3 Forward() {
			SDK::Matrix3 rot = CameraRotation();
			return { rot.data[2], rot.data[5], rot.data[8] };
		}
		SDK::Vector3 Right() {
			SDK::Matrix3 rot = CameraRotation();
			return { rot.data[0], rot.data[3], rot.data[6] };
		}
		SDK::Vector3 Up() {
			SDK::Matrix3 rot = CameraRotation();
			return { rot.data[1], rot.data[4], rot.data[7] };
		}
		SDK::Vector3 FlatForward() {
			SDK::Vector3 flat = Forward();
			flat.y = 0;
			if (flat.magnitude() > 0.0001f) flat = flat.normalize();
			return flat;
		}
		SDK::Matrix3 CameraRotation()
		{
			if (!this->Address)
				return SDK::Matrix3();
			return SDK::Memory->Read<SDK::Matrix3>(this->Address + SDK::Offsets::CameraRotation);
		}
		SDK::Vector3 CameraPosition()
		{
			if (!this->Address)
				return SDK::Vector3();
			return SDK::Memory->Read<SDK::Vector3>(this->Address + SDK::Offsets::CameraPos);
		}

		void SetCameraRotation(SDK::Matrix3 Value)
		{
			if (!this->Address)
				return;
			SDK::Memory->Write<SDK::Matrix3>(this->Address + SDK::Offsets::CameraRotation, Value);
		}
		void SetCameraPosition(SDK::Vector3 Value)
		{
			if (!this->Address)
				return;
			SDK::Memory->Write<SDK::Vector3>(this->Address + SDK::Offsets::CameraPos, Value);
		}
		void SpectateHumanoid(SDK::Humanoid Human)
		{
			if (!this->Address)
				return;
			SDK::Memory->Write<uintptr_t>(this->Address + SDK::Offsets::CameraSubject, Human.Address);
		}
	};
}
