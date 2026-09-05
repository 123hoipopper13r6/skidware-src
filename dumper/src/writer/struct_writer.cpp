#include "struct_writer.h"
#include "dumper/dumper.h"
#include "process/process.h"
#include <algorithm>
#include <format>

namespace dumper::writer {

    auto StructWriter::generate_content() -> std::string {
        std::string content;
        content += "#pragma once\n";
        content += "#include <cstdint>\n\n";
        content += "// clang-format off\n";
        content += "#pragma pack(push, 1)\n";
        content += "namespace structs {\n\n";

        for (const auto& [ns_name, entries] : get_sorted_namespaces()) {
            std::vector<OffsetEntry> typed;
            for (const auto& e : entries) {
                if (e.type != FieldType::None)
                    typed.push_back(e);
            }
            if (typed.empty())
                continue;

            std::sort(typed.begin(), typed.end(),
                      [](const auto& a, const auto& b) { return a.offset < b.offset; });

            std::vector<OffsetEntry> filtered;
            for (const auto& field : typed) {
                if (filtered.empty()) {
                    filtered.push_back(field);
                    continue;
                }
                auto& prev = filtered.back();
                size_t prev_end = prev.offset + field_type_size(prev.type);
                if (field.offset < prev_end) {
                    content += ""; // handledd below
                    continue;
                }
                filtered.push_back(field);
            }

            std::vector<OffsetEntry> overlaps;
            for (const auto& field : typed) {
                bool in_filtered = false;
                for (const auto& f : filtered) {
                    if (f.name == field.name && f.offset == field.offset) {
                        in_filtered = true;
                        break;
                    }
                }
                if (!in_filtered)
                    overlaps.push_back(field);
            }

            content += "    struct " + ns_name + " {\n";

            size_t cursor = 0;
            int pad_idx = 0;

            for (const auto& field : filtered) {
                size_t field_size = field_type_size(field.type);
                if (field_size == 0)
                    continue;

                if (field.offset > cursor) {
                    size_t gap = field.offset - cursor;
                    content += std::format("        char pad_{}[0x{:X}];\n", pad_idx++, gap);
                }

                const char* type_name = field_type_name(field.type);
                content += std::format("        {} {};", type_name, field.name);

                content += std::format("  // 0x{:X}", field.offset);
                if (!field.comment.empty())
                    content += "  " + field.comment;
                content += "\n";

                cursor = field.offset + field_size;
            }

            size_t struct_size = cursor;

            if (!overlaps.empty()) {
                content += "        // overlapping aliases:\n";
                for (const auto& ov : overlaps) {
                    content += std::format("        // {} = 0x{:X} ({})\n", ov.name, ov.offset,
                                           field_type_name(ov.type));
                }
            }

            content += std::format("    }};  // sizeof = 0x{:X}\n\n", struct_size);
        }

        content += "} // namespace structs\n";
        content += "#pragma pack(pop)\n";
        return content;
    }

} // namespace dumper::writer
