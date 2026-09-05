#pragma once
#include "../../Includes.hpp"
namespace SDK
{
	class DataModel : public SDK::Instance
	{
	public:
		uintptr_t GameID()
		{
			if (!this->Address)
				return 0x0;
			return SDK::Memory->Read<uintptr_t>(this->Address + SDK::Offsets::GameId);
		}
	};
	inline SDK::DataModel FetchDatamodel()
	{
		uintptr_t FakeDatamodel = SDK::Memory->Read<uintptr_t>(SDK::RobloxBase + SDK::Offsets::FakeDataModelPointer);
		if (!FakeDatamodel)
			return SDK::DataModel();
		return SDK::Memory->Read<SDK::DataModel>(FakeDatamodel + SDK::Offsets::FakeDataModelToDataModel);
	}
}
