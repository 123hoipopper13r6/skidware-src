#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include <spdlog/spdlog.h>
#include <algorithm>
#include <cctype>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

namespace dumper::stages::luau {

    // Ground truth for library identification: every luaL_Reg table in .rdata is
    // identified by which member names it registers, so a table can never be
    // misattributed even though names like 'create' or 'print' repeat across libs.
    struct LibDef {
        const char* lib;
        std::vector<const char*> names;
    };

    static const std::vector<LibDef>& lib_defs() {
        static const std::vector<LibDef> defs = {
            {"base",
             {"assert", "error", "gcinfo", "getfenv", "getmetatable", "newproxy", "next",
              "print", "rawequal", "rawget", "rawlen", "rawset", "select", "setfenv",
              "setmetatable", "tonumber", "tostring", "type", "typeof"}},
            {"bit32",
             {"add", "arshift", "band", "bnot", "bor", "bswap", "btest", "bxor", "clamp",
              "countlz", "countrz", "create", "div", "extract", "fromstring", "ge", "gt",
              "idiv", "le", "lrotate", "lshift", "lt", "max", "min", "mod", "mul", "neg",
              "rem", "replace", "rrotate", "rshift", "sub", "tonumber", "udiv", "uge",
              "ugt", "ule", "ult", "urem"}},
            {"buffer",
             {"copy", "create", "fill", "fromstring", "len", "readbits", "readf32",
              "readf64", "readi16", "readi32", "readi8", "readinteger", "readstring",
              "readu16", "readu32", "readu8", "tostring", "writebits", "writef32",
              "writef64", "writei16", "writei32", "writei8", "writeinteger",
              "writestring", "writeu16", "writeu32", "writeu8"}},
            {"coroutine",
             {"close", "create", "isyieldable", "running", "status", "wrap", "yield"}},
            {"debug",
             {"dumpcodesize", "dumpheap", "dumprefs", "getmemorycategory", "loadmodule",
              "profilebegin", "profileend", "resetmemorycategory", "setmemorycategory",
              "tracerefs"}},
            {"math",
             {"abs", "acos", "asin", "atan", "atan2", "ceil", "clamp", "cos", "cosh",
              "deg", "exp", "floor", "fmod", "frexp", "isfinite", "isinf", "isnan",
              "ldexp", "lerp", "log", "log10", "map", "max", "min", "modf", "noise", "pow",
              "rad", "random", "randomseed", "round", "sign", "sin", "sinh", "sqrt", "tan",
              "tanh"}},
            {"os", {"clock", "date", "difftime", "time"}},
            {"roblox",
             {"collectgarbage", "delay", "ElapsedTime", "getfenv", "loadstring",
              "PluginManager", "print", "printidentity", "require", "setfenv", "settings",
              "spawn", "stats", "tick", "time", "UserSettings", "version", "wait", "warn"}},
            {"string",
             {"byte", "char", "find", "format", "gmatch", "gsub", "len", "lower", "match",
              "pack", "packsize", "rep", "reverse", "split", "sub", "unpack", "upper"}},
            {"table",
             {"clear", "clone", "concat", "create", "find", "foreach", "foreachi",
              "freeze", "getn", "insert", "isfrozen", "maxn", "move", "pack", "remove",
              "sort", "unpack"}},
            {"utf8", {"char", "codepoint", "codes", "len", "offset"}},
            {"vector",
             {"abs", "angle", "ceil", "clamp", "create", "cross", "dot", "floor", "lerp",
              "magnitude", "max", "min", "normalize", "sign"}},
        };
        return defs;
    }

    // 'rawset' -> 'Rawset', 'ElapsedTime' stays 'ElapsedTime'
    static auto pascal_case(const std::string& name) -> std::string {
        std::string out = name;
        if (!out.empty() && std::isalpha(static_cast<unsigned char>(out[0])))
            out[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(out[0])));
        return out;
    }

    struct RegEntry {
        uintptr_t name_ptr;
        uintptr_t func;
        std::string name;
    };

    auto dump() -> bool {
        const auto base = process::g_process.get_module_base();
        if (!base) {
            spdlog::error("Luau: no module base");
            return false;
        }

        const auto rdata_opt = process::g_process.get_section(".rdata");
        const auto text_opt = process::g_process.get_section(".text");
        if (!rdata_opt || !text_opt || rdata_opt->second == 0 || text_opt->second == 0) {
            spdlog::error("Luau: .rdata/.text not found");
            return false;
        }
        const auto& [rdata_start, rdata_size] = *rdata_opt;
        const auto& [text_start, text_size] = *text_opt;

        auto buf = process::Memory::read_bytes(rdata_start, rdata_size);
        if (buf.empty()) {
            spdlog::error("Luau: failed to read .rdata");
            return false;
        }

        const size_t count = buf.size() / sizeof(uintptr_t);
        const uintptr_t* ptrs = reinterpret_cast<const uintptr_t*>(buf.data());
        const uintptr_t rdata_lo = rdata_start;
        const uintptr_t rdata_hi = rdata_start + rdata_size;
        const uintptr_t text_lo = text_start;
        const uintptr_t text_hi = text_start + text_size;

        // pass 1: find runs of consecutive {const char* name; lua_CFunction fn;}
        // pairs - name pointing into .rdata, fn pointing into .text
        struct Candidate {
            size_t start; // qword index of first pair
            size_t len;   // number of pairs
        };
        std::vector<Candidate> candidates;

        size_t run = 0;
        for (size_t i = 0; i + 1 < count; i++) {
            const bool valid = ptrs[i] >= rdata_lo && ptrs[i] < rdata_hi &&
                               ptrs[i + 1] >= text_lo && ptrs[i + 1] < text_hi;
            if (valid) {
                run++;
                i++; // consumed {name, fn}; next slot is the following entry's name
            } else {
                if (run >= 4)
                    candidates.push_back({i - run * 2, run});
                run = 0;
            }
        }

        spdlog::info("Luau: {} candidate luaL_Reg tables in .rdata", candidates.size());

        // pass 2: fetch the registered names and identify each table by name-set
        // match against the known stdlib definitions. Runs can include a few
        // adjacent non-registry pointers, so undecodable entries are skipped
        // rather than rejecting the whole table.
        std::unordered_map<std::string, Candidate> best; // lib -> best table
        std::unordered_map<std::string, double> best_score;
        std::unordered_map<std::string, std::vector<RegEntry>> best_entries;

        for (const auto& cand : candidates) {
            std::vector<RegEntry> entries;
            entries.reserve(cand.len);
            std::optional<size_t> first_idx;
            for (size_t j = 0; j < cand.len && j < 64; j++) {
                const uintptr_t name_ptr = ptrs[cand.start + j * 2];
                const uintptr_t fn = ptrs[cand.start + j * 2 + 1];
                auto name = process::Memory::read_string(name_ptr, 64);
                if (!name || name->empty() || name->size() > 48 ||
                    name->find_first_not_of(
                        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") !=
                        std::string::npos) {
                    continue;
                }
                if (!first_idx)
                    first_idx = j;
                entries.push_back({name_ptr, fn, *name});
            }
            // table address = first decoded entry, not the raw run start which can
            // include adjacent non-registry pointers
            const Candidate trimmed{cand.start + *first_idx * 2, entries.size()};
            if (entries.size() < 4)
                continue;

            std::set<std::string> have;
            for (const auto& e : entries)
                have.insert(e.name);

            for (const auto& def : lib_defs()) {
                size_t inter = 0;
                for (const char* n : def.names)
                    if (have.count(n))
                        inter++;
                const double score =
                    static_cast<double>(inter) / static_cast<double>(def.names.size());
                if (score >= 0.6 && score > best_score[def.lib]) {
                    best_score[def.lib] = score;
                    best[def.lib] = trimmed;
                    best_entries[def.lib] = entries;
                }
            }
        }

        if (best.empty()) {
            spdlog::warn("Luau: no stdlib registry tables identified");
            return false;
        }

        g_dumper.set_namespace_comment(
            "LuauVM", "Luau VM structs (upstream open-source ABI, stable across builds). "
                      "GC walk recipe: get global_State via any lua_State (LuaState::"
                      "lpGlobalState, +0x20), then follow LuauGlobalState::lpAllgcopages - "
                      "a linked list of lua_Page structs (LuaPage layout: listnext/data/"
                      "pagesize/blocksize) whose blocks are every live GC object "
                      "(instances, tables, threads, buffers). bCurrentwhite gives the "
                      "current mark color for distinguishing object header bits.");

        // VM struct constants - these are compile-time layout facts of the vendored
        // upstream Luau VM, not per-build scan results
        g_dumper.add_offset("LuaState", "lpGlobalState", 0x20,
                            "lua_State.globalState (global_State*) - root of the VM; from "
                            "here the whole GC is reachable");
        g_dumper.add_offset("LuaTable", "dwArraysize", 0x8, "Table.sizearray",
                            FieldType::UInt32);
        g_dumper.add_offset("LuaTable", "lpNode", 0x18, "Table.node (hash part)",
                            FieldType::Pointer);
        g_dumper.add_offset("LuaTable", "lpArray", 0x28, "Table.array (array part)",
                            FieldType::Pointer);
        g_dumper.add_offset("LuaTable", "dwLsizenode", 0x5, "Table.lsizenode (log2 node size)",
                            FieldType::UInt8);
        g_dumper.add_offset("LuaPage", "lpListnext", 0x8, "lua_Page list next page",
                            FieldType::Pointer);
        g_dumper.add_offset("LuaPage", "dwPagesize", 0x20, "lua_Page pageSize",
                            FieldType::UInt32);
        g_dumper.add_offset("LuaPage", "dwBlocksize", 0x24, "lua_Page blockSize",
                            FieldType::UInt32);
        g_dumper.add_offset("LuaPage", "dwFreenext", 0x30, "lua_Page freeNext",
                            FieldType::UInt32);
        g_dumper.add_offset("LuaPage", "lpData", 0x40, "lua_Page data start",
                            FieldType::Pointer);
        g_dumper.add_offset("LuauGlobalState", "bCurrentwhite", 0x58,
                            "global_State.currentwhite GC mark bits", FieldType::UInt32);
        g_dumper.add_offset("LuauGlobalState", "lpAllgcopages", 0x2F0,
                            "global_State.allgcopages - head of the lua_Page list holding "
                            "every live GC object; walk pages via LuaPage::lpListnext, "
                            "enumerate blocks via dwPagesize/dwBlocksize/lpData",
                            FieldType::Pointer);

        int total_funcs = 0;
        for (const auto& [lib, cand] : best) {
            const auto& entries = best_entries[lib];
            std::string ns = "Luau";
            ns += pascal_case(lib);

            g_dumper.set_namespace_comment(
                ns, ("'" + lib + "' Luau stdlib - resolved by scanning .rdata for the "
                               "luaL_Reg registration array and matching member names"));

            const uintptr_t table_rva =
                rdata_start + cand.start * sizeof(uintptr_t) - base;
            g_dumper.add_offset(ns, "relRegistryTable", table_rva,
                                "luaL_Reg array registering '" + lib + "', " +
                                    std::to_string(entries.size()) + " entries");

            for (const auto& e : entries) {
                const uintptr_t fn_rva = e.func - base;
                g_dumper.add_offset(ns, "fp" + pascal_case(e.name), fn_rva,
                                    "lua_CFunction body registered as '" + lib + "." +
                                        e.name + "'");
                total_funcs++;
            }
            spdlog::info("Luau: '{}' library resolved - {} functions @ table RVA 0x{:X}",
                         lib, entries.size(), table_rva);
        }

        spdlog::info("Luau: {} libraries, {} function offsets", best.size(), total_funcs);
        return total_funcs > 0;
    }

} // namespace dumper::stages::luau

REGISTER_STAGE(luau)
