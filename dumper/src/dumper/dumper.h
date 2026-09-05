#pragma once
#include <cstdint>
#include <mutex>
#include <optional>
#include <roblox/instance/instance.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace dumper {

    enum class FieldType {
        None = 0,
        Bool,
        UInt8,
        UInt16,
        Int32,
        UInt32,
        Int64,
        UInt64,
        Float,
        Double,
        Pointer,
        Vector2,
        Vector3,
        Color3Float,
        Color3Uint8,
        Matrix3x3,
        Matrix4x4,
        CFrame,
    };

    inline constexpr size_t field_type_size(FieldType t) {
        switch (t) {
            case FieldType::Bool:
            case FieldType::UInt8: return 1;
            case FieldType::UInt16: return 2;
            case FieldType::Int32:
            case FieldType::UInt32:
            case FieldType::Float: return 4;
            case FieldType::Int64:
            case FieldType::UInt64:
            case FieldType::Double:
            case FieldType::Pointer:
            case FieldType::Vector2: return 8;
            case FieldType::Vector3:
            case FieldType::Color3Float: return 12;
            case FieldType::Color3Uint8: return 3;
            case FieldType::Matrix3x3: return 36;
            case FieldType::Matrix4x4: return 64;
            case FieldType::CFrame: return 48;
            default: return 0;
        }
    }

    inline const char* field_type_name(FieldType t) {
        switch (t) {
            case FieldType::Bool: return "bool";
            case FieldType::UInt8: return "uint8_t";
            case FieldType::UInt16: return "uint16_t";
            case FieldType::Int32: return "int32_t";
            case FieldType::UInt32: return "uint32_t";
            case FieldType::Int64: return "int64_t";
            case FieldType::UInt64: return "uint64_t";
            case FieldType::Float: return "float";
            case FieldType::Double: return "double";
            case FieldType::Pointer: return "uintptr_t";
            case FieldType::Vector2: return "Vector2";
            case FieldType::Vector3: return "Vector3";
            case FieldType::Color3Float: return "Color3";
            case FieldType::Color3Uint8: return "U8Color3";
            case FieldType::Matrix3x3: return "Matrix3x3";
            case FieldType::Matrix4x4: return "Matrix4x4";
            case FieldType::CFrame: return "CFrame";
            default: return "";
        }
    }

    struct OffsetEntry {
        std::string name;
        size_t offset;
        std::string comment;
        FieldType type = FieldType::None;
    };

    struct EnumEntry {
        std::string name;
        int value;
    };

    struct FastFlagEntry {
        std::string name;
        uintptr_t address;
        std::string type;      // Bool / Int / Double / String
        std::string value_str; // human-readable current value
    };

    class Dumper {
      public:
        Dumper() = default;
        ~Dumper();

        auto start() -> bool;
        auto add_offset(const std::string& namespace_name, const std::string& offset_name,
                        size_t offset, const std::string& comment = "",
                        FieldType type = FieldType::None) -> void;
        auto add_enum(const std::string& enum_name, const std::string& entry_name, int value)
            -> void;
        auto set_namespace_comment(const std::string& namespace_name, const std::string& comment)
            -> void;
        auto get_offset(const std::string& namespace_name, const std::string& offset_name) const
            -> std::optional<size_t>;

        std::unordered_map<std::string, std::vector<OffsetEntry>> m_offsets;
        std::unordered_map<std::string, std::vector<EnumEntry>> m_enums;
        std::unordered_map<std::string, std::string> m_namespace_comments;
        std::unordered_map<std::string, std::string> m_offset_descriptions; // "Ns::Name" -> what it is
        std::vector<FastFlagEntry> m_fflags;
        // name -> address index over Workspace + ReplicatedStorage trees,
        // built once in start() so stages don't each re-walk the hierarchy
        std::unordered_map<std::string, uintptr_t> m_workspace_index;
        mutable std::mutex m_offset_mutex;
    };

    inline Dumper g_dumper;

    inline uintptr_t g_visual_engine;
    inline uintptr_t g_data_model_addr;

    inline roblox::Instance g_data_model;
    inline std::optional<roblox::Instance> g_lighting;
    inline std::optional<roblox::Instance> g_workspace;
    inline std::optional<roblox::Instance> g_local_player_char;
} // namespace dumper