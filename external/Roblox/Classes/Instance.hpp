#pragma once
#include "../../Includes.hpp"
#include <vector>
#include <string>
namespace SDK
{
	class Instance
	{
	public:
		uintptr_t Address;
		inline std::string Name()
		{
			if (!this->Address)
				return "?";
			uintptr_t NameContainer = SDK::Memory->Read<uintptr_t>(this->Address + SDK::Offsets::NameContainer);
			if (!NameContainer)
				return "?";
			return SDK::Memory->ReadString(NameContainer + SDK::Offsets::Name);
		}
		inline std::string Class()
		{
			if (!this->Address)
				return "?";
			uintptr_t Descriptor = SDK::Memory->Read<uintptr_t>(this->Address + SDK::Offsets::ClassDescriptor);
			if (!Descriptor)
				return "?";
			uintptr_t StringPointer = SDK::Memory->Read<uintptr_t>(Descriptor + 0x8);
			if (!StringPointer)
				return "?";
			return SDK::Memory->ReadString(StringPointer);
		}
		inline SDK::Instance Parent()
		{
			if (!this->Address)
				return SDK::Instance();
			return SDK::Memory->Read<SDK::Instance>(this->Address + SDK::Offsets::Parent);
		}
		inline std::vector<SDK::Instance> Children()
		{
			std::vector<SDK::Instance> Container;

			if (!this->Address)
				return Container;
			auto Start = SDK::Memory->Read<uintptr_t>(this->Address + SDK::Offsets::ChildrenStart);
			if (!Start)
				return Container;
			auto Begin = SDK::Memory->Read<uintptr_t>(Start);
			auto End = SDK::Memory->Read<uintptr_t>(Start + SDK::Offsets::ChildrenEnd);
			if (!Begin || !End || End < Begin)
				return Container;
			size_t bytes = (size_t)(End - Begin);
			if (bytes > 0x100000)
				return Container;
			std::vector<unsigned char> buf(bytes);
			SDK::Memory->ReadRaw(Begin, buf.data(), bytes);
			size_t count = bytes / 16;
			if (count > 65535) count = 65535;
			Container.reserve(count);
			for (size_t i = 0; i < count; ++i)
			{
				uintptr_t addr = 0;
				memcpy(&addr, buf.data() + i * 16, sizeof(addr));
				if (addr)
				{
					SDK::Instance inst;
					inst.Address = addr;
					Container.push_back(inst);
				}
			}
			return Container;
		}
		inline SDK::Instance FindFirstChild(std::string Name)
		{
			if (!this->Address)
				return SDK::Instance();
			if (Name.empty())
				return SDK::Instance();
			std::vector<SDK::Instance> Children = this->Children();
			for (SDK::Instance Child : Children)
			{
				if (!Child.Address)
					continue;
				if (Child.Name() == Name)
					return Child;
			}
			return SDK::Instance();
		}
		inline SDK::Instance FindFirstChildOfClass(std::string Class)
		{
			if (!this->Address)
				return SDK::Instance();
			if (Class.empty())
				return SDK::Instance();
			std::vector<SDK::Instance> Children = this->Children();
			for (SDK::Instance Child : Children)
			{
				if (!Child.Address)
					continue;
				if (Child.Class() == Class)
					return Child;
			}
			return SDK::Instance();
		}
		inline SDK::Primitive Primitive()
		{
			if (!this->Address)
				return SDK::Primitive();
			return SDK::Memory->Read<SDK::Primitive>(this->Address + SDK::Offsets::Primitive);
		}
		inline std::string AnimationId()
		{
			if (!this->Address)
				return "";
			return SDK::Memory->ReadString(this->Address + SDK::Offsets::AnimationId);
		}
		inline bool SetAnimationId(const std::string& id)
		{
			if (!this->Address)
				return false;
			return SDK::Memory->WriteString(this->Address + SDK::Offsets::AnimationId, id);
		}
	};
}