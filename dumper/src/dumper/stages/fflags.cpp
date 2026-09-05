#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include <Windows.h>
#include <algorithm>
#include <chrono>
#include <cctype>
#include <map>
#include <mutex>
#include <set>
#include <spdlog/spdlog.h>
#include <thread>
#include <unordered_map>
#include <vector>

namespace dumper::stages::fflags {

    // FastFlags live on the HEAP in current clients: a registry object holds a qword
    // pointer to a heap-allocated name string ("FFlag..."/"DF...", NUL-terminated).
    //
    // Empirically derived layout (relative to the name-pointer slot):
    //   +0x05 : constant 1 (registered marker - present for every genuine entry)
    //   +0x0D : current bool value   +0x15 : default bool value   (for FFlag/DFFlag)
    //
    // Non-bool flags (FInt/FString/DF*/SF*) share the registry object but store
    // payloads at different offsets, inferred statistically per type-group.
    // Entries whose type can't be established are emitted as type "Unknown".
    constexpr ptrdiff_t kMarkerRel = 0x05;
    constexpr ptrdiff_t kBoolValueRel = 0x0D;
    constexpr ptrdiff_t kBoolDefaultRel = 0x15;
    constexpr uintptr_t kMaxUserAddress = 0x7FF000000000;
    constexpr size_t kChunk = 0x100000;

    struct Slot {
        std::string name;
        uintptr_t slot; // address of the name-pointer field
    };

    struct ResolvedFlag {
        std::string name;
        uintptr_t address; // absolute address of the value
        std::string type;
        std::string value_str;
    };

    static auto is_flag_char(uint8_t c) -> bool {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ||
               c == '_';
    }

    static auto prefix_len(const uint8_t* p) -> int {
        if (p[0] == 'S' && p[1] == 'F') // SFFlag/SFInt/SFDouble/SFString/SFLog
            return 2;
        if (p[0] == 'D' && p[1] == 'F') // DF*
            return 2;
        if (p[0] == 'F' && p[1] == 'F' && p[2] == 'l' && p[3] == 'a' && p[4] == 'g')
            return 5; // FFlag
        if (p[0] == 'F' && p[1] == 'I' && p[2] == 'n' && p[3] == 't')
            return 4; // FInt
        if (p[0] == 'F' && p[1] == 'S' && p[2] == 't' && p[3] == 'r')
            return 7; // FString
        if (p[0] == 'F' && p[1] == 'D' && p[2] == 'o' && p[3] == 'u')
            return 7; // FDouble
        if (p[0] == 'F' && p[1] == 'L' && p[2] == 'o' && p[3] == 'g')
            return 4; // FLog
        return 0;
    }

    enum class FlagKind { Bool, Int, Double, String, Log, Unknown };

    static auto kind_from_name(const std::string& n) -> FlagKind {
        if (n.rfind("DFFlag", 0) == 0 || n.rfind("FFlag", 0) == 0 || n.rfind("SFFlag", 0) == 0)
            return FlagKind::Bool;
        if (n.rfind("DFInt", 0) == 0 || n.rfind("FInt", 0) == 0 || n.rfind("SFInt", 0) == 0)
            return FlagKind::Int;
        // log flags are plain ints (verbosity levels)
        if (n.rfind("FLog", 0) == 0 || n.rfind("DFLog", 0) == 0 || n.rfind("SFLog", 0) == 0)
            return FlagKind::Int;
        if (n.rfind("DFDouble", 0) == 0 || n.rfind("FDouble", 0) == 0 ||
            n.rfind("SFDouble", 0) == 0)
            return FlagKind::Double;
        if (n.rfind("DFString", 0) == 0 || n.rfind("FString", 0) == 0 ||
            n.rfind("SFString", 0) == 0)
            return FlagKind::String;
        return FlagKind::Unknown;
    }

    static auto committed_regions() -> std::vector<std::pair<uintptr_t, size_t>> {
        std::vector<std::pair<uintptr_t, size_t>> regions;
        MEMORY_BASIC_INFORMATION mbi{};
        uintptr_t current = 0x10000;

        while (current < kMaxUserAddress &&
               VirtualQueryEx(process::g_process.get_handle(), reinterpret_cast<LPCVOID>(current),
                              &mbi, sizeof(mbi)) == sizeof(mbi)) {
            const uintptr_t start = reinterpret_cast<uintptr_t>(mbi.BaseAddress);
            const uintptr_t size = mbi.RegionSize;
            if (size == 0)
                break;

            const bool readable = mbi.State == MEM_COMMIT &&
                                  !(mbi.Protect & PAGE_GUARD) &&
                                  !(mbi.Protect & PAGE_NOACCESS) &&
                                  (mbi.Protect & 0xF0) == 0; // data regions only
            if (readable) {
                regions.emplace_back(start, size);
            }
            current = start + size;
        }

        return regions;
    }

    static auto read_name_at(uintptr_t addr, size_t max_len) -> std::optional<std::string> {
        auto str = process::Memory::read_string(addr, max_len);
        if (!str || str->empty())
            return std::nullopt;
        const auto null_pos = str->find('\0');
        if (null_pos != std::string::npos)
            str->resize(null_pos);
        if (str->size() < 6 || str->size() > 190)
            return std::nullopt;
        return str;
    }

    static auto dump() -> bool {
        const auto begin_time = std::chrono::steady_clock::now();

        spdlog::info("FFlags: walking user-mode memory (parallel)...");

        const auto regions = committed_regions();
        if (regions.empty()) {
            spdlog::error("FFlags: no readable regions");
            return false;
        }

        const unsigned worker_count =
            std::max(2u, std::min(4u, std::thread::hardware_concurrency()));

        // ---- pass 1 (parallel): collect flag name strings -------------------------
        std::mutex names_mutex;
        std::unordered_map<uintptr_t, std::string> addr_to_name;
        {
            std::atomic<size_t> next{0};
            auto worker = [&] {
                std::unordered_map<uintptr_t, std::string> local;
                local.reserve(1 << 13);
                for (;;) {
                    const size_t ri = next.fetch_add(1);
                    if (ri >= regions.size())
                        break;
                    const auto& [start, size] = regions[ri];
                    for (size_t off = 0; off < size; off += kChunk) {
                        const size_t to_read = std::min(kChunk, size - off);
                        const auto buf = process::Memory::read_bytes(start + off, to_read);
                        if (buf.empty())
                            continue;

                        for (size_t i = 0; i + 8 < buf.size(); i++) {
                            const uint8_t c = buf[i];
                            if (c != 'F' && c != 'D' && c != 'S')
                                continue;
                            const int plen = prefix_len(&buf[i]);
                            if (plen == 0 || i + plen >= buf.size())
                                continue;
                            const uint8_t nxt = buf[i + plen];
                            if (!((nxt >= 'A' && nxt <= 'Z') || nxt == '_'))
                                continue;

                            size_t j = i;
                            while (j < buf.size() && is_flag_char(buf[j]))
                                j++;
                            const size_t len = j - i;
                            if (len < 6 || len > 120 || j >= buf.size() || buf[j] != 0)
                                continue;

                            local.emplace(start + off + i,
                                          std::string(reinterpret_cast<const char*>(&buf[i]),
                                                      len));
                            i = j;
                        }
                    }
                }
                std::lock_guard<std::mutex> lock(names_mutex);
                addr_to_name.merge(local);
            };
            std::vector<std::thread> pool;
            for (unsigned t = 0; t < worker_count; t++)
                pool.emplace_back(worker);
            for (auto& t : pool)
                t.join();
        }

        spdlog::info("FFlags: {} candidate flag name strings", addr_to_name.size());

        if (addr_to_name.empty()) {
            spdlog::error("FFlags: no flag names found");
            return false;
        }

        // ---- pass 2 (parallel): find registry slots holding a pointer to a name ---
        std::mutex slots_mutex;
        std::vector<Slot> all_slots;
        {
            std::atomic<size_t> next{0};
            auto worker = [&] {
                std::vector<Slot> local;
                std::set<std::string> local_seen;
                for (;;) {
                    const size_t ri = next.fetch_add(1);
                    if (ri >= regions.size())
                        break;
                    const auto& [start, size] = regions[ri];
                    for (size_t off = 0; off + 8 <= size; off += kChunk) {
                        const size_t span =
                            std::min(kChunk + 8, size - off) & ~(size_t)0x7;
                        const auto buf = process::Memory::read_bytes(start + off, span);
                        if (buf.size() < 8)
                            break;

                        for (size_t i = 0; i + 8 <= buf.size(); i += 8) {
                            uintptr_t q;
                            std::memcpy(&q, &buf[i], 8);
                            const auto it = addr_to_name.find(q);
                            if (it == addr_to_name.end())
                                continue;
                            if (!local_seen.insert(it->second).second)
                                continue;
                            local.push_back({it->second, start + off + i});
                        }
                    }
                }
                std::lock_guard<std::mutex> lock(slots_mutex);
                all_slots.insert(all_slots.end(), local.begin(), local.end());
            };
            std::vector<std::thread> pool;
            for (unsigned t = 0; t < worker_count; t++)
                pool.emplace_back(worker);
            for (auto& t : pool)
                t.join();
        }

        spdlog::info("FFlags: {} unique flag slots", all_slots.size());

        // cross-worker scan can surface the same flag name from duplicate name
        // strings in different heaps - keep the first slot per name
        {
            std::set<std::string> seen;
            std::vector<Slot> unique;
            unique.reserve(all_slots.size());
            for (auto& s : all_slots)
                if (seen.insert(s.name).second)
                    unique.push_back(std::move(s));
            all_slots = std::move(unique);
            spdlog::info("FFlags: {} unique flag names", all_slots.size());
        }

        // ---- pass 3: resolve per-type values --------------------------------------
        std::vector<ResolvedFlag> resolved;
        size_t count_bool_ok = 0, count_bool_rejected = 0;
        size_t count_int_ok = 0, count_double_ok = 0, count_string_ok = 0;
        size_t count_unknown = 0, count_junk = 0;

        // marker byte at +0x05 separates genuine registry entries from junk names
        std::vector<const Slot*> genuine;
        genuine.reserve(all_slots.size());
        for (const auto& s : all_slots) {
            const auto marker = process::Memory::read<uint8_t>(s.slot + kMarkerRel);
            if (marker && *marker == 1)
                genuine.push_back(&s);
            else
                ++count_junk;
        }

        // group by flag kind
        std::map<FlagKind, std::vector<const Slot*>> by_kind;
        for (const auto* s : genuine)
            by_kind[kind_from_name(s->name)].push_back(s);

        std::set<std::string> resolved_names;

        // Bools: validated signature at fixed offsets
        if (auto it = by_kind.find(FlagKind::Bool); it != by_kind.end()) {
            for (const auto* s : it->second) {
                const auto value = process::Memory::read<uint8_t>(s->slot + kBoolValueRel);
                const auto def =
                    process::Memory::read<uint8_t>(s->slot + kBoolDefaultRel);

                if (!value || *value > 1 || !def || *def > 1) {
                    ++count_bool_rejected;
                    continue;
                }

                resolved.push_back({s->name, s->slot + kBoolValueRel, "Bool",
                                    *value ? "true" : "false"});
                resolved_names.insert(s->name);
                ++count_bool_ok;
            }
        }

        // Int/Double/String payload offsets are NOT reliably derivable yet: heap
        // name-pointer slots mix registry entries with pointer-table cells, and a
        // naive delta scan locks onto garbage (e.g. the high half of the name
        // pointer at +0x4). Until per-type ground truth exists, non-bool flags are
        // emitted as Unknown rather than risking fabricated values.

        // everything else that IS a genuine registry entry but whose type/value we
        // couldn't establish gets emitted as Unknown instead of being dropped
        for (const auto* s : genuine) {
            if (resolved_names.count(s->name))
                continue;
            resolved_names.insert(s->name);
            resolved.push_back({s->name, s->slot, "Unknown", ""});
            count_unknown++;
        }

        std::sort(resolved.begin(), resolved.end(),
                  [](const ResolvedFlag& a, const ResolvedFlag& b) { return a.name < b.name; });

        const auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                                    std::chrono::steady_clock::now() - begin_time)
                                    .count();

        spdlog::info(
            "FFlags: {} bool | {} int | {} double | {} string | {} unknown | {} junk | "
            "{} ms with {} workers",
            count_bool_ok, count_int_ok, count_double_ok, count_string_ok, count_unknown,
            count_junk, elapsed_ms, worker_count);

        // handed to the writers: emitted at the bottom of offsets.h/.json/.py/.cs
        g_dumper.m_fflags.clear();
        g_dumper.m_fflags.reserve(resolved.size());
        for (const auto& f : resolved) {
            g_dumper.m_fflags.push_back({f.name, f.address, f.type, f.value_str});
        }

        return true;
    }

} // namespace dumper::stages::fflags

REGISTER_STAGE(fflags)
