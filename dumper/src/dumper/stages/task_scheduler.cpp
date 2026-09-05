#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include "process/helpers/zydis.h"
#include "process/memory/memory.h"
#include "process/rtti/rtti.h"
#include "process/xref/xref.h"
#include <cstring>
#include <spdlog/spdlog.h>
#include <unordered_map>
#include <unordered_set>

namespace dumper::stages::task_scheduler {

    namespace {

        constexpr std::string_view kJobArchetype = "Job@TaskScheduler@RBX";

        // page-cached reader so the scheduler scan doesn't issue one syscall per slot
        class PageCache {
          public:
            auto qword(uintptr_t address) -> std::optional<uint64_t> {
                if (!ensure(address)) {
                    return std::nullopt;
                }
                const uintptr_t page = address & ~0xFFFULL;
                auto& buf = m_pages[page];
                const size_t offset = address - page;
                if (offset + sizeof(uint64_t) > buf.size()) {
                    return std::nullopt;
                }
                uint64_t value = 0;
                std::memcpy(&value, buf.data() + offset, sizeof(value));
                return value;
            }

            auto dword(uintptr_t address) -> std::optional<uint32_t> {
                if (!ensure(address)) {
                    return std::nullopt;
                }
                const uintptr_t page = address & ~0xFFFULL;
                auto& buf = m_pages[page];
                const size_t offset = address - page;
                if (offset + sizeof(uint32_t) > buf.size()) {
                    return std::nullopt;
                }
                uint32_t value = 0;
                std::memcpy(&value, buf.data() + offset, sizeof(value));
                return value;
            }

            auto string(uintptr_t address) -> std::string {
                if (!ensure(address)) {
                    return {};
                }
                const uintptr_t page = address & ~0xFFFULL;
                auto& buf = m_pages[page];
                const size_t offset = address - page;
                std::string result;
                for (size_t i = offset; i < buf.size() && result.size() < 128 && buf[i]; i++) {
                    result.push_back(static_cast<char>(buf[i]));
                }
                return result;
            }

          private:
            auto ensure(uintptr_t address) -> bool {
                const uintptr_t page = address & ~0xFFFULL;
                if (m_pages.find(page) != m_pages.end()) {
                    return true;
                }
                auto buffer = process::Memory::read_bytes(page, 0x1000);
                if (buffer.empty()) {
                    return false;
                }
                m_pages[page] = std::move(buffer);
                return true;
            }

            std::unordered_map<uintptr_t, std::vector<uint8_t>> m_pages;
        };

        auto scheduler_names(PageCache& cache, uintptr_t address) -> std::vector<std::string> {
            std::vector<std::string> names;

            auto vtable = cache.qword(address);
            if (!vtable || *vtable < 0x10000) {
                return names;
            }

            auto col_ptr = cache.qword(*vtable - 0x8);
            if (!col_ptr || *col_ptr < 0x10000) {
                return names;
            }

            auto signature = cache.dword(*col_ptr);
            if (!signature || *signature != 1) {
                return names;
            }

            auto self_offset = cache.dword(*col_ptr + 0x14);
            if (!self_offset) {
                return names;
            }

            const uintptr_t module_base = *col_ptr - *self_offset;

            auto hierarchy_descriptor = cache.dword(*col_ptr + 0x10);
            if (!hierarchy_descriptor) {
                return names;
            }

            auto num_bases = cache.dword(module_base + *hierarchy_descriptor + 0x8);
            auto base_array = cache.dword(module_base + *hierarchy_descriptor + 0xC);
            if (!num_bases || !base_array || *num_bases == 0 || *num_bases >= 25) {
                return names;
            }

            for (uint32_t i = 0; i < *num_bases; i++) {
                auto base_offset = cache.dword(module_base + *base_array + (4 * i));
                if (!base_offset) {
                    break;
                }

                auto type_descriptor = cache.dword(module_base + *base_offset);
                if (!type_descriptor) {
                    continue;
                }

                names.push_back(cache.string(module_base + *type_descriptor + 0x10));
            }

            return names;
        }

        // true if `candidate` looks like the TaskScheduler instance: within 0x1000 bytes it
        // holds a slot whose deref chain reaches a Job@TaskScheduler@RBX object
        auto is_scheduler(PageCache& cache, uintptr_t candidate) -> bool {
            for (size_t offset = 0; offset < 0x1000; offset += 0x8) {
                auto p1 = cache.qword(candidate + offset);
                if (!p1 || *p1 < 0x10000) {
                    continue;
                }

                auto p2 = cache.qword(*p1);
                if (!p2 || *p2 < 0x10000) {
                    continue;
                }

                for (const auto& name : scheduler_names(cache, *p2)) {
                    if (name.find(kJobArchetype) != std::string::npos) {
                        return true;
                    }
                }
            }
            return false;
        }

        // last-resort scan: walk every writable module region looking for a global slot that
        // holds a pointer to the live TaskScheduler instance (job list RTTI verified)
        auto scan_scheduler_pointer() -> std::optional<uintptr_t> {
            const auto module_base = process::g_process.get_module_base();

            auto dos_header = process::Memory::read<IMAGE_DOS_HEADER>(module_base);
            if (!dos_header || dos_header->e_magic != IMAGE_DOS_SIGNATURE) {
                return std::nullopt;
            }

            auto nt_headers =
                process::Memory::read<IMAGE_NT_HEADERS64>(module_base + dos_header->e_lfanew);
            if (!nt_headers || nt_headers->Signature != IMAGE_NT_SIGNATURE) {
                return std::nullopt;
            }

            const uintptr_t image_end = module_base + nt_headers->OptionalHeader.SizeOfImage;

            std::unordered_set<uintptr_t> seen;
            PageCache cache;
            uintptr_t current = module_base;

            while (current < image_end) {
                MEMORY_BASIC_INFORMATION mbi{};
                if (VirtualQueryEx(process::g_process.get_handle(),
                                   reinterpret_cast<LPCVOID>(current), &mbi, sizeof(mbi)) !=
                    sizeof(mbi)) {
                    break;
                }

                const uintptr_t region_start = reinterpret_cast<uintptr_t>(mbi.BaseAddress);
                const uintptr_t region_end = region_start + mbi.RegionSize;

                const bool writable = mbi.State == MEM_COMMIT &&
                                      (mbi.Protect & (PAGE_READWRITE | PAGE_EXECUTE_READWRITE |
                                                      PAGE_WRITECOPY | PAGE_EXECUTE_WRITECOPY));

                if (writable) {
                    auto buffer = process::Memory::read_bytes(region_start, mbi.RegionSize);
                    if (buffer.size() >= sizeof(uintptr_t)) {
                        for (size_t offset = 0; offset + sizeof(uintptr_t) <= buffer.size();
                             offset += sizeof(uintptr_t)) {
                            uintptr_t value = 0;
                            std::memcpy(&value, buffer.data() + offset, sizeof(value));

                            if (value < 0x100000000 ||
                                value >= 0x7FFF00000000ULL) {
                                continue;
                            }

                            if (!seen.emplace(value).second) {
                                continue;
                            }

                            if (is_scheduler(cache, value)) {
                                return region_start + offset - module_base;
                            }
                        }
                    }
                }

                current = region_end;
            }

            return std::nullopt;
        }

    } // namespace

    static auto get_pointer() -> uintptr_t {
        static const std::vector<std::string> anchors = {
            "ScriptContextTaskQueue",
            "TaskScheduler",
        };

        std::unordered_set<uintptr_t> candidates;

        for (const auto& anchor : anchors) {
            const auto string_results = process::Memory::scan_string(anchor, ".rdata");

            if (string_results.empty())
                continue;

            for (const auto& string_addr : string_results) {
                const auto xrefs = process::g_xref.scan(string_addr);

                for (const auto& xref : xrefs) {
                    auto result =
                        process::helpers::zydis::resolve_rip_mov(xref, 0x100, 0x300);

                    if (result) {
                        candidates.emplace(*result - process::g_process.get_module_base());
                    }
                }
            }
        }

        // validate anchor candidates: the pointer global must actually resolve to the
        // TaskScheduler instance (rejects e.g. the settings registry false positive)
        for (const auto candidate : candidates) {
            auto scheduler = process::Memory::read<uintptr_t>(
                process::g_process.get_module_base() + candidate);
            if (!scheduler || *scheduler < 0x10000) {
                continue;
            }

            PageCache cache;
            if (is_scheduler(cache, *scheduler)) {
                return candidate;
            }
        }

        if (const auto found = scan_scheduler_pointer()) {
            return *found;
        }

        spdlog::error("Failed to resolve TaskScheduler pointer");
        return 0;
    }

    static auto get_job_name_offset(uintptr_t task_sched, size_t job_start_offset)
        -> std::optional<size_t> {
        static const std::unordered_set<std::string> job_names = {
            "WorkspaceTaskQueue",
            "PerformanceControlCoordinatorV2Job",
            "NotifyAliveJob",
            "LuaGc",
            "WaitingHybridScriptsJob",
            "ClearUnusedLuaRefsJob",
            "LuauTelemetry",
            "DataModelCharacterTaskQueue",
            "TimerTickerJob",
            "MemoryPrioritizationJob",
            "PerformanceControlOrchestrator",
            "Write Marshalled",
            "Read Marshalled",
            "None Marshalled",
            "ThumbnailFetchJob",
            "Sound",
            "LogServiceJob",
            "HttpRbxApiJob",
            "Simulation",
            "Heartbeat",
            "AnalyticsServiceJob",
            "HumanoidParallelManagerTaskQueue",
            "AnimatorParallelManagerTaskQueue",
            "ScriptContextTaskQueue",
            "EventBroadcastrelayFireEventJob",
            "Video",
            "RenderJob",
            "Replicator ProcessPackets",
            "Network Quality Responder",
            "PreRenderJob",
            "SceneUpdaterTaskQueue",
            "SmoothClusterTaskQueue",
            "DummyClient Event Processor",
            "Network Disconnect Clean Up",
            "Allocate Bandwidth and Run Senders",
            "ScopeCheckCleanupJob",
            "AvatarCreationServiceJob",
            "Net PacketReceive",
            "Net Peer Send",
            "Net Peer Stats",
            "MegaReplicatorPPRTaskQueue",
            "MegaReplicatorTaskQueue",
            "DynamicTranslationSender_LocalizationService",
            "LocalizationTableAnalyticsSender_LocalizationService"};

        const auto job_start = process::Memory::read<uintptr_t>(task_sched + job_start_offset);
        const auto job_end = process::Memory::read<uintptr_t>(task_sched + job_start_offset + 0x8);

        if (!job_start || !job_end || *job_start >= *job_end)
            return std::nullopt;

        for (uintptr_t ptr = *job_start; ptr < *job_end; ptr += 0x8) {
            const auto job = process::Memory::read<uintptr_t>(ptr);
            if (!job || *job < 0x10000)
                continue;

            for (size_t offset = 0; offset < 0x1000; offset += 0x8) {
                auto str = process::Memory::read_sso_string(*job + offset);
                if (!str || str->empty())
                    continue;

                if (job_names.contains(*str)) {
                    return offset;
                }
            }
        }

        return std::nullopt;
    }

    auto dump() -> bool {
        const auto task_scheduler_ptr = get_pointer();
        if (!task_scheduler_ptr) {
            spdlog::error("Failed to find task scheduler pointer");
            return false;
        }

        g_dumper.add_offset("TaskScheduler", "Pointer", task_scheduler_ptr);

        const uintptr_t task_scheduler = *process::Memory::read<uintptr_t>(
            process::g_process.get_module_base() + task_scheduler_ptr);

        const auto job_start =
            process::Rtti::find_deref(task_scheduler, "Job@TaskScheduler@RBX", 0x1000);

        if (!job_start) {
            spdlog::error("Failed to find job start in task scheduler");
            return false;
        }

        g_dumper.add_offset("TaskScheduler", "JobStart", *job_start, "", FieldType::Pointer);
        g_dumper.add_offset("TaskScheduler", "JobEnd", *job_start + 0x8, "", FieldType::Pointer);

        const auto job_name = get_job_name_offset(task_scheduler, *job_start);
        if (!job_name) {
            spdlog::error("Failed to find job name offset");
            return false;
        }

        g_dumper.add_offset("TaskScheduler", "JobName", *job_name);

        const auto max_fps =
            process::helpers::find_offset<double>(task_scheduler, 1.0 / 60.0, 0x1000, 0x4);

        if (!max_fps) {
            spdlog::error("Failed to find MaxFps offset for task scheduler, make sure your Roblox "
                          "FPS is set to 60fps");
            return false;
        }

        g_dumper.add_offset("TaskScheduler", "MaxFps", *max_fps, "", FieldType::Double);

        return true;
    }

} // namespace dumper::stages::task_scheduler

REGISTER_STAGE(task_scheduler)
