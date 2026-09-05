#pragma once
#include "../../Includes.hpp"
namespace SDK
{
	class Player : public SDK::Instance
	{
	public:
		std::string DisplayName()
		{
			if (!this->Address)
				return "?";
			return SDK::Memory->ReadString(this->Address + SDK::Offsets::DisplayName);
		}
		SDK::Instance Character()
		{
			if (!this->Address)
				return SDK::Instance();
			return SDK::Memory->Read<SDK::Instance>(this->Address + SDK::Offsets::ModelInstance);
		}
		SDK::Team Team()
		{
			if (!this->Address)
				return SDK::Team();
			return SDK::Memory->Read<SDK::Team>(this->Address + SDK::Offsets::Team);
		}
		int64_t UserId()
		{
			if (!this->Address)
				return 0;
			return SDK::Memory->Read<int64_t>(this->Address + SDK::Offsets::UserId);
		}
	};
}
