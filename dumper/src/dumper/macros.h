#include "dumper.h"
#include "process/helpers/helpers.h"
#include <format>
#include <spdlog/spdlog.h>
#include <string>

#define FIND_AND_ADD_OFFSET(base_addr, namespace_name, type, name, target, max, align, ftype)      \
    do {                                                                                           \
        const auto offset = process::helpers::find_offset<type>(base_addr, target, max, align);    \
        if (!offset) {                                                                             \
            spdlog::error("Failed to find {}::{} (searched {} bytes from base 0x{:X} for {})",     \
                          #namespace_name, #name, static_cast<size_t>(max),                        \
                          static_cast<uintptr_t>(base_addr), #target);                             \
            return false;                                                                          \
        }                                                                                          \
        const std::string __cmt =                                                                  \
            std::string("scanned for ") + #target + " = " + std::format("{}", target);             \
        dumper::g_dumper.add_offset(#namespace_name, #name, *offset, __cmt, ftype);                \
    } while (0)

// same, but records a derivation-path comment (e.g. "DataModel>Workspace>World")
#define FIND_AND_ADD_OFFSET_C(base_addr, namespace_name, type, name, target, max, align, ftype,    \
                              path_comment)                                                        \
    do {                                                                                           \
        const auto offset = process::helpers::find_offset<type>(base_addr, target, max, align);    \
        if (!offset) {                                                                             \
            spdlog::error("Failed to find {}::{} (searched {} bytes from base 0x{:X} for {}, "     \
                          "path {})",                                                             \
                          #namespace_name, #name, static_cast<size_t>(max),                        \
                          static_cast<uintptr_t>(base_addr), #target, path_comment);               \
            return false;                                                                          \
        }                                                                                          \
        const std::string __cmt = std::string(path_comment) + " | scanned for " + #target +        \
                                 " = " + std::format("{}", target);                                \
        dumper::g_dumper.add_offset(#namespace_name, #name, *offset, __cmt, ftype);                \
    } while (0)
