#include "bridge/bridge.h"
#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include <functional>
#include <spdlog/spdlog.h>
#include <unordered_map>

namespace dumper::stages::particle_emitter {

    auto dump() -> bool {
        const auto props = bridge::g_bridge.read_props_information();
        if (!props || props->particle_emitters.empty()) {
            spdlog::warn("No particle emitter properties from bridge");
            return false;
        }

        const auto& by_name = dumper::g_dumper.m_workspace_index;

        std::vector<uintptr_t> addrs;
        std::vector<const bridge::ParticleEmitterProperty*> entries;
        for (const auto& p : props->particle_emitters) {
            const auto it = by_name.find(p.name);
            if (it == by_name.end())
                continue;
            addrs.push_back(it->second);
            entries.push_back(&p);
        }
        if (addrs.size() < 3) {
            spdlog::warn("Not enough ParticleEmitter instances found ({})", addrs.size());
            return false;
        }

        const auto path = "DataModel>Workspace>SkidParticlesN";

        if (auto off = process::helpers::find_offset_with_getter<float>(
                addrs, [&](size_t i) { return entries[i]->rate; }, 0x800, 0x4)) {
            g_dumper.add_offset("ParticleEmitter", "Rate", *off, path, FieldType::Float);
        } else {
            spdlog::warn("ParticleEmitter::Rate not found (continuing)");
        }

        if (auto off = process::helpers::find_offset_with_getter<uint8_t>(
                addrs, [&](size_t i) { return entries[i]->enabled ? 1 : 0; }, 0x800, 0x1)) {
            g_dumper.add_offset("ParticleEmitter", "Enabled", *off, path, FieldType::Bool);
        } else {
            spdlog::warn("ParticleEmitter::Enabled not found (continuing)");
        }

        return true;
    }

} // namespace dumper::stages::particle_emitter

REGISTER_STAGE(particle_emitter)
