#pragma once
#include "writer.h"

namespace dumper::writer {

    class StructWriter : public IWriter {
      protected:
        auto get_file_extension() -> std::string override { return ".h"; }
        auto generate_content() -> std::string override;
    };

    inline StructWriter g_struct_writer;

} // namespace dumper::writer
