#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include "process/helpers/zydis.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include "process/rtti/rtti.h"
#include <spdlog/spdlog.h>
#include <algorithm>
#include <atomic>
#include <chrono>
#include <map>
#include <mutex>
#include <set>
#include <thread>
#include <vector>

namespace dumper::stages::class_props {

    // Discovers instance property offsets dynamically by decoding the reflection
    // metadata: every instance exposes a ClassDescriptor holding a PropertyDescriptor
    // list; each descriptor names a property and points at its GetImpl function.
    // The getter reads the value straight out of the instance, so disassembling it
    // and taking the first [rcx + disp] access yields the live instance offset -
    // no hardcoded tables, works on any build.

    struct FoundProp {
        std::string ns;
        std::string name;
        size_t offset;
    };

    static auto read_u64(uintptr_t addr) -> std::optional<uintptr_t> {
        return process::Memory::read<uintptr_t>(addr);
    }

    static auto in_text(uintptr_t p) -> bool {
        static const auto text = process::g_process.get_section(".text");
        if (!text || text->second == 0)
            return false;
        return process::helpers::is_in_section(p, *text);
    }

    static auto readable_heap(uintptr_t p) -> bool {
        return p >= 0x10000 && p < 0x7FF000000000;
    }

    // reflection names must be clean identifiers - anything else is junk memory
    static auto clean_name(const std::string& s) -> bool {
        if (s.empty() || s.size() > 64)
            return false;
        for (char c : s)
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
                  (c >= '0' && c <= '9') || c == '_'))
                return false;
        return true;
    }

    // Hyperion traps/flips protections on parts of .text; reads can fail. Retry a
    // little, but remember permanently-dead 4KB pages so we never pay twice.
    static auto read_code_bytes(uintptr_t addr, size_t size) -> std::vector<uint8_t> {
        static std::mutex page_mutex;
        static std::set<uintptr_t> dead_pages;

        const uintptr_t lo = addr & ~uintptr_t(0xFFF);
        const uintptr_t hi = (addr + size - 1) & ~uintptr_t(0xFFF);
        {
            std::lock_guard<std::mutex> lock(page_mutex);
            for (uintptr_t pg = lo;; pg += 0x1000) {
                if (dead_pages.count(pg))
                    return {};
                if (pg >= hi)
                    break;
            }
        }

        for (int attempt = 0; attempt < 3; attempt++) {
            auto buf = process::Memory::read_bytes(addr, size);
            if (!buf.empty() &&
                std::any_of(buf.begin(), buf.end(), [](uint8_t b) { return b != 0; }))
                return buf;
            std::this_thread::sleep_for(std::chrono::milliseconds(10 << attempt));
        }

        {
            std::lock_guard<std::mutex> lock(page_mutex);
            for (uintptr_t pg = lo;; pg += 0x1000) {
                dead_pages.insert(pg);
                if (pg >= hi)
                    break;
            }
        }
        return {};
    }

    // replicate of the reflection-list finder used by the descriptor stage
    static auto find_list_by_rtti(uintptr_t class_desc, const char* rtti_needle)
        -> std::optional<size_t> {
        for (size_t off = 0x20; off < 0x100; off += 0x8) {
            const auto list_ptr = read_u64(class_desc + off);
            if (!list_ptr || *list_ptr < 0x10000)
                continue;
            const auto first = read_u64(*list_ptr);
            if (!first || *first < 0x10000)
                continue;
            const auto rtti = process::Rtti::scan_rtti(*first);
            if (rtti && rtti->name.find(rtti_needle) != std::string::npos)
                return off;
        }
        return std::nullopt;
    }

    static auto find_name_off(uintptr_t first_prop) -> std::optional<size_t> {
        for (size_t off = 0; off < 0x40; off += 0x8) {
            const auto p = read_u64(first_prop + off);
            if (!p || *p < 0x10000)
                continue;
            const auto str = process::Memory::read_sso_string(*p);
            if (str && !str->empty() && str->length() < 64)
                return off;
        }
        return std::nullopt;
    }

    // decode a getter: return the first positive [rcx + disp] field displacement
    static auto decode_getter(uintptr_t fn) -> std::optional<size_t> {
        constexpr size_t kWindow = 0x60;
        auto buf = read_code_bytes(fn, kWindow);
        if (buf.size() < kWindow)
            return std::nullopt;

        std::optional<size_t> result;

        process::helpers::zydis::scan_instructions(
            fn, buf,
            [&](uintptr_t, const ZydisDecodedInstruction& instr,
                const ZydisDecodedOperand* ops) -> bool {
                if (instr.mnemonic == ZYDIS_MNEMONIC_CALL)
                    return true; // computed getter

                for (int i = 0; i < instr.operand_count_visible; i++) {
                    const auto& op = ops[i];
                    if (op.type != ZYDIS_OPERAND_TYPE_MEMORY)
                        continue;
                    if (op.mem.base != ZYDIS_REGISTER_RCX ||
                        op.mem.index != ZYDIS_REGISTER_NONE)
                        continue;

                    switch (instr.mnemonic) {
                        case ZYDIS_MNEMONIC_MOV:
                        case ZYDIS_MNEMONIC_MOVZX:
                        case ZYDIS_MNEMONIC_MOVSX:
                        case ZYDIS_MNEMONIC_MOVSXD:
                        case ZYDIS_MNEMONIC_LEA:
                        case ZYDIS_MNEMONIC_MOVSS:
                        case ZYDIS_MNEMONIC_MOVSD:
                        case ZYDIS_MNEMONIC_XOR:
                        case ZYDIS_MNEMONIC_CMP:
                        case ZYDIS_MNEMONIC_TEST:
                            break;
                        default:
                            continue;
                    }

                    // mov reg, [rcx] with no disp: deref of a sub-object pointer -
                    // not useful without full chain tracking; stop here
                    if (!op.mem.disp.has_displacement || op.mem.disp.value <= 0 ||
                        op.mem.disp.value > 0x8000)
                        return true;

                    result = static_cast<size_t>(op.mem.disp.value);
                    return true;
                }
                return false;
            });

        return result;
    }

    // the GetSetImpl adapters are invoked with rcx = instance + containerOffset;
    // that constant appears in the adapter bodies as lea/add/sub rcx, -N.
    static auto scan_container_adjust(uintptr_t fn) -> int64_t {
        constexpr size_t kWindow = 0x50;
        auto buf = read_code_bytes(fn, kWindow);
        if (buf.size() < kWindow)
            return 0;

        int64_t adjust = 0;
        process::helpers::zydis::scan_instructions(
            fn, buf,
            [&](uintptr_t, const ZydisDecodedInstruction& instr,
                const ZydisDecodedOperand* ops) -> bool {
                if (adjust != 0)
                    return true;
                if (instr.mnemonic != ZYDIS_MNEMONIC_ADD &&
                    instr.mnemonic != ZYDIS_MNEMONIC_SUB &&
                    instr.mnemonic != ZYDIS_MNEMONIC_LEA)
                    return false;
                if (ops[0].type != ZYDIS_OPERAND_TYPE_REGISTER ||
                    ops[0].reg.value != ZYDIS_REGISTER_RCX)
                    return false;

                if (instr.mnemonic == ZYDIS_MNEMONIC_LEA) {
                    if (ops[1].type == ZYDIS_OPERAND_TYPE_MEMORY &&
                        ops[1].mem.base == ZYDIS_REGISTER_RCX &&
                        ops[1].mem.disp.has_displacement && ops[1].mem.disp.value < 0 &&
                        ops[1].mem.disp.value > -0x10000) {
                        adjust = -ops[1].mem.disp.value;
                        return true;
                    }
                    return false;
                }

                if (ops[1].type == ZYDIS_OPERAND_TYPE_IMMEDIATE &&
                    ops[1].imm.value.s != 0) {
                    const int64_t v =
                        instr.mnemonic == ZYDIS_MNEMONIC_ADD ? -ops[1].imm.value.s
                                                             : ops[1].imm.value.s;
                    if (v > 0 && v < 0x10000) {
                        adjust = v;
                        return true;
                    }
                }
                return false;
            });
        return adjust;
    }

    // locate the GetSetImpl object behind a property descriptor, decode its getter
    // and add the container adjustment so the result is instance-relative
    static auto analyze_prop(const std::string& cls, const std::string& pname,
                             uintptr_t prop_desc) -> std::optional<size_t> {
        const bool trace =
            cls == "Humanoid" &&
            (pname == "WalkSpeed" || pname == "Health" || pname == "Health_XML" ||
             pname == "GetChildren" || pname == "ApplyDescription");
        std::optional<size_t> impl_off;
        std::vector<uintptr_t> direct_fns;

        for (size_t off = 0x10; off < 0xC0; off += 0x8) {
            const auto p = read_u64(prop_desc + off);
            if (!p)
                continue;

            if (*p >= 0x10000 && in_text(*p)) {
                direct_fns.push_back(*p);
                continue;
            }

            if (*p >= 0x10000 && readable_heap(*p)) {
                const auto rtti = process::Rtti::scan_rtti(*p);
                if (rtti &&
                    (rtti->name.find("GetSetImpl") != std::string::npos ||
                     rtti->name.find("GetImpl") != std::string::npos)) {
                    impl_off = off;
                    if (trace)
                        spdlog::info("CP TRACE {} impl @+{:#x} rtti={}", pname, off,
                                     rtti->name.substr(0, 44));
                    break;
                }
            }
        }

        if (!impl_off)
            return std::nullopt;

        const auto impl = read_u64(prop_desc + *impl_off);
        if (!impl || !readable_heap(*impl))
            return std::nullopt;

        std::vector<uintptr_t> fns;
        for (size_t inner = 0x8; inner < 0x80; inner += 0x8) {
            const auto fp = read_u64(*impl + inner);
            if (!fp || !in_text(*fp))
                continue;
            fns.push_back(*fp);
        }
        if (fns.empty())
            return std::nullopt;

        int64_t adjust = 0;
        for (const auto fn : fns) {
            const int64_t a = scan_container_adjust(fn);
            if (trace)
                spdlog::info("CP TRACE {} fn {:#x} adjust={:#x}", pname, fn, a);
            adjust = std::max(adjust, a);
        }

        for (const auto fn : fns) {
            if (auto d = decode_getter(fn)) {
                const size_t inst_off =
                    static_cast<size_t>(static_cast<int64_t>(*d) + adjust);
                if (trace)
                    spdlog::info("CP TRACE {} chosen fn {:#x} disp={:#x} -> {:#x}",
                                 pname, fn, *d, inst_off);
                if (inst_off > 0x8000)
                    return std::nullopt;
                return inst_off;
            }
        }
        return std::nullopt;
    }

    auto dump() -> bool {
        const auto begin = std::chrono::steady_clock::now();

        const auto cd_off = dumper::g_dumper.get_offset("Instance", "ClassDescriptor");
        const auto cname_off = dumper::g_dumper.get_offset("ClassDescriptor", "ClassName");
        if (!cd_off || !cname_off) {
            spdlog::error("ClassProps: Instance::ClassDescriptor / ClassName unavailable");
            return false;
        }

        if (dumper::g_dumper.m_workspace_index.empty()) {
            spdlog::error("ClassProps: no instances indexed");
            return false;
        }

        // anchor reflection layout on the workspace's own class descriptor
        uintptr_t anchor_inst = 0;
        for (const auto& [_, addr] : dumper::g_dumper.m_workspace_index) {
            anchor_inst = addr;
            break;
        }
        const auto anchor_cd = read_u64(anchor_inst + *cd_off);
        if (!anchor_cd || *anchor_cd < 0x10000) {
            spdlog::error("ClassProps: failed to read anchor ClassDescriptor");
            return false;
        }

        const auto prop_list_off = find_list_by_rtti(*anchor_cd, "PropDescriptor");
        if (!prop_list_off) {
            spdlog::error("ClassProps: PropDescriptor list not found");
            return false;
        }
        const auto list_head = read_u64(*anchor_cd + *prop_list_off);
        if (!list_head || !*list_head) {
            spdlog::error("ClassProps: empty property list");
            return false;
        }
        const auto first_prop = read_u64(*list_head);
        if (!first_prop || !*first_prop) {
            spdlog::error("ClassProps: null first property");
            return false;
        }
        const auto pname_off = find_name_off(*first_prop);
        if (!pname_off) {
            spdlog::error("ClassProps: descriptor name offset not found");
            return false;
        }

        // unique class descriptors across every indexed instance (+ DataModel)
        std::map<uintptr_t, std::string> classes;
        {
            std::set<uintptr_t> seen_inst;
            auto add_inst = [&](uintptr_t inst) {
                if (!inst || seen_inst.count(inst))
                    return;
                seen_inst.insert(inst);
                const auto cd = read_u64(inst + *cd_off);
                if (!cd || *cd < 0x10000 || classes.count(*cd))
                    return;
                const auto nptr = read_u64(*cd + *cname_off);
                if (!nptr || *nptr < 0x10000)
                    return;
                const auto cn = process::Memory::read_string(*nptr, 64);
                if (cn && clean_name(*cn))
                    classes[*cd] = *cn;
            };
            for (const auto& [_, addr] : dumper::g_dumper.m_workspace_index)
                add_inst(addr);
            add_inst(dumper::g_data_model_addr);
        }
        spdlog::info("ClassProps: {} distinct classes to analyze", classes.size());

        // parallel decode across classes
        std::mutex merge_mutex;
        std::vector<FoundProp> found;
        std::atomic<size_t> next{0};
        std::atomic<size_t> done{0};

        std::vector<std::pair<uintptr_t, std::string>> work(classes.begin(), classes.end());

        auto worker = [&] {
            for (;;) {
                const size_t i = next.fetch_add(1);
                if (i >= work.size())
                    break;
                const auto& [cd, cls] = work[i];

                // per-class: walk the property descriptor linked list
                const auto head = read_u64(cd + *prop_list_off);
                if (!head || !*head)
                    continue;

                std::vector<FoundProp> local;
                std::set<std::string> seen_names;
                uintptr_t node = *head;
                for (int n = 0; n < 600; n++) {
                    const auto entry = read_u64(node);
                    if (!entry || !*entry)
                        break;
                    node += 0x10;

                    const auto nptr = read_u64(*entry + *pname_off);
                    if (!nptr || *nptr < 0x10000)
                        continue;
                    const auto pname = process::Memory::read_sso_string(*nptr);
                    if (!pname || !clean_name(*pname))
                        continue;
                    if (!seen_names.insert(*pname).second)
                        continue;

                    const bool trace = (cls == "Humanoid") &&
                                       (*pname == "WalkSpeed" || *pname == "Health" ||
                                        *pname == "GetChildren" ||
                                        *pname == "ApplyDescription");
                    if (auto off = analyze_prop(cls, *pname, *entry))
                        local.push_back({cls, *pname, *off});
                }

                if (!local.empty()) {
                    std::lock_guard<std::mutex> lock(merge_mutex);
                    found.insert(found.end(), local.begin(), local.end());
                }

                const size_t finished = done.fetch_add(1) + 1;
                if ((finished % 40) == 0)
                    spdlog::info("ClassProps: {}/{} classes...", finished, work.size());
            }
        };

        const unsigned workers = std::max(2u, std::min(4u, std::thread::hardware_concurrency()));
        std::vector<std::thread> pool;
        for (unsigned t = 0; t < workers; t++)
            pool.emplace_back(worker);
        for (auto& t : pool)
            t.join();

        // merge into the dumper quietly (one lock, no per-entry logging)
        {
            std::lock_guard<std::mutex> lock(dumper::g_dumper.m_offset_mutex);
            size_t added = 0;
            for (const auto& f : found) {
                auto& vec = dumper::g_dumper.m_offsets[f.ns];

                // getter-decoded displacements can be container-relative (wrong by
                // a per-class delta). If a scanned/verified stage already covers
                // this class, never compete with it - skip the namespace entirely.
                bool covered = false;
                for (const auto& existing : vec)
                    if (existing.comment != "decoded from property getter") {
                        covered = true;
                        break;
                    }
                if (covered)
                    continue;

                bool dup = false;
                for (const auto& existing : vec)
                    if (existing.name == f.name) {
                        dup = true;
                        break;
                    }
                if (dup)
                    continue;
                vec.push_back({f.name, f.offset, "decoded from property getter",
                               FieldType::None});
                dumper::g_dumper.m_offset_descriptions.emplace(
                    f.ns + "::" + f.name,
                    "instance offset recovered by disassembling this property's "
                    "GetImpl getter");
                ++added;
            }
            spdlog::info("ClassProps: {} property offsets decoded across {} namespaces",
                         added, classes.size());
        }

        const auto ms =
            std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - begin)
                .count();
        spdlog::info("ClassProps: finished in {} ms", ms);
        return !found.empty();
    }

} // namespace dumper::stages::class_props

REGISTER_STAGE(class_props)
