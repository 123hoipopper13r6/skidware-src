#pragma once
#include "../../Includes.hpp"
namespace SDK
{
    inline std::vector<SDK::Instance> Crosshairs;
    inline std::mutex CrosshairsMutex;
    class MouseService : public SDK::Instance
    {
    public:
        uintptr_t InputObject()
        {
            if (!this->Address)
                return 0x0;
            return SDK::Memory->Read<uintptr_t>(this->Address + 0x100);
        }
        void SilentAim(SDK::Vector2 AimPosition, SDK::Vector2 OriginalPosition)
        {
            if (!this->Address)
                return;
            uintptr_t input = InputObject();
            if (!input)
                return;
            SDK::Vector2 Dimensions = SDK::VisualEngineCache::Dimensions;
            
            std::lock_guard<std::mutex> lock(CrosshairsMutex);
            for (SDK::Instance Aim : SDK::Crosshairs)
            {
                if (!Aim.Address)
                    continue;
                
                uint64_t NewPointX = static_cast<uint64_t>(OriginalPosition.x);
                uint64_t NewPointY = static_cast<uint64_t>(Dimensions.y - std::abs(Dimensions.y - OriginalPosition.y) - 58);
                if (Aim.Name() == "Main")
                    NewPointY = static_cast<uint64_t>(Dimensions.y - std::abs(Dimensions.y - OriginalPosition.y));
                
                SDK::Memory->Write<uint64_t>(Aim.Address + SDK::Offsets::FramePositionOffsetX, NewPointX);
                SDK::Memory->Write<uint64_t>(Aim.Address + SDK::Offsets::FramePositionOffsetY, NewPointY);
            }
            SDK::Memory->Write<SDK::Vector2>(input + SDK::Offsets::MousePosition, AimPosition);
        }

    };
}