#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include "process/memory/memory.h"
#include <spdlog/spdlog.h>

namespace dumper::stages::model {

    auto dump() -> bool {
        auto model = dumper::g_workspace->find_first_child("TestModel");
        if (!model || !model->is_valid()) {
            spdlog::error("Model: 'TestModel' not found in Workspace");
            return false;
        }

        auto primary_part = model->find_first_child("PrimaryPart");
        if (!primary_part || !primary_part->is_valid()) {
            spdlog::error("Model: 'PrimaryPart' not found in TestModel");
            return false;
        }

        auto pp_offset = process::helpers::find_pointer_offset(model->get_address(),
                                                               primary_part->get_address(), 0x400);
        if (!pp_offset) {
            spdlog::error("Model: Failed to find PrimaryPart offset");
            return false;
        }
        dumper::g_dumper.add_offset("Model", "PrimaryPart", *pp_offset, "", FieldType::Pointer);

        float expected_scale = 2.5f;
        auto scale_offset = process::helpers::find_offset_with_getter<float>(
            std::vector<uintptr_t>{model->get_address()}, [&](size_t) { return expected_scale; },
            0x400, 0x4);
        if (!scale_offset) {
            spdlog::error("Model: Failed to find Scale offset");
            return false;
        }
        dumper::g_dumper.add_offset("Model", "Scale", *scale_offset, "", FieldType::Float);

        return true;
    }

} // namespace dumper::stages::model

REGISTER_STAGE(model)
