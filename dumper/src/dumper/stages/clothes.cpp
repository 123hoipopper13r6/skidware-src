#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <spdlog/spdlog.h>

namespace dumper::stages::clothes {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->clothes.empty()) {
            spdlog::warn("No clothes properties from bridge");
            return false;
        }

        bool dumped_any = false;

        for (const auto& c : props->clothes) {
            const auto inst = dumper::g_workspace->find_first_child(c.name);
            if (!inst)
                continue;

            const auto offset = process::helpers::find_sso_string_offset(
                inst->get_address(), c.template_id, 0x800, 0x8);

            if (!offset)
                continue;

            const auto field =
                c.name.rfind("Shirt", 0) == 0 ? "ShirtTemplate" : "PantsTemplate";
            const auto ns = c.name.rfind("Shirt", 0) == 0 ? "Shirt" : "Pants";

            g_dumper.add_offset(ns, field, *offset, "DataModel>Workspace>SkidClothesN",
                                FieldType::Pointer);
            dumped_any = true;
            break; // one Shirt + we are done for that namespace
        }

        if (!dumped_any) {
            spdlog::warn("No clothes template offsets found");
            return false;
        }

        return true;
    }

} // namespace dumper::stages::clothes

REGISTER_STAGE(clothes)
