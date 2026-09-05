import re, sys

SRC = r"D:\Users\Phantom\Downloads\Offsets(2).hpp"
OUT = r"D:\skidware\skidware-external\skidware-dumper\src\dumper\stages\rbxcli_reference.cpp"

SKIP_PATH = {"FastFlags", "Luau", "EngineDetections", "AntiCheat", "OffsetChains", "TTypeIds",
             "GlobalState", "LuaState", "LuaTable", "LuaPage"}

entry_re = re.compile(
    r"constexpr\s+(?:std::ptrdiff_t|std::array<std::ptrdiff_t,\s*\d+>|auto)\s+(\w+)\s*=\s*([^;]+);"
    r"(?:\s*/\*(.*?)\*/)?", re.S)

def camel_split(name):
    # strip hungarian-ish prefix (lowercase run before an uppercase letter)
    m = re.match(r"^([a-z]{1,5}[0-9]?)(?=[A-Z])", name)
    core = name[m.end():] if m else name
    # split camelCase / acronym boundaries
    s = re.sub(r"(?<=[a-z0-9])(?=[A-Z])", " ", core)
    s = re.sub(r"(?<=[A-Z])(?=[A-Z][a-z])", " ", s)
    s = s.replace("_", " ").strip()
    for bad, good in (("C Frame", "CFrame"), ("Cframe", "CFrame"), ("Udim2", "UDim2"),
                      ("Udim", "UDim"), ("Lod", "LOD"), ("Hsv", "HSV")):
        s = re.sub(rf"\b{bad}\b", good, s)
    s = re.sub(r"\bC Frame(?=\d?)", "CFrame", s)
    return (s[0].upper() + s[1:]) if s else name

def cstr(s):
    return '"' + s.replace("\\", "\\\\").replace('"', '\\"').replace("\n", " ") + '"'

stack = []
entries = {}   # (ns, name) -> (value, desc)
order = []

for raw in open(SRC, encoding="utf-8", errors="replace"):
    line = raw.rstrip()
    m = re.search(r"namespace\s+([\w:]+)\s*\{", line)
    if m and "=" not in line.split("//")[0][:40]:
        stack.extend(m.group(1).split("::"))
        continue
    # pop on closing braces (count braces outside comments/strings)
    code = line.split("/*")[0]
    closes = code.count("}")
    opens = code.count("{")
    if not m and closes:
        for _ in range(closes):
            if stack: stack.pop()
        continue

    path = [p for p in stack if p not in ("Offsets",)]
    if any(p in SKIP_PATH for p in path):
        # consume entry definitions anyway so brace counting stays sane
        continue
    em = entry_re.search(line)
    if not em or "std::array" in line or "= commonChain" in line or "{ " in line[:60]:
        continue
    name, val, comment = em.group(1), em.group(2).strip(), (em.group(3) or "").strip()
    try:
        v = int(val, 0) & 0xFFFFFFFFFFFFFFFF
    except ValueError:
        continue
    if not path:
        continue
    ns = path[-1]
    if ns == "RBX":
        ns = "RbxSingletons"
    key = (ns, name)
    if key in entries:
        continue
    failed = "Failed to analyze" in comment
    short = comment if (comment and len(comment) <= 180 and not comment.startswith("Hybrid Dumper")) else ""
    desc = camel_split(name)
    if failed:
        desc += " (rbxcli analyzer failed - verify)"
    elif short:
        desc += ". " + short
    desc += " [rbxcli ref]"
    entries[key] = (v, desc)
    order.append(key)

# group by ns, sort inside
from collections import defaultdict
by_ns = defaultdict(list)
for k in order:
    by_ns[k[0]].append(k)

with open(OUT, "w", encoding="utf-8") as f:
    f.write("// GENERATED from Offsets(2).hpp (rbxcli/Dottik reference dump) - do not edit by hand.\n")
    f.write(f"// {len(entries)} static reference offsets, build-matched to the analyzed client.\n")
    f.write('#include "dumper/dumper.h"\n#include "dumper/stages/registry.h"\n')
    f.write('#include <spdlog/spdlog.h>\n#include <mutex>\n\nnamespace dumper::stages::rbxcli_reference {\n\n')
    f.write("struct RefEntry { const char* ns; const char* name; size_t value; const char* desc; };\n\n")
    f.write("static constexpr RefEntry kEntries[] = {\n")
    for ns in sorted(by_ns):
        for k in by_ns[ns]:
            v, d = entries[k]
            f.write(f"    {{{cstr(ns)}, {cstr(k[1])}, 0x{v:X}, {cstr(d)}}},\n")
    f.write("};\n\n")
    f.write("""    auto dump() -> bool {
        std::lock_guard<std::mutex> lock(g_dumper.m_offset_mutex);
        size_t added = 0;
        for (const auto& e : kEntries) {
            auto& vec = g_dumper.m_offsets[e.ns];
            bool dup = false;
            for (const auto& existing : vec)
                if (existing.name == e.name) { dup = true; break; }
            if (dup)
                continue;
            vec.push_back({e.name, e.value, "rbxcli reference (static)", FieldType::None});
            const std::string key = std::string(e.ns) + "::" + e.name;
            g_dumper.m_offset_descriptions.emplace(key, e.desc);
            ++added;
        }
        spdlog::info("RbxcliReference: {} static reference offsets merged", added);
        return added > 0;
    }

} // namespace dumper::stages::rbxcli_reference

REGISTER_STAGE(rbxcli_reference)
""")

print(f"wrote {len(entries)} entries across {len(by_ns)} namespaces")
