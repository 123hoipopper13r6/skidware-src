#pragma once
#include "../../Includes.hpp"
#include <cmath>
#include <vector>
#include <string>
namespace SDK
{
	class VisualEngine
	{
	public:
		uintptr_t Address;
		SDK::Vector2 Dimensions()
		{
			if (!this->Address)
				return SDK::Vector2(-1, -1);
			return SDK::Memory->Read<SDK::Vector2>(this->Address + SDK::Offsets::Dimensions);
		}
		SDK::Matrix4 ViewMatrix()
		{
			if (!this->Address)
				return SDK::Matrix4();
			return SDK::Memory->Read<SDK::Matrix4>(this->Address + SDK::Offsets::ViewMatrix);
		}
	};
	inline SDK::VisualEngine FetchVisualEngine()
	{
		return SDK::Memory->Read<SDK::VisualEngine>(SDK::RobloxBase + SDK::Offsets::VisualEnginePointer);
	}
	namespace VisualEngineCache
	{
		inline SDK::Vector2 Dimensions;
		inline SDK::Matrix4 ViewMatrix;
	}
	inline SDK::Vector2 WorldToScreen(SDK::Vector3 WorldPosition)
	{
		SDK::Matrix4 ViewMatrix = SDK::VisualEngineCache::ViewMatrix;
		SDK::Vector2 Dimensions = SDK::VisualEngineCache::Dimensions;
		SDK::Vector4 Q;
		Q.x = (WorldPosition.x * ViewMatrix.data[0]) + (WorldPosition.y * ViewMatrix.data[1]) + (WorldPosition.z * ViewMatrix.data[2]) + ViewMatrix.data[3];
		Q.y = (WorldPosition.x * ViewMatrix.data[4]) + (WorldPosition.y * ViewMatrix.data[5]) + (WorldPosition.z * ViewMatrix.data[6]) + ViewMatrix.data[7];
		Q.z = (WorldPosition.x * ViewMatrix.data[8]) + (WorldPosition.y * ViewMatrix.data[9]) + (WorldPosition.z * ViewMatrix.data[10]) + ViewMatrix.data[11];
		Q.w = (WorldPosition.x * ViewMatrix.data[12]) + (WorldPosition.y * ViewMatrix.data[13]) + (WorldPosition.z * ViewMatrix.data[14]) + ViewMatrix.data[15];
		if (Q.w < 0.1f || std::isnan(Q.w) || std::isinf(Q.w))
			return { -1, -1 };
		SDK::Vector3 NDC;
		NDC.x = Q.x / Q.w;
		NDC.y = Q.y / Q.w;
		NDC.z = Q.z / Q.w;
		if (std::isnan(NDC.x) || std::isinf(NDC.x) || std::isnan(NDC.y) || std::isinf(NDC.y))
			return { -1, -1 };
		SDK::Vector2 ScreenPosition =
		{
			(Dimensions.x / 2 * NDC.x) + (Dimensions.x / 2),
			-(Dimensions.y / 2 * NDC.y) + (Dimensions.y / 2),
		};
		if (ScreenPosition.x < 0 || ScreenPosition.x > Dimensions.x || ScreenPosition.y < 0 || ScreenPosition.y > Dimensions.y)
			return { -1, -1 };
		return ScreenPosition;
	}
}