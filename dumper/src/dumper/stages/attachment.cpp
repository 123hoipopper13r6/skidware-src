#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>
#include <functional>
#include <unordered_map>
#include <spdlog/spdlog.h>

namespace dumper::stages::attachment {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->attachments.empty()) {
            spdlog::warn("No attachment properties from bridge");
            return false;
        }

        const auto& by_name = dumper::g_dumper.m_workspace_index;

        std::vector<uintptr_t> addrs;
        for (const auto& a : props->attachments) {
            const auto it = by_name.find(a.name);
            if (it != by_name.end())
                addrs.push_back(it->second);
        }

        if (addrs.size() < 3) {
            spdlog::warn("Not enough Attachment instances found ({})", addrs.size());
            return false;
        }

        const auto pos = process::helpers::find_vec3_offset_multi<glm::vec3>(
            addrs,
            [&](size_t i) {
                const auto& a = (*props).attachments[i];
                return glm::vec3(a.pos_x, a.pos_y, a.pos_z);
            },
            0x800, 0.01f);

        if (!pos) {
            spdlog::warn("Attachment::Position not found");
            return false;
        }

        g_dumper.add_offset("Attachment", "Position", *pos,
                            "DataModel>Workspace>TestPartN>SkidAttachN", FieldType::Vector3);
        return true;
    }

} // namespace dumper::stages::attachment

REGISTER_STAGE(attachment)
