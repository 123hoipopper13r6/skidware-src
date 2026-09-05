# Skidware

External cheat for **Roblox**, written in C++ with a DirectX 11 ImGui overlay, plus a
C++ memory dumper that regenerates the SDK offsets the cheat consumes.

**⚠️ For educational / research purposes only. Not affiliated with or endorsed by
Roblox Corporation. Using this may violate Roblox's Terms of Service and can result
in account bans. You are responsible for how you use it.**

---

## Table of contents

- [Overview](#overview)
- [Repository layout](#repository-layout)
- [Features](#features)
- [How it works](#how-it-works)
- [Runtime files](#runtime-files)
- [Building](#building)
- [Origins & credits](#origins--credits)
- [Dependencies](#dependencies)

## Overview

Skidware is a memory-based (external) cheat: it attaches to `RobloxPlayerBeta.exe`,
walks the game's object hierarchy straight from the process memory, and renders its
UI and ESP in a separate DirectX 11 overlay window. Nothing is injected into the
client — reads/writes are done through `ReadProcessMemory`/`WriteProcessMemory`.

The project is split in two:

- `external/` — the cheat itself (Visual Studio solution).
- `dumper/` — the offsets dumper that keeps the cheat working after Roblox updates.

## Repository layout

```
skidware-src/
├── external/                     # The cheat (VS 2022, x64)
│   ├── inferno.cpp               # Entry point (based on the Inferno source)
│   ├── Globals.hpp               # All settings/state
│   ├── ConfigManager.hpp         # JSON config save/load
│   ├── GameSupport.hpp           # Game detection & specialists
│   ├── Hacks/                    # Esp, Aimbot, TriggerBot, Raycast, Explorer, Misc, Animations
│   ├── Overlay/                  # ImGui overlay, fonts, avatar preview renderer
│   ├── Roblox/                   # SDK, instance classes, memory cache, offsets loader
│   ├── Security/                 # Auth backend, anti-tamper, xorstr + VMProtect bridge
│   └── Libs/                     # Vendored deps (ImGui, FreeType, Clipper2, stb, nlohmann-json…)
└── dumper/                       # Offsets dumper (CMake)
```

## Features

### ESP
- Box, box glow, name (incl. display names), distance, tool, tracers, skeleton
- Health bar / health number with glow and background, multiple color modes
- **Chams** with glow, outlines and configurable outline thickness
- Leaderstats display, team filtering, region highlighting
- Max-distance slider, custom fonts, keybind list
- **Avatar previews** next to player ESP (fetched from Roblox thumbnails)
- Murder Mystery awareness: colors Murderer / Sheriff / Innocent per role
- Optional local-player ESP

### Aimbot
- Silent aim via viewport manipulation (smoothing, hitbox selection)
- FOV circle (fill + outline), prediction on X/Y
- Visibility / raycast check before shooting
- Hit detection: **hitsounds**, **hitmarkers**, **hit tracers**
- **Rage mode**: magic bullet, orbit, spam teleport, auto-ragebot targeting

### TriggerBot
- Key/toggle based, configurable delay and threshold, tool check, visibility check

### Raycast
- Reimplemented visibility raytracing with method + aim-mode selection, preview toggle

### Exploits
- Animation pack changer (idle, walk, run, jump, fall, climb, swim)

### World
- Fly, speed, noclip, freecam, third-person (offset adjustable), spinbot, upside-down
- Infinite jump with custom jump power, walk-speed override
- Camera FOV changer, time manipulation, waypoints (name + distance)

### Misc
- Stream-proof mode (hides critical UI while streaming), desync, team check, notifications, watermark

## How it works

1. **Attach** — find `RobloxPlayerBeta.exe`, open it with read/write access and resolve the module base.
2. **Resolve the DataModel** — read the fake DataModel pointer → DataModel, then Games, Players, Workspace.
3. **Walk the instance tree** — each instance is read with known offsets (Name, ClassDescriptor, ChildrenStart/End…), so the cheat sees the *same object graph the client sees*.
4. **Read/patch values** — position, size, health are floats at fixed offsets; hacks write straight into them.
5. **Update offsets** — instead of recompiling the SDK on every Roblox patch, `dumper/` scans the client (RTTI + xref analysis, Zydis disassembly) and regenerates `Offsets.hpp` / `FFlags.hpp`. The external loads the flat file at runtime via `Roblox/OffsetsUpdater.hpp` (fallback to `C:\Skidware\Offsets.h`).

## Runtime files

Everything lives in `C:\Skidware\`:

| Path | Purpose |
|------|---------|
| `Configs\<gameId>.rocks` | Per-game config (JSON) |
| `globals.rocks` | Global settings |
| `auth.bin` | DPAPI-protected auth session |
| `Offsets.h` | Runtime-loaded flattened offsets |
| `Theme.json` | UI theme |
| `imgui.ini` | ImGui layout |

## Building

### external
1. Open `external/Skidware.sln` in **Visual Studio 2022** (x64 Release).
2. Required links already configured: DirectX SDK (June 2010), WinHTTP, GDI+, shell32.
3. Build. The main binary is currently expected to be finalized with **VMProtect** —
   `Security/Vms/VMProtectSDK.h` ships as a *stub bridge* (markers are no-ops), so it
   compiles out of the box; supply the real SDK and run VMProtect for full protection.

### dumper
1. `dumper/` uses CMake + Ninja (see `CMakePresets.json`):
   `cmake --preset x64-release`
2. Run the built dumper while Roblox is open; it writes `offsets.h/json/py/cs`, `structs.h`,
   `sdk_offsets.hpp` and `sdk_fflags.hpp`, then deploys the SDK headers into `external/Roblox/`.
3. `update-offsets.ps1` automates the whole regenerate path.

## Origins & credits

- **Inferno** — the `external/` cheat is built on the **Inferno source** as a base,
  obtained from the **Margiela** server, then heavily reworked.
- **Dumper** — a fork of **jonah/nopjo's roblox-dumper** (itself written with Ox Alpha),
  extended with extra stages and the auto-deploy pipeline.
- Around **90% vibecoded** with **DeepSeek V4 Flash**, **Big Pickle**, and **Ox Alpha**
  (now **GLM 4 Flash**). The remaining ~10% is manual fixing, debugging and tuning.
- No API keys, tokens, webhooks, or personal credentials are shipped in this repository.
  The only "live" endpoint referenced by the source is a DuckDNS-hosted auth API hostname.

## Dependencies

| Library | Vendor | License |
|---------|--------|---------|
| Dear ImGui | ocornut | MIT |
| stb_image | nothings | Public domain |
| nlohmann/json | Niels Lohmann | MIT |
| Clipper2 | Angus Johnson | BSL-1.0 |
| FreeType | FreeType Project | FTL (permissive) |
| LuckMemory | internal | — |
| xorstr.hpp | Andrivet/OneDrive | Apache-2.0 license notice retained |
| Zydis / Zycore (dumper) | zyantific | MIT |
| spdlog (dumper) | gabime | MIT |
| glm (dumper) | g-truc | MIT |