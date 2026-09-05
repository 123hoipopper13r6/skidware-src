// Paste over Roblox/FFlags.hpp. Flag addresses are absolute and valid
// for the dumped game session only - regenerate after every rejoin.
#pragma once
#include <cstdint>
#include <cstring>

namespace SDK::FFlags
{
    enum class FlagType : uint8_t { Bool, Int, Double, String };

    struct Entry
    {
        const char* Name;
        FlagType Type;
        uintptr_t Address;
    };

    inline const Entry Entries[] = {
        { nullptr, FlagType::Bool, 0 },
    };

    inline const Entry* Find(const char* name)
    {
        if (!name)
            return nullptr;
        for (const auto& e : Entries)
            if (e.Name && std::strcmp(e.Name, name) == 0)
                return &e;
        return nullptr;
    }

    inline bool GetBool(const char* name, bool fallback = false)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::Bool)
            return fallback;
        return SDK::Memory->Read<uint8_t>(e->Address) != 0;
    }

    inline bool SetBool(const char* name, bool value)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::Bool)
            return false;
        SDK::Memory->Write<uint8_t>(e->Address, value ? 1 : 0);
        return true;
    }

    inline int32_t GetInt(const char* name, int32_t fallback = 0)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::Int)
            return fallback;
        return SDK::Memory->Read<int32_t>(e->Address);
    }

    inline bool SetInt(const char* name, int32_t value)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::Int)
            return false;
        SDK::Memory->Write<int32_t>(e->Address, value);
        return true;
    }

    inline double GetDouble(const char* name, double fallback = 0.0)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::Double)
            return fallback;
        return SDK::Memory->Read<double>(e->Address);
    }

    inline bool SetDouble(const char* name, double value)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::Double)
            return false;
        SDK::Memory->Write<double>(e->Address, value);
        return true;
    }

    // string payloads are MSVC std::string objects (SSO at >=16 chars goes to heap)
    inline bool GetString(const char* name, char* out, size_t cap)
    {
        const Entry* e = Find(name);
        if (!e || e->Type != FlagType::String || !out || cap == 0)
            return false;
        const uint64_t len = SDK::Memory->Read<uint64_t>(e->Address + 0x10);
        if (len == 0 || len >= cap)
            return false;
        uintptr_t src = e->Address;
        if (len >= 16) {
            src = SDK::Memory->Read<uintptr_t>(e->Address);
            if (!src)
                return false;
        }
        return SDK::Memory->ReadRaw(src, out, len) && ((out[len] = 0), true);
    }
} // namespace SDK::FFlags
