# Skidware

External cheat for Roblox, written in C++ with a DirectX 11 ImGui overlay, plus a
C++ memory dumper that keeps the SDK offsets up to date.

**⚠️ For educational / research purposes only. Not affiliated with or endorsed by
Roblox. Use at your own risk — it may violate Roblox's Terms of Service.**

---

## Layout

| Folder | Contents |
|--------|----------|
| `external/` | The cheat itself (C++ / Visual Studio solution) |
| `dumper/`  | Memory dumper that generates `Offsets.hpp` / `FFlags.hpp` consumed by `external/` |

`dumper/` runs against the Roblox client and writes fresh offsets; `external/`
loads them at runtime via `Roblox/OffsetsUpdater.hpp`.

## Features (external)

- **ESP** — box, box glow, name, distance, tool, tracers, skeleton, health bar /
  number, chams (with glow + outlines), leaderstats, region highlights, avatar
  preview images, Murder Mystery role coloring (Murderer / Sheriff / Innocent),
  max-distance & team filters, custom fonts.
- **Aimbot** — force-field based, silent aim (viewport-level), smoothing, FOV
  circle (fill/outline), prediction, multi-hitbox, visibility/raycast check,
  hitsounds, hitmarkers & hit tracers.
- **Ragebot** — magic bullet, orbit, spam teleport, auto ragebot targeting.
- **Triggerbot** — delay + threshold + tool check.
- **Raycast** — visibility raytracing with preview, multiple aim modes.
- **Exploits / animation** — animation pack changer (walk, run, jump, swim…).
- **World** — fly, speed, noclip, freecam, third person, spinbot, upside-down,
  infinite jump, walk-speed override, camera FOV changer, time manipulation,
  waypoints.
- **Misc** — stream-proof mode, desync, team check, keybind list.
- **Auth** — HWID-locked login backed by a DuckDNS-hosted API.

## Password / licensing

`external/` uses a stub bridge for VMProtect (`Security/Vms/VMProtectSDK.h`):
markers are no-ops unless you open the project in VMProtect and supply the real
commercial SDK. No keys, tokens, or webhook URLs are shipped in this repository.

## Building

- **external/**: open `Skidware.sln` in Visual Studio 2022 (x64 Release). D3D11,
  WinHTTP, GDI+ required links are configured in the project.
- **dumper/**: `cmake --preset x64-release` then build (Ninja + MSVC).

## Credits

Around **90% vibecoded** with DeepSeek V4 Flash, Big Pickle, and Ox Alpha
(now GLM 4 Flash). Vendored third-party code: Dear ImGui (MIT), stb_image
(public domain), nlohmann/json (MIT), Clipper2 (BSL-1.0).