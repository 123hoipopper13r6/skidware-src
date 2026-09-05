#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <string>
#include <vector>
#include <cstring>
#include "../../Libs/LuckMemory/memory.h"

namespace SDK
{
    inline uintptr_t GetProcessId(std::string_view processName)
    {
        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(PROCESSENTRY32);
        HANDLE ss = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        while (Process32Next(ss, &pe)) {
#ifdef UNICODE
            char exeFile[MAX_PATH];
            WideCharToMultiByte(CP_ACP, 0, pe.szExeFile, -1, exeFile, MAX_PATH, nullptr, nullptr);
            if (!processName.compare(exeFile)) {
#else
            if (!processName.compare(pe.szExeFile)) {
#endif
                CloseHandle(ss);
                return pe.th32ProcessID;
            }
        }
        CloseHandle(ss);
        return 0;
    }
    class MemoryClass final
    {
    public:
        HANDLE Handle;

        template <typename T>
        inline T Read(uintptr_t address)
        {
            T B{};
            Luck_ReadVirtualMemory(Handle, (void*)address, &B, sizeof(T), nullptr);
            return B;
        }

        template <typename T>
        inline void Write(uintptr_t address, T v)
        {
            Luck_WriteVirtualMemory(Handle, (void*)address, &v, sizeof(T), nullptr);
        }

        inline bool ReadRaw(uintptr_t address, void* buffer, size_t size)
        {
            if (!Handle || !address || !buffer || !size)
                return false;
            return Luck_ReadVirtualMemory(Handle, (void*)address, buffer, (ULONG)size, nullptr) == 0;
        }

        inline bool WriteRaw(uintptr_t address, const void* data, size_t size)
        {
            if (!Handle || !address || !data || !size)
                return false;
            return Luck_WriteVirtualMemory(Handle, (void*)address, (void*)data, (ULONG)size, nullptr) == 0;
        }

        inline uintptr_t Alloc(size_t size, DWORD protection)
        {
            if (!Handle || !size)
                return 0;
            return (uintptr_t)VirtualAllocEx(Handle, nullptr, size, MEM_RESERVE | MEM_COMMIT, protection);
        }

        inline bool Free(uintptr_t address)
        {
            if (!Handle || !address)
                return false;
            return VirtualFreeEx(Handle, (void*)address, 0, MEM_RELEASE) != 0;
        }

        inline bool IsValid(uintptr_t address)
        {
            if (!Handle || !address)
                return false;
            MEMORY_BASIC_INFORMATION mbi{};
            if (!VirtualQueryEx(Handle, (void*)address, &mbi, sizeof(mbi)))
                return false;
            return mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS));
        }

        inline std::string ReadStringRaw(uintptr_t address, int maxLen)
        {
            std::string s;
            if (!Handle || !address || maxLen <= 0)
                return s;
            if (maxLen > 200)
                maxLen = 200;
            s.resize(maxLen);
            Luck_ReadVirtualMemory(Handle, (void*)address, s.data(), (ULONG)maxLen, nullptr);
            size_t nul = s.find('\0');
            if (nul != std::string::npos)
                s.resize(nul);
            return s;
        }

        inline std::string ReadString(uintptr_t address)
        {
            int length = this->Read<uintptr_t>(address + 0x18);
            if (length < 0) length = 0;
            if (length >= 16u)
            {
                uintptr_t n = this->Read<uintptr_t>(address);
                return this->ReadStringRaw(n, length);
            }
            else
            {
                return this->ReadStringRaw(address, length);
            }
        }

        // Writes a Roblox std::string into the target. Strings stay in the inline
        // SSO buffer when they fit (<16), otherwise we write into the existing heap
        // buffer if it has enough capacity (read at +0x20). Returns false if the new
        // value cannot be stored without reallocation.
        inline bool WriteString(uintptr_t address, const std::string& value)
        {
            if (!Handle || !address)
                return false;

            size_t newLen = value.size();
            int curLength = this->Read<uintptr_t>(address + 0x18);
            if (curLength < 0) curLength = 0;

            if (newLen < 16u)
            {
                // SSO inline write: buffer + length at +0x18
                std::vector<char> buf(16, 0);
                if (newLen > 0) memcpy(buf.data(), value.data(), newLen);
                Luck_WriteVirtualMemory(Handle, (void*)address, buf.data(), 16, nullptr);
                uintptr_t len = newLen;
                Luck_WriteVirtualMemory(Handle, (void*)(address + 0x18), &len, sizeof(len), nullptr);
                return true;
            }

            // Heap-backed string: reuse existing storage. Animation IDs are all URLs
            // of similar length, so the existing allocation has room.
            uintptr_t ptr = this->Read<uintptr_t>(address);
            if (!ptr)
                return false;

            std::vector<char> buf(newLen, 0);
            memcpy(buf.data(), value.data(), newLen);
            SIZE_T written = 0;
            if (!Luck_WriteVirtualMemory(Handle, (void*)ptr, buf.data(), (ULONG)newLen, (PULONG)&written))
                return false;
            intptr_t len = (intptr_t)newLen;
            Luck_WriteVirtualMemory(Handle, (void*)(address + 0x18), &len, sizeof(len), nullptr);
            return true;
        }

        inline uintptr_t GetModule(std::string_view MN)
        {
            HMODULE modules[1024];
            DWORD neededmodule;
            if (EnumProcessModules(this->Handle, modules, sizeof(modules), &neededmodule))
            {
                int moduleCount = neededmodule / sizeof(HMODULE);
                for (int i = 0; i < moduleCount; ++i)
                {
                    char buffer[MAX_PATH];
                    if (GetModuleBaseNameA(this->Handle, modules[i], buffer, sizeof(buffer)))
                    {
                        if (!MN.compare(buffer)) {
                            return reinterpret_cast<uintptr_t>(modules[i]);
                        }
                    }
                }
            }
            return 0;
        }
    };

    inline MemoryClass* Memory;
    inline uintptr_t RobloxBase;
}
