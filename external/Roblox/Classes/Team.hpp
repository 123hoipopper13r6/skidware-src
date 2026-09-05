#pragma once
#include "../../Includes.hpp"
namespace SDK
{
	class Team : public SDK::Instance
	{
	public:
		SDK::Color3 TeamColor()
		{
			if (!this->Address)
				return { "?", 0,0,0,0 };
			int TeamColorID = SDK::Memory->Read<int>(this->Address + SDK::Offsets::TeamColor);
			for (auto Color : SDK::KnownColors) {
				if (Color.id == TeamColorID) {
					return Color;
				}
			}
			return { "?", 0,0,0,0 };
		}
	};
}
