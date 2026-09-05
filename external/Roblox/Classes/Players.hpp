#pragma once
#include "../../Includes.hpp"
namespace SDK
{
	class Players : public SDK::Instance
	{
	public:
		SDK::Player LocalPlayer()
		{
			if (!this->Address)
				return SDK::Player();
			return SDK::Memory->Read<SDK::Player>(this->Address + SDK::Offsets::LocalPlayer);
		}
	};
}
