#include "dumper/dumper.h"
#include "dumper/stages/registry.h"
#include "process/helpers/helpers.h"
#include "process/memory/memory.h"
#include "process/process.h"
#include "process/rtti/rtti.h"
#include <chrono>
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>
#include <thread>

namespace dumper::stages::mesh_content_provider {

    static auto find_lru_holder(uintptr_t instance) -> std::optional<std::pair<size_t, size_t>> {
        for (size_t off = 0; off < 0x300; off += 0x8) {
            auto holder = process::Memory::read<uintptr_t>(instance + off);
            if (!holder || *holder < 0x10000)
                continue;

            for (size_t inner = 0; inner < 0x80; inner += 0x8) {
                auto ptr = process::Memory::read<uintptr_t>(*holder + inner);
                if (!ptr || *ptr < 0x10000)
                    continue;

                auto rtti = process::Rtti::scan_rtti(*ptr);
                if (rtti && rtti->name.find("MemEnforcedLRUCache") != std::string::npos)
                    return std::make_pair(off, inner);
            }
        }
        return std::nullopt;
    }

    static auto find_lru_head(uintptr_t lru_cache) -> std::optional<size_t> {
        const auto base = process::g_process.get_module_base();
        const auto code_end = base + 0x10000000ULL;

        for (size_t off = 0; off < 0x40; off += 0x8) {
            auto ptr = process::Memory::read<uintptr_t>(lru_cache + off);
            if (!ptr || *ptr < 0x10000 || (*ptr >= base && *ptr < code_end))
                continue;

            auto next = process::Memory::read<uintptr_t>(*ptr);
            auto prev = process::Memory::read<uintptr_t>(*ptr + 0x8);
            if (next && *next > 0x10000 && prev && *prev > 0x10000)
                return off;
        }
        return std::nullopt;
    }

    static auto find_mesh_id_offset(uintptr_t first_node) -> std::optional<size_t> {
        for (size_t off = 0x8; off < 0x80; off += 0x8) {
            auto str = process::Memory::read_sso_string(first_node + off);
            if (str && (str->find("rbxasset") != std::string::npos ||
                        str->find("http") != std::string::npos))
                return off;
        }
        return std::nullopt;
    }

    static auto find_node_by_name(uintptr_t head_sentinel, size_t mesh_id_off,
                                  const std::string& needle) -> uintptr_t {
        auto first = process::Memory::read<uintptr_t>(head_sentinel);
        if (!first || !*first || *first == head_sentinel)
            return 0;

        uintptr_t node = *first;
        for (int i = 0; i < 8192 && node != head_sentinel; i++) {
            auto id = process::Memory::read_sso_string(node + mesh_id_off);
            if (id && id->find(needle) != std::string::npos)
                return node;

            auto next = process::Memory::read<uintptr_t>(node);
            if (!next || !*next || *next == node)
                break;
            node = *next;
        }
        return 0;
    }

    struct MeshDataPath {
        size_t cached_item;
        size_t file_mesh_data;
        uintptr_t fmd_addr;
    };

    static auto find_mesh_data_path(uintptr_t node, size_t mesh_id_off)
        -> std::optional<MeshDataPath> {
        const glm::vec3 expected_min(-0.5f, -1.0f, -0.5f);

        for (size_t ci = 0x8; ci < 0x80; ci += 0x8) {
            if (ci == mesh_id_off)
                continue;

            auto ci_ptr = process::Memory::read<uintptr_t>(node + ci);
            if (!ci_ptr || *ci_ptr < 0x10000)
                continue;

            auto vtable = process::Memory::read<uintptr_t>(*ci_ptr);
            if (!vtable || *vtable < 0x10000)
                continue;

            for (size_t fmd = 0x8; fmd < 0x60; fmd += 0x8) {
                auto fmd_ptr = process::Memory::read<uintptr_t>(*ci_ptr + fmd);
                if (!fmd_ptr || *fmd_ptr < 0x10000)
                    continue;

                auto aabb =
                    process::helpers::find_vec_offset(*fmd_ptr, expected_min, 0x300, 0.01f, 4);
                if (aabb)
                    return MeshDataPath{ci, fmd, *fmd_ptr};
            }
        }
        return std::nullopt;
    }

    struct ArrayOffsets {
        size_t vertices;
        size_t vertices_end;
        size_t faces;
        size_t faces_end;
    };

    static auto find_arrays(uintptr_t fmd, size_t vert_bytes, size_t face_bytes)
        -> std::optional<ArrayOffsets> {
        size_t verts = SIZE_MAX;

        for (size_t off = 0; off < 0x100; off += 0x8) {
            auto start = process::Memory::read<uintptr_t>(fmd + off);
            auto end = process::Memory::read<uintptr_t>(fmd + off + 0x8);
            if (start && end && *start > 0x10000 && (*end - *start) == vert_bytes) {
                verts = off;
                break;
            }
        }
        if (verts == SIZE_MAX)
            return std::nullopt;

        for (size_t off = verts + 0x10; off < 0x100; off += 0x8) {
            auto start = process::Memory::read<uintptr_t>(fmd + off);
            auto end = process::Memory::read<uintptr_t>(fmd + off + 0x8);
            if (start && end && *start > 0x10000 && (*end - *start) == face_bytes)
                return ArrayOffsets{verts, verts + 8, off, off + 8};
        }
        return std::nullopt;
    }

    auto dump() -> bool {
        const auto mcp = dumper::g_data_model.find_first_child_of_class("MeshContentProvider");
        if (!mcp) {
            spdlog::error("MeshContentProvider: not found in DataModel");
            return false;
        }

        const auto holder = find_lru_holder(mcp->get_address());
        if (!holder) {
            spdlog::error("MeshContentProvider: failed to find LruHolder");
            return false;
        }
        dumper::g_dumper.add_offset("MeshContentProvider", "LruHolder", holder->first, "", FieldType::Pointer);
        dumper::g_dumper.add_offset("LruHolder", "MemEnforcedLRUCache", holder->second, "", FieldType::Pointer);

        auto holder_val = process::Memory::read<uintptr_t>(mcp->get_address() + holder->first);
        auto lru_val = process::Memory::read<uintptr_t>(*holder_val + holder->second);
        if (!holder_val || !lru_val || !*holder_val || !*lru_val) {
            spdlog::error("MeshContentProvider: failed to resolve LRU cache pointer");
            return false;
        }

        const auto head = find_lru_head(*lru_val);
        if (!head) {
            spdlog::error("MeshContentProvider: failed to find Head");
            return false;
        }
        dumper::g_dumper.add_offset("MemEnforcedLRUCache", "Head", *head, "", FieldType::Pointer);

        auto head_sentinel = process::Memory::read<uintptr_t>(*lru_val + *head);
        auto first_node = process::Memory::read<uintptr_t>(*head_sentinel);
        if (!head_sentinel || !first_node || *first_node == *head_sentinel) {
            for (int retry = 0; retry < 3; retry++) {
                std::this_thread::sleep_for(std::chrono::seconds(2));
                head_sentinel = process::Memory::read<uintptr_t>(*lru_val + *head);
                first_node = process::Memory::read<uintptr_t>(*head_sentinel);
                if (head_sentinel && first_node && *first_node != *head_sentinel)
                    break;
            }
            if (!head_sentinel || !first_node || *first_node == *head_sentinel) {
                spdlog::error("MeshContentProvider: LRU list is empty");
                return false;
            }
        }

        const auto mesh_id = find_mesh_id_offset(*first_node);
        if (!mesh_id) {
            spdlog::error("MeshContentProvider: failed to find MeshId offset");
            return false;
        }
        dumper::g_dumper.add_offset("LruNode", "Next", 0x0, "", FieldType::Pointer);
        dumper::g_dumper.add_offset("LruNode", "MeshId", *mesh_id, "", FieldType::Pointer);

        uintptr_t rightleg = find_node_by_name(*head_sentinel, *mesh_id, "rightleg");
        if (!rightleg) {
            spdlog::error("MeshContentProvider: rightleg.mesh not in LRU cache");
            return false;
        }

        auto path = find_mesh_data_path(rightleg, *mesh_id);
        if (!path) {
            spdlog::error("MeshContentProvider: failed to find CachedItem/FileMeshData path");
            return false;
        }
        dumper::g_dumper.add_offset("LruNode", "CachedItem", path->cached_item, "", FieldType::Pointer);
        dumper::g_dumper.add_offset("CachedItem", "FileMeshData", path->file_mesh_data, "", FieldType::Pointer);

        auto aabb_min = process::helpers::find_vec_offset(
            path->fmd_addr, glm::vec3(-0.5f, -1.0f, -0.5f), 0x300, 0.01f, 4);
        if (!aabb_min) {
            spdlog::error("MeshContentProvider: failed to find AabbMin");
            return false;
        }
        dumper::g_dumper.add_offset("FileMeshData", "AabbMin", *aabb_min, "", FieldType::Vector3);
        dumper::g_dumper.add_offset("FileMeshData", "AabbMax", *aabb_min + 12, "", FieldType::Vector3);

        constexpr size_t VERT_BYTES = 0x690;
        constexpr size_t FACE_BYTES = 0x210;

        auto arrays = find_arrays(path->fmd_addr, VERT_BYTES, FACE_BYTES);
        if (!arrays) {
            spdlog::error("MeshContentProvider: failed to find Vertices/Faces arrays");
            return false;
        }
        dumper::g_dumper.add_offset("FileMeshData", "Vertices", arrays->vertices, "", FieldType::Pointer);
        dumper::g_dumper.add_offset("FileMeshData", "VerticesEnd", arrays->vertices_end, "", FieldType::Pointer);
        dumper::g_dumper.add_offset("FileMeshData", "Faces", arrays->faces, "", FieldType::Pointer);
        dumper::g_dumper.add_offset("FileMeshData", "FacesEnd", arrays->faces_end, "", FieldType::Pointer);

        return true;
    }

} // namespace dumper::stages::mesh_content_provider

REGISTER_STAGE(mesh_content_provider)
