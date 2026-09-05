#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <functional>
#include <unordered_map>
#include <spdlog/spdlog.h>

namespace dumper::stages::decal {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->decals.empty()) {
            spdlog::warn("No decal properties from bridge");
            return false;
        }

        const auto& by_name = dumper::g_dumper.m_workspace_index;

        std::vector<uintptr_t> addrs;
        for (const auto& d : props->decals) {
            const auto it = by_name.find(d.name);
            if (it != by_name.end())
                addrs.push_back(it->second);
        }

        if (addrs.size() < 3) {
            spdlog::warn("Not enough Decal instances found ({})", addrs.size());
            return false;
        }

        const auto offset = process::helpers::find_offset_with_getter<float>(
            addrs, [&](size_t i) { return (*props).decals[i].transparency; }, 0x800, 0x4);

        if (!offset) {
            spdlog::warn("Decal::Transparency not found");
            return false;
        }

        g_dumper.add_offset("Decal", "Transparency", *offset,
                            "DataModel>Workspace>TestPartN>SkidDecalN", FieldType::Float);
        return true;
    }

} // namespace dumper::stages::decal

REGISTER_STAGE(decal)
