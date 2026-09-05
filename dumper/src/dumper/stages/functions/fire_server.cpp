#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/process.h"
#include "roblox/offsets.h"
#include <spdlog/spdlog.h>

namespace dumper::stages::fire_server {

    auto dump() -> bool {
        const auto base = process::g_process.get_module_base();

        const auto replicated_storage =
            dumper::g_data_model.find_first_child_of_class("ReplicatedStorage");
        if (!replicated_storage) {
            spdlog::error("FireServer: Failed to find ReplicatedStorage");
            return false;
        }

        auto remote_event = replicated_storage->find_first_child_of_class("RemoteEvent");
        if (!remote_event) {
            spdlog::error("FireServer: No RemoteEvent in ReplicatedStorage");
            return false;
        }

        auto addr = remote_event->get_function_address("FireServer");
        if (!addr) {
            spdlog::error("FireServer: 'FireServer' not found in RemoteEvent");
            return false;
        }

        dumper::g_dumper.add_offset("Functions", "FireServer", *addr - base,
                                    "better to resolve at runtime via func descriptors");
        return true;
    }

} // namespace dumper::stages::fire_server

REGISTER_STAGE(fire_server)
