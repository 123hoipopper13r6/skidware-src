#pragma once
#include <cstdint>

namespace roblox::offsets {

    namespace ClassDescriptor {
        inline uintptr_t ClassName = 0;
        inline uintptr_t PropertyDescriptors = 0;
        inline uintptr_t EventDescriptors = 0;
        inline uintptr_t FunctionDescriptors = 0;
    } // namespace ClassDescriptor

    namespace Descriptor {
        inline uintptr_t Name = 0;
    } // namespace Descriptor

    namespace FunctionDescriptor {
        inline uintptr_t Function = 0;
    } // namespace FunctionDescriptor

    namespace Instance {
        inline uintptr_t ClassDescriptor = 0;
        inline uintptr_t Parent = 0;
        inline uintptr_t Name = 0;
        inline uintptr_t NameContainer = 0;
        inline uintptr_t ChildrenStart = 0;
        inline uintptr_t ChildrenEnd = 0;
    } // namespace Instance

    namespace Value {
        inline uintptr_t Value = 0;
    } // namespace Value

} // namespace roblox::offsets