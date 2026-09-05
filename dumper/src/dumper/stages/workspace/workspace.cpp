#include "workspace.h"
#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/macros.h"
#include <process/helpers/helpers.h>
#include <process/rtti/rtti.h>
#include <process/xref/xref.h>
#include <Zydis/Zydis.h>
#include <algorithm>
#include <cmath>
#include <optional>
#include <set>
#include <unordered_map>
#include <spdlog/spdlog.h>

namespace dumper::stages::workspace {

    namespace {

        struct DecodedInsn {
            uintptr_t addr;
            ZydisDecodedInstruction insn;
            ZydisDecodedOperand ops[ZYDIS_MAX_OPERAND_COUNT];
        };

        // linear disassembly of a code buffer
        auto walk_code(uintptr_t start, const std::vector<uint8_t>& code,
                       const std::function<void(const DecodedInsn&)>& cb) -> void {
            ZydisDecoder decoder;
            if (!ZYAN_SUCCESS(
                    ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64)))
                return;

            size_t off = 0;
            while (off < code.size()) {
                DecodedInsn d{};
                d.addr = start + off;
                if (!ZYAN_SUCCESS(ZydisDecoderDecodeFull(&decoder, code.data() + off,
                                                         code.size() - off, &d.insn, d.ops))) {
                    off++;
                    continue;
                }
                cb(d);
                off += d.insn.length;
            }
        }

        auto is_gpr64(ZydisRegister reg) -> bool {
            return ZydisRegisterGetClass(reg) == ZYDIS_REGCLASS_GPR64;
        }

        auto is_xmm(ZydisRegister reg) -> bool {
            return ZydisRegisterGetClass(reg) == ZYDIS_REGCLASS_XMM;
        }

        // Chunked scanner for `lea rdx, [rip+disp32]` (48 8D 15 ...) references to
        // target. Xref::scan reads whole .text in one call which fails on the
        // multi-MB Roblox image, so we walk 1MB chunks with overlap instead.
        auto find_lea_rip_refs(uintptr_t target) -> std::vector<uintptr_t> {
            std::vector<uintptr_t> refs;

            auto section = process::g_process.get_section(".text");
            if (!section)
                return refs;

            const uintptr_t start = section->first;
            const uintptr_t end = start + section->second;
            spdlog::info("step cluster: scanning .text 0x{:X}-0x{:X} for lea rip refs",
                         start, end);

            // The image is split into small committed regions with gaps; fixed-size
            // chunks would straddle boundaries and short-read. Walk MBI regions.
            MEMORY_BASIC_INFORMATION mbi{};
            uintptr_t pos = start;
            while (pos < end &&
                   VirtualQueryEx(process::g_process.get_handle(),
                                  reinterpret_cast<LPCVOID>(pos), &mbi, sizeof(mbi)) ==
                       sizeof(mbi)) {
                const uintptr_t region_start = reinterpret_cast<uintptr_t>(mbi.BaseAddress);
                const uintptr_t region_end =
                    std::min(region_start + mbi.RegionSize, end);
                pos = region_end;

                if (mbi.State != MEM_COMMIT || (mbi.Protect & PAGE_GUARD) ||
                    (mbi.Protect & PAGE_NOACCESS))
                    continue;

                auto buf =
                    process::Memory::read_bytes(region_start, region_end - region_start);
                if (buf.size() < 8)
                    continue;

                for (size_t i = 1; i + 7 <= buf.size(); i++) {
                    // lea r64, [rip+disp32]: REX.W[.B] 8D modrm(mod=00,rm=101), len 7
                    // lea r32, [rip+disp32]:      8D     modrm(mod=00,rm=101), len 6
                    const uint8_t b0 = buf[i];
                    const uint8_t rex = buf[i - 1];

                    if ((rex & 0xF8) == 0x48 && b0 == 0x8D &&
                        (buf[i + 1] & 0xC7) == 0x05) {
                        // REX.W lea: rex at i-1, opcode 8D at i, modrm at i+1
                        int32_t disp = 0;
                        std::memcpy(&disp, &buf[i + 2], sizeof(disp));
                        const uintptr_t insn = region_start + i - 1;
                        if (insn + 7 + static_cast<uintptr_t>(disp) == target)
                            refs.push_back(insn);
                        continue;
                    }
                    if (b0 == 0x8D && (buf[i + 1] & 0xC7) == 0x05 &&
                        !((rex & 0xF0) == 0x40)) {
                        // non-REX lea r32: opcode at i, modrm at i+1
                        int32_t disp = 0;
                        std::memcpy(&disp, &buf[i + 1], sizeof(disp));
                        const uintptr_t insn = region_start + i;
                        if (insn + 6 + static_cast<uintptr_t>(disp) == target)
                            refs.push_back(insn);
                    }
                }
            }
            return refs;
        }

        // Resolve the World step timing cluster by decoding
        // RBX::World::getUpdateExpectedStepDelta, the only function touching it.
        //
        // Anchor: its unique FLog format string. Offsets shift between builds, so
        // they are extracted per session from the instruction displacements and
        // validated against the invariant layout {ts_frame, ts_frame+8, +0x10 int,
        // +0x18 accum} observed across versions.
        //
        //   movsd xmm, [this+F] ; subsd xmm, [this+S]  -> frame/send timestamps
        //   mov r32, [this+N]                          -> lastNumWorldSteps (N == F+0x10)
        //   lea r64, [this+A]                          -> worldStepOffset  (A == F+0x18)
        //   mov r32, [this+W]                          -> worldStepId      (first int read)
        auto resolve_step_cluster_via_xref(uintptr_t world_addr) ->
            std::optional<std::array<size_t, 6>> {

            // all unique strings emitted inside getUpdateExpectedStepDelta
            static const char* ANCHORS[] = {
                "[FLog::WorldStepsBehind] DELTA",
                "[FLog::WorldStepsBehind] Expected",
                "[FLog::WorldStepsBehindG] Number of WorldSteps",
                "getWorldStepId changed %d %d",
            };

            for (const auto anchor : ANCHORS) {
                auto strs = process::Memory::scan_string(anchor);
                if (strs.empty()) {
                    spdlog::info("step cluster: anchor '{}' not found", anchor);
                    continue;
                }
                spdlog::info("step cluster: '{}' -> {} string hits", anchor, strs.size());

                for (const auto str_addr : strs) {
                    auto refs = find_lea_rip_refs(str_addr);
                    spdlog::info("step cluster: str @0x{:X} -> {} lea refs", str_addr,
                                 refs.size());
                    if (refs.empty())
                        continue;

                for (const auto ref : refs) {
                    // window covering surrounding code: the live build may inline,
                    // so the field accesses need not sit right before this ref
                    constexpr uintptr_t WIN_BACK = 0x400;
                    constexpr uintptr_t WIN_FWD = 0x100;
                    const uintptr_t win_start =
                        ref > WIN_BACK ? ref - WIN_BACK : 0;
                    auto code =
                        process::Memory::read_bytes(win_start, WIN_BACK + WIN_FWD);
                    if (code.size() < 0x40)
                        continue;

                    std::optional<size_t> frame_ts, send_ts, accum, last_num, step_id;

                    // pass 1: locate the movsd/subsd timestamp pair
                    std::optional<DecodedInsn> pending_movsd;
                    walk_code(win_start, code, [&](const DecodedInsn& d) {
                        const auto& i = d.insn;
                        const auto& o = d.ops;

                        if (pending_movsd && i.mnemonic == ZYDIS_MNEMONIC_SUBSD &&
                            o[0].type == ZYDIS_OPERAND_TYPE_REGISTER &&
                            o[1].type == ZYDIS_OPERAND_TYPE_MEMORY &&
                            o[1].mem.base != ZYDIS_REGISTER_RIP &&
                            o[1].mem.base ==
                                pending_movsd->ops[1].mem.base &&
                            o[1].mem.disp.has_displacement &&
                            pending_movsd->ops[1].mem.disp.has_displacement) {
                            frame_ts = static_cast<size_t>(
                                pending_movsd->ops[1].mem.disp.value);
                            send_ts =
                                static_cast<size_t>(o[1].mem.disp.value);
                            pending_movsd.reset();
                            return;
                        }
                        if (i.mnemonic == ZYDIS_MNEMONIC_MOVSD &&
                            o[0].type == ZYDIS_OPERAND_TYPE_REGISTER &&
                            is_xmm(o[0].reg.value) &&
                            o[1].type == ZYDIS_OPERAND_TYPE_MEMORY &&
                            o[1].mem.base != ZYDIS_REGISTER_RIP &&
                            o[1].mem.base != ZYDIS_REGISTER_NONE &&
                            o[1].mem.disp.has_displacement) {
                            pending_movsd = d;
                            return;
                        }
                    });

                    if (!frame_ts || !send_ts || *send_ts != *frame_ts + 0x8) {
                        spdlog::info("step cluster: no movsd/subsd ts pair near ref 0x{:X}",
                                     ref);
                        continue;
                    }

                    // pass 2: displacement census + ordered int reads
                    // (live builds vary in how they touch lastNum/accum; adjacency
                    //  to the confirmed timestamp pair is the actual validator)
                    std::vector<size_t> int_reads;
                    std::set<size_t> disps;
                    walk_code(win_start, code, [&](const DecodedInsn& d) {
                        const auto& i = d.insn;
                        const auto& o = d.ops;

                        if (i.mnemonic == ZYDIS_MNEMONIC_MOV &&
                            o[0].type == ZYDIS_OPERAND_TYPE_REGISTER &&
                            ZydisRegisterGetClass(o[0].reg.value) ==
                                ZYDIS_REGCLASS_GPR32 &&
                            o[1].type == ZYDIS_OPERAND_TYPE_MEMORY &&
                            o[1].mem.base != ZYDIS_REGISTER_RIP &&
                            o[1].mem.base != ZYDIS_REGISTER_NONE &&
                            o[1].mem.disp.has_displacement) {
                            const auto dv =
                                static_cast<size_t>(o[1].mem.disp.value);
                            int_reads.push_back(dv);
                            disps.insert(dv);
                        }

                        for (int k = 0; k < i.operand_count_visible; k++) {
                            if (o[k].type == ZYDIS_OPERAND_TYPE_MEMORY &&
                                o[k].mem.base != ZYDIS_REGISTER_RIP &&
                                o[k].mem.base != ZYDIS_REGISTER_NONE &&
                                o[k].mem.disp.has_displacement) {
                                disps.insert(
                                    static_cast<size_t>(o[k].mem.disp.value));
                            }
                        }
                    });

                    // validation: cluster members must appear around the ts pair
                    bool num_ok = disps.count(*frame_ts + 0x10) > 0;
                    if (num_ok)
                        last_num = *frame_ts + 0x10;

                    bool accum_ok = disps.count(*frame_ts + 0x18) > 0;
                    if (accum_ok)
                        accum = *frame_ts + 0x18;

                    // worldStepId = earliest int read that isn't part of the cluster
                    for (const auto r : int_reads) {
                        if (r != last_num && r < *frame_ts) {
                            step_id = r;
                            break;
                        }
                    }

                    if (!accum_ok || !num_ok || !step_id) {
                        spdlog::warn("step cluster: partial decode near ref 0x{:X} "
                                     "(frame=0x{:X} num_ok={} accum_ok={} id={})",
                                     ref, *frame_ts, num_ok, accum_ok,
                                     step_id ? *step_id : 0);
                        continue;
                    }

                    spdlog::info("step cluster resolved via xref @0x{:X}: stepId=0x{:X} "
                                 "frameTs=0x{:X} sendTs=0x{:X} lastNum=0x{:X} accum=0x{:X}",
                                 ref, *step_id, *frame_ts, *send_ts, *last_num, *accum);

                    // pass 3: find fWorldStepsPerSecond via instruction pattern.
                    // sps is the only field loaded as float then converted to double:
                    //   movss xmmN, [reg+D]  →  cvtps2pd xmmN, xmmN  →  mulsd xmmN, ...
                    // Track last xmm writer per register to link movss→cvtps2pd.
                    std::optional<size_t> sps_disp;
                    struct XmWrite { uintptr_t addr; size_t disp; };
                    std::unordered_map<uint8_t, XmWrite> xmm_last_write;
                    std::vector<DecodedInsn> all_insns;
                    walk_code(win_start, code, [&](const DecodedInsn& d) {
                        all_insns.push_back(d);
                        const auto& i = d.insn;
                        const auto& o = d.ops;

                        // track movss xmmN, [reg+D] (float memory load)
                        if (i.mnemonic == ZYDIS_MNEMONIC_MOVSS &&
                            o[0].type == ZYDIS_OPERAND_TYPE_REGISTER &&
                            is_xmm(o[0].reg.value) &&
                            o[1].type == ZYDIS_OPERAND_TYPE_MEMORY &&
                            o[1].mem.base != ZYDIS_REGISTER_RIP &&
                            o[1].mem.base != ZYDIS_REGISTER_NONE &&
                            o[1].mem.disp.has_displacement) {
                            xmm_last_write[o[0].reg.value] = {
                                d.addr, static_cast<size_t>(o[1].mem.disp.value)};
                        }
                        // also track movd xmmN, [reg+D] (int32→float path)
                        if (i.mnemonic == ZYDIS_MNEMONIC_MOVD &&
                            o[0].type == ZYDIS_OPERAND_TYPE_REGISTER &&
                            is_xmm(o[0].reg.value) &&
                            o[1].type == ZYDIS_OPERAND_TYPE_MEMORY &&
                            o[1].mem.base != ZYDIS_REGISTER_RIP &&
                            o[1].mem.base != ZYDIS_REGISTER_NONE &&
                            o[1].mem.disp.has_displacement) {
                            xmm_last_write[o[0].reg.value] = {
                                d.addr, static_cast<size_t>(o[1].mem.disp.value)};
                        }
                    });

                    // now scan decoded insns for cvtps2pd xmmN, xmmN
                    for (const auto& d : all_insns) {
                        if (d.insn.mnemonic != ZYDIS_MNEMONIC_CVTPS2PD)
                            continue;
                        if (d.ops[0].type != ZYDIS_OPERAND_TYPE_REGISTER ||
                            d.ops[1].type != ZYDIS_OPERAND_TYPE_REGISTER)
                            continue;
                        const auto reg = d.ops[0].reg.value;
                        auto it = xmm_last_write.find(reg);
                        if (it == xmm_last_write.end())
                            continue;
                        const auto candidate = it->second.disp;
                        // must not be a cluster offset
                        if (candidate == *step_id || candidate == *frame_ts ||
                            candidate == *send_ts || candidate == *last_num ||
                            candidate == *accum)
                            continue;
                        // validate: read as float, must be plausible Hz
                        auto val = process::Memory::read<float>(
                            world_addr + candidate);
                        if (val && *val >= 10.0f && *val <= 1000.0f) {
                            spdlog::info("fWorldStepsPerSecond found via pattern "
                                         "@0x{:X}: disp=0x{:X} ({} Hz)",
                                         d.addr, candidate, *val);
                            sps_disp = candidate;
                            break;
                        }
                    }

                    return std::array<size_t, 6>{
                        *step_id, *frame_ts, *send_ts, *last_num, *accum,
                        sps_disp.value_or(0)};
                }
                }
            }

            spdlog::warn("step cluster: no valid code xref decoded");
            return std::nullopt;
        }

        // Fallback: raw data-pattern scan for {double ts, double ts-8, u32, double}
        auto scan_step_cluster_datapattern(uintptr_t world_addr) ->
            std::optional<std::array<size_t, 6>> {
            constexpr double MAX_ACCUMULATOR = 1000.0;
            constexpr size_t MAX_STEP_COUNT = 100000000;

            for (size_t off = 0; off + 0x20 <= 0x4000; off += 0x8) {
                auto ts_a = process::Memory::read<double>(world_addr + off);
                auto ts_b = process::Memory::read<double>(world_addr + off + 0x8);
                if (!ts_a || !ts_b)
                    continue;
                if (std::isnan(*ts_a) || std::isinf(*ts_a))
                    continue;
                if (std::isnan(*ts_b) || std::isinf(*ts_b))
                    continue;
                if (*ts_a < 1.0 || *ts_b < 0.0)
                    continue;
                if (*ts_a < *ts_b)
                    continue;
                if (*ts_a - *ts_b > 30.0)
                    continue;

                auto step_count = process::Memory::read<uint32_t>(world_addr + off + 0x10);
                if (!step_count || *step_count == 0 || *step_count >= MAX_STEP_COUNT)
                    continue;

                auto accumulator = process::Memory::read<double>(world_addr + off + 0x18);
                if (!accumulator)
                    continue;
                if (std::isnan(*accumulator) || std::isinf(*accumulator))
                    continue;
                if (std::abs(*accumulator) > MAX_ACCUMULATOR)
                    continue;

                spdlog::info("step cluster datapattern hit @0x{:X}: ts_a={:.3f} "
                             "ts_b={:.3f} n={} acc={:.6f}",
                             off, *ts_a, *ts_b, *step_count, *accumulator);
                return std::array<size_t, 6>{0, off, off + 0x8, off + 0x10, off + 0x18, 0};
            }
            return std::nullopt;
        }

    } // namespace

    auto dump() -> bool {
        const auto camera = process::Rtti::find(dumper::g_workspace->get_address(), "Camera@RBX");
        if (!camera) {
            spdlog::error("Failed to find CurrentCamera offset in Workspace");
            return false;
        }

        dumper::g_dumper.add_offset("Workspace", "CurrentCamera", *camera,
                                    "DataModel>Workspace>Camera child", FieldType::Pointer);

        float expected_gravity = 196.2f;
        if (const auto workspace_info = bridge::g_bridge.read_workspace_information();
            workspace_info && workspace_info->gravity > 0.0f) {
            expected_gravity = workspace_info->gravity;
        }

        FIND_AND_ADD_OFFSET_C(dumper::g_workspace->get_address(), Workspace, float,
                              ReadOnlyGravity, expected_gravity, 0x1000, 0x4, FieldType::Float,
                              "DataModel>Workspace");

        const auto result = process::helpers::find_offset_in_pointer<float>(
            dumper::g_workspace->get_address(), expected_gravity, 0x800, 0x400, 0x8, 0x4);

        if (!result) {
            spdlog::error("Failed to dump World and World Gravity in Workspace");
            return false;
        }

        const auto [world, gravity] = *result;
        g_dumper.add_offset("Workspace", "World", world,
                            "DataModel>Workspace>World (via gravity float)", FieldType::Pointer);
        g_dumper.add_offset("World", "Gravity", gravity, "DataModel>Workspace>World",
                            FieldType::Float);

        const auto world_addr =
            process::Memory::read<uintptr_t>(g_workspace->get_address() + world);

        if (!world_addr) {
            spdlog::error("Failed to read World offset in Workspace");
            return false;
        }

        // World step timing cluster (drives time manipulation):
        //   int    dwWorldStepid            monotonically incrementing step counter
        //   double dLastFrameTimeStamp      timestamp of last frame
        //   double dLastSendTimeStamp       timestamp of last send (<= frame ts)
        //   int    dwLastNumberOfWorldStep  step count at last send
        //   double dWorldStepDt             accumulated step drift (write target)
        //
        // Primary: decode RBX::World::getUpdateExpectedStepDelta via string xref.
        // Fallback: raw data-pattern scan of the World instance.
        {
            std::optional<std::array<size_t, 6>> cluster =
                resolve_step_cluster_via_xref(*world_addr);

            if (!cluster)
                cluster = scan_step_cluster_datapattern(*world_addr);

            if (!cluster) {
                spdlog::warn("Failed to find World step timing cluster");
            } else {
                const auto [step_id, frame_ts, send_ts, last_num, accum, sps] = *cluster;

                if (step_id) {
                    g_dumper.add_offset("World", "dwWorldStepid", step_id,
                                        "world step counter: dword, monotonically incrementing",
                                        FieldType::UInt32);
                }
                g_dumper.add_offset("World", "dLastFrameTimeStamp", frame_ts,
                                    "world step timing: double, last frame timestamp",
                                    FieldType::Double);
                g_dumper.add_offset("World", "dLastSendTimeStamp", send_ts,
                                    "world step timing: double, last send timestamp",
                                    FieldType::Double);
                g_dumper.add_offset("World", "dwLastNumberOfWorldStep", last_num,
                                    "world step timing: dword, step count at last send",
                                    FieldType::UInt32);
                g_dumper.add_offset("World", "dWorldStepDt", accum,
                                    "world step timing: double, accumulated step drift "
                                    "(write to manipulate sim speed)",
                                    FieldType::Double);

                if (sps) {
                    g_dumper.add_offset("World", "fWorldStepsPerSecond", sps,
                                        "simulation steps-per-second scalar "
                                        "(write to change sim speed)",
                                        FieldType::Float);
                } else {
                    spdlog::warn("fWorldStepsPerSecond not found via instruction "
                                 "pattern; sps field may have moved");
                }
            }
        }

        std::optional<size_t> primitives_offset;

        for (size_t offset = 0; offset < 0x1000; offset += 0x8) {
            const auto array_ptr = process::Memory::read<uintptr_t>(*world_addr + offset);
            if (!array_ptr || *array_ptr == 0)
                continue;

            const auto check_slot = [&](size_t slot) -> bool {
                const auto primitive_ptr = process::Memory::read<uintptr_t>(*array_ptr + slot);
                if (!primitive_ptr || *primitive_ptr == 0)
                    return false;

                const auto names = process::Rtti::get_all_names(*primitive_ptr);
                return std::ranges::any_of(names, [](const auto& name) {
                    return name.find("Primitive@RBX") != std::string::npos;
                });
            };

            if (check_slot(0x0) && check_slot(0x8)) {
                primitives_offset = offset;
                break;
            }
        }

        if (!primitives_offset) {
            spdlog::error("Failed to find Primitives offset in World");
            return false;
        }

        g_dumper.add_offset("World", "Primitives", *primitives_offset, "", FieldType::Pointer);

        for (size_t offset = 0; offset < 0x400; offset += 0x8) {
            const auto air_props = process::Memory::read<uintptr_t>(*world_addr + offset);

            const auto global_wind_offset = process::helpers::find_vec_offset<glm::vec3>(
                *air_props, glm::vec3(100.2f, 102.f, 105.4f), 0x200);

            if (global_wind_offset) {
                g_dumper.add_offset("World", "AirProperties", offset, "", FieldType::Pointer);
                g_dumper.add_offset("AirProperties", "GlobalWind", *global_wind_offset, "",
                                    FieldType::Vector3);
                FIND_AND_ADD_OFFSET(*air_props, AirProperties, float, AirDensity, 9.67f, 0x200, 0x4,
                                    FieldType::Float);
            }
        }

        return true;
    }
} // namespace dumper::stages::workspace
