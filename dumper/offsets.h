/*
 * Dumped With: skidware-dumper 3.8 (by Ox Alpha)
 * Fork of jonah/nopjo's roblox-dumper
 * Dumped At: 2026-08-28 12:15:34 UTC
 * Roblox Version: version-f5a60436d48947d3
 * Time Taken: 204178 ms (204.178000 seconds)
 * Total Offsets: 1596
 *
 * Method:
 *   1. Bridge ground truth - an in-game script creates test instances with
 *       known unique values and reports them as JSON via ReplicatedStorage.
 *   2. Empirical scanning - instance memory is searched for those values;
 *       offsets are only accepted when they verify across many instances.
 *   3. RTTI / class-descriptor walks resolve services and child pointers.
 *   4. String-signature + xref scans locate engine singletons.
 *   5. FastFlags - heap registry discovery via name-pointer slots, with
 *       statistical per-type payload layout inference.
 */

#pragma once
#include <cstdint>

// clang-format off
namespace offsets {
    inline constexpr const char* roblox_version = "version-f5a60436d48947d3";

    namespace Accessory {
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttachmentForward = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttachmentPoint = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttachmentPos = 0x2C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttachmentRight = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttachmentUp = 0xC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BackendAccoutrementState = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace AirProperties { // per-workspace wind/air physics
        inline constexpr uintptr_t AirDensity = 0x18; // scanned for 9.67f = 9.67 - air density for drag calculations
        inline constexpr uintptr_t GlobalWind = 0x3C; // wind vector applied to unanchored parts
    }

    namespace Animation { // animation asset reference
        inline constexpr uintptr_t AnimationId = 0xC0; // Animation Id
    }

    namespace Animator {
        inline constexpr uintptr_t AnimTrackMetadata0 = 0x2F4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata1 = 0x2F8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata10 = 0x2FC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata11 = 0x300; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata12 = 0x304; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata13 = 0x308; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata14 = 0x30C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata15 = 0x310; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata2 = 0x314; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata3 = 0x318; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata4 = 0x31C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata5 = 0x320; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata6 = 0x324; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata7 = 0x328; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata8 = 0x32C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackMetadata9 = 0x330; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState0 = 0x2F4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState1 = 0x2F8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState10 = 0x2FC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState11 = 0x300; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState12 = 0x304; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState13 = 0x308; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState14 = 0x30C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState15 = 0x310; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState2 = 0x314; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState3 = 0x318; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState4 = 0x31C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState5 = 0x320; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState6 = 0x324; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState7 = 0x328; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState8 = 0x32C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackPlayState9 = 0x330; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight0 = 0x2F8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight1 = 0x314; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight10 = 0x300; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight11 = 0x304; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight12 = 0x308; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight13 = 0x30C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight14 = 0x310; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight15 = 0x90; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight2 = 0x318; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight3 = 0x31C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight4 = 0x320; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight5 = 0x324; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight6 = 0x328; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight7 = 0x32C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight8 = 0x330; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimTrackWeight9 = 0x2FC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId0 = 0x240; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId1 = 0x248; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId10 = 0x250; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId11 = 0x258; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId12 = 0x260; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId13 = 0x268; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId14 = 0x270; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId15 = 0x278; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId2 = 0x280; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId3 = 0x288; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId4 = 0x290; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId5 = 0x298; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId6 = 0x2A0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId7 = 0x2A8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId8 = 0x2B0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnimationId9 = 0x2B8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t EvaluationThrottled = 0x334; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t FacsReplicationData = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PreferLodEnabled = 0x3E4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RootMotion = 0x3A0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RootMotionWeight = 0x3A0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace AntiCheat { // Hyperion integrity machinery. Static RVAs from static analysis of this build - not empirically scanned.
        inline constexpr uintptr_t relControlFlowGuardMap = 0x145BA48; // Custom CFG-style map encoded over page boundaries; shift address by 0x13 bytes then set bit to 0xFF to whitelist code outside allowed segments - Control Flow Guard Map
        inline constexpr uintptr_t relFpControlFlowCheck = 0xC53000; // Function carrying out the control flow check against the map above - Fp Control Flow Check
    }

    namespace Atmosphere {
        inline constexpr uintptr_t Color = 0xB8; // Color
        inline constexpr uintptr_t Decay = 0xC4; // Decay
        inline constexpr uintptr_t Density = 0xD0; // scanned for 0.324f = 0.324 - Density
        inline constexpr uintptr_t Glare = 0xD4; // scanned for 0.432f = 0.432 - Glare
        inline constexpr uintptr_t Haze = 0xD8; // scanned for 0.123f = 0.123 - Haze
        inline constexpr uintptr_t Offset = 0xDC; // scanned for 0.561f = 0.561 - Offset
    }

    namespace Attachment { // attach point on a part
        inline constexpr uintptr_t Position = 0xC4; // DataModel>Workspace>TestPartN>SkidAttachN - attachment offset from its parent part center
    }

    namespace AudioListener {
        inline constexpr uintptr_t AcousticSimulationEnabled = 0x3C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AngleAttenuation = 0x40; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AudioInteractionGroup = 0x40; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DiffractionEnabled = 0x30; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DistanceAttenuation = 0x40; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t OcclusionEnabled = 0x3C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PositionInstance = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PositionType = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ReverbEnabled = 0x3C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SimulationFidelity = 0x40; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace BasePart { // part instance (aliases into Primitive)
        inline constexpr uintptr_t AngularVelocity = 0x28C; // DataModel>Workspace>TestPartN>BasePart>Primitive - convenience alias: Primitive->AssemblyAngularVelocity
        inline constexpr uintptr_t CastShadow = 0x135; // Cast Shadow
        inline constexpr uintptr_t Color3 = 0x1A8; // Color3
        inline constexpr uintptr_t Locked = 0x136; // Locked
        inline constexpr uintptr_t Massless = 0x137; // Massless
        inline constexpr uintptr_t Primitive = 0x188; // pointer from BasePart to its physics Primitive
        inline constexpr uintptr_t PrimitiveFlags = 0x33E; // Primitive Flags
        inline constexpr uintptr_t Reflectance = 0x10C; // Reflectance
        inline constexpr uintptr_t Shape = 0x1B9; // Shape
        inline constexpr uintptr_t Transparency = 0x130; // Transparency
        inline constexpr uintptr_t Velocity = 0x280; // DataModel>Workspace>TestPartN>BasePart>Primitive - convenience alias: Primitive->AssemblyLinearVelocity
    }

    namespace BloomEffect {
        inline constexpr uintptr_t Intensity = 0xB8; // scanned for 1.23f = 1.23 - Intensity
        inline constexpr uintptr_t Size = 0xBC; // scanned for 24.5 = 24.5 - Size
        inline constexpr uintptr_t Threshold = 0xC0; // scanned for 2.1f = 2.1 - Threshold
    }

    namespace BodyColors {
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HeadColor = 0x24; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HeadColor3 = 0x24; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftArmColor = 0x24; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftArmColor3 = 0x24; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightArmColor = 0x54; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightArmColor3 = 0x54; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightLegColor = 0x54; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightLegColor3 = 0x54; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace BoolValue { // bool container
        inline constexpr uintptr_t Value = 0xB8; // DataModel>Workspace>SkidValueN - the bool payload
    }

    namespace ByteCode {
        inline constexpr uintptr_t Pointer = 0x10; // Pointer
        inline constexpr uintptr_t Size = 0x28; // Size
    }

    namespace CFrameValue { // cframe container
        inline constexpr uintptr_t Value = 0xDC; // DataModel>Workspace>SkidValueN - cframe translation payload
    }

    namespace CachedItem {
        inline constexpr uintptr_t FileMeshData = 0x28; // File Mesh Data
    }

    namespace Camera { // view camera
        inline constexpr uintptr_t CFrame = 0xD8; // camera position + rotation
        inline constexpr uintptr_t CameraSubject = 0xC8; // instance the camera follows
        inline constexpr uintptr_t FieldOfView = 0x140; // scanned for fov_radians = 1.9757127 - field of view in degrees (stored as radians here)
        inline constexpr uintptr_t Position = 0xFC; // camera world position
        inline constexpr uintptr_t Rotation = 0xD8; // Rotation
        inline constexpr uintptr_t ViewportInt16 = 0x28C; // Viewport Int16
        inline constexpr uintptr_t ViewportSize = 0x2CC; // viewport size in pixels
    }

    namespace CharacterMesh {
        inline constexpr uintptr_t BaseTextureId = 0xC8; // Base Texture Id
        inline constexpr uintptr_t BodyPart = 0x148; // Body Part
        inline constexpr uintptr_t MeshId = 0xF8; // Mesh Id
        inline constexpr uintptr_t OverlayTextureId = 0x128; // Overlay Texture Id
    }

    namespace ClassDescriptor {
        inline constexpr uintptr_t ClassName = 0x8; // class name string (e.g. "Part")
        inline constexpr uintptr_t Creator = 0x230; // ICreator vtable, [0] = create fn - Creator
        inline constexpr uintptr_t EventDescriptors = 0x88; // Event Descriptors
        inline constexpr uintptr_t FunctionDescriptors = 0xD0; // Function Descriptors
        inline constexpr uintptr_t PropertyDescriptors = 0x40; // Property Descriptors
    }

    namespace ClickDetector { // click interaction
        inline constexpr uintptr_t MaxActivationDistance = 0xE8; // DataModel>Workspace>TestPartN>SkidClickN - max click range in studs
    }

    namespace Creator {
        inline constexpr uintptr_t MapEnd = 0x83403D8; // Map End
        inline constexpr uintptr_t MapStart = 0x83403D0; // Map Start
    }

    namespace DataModel { // root game object (place/session info)
        inline constexpr uintptr_t CreatorId = 0x180; // scanned for data->creator_id = 3672944211 - user/group ID of the game creator
        inline constexpr uintptr_t DataModelType = 0x958; // DWORD containing the type of datamodel, related to whether you're in game or not. - Data Model Type
        inline constexpr uintptr_t GameId = 0x188; // scanned for data->game_id = 10735428841 - ID of the universe (game) this place belongs to
        inline constexpr uintptr_t GameLoaded = 0x5D0; // scanned for 31 = 31 - non-zero once the place finished loading
        inline constexpr uintptr_t HackFlagNodeValue = 0x10; // Flag dword inside a detection flag list node. - Hack Flag Node Value
        inline constexpr uintptr_t HackFlagSetList = 0x830; // Circular std::list sentinel of detection flag nodes. Walk _Next at +0x0. - Hack Flag Set List
        inline constexpr uintptr_t HackFlagSetMutex = 0x828; // DMHackFlagSetMutex, guards the per-DataModel detection flag list. - Hack Flag Set Mutex
        inline constexpr uintptr_t JobId = 0x118; // server session ID (unique per server join)
        inline constexpr uintptr_t PlaceId = 0x190; // scanned for data->place_id = 90790446880270 - ID of the current place
        inline constexpr uintptr_t Workspace = 0x158; // DataModel instance > Workspace service child - pointer to the Workspace service
    }

    namespace Decal { // texture on a face
        inline constexpr uintptr_t Transparency = 0x25C; // DataModel>Workspace>TestPartN>SkidDecalN - 0 = opaque, 1 = invisible
    }

    namespace Descriptor {
        inline constexpr uintptr_t Name = 0x8; // Name
    }

    namespace EngineDetections { // Hyperion detection flag DWORDs reported through the RBX::PingItem telemetry serializer. Nonzero/non-initial value = that detection fired. Static RVAs from static analysis of this build - not empirically scanned.
        inline constexpr uintptr_t dwDetectionFlag_0 = 0x7EAD1C8; // Detection flag #0 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 0
        inline constexpr uintptr_t dwDetectionFlag_1 = 0x7EAD1CC; // Detection flag #1 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 1
        inline constexpr uintptr_t dwDetectionFlag_10 = 0x7EDE53C; // Detection flag #10 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 10
        inline constexpr uintptr_t dwDetectionFlag_11 = 0x7EDEB98; // Detection flag #11 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 11
        inline constexpr uintptr_t dwDetectionFlag_12 = 0x7EDEB9C; // Detection flag #12 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 12
        inline constexpr uintptr_t dwDetectionFlag_13 = 0x7EE6B20; // Detection flag #13 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 13
        inline constexpr uintptr_t dwDetectionFlag_14 = 0x7EE6B24; // Detection flag #14 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 14
        inline constexpr uintptr_t dwDetectionFlag_15 = 0x7EE6B28; // Detection flag #15 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 15
        inline constexpr uintptr_t dwDetectionFlag_16 = 0x7EE6B2C; // Detection flag #16 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 16
        inline constexpr uintptr_t dwDetectionFlag_17 = 0x7EE6B30; // Detection flag #17 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 17
        inline constexpr uintptr_t dwDetectionFlag_2 = 0x7ED1E3C; // Detection flag #2 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 2
        inline constexpr uintptr_t dwDetectionFlag_3 = 0x7ED217C; // Detection flag #3 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 3
        inline constexpr uintptr_t dwDetectionFlag_4 = 0x7ED3E28; // Detection flag #4 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 4
        inline constexpr uintptr_t dwDetectionFlag_5 = 0x7ED3E2C; // Detection flag #5 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 5
        inline constexpr uintptr_t dwDetectionFlag_6 = 0x7EDDA9C; // Detection flag #6 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 6
        inline constexpr uintptr_t dwDetectionFlag_7 = 0x7EDE2AC; // Detection flag #7 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 7
        inline constexpr uintptr_t dwDetectionFlag_8 = 0x7EDE33C; // Detection flag #8 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 8
        inline constexpr uintptr_t dwDetectionFlag_9 = 0x7EDE538; // Detection flag #9 - referenced by PingItem serializer; absolute RVA, build-specific - Detection Flag 9
    }

    namespace FaceControls {
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ChinRaiser = 0xE0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ChinRaiserUpperLip = 0xE4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Corrugator = 0xE8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t EyesLookDown = 0xEC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t EyesLookLeft = 0xF0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t EyesLookRight = 0xF4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t EyesLookUp = 0xF8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t FlatPucker = 0xFC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Funneler = 0x100; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t InternalOverrideFACSData = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t JawDrop = 0x104; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t JawLeft = 0x108; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t JawRight = 0x10C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftBrowLowerer = 0x110; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftCheekPuff = 0x114; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftCheekRaiser = 0x118; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftDimpler = 0x11C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftEyeClosed = 0x120; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftEyeUpperLidRaiser = 0x124; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftInnerBrowRaiser = 0x530; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftLipCornerDown = 0x12C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftLipCornerPuller = 0x130; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftLipStretcher = 0x134; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftLowerLipDepressor = 0x138; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftNoseWrinkler = 0x544; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftOuterBrowRaiser = 0x140; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LeftUpperLipRaiser = 0x144; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LipPresser = 0x148; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LipsTogether = 0x14C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LowerLipSuck = 0x150; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouthLeft = 0x154; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouthRight = 0x158; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Pucker = 0x15C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightBrowLowerer = 0x568; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightCheekPuff = 0x164; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightCheekRaiser = 0x168; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightDimpler = 0x16C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightEyeClosed = 0x170; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightEyeUpperLidRaiser = 0x174; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightInnerBrowRaiser = 0x178; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightLipCornerDown = 0x17C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightLipCornerPuller = 0x180; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightLipStretcher = 0x184; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightLowerLipDepressor = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightNoseWrinkler = 0x18C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightOuterBrowRaiser = 0x598; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightUpperLipRaiser = 0x194; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TongueDown = 0x198; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TongueOut = 0x19C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TongueUp = 0x1A0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UpperLipSuck = 0x1A4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace FakeDataModel { // global entry: *(module + Pointer) = FakeDataModel
        inline constexpr uintptr_t Pointer = 0x8CA9CC8; // Pointer
        inline constexpr uintptr_t Pointer = 0x8CA9CC8; // global holding the fake DataModel instance - external attach chain entry - Pointer
        inline constexpr uintptr_t RealDataModel = 0x1F8; // *(*FakeDataModelPtr) - offset of the real DataModel pointer inside FakeDataModel
    }

    namespace FileMeshData {
        inline constexpr uintptr_t AabbMax = 0x2BC; // Aabb Max
        inline constexpr uintptr_t AabbMin = 0x2B0; // Aabb Min
        inline constexpr uintptr_t Faces = 0x30; // Faces
        inline constexpr uintptr_t FacesEnd = 0x38; // Faces End
        inline constexpr uintptr_t Vertices = 0x0; // Vertices
        inline constexpr uintptr_t VerticesEnd = 0x8; // Vertices End
    }

    namespace Fire { // fire particle effect
        inline constexpr uintptr_t FireProximityPrompt = 0x309BD00; // Fire Proximity Prompt
        inline constexpr uintptr_t Heat = 0xD8; // DataModel>Workspace>TestPartN>SkidFireN - fire heat intensity
        inline constexpr uintptr_t Size = 0xDC; // DataModel>Workspace>TestPartN>SkidFireN - fire effect size
    }

    namespace Folder {
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ReplicatedGuiInsertionOrder = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace Frame {
        inline constexpr uintptr_t AbsoluteSize = 0x135; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Active = 0x57C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ActiveQueryNames = 0x3E0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnchorPoint = 0x500; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AutoLocalize = 0x65; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AutomaticSize = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BorderMode = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BorderSizePixel = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ClippedRect = 0x65; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ClipsDescendants = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DragBeginConnectionCount = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DragStoppedConnectionCount = 0xBC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Draggable = 0xF2; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t GuiState = 0x578; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t InputSink = 0x57C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Interactable = 0x5AB; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsNotOccluded = 0x65; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LayoutOrder = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseEnterConnectionCount = 0xCC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseLeaveConnectionCount = 0xD0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseMovedConnectionCount = 0xD4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseWheelBackwardConnectionCount = 0xD8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseWheelForwardConnectionCount = 0x594; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NextSelectionDown = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NextSelectionLeft = 0x4D8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NextSelectionRight = 0x4E8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NextSelectionUp = 0x4F8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Position = 0x598; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RawRect2D = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ReplicatedInsertionOrder = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RootLocalizationTable = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Rotation = 0x598; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Selectable = 0x520; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorDown = 0x50; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorLeft = 0x54; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorRight = 0x58; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorUp = 0x5C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionGroup = 0x60; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionImageObject = 0x500; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionOrder = 0x53C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionRect2D = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Size = 0x520; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SizeConstraint = 0x578; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TotalGroupScale = 0x60; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Transparency = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Visible = 0x57C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ZIndex = 0x57C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace FunctionDescriptor {
        inline constexpr uintptr_t Function = 0x80; // Function
    }

    namespace Functions {
        inline constexpr uintptr_t Clone = 0x1619170; // better to resolve at runtime via func descriptors - Clone
        inline constexpr uintptr_t Destroy = 0x1619190; // better to resolve at runtime via func descriptors - Destroy
        inline constexpr uintptr_t FindPartOnRay = 0xEB3460; // better to resolve at runtime via func descriptors - Find Part On Ray
        inline constexpr uintptr_t FindPartOnRayWithIgnoreList = 0xEB34E0; // better to resolve at runtime via func descriptors - Find Part On Ray With Ignore List
        inline constexpr uintptr_t FindPartOnRayWithWhitelist = 0xEB3570; // better to resolve at runtime via func descriptors - Find Part On Ray With Whitelist
        inline constexpr uintptr_t FireServer = 0xC99010; // better to resolve at runtime via func descriptors - Fire Server
        inline constexpr uintptr_t Print = 0x1C68FE0; // Print
        inline constexpr uintptr_t RaisePropertyChanged = 0xF5F550; // Raise Property Changed
        inline constexpr uintptr_t Raycast = 0xEAAA10; // better to resolve at runtime via func descriptors - Raycast
        inline constexpr uintptr_t SetParent = 0xB084E8; // Set Parent
        inline constexpr uintptr_t SetParentInternal = 0x1CB1AD0; // Set Parent Internal
        inline constexpr uintptr_t Shapecast = 0xEAC3D0; // better to resolve at runtime via func descriptors - Shapecast
    }

    namespace GuiBase2D {
        inline constexpr uintptr_t AbsolutePosition = 0x108; // Absolute Position
        inline constexpr uintptr_t AbsoluteRotation = 0xE8; // Absolute Rotation
        inline constexpr uintptr_t AbsoluteSize = 0x114; // Absolute Size
    }

    namespace GuiObject {
        inline constexpr uintptr_t Active = 0x5A8; // Active
        inline constexpr uintptr_t AnchorPoint = 0x558; // Anchor Point
        inline constexpr uintptr_t AutomaticSize = 0x560; // Automatic Size
        inline constexpr uintptr_t BackgroundColor3 = 0x540; // Background Color3
        inline constexpr uintptr_t BackgroundTransparency = 0x564; // Background Transparency
        inline constexpr uintptr_t BorderColor3 = 0x54C; // Border Color3
        inline constexpr uintptr_t BorderMode = 0x568; // Border Mode
        inline constexpr uintptr_t BorderSizePixel = 0x56C; // Border Size Pixel
        inline constexpr uintptr_t ClipsDescendants = 0x5A9; // Clips Descendants
        inline constexpr uintptr_t GuiState = 0x578; // Gui State
        inline constexpr uintptr_t Interactable = 0x5AB; // Interactable
        inline constexpr uintptr_t LayoutOrder = 0x580; // Layout Order
        inline constexpr uintptr_t Position = 0x510; // Position
        inline constexpr uintptr_t Rotation = 0xE8; // Rotation
        inline constexpr uintptr_t Selectable = 0x5AC; // Selectable
        inline constexpr uintptr_t SelectionOrder = 0x59C; // Selection Order
        inline constexpr uintptr_t Size = 0x530; // Size
        inline constexpr uintptr_t SizeConstraint = 0x5A0; // Size Constraint
        inline constexpr uintptr_t Visible = 0x5AD; // Visible
        inline constexpr uintptr_t ZIndex = 0x5A4; // Z Index
    }

    namespace Highlight { // selection highlight effect
        inline constexpr uintptr_t Adornee = 0xB8; // instance being highlighted
        inline constexpr uintptr_t DepthMode = 0xE0; // Depth Mode
        inline constexpr uintptr_t Enabled = 0xF4; // Enabled
        inline constexpr uintptr_t FillColor = 0xC8; // highlight fill color
        inline constexpr uintptr_t FillTransparency = 0xE4; // Fill Transparency
        inline constexpr uintptr_t OutlineColor = 0xD4; // highlight outline color
        inline constexpr uintptr_t OutlineTransparency = 0xEC; // Outline Transparency
    }

    namespace HopperBin {
        inline constexpr uintptr_t BinType = 0x468; // Bin Type
    }

    namespace Humanoid { // character controller (walk speed, jump, state)
        inline constexpr uintptr_t AutoJumpEnabled = 0x1D4; // auto-jump on obstacles (mobile style)
        inline constexpr uintptr_t AutoRotate = 0x1D5; // whether the humanoid turns to face movement direction
        inline constexpr uintptr_t AutomaticScalingEnabled = 0x1D6; // auto-scale animations to body proportions
        inline constexpr uintptr_t BreakJointsOnDeath = 0x1D7; // joints break on death when true
        inline constexpr uintptr_t CameraOffset = 0x128; // camera offset relative to the humanoid head
        inline constexpr uintptr_t DisplayDistanceType = 0x180; // Display Distance Type
        inline constexpr uintptr_t DisplayName = 0xB8; // name shown above the character
        inline constexpr uintptr_t EvaluateStateMachine = 0x1D8; // engine state machine enabled
        inline constexpr uintptr_t Health = 0x190; // scanned for 67.f = 67 - current health
        inline constexpr uintptr_t HealthDisplayDistance = 0x188; // max distance at which health bar shows
        inline constexpr uintptr_t HealthDisplayType = 0x18C; // when the health bar is displayed
        inline constexpr uintptr_t HipHeight = 0x194; // distance of torso above the ground
        inline constexpr uintptr_t JumpHeight = 0x1A0; // jump height in studs (modern mode)
        inline constexpr uintptr_t JumpPower = 0x1A4; // jump impulse strength (legacy mode)
        inline constexpr uintptr_t MaxHealth = 0x1A8; // maximum health
        inline constexpr uintptr_t MaxSlopeAngle = 0x1AC; // steepest walkable slope in degrees
        inline constexpr uintptr_t NameDisplayDistance = 0x1B0; // max distance at which name shows
        inline constexpr uintptr_t NameOcclusion = 0x1B4; // name occlusion behaviour behind walls
        inline constexpr uintptr_t PlatformStand = 0x1DC; // DataModel>Workspace>Characters>TestCharN>Humanoid - when true the humanoid ignores input (ragdoll-ish)
        inline constexpr uintptr_t RequiresNeck = 0x1DD; // humanoid dies without a Neck joint when true
        inline constexpr uintptr_t RigType = 0x1C0; // R6 or R15 skeleton
        inline constexpr uintptr_t SeatPart = 0x108; // pointer to the seat being sat on (null if standing)
        inline constexpr uintptr_t Sit = 0x1DE; // whether the humanoid is seated
        inline constexpr uintptr_t TargetPoint = 0x14C; // current MoveTo target point
        inline constexpr uintptr_t UseJumpPower = 0x1E0; // true = use JumpPower, false = use JumpHeight
        inline constexpr uintptr_t WalkSpeed = 0x1D0; // movement speed in studs/s (write to change speed)
        inline constexpr uintptr_t WalkSpeedCheck = 0x3BC; // duplicate WalkSpeed cache used by engine checks
        inline constexpr uintptr_t WalkToPoint = 0x164; // walk target point (same as TargetPoint usually)
    }

    namespace ICreator {
        inline constexpr uintptr_t Create = 0x0; // Create
    }

    namespace ImageLabel { // GUI image element
        inline constexpr uintptr_t ImageTransparency = 0xAA4; // DataModel>Workspace>SkidImage - 0 = opaque image
    }

    namespace InputObject {
        inline constexpr uintptr_t MousePosition = 0xD4; // Mouse Position
    }

    namespace Instance { // base of every Roblox object
        inline constexpr uintptr_t ChildrenEnd = 0x8; // one-past-end marker inside the children array
        inline constexpr uintptr_t ChildrenStart = 0x78; // children vector: array-of-slots pointer
        inline constexpr uintptr_t ClassDescriptor = 0x18; // pointer to RTTI class descriptor (per-class static)
        inline constexpr uintptr_t Name = 0x8; // offset of the name chars inside the name container
        inline constexpr uintptr_t NameContainer = 0x70; // pointer to this instance's name string object
        inline constexpr uintptr_t Parent = 0x68; // pointer to the parent instance
    }

    namespace IntValue { // int container
        inline constexpr uintptr_t Value = 0xB8; // DataModel>Workspace>SkidValueN - the int payload
    }

    namespace Light { // point/surface light source
        inline constexpr uintptr_t Brightness = 0xCC; // DataModel>Workspace>TestPartN>SkidLightN - Brightness
        inline constexpr uintptr_t Range = 0xD8; // DataModel>Workspace>TestPartN>SkidLightN - Range
    }

    namespace Lighting { // lighting/atmosphere settings
        inline constexpr uintptr_t Ambient = 0xD0; // Ambient
        inline constexpr uintptr_t Atmosphere = 0x1D8; // Atmosphere
        inline constexpr uintptr_t Brightness = 0x118; // scanned for 3.567f = 3.567 - light brightness multiplier
        inline constexpr uintptr_t ClockTime = 0xC8; // scanned for 32400000000 = 32400000000 - time of day in seconds since midnight * 1000000
        inline constexpr uintptr_t ColorShift_Bottom = 0xDC; // Color Shift Bottom
        inline constexpr uintptr_t ColorShift_Top = 0xE8; // Color Shift Top
        inline constexpr uintptr_t EnvironmentDiffuseScale = 0x11C; // scanned for 0.678 = 0.678 - Environment Diffuse Scale
        inline constexpr uintptr_t EnvironmentSpecularScale = 0x120; // scanned for 0.762 = 0.762 - Environment Specular Scale
        inline constexpr uintptr_t ExposureCompensation = 0x124; // scanned for -1.572f = -1.572 - Exposure Compensation
        inline constexpr uintptr_t FogColor = 0xF4; // fog color
        inline constexpr uintptr_t FogEnd = 0x12C; // scanned for 60.456f = 60.456 - distance where fog is fully opaque
        inline constexpr uintptr_t FogStart = 0x130; // scanned for 123.456f = 123.456 - distance where fog starts
        inline constexpr uintptr_t OutdoorAmbient = 0x100; // Outdoor Ambient
        inline constexpr uintptr_t ShadowSoftness = 0x13C; // scanned for 0.456f = 0.456 - Shadow Softness
        inline constexpr uintptr_t Sky = 0x1C8; // Sky
    }

    namespace LightingParameters { // these are in the lighting service
        inline constexpr uintptr_t GeographicLatitude = 0x134; // scanned for 115.9 = 115.9 - Geographic Latitude
        inline constexpr uintptr_t LightColor = 0x15C; // Light Color
        inline constexpr uintptr_t LightDirection = 0x168; // Light Direction
        inline constexpr uintptr_t SkyAmbient = 0x150; // Sky Ambient
        inline constexpr uintptr_t SkyAmbient2 = 0x138; // Sky Ambient2
        inline constexpr uintptr_t Source = 0x174; // Source
        inline constexpr uintptr_t TrueMoonPosition = 0x184; // True Moon Position
        inline constexpr uintptr_t TrueSunPosition = 0x178; // True Sun Position
    }

    namespace LinearVelocity { // physics velocity constraint
        inline constexpr uintptr_t MaxForce = 0x190; // DataModel>Workspace>SkidLinVelN - force cap of the constraint
        inline constexpr uintptr_t VectorVelocity = 0x244; // DataModel>Workspace>SkidLinVelN - target velocity vector
    }

    namespace LocalScript {
        inline constexpr uintptr_t Bytecode = 0x190; // Bytecode
        inline constexpr uintptr_t Hash = 0x1A0; // Hash
    }

    namespace LruHolder {
        inline constexpr uintptr_t MemEnforcedLRUCache = 0x20; // Mem Enforced LRU Cache
    }

    namespace LruNode {
        inline constexpr uintptr_t CachedItem = 0x38; // Cached Item
        inline constexpr uintptr_t MeshId = 0x10; // Mesh Id
        inline constexpr uintptr_t Next = 0x0; // Next
    }

    namespace LuaPage {
        inline constexpr uintptr_t dwBlocksize = 0x24; // lua_Page blockSize - Blocksize
        inline constexpr uintptr_t dwFreenext = 0x30; // lua_Page freeNext - Freenext
        inline constexpr uintptr_t dwPagesize = 0x20; // lua_Page pageSize - Pagesize
        inline constexpr uintptr_t lpData = 0x40; // lua_Page data start - Data
        inline constexpr uintptr_t lpListnext = 0x8; // lua_Page list next page - Listnext
    }

    namespace LuaState {
        inline constexpr uintptr_t lpGlobalState = 0x20; // lua_State.globalState (global_State*) - root of the VM; from here the whole GC is reachable - Global State
    }

    namespace LuaTable {
        inline constexpr uintptr_t dwArraysize = 0x8; // Table.sizearray - Arraysize
        inline constexpr uintptr_t dwLsizenode = 0x5; // Table.lsizenode (log2 node size) - Lsizenode
        inline constexpr uintptr_t lpArray = 0x28; // Table.array (array part) - Array
        inline constexpr uintptr_t lpNode = 0x18; // Table.node (hash part) - Node
    }

    namespace LuauBase { // 'base' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        inline constexpr uintptr_t fpAssert = 0x26EBB40; // lua_CFunction body registered as 'base.assert' - Assert
        inline constexpr uintptr_t fpError = 0x26E6810; // lua_CFunction body registered as 'base.error' - Error
        inline constexpr uintptr_t fpGcinfo = 0x26EA470; // lua_CFunction body registered as 'base.gcinfo' - Gcinfo
        inline constexpr uintptr_t fpGetfenv = 0x26E7E70; // lua_CFunction body registered as 'base.getfenv' - Getfenv
        inline constexpr uintptr_t fpGetmetatable = 0x26E7250; // lua_CFunction body registered as 'base.getmetatable' - Getmetatable
        inline constexpr uintptr_t fpNewproxy = 0x26ECA60; // lua_CFunction body registered as 'base.newproxy' - Newproxy
        inline constexpr uintptr_t fpNext = 0x26EB090; // lua_CFunction body registered as 'base.next' - Next
        inline constexpr uintptr_t fpPrint = 0x26E63C0; // lua_CFunction body registered as 'base.print' - Print
        inline constexpr uintptr_t fpRawequal = 0x26E8160; // lua_CFunction body registered as 'base.rawequal' - Rawequal
        inline constexpr uintptr_t fpRawget = 0x26E8270; // lua_CFunction body registered as 'base.rawget' - Rawget
        inline constexpr uintptr_t fpRawlen = 0x26EA3D0; // lua_CFunction body registered as 'base.rawlen' - Rawlen
        inline constexpr uintptr_t fpRawset = 0x26E87C0; // lua_CFunction body registered as 'base.rawset' - Rawset
        inline constexpr uintptr_t fpSelect = 0x26EBBF0; // lua_CFunction body registered as 'base.select' - Select
        inline constexpr uintptr_t fpSetfenv = 0x26E7F30; // lua_CFunction body registered as 'base.setfenv' - Setfenv
        inline constexpr uintptr_t fpSetmetatable = 0x26E73D0; // lua_CFunction body registered as 'base.setmetatable' - Setmetatable
        inline constexpr uintptr_t fpTonumber = 0x26E6490; // lua_CFunction body registered as 'base.tonumber' - Tonumber
        inline constexpr uintptr_t fpTostring = 0x26ECA00; // lua_CFunction body registered as 'base.tostring' - Tostring
        inline constexpr uintptr_t fpType = 0x26EA490; // lua_CFunction body registered as 'base.type' - Type
        inline constexpr uintptr_t fpTypeof = 0x26EAA90; // lua_CFunction body registered as 'base.typeof' - Typeof
        inline constexpr uintptr_t relRegistryTable = 0x6313CE0; // luaL_Reg array registering 'base', 19 entries - Registry Table
    }

    namespace LuauBit32 { // 'bit32' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        inline constexpr uintptr_t fpAdd = 0x54E5D60; // lua_CFunction body registered as 'bit32.add' - Add
        inline constexpr uintptr_t fpArshift = 0x54E72F0; // lua_CFunction body registered as 'bit32.arshift' - Arshift
        inline constexpr uintptr_t fpBand = 0x54E6600; // lua_CFunction body registered as 'bit32.band' - Band
        inline constexpr uintptr_t fpBnot = 0x54E67F0; // lua_CFunction body registered as 'bit32.bnot' - Bnot
        inline constexpr uintptr_t fpBor = 0x54E6700; // lua_CFunction body registered as 'bit32.bor' - Bor
        inline constexpr uintptr_t fpBswap = 0x54E7AF0; // lua_CFunction body registered as 'bit32.bswap' - Bswap
        inline constexpr uintptr_t fpBtest = 0x54E7920; // lua_CFunction body registered as 'bit32.btest' - Btest
        inline constexpr uintptr_t fpBxor = 0x54E6840; // lua_CFunction body registered as 'bit32.bxor' - Bxor
        inline constexpr uintptr_t fpClamp = 0x54E7840; // lua_CFunction body registered as 'bit32.clamp' - Clamp
        inline constexpr uintptr_t fpCountlz = 0x54E7A80; // lua_CFunction body registered as 'bit32.countlz' - Countlz
        inline constexpr uintptr_t fpCountrz = 0x54E7A20; // lua_CFunction body registered as 'bit32.countrz' - Countrz
        inline constexpr uintptr_t fpCreate = 0x54E58C0; // lua_CFunction body registered as 'bit32.create' - Create
        inline constexpr uintptr_t fpDiv = 0x54E5EE0; // lua_CFunction body registered as 'bit32.div' - Div
        inline constexpr uintptr_t fpExtract = 0x54E74F0; // lua_CFunction body registered as 'bit32.extract' - Extract
        inline constexpr uintptr_t fpFromstring = 0x54E59D0; // lua_CFunction body registered as 'bit32.fromstring' - Fromstring
        inline constexpr uintptr_t fpGe = 0x54E6E80; // lua_CFunction body registered as 'bit32.ge' - Ge
        inline constexpr uintptr_t fpGt = 0x54E6D70; // lua_CFunction body registered as 'bit32.gt' - Gt
        inline constexpr uintptr_t fpIdiv = 0x54E5FC0; // lua_CFunction body registered as 'bit32.idiv' - Idiv
        inline constexpr uintptr_t fpLe = 0x54E6A40; // lua_CFunction body registered as 'bit32.le' - Le
        inline constexpr uintptr_t fpLrotate = 0x54E73D0; // lua_CFunction body registered as 'bit32.lrotate' - Lrotate
        inline constexpr uintptr_t fpLshift = 0x54E71B0; // lua_CFunction body registered as 'bit32.lshift' - Lshift
        inline constexpr uintptr_t fpLt = 0x54E6930; // lua_CFunction body registered as 'bit32.lt' - Lt
        inline constexpr uintptr_t fpMax = 0x54E64D0; // lua_CFunction body registered as 'bit32.max' - Max
        inline constexpr uintptr_t fpMin = 0x54E63A0; // lua_CFunction body registered as 'bit32.min' - Min
        inline constexpr uintptr_t fpMod = 0x54E6170; // lua_CFunction body registered as 'bit32.mod' - Mod
        inline constexpr uintptr_t fpMul = 0x54E5E60; // lua_CFunction body registered as 'bit32.mul' - Mul
        inline constexpr uintptr_t fpNeg = 0x54E5D10; // lua_CFunction body registered as 'bit32.neg' - Neg
        inline constexpr uintptr_t fpRem = 0x54E60B0; // lua_CFunction body registered as 'bit32.rem' - Rem
        inline constexpr uintptr_t fpReplace = 0x54E7670; // lua_CFunction body registered as 'bit32.replace' - Replace
        inline constexpr uintptr_t fpRrotate = 0x54E7460; // lua_CFunction body registered as 'bit32.rrotate' - Rrotate
        inline constexpr uintptr_t fpRshift = 0x54E7250; // lua_CFunction body registered as 'bit32.rshift' - Rshift
        inline constexpr uintptr_t fpSub = 0x54E5DE0; // lua_CFunction body registered as 'bit32.sub' - Sub
        inline constexpr uintptr_t fpTonumber = 0x54E5C60; // lua_CFunction body registered as 'bit32.tonumber' - Tonumber
        inline constexpr uintptr_t fpUdiv = 0x54E6260; // lua_CFunction body registered as 'bit32.udiv' - Udiv
        inline constexpr uintptr_t fpUge = 0x54E70A0; // lua_CFunction body registered as 'bit32.uge' - Uge
        inline constexpr uintptr_t fpUgt = 0x54E6F90; // lua_CFunction body registered as 'bit32.ugt' - Ugt
        inline constexpr uintptr_t fpUle = 0x54E6C60; // lua_CFunction body registered as 'bit32.ule' - Ule
        inline constexpr uintptr_t fpUlt = 0x54E6B50; // lua_CFunction body registered as 'bit32.ult' - Ult
        inline constexpr uintptr_t fpUrem = 0x54E6300; // lua_CFunction body registered as 'bit32.urem' - Urem
        inline constexpr uintptr_t relRegistryTable = 0x652C100; // luaL_Reg array registering 'bit32', 39 entries - Registry Table
    }

    namespace LuauBuffer { // 'buffer' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        inline constexpr uintptr_t fpCopy = 0x54FEC00; // lua_CFunction body registered as 'buffer.copy' - Copy
        inline constexpr uintptr_t fpCreate = 0x54FD880; // lua_CFunction body registered as 'buffer.create' - Create
        inline constexpr uintptr_t fpFill = 0x54FEEF0; // lua_CFunction body registered as 'buffer.fill' - Fill
        inline constexpr uintptr_t fpFromstring = 0x54FD930; // lua_CFunction body registered as 'buffer.fromstring' - Fromstring
        inline constexpr uintptr_t fpLen = 0x54FEB50; // lua_CFunction body registered as 'buffer.len' - Len
        inline constexpr uintptr_t fpReadbits = 0x54FF140; // lua_CFunction body registered as 'buffer.readbits' - Readbits
        inline constexpr uintptr_t fpReadf32 = 0x54FFF00; // lua_CFunction body registered as 'buffer.readf32' - Readf32
        inline constexpr uintptr_t fpReadf64 = 0x5500060; // lua_CFunction body registered as 'buffer.readf64' - Readf64
        inline constexpr uintptr_t fpReadi16 = 0x54FF980; // lua_CFunction body registered as 'buffer.readi16' - Readi16
        inline constexpr uintptr_t fpReadi32 = 0x54FFC40; // lua_CFunction body registered as 'buffer.readi32' - Readi32
        inline constexpr uintptr_t fpReadi8 = 0x54FF6C0; // lua_CFunction body registered as 'buffer.readi8' - Readi8
        inline constexpr uintptr_t fpReadinteger = 0x54FDF80; // lua_CFunction body registered as 'buffer.readinteger' - Readinteger
        inline constexpr uintptr_t fpReadstring = 0x54FE1D0; // lua_CFunction body registered as 'buffer.readstring' - Readstring
        inline constexpr uintptr_t fpReadu16 = 0x54FFAE0; // lua_CFunction body registered as 'buffer.readu16' - Readu16
        inline constexpr uintptr_t fpReadu32 = 0x54FFDA0; // lua_CFunction body registered as 'buffer.readu32' - Readu32
        inline constexpr uintptr_t fpReadu8 = 0x54FF820; // lua_CFunction body registered as 'buffer.readu8' - Readu8
        inline constexpr uintptr_t fpTostring = 0x54FDA00; // lua_CFunction body registered as 'buffer.tostring' - Tostring
        inline constexpr uintptr_t fpWritebits = 0x54FF380; // lua_CFunction body registered as 'buffer.writebits' - Writebits
        inline constexpr uintptr_t fpWritef32 = 0x5500640; // lua_CFunction body registered as 'buffer.writef32' - Writef32
        inline constexpr uintptr_t fpWritef64 = 0x55007D0; // lua_CFunction body registered as 'buffer.writef64' - Writef64
        inline constexpr uintptr_t fpWritei16 = 0x5500340; // lua_CFunction body registered as 'buffer.writei16' - Writei16
        inline constexpr uintptr_t fpWritei32 = 0x55004C0; // lua_CFunction body registered as 'buffer.writei32' - Writei32
        inline constexpr uintptr_t fpWritei8 = 0x55001C0; // lua_CFunction body registered as 'buffer.writei8' - Writei8
        inline constexpr uintptr_t fpWriteinteger = 0x54FE090; // lua_CFunction body registered as 'buffer.writeinteger' - Writeinteger
        inline constexpr uintptr_t fpWritestring = 0x54FE8B0; // lua_CFunction body registered as 'buffer.writestring' - Writestring
        inline constexpr uintptr_t fpWriteu16 = 0x5500340; // lua_CFunction body registered as 'buffer.writeu16' - Writeu16
        inline constexpr uintptr_t fpWriteu32 = 0x55004C0; // lua_CFunction body registered as 'buffer.writeu32' - Writeu32
        inline constexpr uintptr_t fpWriteu8 = 0x55001C0; // lua_CFunction body registered as 'buffer.writeu8' - Writeu8
        inline constexpr uintptr_t relRegistryTable = 0x652CAD0; // luaL_Reg array registering 'buffer', 28 entries - Registry Table
    }

    namespace LuauCoroutine { // 'coroutine' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        inline constexpr uintptr_t fpClose = 0x5504330; // lua_CFunction body registered as 'coroutine.close' - Close
        inline constexpr uintptr_t fpCreate = 0x55039B0; // lua_CFunction body registered as 'coroutine.create' - Create
        inline constexpr uintptr_t fpIsyieldable = 0x55042B0; // lua_CFunction body registered as 'coroutine.isyieldable' - Isyieldable
        inline constexpr uintptr_t fpRunning = 0x5504240; // lua_CFunction body registered as 'coroutine.running' - Running
        inline constexpr uintptr_t fpStatus = 0x5502340; // lua_CFunction body registered as 'coroutine.status' - Status
        inline constexpr uintptr_t fpWrap = 0x5503F60; // lua_CFunction body registered as 'coroutine.wrap' - Wrap
        inline constexpr uintptr_t fpYield = 0x55041E0; // lua_CFunction body registered as 'coroutine.yield' - Yield
        inline constexpr uintptr_t relRegistryTable = 0x652CE50; // luaL_Reg array registering 'coroutine', 7 entries - Registry Table
    }

    namespace LuauDebug { // 'debug' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        inline constexpr uintptr_t fpDumpcodesize = 0x4180630; // lua_CFunction body registered as 'debug.dumpcodesize' - Dumpcodesize
        inline constexpr uintptr_t fpDumpheap = 0x4180600; // lua_CFunction body registered as 'debug.dumpheap' - Dumpheap
        inline constexpr uintptr_t fpDumprefs = 0x4180610; // lua_CFunction body registered as 'debug.dumprefs' - Dumprefs
        inline constexpr uintptr_t fpGetmemorycategory = 0x41804C0; // lua_CFunction body registered as 'debug.getmemorycategory' - Getmemorycategory
        inline constexpr uintptr_t fpLoadmodule = 0x41804B0; // lua_CFunction body registered as 'debug.loadmodule' - Loadmodule
        inline constexpr uintptr_t fpProfilebegin = 0x4180230; // lua_CFunction body registered as 'debug.profilebegin' - Profilebegin
        inline constexpr uintptr_t fpProfileend = 0x4180350; // lua_CFunction body registered as 'debug.profileend' - Profileend
        inline constexpr uintptr_t fpResetmemorycategory = 0x4180500; // lua_CFunction body registered as 'debug.resetmemorycategory' - Resetmemorycategory
        inline constexpr uintptr_t fpSetmemorycategory = 0x41804F0; // lua_CFunction body registered as 'debug.setmemorycategory' - Setmemorycategory
        inline constexpr uintptr_t fpTracerefs = 0x4180620; // lua_CFunction body registered as 'debug.tracerefs' - Tracerefs
        inline constexpr uintptr_t relRegistryTable = 0x64F2560; // luaL_Reg array registering 'debug', 10 entries - Registry Table
    }

    namespace LuauGlobalState {
        inline constexpr uintptr_t bCurrentwhite = 0x58; // global_State.currentwhite GC mark bits - Currentwhite
        inline constexpr uintptr_t lpAllgcopages = 0x2F0; // global_State.allgcopages - head of the lua_Page list holding every live GC object; walk pages via LuaPage::lpListnext, enumerate blocks via dwPagesize/dwBlocksize/lpData - Allgcopages
    }

    namespace LuauMath { // 'math' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        inline constexpr uintptr_t fpAbs = 0x54F89C0; // lua_CFunction body registered as 'math.abs' - Abs
        inline constexpr uintptr_t fpAcos = 0x54F90C0; // lua_CFunction body registered as 'math.acos' - Acos
        inline constexpr uintptr_t fpAsin = 0x54F8FE0; // lua_CFunction body registered as 'math.asin' - Asin
        inline constexpr uintptr_t fpAtan = 0x54F91A0; // lua_CFunction body registered as 'math.atan' - Atan
        inline constexpr uintptr_t fpAtan2 = 0x54F9280; // lua_CFunction body registered as 'math.atan2' - Atan2
        inline constexpr uintptr_t fpCeil = 0x54F93E0; // lua_CFunction body registered as 'math.ceil' - Ceil
        inline constexpr uintptr_t fpClamp = 0x54FB040; // lua_CFunction body registered as 'math.clamp' - Clamp
        inline constexpr uintptr_t fpCos = 0x54F8C60; // lua_CFunction body registered as 'math.cos' - Cos
        inline constexpr uintptr_t fpCosh = 0x54F8D40; // lua_CFunction body registered as 'math.cosh' - Cosh
        inline constexpr uintptr_t fpDeg = 0x54F9E10; // lua_CFunction body registered as 'math.deg' - Deg
        inline constexpr uintptr_t fpExp = 0x54F9D30; // lua_CFunction body registered as 'math.exp' - Exp
        inline constexpr uintptr_t fpFloor = 0x54F94C0; // lua_CFunction body registered as 'math.floor' - Floor
        inline constexpr uintptr_t fpFmod = 0x54F95A0; // lua_CFunction body registered as 'math.fmod' - Fmod
        inline constexpr uintptr_t fpFrexp = 0x54F9FD0; // lua_CFunction body registered as 'math.frexp' - Frexp
        inline constexpr uintptr_t fpIsfinite = 0x54FBAE0; // lua_CFunction body registered as 'math.isfinite' - Isfinite
        inline constexpr uintptr_t fpIsinf = 0x54FB9F0; // lua_CFunction body registered as 'math.isinf' - Isinf
        inline constexpr uintptr_t fpIsnan = 0x54FB910; // lua_CFunction body registered as 'math.isnan' - Isnan
        inline constexpr uintptr_t fpLdexp = 0x54FA0D0; // lua_CFunction body registered as 'math.ldexp' - Ldexp
        inline constexpr uintptr_t fpLerp = 0x54FB730; // lua_CFunction body registered as 'math.lerp' - Lerp
        inline constexpr uintptr_t fpLog = 0x54F9A90; // lua_CFunction body registered as 'math.log' - Log
        inline constexpr uintptr_t fpLog10 = 0x54F9C50; // lua_CFunction body registered as 'math.log10' - Log10
        inline constexpr uintptr_t fpMap = 0x54FB450; // lua_CFunction body registered as 'math.map' - Map
        inline constexpr uintptr_t fpMax = 0x54FA3A0; // lua_CFunction body registered as 'math.max' - Max
        inline constexpr uintptr_t fpMin = 0x54FA240; // lua_CFunction body registered as 'math.min' - Min
        inline constexpr uintptr_t fpModf = 0x54F9700; // lua_CFunction body registered as 'math.modf' - Modf
        inline constexpr uintptr_t fpNoise = 0x54FAD00; // lua_CFunction body registered as 'math.noise' - Noise
        inline constexpr uintptr_t fpPow = 0x54F9930; // lua_CFunction body registered as 'math.pow' - Pow
        inline constexpr uintptr_t fpRad = 0x54F9EF0; // lua_CFunction body registered as 'math.rad' - Rad
        inline constexpr uintptr_t fpRandom = 0x54FA500; // lua_CFunction body registered as 'math.random' - Random
        inline constexpr uintptr_t fpRandomseed = 0x54FA820; // lua_CFunction body registered as 'math.randomseed' - Randomseed
        inline constexpr uintptr_t fpRound = 0x54FB370; // lua_CFunction body registered as 'math.round' - Round
        inline constexpr uintptr_t fpSign = 0x54FB270; // lua_CFunction body registered as 'math.sign' - Sign
        inline constexpr uintptr_t fpSin = 0x54F8AA0; // lua_CFunction body registered as 'math.sin' - Sin
        inline constexpr uintptr_t fpSinh = 0x54F8B80; // lua_CFunction body registered as 'math.sinh' - Sinh
        inline constexpr uintptr_t fpSqrt = 0x54F9830; // lua_CFunction body registered as 'math.sqrt' - Sqrt
        inline constexpr uintptr_t fpTan = 0x54F8E20; // lua_CFunction body registered as 'math.tan' - Tan
        inline constexpr uintptr_t fpTanh = 0x54F8F00; // lua_CFunction body registered as 'math.tanh' - Tanh
        inline constexpr uintptr_t relRegistryTable = 0x652C870; // luaL_Reg array registering 'math', 37 entries - Registry Table
    }

    namespace LuauOs { // 'os' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        inline constexpr uintptr_t fpClock = 0x54EA720; // lua_CFunction body registered as 'os.clock' - Clock
        inline constexpr uintptr_t fpDate = 0x54EBCD0; // lua_CFunction body registered as 'os.date' - Date
        inline constexpr uintptr_t fpDifftime = 0x54EC6E0; // lua_CFunction body registered as 'os.difftime' - Difftime
        inline constexpr uintptr_t fpTime = 0x54EC3D0; // lua_CFunction body registered as 'os.time' - Time
        inline constexpr uintptr_t relRegistryTable = 0x652C410; // luaL_Reg array registering 'os', 4 entries - Registry Table
    }

    namespace LuauRoblox { // 'roblox' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        inline constexpr uintptr_t fpCollectgarbage = 0x40D0CE0; // lua_CFunction body registered as 'roblox.collectgarbage' - Collectgarbage
        inline constexpr uintptr_t fpDelay = 0x40D1510; // lua_CFunction body registered as 'roblox.delay' - Delay
        inline constexpr uintptr_t fpDelay = 0x40D1510; // lua_CFunction body registered as 'roblox.Delay' - Delay
        inline constexpr uintptr_t fpElapsedTime = 0x40D1D20; // lua_CFunction body registered as 'roblox.elapsedTime' - Elapsed Time
        inline constexpr uintptr_t fpElapsedTime = 0x40D1D20; // lua_CFunction body registered as 'roblox.ElapsedTime' - Elapsed Time
        inline constexpr uintptr_t fpGetfenv = 0x40D5490; // lua_CFunction body registered as 'roblox.getfenv' - Getfenv
        inline constexpr uintptr_t fpLoadstring = 0x40D1DA0; // lua_CFunction body registered as 'roblox.loadstring' - Loadstring
        inline constexpr uintptr_t fpPluginManager = 0x40D2510; // lua_CFunction body registered as 'roblox.PluginManager' - Plugin Manager
        inline constexpr uintptr_t fpPrint = 0x40D2A20; // lua_CFunction body registered as 'roblox.print' - Print
        inline constexpr uintptr_t fpPrintidentity = 0x40D2A40; // lua_CFunction body registered as 'roblox.printidentity' - Printidentity
        inline constexpr uintptr_t fpRequire = 0x40D2B30; // lua_CFunction body registered as 'roblox.require' - Require
        inline constexpr uintptr_t fpSetfenv = 0x40D55C0; // lua_CFunction body registered as 'roblox.setfenv' - Setfenv
        inline constexpr uintptr_t fpSettings = 0x40D3020; // lua_CFunction body registered as 'roblox.settings' - Settings
        inline constexpr uintptr_t fpSpawn = 0x40D3520; // lua_CFunction body registered as 'roblox.spawn' - Spawn
        inline constexpr uintptr_t fpSpawn = 0x40D3520; // lua_CFunction body registered as 'roblox.Spawn' - Spawn
        inline constexpr uintptr_t fpStats = 0x40D3D30; // lua_CFunction body registered as 'roblox.stats' - Stats
        inline constexpr uintptr_t fpStats = 0x40D3D30; // lua_CFunction body registered as 'roblox.Stats' - Stats
        inline constexpr uintptr_t fpTick = 0x40D4250; // lua_CFunction body registered as 'roblox.tick' - Tick
        inline constexpr uintptr_t fpTime = 0x40D42D0; // lua_CFunction body registered as 'roblox.time' - Time
        inline constexpr uintptr_t fpUserSettings = 0x40D44D0; // lua_CFunction body registered as 'roblox.UserSettings' - User Settings
        inline constexpr uintptr_t fpVersion = 0x40D4970; // lua_CFunction body registered as 'roblox.version' - Version
        inline constexpr uintptr_t fpVersion = 0x40D4970; // lua_CFunction body registered as 'roblox.Version' - Version
        inline constexpr uintptr_t fpWait = 0x40D4A40; // lua_CFunction body registered as 'roblox.wait' - Wait
        inline constexpr uintptr_t fpWait = 0x40D4A40; // lua_CFunction body registered as 'roblox.Wait' - Wait
        inline constexpr uintptr_t fpWarn = 0x40D4BF0; // lua_CFunction body registered as 'roblox.warn' - Warn
        inline constexpr uintptr_t relRegistryTable = 0x6BA9F00; // luaL_Reg array registering 'roblox', 25 entries - Registry Table
    }

    namespace LuauString { // 'string' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        inline constexpr uintptr_t fpByte = 0x54EDD90; // lua_CFunction body registered as 'string.byte' - Byte
        inline constexpr uintptr_t fpChar = 0x54EE020; // lua_CFunction body registered as 'string.char' - Char
        inline constexpr uintptr_t fpFind = 0x54EFC60; // lua_CFunction body registered as 'string.find' - Find
        inline constexpr uintptr_t fpFormat = 0x54F1C40; // lua_CFunction body registered as 'string.format' - Format
        inline constexpr uintptr_t fpGmatch = 0x54F0040; // lua_CFunction body registered as 'string.gmatch' - Gmatch
        inline constexpr uintptr_t fpGsub = 0x54F1630; // lua_CFunction body registered as 'string.gsub' - Gsub
        inline constexpr uintptr_t fpLen = 0x54EC890; // lua_CFunction body registered as 'string.len' - Len
        inline constexpr uintptr_t fpLower = 0x54ED500; // lua_CFunction body registered as 'string.lower' - Lower
        inline constexpr uintptr_t fpMatch = 0x54EFC70; // lua_CFunction body registered as 'string.match' - Match
        inline constexpr uintptr_t fpPack = 0x54F3830; // lua_CFunction body registered as 'string.pack' - Pack
        inline constexpr uintptr_t fpPacksize = 0x54F4190; // lua_CFunction body registered as 'string.packsize' - Packsize
        inline constexpr uintptr_t fpRep = 0x54ED7A0; // lua_CFunction body registered as 'string.rep' - Rep
        inline constexpr uintptr_t fpReverse = 0x54ED3B0; // lua_CFunction body registered as 'string.reverse' - Reverse
        inline constexpr uintptr_t fpSplit = 0x54F2270; // lua_CFunction body registered as 'string.split' - Split
        inline constexpr uintptr_t fpSub = 0x54EC940; // lua_CFunction body registered as 'string.sub' - Sub
        inline constexpr uintptr_t fpUnpack = 0x54F4500; // lua_CFunction body registered as 'string.unpack' - Unpack
        inline constexpr uintptr_t fpUpper = 0x54ED650; // lua_CFunction body registered as 'string.upper' - Upper
        inline constexpr uintptr_t relRegistryTable = 0x652C460; // luaL_Reg array registering 'string', 17 entries - Registry Table
    }

    namespace LuauTable { // 'table' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        inline constexpr uintptr_t fpClear = 0x54E4B40; // lua_CFunction body registered as 'table.clear' - Clear
        inline constexpr uintptr_t fpClone = 0x54E4D90; // lua_CFunction body registered as 'table.clone' - Clone
        inline constexpr uintptr_t fpConcat = 0x54E1B90; // lua_CFunction body registered as 'table.concat' - Concat
        inline constexpr uintptr_t fpCreate = 0x54E3EB0; // lua_CFunction body registered as 'table.create' - Create
        inline constexpr uintptr_t fpFind = 0x54E46A0; // lua_CFunction body registered as 'table.find' - Find
        inline constexpr uintptr_t fpForeach = 0x54DDE20; // lua_CFunction body registered as 'table.foreach' - Foreach
        inline constexpr uintptr_t fpForeachi = 0x54DD0C0; // lua_CFunction body registered as 'table.foreachi' - Foreachi
        inline constexpr uintptr_t fpFreeze = 0x54E4B90; // lua_CFunction body registered as 'table.freeze' - Freeze
        inline constexpr uintptr_t fpGetn = 0x54DF240; // lua_CFunction body registered as 'table.getn' - Getn
        inline constexpr uintptr_t fpInsert = 0x54E0310; // lua_CFunction body registered as 'table.insert' - Insert
        inline constexpr uintptr_t fpIsfrozen = 0x54E4CE0; // lua_CFunction body registered as 'table.isfrozen' - Isfrozen
        inline constexpr uintptr_t fpMaxn = 0x54DEF80; // lua_CFunction body registered as 'table.maxn' - Maxn
        inline constexpr uintptr_t fpMove = 0x54E0880; // lua_CFunction body registered as 'table.move' - Move
        inline constexpr uintptr_t fpPack = 0x54E1EB0; // lua_CFunction body registered as 'table.pack' - Pack
        inline constexpr uintptr_t fpRemove = 0x54E0510; // lua_CFunction body registered as 'table.remove' - Remove
        inline constexpr uintptr_t fpSort = 0x54E3D30; // lua_CFunction body registered as 'table.sort' - Sort
        inline constexpr uintptr_t fpUnpack = 0x54E26F0; // lua_CFunction body registered as 'table.unpack' - Unpack
        inline constexpr uintptr_t relRegistryTable = 0x652BFE0; // luaL_Reg array registering 'table', 17 entries - Registry Table
    }

    namespace LuauUtf8 { // 'utf8' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        inline constexpr uintptr_t fpChar = 0x54E8B30; // lua_CFunction body registered as 'utf8.char' - Char
        inline constexpr uintptr_t fpCodepoint = 0x54E8790; // lua_CFunction body registered as 'utf8.codepoint' - Codepoint
        inline constexpr uintptr_t fpCodes = 0x54E9810; // lua_CFunction body registered as 'utf8.codes' - Codes
        inline constexpr uintptr_t fpLen = 0x54E84B0; // lua_CFunction body registered as 'utf8.len' - Len
        inline constexpr uintptr_t fpOffset = 0x54E92C0; // lua_CFunction body registered as 'utf8.offset' - Offset
        inline constexpr uintptr_t relRegistryTable = 0x652C380; // luaL_Reg array registering 'utf8', 5 entries - Registry Table
    }

    namespace LuauVector { // 'vector' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        inline constexpr uintptr_t fpAbs = 0x54F7010; // lua_CFunction body registered as 'vector.abs' - Abs
        inline constexpr uintptr_t fpAngle = 0x54F6C40; // lua_CFunction body registered as 'vector.angle' - Angle
        inline constexpr uintptr_t fpCeil = 0x54F6F70; // lua_CFunction body registered as 'vector.ceil' - Ceil
        inline constexpr uintptr_t fpClamp = 0x54F7140; // lua_CFunction body registered as 'vector.clamp' - Clamp
        inline constexpr uintptr_t fpCreate = 0x54F66F0; // lua_CFunction body registered as 'vector.create' - Create
        inline constexpr uintptr_t fpCross = 0x54F6A70; // lua_CFunction body registered as 'vector.cross' - Cross
        inline constexpr uintptr_t fpDot = 0x54F6B40; // lua_CFunction body registered as 'vector.dot' - Dot
        inline constexpr uintptr_t fpFloor = 0x54F6ED0; // lua_CFunction body registered as 'vector.floor' - Floor
        inline constexpr uintptr_t fpLerp = 0x54F7680; // lua_CFunction body registered as 'vector.lerp' - Lerp
        inline constexpr uintptr_t fpMagnitude = 0x54F68A0; // lua_CFunction body registered as 'vector.magnitude' - Magnitude
        inline constexpr uintptr_t fpMax = 0x54F73D0; // lua_CFunction body registered as 'vector.max' - Max
        inline constexpr uintptr_t fpMin = 0x54F72B0; // lua_CFunction body registered as 'vector.min' - Min
        inline constexpr uintptr_t fpNormalize = 0x54F6990; // lua_CFunction body registered as 'vector.normalize' - Normalize
        inline constexpr uintptr_t fpSign = 0x54F7080; // lua_CFunction body registered as 'vector.sign' - Sign
        inline constexpr uintptr_t relRegistryTable = 0x652C580; // luaL_Reg array registering 'vector', 14 entries - Registry Table
    }

    namespace MaterialColors {
        inline constexpr uintptr_t Asphalt = 0x30; // Asphalt
        inline constexpr uintptr_t Basalt = 0x27; // Basalt
        inline constexpr uintptr_t Brick = 0xF; // Brick
        inline constexpr uintptr_t Cobblestone = 0x33; // Cobblestone
        inline constexpr uintptr_t Concrete = 0xC; // Concrete
        inline constexpr uintptr_t CrackedLava = 0x2D; // Cracked Lava
        inline constexpr uintptr_t Glacier = 0x1B; // Glacier
        inline constexpr uintptr_t Grass = 0x6; // Grass
        inline constexpr uintptr_t Ground = 0x2A; // Ground
        inline constexpr uintptr_t Ice = 0x36; // Ice
        inline constexpr uintptr_t LeafyGrass = 0x39; // Leafy Grass
        inline constexpr uintptr_t Limestone = 0x3F; // Limestone
        inline constexpr uintptr_t Mud = 0x24; // Mud
        inline constexpr uintptr_t Pavement = 0x42; // Pavement
        inline constexpr uintptr_t Rock = 0x18; // Rock
        inline constexpr uintptr_t Salt = 0x3C; // Salt
        inline constexpr uintptr_t Sand = 0x12; // Sand
        inline constexpr uintptr_t Sandstone = 0x21; // Sandstone
        inline constexpr uintptr_t Slate = 0x9; // Slate
        inline constexpr uintptr_t Snow = 0x1E; // Snow
        inline constexpr uintptr_t WoodPlanks = 0x15; // Wood Planks
    }

    namespace MemEnforcedLRUCache {
        inline constexpr uintptr_t Head = 0x8; // Head
    }

    namespace MeshContentProvider {
        inline constexpr uintptr_t LruHolder = 0xD8; // Lru Holder
    }

    namespace MeshPart {
        inline constexpr uintptr_t MeshId = 0x310; // Mesh Id
        inline constexpr uintptr_t TextureId = 0x340; // Texture Id
    }

    namespace Model {
        inline constexpr uintptr_t PrimaryPart = 0x258; // Primary Part
        inline constexpr uintptr_t Scale = 0x144; // Scale
    }

    namespace ModuleScript {
        inline constexpr uintptr_t Bytecode = 0x138; // Bytecode
        inline constexpr uintptr_t Hash = 0xD0; // Hash
        inline constexpr uintptr_t IsRobloxScript = 0x168; // Is Roblox Script
    }

    namespace Motor6D { // joint between two parts (animation bones)
        inline constexpr uintptr_t C0 = 0x3C0; // Motor6D>C0Container - joint offset on Part0 (translation)
        inline constexpr uintptr_t C0Container = 0x58; // DataModel>Workspace>TestPartN>SkidMotorN - pointer to joint coordinate sub-structure
        inline constexpr uintptr_t C1 = 0x3F0; // CFrame stride from C0 - joint offset on Part1 (translation)
    }

    namespace MouseService {
        inline constexpr uintptr_t InputObject = 0x100; // Input Object
    }

    namespace NumberValue { // double container
        inline constexpr uintptr_t Value = 0xB8; // DataModel>Workspace>SkidValueN - the double payload
    }

    namespace Pants { // pants template content
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Color3 = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Outfit1 = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Outfit1Content = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Outfit2 = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Outfit2Content = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PantsTemplate = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PantsTemplateContent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace Part {
        inline constexpr uintptr_t Anchored = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AssemblyAngularVelocity = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AssemblyCenterOfMass = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AssemblyLinearVelocity = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AssemblyMass = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AssemblyRootPart = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AudioCanCollide = 0x74; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BackParamA = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BackParamB = 0xCC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BackSurface = 0xD0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BackSurfaceInput = 0xD4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BottomParamA = 0xD8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BottomParamB = 0xDC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BrickColor = 0x1A8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CFrame = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CanCollide = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CanQuery = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CanTouch = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CastShadow = 0x75; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CenterOfMass = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CollisionGroup = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CollisionGroupId = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CollisionGroupReplicate = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Color = 0xE8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Color3uint8 = 0xE8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CurrentPhysicalProperties = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CustomPhysicalProperties = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DraggingV1 = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Elasticity = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ExtentsCFrame = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ExtentsSize = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Friction = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LocalTransparencyModifier = 0x48; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Locked = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Mass = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Massless = 0x137; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Material = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MaterialVariant = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MaterialVariantSerialized = 0xD0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NetworkIsSleeping = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NetworkOwnerV3 = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NetworkOwnershipRule = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Orientation = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Origin = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PhysicsRepRootPart = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PhysicsRepRootRef = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PivotOffset = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Position = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ReceiveAge = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Reflectance = 0x4C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ReplicationPV = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ResizeIncrement = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ResizeableFaces = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RightSurface = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RootPriority = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RotVelocity = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Rotation = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Size = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SpecificGravity = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TopSurface = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Transparency = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Velocity = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t brickColor = 0xE8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t shape = 0x300; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t size = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace ParticleEmitter { // particle effect emitter
        inline constexpr uintptr_t Enabled = 0x268; // DataModel>Workspace>SkidParticlesN - emitter active flag
        inline constexpr uintptr_t Rate = 0x248; // DataModel>Workspace>SkidParticlesN - particles spawned per second
    }

    namespace Player { // local player info
        inline constexpr uintptr_t AccountAge = 0x35C; // scanned for player_info->account_age = 1518 - account age in days
        inline constexpr uintptr_t CameraMaxZoomDistance = 0x368; // DataModel>Players>LocalPlayer | scanned for player_info->camera_max_zoom = 128 - max camera zoom-out distance
        inline constexpr uintptr_t CameraMinZoomDistance = 0x36C; // DataModel>Players>LocalPlayer | scanned for player_info->camera_min_zoom = 0.5 - min camera zoom-in distance
        inline constexpr uintptr_t Character = 0x298; // pointer to the player's character model
        inline constexpr uintptr_t DisplayName = 0x138; // display name string
        inline constexpr uintptr_t HealthDisplayDistance = 0x394; // scanned for 87.12f = 87.12 - health bar visibility distance
        inline constexpr uintptr_t LocaleId = 0x748; // locale string (e.g. en-us)
        inline constexpr uintptr_t NameDisplayDistance = 0x3A4; // scanned for 56.89f = 56.89 - name visibility distance
        inline constexpr uintptr_t Team = 0x2D8; // pointer to current Team
        inline constexpr uintptr_t TeamColor = 0x3B0; // scanned for 1004 = 1004 - BrickColor enum of the team
        inline constexpr uintptr_t UserId = 0xD0; // scanned for player_info->user_id = 3672944211 - account user ID
    }

    namespace Players {
        inline constexpr uintptr_t LocalPlayer = 0x130; // pointer to the local player
    }

    namespace PointLight {
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Brightness = 0x14; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Color = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Enabled = 0x18; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Range = 0x60; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Shadows = 0x19; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace Primitive { // per-part physics data (cframe, velocity, size)
        inline constexpr uintptr_t AssemblyAngularVelocity = 0x104; // angular velocity of the assembly (rad/s)
        inline constexpr uintptr_t AssemblyLinearVelocity = 0xF8; // linear velocity of the assembly (studs/s)
        inline constexpr uintptr_t CFrame = 0xC8; // full rotation matrix + position of the part
        inline constexpr uintptr_t Material = 0x246; // material enum value
        inline constexpr uintptr_t Orientation = 0xC8; // Orientation
        inline constexpr uintptr_t Part = 0x210; // back-pointer from Primitive to its BasePart
        inline constexpr uintptr_t Position = 0xEC; // world position (translation part of CFrame)
        inline constexpr uintptr_t PrimitiveFlags = 0x1B6; // Primitive Flags
        inline constexpr uintptr_t Rotation = 0xC8; // Rotation
        inline constexpr uintptr_t Size = 0x1BC; // part dimensions in studs
    }

    namespace PrimitiveFlags { // physics behavior bitfield (anchored/collide/touch/query)
        inline constexpr uintptr_t Anchored = 0x2; // bit: part is immovable
        inline constexpr uintptr_t CanCollide = 0x8; // bit: part participates in collisions
        inline constexpr uintptr_t CanQuery = 0x20; // bit: part is hit by raycasts
        inline constexpr uintptr_t CanTouch = 0x10; // bit: part fires Touched events
    }

    namespace PropertyDescriptor {
        inline constexpr uintptr_t GetSetImpl = 0x90; // Get Set Impl
        inline constexpr uintptr_t TType = 0x68; // T Type
    }

    namespace ProximityPrompt { // interact prompt
        inline constexpr uintptr_t ActionText = 0xB0; // Action Text
        inline constexpr uintptr_t Enabled = 0x136; // Enabled
        inline constexpr uintptr_t HoldDuration = 0x120; // Hold Duration
        inline constexpr uintptr_t KeyboardKeyCode = 0x124; // Keyboard Key Code
        inline constexpr uintptr_t MaxActivationDistance = 0x128; // Max Activation Distance
        inline constexpr uintptr_t ObjectText = 0xD0; // Object Text
        inline constexpr uintptr_t RequiresLineOfSight = 0x137; // Requires Line Of Sight
    }

    namespace RemoteEvent {
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace RemoteFunction {
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace RenderView { // render target info
        inline constexpr uintptr_t DeviceD3D11 = 0x8; // Device D3 D11
        inline constexpr uintptr_t LightingValid = 0x228; // scanned for 257 = 257 - Lighting Valid
        inline constexpr uintptr_t SkyboxValid = 0x28D; // Skybox Valid
    }

    namespace RigidConstraint {
        inline constexpr uintptr_t Active = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Attachment0 = 0x58; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Attachment1 = 0x78; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Color = 0x40; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Enabled = 0x9; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Visible = 0x44; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace ScreenGui {
        inline constexpr uintptr_t AbsoluteSize = 0x135; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ActiveQueryNames = 0x3E0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AutoLocalize = 0x65; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ClipToDeviceSafeArea = 0x14; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ClippedRect = 0x65; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DisplayOrder = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Enabled = 0xC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IgnoreGuiInset = 0x740; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IgnoresTitleBarReservation = 0x15; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsNotOccluded = 0x65; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t OnTopOfCoreBlur = 0x16; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RawRect2D = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ReplicatedInsertionOrder = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ResetOnSpawn = 0xD; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RootLocalizationTable = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SafeAreaCompatibility = 0xC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ScreenInsets = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorDown = 0x50; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorLeft = 0x54; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorRight = 0x58; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorUp = 0x5C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionGroup = 0x60; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TabKeyboardNavigation = 0xE; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TotalGroupScale = 0x60; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ZIndexBehavior = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace Script {
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CachedRemoteSource = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CachedRemoteSourceLoadState = 0x40; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Disabled = 0x30; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Enabled = 0x30; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsDifferentFromFileSystem = 0x20; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LinkedSource = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RunContext = 0x30; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SandboxedSource = 0x20; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ScriptGuid = 0x20; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Source = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace ScriptContext {
        inline constexpr uintptr_t RequireBypass = 0xA00; // Require Bypass
    }

    namespace Seat {
        inline constexpr uintptr_t Occupant = 0x210; // Occupant
    }

    namespace Shirt { // shirt template content
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Color3 = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Outfit1 = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Outfit1Content = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Outfit2 = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Outfit2Content = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace Sky {
        inline constexpr uintptr_t MoonAngularSize = 0x244; // scanned for 22.56f = 22.56 - Moon Angular Size
        inline constexpr uintptr_t MoonTextureId = 0xC8; // Moon Texture Id
        inline constexpr uintptr_t SkyboxBk = 0xF8; // Skybox Bk
        inline constexpr uintptr_t SkyboxDn = 0x128; // Skybox Dn
        inline constexpr uintptr_t SkyboxFt = 0x158; // Skybox Ft
        inline constexpr uintptr_t SkyboxLf = 0x188; // Skybox Lf
        inline constexpr uintptr_t SkyboxOrientation = 0x238; // Skybox Orientation
        inline constexpr uintptr_t SkyboxRt = 0x1B8; // Skybox Rt
        inline constexpr uintptr_t SkyboxUp = 0x1E8; // Skybox Up
        inline constexpr uintptr_t StarCount = 0x248; // scanned for 2346 = 2346 - Star Count
        inline constexpr uintptr_t SunAngularSize = 0x24C; // scanned for 11.98f = 11.98 - Sun Angular Size
        inline constexpr uintptr_t SunTextureId = 0x218; // Sun Texture Id
    }

    namespace Sound { // sound instance playback props
        inline constexpr uintptr_t Looped = 0x13D; // DataModel>Workspace>TestPartN>SkidSoundN - restart when finished
        inline constexpr uintptr_t MaxDistance = 0x120; // DataModel>Workspace>TestPartN>SkidSoundN - audible range in studs
        inline constexpr uintptr_t PlaybackSpeed = 0x11C; // DataModel>Workspace>TestPartN>SkidSoundN - pitch/speed multiplier (1 = normal)
        inline constexpr uintptr_t RollOffMinDistance = 0x124; // DataModel>Workspace>TestPartN>SkidSoundN - distance where volume rolloff begins
        inline constexpr uintptr_t Volume = 0x130; // DataModel>Workspace>TestPartN>SkidSoundN - volume 0-10
    }

    namespace SpawnLocation { // player spawn point
        inline constexpr uintptr_t Duration = 0x20; // DataModel>Workspace>SkidSpawn - forcefield duration on spawn
        inline constexpr uintptr_t Neutral = 0xD; // DataModel>Workspace>SkidSpawn - usable by any team
    }

    namespace SpecialMesh {
        inline constexpr uintptr_t MeshId = 0xF8; // Mesh Id
        inline constexpr uintptr_t Offset = 0xB8; // Offset
        inline constexpr uintptr_t Scale = 0xC4; // Scale
        inline constexpr uintptr_t TextureId = 0x128; // Texture Id
    }

    namespace SpotLight { // cone light source
        inline constexpr uintptr_t Angle = 0x4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Brightness = 0x14; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Color = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Enabled = 0x18; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Face = 0x4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Origin = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Range = 0x4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Shadows = 0x19; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SpecificGravity = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TopSurface = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Transparency = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Velocity = 0xC8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t brickColor = 0xE8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t size = 0x188; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace Status {
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LevelOfDetail = 0x7C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LodEntity = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ModelMeshCFrame = 0x40; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ModelMeshData = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ModelMeshSize = 0x198; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ModelStreamingMode = 0x80; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NeedsPivotMigration = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Origin = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PrimaryPart = 0x198; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Scale = 0x84; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ScaleFactor = 0x84; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SlimAnimationTarget = 0x20; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SlimHash = 0x198; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t WorldPivot = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t WorldPivotData = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace StringValue { // string container
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Value = 0xB8; // decoded from property getter - SSO string payload offset
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace TaskScheduler { // frame scheduler (fps cap, job list)
        inline constexpr uintptr_t JobEnd = 0xD0; // Job End
        inline constexpr uintptr_t JobName = 0x18; // Job Name
        inline constexpr uintptr_t JobStart = 0xC8; // Job Start
        inline constexpr uintptr_t MaxFps = 0xB0; // frame cap as frame-time double (1/fps); write smaller value for higher cap
        inline constexpr uintptr_t Pointer = 0x8A44D68; // Pointer
    }

    namespace Team { // team definition
        inline constexpr uintptr_t TeamColor = 0xB8; // BrickColor enum of the team
    }

    namespace Terrain {
        inline constexpr uintptr_t GrassLength = 0x1E8; // scanned for 0.722f = 0.722 - Grass Length
        inline constexpr uintptr_t MaterialColors = 0x4B0; // Material Colors
        inline constexpr uintptr_t WaterColor = 0x1D8; // Water Color
        inline constexpr uintptr_t WaterReflectance = 0x1F0; // scanned for 0.935f = 0.935 - Water Reflectance
        inline constexpr uintptr_t WaterTransparency = 0x1F4; // scanned for 0.323f = 0.323 - Water Transparency
        inline constexpr uintptr_t WaterWaveSize = 0x1F8; // scanned for 0.159f = 0.159 - Water Wave Size
        inline constexpr uintptr_t WaterWaveSpeed = 0x1FC; // scanned for 10.34f = 10.34 - Water Wave Speed
    }

    namespace TextButton {
        inline constexpr uintptr_t AbsoluteSize = 0x135; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Active = 0x57C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ActiveQueryNames = 0x3E0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnchorPoint = 0x500; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AutoButtonColor = 0x4C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AutoLocalize = 0x65; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AutomaticSize = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BorderMode = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BorderSizePixel = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ClippedRect = 0x65; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ClipsDescendants = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Confidential = 0xF4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ContentText = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DragBeginConnectionCount = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DragStoppedConnectionCount = 0xBC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Draggable = 0xF2; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Font = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t FontFace = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t GuiState = 0x578; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HoverHapticEffect = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t InputSink = 0x57C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Interactable = 0x5AB; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsNotOccluded = 0x65; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LayoutOrder = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LineHeight = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LocalizationMatchIdentifier = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LocalizationMatchedSourceText = 0x48; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LocalizedText = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MaxVisibleGraphemes = 0x48; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Modal = 0x4C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseButton1ClickConnectionCount = 0x30; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseButton1DownConnectionCount = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseButton1UpConnectionCount = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseButton2ClickConnectionCount = 0x3C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseButton2DownConnectionCount = 0x40; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseButton2UpConnectionCount = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseEnterConnectionCount = 0xCC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseLeaveConnectionCount = 0xD0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseMovedConnectionCount = 0xD4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseWheelBackwardConnectionCount = 0xD8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseWheelForwardConnectionCount = 0x594; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NextSelectionDown = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NextSelectionLeft = 0x4D8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NextSelectionRight = 0x4E8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NextSelectionUp = 0x4F8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Position = 0x598; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PressHapticEffect = 0x20; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RawRect2D = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ReplicatedInsertionOrder = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RichText = 0x48; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RootLocalizationTable = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Rotation = 0x598; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Selectable = 0x520; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Selected = 0x4E; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorDown = 0x50; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorLeft = 0x54; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorRight = 0x58; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorUp = 0x5C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionGroup = 0x60; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionImageObject = 0x500; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionOrder = 0x53C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionRect2D = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Size = 0x520; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SizeConstraint = 0x578; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Style = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Text = 0x48; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TotalGroupScale = 0x60; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Transparency = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Visible = 0x57C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ZIndex = 0x57C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace TextLabel {
        inline constexpr uintptr_t AbsoluteSize = 0x135; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Active = 0x57C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ActiveQueryNames = 0x3E0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AnchorPoint = 0x500; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AutoLocalize = 0x65; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AutomaticSize = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BorderMode = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t BorderSizePixel = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ClippedRect = 0x65; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ClipsDescendants = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Confidential = 0xEDC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ContentText = 0xDF0; // decoded from property getter - raw text content before rich-text processing
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DragBeginConnectionCount = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DragStoppedConnectionCount = 0xBC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Draggable = 0xF2; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t FontSize = 0xE08; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t GuiState = 0x578; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t InputSink = 0x57C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Interactable = 0x5AB; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsNotOccluded = 0x65; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LayoutOrder = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LocalizationMatchIdentifier = 0xE10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LocalizationMatchedSourceText = 0x48; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t LocalizedText = 0xE50; // decoded from property getter - localized text variant
        inline constexpr uintptr_t MaxVisibleGraphemes = 0x48; // decoded from property getter - grapheme reveal limit (-1 = all)
        inline constexpr uintptr_t MouseEnterConnectionCount = 0xCC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseLeaveConnectionCount = 0xD0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseMovedConnectionCount = 0xD4; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseWheelBackwardConnectionCount = 0xD8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MouseWheelForwardConnectionCount = 0x594; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NextSelectionDown = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NextSelectionLeft = 0x4D8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NextSelectionRight = 0x4E8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NextSelectionUp = 0x4F8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Position = 0x598; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RawRect2D = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ReplicatedInsertionOrder = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RichText = 0x48; // decoded from property getter - rich text markup enabled
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RootLocalizationTable = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Rotation = 0x598; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Selectable = 0x520; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorDown = 0x50; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorLeft = 0x54; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorRight = 0x58; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionBehaviorUp = 0x5C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionGroup = 0x60; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionImageObject = 0x500; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionOrder = 0x53C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SelectionRect2D = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Size = 0x520; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SizeConstraint = 0x578; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Text = 0x48; // decoded from property getter - the rendered text (SSO string)
        inline constexpr uintptr_t TotalGroupScale = 0x60; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Transparency = 0xB8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Visible = 0x57C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ZIndex = 0x57C; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace Texture {
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ColorMap = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ColorMapContent = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t EmissiveMaskContent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t EmissiveTint = 0x128; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Face = 0x10; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MetalnessMap = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t MetalnessMapContent = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NormalMap = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t NormalMapContent = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Rotation = 0x178; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RoughnessMap = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RoughnessMapContent = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t StudsPerTileV = 0x24; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TexturePack = 0x128; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TexturePackContent = 0x128; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TexturePackMetadata = 0x128; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UVOffset = 0x178; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UVScale = 0x178; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ZIndex = 0x178; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace Tool {
        inline constexpr uintptr_t CanBeDropped = 0x4B8; // Can Be Dropped
        inline constexpr uintptr_t Enabled = 0x4B9; // Enabled
        inline constexpr uintptr_t Grip = 0x488; // Grip
        inline constexpr uintptr_t GripForward = 0x4A0; // Grip Forward
        inline constexpr uintptr_t GripPos = 0x4AC; // Grip Pos
        inline constexpr uintptr_t GripRight = 0x488; // Grip Right
        inline constexpr uintptr_t GripUp = 0x494; // Grip Up
        inline constexpr uintptr_t ManualActivationOnly = 0x4BA; // Manual Activation Only
        inline constexpr uintptr_t RequiresHandle = 0x4BB; // Requires Handle
        inline constexpr uintptr_t Tooltip = 0x468; // Tooltip
    }

    namespace Value {
        inline constexpr uintptr_t Value = 0xB8; // generic ValueBase payload offset
    }

    namespace Vector3Value { // vector3 container
        inline constexpr uintptr_t Value = 0xB8; // DataModel>Workspace>SkidValueN - vector3 payload
    }

    namespace VehicleSeat {
        inline constexpr uintptr_t MaxSpeed = 0x228; // scanned for 456.2f = 456.2 - Max Speed
        inline constexpr uintptr_t Occupant = 0x208; // Occupant
        inline constexpr uintptr_t SteerFloat = 0x22C; // scanned for 0.256f = 0.256 - Steer Float
        inline constexpr uintptr_t ThrottleFloat = 0x230; // scanned for 0.412f = 0.412 - Throttle Float
        inline constexpr uintptr_t Torque = 0x234; // scanned for 108.1f = 108.1 - Torque
        inline constexpr uintptr_t TurnSpeed = 0x238; // scanned for 26.123f = 26.123 - Turn Speed
    }

    namespace VisualEngine { // renderer root (view matrix, render view)
        inline constexpr uintptr_t Dimensions = 0xAE0; // Dimensions
        inline constexpr uintptr_t FakeDataModel = 0xAC0; // Fake Data Model
        inline constexpr uintptr_t Pointer = 0x82E2128; // Pointer
        inline constexpr uintptr_t RenderView = 0xC00; // Render View
        inline constexpr uintptr_t ViewMatrix = 0x180; // View Matrix
    }

    namespace Weld {
        inline constexpr uintptr_t Active = 0x78; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t C0 = 0xD0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t C1 = 0xD0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t EnableSkinning = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Enabled = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Part0 = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Part1 = 0x78; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t part1 = 0x78; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace Wire {
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Connected = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceInstance = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceName = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TargetInstance = 0x60; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TargetName = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

    namespace Workspace { // 3D world container
        inline constexpr uintptr_t CurrentCamera = 0x498; // DataModel>Workspace>Camera child - pointer to the active Camera
        inline constexpr uintptr_t ReadOnlyGravity = 0x9C8; // DataModel>Workspace | scanned for expected_gravity = 196.2 - cached gravity value (studs/s^2)
        inline constexpr uintptr_t World = 0x3F0; // DataModel>Workspace>World (via gravity float) - pointer to the physics World
    }

    namespace World { // physics simulation container (gravity, sim rate, primitives)
        inline constexpr uintptr_t AirProperties = 0x238; // air density / global wind container
        inline constexpr uintptr_t Gravity = 0x228; // DataModel>Workspace>World - live gravity used by the solver (write to change fall speed)
        inline constexpr uintptr_t Primitives = 0x2A8; // array of every Primitive in the world
        inline constexpr uintptr_t dLastFrameTimeStamp = 0x3C0; // world step timing: double, last frame timestamp - D Last Frame Time Stamp
        inline constexpr uintptr_t dLastSendTimeStamp = 0x3C8; // world step timing: double, last send timestamp - D Last Send Time Stamp
        inline constexpr uintptr_t dWorldStepDt = 0x3D8; // world step timing: double, accumulated step drift (write to manipulate sim speed) - D World Step Dt
        inline constexpr uintptr_t dwLastNumberOfWorldStep = 0x3D0; // world step timing: dword, step count at last send - Last Number Of World Step
        inline constexpr uintptr_t dwWorldStepid = 0xE8; // world step counter: dword, monotonically incrementing - World Stepid
        inline constexpr uintptr_t fWorldStepsPerSecond = 0x720; // simulation steps-per-second scalar (write to change sim speed) - World Steps Per Second
    }

    namespace WorldRoot {
        inline constexpr uintptr_t RaycastBoundDesc = 0x8089F20; // Raycast Bound Desc
        inline constexpr uintptr_t RaycastBoundFn = 0x80; // Raycast Bound Fn
    }

    namespace WrapTarget {
        inline constexpr uintptr_t Archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t AttributesSerialize = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CageMeshContent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CageMeshId = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CageOrigin = 0xB0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t CageOriginWorld = 0xE0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Capabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Color = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DataCost = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DebugMode = 0x14; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t DefinesCapabilities = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HSRAssetId = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HSRContent = 0x38; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HSRData = 0xA0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HSRMeshIdData = 0x110; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t HistoryId = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ImportInProcess = 0x110; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t ImportOrigin = 0xE0; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t IsInSandbox = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Name = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Parent = 0x8; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PredictionMode = 0xAC; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t PropertyStatusStudio = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t RobloxLocked = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Sandboxed = 0xAA; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SerializedOverrides = 0x70; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t SourceAssetId = 0x88; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Stiffness = 0x18; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t Tags = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TemporaryCageMeshContent = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t TemporaryCageMeshId = 0x68; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t UniqueId = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t archivable = 0x4A; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
        inline constexpr uintptr_t numExpectedDirectChildren = 0x28; // decoded from property getter - instance offset recovered by disassembling this property's GetImpl getter
    }

} // namespace offsets
namespace FFlags {
    inline constexpr uintptr_t DFFlagCLI119 = 0x19B985E69BD; // Bool = false
    inline constexpr uintptr_t DFFlagCapturePlayerGuiScreenshotAndBuildVideos = 0x19B8E6126BD; // Bool = false
    inline constexpr uintptr_t DFFlagFixMonitorNullDerefOnBatchConnect = 0x19B84E6905D; // Bool = false
    inline constexpr uintptr_t DFFlagFixVoiceAvailabilityRetryInfiniteLoop = 0x19B84E68C50; // Unknown = 
    inline constexpr uintptr_t DFFlagGetHlsLodManifest2 = 0x19B8E61405D; // Bool = false
    inline constexpr uintptr_t DFFlagTextChatUserMessageIntentRaisedLimitEnabled = 0x19B949D71ED; // Bool = true
    inline constexpr uintptr_t DFStringContentProviderToAssetDeliveryMarkFromLodLoadStudy = 0x19B949E8EE0; // Unknown = 
    inline constexpr uintptr_t DFVideoStudioPreviewPermissionFix2 = 0x19B827AE310; // Unknown = 
    inline constexpr uintptr_t FFlagAEGIS2EnableGatesForExpChat = 0x19BA515711D; // Bool = false
    inline constexpr uintptr_t FFlagAEGIS2EnableGatesForExpChat6 = 0x19BA515931D; // Bool = false
    inline constexpr uintptr_t FFlagAEGIS2UseGuacToShowEnabledMessage = 0x19BACFD3A90; // Unknown = 
    inline constexpr uintptr_t FFlagAEGIS2UseGuacToShowFAEUpsell = 0x19BACFD5B10; // Unknown = 
    inline constexpr uintptr_t FFlagAEGISPhase2ShowImageOnFAEOverlay = 0x19B9F182E1D; // Bool = true
    inline constexpr uintptr_t FFlagAEGetEditableOutfitsType2 = 0x19B9026EB9D; // Bool = false
    inline constexpr uintptr_t FFlagAFPConnectionsChannelsHeader = 0x19B8C2E4610; // Unknown = 
    inline constexpr uintptr_t FFlagAIRephraseSettingEnabled3 = 0x19B8C302D5D; // Bool = true
    inline constexpr uintptr_t FFlagAXAccessoryAdjustmentReturnOnNil = 0x19BA3A538DD; // Bool = false
    inline constexpr uintptr_t FFlagAXAdaptiveScrollingFixForward = 0x19BBC7A0850; // Unknown = 
    inline constexpr uintptr_t FFlagAXAddFacesToHeadList = 0x19BA3A55850; // Unknown = 
    inline constexpr uintptr_t FFlagAXAddHDCatalogTab = 0x19BA3A50CD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXAddHDCatalogTooltip = 0x19BA3A55610; // Unknown = 
    inline constexpr uintptr_t FFlagAXAddHDRowInItemDetailsPage = 0x19B8F905850; // Unknown = 
    inline constexpr uintptr_t FFlagAXAddInventoryItemsListProps = 0x19BBC7A9690; // Unknown = 
    inline constexpr uintptr_t FFlagAXAddLimitedLabelForCheckout = 0x19BBC7A08D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXAddManageOutfitClickTracking = 0x19BBC7AC390; // Unknown = 
    inline constexpr uintptr_t FFlagAXAddManageOutfitClickTracking2 = 0x19BBC7AFB90; // Unknown = 
    inline constexpr uintptr_t FFlagAXAddNavigationKeyToEditorSubcategories2 = 0x19B9026E1DD; // Bool = false
    inline constexpr uintptr_t FFlagAXAddSearchTrendingChips2 = 0x19B8F905110; // Unknown = 
    inline constexpr uintptr_t FFlagAXAddSectionsToItemInfoRowPrompt = 0x19B8F907650; // Unknown = 
    inline constexpr uintptr_t FFlagAXAddTextXAlignmentProp = 0x19BBC7A69DD; // Bool = false
    inline constexpr uintptr_t FFlagAXAddToolTipToIconItemMenu = 0x19BBC7A2F9D; // Bool = false
    inline constexpr uintptr_t FFlagAXAddToolTipToIconItemMenu2 = 0x19BBC7AC090; // Unknown = 
    inline constexpr uintptr_t FFlagAXAddTransparencyToItemCardHeader = 0x19BBC7A86DD; // Bool = false
    inline constexpr uintptr_t FFlagAXAddV1CountersForMISPurchaseSuccess = 0x19B9F29CD90; // Unknown = 
    inline constexpr uintptr_t FFlagAXAnimatedLooksThumbnails = 0x19B90648B5D; // Bool = false
    inline constexpr uintptr_t FFlagAXAppLaunchedCounterEnabled = 0x19B90648210; // Unknown = 
    inline constexpr uintptr_t FFlagAXAppSystemBarEnableTelemtryForFPS = 0x19B90649190; // Unknown = 
    inline constexpr uintptr_t FFlagAXAppSystemBarEnableTelemtryForFPSForAll = 0x19B90649150; // Unknown = 
    inline constexpr uintptr_t FFlagAXAvatarEditorStoresContext = 0x19BBC7AABD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXAvatarFoldersEnabled = 0x19BBC7A8C90; // Unknown = 
    inline constexpr uintptr_t FFlagAXAvatarFoldersEnabledDev = 0x19BBC7A37DD; // Bool = false
    inline constexpr uintptr_t FFlagAXAvatarLoadWithRetry = 0x19BA3A57490; // Unknown = 
    inline constexpr uintptr_t FFlagAXAvatarSharingEntryPoint = 0x19BBC7AB6DD; // Bool = false
    inline constexpr uintptr_t FFlagAXAvatarSortInDiscoveryUnifiedPurchase = 0x19B9ACB0550; // Unknown = 
    inline constexpr uintptr_t FFlagAXAvatarTabLooksYouMayAlsoLike = 0x19BBC7A0D9D; // Bool = false
    inline constexpr uintptr_t FFlagAXAvatarTabShopForMore = 0x19B9026F01D; // Bool = false
    inline constexpr uintptr_t FFlagAXAvatarTabWidgetRecommendation = 0x19BA3A51250; // Unknown = 
    inline constexpr uintptr_t FFlagAXAvatarsTabIXP = 0x19BBC7AFDDD; // Bool = false
    inline constexpr uintptr_t FFlagAXAvatarsTabIXP1 = 0x19BBC7A36D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXAvatarsTabIXPEnabledForAll = 0x19BBC7A4650; // Unknown = 
    inline constexpr uintptr_t FFlagAXAvatarsTabNoItemsFound = 0x19B90648ADD; // Bool = false
    inline constexpr uintptr_t FFlagAXBackendDrivenCatalogLayers = 0x19BBC7A58D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXBackgroundCycloramaRendering = 0x19B86E1E2C8; // Unknown = 
    inline constexpr uintptr_t FFlagAXBackgroundDisableFogWhileActive = 0x19B8F90445D; // Bool = false
    inline constexpr uintptr_t FFlagAXBackgroundGenerationDev = 0x19B8F905FD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXBackgroundSceneManagerRevamp = 0x19BBC7A73D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXBackgroundSceneManagerRevamp3 = 0x19BBC7A6C90; // Unknown = 
    inline constexpr uintptr_t FFlagAXBackgroundsCustomizeHydration4 = 0x19B8F90519D; // Bool = false
    inline constexpr uintptr_t FFlagAXBackgroundsCycloramaVR = 0x19B8F905050; // Unknown = 
    inline constexpr uintptr_t FFlagAXBackgroundsEquipTryOnCounters2 = 0x19B8F905BDD; // Bool = false
    inline constexpr uintptr_t FFlagAXBackgroundsInAvatarBustThumbnails = 0x19B88C6071D; // Bool = false
    inline constexpr uintptr_t FFlagAXBackgroundsInAvatarThumbnails = 0x19B88C6055D; // Bool = false
    inline constexpr uintptr_t FFlagAXBackgroundsInHeadshotThumbnails = 0x19B88C6095D; // Bool = false
    inline constexpr uintptr_t FFlagAXBackgroundsInOutfitDetails = 0x19B8F90551D; // Bool = false
    inline constexpr uintptr_t FFlagAXBackgroundsInOutfitThumbnails = 0x19B88C60B1D; // Bool = false
    inline constexpr uintptr_t FFlagAXBackgroundsOutfitHighlight = 0x19B8F90565D; // Bool = false
    inline constexpr uintptr_t FFlagAXBackgroundsOutfitPersistence = 0x19B9F184C35; // Bool = true
    inline constexpr uintptr_t FFlagAXBackgroundsPersistence = 0x19B8F90575D; // Bool = false
    inline constexpr uintptr_t FFlagAXBackgroundsRoot = 0x19BA3A582D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXBackgroundsTryOn = 0x19B8F905A9D; // Bool = false
    inline constexpr uintptr_t FFlagAXBlockMakeupEquipR6 = 0x19BA3A56F10; // Unknown = 
    inline constexpr uintptr_t FFlagAXBodyPartsPillLabel = 0x19BBC7A5250; // Unknown = 
    inline constexpr uintptr_t FFlagAXBuildSubcategoryMapWhenBuildingCategoryInfo = 0x19B82CB5EDD; // Bool = true
    inline constexpr uintptr_t FFlagAXCameraDownwardTilt = 0x19B9064675D; // Bool = false
    inline constexpr uintptr_t FFlagAXCameraLevelHorizon = 0x19B906467DD; // Bool = false
    inline constexpr uintptr_t FFlagAXCameraManagerErrorsEnabled = 0x19B9064641D; // Bool = false
    inline constexpr uintptr_t FFlagAXCatalogBackgroundsFilters = 0x19B8F90415D; // Bool = false
    inline constexpr uintptr_t FFlagAXCatalogBackgroundsSupport = 0x19B8F903650; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogBodySuits = 0x19BA3A5CAD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogCategoriesSDUI = 0x19BA3A5A710; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogCategoriesSDUI14 = 0x19BA3A50490; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogCategoriesSDUIDebugDiff = 0x19BA3A53410; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogCategoriesSDUILinks = 0x19BA3A5B25D; // Bool = true
    inline constexpr uintptr_t FFlagAXCatalogCategoriesSDUIPillTitleNormalization = 0x19BA3A53710; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogCategoriesSDUITaxonomy = 0x19BA3A51A90; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogCategoriesStoreImprovePerf = 0x19BA3A54AD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogCategoryTooltip = 0x19BA3A543DD; // Bool = false
    inline constexpr uintptr_t FFlagAXCatalogItemCardDarkerBackground = 0x19B8F90729D; // Bool = false
    inline constexpr uintptr_t FFlagAXCatalogItemCardDarkerBackgroundLogExposure = 0x19D80F1CCB8; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogItemInformationPopover2 = 0x19B8F90689D; // Bool = false
    inline constexpr uintptr_t FFlagAXCatalogM41CategoriesExposureLogging = 0x19BA3A550D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogM41FullMasks = 0x19BA3A5A350; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogM41HandAndArm = 0x19BA3A50AD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogM41Props = 0x19BA3A51A10; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogM41Props3 = 0x19BA3A528D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogMakeupFtuxUseMemStorage = 0x19B8FC36C50; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogMakeupSupport = 0x19BBC7AAA50; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogMakeupSupport10 = 0x19BBC7AAA10; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogMakeupTaxonomy = 0x19BA3A59490; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogMakeupTaxonomy2 = 0x19BA3A57F90; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogMultiItemShoppingFtuxUseMemStorage = 0x19B8FC36A9D; // Bool = false
    inline constexpr uintptr_t FFlagAXCatalogOffersAutoOpenFTUXSheet = 0x19BA3A59A50; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogOffersAutoOpenFTUXSheet2 = 0x19BA3A51B50; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogOffersBannerAppStorageUseMemStorage = 0x19B8FC31A10; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogOffersBannerEnabled = 0x19BA3A59690; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogOffersBannerEnabled2 = 0x19BA3A56F90; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogOffersBannerMockApi = 0x19BA3A554D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogOffersClearOnLogout = 0x19BA3A5F290; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogOffersClearOnLogout2 = 0x19BA3A5A290; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogOffersDismissedStorageKeyFix = 0x19BA3A5BAD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogPerfReduxReductionIXP2 = 0x19B9026F5D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogPerfReduxReductionIXPEnabledForAll2 = 0x19B9026F490; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogRealTimeRecommendationsIXPEnabledForAllV2 = 0x19B90648A5D; // Bool = false
    inline constexpr uintptr_t FFlagAXCatalogRealTimeRecommendationsIXPV2 = 0x19B906488DD; // Bool = false
    inline constexpr uintptr_t FFlagAXCatalogSaveOptionsUseMemStorage = 0x19B8FC3651D; // Bool = false
    inline constexpr uintptr_t FFlagAXCatalogSduiDisableOnSearchRoute = 0x19B9F18981D; // Bool = true
    inline constexpr uintptr_t FFlagAXCatalogSduiSingleRetryButtonOnError = 0x19BA3A58F50; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogSduiUseOpaqueRouteForSearch = 0x19B8F90291D; // Bool = false
    inline constexpr uintptr_t FFlagAXCatalogSearchSupportDisableFilters = 0x19BA3A59790; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogSupportDisableFilters = 0x19BA3A54BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogSupportDisableFilters3 = 0x19BA3A59410; // Unknown = 
    inline constexpr uintptr_t FFlagAXCatalogUseFixedWidgetPadding = 0x19BA36666C8; // Unknown = 
    inline constexpr uintptr_t FFlagAXCategoryMenuBadgePositionTokens2 = 0x19B9F00721D; // Bool = false
    inline constexpr uintptr_t FFlagAXCategoryMenuVisualFixes = 0x19B8F902A9D; // Bool = false
    inline constexpr uintptr_t FFlagAXCategoryPillColorAnimation = 0x19BBC7A9410; // Unknown = 
    inline constexpr uintptr_t FFlagAXCategoryPillPositionAnimation = 0x19BBC7A77D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXCategoryUnifiedLogging = 0x19BBC7A3210; // Unknown = 
    inline constexpr uintptr_t FFlagAXCharacterToAvatarStrings = 0x19BBC7A89DD; // Bool = false
    inline constexpr uintptr_t FFlagAXCheckApplyDefaultClothingErrorGuards = 0x19B9064751D; // Bool = false
    inline constexpr uintptr_t FFlagAXCloseFilterOnBackgroundTap = 0x19B8578AF90; // Unknown = 
    inline constexpr uintptr_t FFlagAXColorAdjustmentButtonShouldAccountForTryOns = 0x19BBC7A9190; // Unknown = 
    inline constexpr uintptr_t FFlagAXColorGradientRenderFlatWithJustOneColor = 0x19B9F008B9D; // Bool = false
    inline constexpr uintptr_t FFlagAXCombineGetOutfitDispatchesIXP3 = 0x19B9026DE5D; // Bool = false
    inline constexpr uintptr_t FFlagAXCombineGetOutfitDispatchesIXPForAll3 = 0x19B9026DD90; // Unknown = 
    inline constexpr uintptr_t FFlagAXCommunityAvatarsMakeupEquipping = 0x19BA3A55190; // Unknown = 
    inline constexpr uintptr_t FFlagAXCustomGetStateForActionHandler = 0x19BBC7A379D; // Bool = false
    inline constexpr uintptr_t FFlagAXCustomGetStateForActionHandler3 = 0x19BBC7AC550; // Unknown = 
    inline constexpr uintptr_t FFlagAXCustomizeBackgrounds = 0x19BA3A54A50; // Unknown = 
    inline constexpr uintptr_t FFlagAXCycloramaAssetFallback2 = 0x19B8F90499D; // Bool = false
    inline constexpr uintptr_t FFlagAXDHEquippedAssetsNilCheck = 0x19B9F00A99D; // Bool = false
    inline constexpr uintptr_t FFlagAXDebugCreateHumanoidModelError = 0x19B90646590; // Unknown = 
    inline constexpr uintptr_t FFlagAXDebugForceIsRecentMarketplaceEnabled = 0x19B90648BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXDebugGridShouldErrorOnInvalidRowCount = 0x19B9F006B90; // Unknown = 
    inline constexpr uintptr_t FFlagAXDebugMobileRbxlContentProbe = 0x19B8F904110; // Unknown = 
    inline constexpr uintptr_t FFlagAXDebugPanel = 0x19B8F9033D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXDebugPanelImpressed = 0x19BA3A55F90; // Unknown = 
    inline constexpr uintptr_t FFlagAXDefaultAvatarToShopEnabled3 = 0x19B90647E10; // Unknown = 
    inline constexpr uintptr_t FFlagAXDefaultAvatarToShopEnabledForAll3 = 0x19B906476D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXDefaultAvatarToShopWidgetEnabled3 = 0x19B90647490; // Unknown = 
    inline constexpr uintptr_t FFlagAXDeferLookImpressionsForHydration = 0x19BA3A5BC1D; // Bool = true
    inline constexpr uintptr_t FFlagAXDeferWidgetLoadedUntilMarketplaceEntered = 0x19BA3A55D10; // Unknown = 
    inline constexpr uintptr_t FFlagAXDisableControlBarMenuAnimation = 0x19B9026CBDD; // Bool = false
    inline constexpr uintptr_t FFlagAXDisableHiddenCatalogCategoryPills = 0x19BBC7A2BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXDisableMultiItemShoppingFtux = 0x19BBC7A3410; // Unknown = 
    inline constexpr uintptr_t FFlagAXDisableTimedOptionsFtux = 0x19B8FC34E95; // Bool = false
    inline constexpr uintptr_t FFlagAXDisableWidgetHydrationCacheForLooks = 0x19B90648C9D; // Bool = false
    inline constexpr uintptr_t FFlagAXDoNotPass356FetchCartPricing = 0x19B8FC3635D; // Bool = false
    inline constexpr uintptr_t FFlagAXDownrankMakeupCustomize = 0x19BA3A54790; // Unknown = 
    inline constexpr uintptr_t FFlagAXDurables2Option = 0x19BA3A57B90; // Unknown = 
    inline constexpr uintptr_t FFlagAXDurables2Option4 = 0x19BA3A5E710; // Unknown = 
    inline constexpr uintptr_t FFlagAXDurables2OptionFixes = 0x19BA3A54FD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXDurablesFooter = 0x19BA3A56650; // Unknown = 
    inline constexpr uintptr_t FFlagAXDurablesFooter2 = 0x19BA3A56C50; // Unknown = 
    inline constexpr uintptr_t FFlagAXDurablesFooterWithPermanent = 0x19B949FAD6D; // Bool = false
    inline constexpr uintptr_t FFlagAXDurablesForMIS = 0x19BBC7A5A90; // Unknown = 
    inline constexpr uintptr_t FFlagAXDurablesForMIS2 = 0x19BBC7A3910; // Unknown = 
    inline constexpr uintptr_t FFlagAXDurablesSupportExposureLogging = 0x19BA3A59A90; // Unknown = 
    inline constexpr uintptr_t FFlagAXDurablesSupportForRFYMigration = 0x19BBC7AA650; // Unknown = 
    inline constexpr uintptr_t FFlagAXDurablesSupportForRFYMigration2 = 0x19BBC7A8650; // Unknown = 
    inline constexpr uintptr_t FFlagAXDurablesSupportWithPostPurchaseFix = 0x19BBC7A5650; // Unknown = 
    inline constexpr uintptr_t FFlagAXEditorEnableThumbnailLatencyStore2 = 0x19B8F905A50; // Unknown = 
    inline constexpr uintptr_t FFlagAXEditorSubcategoryFilters = 0x19BBC7A639D; // Bool = false
    inline constexpr uintptr_t FFlagAXEditorSubcategoryFilters2 = 0x19BBC7A9F10; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableAvatarDataRefreshV4 = 0x19B9026E110; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableBatchItemDetailsFetchV2 = 0x19BA3A51F50; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableBatchUnequips2 = 0x19B9026E550; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableCategoryPills9 = 0x19B9026D8DD; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableCategoryPillsExposureLogging = 0x19BA3A54250; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableCategoryPillsExposureLogging2 = 0x19BA3A5D550; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableEditorCategoryDeepLink = 0x19BACFDCE90; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableErrorLoggingForSubcategorySelectionById = 0x19B861CE365; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableExpiredUserLookCheckout = 0x19BBC7A5ED0; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableExpiredUserLookCheckout10 = 0x19BBC7A4550; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableFetchAvatarPreview = 0x19B9F0A16D5; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableFetchAvatarPreview9 = 0x19B9F0A179D; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableFoundationSegmentedMenu = 0x19BBC7A4A1D; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableFullSceneInteractionFrame3 = 0x19B82DBDC10; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableHeadCombineHeadPickerIXPTogether2 = 0x19B9026E61D; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableHomeTryOnComplexView = 0x19B88C2F790; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableIaBRbxClientFeature = 0x19B9F0A051D; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableIaBTimedOptionsBulkPurchase = 0x19B9F18ECD5; // Bool = true
    inline constexpr uintptr_t FFlagAXEnableIaBTimedOptionsBulkPurchase3 = 0x19B8F90351D; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableInspectAndBuyBulkPurchase = 0x19B9ACB7310; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableInspectAndBuyBulkPurchase3 = 0x19B9ACB3BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableInspectAndBuyExposureLogging = 0x19B9F298D50; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableInspectAndBuyFocusNavigation = 0x19BA3A51C90; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableInspectAndBuyVersionAnalytics = 0x19B9F0A0715; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableMakeupOutfitCreation = 0x19B9F18A245; // Bool = true
    inline constexpr uintptr_t FFlagAXEnableManualSaving = 0x19BBC7A1790; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableManualSaving4 = 0x19BBC7ABE90; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableManualSavingBlockingPrompt = 0x19BBC7AE590; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableManualSavingBlockingPrompt3 = 0x19BBC7AAE10; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableMaxUndoRedoHistory = 0x19BBBFF376D; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableModeratedItemsFlowForDurables = 0x19BBC7A7BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableMultiTryOnUI = 0x19B8F90841D; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableNewInspectAndBuyContainer = 0x19B9F0A6C15; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableNewInspectAndBuyContainer21 = 0x19B9F0A6710; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableNewInventoryItemsList2 = 0x19B9026E010; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableProfileTab_1 = 0x19B9AF13E50; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableRecommendationTypeAllInCustomize2 = 0x19B9026ED5D; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableRegionalFilteringofAssets = 0x19B9FDD9C15; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableResponsiveHeadRefinementMenu = 0x19BA3A5D410; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableSearchLandingFocusedPageFullViewDefault = 0x19B9026D7DD; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableTaxonomyM20ExposureLoggingCatalog = 0x19BA3A55550; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableTaxonomyM20ExposureLoggingClothing = 0x19BA3A50810; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableTaxonomyM21ExposureLoggingClothing = 0x19BA3A54490; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableTimedOptionsForCatalogRowCard2 = 0x19B8F90375D; // Bool = false
    inline constexpr uintptr_t FFlagAXEnableTimedOptionsServerScript = 0x19B9ACB2CD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableUnifiedProductPurchaseForMarketplace = 0x19BA3A584D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableUnifiedProductPurchaseForMarketplace2 = 0x19BA3A521D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnableUnifiedPurchaseFlowForLooks = 0x19BA3A55E90; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnhancedAvatarHeadsFtuxUseMemStorage = 0x19BA3A5AA90; // Unknown = 
    inline constexpr uintptr_t FFlagAXEnsureOfferBannerRefetchMIS = 0x19B8FC366DD; // Bool = false
    inline constexpr uintptr_t FFlagAXEnsureOfferBannerRefetchUnified = 0x19D85DCA8DD; // Bool = true
    inline constexpr uintptr_t FFlagAXExpandPeekViewOnFirstScroll = 0x19BBC7A4310; // Unknown = 
    inline constexpr uintptr_t FFlagAXExpandPeekViewOnFirstScroll1 = 0x19BBC7A7950; // Unknown = 
    inline constexpr uintptr_t FFlagAXExtendUndoRedoTracking = 0x19BBC7A4050; // Unknown = 
    inline constexpr uintptr_t FFlagAXExtractEmotesCategory2 = 0x19B9026EC1D; // Bool = false
    inline constexpr uintptr_t FFlagAXEyebrowEyelashToMakeupCategory = 0x19BA3A502D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFPSEventStreamAndCounters = 0x19BA6A37690; // Unknown = 
    inline constexpr uintptr_t FFlagAXFavoritePillOnItemDetails4 = 0x19B8F906D10; // Unknown = 
    inline constexpr uintptr_t FFlagAXFavoritesManagerNavEntry = 0x19BBC7A0C50; // Unknown = 
    inline constexpr uintptr_t FFlagAXFavoritesManagerSdui = 0x19B88C20C1D; // Bool = false
    inline constexpr uintptr_t FFlagAXFavoritesPillExposureLogging2 = 0x19BA3664FC8; // Unknown = 
    inline constexpr uintptr_t FFlagAXFetchCartPricingDuringInExperienceExposure = 0x19B9ACB8F90; // Unknown = 
    inline constexpr uintptr_t FFlagAXFetchCatalogPageReturnsPromise = 0x19B8F9026DD; // Bool = false
    inline constexpr uintptr_t FFlagAXFetchItemDetailsFromAvatarEditorService = 0x19B8F907A50; // Unknown = 
    inline constexpr uintptr_t FFlagAXFilterOutShopOnlyItemsOnBulkPurchase2 = 0x19B9ACB9750; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixAvatarSaveContext = 0x19BBB850090; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixAvatarScreenVR = 0x19BA3A5BD10; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixAvatarScreenVR2 = 0x19BA3A55B50; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixAvatarsTabPurchaseLogging = 0x19BBC7A371D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixAverageFPSCasing = 0x19B9CB7BF9D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixBadgeStatusConfigOptions = 0x19B9F18F10D; // Bool = true
    inline constexpr uintptr_t FFlagAXFixBodyScaleReduxUpdates4 = 0x19B90646250; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixBottomNavCTAHeight = 0x19B9AF125D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixBundleOutfitFetchForShoes = 0x19B9064845D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixBundleRedirectFromCatalogForSlots = 0x19B9026EB10; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixBundleVerifiedBadgeInWidgets = 0x19B9026D750; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixCameraManagerInitialization = 0x19B906465DD; // Bool = false
    inline constexpr uintptr_t FFlagAXFixCatalogPageButtonSduiCrash = 0x19BA3A59B10; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixCatalogRefreshRendering = 0x19BA3A53BDD; // Bool = false
    inline constexpr uintptr_t FFlagAXFixCatalogRefreshRenderingV3 = 0x19BA3A5701D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixCatalogSearchZoom = 0x19B8F903B1D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixCatalogTileThumbnailFlash = 0x19BBCCCB19D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixCatalogTileThumbnailFlash3 = 0x19BBC7A5C9D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixCheckOnOutfitAssets = 0x19B90644CD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixClickItemDetailsSurfaceLogging = 0x19B88C6025D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixConditionalUseRefSearchBar = 0x19B9029E85D; // Bool = true
    inline constexpr uintptr_t FFlagAXFixContextualActionVisibility = 0x19BA3A5DED0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixContextualActionVisibility2 = 0x19BA3A5F2D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixContextualMenuScrimSize = 0x19B88C6041D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixControlBarSubMenuOverlap = 0x19BA3A596D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixControlBarSubMenuOverlap2 = 0x19BA3A5BC50; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixCustomOutfitNamesDisabled = 0x19BA3A552D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixCycloramaOrphanRemount = 0x19B8F90489D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixDataProcessingMilestoneGating = 0x19BA3A5B1D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixDeselectOutfitInManage = 0x19BA3A555D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixEditorCategoryRenavigation = 0x19BACFD3790; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixEmptyCatalogSearchChrome = 0x19B8F9066DD; // Bool = false
    inline constexpr uintptr_t FFlagAXFixEmptyDictionaryKeysForSaveDict2 = 0x19B9026C75D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixEmptyMakeupLooks = 0x19BBC7A9910; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixFetchOwnedHeadsPaging = 0x19B82A74BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixGamepadNavigationOnOutfitManagement = 0x19B8F90249D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixHandAndArmWidgetApiContext = 0x19BA3A50410; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixHydratedWidgetsParams = 0x19BA3A54A90; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixHydratedWidgetsParams2 = 0x19BA3A5F4D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixIaBTimedOptionsPopoverFocus = 0x19BA3A51CD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixItemDetailsDescriptionSpacing = 0x19B8F905D10; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixItemDetailsPurchaseAttribution = 0x19BA3A520D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixLimitedUniqueResale = 0x19B8F907250; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixLookDetailsContextualMenu = 0x19BA3A56A1D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixLookLinkToCustomize = 0x19BBC7AE5D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixLookPurchaseMissingPurchaseSuccess = 0x19B8FC3689D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixLookTryOnReturnRemoval = 0x19BBC7A1050; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixMakeupLookGrantOutfitHoisting = 0x19B8F902410; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixMinMaxPriceFilterError = 0x19B90644550; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixOpenPurchasePromptForOffersGamepad = 0x19BA3A53610; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixOrderFieldUnlayeredItems = 0x19B90646E90; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixOrientationInputBlocking = 0x19B8578B31D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixOutfitEquipCheckEmptyArray = 0x19B8F902E10; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixPrefetchMarketplaceStartupCrash = 0x19BA3A51910; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixProfileQRCodeTryOnFlash = 0x19B90646C10; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixPurchaseAttemptSurfaceLogging = 0x19BA3A50B50; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixPurchaseSurfaceLogging = 0x19B88C6009D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixR6DefaultHeadShape = 0x19BA3A54590; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixRecommendedItemCreatorType = 0x19BA3A59B90; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixRemoveLookOnMySharedAvatars = 0x19BBC7A475D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixRobuxButtonShowingInFullView = 0x19B8F9021D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixRobuxUpsellSoftLock = 0x19D85DC021D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixSaveManagerOnAXExit = 0x19B9064699D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixScrollingCarouselShowRightButton = 0x19BA6092610; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixSduiCatalogRowJump = 0x19BA3A5D250; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixSduiWidgetTTITileLatencyCallbackIdentity = 0x19BBC7A3ED0; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixSearchLandingQuickButtonsOffset = 0x19B8F90829D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixSearchPurchaseSurface = 0x19BADFD6335; // Bool = false
    inline constexpr uintptr_t FFlagAXFixSeeAllSpacing = 0x19BBC7AE490; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixSelectedItemIndexBleed = 0x19BA3A56110; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixSingleItemPurchaseWidgetLogging = 0x19BA3A52F50; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixSortFunctionForMakeupTryOn = 0x19B90646850; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixTabBarOverrideForWrapperPages = 0x19B9AF13A90; // Unknown = 
    inline constexpr uintptr_t FFlagAXFixTryOnDefaultClothing = 0x19B906473DD; // Bool = false
    inline constexpr uintptr_t FFlagAXFixTryOnHeadShapeThumbnail = 0x19B8F90319D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixVRControlBarFlicker = 0x19B8F90815D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixWidgetHydrationPermanentPrice = 0x19B8F90635D; // Bool = false
    inline constexpr uintptr_t FFlagAXFixWidgetOnlyTabNoItemsFound = 0x19BA3A52B90; // Unknown = 
    inline constexpr uintptr_t FFlagAXFlagBasedExposureLoggingCatalogPage = 0x19BA3A58DD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXGeneralizeInventoryItemsList = 0x19BBC7A9E5D; // Bool = false
    inline constexpr uintptr_t FFlagAXGuardCharacterSpotLightSideAccess = 0x19B9064799D; // Bool = false
    inline constexpr uintptr_t FFlagAXGuardNavStateNil = 0x19BBC7A3350; // Unknown = 
    inline constexpr uintptr_t FFlagAXGuardNavStateTraversal = 0x19BBC7A63D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXHeadCategoryCombineEnabled4 = 0x19B9026E7DD; // Bool = false
    inline constexpr uintptr_t FFlagAXHeadCategoryCombineEnabledForAll4 = 0x19B9026E99D; // Bool = false
    inline constexpr uintptr_t FFlagAXHeroUnitUIBloxDarkScope = 0x19B8F906F10; // Unknown = 
    inline constexpr uintptr_t FFlagAXHideCatalogShortcutsInFullView = 0x19B9F18D25D; // Bool = true
    inline constexpr uintptr_t FFlagAXHideEmptySponsoredRow = 0x19B8F90661D; // Bool = false
    inline constexpr uintptr_t FFlagAXHideHeadAdjustmentForDefaultHead = 0x19BA3A5031D; // Bool = false
    inline constexpr uintptr_t FFlagAXHideMenuOnScroll = 0x19BA3A549DD; // Bool = false
    inline constexpr uintptr_t FFlagAXHideMenuOnScroll3 = 0x19BA3A56750; // Unknown = 
    inline constexpr uintptr_t FFlagAXHideMenuOnScrollExposureLogging = 0x19BA3A5C1DD; // Bool = false
    inline constexpr uintptr_t FFlagAXHideMenuOnScrollExposureLogging3 = 0x19BA3A54D9D; // Bool = true
    inline constexpr uintptr_t FFlagAXHideUnifiedPurchaseFlowSuccessToastMarketplace = 0x19BBC7A1E9D; // Bool = false
    inline constexpr uintptr_t FFlagAXImproveSlotBasedEditorPerformance = 0x19B9064521D; // Bool = false
    inline constexpr uintptr_t FFlagAXIncreaseDefaultPeekViewHeight = 0x19BBCCCCE3D; // Bool = false
    inline constexpr uintptr_t FFlagAXInspectAndBuyMakeupSupport = 0x19B8F902850; // Unknown = 
    inline constexpr uintptr_t FFlagAXIntervalPerformanceTrackerFPSStandardDeviation = 0x19B9CB74F5D; // Bool = false
    inline constexpr uintptr_t FFlagAXIntervalPerformanceTrackerScrollFrameTime = 0x19B9CB7C29D; // Bool = false
    inline constexpr uintptr_t FFlagAXInventoryDurablesExpiredFilter = 0x19BA3A55210; // Unknown = 
    inline constexpr uintptr_t FFlagAXInventoryDurablesSupport = 0x19BBC7AD1D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXInventoryDurablesSupport5 = 0x19BBC7A2D50; // Unknown = 
    inline constexpr uintptr_t FFlagAXInventoryIncludeUnavailableItems = 0x19B8F902810; // Unknown = 
    inline constexpr uintptr_t FFlagAXInventoryItemsListImpressionLogging = 0x19BA3A56690; // Unknown = 
    inline constexpr uintptr_t FFlagAXItemCardBadgeCheckText = 0x19B9F005E10; // Unknown = 
    inline constexpr uintptr_t FFlagAXItemCardComponentsMemo = 0x19BBC7A2250; // Unknown = 
    inline constexpr uintptr_t FFlagAXItemDetails3DPreviewEnabled = 0x19B9026C890; // Unknown = 
    inline constexpr uintptr_t FFlagAXItemDetails3DPreviewEnabledForAll = 0x19B9026D0DD; // Bool = false
    inline constexpr uintptr_t FFlagAXItemDetailsIxpExposure = 0x19BBC7A9890; // Unknown = 
    inline constexpr uintptr_t FFlagAXItemDetailsIxpExposure2 = 0x19BBC7A9C50; // Unknown = 
    inline constexpr uintptr_t FFlagAXItemDetailsPartialAssetInfoFix = 0x19B8F905150; // Unknown = 
    inline constexpr uintptr_t FFlagAXItemInfoRowWrapInfoData = 0x19BC5B818A0; // Unknown = 
    inline constexpr uintptr_t FFlagAXItemsViewContentSizeBinding = 0x19BBC7A2550; // Unknown = 
    inline constexpr uintptr_t FFlagAXKeepTryOnsInAvatarEditor = 0x19B8F90849D; // Bool = false
    inline constexpr uintptr_t FFlagAXLaunchUnifiedPurchaseFlowMarketplaceAssetBundles = 0x19BBC7A2B5D; // Bool = false
    inline constexpr uintptr_t FFlagAXLaunchUnifiedPurchaseFlowMarketplaceLooks = 0x19BBC7A735D; // Bool = false
    inline constexpr uintptr_t FFlagAXLeaveCatalogToAvatarPromptHandleSubcategoryFilters = 0x19BBC7A7C50; // Unknown = 
    inline constexpr uintptr_t FFlagAXLegacyIXPExposureLogging = 0x19B8578A750; // Unknown = 
    inline constexpr uintptr_t FFlagAXLimitWidgetLoadedItemCount = 0x19BA3A53350; // Unknown = 
    inline constexpr uintptr_t FFlagAXLogFacialAnimationOnHeadChange = 0x19BA3A53990; // Unknown = 
    inline constexpr uintptr_t FFlagAXLogFacialAnimationOnHeadChange2 = 0x19BA3A57690; // Unknown = 
    inline constexpr uintptr_t FFlagAXLogFacialAnimationToggle = 0x19BA3A519D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXLogFacialAnimationToggle2 = 0x19BA3A52610; // Unknown = 
    inline constexpr uintptr_t FFlagAXLogFavoritePillToggle = 0x19BA3A52D90; // Unknown = 
    inline constexpr uintptr_t FFlagAXLogNilCategoryAndSubcategorySelection = 0x19BA3A532D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXLookDetailsBottomBarFavoriteLogging = 0x19BABC163C8; // Unknown = 
    inline constexpr uintptr_t FFlagAXLookDetailsBottomBarRobux = 0x19B82C68590; // Unknown = 
    inline constexpr uintptr_t FFlagAXLookDetailsChevronSpacing = 0x19B82AC931D; // Bool = false
    inline constexpr uintptr_t FFlagAXM41AllCategoriesToTaxonomy = 0x19BA3A56410; // Unknown = 
    inline constexpr uintptr_t FFlagAXMISEnableMultiShopping = 0x19BBCCCBF5D; // Bool = false
    inline constexpr uintptr_t FFlagAXMISEnableMultiShopping13 = 0x19BBC7AEF1D; // Bool = false
    inline constexpr uintptr_t FFlagAXMISEnableMultiShoppingUnifiedEvents = 0x19BBC7A199D; // Bool = false
    inline constexpr uintptr_t FFlagAXMISEnableMultiShoppingUnifiedEvents2 = 0x19BBC7A1A10; // Unknown = 
    inline constexpr uintptr_t FFlagAXMISFixAccessoryOverLimits = 0x19B9026E150; // Unknown = 
    inline constexpr uintptr_t FFlagAXMISSaveWearFix = 0x19BBC7A4490; // Unknown = 
    inline constexpr uintptr_t FFlagAXMISSmallUIChanges = 0x19BBC7A631D; // Bool = false
    inline constexpr uintptr_t FFlagAXMISWithBlackbird = 0x19BA59BF9D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMISWithOffers = 0x19BBC7AF11D; // Bool = false
    inline constexpr uintptr_t FFlagAXMISWithOffers4 = 0x19BBC7AF850; // Unknown = 
    inline constexpr uintptr_t FFlagAXMakeSlidersSmoothWithGamepad = 0x19B8F9032DD; // Bool = false
    inline constexpr uintptr_t FFlagAXMakeupCategoryPositionExperiment = 0x19BBC7A1D90; // Unknown = 
    inline constexpr uintptr_t FFlagAXMakeupCategoryPositionExperimentExposureLogging = 0x19BBC7A44D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMakeupEquipping = 0x19BA3A58390; // Unknown = 
    inline constexpr uintptr_t FFlagAXMakeupFixAvatarLooksTryOn = 0x19BA3A5C990; // Unknown = 
    inline constexpr uintptr_t FFlagAXMakeupLayeringTooltipFTUX = 0x19BA3A52150; // Unknown = 
    inline constexpr uintptr_t FFlagAXMakeupReleaseFTUX = 0x19BA3A5A990; // Unknown = 
    inline constexpr uintptr_t FFlagAXManageOutfitsCatalogItemCard = 0x19BA3A5201D; // Bool = false
    inline constexpr uintptr_t FFlagAXMarketplaceLoadingSkeleton = 0x19B86E1FDD5; // Bool = true
    inline constexpr uintptr_t FFlagAXMeTabTopScrim = 0x19B8F90759D; // Bool = false
    inline constexpr uintptr_t FFlagAXMigrateAXToGlobalAutofocus = 0x19BA74E5BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateAdjustAccessoryViewToFocusNavigation = 0x19BA520ACDD; // Bool = true
    inline constexpr uintptr_t FFlagAXMigrateAdjustAccessoryViewToFocusNavigation3 = 0x19B88C4D610; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateAllTabToSdui8 = 0x19B8F902D9D; // Bool = false
    inline constexpr uintptr_t FFlagAXMigrateAvatarEditorItemCardInputBindingsToFocusNavigation3 = 0x19B88C4DF9D; // Bool = false
    inline constexpr uintptr_t FFlagAXMigrateAvatarEditorPageInputBindings = 0x19B8578AD10; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateBuilderIcons = 0x19BA3A5B150; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateBuilderIcons2 = 0x19BA3A5D7D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateCatalogPageInputBindings = 0x19BA74EBF50; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateCatalogPageInputBindings2 = 0x19B8578A8D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateCatalogResultListNavigationToMVVM = 0x19BA3A5AD50; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateCatalogSearchToFocusNavigation = 0x19B88C4D1D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateCategoryTooltip = 0x19BA3A595D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateCategoryTooltip1 = 0x19BA3A57210; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateEmoteMenuFromRoactGamepad = 0x19B8578BADD; // Bool = false
    inline constexpr uintptr_t FFlagAXMigrateEquipSlotsInputBindingsToRoactGamepad = 0x19BA74EA710; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateEquipSlotsInputBindingsToRoactGamepad2 = 0x19B8578A510; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateItemDetailsContainerInputBindingsToFocusNavigation = 0x19BA57F59A5; // Bool = false
    inline constexpr uintptr_t FFlagAXMigrateItemDetailsInputBindingsToFocusNavigation = 0x19B8578B25D; // Bool = false
    inline constexpr uintptr_t FFlagAXMigrateLookDetailsPeekViewToFocusNavigation = 0x19B88C4D190; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateMainNavHeightToFInt = 0x19B9026DA1D; // Bool = false
    inline constexpr uintptr_t FFlagAXMigrateMainNavigationInputBindings = 0x19BBC7A785D; // Bool = false
    inline constexpr uintptr_t FFlagAXMigrateMakeBackButtonToFocusNavigation3 = 0x19B94810E5D; // Bool = false
    inline constexpr uintptr_t FFlagAXMigrateManageOutfitPageInputBindingsToFocusNavigation = 0x19BA74E1FD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateManageOutfitPageInputBindingsToFocusNavigation3 = 0x19B8578B1DD; // Bool = false
    inline constexpr uintptr_t FFlagAXMigrateMaterialsToAttributes = 0x19B8F906CD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateOutfitsToUserInventory = 0x19BA3A50850; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigratePeekViewToFocusNavigation = 0x19BA6098390; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateProfilePictureEditorEmotesPageToFocusNavigation = 0x19B88C4C7D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigratePurchasePromptInteractiveToFocusNavigation2 = 0x19B88C4D910; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateQuickButtonsToGlobalAutoFocus = 0x19B8578AF50; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateRecommendedItemsGridToFocusNavigation = 0x19B88C4DD50; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateResellersInputBindingsToRoactGamepad = 0x19BBC7A7DD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateSaveOutfitPromptFromRoactGamepad = 0x19B88C4DE1D; // Bool = false
    inline constexpr uintptr_t FFlagAXMigrateSceneGamepadHandlerInputBindings = 0x19BA74E2AD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateSceneGamepadHandlerInputBindings2 = 0x19B857892D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateSearchBarToFocusNavigation = 0x19B9029D3D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateSearchLandingPageToFocusNavigation = 0x19B9029E910; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateSlotsSignals = 0x19BBC7A3550; // Unknown = 
    inline constexpr uintptr_t FFlagAXMigrateSystemSliderToFoundationSlider = 0x19BA74E575D; // Bool = false
    inline constexpr uintptr_t FFlagAXMigrateSystemSliderToFoundationSlider2 = 0x19B8578B4DD; // Bool = false
    inline constexpr uintptr_t FFlagAXModeratedItemIconUpdates = 0x19BA3A5245D; // Bool = true
    inline constexpr uintptr_t FFlagAXModeratedItemIconUpdates2 = 0x19BA3A58E1D; // Bool = false
    inline constexpr uintptr_t FFlagAXModeratedItemsFlow = 0x19BBC7A8A10; // Unknown = 
    inline constexpr uintptr_t FFlagAXModeratedItemsFlow5 = 0x19BBC7A9250; // Unknown = 
    inline constexpr uintptr_t FFlagAXMoveAllTabToWidgetOnly = 0x19BA3A58A90; // Unknown = 
    inline constexpr uintptr_t FFlagAXMoveAllTabToWidgetOnly5 = 0x19BA3A5D610; // Unknown = 
    inline constexpr uintptr_t FFlagAXMoveCatalogFilterToL1Navigation = 0x19BABC12D08; // Unknown = 
    inline constexpr uintptr_t FFlagAXMoveCatalogFilterToL1Navigation2 = 0x19BBC7A5610; // Unknown = 
    inline constexpr uintptr_t FFlagAXMoveCatalogFilterToL1NavigationExposureLogging = 0x19BBC7ABA10; // Unknown = 
    inline constexpr uintptr_t FFlagAXMoveCatalogFilterToL1NavigationExposureLogging3 = 0x19BBC7AC910; // Unknown = 
    inline constexpr uintptr_t FFlagAXMoveContextualActionButtons = 0x19BA3A52990; // Unknown = 
    inline constexpr uintptr_t FFlagAXMutedErrorLoggingForCategorySelection = 0x19BA3A53490; // Unknown = 
    inline constexpr uintptr_t FFlagAXNegativeAvatarSequenceFeatures = 0x19BBC7AAD90; // Unknown = 
    inline constexpr uintptr_t FFlagAXNilCheckEquippedAssets = 0x19B90646550; // Unknown = 
    inline constexpr uintptr_t FFlagAXNilGuardCharacterManager = 0x19B9064711D; // Bool = false
    inline constexpr uintptr_t FFlagAXNoCarouselsOnCatalogWithGamepad = 0x19B8F9DF35D; // Bool = false
    inline constexpr uintptr_t FFlagAXOnlyHydrateVisibleRows = 0x19B8F903B9D; // Bool = false
    inline constexpr uintptr_t FFlagAXOpaqueMarketplaceTopbar = 0x19BBC7A8C50; // Unknown = 
    inline constexpr uintptr_t FFlagAXOrganicItemPosition = 0x19BA3A50150; // Unknown = 
    inline constexpr uintptr_t FFlagAXOutfitDetailsV4_2 = 0x19B8F90531D; // Bool = false
    inline constexpr uintptr_t FFlagAXOutfitPageRevamp = 0x19BA3A5E550; // Unknown = 
    inline constexpr uintptr_t FFlagAXOutfitPageRevamp3 = 0x19BA3A56ED0; // Unknown = 
    inline constexpr uintptr_t FFlagAXPPEReturnToEntrySurface = 0x19B9AF13ED0; // Unknown = 
    inline constexpr uintptr_t FFlagAXPartialPageModalBackgroundShim = 0x19BA3A5D81D; // Bool = true
    inline constexpr uintptr_t FFlagAXPartialPageModalBackgroundShim2 = 0x19BA3A56D10; // Unknown = 
    inline constexpr uintptr_t FFlagAXPartialPageModalDockedPadding = 0x19B9F008B50; // Unknown = 
    inline constexpr uintptr_t FFlagAXPassScreenSizeToWidgetApi = 0x19BA3A5DF90; // Unknown = 
    inline constexpr uintptr_t FFlagAXPassScreenSizeToWidgetApi5 = 0x19BA3A5FCD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXPhotoboothAddTropicalRunway = 0x19BBC7A3950; // Unknown = 
    inline constexpr uintptr_t FFlagAXPhotoboothAnalytics = 0x19BBC7A9F50; // Unknown = 
    inline constexpr uintptr_t FFlagAXPhotoboothBugBashFixes = 0x19BBC7AE3D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXPhotoboothBugBashFixes4 = 0x19BB6BB7F15; // Bool = false
    inline constexpr uintptr_t FFlagAXPhotoboothCaptureServiceScreenshot = 0x19BBC7A0710; // Unknown = 
    inline constexpr uintptr_t FFlagAXPhotoboothExposure = 0x19BBC7A5950; // Unknown = 
    inline constexpr uintptr_t FFlagAXPhotoboothFunctionality = 0x19BBC7A1650; // Unknown = 
    inline constexpr uintptr_t FFlagAXPhotoboothFunctionality12 = 0x19BBC7ADD10; // Unknown = 
    inline constexpr uintptr_t FFlagAXPhotoboothIsStandalone = 0x19BBC7A9A9D; // Bool = false
    inline constexpr uintptr_t FFlagAXPhotoboothReplacesFullview = 0x19BBC7A24D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXPhotoboothShareModal = 0x19BBC7A1A9D; // Bool = false
    inline constexpr uintptr_t FFlagAXPrefetchMarketplaceIXP5 = 0x19B9064855D; // Bool = false
    inline constexpr uintptr_t FFlagAXPrefetchMarketplaceIXPEnabledForAll5 = 0x19B9064869D; // Bool = false
    inline constexpr uintptr_t FFlagAXPrefetchMarketplaceThumbnailsXPExposureV4 = 0x19BA3A58C10; // Unknown = 
    inline constexpr uintptr_t FFlagAXPrefetchMarketplaceThumbnailsXPV4 = 0x19BA3A50950; // Unknown = 
    inline constexpr uintptr_t FFlagAXPrefetchOnlyWithinTTL = 0x19BA3A575D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXProfileConfigurationMultiFieldApply = 0x19B8F90589D; // Bool = false
    inline constexpr uintptr_t FFlagAXProvideAccessoryAdjustmentDefaults = 0x19BBC7A7050; // Unknown = 
    inline constexpr uintptr_t FFlagAXPurchaseFromQuantityFirst = 0x19BA3A54D10; // Unknown = 
    inline constexpr uintptr_t FFlagAXRecentlyViewedCounters = 0x19B9029E450; // Unknown = 
    inline constexpr uintptr_t FFlagAXRecentlyViewedSearchItemsEnabled4 = 0x19B9F00EE9D; // Bool = false
    inline constexpr uintptr_t FFlagAXRecentlyViewedSearchItemsEnabledForAll4 = 0x19B9F00F05D; // Bool = false
    inline constexpr uintptr_t FFlagAXRecentlyViewedSearchItemsPositionTop4 = 0x19B9F00E8D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXRecentlyViewedSearchItemsSaveInCatalog4 = 0x19B9F00ED50; // Unknown = 
    inline constexpr uintptr_t FFlagAXRecommendedItemsImpressionExposureLogging = 0x19BA3A50250; // Unknown = 
    inline constexpr uintptr_t FFlagAXReduceCatalogFilterWidth = 0x19BBC7AA690; // Unknown = 
    inline constexpr uintptr_t FFlagAXReduceCatalogFilterWidth2 = 0x19BBC7A9A50; // Unknown = 
    inline constexpr uintptr_t FFlagAXRefactorCatalogItemCard = 0x19BBC7A8D1D; // Bool = false
    inline constexpr uintptr_t FFlagAXRefactorCatalogItemCard8 = 0x19BBC7A6D1D; // Bool = false
    inline constexpr uintptr_t FFlagAXRefactorToggleEquipAsset3 = 0x19B9026E590; // Unknown = 
    inline constexpr uintptr_t FFlagAXRefetchInventoryOnAssetGrant = 0x19BA3A53110; // Unknown = 
    inline constexpr uintptr_t FFlagAXRefreshThumbnailsOnLocalSave = 0x19B9064689D; // Bool = false
    inline constexpr uintptr_t FFlagAXRemoveCatalogCategoryIconOnOff3 = 0x19B82C6681D; // Bool = false
    inline constexpr uintptr_t FFlagAXRemoveCatalogCategoryNavKey = 0x19BA3A56F5D; // Bool = false
    inline constexpr uintptr_t FFlagAXRemoveCatalogCategoryNavKey4 = 0x19BA3A5279D; // Bool = false
    inline constexpr uintptr_t FFlagAXRemoveDynamicHeadAssetsFromTryOn = 0x19B9064725D; // Bool = false
    inline constexpr uintptr_t FFlagAXRemoveExpiredItemsFromInventory = 0x19BA3A52310; // Unknown = 
    inline constexpr uintptr_t FFlagAXRemoveMemoizeFromAccessoryAdjustmentUtils = 0x19BBC7A6DDD; // Bool = false
    inline constexpr uintptr_t FFlagAXRemoveTimedOptionsSalesTypeEnumCheck = 0x19BA3A56310; // Unknown = 
    inline constexpr uintptr_t FFlagAXRenameBackToAddToAvatar = 0x19BA3A50D90; // Unknown = 
    inline constexpr uintptr_t FFlagAXReplaceDefaultHeadAssetId = 0x19B9026C21D; // Bool = false
    inline constexpr uintptr_t FFlagAXRepositionLooksFormKeyboard = 0x19B82A1A19D; // Bool = false
    inline constexpr uintptr_t FFlagAXResetAvatarButton = 0x19BA3A59150; // Unknown = 
    inline constexpr uintptr_t FFlagAXResetAvatarButton2 = 0x19BA3A5E350; // Unknown = 
    inline constexpr uintptr_t FFlagAXResetAvatarButtonExposureLogging = 0x19BA3A56D90; // Unknown = 
    inline constexpr uintptr_t FFlagAXResetFetchMarketplaceLogic = 0x19BA3A54CD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXResetFetchMarketplaceLogicV2 = 0x19BA3A56450; // Unknown = 
    inline constexpr uintptr_t FFlagAXRevertEquippedAssetsAfterLayeringTryOnMakeup = 0x19BBC7A0F10; // Unknown = 
    inline constexpr uintptr_t FFlagAXRootRFYMigration = 0x19BA3A58C50; // Unknown = 
    inline constexpr uintptr_t FFlagAXRootSlotBasedEditorFlag = 0x19BBC7A41D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXScrollHighlightedTabIntoView = 0x19B8F902B5D; // Bool = false
    inline constexpr uintptr_t FFlagAXScrollingCarouselWidgetIndexBugfix = 0x19BA59B9350; // Unknown = 
    inline constexpr uintptr_t FFlagAXScrollingFramesShouldAnimateOnFocus3 = 0x19B88C4D410; // Unknown = 
    inline constexpr uintptr_t FFlagAXSduiCatalogScrollImpressions = 0x19BA3A56CD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXSduiFeedBackToTopAndNavClearance = 0x19BA3A50650; // Unknown = 
    inline constexpr uintptr_t FFlagAXSduiWidgetsTTITracking = 0x19B8F902F5D; // Bool = false
    inline constexpr uintptr_t FFlagAXSearchTrendingChipLogging = 0x19BA3A59750; // Unknown = 
    inline constexpr uintptr_t FFlagAXSelectedBorderWrapsBackground = 0x19B8F906F5D; // Bool = false
    inline constexpr uintptr_t FFlagAXSendImpressionsForCatalogOffersBanner = 0x19B8FC32210; // Unknown = 
    inline constexpr uintptr_t FFlagAXSendModelMismatchCounter = 0x19B8F9DF21D; // Bool = false
    inline constexpr uintptr_t FFlagAXSendPurchaseAttempt = 0x19B9F29B7DD; // Bool = false
    inline constexpr uintptr_t FFlagAXSendSessionForEvents = 0x19B9F29AF90; // Unknown = 
    inline constexpr uintptr_t FFlagAXSendUnifiedEventLogWithInstance = 0x19BA3A54190; // Unknown = 
    inline constexpr uintptr_t FFlagAXSendUnifiedEventsInStudio = 0x19B9F29B890; // Unknown = 
    inline constexpr uintptr_t FFlagAXSetAngularVelocityIsOptional = 0x19BBC7A8950; // Unknown = 
    inline constexpr uintptr_t FFlagAXShowBodySuitsCategoryInCatalog = 0x19BA3A53ED0; // Unknown = 
    inline constexpr uintptr_t FFlagAXShowExpiredItemsFilterTooltip = 0x19B9F18328D; // Bool = true
    inline constexpr uintptr_t FFlagAXShowFaeUpsell2 = 0x19B8F902190; // Unknown = 
    inline constexpr uintptr_t FFlagAXShowFavoritePillFtuxTooltip = 0x19BBCCCAC5D; // Bool = true
    inline constexpr uintptr_t FFlagAXShowHeadAdjustmentInRightControlBar = 0x19BA3A5595D; // Bool = false
    inline constexpr uintptr_t FFlagAXShowHeadAdjustmentInRightControlBar2 = 0x19BA3A59F9D; // Bool = true
    inline constexpr uintptr_t FFlagAXSilenceGetOutfitMutedError = 0x19B9064831D; // Bool = false
    inline constexpr uintptr_t FFlagAXSimplifyOutfitEquipCheck = 0x19B9026E950; // Unknown = 
    inline constexpr uintptr_t FFlagAXSkipEmotesInAvatarData = 0x19BA3A52A1D; // Bool = false
    inline constexpr uintptr_t FFlagAXSkipMakeupFTUX = 0x19BC5B8BF80; // Unknown = 
    inline constexpr uintptr_t FFlagAXSkyboxFromBackgroundAsset = 0x19B8F90475D; // Bool = false
    inline constexpr uintptr_t FFlagAXSlotAvatarThumbnailPromptFix = 0x19BBC7A3B10; // Unknown = 
    inline constexpr uintptr_t FFlagAXSlotBasedEditorCategoryTooltip = 0x19BA3A5AC50; // Unknown = 
    inline constexpr uintptr_t FFlagAXSlotBasedEditorCategoryTooltip2 = 0x19BA3A57590; // Unknown = 
    inline constexpr uintptr_t FFlagAXSlotBasedEditorCustomizeFtuxUseMemStorage2 = 0x19D80F6BE25; // Bool = false
    inline constexpr uintptr_t FFlagAXSlotEditorCategoryMenu = 0x19BA3A5C350; // Unknown = 
    inline constexpr uintptr_t FFlagAXSlotsDesignUpdatesExposureLogging = 0x19BA3A51A50; // Unknown = 
    inline constexpr uintptr_t FFlagAXSlotsDesignUpdatesExposureLogging2 = 0x19BA3A51D10; // Unknown = 
    inline constexpr uintptr_t FFlagAXSlotsDesktopRedesign = 0x19BA3A5EFD0; // Unknown = 
    inline constexpr uintptr_t FFlagAXSlotsDesktopRedesign2 = 0x19BA3A558D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXSlotsDisableScrollAwayOnLandscape = 0x19BBC7A1E5D; // Bool = false
    inline constexpr uintptr_t FFlagAXSlotsFixLeftScroll = 0x19BA3A52C50; // Unknown = 
    inline constexpr uintptr_t FFlagAXSlotsInventoryLoadableGridView = 0x19BBC7A7890; // Unknown = 
    inline constexpr uintptr_t FFlagAXSlotsPeekViewScrollFix = 0x19BBC7AC7D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXSortsBodyTabRecExposureLogging = 0x19B8F9076DD; // Bool = false
    inline constexpr uintptr_t FFlagAXStandaloneInventoryDurablesSupport = 0x19BBC7A9290; // Unknown = 
    inline constexpr uintptr_t FFlagAXStrictCheckForPrefetchMarketplace = 0x19BA3A5A55D; // Bool = true
    inline constexpr uintptr_t FFlagAXSubscriptionRefetchEvictStores = 0x19B8F903410; // Unknown = 
    inline constexpr uintptr_t FFlagAXSubscriptionSignalsPlayersServiceOverride = 0x19D80F125C8; // Unknown = 
    inline constexpr uintptr_t FFlagAXSupportRentalPurchaseInUnifiedProductPurchaseFlow = 0x19B9AF1E890; // Unknown = 
    inline constexpr uintptr_t FFlagAXSupportRentalPurchaseInUnifiedProductPurchaseFlow3 = 0x19B9AF1D150; // Unknown = 
    inline constexpr uintptr_t FFlagAXSupportShoesInItemViewport = 0x19B9026D5DD; // Bool = false
    inline constexpr uintptr_t FFlagAXSwapOuterwearSubcategoryOrder = 0x19B9026E39D; // Bool = false
    inline constexpr uintptr_t FFlagAXTTIAddNumElementsRendered = 0x19B8F74181D; // Bool = false
    inline constexpr uintptr_t FFlagAXTTIEditorColdStartDetection = 0x19B9F18A44D; // Bool = true
    inline constexpr uintptr_t FFlagAXTTIEditorEnableMilestones4 = 0x19B8F905EDD; // Bool = false
    inline constexpr uintptr_t FFlagAXTallTilesForAdvancedBodiesWidget = 0x19BA3A52E50; // Unknown = 
    inline constexpr uintptr_t FFlagAXTallTilesForMakeupLooks = 0x19BA3A51150; // Unknown = 
    inline constexpr uintptr_t FFlagAXTestDontUseSkeletonOnloadInCatalog = 0x19B9F006BDD; // Bool = false
    inline constexpr uintptr_t FFlagAXTestSkeletonInCatalog = 0x19BADFD59D5; // Bool = false
    inline constexpr uintptr_t FFlagAXThumbTypeNilCheck = 0x19B86CD7BB8; // Unknown = 
    inline constexpr uintptr_t FFlagAXTimedOptionsFTUXModalUseMemStorage = 0x19BA3A54450; // Unknown = 
    inline constexpr uintptr_t FFlagAXTimedOptionsFtuxUseMemStorage = 0x19B8FC35E90; // Unknown = 
    inline constexpr uintptr_t FFlagAXTimedOptionsPopoverSkipFocusOnCursor = 0x19BA3A55050; // Unknown = 
    inline constexpr uintptr_t FFlagAXTooltipUseMemStorage = 0x19B9F00E05D; // Bool = false
    inline constexpr uintptr_t FFlagAXTryOnScreenFixes = 0x19BA3A5C6D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXTryOnScreenImprovements6 = 0x19B88C4F210; // Unknown = 
    inline constexpr uintptr_t FFlagAXTweakSlotsCameraPositioning = 0x19B9026EF1D; // Bool = false
    inline constexpr uintptr_t FFlagAXUnifiedFilterWidgetLoadedAndUIImpression = 0x19B9F29B8DD; // Bool = false
    inline constexpr uintptr_t FFlagAXUnifiedImpressionsOnThumbnail = 0x19BBCCCE41D; // Bool = false
    inline constexpr uintptr_t FFlagAXUnifiedMarketplaceResultsFetcher = 0x19BBC7ACB90; // Unknown = 
    inline constexpr uintptr_t FFlagAXUnifiedMarketplaceResultsFetcherV3 = 0x19BBC7ACED0; // Unknown = 
    inline constexpr uintptr_t FFlagAXUnifiedPurchaseExtendRentalsFix = 0x19BA3A52050; // Unknown = 
    inline constexpr uintptr_t FFlagAXUnifiedPurchasePromptMakeupLooksSaveLookType = 0x19BA3A539DD; // Bool = true
    inline constexpr uintptr_t FFlagAXUpdateAvatarOnGameLeave = 0x19B90644ADD; // Bool = false
    inline constexpr uintptr_t FFlagAXUpdateSlotBasedEditorToastAndPrompts = 0x19BBC7AB890; // Unknown = 
    inline constexpr uintptr_t FFlagAXUprankBundles = 0x19B9026F15D; // Bool = false
    inline constexpr uintptr_t FFlagAXUseFIntForWidgetListInitialNumToRender = 0x19B8F9DF89D; // Bool = false
    inline constexpr uintptr_t FFlagAXUsePreloadingSwitchView = 0x19BA3A551D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXUseProfileIconEntryPoint = 0x19BBC7A50D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXUseUnifiedLoggingEnums = 0x19BA3A50B10; // Unknown = 
    inline constexpr uintptr_t FFlagAXUseVirtualizedFeedInWidgetList2 = 0x19B8F90399D; // Bool = false
    inline constexpr uintptr_t FFlagAXVirtualizedFeedVerticalPadding = 0x19B88C26E5D; // Bool = false
    inline constexpr uintptr_t FFlagAXWearTimeListItemUnifiedLogging = 0x19BBCCC68FD; // Bool = true
    inline constexpr uintptr_t FFlagAXWearTimeSupport = 0x19BA59BFA10; // Unknown = 
    inline constexpr uintptr_t FFlagAXWearTimeSupport3 = 0x19BA59BA5D0; // Unknown = 
    inline constexpr uintptr_t FFlagAXWidgetHeaderTreatEmptyTextAsNil = 0x19B8F90609D; // Bool = false
    inline constexpr uintptr_t FFlagAXWrapInspectAndBuyThunksInTasks = 0x19B9F0A6B15; // Bool = false
    inline constexpr uintptr_t FFlagAbuseReportAttributedRBXSystemMessages = 0x19B8C30C79D; // Bool = true
    inline constexpr uintptr_t FFlagAbuseReportCheckSceneSelectionAvailabilityOnOpen = 0x19BB7F45B10; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportClientVersion = 0x19BB7F45F10; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportDensifyResolvedArrays = 0x19BB7F44B90; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportEnableReportSentPage = 0x19B81E13D10; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportForwardCustomTagFields = 0x19BB7F458D5; // Bool = false
    inline constexpr uintptr_t FFlagAbuseReportImproveErrorEvents = 0x19BB7F44FD0; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportInExpPlayerListV3 = 0x19B8C30EA90; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportInExpShowConfigLoadingSkeleton = 0x19BB7F42850; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportInlineAlertStateOutsideReducer = 0x19BB7F48A50; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportInlineTitleDisclosureFocus = 0x19B8C30D390; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportLinkOpenedAnalytics = 0x19B8C30D610; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportMenuOpenCloseSignal = 0x19BB7F44410; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportMenuV2 = 0x19B949D846D; // Bool = true
    inline constexpr uintptr_t FFlagAbuseReportSceneSelectionNextOnFailure = 0x19BB7F40650; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportSceneSelectionSubmitTracking = 0x19BB7F4BB10; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportSelectItemAddId = 0x19B8C30D950; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportSlideOutgoingInputSink = 0x19BB7F4DC90; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportSubmissionTargetV4 = 0x19B8C30E6D0; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportTabClearCapturedScreenshotOnCloseFix = 0x19BB7F49B90; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportV2ScrollNavigation = 0x19BB7F44190; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportVoiceMute = 0x19B8C30E490; // Unknown = 
    inline constexpr uintptr_t FFlagAbuseReportingUseProfileFrameThumbnail = 0x19BB7F4D7D0; // Unknown = 
    inline constexpr uintptr_t FFlagAccountLockReceiverClosesModal = 0x19B8C30EADD; // Bool = true
    inline constexpr uintptr_t FFlagAccountSwitchRelaunchFallback = 0x19B88C4D81D; // Bool = false
    inline constexpr uintptr_t FFlagAccountUnlockAllowMissingUserId = 0x19B8C30EE5D; // Bool = true
    inline constexpr uintptr_t FFlagAddAEGIS2Analytics = 0x19BA6099310; // Unknown = 
    inline constexpr uintptr_t FFlagAddAbilityToDisableIGMScroll = 0x19B8C30D0D0; // Unknown = 
    inline constexpr uintptr_t FFlagAddAbuseReportOffsetForLandscape = 0x19B88C4F95D; // Bool = false
    inline constexpr uintptr_t FFlagAddApolloClientToExperienceChat = 0x19BB2AF7E90; // Unknown = 
    inline constexpr uintptr_t FFlagAddBackplateSupportToUserTile = 0x19B8C302DD0; // Unknown = 
    inline constexpr uintptr_t FFlagAddCenterDialogForUnifiedPurchaseModal = 0x19B9AF1B3D0; // Unknown = 
    inline constexpr uintptr_t FFlagAddCenterDialogForUnifiedPurchaseModal2 = 0x19B9AF1B650; // Unknown = 
    inline constexpr uintptr_t FFlagAddCollaborationCoreGatedConnectionError2 = 0x19BBC38BC10; // Unknown = 
    inline constexpr uintptr_t FFlagAddCommerceErrors = 0x19B9FD8321D; // Bool = false
    inline constexpr uintptr_t FFlagAddCommunityLockedToCommunityProfile = 0x19BACFD5090; // Unknown = 
    inline constexpr uintptr_t FFlagAddContextualPlayabilityConnectionErrors = 0x19BA672D19D; // Bool = false
    inline constexpr uintptr_t FFlagAddCursorProviderToPurchasePromptApp = 0x19B9ACB5050; // Unknown = 
    inline constexpr uintptr_t FFlagAddCursorProviderToPurchasePromptAppV5 = 0x19B9ACB54D0; // Unknown = 
    inline constexpr uintptr_t FFlagAddDefaultFocusNavSelectorsOnBuyPurchasePrompt = 0x19D80F49058; // Unknown = 
    inline constexpr uintptr_t FFlagAddEventsToCommunityProfile = 0x19B8EAE9230; // Unknown = 
    inline constexpr uintptr_t FFlagAddFetchProductInfoAsACallback = 0x19B9AF1C0D0; // Unknown = 
    inline constexpr uintptr_t FFlagAddFontStyleToTextWithTranslation = 0x19BB7F45510; // Unknown = 
    inline constexpr uintptr_t FFlagAddFriendsBannersNewUI_IXP = 0x19BA59BF390; // Unknown = 
    inline constexpr uintptr_t FFlagAddFriendsBannersNewUI_exp = 0x19BA59BEFD0; // Unknown = 
    inline constexpr uintptr_t FFlagAddFriendsCINewIcon_exp = 0x19BA59B9590; // Unknown = 
    inline constexpr uintptr_t FFlagAddFriendsDeprecateUnusedReducers = 0x19B8C2E1A1D; // Bool = false
    inline constexpr uintptr_t FFlagAddFriendsIgnoreAllFoundationMenu = 0x19B8C2E11DD; // Bool = false
    inline constexpr uintptr_t FFlagAddFriendsOldIconForChannelsVariant_exp = 0x19D81FADD2D; // Bool = true
    inline constexpr uintptr_t FFlagAddFriendsPageCapitalization = 0x19BA59B9A10; // Unknown = 
    inline constexpr uintptr_t FFlagAddFriendsPageFAEUpsell = 0x19BAEE137D0; // Unknown = 
    inline constexpr uintptr_t FFlagAddFriendsPageFAEUpsell3 = 0x19B8C2E4910; // Unknown = 
    inline constexpr uintptr_t FFlagAddFriendsPageTrustedFriendRequestSection_v10 = 0x19B8C2E0390; // Unknown = 
    inline constexpr uintptr_t FFlagAddFriendsPageUpdateAmpRules = 0x19B8C2E49D0; // Unknown = 
    inline constexpr uintptr_t FFlagAddFriendsPresenceStoreMigration = 0x19BA59B4BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAddFriendsPresenceStoreMigration_v4 = 0x19BA59BC9D0; // Unknown = 
    inline constexpr uintptr_t FFlagAddFriendsRefreshRequestOrder = 0x19B8C2E185D; // Bool = false
    inline constexpr uintptr_t FFlagAddFriendsSessionId = 0x19BA59B7410; // Unknown = 
    inline constexpr uintptr_t FFlagAddFriendsUserListEnabled_v2 = 0x19B8C2E0210; // Unknown = 
    inline constexpr uintptr_t FFlagAddGamepadBumperNavigation3 = 0x19BA6A3BD5D; // Bool = false
    inline constexpr uintptr_t FFlagAddIEMProfilePage = 0x19BACFD4A10; // Unknown = 
    inline constexpr uintptr_t FFlagAddInviteFriendsIntegration = 0x19B9ACB531D; // Bool = true
    inline constexpr uintptr_t FFlagAddLayoutOrderToSduiSectionHeaderIconComponent = 0x19B9029B310; // Unknown = 
    inline constexpr uintptr_t FFlagAddMapToNineDot = 0x19B9ACB611D; // Bool = false
    inline constexpr uintptr_t FFlagAddMenuNavigationToggleDialog = 0x19B88C4D65D; // Bool = false
    inline constexpr uintptr_t FFlagAddMorePhoneUpsellEvents = 0x19B8C30AD1D; // Bool = true
    inline constexpr uintptr_t FFlagAddNewPlayerListFocusNav = 0x19BACE9621D; // Bool = false
    inline constexpr uintptr_t FFlagAddNewPlayerListMobileFocusNav = 0x19D8704E9D0; // Unknown = 
    inline constexpr uintptr_t FFlagAddNewPlayerListMobileFocusNav2 = 0x19BACE9631D; // Bool = false
    inline constexpr uintptr_t FFlagAddOnRobloxSubscriptionUpsellSuccessCallbackToUnifiedPurchaseModal = 0x19B9AF1CC10; // Unknown = 
    inline constexpr uintptr_t FFlagAddPeoplePageCardLayout = 0x19BBC386B10; // Unknown = 
    inline constexpr uintptr_t FFlagAddPeoplePageCardLayout4 = 0x19BBC38DE90; // Unknown = 
    inline constexpr uintptr_t FFlagAddPerformanceMetricsToUnifiedPurchaseModal = 0x19B9AF1BE50; // Unknown = 
    inline constexpr uintptr_t FFlagAddPerformanceMetricsToUnifiedPurchaseModal3 = 0x19B9AF1BED0; // Unknown = 
    inline constexpr uintptr_t FFlagAddPlacelaunchDeviceBlock2 = 0x19BA672CFD0; // Unknown = 
    inline constexpr uintptr_t FFlagAddPlatformNameToProfileHeader = 0x19BACFD7210; // Unknown = 
    inline constexpr uintptr_t FFlagAddPreselectedAbuseTypeAnalytics = 0x19BBB318F50; // Unknown = 
    inline constexpr uintptr_t FFlagAddPreselectedAbuseTypeAnalytics2 = 0x19B8C30DC1D; // Bool = true
    inline constexpr uintptr_t FFlagAddPriceBelowCurrentlyWearing = 0x19B8EAEE91D; // Bool = true
    inline constexpr uintptr_t FFlagAddPromCounterToKeystoreOps = 0x19B9ACB8950; // Unknown = 
    inline constexpr uintptr_t FFlagAddPublishAssetPrompt6 = 0x19B9AF11290; // Unknown = 
    inline constexpr uintptr_t FFlagAddPurchaseOptionForProvidingBalance = 0x19B9AF1B490; // Unknown = 
    inline constexpr uintptr_t FFlagAddReasonToEveryLogout = 0x19B945A0350; // Unknown = 
    inline constexpr uintptr_t FFlagAddReportCharacterLimit = 0x19BBD290D2D; // Bool = false
    inline constexpr uintptr_t FFlagAddSocialLinksToCommunityProfile = 0x19BACFDFF90; // Unknown = 
    inline constexpr uintptr_t FFlagAddSocialLinksToCommunityProfile_v3 = 0x19BACFDF390; // Unknown = 
    inline constexpr uintptr_t FFlagAddStatusIndicatorToBaseRow_v2 = 0x19B8C2E1710; // Unknown = 
    inline constexpr uintptr_t FFlagAddSwitchTabHintsToIEM = 0x19B9ACB90D0; // Unknown = 
    inline constexpr uintptr_t FFlagAddTakeItDownReportLinkToSurfaces = 0x19B8C30E75D; // Bool = true
    inline constexpr uintptr_t FFlagAddThumbnailReportToPlayerFeedback = 0x19B90262FDD; // Bool = false
    inline constexpr uintptr_t FFlagAddThumbnailSelectorReport = 0x19BBB3185D0; // Unknown = 
    inline constexpr uintptr_t FFlagAddThumbnailSelectorReport6 = 0x19B8C30CD90; // Unknown = 
    inline constexpr uintptr_t FFlagAddTimerToBulkPurchaseBuyButton = 0x19B9F927A5D; // Bool = false
    inline constexpr uintptr_t FFlagAddTopBarScrim = 0x19BACFEE25D; // Bool = false
    inline constexpr uintptr_t FFlagAddTraversalBackButton699v1 = 0x19BBC38EED0; // Unknown = 
    inline constexpr uintptr_t FFlagAddTraversalBackButtonAnimation699v1 = 0x19BBC380790; // Unknown = 
    inline constexpr uintptr_t FFlagAddTraversalHistory699v1 = 0x19BBC383990; // Unknown = 
    inline constexpr uintptr_t FFlagAddTraversalHistoryReactMenuButtons = 0x19BBE91E695; // Bool = false
    inline constexpr uintptr_t FFlagAddTypesToWidgetItems = 0x19BA3A58590; // Unknown = 
    inline constexpr uintptr_t FFlagAddUILessMode = 0x19B8578B89D; // Bool = false
    inline constexpr uintptr_t FFlagAddUnderlineToLinksInTextWithTranslation = 0x19BB7F40690; // Unknown = 
    inline constexpr uintptr_t FFlagAddUnifiedPurchaseFlowTTIToEDP = 0x19B9AF1B150; // Unknown = 
    inline constexpr uintptr_t FFlagAddUnifiedPurchaseRobuxUpsellCompletedTelemetry = 0x19D85DC88D0; // Unknown = 
    inline constexpr uintptr_t FFlagAddUnifiedPurchaseRobuxUpsellCompletedTelemetry2 = 0x19D85DC6210; // Unknown = 
    inline constexpr uintptr_t FFlagAddUpsellEntryComponentToAnalytics = 0x19BA60981D0; // Unknown = 
    inline constexpr uintptr_t FFlagAddVideoToCommunityProfile = 0x19BACFD6910; // Unknown = 
    inline constexpr uintptr_t FFlagAddVideoToCommunityProfile_v7 = 0x19BACFD8A90; // Unknown = 
    inline constexpr uintptr_t FFlagAddVipOwnerNotPresentConnectionError = 0x19BA672D3DD; // Bool = false
    inline constexpr uintptr_t FFlagAdjustHorizontalUserListSizeForMobile = 0x19BA67979D0; // Unknown = 
    inline constexpr uintptr_t FFlagAdoptStyleTokens = 0x19BA607699D; // Bool = true
    inline constexpr uintptr_t FFlagAdsInteractivityControlsFixStyleLink = 0x19BA8A0C6D0; // Unknown = 
    inline constexpr uintptr_t FFlagAgeBasedUXHomepageVerificationBannerGreyButton = 0x19B8C2E4890; // Unknown = 
    inline constexpr uintptr_t FFlagAgeBasedUXHomepageVerificationBannerLockIcon = 0x19BA6F62D9D; // Bool = false
    inline constexpr uintptr_t FFlagAgreementItemsOrderFixEnabled = 0x19B859C9BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAllowAmpV2FeatureAccessCall = 0x19B88C6125D; // Bool = false
    inline constexpr uintptr_t FFlagAllowCustomUnifiedEventFilter = 0x19BB2B247B5; // Bool = true
    inline constexpr uintptr_t FFlagAllowDisconnectGuiForOkUnknown = 0x19B9FDD4BD5; // Bool = false
    inline constexpr uintptr_t FFlagAllowDisplayingFoundationIconsForDropdown = 0x19BAD28459D; // Bool = false
    inline constexpr uintptr_t FFlagAllowNumberLocalizationSigFigParam = 0x19B8A186CCD; // Bool = false
    inline constexpr uintptr_t FFlagAllowQrEnlargeUniversally = 0x19BA6076A1D; // Bool = true
    inline constexpr uintptr_t FFlagAlwaysShowGamepadNavigationDialog = 0x19B9FDDC995; // Bool = false
    inline constexpr uintptr_t FFlagAlwaysShowVRToggleV3 = 0x19B9FD8ADDD; // Bool = false
    inline constexpr uintptr_t FFlagAmpGqlPassSuccessfulActions = 0x19B901113D0; // Unknown = 
    inline constexpr uintptr_t FFlagAmpWizardDeepLinkReplaceOnlyWebView = 0x19B9011365D; // Bool = false
    inline constexpr uintptr_t FFlagAndroidPasswordSuggestionExperimentEnrollmentBypass = 0x19BA4D4DC85; // Bool = false
    inline constexpr uintptr_t FFlagAndroidTVExitWithB2 = 0x19B9AF14290; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatAnalyticsUseTelemetryService = 0x19BA6798B90; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatAutotranslationRespectsExperienceChatSetting = 0x19BACE71C10; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatCatchSendMessageSyncError = 0x19B9026B190; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatChannelsGetNewerMessagesWithPrevCursor = 0x19B8FA15110; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatChatLandingScreenRenameFixEnabled = 0x19B8C2E2490; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatContextCardNameLoadingShimmer = 0x19BACE705D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatConversationLoadingSkeleton = 0x19BACE7E110; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatConversationPageSyntheticSystemMessageIxpEnabled = 0x19BACE7C350; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatConversationStore = 0x19B9987B235; // Bool = true
    inline constexpr uintptr_t FFlagAppChatCustomConversationListRow = 0x19B8FA1CEDD; // Bool = false
    inline constexpr uintptr_t FFlagAppChatDiscloseUpdateSecondVersion = 0x19B8578775D; // Bool = false
    inline constexpr uintptr_t FFlagAppChatDisclosureUpdateEnabled = 0x19B8C305410; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatDomLocatorFoundationMigration = 0x19B8C2E10D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatEnableAutotranslation = 0x19BA6B36A1D; // Bool = false
    inline constexpr uintptr_t FFlagAppChatEnableAutotranslation2 = 0x19B9026A210; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatEnableDoubleOptInRC3 = 0x19B8C2E2190; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatEnableManualTranslation = 0x19B9026AA90; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatEnableMessageContextMenu = 0x19BA802A4D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatEnableOSAConversationFetchForFriendsPlaceholdersFix = 0x19B82AC8D9D; // Bool = false
    inline constexpr uintptr_t FFlagAppChatEnableRepliesUIIxpEnabled2 = 0x19BACE71750; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatEnableRootedNavigation2 = 0x19BA6079ED0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatEnabledChromeDropdownFtuxTooltip = 0x19BB8FA4538; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatExcludeStandardizedFieldsFromCounters = 0x19B8FA14ED0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatFixBackButtonOnRotation = 0x19BACE76B10; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatFixPlusBadgeAlignment = 0x19BACE70BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatFixRootChatBackNavigation = 0x19B8C305B50; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatFixRootChatBackNavigationIxpEnabled = 0x19B8FA156DD; // Bool = false
    inline constexpr uintptr_t FFlagAppChatFriendsTabIxpEnabled = 0x19BA802AE50; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatFriendsTabIxpEnabledRC1 = 0x19BA8029550; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatFullPlaintextBeforeGameCards = 0x19B9026BB90; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatGamepadSendButtonNav = 0x19BACE7EC10; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatGlobalSwipeTracking = 0x19BACE7C510; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatHidePlayButtonsInExp = 0x19BA8020790; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatIgnoreUnknownThirdPartyChatStatus = 0x19BA802DD90; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatInExpSelectChatMembersMobileHeight = 0x19BA8022250; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatInExpToastSnoozeMenuDismissFix = 0x19BACFD78D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatInExperienceEnabledV654NewIcon = 0x19B8C2EA810; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatInExperienceTabBarAdjustment = 0x19BA6079AD0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatInvalidGameLinkCard = 0x19BA8023750; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatIxpScreenExposure = 0x19BACE732D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatLoadingIndicatorTransparency = 0x19B8FA1CC9D; // Bool = false
    inline constexpr uintptr_t FFlagAppChatMessageTTIMilestones = 0x19BA6B3B3DD; // Bool = false
    inline constexpr uintptr_t FFlagAppChatMessageTTIMilestones1 = 0x19B9026B510; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatMigrateScrollIntervalTracker2 = 0x19BA802A750; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatMomentShareCard = 0x19BACE77910; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatMomentShareCardNavigation = 0x19B9ACB9690; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatMomentShareCardUseFoundationImage = 0x19BA8024490; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatMoveMainComponent = 0x19B82B7EF1D; // Bool = false
    inline constexpr uintptr_t FFlagAppChatNativeFoundationCornerRadii = 0x19BA8021D10; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatNavigateBackIfOSAUnacknowledged = 0x19B8C2E2690; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatNewChatFixEnabled = 0x19B8C2E2A10; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatNewChatInputBar = 0x19BACE72D90; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatNewChatInputBar2 = 0x19BACE72B90; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatNewChatInputBarIxpEnabled = 0x19BACE71390; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatNewSquadJoinButtonLookIconless = 0x19BACE7FB50; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatNilGuardMessageSort = 0x19B9026A690; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatNilGuardReceivedChatResponse = 0x19B9026B7D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatOnConsoles_Dev = 0x19BA6A3ACD0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatPCMFixBlocking = 0x19BACFD49D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatParticipantDialogGamepadFocus = 0x19B8FA1549D; // Bool = false
    inline constexpr uintptr_t FFlagAppChatPerfTracking = 0x19BA6070FD0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatPerfTracking3 = 0x19BA607F3D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatPresenceStoreMigration = 0x19BA6B3FC1D; // Bool = false
    inline constexpr uintptr_t FFlagAppChatPresenceStoreMigration_v1 = 0x19BA7DA1D8D; // Bool = false
    inline constexpr uintptr_t FFlagAppChatReactToFaeForOsa = 0x19BAC4BCE65; // Bool = true
    inline constexpr uintptr_t FFlagAppChatRefactorChatMessage = 0x19BA8026A90; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatRemoveConversationListDivider = 0x19BACE7A6D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatRemoveConversationListDividerIxpEnabled = 0x19B8FA1E490; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatRemoveDynamicRequires = 0x19BAE779905; // Bool = true
    inline constexpr uintptr_t FFlagAppChatRemoveNotifications = 0x19B8C2E1190; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatRemoveToggleChatPaused = 0x19B8C2E1BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatRemoveUserProfileTitles2 = 0x19B94A150ED; // Bool = true
    inline constexpr uintptr_t FFlagAppChatReplyComposeBarContainer = 0x19BACE72FD0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatReplyComposeBarContainer2 = 0x19BACE7E410; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatRequestedRoute = 0x19BA6079C90; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatResolveShareLinkV2 = 0x19B9026BE50; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatSanitizeConversationTitleRichText = 0x19B8C2E21D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatScrollFrameTimeTracking = 0x19BA6070250; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatShowOSAOnPageEntry2 = 0x19B8C2E2810; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatShutdownBeforeLaunch = 0x19BA802AED0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatSignalsMessageStore = 0x19BA6B3FA10; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatSignalsMessageStore5 = 0x19B8FA15FDD; // Bool = false
    inline constexpr uintptr_t FFlagAppChatSignalsReplyStore = 0x19B8FA15BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatSmartSuggestions = 0x19BACE71790; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatSquadButtonColorUpdate = 0x19BACE7FAD0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatSquadButtonColorUpdateIxpEnabled = 0x19BACE778D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatSquadButtonColorVariantB = 0x19BACE73710; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatSquadButtonHideGamepadIconOnTvRemote = 0x19BACE76110; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatSquadJoinButtonU13OSA = 0x19BAFCF76D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatTimestampInSubtitle = 0x19BC0A66915; // Bool = false
    inline constexpr uintptr_t FFlagAppChatTimestampInSubtitleIxpEnabled = 0x19BB6C1D205; // Bool = false
    inline constexpr uintptr_t FFlagAppChatTopBarConfigDriven = 0x19BA6B3A91D; // Bool = false
    inline constexpr uintptr_t FFlagAppChatTopBarConfigDrivenV6 = 0x19B8FA15C1D; // Bool = false
    inline constexpr uintptr_t FFlagAppChatTopBarSignalsStore = 0x19BA6B3F65D; // Bool = false
    inline constexpr uintptr_t FFlagAppChatTopBarSignalsStoreV2 = 0x19B8FA15ADD; // Bool = false
    inline constexpr uintptr_t FFlagAppChatUnreadMessageCountStore = 0x19B8FC3759D; // Bool = false
    inline constexpr uintptr_t FFlagAppChatUseNewConversationRow = 0x19B8FA1CE10; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatUseProfileFrameThumbnail = 0x19BACE77790; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatUseSwipeForReplies = 0x19BA802FD90; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatUseSwipeForReplies2 = 0x19BA8025750; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatUseSymmetricSwipe = 0x19BA3A88E0D; // Bool = false
    inline constexpr uintptr_t FFlagAppChatUseTextBoxTextOnSend = 0x19BACE7F690; // Unknown = 
    inline constexpr uintptr_t FFlagAppChatUseUltimateListConversationList = 0x19B8FA1C9D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppContainerReadyToRender = 0x19BA5538FD0; // Unknown = 
    inline constexpr uintptr_t FFlagAppDebugPanel = 0x19B9AF15A90; // Unknown = 
    inline constexpr uintptr_t FFlagAppDebugTagAnnotation = 0x19B9AF15BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAppFocusWrapperRefactor = 0x19BC0546810; // Unknown = 
    inline constexpr uintptr_t FFlagAppHeaderBarUseSizeFull = 0x19BAFCF0BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAppIaHomeOmniFeedFix = 0x19B94811150; // Unknown = 
    inline constexpr uintptr_t FFlagAppIaHomeSubTab = 0x19B9ACB15D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppIaHomeSubTabAnalytics = 0x19B9ACBBF10; // Unknown = 
    inline constexpr uintptr_t FFlagAppIaHomeSubTabScrollAwayFull = 0x19B9ACB1A50; // Unknown = 
    inline constexpr uintptr_t FFlagAppIaScopedScrollAway = 0x19B9ACB2E50; // Unknown = 
    inline constexpr uintptr_t FFlagAppIaScrollAway = 0x19B9ACB6BD0; // Unknown = 
    inline constexpr uintptr_t FFlagAppIaScrollAway9 = 0x19B9ACB1090; // Unknown = 
    inline constexpr uintptr_t FFlagAppIaScrollAwayDisableChat = 0x19B90643FDD; // Bool = false
    inline constexpr uintptr_t FFlagAppIaScrollAwayFixSocial = 0x19B9ACBCB10; // Unknown = 
    inline constexpr uintptr_t FFlagAppIaScrollAwayGuac = 0x19B9ACBDA10; // Unknown = 
    inline constexpr uintptr_t FFlagAppIaScrollAwayIgnoreHorizontal = 0x19BA60984D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppIaScrollAwayPinHeader = 0x19B9ACB9150; // Unknown = 
    inline constexpr uintptr_t FFlagAppIaStatusBar = 0x19B9ACB8D90; // Unknown = 
    inline constexpr uintptr_t FFlagAppIaStatusBar3 = 0x19B9ACB1DD0; // Unknown = 
    inline constexpr uintptr_t FFlagAppNavBarFooterVisibleWithoutScrollAway = 0x19BA6093CDD; // Bool = false
    inline constexpr uintptr_t FFlagAppNavBarGateFooterVisibleOnPlacement = 0x19BA60929DD; // Bool = false
    inline constexpr uintptr_t FFlagAppNavBarPerItemThemeOverride2 = 0x19B9AF17250; // Unknown = 
    inline constexpr uintptr_t FFlagAppNavDeviceTier = 0x19BA60975DD; // Bool = false
    inline constexpr uintptr_t FFlagAppNavLabelScaling = 0x19B9ACB7250; // Unknown = 
    inline constexpr uintptr_t FFlagAppNavMyStatsTab3 = 0x19B9AF138D0; // Unknown = 
    inline constexpr uintptr_t FFlagAppNavTelemetryLogger = 0x19B9ACB6D10; // Unknown = 
    inline constexpr uintptr_t FFlagApplyLaunchContextForNewAccountSwitches = 0x19B945A5BD0; // Unknown = 
    inline constexpr uintptr_t FFlagApplyResolutionScale = 0x19B8578A2DD; // Bool = false
    inline constexpr uintptr_t FFlagArgoEnableMoments = 0x19B9ACB2890; // Unknown = 
    inline constexpr uintptr_t FFlagArgusTabImpliesFlyout = 0x19B9ACB0750; // Unknown = 
    inline constexpr uintptr_t FFlagAudioPlayerCanSkipTracks = 0x19B9ACBA9D0; // Unknown = 
    inline constexpr uintptr_t FFlagAudioPreviewLua = 0x19D86F064D0; // Unknown = 
    inline constexpr uintptr_t FFlagAuthBirthdayBarFoundationColors = 0x19B88C4AE90; // Unknown = 
    inline constexpr uintptr_t FFlagAuthCollapsingValidatorFoundationInput2 = 0x19B9ACBE2D0; // Unknown = 
    inline constexpr uintptr_t FFlagAuthFlowProviderEnabled = 0x19B85788B1D; // Bool = false
    inline constexpr uintptr_t FFlagAuthFlowStandaloneEnabled = 0x19D88FB0D45; // Bool = false
    inline constexpr uintptr_t FFlagAuthFlowStandaloneEnabledDev = 0x19B85788BDD; // Bool = false
    inline constexpr uintptr_t FFlagAuthNewModalSchematization = 0x19B90294B50; // Unknown = 
    inline constexpr uintptr_t FFlagAuthValidatorStyleOverrides = 0x19B9ACB2A90; // Unknown = 
    inline constexpr uintptr_t FFlagAuthValidatorStyleOverrides3 = 0x19B9ACBA3D0; // Unknown = 
    inline constexpr uintptr_t FFlagAvatarAutocompleteEnabledForAll2 = 0x19B9029FED0; // Unknown = 
    inline constexpr uintptr_t FFlagAvatarContextMenuItemsChatButtonRefactor = 0x19BA6078D5D; // Bool = false
    inline constexpr uintptr_t FFlagAvatarHeadshotIconUseProfileFrameThumbnail = 0x19B859CA6D0; // Unknown = 
    inline constexpr uintptr_t FFlagAvatarJointUpgradeInUA = 0x19B9AF1ADD0; // Unknown = 
    inline constexpr uintptr_t FFlagAvatarJointUpgradeInUA3 = 0x19B99717810; // Unknown = 
    inline constexpr uintptr_t FFlagAvatarPreviewerDisambiguationMenuModal = 0x19B82A7F11D; // Bool = true
    inline constexpr uintptr_t FFlagAvatarSwitcherAccurateAvatarWarning = 0x19BA3A52DD0; // Unknown = 
    inline constexpr uintptr_t FFlagAvatarSwitcherCounters = 0x19BA3A56C90; // Unknown = 
    inline constexpr uintptr_t FFlagAvatarSwitcherExpiredItemsWarning = 0x19BA3A5A61D; // Bool = false
    inline constexpr uintptr_t FFlagAvatarSwitcherMakeupSupport = 0x19BAC878B08; // Unknown = 
    inline constexpr uintptr_t FFlagAvatarSwitcherUiFixes = 0x19BA3A531D0; // Unknown = 
    inline constexpr uintptr_t FFlagAvatarSwitcherUseAvatarInventoryEndpoint = 0x19BA3A50D10; // Unknown = 
    inline constexpr uintptr_t FFlagAvatarSwitcherWarningLayoutFix = 0x19BA3A53C90; // Unknown = 
    inline constexpr uintptr_t FFlagBackpackResponsiveUnits = 0x19B9AF19B50; // Unknown = 
    inline constexpr uintptr_t FFlagBadgeVisibilitySettingEnabled = 0x19BA59BB310; // Unknown = 
    inline constexpr uintptr_t FFlagBadgeVisibilitySettingEnabled_v3 = 0x19BA59BF050; // Unknown = 
    inline constexpr uintptr_t FFlagBasedExposureLoggingCatalogPage = 0x19BA3A593D0; // Unknown = 
    inline constexpr uintptr_t FFlagBatchVoiceParticipantsUpdates = 0x19B8FDEA71D; // Bool = false
    inline constexpr uintptr_t FFlagBehaviorCollectionControlEnabled = 0x19BB6BBE19D; // Bool = true
    inline constexpr uintptr_t FFlagBlackbirdRequiresIAP = 0x19BA6A30FD0; // Unknown = 
    inline constexpr uintptr_t FFlagBlackbirdUpdateStringFlyoutMenu = 0x19BA6A32550; // Unknown = 
    inline constexpr uintptr_t FFlagBlackbirdUpsellGateResale = 0x19B9EE00B1D; // Bool = false
    inline constexpr uintptr_t FFlagBlackbirdUpsellGateResaleAndTimedOption = 0x19B9EE0065D; // Bool = false
    inline constexpr uintptr_t FFlagBlackbirdUpsellGateTimedOption = 0x19B9EE0095D; // Bool = false
    inline constexpr uintptr_t FFlagBlackbirdUpsellProd2 = 0x19B9ACBFBD0; // Unknown = 
    inline constexpr uintptr_t FFlagBlackbirdUpsellVersion = 0x19B9ACB8210; // Unknown = 
    inline constexpr uintptr_t FFlagBlendedSerpUserPresenceInLineEnabled = 0x19BACFDA810; // Unknown = 
    inline constexpr uintptr_t FFlagBlockEDPClickthrough = 0x19B8C30309D; // Bool = true
    inline constexpr uintptr_t FFlagBlockingConsolePreparePaymentCheck = 0x19BAC8330DD; // Bool = false
    inline constexpr uintptr_t FFlagBlockingUtilityClearUnblockedFromBlockedList = 0x19B8FDE9A5D; // Bool = false
    inline constexpr uintptr_t FFlagBlockingUtilityRefireOnReplace = 0x19B8FDE9B9D; // Bool = false
    inline constexpr uintptr_t FFlagBoldBlackbirdUpsellBannerStroke = 0x19B8FC3351D; // Bool = false
    inline constexpr uintptr_t FFlagBoldSearchListPickerSuggestions2 = 0x19B9029F590; // Unknown = 
    inline constexpr uintptr_t FFlagBuildAudiencePublishPrompt = 0x19BAD1A644D; // Bool = false
    inline constexpr uintptr_t FFlagBuildBackButtonChevron = 0x19BAD1ADB75; // Bool = true
    inline constexpr uintptr_t FFlagBuildDesktopReadiness = 0x19BAD08003D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceAskForLogsSeverityRetention = 0x19BAD587E1D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceAssetLibrary = 0x19BAD58C79D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceBuyRobuxContext = 0x19BAD58CE90; // Unknown = 
    inline constexpr uintptr_t FFlagBuildExperienceChatHistoryLoadingSkeleton = 0x19BAD5888DD; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceChatHistoryPrefetch = 0x19BAD58819D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceClientDataModelTools2 = 0x19B9AF14110; // Unknown = 
    inline constexpr uintptr_t FFlagBuildExperienceConfigurableProductionTemplatePlaceId = 0x19BAD5883DD; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceCopyChatMessages = 0x19BAD58A91D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceCreatorCreditUsageBadge = 0x19BAD5840DD; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceDontAskAgainPushUpsell = 0x19BAD58C05D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceExcludeUserWaitFromTurnDuration = 0x19BAD58A65D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceFixChatBottomLock = 0x19BAD586F9D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceFixChatComposerInitialSendState = 0x19BAD585CDD; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceMyCreationsUseAudiences = 0x19BAD58D710; // Unknown = 
    inline constexpr uintptr_t FFlagBuildExperienceMyCreationsUseUniverseList = 0x19BAD58DC5D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperiencePersistPlaytestLogs = 0x19BAD58735D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperiencePrivateInvites = 0x19BAD583B1D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceRichTextUserMessages = 0x19BAD58B61D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceSecondActivateAfterSetAudiences = 0x19BAD58E1D0; // Unknown = 
    inline constexpr uintptr_t FFlagBuildExperienceShareUseUniverseSummary = 0x19B9AF15790; // Unknown = 
    inline constexpr uintptr_t FFlagBuildExperienceShowThinkingBeforeUniverseCreation = 0x19BAD58755D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceSinglePlaytestCard = 0x19BAD584D1D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceStableMyCreationsListItems = 0x19D80291CD0; // Unknown = 
    inline constexpr uintptr_t FFlagBuildExperienceStableMyCreationsListItems2 = 0x19BAD58E2DD; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceToolResultFailureRecovery = 0x19BAD5861DD; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceTooltipsLightDismiss = 0x19BAD2874DD; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceUseCommonTextArea = 0x19BAD58601D; // Bool = false
    inline constexpr uintptr_t FFlagBuildExperienceUseFoundationSheet = 0x19BAD28A850; // Unknown = 
    inline constexpr uintptr_t FFlagBuildExperienceUserMessageHapticFeedback = 0x19BAD58B99D; // Bool = false
    inline constexpr uintptr_t FFlagBuildLocalization = 0x19B9AF15390; // Unknown = 
    inline constexpr uintptr_t FFlagBuildNoPublishOnRevert = 0x19BAD58085D; // Bool = false
    inline constexpr uintptr_t FFlagBuildPublishAccountTooNewError = 0x19BACE7109D; // Bool = false
    inline constexpr uintptr_t FFlagBuildRehydrateOnPublish = 0x19BAD58D310; // Unknown = 
    inline constexpr uintptr_t FFlagBuildTabBetweenMeAndChat = 0x19B859CADD0; // Unknown = 
    inline constexpr uintptr_t FFlagBuilderSansNavbarFlagSize = 0x19B90649450; // Unknown = 
    inline constexpr uintptr_t FFlagBulkPurchaseCloseOnEscape = 0x19B9F925A1D; // Bool = false
    inline constexpr uintptr_t FFlagBulkPurchaseEnablePurchaseOptions = 0x19B9F927CD0; // Unknown = 
    inline constexpr uintptr_t FFlagBulkPurchaseHandleMissingFulfillmentGroupsKey = 0x19B9F928F50; // Unknown = 
    inline constexpr uintptr_t FFlagBulkPurchaseUsesPurchaseOptionDiscount = 0x19B9F9292DD; // Bool = false
    inline constexpr uintptr_t FFlagBypassKeystoreLoginIxpV2 = 0x19B9ACBF210; // Unknown = 
    inline constexpr uintptr_t FFlagCIDeeplinkEnabledForAll = 0x19BACFD1410; // Unknown = 
    inline constexpr uintptr_t FFlagCTAChangeMorePageFlyoutButtonText = 0x19BA553C7D0; // Unknown = 
    inline constexpr uintptr_t FFlagCacheCredentialsProtocolIsAvailable = 0x19B8FC38590; // Unknown = 
    inline constexpr uintptr_t FFlagCacheReadParsePolicy = 0x19BB6BBCC10; // Unknown = 
    inline constexpr uintptr_t FFlagCacheShouldShowPushUpsellHideResponse = 0x19B8FA1F650; // Unknown = 
    inline constexpr uintptr_t FFlagCapturePermissionsPromptFreeMouse = 0x19BAE74012D; // Bool = true
    inline constexpr uintptr_t FFlagCaptureServiceRetrieveCapturesSafeguard = 0x19BAC87DD50; // Unknown = 
    inline constexpr uintptr_t FFlagCapturesAddLegacyVideoRecordingLogging_v2 = 0x19D86F07390; // Unknown = 
    inline constexpr uintptr_t FFlagCapturesDragEdgeOffsetEnabled = 0x19D86F08C50; // Unknown = 
    inline constexpr uintptr_t FFlagCapturesEnableDownloadPromptForU13 = 0x19D86F00890; // Unknown = 
    inline constexpr uintptr_t FFlagCapturesFetchUseSharedUtility = 0x19D86EC1E55; // Bool = false
    inline constexpr uintptr_t FFlagCapturesGalleryDespawnOnMenuClose = 0x19D86F06A10; // Unknown = 
    inline constexpr uintptr_t FFlagCapturesLayerExposureLoggingEnabled = 0x19D86F04210; // Unknown = 
    inline constexpr uintptr_t FFlagCapturesPostEnabledForAll = 0x19BACFD16D0; // Unknown = 
    inline constexpr uintptr_t FFlagCapturesPostEnabledForAll_v4 = 0x19BACFD4490; // Unknown = 
    inline constexpr uintptr_t FFlagCapturesPromptShareImageFixEnabled = 0x19D86F0D1D0; // Unknown = 
    inline constexpr uintptr_t FFlagCapturesRecursiveCoreUIRemoval = 0x19BA6C4089D; // Bool = false
    inline constexpr uintptr_t FFlagCapturesUpdateUsePlayShutterSoundTesting = 0x19BAE77E92D; // Bool = true
    inline constexpr uintptr_t FFlagCapturesVideoBulkManagerStopGap = 0x19BAC87C2DD; // Bool = false
    inline constexpr uintptr_t FFlagCapturesVideoCaptureTriggerHandlerEnabled = 0x19D87046310; // Unknown = 
    inline constexpr uintptr_t FFlagCapturesVideoDeleteAsync = 0x19BACE9339D; // Bool = false
    inline constexpr uintptr_t FFlagCapturesVideoSupportLegacyVideos = 0x19BAC87C49D; // Bool = false
    inline constexpr uintptr_t FFlagCarouselUseNewUserTileWithPresenceIcon = 0x19B8EE09C3D; // Bool = false
    inline constexpr uintptr_t FFlagCarouselUserTileUseProfileFrameThumbnail = 0x19B8F90EC5D; // Bool = false
    inline constexpr uintptr_t FFlagCenterShiftLockOverride = 0x19B9FD8B7DD; // Bool = false
    inline constexpr uintptr_t FFlagChallengeInterceptorResolveOriginalNetworkImpl = 0x19B902922D0; // Unknown = 
    inline constexpr uintptr_t FFlagChangeSocialGraphLifecycleEvent = 0x19B9ACBDB10; // Unknown = 
    inline constexpr uintptr_t FFlagChangeToggleMicText = 0x19B9FDD17D5; // Bool = false
    inline constexpr uintptr_t FFlagCharacterNameHandlerUserProfileApiEnabledForAll = 0x19B8C2E92D0; // Unknown = 
    inline constexpr uintptr_t FFlagChartsHydrationStreaming2 = 0x19B88C28EDD; // Bool = false
    inline constexpr uintptr_t FFlagChatIntegrationFixShortcut = 0x19B9FDD1815; // Bool = false
    inline constexpr uintptr_t FFlagChatLineReportingFocusFixesEnabled = 0x19B8C30CC1D; // Bool = true
    inline constexpr uintptr_t FFlagChatLineReportingGlobalMuteEnabled2 = 0x19B8C30CE5D; // Bool = true
    inline constexpr uintptr_t FFlagChatModeratedMaskRandomLength = 0x19B8C305210; // Unknown = 
    inline constexpr uintptr_t FFlagChatOptimizeCommandProcessing = 0x19BA3A5575D; // Bool = false
    inline constexpr uintptr_t FFlagChatSnoozeMenuDescriptionFixEnabled = 0x19BAFCF65D0; // Unknown = 
    inline constexpr uintptr_t FFlagChatSummariesSettingEnabled3 = 0x19B8C302E9D; // Bool = true
    inline constexpr uintptr_t FFlagChatTabHideGroupsLinkOnVR = 0x19B8FA1F49D; // Bool = false
    inline constexpr uintptr_t FFlagChatTranslationForceSetting = 0x19B9FD8C25D; // Bool = false
    inline constexpr uintptr_t FFlagChatTranslationHoldoutEnabled = 0x19B9FD8BCD0; // Unknown = 
    inline constexpr uintptr_t FFlagChatTranslationNewDefaults = 0x19B9FD8C41D; // Bool = false
    inline constexpr uintptr_t FFlagChatTranslationSettingEnabled3 = 0x19B9AF10650; // Unknown = 
    inline constexpr uintptr_t FFlagChatTranslationShowFTUX = 0x19BA6B3F890; // Unknown = 
    inline constexpr uintptr_t FFlagChatTranslationWaitForIXP = 0x19B9FD8C09D; // Bool = false
    inline constexpr uintptr_t FFlagChatWindowUseCallbackOptimizations = 0x19BA5153C9D; // Bool = false
    inline constexpr uintptr_t FFlagCheckCameraAvailabilityBeforePermissions = 0x19BA4E9B450; // Unknown = 
    inline constexpr uintptr_t FFlagCheckForUpdatePromise2 = 0x19B9AF1ACD0; // Unknown = 
    inline constexpr uintptr_t FFlagCheckUniversePlaceBeforeSuspending = 0x19BACFDF750; // Unknown = 
    inline constexpr uintptr_t FFlagCheckUserModerationAfterLogin = 0x19B8C30B750; // Unknown = 
    inline constexpr uintptr_t FFlagChromeCentralizedConfiguration4 = 0x19B9ACB75D0; // Unknown = 
    inline constexpr uintptr_t FFlagChromeChatGamepadSupportFix = 0x19B9ACB86D0; // Unknown = 
    inline constexpr uintptr_t FFlagChromeDeprecateMRUs = 0x19B9481539D; // Bool = false
    inline constexpr uintptr_t FFlagChromeMusicWindowTopbarReappearsOnGamepad = 0x19B9ACB8CD0; // Unknown = 
    inline constexpr uintptr_t FFlagChromeShortcutAddRespawnLeaveToIEM = 0x19B9ACB1B10; // Unknown = 
    inline constexpr uintptr_t FFlagChromeShortcutChatOpenKeyboard = 0x19B9ACB6690; // Unknown = 
    inline constexpr uintptr_t FFlagChromeShortcutRemoveLeaveOnRespawnPage = 0x19B9ACB3390; // Unknown = 
    inline constexpr uintptr_t FFlagChromeShortcutRemoveRespawnOnLeavePage = 0x19B9ACB0350; // Unknown = 
    inline constexpr uintptr_t FFlagChromeWindowSignalConstraintsToggle = 0x19B88C4F410; // Unknown = 
    inline constexpr uintptr_t FFlagCiDeprecateFindFriendsModal = 0x19BA59BE51D; // Bool = false
    inline constexpr uintptr_t FFlagCleanUpAXAlternativeLandingPageIXP = 0x19B90647EDD; // Bool = false
    inline constexpr uintptr_t FFlagClearPolicyOnLogout = 0x19BB6BBCCD0; // Unknown = 
    inline constexpr uintptr_t FFlagClearProductInfoCachesOnPriceChanged = 0x19D85DCA450; // Unknown = 
    inline constexpr uintptr_t FFlagClearUserFromRecentVoiceDataOnLeave = 0x19B8FDEA0DD; // Bool = false
    inline constexpr uintptr_t FFlagClientErrorAdditionalArgs = 0x19BBC1C1D5D; // Bool = false
    inline constexpr uintptr_t FFlagClientToastNotificationsRedirect4 = 0x19BACFEAD50; // Unknown = 
    inline constexpr uintptr_t FFlagCloseBadgeSheetOnAbuseReport2 = 0x19BA5533650; // Unknown = 
    inline constexpr uintptr_t FFlagCloseFavoritePromptWithB = 0x19B9F29279D; // Bool = false
    inline constexpr uintptr_t FFlagCollectiblesCatalogFollowUpForSaleLocation = 0x19B9026F910; // Unknown = 
    inline constexpr uintptr_t FFlagCollectionViewMathChanges = 0x19B88C25BD0; // Unknown = 
    inline constexpr uintptr_t FFlagCommunitiesUseVisualConfigUtil2 = 0x19BC0546B90; // Unknown = 
    inline constexpr uintptr_t FFlagCompleteFlowInStudioAccept = 0x19BAC836FDD; // Bool = false
    inline constexpr uintptr_t FFlagConfirmationButtonsUseGreyButtons = 0x19B9FD86E15; // Bool = false
    inline constexpr uintptr_t FFlagConnectionAmpParentalApprovalUpsell = 0x19BA553F790; // Unknown = 
    inline constexpr uintptr_t FFlagConnectionAmpUpsellOnLeave = 0x19BA553AE10; // Unknown = 
    inline constexpr uintptr_t FFlagConnectionChannelsTileSize = 0x19B8C2E4790; // Unknown = 
    inline constexpr uintptr_t FFlagConnectionEnableAutoReconnect = 0x19BA672C6DD; // Bool = false
    inline constexpr uintptr_t FFlagConnectionManagementChips_V3 = 0x19B8C3034DD; // Bool = true
    inline constexpr uintptr_t FFlagConnectionRemoveLoadingTimeout = 0x19B9985639D; // Bool = false
    inline constexpr uintptr_t FFlagConnectionUpsellAnalytics = 0x19BA5537550; // Unknown = 
    inline constexpr uintptr_t FFlagConnectionsHubLayerExposure = 0x19B949FA42D; // Bool = false
    inline constexpr uintptr_t FFlagConnectionsToFriendsRename = 0x19BA59BDED0; // Unknown = 
    inline constexpr uintptr_t FFlagConnectionsToFriendsRename1 = 0x19BA59BB810; // Unknown = 
    inline constexpr uintptr_t FFlagConnectionsToFriendsRenameP1_v1 = 0x19BA59B595D; // Bool = false
    inline constexpr uintptr_t FFlagConsoleApplyTokenizationEdp = 0x19B8578A1DD; // Bool = false
    inline constexpr uintptr_t FFlagConsoleChatUseChromeFocusUtils = 0x19B9ACB43D0; // Unknown = 
    inline constexpr uintptr_t FFlagConsoleCloseAffordanceFix = 0x19BA6076A9D; // Bool = true
    inline constexpr uintptr_t FFlagConsoleVoiceIXPEnabled = 0x19B8FDE9A10; // Unknown = 
    inline constexpr uintptr_t FFlagContactImportButtonsExperimentEnabled = 0x19BAFCF9D10; // Unknown = 
    inline constexpr uintptr_t FFlagContactImporterIXPCleanup = 0x19BA59B6B10; // Unknown = 
    inline constexpr uintptr_t FFlagContactsListEmojiSorting = 0x19BAFCFAA90; // Unknown = 
    inline constexpr uintptr_t FFlagContactsListEmojiSortingIXP = 0x19B8EAE1530; // Unknown = 
    inline constexpr uintptr_t FFlagContactsListEmojiSortingIxpEnabled = 0x19BAFCFAF50; // Unknown = 
    inline constexpr uintptr_t FFlagContactsListEntryUpdatedTruncationFix = 0x19BAFB25B50; // Unknown = 
    inline constexpr uintptr_t FFlagContentFeedEnableReactions = 0x19BACFD9050; // Unknown = 
    inline constexpr uintptr_t FFlagCoreMicManagerRefactor = 0x19B8FDEB8D0; // Unknown = 
    inline constexpr uintptr_t FFlagCoreScriptBacktraceRepeatedErrorRateLimiting = 0x19BA5537EDD; // Bool = false
    inline constexpr uintptr_t FFlagCoreScriptShowTeleportPrompt = 0x19B9FDD4C55; // Bool = false
    inline constexpr uintptr_t FFlagCoreScriptsProfilerTelemetryContext = 0x19B9AF12050; // Unknown = 
    inline constexpr uintptr_t FFlagCoreUiMigrateUIBloxToFoundation = 0x19B9AF13790; // Unknown = 
    inline constexpr uintptr_t FFlagCoreUiMigrateUIBloxToFoundation2 = 0x19B9AF13490; // Unknown = 
    inline constexpr uintptr_t FFlagCreateConnectionsHub_v6 = 0x19B8C2E2D50; // Unknown = 
    inline constexpr uintptr_t FFlagCreateMomentsToast = 0x19BBF256310; // Unknown = 
    inline constexpr uintptr_t FFlagCreateMomentsToast_v3 = 0x19BB6B28995; // Bool = false
    inline constexpr uintptr_t FFlagCreatorAgentChatFilterTerminalClientTools = 0x19BAD28809D; // Bool = false
    inline constexpr uintptr_t FFlagCreatorAgentChatParseDirectPublishVersion = 0x19B9AF155D0; // Unknown = 
    inline constexpr uintptr_t FFlagCreatorAgentChatStrictAskUserToolName = 0x19BAD28841D; // Bool = false
    inline constexpr uintptr_t FFlagCreatorSubtitleNavigationIXPEnabled = 0x19B8EDC6D5D; // Bool = false
    inline constexpr uintptr_t FFlagCrossPlayActuallyResetErrorStates = 0x19B859CA95D; // Bool = false
    inline constexpr uintptr_t FFlagCurrencyTransferCenterRobuxIcon = 0x19B9F92A150; // Unknown = 
    inline constexpr uintptr_t FFlagCurrencyTransferDeepLinkValidateSender = 0x19B8C2EB89D; // Bool = false
    inline constexpr uintptr_t FFlagCurrencyTransferFixDesktopInput = 0x19B9F92C85D; // Bool = false
    inline constexpr uintptr_t FFlagCurrencyTransferFixHeaderTouchPadding = 0x19B9F92B110; // Unknown = 
    inline constexpr uintptr_t FFlagCurrencyTransferFixTextBoxInput = 0x19B9F92B090; // Unknown = 
    inline constexpr uintptr_t FFlagCurrencyTransferFlowUIImprovementFix = 0x19B9F92B510; // Unknown = 
    inline constexpr uintptr_t FFlagCurrencyTransferReceiveLimitExceededError = 0x19B9F92D390; // Unknown = 
    inline constexpr uintptr_t FFlagCurrencyTransferSignalRecipientOnComplete = 0x19B9F92E55D; // Bool = false
    inline constexpr uintptr_t FFlagCurrencyTransferSuccessModal = 0x19B9F92FC1D; // Bool = false
    inline constexpr uintptr_t FFlagCurrencyTransferUseAmpWizardContainerForInApp = 0x19B9F92EB10; // Unknown = 
    inline constexpr uintptr_t FFlagCurrencyTransferUseBackendTransferLimitsV1 = 0x19B9F92CA5D; // Bool = false
    inline constexpr uintptr_t FFlagCurrencyTransferUseProfileFrameThumbnail = 0x19B9F92B7D0; // Unknown = 
    inline constexpr uintptr_t FFlagCurrencyTransferUseRoactNetworking = 0x19B9F92FE9D; // Bool = false
    inline constexpr uintptr_t FFlagDSAConsequenceTransparency = 0x19BC05413D0; // Unknown = 
    inline constexpr uintptr_t FFlagDSAIllegalContentReporting2 = 0x19BC0547A50; // Unknown = 
    inline constexpr uintptr_t FFlagDSALuaGeoGateBEDUIDevMode = 0x19BC0546210; // Unknown = 
    inline constexpr uintptr_t FFlagDSAVRSkipFrontendGeoCheck = 0x19BC0541590; // Unknown = 
    inline constexpr uintptr_t FFlagDeactivateAudioDeviceOnVoiceLeave = 0x19B8FDEB95D; // Bool = false
    inline constexpr uintptr_t FFlagDebounceVoiceSelectorIndexChange = 0x19B9FD8C01D; // Bool = false
    inline constexpr uintptr_t FFlagDebugAEGIS1AppChatBanner = 0x19B9026C15D; // Bool = false
    inline constexpr uintptr_t FFlagDebugAPPEXP4747B = 0x19BA6C4099D; // Bool = false
    inline constexpr uintptr_t FFlagDebugAlwaysShowDisableCameraToast = 0x19B9FD894D0; // Unknown = 
    inline constexpr uintptr_t FFlagDebugAlwaysShowSystemTrayModal = 0x19B9ACB1910; // Unknown = 
    inline constexpr uintptr_t FFlagDebugAppChat = 0x19BA8026B90; // Unknown = 
    inline constexpr uintptr_t FFlagDebugAppChatDisplayOnJoin = 0x19B9987EE55; // Bool = true
    inline constexpr uintptr_t FFlagDebugAppChatEnableDomLocators = 0x19B8C2E1150; // Unknown = 
    inline constexpr uintptr_t FFlagDebugAppChatFae = 0x19B9026C0DD; // Bool = false
    inline constexpr uintptr_t FFlagDebugCrossPlaySystemUi = 0x19BB6BB325D; // Bool = false
    inline constexpr uintptr_t FFlagDebugDefaultChannelStartMuted = 0x19B9F0AB850; // Unknown = 
    inline constexpr uintptr_t FFlagDebugEnableChromeOnUnsupportedDevices = 0x19BA3BBD7D0; // Unknown = 
    inline constexpr uintptr_t FFlagDebugEnableErrorStringTesting = 0x19BA672B9D0; // Unknown = 
    inline constexpr uintptr_t FFlagDebugEnableImageLoadObserver = 0x19B9481299D; // Bool = false
    inline constexpr uintptr_t FFlagDebugEnableImpressionsVisualizer = 0x19B8F90EE9D; // Bool = false
    inline constexpr uintptr_t FFlagDebugEnablePageLoadTrackerVisualizer = 0x19B8578BD1D; // Bool = false
    inline constexpr uintptr_t FFlagDebugEnablePioneerUX = 0x19B9ACB7750; // Unknown = 
    inline constexpr uintptr_t FFlagDebugEnableUnibarDummyIntegrations = 0x19B9ACB6A50; // Unknown = 
    inline constexpr uintptr_t FFlagDebugEnableVRFTUXExperienceInStudio = 0x19BAEB77210; // Unknown = 
    inline constexpr uintptr_t FFlagDebugExpChat = 0x19B9F0AC2DD; // Bool = false
    inline constexpr uintptr_t FFlagDebugExpChatAlwaysRunTCS = 0x19BACFD1E90; // Unknown = 
    inline constexpr uintptr_t FFlagDebugExpChatPerf = 0x19BA6B3F29D; // Bool = false
    inline constexpr uintptr_t FFlagDebugForceConsoleSafeInsets = 0x19BA6A39450; // Unknown = 
    inline constexpr uintptr_t FFlagDebugForceEnableChatButtonOn = 0x19BA6B3EED0; // Unknown = 
    inline constexpr uintptr_t FFlagDebugForceShowIllegalContentReportingUI = 0x19BB6BBE91D; // Bool = true
    inline constexpr uintptr_t FFlagDebugFriendsChat = 0x19BACFD591D; // Bool = false
    inline constexpr uintptr_t FFlagDebugImmersionModeNonVR = 0x19B9F0A6090; // Unknown = 
    inline constexpr uintptr_t FFlagDebugInlineLayout = 0x19BBE2F963D; // Bool = false
    inline constexpr uintptr_t FFlagDebugLuaAppAlwaysUseGamepad = 0x19BC054DDD0; // Unknown = 
    inline constexpr uintptr_t FFlagDebugLuaAppEnableScale = 0x19BA461009D; // Bool = false
    inline constexpr uintptr_t FFlagDebugLuaAppEnableTokenScale = 0x19BA3A7F010; // Unknown = 
    inline constexpr uintptr_t FFlagDebugLuaAppThrowErrorInStarterScript = 0x19B90295510; // Unknown = 
    inline constexpr uintptr_t FFlagDebugLuaAppValidateProps = 0x19B857825DD; // Bool = false
    inline constexpr uintptr_t FFlagDebugLuaAppsUseDarkTheme = 0x19B8C31695D; // Bool = false
    inline constexpr uintptr_t FFlagDebugLuaArgCheck = 0x19B8C317010; // Unknown = 
    inline constexpr uintptr_t FFlagDebugMessageProfiling = 0x19BA51508DD; // Bool = false
    inline constexpr uintptr_t FFlagDebugMusicSampleSounds = 0x19D84DA2B90; // Unknown = 
    inline constexpr uintptr_t FFlagDebugMyStatsExperienceAgentSpec = 0x19BAD287590; // Unknown = 
    inline constexpr uintptr_t FFlagDebugMyStatsExperienceStats = 0x19BAD28A31D; // Bool = false
    inline constexpr uintptr_t FFlagDebugOverrideCaptureControlsVideoGuacPolicy = 0x19D86F03910; // Unknown = 
    inline constexpr uintptr_t FFlagDebugPrintIntervalPerformanceTrackerResults = 0x19B9CB7E19D; // Bool = false
    inline constexpr uintptr_t FFlagDebugReactSchedulingEnableErrorEvents = 0x19BBC7A16D0; // Unknown = 
    inline constexpr uintptr_t FFlagDebugRomarkAudioPermissionsBypass = 0x19BB6BB1ED0; // Unknown = 
    inline constexpr uintptr_t FFlagDebugScreenSizeUseDisplayStore = 0x19B9026A650; // Unknown = 
    inline constexpr uintptr_t FFlagDebugSelfViewPerfBenchmark = 0x19BACFED9D0; // Unknown = 
    inline constexpr uintptr_t FFlagDebugShowAccountSecurityPromptBanner = 0x19B9029CF90; // Unknown = 
    inline constexpr uintptr_t FFlagDebugShowAudioDeviceInputDebuggerV2 = 0x19BACFD1CD0; // Unknown = 
    inline constexpr uintptr_t FFlagDebugShowSiteMessageBanner = 0x19B9029E390; // Unknown = 
    inline constexpr uintptr_t FFlagDebugSimulateConnectDisconnect = 0x19BA5158E10; // Unknown = 
    inline constexpr uintptr_t FFlagDebugSkipSeamlessVoiceAPICheck = 0x19B9F186B9D; // Bool = true
    inline constexpr uintptr_t FFlagDebugSkipVoicePermissionCheck = 0x19B9F18AB4D; // Bool = true
    inline constexpr uintptr_t FFlagDebugSquadLogsEnabled = 0x19B8C2E3150; // Unknown = 
    inline constexpr uintptr_t FFlagDebugTCUpsellModalEnabled_DEV = 0x19B8C2E2150; // Unknown = 
    inline constexpr uintptr_t FFlagDebugTimeToInteractiveTracker = 0x19BA3663F08; // Unknown = 
    inline constexpr uintptr_t FFlagDebugUnfilteredThreads = 0x19BACFD0110; // Unknown = 
    inline constexpr uintptr_t FFlagDebugUnmuteLuaErrors = 0x19B857878DD; // Bool = false
    inline constexpr uintptr_t FFlagDebugUseLegacyCrossPlayApi = 0x19BB6BB4710; // Unknown = 
    inline constexpr uintptr_t FFlagDebugVRModeInStudio = 0x19B8C2E9A90; // Unknown = 
    inline constexpr uintptr_t FFlagDebugVoiceChatMicPermissionCliBypass = 0x19B8FDEBB50; // Unknown = 
    inline constexpr uintptr_t FFlagDefaultChannelEnableDefaultVoice = 0x19B9F0ABFD0; // Unknown = 
    inline constexpr uintptr_t FFlagDefaultKidsToDarkTheme = 0x19B9AF17690; // Unknown = 
    inline constexpr uintptr_t FFlagDefaultKidsToDarkTheme2 = 0x19B9AF17710; // Unknown = 
    inline constexpr uintptr_t FFlagDeferPlayerInfoRequests = 0x19BAD28561D; // Bool = false
    inline constexpr uintptr_t FFlagDeferProgrammaticChange = 0x19B9FD8BE1D; // Bool = false
    inline constexpr uintptr_t FFlagDeprecateNavigateToUserInfoJoinable = 0x19B90294650; // Unknown = 
    inline constexpr uintptr_t FFlagDeprecatePeopleListContextualMenu = 0x19B9F18FEBD; // Bool = true
    inline constexpr uintptr_t FFlagDesktopGameJoinCardUIImprovements = 0x19B8C30331D; // Bool = true
    inline constexpr uintptr_t FFlagDetailsPageLayoutSeedContainerSize = 0x19B88C21910; // Unknown = 
    inline constexpr uintptr_t FFlagDevClosedStartupSequence = 0x19B8578289D; // Bool = false
    inline constexpr uintptr_t FFlagDevConsoleAdminSeesDevTabs = 0x19BACFE6290; // Unknown = 
    inline constexpr uintptr_t FFlagDevConsoleDownArrowIconFix = 0x19B9FB6F210; // Unknown = 
    inline constexpr uintptr_t FFlagDevConsoleDropdownFlipFix = 0x19BACFE0CDD; // Bool = false
    inline constexpr uintptr_t FFlagDevConsoleDropdownMultiSelect = 0x19BACFE0DDD; // Bool = false
    inline constexpr uintptr_t FFlagDevConsoleFixTimestampDST = 0x19BACE9F3DD; // Bool = false
    inline constexpr uintptr_t FFlagDevConsoleMemoryTrackingAlert = 0x19BACFE1B1D; // Bool = false
    inline constexpr uintptr_t FFlagDevConsoleMicroProfilerFixAutoTextClear = 0x19BACFE329D; // Bool = false
    inline constexpr uintptr_t FFlagDevConsoleMicroProfilerImproveWording = 0x19BACFE2E10; // Unknown = 
    inline constexpr uintptr_t FFlagDevConsoleMicroProfilerNewLayout = 0x19BACFE3F5D; // Bool = false
    inline constexpr uintptr_t FFlagDevConsoleMpEnableOpenDumpsFolderButton = 0x19BACFE399D; // Bool = false
    inline constexpr uintptr_t FFlagDevConsoleRequestOrchestratorTab2 = 0x19BACFE7050; // Unknown = 
    inline constexpr uintptr_t FFlagDevConsoleStartDataOnMount = 0x19BACFE015D; // Bool = false
    inline constexpr uintptr_t FFlagDevFrameworkMoveEditTree = 0x19B82A7F25D; // Bool = true
    inline constexpr uintptr_t FFlagDifferentiateAddAuthMethodPasskeyFlow = 0x19B90291DD0; // Unknown = 
    inline constexpr uintptr_t FFlagDifferentiateSharingBaseOnPlatform = 0x19B9FD84E5D; // Bool = false
    inline constexpr uintptr_t FFlagDifferentiateVoiceSelectorSystemAndUser = 0x19B9FD8BD1D; // Bool = false
    inline constexpr uintptr_t FFlagDisableAppShortcutBarAndroidTV = 0x19BA607C1D0; // Unknown = 
    inline constexpr uintptr_t FFlagDisableAutocorrectSocialUserSearch = 0x19BAEE1F750; // Unknown = 
    inline constexpr uintptr_t FFlagDisableAutocorrectSocialUserSearch_v2 = 0x19B8C2EA310; // Unknown = 
    inline constexpr uintptr_t FFlagDisableBlockAndReport = 0x19B8C2E19D0; // Unknown = 
    inline constexpr uintptr_t FFlagDisableCDLQrCodeForMaquettes = 0x19BA5208975; // Bool = false
    inline constexpr uintptr_t FFlagDisableCameraOnLowSpecDevices2 = 0x19B9FD8A05D; // Bool = false
    inline constexpr uintptr_t FFlagDisableCameraOnLowspecAndroidCalls = 0x19B9F0AC550; // Unknown = 
    inline constexpr uintptr_t FFlagDisableCameraOnSelfieViewForLowspecDevices = 0x19BACFECF10; // Unknown = 
    inline constexpr uintptr_t FFlagDisableConsentModalForExistingUsers = 0x19B9F18DDDD; // Bool = true
    inline constexpr uintptr_t FFlagDisableCopyUsernameOnConsole = 0x19B8C2E0190; // Unknown = 
    inline constexpr uintptr_t FFlagDisableCorescriptBacktraceReporting = 0x19BA553A350; // Unknown = 
    inline constexpr uintptr_t FFlagDisableEditProfileForVRV2 = 0x19BC0549190; // Unknown = 
    inline constexpr uintptr_t FFlagDisableFeedbackSoothsayerCheck = 0x19B9FD8D3DD; // Bool = false
    inline constexpr uintptr_t FFlagDisableGoogleAnalyticsErrorReporting = 0x19B8578875D; // Bool = false
    inline constexpr uintptr_t FFlagDisableHomePageUpsellCardFeedItem = 0x19BC0541790; // Unknown = 
    inline constexpr uintptr_t FFlagDisableLeaveToastInStudio = 0x19BA437003D; // Bool = false
    inline constexpr uintptr_t FFlagDisableLegacyChatSimpleUnreadMessageCount = 0x19B9ACB0C1D; // Bool = true
    inline constexpr uintptr_t FFlagDisableListenToSessionTerminalStatus = 0x19B90291A50; // Unknown = 
    inline constexpr uintptr_t FFlagDisableLuobuWarningToast = 0x19B9AF11710; // Unknown = 
    inline constexpr uintptr_t FFlagDisableMemStorageServicePasswordEvent = 0x19B9ACB1990; // Unknown = 
    inline constexpr uintptr_t FFlagDisableMessageBusUnSubscribeError = 0x19B9F18DF4D; // Bool = true
    inline constexpr uintptr_t FFlagDisableNonSchematizedInGameRobuxUpsellEvent = 0x19BAC83679D; // Bool = false
    inline constexpr uintptr_t FFlagDisablePVUpsellDataConsent = 0x19B8C30595D; // Bool = true
    inline constexpr uintptr_t FFlagDisablePermissionPromptDeeplink = 0x19BA515909D; // Bool = false
    inline constexpr uintptr_t FFlagDisablePlayerListDisplayCloseBtn = 0x19BAD2840D0; // Unknown = 
    inline constexpr uintptr_t FFlagDisablePurchasePromptFunctionForMaquettes = 0x19B9EE0155D; // Bool = false
    inline constexpr uintptr_t FFlagDisableReactSchedulingAvgMaxMsStats = 0x19BA366FFD0; // Unknown = 
    inline constexpr uintptr_t FFlagDisableReactSchedulingTimePctStats = 0x19BA366FA90; // Unknown = 
    inline constexpr uintptr_t FFlagDisableRejoinGroupIdDoubleRead = 0x19B8FDEBB9D; // Bool = false
    inline constexpr uintptr_t FFlagDisableRobuxUpsell = 0x19D85DCBBD0; // Unknown = 
    inline constexpr uintptr_t FFlagDisableVerifyPhoneViewOnSuccess = 0x19BBC38A49D; // Bool = false
    inline constexpr uintptr_t FFlagDisableWebViewSupportInStudio = 0x19BB6BB4510; // Unknown = 
    inline constexpr uintptr_t FFlagDisallowStickyShortcutBarOnNotLoggedIn = 0x19BA607F750; // Unknown = 
    inline constexpr uintptr_t FFlagDisconnectToastClientRewrite = 0x19B8C30561D; // Bool = true
    inline constexpr uintptr_t FFlagDiscountInfoForSubscriptionPurchaseModalLua2 = 0x19B9ACBC050; // Unknown = 
    inline constexpr uintptr_t FFlagDispatchHybridWebviewWithBypassNavigationLock = 0x19B90291750; // Unknown = 
    inline constexpr uintptr_t FFlagDisplayChannelNameOnErrorPrompt = 0x19BA672B21D; // Bool = false
    inline constexpr uintptr_t FFlagDisplayCollectiblesIcon = 0x19B9F0A399D; // Bool = false
    inline constexpr uintptr_t FFlagDisplayServerChannel = 0x19B88C4E8DD; // Bool = false
    inline constexpr uintptr_t FFlagDontAssertOnUserIDInCaptureMetadata = 0x19BAC87D69D; // Bool = false
    inline constexpr uintptr_t FFlagDontUseCrossPlayGlobalEffect = 0x19BA6A33490; // Unknown = 
    inline constexpr uintptr_t FFlagDrawerScrimCanBeModal = 0x19B9AF1691D; // Bool = false
    inline constexpr uintptr_t FFlagDropUnroutableMultiReportOptions = 0x19B8C30C6D0; // Unknown = 
    inline constexpr uintptr_t FFlagDynamicHeadsMigration = 0x19BA3A56190; // Unknown = 
    inline constexpr uintptr_t FFlagDynamicHeadsMigration7 = 0x19BA3A5D850; // Unknown = 
    inline constexpr uintptr_t FFlagEDPTTITrackingEnabled = 0x19B90261110; // Unknown = 
    inline constexpr uintptr_t FFlagEarlierFetchTimeForFriendsCarousel_v1 = 0x19BAFCF8250; // Unknown = 
    inline constexpr uintptr_t FFlagEasierUnmuting = 0x19BBCD78F90; // Unknown = 
    inline constexpr uintptr_t FFlagEasierUnmutingTCS5 = 0x19BBCD79E50; // Unknown = 
    inline constexpr uintptr_t FFlagEasierUnmutingVoiceParticipantsMutedReducer = 0x19BA74A085D; // Bool = false
    inline constexpr uintptr_t FFlagEditProfileBackgroundEnabled = 0x19BACFD0E90; // Unknown = 
    inline constexpr uintptr_t FFlagEditProfileFramesEnabled = 0x19BA6A310D5; // Bool = false
    inline constexpr uintptr_t FFlagEditProfileImageV2Enabled = 0x19BACFD5290; // Unknown = 
    inline constexpr uintptr_t FFlagEditProfileImageV2Telemetry = 0x19BACFD6F10; // Unknown = 
    inline constexpr uintptr_t FFlagEditProfileLandingV2Enabled = 0x19B90643DDD; // Bool = false
    inline constexpr uintptr_t FFlagEditProfileNavigateToAvatar = 0x19B9064331D; // Bool = false
    inline constexpr uintptr_t FFlagEditProfilePPEStartOnEmotesPage = 0x19B90643C9D; // Bool = false
    inline constexpr uintptr_t FFlagEditProfileSetupNewExperimentFlow = 0x19B90642910; // Unknown = 
    inline constexpr uintptr_t FFlagEdpGameLeavePromptsHandlerEnabled = 0x19BC0547D10; // Unknown = 
    inline constexpr uintptr_t FFlagEdpPlayerFeedbackCommentsOnly = 0x19B9ACB7550; // Unknown = 
    inline constexpr uintptr_t FFlagEdpPlayerFeedbackEnabled5 = 0x19B9ACB1350; // Unknown = 
    inline constexpr uintptr_t FFlagEdpPlayerFeedbackLogIXPExposure2 = 0x19B9ACB4490; // Unknown = 
    inline constexpr uintptr_t FFlagEdpPlayerFeedbackPromptTitleOnly = 0x19B9ACB0DD0; // Unknown = 
    inline constexpr uintptr_t FFlagEmit401WebViewDiagnostics = 0x19B9029301D; // Bool = false
    inline constexpr uintptr_t FFlagEmitPasskeyRegistrationSourceOnFinish = 0x19B9ACB6A90; // Unknown = 
    inline constexpr uintptr_t FFlagEmoteUtilityDefaultMoodFromCharacter = 0x19D89526290; // Unknown = 
    inline constexpr uintptr_t FFlagEmoteUtilityReportPoseAnimationDownloadFailure = 0x19D8952ED10; // Unknown = 
    inline constexpr uintptr_t FFlagEmoteUtilityUseIdleAnimationFallback = 0x19D8952F650; // Unknown = 
    inline constexpr uintptr_t FFlagEmotesStayOpenWithChat = 0x19BA607DE90; // Unknown = 
    inline constexpr uintptr_t FFlagEnable2SVRecovery7 = 0x19B9ACB3550; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAEGIS2AppChatConversationBanner = 0x19BAEE18F50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAEGIS2AppChatConversationBannerv699 = 0x19B8C2E4350; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAEGIS2Upsellv700 = 0x19B8C2E4550; // Unknown = 
    inline constexpr uintptr_t FFlagEnableARFlowSession = 0x19D81686290; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAbuseReport10ft2 = 0x19BA6A3F29D; // Bool = true
    inline constexpr uintptr_t FFlagEnableAbuseReportMutedError = 0x19BA6A3AC10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAbuseReportRevampFeedback = 0x19B90262E1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAbuseReportRevampFlow = 0x19B8DD89D90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAbuseReportRevampFlow_1 = 0x19B8C30B99D; // Bool = true
    inline constexpr uintptr_t FFlagEnableAccessBlockAtAppContainerLevel = 0x19BC0545690; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAccountCarouselEvents1 = 0x19B9ACB6790; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAccountCountdownLabel = 0x19B9F1843CD; // Bool = true
    inline constexpr uintptr_t FFlagEnableAccountRecoveryPreAuthDeepLink2 = 0x19B8FC39FDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableAccountSettingsUpsell = 0x19B906443DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableAccountSwitcherAddWithMaxSignedOut = 0x19B88C4C9D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAccountSwitcherFoundationDesign9 = 0x19B88C4CA5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAccountSwitcherIXPTextGatingFix = 0x19B88C4C610; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAccountSwitcherManageAccounts6 = 0x19B88C4D25D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAccountSwitcherSignedOutAccounts5 = 0x19B88C4CE50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAccountSwitcherUncheckedBadge = 0x19B88C4D49D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAccountUnlockDeepLink = 0x19B8C30E99D; // Bool = true
    inline constexpr uintptr_t FFlagEnableAdConsentAttribution = 0x19B8F90F29D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAdDataPlayIntentEventIngest = 0x19B82C6C89D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAdDataReferralEventIngest = 0x19B82A7779D; // Bool = true
    inline constexpr uintptr_t FFlagEnableAddAuthMethodPageEmailSignup = 0x19B945A6D50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAddAuthMethodPageEmailSignup5 = 0x19B945A0510; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAddAuthMethodPageFoundationalizeHeader = 0x19B945A8F90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAddAuthMethodPageFoundationalizeHeader2 = 0x19B945A7490; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAddAuthMethodPageFoundationalizeParagraph = 0x19B945A4950; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAddAuthMethodPageFoundationalizeParagraph2 = 0x19B945A5FD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAddAuthMethodPagePasskeyNudgeDirectionalExperiment = 0x19B945A5010; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAddAuthMethodPagePasskeyNudgeDirectionalExperiment10 = 0x19B945A4590; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAffiliateLinksQualifiedSignUpTracking = 0x19B9ACBBD50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAmpEmailUpsellSupport = 0x19B901123DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableAmpIDVUpsellAnalytics = 0x19B90113C1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAmpIDVUpsellPopOnCompletion = 0x19B9011261D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAmpIDVUpsellSupport = 0x19B901124DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableAmpSubscriptionUpsell = 0x19B901127DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableAmpUpsellGQL = 0x19B9011231D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAmpUpsellLogging = 0x19B90112BDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableAmpUpsellWizard = 0x19B906444DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableAmpUserMismatchTelemetry = 0x19B9F18C67D; // Bool = true
    inline constexpr uintptr_t FFlagEnableAmpV2Wizard = 0x19B8C2EB75D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAmpVPCPrologue = 0x19B901128DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableAmpWizardDeepLink = 0x19B8C2E4290; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAmpWizardDeepLinkValidateUserId = 0x19B8C2E43D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAmpWizardInlineVPCForFAE = 0x19B9011299D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAmpWizardVPCNavigationFix = 0x19B90112ADD; // Bool = false
    inline constexpr uintptr_t FFlagEnableAnalyticsForCameraDevicePermissions = 0x19BA4E92AD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAndroidAppRatingPromptLua = 0x19BA59B0F55; // Bool = false
    inline constexpr uintptr_t FFlagEnableAndroidTvAppPolicies = 0x19BBCD71A50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAndroidWidgetsLuaIXP2 = 0x19B88C4BADD; // Bool = false
    inline constexpr uintptr_t FFlagEnableAppAgeSignalsErrorTelemetry = 0x19B948141D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAppAgeSignalsService = 0x19B94814690; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAppChatSnoozeMenuFocus = 0x19B9F18426D; // Bool = true
    inline constexpr uintptr_t FFlagEnableAppRatingPromptLua = 0x19BA59B15D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAppRatingPromptLua4 = 0x19BA59BCD10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAppStorageJsonCacheInABTest = 0x19B9ACBF8D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAppStorageJsonDecodeCache = 0x19BA3BB6590; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAppStoreAgeSignalsOnHomePage = 0x19B8C2E4E9D; // Bool = false
    inline constexpr uintptr_t FFlagEnableArgoPartyChanges = 0x19B8FDECFDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableArgoPartyExperimentation7 = 0x19BAC87E595; // Bool = true
    inline constexpr uintptr_t FFlagEnableArgus = 0x19B9ACB99D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableArgus2 = 0x19B9ACBDB90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableArgusFlyoutEntry = 0x19B9ACB8050; // Unknown = 
    inline constexpr uintptr_t FFlagEnableArgusImmersiveNav = 0x19B9ACB02D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableArgusTab = 0x19B9ACBEC90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAttributionContextEventReceiver = 0x19B90290E50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAuditForSinglePageSignUp4 = 0x19B9ACBDE10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAuditForSso = 0x19B9ACBA490; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAuditSystem2 = 0x19BBC1C35D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAuthAnalyticsPrintDebuggingDev = 0x19B945A0B10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAuthStatefulTextInputUpdatesRelease1 = 0x19B88C4AF1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAuthsecImageUpdate = 0x19B88C4DC5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAutoLoginAfterRecovery = 0x19B88C4C11D; // Bool = false
    inline constexpr uintptr_t FFlagEnableAutomaticSizeVerticalOffsetWidthFix = 0x19B9FDD4CD5; // Bool = false
    inline constexpr uintptr_t FFlagEnableAvatarEditorServiceAPIErrorLogging = 0x19B906430D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAvatarExperienceSdui = 0x19B9ACB0D90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAvatarHeadshotLocalIconBackgroundFix = 0x19B859CA310; // Unknown = 
    inline constexpr uintptr_t FFlagEnableAvatarViewportAutoRotation = 0x19B9F0A641D; // Bool = false
    inline constexpr uintptr_t FFlagEnableBadgeCheckForUserCreator = 0x19BAD28549D; // Bool = false
    inline constexpr uintptr_t FFlagEnableBirthdayOverlayAnalytics = 0x19B9ACBCD50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBlackbird = 0x19BA6A3F750; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBlackbirdCheck = 0x19BA6A32DD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBlackbirdOnFlyoutMenu = 0x19BA6A341D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBlackbirdOnFlyoutMenu2 = 0x19BA6A37B50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBlackbirdOnMorePage = 0x19BA6A34510; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBlackbirdOnMorePage2 = 0x19BA6A3A790; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBlackbirdPageCloseCallback = 0x19BA6A3BC50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBlackbirdPageCloseCallback2 = 0x19BA6A3D010; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBlackbirdUpsellImpressionGating = 0x19B9AF1FE50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBlackbirdUpsellInUnifiedPurchaseModal = 0x19B9AF1FAD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBlackbirdUpsellInUnifiedPurchaseModal7 = 0x19B9AF1FF10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBlackbirdV2 = 0x19BA6A34B10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBottomNavOnMarketplace_v3 = 0x19B9AF14490; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBuildExperienceScrollPerformanceTracking = 0x19BAD58045D; // Bool = false
    inline constexpr uintptr_t FFlagEnableBuildOverflowMenuForNewGames = 0x19BAD58459D; // Bool = false
    inline constexpr uintptr_t FFlagEnableBuildTabOverride = 0x19B9AF133D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableBypassNavigationLockHybridWebview = 0x19B90292590; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCEVForceInitialize = 0x19B859C92DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableCachingforReminderOfNorms = 0x19BC0544C50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCallingLogoutOnResetIXP = 0x19B945A5050; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCancelSubscriptionAppLua = 0x19B9AF11E90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCapturesGalleryRetrievalCoreScript = 0x19BBF25A790; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCapturesGalleryRetrievalCoreScript_v3 = 0x19BAC87B69D; // Bool = false
    inline constexpr uintptr_t FFlagEnableCatalogTileLoadingLatencyV2 = 0x19B9026ECD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCentralFoundationOverlayProvider = 0x19B9064951D; // Bool = false
    inline constexpr uintptr_t FFlagEnableCentralOverlayForUpsellPrompt = 0x19BAC83611D; // Bool = false
    inline constexpr uintptr_t FFlagEnableChatIconUnibarDropdownFixEnabled = 0x19BACFDED90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableChatLineReporting2 = 0x19B8C30AC9D; // Bool = true
    inline constexpr uintptr_t FFlagEnableChatMicPerfBinding = 0x19BBCD7A290; // Unknown = 
    inline constexpr uintptr_t FFlagEnableChatNewMessage = 0x19B8C303F5D; // Bool = true
    inline constexpr uintptr_t FFlagEnableChatReportingTextChannelTag = 0x19B8C30E0D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableChromeWindowsNotInMenu = 0x19BA7FC8878; // Unknown = 
    inline constexpr uintptr_t FFlagEnableClientToastNotificationsRedirectExperiment = 0x19BACFEB11D; // Bool = false
    inline constexpr uintptr_t FFlagEnableClientToastNotificationsReducedMotion = 0x19BA672B39D; // Bool = false
    inline constexpr uintptr_t FFlagEnableCommonFriendsMenu3 = 0x19B8C2EA6D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCompensatingScrollingFrame = 0x19BAC834A5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableCondenseRobuxUpsell = 0x19BAC83275D; // Bool = false
    inline constexpr uintptr_t FFlagEnableConfirmSignOutV2 = 0x19B945A40D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableConfirmSignifierOnSignUpPage = 0x19B9ACBB010; // Unknown = 
    inline constexpr uintptr_t FFlagEnableConnectDisconnect = 0x19B8FDEAF5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableConnectDisconnectInSettingsAndChrome = 0x19BA515971D; // Bool = false
    inline constexpr uintptr_t FFlagEnableConsoleAutoFocusForUEN1 = 0x19B8FA1F55D; // Bool = false
    inline constexpr uintptr_t FFlagEnableConsoleDisconnectNetworkingErrorToast = 0x19B8FC39CDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableConsoleExpControls = 0x19B9ACB53D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableConsoleExpControls684 = 0x19B9ACB80D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableConsoleExpControlsIXP = 0x19B9ACB32D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableConsoleExpControlsIXP684 = 0x19B9ACB88D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableConsoleGameJoinCard_v4 = 0x19B8C302490; // Unknown = 
    inline constexpr uintptr_t FFlagEnableConsolePreparePaymentCheck = 0x19BAC8341DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableConsoleRobloxLogo = 0x19B9ACBF6D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableContactInvitesForNonPhoneVerifiedForAll = 0x19B8C2E9BDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableContextFeaturesForOmniRecommendations = 0x19BC0548390; // Unknown = 
    inline constexpr uintptr_t FFlagEnableContinueRecovery3 = 0x19B88C4BFD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableConvertPriceChangedToUnknownFailure = 0x19D85DC95D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCoreContentAccountType = 0x19B9AF16AD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCoreContentBadge = 0x19B9AF16850; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCoreContentBadge2 = 0x19B9AF16710; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCoreContentThemeUseGuacForTokenOverrides = 0x19B9AF163D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCoreContentThemeUseGuacForTokenOverrides2 = 0x19B9AF16590; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCoreContentThemeVRScene = 0x19B9AF17350; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCoreUISystemV2 = 0x19B9AF11F10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCorescriptExecutionTime = 0x19BBC7A1610; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCorescriptMemoryTracker = 0x19B9F18B905; // Bool = true
    inline constexpr uintptr_t FFlagEnableCorescriptTrackerForLuaApp = 0x19B90296B50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCorescriptsProfiler = 0x19B9AF11F50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCreatorStorePurchasingCutover = 0x19D85DC3A90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCreatorSubtitleNavigation_v2 = 0x19B8EDC671D; // Bool = true
    inline constexpr uintptr_t FFlagEnableCrossDeviceLoginUsingQRCodes3 = 0x19B88C4B250; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCrossExpEventLogging = 0x19B8ED7FB50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCrossExpVoiceAbuseReport = 0x19B88C4B91D; // Bool = false
    inline constexpr uintptr_t FFlagEnableCrossExpVoiceMemoryCheck = 0x19B88C4B7DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableCurrencyTransferDeepLink = 0x19B8C2EB650; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCurrencyTransferFlowV3 = 0x19B8C2EB2D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableCurrencyTransferWizardVPCPrologue = 0x19B9F92F3D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDarkerShimmerTransparency = 0x19BBCD79E10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDeactivatedUserReactivation = 0x19B88C4BA90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDeepLinkHistoryWithModalAPI2 = 0x19B8C2E2F90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDeeplinkResolutionEventReceiver = 0x19B90290B90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDeferVoiceConnection = 0x19B8FDEA850; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDemoModeRegionalAvailability = 0x19B88C2FF5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableDesktopGameJoinCard_v5 = 0x19D812E9648; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDevProductPendingProductsLimitExceededInUnifiedPurchase = 0x19B863E0F55; // Bool = true
    inline constexpr uintptr_t FFlagEnableDevSubsFastFollowFixes = 0x19B9ACBB950; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDeviceGateForInExpChatRewrite = 0x19B9CB7DFDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableDialogAfterSquadJoin1 = 0x19B8C2E24D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDirectLinkForTablets = 0x19B9011391D; // Bool = false
    inline constexpr uintptr_t FFlagEnableDisableSubPurchase = 0x19BAC8361D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDisconnectPartyVoiceIfNeeded = 0x19BA8021050; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDiscountInfoInUnifiedPurchaseModal = 0x19B9ACB2B90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDiscountInfoInUnifiedPurchaseModal6 = 0x19B9ACB4650; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDisplayLoggingForToastsFix = 0x19BA6726E1D; // Bool = true
    inline constexpr uintptr_t FFlagEnableDrawerAnimatingHook = 0x19B9ACBD950; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDrawerFocusNav = 0x19B9ACB0390; // Unknown = 
    inline constexpr uintptr_t FFlagEnableDummyAMPWizard = 0x19B9011401D; // Bool = false
    inline constexpr uintptr_t FFlagEnableDynamicReportV2ForUserProfileReports3 = 0x19B8EE08FB0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableEDPTTIManagerColdWarmDetection = 0x19B90261910; // Unknown = 
    inline constexpr uintptr_t FFlagEnableExitModalExposure = 0x19BACE9E01D; // Bool = false
    inline constexpr uintptr_t FFlagEnableExpChatLocalChatEnabledMessageExperimentation2 = 0x19B8FDEC45D; // Bool = false
    inline constexpr uintptr_t FFlagEnableExpChatNewSystemMessagesExperimentation = 0x19B8FDEC4D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableExpChatUniverseChatTabNames2 = 0x19B8FA14F5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableExpJoinMicPermAnalytics = 0x19BBCA071B5; // Bool = false
    inline constexpr uintptr_t FFlagEnableExperienceDetailsBottomSheet2 = 0x19BA5537965; // Bool = false
    inline constexpr uintptr_t FFlagEnableExperienceDetailsBottomSheetTopBar = 0x19BA520C47D; // Bool = true
    inline constexpr uintptr_t FFlagEnableExperienceGenericChallengeRenderingConnection2 = 0x19BA672CF90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableExperienceGenericChallengeRenderingOnLoadingScript = 0x19B9AF11DD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableExperienceNotificationPrompts2 = 0x19B9AF11B50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableExplicitSettingsChangeAnalytics = 0x19B9FD8D09D; // Bool = false
    inline constexpr uintptr_t FFlagEnableExternalBrowserForVPCPrivacyPolicy = 0x19B9011211D; // Bool = false
    inline constexpr uintptr_t FFlagEnableFAECancellationAnalytics = 0x19B90112FDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableFAEQRCodeHandoff = 0x19B90112090; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFaceIDTextOnAddAuthMethodPage = 0x19B945A1050; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFastScrollingFixTest = 0x19BA6092210; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFeatureRestrictionOnAgeVerificationAttempt = 0x19B8FC39F10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFetchCartPricingDuringInExperience = 0x19B9ACB8890; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFixRobuxUpsellPriceCrash = 0x19BAC83299D; // Bool = false
    inline constexpr uintptr_t FFlagEnableFlyoutExposure = 0x19BA4616ED0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFlyoutFriendsHeaderFix = 0x19B9AF15C90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFlyoutIxp11 = 0x19BA3BB4E90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFlyoutMenuRobuxCardRefactor = 0x19BA6A37B90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFlyoutOnNavRail = 0x19B85788DDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableFlyoutSidePanel15 = 0x19B859CAAD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFlyoutUncheckedBadge = 0x19B9AF174D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFlyoutUncheckedBadge2 = 0x19B9AF17550; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFlyoutWithScrollAway2 = 0x19BA6094B10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFontStylisticAlternativesOnSocialScreens = 0x19BACFDE510; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFoundationUIVPCUpsellForInExperience = 0x19B90111510; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFriendCarouselInGameFriendExposureLogging_v2 = 0x19B8FA1E39D; // Bool = false
    inline constexpr uintptr_t FFlagEnableFriendsLandingChallengeInterceptor = 0x19BAFCF8AD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFriendsListSearchNormalizationErrorFix = 0x19B8C304CDD; // Bool = true
    inline constexpr uintptr_t FFlagEnableFriendsMenuShareGameInviteLink3 = 0x19BADF95010; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFriendsRenamingForAll = 0x19B8C2E2610; // Unknown = 
    inline constexpr uintptr_t FFlagEnableFtuxExitOnMuteToggle = 0x19B8FDEAD1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableGameInviteModalVRSupportV2 = 0x19B8C3048DD; // Bool = true
    inline constexpr uintptr_t FFlagEnableGameInviteRewardsBanner3 = 0x19B8C30545D; // Bool = true
    inline constexpr uintptr_t FFlagEnableGameLeftMessage = 0x19BB2B2B1F0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableGamepadHookForCorescriptGlobalEffects = 0x19B85A50B98; // Unknown = 
    inline constexpr uintptr_t FFlagEnableGateNotificationPreferencesTab = 0x19B8C30469D; // Bool = true
    inline constexpr uintptr_t FFlagEnableGenericIllegalContentReporting3 = 0x19BA3A57A5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableGenericTwoFAMessage = 0x19B88C4DB5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableGetCredentialsInCredentialsProtocolHook = 0x19BA5156150; // Unknown = 
    inline constexpr uintptr_t FFlagEnableGetFriendshipStatus = 0x19B88C248DD; // Bool = true
    inline constexpr uintptr_t FFlagEnableGlobalChat3pSummaryLuaApps = 0x19BA74A559D; // Bool = false
    inline constexpr uintptr_t FFlagEnableGlobalChatAbuseReporting = 0x19B8C30C5DD; // Bool = true
    inline constexpr uintptr_t FFlagEnableHandleEngineSessionCheckAtStartup = 0x19B90291A90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableHeadShapeForCharacterManager = 0x19BA3A564D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableHeadShapeForCharacterManager6 = 0x19BA3A53090; // Unknown = 
    inline constexpr uintptr_t FFlagEnableHeaderBarButtonsUpdate = 0x19BBCD7155D; // Bool = false
    inline constexpr uintptr_t FFlagEnableHeaderBarButtonsUpdate2 = 0x19BBCD75C10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableHeadlessSubscriptionNativePurchaseCancelCallback = 0x19B8FC33FDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableHearingWithoutMicPermissions = 0x19B8FDEAA50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableHideJoinToastSubtitle = 0x19B8FDE9F90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableHideReportAdModalDuringScreenshot2 = 0x19BA8A0F79D; // Bool = false
    inline constexpr uintptr_t FFlagEnableHomeBetaBadge = 0x19BA76D2E60; // Unknown = 
    inline constexpr uintptr_t FFlagEnableHomeGameItemOwnershipUpdate = 0x19BC05446D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableHomePageEmailUpsellCard = 0x19B90294C90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableHomePageUpsellCardRelease7 = 0x19B90266810; // Unknown = 
    inline constexpr uintptr_t FFlagEnableHomeRobloxLogo = 0x19B9ACBCA10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableHomepagePromptsForModalsAndBanners = 0x19BC05437D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableHotbarHide = 0x19BA6078DD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableIAFlyoutIXPHomeProfileRemoval = 0x19B94811C50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableIOSUIRefactorLuaIXP2 = 0x19B88C4BBDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableIXPOverrideAccountPicker1 = 0x19B9ACB48D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByCode = 0x19B8FC38F1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByEmail = 0x19B8FC38F9D; // Bool = false
    inline constexpr uintptr_t FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByOtp = 0x19B8FC3901D; // Bool = false
    inline constexpr uintptr_t FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByPhone = 0x19B8FC38AD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByUsername = 0x19B8FC38390; // Unknown = 
    inline constexpr uintptr_t FFlagEnableIllegalChildAccountLinkingErrorMessageOnSSO = 0x19B8FC38E9D; // Bool = false
    inline constexpr uintptr_t FFlagEnableInAppBugReporting = 0x19BACFD4810; // Unknown = 
    inline constexpr uintptr_t FFlagEnableInExpChatPolishSummaryOnLuaForTranslatedMessageV2 = 0x19BA515FF1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableInExpChatRewrite = 0x19B9CB7C39D; // Bool = false
    inline constexpr uintptr_t FFlagEnableInExpChatSummaryOnLua = 0x19B9CB7235D; // Bool = false
    inline constexpr uintptr_t FFlagEnableInExpChatSummaryOnLua4 = 0x19B9CB7D59D; // Bool = false
    inline constexpr uintptr_t FFlagEnableInExpChatSummaryOnLuaForTranslatedMessageV2 = 0x19BA515D29D; // Bool = false
    inline constexpr uintptr_t FFlagEnableInExpPhoneVoiceUpsellEntrypoints2 = 0x19B88C4E29D; // Bool = false
    inline constexpr uintptr_t FFlagEnableInExperienceAvatarSwitcher9 = 0x19B88C4FF1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableInExperienceHandheldControls = 0x19B9ACB4A90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableInExperienceShop = 0x19B9ACB45D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableInExperienceShop3 = 0x19B9ACB4850; // Unknown = 
    inline constexpr uintptr_t FFlagEnableInExperienceUIPCVRFix_dev = 0x19BA6A37090; // Unknown = 
    inline constexpr uintptr_t FFlagEnableInGameMenuChrome = 0x19BA3BBDBD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableInGameMenuDurationLogger = 0x19BA366B81D; // Bool = false
    inline constexpr uintptr_t FFlagEnableInitialJoinVoiceButton = 0x19B8FDEA290; // Unknown = 
    inline constexpr uintptr_t FFlagEnableInlineSurveyOnUserReport = 0x19B8C30C11D; // Bool = true
    inline constexpr uintptr_t FFlagEnableInspectAndBuyV2RootFlag = 0x19B9ACB65D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableInspectAndBuyV2RootFlag2 = 0x19B9ACB6590; // Unknown = 
    inline constexpr uintptr_t FFlagEnableInvitePromptLoadingState2 = 0x19B9F294910; // Unknown = 
    inline constexpr uintptr_t FFlagEnableInvoluntaryLogoutEvent = 0x19B902900D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableIosAuthServiceLuaIXP = 0x19B88C4C35D; // Bool = false
    inline constexpr uintptr_t FFlagEnableIosKeychainLoginLua4 = 0x19B8EAF6150; // Unknown = 
    inline constexpr uintptr_t FFlagEnableJoinV2PreAuthDeepLink = 0x19B8FC39E1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableJoinVoiceIsMutedMic = 0x19B8FDEA6D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableJoinVoiceTooltip = 0x19B8FDEA490; // Unknown = 
    inline constexpr uintptr_t FFlagEnableJoinVoiceVrTelemetry = 0x19D8168B050; // Unknown = 
    inline constexpr uintptr_t FFlagEnableKeyboardVisibilityCheckOnPasswordFocus = 0x19BBC1C1D90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableKoreaKISACompliance = 0x19B945A2E10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLastLoginMethodTracking = 0x19B945A08D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLaunchAfterPurchase2 = 0x19B9ACB1650; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLaunchAppCheckForAccountSwitchGameParams = 0x19B90291AD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLeaveGameUpsellEntrypoint = 0x19BACE9CC50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLeftNavOnConsole14 = 0x19BA6A38890; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLimitHit2SVUpsell = 0x19B9F92BF90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLinkSharingEvent = 0x19B9AF11E50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLocalesForExperienceLanguageSwitcher4 = 0x19B9FD8DB1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableLockScreenWidgetLuaIXP = 0x19B88C4BC9D; // Bool = false
    inline constexpr uintptr_t FFlagEnableLoginAccountSelectorRelease1 = 0x19B88C4B190; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLoginDisambiguationFoundationSwitcher = 0x19B88C4CE9D; // Bool = false
    inline constexpr uintptr_t FFlagEnableLoginV2Modalization15 = 0x19B9AF19C50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLogoutV3 = 0x19B945A1450; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLookFavoriting = 0x19B82D0DD9D; // Bool = true
    inline constexpr uintptr_t FFlagEnableLuaAccountSwitchRelease2 = 0x19B88C4C65D; // Bool = false
    inline constexpr uintptr_t FFlagEnableLuaAppBootcamp = 0x19B9029401D; // Bool = false
    inline constexpr uintptr_t FFlagEnableLuaAppSessionWithError2 = 0x19B8F90911D; // Bool = false
    inline constexpr uintptr_t FFlagEnableLuaAppsAppsflyerIdCounter = 0x19B90291350; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLuaAppsFollowUserId = 0x19B9AF14250; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLuaCommunityList = 0x19B85788EDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableLuaLogReporterMultipleLogs = 0x19B88C4EDDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableLuafiedRecoveryFlow2 = 0x19B88C4B550; // Unknown = 
    inline constexpr uintptr_t FFlagEnableLuckyRecommendationExperimentation = 0x19B8C2E3D9D; // Bool = false
    inline constexpr uintptr_t FFlagEnableLuobuInGameUpsell = 0x19D85DC5390; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMagicLogin = 0x19B9ACBC450; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMagicLogin_debug = 0x19B9ACB4590; // Unknown = 
    inline constexpr uintptr_t FFlagEnableManageAccountsRedesign8 = 0x19B88C4C990; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMaquettesShortLinkCDLInstructions = 0x19BC05433D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMeTabMarketplaceNav = 0x19BA5539DD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMeTabProfile = 0x19BA553B710; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMemoryShell = 0x19BC2566E10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMemorySnapshotCategories = 0x19B8F741E1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableMenuTrailingBadge = 0x19B9ACB2C10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMergeOmniFeedSorts3 = 0x19BA515539D; // Bool = false
    inline constexpr uintptr_t FFlagEnableMessageBusUnSubscribeErrorTelemetry = 0x19B8C316D10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMicrosoftStorePaymentsPlatform = 0x19B8578A95D; // Bool = false
    inline constexpr uintptr_t FFlagEnableMilkyWayPaymentsPlatformV2 = 0x19B8578AB9D; // Bool = false
    inline constexpr uintptr_t FFlagEnableMobileGameJoinCard_V14 = 0x19B8C3028D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMobilePlayerListOnConsole = 0x19D86AEB668; // Unknown = 
    inline constexpr uintptr_t FFlagEnableModerateChatRemoteEvent = 0x19B8C302C5D; // Bool = true
    inline constexpr uintptr_t FFlagEnableModerateChatUseChatService = 0x19BA553B850; // Unknown = 
    inline constexpr uintptr_t FFlagEnableModularExternalNavigationHandler = 0x19BA8020FD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableModularizedUserAgreementsList = 0x19BA6A37F90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMomentTextGeneration3 = 0x19D86F02D90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMorePageDirectionalLayoutRolloutFix = 0x19B9ACB0D1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableMorePageExitButtonSupport = 0x19B9ACBB19D; // Bool = true
    inline constexpr uintptr_t FFlagEnableMorePageExitButtonSupport2 = 0x19B9ACBD290; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMotionJitterMetric2 = 0x19BC054CFD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMoveSnapInVirtualCursor = 0x19BA59B9E50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMultiPageSignup5 = 0x19B945A83D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMultiPageSignupExperimentRelease2 = 0x19B902918D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMultiPageSignupV2Updates = 0x19B945A5710; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMultipageSignupNonInteractiveUserAgreementsPage = 0x19B945A63D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableMutexOnGenericChallengeInterceptorMount = 0x19B82BC561D; // Bool = false
    inline constexpr uintptr_t FFlagEnableNapIxpLayerExposure = 0x19B8C30BAD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNativePersonaInquiryForAmpIDVUpsell = 0x19B90113A5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableNativeToWebviewMiddleware = 0x19BA5158590; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNativeWrapperAppPage = 0x19B90642F1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableNavBarLabels3 = 0x19B8578939D; // Bool = false
    inline constexpr uintptr_t FFlagEnableNavigateToLoginAfterLogoutAll = 0x19B88C4C81D; // Bool = false
    inline constexpr uintptr_t FFlagEnableNavigationPerformanceIntervals2 = 0x19BA6A3E790; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNewAddFriendsTileForAll = 0x19BACFD97D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNewAvatarViewportProps = 0x19B9F0A5355; // Bool = false
    inline constexpr uintptr_t FFlagEnableNewBackpack = 0x19B9AF19FD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNewBackpackV5 = 0x19B9AF19890; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNewCustomizeBundleEquip3 = 0x19B9026E510; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNewDeviceIntegrityFailureHandling = 0x19BA607F6D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNewInviteMenuCustomization2 = 0x19B9F294E9D; // Bool = false
    inline constexpr uintptr_t FFlagEnableNewInviteMenuCustomizationIXP2 = 0x19B9F294F90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNewInviteMenuIXP2 = 0x19BA5538090; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNewInviteMenuStyle = 0x19B9F2955DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableNewInviteSendEndpoint = 0x19B9F29675D; // Bool = false
    inline constexpr uintptr_t FFlagEnableNewInviteSendEndpointIXP = 0x19B9F29681D; // Bool = false
    inline constexpr uintptr_t FFlagEnableNonFlyoutUncheckedBadge = 0x19B9AF17890; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNonFlyoutUncheckedBadge2 = 0x19B9AF17950; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNotApprovedCheckBoxTextABTest = 0x19BC054B550; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNotApprovedForeshadowingConsequenceABTest = 0x19BC0541F90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNotificationsDeeplink = 0x19B9AF1B810; // Unknown = 
    inline constexpr uintptr_t FFlagEnableNotificationsToastTTLFix = 0x19BA6727F5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableOffersOnInExperienceSurface = 0x19B9ACB3E50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableOnPlatformSharingExperiment = 0x19BACFD5E10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableOnPlatformSharingExperiment_v5 = 0x19BACFD2090; // Unknown = 
    inline constexpr uintptr_t FFlagEnableOtpEmailLoginRelease1 = 0x19B90648610; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePLTPrefetchCallbacks = 0x19BA607F910; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePWManagerSignupCheck = 0x19B9ACBB4D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePalisadesPaymentsPlatform = 0x19D85DC2350; // Unknown = 
    inline constexpr uintptr_t FFlagEnableParentalControlsScreentimeEnforcement3 = 0x19D84DACD50; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePartyNudgeAfterJoin2 = 0x19B8C2E2CD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePartyNudgeV1_DEV = 0x19BACFDB550; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePartyPageCarouselExperimentation4 = 0x19B8FDEF35D; // Bool = false
    inline constexpr uintptr_t FFlagEnablePartyQuickStartButton = 0x19BACFDF610; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePartyQuickStartButton3 = 0x19BACFD5210; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePartyQuickStartChanges2 = 0x19B8FDEEB1D; // Bool = false
    inline constexpr uintptr_t FFlagEnablePartyVoiceChangersInLua = 0x19BACFDB890; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePartyVoiceOnlyForEligibleUsers = 0x19BA67295DD; // Bool = false
    inline constexpr uintptr_t FFlagEnablePartyVoiceOnlyForUnfilteredThreads = 0x19BA672D29D; // Bool = true
    inline constexpr uintptr_t FFlagEnablePartyVoiceRestrictionStatus = 0x19BA8028790; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePartyVoiceStatusChangedDetailAnalytics = 0x19B859C9C1D; // Bool = false
    inline constexpr uintptr_t FFlagEnablePartyVoiceVolumeOnlyWhenInEligibleParty = 0x19B88C4B29D; // Bool = false
    inline constexpr uintptr_t FFlagEnablePasskeyLoginErrorLogging = 0x19B945A6FD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePasskeyOnlyUserErrorMessage = 0x19B8FC38850; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePasswordStatusRemoval = 0x19B90291190; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePaymentSessionIdInRobuxPurchase = 0x19B9EE02510; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePeekViewFocusNav = 0x19BC0543690; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePeekViewStateOnMountParam = 0x19B8578959D; // Bool = false
    inline constexpr uintptr_t FFlagEnablePeopleListLazyRender = 0x19BBC382BD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePeoplePageButtonOnMount = 0x19BBC38EBD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePerfRegressionTest = 0x19B902683D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePerformPurchaseGCSHandling = 0x19D85DCDD10; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePersonaLivenessQR = 0x19B8C30ED1D; // Bool = true
    inline constexpr uintptr_t FFlagEnablePinnedShortcutsOnHomeScreenLua2 = 0x19B9AF12990; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePioneerLandingPageLayout = 0x19B9ACB605D; // Bool = false
    inline constexpr uintptr_t FFlagEnablePioneerPaymentsPlatform = 0x19D85DC341D; // Bool = true
    inline constexpr uintptr_t FFlagEnablePioneerPostAuthGameJoin = 0x19B9ACB185D; // Bool = false
    inline constexpr uintptr_t FFlagEnablePlatformEvidence = 0x19BC0543410; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePlatformProfileContextualMenuOption = 0x19BA59B5BD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePlatformRestrictedEventReceiver3 = 0x19B9AF16B90; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePlayWithRewardComponent = 0x19BBB595850; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePlayWithRewardComponent10 = 0x19B88C42EDD; // Bool = false
    inline constexpr uintptr_t FFlagEnablePlayWithRewardNonPeekviewEdp = 0x19B9ACBA610; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePlayerListExposureEvents = 0x19BACE972D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePlayerSupportCaptureAttachments = 0x19B9EE0BB5D; // Bool = false
    inline constexpr uintptr_t FFlagEnablePlayerSupportCaptureAttachments2 = 0x19BA6074310; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePlayerSupportPrompt = 0x19BA6074B1D; // Bool = true
    inline constexpr uintptr_t FFlagEnablePlaytestModeUnibar2 = 0x19B9ACB2650; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePlusUpsellDeepLink = 0x19BA520126D; // Bool = false
    inline constexpr uintptr_t FFlagEnablePopLatencyOverlay = 0x19B85788510; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePostAuthRoutingInAllCases = 0x19B945AE510; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePostAuthRoutingInAllCases2 = 0x19B945A3DD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePreAuthDeepLinkHandler2 = 0x19B8FC395D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePriceChangedErrorHandling = 0x19D85DC4490; // Unknown = 
    inline constexpr uintptr_t FFlagEnableProfileCompletion = 0x19BA6A3C855; // Bool = false
    inline constexpr uintptr_t FFlagEnableProfileInsightsApolloMigration_v3 = 0x19B8C2E31D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableProfilePlatformChallengeInterceptor = 0x19BB7F41FD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableProfilePlatformDisabledActions = 0x19BACFD6B90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableProgressLoadingAssetsAppContainer = 0x19B9064E85D; // Bool = false
    inline constexpr uintptr_t FFlagEnableProgressLoadingAssetsTenFoot = 0x19B90641D9D; // Bool = false
    inline constexpr uintptr_t FFlagEnablePromptAgeCheckListener = 0x19B9AF11350; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePromptPurchaseRequestedV2 = 0x19D85DC9890; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePromptPurchaseRequestedV2Take2 = 0x19D85DC9F90; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePromptRobloxSubscriptionPurchaseBinding = 0x19D85DC0510; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePromptRobloxSubscriptionPurchaseBinding2 = 0x19D85DC6390; // Unknown = 
    inline constexpr uintptr_t FFlagEnableProvisionalRating = 0x19BAD1A4FCD; // Bool = true
    inline constexpr uintptr_t FFlagEnablePurchaseFlowUUIDMigration = 0x19D85DC8B50; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePurchasePayloadInExperienceShop = 0x19B9ACB0E10; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePushNotificationsUpsellModal6 = 0x19B8C304850; // Unknown = 
    inline constexpr uintptr_t FFlagEnablePushNotificationsUpsellModalChat4 = 0x19B9F1824BD; // Bool = true
    inline constexpr uintptr_t FFlagEnablePymkCarouselChallengeInterceptor = 0x19B8FC3A610; // Unknown = 
    inline constexpr uintptr_t FFlagEnableQuestIAPAnalytics = 0x19D85DC1890; // Unknown = 
    inline constexpr uintptr_t FFlagEnableQueueExperimentation2 = 0x19B8FDED79D; // Bool = false
    inline constexpr uintptr_t FFlagEnableRMOnMorePageForAll = 0x19BA6A3AAD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableRMOnMorePageGUAC = 0x19BA6A37BD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableReactSchedulerIXP = 0x19B9ACB0410; // Unknown = 
    inline constexpr uintptr_t FFlagEnableReadAloudInUA2 = 0x19B8578C61D; // Bool = false
    inline constexpr uintptr_t FFlagEnableRecentActivityInspectAndBuy = 0x19B9F18F9BD; // Bool = true
    inline constexpr uintptr_t FFlagEnableRecentActivitySingleItemDetails = 0x19B9F18B8FD; // Bool = true
    inline constexpr uintptr_t FFlagEnableRecommendationsForPCGDK = 0x19B8C2E1E1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableRecordLogin = 0x19B9ACB6510; // Unknown = 
    inline constexpr uintptr_t FFlagEnableRecordLogin1 = 0x19B9ACB1790; // Unknown = 
    inline constexpr uintptr_t FFlagEnableRecordSignOut = 0x19B902901D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableReferredPlayerJoinRemoteEvent = 0x19B945A3390; // Unknown = 
    inline constexpr uintptr_t FFlagEnableReferredPlayerJoinRemoteEventForAll = 0x19B945A4190; // Unknown = 
    inline constexpr uintptr_t FFlagEnableRejectPromiseOnWebviewClosed = 0x19BA5158C10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableReminderOfNormsABTest = 0x19BC05444D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableReportAdDropdown5 = 0x19BA8A0F09D; // Bool = false
    inline constexpr uintptr_t FFlagEnableReportingFlowForDevSubs = 0x19B9ACBC350; // Unknown = 
    inline constexpr uintptr_t FFlagEnableReportingFlowForDevSubs2 = 0x19B9ACBFC10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableReportingFlowForExperienceShop2 = 0x19B9ACBF5D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableReportingFlowForMomentsFeed = 0x19B9ACBBA90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableRequestLocationTypeForSduiPurchase = 0x19D85DC2E90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableRetryForLinkingProtocolFetch = 0x19B8578A55D; // Bool = false
    inline constexpr uintptr_t FFlagEnableRetryOnPrefetch401 = 0x19BA3A7B310; // Unknown = 
    inline constexpr uintptr_t FFlagEnableReusableVPCPrologue = 0x19B9011229D; // Bool = false
    inline constexpr uintptr_t FFlagEnableRewardsWebViewOverlay = 0x19D8952B4D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableRichTextForBubbleChat = 0x19B81E171DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableRoactNetworkingForChallengeInteception = 0x19B90112D5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableRobloxSubscriptionEventListener = 0x19B9AF181D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableRobuxInExperienceShop = 0x19B9ACBAF50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableRobuxInExperienceShop3 = 0x19B9ACBC610; // Unknown = 
    inline constexpr uintptr_t FFlagEnableRobuxTransferFlowEventIngest = 0x19B8C2EBB50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSafetyDashboard = 0x19B825F743D; // Bool = true
    inline constexpr uintptr_t FFlagEnableSavePasswordAfterRecovery = 0x19B88C4C25D; // Bool = false
    inline constexpr uintptr_t FFlagEnableScheduledSquadsListExperimentation_dev = 0x19B8FDEDADD; // Bool = false
    inline constexpr uintptr_t FFlagEnableScheduledSquadsTopBarEntrypoint_dev = 0x19BBB2D8A5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableSchedulerFlagOverrides = 0x19B9ACBD1D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSchematizedInGameRobuxUpsellEvent2 = 0x19BAE780D0D; // Bool = true
    inline constexpr uintptr_t FFlagEnableSchoolEntry = 0x19B8C2E4710; // Unknown = 
    inline constexpr uintptr_t FFlagEnableScreentimeMoreTimeOption = 0x19BA59B8C90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableScrollAwayContentScrollableFix = 0x19B9ACB8710; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSduiRegistriesforTenFootUiContainer = 0x19B90641FDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableSduiV2HomepagePrompts2 = 0x19B88C4F6D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSeamlessVoiceDataConsentToast = 0x19BA515819D; // Bool = false
    inline constexpr uintptr_t FFlagEnableSeamlessVoiceFeature = 0x19B8FDEAEDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableSearchOmniAutocompletePageByDefault5 = 0x19B88C4E61D; // Bool = false
    inline constexpr uintptr_t FFlagEnableSecurityAlertDeeplink = 0x19B8C30B61D; // Bool = true
    inline constexpr uintptr_t FFlagEnableSecurityAlertToastCallback = 0x19B8C30BFDD; // Bool = true
    inline constexpr uintptr_t FFlagEnableSendCameraAccessAnalytics = 0x19B9AF11950; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSessionCheckManagerToListenOnce = 0x19B902925D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSetCoreGuiEnabledExpChat = 0x19B81E1691D; // Bool = false
    inline constexpr uintptr_t FFlagEnableSettingsHubUIDelegateRollout = 0x19BA6A392D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableShareLinksInGameDetailEvent = 0x19B9ACB3A10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableShareSheetForBuild = 0x19B9AF19BD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSharedInviteStore = 0x19BB4E67A3D; // Bool = false
    inline constexpr uintptr_t FFlagEnableShopGiftCardsURL = 0x19BA5BD7D10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableShortLinkCodeForVRCDLv2 = 0x19BC0540290; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSideSheet = 0x19B9ACB4C5D; // Bool = true
    inline constexpr uintptr_t FFlagEnableSideSheet6 = 0x19B9ACBAD1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableSignUpExitModal = 0x19B9ACBAE90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSignUpExitModal3 = 0x19B9ACBD4D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSignupFoundationText2 = 0x19B945A3E90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSignupFoundationalizeBackgroundAndText = 0x19B945A5F50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSilentUpgradeOnSignUp = 0x19B9ACB2090; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSilentUpgradeOnSignUp2 = 0x19B9ACBE610; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSkyStyle = 0x19BA6A3F61D; // Bool = false
    inline constexpr uintptr_t FFlagEnableSlotsHeadShapeThumbnail = 0x19BA3A51850; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSlotsHeadShapeThumbnail2 = 0x19BA3A545D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSnapInVirtualCursor2 = 0x19BA59BB650; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSocialCards2 = 0x19B8C2E3A50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSocialContextToast = 0x19BC0541910; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSocialProofOnItemDetails = 0x19BACFD211D; // Bool = false
    inline constexpr uintptr_t FFlagEnableSocialProofOnItemDetailsRoactGamepadNavigation = 0x19BACFD5110; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSocialProofUserList = 0x19BACFD9DD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSocialProofUserList_4 = 0x19BACFDB0D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSocialProofVerticalUserListSheet = 0x19BA74E2010; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSocialProofVerticalUserListSheet_2 = 0x19B85788F90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSocialTabsPage = 0x19BACFD92D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSocialTabsPage_DEV = 0x19BACFDDC10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSortInvitesByScoreExperiment = 0x19BADF9A4DD; // Bool = true
    inline constexpr uintptr_t FFlagEnableSoundSessionTelemetry5 = 0x19B9AF123D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSpatialRobloxGui = 0x19B9FDD4D55; // Bool = false
    inline constexpr uintptr_t FFlagEnableSpatialRobloxGui4 = 0x19BB2AF6AD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSpatialUIBottomBarFixPlaceFilter = 0x19B9FD8839D; // Bool = false
    inline constexpr uintptr_t FFlagEnableSpatialUICameraTypeFix8 = 0x19BA3BB18D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSpatialUIPlaceFilter = 0x19BA3BB2550; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSpatialUIScalingFix = 0x19BA3BB9110; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSplitPanel = 0x19B85786D90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSquadCoplayAnalytic = 0x19B88C2AD1D; // Bool = false
    inline constexpr uintptr_t FFlagEnableSquadDeeplinkWithChatId = 0x19B8C2E3A90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSquadLobbyUpsellCardShortScreenFix = 0x19B82C1A6DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableSquadPromptAnalytics = 0x19BA8020A50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSquadRegroupExperimentation = 0x19B9F18E7BD; // Bool = true
    inline constexpr uintptr_t FFlagEnableSquadRegroupExperimentation1 = 0x19B8C30211D; // Bool = true
    inline constexpr uintptr_t FFlagEnableSquadRegroupExperimentationSmallScreenFix = 0x19B8C30231D; // Bool = true
    inline constexpr uintptr_t FFlagEnableSquadRegroupServerCapacityCheck = 0x19B8C3024DD; // Bool = true
    inline constexpr uintptr_t FFlagEnableSquadTopBannerWideMode = 0x19B8C2E3F50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSquadUserCardHoverFix = 0x19BACFD1210; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSquadsUnifyCoplayExperimentation_dev = 0x19B8FDEE5DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableSquadsUnifyCoplayMultiInvitePartyCreation_dev = 0x19B8FDEE49D; // Bool = false
    inline constexpr uintptr_t FFlagEnableSquadsUnifyCoplayOneOnOnePartyCreation_dev = 0x19B8FDEE41D; // Bool = false
    inline constexpr uintptr_t FFlagEnableStandaloneAppChat = 0x19BA672E0DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableStorePreviousAccountData = 0x19B945A18D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableStreamAvatarImageUrlThumbnail = 0x19BA6076950; // Unknown = 
    inline constexpr uintptr_t FFlagEnableStudioMockPurchaseRobloxSubscription = 0x19B9F18B7BD; // Bool = true
    inline constexpr uintptr_t FFlagEnableSubTabForSpatial = 0x19B9ACB00D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSubscriptionPurchaseFlowEventIngest = 0x19B8FC33C9D; // Bool = false
    inline constexpr uintptr_t FFlagEnableSubscriptionPurchaseToast = 0x19B9EE020DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableSubscriptionUpsellUnifiedPurchaseEventTelemetry = 0x19B93A1E010; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSummarySystemMessageOnLua = 0x19B8578599D; // Bool = false
    inline constexpr uintptr_t FFlagEnableSupportCenter = 0x19B8C30E8DD; // Bool = true
    inline constexpr uintptr_t FFlagEnableSystemScrim = 0x19B9AF11ED0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSystemScrimInSettingsHub = 0x19BACE9DC9D; // Bool = false
    inline constexpr uintptr_t FFlagEnableSystemTrayModals = 0x19B9ACB18D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableSystemTrayModals3 = 0x19B9ACB8190; // Unknown = 
    inline constexpr uintptr_t FFlagEnableTFFeedbackModeEntryCheck = 0x19B9FD8D5DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableTTIRecordWebViewMilestones = 0x19B8578C25D; // Bool = false
    inline constexpr uintptr_t FFlagEnableTeamTestLua = 0x19B9ACB2C90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableTeamTestLuaVersionCheck = 0x19B9ACB9FD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableTelemetryProtocol = 0x19B8C316F90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableTenftUiDetailsMoreDropupMenu = 0x19BA6A39810; // Unknown = 
    inline constexpr uintptr_t FFlagEnableTiltLoadingScreen = 0x19B9AF128D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableTiltLoadingScreen2 = 0x19B9AF129D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableTimeoutUI = 0x19BA6076B1D; // Bool = true
    inline constexpr uintptr_t FFlagEnableToSwitchToSettingsAppWithRouteLua = 0x19B8F90F11D; // Bool = false
    inline constexpr uintptr_t FFlagEnableToastIconSupport = 0x19B8C30B390; // Unknown = 
    inline constexpr uintptr_t FFlagEnableToastLiteRender = 0x19D85DCDAD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableToastNotificationsDeeplinkConfirmationModalHeightFix = 0x19BA607A050; // Unknown = 
    inline constexpr uintptr_t FFlagEnableTopBarAnalytics = 0x19BBF8812A8; // Unknown = 
    inline constexpr uintptr_t FFlagEnableTopSongsSort7 = 0x19B88C4EFDD; // Bool = false
    inline constexpr uintptr_t FFlagEnableTradesEntryForNonPremium = 0x19BA6A33390; // Unknown = 
    inline constexpr uintptr_t FFlagEnableTransparentDeviceIntegrityChallengeSpinner = 0x19BA6078F10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableTransparentNativeChallengeWrapper = 0x19B9064461D; // Bool = false
    inline constexpr uintptr_t FFlagEnableUIManagerPackgify = 0x19BA6A31950; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUIManagerPackgify8 = 0x19BA6A300D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUISelector3 = 0x19BA4611A5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableUnifiedProductPurchaseFlow = 0x19B9ACB64D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUnifiedProductPurchaseFlowV37 = 0x19B9ACB92D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUnifiedPurchaseFlowForDevSubs = 0x19B9ACB8A50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUnifiedPurchaseFlowForDevSubs10 = 0x19B9ACB12D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUniveralVoiceToasts = 0x19BA5157E5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableUpdateAddPhoneDescriptionTextExperimentRelease1 = 0x19B90294D90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUpdatedCaptureControls = 0x19D86F0BED0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUpdatedCaptureControls_v9 = 0x19D86F074D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUpdatedLogoutUpsellModal = 0x19B945A7590; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUpsellSuggestionsAnalyticsId = 0x19B9ACBAC90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUpsellVirtualItemBadge = 0x19BAC833B5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableUseShowTopBar4 = 0x19B8578931D; // Bool = false
    inline constexpr uintptr_t FFlagEnableUserAccessServiceIntegration = 0x19B8DD87890; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUserAccessServiceIntegration3 = 0x19B8C30B11D; // Bool = true
    inline constexpr uintptr_t FFlagEnableUserInputCFrameLogging = 0x19BBE911690; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUserListModule = 0x19BACFD9AD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUserListModule_2 = 0x19BACFD6F50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableUserRecentActivityEntryPoint = 0x19B9F18BA2D; // Bool = true
    inline constexpr uintptr_t FFlagEnableUserRecentActivityEntryPoint_v2 = 0x19B8C30371D; // Bool = true
    inline constexpr uintptr_t FFlagEnableUserSearchChallengeInterceptor = 0x19B9011D590; // Unknown = 
    inline constexpr uintptr_t FFlagEnableVNGNewAppAvailableModal = 0x19B906491DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableVPCUpsellFoundationDialogHardening = 0x19B90110FD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableVRChartsTab = 0x19BC054E710; // Unknown = 
    inline constexpr uintptr_t FFlagEnableVREnvironmentSetting3 = 0x19BA6A3CA10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableVRFTUXExperienceV2 = 0x19BAFCFD810; // Unknown = 
    inline constexpr uintptr_t FFlagEnableVRPreparePaymentCheck = 0x19BAC8335DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableVRWrapperTransparency = 0x19BC0540ED0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableValidateFAEVerificationLink = 0x19B90112A90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableVerifiedBadgeStore = 0x19BAE722170; // Unknown = 
    inline constexpr uintptr_t FFlagEnableVerifiedCheckViaOverlay = 0x19BA515949D; // Bool = false
    inline constexpr uintptr_t FFlagEnableVirtualCursorDebugging = 0x19BA59BF710; // Unknown = 
    inline constexpr uintptr_t FFlagEnableVirtualizedListBacktraceTag = 0x19B9029281D; // Bool = false
    inline constexpr uintptr_t FFlagEnableVoiceChatStorybookFix = 0x19B81E9E098; // Unknown = 
    inline constexpr uintptr_t FFlagEnableVoiceChatVoiceUISync = 0x19BACE7C9DD; // Bool = false
    inline constexpr uintptr_t FFlagEnableVoiceEuConsentPrompt = 0x19BACFD261D; // Bool = false
    inline constexpr uintptr_t FFlagEnableVoicePromptReasonText = 0x19BA5157A90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableVoiceReverseNudge = 0x19B8FDE8F10; // Unknown = 
    inline constexpr uintptr_t FFlagEnableVoiceTrialUpsellCard = 0x19B90643F5D; // Bool = false
    inline constexpr uintptr_t FFlagEnableVoiceTrustedConnectionsToasts = 0x19BA515851D; // Bool = false
    inline constexpr uintptr_t FFlagEnableVoiceUxUpdates5_AEGIS2 = 0x19B8C305A1D; // Bool = true
    inline constexpr uintptr_t FFlagEnableVoiceVrVoiceConnectDisconnect_AEGIS2 = 0x19B8C305BDD; // Bool = true
    inline constexpr uintptr_t FFlagEnableVolumeSliderQOLFix = 0x19BA6A3F990; // Unknown = 
    inline constexpr uintptr_t FFlagEnableVpcForInExperiencePremiumUpsell = 0x19B9EE01F9D; // Bool = false
    inline constexpr uintptr_t FFlagEnableVpcForInExperienceSubscriptionPurchase = 0x19B9EE0229D; // Bool = false
    inline constexpr uintptr_t FFlagEnableVrVoiceParity = 0x19BA6A3D410; // Unknown = 
    inline constexpr uintptr_t FFlagEnableWebAmpWizardForFAEHandoff = 0x19B90112390; // Unknown = 
    inline constexpr uintptr_t FFlagEnableWebViewOpenDurationCap = 0x19B90292B90; // Unknown = 
    inline constexpr uintptr_t FFlagEnableWebViewStateTracker = 0x19B9ACB5AD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableWebViewStateTracker3 = 0x19B9ACBBAD0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableWhatsNew2 = 0x19B9ACB2A50; // Unknown = 
    inline constexpr uintptr_t FFlagEnableWhiteOrGreyRobuxIcon = 0x19B948105D0; // Unknown = 
    inline constexpr uintptr_t FFlagEnableWhiteRobuxIcon = 0x19B94810910; // Unknown = 
    inline constexpr uintptr_t FFlagEnableWidgetLUAIXP = 0x19B88C4BA1D; // Bool = false
    inline constexpr uintptr_t FFlagEncodeSquadMembersUpdated = 0x19BA672019D; // Bool = true
    inline constexpr uintptr_t FFlagEngineAudioSTTIsDictationEnabled = 0x19BABBD13DD; // Bool = false
    inline constexpr uintptr_t FFlagEnhancedPersonaLivenessEvents = 0x19B8C30EF9D; // Bool = true
    inline constexpr uintptr_t FFlagEraseFPSFromDefaultSetting = 0x19B9FD8D450; // Unknown = 
    inline constexpr uintptr_t FFlagErrorPromptUseLeaveGameHelper = 0x19BA59B3650; // Unknown = 
    inline constexpr uintptr_t FFlagEventsInExperienceAppFixStyleLink = 0x19BA6073E1D; // Bool = true
    inline constexpr uintptr_t FFlagExpChatAddUserAsyncNilCheck = 0x19B9F18D075; // Bool = true
    inline constexpr uintptr_t FFlagExpChatAddWindowSettingDependency = 0x19BA515415D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatAddressFrame0Flash = 0x19B9CB74310; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatAlignSystemMessageStyling = 0x19B9F187165; // Bool = true
    inline constexpr uintptr_t FFlagExpChatBackspaceExitsTargetChannelInGlobalTabs = 0x19BA3A5289D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatBubbleChatRerenderOnAncestryChange = 0x19BB8FBFCE8; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatCanShowFriendsTab = 0x19BACFDE150; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatCanShowFriendsTabRC1 = 0x19BACFD5F90; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatChannelBarDropdownZIndexFix = 0x19BA515085D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatChannelTabSizingUpdate2 = 0x19BA679FBDD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatClearHiddenMessagesPostAgeCheck = 0x19B9CB7971D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatComposerFigmaParity = 0x19B9CB7C25D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatConditionallyMountAppLayout2 = 0x19BA6B3EE1D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatContinuousDictation = 0x19BA59B2850; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatDebounceRephraseIndexSelection = 0x19B9FD8D690; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatDictatedSpeechEnabled = 0x19BBCD77AD0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatDictation = 0x19BA59B0DD0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatDictation3 = 0x19BA59B1C1D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatDictationFTUX = 0x19BBF850408; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatDictationFTUX2 = 0x19BABBD021D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatDictationFadeOverride = 0x19BA553003D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatDictationIXPExposure = 0x19BABBD259D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatDictationMicToastFix = 0x19BABBD0950; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatDictationU13PolicyToast = 0x19BABBD0F1D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatDisableUniverseBubbleChat2 = 0x19B8FA13390; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatDoNotSetCursorPosition = 0x19BA3A53AD0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatDynamicV2Pool = 0x19BA515AC5D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatEmojiInputParity = 0x19BA59BD950; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatEnableCrossAgeChatActivity = 0x19BA515A59D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatEnableFOMOUpsell = 0x19B822EA405; // Bool = false
    inline constexpr uintptr_t FFlagExpChatEnableFriendsTab = 0x19BACFD3CD0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatEnableFriendsTabRC1 = 0x19BACFD8E10; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatEnableGlobalChatSummarySystemMessage = 0x19BA74A581D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatEnableGlobalOnlineCommand = 0x19B9F18FFBD; // Bool = true
    inline constexpr uintptr_t FFlagExpChatEnableNewBottomLockedScrollView = 0x19B8C2B3D5D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatEnablePresetChatBadgeFTUXExperimentation = 0x19B8FDEC91D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatEnableTabsImpressionAnalytics = 0x19BA515CB1D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatEnableV2ChatWindow = 0x19BA3BBD99D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatEnableV2ChatWindow6 = 0x19B9BF24F15; // Bool = false
    inline constexpr uintptr_t FFlagExpChatEnableVirtualLocalOnlineCommand = 0x19B8FA13BD0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatEnableVoiceReverseNudge = 0x19BBCD74050; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatEvictFloodcheckedFromWindowOrder = 0x19BA553811D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatExcludeFOMORenders = 0x19B9CB763D0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatFixBackspaceNilTargetChannel = 0x19B8FA1425D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatFixChannelBarInitialWidth = 0x19BA5155010; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatFixChannelTabsMidExperienceToggle = 0x19BA74A2ADD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatFixInputBarSendEligibility = 0x19B9CB7BFDD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatFixLocalUserVerifiedBadge = 0x19B9CB72EDD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatFixRateLimitedMessageRemoval = 0x19BA515089D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatFixRateLimitedMessageRemoval2 = 0x19BA5158EDD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatFixTeamChangeOverwriteChannel = 0x19B8FA14710; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatFixTopPaddingColor = 0x19BA6B3E210; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatFixWarmMountBottomLock = 0x19BA3A5465D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatFlipDictationPriority = 0x19BBCD77890; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatFocusChannelBarSupport = 0x19BA515371D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatFocusViaLastModeFix = 0x19BA4611210; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatFocusViaLastModeFix2 = 0x19BABBD28D0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatFocusablePlaceholderText = 0x19BAB70F9DD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatFriendsTabUsePolicy = 0x19BA6A3F790; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatGlobalCommandAutocompletePrimaryAliasOnly = 0x19BA4616E10; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatGuacChatDisabledReason = 0x19B8C2E2E90; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatInputBarV2CornerAndTruncationFix = 0x19BAB70FBD0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatInputBarV2CustomSendButton = 0x19BAB70FCDD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatKeepV2PoolMounted = 0x19BA515669D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatLimitScrollingV2Window = 0x19BA3A57A1D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatLogGlobalChatTabClicked = 0x19BA515025D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatLogTabClicked = 0x19BA51502D0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatLongPressContinuousDictation = 0x19BA59B7A1D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatMainInputBarClickAnalytics = 0x19BABBD301D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatMemoBillboardGui = 0x19BBCD71190; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatMessagesStoreBatch = 0x19BA5531F9D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatMessagesStoreKeepInByMessageId = 0x19BA55331DD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatMessagesStoreMemoryCleanup = 0x19BA5530C9D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatMessagesStoreUseProxy = 0x19BA5531D9D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatMicBubbleSingleImage = 0x19BBCD78490; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatMigrateScrollIntervalTracker = 0x19B9CB720D0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatMigrationReplicationFix = 0x19BACFD0590; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatMoveMessagesStoreToInit = 0x19BA515ED1D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatMuteByUserIdBeforeUsernameCheck = 0x19BA515E11D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatNewInputBar = 0x19BBCD74110; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatNewInputBar4 = 0x19BBCD72910; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatNewInputBarDictation = 0x19BABBD1F90; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatOnlyWakeTextForSelectedTab = 0x19BA74A4650; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatPerfTrackerTabName = 0x19B9CB72C50; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatPolishSummaryMessageUI = 0x19BA6796F10; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatPresetAutocompleteIxpEnabled = 0x19BABBD2A1D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatPresetBoltInMessageLayout = 0x19B9CB735DD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatPresetButtonOldInputBarV2 = 0x19BA6B3E510; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatPresetChatAutocompleteAnalyticsEnabled = 0x19BABBD1710; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatPresetChatAutocompleteEnabled = 0x19BA7311E05; // Bool = false
    inline constexpr uintptr_t FFlagExpChatPresetChatEnabled10 = 0x19B8FA1445D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatPresetChatFixesEnabled = 0x19BA6B3F0DD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatPresetChatGamepadEnabled = 0x19BAB70FF50; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatPresetChatIXPExposure = 0x19BABBD219D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatPresetChatLoadTestEnabled = 0x19B8FA1459D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatPresetChatSendEnabled = 0x19B9F18C88D; // Bool = true
    inline constexpr uintptr_t FFlagExpChatPresetChatVREnabled = 0x19B8FA143DD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatPresetFixChatHotkey = 0x19BA6B3EAD0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatReconcileOnAgeVerifiedChange = 0x19BA74A2990; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatRefactorEnabledMessageLogic = 0x19BBC38745D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatRemoveBubbleChatAppUserMessagesState = 0x19BBACABA05; // Bool = false
    inline constexpr uintptr_t FFlagExpChatRemoveSpaceFromTeamPrefix = 0x19BB20AC270; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatReportChatEnabledUserCountMetrics = 0x19BBC385790; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatReportVirtualCommandTelemetry = 0x19D82453925; // Bool = false
    inline constexpr uintptr_t FFlagExpChatRewriteInline = 0x19BA515FE1D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatRewriteInline3 = 0x19BA5157D5D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatRewriteInlineIxpEnabled = 0x19BA515935D; // Bool = true
    inline constexpr uintptr_t FFlagExpChatRewriteToggleAnalytics = 0x19BA5150D5D; // Bool = true
    inline constexpr uintptr_t FFlagExpChatScrollbarInset = 0x19BA3A5E450; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatSelectTextChatTabByName = 0x19BACFD6610; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatSendWindowScrollEvent = 0x19BA3A5E2D0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatShowPresetTooltipToNonAgeChecked2 = 0x19BC2218430; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatSuppressGlobalSummaryTabUnread = 0x19BA74A5D9D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatSuppressWelcomeMessageTabUnread = 0x19B8FA14A90; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatSyntheticSystemMessageRichText = 0x19B8FA14D1D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatTelemetryEventTrigger3 = 0x19B9F18570D; // Bool = true
    inline constexpr uintptr_t FFlagExpChatTopBannerForPresetChatAccess = 0x19BA5153DDD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatTopBannerZIndexFix = 0x19BB6B2DB50; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatTranslationToggleSpacingFix = 0x19BA5157CDD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatTransparentFocusSupport = 0x19BA553291D; // Bool = false
    inline constexpr uintptr_t FFlagExpChatTriggerWindowStatusEvent = 0x19BA6B3F550; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUniverseChatPresetEnabled = 0x19BA461BADD; // Bool = false
    inline constexpr uintptr_t FFlagExpChatUniverseChatPresetEnabled2 = 0x19BA731739D; // Bool = true
    inline constexpr uintptr_t FFlagExpChatUnreadTabIndicatorV2Window = 0x19BB20A429D; // Bool = true
    inline constexpr uintptr_t FFlagExpChatUseAdorneeStore = 0x19BACFD42D0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseAdorneeStoreV4 = 0x19BACFD1110; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseChannelTabsStore = 0x19BACFD1C9D; // Bool = true
    inline constexpr uintptr_t FFlagExpChatUseChannelTabsStore3 = 0x19BACFD169D; // Bool = true
    inline constexpr uintptr_t FFlagExpChatUseChatConfigStore = 0x19BACFD38D0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseChatMuteStore = 0x19BACFD7050; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseGuacForCrossAgeChat = 0x19B8C2E4CD0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseGuacForFOMOUpsell = 0x19B8C2E4B90; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseInternalTextChatAPIs2 = 0x19BACFD21D0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseMessagesStore = 0x19BACFD0B90; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseMessagesStore9 = 0x19BACFD8DDD; // Bool = true
    inline constexpr uintptr_t FFlagExpChatUseProximityStore = 0x19BACFDD810; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseSharedChannelTabDisplayLabel2 = 0x19BACFD72D0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseTooltipPromptStyle = 0x19BBCD75390; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseUnifiedTooltipStore = 0x19B9F18C8CD; // Bool = true
    inline constexpr uintptr_t FFlagExpChatUseUpdatedMessageRendered = 0x19BBCD7C390; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseUpdatedUserCountStrings = 0x19B8FA13650; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseVirtualCommandRunner = 0x19BBCD77D10; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatUseVoiceParticipantsStore2 = 0x19BACFDC0D0; // Unknown = 
    inline constexpr uintptr_t FFlagExpChatWindowSyncUnibar = 0x19BA59B031D; // Bool = false
    inline constexpr uintptr_t FFlagExpDetailsUseSelectionBumpers = 0x19BA520DEBD; // Bool = true
    inline constexpr uintptr_t FFlagExperienceBannerImageAllowCustomDimensions = 0x19B9026245D; // Bool = false
    inline constexpr uintptr_t FFlagExperienceBannerImageDefaultFallback = 0x19B9026269D; // Bool = false
    inline constexpr uintptr_t FFlagExperienceChatUserProfileApiEnabledForAll_v1 = 0x19BA515EF5D; // Bool = false
    inline constexpr uintptr_t FFlagExperienceLoadingScreenFixStyleLink = 0x19BA8A08A5D; // Bool = false
    inline constexpr uintptr_t FFlagExperienceMenuGamepadExposureEnabled = 0x19B9ACB5B10; // Unknown = 
    inline constexpr uintptr_t FFlagExperienceMenuGamepadExposureEnabled684 = 0x19B9ACB55D0; // Unknown = 
    inline constexpr uintptr_t FFlagExperienceShopGlobalIconSkipCoreGuiCheck = 0x19BB7F4C350; // Unknown = 
    inline constexpr uintptr_t FFlagExperiencesOnProfile = 0x19BA59B1B90; // Unknown = 
    inline constexpr uintptr_t FFlagExperiencesOnProfile_v2 = 0x19BA59BC110; // Unknown = 
    inline constexpr uintptr_t FFlagExtendScrollingFramesBySafeInsets2 = 0x19B8578899D; // Bool = false
    inline constexpr uintptr_t FFlagFFlagAXFixAvatarSaveContext = 0x19B9026C59D; // Bool = false
    inline constexpr uintptr_t FFlagFFlagAddDefaultFocusNavSelectorsOnBuyPurchasePrompt = 0x19BAC83109D; // Bool = false
    inline constexpr uintptr_t FFlagFFlagBlackbirdUpdateStringFlyoutMenu = 0x19BA6A363D0; // Unknown = 
    inline constexpr uintptr_t FFlagFFlagDebugInlineLayout = 0x19B8FC348D0; // Unknown = 
    inline constexpr uintptr_t FFlagFFlagEnableCallingLogoutOnResetIXP = 0x19B945A4510; // Unknown = 
    inline constexpr uintptr_t FFlagFFlagEnableFontStylisticAlternativesOnSocialScreens = 0x19BACFD37D0; // Unknown = 
    inline constexpr uintptr_t FFlagFFlagEnableLookFavoriting = 0x19B9026C1D0; // Unknown = 
    inline constexpr uintptr_t FFlagFFlagEnableMutexOnGenericChallengeInterceptorMount = 0x19BA607F290; // Unknown = 
    inline constexpr uintptr_t FFlagFFlagFixDetailsPageIconShadowSlicing = 0x19BA609B050; // Unknown = 
    inline constexpr uintptr_t FFlagFFlagFixLayeredSorting = 0x19BBC7ABFD0; // Unknown = 
    inline constexpr uintptr_t FFlagFFlagLogAllGuacRead = 0x19BB6BBCB90; // Unknown = 
    inline constexpr uintptr_t FFlagFFlagLogFirstGuacRead = 0x19BB6BBCB50; // Unknown = 
    inline constexpr uintptr_t FFlagFFlagLuaAppEnableWindowsHandheldScale = 0x19BA461B1DD; // Bool = false
    inline constexpr uintptr_t FFlagFFlagLuaAppFixToastNotificationClosePosition = 0x19BA6074350; // Unknown = 
    inline constexpr uintptr_t FFlagFFlagPCMAcceptWidthAsProp = 0x19B859CA090; // Unknown = 
    inline constexpr uintptr_t FFlagFFlagSongEdpCarouselIxp2 = 0x19B88C407D0; // Unknown = 
    inline constexpr uintptr_t FFlagFFlagTimeoutRemoteEvent = 0x19BACE7931D; // Bool = false
    inline constexpr uintptr_t FFlagFFlagUpdateNoInternetConnectionText = 0x19BBC7A9C10; // Unknown = 
    inline constexpr uintptr_t FFlagFacialAnimationStreamingClearAllConnectionsFix2 = 0x19B9F0ACF5D; // Bool = false
    inline constexpr uintptr_t FFlagFacialAnimationStreamingClearTrackImprovementsV2 = 0x19B9F0ACDDD; // Bool = false
    inline constexpr uintptr_t FFlagFacialAnimationStreamingFixNilMutedCheck = 0x19B9F0ACFD0; // Unknown = 
    inline constexpr uintptr_t FFlagFacialAnimationStreamingIfNoDynamicHeadDisableA2C = 0x19B9F0AD01D; // Bool = false
    inline constexpr uintptr_t FFlagFacialAnimationStreamingSearchForReplacementWhenRemovingAnimator = 0x19B9F0ACE5D; // Bool = false
    inline constexpr uintptr_t FFlagFacialAnimationStreamingValidateAnimatorBeforeRemoving = 0x19B9F0ACE1D; // Bool = false
    inline constexpr uintptr_t FFlagFeedbackEntryPointButtonSizeAdjustment2 = 0x19B9FD8D71D; // Bool = false
    inline constexpr uintptr_t FFlagFeedbackEntryPointImprovedStrictnessCheck = 0x19B9FD8D8DD; // Bool = false
    inline constexpr uintptr_t FFlagFilterNewPlayerListValueStat = 0x19BACE95CDD; // Bool = false
    inline constexpr uintptr_t FFlagFilterOutDeletedAccountsGameInvites = 0x19BADF9F2DD; // Bool = true
    inline constexpr uintptr_t FFlagFilterOutShopOnlyItemsonBulkPurchase = 0x19B9ACBBF90; // Unknown = 
    inline constexpr uintptr_t FFlagFilterSecurityAlertsVRToastEnabled = 0x19B8C30B050; // Unknown = 
    inline constexpr uintptr_t FFlagFindFriendsClickedEventEnabled = 0x19BAFCF32D0; // Unknown = 
    inline constexpr uintptr_t FFlagFireErrorRCCTimeoutSignal = 0x19B859C935D; // Bool = false
    inline constexpr uintptr_t FFlagFix10ftGlobalNavSelection = 0x19BA6A315DD; // Bool = true
    inline constexpr uintptr_t FFlagFixAbuseReportInExpPhantomAnalytics = 0x19BB7F47FD0; // Unknown = 
    inline constexpr uintptr_t FFlagFixAccountSwitcherOverlayBackgroundTap = 0x19B88C4CC9D; // Bool = false
    inline constexpr uintptr_t FFlagFixAnalyticsForDynamicReportV2 = 0x19B8C30DB90; // Unknown = 
    inline constexpr uintptr_t FFlagFixAppNavContainerShortcutBarHeight = 0x19BBCD716D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixBackOnTopBarTriggeringDevUI = 0x19B82BCFDDD; // Bool = false
    inline constexpr uintptr_t FFlagFixBannerButtonSize = 0x19B90294F10; // Unknown = 
    inline constexpr uintptr_t FFlagFixBulkPurchaseInputPerf = 0x19B9F9296D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixBulkPurchaseStarterGuiRename = 0x19B9F92999D; // Bool = false
    inline constexpr uintptr_t FFlagFixBundlePromptThumbnail = 0x19D85DC97D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixBundleThumbnailOnDetailPage = 0x19B9F0A3A90; // Unknown = 
    inline constexpr uintptr_t FFlagFixBuyRobuxForAndroid = 0x19B9F92991D; // Bool = false
    inline constexpr uintptr_t FFlagFixCameraSetupBeforeMood = 0x19B84FE539D; // Bool = false
    inline constexpr uintptr_t FFlagFixCarouselTileSizeScaling = 0x19B8FA1ECD0; // Unknown = 
    inline constexpr uintptr_t FFlagFixCharacterManagerValueConversionWarning = 0x19B90646F1D; // Bool = false
    inline constexpr uintptr_t FFlagFixCharacterNameHandlerNilProfileCrash = 0x19B9F921E1D; // Bool = false
    inline constexpr uintptr_t FFlagFixChatLanguageSwitcherLabel = 0x19B9FD8C59D; // Bool = false
    inline constexpr uintptr_t FFlagFixChatsBottomInsetBackgroundColor = 0x19B8FA15150; // Unknown = 
    inline constexpr uintptr_t FFlagFixCohubExposureLayer = 0x19BA59B30D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixCohubSearchYNavigation = 0x19BA59B4810; // Unknown = 
    inline constexpr uintptr_t FFlagFixCohubUiBugs = 0x19BA59B9250; // Unknown = 
    inline constexpr uintptr_t FFlagFixConnectTabSearchBarHeight = 0x19BACFD5F10; // Unknown = 
    inline constexpr uintptr_t FFlagFixConsoleEDPDirectionalNavigation = 0x19BA609F910; // Unknown = 
    inline constexpr uintptr_t FFlagFixContextualMenu = 0x19B82CBDE5D; // Bool = true
    inline constexpr uintptr_t FFlagFixCountersForUpsellModalShown = 0x19B9EE0185D; // Bool = false
    inline constexpr uintptr_t FFlagFixCrossExperienceVoiceExecutePrint = 0x19B9AF197D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixCyclicFullscreenIndexEvent = 0x19B9FD8D31D; // Bool = false
    inline constexpr uintptr_t FFlagFixDefaultThemeOverride = 0x19B9AF16F10; // Unknown = 
    inline constexpr uintptr_t FFlagFixDetailsPageIconShadowSlicing = 0x19B82C68B9D; // Bool = false
    inline constexpr uintptr_t FFlagFixDeveloperConsoleButtonSizeAndPositioning = 0x19B9FD8D4DD; // Bool = false
    inline constexpr uintptr_t FFlagFixDeviceSafePaddingAccess = 0x19BA609FF50; // Unknown = 
    inline constexpr uintptr_t FFlagFixDisableTopPaddingError = 0x19BACE9C71D; // Bool = false
    inline constexpr uintptr_t FFlagFixDisabledScrollOnIos = 0x19BACE9DD5D; // Bool = false
    inline constexpr uintptr_t FFlagFixDoubleSubmit = 0x19B9011E41D; // Bool = false
    inline constexpr uintptr_t FFlagFixDrawerNavigateBackWhileClosing = 0x19B9AF105DD; // Bool = false
    inline constexpr uintptr_t FFlagFixEmptyLimitedBadges = 0x19B9026DD1D; // Bool = false
    inline constexpr uintptr_t FFlagFixEmptyLimitedBadgesForBundles = 0x19B9026D2D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixFeedItemRenderedRowsEqualityCheck = 0x19B9026A89D; // Bool = false
    inline constexpr uintptr_t FFlagFixFetchNextOmniWithoutPageToken3 = 0x19B90262C5D; // Bool = false
    inline constexpr uintptr_t FFlagFixFiatPaidAccessPlayButton = 0x19B8F90E85D; // Bool = false
    inline constexpr uintptr_t FFlagFixFocusWhenInGameMenuIsOpen = 0x19BA6073C5D; // Bool = true
    inline constexpr uintptr_t FFlagFixFullscreenTitleBarPromiseCancel = 0x19D8168F110; // Unknown = 
    inline constexpr uintptr_t FFlagFixGameInviteModalLoadTimeIncrease = 0x19D895251D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixGetPlayerByUserIdStringCast = 0x19B8FDEA690; // Unknown = 
    inline constexpr uintptr_t FFlagFixGlobalChat3pSummarySystemMessage = 0x19BA74A5B5D; // Bool = false
    inline constexpr uintptr_t FFlagFixHeadShapeColorSlider = 0x19BA3A55D50; // Unknown = 
    inline constexpr uintptr_t FFlagFixIGMTabTransitions = 0x19B9FD86990; // Unknown = 
    inline constexpr uintptr_t FFlagFixInactiveChildStateForwarding = 0x19B9AF1A9D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixIosAuthServiceCredentialSheetBackends = 0x19BBC1C6050; // Unknown = 
    inline constexpr uintptr_t FFlagFixIosOtpAutofill = 0x19BBC386410; // Unknown = 
    inline constexpr uintptr_t FFlagFixIsConsoleCheckForSocialCarousel = 0x19B8C2E1FDD; // Bool = false
    inline constexpr uintptr_t FFlagFixJoinVoiceDelayedAFMInit = 0x19B9FD80E9D; // Bool = false
    inline constexpr uintptr_t FFlagFixLayeredSorting = 0x19B82BC955D; // Bool = false
    inline constexpr uintptr_t FFlagFixLimitedBundleResalePrerequisite = 0x19D85DC4350; // Unknown = 
    inline constexpr uintptr_t FFlagFixLocalizationOfMissingAgreementTitles = 0x19B859C99DD; // Bool = true
    inline constexpr uintptr_t FFlagFixLocalizationOfStudioTermsForVNGSKU = 0x19B859C9650; // Unknown = 
    inline constexpr uintptr_t FFlagFixLoginV2LandscapeLayout = 0x19B9AF19C90; // Unknown = 
    inline constexpr uintptr_t FFlagFixMediaGalleryOversized = 0x19BB1D98190; // Unknown = 
    inline constexpr uintptr_t FFlagFixMomentsExperienceFallback = 0x19B9ACB0AD0; // Unknown = 
    inline constexpr uintptr_t FFlagFixMomentsTabReactiveIXPRace = 0x19B857856D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixMoreSubMenuTitleFlash = 0x19BBCD729D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixNavBarStartupDuplicateAnim = 0x19B90642FDD; // Bool = false
    inline constexpr uintptr_t FFlagFixNavigationInsetsOnHiddenTabBar = 0x19B9ACB4990; // Unknown = 
    inline constexpr uintptr_t FFlagFixNonTruncatedText = 0x19B90643EDD; // Bool = false
    inline constexpr uintptr_t FFlagFixOffSaleCurrentlyWearingItemNavigation = 0x19B8578ADDD; // Bool = false
    inline constexpr uintptr_t FFlagFixOnBadgeAwardedError = 0x19BACFEBFDD; // Bool = false
    inline constexpr uintptr_t FFlagFixOneNameManyFacesDisconnectCrash = 0x19B9F92421D; // Bool = false
    inline constexpr uintptr_t FFlagFixPartyNudgeNilThunkWhenLeave = 0x19BA802EDD0; // Unknown = 
    inline constexpr uintptr_t FFlagFixPartyVoiceGetPermissions2 = 0x19B8C2E339D; // Bool = false
    inline constexpr uintptr_t FFlagFixPeekViewAnimationJitter = 0x19BA609C010; // Unknown = 
    inline constexpr uintptr_t FFlagFixPeoplePageCardTooltip = 0x19BBC387010; // Unknown = 
    inline constexpr uintptr_t FFlagFixPlainTextAutomaticSizeClippingText = 0x19BB6BB9DD0; // Unknown = 
    inline constexpr uintptr_t FFlagFixPlatformRestrictedHomeClobber = 0x19B9AF161D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixPlayerGuiSelectionBugOnPromptExit = 0x19B9EE0255D; // Bool = false
    inline constexpr uintptr_t FFlagFixPolicyStalePlayerUpdates = 0x19BB6BBCC90; // Unknown = 
    inline constexpr uintptr_t FFlagFixPromptGameInviteUIButtonScaling = 0x19B81E9F448; // Unknown = 
    inline constexpr uintptr_t FFlagFixPurchasingErrorCounter = 0x19D85DC8010; // Unknown = 
    inline constexpr uintptr_t FFlagFixReportAdInfoDuringRotation = 0x19BA8A01850; // Unknown = 
    inline constexpr uintptr_t FFlagFixReportButtonCutOff = 0x19B9FD86B1D; // Bool = false
    inline constexpr uintptr_t FFlagFixResaleDisplayPrice = 0x19D85DC21DD; // Bool = false
    inline constexpr uintptr_t FFlagFixSTUXShowingIncorrectly = 0x19BA5158890; // Unknown = 
    inline constexpr uintptr_t FFlagFixSafetyBubbleWidth = 0x19B9FDD8F95; // Bool = false
    inline constexpr uintptr_t FFlagFixSduiCardFocusNavScroll = 0x19B88C26590; // Unknown = 
    inline constexpr uintptr_t FFlagFixSduiEdpTtiPeekCategory = 0x19BC0545250; // Unknown = 
    inline constexpr uintptr_t FFlagFixSeamlessVoiceIntegrationWithPrivateVoice2 = 0x19B8C2E2B10; // Unknown = 
    inline constexpr uintptr_t FFlagFixSelectionWithWebViews = 0x19B9AF1AC90; // Unknown = 
    inline constexpr uintptr_t FFlagFixSettingshubImportOrder = 0x19BBC38269D; // Bool = false
    inline constexpr uintptr_t FFlagFixSignalFinishedOnError = 0x19B8FC33F5D; // Bool = false
    inline constexpr uintptr_t FFlagFixSpatialUICaptures = 0x19B8C2E1C10; // Unknown = 
    inline constexpr uintptr_t FFlagFixSquadTopBannerMemo = 0x19B90290A50; // Unknown = 
    inline constexpr uintptr_t FFlagFixTabletEDPNavBarVisibility = 0x19B90643810; // Unknown = 
    inline constexpr uintptr_t FFlagFixTimedOptionRefresh = 0x19D85DC51DD; // Bool = false
    inline constexpr uintptr_t FFlagFixToastNotificationRightPosition = 0x19B8188931D; // Bool = true
    inline constexpr uintptr_t FFlagFixUnifiedPurchaseResalePurchases = 0x19BA3A51390; // Unknown = 
    inline constexpr uintptr_t FFlagFixUnifiedUpsellCompletionModal = 0x19BAC836B5D; // Bool = false
    inline constexpr uintptr_t FFlagFixUnnecessaryPaddingInUnifiedPurchaseModal = 0x19B82E0F85D; // Bool = false
    inline constexpr uintptr_t FFlagFixUpsellModalUnevenLayout = 0x19BAC835EDD; // Bool = false
    inline constexpr uintptr_t FFlagFixUpsellVerificationToNavigateToOverlays = 0x19BBC38261D; // Bool = false
    inline constexpr uintptr_t FFlagFixUseDeviceOrientationNilViewportSize = 0x19B859C57D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixUserInfoSelection = 0x19B902935D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixUserInfoWidgetPlusBadge = 0x19BA6A3BA50; // Unknown = 
    inline constexpr uintptr_t FFlagFixUserRowCombinedName = 0x19B8C301210; // Unknown = 
    inline constexpr uintptr_t FFlagFixUsernameSelectionStuck = 0x19B90293390; // Unknown = 
    inline constexpr uintptr_t FFlagFixUsernameValidationAlreadyInUse = 0x19BA5534F10; // Unknown = 
    inline constexpr uintptr_t FFlagFixUsernameValidationBackendCriteria = 0x19B88C6189D; // Bool = false
    inline constexpr uintptr_t FFlagFixVRAvatarPlacement = 0x19B90646C9D; // Bool = false
    inline constexpr uintptr_t FFlagFixVRBottomBarAnalytics = 0x19BAEB7969D; // Bool = false
    inline constexpr uintptr_t FFlagFixVirtualizedGridNumItems = 0x19BBC38F8D0; // Unknown = 
    inline constexpr uintptr_t FFlagFixWindowDragError = 0x19D81683B90; // Unknown = 
    inline constexpr uintptr_t FFlagFixWindowDragStaleConnection = 0x19D81680190; // Unknown = 
    inline constexpr uintptr_t FFlagFlyoutDisablePremiumEntrypoint1 = 0x19BB6BBE2DD; // Bool = true
    inline constexpr uintptr_t FFlagFlyoutDisallowAlternativeEntryOnProfileEntryEnabled = 0x19BA4610B50; // Unknown = 
    inline constexpr uintptr_t FFlagFlyoutEnableGiftcardsWithRedeem = 0x19BB6BB465D; // Bool = true
    inline constexpr uintptr_t FFlagFlyoutFacepileEnableProfileEntry = 0x19BA4615750; // Unknown = 
    inline constexpr uintptr_t FFlagFlyoutHamburgerEnableProfileEntry = 0x19BA626ED9D; // Bool = true
    inline constexpr uintptr_t FFlagFlyoutHideFriendsHeader = 0x19B8FA1DC5D; // Bool = false
    inline constexpr uintptr_t FFlagFlyoutNavigationInMarketplace = 0x19B9AF14B10; // Unknown = 
    inline constexpr uintptr_t FFlagFlyoutRemoveAddSessionInfo = 0x19B8579BA75; // Bool = false
    inline constexpr uintptr_t FFlagFlyoutResolveItemContextOnActivation = 0x19BBF7C3EF5; // Bool = false
    inline constexpr uintptr_t FFlagFlyoutShowFriendsSortForCurrentVariant = 0x19BA46145D0; // Unknown = 
    inline constexpr uintptr_t FFlagFlyoutSidePanelTradesEntry = 0x19D7C7CEAD0; // Unknown = 
    inline constexpr uintptr_t FFlagFlyoutUseOpenHook = 0x19B85788E5D; // Bool = false
    inline constexpr uintptr_t FFlagFocusRootUseHooks = 0x19B8F90899D; // Bool = false
    inline constexpr uintptr_t FFlagForceAegisPhase2Modal = 0x19B9026955D; // Bool = false
    inline constexpr uintptr_t FFlagForceEnableArgoPartyChanges7 = 0x19B8FDECD9D; // Bool = false
    inline constexpr uintptr_t FFlagForceEnableExpChatNewSystemMessages = 0x19B8FDEC210; // Unknown = 
    inline constexpr uintptr_t FFlagForceEnableLuckyRecommendation = 0x19B8C2E3BD0; // Unknown = 
    inline constexpr uintptr_t FFlagForceEnablePartyCoordinationUiChanges3 = 0x19B8FDEDBD0; // Unknown = 
    inline constexpr uintptr_t FFlagForceEnableQueueAutoJoinNewServer2 = 0x19B8FDED39D; // Bool = false
    inline constexpr uintptr_t FFlagForceEnableQueueJoinNewServerButton2 = 0x19B8FDED5DD; // Bool = false
    inline constexpr uintptr_t FFlagForceEnableSocialCarouselPartyPage5 = 0x19B8FDEF11D; // Bool = false
    inline constexpr uintptr_t FFlagForceEnableSquad = 0x19B8C2E3CD0; // Unknown = 
    inline constexpr uintptr_t FFlagForceEnableSquadRegroup = 0x19B8C301850; // Unknown = 
    inline constexpr uintptr_t FFlagForceGetGameIconsFromThumbnailsDeliveryApi = 0x19B88C25A5D; // Bool = true
    inline constexpr uintptr_t FFlagForceReportAnythingAnnotationEnabled = 0x19B9AF1EE90; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationActionEmphasisStatusIndicator = 0x19B9AF1C490; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationAvatarBeta3 = 0x19B9AF1AED0; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationAvatarBindableUserId = 0x19B9AF11510; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationAvatarIncludeProfileFrame = 0x19B9AF18E90; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationBadgeBetaUpdate3 = 0x19B9CB70ADD; // Bool = false
    inline constexpr uintptr_t FFlagFoundationBaseMenuContentSizing = 0x19B9AF16D50; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationBaseMenuSubmenuMaxHeight = 0x19B9AF1CB10; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationBottomSheetFixHeightCap = 0x19B9AF1E2D0; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationBottomSheetGestureInteractionSink = 0x19B9AF13910; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationBottomSheetOnSnapPointChanged = 0x19B9AF15350; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationBottomSheetScrollAtMaxTolerance = 0x19B9AF12D90; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationButtonLabelTypography = 0x19B9AF19DD0; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationCheckboxBeta = 0x19B9AF1EC90; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationCoachmarkPressedOutside = 0x19B9CB7E1DD; // Bool = false
    inline constexpr uintptr_t FFlagFoundationDateTimePickerBetaUpdate = 0x19B9CB7049D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationDateTimePickerDSTFix = 0x19B82DBA2D0; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationDialogBetaUpdate = 0x19B9CB7311D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationDisableTokenScaling2 = 0x19B9AF1FC50; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationDropdownSelectionProps = 0x19B9AF182D0; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationDropdownSizeGap = 0x19B9AF19A10; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationFixTabsBorderPosition = 0x19B9CB7529D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationFixTabsFitBorderWidth2 = 0x19B9AF1F4D0; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationGuiObjectInputSinkProperty = 0x19B9AF1F190; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationImageContentSupport = 0x19B9AF1F350; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationIncludeSpaceRequiredLabel = 0x19B9CB7179D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationInputGroup = 0x19B9AF1ED50; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationInteractableSecondaryActivated = 0x19B9AF1C2D0; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationInternalInputBeta2 = 0x19B9AF1D190; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationListItemDecoupledInput = 0x19B9CB7285D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationListItemTypographySpacing = 0x19B9CB7F11D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationListStableContextValue = 0x19B9CB7751D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationNumberInputBeta = 0x19B9AF10D50; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationNumberInputOnTextChanged = 0x19B9AF19190; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationNumberInputScrubCallbackProps = 0x19B9CB7ED5D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationOptionSelectorGroupBeta = 0x19B9CB7ACDD; // Bool = false
    inline constexpr uintptr_t FFlagFoundationOptionSelectorGroupFixes = 0x19B9AF16810; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationOverlayResilientMainGui = 0x19B9AF14910; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationPopoverClickOutsideInGuiShadow = 0x19B9CB7E89D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationPopoverContentAnchorFix = 0x19B9CB7B69D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationPopoverPluginAnchorRefresh = 0x19B9CB7BD9D; // Bool = true
    inline constexpr uintptr_t FFlagFoundationPopoverPluginOverlayMeasurement2 = 0x19B9AF10A90; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationPopoverRecomputeContentSize = 0x19B9CB7C81D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationProgressBarBetaUpdate = 0x19B9CB7ED1D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationProgressCircleRoundCaps = 0x19B9CB7F29D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationRadioBeta = 0x19B9AF1DBD0; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationRemoveSecondUIDDFromScrubbableTextboxes = 0x19B9AF139D0; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationSegmentedControlBeta = 0x19B9CB7B75D; // Bool = true
    inline constexpr uintptr_t FFlagFoundationSkeletonCommonShimmerToken = 0x19B9CB7455D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationSliderAsSeenOnTV = 0x19B9AF1BD50; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationSliderOffloadDraggingMath = 0x19B9AF172D0; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationStableContextValues = 0x19B9CB7E49D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationStatusIndicatorVariantExperiment2 = 0x19B945A4215; // Bool = false
    inline constexpr uintptr_t FFlagFoundationStyleSheetRefCounting = 0x19B9AF1D550; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationStylingOnSignUp = 0x19B9ACBE310; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationStylingOnSignUp3 = 0x19B9ACBDE50; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationThemeName = 0x19B9AF1D090; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationToggleBetaUpdate = 0x19B98E916B0; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationTokenOverrides2 = 0x19B9AF1AB10; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationTooltipBeta = 0x19B9CB75E1D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationTooltipPressedOutside = 0x19B9CB7B45D; // Bool = false
    inline constexpr uintptr_t FFlagFoundationUnifiedScrimScrolling = 0x19B9CB7D4DD; // Bool = false
    inline constexpr uintptr_t FFlagFoundationUsePath2DSpinner = 0x19B9AF1E810; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationViewMemoizationChanges = 0x19B9AF11F90; // Unknown = 
    inline constexpr uintptr_t FFlagFoundationWidgetManagerSnapshotFlush = 0x19B9CB7AA1D; // Bool = false
    inline constexpr uintptr_t FFlagFriendCarouselHas10ftPolicies = 0x19B9026745D; // Bool = false
    inline constexpr uintptr_t FFlagFriendRequestModalIxpEnabled = 0x19BA6078150; // Unknown = 
    inline constexpr uintptr_t FFlagFriendRequestModalRevampV4 = 0x19BA6077E10; // Unknown = 
    inline constexpr uintptr_t FFlagFriendRequestNicknames = 0x19BACFD86D0; // Unknown = 
    inline constexpr uintptr_t FFlagFriendRequestNicknamesUIBugFixes = 0x19B90115BDD; // Bool = false
    inline constexpr uintptr_t FFlagFriendRequestNicknamesV9 = 0x19BACFD5510; // Unknown = 
    inline constexpr uintptr_t FFlagFriendSortedByPresenceSignalsImplementation_v2 = 0x19B85A50695; // Bool = false
    inline constexpr uintptr_t FFlagFriendsActivityFeedEnabled = 0x19BA59B3610; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsActivityFeedFetchItemNames = 0x19B9F187AED; // Bool = true
    inline constexpr uintptr_t FFlagFriendsCarouselProfileFrameEnabled = 0x19BA2EF6795; // Bool = false
    inline constexpr uintptr_t FFlagFriendsCarouselUseFindFriendsOnDesktop = 0x19BACFDF490; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsCarouselUseFindFriendsOnDesktop_v2 = 0x19BACFDE090; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsChatConversationListFadeScrollbar = 0x19BA6B3905D; // Bool = false
    inline constexpr uintptr_t FFlagFriendsChatConversationListShowScrollBar = 0x19BACFDA2DD; // Bool = true
    inline constexpr uintptr_t FFlagFriendsChatEnableConversationConsent = 0x19BB6BBEEDD; // Bool = true
    inline constexpr uintptr_t FFlagFriendsChatEnforceInputCharacterLimit = 0x19BA6B3BF1D; // Bool = false
    inline constexpr uintptr_t FFlagFriendsChatFacePileGroupPresence = 0x19BA6B3B190; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsChatNavIconSizeFixEnabled = 0x19B859C95D0; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsChatOsaSystemMessage = 0x19BACFDB510; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsChatPlaceholderRenameFix = 0x19B8C305E1D; // Bool = true
    inline constexpr uintptr_t FFlagFriendsChatRefreshListForNewConversation = 0x19BA74A371D; // Bool = false
    inline constexpr uintptr_t FFlagFriendsCountDataHydrationMigrationEnabled = 0x19BA59B8550; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsEmptyStateIllustrationTheming = 0x19BBF820208; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsMenuDummyLoadingFriendsFixV3 = 0x19B8C306390; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsMenuUseProfileFrameThumbnail = 0x19BADF9EC5D; // Bool = false
    inline constexpr uintptr_t FFlagFriendsPageAlwaysOpenPPV = 0x19BA59BE790; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsPageUnifiedOpenProfileLogic = 0x19BA59B441D; // Bool = false
    inline constexpr uintptr_t FFlagFriendsPageUserListEnabled = 0x19BA59B5ED0; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsPageUserListEnabled_v2 = 0x19BA59BF090; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsPageViewBtnEnabled = 0x19B8276616D; // Bool = false
    inline constexpr uintptr_t FFlagFriendsPageViewBtnWidth = 0x19B9229DAA0; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsSignalMigrationTelemetry = 0x19BACFD8CD0; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsSignalMigrationTelemetry_v1 = 0x19BACFD0A90; // Unknown = 
    inline constexpr uintptr_t FFlagFriendsStoreSortOnlineFriendsByRank = 0x19BA59BC410; // Unknown = 
    inline constexpr uintptr_t FFlagFriendshipNotifsUseSendrEnabledForAll = 0x19BACFEB71D; // Bool = false
    inline constexpr uintptr_t FFlagFriendshipNotifsUseSendrExperiment = 0x19B8DD81290; // Unknown = 
    inline constexpr uintptr_t FFlagFriendshipNotifsUseSendrExperiment_v2 = 0x19BACFEB95D; // Bool = false
    inline constexpr uintptr_t FFlagFriendshipNotifsUseSendrExperiment_v3 = 0x19B8C30B410; // Unknown = 
    inline constexpr uintptr_t FFlagFullscreenElementsIgnoreSafeArea = 0x19BBCD72390; // Unknown = 
    inline constexpr uintptr_t FFlagFullscreenTitleBarInjectGameServices = 0x19BAEB7585D; // Bool = false
    inline constexpr uintptr_t FFlagGameInviteModalAnalyticsEmptyEventContextFix = 0x19D8952FF50; // Unknown = 
    inline constexpr uintptr_t FFlagGameInviteModalIncludeLinkIdInShareButton = 0x19D89523950; // Unknown = 
    inline constexpr uintptr_t FFlagGameInviteModalUnlockMouse = 0x19B8C304BDD; // Bool = true
    inline constexpr uintptr_t FFlagGameInviteOpenModalWithoutBlockingOnCanPrompt = 0x19B8C304ADD; // Bool = true
    inline constexpr uintptr_t FFlagGameJoinCardOnBeforeJoinCallback = 0x19BA6796A1D; // Bool = false
    inline constexpr uintptr_t FFlagGameJoinTimeoutChatAttemptEnabled = 0x19B8C30BB5D; // Bool = true
    inline constexpr uintptr_t FFlagGameSettingsCameraModeFixEnabled = 0x19BC0546490; // Unknown = 
    inline constexpr uintptr_t FFlagGameTileMigrateOffLegacyPresence = 0x19B88C40CD0; // Unknown = 
    inline constexpr uintptr_t FFlagGamepadIconSupportCheck = 0x19B88C6119D; // Bool = false
    inline constexpr uintptr_t FFlagGamepadNavigationDialogABTest = 0x19B9FDDCA15; // Bool = false
    inline constexpr uintptr_t FFlagGamepadNavigationDialogABTest2 = 0x19D8168BD90; // Unknown = 
    inline constexpr uintptr_t FFlagGateAbuseReportInExpSceneSelectionOnIXP = 0x19BB7F4B310; // Unknown = 
    inline constexpr uintptr_t FFlagGateEducationalPopupVisibilityViaGUAC = 0x19B9ACBE950; // Unknown = 
    inline constexpr uintptr_t FFlagGateLeaderboardPlayerDropdownViaGUAC = 0x19B9ACB6550; // Unknown = 
    inline constexpr uintptr_t FFlagGenerateLinkWithChannel = 0x19B8C30BA90; // Unknown = 
    inline constexpr uintptr_t FFlagGenericAbuseReportingGranularExports = 0x19B8C30C9DD; // Bool = true
    inline constexpr uintptr_t FFlagGetFFlagCountryCodeBoldPrefixEnabled = 0x19BBC1C8F10; // Unknown = 
    inline constexpr uintptr_t FFlagGetFFlagLuaAppChallengeDialogContainerPageEnabled = 0x19B90642D5D; // Bool = false
    inline constexpr uintptr_t FFlagGetGameIconsFromThumbnailsDeliveryApiIxp = 0x19B88C2581D; // Bool = false
    inline constexpr uintptr_t FFlagGetHumanoidDescription = 0x19BA6A3E2D0; // Unknown = 
    inline constexpr uintptr_t FFlagGetHumanoidDescriptionUpdates = 0x19BBB7F2150; // Unknown = 
    inline constexpr uintptr_t FFlagGetHumanoidDescriptionUpdatesV2A = 0x19BBBE59ED0; // Unknown = 
    inline constexpr uintptr_t FFlagGetHumanoidDescriptionUpdatesV2B = 0x19BAC87FA1D; // Bool = false
    inline constexpr uintptr_t FFlagGetHumanoidDescriptionUpdatesV2E2 = 0x19B8C30BD9D; // Bool = true
    inline constexpr uintptr_t FFlagGlobalFocusFailureTelemetry = 0x19B8F90889D; // Bool = false
    inline constexpr uintptr_t FFlagGlobalTextChatAddPlaySessionField = 0x19BA5150B5D; // Bool = false
    inline constexpr uintptr_t FFlagGranularExportsBucket = 0x19B90295690; // Unknown = 
    inline constexpr uintptr_t FFlagGridHomeUserInfoUseProfileFrameThumbnail = 0x19B948111D0; // Unknown = 
    inline constexpr uintptr_t FFlagGuacAppPolicyDisableSignupCheckbox = 0x19BB6BB2FD0; // Unknown = 
    inline constexpr uintptr_t FFlagGuacCanRenderTransferOnProfile = 0x19B8C2E2FD0; // Unknown = 
    inline constexpr uintptr_t FFlagGuacDisableBlackbirdEntrypoints = 0x19BB6BB4FDD; // Bool = true
    inline constexpr uintptr_t FFlagGuacStickyShortcutBarEnabled = 0x19BBCD75DD0; // Unknown = 
    inline constexpr uintptr_t FFlagGuardVoiceInExpUpsellVariant = 0x19B9F18F905; // Bool = true
    inline constexpr uintptr_t FFlagHeadRefinementFacialAnimationToggle = 0x19BA3A5BE1D; // Bool = false
    inline constexpr uintptr_t FFlagHeadRefinementFacialAnimationToggle4 = 0x19BA3A54C9D; // Bool = false
    inline constexpr uintptr_t FFlagHelpPageIXPExposure = 0x19BBF254E5D; // Bool = true
    inline constexpr uintptr_t FFlagHelpPageIXPExposure3 = 0x19BAC87331D; // Bool = false
    inline constexpr uintptr_t FFlagHelpPageMountVR = 0x19BBF25C85D; // Bool = true
    inline constexpr uintptr_t FFlagHelpPageMountVR3 = 0x19BAC8731DD; // Bool = false
    inline constexpr uintptr_t FFlagHiddenFriendsSortHeaderAddSubTabDependency = 0x19BA461AC90; // Unknown = 
    inline constexpr uintptr_t FFlagHiddenFriendsSortHeaderRemoveFlyoutDependency = 0x19B9ACB4390; // Unknown = 
    inline constexpr uintptr_t FFlagHideConnectPageWebViewItemsForVRV2 = 0x19BC0541090; // Unknown = 
    inline constexpr uintptr_t FFlagHideContextualButtonBasedOnStateForVR = 0x19BC0544950; // Unknown = 
    inline constexpr uintptr_t FFlagHideDevSubsPriceIfSubscribed = 0x19B9ACB36D0; // Unknown = 
    inline constexpr uintptr_t FFlagHideLaunchAtStartupMac = 0x19BA59BB8D0; // Unknown = 
    inline constexpr uintptr_t FFlagHideLookDiscountPercentWithIneligibleItems = 0x19D85DC2DDD; // Bool = false
    inline constexpr uintptr_t FFlagHideNotificationIconForVR = 0x19B8FA15690; // Unknown = 
    inline constexpr uintptr_t FFlagHidePeoplePageInviteFriends = 0x19B9ACBDC1D; // Bool = false
    inline constexpr uintptr_t FFlagHidePremiumIconography = 0x19BA6A3CB10; // Unknown = 
    inline constexpr uintptr_t FFlagHideShortcutsOnReportDropdown = 0x19B9FD8F815; // Bool = false
    inline constexpr uintptr_t FFlagHideShortcutsWhileIemDropdownActive = 0x19BA7FC1F28; // Unknown = 
    inline constexpr uintptr_t FFlagHideVoiceChatSelectorForFae_AEGIS2 = 0x19B9FD8B6DD; // Bool = false
    inline constexpr uintptr_t FFlagHighlightModePreciseSelectionEnabled3 = 0x19B8C30D45D; // Bool = true
    inline constexpr uintptr_t FFlagHomePYMKUseProfileFrameThumbnail = 0x19BA005E6AD; // Bool = false
    inline constexpr uintptr_t FFlagHomePagePromptsHandlerEnabled = 0x19BC0541310; // Unknown = 
    inline constexpr uintptr_t FFlagHomePhoneVerificationUpsellNewCopy = 0x19D8244A670; // Unknown = 
    inline constexpr uintptr_t FFlagHomepagePromptsPaddingFix = 0x19BC0545090; // Unknown = 
    inline constexpr uintptr_t FFlagIAPExperienceEnableBestValueBadge = 0x19BAC83009D; // Bool = false
    inline constexpr uintptr_t FFlagIAPExperienceEnableMultiDisplayUpsellV3 = 0x19BAC830A5D; // Bool = false
    inline constexpr uintptr_t FFlagIAPExperienceUseUpsellBadgeHelper = 0x19BAC830DDD; // Bool = false
    inline constexpr uintptr_t FFlagIBEnableCollectiblesSystemSupport = 0x19B9F0A111D; // Bool = false
    inline constexpr uintptr_t FFlagIBGateUGC4ACollectibleAssetsBundles1 = 0x19B9F0A4590; // Unknown = 
    inline constexpr uintptr_t FFlagIDVGuardStartPollingAfterUnmount = 0x19B8FC3A1DD; // Bool = false
    inline constexpr uintptr_t FFlagIEMFocusNavPeoplePageToButtons = 0x19B9ACB27DD; // Bool = false
    inline constexpr uintptr_t FFlagIEMFocusNavSupportNewButtons2 = 0x19BAC8737D0; // Unknown = 
    inline constexpr uintptr_t FFlagIEMReportScrollingFix = 0x19BB7F45CD0; // Unknown = 
    inline constexpr uintptr_t FFlagIEMSettingsGroups = 0x19B9FD867D5; // Bool = false
    inline constexpr uintptr_t FFlagIEMSettingsGroups709 = 0x19B9FD86810; // Unknown = 
    inline constexpr uintptr_t FFlagIEMSettingsLogExposureIXPFlags = 0x19BACE9B350; // Unknown = 
    inline constexpr uintptr_t FFlagIEMSettingsPageDisplaying = 0x19B8C30D990; // Unknown = 
    inline constexpr uintptr_t FFlagIEMTabFocusNav = 0x19B9ACB5F1D; // Bool = false
    inline constexpr uintptr_t FFlagIEMTabFocusNav2 = 0x19B9ACB9ADD; // Bool = false
    inline constexpr uintptr_t FFlagIGMAlwaysResetGfxLv5 = 0x19B9FD8CC1D; // Bool = false
    inline constexpr uintptr_t FFlagIGMChangeCapturesToGallery = 0x19B998BD22D; // Bool = false
    inline constexpr uintptr_t FFlagIGMChangeGalleryHeaderIcon = 0x19B9FDDAE95; // Bool = false
    inline constexpr uintptr_t FFlagIGMEnableGFXReset = 0x19B9FD8D050; // Unknown = 
    inline constexpr uintptr_t FFlagIGMGamepadSelectionHistory = 0x19D81687F9D; // Bool = false
    inline constexpr uintptr_t FFlagIGMResetGfxLv5Only = 0x19B9FD8CBDD; // Bool = false
    inline constexpr uintptr_t FFlagIGMResetGfxQuality = 0x19B9FD8CB1D; // Bool = false
    inline constexpr uintptr_t FFlagIGMRevertGfxLv5Only = 0x19B9FD8CB9D; // Bool = false
    inline constexpr uintptr_t FFlagIGMRevertGfxQuality = 0x19B9FD8CB5D; // Bool = false
    inline constexpr uintptr_t FFlagIGMSelectionGroup = 0x19BACE9DF9D; // Bool = false
    inline constexpr uintptr_t FFlagIXPServiceWrapperWaitRefactor = 0x19BBCD76310; // Unknown = 
    inline constexpr uintptr_t FFlagIconHostSetZIndexToDefault = 0x19B82BC9FDD; // Bool = false
    inline constexpr uintptr_t FFlagImmutableJoinDictionariesUseTableClone = 0x19B8C2E5290; // Unknown = 
    inline constexpr uintptr_t FFlagImportVirtualCursorToUA = 0x19BA59BE450; // Unknown = 
    inline constexpr uintptr_t FFlagImproveIllegalContentReportingLinkLook = 0x19BA3A54610; // Unknown = 
    inline constexpr uintptr_t FFlagImprovePageTitleCloseButton = 0x19BACE9DEDD; // Bool = false
    inline constexpr uintptr_t FFlagImproveSearchSelectionUX2 = 0x19B9029F350; // Unknown = 
    inline constexpr uintptr_t FFlagInAppBugReporterIxpBypass = 0x19B90293D50; // Unknown = 
    inline constexpr uintptr_t FFlagInAppBugReporterIxpEnabled = 0x19B90293CD0; // Unknown = 
    inline constexpr uintptr_t FFlagInExperienceAddPhoneViewNewCopy = 0x19B8C30A410; // Unknown = 
    inline constexpr uintptr_t FFlagInExperienceAvatarSwitcherPlaceFilter = 0x19B88C4F8D0; // Unknown = 
    inline constexpr uintptr_t FFlagInExperienceContainerAppLinking = 0x19B8C30C090; // Unknown = 
    inline constexpr uintptr_t FFlagInExperienceContainerRespectUserTheme = 0x19B8C30D19D; // Bool = true
    inline constexpr uintptr_t FFlagInExperienceContainerScreenSizeReducer = 0x19B8C30C750; // Unknown = 
    inline constexpr uintptr_t FFlagInExperienceInterventionApp = 0x19BACFEAF9D; // Bool = false
    inline constexpr uintptr_t FFlagInExperiencePhoneUpsellNewCopy = 0x19B8C30AF1D; // Bool = true
    inline constexpr uintptr_t FFlagInExperienceReportClosingBugfix = 0x19B9ACB4150; // Unknown = 
    inline constexpr uintptr_t FFlagInExperienceRequestProfileSettings = 0x19BA7FC4138; // Unknown = 
    inline constexpr uintptr_t FFlagInExperienceShopFtuxTooltip = 0x19BABC10AD5; // Bool = true
    inline constexpr uintptr_t FFlagInExperienceUseAppStyleProvider = 0x19B9ACB33DD; // Bool = false
    inline constexpr uintptr_t FFlagInExperienceUserProfileSettingsEnabled = 0x19BA7FC7428; // Unknown = 
    inline constexpr uintptr_t FFlagInExperienceUserProfileSettingsEnabled_v3 = 0x19BACFE6E1D; // Bool = false
    inline constexpr uintptr_t FFlagInGameLargerRobuxUpsellEnabled = 0x19D85DCB59D; // Bool = false
    inline constexpr uintptr_t FFlagInGameLargerRobuxUpsellIXP = 0x19D85DCF51D; // Bool = false
    inline constexpr uintptr_t FFlagInGameLargerRobuxUpsellIXPRolledOut = 0x19D85DCA7DD; // Bool = false
    inline constexpr uintptr_t FFlagIncludeWaitingForPartyInCondition = 0x19BA679509D; // Bool = false
    inline constexpr uintptr_t FFlagIncreaseLegacyPeopleRowButtonSize = 0x19BA4E9DE9D; // Bool = false
    inline constexpr uintptr_t FFlagIncreaseLoadingScreenOrder = 0x19B9AF14AD0; // Unknown = 
    inline constexpr uintptr_t FFlagIncreaseMarketplaceContentHeight = 0x19B9AF14850; // Unknown = 
    inline constexpr uintptr_t FFlagIncreaseUtilityRowTextSizeConsole = 0x19BA515A510; // Unknown = 
    inline constexpr uintptr_t FFlagInitializeAutocompleteOnlyIfEnabled = 0x19D81FAB820; // Unknown = 
    inline constexpr uintptr_t FFlagInjectAnalyticsService = 0x19B90293DD0; // Unknown = 
    inline constexpr uintptr_t FFlagInlineRichTextUseWebViewService = 0x19B9AF191D0; // Unknown = 
    inline constexpr uintptr_t FFlagInlineSurveyBranching = 0x19B8C30C3DD; // Bool = true
    inline constexpr uintptr_t FFlagInlineSurveyChoiceTextEntry = 0x19B8C30C49D; // Bool = true
    inline constexpr uintptr_t FFlagInlineSurveyEnhancements = 0x19BBB317F10; // Unknown = 
    inline constexpr uintptr_t FFlagInlineSurveyEnhancements2 = 0x19B8C30C21D; // Bool = true
    inline constexpr uintptr_t FFlagInlineSurveyFocusRoot = 0x19BB7F4869D; // Bool = false
    inline constexpr uintptr_t FFlagInlineSurveyOnInExpReport = 0x19BB7F41C50; // Unknown = 
    inline constexpr uintptr_t FFlagInlineSurveyPartialResponse = 0x19D812EE588; // Unknown = 
    inline constexpr uintptr_t FFlagInspectAndBuyFixStyleLink = 0x19D81681150; // Unknown = 
    inline constexpr uintptr_t FFlagIntegrateDiscountsWithEDP = 0x19B9AF1C750; // Unknown = 
    inline constexpr uintptr_t FFlagIntegrateDiscountsWithEDP2 = 0x19B9AF1C290; // Unknown = 
    inline constexpr uintptr_t FFlagIntegratePhoneUpsellJoinVoice = 0x19B8C30ADDD; // Bool = true
    inline constexpr uintptr_t FFlagIntegrateTraversalHistoryInSideSheet2 = 0x19B9ACBE4DD; // Bool = false
    inline constexpr uintptr_t FFlagIntegrationsChromeShortcutTelemetry = 0x19BA7FC0DF8; // Unknown = 
    inline constexpr uintptr_t FFlagInternationalNamesEnabledForAll = 0x19B90642690; // Unknown = 
    inline constexpr uintptr_t FFlagIntroduceMetricsLegacyUpsell = 0x19BAC832C1D; // Bool = false
    inline constexpr uintptr_t FFlagInviteListRerank = 0x19B99718290; // Unknown = 
    inline constexpr uintptr_t FFlagIsPublishOnBuildRevert = 0x19BAD28FA5D; // Bool = false
    inline constexpr uintptr_t FFlagIsSquadCoordinationExperienceJoinExperimentExposureEnabled = 0x19B8FDEDA50; // Unknown = 
    inline constexpr uintptr_t FFlagIsSquadLobbySessionEnabled = 0x19B8FDEDA90; // Unknown = 
    inline constexpr uintptr_t FFlagIssueTrackerUseFoundationIcon = 0x19BBC1CCF10; // Unknown = 
    inline constexpr uintptr_t FFlagItemImpressionsAddGameMetadata = 0x19B88C2E410; // Unknown = 
    inline constexpr uintptr_t FFlagJoinCardAgeCheckUpsell_V3 = 0x19B8C3022D0; // Unknown = 
    inline constexpr uintptr_t FFlagJoinGameCardPassThroughUniversePlaceInfoFromFriendsCarousel = 0x19BACFD0390; // Unknown = 
    inline constexpr uintptr_t FFlagJoinGameCardViewProfileNavigateToProfilePlatform = 0x19B85A50685; // Bool = false
    inline constexpr uintptr_t FFlagJoinWithoutMicPermissions3 = 0x19BACFD6C90; // Unknown = 
    inline constexpr uintptr_t FFlagKISAUserAgreementsRedesign = 0x19B945A0D50; // Unknown = 
    inline constexpr uintptr_t FFlagKeepDarkThemeOverrideWhenLoggedOut = 0x19B9AF16090; // Unknown = 
    inline constexpr uintptr_t FFlagKeepSideSheetOpenFromGrid = 0x19BA4E9AA1D; // Bool = false
    inline constexpr uintptr_t FFlagLazyInitiateExperienceLanguageSwitcher = 0x19B9FD8DDDD; // Bool = false
    inline constexpr uintptr_t FFlagLazyPerfStatsInit = 0x19BACE7AB1D; // Bool = false
    inline constexpr uintptr_t FFlagLeaderstatsWithASideOfClient = 0x19BAD281B5D; // Bool = false
    inline constexpr uintptr_t FFlagLeaveActionChromeShortcutTelemetry = 0x19B9FDD1855; // Bool = false
    inline constexpr uintptr_t FFlagLeaveChromeShortcutTelemetry = 0x19B9FDD18D5; // Bool = false
    inline constexpr uintptr_t FFlagLeaveSquadIfChatDisabled = 0x19BA802C050; // Unknown = 
    inline constexpr uintptr_t FFlagLocalUserGameVoteCounterReducer = 0x19B90269750; // Unknown = 
    inline constexpr uintptr_t FFlagLocalizeGameplayPaused = 0x19B9F0A715D; // Bool = false
    inline constexpr uintptr_t FFlagLocalizeMenuNavigationToggleDialog = 0x19B9FDDCA95; // Bool = false
    inline constexpr uintptr_t FFlagLogAllGuacRead = 0x19BAF803CFD; // Bool = false
    inline constexpr uintptr_t FFlagLogFirstGuacRead = 0x19BAF8029BD; // Bool = false
    inline constexpr uintptr_t FFlagLogInputTypeChangedTvRemote1 = 0x19BBCCC90FD; // Bool = false
    inline constexpr uintptr_t FFlagLogKeyboardFocusModeEntered = 0x19B9064E69D; // Bool = false
    inline constexpr uintptr_t FFlagLogSessionOnOrientationChange = 0x19BA609BCD0; // Unknown = 
    inline constexpr uintptr_t FFlagLoggingGamepadOpenExpControlsMenu = 0x19BAD28025D; // Bool = false
    inline constexpr uintptr_t FFlagLoggingRethrowUsingError = 0x19B8C2EA01D; // Bool = false
    inline constexpr uintptr_t FFlagLoginV2FullFlowDevOverride = 0x19B9AF19C10; // Unknown = 
    inline constexpr uintptr_t FFlagLogoutPhoneVerificationUpsellCopy = 0x19B8DD82210; // Unknown = 
    inline constexpr uintptr_t FFlagLogoutPhoneVerificationUpsellCopy_v3 = 0x19B8C309790; // Unknown = 
    inline constexpr uintptr_t FFlagLowCogsBannerExperiment = 0x19B88C4EF5D; // Bool = false
    inline constexpr uintptr_t FFlagLowCogsBannerInfoIcon = 0x19BAC83249D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAbuseReportAnalyticsHasLaunchData = 0x19B9F29649D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAccountSecurityPromptEnabled = 0x19B90648290; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppAccountSecurityPromptRolloutEnabledForAll = 0x19B9029EFD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppAddAnalyticsDataToSeeAllImpressions = 0x19B88C4DDD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppAddCarouselAmpUpsellAccessResponses = 0x19B902697DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAddComponentTypeToSearchImpressions2 = 0x19BC05491DD; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppAddIgrsImages = 0x19B88C2161D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAddPlaceholderRecoveryCounter = 0x19B90269B9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAddRequestIdToRfySignalApportioning = 0x19B88C43E1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAddSeeAllFlagToGameDetailReferral = 0x19B88C4F4DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAddSessionIdToUserSignals = 0x19B88C26450; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppAddSocialLinkClickTelemetryToEdp = 0x19B88C2661D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAddSocialLinkImpressionsTelemetryToEdp = 0x19BA6F6003D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAddSortDataToSocialCarouselClicks = 0x19B88C2B71D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAddTestIdsForArrow = 0x19B88C24DD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppAddUniverseIdToGameDetailsEvents = 0x19B88C43410; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppAddVideoIneligiblePlayabilityStatus = 0x19B88C2135D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAdjustOverflowMenuVisual = 0x19B88C2C81D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAlignHeroUnitBottomRowCtaButton = 0x19BAC82A3DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppApportioningInCollectionViews = 0x19BAFB67B10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppApportioningInCollectionViews2 = 0x19B857857DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAttachChallengeInterceptor = 0x19B9029309D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppAutocompleteIXPConfig4 = 0x19B90294FD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppAvoidPushUpsellConflicts = 0x19B90295210; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppBadgeDetailsEnabled6 = 0x19B88C2221D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppBadgeDetailsLogExposure = 0x19B88C222DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppBadgesSeeAllEnabled4 = 0x19B88C218D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppBadgesSeeAllLogExposure = 0x19B88C21490; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppBlockedUnplayableError = 0x19B88C2B15D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppBottomAlignDetailsHeaderInfoFrame = 0x19BA6093A90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppBroadenVideoAnalytics = 0x19BC0540710; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppChallengeCaptchaV2ForceWebViewVisible = 0x19B90292510; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppChallengeDialogEventReceiverEnabled = 0x19B90642BDD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppChallengeDialogFetchDialogConditionally = 0x19B90640C90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppChallengeDisableForceWebViewVisible = 0x19B90292B50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppChallengeTurnstileForceWebViewVisible = 0x19B90292250; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppChartsActiveFilterChips = 0x19BC05485DD; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppChartsActiveFilterChips3 = 0x19BC0542B1D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppChartsAppPage = 0x19B88C2865D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppChartsAppUseHoverTile = 0x19B825F97DD; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppChartsFilterOptionTextTag = 0x19BC0540250; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppChartsFilterOptionTextTag2 = 0x19BC0543450; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppChartsPreloadingEnabled = 0x19B9026AF9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppChartsResetFetchingStatusOnFilterChange = 0x19BC054485D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppChartsResetFetchingStatusOnFilterChange2 = 0x19BC0547490; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCheckboxFeedbackFormTitleTextWrapping = 0x19BA6094110; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppClampBannerPaddingToViewport = 0x19B88C21FDD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppCompositionAlways4 = 0x19BA55389D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCompositionAppChat = 0x19B9AF1A4D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCompositionAvatar = 0x19B9AF1A550; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCompositionCharts = 0x19B9AF1A510; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCompositionFixDetailClip = 0x19BA609A650; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCompositionFixEmphasisApportioning = 0x19B90269AD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCompositionHome = 0x19B9AF1AA90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCompositionHomeHeaderFullBleed = 0x19B9AF1AC10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCompositionLegacyLayout = 0x19B9AF1A350; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCompositionPlayerGrid = 0x19B9AF1A010; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCompositionSearch = 0x19B9AF1A050; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCompositionTopBarFullBleed = 0x19B9AF1A690; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppContinueSortInstantPlay = 0x19BBB59A19D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppContinueSortInstantPlay_DEV = 0x19B88C2D610; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCreatorSuccessVirtualEventsLayerUseRoactExperiment = 0x19B9EE08AD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCreatorSuccessVirtualEventsLayerUseRoactExperiment2 = 0x19BA6072110; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppCredentialSheetEventStream = 0x19BBC1C695D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppCustomizableEntryPoint = 0x19BA6A31895; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppDataCacheBatch = 0x19BA5BD67D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppDataHydrationConnectionsPlayedStore = 0x19B85789D50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppDataHydrationDataResolverOnClear = 0x19B8578991D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppDataHydrationOptimisticMutationLayer = 0x19B85789690; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppDataHydrationPlayerCountGameInfoStore = 0x19B85789F1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppDataHydrationSanitizeItem = 0x19B85789D9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppDataHydrationUpdateItem = 0x19B85789C5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppDataHydrationVotesStoreTrackOptimisticVotes = 0x19B857897DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppDefaultHttpRetry = 0x19B8578B99D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppDefaultInitialItemsPerRowForSearch = 0x19B90269F1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppDeferLaunch = 0x19B902921D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppDemoModePlayButton = 0x19B88C2FBDD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppDemoModePlayButtonTelemetry2 = 0x19B88C2FD1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppDerivedStackAndSwitchState = 0x19B8578B71D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppDesignFoundationsBridge = 0x19B8578C050; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppDesktopFriendCarouselClicks = 0x19B88C2A75D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppDesktopMediaGalleryTelemetry = 0x19B88C2A290; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppDevStoreSeeAllForceRefreshOnNavigate = 0x19BA5207FBD; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppDevStoreSeeAllSduiEnabled = 0x19BA520247D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppDevStoreSeeAllSduiLogExposure = 0x19BC0543FD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppDisableChevronSeeAll = 0x19B88C2A8DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppDisableDataModelStreamingInStudio = 0x19B90295E50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppDisablePlayableWhenLoadingForce = 0x19B88C2A350; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppDisableStickyBarMediaGallery = 0x19BA6094690; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppDiscoveryClientAppStorageEmptyCacheTelemetry = 0x19BA3A7E590; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppDismissUnlockUpsell = 0x19BC054D59D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppEdpBackendV2AddUserVote = 0x19B88C41F10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpBackendV2HydrateLegacyDefault = 0x19BBB598FD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpBackendV2HydrateLegacyDefault9 = 0x19B88C425DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpBackendV2HydrateLegacyIxp = 0x19BBB59AED0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpBackendV2HydrateLegacyIxp9 = 0x19B88C4281D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpBackendV2LogFetchSuccessAndFailure2 = 0x19B88C42750; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpBackendV2LogUniverseIdForEvents = 0x19B88C422D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpBackendV2SduiInterleaveDefault = 0x19BBB595210; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpBackendV2SduiInterleaveDefault3 = 0x19B88C42A5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpBackendV2SduiInterleaveIxp = 0x19BBB594610; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpBackendV2SduiInterleaveIxp3 = 0x19B88C42C9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpBottomSheetPeekViewEvents2 = 0x19BA52031F5; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpConsoleMediaGalleryVideo = 0x19B88C2ABD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpConsoleMediaGalleryVideoMute = 0x19BBB59569D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpConsoleMediaGalleryVideoPlayIcon = 0x19BBB595495; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpFaeIxpEnabled = 0x19B9029B790; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpFetchLatencyTracking = 0x19B88C43210; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpFixDefaultBanner = 0x19B88C2B25D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpHideSystemBarOnPeekViewMount = 0x19B88C24990; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpKeepCachedDetailsOnRefetch = 0x19B88C24E90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpKeepFullPageOnPortraitRotation = 0x19B88C2525D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryAutoAdvance = 0x19BBB59869D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryAutoAdvance5 = 0x19B88C2D69D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryFullScreen = 0x19BBB59925D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryFullScreen4 = 0x19B88C2DB1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryHeightJitterFix = 0x19B88C2549D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryPreloadImage = 0x19B88C2D8DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryRedesign = 0x19BBB595B5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryRedesign5 = 0x19B88C2B55D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryRedesignIxp = 0x19BBB59515D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryRedesignIxp5 = 0x19B88C2B39D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryRedesignTelemetry = 0x19B88C2DD5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryVideoPreview = 0x19BBB59D79D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryVideoPreview5 = 0x19B88C2B690; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryVideoPreviewIxp = 0x19BBB594B5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpMediaGalleryVideoPreviewIxp5 = 0x19B88C2BAD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpNonSduiBuildAttribution = 0x19B88C4239D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEdpPeekViewReserveBottomDockHeight = 0x19B88C24190; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpShowBuildTag = 0x19B8C30F11D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppEdpUseHidePlayWithRewardVisibilityVariable = 0x19D82441370; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpVideoAvailableRamDeny = 0x19BBC38EC10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpVideoDeviceDeny = 0x19BBC380B10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpVideoManufacturerDeny2 = 0x19BBC38DFD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEdpVideoMaxMemoryDeny = 0x19BBC381B50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEmail2SVUpsellPopUpEnabled = 0x19B857818DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEmphasisGameTileVideo = 0x19B88C2C1D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnable10ftSignUpView = 0x19B945A5750; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableAndroidPushUpsell = 0x19B8C304E1D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppEnableBacktraceSessionInfo = 0x19B9F184A8D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppEnableChartsPageProfileLink = 0x19B9F18DE2D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppEnableChatMilestones = 0x19B8578C11D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableCommunityLinksRedirect = 0x19B9026AADD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableCompactDataModelPayload = 0x19B90295B90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableConsolidatedGameRefundPolicy = 0x19B88C413D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableContainedRewardUi = 0x19B9064009D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableContentfulPaintTracking = 0x19B8578C49D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableCredentialsProtocol = 0x19B8FC396DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableCustomAnalyticsEvent = 0x19B9064191D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableDataModelStreamForConsoles = 0x19B90295D90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableDesktopDualLoginABTest = 0x19BC0546B50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableEnhancedVideoExperienceAssetAndTimeline = 0x19B9F9207DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableEnhancedVideoExperienceGroupIdCheck = 0x19B9F920B5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableFeatureTileAdPlayer = 0x19BA5202D95; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableGameGridTable2 = 0x19B90264E1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableHeroUnitV2 = 0x19B88C41CD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableHomepageOneByTwoTile = 0x19BAC82D3D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableInExperienceDataModelStreamStarter = 0x19B9AF12D10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableLogoHeaderByDefault = 0x19B94810D90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableLumberyakLogBound = 0x19B8F90B1DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableMilestoneDeduplication = 0x19B85789110; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableMorePageProfileLink = 0x19B88C2979D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableNativePurchaseFinishedV2Signals = 0x19B9AF1D210; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableNativeRobuxProducts = 0x19B90269310; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableNxMApportioningExtraLogging = 0x19BAC82C350; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableNxMRoduxApportioning = 0x19B8578559D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableOpenTypeIGMFix = 0x19B9ACBEA50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableOpenTypeSignUpPageFix = 0x19B9ACBDD10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableOpenTypeSupport4 = 0x19BACFD6010; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnablePageLoadTracker = 0x19B8578BEDD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnablePlayButtonThrottle = 0x19B88C2CFD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnablePlaySquadButton = 0x19BBB591390; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnablePlaySquadButton3 = 0x19B88C2AC1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnablePlayableStateWhenLoading = 0x19B88C2AE5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnablePushUpsellOnFirstTime = 0x19B8C304F90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableRecommendedCarouselForDesktop = 0x19BB6BB5050; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableRelativeGuiHomeForAll = 0x19BBB317D50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableRelativeGuiHomeForAll2 = 0x19BB1D96810; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableRelativeGuiHomeWithIxp = 0x19BBB3119D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableRelativeGuiHomeWithIxp2 = 0x19B88C27690; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableReportBadge = 0x19BA59B2690; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableSduiHomePageDev = 0x19B9F18D2F5; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppEnableSearchStreamingEndpoint = 0x19B9AF14A90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableSinglePageSignUp = 0x19B9026A7D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableSlpForVr = 0x19B9481089D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableSponsoredReportAd = 0x19BAC820E10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableSponsoredReportAd3 = 0x19BAC820D90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableSquadPage4 = 0x19B8C2E3F10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableStickyShortcutBar = 0x19B88C4FB1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableStratusStreamingCheck = 0x19B88C4129D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableStratusStreamingTestOnly = 0x19B88C40410; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableToastNotificationsCoreScripts4 = 0x19B9AF11590; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableTokenBucketLimiter = 0x19B8F907610; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableTopBanner3 = 0x19B8C2E4810; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableVRCarouselScrolling = 0x19B88C4479D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableVirtualEventPlaceId = 0x19B8578A39D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppEnableWaitForPropWrapperAssert = 0x19BBE91CC50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableWebViewStateTrackerInDataModelStreaming = 0x19B90295D10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableWebViewTelemetry = 0x19BC05447D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnableWindowsHandheldScale = 0x19B8CA85FFD; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppEnableWindowsHandheldTokenScale = 0x19BA3A7D410; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEnhancedVideoAdLabelPropUpdate = 0x19B9F92021D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppErrorOnBadSortGroup = 0x19B90266F5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppErrorReportCountryCode = 0x19B8F90A250; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppEventDetailsPageDisableCtaOnUnplayable = 0x19B88C2E1D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppExpandableTextAdjustClipToContent = 0x19BA609985D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppExpandableTextImpressionsEnabled = 0x19B88C269DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppExpandableTextNewLineStrip = 0x19BA609CED0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppExperienceDetailsLayoutOrderConfig = 0x19BBB59BFD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppExperienceDetailsLayoutOrderConfig2 = 0x19B88C42B90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppExperienceJoinIdempotencyKey = 0x19D8952A8D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppExtendPlayWithRewardPeekView = 0x19BBB599490; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppExtraInviteModalStringValidation = 0x19B9F294C90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFetchContentMaturityWithPlayability = 0x19BA672F35D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFetchPlayabilityKillSwitch1 = 0x19BA67925DD; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppFix10ftGlobalNavAppHeaderBarSelection = 0x19B859CB450; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixActiveGameLoadingCheck = 0x19BA3A70150; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixAppExperienceActionRowLoadingState = 0x19BBC380750; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixAppNavHeaderIconsAlignment = 0x19B9ACB9850; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixApportioningTileTailConflict = 0x19BA679D1D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixAutocompleteEntryDups = 0x19B9026ADDD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixCarouselCanvasOverflow = 0x19B88C2151D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixCarouselPeekInControl = 0x19B9AF17D10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixCentralOverlayDeviceSafe = 0x19B9064975D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixChartsRenderOnFail = 0x19B88C439DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixCollectionGridWindowAbsoluteCanvasSize = 0x19BA679C1D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixCollectionSizeBindingsZero = 0x19BA6795A10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixCommunityLinksRedirect = 0x19B9026AC9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixCompositionSizeOverrideGap = 0x19B9AF17E90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixComputedSideMarginResponsiveBreakpoint = 0x19BA6796F90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixConsoleSeeAllGridContainment = 0x19B902600D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixCursorHooks = 0x19B88C4AA50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixDetailsPageThumbnailRenderInPhone = 0x19B88C29390; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixEdpRecommendedCarouselHoverZIndex = 0x19BB1D9B6D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixEventNotFoundErrorStateExit = 0x19BA60723DD; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppFixExplicitFeedbackConsoleTelemetry = 0x19B88C2629D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixExplicitFeedbackTelemetry = 0x19B88C25990; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixFrameBoundsImpressions = 0x19B8F90E950; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixGameGridTableNilRelativeHeight = 0x19B90264C9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixGamesListSortTokenExpiringTime = 0x19B88C432DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixHiddenTileVideoCleanup = 0x19B88C2D4DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixHomeGridPlaceholderFlowIssues = 0x19B88C43D90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixImpressionsHookDependencies = 0x19B8F90EE10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixInlineSignalsReactPattern = 0x19B88C4381D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixLaunchGameSourceParam = 0x19B88C2D450; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixNotificationBadgeCountsSync = 0x19B88C2279D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixPassesPageStoreFetch = 0x19B88C225DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixPlayButtonDefaultLaunchSource = 0x19BA679BD5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixRecommendedImpressionsInterface = 0x19BBE91D750; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixRsvpPromptDescriptionScrolling = 0x19BA6073A9D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppFixSDPLayout = 0x19B9ACB7850; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixSduiHeroUnitTitle = 0x19B82B178DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixSearchImpressions = 0x19B88C4319D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixSelectionCursor = 0x19B88C4ADDD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixSmallScreenFooterStatsOverlap = 0x19B88C41810; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixStudioNotchSupport3 = 0x19B906462DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixToastNotificationClosePosition = 0x19B827A5C5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFixTotalColsBound = 0x19BC0547A1D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppFixUnifiedPlayButtonStickyActionBar = 0x19BA609A210; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFixWebViewUnderlyingBackButton = 0x19B94810C1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppForceLowResMural = 0x19B902699DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppForceVrAppPanelWidthRollout = 0x19B88C40F50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppForumsDeeplinkFix = 0x19BA59B6C50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppFriendCarouselImpressionsTimestamp = 0x19BB1D90D1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppFriendsSortHeaderByPosition = 0x19BB1D9B850; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppGameCarouselUseAutoSizing = 0x19B90294490; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppGameDetailEventMobileAdsId = 0x19B88C4F29D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppGameDetailsAttributionFix = 0x19BBB59E290; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppGameEventsTelemetryServiceShadowTraffic = 0x19B88C24790; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppGameImpressionsAddUnifiedFields = 0x19B88C4E010; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppGameImpressionsMobileAdsId = 0x19B88C4E210; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppGamePassesDataHydrationMigrationEnabled = 0x19BB2AEB045; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppGamePlayIntentEventMobileAdsId = 0x19B88C4F71D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppGameStatsFallbackRendering = 0x19B88C4495D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppGameTileExtractGameDetailsCallback = 0x19B88C2DA50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppGameTileInteractionFeedback = 0x19BB1D92790; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppGameTileNotInterestedDirectAction = 0x19B88C2C9DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppGameTileOverflowMenuSelectionCloseFix = 0x19BBE9137D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppGameTileSelectionVideoPlayback = 0x19B88C2CE5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppGameTileVideoAvailableRamDeny = 0x19BBE912050; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppGameTileVideoDeviceDeny = 0x19BBE912E10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppGameTileVideoManufacturerDeny = 0x19BBE912310; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppGameTileVideoMaxMemoryDeny = 0x19BBE9125D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppGameViewTileBackgroundColorOverride = 0x19B88C4065D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppGateVideoPlaybackOnNavigationFocus = 0x19B88C2CC1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppGenreRatingFooter = 0x19B88C40C90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppHapticTriggeredTelemetry = 0x19B88C25C90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppHeadShapeInventory = 0x19B85788D5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppHeaderButtonText = 0x19BB1D9189D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppHideEdpStoreForUnplayable = 0x19B88C2A950; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppHideEmptyCarouselHeader = 0x19B9AF15D50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppHomeFirstTileThumbnailLoadedMilestone = 0x19B8578B610; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppHomeGameCarouselRemount = 0x19B88C4351D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppHomeJoinYourFriendsPresenceFix = 0x19B90290310; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppHomePageFirstImageLoadObserver2 = 0x19BA553E4D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppHomePageLoadTracker = 0x19BA553AE90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppHomePageReadyToRender = 0x19BA553DD90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppHomePageSharedEffects = 0x19B9481285D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppHomeReduceRenders = 0x19B88C2C190; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppHomeThumbnailPrefetch = 0x19B8578B450; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppHomeUseFeedVideoPlaybackContext = 0x19B94811390; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppHomeVngAppUpsell = 0x19B88C4BEDD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppHttpSupportNoContent = 0x19BA3A73B10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppIECVREnabled8 = 0x19BA3BB0A90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppIECVRIxpEnabled8 = 0x19BA3BB8890; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppIaHomeSubTab = 0x19B9ACBEAD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppIconPlayButton = 0x19B88C2F91D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppIconTextPlayButton = 0x19B88C2F490; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppIedpFixPlayButton = 0x19B88C446DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppIedpOverlayAndNavigationFix = 0x19B88C443DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppIedpSendPoints = 0x19B88C445DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppIedpSwitchChipToBadge = 0x19B9FD85B9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppImproveAccountSwitcherPeekView = 0x19B948109DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppImproveComponentTrackingTiming = 0x19B8578B650; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppInExperienceDetailsPrompt3 = 0x19B88C4419D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppIncorrectWebViewProperty = 0x19B90642E1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppInfoTableResponsiveProviderOverride = 0x19BA609851D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppInfoTableWorkaroundGridJank2 = 0x19BA6098590; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppInitializeToastNotificationEventParams2 = 0x19BA607EF50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppInlineRequireAppConfigurer = 0x19B859C9D10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppIsClickoutEnabledUniverse = 0x19B9F92101D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppIsEnhancedVideoUniverse = 0x19B9F920A50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppItemEventsTelemetryServiceShadowTraffic = 0x19B88C24310; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppJoinTextPlayableButton = 0x19B88C2F81D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppKeepTileBadgesDuringVideo = 0x19BBE913950; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppLCPTimingFix = 0x19BA59B5A10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppLaunchTrackThunks = 0x19BC27AD7C0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppLaunchWhenLoadingEdp = 0x19B88C2AFDD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppLaunchWhenLoadingForce = 0x19B88C2AD90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppLayoutParamsInContext2 = 0x19BA5538F10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppLazyComponentAsyncChunkLoad = 0x19BA461981D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppLimitEventThumbnailToOne = 0x19BA6070A1D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppLogChartsAppPageExposure = 0x19B88C23BDD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppLogExposurePlayButtonUX = 0x19B88C2F210; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppLogGameAttributionError = 0x19BBB59B090; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppLogGameAttributionError2 = 0x19B88C4365D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppLogMorePageLayerExposure = 0x19B82A141DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppLogOmniRecommendationsMetadata2 = 0x19B88C2175D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppLogSearchTopPageExposure = 0x19B88C23D1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppLoosenCollectionIdTypeInterface = 0x19B88C2AA1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppLuaBuyRobuxPage = 0x19B9064431D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppMakeDisclaimerOptInForFeedbackForm = 0x19B88C25750; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppMediaGalleryGamepadSupportsPagingIcons = 0x19B906416DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppMediaGalleryNilImageIdFix = 0x19B9AF13B10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppMigrateGameEventsTelemetryService = 0x19B88C24F1D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppMigrateGameTileActiveFriendsFix = 0x19B88C40D9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppMigrateGameTileActiveFriendsHydrationFix2 = 0x19B88C40F9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppMigrateGameTileFixConsoleMetadataText = 0x19B88C421DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppMigrateGameTileFooterValueFixes = 0x19B88C40290; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppMigrateGameTileHoverFixes = 0x19B88C4049D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppMigrateItemEventsTelemetryService = 0x19B88C24BD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppMobileEdpPlayButtonPartialUnificationIXP = 0x19B88C2F6DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppMorePageLayerExposure = 0x19B82B1D35D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppMoveProfileIntoTopBar = 0x19B9F185A8D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppMoveProfileIntoTopBarIXP = 0x19BAFB61E50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppMoveSocialLinksImpressions = 0x19B84E6CF9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppMutedSetNetworkingErrorToast = 0x19B8F90EA1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppNarrowTileHidePlayerCount2 = 0x19B88C41490; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppNarrowTileHideRating2 = 0x19B88C40250; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppNarrowTileSmallerFooterFont2 = 0x19B88C41410; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppNewSlpEndpointIxpEnabled = 0x19B8558AE9D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppNilApportionedItems = 0x19B9011F5DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppNormalizeUnifiedPasskeyResponse = 0x19B8FC38210; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppNotInterestedFeedbackFormTelemetry = 0x19B88C24B50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppNotInterestedReportPlaceId = 0x19B88C257D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppNullableGridLayoutTelemetryFields = 0x19BBE91F990; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPYMKSendUserSeenCollection = 0x19B88C2B95D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppPageLoadTrackerJoinExperienceFix = 0x19B8578C75D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppParentApprovedExperiences = 0x19B88C2A59D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppParentUpsellPolicy = 0x19B88C29190; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPersistentMusicPlayerDev = 0x19B9ACB8B90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPlatformRestrictionVPC = 0x19B9AF15550; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPlayButtonAmpAgeCheckFlow = 0x19B88C29D50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPlayButtonLaunchOnReleaseAfterUnmountEdp = 0x19B88C2A990; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPlayButtonLaunchOnReleaseAfterUnmountForce = 0x19B88C2A6D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPlayButtonLoadingDurationTelemetry = 0x19B88C2D850; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPlayButtonLoadingPrimary = 0x19BBB318A10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPlayButtonLoadingPrimary2 = 0x19B88C274DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppPlayButtonLoadingSkeleton3 = 0x19B88C2FA5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppPlayButtonOptOutFoundationButton = 0x19B88C2FED0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPlayButtonViewRefactor = 0x19B8578759D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppPlayButtonWizardCloseDelay = 0x19B88C2E4DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppPlayLoadingClickTelemetryMobile = 0x19B88C2DE90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPlayWithRewardSkipIxpForShimmer = 0x19B9064085D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppPlayWithRewardUsePlatformSpecificLayerValueForShimmer = 0x19B906409DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppPlayableUxTreatment = 0x19B88C41A90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppProcessGameSocialLinks = 0x19B88C42990; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPromotionalEmailsCheckboxEnabledInAppPolicy = 0x19BB6BB2C5D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppPromptsHomepageConfigName = 0x19B902947D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPropagateFriendsCarouselHeader = 0x19BB1D90150; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPushSystemUpsellDevOverride = 0x19B8C304C50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppPushUpsellDeprecateOldEvents = 0x19B8C304310; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppReduceGameIconFetches = 0x19B88C40A90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppRefactorSelectRouteDev = 0x19BA6A334D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppRemoveNumericalSortIndexSearch = 0x19BA672A6D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppRemoveOmniFeedDividersAndExtraPadding = 0x19BC054219D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppRemovePlayWithRewardBetaAllowlist = 0x19BBAE319F0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppRemovePlayWithRewardBetaAllowlist2 = 0x19B88C42C10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppRenameFriendsToConnectionsEdp = 0x19BBB59AC50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppResetHoverOnSduiPlayButtonActivation = 0x19B88C21D9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppRespectClipAncestorImpressions = 0x19B88C23A50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppResponsiveEnginePreferredInput = 0x19B88C27310; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppResponsiveFixHookDeps = 0x19B859C72D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppRfyRevealRows2 = 0x19B88C21290; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppRfyRevealRowsFocusFix = 0x19B88C21310; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppRfySignalApportioning4 = 0x19B88C43C5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppRfySignalApportioningIxp4 = 0x19BA5535A10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppScaleDetailWidth = 0x19BA6095A90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppScaleDiscoveryWidth = 0x19BA609DE50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppScrollDetectorLifecycleHardening = 0x19B88C4089D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppScrollTelemetryIntegration = 0x19BA6A30BD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiAttributionRow5 = 0x19B88C25610; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiColorPropMigration = 0x19B88C26190; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiEdpEnabled2 = 0x19B88C2251D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiEdpFallbackAttributionFromCache2 = 0x19B88C22BD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiEdpFallbackPlayButtonPassUiBlox = 0x19B88C2DCD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiEdpFallbackPlayButtonUseUiBlox = 0x19B88C2ED90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiEdpHideSystemBarOnPeekViewMount = 0x19BA55359D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiEdpLogExposure = 0x19B88C2291D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiEdpLogExposureLayoutEffect = 0x19B88C22A5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiEdpPassPageTimerThroughNav = 0x19B88C22C9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiEdpRouteAwareSessionRemoval = 0x19B88C22EDD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiErrorPage = 0x19B8FC32A9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiEventDetailsActionBarInFeed = 0x19B88C238DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiEventDetailsCenterSheet2 = 0x19B88C2345D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiEventDetailsEnabled = 0x19B88C21F50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiEventDetailsLoadingSlot = 0x19B88C2369D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiEventDetailsLogExposure = 0x19B88C2321D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiGameSortDropDown2 = 0x19BC054959D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiGameTileHoverShadow = 0x19B88C28F9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiGameTilePlayButtonDefaults = 0x19B9F18FF15; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppSduiLandingPageEnabled = 0x19B88C229D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiOpenSearchResultsWithQueryAction = 0x19B88C243D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiPageEntryPointSnackbar2 = 0x19BA553D390; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiPageEntryScrollAway = 0x19B88C2003D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiPlaceholderSupport2 = 0x19B88C27C50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiQuerySuggestionClickedTelemetry = 0x19B88C29510; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiRemoveAbuseReportActionFromLegacyRegistry = 0x19B88C26FD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiSeeAllArrowIconMigration2 = 0x19B9029B390; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiSeeAllLayoutParamsFix = 0x19B88C43B1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiStickyHeaderScrollAway = 0x19B88C2021D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiStreamingChunkedResponses = 0x19B9AF14C90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiStreamingFirstDataTiming = 0x19B9AF14090; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiUpdateUserSettingsAction = 0x19B88C41F9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiVerificationUpsellActions2 = 0x19BC054991D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppSduiVerticalFeedThresholdRefresh = 0x19B906412DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSduiVideoThumbnail = 0x19BBB315010; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSduiVideoThumbnailDev = 0x19B88C2715D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSearchListFramesSelectable = 0x19B9029C5D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSearchPeopleUnifiedSchemaFields = 0x19B88C2BF1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSearchPlaceholderGrid = 0x19B88C43790; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSearchResultsPageGameTileVideo = 0x19BBB59D0DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSearchResultsPageGameTileVideo2 = 0x19B88C2C3D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSearchStandardizeAssetCategorization = 0x19BA520F71D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppSendTTIEventsPerDM = 0x19BA3AD2610; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSentryAddAppPolicyMetadata2 = 0x19B8F90A210; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSentryReporterIncludeInTags = 0x19B8F90B51D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppShareEdpVideoBlockingConfig = 0x19BA5530F50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSharedHomePageInteractive = 0x19BAFB689F0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppShouldTrackTopThunks = 0x19B8C316910; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSignupPasskeyAvailabilityPreflight2 = 0x19B945A4550; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSortDeeplinkFix = 0x19BA59B1210; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSortHeaderAnchorTag = 0x19B88C214D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSponsoredAdVideoViewabilityEnabled = 0x19BAC823AD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSponsoredAdViewabilityEnabled = 0x19BAC826B5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppStratusBugReportAfterConnect = 0x19B88C4155D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSupportDeviceSafeInsets = 0x19B9ACBE810; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppSupportDisablePlayableWhenLoading = 0x19B8578651D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSupportHomeBackToTop = 0x19B88C4345D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppSupportNonSduiTypeForServerTriggeredModals = 0x19BA6F6A295; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppTextFeedbackFormModal = 0x19B88C253D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppTextFeedbackFormModalStandardInput = 0x19BA60903D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppTextOnlyPlayButton = 0x19B88C2F410; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppThrottleInviteSendEndpoint = 0x19B9F296A9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppThrottleViewportBoundsScreenSize = 0x19B8F90E250; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppTileVideoCandidateOnly = 0x19B88C2C950; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppTileVideoKeepPlayingOnScroll = 0x19B88C2C5D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppToastV2PerMessageDuration = 0x19B88C25E10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUnifiedLoggingDialogContentType = 0x19B8F9DF7D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUnifiedPlayButtonSquadMenuDirection = 0x19B88C4009D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUnifyPlayButtonAllSurfacesIxp = 0x19BBB597E9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUnifyPlayButtonAllSurfacesIxp5 = 0x19B88C2F0DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUnifyPlayButtonMobileEdp = 0x19BBB59F210; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUnifyPlayButtonMobileEdp3 = 0x19B88C2F31D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUnifyPlayButtonNonMobileEdp = 0x19BBB59F990; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUnifyPlayButtonNonMobileEdp3 = 0x19B88C2F4DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUnifyPlayButtonTile = 0x19BBB59EA5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUnifyPlayButtonTile4 = 0x19B88C2F25D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUnifyPlayButtonTileIxp = 0x19BBB59799D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUnifyPlayButtonTileIxp2 = 0x19B88C2EAD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUnlockUpsellSupport = 0x19B857853DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUpdateContentDescriptorsTranslation = 0x19B88C42350; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUpdateFailedStateEdpIcon = 0x19B88C2565D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUpdateGameSortGridRowHeight10ft2 = 0x19B90262610; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUpdatePlayButtonText = 0x19B88C2D090; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUpdateRevealMoreButtonUi = 0x19B90269D5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUseAppHttpStore = 0x19B85788CDD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUseAppHttpStoreInExperience = 0x19BA8A04110; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUseDeviceSafeInsetsForAppContainer3 = 0x19B9ACB0F50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUseDisplayStoreForCollectionLayoutParams = 0x19BA679BFD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUseEffectInSignalPreprocessing = 0x19B88C2199D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUseExperienceLogoTrayInGameInfoList = 0x19B88C41D5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUseFoundationCheckbox = 0x19B8E6109FD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUseFoundationLoading = 0x19B8E610B30; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUseFrameBoundsImpressions = 0x19B9AF1AF10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUseGameTransactionsApiForReceipts = 0x19B9ACB5D90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUseOverlayInAppContainer = 0x19B88C27050; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUsePrevalidatedVideoGamePlayability = 0x19B88C402DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUseRatingFormatHelper2 = 0x19BBE913AD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUseScreenFillBoundsForFrameBoundsImpressions = 0x19B9AF1A450; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUseSettingsNativeWrapper2 = 0x19B9064421D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUseSnackbarForProvideFeedbackToast = 0x19B88C25EDD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUseSortsWithDividersFString2 = 0x19BC0549B90; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUseSpanTileOverflowMenuTwoByOne2 = 0x19BBE91FFD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUseTokenHeightForPlayButton = 0x19B88C2F7D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUseViewportBoundsInsetFix = 0x19B8F90E810; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUseWithLocalization = 0x19B90649C1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUserSearchGridReactiveContainer = 0x19B902949D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppUserSeenCollectionUnifiedFields = 0x19B88C2BB9D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppUsingSecurityQuestionsForLuaLogin2 = 0x19B88C4B110; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppVideoAutoplayElectOnNewCandidate = 0x19BBC387890; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppVideoAutoplayFeedElection = 0x19B88C2D010; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppVideoPlaybackRefCount = 0x19B88C4171D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppVideoServerDisplayWakeLock = 0x19B88C418DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppVideoTileDisableActivation = 0x19B88C2D0DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppVideoTileHideCenterPlayButton = 0x19B88C2D31D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppVngUpsellAlwaysCanClose = 0x19B9481249D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppVngUpsellAlwaysEnabled = 0x19B9481235D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppVoteOptimisticUpdateRaceFix = 0x19BA553DC10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppWireAudioDeviceInputOnRequest = 0x19B88C41B1D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppWizardContainerBypassNavigationLock = 0x19BC054AB1D; // Bool = true
    inline constexpr uintptr_t FFlagLuaAppWrapChartsFilterOptionLabels = 0x19B90264F5D; // Bool = false
    inline constexpr uintptr_t FFlagLuaAppsDefaultSelection = 0x19BA6A379D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaAppsServerTriggeredModals = 0x19B88C4F650; // Unknown = 
    inline constexpr uintptr_t FFlagLuaConsumePlayerModerated = 0x19B8FDE9D10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaEnableCustomizedInviteLandingPage = 0x19B945A7690; // Unknown = 
    inline constexpr uintptr_t FFlagLuaEnableCustomizedInviteLandingPageForTesting = 0x19B945A1950; // Unknown = 
    inline constexpr uintptr_t FFlagLuaEnableDidSwitchAccount = 0x19B88C4D75D; // Bool = false
    inline constexpr uintptr_t FFlagLuaEnableGameInviteModal2023V5 = 0x19D89528290; // Unknown = 
    inline constexpr uintptr_t FFlagLuaEnableGameInviteModalInvitePromptV2 = 0x19B9F29455D; // Bool = false
    inline constexpr uintptr_t FFlagLuaEnableGameInviteModalSettingsHub = 0x19BACE9C5DD; // Bool = false
    inline constexpr uintptr_t FFlagLuaEnableGenreDeeplinkSortId = 0x19B8616E548; // Unknown = 
    inline constexpr uintptr_t FFlagLuaEnableGenreLandingDeeplink = 0x19B88C22E10; // Unknown = 
    inline constexpr uintptr_t FFlagLuaEnableLandingPageTTIMeasurements = 0x19B945A0150; // Unknown = 
    inline constexpr uintptr_t FFlagLuaEnableLoginAndSignupDifferentiatedStatusValues = 0x19B945A1350; // Unknown = 
    inline constexpr uintptr_t FFlagLuaEnableScreenTimeSignalR = 0x19BA3AD9010; // Unknown = 
    inline constexpr uintptr_t FFlagLuaEnableShowUpsellMethod2 = 0x19B8C304F1D; // Bool = true
    inline constexpr uintptr_t FFlagLuaFlagVoiceChatDisableSubscribeRetryForMultistream = 0x19BA6B3C21D; // Bool = false
    inline constexpr uintptr_t FFlagLuaIdentityGetPhoneNumber = 0x19BC054BE50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaIdentityGetSMSOTP = 0x19BC0546E50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaIdentityProtocol = 0x19BBC385110; // Unknown = 
    inline constexpr uintptr_t FFlagLuaIdentityVerifySNA = 0x19BC054DE50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaInExperienceCoreScriptsGameInviteUnificationV3 = 0x19B9AF10E50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaMenuPerfImprovements = 0x19B996ED650; // Unknown = 
    inline constexpr uintptr_t FFlagLuaMultiPageSignupForceDeviceBoundPasskey = 0x19B945A0590; // Unknown = 
    inline constexpr uintptr_t FFlagLuaUsePhoneNumberTextTypeForPhoneUpsellV2 = 0x19BBC384B50; // Unknown = 
    inline constexpr uintptr_t FFlagLuaVoiceChatAnalyticsBanMessage = 0x19B8FDE961D; // Bool = false
    inline constexpr uintptr_t FFlagLuaVoiceChatAnalyticsUseCounterV2 = 0x19B8FDE921D; // Bool = false
    inline constexpr uintptr_t FFlagLuaVoiceChatAnalyticsUseEventsV2 = 0x19B8FDE945D; // Bool = false
    inline constexpr uintptr_t FFlagLuaVoiceChatAnalyticsUsePointsV2 = 0x19B8FDE82D0; // Unknown = 
    inline constexpr uintptr_t FFlagLuaVoiceChatReconnectMissedSequence = 0x19B8FDE97DD; // Bool = false
    inline constexpr uintptr_t FFlagLuafiedReportEntryPoints = 0x19B8C306FDD; // Bool = true
    inline constexpr uintptr_t FFlagLuafiedReportErrorStates = 0x19B8C306B50; // Unknown = 
    inline constexpr uintptr_t FFlagLuafiedReportFullFlow = 0x19BBF83F308; // Unknown = 
    inline constexpr uintptr_t FFlagLuafiedReportThumbnail = 0x19B8C306DD0; // Unknown = 
    inline constexpr uintptr_t FFlagLuafiedWechatQQLogin8 = 0x19B88C4DCDD; // Bool = false
    inline constexpr uintptr_t FFlagMacMenuBarContentUpdates = 0x19BA59B4AD0; // Unknown = 
    inline constexpr uintptr_t FFlagMacUnifyKeyCodeMapping = 0x19B825F289D; // Bool = true
    inline constexpr uintptr_t FFlagMakeCreateOrJoinSquadAThunks = 0x19BACFD4510; // Unknown = 
    inline constexpr uintptr_t FFlagMakeVPCFAECheckMoreGeneric = 0x19B8C2E4ADD; // Bool = false
    inline constexpr uintptr_t FFlagManagerAddDisplayOrderAndBackgroundDismiss = 0x19B8FC35C5D; // Bool = false
    inline constexpr uintptr_t FFlagManuallyInvokeAmpUpsell2 = 0x19B90268C50; // Unknown = 
    inline constexpr uintptr_t FFlagManuallyMigrateDeprecatedIconUsage = 0x19B85788B90; // Unknown = 
    inline constexpr uintptr_t FFlagMarketplaceCatalogCategoryTrackLastReceived = 0x19B88C20710; // Unknown = 
    inline constexpr uintptr_t FFlagMarketplaceCatalogSortTrackLastReceived = 0x19B88C20E10; // Unknown = 
    inline constexpr uintptr_t FFlagMarketplaceOffersOptOutRoot = 0x19B9AF1EB90; // Unknown = 
    inline constexpr uintptr_t FFlagMarketplaceOffersOptOutRootLowSpender = 0x19B9AF1D450; // Unknown = 
    inline constexpr uintptr_t FFlagMarketplaceOffersOptOutRootNoSpender = 0x19B9AF1E710; // Unknown = 
    inline constexpr uintptr_t FFlagMarketplaceOffersOptOutRootRandom = 0x19B9AF1F250; // Unknown = 
    inline constexpr uintptr_t FFlagMarketplaceOffersRoot = 0x19B9ACB1550; // Unknown = 
    inline constexpr uintptr_t FFlagMarketplaceOffersRootLowSpender = 0x19B9ACB6710; // Unknown = 
    inline constexpr uintptr_t FFlagMarketplaceOffersRootNoSpender = 0x19B9AF1D510; // Unknown = 
    inline constexpr uintptr_t FFlagMarketplaceOffersRootRandom = 0x19B9AF1ED90; // Unknown = 
    inline constexpr uintptr_t FFlagMeTabBadgeEnabled = 0x19B859CAF50; // Unknown = 
    inline constexpr uintptr_t FFlagMeTabRightOfPartyBottomNav = 0x19B859CAD10; // Unknown = 
    inline constexpr uintptr_t FFlagMediaAccordionAndFullTelemetry = 0x19BB1D93BD0; // Unknown = 
    inline constexpr uintptr_t FFlagMediaGalleryVideoVisiblePercent = 0x19B9AF14050; // Unknown = 
    inline constexpr uintptr_t FFlagMediaSelectorErrorLogging = 0x19BACE7269D; // Bool = false
    inline constexpr uintptr_t FFlagMemoizeBubbleChatApp = 0x19BBCD79BD0; // Unknown = 
    inline constexpr uintptr_t FFlagMemoizeChatInputApp = 0x19BA461A290; // Unknown = 
    inline constexpr uintptr_t FFlagMemoizeChatReportingMenu = 0x19BACFDC850; // Unknown = 
    inline constexpr uintptr_t FFlagMenuButtonsDisconnectGamepadConnected = 0x19BAC873410; // Unknown = 
    inline constexpr uintptr_t FFlagMenuButtonsIncreaseIconSize = 0x19BAC873E10; // Unknown = 
    inline constexpr uintptr_t FFlagMenuButtonsMountWithIEM = 0x19BACE9D51D; // Bool = false
    inline constexpr uintptr_t FFlagMenuButtonsUseGreyResumeButton = 0x19BAC87409D; // Bool = false
    inline constexpr uintptr_t FFlagMicroProfilerReadOnlyInformationLabel = 0x19B9FD8BA9D; // Bool = false
    inline constexpr uintptr_t FFlagMigrateAllOsaMessagingToCentralService = 0x19B8C30DE5D; // Bool = true
    inline constexpr uintptr_t FFlagMigrateCameraCFrameDatamodel = 0x19B8184305D; // Bool = false
    inline constexpr uintptr_t FFlagMigrateCameraFocusDatamodel = 0x19B81842F9D; // Bool = false
    inline constexpr uintptr_t FFlagMigrateCameraFovDatamodel = 0x19B81842F1D; // Bool = false
    inline constexpr uintptr_t FFlagMigrateFriendshipStatusesPYMK = 0x19B8FC3B45D; // Bool = false
    inline constexpr uintptr_t FFlagMigrateFriendshipStatusesRemainingActions = 0x19B88C24A1D; // Bool = false
    inline constexpr uintptr_t FFlagMigrateFriendshipStatusesSocialCarousel = 0x19B8FA1D81D; // Bool = false
    inline constexpr uintptr_t FFlagMigrateFriendshipStatusesUserSearch = 0x19B9011A99D; // Bool = false
    inline constexpr uintptr_t FFlagMigrateGameIconsToStore = 0x19BA5539B10; // Unknown = 
    inline constexpr uintptr_t FFlagMigrateGameInfoToStoreDev = 0x19B88C20990; // Unknown = 
    inline constexpr uintptr_t FFlagMigrateNoFriendsViewToFoundation = 0x19B8FA1C81D; // Bool = false
    inline constexpr uintptr_t FFlagMigratePymkCarouselHttpRequestToRequestInternal = 0x19B8FC377DD; // Bool = false
    inline constexpr uintptr_t FFlagMigrateRoactUtilsToReactUtils = 0x19B857896DD; // Bool = false
    inline constexpr uintptr_t FFlagMigrateSocialNetworking = 0x19BC054B150; // Unknown = 
    inline constexpr uintptr_t FFlagMigrateUserSearchHttpRequestToRequestInternal = 0x19B9011DED0; // Unknown = 
    inline constexpr uintptr_t FFlagMinMaxPriceValidation = 0x19BBC7A2710; // Unknown = 
    inline constexpr uintptr_t FFlagMobileGameJoinCardEDPFromThumbnail = 0x19B8FA1D0DD; // Bool = false
    inline constexpr uintptr_t FFlagMobileGameJoinCardEDPFromTitle = 0x19B8FA1BD50; // Unknown = 
    inline constexpr uintptr_t FFlagMobileGameJoinCardHideUserAvatar = 0x19B8FA1D39D; // Bool = false
    inline constexpr uintptr_t FFlagMobileGameJoinCardShowExperienceNameOnly = 0x19B8FA1D5DD; // Bool = false
    inline constexpr uintptr_t FFlagMobileGameJoinCardTTITracking = 0x19B8C30315D; // Bool = true
    inline constexpr uintptr_t FFlagMobileGameJoinCardThumbnail = 0x19B8FA1C7D0; // Unknown = 
    inline constexpr uintptr_t FFlagMobilePopularItemBadgingExperimentEnabled = 0x19B9B5F4EAD; // Bool = false
    inline constexpr uintptr_t FFlagMobilePopularItemBadgingExperimentEnabledV2 = 0x19BAC833DDD; // Bool = false
    inline constexpr uintptr_t FFlagMobileSoundAndHapticsEnabledIXP = 0x19BBC383950; // Unknown = 
    inline constexpr uintptr_t FFlagMobileSoundAndHapticsIXPBypass = 0x19BBC38BB90; // Unknown = 
    inline constexpr uintptr_t FFlagMockDevSubPurchaseInStudio = 0x19D85DC32D0; // Unknown = 
    inline constexpr uintptr_t FFlagModalImpressionEventAddSessionInfo = 0x19B90294590; // Unknown = 
    inline constexpr uintptr_t FFlagModalSelectorCloseButton = 0x19BBB7FC490; // Unknown = 
    inline constexpr uintptr_t FFlagMomentTextGenerationFilteredSignal = 0x19D86F02590; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsAnalyticsClientEventTimestamp = 0x19BBF255110; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsAnalyticsProducerPrereqs = 0x19BBF25D990; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsAnalyticsSchemaIdentity = 0x19BBF25E690; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsAutoplayAmpPolicy = 0x19B85786910; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsCarouselVideoHandoff = 0x19B8C2EC090; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsContentStatsTelemetry = 0x19D86F04290; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsCreationAccurateDirtyTracking = 0x19D86F0C510; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsCreationBlockBackgroundInteraction = 0x19D86F0BA9D; // Bool = false
    inline constexpr uintptr_t FFlagMomentsCreationGalleryPreviewSwapFix = 0x19D86F0B25D; // Bool = true
    inline constexpr uintptr_t FFlagMomentsCreationMusicSearchStateFix = 0x19D86F00490; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsCreationNormalizeMetadataEnums = 0x19D86F04C90; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsCreationPersistEditSession = 0x19D86F0781D; // Bool = false
    inline constexpr uintptr_t FFlagMomentsCreationSaveDraft = 0x19BB2739B35; // Bool = true
    inline constexpr uintptr_t FFlagMomentsCreationTextOverlayResolutionScale = 0x19D864C13C0; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsDarkAppNavBar = 0x19B9AF17110; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsDescriptionKeyboardAvoidance = 0x19D86F09EDD; // Bool = true
    inline constexpr uintptr_t FFlagMomentsEmojiSetsApi = 0x19BB89771A5; // Bool = true
    inline constexpr uintptr_t FFlagMomentsEntryImmersiveNav = 0x19B9ACB6950; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsFeedHealthAnalytics = 0x19D86F03090; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsFeedWatchPageAttribution = 0x19B8578681D; // Bool = false
    inline constexpr uintptr_t FFlagMomentsFixBatchedGetMomentsQueryParams = 0x19BACE70190; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsIPReporting = 0x19B85786AD0; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsLoopOnEndSeek = 0x19D86F08490; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsMediaSmoothnessTelemetry = 0x19D86F04110; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsMuteVideoAudioOnly = 0x19D86F0731D; // Bool = true
    inline constexpr uintptr_t FFlagMomentsOverlayContainerScaleFallback = 0x19D86F09CD0; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsPassFeedItemIdToBackendApis = 0x19B9F181945; // Bool = true
    inline constexpr uintptr_t FFlagMomentsPostCtaUseCaptureUniverse = 0x19D86F03290; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsProfileGridInfiniteLoad = 0x19D86F07B50; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsReactToFeedItemV2 = 0x19B99878365; // Bool = true
    inline constexpr uintptr_t FFlagMomentsRealtimeObservability = 0x19D86F03750; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsRealtimeSessionTelemetry = 0x19D86F01410; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsRefreshOwnMomentsAfterPublish = 0x19B85786F9D; // Bool = false
    inline constexpr uintptr_t FFlagMomentsRemoveDeletedFromProfile = 0x19B85786DDD; // Bool = false
    inline constexpr uintptr_t FFlagMomentsReportWithFeedId = 0x19B9AF17150; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsRequireApiFeedItemId = 0x19BA8025DDD; // Bool = false
    inline constexpr uintptr_t FFlagMomentsRespectAccountTheme = 0x19B9AF16E90; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsScreenshotMusicScrubber = 0x19D86F00BDD; // Bool = false
    inline constexpr uintptr_t FFlagMomentsSessionHeartbeat = 0x19D86F03F90; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsStickerButton3 = 0x19D86F011D0; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsStickerOverlayMediaRect = 0x19D86F09990; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsStickerOverlayNormalization = 0x19BA8026DD0; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsStickerOverlayNormalization2 = 0x19BA802D910; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsSurfaceLoadTTI = 0x19B85786A5D; // Bool = false
    inline constexpr uintptr_t FFlagMomentsTTSAudioOverlayLua2 = 0x19D86F04D1D; // Bool = false
    inline constexpr uintptr_t FFlagMomentsTabReactiveIXP = 0x19B85783C10; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsTextDragToDelete = 0x19D86F06290; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsTextOverlayAfterVideoLoaded = 0x19D86F02050; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsTextOverlayClampToBounds = 0x19D86F031D0; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsTextOverlayMediaRect = 0x19D86F066D0; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsTileSkeletonPoster = 0x19D86F05790; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsUseBackendPostStatusNotification = 0x19D86F0DB50; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsUseUploadPostAsync = 0x19D86F08B90; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsVideoCropRoundedCorners = 0x19D86F02F10; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsVideoSurfaceMediaRect = 0x19D86F05FD0; // Unknown = 
    inline constexpr uintptr_t FFlagMomentsWatchSessionalization = 0x19B857866DD; // Bool = false
    inline constexpr uintptr_t FFlagMoreFramerateOptions = 0x19BA3669F9D; // Bool = false
    inline constexpr uintptr_t FFlagMountCoreGuiBackpack = 0x19BA6078890; // Unknown = 
    inline constexpr uintptr_t FFlagMountUnmountSideSheet = 0x19BA4E9D21D; // Bool = false
    inline constexpr uintptr_t FFlagMoveAmpUpsellOffNavigateDown = 0x19B8C30C0D0; // Unknown = 
    inline constexpr uintptr_t FFlagMoveInExperienceModeToEditProfile_V2 = 0x19B8C2E38D0; // Unknown = 
    inline constexpr uintptr_t FFlagMoveLimitedBadgeToTopLeft = 0x19B9F0081DD; // Bool = false
    inline constexpr uintptr_t FFlagMoveLuaExpLaunchBegin = 0x19BA46128DD; // Bool = false
    inline constexpr uintptr_t FFlagMoveReducerCreationOutOfReducer = 0x19B81DE7C18; // Unknown = 
    inline constexpr uintptr_t FFlagMusicPlayerUseDynamicNavBarHeight = 0x19B9ACBD790; // Unknown = 
    inline constexpr uintptr_t FFlagMutualConnectionsListPagination = 0x19BACFDDDDD; // Bool = false
    inline constexpr uintptr_t FFlagMyStatsMediaSelector3 = 0x19B9AF15450; // Unknown = 
    inline constexpr uintptr_t FFlagNavigateToSafetyDashboardForAppeals = 0x19BBB3191D0; // Unknown = 
    inline constexpr uintptr_t FFlagNavigateToSafetyDashboardForAppeals2 = 0x19B8C30E51D; // Bool = true
    inline constexpr uintptr_t FFlagNewEventIngestPlayerScriptsDimensions = 0x19BACE9CB9D; // Bool = false
    inline constexpr uintptr_t FFlagNewInGameMenuDisabledInVR = 0x19BA36674DD; // Bool = false
    inline constexpr uintptr_t FFlagNewPeopleButtonOrder = 0x19BBC386E90; // Unknown = 
    inline constexpr uintptr_t FFlagNewPeopleButtonOrder4 = 0x19BBC38F150; // Unknown = 
    inline constexpr uintptr_t FFlagNewPeoplePageIcons = 0x19BBC389AD0; // Unknown = 
    inline constexpr uintptr_t FFlagNewPeoplePageIcons5 = 0x19BBC389910; // Unknown = 
    inline constexpr uintptr_t FFlagNewUpsellModalExperiment = 0x19D84DA64D0; // Unknown = 
    inline constexpr uintptr_t FFlagNewUpsellModalExperimentForDesktopV2 = 0x19BAC8320DD; // Bool = false
    inline constexpr uintptr_t FFlagNewUpsellModalExperimentForPlatform = 0x19BAC831990; // Unknown = 
    inline constexpr uintptr_t FFlagNewUpsellModalExperimentV2 = 0x19BAC831FDD; // Bool = false
    inline constexpr uintptr_t FFlagNoShortcutBarWithTvRemote = 0x19BA607D150; // Unknown = 
    inline constexpr uintptr_t FFlagNonVoiceFTUX = 0x19BACFD7D10; // Unknown = 
    inline constexpr uintptr_t FFlagNormalizePriceDiscountAcceptLowercase = 0x19D85DCDC90; // Unknown = 
    inline constexpr uintptr_t FFlagNotApprovedPageIXPExposure = 0x19B8C30B950; // Unknown = 
    inline constexpr uintptr_t FFlagNotificationModalSetMenuIsOpen = 0x19B88C4EC1D; // Bool = false
    inline constexpr uintptr_t FFlagNotificationThumbnailUseProfileFrameThumbnail = 0x19BA607CC50; // Unknown = 
    inline constexpr uintptr_t FFlagNotificationsComplianceShouldRestrictStream = 0x19B8C304210; // Unknown = 
    inline constexpr uintptr_t FFlagNotificationsForceEnableEDPDiscoverability = 0x19B8C30529D; // Bool = true
    inline constexpr uintptr_t FFlagNotificationsRenameFriendRequestToConnection = 0x19BACFEBDDD; // Bool = false
    inline constexpr uintptr_t FFlagNotificationsUpsellDisableBackgroundDismiss = 0x19B8FA1FB5D; // Bool = false
    inline constexpr uintptr_t FFlagOffNetworkAnalytics = 0x19BC0543110; // Unknown = 
    inline constexpr uintptr_t FFlagOnlyEnableJoinVoiceInVoiceEnabledUniversesV2 = 0x19BA515789D; // Bool = false
    inline constexpr uintptr_t FFlagOnlyShowToastOnce2 = 0x19B9FD8909D; // Bool = false
    inline constexpr uintptr_t FFlagOnlyShowToastOnceInLifetime2 = 0x19B9FD89450; // Unknown = 
    inline constexpr uintptr_t FFlagOpenVngTosForVngRobuxUpsell = 0x19B88C4B45D; // Bool = false
    inline constexpr uintptr_t FFlagOrientationUseTelemetryService = 0x19BA609D790; // Unknown = 
    inline constexpr uintptr_t FFlagOverflowMenuRemoveCloseMenuChecks = 0x19BA609D6D0; // Unknown = 
    inline constexpr uintptr_t FFlagOverrideInExperienceMenuReorderFirstVariant = 0x19B9FDDAED5; // Bool = false
    inline constexpr uintptr_t FFlagOverridePlayerVerifiedBadge = 0x19B85788110; // Unknown = 
    inline constexpr uintptr_t FFlagPCMAcceptWidthAsProp = 0x19B82A11CD0; // Unknown = 
    inline constexpr uintptr_t FFlagPPDebugLogging = 0x19D85DC2150; // Unknown = 
    inline constexpr uintptr_t FFlagPPVBackgroundUse2DAsLoadingState = 0x19B8C2E1C5D; // Bool = false
    inline constexpr uintptr_t FFlagPPVEnable3DBackground = 0x19BA59B9E10; // Unknown = 
    inline constexpr uintptr_t FFlagPPVEnabledOnConsole_V3 = 0x19B8C2E0450; // Unknown = 
    inline constexpr uintptr_t FFlagPYMKAddFriendsEntry_v3 = 0x19B8C2E5010; // Unknown = 
    inline constexpr uintptr_t FFlagPYMKDisableButtonsOnFetch = 0x19B9011541D; // Bool = false
    inline constexpr uintptr_t FFlagPYMKFriendsToastRename = 0x19B9011539D; // Bool = false
    inline constexpr uintptr_t FFlagPYMKShowAddFriendsButton_DEV = 0x19B9029481D; // Bool = false
    inline constexpr uintptr_t FFlagPackagifySettingsShowSignal = 0x19B88C4EADD; // Bool = false
    inline constexpr uintptr_t FFlagPageLoadAllowImprovedDisconnectTiming = 0x19B8578BC90; // Unknown = 
    inline constexpr uintptr_t FFlagParseHeadShapeFromAPIResponse = 0x19BA3A5A15D; // Bool = false
    inline constexpr uintptr_t FFlagParseHeadShapeFromAPIResponse6 = 0x19BA3A5955D; // Bool = false
    inline constexpr uintptr_t FFlagPartyCoordinationUIExposureEnabled = 0x19B8FDED350; // Unknown = 
    inline constexpr uintptr_t FFlagPartyDevAPIToRespectThirdPartySettingsEnabled = 0x19B8C2E2910; // Unknown = 
    inline constexpr uintptr_t FFlagPartyFormationCreateUserExposureEnabled = 0x19B8FDEECDD; // Bool = false
    inline constexpr uintptr_t FFlagPartyFoundationIconFixEnabled = 0x19B8C2E14D0; // Unknown = 
    inline constexpr uintptr_t FFlagPartyVoiceDisallowIXPLayerExposureOnInit = 0x19B859C8EDD; // Bool = false
    inline constexpr uintptr_t FFlagPartyVoiceLogActiveDM = 0x19B859C93DD; // Bool = false
    inline constexpr uintptr_t FFlagPassNavigationToContactsRevoked = 0x19BAFCFE990; // Unknown = 
    inline constexpr uintptr_t FFlagPassShopPurchaseSurfaceToBuyModal = 0x19B9ACBBE10; // Unknown = 
    inline constexpr uintptr_t FFlagPasskeySignupEnabled5 = 0x19B9029179D; // Bool = false
    inline constexpr uintptr_t FFlagPasskeyUpsellEnabled = 0x19B945A7410; // Unknown = 
    inline constexpr uintptr_t FFlagPasskeyUpsellEnabled1 = 0x19B945A2C10; // Unknown = 
    inline constexpr uintptr_t FFlagPasskeyUpsellFilteringEnabled = 0x19B945A3750; // Unknown = 
    inline constexpr uintptr_t FFlagPasswordErrorLength = 0x19B8C30DADD; // Bool = true
    inline constexpr uintptr_t FFlagPasswordErrorSimple = 0x19B88C61A1D; // Bool = false
    inline constexpr uintptr_t FFlagPeekViewFixBriefHeightLayoutRace = 0x19BC0543850; // Unknown = 
    inline constexpr uintptr_t FFlagPeopleCardsEnableVirtualizedGrid = 0x19BBC381D10; // Unknown = 
    inline constexpr uintptr_t FFlagPeopleListContextualMenuFixFocusNavigation = 0x19BACFDE290; // Unknown = 
    inline constexpr uintptr_t FFlagPeoplePageCardMenuUseVisibleProperty = 0x19BB7F4CE55; // Bool = false
    inline constexpr uintptr_t FFlagPeoplePageDismissCardMenuOnScrollOutOfView = 0x19BBC381710; // Unknown = 
    inline constexpr uintptr_t FFlagPeoplePageDismissVolumePopoverOnScrollOutOfView = 0x19BBC38B050; // Unknown = 
    inline constexpr uintptr_t FFlagPeoplePageEnablePersonSignalStore = 0x19BBC380B50; // Unknown = 
    inline constexpr uintptr_t FFlagPeoplePageFlipVolumePopoverToFitViewport = 0x19BBC380890; // Unknown = 
    inline constexpr uintptr_t FFlagPeoplePageLazyRenderCards = 0x19BBC387750; // Unknown = 
    inline constexpr uintptr_t FFlagPeoplePagePostponeInitialRender = 0x19BBC3813D0; // Unknown = 
    inline constexpr uintptr_t FFlagPeoplePageRemoveSkeletons = 0x19BBC38D290; // Unknown = 
    inline constexpr uintptr_t FFlagPeoplePageRemoveUseMemoElements = 0x19BBC381650; // Unknown = 
    inline constexpr uintptr_t FFlagPeopleTabUseProfileFrameThumbnail = 0x19BB7F467DD; // Bool = false
    inline constexpr uintptr_t FFlagPerfInsightsEnabled = 0x19B902905D0; // Unknown = 
    inline constexpr uintptr_t FFlagPermissionAlertContentUpgrade = 0x19BB02C74E5; // Bool = true
    inline constexpr uintptr_t FFlagPhoneUseParentSizeForScreenSize = 0x19BBC384A50; // Unknown = 
    inline constexpr uintptr_t FFlagPhoneVerificationWebviewShouldBeFullscreen1 = 0x19BC0545190; // Unknown = 
    inline constexpr uintptr_t FFlagPlatformEventEnabled2 = 0x19BA59BB710; // Unknown = 
    inline constexpr uintptr_t FFlagPlatformLeaderboardDebugLogging = 0x19BA59B04D0; // Unknown = 
    inline constexpr uintptr_t FFlagPlatformLeaderboardEnabled = 0x19BACE98F10; // Unknown = 
    inline constexpr uintptr_t FFlagPlatformLeaderboardLocalizedUnitEnabled = 0x19BACE9975D; // Bool = false
    inline constexpr uintptr_t FFlagPlatformLeaderboardPersistStoreOnRemount = 0x19B949F9960; // Unknown = 
    inline constexpr uintptr_t FFlagPlatformLeaderboardRccEnabled = 0x19BA59B7FD0; // Unknown = 
    inline constexpr uintptr_t FFlagPlatformLeaderboardRccEnabled2 = 0x19BA59B649D; // Bool = false
    inline constexpr uintptr_t FFlagPlatformLeaderboardsExposure2Enabled_V2 = 0x19BACE9921D; // Bool = false
    inline constexpr uintptr_t FFlagPlatformLeaderboardsIXPNoLeaderboardsShown_V3 = 0x19BACE9991D; // Bool = false
    inline constexpr uintptr_t FFlagPlayStationBumperHint = 0x19BA6A37210; // Unknown = 
    inline constexpr uintptr_t FFlagPlayWithRewardClearOnExperienceLeave = 0x19B9ACB3D90; // Unknown = 
    inline constexpr uintptr_t FFlagPlayWithRewardCoachmarkOverlayFix = 0x19B9ACB4B90; // Unknown = 
    inline constexpr uintptr_t FFlagPlayWithRewardCoachmarkWindowResets = 0x19B90640B1D; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListClosedNoRender = 0x19B8EE05D10; // Unknown = 
    inline constexpr uintptr_t FFlagPlayerListClosedNoRenderWithTenFoot = 0x19B8EE06AD0; // Unknown = 
    inline constexpr uintptr_t FFlagPlayerListDropDownShowPlatformName = 0x19BACE9775D; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListFilterInputServiceDispatches = 0x19BAD285B9D; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListFixLeaderstatsStacking2 = 0x19BBCD7F89D; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListFixMobileScrolling = 0x19BAD284450; // Unknown = 
    inline constexpr uintptr_t FFlagPlayerListFoundationSubscriptionIcon = 0x19BACE97ADD; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListHideUnusedStats = 0x19BACE95D9D; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListIgnoreDevGamepadBindings = 0x19D87043CD0; // Unknown = 
    inline constexpr uintptr_t FFlagPlayerListIgnoreDevGamepadBindings2 = 0x19BACE973DD; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListLocalizeGameText = 0x19BACE97990; // Unknown = 
    inline constexpr uintptr_t FFlagPlayerListPersistVisibility = 0x19BA7DA2C20; // Unknown = 
    inline constexpr uintptr_t FFlagPlayerListReduceRerenders = 0x19BAD28391D; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListRefactorUsernameFormatting = 0x19BB7F4A150; // Unknown = 
    inline constexpr uintptr_t FFlagPlayerListRemoveTopStat = 0x19BA76D370D; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListReskin = 0x19BB6B08165; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListReskin3 = 0x19BACE97CDD; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListSortByLowercaseUsername = 0x19BACE95F1D; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListTopStatCheckGamepad = 0x19BAD285A90; // Unknown = 
    inline constexpr uintptr_t FFlagPlayerListTwoTabs = 0x19BACE97E1D; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListTwoTabsOnLegacy = 0x19BACE97F5D; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListUseFocusNavHook = 0x19BB20A2FDD; // Bool = true
    inline constexpr uintptr_t FFlagPlayerListUseFocusNavHook2 = 0x19BACE963DD; // Bool = false
    inline constexpr uintptr_t FFlagPlayerListUseMobileOnSmallDisplay = 0x19D8704B090; // Unknown = 
    inline constexpr uintptr_t FFlagPlayerListUseMobileOnSmallDisplay2 = 0x19BACE96250; // Unknown = 
    inline constexpr uintptr_t FFlagPlayerSearchEnableOnlineFrequents = 0x19BA59B01D0; // Unknown = 
    inline constexpr uintptr_t FFlagPlayerSearchEnableOnlineFrequentsForAll = 0x19BA59B2C50; // Unknown = 
    inline constexpr uintptr_t FFlagPlayerViewRemoteEnabled = 0x19B9F924D9D; // Bool = false
    inline constexpr uintptr_t FFlagPlaytestModeExcludeStudio = 0x19BBBFF4A6D; // Bool = false
    inline constexpr uintptr_t FFlagPopularFillIconEnabled = 0x19BAC833390; // Unknown = 
    inline constexpr uintptr_t FFlagPreHomePageRoutingEnabled = 0x19B945AEF90; // Unknown = 
    inline constexpr uintptr_t FFlagPreciseSelectionBugfixesEnabled = 0x19BBB7FEB90; // Unknown = 
    inline constexpr uintptr_t FFlagPrefetchFriendGameMedia = 0x19BBF84F5C8; // Unknown = 
    inline constexpr uintptr_t FFlagPrefetchProfileNamesOnStartup_v2 = 0x19BAFCFBB90; // Unknown = 
    inline constexpr uintptr_t FFlagPrefillPreciseSelectionChoices = 0x19B8C30DD90; // Unknown = 
    inline constexpr uintptr_t FFlagPreselectedPlayerReportBugfix = 0x19BB7F490D0; // Unknown = 
    inline constexpr uintptr_t FFlagPresencePropagationDelayMonitoringEnabledV2 = 0x19B90290510; // Unknown = 
    inline constexpr uintptr_t FFlagPreventHiddenSwitchPage = 0x19BA6C3CDC5; // Bool = true
    inline constexpr uintptr_t FFlagPreventMicToggleIfGameConsumedEvent = 0x19BBCD70110; // Unknown = 
    inline constexpr uintptr_t FFlagPreventSuperBriefPeekViewClose2 = 0x19BC0549ED0; // Unknown = 
    inline constexpr uintptr_t FFlagPriceSummaryV2UseLocalizedBreakdown = 0x19BAE780E8D; // Bool = true
    inline constexpr uintptr_t FFlagProfileAboutDetailsUseSheet = 0x19B8C2EA950; // Unknown = 
    inline constexpr uintptr_t FFlagProfileContextualMenuDisableFix = 0x19B8C2EC8D0; // Unknown = 
    inline constexpr uintptr_t FFlagProfileEnableSocialNetworksUsernames = 0x19BACFDA250; // Unknown = 
    inline constexpr uintptr_t FFlagProfileFixMenuNavigation = 0x19BAEE1E750; // Unknown = 
    inline constexpr uintptr_t FFlagProfileFixMenuNavigation_V2 = 0x19B8C2ECA10; // Unknown = 
    inline constexpr uintptr_t FFlagProfileFrameThumbnailEnabled = 0x19BACFD8B10; // Unknown = 
    inline constexpr uintptr_t FFlagProfileHideTabBarOnAboutSheet = 0x19B90641510; // Unknown = 
    inline constexpr uintptr_t FFlagProfileInspectAndBuyRefactorTooltip = 0x19BB7F4CA50; // Unknown = 
    inline constexpr uintptr_t FFlagProfileInspectAvatarCWEntry = 0x19BB7F42510; // Unknown = 
    inline constexpr uintptr_t FFlagProfileMomentsFeedHideTabBar = 0x19B90641890; // Unknown = 
    inline constexpr uintptr_t FFlagProfileMomentsFeedRootRoute = 0x19B9AF13F10; // Unknown = 
    inline constexpr uintptr_t FFlagProfileMomentsOrderingAndReactions = 0x19B8C2EB850; // Unknown = 
    inline constexpr uintptr_t FFlagProfileMomentsVideoPlaybackFix = 0x19B8C2EBA90; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformAboutBeforeActionClient = 0x19B825F4F50; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformAddCurrentlyPlaying_V4 = 0x19B825F1B70; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformAddTC = 0x19BAEE1D150; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformAddTC_v10 = 0x19B8C2EC210; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformCTAsRefactor = 0x19D7C7C2CD0; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformCTAsRefactor_V3 = 0x19B81F0FED0; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformEditBackgroundMenuItem = 0x19B859CBAD0; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformEnableAvatarBackground = 0x19BA59B3F1D; // Bool = false
    inline constexpr uintptr_t FFlagProfilePlatformEnableBundlesInAssetsCarousel = 0x19BACFD3410; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformEnableChipSocialRow_v6 = 0x19B825F30BD; // Bool = true
    inline constexpr uintptr_t FFlagProfilePlatformEnableClickToCopyUsername = 0x19B825FEC3D; // Bool = true
    inline constexpr uintptr_t FFlagProfilePlatformEnableCoverPhotoPeekViewFix_v2 = 0x19B8EAE95F0; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformEnableCurrencyTransfer = 0x19BAEE12110; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformEnableCurrencyTransferV1 = 0x19B8C2EB49D; // Bool = false
    inline constexpr uintptr_t FFlagProfilePlatformEnableEditAppearanceMenu = 0x19B859CBCDD; // Bool = false
    inline constexpr uintptr_t FFlagProfilePlatformEnableImpressions = 0x19B8C2E9510; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformEnableInventory = 0x19BAEE1AD90; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformEnableInventory_V2 = 0x19B8C2EA250; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformEnableLazyLoadingComponents = 0x19BB7F4A550; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformEnableLazyLoadingComponentsV5 = 0x19B859CB2DD; // Bool = false
    inline constexpr uintptr_t FFlagProfilePlatformEnableMoments = 0x19B859CB7D0; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformEnableSchoolChip = 0x19B8C2EB190; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformEnableStore = 0x19BAEE13B1D; // Bool = false
    inline constexpr uintptr_t FFlagProfilePlatformEnableStore_V2 = 0x19B8C2E9FD0; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformEnableTradeItems = 0x19B859CBE9D; // Bool = false
    inline constexpr uintptr_t FFlagProfilePlatformEnableUnlockChat_V2 = 0x19B825F27FD; // Bool = true
    inline constexpr uintptr_t FFlagProfilePlatformEnableVR = 0x19BBBFF5EA5; // Bool = true
    inline constexpr uintptr_t FFlagProfilePlatformEnableVR_v2 = 0x19BBBFF5E2D; // Bool = false
    inline constexpr uintptr_t FFlagProfilePlatformFavoritesEnableGameDetailAnalytics = 0x19BACFD2B50; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformFixPresenceReducer = 0x19B859CB610; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformImproveGameDetailsAnalytics = 0x19BACFD3550; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformMeTabMobileProfileHero = 0x19D812E7108; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformNewAboutSection_v9 = 0x19B825F51D0; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformNewProfileHeader = 0x19BAEE12AD0; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformNewProfileHeader_v4 = 0x19B8C2EBFD0; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformPassPresenceToJoinUserInExperience = 0x19B8C2EC190; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformPeekDraggerContrast = 0x19B8C2EB7D0; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformPresenceStoreMigration = 0x19BB7F4F810; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformPresenceStoreMigration_v1 = 0x19B859CB09D; // Bool = false
    inline constexpr uintptr_t FFlagProfilePlatformTrustedConnectionsMVP = 0x19B8C2EBD90; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformUseCatalogItemOpenedNewFields = 0x19BB7F41990; // Unknown = 
    inline constexpr uintptr_t FFlagProfilePlatformUseNewLayoutForAssetsCarousel = 0x19D80F5AAF5; // Bool = false
    inline constexpr uintptr_t FFlagProfilePlatformUseProfileTypeContext = 0x19B9029171D; // Bool = true
    inline constexpr uintptr_t FFlagProfilePlatformUseRoduxNetworkingRefactor = 0x19B859CC05D; // Bool = false
    inline constexpr uintptr_t FFlagProfileQRCodeFixFocusNavigation = 0x19BAFCF67D0; // Unknown = 
    inline constexpr uintptr_t FFlagProfileQrCodeDeprecateUserRedux = 0x19BAFCF9990; // Unknown = 
    inline constexpr uintptr_t FFlagPromptBannerWaitInSmallIntervals = 0x19B9481045D; // Bool = false
    inline constexpr uintptr_t FFlagPromptCreatorTransientDialog = 0x19BA6076FDD; // Bool = true
    inline constexpr uintptr_t FFlagPromptFriendRequestModalRevampFriendsRename = 0x19BA6077D10; // Unknown = 
    inline constexpr uintptr_t FFlagPromptPurchaseClearStateOnCompletion = 0x19D85DC65D0; // Unknown = 
    inline constexpr uintptr_t FFlagPromptsHandlerCoachmarkEnabled = 0x19BC0544BD0; // Unknown = 
    inline constexpr uintptr_t FFlagPromptsHandlerEnabled = 0x19BC0548CD0; // Unknown = 
    inline constexpr uintptr_t FFlagPromptsHandlerEnabled2 = 0x19BC0543790; // Unknown = 
    inline constexpr uintptr_t FFlagPromptsImpressionUsesTitle = 0x19BC0548350; // Unknown = 
    inline constexpr uintptr_t FFlagPurchaseModalTimedOptionExtension = 0x19B9AF1C550; // Unknown = 
    inline constexpr uintptr_t FFlagPurchasePromptAppConditionalFocusNavigation = 0x19B9EE0299D; // Bool = false
    inline constexpr uintptr_t FFlagPurchasePromptAppFixStyleLink = 0x19B9EE02C5D; // Bool = false
    inline constexpr uintptr_t FFlagPurchasePromptAppTrackRenderPerformance = 0x19B9EE02B1D; // Bool = false
    inline constexpr uintptr_t FFlagPurchasePromptCartPricingEnabled = 0x19D85DCEC90; // Unknown = 
    inline constexpr uintptr_t FFlagPurchasePromptCartPricingRequireOffer2 = 0x19B8F906D9D; // Bool = false
    inline constexpr uintptr_t FFlagPurchasePromptCartPricingSkipFreeItems2 = 0x19B9F18D03D; // Bool = true
    inline constexpr uintptr_t FFlagPurchasePromptCartPricingSkipLimitedCollectibles = 0x19D80F1C128; // Unknown = 
    inline constexpr uintptr_t FFlagPurchasePromptCartPricingSkipLimitedCollectibles2 = 0x19B8F906C5D; // Bool = false
    inline constexpr uintptr_t FFlagPurchasePromptElevateDisplayOrder = 0x19B9EE0301D; // Bool = false
    inline constexpr uintptr_t FFlagPurchasePromptFetchCartPricing = 0x19B9AF1F310; // Unknown = 
    inline constexpr uintptr_t FFlagPurchasePromptFetchCartPricing2 = 0x19B9AF1F290; // Unknown = 
    inline constexpr uintptr_t FFlagPurchasePromptFetchCartPricingForLooks = 0x19B9AF1DAD0; // Unknown = 
    inline constexpr uintptr_t FFlagPurchasePromptFetchCartPricingForLooks2 = 0x19B9AF1D710; // Unknown = 
    inline constexpr uintptr_t FFlagPurchasePromptFixOfferMarginUpsell = 0x19B9AF1D810; // Unknown = 
    inline constexpr uintptr_t FFlagPurchasePromptOfferMarginUpsellEnabled = 0x19D85DC8EDD; // Bool = false
    inline constexpr uintptr_t FFlagPurchasePromptPreviewMakeupHead = 0x19BACE7E4DD; // Bool = false
    inline constexpr uintptr_t FFlagPurchasePromptPriceShouldUseProductInfoPrice = 0x19D85DC5150; // Unknown = 
    inline constexpr uintptr_t FFlagPurchasePromptPriceShouldUseProductInfoPrice4 = 0x19D85DCC7D0; // Unknown = 
    inline constexpr uintptr_t FFlagPurchasePromptSubtitleForTimedOptions = 0x19B9AF1CD10; // Unknown = 
    inline constexpr uintptr_t FFlagPurchasePromptSubtitleForTimedOptions2 = 0x19B9AF1CB90; // Unknown = 
    inline constexpr uintptr_t FFlagPurchasePromptUnifiedEventsUseOfferAdjustedPrice = 0x19B9AF1E150; // Unknown = 
    inline constexpr uintptr_t FFlagPymkCarouselPresenceStoreMigration_v2 = 0x19B8FC3A150; // Unknown = 
    inline constexpr uintptr_t FFlagQRCodeCopyUpdates_v2 = 0x19B8C30301D; // Bool = true
    inline constexpr uintptr_t FFlagQRCodeFriendRequestNotificationV2 = 0x19BAFCF4BD0; // Unknown = 
    inline constexpr uintptr_t FFlagQRCodeItemRedemptionEnabled = 0x19B9026FAD0; // Unknown = 
    inline constexpr uintptr_t FFlagQRCodeScannerDeeplinkEnabledForAll = 0x19BACFDF410; // Unknown = 
    inline constexpr uintptr_t FFlagQRInSearchProfileQR = 0x19BA8447550; // Unknown = 
    inline constexpr uintptr_t FFlagQRInSearchScanner = 0x19BBB794ABD; // Bool = false
    inline constexpr uintptr_t FFlagRAEnableCircleRegion = 0x19BA6A3D9D0; // Unknown = 
    inline constexpr uintptr_t FFlagRAKickLogic2 = 0x19BA672D75D; // Bool = false
    inline constexpr uintptr_t FFlagRateLimitNudgeDialog = 0x19BACE787DD; // Bool = false
    inline constexpr uintptr_t FFlagRateLimitNudgeToast = 0x19BACE786DD; // Bool = false
    inline constexpr uintptr_t FFlagRateLimitTimeoutDialog = 0x19BACE7885D; // Bool = false
    inline constexpr uintptr_t FFlagRateLimitTimeoutToast = 0x19BACE7875D; // Bool = false
    inline constexpr uintptr_t FFlagReactCatchYieldingInDEV = 0x19BA5538A90; // Unknown = 
    inline constexpr uintptr_t FFlagReactCleanQueueOnUpdateBailout = 0x19B90295490; // Unknown = 
    inline constexpr uintptr_t FFlagReactDevtoolsFixTopbar = 0x19BACFED19D; // Bool = false
    inline constexpr uintptr_t FFlagReactEnableNewTreeCleanupPath = 0x19BA55347D0; // Unknown = 
    inline constexpr uintptr_t FFlagReactEnableSchedulingProfiler = 0x19BA5535FD0; // Unknown = 
    inline constexpr uintptr_t FFlagReactFilterInternalStackFrames = 0x19BA553E410; // Unknown = 
    inline constexpr uintptr_t FFlagReactFixBindingMemoryLeak = 0x19BA553345D; // Bool = true
    inline constexpr uintptr_t FFlagReactInlineMergeLanes = 0x19BA5537E9D; // Bool = true
    inline constexpr uintptr_t FFlagReactInstanceMapDisableErrorChecking = 0x19BA5533990; // Unknown = 
    inline constexpr uintptr_t FFlagReactIsProtectedTypeOf = 0x19B9CB7A85D; // Bool = false
    inline constexpr uintptr_t FFlagReactIsolatedGlobalsEnabled = 0x19B9F184FBD; // Bool = true
    inline constexpr uintptr_t FFlagReactPreventAssigningKeyToChildren = 0x19B90295310; // Unknown = 
    inline constexpr uintptr_t FFlagReactSchedulerEnableDeferredWork = 0x19BA553B09D; // Bool = false
    inline constexpr uintptr_t FFlagReactSchedulerLookbackUseRingBuffer = 0x19BA553211D; // Bool = true
    inline constexpr uintptr_t FFlagReactSchedulerSetFrameMarkerOnHeartbeatEnd = 0x19BA5538250; // Unknown = 
    inline constexpr uintptr_t FFlagReactSchedulerSetTargetMsByHeartbeatDelta = 0x19BA5532A9D; // Bool = false
    inline constexpr uintptr_t FFlagReactSchedulingTrackerDataModelUpdate = 0x19BBCCCC2DD; // Bool = false
    inline constexpr uintptr_t FFlagReactSchedulingTrackerLayoutEffects = 0x19BBC7A9D50; // Unknown = 
    inline constexpr uintptr_t FFlagReactTelemetryEnabled = 0x19B9ACB399D; // Bool = true
    inline constexpr uintptr_t FFlagReadAppChatFetchingVariable = 0x19BACFD4A50; // Unknown = 
    inline constexpr uintptr_t FFlagRealNamesInDisplayNamesEnabledForAll = 0x19B90642090; // Unknown = 
    inline constexpr uintptr_t FFlagReducePromiseTaskDefer = 0x19B8C2E5590; // Unknown = 
    inline constexpr uintptr_t FFlagReduceTopBarInsetsWhileHidden = 0x19B9ACB9190; // Unknown = 
    inline constexpr uintptr_t FFlagRefactorButtonTileCircular = 0x19BACFDED10; // Unknown = 
    inline constexpr uintptr_t FFlagRefactorHelpPage = 0x19BBF252F9D; // Bool = false
    inline constexpr uintptr_t FFlagRefactorHelpPage5 = 0x19BAC87309D; // Bool = false
    inline constexpr uintptr_t FFlagRefactorInExpSettingsInDevelopment = 0x19BACE9C21D; // Bool = false
    inline constexpr uintptr_t FFlagRefactorMenuConfirmationButtons = 0x19B9FDDAF15; // Bool = false
    inline constexpr uintptr_t FFlagRefactorMenuConfirmationButtons5 = 0x19BA515B61D; // Bool = false
    inline constexpr uintptr_t FFlagRefactorPeoplePage = 0x19B9FDDAF95; // Bool = false
    inline constexpr uintptr_t FFlagRefactorPeoplePage9 = 0x19B8EDBA13D; // Bool = false
    inline constexpr uintptr_t FFlagRefactorReconnectUnblockTeleport = 0x19BA672C51D; // Bool = false
    inline constexpr uintptr_t FFlagRefreshAuthSessionAfterLanguageChange = 0x19B9ACBA1D0; // Unknown = 
    inline constexpr uintptr_t FFlagRefreshDevSubPriceOnRetryAfterUpsell2 = 0x19D85DC49D0; // Unknown = 
    inline constexpr uintptr_t FFlagRefreshLookPriceOnRetryAfterUpsell = 0x19D85DC0C9D; // Bool = false
    inline constexpr uintptr_t FFlagRefreshPriceOnRetryAfterUpsell = 0x19D85DC6310; // Unknown = 
    inline constexpr uintptr_t FFlagRegisterQRCodeKeyInEngine = 0x19BACFD2010; // Unknown = 
    inline constexpr uintptr_t FFlagRegisterQRCodeKeyInEngine_v2 = 0x19BACFD96DD; // Bool = true
    inline constexpr uintptr_t FFlagRelocateMobileMenuButtons = 0x19B9FDDAFD5; // Bool = false
    inline constexpr uintptr_t FFlagRelocateMobileMenuButtons4 = 0x19BA515A9D0; // Unknown = 
    inline constexpr uintptr_t FFlagReminderAPIFetchErrorLogging = 0x19B948125DD; // Bool = false
    inline constexpr uintptr_t FFlagRemoveAcountInfoFetchFromPurchase = 0x19D85DB6280; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveAssetVersionEndpoint = 0x19BACE9C8DD; // Bool = false
    inline constexpr uintptr_t FFlagRemoveAvatarSwitcherIfUnsupported = 0x19B88C4E110; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveBottomNavOnLookDetails = 0x19B9AF15250; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveCentralOverlayBackgroundSafeArea = 0x19B9064999D; // Bool = false
    inline constexpr uintptr_t FFlagRemoveCentralOverlayScrimForUnifiedPurchaseModal = 0x19B9ACB1150; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveClassicHeadsAndFaces = 0x19BA3A5C4DD; // Bool = false
    inline constexpr uintptr_t FFlagRemoveDataLoaderTimer = 0x19B8C2E9CD0; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveDelayedInputForUnifiedPurchaseModal = 0x19B9EE00D9D; // Bool = false
    inline constexpr uintptr_t FFlagRemoveDiscoverabilityModal = 0x19B90294E90; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveExitModal = 0x19B9FDDB015; // Bool = false
    inline constexpr uintptr_t FFlagRemoveFetchFriendsCarouselAtStartup = 0x19B90267090; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveFriendsChatUnibarEntrypoints = 0x19B8C2E2B5D; // Bool = false
    inline constexpr uintptr_t FFlagRemoveHardCodedFriendLimitPrompt = 0x19BACFEA510; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveHttpErrorLog2 = 0x19B90292AD0; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveKeystoreIxpLogic = 0x19B9ACB4810; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveLeaveShortcutFromLeaveConfirm = 0x19BA7FCB848; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveLoadingTimeout = 0x19BBC38A2D5; // Bool = false
    inline constexpr uintptr_t FFlagRemoveLoggingHookForCorescriptGlobalEffects2 = 0x19B9F921B50; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveMobileHomeProfileHeader_v2 = 0x19B94811590; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveNameRegex = 0x19B9EE0321D; // Bool = false
    inline constexpr uintptr_t FFlagRemoveNewPlayerListOverlay = 0x19BACE96C9D; // Bool = false
    inline constexpr uintptr_t FFlagRemovePeekViewScrimBorder = 0x19BBC7A3490; // Unknown = 
    inline constexpr uintptr_t FFlagRemovePhoneUpsellWebview = 0x19B90294E10; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveRecordPage = 0x19BACE9C3DD; // Bool = false
    inline constexpr uintptr_t FFlagRemoveRefToMissingLocInConnection = 0x19BBC38AF50; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveRespawnShortcutFromRespawnConfirmation = 0x19BA7FC4F48; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveUnusedConnectionStateRoduxSlice = 0x19B9AF190D0; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveUnusedFriendStatusesRoduxSlice = 0x19B9AF19210; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveUnusedGameThumbnailsRoduxSlice = 0x19B9AF18110; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveUnusedLoginResultRoduxSlice = 0x19B9AF18390; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveUnusedRoactChatRoduxSlice = 0x19B8C2E2390; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveUnusedSignUpInfoRoduxSlice = 0x19B9AF18CD0; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveUnusedUserStatusesRoduxSlice = 0x19B9AF18550; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveUnusedUsersAsyncRoduxSlice = 0x19B9AF18750; // Unknown = 
    inline constexpr uintptr_t FFlagRemoveVirtualEventsExperiment = 0x19B857882D0; // Unknown = 
    inline constexpr uintptr_t FFlagRenameAvatarToMe = 0x19B9AF14F90; // Unknown = 
    inline constexpr uintptr_t FFlagRenameDeprecatedUIBloxTokens3 = 0x19B85788690; // Unknown = 
    inline constexpr uintptr_t FFlagRenameParentEmailForVerificationUpsell = 0x19B8C30B7DD; // Bool = true
    inline constexpr uintptr_t FFlagRenameRespawnConfirmationPage = 0x19BBCD7165D; // Bool = false
    inline constexpr uintptr_t FFlagRenameVolumeToMainVolume = 0x19B9FD8BE95; // Bool = false
    inline constexpr uintptr_t FFlagRenderChatConversationOnlyWhenVisible = 0x19BACE7F090; // Unknown = 
    inline constexpr uintptr_t FFlagRenderChatConversationOnlyWhenVisible3 = 0x19BACE7BE50; // Unknown = 
    inline constexpr uintptr_t FFlagRenderPeoplePageOnTabSwitch = 0x19BB7F4B71D; // Bool = false
    inline constexpr uintptr_t FFlagRenderUseTextureManager224 = 0x19B9B16003D; // Bool = false
    inline constexpr uintptr_t FFlagReplaceChatLineReportingIcon = 0x19BA5153EDD; // Bool = false
    inline constexpr uintptr_t FFlagReplaceMissingDesignTokens = 0x19B945A0455; // Bool = false
    inline constexpr uintptr_t FFlagReplaceNavbarIconsWithFoundation = 0x19B9AF13F90; // Unknown = 
    inline constexpr uintptr_t FFlagReplacePlayerIconRoduxWithSignal_2 = 0x19B88C4FCDD; // Bool = false
    inline constexpr uintptr_t FFlagReportAbuseMenuEntrypointAnalytics = 0x19BACE9CF1D; // Bool = false
    inline constexpr uintptr_t FFlagReportAnythingAnnotationIXP = 0x19B8C30B29D; // Bool = true
    inline constexpr uintptr_t FFlagReportAnythingDebugCanvas = 0x19D81681850; // Unknown = 
    inline constexpr uintptr_t FFlagReportAnythingEnableAdReport = 0x19BA6A32E90; // Unknown = 
    inline constexpr uintptr_t FFlagReportAnythingFixConvexHullCalculation = 0x19BAC87FEDD; // Bool = false
    inline constexpr uintptr_t FFlagReportAnythingLocalizationEnabled = 0x19D8168E5D0; // Unknown = 
    inline constexpr uintptr_t FFlagReportAnythingMultistepScreenshot = 0x19D81683490; // Unknown = 
    inline constexpr uintptr_t FFlagReportAnythingScreenshot = 0x19D81683C50; // Unknown = 
    inline constexpr uintptr_t FFlagReportFirstExperienceCancelled = 0x19BA6728D1D; // Bool = false
    inline constexpr uintptr_t FFlagReportFocusNavIEMButtons = 0x19B9FD8F895; // Bool = false
    inline constexpr uintptr_t FFlagReportFocusNavIEMButtons2 = 0x19BBB7FA390; // Unknown = 
    inline constexpr uintptr_t FFlagReportListRadioSelectable = 0x19BB7F4FE50; // Unknown = 
    inline constexpr uintptr_t FFlagReportNotificationStreamCTA = 0x19B94810610; // Unknown = 
    inline constexpr uintptr_t FFlagRepositionDropDownScrim = 0x19BA515B75D; // Bool = false
    inline constexpr uintptr_t FFlagRepositionInExperienceVRToasts = 0x19BA67212DD; // Bool = false
    inline constexpr uintptr_t FFlagRespawnActionChromeShortcutTelemetry = 0x19B9FD87495; // Bool = false
    inline constexpr uintptr_t FFlagRespawnChromeShortcutTelemetry = 0x19BA7FC9FE8; // Unknown = 
    inline constexpr uintptr_t FFlagRespectBalanceInfoForBundleUpsellInStudio = 0x19D85DC7090; // Unknown = 
    inline constexpr uintptr_t FFlagResponsiveUnitsProfileHeader = 0x19BB7F4B790; // Unknown = 
    inline constexpr uintptr_t FFlagRetryAfterUpsellV2 = 0x19D85DC3890; // Unknown = 
    inline constexpr uintptr_t FFlagReworkPurchaseRobuxPage = 0x19B906437D0; // Unknown = 
    inline constexpr uintptr_t FFlagRoactPolicyLoggerName = 0x19BB6BB2C1D; // Bool = false
    inline constexpr uintptr_t FFlagRobloxExperienceKickOverride = 0x19BBC38AD50; // Unknown = 
    inline constexpr uintptr_t FFlagRobloxPlusAmpSubscriptionCheck = 0x19B8FC33E5D; // Bool = false
    inline constexpr uintptr_t FFlagRobloxPlusFAEFreeTrial = 0x19BC054DADD; // Bool = true
    inline constexpr uintptr_t FFlagRobloxPlusUpdateDiscountIcons = 0x19B9F18196D; // Bool = true
    inline constexpr uintptr_t FFlagRobloxPlusUpsellRefreshOnComplete = 0x19BC05455DD; // Bool = true
    inline constexpr uintptr_t FFlagRobuxBadgeEnabled = 0x19B9026911D; // Bool = false
    inline constexpr uintptr_t FFlagRobuxIconColorHotfix = 0x19B94810950; // Unknown = 
    inline constexpr uintptr_t FFlagRoduxRemoveConnectTraceback = 0x19BA6C40C50; // Unknown = 
    inline constexpr uintptr_t FFlagRoduxSignalsNavigationMigration2 = 0x19B85785BDD; // Bool = false
    inline constexpr uintptr_t FFlagRoutePremiumToBlackbirdUpsell = 0x19D85DC9AD0; // Unknown = 
    inline constexpr uintptr_t FFlagSAToolEquipLuauFlag = 0x19BA6078BD0; // Unknown = 
    inline constexpr uintptr_t FFlagScopeBadUtterancePlayerNameToChatDialogs = 0x19BA80287D0; // Unknown = 
    inline constexpr uintptr_t FFlagScopedSubscribersForPermissionsProtocol2 = 0x19BB6BBC4D0; // Unknown = 
    inline constexpr uintptr_t FFlagScriptProfilerShowPlugins2 = 0x19BACFE445D; // Bool = false
    inline constexpr uintptr_t FFlagSduiActionSequence = 0x19B88C2121D; // Bool = false
    inline constexpr uintptr_t FFlagSduiActionSkipUnifiedLogging = 0x19B9F189CF5; // Bool = true
    inline constexpr uintptr_t FFlagSduiActionTelemetryHandler2 = 0x19B9F1897FD; // Bool = true
    inline constexpr uintptr_t FFlagSduiActionsUpdateFiresOwnTelemetry = 0x19B88C2995D; // Bool = false
    inline constexpr uintptr_t FFlagSduiAddMarketplaceEntityDataHydration = 0x19B88C20E9D; // Bool = false
    inline constexpr uintptr_t FFlagSduiAgeCheckUpsellRaisePeekViewBriefHeight = 0x19BC054689D; // Bool = true
    inline constexpr uintptr_t FFlagSduiAiOverviewEnabled = 0x19B88C23E10; // Unknown = 
    inline constexpr uintptr_t FFlagSduiAllowNoConfigsBuilt = 0x19BC054FB5D; // Bool = true
    inline constexpr uintptr_t FFlagSduiAlwaysCacheWithIdentifier = 0x19BBB316AD0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiAlwaysCacheWithIdentifier3 = 0x19B8C30F190; // Unknown = 
    inline constexpr uintptr_t FFlagSduiApiStoreExposeGetInputData = 0x19BA5531690; // Unknown = 
    inline constexpr uintptr_t FFlagSduiApiStoreOnSuccessAndRefresh = 0x19BA5533C10; // Unknown = 
    inline constexpr uintptr_t FFlagSduiAppPolicyBindings = 0x19B8C30FB9D; // Bool = true
    inline constexpr uintptr_t FFlagSduiArrayMapSupport = 0x19B945A3D50; // Unknown = 
    inline constexpr uintptr_t FFlagSduiBadgeComponent = 0x19B9011EC10; // Unknown = 
    inline constexpr uintptr_t FFlagSduiCapabilityBindings2 = 0x19B8C30FC1D; // Bool = true
    inline constexpr uintptr_t FFlagSduiCapabilityDevStoreSeeAllWebviewFallback = 0x19B8C30FD1D; // Bool = true
    inline constexpr uintptr_t FFlagSduiCardComponent = 0x19BBB31F290; // Unknown = 
    inline constexpr uintptr_t FFlagSduiCardComponent_v3 = 0x19B88C26D1D; // Bool = true
    inline constexpr uintptr_t FFlagSduiCarouselUseNestedImpressionsFeedContext = 0x19B88C23410; // Unknown = 
    inline constexpr uintptr_t FFlagSduiCatalogCategoryMenu = 0x19B88C26550; // Unknown = 
    inline constexpr uintptr_t FFlagSduiCatalogItemGrid = 0x19B88C20B9D; // Bool = false
    inline constexpr uintptr_t FFlagSduiCatalogVirtualizedFeed = 0x19BBB31EA50; // Unknown = 
    inline constexpr uintptr_t FFlagSduiCatalogVirtualizedFeed4 = 0x19B88C26790; // Unknown = 
    inline constexpr uintptr_t FFlagSduiChartsAnalyticsPage = 0x19B90293290; // Unknown = 
    inline constexpr uintptr_t FFlagSduiChartsDedupSessionRotation = 0x19B88C28D5D; // Bool = false
    inline constexpr uintptr_t FFlagSduiChartsPlaceholderMergeStrategySupport = 0x19BA553BB90; // Unknown = 
    inline constexpr uintptr_t FFlagSduiChartsPostBody = 0x19B88C28E5D; // Bool = false
    inline constexpr uintptr_t FFlagSduiChartsRequestPlaceholders = 0x19B9F181BE5; // Bool = true
    inline constexpr uintptr_t FFlagSduiChartsResetSessionOnRefresh = 0x19B88C28C1D; // Bool = false
    inline constexpr uintptr_t FFlagSduiChartsSortDetailGenreFilter = 0x19B88C2899D; // Bool = false
    inline constexpr uintptr_t FFlagSduiChartsSupport2 = 0x19BA5535D50; // Unknown = 
    inline constexpr uintptr_t FFlagSduiChipAccessoryProps = 0x19B85789AD0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiClientPageScope2 = 0x19BA5539C50; // Unknown = 
    inline constexpr uintptr_t FFlagSduiClientTemplateCache = 0x19B8578719D; // Bool = false
    inline constexpr uintptr_t FFlagSduiCoachmarkComponent = 0x19B906417DD; // Bool = false
    inline constexpr uintptr_t FFlagSduiCollectionCarouselOverrides = 0x19B88C2941D; // Bool = false
    inline constexpr uintptr_t FFlagSduiCollectionCarouselPlaceholderItem = 0x19B88C2925D; // Bool = false
    inline constexpr uintptr_t FFlagSduiCollectionGridMaxNumRows = 0x19B8C30F61D; // Bool = true
    inline constexpr uintptr_t FFlagSduiCommunitySectionSupport = 0x19B8C30E210; // Unknown = 
    inline constexpr uintptr_t FFlagSduiConfigFetchTakesPostBody = 0x19B8578709D; // Bool = false
    inline constexpr uintptr_t FFlagSduiCreateSocialTelemetryRegistries = 0x19B90641B5D; // Bool = false
    inline constexpr uintptr_t FFlagSduiDataBindingShallowEquals = 0x19B8FC32B10; // Unknown = 
    inline constexpr uintptr_t FFlagSduiDeferredListItems2 = 0x19B8C30F45D; // Bool = true
    inline constexpr uintptr_t FFlagSduiDevStoreSeeAllImpressionsLogging = 0x19B88C29F5D; // Bool = false
    inline constexpr uintptr_t FFlagSduiDevStoreSeeAllSupportDev2 = 0x19BC054B990; // Unknown = 
    inline constexpr uintptr_t FFlagSduiDismissPromptAction = 0x19B8578545D; // Bool = false
    inline constexpr uintptr_t FFlagSduiDividerThemeAwareStroke = 0x19B88C26210; // Unknown = 
    inline constexpr uintptr_t FFlagSduiEdpClientTemplateCache = 0x19B8578721D; // Bool = false
    inline constexpr uintptr_t FFlagSduiEdpInheritGameDetailSourceSession = 0x19B8C30F25D; // Bool = true
    inline constexpr uintptr_t FFlagSduiEdpPageScopeIsTenFoot = 0x19B9026281D; // Bool = false
    inline constexpr uintptr_t FFlagSduiEdpPersistentActionBarPlayButton = 0x19B9F18627D; // Bool = true
    inline constexpr uintptr_t FFlagSduiEdpPersistentActionBarPlayButton2 = 0x19B9F182D3D; // Bool = true
    inline constexpr uintptr_t FFlagSduiEdpPrefetchPlayability = 0x19BC0545610; // Unknown = 
    inline constexpr uintptr_t FFlagSduiEdpStoreImpressionsLogging = 0x19B88C29D9D; // Bool = false
    inline constexpr uintptr_t FFlagSduiEnableAssociatedItemsRow = 0x19B88C26C1D; // Bool = true
    inline constexpr uintptr_t FFlagSduiEnableBackToTop = 0x19B9064145D; // Bool = false
    inline constexpr uintptr_t FFlagSduiEnableClearOnEmptyResponse = 0x19B8FC32410; // Unknown = 
    inline constexpr uintptr_t FFlagSduiEnableHeroUnitBottomRow = 0x19B9011F890; // Unknown = 
    inline constexpr uintptr_t FFlagSduiErrorCleanup = 0x19B8C30F4DD; // Bool = true
    inline constexpr uintptr_t FFlagSduiEventDetailsSupport = 0x19B8C30F55D; // Bool = true
    inline constexpr uintptr_t FFlagSduiEventRsvpFacePile = 0x19B8C30FE1D; // Bool = true
    inline constexpr uintptr_t FFlagSduiExperienceDetailsSocialProof = 0x19BA74E9210; // Unknown = 
    inline constexpr uintptr_t FFlagSduiExperienceDetailsSocialProof_3 = 0x19B8578A010; // Unknown = 
    inline constexpr uintptr_t FFlagSduiExperienceDetailsSupport = 0x19BA553C410; // Unknown = 
    inline constexpr uintptr_t FFlagSduiFavoritesHydrationStructured = 0x19BA553F0D0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiFeatureEntryPointTakesAbsoluteSizeHandler = 0x19B85780AD0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiFeedDebugNameWithImpressionsTag = 0x19B90640190; // Unknown = 
    inline constexpr uintptr_t FFlagSduiFeedIndexInExtraLocalProps = 0x19B906407D0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiFixEmptyRobloxComponentInPropBuilder = 0x19B8C30F8DD; // Bool = true
    inline constexpr uintptr_t FFlagSduiFocusNavActionsStructured = 0x19B88C21BDD; // Bool = false
    inline constexpr uintptr_t FFlagSduiFormatArgFormatters3 = 0x19B88C20790; // Unknown = 
    inline constexpr uintptr_t FFlagSduiGameIconSupport = 0x19BA553D310; // Unknown = 
    inline constexpr uintptr_t FFlagSduiGameItemsComponent = 0x19BC0547510; // Unknown = 
    inline constexpr uintptr_t FFlagSduiGenericContainerDispatch = 0x19B8578525D; // Bool = false
    inline constexpr uintptr_t FFlagSduiGetItemCollectionKeys = 0x19B88C26B5D; // Bool = true
    inline constexpr uintptr_t FFlagSduiGlobalRegistryFallback = 0x19B8578535D; // Bool = false
    inline constexpr uintptr_t FFlagSduiHydrationClientHints = 0x19B85780C90; // Unknown = 
    inline constexpr uintptr_t FFlagSduiHydrationDataCamelCasePropertyKeys = 0x19B85780DD0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiHydrationDataCamelCaseTopLevelKeys = 0x19B8C30FDD0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiHydrationFetchIfMissing = 0x19BA5538C90; // Unknown = 
    inline constexpr uintptr_t FFlagSduiImprovedErrorDimensions = 0x19B88C201D0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiInlineNestedComponentSchema2 = 0x19BA553FB10; // Unknown = 
    inline constexpr uintptr_t FFlagSduiInputDataMergeStrategy = 0x19BA55334D0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiInputDataMergeStrategy2 = 0x19BA5538D10; // Unknown = 
    inline constexpr uintptr_t FFlagSduiIsEmptyConditions = 0x19BA5536550; // Unknown = 
    inline constexpr uintptr_t FFlagSduiLaunchExperienceAction = 0x19BA5536790; // Unknown = 
    inline constexpr uintptr_t FFlagSduiLazyNestedComponentArrayMapItemResolutionSupport = 0x19B8C30F79D; // Bool = true
    inline constexpr uintptr_t FFlagSduiLazyNestedComponentProp = 0x19BA5531210; // Unknown = 
    inline constexpr uintptr_t FFlagSduiLinkActionSharedWebLink = 0x19B8C30F810; // Unknown = 
    inline constexpr uintptr_t FFlagSduiMarketplaceCatalogActions4 = 0x19B88C20CDD; // Bool = false
    inline constexpr uintptr_t FFlagSduiMarketplaceCatalogCategorySupport2 = 0x19B88C207DD; // Bool = false
    inline constexpr uintptr_t FFlagSduiMarketplaceCatalogSortSupport6 = 0x19B88C20A1D; // Bool = false
    inline constexpr uintptr_t FFlagSduiNestedComponentListProp = 0x19B88C20390; // Unknown = 
    inline constexpr uintptr_t FFlagSduiNilHydrationGuard = 0x19BA5530650; // Unknown = 
    inline constexpr uintptr_t FFlagSduiOneofPropSupport = 0x19B88C21B1D; // Bool = false
    inline constexpr uintptr_t FFlagSduiOpenIncomingTransferUpsellAction = 0x19B9AF12750; // Unknown = 
    inline constexpr uintptr_t FFlagSduiOpenSearchResultsTabAction = 0x19B88C2421D; // Bool = false
    inline constexpr uintptr_t FFlagSduiOptionImpressionsEventName = 0x19BB1D92110; // Unknown = 
    inline constexpr uintptr_t FFlagSduiOptionSelectorCollection = 0x19BB1D986D0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiOptionalUniverseHydration = 0x19BA5533890; // Unknown = 
    inline constexpr uintptr_t FFlagSduiOrderedTemplateDataSupport = 0x19B8C30FA9D; // Bool = true
    inline constexpr uintptr_t FFlagSduiPageEntryPointResolvedSlot = 0x19BA5531990; // Unknown = 
    inline constexpr uintptr_t FFlagSduiPageEntrySurfacing = 0x19BC054631D; // Bool = true
    inline constexpr uintptr_t FFlagSduiPageEntryUseSharedHooks = 0x19B85781B10; // Unknown = 
    inline constexpr uintptr_t FFlagSduiPaginatePostBody = 0x19B8578729D; // Bool = false
    inline constexpr uintptr_t FFlagSduiPinShortcutAction = 0x19B9AF12690; // Unknown = 
    inline constexpr uintptr_t FFlagSduiPlayWithReward = 0x19B88C20350; // Unknown = 
    inline constexpr uintptr_t FFlagSduiPlayWithRewardGapFix = 0x19B88C2109D; // Bool = false
    inline constexpr uintptr_t FFlagSduiPoolBackedFeed = 0x19BB1D97C90; // Unknown = 
    inline constexpr uintptr_t FFlagSduiPromptImpressions = 0x19B88C2111D; // Bool = false
    inline constexpr uintptr_t FFlagSduiPropBuilderSupportNilHydration = 0x19B945A2FD0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiPropParsersShouldHandleTokens = 0x19B88C2045D; // Bool = false
    inline constexpr uintptr_t FFlagSduiProtobufJsonDecode = 0x19B88C25D9D; // Bool = true
    inline constexpr uintptr_t FFlagSduiQueryImpressionsLogging = 0x19B9F1845ED; // Bool = true
    inline constexpr uintptr_t FFlagSduiRegisterSocialActions = 0x19B88C2119D; // Bool = false
    inline constexpr uintptr_t FFlagSduiRenderPerf = 0x19B88C20150; // Unknown = 
    inline constexpr uintptr_t FFlagSduiRequestFriendshipAction4 = 0x19B88C247DD; // Bool = true
    inline constexpr uintptr_t FFlagSduiRequestFriendshipActionHandler = 0x19B88C24C5D; // Bool = false
    inline constexpr uintptr_t FFlagSduiRevealTextComponentEnabled = 0x19BC05473D0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiScalePlayButtonAndImageSizes = 0x19B8C30FF5D; // Bool = true
    inline constexpr uintptr_t FFlagSduiSearchPeoplePlayerTileTelemetry = 0x19B9F18889D; // Bool = true
    inline constexpr uintptr_t FFlagSduiSearchResultsPageEnabled = 0x19BA553B6D0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiShimmerTextComponentEnabled = 0x19BC05434D0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiShowToastAction_v2 = 0x19BC054F01D; // Bool = true
    inline constexpr uintptr_t FFlagSduiSocialDataMigrateOffLegacyPresence = 0x19B88C24610; // Unknown = 
    inline constexpr uintptr_t FFlagSduiSrpScrollAway = 0x19B9AF13E90; // Unknown = 
    inline constexpr uintptr_t FFlagSduiSrpShowNavOnNewSearch = 0x19B9AF13E10; // Unknown = 
    inline constexpr uintptr_t FFlagSduiStickyHeaderDividerLayoutOrderConstant = 0x19B9064109D; // Bool = false
    inline constexpr uintptr_t FFlagSduiStringPropToString = 0x19B85780C10; // Unknown = 
    inline constexpr uintptr_t FFlagSduiSubscriptionCellPostPurchaseSync = 0x19B9AF17450; // Unknown = 
    inline constexpr uintptr_t FFlagSduiSupportRatingNoPercent = 0x19BC054A910; // Unknown = 
    inline constexpr uintptr_t FFlagSduiSurfaceBannerAlwaysMounted = 0x19BC0546A50; // Unknown = 
    inline constexpr uintptr_t FFlagSduiSurfaceBannerScrollAwaySticky = 0x19BC0546F10; // Unknown = 
    inline constexpr uintptr_t FFlagSduiSystemBannerComponent = 0x19BC054DA10; // Unknown = 
    inline constexpr uintptr_t FFlagSduiTileBottomButton = 0x19BC0541A10; // Unknown = 
    inline constexpr uintptr_t FFlagSduiTileDisableLegacyHover = 0x19B9011FAD0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiTileHoldAction = 0x19BC05425D0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiTileImagePaddingInset = 0x19BC0547CD0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiTileThumbnailPadding = 0x19BC0540790; // Unknown = 
    inline constexpr uintptr_t FFlagSduiTileTitleTextAlignment = 0x19BA553CC90; // Unknown = 
    inline constexpr uintptr_t FFlagSduiTooltipComponentEnabled = 0x19BC0540750; // Unknown = 
    inline constexpr uintptr_t FFlagSduiUniversalPageEntry = 0x19B8C30F71D; // Bool = true
    inline constexpr uintptr_t FFlagSduiUnwrapStructPropEnvelope = 0x19B88C2061D; // Bool = false
    inline constexpr uintptr_t FFlagSduiUsageTelemetry = 0x19B8C30F3DD; // Bool = true
    inline constexpr uintptr_t FFlagSduiUseInputData = 0x19BA553EED0; // Unknown = 
    inline constexpr uintptr_t FFlagSduiUseSharedUiStatusHook = 0x19B85780B50; // Unknown = 
    inline constexpr uintptr_t FFlagSduiVerticalFeedBottomSpacerLayoutOrderConstant = 0x19B9064155D; // Bool = false
    inline constexpr uintptr_t FFlagSduiVerticalListWithImpressionsEnabled = 0x19B88C23390; // Unknown = 
    inline constexpr uintptr_t FFlagSduiViewContainerRefEnabled = 0x19B88C23190; // Unknown = 
    inline constexpr uintptr_t FFlagSeamlessVoiceConsentToastPolicy = 0x19B8C2E3710; // Unknown = 
    inline constexpr uintptr_t FFlagSeamlessVoiceFTUXV2 = 0x19BACFDC110; // Unknown = 
    inline constexpr uintptr_t FFlagSeamlessVoiceV2JoinVoiceToast = 0x19BA51583D0; // Unknown = 
    inline constexpr uintptr_t FFlagSearchOmniAutocompletePageIXP5 = 0x19B88C4E45D; // Bool = false
    inline constexpr uintptr_t FFlagSearchTopResultsTabEnabledForAll = 0x19BACFDBA90; // Unknown = 
    inline constexpr uintptr_t FFlagSeedAccountThemeFromDisk = 0x19B9AF17090; // Unknown = 
    inline constexpr uintptr_t FFlagSelfViewCameraSettings = 0x19BC0545390; // Unknown = 
    inline constexpr uintptr_t FFlagSelfViewNeckCheck = 0x19BACFEC390; // Unknown = 
    inline constexpr uintptr_t FFlagSelfViewNewPoseSynchronization = 0x19BACFED690; // Unknown = 
    inline constexpr uintptr_t FFlagSelfViewNoApi = 0x19BBCD74C50; // Unknown = 
    inline constexpr uintptr_t FFlagSelfViewVisibilityFix = 0x19BC0542ED0; // Unknown = 
    inline constexpr uintptr_t FFlagSelfieFrontendConsoleDesktop3 = 0x19B9AF11C90; // Unknown = 
    inline constexpr uintptr_t FFlagSendConsentDeniedOnCancel = 0x19B9EE03C1D; // Bool = false
    inline constexpr uintptr_t FFlagSendUserConnectionStatus = 0x19BA5158650; // Unknown = 
    inline constexpr uintptr_t FFlagSendVoiceCapturedDuringVideoCaptureEvent = 0x19B8FDE9750; // Unknown = 
    inline constexpr uintptr_t FFlagSentryIncludeRolloutFlagsContext = 0x19B9F18207D; // Bool = true
    inline constexpr uintptr_t FFlagServerTriggeredModalsAccepts2xxImpressionResponses = 0x19B90294910; // Unknown = 
    inline constexpr uintptr_t FFlagSessionL2ValidationCountResetFix = 0x19B949F9CE0; // Unknown = 
    inline constexpr uintptr_t FFlagSetAliasFixFocusNavigation = 0x19B9011985D; // Bool = false
    inline constexpr uintptr_t FFlagSetMenuOnPurchasePrompt = 0x19B9EE00F1D; // Bool = false
    inline constexpr uintptr_t FFlagSetMenuOnPurchasePrompt3 = 0x19B9EE00F5D; // Bool = false
    inline constexpr uintptr_t FFlagSetRSFNotSelectable = 0x19B94810650; // Unknown = 
    inline constexpr uintptr_t FFlagSetUpBubbleChatConfigurationChildProperties = 0x19BBC381EDD; // Bool = false
    inline constexpr uintptr_t FFlagSettingsHubIndependentBackgroundVisibility = 0x19BACFD58D0; // Unknown = 
    inline constexpr uintptr_t FFlagSettingsHubRaceConditionFix = 0x19B9FD86A9D; // Bool = false
    inline constexpr uintptr_t FFlagShareGameSearchBoxFocusAnalytics = 0x19B9F295DDD; // Bool = false
    inline constexpr uintptr_t FFlagShareGetPlatformTargetImpl = 0x19BC0543C10; // Unknown = 
    inline constexpr uintptr_t FFlagShareSheetTelemetryRefactor = 0x19D7C7CAF50; // Unknown = 
    inline constexpr uintptr_t FFlagShareSheetTelemetryRefactor_Dev2 = 0x19D7C7CF450; // Unknown = 
    inline constexpr uintptr_t FFlagShareTargetGameCleanup = 0x19BA59BDAD0; // Unknown = 
    inline constexpr uintptr_t FFlagShipUnifiedPurchaseFlowToPaidAccess = 0x19B9AF1A290; // Unknown = 
    inline constexpr uintptr_t FFlagShipUnifiedPurchaseInExperience = 0x19B9AF1A110; // Unknown = 
    inline constexpr uintptr_t FFlagShopProductsUseDisplayName = 0x19BAFCFE9D0; // Unknown = 
    inline constexpr uintptr_t FFlagShortcutBarMinSize = 0x19BA6071590; // Unknown = 
    inline constexpr uintptr_t FFlagShortcutUseDispatchSyntheticEvent = 0x19BA607D250; // Unknown = 
    inline constexpr uintptr_t FFlagShouldApplyDevSubsUpsellFix = 0x19BAC8304DD; // Bool = false
    inline constexpr uintptr_t FFlagShouldFixDevSubsFlashingTitle = 0x19BAC83075D; // Bool = false
    inline constexpr uintptr_t FFlagShouldMuteUnlocalizedError = 0x19BA672BE90; // Unknown = 
    inline constexpr uintptr_t FFlagShowAccountUnlockMismatchDialog = 0x19B8C30EC1D; // Bool = true
    inline constexpr uintptr_t FFlagShowAntiHarassmentSettings = 0x19B9FD8B29D; // Bool = false
    inline constexpr uintptr_t FFlagShowConfirmationScreenForOOAP2 = 0x19B88C4E99D; // Bool = false
    inline constexpr uintptr_t FFlagShowContextMenuWhenButtonsArePresent = 0x19D8168BA10; // Unknown = 
    inline constexpr uintptr_t FFlagShowCreatorNameOnEmphasisSearchTileIXP2 = 0x19B9011FEDD; // Bool = false
    inline constexpr uintptr_t FFlagShowDOTADogfoodSiteMessage = 0x19B9029F450; // Unknown = 
    inline constexpr uintptr_t FFlagShowDevicePermissionsModal3 = 0x19B88C4E7DD; // Bool = false
    inline constexpr uintptr_t FFlagShowFAELoadingModalForWebView = 0x19B90112E9D; // Bool = false
    inline constexpr uintptr_t FFlagShowGameAgeRating = 0x19B9AF19A50; // Unknown = 
    inline constexpr uintptr_t FFlagShowInvoluntarilySignedOutAccounts = 0x19B88C4C410; // Unknown = 
    inline constexpr uintptr_t FFlagShowJoinVoiceRaceConditionFix = 0x19BA3662EC8; // Unknown = 
    inline constexpr uintptr_t FFlagShowJoinVoiceWhenDisconnectedV3 = 0x19BA5159CDD; // Bool = false
    inline constexpr uintptr_t FFlagShowScreentimeLockoutKickMessage = 0x19BA672C11D; // Bool = false
    inline constexpr uintptr_t FFlagShowStartupMessageOnUnhide = 0x19B8F908A1D; // Bool = false
    inline constexpr uintptr_t FFlagShowSwitchServerButton = 0x19BBC387990; // Unknown = 
    inline constexpr uintptr_t FFlagShowSwitchServerButton2 = 0x19BBC384910; // Unknown = 
    inline constexpr uintptr_t FFlagShowTeleportHistoryFrontButton = 0x19BAC873CDD; // Bool = false
    inline constexpr uintptr_t FFlagShowUnibarOnVirtualCursor = 0x19B9ACB46D0; // Unknown = 
    inline constexpr uintptr_t FFlagShrinkAppNavBar = 0x19B9ACB0C50; // Unknown = 
    inline constexpr uintptr_t FFlagSideSheetAndroidBack = 0x19BACE9DDDD; // Bool = false
    inline constexpr uintptr_t FFlagSideSheetFocusNav_DEV = 0x19B9ACB07D0; // Unknown = 
    inline constexpr uintptr_t FFlagSignUpBirthdayPickerRemoveBottomBarOffset = 0x19B9ACB2290; // Unknown = 
    inline constexpr uintptr_t FFlagSignUpBirthdayPickerRequireManualSelection = 0x19B9ACBD010; // Unknown = 
    inline constexpr uintptr_t FFlagSignUpBirthdayPickerShowAgeCalculator = 0x19B9ACB21D0; // Unknown = 
    inline constexpr uintptr_t FFlagSignUpBirthdayRefactorNestedDefinition = 0x19B9ACBEE10; // Unknown = 
    inline constexpr uintptr_t FFlagSignUpTrackFailedRequest = 0x19B945AE5D0; // Unknown = 
    inline constexpr uintptr_t FFlagSignalsNavP2NavigationPrimitives5 = 0x19B85785E1D; // Bool = false
    inline constexpr uintptr_t FFlagSignalsNavP3Dispatch5 = 0x19B8578625D; // Bool = false
    inline constexpr uintptr_t FFlagSignalsNavP3Final = 0x19B857862DD; // Bool = false
    inline constexpr uintptr_t FFlagSignalsNavP3aWrapAppPage2 = 0x19BA59BF795; // Bool = false
    inline constexpr uintptr_t FFlagSignalsNavP3bTopBar4 = 0x19B8578601D; // Bool = false
    inline constexpr uintptr_t FFlagSignalsNavP3cEvents4 = 0x19B85785DD0; // Unknown = 
    inline constexpr uintptr_t FFlagSignalsNavP3dRouteGated2 = 0x19B85785D50; // Unknown = 
    inline constexpr uintptr_t FFlagSignalsNavP3eAuth3 = 0x19B85785B10; // Unknown = 
    inline constexpr uintptr_t FFlagSignalsNavP3fGameDetails3 = 0x19B85785B90; // Unknown = 
    inline constexpr uintptr_t FFlagSignalsNavP3gAvatarExperience4 = 0x19B85785710; // Unknown = 
    inline constexpr uintptr_t FFlagSignalsNavP3hMisc3 = 0x19B857854D0; // Unknown = 
    inline constexpr uintptr_t FFlagSignalsNavProjected2 = 0x19B8578635D; // Bool = false
    inline constexpr uintptr_t FFlagSignalsReactUseMutableSource = 0x19B859C4790; // Unknown = 
    inline constexpr uintptr_t FFlagSignupDisplayNameLogging = 0x19B90294BD0; // Unknown = 
    inline constexpr uintptr_t FFlagSignupLogoAspectRatioFix = 0x19B82B1631D; // Bool = false
    inline constexpr uintptr_t FFlagSignupTrackFailedRequestv1 = 0x19B945A6CD0; // Unknown = 
    inline constexpr uintptr_t FFlagSilentUpgradeOnSignupIXPBypass = 0x19B90291310; // Unknown = 
    inline constexpr uintptr_t FFlagSilentlyFailIfChallenge = 0x19B90293210; // Unknown = 
    inline constexpr uintptr_t FFlagSingleUploadMakeupSupport4 = 0x19B9EE03790; // Unknown = 
    inline constexpr uintptr_t FFlagSingleUserInvitePageKeybind = 0x19B9F29811D; // Bool = false
    inline constexpr uintptr_t FFlagSkipBlockModal = 0x19B8C2E1950; // Unknown = 
    inline constexpr uintptr_t FFlagSkipBuyDelayForExperienceShop = 0x19B9ACBCD10; // Unknown = 
    inline constexpr uintptr_t FFlagSkipCompletionModalForMarketplace = 0x19B9ACB4E90; // Unknown = 
    inline constexpr uintptr_t FFlagSkipCompletionModalForMarketplace3 = 0x19B9ACB2D50; // Unknown = 
    inline constexpr uintptr_t FFlagSlimDevConsole2 = 0x19BACE9E71D; // Bool = false
    inline constexpr uintptr_t FFlagSlimTintContextFilter = 0x19BACE9F190; // Unknown = 
    inline constexpr uintptr_t FFlagSnoozeMenuTextXAlignment = 0x19BA6070210; // Unknown = 
    inline constexpr uintptr_t FFlagSocialBlockingModalFocusNavSupport = 0x19D7F97096D; // Bool = true
    inline constexpr uintptr_t FFlagSocialCarouselEnableNewFriendRequestsBadgeForAll = 0x19B8FA1EC1D; // Bool = false
    inline constexpr uintptr_t FFlagSocialCarouselEnableUserSeenEvents = 0x19BB7870490; // Unknown = 
    inline constexpr uintptr_t FFlagSocialCarouselEnableUserSeenEvents2 = 0x19B8FA1DA5D; // Bool = false
    inline constexpr uintptr_t FFlagSocialCarouselFixColdStartJitter = 0x19B8FA1ED5D; // Bool = false
    inline constexpr uintptr_t FFlagSocialCarouselFixConsoleCtaForInGame = 0x19B8FA1D950; // Unknown = 
    inline constexpr uintptr_t FFlagSocialCarouselFixGameJoinCardDismiss = 0x19B8FA1E21D; // Bool = false
    inline constexpr uintptr_t FFlagSocialCarouselFixLoadingSkeletonSizing = 0x19B8FA1EF9D; // Bool = false
    inline constexpr uintptr_t FFlagSocialCarouselMigrateRecommendations = 0x19BACFD6B50; // Unknown = 
    inline constexpr uintptr_t FFlagSocialCarouselPressXToViewProfile = 0x19BACFD7290; // Unknown = 
    inline constexpr uintptr_t FFlagSocialCarouselShareQRBackToAddFriends = 0x19B9AF15E10; // Unknown = 
    inline constexpr uintptr_t FFlagSocialCarouselShareQRBackToAddFriends_v2 = 0x19B9AF15850; // Unknown = 
    inline constexpr uintptr_t FFlagSocialCarouselShareQREnabled = 0x19B9AF15F90; // Unknown = 
    inline constexpr uintptr_t FFlagSocialCarouselShareQREnabled_v5 = 0x19B9AF15F50; // Unknown = 
    inline constexpr uintptr_t FFlagSocialCarouselShowLoadingSkeleton = 0x19B8FA1DD9D; // Bool = false
    inline constexpr uintptr_t FFlagSocialCarouselUpdateVerticalSpacing = 0x19B8FA1C510; // Unknown = 
    inline constexpr uintptr_t FFlagSocialCarouselUseConsolePolicyForCta = 0x19B8FA1C950; // Unknown = 
    inline constexpr uintptr_t FFlagSocialCarouselUseProfileStore_v2 = 0x19BACFDCE10; // Unknown = 
    inline constexpr uintptr_t FFlagSocialContextToastEventStream3 = 0x19BAED56548; // Unknown = 
    inline constexpr uintptr_t FFlagSocialEnableProfileInspectAndBuy = 0x19BAEE1DF90; // Unknown = 
    inline constexpr uintptr_t FFlagSocialEnableProfileInspectAndBuyAnalytics = 0x19B8C2EC590; // Unknown = 
    inline constexpr uintptr_t FFlagSocialEnableProfileInspectAndBuyAnalyticsV2 = 0x19B9ABD63B5; // Bool = false
    inline constexpr uintptr_t FFlagSocialEnableProfileInspectAndBuyAnalyticsV3 = 0x19BB7F4A750; // Unknown = 
    inline constexpr uintptr_t FFlagSocialEnableProfileInspectAndBuyConsoleFocusNav = 0x19B8C2EC79D; // Bool = false
    inline constexpr uintptr_t FFlagSocialEnableProfileInspectAndBuy_8 = 0x19B8C2EC35D; // Bool = false
    inline constexpr uintptr_t FFlagSocialExperienceJoinPresenceStoreMigration = 0x19B9FB6E1DD; // Bool = false
    inline constexpr uintptr_t FFlagSocialExperienceJoinPresenceStoreMigration_v1 = 0x19BA679DD1D; // Bool = false
    inline constexpr uintptr_t FFlagSocialJoinPassPlaceIdToLaunch = 0x19BA6799A5D; // Bool = false
    inline constexpr uintptr_t FFlagSocialJoinUseUnifiedPurchaseFlow = 0x19BA67985DD; // Bool = false
    inline constexpr uintptr_t FFlagSocialLibrariesSelectableAlertViewShim = 0x19BB6BB10DD; // Bool = false
    inline constexpr uintptr_t FFlagSocialLuaAnalyticsUseTelemetryServiceAsDefault = 0x19BBC743050; // Unknown = 
    inline constexpr uintptr_t FFlagSocialMetadataSectionMigrateUserProfileToSignals = 0x19BC27B4CE0; // Unknown = 
    inline constexpr uintptr_t FFlagSocialNetworksInEditProfileIXPEnabled = 0x19B9064389D; // Bool = false
    inline constexpr uintptr_t FFlagSocialNetworksInEditProfileIXPSetupEnabled_v6 = 0x19B906436DD; // Bool = false
    inline constexpr uintptr_t FFlagSocialTabReplaceRefreshConversations = 0x19B8C2E4C90; // Unknown = 
    inline constexpr uintptr_t FFlagSocialTabsPagePresenceSignalsMigration = 0x19B9011F2DD; // Bool = false
    inline constexpr uintptr_t FFlagSongCarouselPropUpdate = 0x19B88C40850; // Unknown = 
    inline constexpr uintptr_t FFlagSongDetailsPageDesignPass3 = 0x19B9ACB6F90; // Unknown = 
    inline constexpr uintptr_t FFlagSongEdpCarouselIxp = 0x19BBB59C910; // Unknown = 
    inline constexpr uintptr_t FFlagSongEdpCarouselIxp2 = 0x19B82B1D6D0; // Unknown = 
    inline constexpr uintptr_t FFlagSongbirdMusicIconThumbnail = 0x19D84DA0490; // Unknown = 
    inline constexpr uintptr_t FFlagSongbirdPopoverSubmenu2 = 0x19B8579B0F5; // Bool = false
    inline constexpr uintptr_t FFlagSoothsayerCheckForContactImporterV1 = 0x19BC054691D; // Bool = false
    inline constexpr uintptr_t FFlagSortInvitesByScoreEnabledForAll = 0x19BADF9C710; // Unknown = 
    inline constexpr uintptr_t FFlagSpatialUIDisableBottomBarFading = 0x19B9FD87C50; // Unknown = 
    inline constexpr uintptr_t FFlagSpatialUIDisableBottomBarInteractionOnAnimating = 0x19B9FD86610; // Unknown = 
    inline constexpr uintptr_t FFlagSpatialUIEnableDrag8 = 0x19BA3BB4890; // Unknown = 
    inline constexpr uintptr_t FFlagSpatialUIEnableMovePanelToCenter8 = 0x19BA3BB39D0; // Unknown = 
    inline constexpr uintptr_t FFlagSpatialUIEnablePanelsRefocusing = 0x19B9FD87890; // Unknown = 
    inline constexpr uintptr_t FFlagSpatialUIFixGameInviteChatExclusive = 0x19B9FD88A5D; // Bool = false
    inline constexpr uintptr_t FFlagSpatialUIFixMenuPanelChatExclusive = 0x19BACE9D7DD; // Bool = false
    inline constexpr uintptr_t FFlagSquadAppChatRTNFixWithSquadMainFlag = 0x19B8C2E4110; // Unknown = 
    inline constexpr uintptr_t FFlagSquadEnabled = 0x19B8C2E3D50; // Unknown = 
    inline constexpr uintptr_t FFlagSquadExperienceInviteRetryAfter = 0x19BA672739D; // Bool = false
    inline constexpr uintptr_t FFlagSquadLaunchExperienceMobileFix = 0x19B88C4E790; // Unknown = 
    inline constexpr uintptr_t FFlagSquadsPresenceStoreMigration = 0x19BA6723D9D; // Bool = false
    inline constexpr uintptr_t FFlagSquadsUseProfileFrameThumbnail = 0x19BAFCFC810; // Unknown = 
    inline constexpr uintptr_t FFlagStackedBottomNavMarketplaceCTA = 0x19B9AF15190; // Unknown = 
    inline constexpr uintptr_t FFlagStandardizeSafetyIcon = 0x19B88C4B39D; // Bool = false
    inline constexpr uintptr_t FFlagStopBubbleChatReactWarning = 0x19BBCD71750; // Unknown = 
    inline constexpr uintptr_t FFlagStopModerationConnectionOnLeave = 0x19B8FDEB79D; // Bool = false
    inline constexpr uintptr_t FFlagStopStreamTrackOnDeath = 0x19B9119EC6D; // Bool = true
    inline constexpr uintptr_t FFlagStreamNotificationBellEntryPoint = 0x19B9F18E83D; // Bool = true
    inline constexpr uintptr_t FFlagStreamNotificationDropdownFocusedOwner = 0x19B8C306C1D; // Bool = true
    inline constexpr uintptr_t FFlagStreamNotificationDropdownSingleOwner = 0x19B8C3069DD; // Bool = true
    inline constexpr uintptr_t FFlagStreamNotificationImpressionLogging = 0x19B9F182E9D; // Bool = true
    inline constexpr uintptr_t FFlagStreamNotificationUXDropdown2 = 0x19B8C3065DD; // Bool = true
    inline constexpr uintptr_t FFlagStreamNotificationUXSettingsHeader = 0x19B8C30679D; // Bool = true
    inline constexpr uintptr_t FFlagStreamNotificationsStandardizeClickEvents = 0x19B8C30641D; // Bool = true
    inline constexpr uintptr_t FFlagStreamingPauseUIAnalyticsEnabled = 0x19B9F0A751D; // Bool = false
    inline constexpr uintptr_t FFlagStringKeyFixForParticipantsTable = 0x19B8FDE9E10; // Unknown = 
    inline constexpr uintptr_t FFlagSubTabAddDesktopTopMargin = 0x19B9ACB8110; // Unknown = 
    inline constexpr uintptr_t FFlagSubTabAddMomentsFlagGating = 0x19B9ACB09D0; // Unknown = 
    inline constexpr uintptr_t FFlagSubTabFixMissingProfileWidget = 0x19B9ACBD610; // Unknown = 
    inline constexpr uintptr_t FFlagSubTabNavigationTTITracking = 0x19B9ACB9090; // Unknown = 
    inline constexpr uintptr_t FFlagSubTabRemoveFlyoutDependency = 0x19B9ACB8490; // Unknown = 
    inline constexpr uintptr_t FFlagSubscriptionPurchaseModalLiveStatus = 0x19B9AF17ED0; // Unknown = 
    inline constexpr uintptr_t FFlagSubscriptionUpsellCounterWithErrorReasonV2 = 0x19D4353DFE8; // Unknown = 
    inline constexpr uintptr_t FFlagSuggestedCalleeBugFixEnabledV2 = 0x19BA52097D5; // Bool = false
    inline constexpr uintptr_t FFlagSupportFreeTrial = 0x19B8FC35DDD; // Bool = false
    inline constexpr uintptr_t FFlagSupportFreeTrialPriceRow = 0x19B8FC33810; // Unknown = 
    inline constexpr uintptr_t FFlagSupportGamepadNavInVoiceModals = 0x19B9F182535; // Bool = true
    inline constexpr uintptr_t FFlagSupportNewBadgeRobloxPlus = 0x19B8FC3331D; // Bool = false
    inline constexpr uintptr_t FFlagSupportSubmissionOnAllReportNodes = 0x19B8C30D150; // Unknown = 
    inline constexpr uintptr_t FFlagSupportTerminalMilestoneInReactProfilerLogger = 0x19BA60951D0; // Unknown = 
    inline constexpr uintptr_t FFlagSupportViewingUserProfileOnOSA = 0x19BA6B2E85D; // Bool = true
    inline constexpr uintptr_t FFlagSupportViewingUserProfileOnOSA1 = 0x19B8FA1519D; // Bool = false
    inline constexpr uintptr_t FFlagSurvBloxAddSurveyLinkParamsEnabled = 0x19B90290690; // Unknown = 
    inline constexpr uintptr_t FFlagSurvBloxEnabled = 0x19B90290B10; // Unknown = 
    inline constexpr uintptr_t FFlagSurvBloxEventTypeEnabled = 0x19BBB31E010; // Unknown = 
    inline constexpr uintptr_t FFlagSurvBloxEventTypeEnabled2 = 0x19B8C30ED9D; // Bool = true
    inline constexpr uintptr_t FFlagSurvBloxLocalStorageEnabled = 0x19B90290610; // Unknown = 
    inline constexpr uintptr_t FFlagSurvBloxTrackingFixes = 0x19B902902D0; // Unknown = 
    inline constexpr uintptr_t FFlagSwitchCSRootProviderTranslationsPackage = 0x19BBC38A450; // Unknown = 
    inline constexpr uintptr_t FFlagSwitchOverToAbuseReportMenuV2 = 0x19BB7F42FD0; // Unknown = 
    inline constexpr uintptr_t FFlagSwitchProfileWidthHookToSocialCommon = 0x19BACFDFD50; // Unknown = 
    inline constexpr uintptr_t FFlagSwitchProfileWidthHookToSocialCommon_v2 = 0x19BACFDF850; // Unknown = 
    inline constexpr uintptr_t FFlagSwitchTnSTranslationsPackage = 0x19D8168DA50; // Unknown = 
    inline constexpr uintptr_t FFlagSystemTrayDeviceSettings2 = 0x19BA59BAB5D; // Bool = false
    inline constexpr uintptr_t FFlagTCEducationModalSideBarPolicy = 0x19B90643A10; // Unknown = 
    inline constexpr uintptr_t FFlagTCModalUseFoundationOverlay = 0x19BA59B3B10; // Unknown = 
    inline constexpr uintptr_t FFlagTCParentChildAutoUpgrade = 0x19BA59BBF50; // Unknown = 
    inline constexpr uintptr_t FFlagTCParentChildAutoUpgrade2 = 0x19BA59B8CD0; // Unknown = 
    inline constexpr uintptr_t FFlagTCPolicyCheckRedirect = 0x19B8C3035DD; // Bool = true
    inline constexpr uintptr_t FFlagTCShareLinkErrorModal = 0x19BA59BDA90; // Unknown = 
    inline constexpr uintptr_t FFlagTCShareLinkErrorModalTextRename = 0x19BA59B0750; // Unknown = 
    inline constexpr uintptr_t FFlagTCShareLinkReceiverUI4 = 0x19BA59BEC50; // Unknown = 
    inline constexpr uintptr_t FFlagTCStreamNotifEventReceiver = 0x19B8C2E2DD0; // Unknown = 
    inline constexpr uintptr_t FFlagTCUpdateProfileCTAButton = 0x19BA59BAA10; // Unknown = 
    inline constexpr uintptr_t FFlagTFPassQRCodeSource = 0x19BC27B5D90; // Unknown = 
    inline constexpr uintptr_t FFlagTFProfileInsightsBypassCache = 0x19BA59BA2D0; // Unknown = 
    inline constexpr uintptr_t FFlagTFWithActionsCheck = 0x19BA59B99D0; // Unknown = 
    inline constexpr uintptr_t FFlagTFWithActionsCheck_4 = 0x19BA59B8310; // Unknown = 
    inline constexpr uintptr_t FFlagTTITrackerMemoryTracking = 0x19BC2568860; // Unknown = 
    inline constexpr uintptr_t FFlagTTITrackerMemoryTracking3 = 0x19B8F7416DD; // Bool = false
    inline constexpr uintptr_t FFlagTakeAScreenshotOfThis = 0x19D81687050; // Unknown = 
    inline constexpr uintptr_t FFlagTalkingChangedWithDebounceV2 = 0x19B8FDE9190; // Unknown = 
    inline constexpr uintptr_t FFlagTempFixInfiniteHomePYMK = 0x19B8FC3ABD0; // Unknown = 
    inline constexpr uintptr_t FFlagTemporaryAvatarKickWarningDialog = 0x19BACE781DD; // Bool = false
    inline constexpr uintptr_t FFlagTenFootUiCorrectAutoFocusLoggingBehavior = 0x19B8F90865D; // Bool = false
    inline constexpr uintptr_t FFlagTenFootUiGlobalNavFixOptionText = 0x19B859CBF90; // Unknown = 
    inline constexpr uintptr_t FFlagTenFootUiSupportSortHeaderTooltip2 = 0x19BA520F2BD; // Bool = true
    inline constexpr uintptr_t FFlagTenFootUiSupportSortSubtitle2 = 0x19B88C4ACDD; // Bool = false
    inline constexpr uintptr_t FFlagTestDeviceForFAEUpsell = 0x19B8FDEF4DD; // Bool = false
    inline constexpr uintptr_t FFlagTextChannelWindowPerfTrackingEnabled = 0x19B9CB7D55D; // Bool = false
    inline constexpr uintptr_t FFlagTextChatEnableUniverseChatTabs11 = 0x19B9F18C7DD; // Bool = true
    inline constexpr uintptr_t FFlagTextFilterEducationNudgeEnabled = 0x19B9481271D; // Bool = false
    inline constexpr uintptr_t FFlagTiltLoadingScreenConsoleHints = 0x19B9AF12210; // Unknown = 
    inline constexpr uintptr_t FFlagTiltLoadingScreenEnterExitHold = 0x19B9AF12B50; // Unknown = 
    inline constexpr uintptr_t FFlagTiltLoadingScreenEnterExitHold2 = 0x19B9AF12CD0; // Unknown = 
    inline constexpr uintptr_t FFlagTimeToInteractiveTrackerWarningsRequireDebug = 0x19B8F741950; // Unknown = 
    inline constexpr uintptr_t FFlagTimeoutRemoteEvent = 0x19BB1C1813D; // Bool = false
    inline constexpr uintptr_t FFlagTokenizeUnibarConstantsWithStyleProvider = 0x19BA7FC10C8; // Unknown = 
    inline constexpr uintptr_t FFlagTopBarDeprecateChatRodux = 0x19D7C7CF595; // Bool = false
    inline constexpr uintptr_t FFlagTopBarDeprecateChatRodux2 = 0x19BAD28699D; // Bool = false
    inline constexpr uintptr_t FFlagTopBarDeprecateCoreGuiRodux = 0x19B9FDDCB15; // Bool = false
    inline constexpr uintptr_t FFlagTopBarDeprecateCoreGuiRodux2 = 0x19D8168AD90; // Unknown = 
    inline constexpr uintptr_t FFlagTopBarDeprecateDisplayOptionsRodux = 0x19D7C7CDC55; // Bool = false
    inline constexpr uintptr_t FFlagTopBarDeprecateDisplayOptionsRodux2 = 0x19BAD286C9D; // Bool = false
    inline constexpr uintptr_t FFlagTopBarDeprecateGameInfoRodux = 0x19BAD2865DD; // Bool = false
    inline constexpr uintptr_t FFlagTopBarDeprecateGamepadNavigationDialogRodux = 0x19BAD2867DD; // Bool = false
    inline constexpr uintptr_t FFlagTopBarDeprecateMoreMenuRodux = 0x19B9FDDCB95; // Bool = false
    inline constexpr uintptr_t FFlagTopBarDeprecateRespawnRodux = 0x19B9FDDCC15; // Bool = false
    inline constexpr uintptr_t FFlagTopBarDeprecateRespawnRodux2 = 0x19D816809D0; // Unknown = 
    inline constexpr uintptr_t FFlagTopBarRefactor2 = 0x19BA4614D5D; // Bool = false
    inline constexpr uintptr_t FFlagTopBarSignalizeHealthBar4 = 0x19BA4617E5D; // Bool = false
    inline constexpr uintptr_t FFlagTopBarSignalizeKeepOutAreas5 = 0x19BA461171D; // Bool = false
    inline constexpr uintptr_t FFlagTopBarSignalizeMenuOpen = 0x19BA461221D; // Bool = false
    inline constexpr uintptr_t FFlagTopBarSignalizeScreenSize2 = 0x19BA461C41D; // Bool = false
    inline constexpr uintptr_t FFlagTopBarSignalizeSetCores = 0x19BA461A210; // Unknown = 
    inline constexpr uintptr_t FFlagTouchHelpPageResponsiveUnits = 0x19BBE91D7D0; // Unknown = 
    inline constexpr uintptr_t FFlagTrackerPromptNewCopyForCameraPerformanceEnabled = 0x19B9F0AD550; // Unknown = 
    inline constexpr uintptr_t FFlagTranslateDevProducts = 0x19D85DC1CD0; // Unknown = 
    inline constexpr uintptr_t FFlagTraversalExpPagePaddingFixes709 = 0x19BBC380450; // Unknown = 
    inline constexpr uintptr_t FFlagTraversalHistoryDiscoveryTelemetry = 0x19B88C2CD90; // Unknown = 
    inline constexpr uintptr_t FFlagTraversalUseDiscoveryCollectionViews = 0x19BBE91E9D0; // Unknown = 
    inline constexpr uintptr_t FFlagTraversalUseXSmallCollectionItems = 0x19BBE91B9D0; // Unknown = 
    inline constexpr uintptr_t FFlagTriggerLogoutOnAuthErrorCode = 0x19BA6A34890; // Unknown = 
    inline constexpr uintptr_t FFlagTrimLongTitleForTOSEnabled = 0x19B859C9810; // Unknown = 
    inline constexpr uintptr_t FFlagTruncateDeviceSelection = 0x19D8168D810; // Unknown = 
    inline constexpr uintptr_t FFlagTrustedFriendsUseEnumCTA = 0x19BA59B8D10; // Unknown = 
    inline constexpr uintptr_t FFlagTrustedFriendsUseEnumCTA_2 = 0x19BA59B83D0; // Unknown = 
    inline constexpr uintptr_t FFlagTrustedFriendsUseFoundationSheet = 0x19BA59B0550; // Unknown = 
    inline constexpr uintptr_t FFlagTutorialUpsellEnabled = 0x19B945A0310; // Unknown = 
    inline constexpr uintptr_t FFlagTutorialUpsellOverrideIXPEnabled = 0x19B90291D10; // Unknown = 
    inline constexpr uintptr_t FFlagUFRImprovements = 0x19BA4E9B055; // Bool = true
    inline constexpr uintptr_t FFlagUFRImprovements3 = 0x19BA4E9B995; // Bool = true
    inline constexpr uintptr_t FFlagUFRInlineAppealLink = 0x19BA8023B10; // Unknown = 
    inline constexpr uintptr_t FFlagUIBloxAddFoundationNavigationTabIcon = 0x19B8578839D; // Bool = false
    inline constexpr uintptr_t FFlagUIBloxAddTestIdToActionBar = 0x19B85787310; // Unknown = 
    inline constexpr uintptr_t FFlagUIBloxAppShortcutBarUseTokens = 0x19B85787BD0; // Unknown = 
    inline constexpr uintptr_t FFlagUIBloxDeprecateComponentGlobalSemanticTokenUse = 0x19B8578859D; // Bool = false
    inline constexpr uintptr_t FFlagUIBloxDidMountUpdateFullPageModal = 0x19B85787DDD; // Bool = false
    inline constexpr uintptr_t FFlagUIBloxDisableTokenScaling = 0x19B85787390; // Unknown = 
    inline constexpr uintptr_t FFlagUIBloxEnableActionBarButtonOverride = 0x19B857876D0; // Unknown = 
    inline constexpr uintptr_t FFlagUIBloxEnableTooltipV2BodyFontFix = 0x19B9F18C03D; // Bool = true
    inline constexpr uintptr_t FFlagUIBloxEnableTooltipV2HoverControllerReRenderFix = 0x19B85787C1D; // Bool = false
    inline constexpr uintptr_t FFlagUIBloxFixCoplayFooterConditionalHooks = 0x19BB1A40EDD; // Bool = true
    inline constexpr uintptr_t FFlagUIBloxRemoveStackedNavigationTabIconLabelSpacing = 0x19B85786190; // Unknown = 
    inline constexpr uintptr_t FFlagUIBloxToastFoundationButtonSizing = 0x19B8578815D; // Bool = false
    inline constexpr uintptr_t FFlagUIBloxUseEngineRichTextBounds = 0x19B85787D10; // Unknown = 
    inline constexpr uintptr_t FFlagUIBloxUseFoundationButton5 = 0x19B85787F5D; // Bool = false
    inline constexpr uintptr_t FFlagUIBloxUseFoundationButtonInGame2 = 0x19B8E61095D; // Bool = true
    inline constexpr uintptr_t FFlagUIBloxUseFoundationSkeleton = 0x19B85A50740; // Unknown = 
    inline constexpr uintptr_t FFlagUIBloxUseGridInfoForTile = 0x19B8C347BDD; // Bool = false
    inline constexpr uintptr_t FFlagUIBloxUseNewZindex = 0x19B8C347B5D; // Bool = false
    inline constexpr uintptr_t FFlagUXForCameraPerformanceEnabled = 0x19B9F0ACB90; // Unknown = 
    inline constexpr uintptr_t FFlagUXForCameraPerformanceIXPEnabled = 0x19B9AF10DD0; // Unknown = 
    inline constexpr uintptr_t FFlagUnibarLuaOcclusionMetrics = 0x19B9ACBD8D0; // Unknown = 
    inline constexpr uintptr_t FFlagUnibarMenuOpenHamburger = 0x19B9FDD1955; // Bool = false
    inline constexpr uintptr_t FFlagUnibarMenuOpenHamburgerGamepadIXP = 0x19B9ACB5590; // Unknown = 
    inline constexpr uintptr_t FFlagUnibarMenuOpenHamburgerGamepadIXP684 = 0x19B9ACBEB90; // Unknown = 
    inline constexpr uintptr_t FFlagUnibarMenuOpenSelectionIXP = 0x19B9ACB0A90; // Unknown = 
    inline constexpr uintptr_t FFlagUnibarMenuOpenSelectionIXP2 = 0x19B9ACB4CD0; // Unknown = 
    inline constexpr uintptr_t FFlagUnibarMenuOpenSubmenu = 0x19B9FDD1995; // Bool = false
    inline constexpr uintptr_t FFlagUnifiedPurchaseAddSkeleton = 0x19B9ACB1690; // Unknown = 
    inline constexpr uintptr_t FFlagUnifiedPurchaseFlowMarketplaceUIImprovements = 0x19B9ACBDF50; // Unknown = 
    inline constexpr uintptr_t FFlagUnifiedPurchaseFlowMarketplaceUIImprovementsV4 = 0x19B9ACBCED0; // Unknown = 
    inline constexpr uintptr_t FFlagUnifiedPurchaseGamepassAddProductUniverseId = 0x19B9ACB7B90; // Unknown = 
    inline constexpr uintptr_t FFlagUnifiedPurchaseOptimizeTTIMarketplace = 0x19B9AF19850; // Unknown = 
    inline constexpr uintptr_t FFlagUnifiedPurchaseOptimizeTTIMarketplaceIntegration = 0x19BA3A55F50; // Unknown = 
    inline constexpr uintptr_t FFlagUnifiedPurchasePassInProductInfoEDP = 0x19B9AF1B610; // Unknown = 
    inline constexpr uintptr_t FFlagUnifiedPurchasePassInProductInfoEDP2 = 0x19B9AF1C010; // Unknown = 
    inline constexpr uintptr_t FFlagUnifiedPurchaseSupportRefetchingLooksAfterUpsell = 0x19B9ACB0610; // Unknown = 
    inline constexpr uintptr_t FFlagUnifyConsoleSettingsPage5 = 0x19B9AF12550; // Unknown = 
    inline constexpr uintptr_t FFlagUnifyVerifiedBadgeComponent = 0x19B85788290; // Unknown = 
    inline constexpr uintptr_t FFlagUniversalAppCameraEnabled5 = 0x19B90644C1D; // Bool = false
    inline constexpr uintptr_t FFlagUniversalAppCameraEnabledForAll4 = 0x19B90644D5D; // Bool = false
    inline constexpr uintptr_t FFlagUniversalFeatureRestrictionReceivers = 0x19BBB31F390; // Unknown = 
    inline constexpr uintptr_t FFlagUniversalFeatureRestrictionReceivers10 = 0x19B8C30E2DD; // Bool = true
    inline constexpr uintptr_t FFlagUnreduxLastInputTypeChanged = 0x19BA4614AD0; // Unknown = 
    inline constexpr uintptr_t FFlagUpdateDeviceInputPlayerChanged = 0x19B8FDE9E5D; // Bool = false
    inline constexpr uintptr_t FFlagUpdateDiscoveryEventErrorDetailsLogging = 0x19BA3A70E1D; // Bool = false
    inline constexpr uintptr_t FFlagUpdateDividerStartBounds = 0x19B94810390; // Unknown = 
    inline constexpr uintptr_t FFlagUpdateInGameAssetReportingCTAs = 0x19B8C30CB90; // Unknown = 
    inline constexpr uintptr_t FFlagUpdateInvitesToUsePaginatedFriends = 0x19BACE72050; // Unknown = 
    inline constexpr uintptr_t FFlagUpdateNoInternetConnectionText = 0x19B82B1B75D; // Bool = false
    inline constexpr uintptr_t FFlagUpdatePeopleNamesSettingCopy = 0x19B9FD8B455; // Bool = false
    inline constexpr uintptr_t FFlagUpdateRephraseSettingUI = 0x19B9FD8B790; // Unknown = 
    inline constexpr uintptr_t FFlagUpdateSocialCarouselAddFriendsIcon = 0x19B8EE09D7D; // Bool = false
    inline constexpr uintptr_t FFlagUpdateSongCarouselClipDefault = 0x19B88C405D0; // Unknown = 
    inline constexpr uintptr_t FFlagUpdateTranslateInReportRevamp = 0x19B8C30E11D; // Bool = true
    inline constexpr uintptr_t FFlagUpdateUnifiedPurchasePriceTelemetry = 0x19B9ACB0250; // Unknown = 
    inline constexpr uintptr_t FFlagUpdateVisibilitySettingsCopy = 0x19B9FD8D810; // Unknown = 
    inline constexpr uintptr_t FFlagUpdateVoiceConnectionToasts_AEGIS2 = 0x19BA5155990; // Unknown = 
    inline constexpr uintptr_t FFlagUpdatedTrimMemoryLevelPropagation = 0x19B82A7009D; // Bool = true
    inline constexpr uintptr_t FFlagUploadMakeupSupport = 0x19B9EE04C1D; // Bool = false
    inline constexpr uintptr_t FFlagUseAccountPickerAmpEligibility = 0x19B9ACB0150; // Unknown = 
    inline constexpr uintptr_t FFlagUseAnimateScrollViewToSelectionHelper = 0x19B9ACBDD50; // Unknown = 
    inline constexpr uintptr_t FFlagUseAudioAnalyzerForLocalMetering2 = 0x19B8FDEB55D; // Bool = false
    inline constexpr uintptr_t FFlagUseBindingForUnreadChat = 0x19B8EE06F3D; // Bool = false
    inline constexpr uintptr_t FFlagUseCameraDevicesListener = 0x19B9FD89F1D; // Bool = false
    inline constexpr uintptr_t FFlagUseCaptureCommonComponents = 0x19D86F01A90; // Unknown = 
    inline constexpr uintptr_t FFlagUseCharacterStore2 = 0x19B8FA14210; // Unknown = 
    inline constexpr uintptr_t FFlagUseCommunitiesTranslation = 0x19BC0547D50; // Unknown = 
    inline constexpr uintptr_t FFlagUseCoreScriptsRootProviderForUpsellModal = 0x19B9EE011DD; // Bool = false
    inline constexpr uintptr_t FFlagUseDefaultOverrideColorsFor10ftModels = 0x19B9AF16550; // Unknown = 
    inline constexpr uintptr_t FFlagUseEnablePremiumUserFeaturesAppPolicy = 0x19BC0545D50; // Unknown = 
    inline constexpr uintptr_t FFlagUseExternalBrowserForAgeGuidelines10ft = 0x19BA6A3B850; // Unknown = 
    inline constexpr uintptr_t FFlagUseExtraATCProperties = 0x19B84FE2410; // Unknown = 
    inline constexpr uintptr_t FFlagUseFriendsListOrderedByIdPresenceImpressionEventsEnabled = 0x19BA679F09D; // Bool = false
    inline constexpr uintptr_t FFlagUseIsAvailableCheckForIOSKeychainFetch = 0x19B945AF510; // Unknown = 
    inline constexpr uintptr_t FFlagUseLocalTraversalHistory699v1 = 0x19BBC38EB50; // Unknown = 
    inline constexpr uintptr_t FFlagUseMediaPlayerInCarousel = 0x19BACFDCF10; // Unknown = 
    inline constexpr uintptr_t FFlagUseMediaPlayerInCarousel_v2 = 0x19BACFDAA90; // Unknown = 
    inline constexpr uintptr_t FFlagUseNavigationSelectors = 0x19B9AF1A190; // Unknown = 
    inline constexpr uintptr_t FFlagUseNewDiscoverabilityModal = 0x19B84F2632D; // Bool = false
    inline constexpr uintptr_t FFlagUseNewDiscoverabilityModal_v2 = 0x19BA59B4190; // Unknown = 
    inline constexpr uintptr_t FFlagUseNewHurtOverlayAnimation = 0x19BA461295D; // Bool = false
    inline constexpr uintptr_t FFlagUseNewHurtOverlayImage = 0x19BA461701D; // Bool = false
    inline constexpr uintptr_t FFlagUseNewPlayerList3 = 0x19B8EE07A7D; // Bool = false
    inline constexpr uintptr_t FFlagUseNotificationServiceIsConnected = 0x19B9F0AB550; // Unknown = 
    inline constexpr uintptr_t FFlagUseObservableDefaultForChromeFocused = 0x19BACFEFB10; // Unknown = 
    inline constexpr uintptr_t FFlagUseOmniFeedDividerOverrides = 0x19BC054EC90; // Unknown = 
    inline constexpr uintptr_t FFlagUseOriginalPlatformChatPolicy = 0x19BB6BBE39D; // Bool = true
    inline constexpr uintptr_t FFlagUsePlaceInfoController2 = 0x19B8F90E71D; // Bool = false
    inline constexpr uintptr_t FFlagUsePlatformNameForUnknown = 0x19D85DCF010; // Unknown = 
    inline constexpr uintptr_t FFlagUsePlaystationPaymentsProtocolCommonFunctions = 0x19BAC83345D; // Bool = false
    inline constexpr uintptr_t FFlagUsePresenceDataFromRtn = 0x19B8EAEC75D; // Bool = false
    inline constexpr uintptr_t FFlagUseRbxStorageInCapturesCommon = 0x19BA4562B2D; // Bool = false
    inline constexpr uintptr_t FFlagUseRbxstorageInGallery = 0x19B98EC7418; // Unknown = 
    inline constexpr uintptr_t FFlagUseRoactGlobalConfigInCoreScripts = 0x19B9FDD4D95; // Bool = false
    inline constexpr uintptr_t FFlagUseSessionServiceWrapper = 0x19B90293E50; // Unknown = 
    inline constexpr uintptr_t FFlagUseSessionServiceWrapperModule = 0x19B902929D0; // Unknown = 
    inline constexpr uintptr_t FFlagUseSharedLoadingScreenView = 0x19BA8A09B5D; // Bool = false
    inline constexpr uintptr_t FFlagUseSignalsForAccountSecurityPrompt = 0x19BA5532310; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForAppTopBanner = 0x19BA553FF90; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForAuthenticationStatus7 = 0x19BA5531A90; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForCountryCode = 0x19BA5536490; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForCountryCodeList = 0x19B85784890; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForGameInvitesStatus = 0x19BA55320D0; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForGlobalContextMenuInset1 = 0x19BA553C590; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForIsLocalUserSoothsayer = 0x19B85785950; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForIsLocalUserUnder13 = 0x19BA553D190; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForModeration = 0x19B857861DD; // Bool = false
    inline constexpr uintptr_t FFlagUseSignalsForPlatform = 0x19BA5535B90; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForScreenGuiBlur = 0x19BA5533B90; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForSearchBar = 0x19BA5536E90; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForSiteMessage = 0x19BA5536950; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForSquadExperienceInviteStatus = 0x19B8C2E3490; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsForStartup = 0x19BA5530110; // Unknown = 
    inline constexpr uintptr_t FFlagUseSignalsNavigation2 = 0x19B85785A9D; // Bool = false
    inline constexpr uintptr_t FFlagUseSignalsRoduxStore3 = 0x19B857863DD; // Bool = false
    inline constexpr uintptr_t FFlagUseTeleportTraversalHistory699v1 = 0x19BBC381DD0; // Unknown = 
    inline constexpr uintptr_t FFlagUseUniverseVotesController = 0x19B8F90E79D; // Bool = false
    inline constexpr uintptr_t FFlagUseUpdatedBackgroundSceneSettingsOnMobile1 = 0x19B9026C510; // Unknown = 
    inline constexpr uintptr_t FFlagUseUpdatedVNGAgreementsWorkflow = 0x19B88C4A650; // Unknown = 
    inline constexpr uintptr_t FFlagUseV2LivePreviewWatermark = 0x19BA8A0EF9D; // Bool = false
    inline constexpr uintptr_t FFlagUseVRSpecificLeaveButton = 0x19D81681210; // Unknown = 
    inline constexpr uintptr_t FFlagUseVoiceExitBetaLanguageV2 = 0x19BC05429D0; // Unknown = 
    inline constexpr uintptr_t FFlagUserBlockingApiPlayerContextMenuEnabled = 0x19B859CA750; // Unknown = 
    inline constexpr uintptr_t FFlagUserInfoWidgetUseProfileFrameThumbnail = 0x19B902937DD; // Bool = true
    inline constexpr uintptr_t FFlagUserListCtaAnalyticsEnabled = 0x19BACFD69DD; // Bool = false
    inline constexpr uintptr_t FFlagUserListCtaIntegrationEnabled = 0x19BACFDED5D; // Bool = true
    inline constexpr uintptr_t FFlagUserListCtaIntegrationEnabled_v2 = 0x19BACFD1B50; // Unknown = 
    inline constexpr uintptr_t FFlagUserListFooterViewMore = 0x19BA59B7990; // Unknown = 
    inline constexpr uintptr_t FFlagUserListPresenceStoreMigration = 0x19BA672D31D; // Bool = false
    inline constexpr uintptr_t FFlagUserListPresenceStoreMigration_v2 = 0x19BA672475D; // Bool = false
    inline constexpr uintptr_t FFlagUserListTightHeaderSpacing = 0x19BA679385D; // Bool = false
    inline constexpr uintptr_t FFlagUserListUseActionAddTranslation = 0x19BA6790F1D; // Bool = false
    inline constexpr uintptr_t FFlagUserListUseSheet = 0x19BACFDA290; // Unknown = 
    inline constexpr uintptr_t FFlagUserListUsernameFallbackConfig = 0x19BACFD5850; // Unknown = 
    inline constexpr uintptr_t FFlagUserPresenceTokenRccCheckPermissionsLua = 0x19B9FDD0A95; // Bool = false
    inline constexpr uintptr_t FFlagUserProfileBetterErrors = 0x19BADF90310; // Unknown = 
    inline constexpr uintptr_t FFlagUserProfileConsoleUseNewReportFlow = 0x19B859CA4DD; // Bool = false
    inline constexpr uintptr_t FFlagUserProfileStoreDataFetchFix = 0x19BA672069D; // Bool = false
    inline constexpr uintptr_t FFlagUserProfileStoreQueryRefetch = 0x19BACFD1510; // Unknown = 
    inline constexpr uintptr_t FFlagUserProfileTurnCacheBackOn = 0x19B827A3F5D; // Bool = false
    inline constexpr uintptr_t FFlagUserProfilesDataLoaderEnabled = 0x19BC054BB10; // Unknown = 
    inline constexpr uintptr_t FFlagUserProfilesEnableRetries = 0x19BA515B21D; // Bool = false
    inline constexpr uintptr_t FFlagUserProfilesFilterInvalidUserIds = 0x19BA515481D; // Bool = false
    inline constexpr uintptr_t FFlagUserProfilesLogCancelledRequests = 0x19BA515165D; // Bool = false
    inline constexpr uintptr_t FFlagUserProfilesLogErrorCodes = 0x19B994C19D5; // Bool = true
    inline constexpr uintptr_t FFlagUserProfilesUseIsRobloxSubscriberGetter = 0x19BA515405D; // Bool = false
    inline constexpr uintptr_t FFlagUserSearchAddFocusActionsSupport_1 = 0x19B8C2E0B50; // Unknown = 
    inline constexpr uintptr_t FFlagUserSearchEmptyPageNewIcons = 0x19BA59B0450; // Unknown = 
    inline constexpr uintptr_t FFlagUserSearchGoBackOnCancel = 0x19BA59B3E50; // Unknown = 
    inline constexpr uintptr_t FFlagUserSearchPresenceStoreMigration_v2 = 0x19B9011D290; // Unknown = 
    inline constexpr uintptr_t FFlagUserSearchUseProfileFrameThumbnail = 0x19B9011E29D; // Bool = false
    inline constexpr uintptr_t FFlagUserSearchUseThisIsYou = 0x19B8C2E0850; // Unknown = 
    inline constexpr uintptr_t FFlagUserTM2Experiment = 0x19B8EE0BADD; // Bool = false
    inline constexpr uintptr_t FFlagUserTileAddContextualInfoIcon = 0x19B8C30279D; // Bool = true
    inline constexpr uintptr_t FFlagUserTileAddDataHydrationWrapper = 0x19BA672881D; // Bool = false
    inline constexpr uintptr_t FFlagUserTileIncludeProfileFrameProp = 0x19BA679021D; // Bool = false
    inline constexpr uintptr_t FFlagUserTileRemoveContextualInfoTag = 0x19BA679FA1D; // Bool = false
    inline constexpr uintptr_t FFlagUserTileShowBadges = 0x19B8C3026DD; // Bool = true
    inline constexpr uintptr_t FFlagUserTileShowShimmerWhenLoading = 0x19BA6795D9D; // Bool = false
    inline constexpr uintptr_t FFlagUserTileShowShimmerWhenLoading_v2 = 0x19BA67951DD; // Bool = false
    inline constexpr uintptr_t FFlagUserTileTextTCIndicator_V3 = 0x19B8C30265D; // Bool = true
    inline constexpr uintptr_t FFlagUserTileTitleStackAddExtraInfo_DEV = 0x19B8C30295D; // Bool = true
    inline constexpr uintptr_t FFlagUserTileUnfilteredChatIndicator = 0x19B8C302B1D; // Bool = true
    inline constexpr uintptr_t FFlagUserTileUseProfileFrameThumbnail = 0x19BA6799EDD; // Bool = false
    inline constexpr uintptr_t FFlagUsesCancelSearchAppPolicy = 0x19BBCD72690; // Unknown = 
    inline constexpr uintptr_t FFlagVCWasDisabledFromMenuOpen = 0x19BC0542990; // Unknown = 
    inline constexpr uintptr_t FFlagVRAbuseReportLocales = 0x19B8C306B90; // Unknown = 
    inline constexpr uintptr_t FFlagVRBottomBarDebugPositionConfig = 0x19B9FDD4E15; // Bool = false
    inline constexpr uintptr_t FFlagVRLaserPointerRaycastChange = 0x19BBE910E90; // Unknown = 
    inline constexpr uintptr_t FFlagVRPanelWidthIXPEnabledV5 = 0x19B9ACB9B50; // Unknown = 
    inline constexpr uintptr_t FFlagVRPanelWidthIXPLocalOverrideEnabled = 0x19BA6A37E10; // Unknown = 
    inline constexpr uintptr_t FFlagVRSpatialUIGuardNilHeadScale = 0x19B9FD8815D; // Bool = false
    inline constexpr uintptr_t FFlagValidateDescription = 0x19B9EE0341D; // Bool = false
    inline constexpr uintptr_t FFlagValidateUGCContentMakeupAssetTypes = 0x19B82E0BA90; // Unknown = 
    inline constexpr uintptr_t FFlagVideoPlaybackDetectorCancelPendingScanTask = 0x19B88C2BE90; // Unknown = 
    inline constexpr uintptr_t FFlagVipOwnerNotPresentEnableReconnect = 0x19BA672D61D; // Bool = false
    inline constexpr uintptr_t FFlagVirtualCursorDisplayOrder = 0x19B9ACB0690; // Unknown = 
    inline constexpr uintptr_t FFlagVirtualCursorForTVRemoteKeycodes = 0x19BA59B4610; // Unknown = 
    inline constexpr uintptr_t FFlagVirtualCursorModularization4 = 0x19BA59B2590; // Unknown = 
    inline constexpr uintptr_t FFlagVirtualCursorSnapLevelBasedOnDirection = 0x19BA59B4390; // Unknown = 
    inline constexpr uintptr_t FFlagVirtualCursorSnapStopsWhenInputStops = 0x19BA59B7850; // Unknown = 
    inline constexpr uintptr_t FFlagVirtualizedFeedFooterWrapperProp = 0x19B88C26D90; // Unknown = 
    inline constexpr uintptr_t FFlagVngAppUpsellPcLayout = 0x19B88C4BF5D; // Bool = false
    inline constexpr uintptr_t FFlagVngLogoutGlobalAppSessionsOnConversion = 0x19B88C4A190; // Unknown = 
    inline constexpr uintptr_t FFlagVngTOSRevisedEnabled = 0x19B9ACB8E10; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceARUnblockingUnmutingEnabled = 0x19BB7F43C9D; // Bool = false
    inline constexpr uintptr_t FFlagVoiceChatDisruptiveVoiceNudgeEnableVariant2 = 0x19BA515881D; // Bool = false
    inline constexpr uintptr_t FFlagVoiceChatDisruptiveVoiceNudgeForceUseNewDACopy = 0x19BA5158B5D; // Bool = false
    inline constexpr uintptr_t FFlagVoiceChatLocalMutedNilFix = 0x19BACFD8FD0; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceChatMuteAllSyncMutedPlayers = 0x19B8FDEBEDD; // Bool = false
    inline constexpr uintptr_t FFlagVoiceChatOnlyReportVoiceBans = 0x19BA4E9F9D0; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceChatSelectorReconnectFocus2_AEGIS2 = 0x19B9FD8B8DD; // Bool = false
    inline constexpr uintptr_t FFlagVoiceChatServiceManagerUseAvatarChat = 0x19B8FDEA55D; // Bool = false
    inline constexpr uintptr_t FFlagVoiceChatUILogging = 0x19B9FD8C8D0; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceChatVolumePerUserDisableInteractionWhenMuted = 0x19BBC380AD0; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceChatVolumePerUserMuteVolumeSync = 0x19B8BABB78D; // Bool = false
    inline constexpr uintptr_t FFlagVoiceConnectToastCapturesTrustedFriendsSubtitle = 0x19BA4E9AF90; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceEndedCheckDisregardIdleState = 0x19B9F185E5D; // Bool = true
    inline constexpr uintptr_t FFlagVoiceNudgeUseNewConfirmButton = 0x19BA4E99F10; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceRewarmTelemetryV2 = 0x19B8C305D5D; // Bool = true
    inline constexpr uintptr_t FFlagVoiceSelectorAvailableAfterFae = 0x19B9FD8BBDD; // Bool = false
    inline constexpr uintptr_t FFlagVoiceSelectorIgnoreFailedStateDisconnect = 0x19B9FD8BB90; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceUserAgency3 = 0x19B9AF11890; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceUserAgencyEnableIXP = 0x19B9AF10890; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceVolumeControlsApplyPerUserMultiplier = 0x19B949F83A0; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceVolumeControlsDisableInteractionWhenNoMasterVolume = 0x19B9FD8B810; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceVolumeControlsEnableNotAudibleVoiceChatVolumeToast = 0x19B9FDDDD55; // Bool = false
    inline constexpr uintptr_t FFlagVoiceVolumeControlsEnablePerUserVolumeInteractionTelemetry = 0x19BBC38449D; // Bool = true
    inline constexpr uintptr_t FFlagVoiceVolumeControlsEnableVoiceChatVolumeSlider = 0x19B9FDDB055; // Bool = false
    inline constexpr uintptr_t FFlagVoiceVolumeControlsEnableVoiceVolumeEligibilityTelemetry = 0x19B8FDEBD1D; // Bool = false
    inline constexpr uintptr_t FFlagVoiceVolumeControlsEnableVoiceVolumeImpressionsTelemetry = 0x19B8FDEBD9D; // Bool = false
    inline constexpr uintptr_t FFlagVoiceVolumeControlsFixSliderVisibilityOnEligibleGames = 0x19B9FD8BA50; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceVolumeControlsGlobalVoiceVolumeSliderIxpExposure = 0x19BA5159A1D; // Bool = false
    inline constexpr uintptr_t FFlagVoiceVolumeControlsPerUserPlayerGridMenu = 0x19BBC38ED10; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceVolumeControlsPerUserPlayerListButton = 0x19BBC382510; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceVolumeControlsPerUserPlayerListButton5 = 0x19BBC383390; // Unknown = 
    inline constexpr uintptr_t FFlagVoiceVolumeControlsSuppressInExperienceUiForPartyVoice = 0x19B9FD8B850; // Unknown = 
    inline constexpr uintptr_t FFlagWHAM1707ExperimentForceEnabled = 0x19BBBEC4D65; // Bool = false
    inline constexpr uintptr_t FFlagWebViewHideLuaSideBar = 0x19B90643D90; // Unknown = 
    inline constexpr uintptr_t FFlagWebViewServiceHasBackButtonVisibility = 0x19B90643610; // Unknown = 
    inline constexpr uintptr_t FFlagWhisperEmoteOnAvatarContextMenuWithExpChat = 0x19BA60788D0; // Unknown = 
    inline constexpr uintptr_t FFlagWrapEmphasisTileDescriptionText = 0x19BBE910650; // Unknown = 
    inline constexpr uintptr_t FIntAXAnimatedScrollingFrameScrollTimeMs = 0x19B9F00D910; // Unknown = 
    inline constexpr uintptr_t FIntAXAvatarLoadRetryCount = 0x19B906480D0; // Unknown = 
    inline constexpr uintptr_t FIntAXAvatarLoadRetryDelayMs = 0x19B90648150; // Unknown = 
    inline constexpr uintptr_t FIntAXAvatarUpdateOnGameLeaveDelay = 0x19B906449D0; // Unknown = 
    inline constexpr uintptr_t FIntAXBackgroundFogDisabledDistance = 0x19B8F904610; // Unknown = 
    inline constexpr uintptr_t FIntAXBackgroundGenerationMaxConsecutivePollFailures = 0x19D80F1A7B8; // Unknown = 
    inline constexpr uintptr_t FIntAXBackgroundGenerationMaxPromptLength = 0x19BABC1CB08; // Unknown = 
    inline constexpr uintptr_t FIntAXBackgroundGenerationPollIntervalSeconds = 0x19BBB2D49C8; // Unknown = 
    inline constexpr uintptr_t FIntAXBackgroundGenerationPollTimeoutSeconds = 0x19B8F9045D0; // Unknown = 
    inline constexpr uintptr_t FIntAXBackgroundsCatalogTabPosition = 0x19B8EAE7A70; // Unknown = 
    inline constexpr uintptr_t FIntAXBuyDelayMilliseconds = 0x19B8FC36290; // Unknown = 
    inline constexpr uintptr_t FIntAXCarouselItemsBasedOnFrameSize = 0x19B8FC33210; // Unknown = 
    inline constexpr uintptr_t FIntAXCarouselLoadingBuffer = 0x19B8FC330D0; // Unknown = 
    inline constexpr uintptr_t FIntAXCarouselMaxItems = 0x19B8FC32650; // Unknown = 
    inline constexpr uintptr_t FIntAXCarouselPeakFraction = 0x19B8FC33150; // Unknown = 
    inline constexpr uintptr_t FIntAXCatalogMainNavHeight = 0x19B9026D950; // Unknown = 
    inline constexpr uintptr_t FIntAXCatalogMultiItemShoppingFtuxOtherPromptMaxCount = 0x19B8FC36B90; // Unknown = 
    inline constexpr uintptr_t FIntAXCatalogPartialPageModalBottomInsetMultiplier = 0x19B9F0082D0; // Unknown = 
    inline constexpr uintptr_t FIntAXCategoryPillPositionAnimationDampingRatio = 0x19B9F00BE10; // Unknown = 
    inline constexpr uintptr_t FIntAXCategoryPillPositionAnimationFrequency = 0x19B9F00BED0; // Unknown = 
    inline constexpr uintptr_t FIntAXCategoryPillTransparencyAnimationDampingRatio = 0x19B9F00B550; // Unknown = 
    inline constexpr uintptr_t FIntAXCategoryPillTransparencyAnimationFrequency = 0x19B9F00BB90; // Unknown = 
    inline constexpr uintptr_t FIntAXCheckoutButtonTooltipExpireTime = 0x19B8FC36F10; // Unknown = 
    inline constexpr uintptr_t FIntAXCheckoutButtonTooltipFtuxDelay = 0x19B8FC36CD0; // Unknown = 
    inline constexpr uintptr_t FIntAXClusterCompositionTimeoutMs = 0x19B9F0047D0; // Unknown = 
    inline constexpr uintptr_t FIntAXDefaultInventoryPageSize = 0x19BA3A57AD0; // Unknown = 
    inline constexpr uintptr_t FIntAXEnhancedAvatarHeadsFtuxDelay = 0x19BB6EF4AF0; // Unknown = 
    inline constexpr uintptr_t FIntAXEnhancedAvatarHeadsFtuxDelayMs = 0x19B8F902250; // Unknown = 
    inline constexpr uintptr_t FIntAXEyeMakeupZoomRadius = 0x19B9F009D90; // Unknown = 
    inline constexpr uintptr_t FIntAXEyebrowsZoomRadius = 0x19B9F009CD0; // Unknown = 
    inline constexpr uintptr_t FIntAXEyelashesZoomRadius = 0x19B9F009C90; // Unknown = 
    inline constexpr uintptr_t FIntAXFPSDurationForCatSubCat = 0x19B906450D0; // Unknown = 
    inline constexpr uintptr_t FIntAXFaceMakeupZoomRadius = 0x19B9F009D10; // Unknown = 
    inline constexpr uintptr_t FIntAXGetAvatarDataThrottleInterval = 0x19B906432D0; // Unknown = 
    inline constexpr uintptr_t FIntAXGuiObjectIsObscuredPadding = 0x19B9F928A90; // Unknown = 
    inline constexpr uintptr_t FIntAXHDCatalogTabPosition = 0x19B9026F1D0; // Unknown = 
    inline constexpr uintptr_t FIntAXHeadRefinementTooltipExpirationDurationDays = 0x19B9026C310; // Unknown = 
    inline constexpr uintptr_t FIntAXLipMakeupZoomRadius = 0x19B9F009D50; // Unknown = 
    inline constexpr uintptr_t FIntAXLookImpressionDeferTimeoutMs = 0x19BA3A56850; // Unknown = 
    inline constexpr uintptr_t FIntAXLookOutfitCreationDelayMs = 0x19BA3A5B410; // Unknown = 
    inline constexpr uintptr_t FIntAXLookOutfitCreationDelayMs1 = 0x19BA3A5B750; // Unknown = 
    inline constexpr uintptr_t FIntAXLooksImageOffsetMultiplierX = 0x19B8F9DF590; // Unknown = 
    inline constexpr uintptr_t FIntAXLooksImageOffsetMultiplierY = 0x19B8F9DF6D0; // Unknown = 
    inline constexpr uintptr_t FIntAXLooksImageZoom = 0x19B8F9DF4D0; // Unknown = 
    inline constexpr uintptr_t FIntAXMainNavHeight = 0x19B9026DB10; // Unknown = 
    inline constexpr uintptr_t FIntAXMakeupCategoryPosition = 0x19BBC7A4690; // Unknown = 
    inline constexpr uintptr_t FIntAXMakeupLayeringTooltipDismissTimeoutSeconds = 0x19B8FC36310; // Unknown = 
    inline constexpr uintptr_t FIntAXMakeupLayeringTooltipMaxSeenCount = 0x19B8FC36810; // Unknown = 
    inline constexpr uintptr_t FIntAXMakeupLayeringTooltipShowDelayMS = 0x19B8FC367D0; // Unknown = 
    inline constexpr uintptr_t FIntAXMakeupLooksZoomRadius = 0x19B9F009C50; // Unknown = 
    inline constexpr uintptr_t FIntAXMakeupMax6LayersPromptMaxSeenCount = 0x19B8FC361D0; // Unknown = 
    inline constexpr uintptr_t FIntAXMakeupReleaseFtuxPromptDelayMS = 0x19B8FC37090; // Unknown = 
    inline constexpr uintptr_t FIntAXMakeupZoomRadius = 0x19B9F009C10; // Unknown = 
    inline constexpr uintptr_t FIntAXMaxAutocompleteSearchTextLen = 0x19B93A14890; // Unknown = 
    inline constexpr uintptr_t FIntAXMaxRecentSearchTerms = 0x19B9029E890; // Unknown = 
    inline constexpr uintptr_t FIntAXMaxRecentlyViewedSearchItems = 0x19B93A147B0; // Unknown = 
    inline constexpr uintptr_t FIntAXMaxRecentlyViewedSearchItemsInCarousel = 0x19B93A14CF0; // Unknown = 
    inline constexpr uintptr_t FIntAXMaxThumbnailsToPrefetchPerWidgetLargeScreen = 0x19B90648890; // Unknown = 
    inline constexpr uintptr_t FIntAXMaxThumbnailsToPrefetchPerWidgetSmallScreen = 0x19B906482D0; // Unknown = 
    inline constexpr uintptr_t FIntAXMaxUndoRedoHistory = 0x19B9026CA10; // Unknown = 
    inline constexpr uintptr_t FIntAXMinSaveIntervalSeconds = 0x19BBB851E50; // Unknown = 
    inline constexpr uintptr_t FIntAXMinSecsToRefreshRecommendedCatalogPage = 0x19BA3A50B90; // Unknown = 
    inline constexpr uintptr_t FIntAXOutfitNameMaxLength = 0x19B8F906210; // Unknown = 
    inline constexpr uintptr_t FIntAXPrefetchTTL = 0x19BA3A534D0; // Unknown = 
    inline constexpr uintptr_t FIntAXPrefetchWidgetHydrationRowsLandscape = 0x19B8F903F10; // Unknown = 
    inline constexpr uintptr_t FIntAXPrefetchWidgetHydrationRowsPortrait = 0x19B8F903CD0; // Unknown = 
    inline constexpr uintptr_t FIntAXSearchAutocompleteDebounceMs = 0x19B93A16E40; // Unknown = 
    inline constexpr uintptr_t FIntAXSkyboxBlockerPositionX = 0x19B90647C90; // Unknown = 
    inline constexpr uintptr_t FIntAXSkyboxBlockerPositionY = 0x19B90647D10; // Unknown = 
    inline constexpr uintptr_t FIntAXSkyboxBlockerPositionZ = 0x19B90647D90; // Unknown = 
    inline constexpr uintptr_t FIntAXSkyboxBlockerSizeX = 0x19B90647B10; // Unknown = 
    inline constexpr uintptr_t FIntAXSkyboxBlockerSizeY = 0x19B90647B90; // Unknown = 
    inline constexpr uintptr_t FIntAXSkyboxBlockerSizeZ = 0x19B90647C10; // Unknown = 
    inline constexpr uintptr_t FIntAXSlotBasedEditorAvatarSwitcherFtuxDelay2 = 0x19B9026CB50; // Unknown = 
    inline constexpr uintptr_t FIntAXSlotBasedEditorCustomizeFtuxDelay2 = 0x19B9026CF90; // Unknown = 
    inline constexpr uintptr_t FIntAXSponsoredItemsRow = 0x19B9026D6D0; // Unknown = 
    inline constexpr uintptr_t FIntAXSubcategoryPillFadeAnimationDampingRatio = 0x19B9F00BCD0; // Unknown = 
    inline constexpr uintptr_t FIntAXSubcategoryPillFadeAnimationDurationMs = 0x19B9F00C090; // Unknown = 
    inline constexpr uintptr_t FIntAXSubcategoryPillFadeAnimationFrequency = 0x19B9F00C010; // Unknown = 
    inline constexpr uintptr_t FIntAXTooltipMaxNumberOfTimesSeen = 0x19BA7FC1CD8; // Unknown = 
    inline constexpr uintptr_t FIntAXTooltipTimeToDismiss = 0x19B9F00DAD0; // Unknown = 
    inline constexpr uintptr_t FIntAXViewportCameraFieldOfView = 0x19B9F0A6510; // Unknown = 
    inline constexpr uintptr_t FIntAXWidgetLoadedItemCountLimit = 0x19BA3A56C10; // Unknown = 
    inline constexpr uintptr_t FIntAbuseReportMenuScreenshotReduceMotionWaitFrames = 0x19BB7F44250; // Unknown = 
    inline constexpr uintptr_t FIntAbuseReportMenuScreenshotWaitFrames = 0x19BB7F42410; // Unknown = 
    inline constexpr uintptr_t FIntAbuseReportTabClearCapturedScreenshotOnCloseFixDelay = 0x19B9FD8F8C8; // Unknown = 
    inline constexpr uintptr_t FIntAccountPickerVariantOverride2 = 0x19B9ACB5190; // Unknown = 
    inline constexpr uintptr_t FIntAccountRecoverySecondsBetweenResends = 0x19B88C4C490; // Unknown = 
    inline constexpr uintptr_t FIntAccountSwitchRelaunchFallbackSeconds = 0x19B88C4D9D0; // Unknown = 
    inline constexpr uintptr_t FIntAccountSwitcherAccountLimit = 0x19B88C4CC50; // Unknown = 
    inline constexpr uintptr_t FIntAchievementGrantedThrottleHundrethsPercent = 0x19B9F923790; // Unknown = 
    inline constexpr uintptr_t FIntActiveSquadInitPollingDelaySeconds = 0x19BA802EBD0; // Unknown = 
    inline constexpr uintptr_t FIntActiveSquadPollingCardIntervalSeconds = 0x19BA8025310; // Unknown = 
    inline constexpr uintptr_t FIntActiveSquadPollingIdleIntervalSeconds = 0x19BA8022CD0; // Unknown = 
    inline constexpr uintptr_t FIntActiveSquadPollingLobbyIntervalSeconds = 0x19BA8029E10; // Unknown = 
    inline constexpr uintptr_t FIntAdGuiInteractivityPixelsPerStud = 0x19BA8A0FE10; // Unknown = 
    inline constexpr uintptr_t FIntAdIdentificationMinimumAreaPerMyriad = 0x19BBB7FC9D0; // Unknown = 
    inline constexpr uintptr_t FIntAdIdentifiedTelemetryThrottleHundredthsPercent = 0x19BBB7F8550; // Unknown = 
    inline constexpr uintptr_t FIntAddFriendsHttpRetryCount = 0x19B9011EB10; // Unknown = 
    inline constexpr uintptr_t FIntAddUILessModeVariant = 0x19B84F31B60; // Unknown = 
    inline constexpr uintptr_t FIntAgentTurnFeedbackEventThrottleHundredthsPercent = 0x19BAD58B1D0; // Unknown = 
    inline constexpr uintptr_t FIntAiOverviewExplicitFeedbackThrottleHundrethsPercent = 0x19BA6793810; // Unknown = 
    inline constexpr uintptr_t FIntAiOverviewSentimentThrottleHundrethsPercent = 0x19BA6794B90; // Unknown = 
    inline constexpr uintptr_t FIntAllFriendsCacheTtlSec = 0x19B8F90E410; // Unknown = 
    inline constexpr uintptr_t FIntAppChatBehaviorCollectionEnabledPercentage = 0x19BACE7B090; // Unknown = 
    inline constexpr uintptr_t FIntAppChatChatLandingInitialFetchLimit = 0x19B8FA1E790; // Unknown = 
    inline constexpr uintptr_t FIntAppChatChatLandingInitialFetchMinimumConversations = 0x19B8FA1E4D0; // Unknown = 
    inline constexpr uintptr_t FIntAppChatGetAllMessagesDepth = 0x19BAC4BC458; // Unknown = 
    inline constexpr uintptr_t FIntAppChatInExperienceDisplayOrder = 0x19BA8024350; // Unknown = 
    inline constexpr uintptr_t FIntAppChatInExperienceMountMinLoadingTimeMs = 0x19BA8029090; // Unknown = 
    inline constexpr uintptr_t FIntAppChatInitialMessageFetchLimit = 0x19BACE77A90; // Unknown = 
    inline constexpr uintptr_t FIntAppChatMessageFetchRetryDelayMs = 0x19BACE76050; // Unknown = 
    inline constexpr uintptr_t FIntAppChatMessageInitialFetchMinMessages = 0x19BACE78950; // Unknown = 
    inline constexpr uintptr_t FIntAppChatMessageLongPressDismissDelayMs = 0x19BACE71150; // Unknown = 
    inline constexpr uintptr_t FIntAppChatMessageLongPressDistanceThreshold = 0x19BACE70B90; // Unknown = 
    inline constexpr uintptr_t FIntAppChatModalSeenImpressionDelayMs = 0x19BACE7D9D0; // Unknown = 
    inline constexpr uintptr_t FIntAppChatNetworkingHttpRetryCount = 0x19BA607F190; // Unknown = 
    inline constexpr uintptr_t FIntAppChatNetworkingTelemetryThrottlingThousandths = 0x19BA515AC10; // Unknown = 
    inline constexpr uintptr_t FIntAppChatNewMessageFetchMaxDepth = 0x19B9026B790; // Unknown = 
    inline constexpr uintptr_t FIntAppChatOsaAutoScrollDelayMs = 0x19BACE7A250; // Unknown = 
    inline constexpr uintptr_t FIntAppChatPerfChatConversationPaginationInitialRender = 0x19BACE7FB90; // Unknown = 
    inline constexpr uintptr_t FIntAppChatPerfChatConversationPaginationOnEndReached = 0x19BAFB62CB0; // Unknown = 
    inline constexpr uintptr_t FIntAppChatPerfChatConversationPaginationOnStartReached = 0x19BACE74C50; // Unknown = 
    inline constexpr uintptr_t FIntAppChatPerfChatConversationPaginationWindowSize = 0x19BACE7C090; // Unknown = 
    inline constexpr uintptr_t FIntAppChatPerfChatLandingPaginationInitialRender = 0x19B8FA1F290; // Unknown = 
    inline constexpr uintptr_t FIntAppChatPerfChatLandingPaginationOnEndReachedUnits = 0x19B8FA1F410; // Unknown = 
    inline constexpr uintptr_t FIntAppChatPerfChatLandingPaginationOnStartReachedUnits = 0x19B8FA1F390; // Unknown = 
    inline constexpr uintptr_t FIntAppChatPerfChatLandingPaginationWindowSize = 0x19B8FA1F090; // Unknown = 
    inline constexpr uintptr_t FIntAppChatReplyIconSwipeOffset = 0x19BACE72CD0; // Unknown = 
    inline constexpr uintptr_t FIntAppChatRoduxNetworkingHttpRetryCount = 0x19B9026B150; // Unknown = 
    inline constexpr uintptr_t FIntAppChatScrollPerfMinDistancePx = 0x19BA802CD50; // Unknown = 
    inline constexpr uintptr_t FIntAppChatScrollPerfMinStableFrames = 0x19BA80286D0; // Unknown = 
    inline constexpr uintptr_t FIntAppChatSwipeCompleteThreshold = 0x19BACE75CD0; // Unknown = 
    inline constexpr uintptr_t FIntAppChatSwipeMaxVerticalDrift = 0x19BACE711D0; // Unknown = 
    inline constexpr uintptr_t FIntAppChatSwipeStartThreshold = 0x19BA4A7D888; // Unknown = 
    inline constexpr uintptr_t FIntAppChatWideBreakpointMinHeight = 0x19B86E1B888; // Unknown = 
    inline constexpr uintptr_t FIntAppChatWideBreakpointMinWidth = 0x19B8FA16190; // Unknown = 
    inline constexpr uintptr_t FIntAppHover1VolumePercentage = 0x19B8C345810; // Unknown = 
    inline constexpr uintptr_t FIntAppIaScrollAwayThreshold = 0x19BA609DBD0; // Unknown = 
    inline constexpr uintptr_t FIntAppLaunchReactProfilerLoggerCollectionTimeoutSec = 0x19BA609BF90; // Unknown = 
    inline constexpr uintptr_t FIntAppLaunchTrackerEnableHundredthsPercent = 0x19B8C315910; // Unknown = 
    inline constexpr uintptr_t FIntAppMusicVolumePercentage = 0x19B90293310; // Unknown = 
    inline constexpr uintptr_t FIntAppNotificationHighVolumePercentage = 0x19B8C345950; // Unknown = 
    inline constexpr uintptr_t FIntAppSelectVolumePercentage = 0x19B8C345AD0; // Unknown = 
    inline constexpr uintptr_t FIntAttributionContextRecordedThrottleHundredthsPercent = 0x19B90290FD0; // Unknown = 
    inline constexpr uintptr_t FIntAuthButtonClickedThrottlingHundredthsPercent = 0x19BBC1C9FD0; // Unknown = 
    inline constexpr uintptr_t FIntAuthPageMountThrottlingHundredthsPercent = 0x19BBC1CE5D0; // Unknown = 
    inline constexpr uintptr_t FIntAutoFocusFailsafeThreshold = 0x19B8F9087D0; // Unknown = 
    inline constexpr uintptr_t FIntAutoJoinNewServerTimeMs = 0x19B9AF14550; // Unknown = 
    inline constexpr uintptr_t FIntAvatarChatHeartbeatStatsEventThrottleHundrethsPercent = 0x19B9F0AC450; // Unknown = 
    inline constexpr uintptr_t FIntAvatarEditorParticleEmitterRateOverride = 0x19B90647750; // Unknown = 
    inline constexpr uintptr_t FIntAvatarEditorTimeBetweenSaves = 0x19B90646A50; // Unknown = 
    inline constexpr uintptr_t FIntAvatarGoldenRatio = 0x19D8952F310; // Unknown = 
    inline constexpr uintptr_t FIntAvatarSwitcherGridOnEndReachedThreshold = 0x19BC2215B50; // Unknown = 
    inline constexpr uintptr_t FIntBlackbirdUpsellBannerMaxSessionImpressions = 0x19B9EE00490; // Unknown = 
    inline constexpr uintptr_t FIntBlackbirdUpsellMaxPriceForDiscountInclusive = 0x19B9AF1CBD0; // Unknown = 
    inline constexpr uintptr_t FIntBlackbirdUpsellMinPriceForDiscountInclusive = 0x19B9AF1C210; // Unknown = 
    inline constexpr uintptr_t FIntBlockUserButtonClickThrottleHundredthsPercent = 0x19BBC386810; // Unknown = 
    inline constexpr uintptr_t FIntBlockUserButtonClickThrottleHundredthsPercent4 = 0x19BBC38D710; // Unknown = 
    inline constexpr uintptr_t FIntBlockUserThrottleHundredthsPercent = 0x19BBC385310; // Unknown = 
    inline constexpr uintptr_t FIntBlockUserThrottleHundredthsPercent4 = 0x19BBC389990; // Unknown = 
    inline constexpr uintptr_t FIntBubbleChatAddMessageRolloutPercent = 0x19BACE7C390; // Unknown = 
    inline constexpr uintptr_t FIntBugReporterErrorHundredthsPercent = 0x19B90293AD0; // Unknown = 
    inline constexpr uintptr_t FIntBugReporterMilestoneHundredthsPercent = 0x19B90293890; // Unknown = 
    inline constexpr uintptr_t FIntBugReportingHttpRetryCount = 0x19B90293C50; // Unknown = 
    inline constexpr uintptr_t FIntBuildAgentDetailsStatusMenuWidth = 0x19BAD58C150; // Unknown = 
    inline constexpr uintptr_t FIntBuildCreatorCreditPostTurnRefreshDelaySeconds = 0x19BAD58CF50; // Unknown = 
    inline constexpr uintptr_t FIntBuildCreatorCreditResetRefreshBufferSeconds = 0x19BAD58CD50; // Unknown = 
    inline constexpr uintptr_t FIntBuildExperienceAssistantStatusSwapIntervalSeconds = 0x19BAD28EB10; // Unknown = 
    inline constexpr uintptr_t FIntBuildExperienceAssistantThinkingDurationSuffixDelaySeconds = 0x19BAD28E710; // Unknown = 
    inline constexpr uintptr_t FIntBuildExperienceAudienceTooltipMaxWidth = 0x19BAD58F1D0; // Unknown = 
    inline constexpr uintptr_t FIntBuildExperienceEventThrottleHundredthsPercent = 0x19B859C9CD0; // Unknown = 
    inline constexpr uintptr_t FIntBuildExperienceRollbackPlaceMaxRetries = 0x19BAD28FED0; // Unknown = 
    inline constexpr uintptr_t FIntBuildExperienceRollbackPlaceRetryDelayMs = 0x19BAD28FD10; // Unknown = 
    inline constexpr uintptr_t FIntBuildExperienceSetAudiencesMaxRetries = 0x19BAD58EF90; // Unknown = 
    inline constexpr uintptr_t FIntBuildExperienceSetAudiencesRetryDelayMs = 0x19BAD58ED10; // Unknown = 
    inline constexpr uintptr_t FIntBuildExperienceTurnActivityGapMsThrottleHundredthsPercent = 0x19BAD58AAD0; // Unknown = 
    inline constexpr uintptr_t FIntBuildExperienceUserPickerSearchDebounceMs = 0x19BAD58FD90; // Unknown = 
    inline constexpr uintptr_t FIntBuildHistoryLoadTriggerViewportHeightPercent = 0x19BAD587D50; // Unknown = 
    inline constexpr uintptr_t FIntBuildMinimumUsableRobuxBalance = 0x19BAD58CE10; // Unknown = 
    inline constexpr uintptr_t FIntBuildOverflowMenuWidth = 0x19BAD585490; // Unknown = 
    inline constexpr uintptr_t FIntBuildPolicyRefreshTimeoutMs = 0x19BACE73310; // Unknown = 
    inline constexpr uintptr_t FIntBuildPublishPreviewCardMaxWidth = 0x19BACE71550; // Unknown = 
    inline constexpr uintptr_t FIntBuilderSansNavBarMaxSize = 0x19B906493D0; // Unknown = 
    inline constexpr uintptr_t FIntBuilderSansNavBarMinSize = 0x19B90649490; // Unknown = 
    inline constexpr uintptr_t FIntBulkPurchaseEnabledCountdownMS = 0x19B9F927C50; // Unknown = 
    inline constexpr uintptr_t FIntBulkPurchaseMaxHttpRequestRetries = 0x19B9F9294D0; // Unknown = 
    inline constexpr uintptr_t FIntBulkPurchaseMaxHttpRequestWaitTime = 0x19B9F92A210; // Unknown = 
    inline constexpr uintptr_t FIntBulkPurchaseMissingPurchaseOptionsCounterThrottleHundredthsPercent = 0x19BC27C7380; // Unknown = 
    inline constexpr uintptr_t FIntBulkPurchaseRequestLimit = 0x19B9ACB95D0; // Unknown = 
    inline constexpr uintptr_t FIntBulkPurchaseThrottleLimit = 0x19B9ACB81D0; // Unknown = 
    inline constexpr uintptr_t FIntCameraPresetHeadshotExtentScaleHundredths = 0x19D8952F8D0; // Unknown = 
    inline constexpr uintptr_t FIntCaptureControlsStoredAnchorPoints = 0x19D86F0AD50; // Unknown = 
    inline constexpr uintptr_t FIntCaptureMetadataGetAvatarsTimeoutMs = 0x19BAC87FC10; // Unknown = 
    inline constexpr uintptr_t FIntCaptureMetadataMaxAvatars = 0x19BAC87F890; // Unknown = 
    inline constexpr uintptr_t FIntCaptureMetadataMinAvatarBoundingBoxPixels = 0x19BA6C40030; // Unknown = 
    inline constexpr uintptr_t FIntCaptureMetadataMinHitRatePercentage = 0x19D8504BE70; // Unknown = 
    inline constexpr uintptr_t FIntCapturesCommonMaxHttpRequestRetries = 0x19BAC876490; // Unknown = 
    inline constexpr uintptr_t FIntCapturesCommonMaxHttpRequestWaitTime = 0x19B9298EBE0; // Unknown = 
    inline constexpr uintptr_t FIntCapturesCoreGuiEventsPerMyriad = 0x19BACE94E90; // Unknown = 
    inline constexpr uintptr_t FIntCapturesMaxHttpRequestRetries = 0x19BAC87DB50; // Unknown = 
    inline constexpr uintptr_t FIntCapturesMaxHttpRequestWaitTime = 0x19BAC87DC90; // Unknown = 
    inline constexpr uintptr_t FIntCapturesSaveToExternalStorageLimit = 0x19BA4561D60; // Unknown = 
    inline constexpr uintptr_t FIntCapturesTelemetryThrottlingThousandths = 0x19BAC87D290; // Unknown = 
    inline constexpr uintptr_t FIntChallengeDialogEventReceiverHttpRetryCount = 0x19B90641290; // Unknown = 
    inline constexpr uintptr_t FIntChallengeDialogModalContainerHttpRetryCount = 0x19B90642990; // Unknown = 
    inline constexpr uintptr_t FIntCharacterNameHandlerUserProfileApiRollout = 0x19B8C2E9B90; // Unknown = 
    inline constexpr uintptr_t FIntChatAutocompleteMaxVisibleEntries = 0x19B9CB7B410; // Unknown = 
    inline constexpr uintptr_t FIntChatGetConversationsPageSize = 0x19BA607CD10; // Unknown = 
    inline constexpr uintptr_t FIntChatInterventionUIRateLimitWindowSec = 0x19BACE78590; // Unknown = 
    inline constexpr uintptr_t FIntChatModerationFrameLayoutOrder = 0x19B9FD8B550; // Unknown = 
    inline constexpr uintptr_t FIntCheckLeaveGameUpsellCooldown = 0x19BACE9C050; // Unknown = 
    inline constexpr uintptr_t FIntChromeWindowLayoutOrder = 0x19D81689C50; // Unknown = 
    inline constexpr uintptr_t FIntCloseReactPageThrottleHundredthsPercent = 0x19BACFE7D90; // Unknown = 
    inline constexpr uintptr_t FIntCommercePurchaseMaxHttpRequestRetries = 0x19B9FD84050; // Unknown = 
    inline constexpr uintptr_t FIntCommercePurchaseMaxHttpRequestWaitTime = 0x19B9FD830D0; // Unknown = 
    inline constexpr uintptr_t FIntCommsFAELockTimestamp = 0x19BBC7AB310; // Unknown = 
    inline constexpr uintptr_t FIntCompactUpsellModalBreakpoint = 0x19BAC830250; // Unknown = 
    inline constexpr uintptr_t FIntConnectionAmpGameJoinUpsellImpressionThrottleHundredthsPercent = 0x19BBC38C110; // Unknown = 
    inline constexpr uintptr_t FIntConnectionAmpUnlockPlayIntentThrottleHundredthsPercent = 0x19BBC382890; // Unknown = 
    inline constexpr uintptr_t FIntConnectionAutoReconnectBaseDelayMs = 0x19BA672CAD0; // Unknown = 
    inline constexpr uintptr_t FIntConnectionAutoReconnectFirstDelayMs = 0x19BA672C890; // Unknown = 
    inline constexpr uintptr_t FIntConnectionAutoReconnectJitterMs = 0x19BA672CED0; // Unknown = 
    inline constexpr uintptr_t FIntConnectionAutoReconnectMaxDelayMs = 0x19BA672CD10; // Unknown = 
    inline constexpr uintptr_t FIntConnectionAutoReconnectMaxDurationSeconds = 0x19BA672CE10; // Unknown = 
    inline constexpr uintptr_t FIntContactImporterHttpRetryCount = 0x19BAFCFCA10; // Unknown = 
    inline constexpr uintptr_t FIntContactImporterModalDisplayMaxCount = 0x19BAFCF1390; // Unknown = 
    inline constexpr uintptr_t FIntContactImporterModalDisplayMinDays = 0x19BAFB29810; // Unknown = 
    inline constexpr uintptr_t FIntContactImporterSyncMinHours = 0x19BAFCF2A10; // Unknown = 
    inline constexpr uintptr_t FIntContactImporterUploadContactsMax = 0x19BAFCF3390; // Unknown = 
    inline constexpr uintptr_t FIntContactImporterUploadContactsMin = 0x19BAFCF6DD0; // Unknown = 
    inline constexpr uintptr_t FIntContactsSyncWarningImpressionsCountCap = 0x19BAFCF9850; // Unknown = 
    inline constexpr uintptr_t FIntContentPostsThumbnailsInitialDelayTimeMs = 0x19BAC876A10; // Unknown = 
    inline constexpr uintptr_t FIntContentPostsThumbnailsMaxRetries = 0x19BAC876C50; // Unknown = 
    inline constexpr uintptr_t FIntCoreScriptBacktraceErrorReportPercentage = 0x19BA5530950; // Unknown = 
    inline constexpr uintptr_t FIntCoreScriptBacktracePIIFilterEraseTimeoutSeconds = 0x19BA553A310; // Unknown = 
    inline constexpr uintptr_t FIntCoreScriptBacktraceRepeatedErrorRateLimitCount = 0x19BA553CAD0; // Unknown = 
    inline constexpr uintptr_t FIntCoreScriptBacktraceRepeatedErrorRateLimitPeriod = 0x19BA55358D0; // Unknown = 
    inline constexpr uintptr_t FIntCoreScriptBacktraceRepeatedErrorRateLimitProcessIntervalTenths = 0x19BA553E690; // Unknown = 
    inline constexpr uintptr_t FIntCoreScriptsProfilerDelaySeconds = 0x19B9FD86550; // Unknown = 
    inline constexpr uintptr_t FIntCoreScriptsProfilerDurationSeconds = 0x19B9FD86690; // Unknown = 
    inline constexpr uintptr_t FIntCoreScriptsProfilerSamplingHundredthsPercentv1 = 0x19B9FD86450; // Unknown = 
    inline constexpr uintptr_t FIntCoreScriptsProfilerTelemetryLimit = 0x19B9FD86850; // Unknown = 
    inline constexpr uintptr_t FIntCorescriptMemoryPeriodSeconds = 0x19B8F741B90; // Unknown = 
    inline constexpr uintptr_t FIntCreatorAgentChatMaxCachedSessionHistories = 0x19BAD28A050; // Unknown = 
    inline constexpr uintptr_t FIntCreatorAgentChatMaxReconciliationHistoryPages = 0x19BAD289E50; // Unknown = 
    inline constexpr uintptr_t FIntCreatorAgentChatPollBackoffMultiplier = 0x19BAD289C90; // Unknown = 
    inline constexpr uintptr_t FIntCreatorAgentChatPollMaxIntervalSeconds = 0x19BAD289A50; // Unknown = 
    inline constexpr uintptr_t FIntCreatorAgentChatPollMinIntervalSeconds = 0x19BAD289810; // Unknown = 
    inline constexpr uintptr_t FIntCreatorAgentChatPrefetchHistoryPagesOnRefresh = 0x19BAD289BD0; // Unknown = 
    inline constexpr uintptr_t FIntCreatorAgentChatRpcTimeoutSeconds = 0x19BAD289210; // Unknown = 
    inline constexpr uintptr_t FIntCreatorAgentChatRtnIdleFallbackSeconds = 0x19BAD289450; // Unknown = 
    inline constexpr uintptr_t FIntCreatorAgentChatRtnSequenceGapFallbackSeconds = 0x19BAD289610; // Unknown = 
    inline constexpr uintptr_t FIntCrossDeviceLoginRollout2 = 0x19B9026AA50; // Unknown = 
    inline constexpr uintptr_t FIntCrossExperienceEventThrottleHunderedthsPercent = 0x19B8CA83EB0; // Unknown = 
    inline constexpr uintptr_t FIntCurrencyTransferDeveloperCommissionRate = 0x19B9F92DA90; // Unknown = 
    inline constexpr uintptr_t FIntCurrencyTransferMaxAmount = 0x19B9F92C690; // Unknown = 
    inline constexpr uintptr_t FIntCurrencyTransferMinAmount = 0x19B9F92C510; // Unknown = 
    inline constexpr uintptr_t FIntCurrencyTransferPlatformFeeRate = 0x19B9F92DD10; // Unknown = 
    inline constexpr uintptr_t FIntCurrencyTransferTelemetryCounterThrottleHundredthsPercent = 0x19B9F92CC90; // Unknown = 
    inline constexpr uintptr_t FIntDebounceAIRephraseSettingDelay = 0x19B9FD8A990; // Unknown = 
    inline constexpr uintptr_t FIntDebounceChatSummariesSettingDelay = 0x19B9FD8B190; // Unknown = 
    inline constexpr uintptr_t FIntDebounceDisconnectButtonDelay = 0x19B9FD8AF90; // Unknown = 
    inline constexpr uintptr_t FIntDebugAvatarDataDelay = 0x19B906441D0; // Unknown = 
    inline constexpr uintptr_t FIntDebugConnectDisconnectInterval = 0x19BA5158450; // Unknown = 
    inline constexpr uintptr_t FIntDebugForceMSAASamples = 0x19B8512C130; // Unknown = 
    inline constexpr uintptr_t FIntDebugLuaAppForceGamepad = 0x19BC05481D0; // Unknown = 
    inline constexpr uintptr_t FIntDeepLinkNavigationLockThrottlingHundredthsPercent = 0x19BBC1CFB90; // Unknown = 
    inline constexpr uintptr_t FIntDefaultInfiniteScrollRecommendationsFetchSize = 0x19B9026D9D0; // Unknown = 
    inline constexpr uintptr_t FIntDefaultMaxPruneAccounts = 0x19B8FC38D90; // Unknown = 
    inline constexpr uintptr_t FIntDeferredDeeplinkResolvedThrottleHundredthsPercent = 0x19B90290D10; // Unknown = 
    inline constexpr uintptr_t FIntDeviceIntegrityNativeTimeoutMilliseconds = 0x19BA607E350; // Unknown = 
    inline constexpr uintptr_t FIntDiscoverabilityModalHttpRetryCount = 0x19BAFCFD6D0; // Unknown = 
    inline constexpr uintptr_t FIntDiscoveryAppLaunchErrorHundredthsPercent = 0x19B8C316310; // Unknown = 
    inline constexpr uintptr_t FIntDiscoveryAppLaunchMilestonesHundredthsPercent = 0x19D86D69368; // Unknown = 
    inline constexpr uintptr_t FIntDiscoveryClientAppStorageGetItemErrorThrottleHundredthsPercent = 0x19BA3A73F10; // Unknown = 
    inline constexpr uintptr_t FIntDiscoveryEventErrorDetailsHundredthsPercent = 0x19BA3A711D0; // Unknown = 
    inline constexpr uintptr_t FIntDiscoveryFeedStatsHundredthsPercent = 0x19B8F032A98; // Unknown = 
    inline constexpr uintptr_t FIntDiscoveryResponseErrorEventHundredthsPercent = 0x19BA3A79590; // Unknown = 
    inline constexpr uintptr_t FIntDiscoveryResponseSizeEventHundredthsPercent = 0x19BA3A70FD0; // Unknown = 
    inline constexpr uintptr_t FIntDiscoverySduiErrorHundredthsPercent = 0x19B8FC32490; // Unknown = 
    inline constexpr uintptr_t FIntDiscoverySduiInstrumentationHundredthsPercent = 0x19D86D60C68; // Unknown = 
    inline constexpr uintptr_t FIntDiscoverySduiParamUsageHundredthsPercent = 0x19B8FC32E10; // Unknown = 
    inline constexpr uintptr_t FIntDiscoverySduiTimerEventsHundredthsPercent = 0x19B8FC326D0; // Unknown = 
    inline constexpr uintptr_t FIntDiscoverySduiTypeUsageHundredthsPercent = 0x19B8FC32BD0; // Unknown = 
    inline constexpr uintptr_t FIntDiscoveryVideoEndEventHundredthsPercent = 0x19BA67214D0; // Unknown = 
    inline constexpr uintptr_t FIntDiscoveryVideoLoadEventHundredthsPercent = 0x19BA6728750; // Unknown = 
    inline constexpr uintptr_t FIntDiscoveryVideoLoopEventHundredthsPercent = 0x19BA672FA50; // Unknown = 
    inline constexpr uintptr_t FIntDiscoveryVideoPlayEventHundredthsPercent = 0x19BA6727CD0; // Unknown = 
    inline constexpr uintptr_t FIntDiscoveryWarningEventHundredthsPercent = 0x19BA6796010; // Unknown = 
    inline constexpr uintptr_t FIntDrawerSwipeThresholdPercent = 0x19B9AF16D90; // Unknown = 
    inline constexpr uintptr_t FIntDrawerSwipeVelocityThreshold = 0x19B9AF14BD0; // Unknown = 
    inline constexpr uintptr_t FIntDynamicAbuseReportV2ThrottleHundredthsPercent = 0x19BB7F47510; // Unknown = 
    inline constexpr uintptr_t FIntEditProfileMaxHttpRetries = 0x19B859CAC50; // Unknown = 
    inline constexpr uintptr_t FIntEdpBannerBottomVisiblePercent = 0x19B90262950; // Unknown = 
    inline constexpr uintptr_t FIntEdpFallbackActionBarPlayButtonWidth = 0x19B90262210; // Unknown = 
    inline constexpr uintptr_t FIntEdpFullBleedOverlapOffset = 0x19B90262890; // Unknown = 
    inline constexpr uintptr_t FIntEducationalPopupDisplayMaxCount = 0x19BB6EF91D0; // Unknown = 
    inline constexpr uintptr_t FIntEnableContactInvitesForNonPhoneVerifiedRollout = 0x19B8C2E9D50; // Unknown = 
    inline constexpr uintptr_t FIntEnableNewInviteMenuStyleRollout = 0x19B9F295550; // Unknown = 
    inline constexpr uintptr_t FIntEnableSentryUARolloutPercentage = 0x19B90295350; // Unknown = 
    inline constexpr uintptr_t FIntEnableUnifiedProductPurchaseFlowThrottleHundredthsPercent = 0x19D85DC7B10; // Unknown = 
    inline constexpr uintptr_t FIntEventNetworkHttpRetryCount = 0x19B8FC37690; // Unknown = 
    inline constexpr uintptr_t FIntEventStatusCheckIntervalSec = 0x19B8F90E690; // Unknown = 
    inline constexpr uintptr_t FIntExpChatChatableUserCountSystemMessageMinUsers = 0x19BBC381790; // Unknown = 
    inline constexpr uintptr_t FIntExpChatDefaultARButtonPadding = 0x19BA515F110; // Unknown = 
    inline constexpr uintptr_t FIntExpChatDefaultARButtonPaddingInset = 0x19BA515C590; // Unknown = 
    inline constexpr uintptr_t FIntExpChatGlobalChatTabClickedThrottlePerMyriad = 0x19BBACA5EC8; // Unknown = 
    inline constexpr uintptr_t FIntExpChatHiddenMessagesPromptThresholdLowerBound = 0x19BA74A4490; // Unknown = 
    inline constexpr uintptr_t FIntExpChatHiddenMessagesPromptThresholdUpperBound = 0x19BA74A4FD0; // Unknown = 
    inline constexpr uintptr_t FIntExpChatMessageRenderUserThrottlePermyriad = 0x19BBCD70FD0; // Unknown = 
    inline constexpr uintptr_t FIntExpChatMessageResponseThrottlePermyriad = 0x19BA74A4E50; // Unknown = 
    inline constexpr uintptr_t FIntExpChatMessageResponseUserSamplePermyriad = 0x19BA74A49D0; // Unknown = 
    inline constexpr uintptr_t FIntExpChatMicActivityHeartbeatIncrement = 0x19BBCD77290; // Unknown = 
    inline constexpr uintptr_t FIntExpChatPresetActionThrottlePerMyriad = 0x19B8FA13A50; // Unknown = 
    inline constexpr uintptr_t FIntExpChatPresetChatIconBadgeOverride = 0x19BAF80A470; // Unknown = 
    inline constexpr uintptr_t FIntExpChatPresetChatLoadAnalyticsTimeoutMs = 0x19BA74A2F90; // Unknown = 
    inline constexpr uintptr_t FIntExpChatProximityStoreExtraRendersBeforeUnmount = 0x19B861B4778; // Unknown = 
    inline constexpr uintptr_t FIntExpChatRandomCharChangeLowerBound = 0x19B9CB75190; // Unknown = 
    inline constexpr uintptr_t FIntExpChatRandomCharChangeUpperBound = 0x19B9CB71B10; // Unknown = 
    inline constexpr uintptr_t FIntExpChatRewriteDropdownToggledThrottlePerMyriad = 0x19B8FA121D0; // Unknown = 
    inline constexpr uintptr_t FIntExpChatScrollLockThreshold = 0x19BA3A59990; // Unknown = 
    inline constexpr uintptr_t FIntExpChatSlotBatchSize = 0x19BA5158350; // Unknown = 
    inline constexpr uintptr_t FIntExpChatTabClickedThrottlePerMyriad = 0x19B8FA13250; // Unknown = 
    inline constexpr uintptr_t FIntExpChatTabImpressionThrottlePerMyriad = 0x19B8FA138D0; // Unknown = 
    inline constexpr uintptr_t FIntExpChatVisibleARButtonPadding = 0x19BA5159B10; // Unknown = 
    inline constexpr uintptr_t FIntExpChatVisibleARButtonPaddingInset = 0x19BA515A990; // Unknown = 
    inline constexpr uintptr_t FIntExpChatWindowScrollV3Debounce = 0x19BA3A5F310; // Unknown = 
    inline constexpr uintptr_t FIntExpChatWindowTransparencyRewriteInteractableThreshold = 0x19BA515D950; // Unknown = 
    inline constexpr uintptr_t FIntExpChatWindowTransparencyRewriteInteractableThresholdHundredth = 0x19BA5155810; // Unknown = 
    inline constexpr uintptr_t FIntExperienceChatHeartbeatIncrement = 0x19BBCD72510; // Unknown = 
    inline constexpr uintptr_t FIntExperienceChatUserProfileApiRollout_v1 = 0x19BA515B450; // Unknown = 
    inline constexpr uintptr_t FIntExperienceDetailsMotionJitterHundredthsPercent = 0x19B90261890; // Unknown = 
    inline constexpr uintptr_t FIntFAEBackgroundOnlyPollDelay = 0x19B90112CD0; // Unknown = 
    inline constexpr uintptr_t FIntFAEBackgroundOnlyPollMaxRetries = 0x19B90113110; // Unknown = 
    inline constexpr uintptr_t FIntFAEWithCallbackPollDelay = 0x19B901120D0; // Unknown = 
    inline constexpr uintptr_t FIntFAEWithCallbackPollMaxRetries = 0x19B90112D10; // Unknown = 
    inline constexpr uintptr_t FIntFAEWithWebViewCallbackPollDelay = 0x19B90113250; // Unknown = 
    inline constexpr uintptr_t FIntFAEWithWebViewCallbackPollMaxRetries = 0x19B90113410; // Unknown = 
    inline constexpr uintptr_t FIntFIntAXMinSaveIntervalSeconds = 0x19B9026C910; // Unknown = 
    inline constexpr uintptr_t FIntFIntCrossExperienceEventThrottleHunderedthsPercent = 0x19B8ED7F990; // Unknown = 
    inline constexpr uintptr_t FIntFIntInGameBuildChatSheetSnapPoint = 0x19BACE73190; // Unknown = 
    inline constexpr uintptr_t FIntFIntLegacyPurchaseFPSTrackingTimeout = 0x19B9AF1BC50; // Unknown = 
    inline constexpr uintptr_t FIntFIntMuteSelfThrottleHundredthsPercent4 = 0x19BBC386090; // Unknown = 
    inline constexpr uintptr_t FIntFIntPeoplePageLayoutChangedThrottleHundredthsPercent = 0x19BBC386B50; // Unknown = 
    inline constexpr uintptr_t FIntFIntPersonCardMenuToggledThrottleHundredthsPercent = 0x19BBC389C90; // Unknown = 
    inline constexpr uintptr_t FIntFIntSocialUpsellEventThrottleHunderedthsPercent = 0x19BA6096BD0; // Unknown = 
    inline constexpr uintptr_t FIntFIntUIResetDelayInSec = 0x19B9119EB80; // Unknown = 
    inline constexpr uintptr_t FIntFIntUnmuteSelfThrottleHundredthsPercent4 = 0x19BBC386A90; // Unknown = 
    inline constexpr uintptr_t FIntFPSAwareSplashScreenTimeout = 0x19BA8A088D0; // Unknown = 
    inline constexpr uintptr_t FIntFTUXPanelXOffset = 0x19D81689DD0; // Unknown = 
    inline constexpr uintptr_t FIntFacialAnimationStreamingHeartbeatStatsIntervalSec = 0x19B869BD520; // Unknown = 
    inline constexpr uintptr_t FIntFallbackExclusiveUnderageCutoffForMultiPageSignup = 0x19B945A8BD0; // Unknown = 
    inline constexpr uintptr_t FIntFeatureTileAdPlayerOverlayTransparencyPercent = 0x19B90643110; // Unknown = 
    inline constexpr uintptr_t FIntFeedItemRowDataCounterThrottle = 0x19BBE91AE10; // Unknown = 
    inline constexpr uintptr_t FIntFlyoutContentItemClickEventThrottleHunderedthsPercent = 0x19D86D67928; // Unknown = 
    inline constexpr uintptr_t FIntFlyoutSidePanelCloseEventThrottleHunderedthsPercent = 0x19D7C7C85D0; // Unknown = 
    inline constexpr uintptr_t FIntFlyoutSidePanelOpenEventThrottleHunderedthsPercent = 0x19D86D6DFA8; // Unknown = 
    inline constexpr uintptr_t FIntFlyoutTestVariantRollout12 = 0x19BA3BBABD0; // Unknown = 
    inline constexpr uintptr_t FIntFlyoutTooltipDismissEventThrottleHunderedthsPercent = 0x19D7C7C9190; // Unknown = 
    inline constexpr uintptr_t FIntFlyoutTooltipShowEventThrottleHunderedthsPercent = 0x19D7C7C81D0; // Unknown = 
    inline constexpr uintptr_t FIntFriendCarouselRefreshThrottleInterval = 0x19B8FA1D9D0; // Unknown = 
    inline constexpr uintptr_t FIntFriendPlayerJoinedRemoteEventTimeout = 0x19BB2AFD050; // Unknown = 
    inline constexpr uintptr_t FIntFriendRequestNicknameMaxChars = 0x19B901158D0; // Unknown = 
    inline constexpr uintptr_t FIntFriendRequestNicknameMaxHistory = 0x19B90115A10; // Unknown = 
    inline constexpr uintptr_t FIntFriendRequestNicknameMinChars = 0x19B90115790; // Unknown = 
    inline constexpr uintptr_t FIntFriendRequestNicknamesMaxHttpRetries = 0x19B90115550; // Unknown = 
    inline constexpr uintptr_t FIntFriendRequestNicknamesTelemetryThrottlingThousandths = 0x19B901156D0; // Unknown = 
    inline constexpr uintptr_t FIntFriendsCarouselFetchPageDistance = 0x19B8C2EA0D0; // Unknown = 
    inline constexpr uintptr_t FIntFriendsCarouselHttpRetryCount = 0x19B90267310; // Unknown = 
    inline constexpr uintptr_t FIntFriendsCarouselInitialFetchSize = 0x19B8C2EAE90; // Unknown = 
    inline constexpr uintptr_t FIntFriendsCarouselSocialBtnFriendsLimit = 0x19B8C2EAB90; // Unknown = 
    inline constexpr uintptr_t FIntFriendsChatConversationListAutoscrollToTopThreshold = 0x19BA6B3A2D0; // Unknown = 
    inline constexpr uintptr_t FIntFriendsChatConversationListInitialNumToRender = 0x19BA6B3A3D0; // Unknown = 
    inline constexpr uintptr_t FIntFriendsChatConversationListPaginationThresholdRows = 0x19BA6B3A4D0; // Unknown = 
    inline constexpr uintptr_t FIntFriendsChatConversationListScrollbarIdleHideMs = 0x19BA6B3A5D0; // Unknown = 
    inline constexpr uintptr_t FIntFriendsChatConversationListScrollbarThickness = 0x19BA6B3A750; // Unknown = 
    inline constexpr uintptr_t FIntFriendsChatConversationListWindowSize = 0x19BA6B3A950; // Unknown = 
    inline constexpr uintptr_t FIntFriendsChatModeratedMaskMaxLength = 0x19B9F185D40; // Unknown = 
    inline constexpr uintptr_t FIntFriendsChatModeratedMaskMinLength = 0x19B9F188710; // Unknown = 
    inline constexpr uintptr_t FIntFriendsCommonAnalyticsThrottlingThousandths = 0x19B8F90E110; // Unknown = 
    inline constexpr uintptr_t FIntFriendsCountCacheTtlSec = 0x19B8F90E510; // Unknown = 
    inline constexpr uintptr_t FIntFriendsHttpRetryCount = 0x19BA5BDC610; // Unknown = 
    inline constexpr uintptr_t FIntFriendsLandingHttpRetryCount = 0x19BAFB25870; // Unknown = 
    inline constexpr uintptr_t FIntFriendsMenuHttpRetryCount = 0x19BACE76490; // Unknown = 
    inline constexpr uintptr_t FIntFriendsPageSize = 0x19B8F90E590; // Unknown = 
    inline constexpr uintptr_t FIntFriendsStoreProcessDelaySec = 0x19B8F90E290; // Unknown = 
    inline constexpr uintptr_t FIntFriendshipStatusCacheTtlSec = 0x19BC255C8A0; // Unknown = 
    inline constexpr uintptr_t FIntFullscreenTitleBarTriggerDelayMillis = 0x19D89521110; // Unknown = 
    inline constexpr uintptr_t FIntGameCardContainerHttpRetryCount = 0x19BA8027D90; // Unknown = 
    inline constexpr uintptr_t FIntGameConnectionsPlayedChipClickedThrottleHundredthsPercent = 0x19BA6726210; // Unknown = 
    inline constexpr uintptr_t FIntGameCopyExperienceLinkThrottleHundrethsPercent = 0x19BA672C490; // Unknown = 
    inline constexpr uintptr_t FIntGameCreatePrivateGameThrottleHundrethsPercent = 0x19BA6723BD0; // Unknown = 
    inline constexpr uintptr_t FIntGameDetailsSubpageThrottleHundrethsPercent = 0x19BA672F110; // Unknown = 
    inline constexpr uintptr_t FIntGameFavoriteThrottleHundrethsPercent = 0x19BA67238D0; // Unknown = 
    inline constexpr uintptr_t FIntGameFollowThrottleHundrethsPercent = 0x19BA6726D50; // Unknown = 
    inline constexpr uintptr_t FIntGameGridFlexFeedItemTileNumPerFeed = 0x19B88C2ED10; // Unknown = 
    inline constexpr uintptr_t FIntGameInviteEntryPointThrottleHundredthsPercent = 0x19BBC380510; // Unknown = 
    inline constexpr uintptr_t FIntGameInviteHttpRetryCount = 0x19D8952FBD0; // Unknown = 
    inline constexpr uintptr_t FIntGameJoinCardAnalyticsThrottleHundredthsPercent = 0x19B8FA1B1D0; // Unknown = 
    inline constexpr uintptr_t FIntGameJoinFriendsInGameThrottleHundrethsPercent = 0x19BA6723590; // Unknown = 
    inline constexpr uintptr_t FIntGameShareExperienceLinkThrottleHundrethsPercent = 0x19B9F968758; // Unknown = 
    inline constexpr uintptr_t FIntGameTileOverflowMenuActionThrottleHundrethsPercent = 0x19BA672E850; // Unknown = 
    inline constexpr uintptr_t FIntGameVoteThrottleHundrethsPercent = 0x19BA672EF90; // Unknown = 
    inline constexpr uintptr_t FIntGamepadMenuActionThrottleHundrethsPercent = 0x19BAD2807D0; // Unknown = 
    inline constexpr uintptr_t FIntGamepadOpenExperienceControlsMenuThrottleHundrethsPercent = 0x19BAD280390; // Unknown = 
    inline constexpr uintptr_t FIntGameplayPauseShowDelayMs = 0x19B9F0A7410; // Unknown = 
    inline constexpr uintptr_t FIntGenericInterventionSnackbarAutoDismissDelaySeconds = 0x19BA8026ED0; // Unknown = 
    inline constexpr uintptr_t FIntGetRewardMetadataHttpRetryCount = 0x19D8952B090; // Unknown = 
    inline constexpr uintptr_t FIntGetServerChannelRetries = 0x19BACE9BD50; // Unknown = 
    inline constexpr uintptr_t FIntHapticTriggerAttemptThrottleHundredthsPercent = 0x19B90261B10; // Unknown = 
    inline constexpr uintptr_t FIntHelpPageThrottleHundredthsPercent = 0x19BB3F277D8; // Unknown = 
    inline constexpr uintptr_t FIntHomePagePYMKPercentageOfViewPortToStartFetch = 0x19B90115290; // Unknown = 
    inline constexpr uintptr_t FIntHomePagePYMKPresenceFetchThrottleInterval = 0x19B90115750; // Unknown = 
    inline constexpr uintptr_t FIntHomepageReadyFailsafeTimeoutSeconds = 0x19B90648ED0; // Unknown = 
    inline constexpr uintptr_t FIntIAFlyoutDailyTooltipMaxShownCount = 0x19D7C7CC910; // Unknown = 
    inline constexpr uintptr_t FIntIAFlyoutTooltipMaxShownCount = 0x19D7C7CB990; // Unknown = 
    inline constexpr uintptr_t FIntIDVMaxRetries = 0x19B8FC3A090; // Unknown = 
    inline constexpr uintptr_t FIntIDVPollDelay = 0x19B8FC38B50; // Unknown = 
    inline constexpr uintptr_t FIntIGARRaycastTargetCount = 0x19BBB7F7050; // Unknown = 
    inline constexpr uintptr_t FIntIGARSubtreeDivergenceThresholdPerMille = 0x19BBB7F2990; // Unknown = 
    inline constexpr uintptr_t FIntIGMTempOverrideGfxLv5 = 0x19B9FD8CC50; // Unknown = 
    inline constexpr uintptr_t FIntIconSelectionTimeout = 0x19B9ACBFA10; // Unknown = 
    inline constexpr uintptr_t FIntImageLoadObserverPollIntervalMs = 0x19B94812AD0; // Unknown = 
    inline constexpr uintptr_t FIntInAppAchievementManagerHttpRetryCount = 0x19B9F9243D0; // Unknown = 
    inline constexpr uintptr_t FIntInAppBugReporterMaxTitleLength = 0x19B90293610; // Unknown = 
    inline constexpr uintptr_t FIntInAppBugReporterMinCommentLength = 0x19B90293E90; // Unknown = 
    inline constexpr uintptr_t FIntInExpAchievementManagerHttpRetryCount = 0x19B9F924A10; // Unknown = 
    inline constexpr uintptr_t FIntInExpAmpWizardDisplayOrder = 0x19B90113D90; // Unknown = 
    inline constexpr uintptr_t FIntInExperienceClickoutToggledTelemetryThrottleHundredthsPercent = 0x19B9F920F90; // Unknown = 
    inline constexpr uintptr_t FIntInExperienceDetailsPromptClosedHundredthsPercent = 0x19BA679E610; // Unknown = 
    inline constexpr uintptr_t FIntInExperienceDetailsPromptDisplayOrder = 0x19B9FD86050; // Unknown = 
    inline constexpr uintptr_t FIntInExperienceDetailsPromptLoadedHundredthsPercent = 0x19BA6797510; // Unknown = 
    inline constexpr uintptr_t FIntInExperienceDetailsPromptOpenedHundredthsPercent = 0x19BA679AED0; // Unknown = 
    inline constexpr uintptr_t FIntInExperienceDetailsPromptPlayClickedHundredthsPercent = 0x19BA51DB2A8; // Unknown = 
    inline constexpr uintptr_t FIntInExperienceInterventionDisplayOrder = 0x19BACE79490; // Unknown = 
    inline constexpr uintptr_t FIntInExperienceInterventionToastDuration = 0x19BACE780D0; // Unknown = 
    inline constexpr uintptr_t FIntInExperienceShopTelemetryThrottleHundredthsPercent = 0x19D80F60C08; // Unknown = 
    inline constexpr uintptr_t FIntInExperienceTransferMaxHttpRequestRetries = 0x19B9FD80710; // Unknown = 
    inline constexpr uintptr_t FIntInExperienceTransferMaxHttpRequestWaitTime = 0x19B9FD808D0; // Unknown = 
    inline constexpr uintptr_t FIntInGameBuildChatSheetSnapPoint = 0x19BB1C174F0; // Unknown = 
    inline constexpr uintptr_t FIntInGameRobuxUpsellEventThrottleHundredthsPercent = 0x19BAC8363D0; // Unknown = 
    inline constexpr uintptr_t FIntInitialFriendsPageSize = 0x19B8F90E610; // Unknown = 
    inline constexpr uintptr_t FIntInitialTrustedFriendRequestsPageSize = 0x19B8C2E1550; // Unknown = 
    inline constexpr uintptr_t FIntInitializeFmodMsDelay = 0x19D86F0D690; // Unknown = 
    inline constexpr uintptr_t FIntInspectAndBuyClusterCompositionTimeoutMs = 0x19B9F0A5210; // Unknown = 
    inline constexpr uintptr_t FIntInspectButtonThrottleHundredthsPercent = 0x19BBC38E350; // Unknown = 
    inline constexpr uintptr_t FIntIntervalPerformanceTrackerEventStream = 0x19BA6A34110; // Unknown = 
    inline constexpr uintptr_t FIntIntervalPerformanceTrackerEventThrottleHundrethsPercent = 0x19B9CB753D0; // Unknown = 
    inline constexpr uintptr_t FIntInviteLinkExpiredModalHttpRetryCount = 0x19B859CAE90; // Unknown = 
    inline constexpr uintptr_t FIntIosAuthServiceHealthCounterThrottlingHundredthsPercent = 0x19BBC1C5450; // Unknown = 
    inline constexpr uintptr_t FIntIosAuthServiceLoginThrottlingHundredthsPercent = 0x19BBC1CFB50; // Unknown = 
    inline constexpr uintptr_t FIntIsFriendsWithCacheTtlSec = 0x19B8F90E390; // Unknown = 
    inline constexpr uintptr_t FIntIxpFlyoutControl = 0x19BA461AD10; // Unknown = 
    inline constexpr uintptr_t FIntIxpFlyoutVariantAlternateEntry = 0x19BA4616810; // Unknown = 
    inline constexpr uintptr_t FIntIxpFlyoutVariantHamburger = 0x19BA4618210; // Unknown = 
    inline constexpr uintptr_t FIntIxpFlyoutVariantNoSubTabs = 0x19BA4617C10; // Unknown = 
    inline constexpr uintptr_t FIntIxpFlyoutVariantRemovalRobuxIcon = 0x19BA4615DD0; // Unknown = 
    inline constexpr uintptr_t FIntKeystoreTelemetryThrottlingHundredthsPercent = 0x19BBC1CC990; // Unknown = 
    inline constexpr uintptr_t FIntKeystoreTimeout = 0x19BBC1C2F90; // Unknown = 
    inline constexpr uintptr_t FIntLargeCollectionItemFractionalPercent = 0x19BA6791FD0; // Unknown = 
    inline constexpr uintptr_t FIntLargeCollectionItemMaxItemCount = 0x19BA6796290; // Unknown = 
    inline constexpr uintptr_t FIntLargeCollectionItemMinItemCount = 0x19BA6795A90; // Unknown = 
    inline constexpr uintptr_t FIntLargeCollectionItemMinItemWidth = 0x19BA679F210; // Unknown = 
    inline constexpr uintptr_t FIntLargeCollectionItemVerticalGap = 0x19BA67904D0; // Unknown = 
    inline constexpr uintptr_t FIntLegacyPurchaseFPSTrackingTimeout = 0x19B88C766F0; // Unknown = 
    inline constexpr uintptr_t FIntLinkingProtocolFetchRetries = 0x19B8578A6D0; // Unknown = 
    inline constexpr uintptr_t FIntLinkingProtocolFetchTimeoutMS = 0x19B8578A790; // Unknown = 
    inline constexpr uintptr_t FIntLivenessBackgroundOnlyPollDelay = 0x19BA607D7D0; // Unknown = 
    inline constexpr uintptr_t FIntLivenessBackgroundOnlyPollMaxRetries = 0x19BA607EB90; // Unknown = 
    inline constexpr uintptr_t FIntLivenessWithCallbackPollDelay = 0x19BA6070350; // Unknown = 
    inline constexpr uintptr_t FIntLivenessWithCallbackPollMaxRetries = 0x19BA6076090; // Unknown = 
    inline constexpr uintptr_t FIntLoadingScreenQueuedStateButtonClickThrottleHundredthsPercent = 0x19B9AF14710; // Unknown = 
    inline constexpr uintptr_t FIntLogTreeMaxLogsToBacktrace = 0x19B8F90B7D0; // Unknown = 
    inline constexpr uintptr_t FIntLoginByUsernameSSOErrorsThrottleHundrethsPercent = 0x19D8851A098; // Unknown = 
    inline constexpr uintptr_t FIntLookAvatarRotationDegree1 = 0x19D8952F250; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppAccountSecurityPromptForcePopUpRenderAfterSeconds = 0x19B9029F290; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppAccountSecurityPromptPollingIntervalSeconds = 0x19B859CE390; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppAccountSecurityPromptPollingIntervalSecondsVisible = 0x19B948100D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppAccountSecurityPromptPopUpSpawnDelay = 0x19B94810210; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppAccountSecurityPromptRollout = 0x19B8558AEA0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppAutocompleteSearchTextMaxLen = 0x19B9029EBD0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppBackToTopClickEventThrottlingHundredthsPercent = 0x19BA67919D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppBatchFetchingStatusDelayMs = 0x19B85789190; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppChallengeDeviceAccessEventThrottlingPercent = 0x19BA515B810; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppChallengeDialogEventReceiverRetryIntervalSeconds = 0x19B90641210; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppChallengeDialogEventReceiverRetryTimes = 0x19B90640ED0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppChallengeDialogPollingIntervalSeconds = 0x19B90642750; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppCredentialsProtocolAvailableTimeout = 0x19B8FC39AD0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppCredentialsProtocolTimeout = 0x19B8FC39890; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppDataHydrationDefaultBatchSize = 0x19BA5BD3F10; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppDataHydrationDefaultRequestTimeoutSec = 0x19BA5BDEA10; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppDataHydrationQueueProcessDelaySec = 0x19BA5BD9590; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppDefaultDataTtlSec = 0x19BA5BDD790; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppDefaultFailedDataTtlSec = 0x19BA5BD1F90; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppDelayImpressionsMaxUpdates = 0x19B88C2EDD0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppDiscoveryClientAppStorageCacheTtlDays = 0x19BA3A775D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppEdpMediaGalleryItemVisiblePercent = 0x19B88C2B2D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppEdpVideoAvailableRamThresholdMb = 0x19BBC388750; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppEdpVideoMaxMemoryThresholdMb = 0x19BBC3841D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppEnableReactProfilerHundredthsPercent = 0x19B85782710; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppFeedImpressionsHundredthsPercent = 0x19B8F9DEDD0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppFriendsSortHeaderMaxHiddenPosition = 0x19BB1D9A810; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameAttributionErrorEventThrottleHundrethsPercent = 0x19BA6795490; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameDetailReferralEventThrottlingHundredthsPercent = 0x19BA6728510; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameDetailReferralShadowThrottlingHundredthsPercent = 0x19BA51DB2C8; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameGridBufferRowsAboveScreen = 0x19BBE91B290; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameGridBufferRowsBelowScreen = 0x19BBE91AED0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameGridRevealMoreButtonGapPx = 0x19B88C2E8D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameIconLargeSizePx = 0x19BA5BDEF50; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameIconSmallSizePx = 0x19BA5BDF450; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameImpressionsEventThrottlingHundredthsPercent = 0x19BBE91B010; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameImpressionsShadowThrottlingHundredthsPercent = 0x19BBE91A590; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGamePlayIntentEventThrottlingHundredthsPercent = 0x19BA6724690; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGamePlayIntentShadowThrottlingHundredthsPercent = 0x19BA672F450; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameTileHoverDelayMs = 0x19BBE9115D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameTileVideoAvailableRamThresholdMb = 0x19BBE912D50; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameTileVideoDwellTimeInSec = 0x19B88C2C410; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameTileVideoMaxMemoryThresholdMb = 0x19BBE912710; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGameTileVideoVisiblePercent = 0x19B88C2C650; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppGamesListSortTokenExpiryInSec = 0x19B90266C50; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppHomeFeedFriendsPosition = 0x19B94811C90; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppHomeFeedProfilePosition = 0x19B94811B50; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppHomeFeedUpsellCardPosition = 0x19B94811E50; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppIECVRVariantNoSpatialUI = 0x19BA3BB3290; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppIECVRVariantSpatialUIMovePanelToCenter = 0x19BA3BB7850; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppIECVRVariantSpatialUIWithDragging = 0x19B9F18B860; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppIECVRVariantSpatialUIWithoutDragging = 0x19B9F18BBE0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppInvalidPlayIntentThrottlingHundredthsPercent = 0x19BA6729550; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppItemActionEventThrottlingHundredthsPercent = 0x19B8F9DFDD0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppItemActionShadowThrottlingHundredthsPercent = 0x19D86D61CA8; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppItemImpressionsEventThrottlingHundredthsPercent = 0x19B8F9DF550; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppItemImpressionsShadowThrottlingHundredthsPercent = 0x19B8F9DF290; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppJoinGameFailureInfluxHundredthsPercentage = 0x19BA6797DD0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppLaunchTrackerTimeoutSec = 0x19B8C317090; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppLoginRollout = 0x19B9026AD90; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppLoginRolloutIos = 0x19B9026AA10; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppLumberyakLogBound = 0x19B8F90B2D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppNxMApportioningDiagnosticThrottleHundredthsPercent = 0x19BA5BD3B10; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppOmniFeedInitialNumRows = 0x19B94810150; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppOmniFeedLoadNumRows = 0x19B948110D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppOmniFeedScrollAnimDurationMs = 0x19B94811210; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppOneByTwoTileGradientBottomHeightPercent = 0x19BBE91E910; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppOneByTwoTileGradientBottomTransparencyPercent = 0x19BBE91E250; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppOneByTwoTileGradientTopTransparencyPercent = 0x19BBE91F9D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppOneByTwoTileLogoWidthPercentLandscape = 0x19BBE91E290; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppOneByTwoTileLogoWidthPercentSquare = 0x19BBE91F710; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppPlayButtonLoadingDurationTelemetryThrottleHundredthsPercent = 0x19BA67210D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppPlayButtonSecondaryButtonGap = 0x19B88C2E290; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppPlayButtonThrottleTimeSeconds = 0x19B88C2E710; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppPlayButtonWizardCloseDelayMs = 0x19B88C2E950; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppPlayWithRewardMobileEdpLayoutOrder = 0x19B90640390; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppRecommendedGamesCount = 0x19BA5BD3510; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSchedulerDeferredWork = 0x19B9ACB2D90; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSchedulerDesiredFrameRate = 0x19B9ACBB650; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSchedulerHeartbeatFrameMarker = 0x19B9ACBB510; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSchedulerLookbackUseRingBuffer = 0x19B9ACBD110; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSchedulerMinimumFrameRate = 0x19B9ACBB590; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSchedulerNumberOfLookbackFrames = 0x19B9ACBA590; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSchedulerTargetMsByHeartbeatDelta = 0x19B9ACBBC90; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSchedulerYieldInterval = 0x19B9ACB2010; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSduiCarouselPlaceholderHeaderHeightPx = 0x19B88C283D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSduiCarouselPlaceholderHeaderMaxWidthPct = 0x19B9029B8D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSduiCarouselPlaceholderHeaderMinWidthPct = 0x19B9029BC90; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSearchAutocompleteDebounceMs = 0x19B9986B0E8; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSessionWithErrorThrottlePercentage = 0x19B8F9092D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppShowMoreClickEventThrottlingHundredthsPercent = 0x19BA67989D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSmallScreenDesignWidth = 0x19B859C6950; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSponsoredAdLoadTelemetryThrottlingHundredthsPercent = 0x19BBE91D5D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSponsoredAdUnloadTelemetryThrottlingHundredthsPercent = 0x19BBE91D490; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSponsoredAdViewableImpressionTelemetryThrottlingHundredthsPercent = 0x19BBE91FA10; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppStartupReactSchedulerDelayMs = 0x19B8F908C50; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppStartupReactSchedulerInterval = 0x19B8F908E90; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppSubTabTopPadding = 0x19B9ACB4A10; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppThrottleInviteSendEndpointDelay = 0x19B9F296D90; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppThrottleRefreshPlayabilityIntervalSeconds = 0x19BC0547410; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppTransparentPageMaxCount = 0x19B90643410; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppTwoByOneTileGradientEndOpacityPercent = 0x19BBE91E490; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppTwoByOneTileGradientStartOpacityPercent = 0x19BBE91FE90; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppTwoByOneTileGradientWidthPercent = 0x19BBE91A710; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppTwoByOneTileLogoHeightPercentLandscape = 0x19BBE91D510; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppTwoByOneTileLogoHeightPercentSquare = 0x19BBE91DF10; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppTwoByOneTileSmallScreenBreakpoint = 0x19BBE91C5D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppUpdateImpressionsViewportBoundsPositionThreshold = 0x19B88C23A10; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppVideoAutoplayMaxDistanceToWinnerLinePercent = 0x19BBC38AC50; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppVideoAutoplayWinnerLineOffsetFromTopBarPx = 0x19BBC389D10; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppViewportBoundsScreenSizeThreshold = 0x19B88C24050; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppVngUpsellNagFrequencySec = 0x19B94812210; // Unknown = 
    inline constexpr uintptr_t FIntLuaAppsAppsflyerIdCounterThrottle = 0x19B90291510; // Unknown = 
    inline constexpr uintptr_t FIntLuaCoreScriptsErrorV2ThrottleHundredthPercentage = 0x19BA555C990; // Unknown = 
    inline constexpr uintptr_t FIntLuaErrorV2ThrottleHundredthPercentage = 0x19B8F908B90; // Unknown = 
    inline constexpr uintptr_t FIntLuaFetchUpdatedUserAgreementsErrorsThrottling = 0x19B859C9450; // Unknown = 
    inline constexpr uintptr_t FIntLuaHttpClientPayloadSizeEventHundredthsPercent = 0x19BA5BDA510; // Unknown = 
    inline constexpr uintptr_t FIntLuaHttpClientRequestStatusEventHundredthsPercent = 0x19BA5BD6E10; // Unknown = 
    inline constexpr uintptr_t FIntLuaHttpClientRequestTimerEventHundredthsPercent = 0x19BA5BDB290; // Unknown = 
    inline constexpr uintptr_t FIntLuaInExpSchedulerDeferredWork = 0x19B9ACB2ED0; // Unknown = 
    inline constexpr uintptr_t FIntLuaInExpSchedulerDesiredFrameRate = 0x19B9ACBA090; // Unknown = 
    inline constexpr uintptr_t FIntLuaInExpSchedulerHeartbeatFrameMarker = 0x19B9ACBEC50; // Unknown = 
    inline constexpr uintptr_t FIntLuaInExpSchedulerLookbackUseRingBuffer = 0x19B9ACBD810; // Unknown = 
    inline constexpr uintptr_t FIntLuaInExpSchedulerMinimumFrameRate = 0x19B9ACB0E90; // Unknown = 
    inline constexpr uintptr_t FIntLuaInExpSchedulerNumberOfLookbackFrames = 0x19B9ACBD190; // Unknown = 
    inline constexpr uintptr_t FIntLuaInExpSchedulerTargetMsByHeartbeatDelta = 0x19B9ACB78D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaInExpSchedulerYieldInterval = 0x19B9ACBBBD0; // Unknown = 
    inline constexpr uintptr_t FIntLuaJoinYourFriendsRefreshInterval = 0x19B94810190; // Unknown = 
    inline constexpr uintptr_t FIntLuaLogoutReasonsThrottleHundrethsPercent = 0x19B8FA1F1D0; // Unknown = 
    inline constexpr uintptr_t FIntLuaLogoutThrottlingHundredthsPercent = 0x19BBC1C3C10; // Unknown = 
    inline constexpr uintptr_t FIntLuaMaxCatalogTopics = 0x19B9026DC10; // Unknown = 
    inline constexpr uintptr_t FIntLuaMaxItemsInTopicsRequest = 0x19B9026DC90; // Unknown = 
    inline constexpr uintptr_t FIntLuaPushUpsellEventThrottleHundrethsPercent = 0x19B8FA1FD10; // Unknown = 
    inline constexpr uintptr_t FIntLuaUIOcclusionMetricsReportingPeriodSeconds = 0x19B9ACB0A50; // Unknown = 
    inline constexpr uintptr_t FIntLuaVoiceChatAnalyticsPointsThrottle = 0x19BBC9D5D10; // Unknown = 
    inline constexpr uintptr_t FIntLuaVoiceChatThrottleHundrethsPercent = 0x19B8FDE8F50; // Unknown = 
    inline constexpr uintptr_t FIntLuaVoiceVolumeControlsEligibilityThrottleHundredthsPercent = 0x19B8FDE8990; // Unknown = 
    inline constexpr uintptr_t FIntLuaVoiceVolumeControlsImpressionsThrottleHundredthsPercent = 0x19B8FDE89D0; // Unknown = 
    inline constexpr uintptr_t FIntMaquetesAppPanelDistanceMultiplierPercentage = 0x19B8C306950; // Unknown = 
    inline constexpr uintptr_t FIntMaxDaysToShowCountDownLabel = 0x19BA6092510; // Unknown = 
    inline constexpr uintptr_t FIntMaxIGMBackgroundTransparencyPercent = 0x19BA4E9A190; // Unknown = 
    inline constexpr uintptr_t FIntMaxKickMessageLength = 0x19BA672C390; // Unknown = 
    inline constexpr uintptr_t FIntMaxNumUniversesExposedToCardTooltip = 0x19BB7F4A990; // Unknown = 
    inline constexpr uintptr_t FIntMaxReferredPlayerJoinToasts = 0x19B945A1690; // Unknown = 
    inline constexpr uintptr_t FIntMaxTraversalHistoryCardsPerRow709 = 0x19BBE91B8D0; // Unknown = 
    inline constexpr uintptr_t FIntMaxVideoCaptureDurationSeconds = 0x19D86F0C450; // Unknown = 
    inline constexpr uintptr_t FIntMaximumTraversalHistoryItemsFetch = 0x19BBC388D10; // Unknown = 
    inline constexpr uintptr_t FIntMediumCollectionItemFractionalPercent = 0x19BA6796D90; // Unknown = 
    inline constexpr uintptr_t FIntMediumCollectionItemMaxItemCount = 0x19BA6790F50; // Unknown = 
    inline constexpr uintptr_t FIntMediumCollectionItemMinItemCount = 0x19BA6793550; // Unknown = 
    inline constexpr uintptr_t FIntMediumCollectionItemMinItemWidth = 0x19BB190E500; // Unknown = 
    inline constexpr uintptr_t FIntMediumCollectionItemVerticalGap = 0x19BA67924D0; // Unknown = 
    inline constexpr uintptr_t FIntMenuButtonsThrottleHundredthsPercent = 0x19BACFE7850; // Unknown = 
    inline constexpr uintptr_t FIntMinDaysToShowCountDownLabel = 0x19BA609F890; // Unknown = 
    inline constexpr uintptr_t FIntMinDaysToShowCountdownLabel = 0x19BA6095250; // Unknown = 
    inline constexpr uintptr_t FIntMobileBreakpointInspectAndBuy = 0x19B859CB3D0; // Unknown = 
    inline constexpr uintptr_t FIntMobileGameJoinCardBannerLoadCounterThrottleHundredthsPercent = 0x19B8FA1D250; // Unknown = 
    inline constexpr uintptr_t FIntModalChallengeDialogApprovalHttpRetryCount = 0x19B906422D0; // Unknown = 
    inline constexpr uintptr_t FIntModalChallengeDialogExpiredHttpRetryCount = 0x19B90642510; // Unknown = 
    inline constexpr uintptr_t FIntModalImpressionThrottleHundrethsPercent = 0x19B90293850; // Unknown = 
    inline constexpr uintptr_t FIntMomentDraftTTLDays = 0x19D86F010D0; // Unknown = 
    inline constexpr uintptr_t FIntMomentsPreloadDecodeRetryDelayMs = 0x19D86F02A50; // Unknown = 
    inline constexpr uintptr_t FIntMomentsPreloadDecodeWindowBack = 0x19D86F06010; // Unknown = 
    inline constexpr uintptr_t FIntMomentsPreloadDecodeWindowForward = 0x19D86F08290; // Unknown = 
    inline constexpr uintptr_t FIntMomentsPreloadDownloadWindowBack = 0x19D86F08790; // Unknown = 
    inline constexpr uintptr_t FIntMomentsPreloadDownloadWindowForward = 0x19D86F0E650; // Unknown = 
    inline constexpr uintptr_t FIntMomentsPreloadMaxDecodeRetries = 0x19D86F0E910; // Unknown = 
    inline constexpr uintptr_t FIntMomentsScreenshotDurationSeconds = 0x19D86F03A50; // Unknown = 
    inline constexpr uintptr_t FIntMomentsSurfaceLoadTTIMaxMs = 0x19B85786D10; // Unknown = 
    inline constexpr uintptr_t FIntMomentsSurfaceLoadTTISamplingRate = 0x19B85786B90; // Unknown = 
    inline constexpr uintptr_t FIntMomentsTTSDefaultVoiceId = 0x19D86F09C10; // Unknown = 
    inline constexpr uintptr_t FIntMomentsTTSMaxCharacters = 0x19D86F0D550; // Unknown = 
    inline constexpr uintptr_t FIntMomentsTTSWaveformMaxBarHeightPercent = 0x19D86F033D0; // Unknown = 
    inline constexpr uintptr_t FIntMomentsTTSWaveformMaxSamples = 0x19D86F02890; // Unknown = 
    inline constexpr uintptr_t FIntMomentsTTSWaveformMinBarHeightPercent = 0x19BAE770BB8; // Unknown = 
    inline constexpr uintptr_t FIntMomentsTTSWaveformMinSamples = 0x19D86F032D0; // Unknown = 
    inline constexpr uintptr_t FIntMomentsTTSWaveformSamplesPerSecond = 0x19D86F03D90; // Unknown = 
    inline constexpr uintptr_t FIntMuteAllThrottleHundredthsPercent = 0x19BBC38AD90; // Unknown = 
    inline constexpr uintptr_t FIntMutePlayerThrottleHundredthsPercent = 0x19BBC38DF10; // Unknown = 
    inline constexpr uintptr_t FIntMuteSelfThrottleHundredthsPercent = 0x19BBC38FBD0; // Unknown = 
    inline constexpr uintptr_t FIntMuteSelfThrottleHundredthsPercent4 = 0x19B9CCE21D0; // Unknown = 
    inline constexpr uintptr_t FIntMyCreationsSessionListPollingIntervalSeconds = 0x19BAD58D910; // Unknown = 
    inline constexpr uintptr_t FIntMyStatsExperienceAskForLogsMaxEntries = 0x19BAD588050; // Unknown = 
    inline constexpr uintptr_t FIntMyStatsExperienceSearchDebounceMs = 0x19BAD58D650; // Unknown = 
    inline constexpr uintptr_t FIntNewBadgeMaximumImpressionCount = 0x19B8FC333D0; // Unknown = 
    inline constexpr uintptr_t FIntNewInGameMenuPercentRollout3 = 0x19BA3666ED0; // Unknown = 
    inline constexpr uintptr_t FIntNotInterestedFeedbackFormActionThrottleHundredthsPercent = 0x19BBE914A10; // Unknown = 
    inline constexpr uintptr_t FIntNotificationsUpsellModalHttpRetryCount = 0x19B8FA1F710; // Unknown = 
    inline constexpr uintptr_t FIntOffPlatformFriendRequestsRolloutEnabled = 0x19BAFCF3DD0; // Unknown = 
    inline constexpr uintptr_t FIntOldestUAVersionToReportErrors = 0x19B9F188470; // Unknown = 
    inline constexpr uintptr_t FIntOmniFeedDividerHeightOverride = 0x19BA5205308; // Unknown = 
    inline constexpr uintptr_t FIntOmniFeedDividerPaddingOverride = 0x19BC054B5D0; // Unknown = 
    inline constexpr uintptr_t FIntOmniRecommendationsMetadataEventThrottlingHundredthsPercent = 0x19B902670D0; // Unknown = 
    inline constexpr uintptr_t FIntOnlineFriendsCacheTtlSec = 0x19B8F90E310; // Unknown = 
    inline constexpr uintptr_t FIntOpenLeavingRobloxModalThrottleHundrethsPercent = 0x19BA67938D0; // Unknown = 
    inline constexpr uintptr_t FIntOpenReactPageThrottleHundredthsPercent = 0x19BACFE7E90; // Unknown = 
    inline constexpr uintptr_t FIntOpenSearchResultsWithQueryDeeplinkEventThrottlingHundredthsPercent = 0x19BA6793C50; // Unknown = 
    inline constexpr uintptr_t FIntPYMKCarouselHttpRetryCount = 0x19B8FC3AA10; // Unknown = 
    inline constexpr uintptr_t FIntPYMKSeeAllTileLimit = 0x19B90115190; // Unknown = 
    inline constexpr uintptr_t FIntParentalControlsScreentimeLockoutPollIntervalMs = 0x19B90290DD0; // Unknown = 
    inline constexpr uintptr_t FIntPartyVoiceAudioFaderVolumePerc = 0x19B8ED7FC50; // Unknown = 
    inline constexpr uintptr_t FIntPartyVoiceJoinRequestPulseCheckTimeout = 0x19B8C2E3550; // Unknown = 
    inline constexpr uintptr_t FIntPartyVoiceRestrictionStatusMaxAttempts = 0x19BA8026C50; // Unknown = 
    inline constexpr uintptr_t FIntPartyVoiceTelemetryThrottlingThousandths = 0x19B9F1866D0; // Unknown = 
    inline constexpr uintptr_t FIntPartyVoiceTopbarActivityIndicatorAnimationMs = 0x19D80F6FED8; // Unknown = 
    inline constexpr uintptr_t FIntPartyVoiceUndeafenDelayMS = 0x19B88C4B710; // Unknown = 
    inline constexpr uintptr_t FIntPasskeyUpsellDisableButtonTimer = 0x19B90291C10; // Unknown = 
    inline constexpr uintptr_t FIntPeekViewTransitionDelayTiming = 0x19B88C4BDD0; // Unknown = 
    inline constexpr uintptr_t FIntPeoplePageLayoutChangedThrottleHundredthsPercent = 0x19B82C1A990; // Unknown = 
    inline constexpr uintptr_t FIntPeoplePageLazyRenderThreshold = 0x19BB7F4B1D0; // Unknown = 
    inline constexpr uintptr_t FIntPeoplePageVirtualizedGridBuffer = 0x19BB7F4D210; // Unknown = 
    inline constexpr uintptr_t FIntPeopleServiceGameInviteEntryPointThrottleHundredthsPercent4 = 0x19BBC387150; // Unknown = 
    inline constexpr uintptr_t FIntPeopleServiceInspectButtonThrottleHundredthsPercent4 = 0x19BBC38C3D0; // Unknown = 
    inline constexpr uintptr_t FIntPeopleServiceMuteAllThrottleHundredthsPercent4 = 0x19BBC3853D0; // Unknown = 
    inline constexpr uintptr_t FIntPeopleServiceMutePlayerThrottleHundredthsPercent4 = 0x19BBC385F90; // Unknown = 
    inline constexpr uintptr_t FIntPeopleServicePerUserVoiceVolumeChangedThrottleHundredthsPercent = 0x19BBC384510; // Unknown = 
    inline constexpr uintptr_t FIntPeopleServicePerUserVoiceVolumeMutedViaSliderThrottleHundredthsPercent = 0x19BBC3859D0; // Unknown = 
    inline constexpr uintptr_t FIntPeopleServicePerUserVoiceVolumeSessionThrottleHundredthsPercent = 0x19BBC38E9D0; // Unknown = 
    inline constexpr uintptr_t FIntPeopleServicePerUserVoiceVolumeSliderTouchThrottleHundredthsPercent = 0x19BBC383B50; // Unknown = 
    inline constexpr uintptr_t FIntPeopleServicePerUserVoiceVolumeUnmutedViaSliderThrottleHundredthsPercent = 0x19BBC385E50; // Unknown = 
    inline constexpr uintptr_t FIntPeopleServiceRequestFriendshipThrottleHundredthsPercent4 = 0x19BBC38C550; // Unknown = 
    inline constexpr uintptr_t FIntPeopleServiceUnmuteAllThrottleHundredthsPercent4 = 0x19BBC388C90; // Unknown = 
    inline constexpr uintptr_t FIntPeopleServiceUnmutePlayerThrottleHundredthsPercent4 = 0x19BBC38E390; // Unknown = 
    inline constexpr uintptr_t FIntPerUserVoiceVolumeChangedThrottleHundredthsPercent = 0x19BBC385CD0; // Unknown = 
    inline constexpr uintptr_t FIntPerUserVoiceVolumeMutedViaSliderThrottleHundredthsPercent = 0x19BBC3846D0; // Unknown = 
    inline constexpr uintptr_t FIntPerUserVoiceVolumeSessionThrottleHundredthsPercent = 0x19BBC389E10; // Unknown = 
    inline constexpr uintptr_t FIntPerUserVoiceVolumeSliderTouchThrottleHundredthsPercent = 0x19BBC386A10; // Unknown = 
    inline constexpr uintptr_t FIntPerUserVoiceVolumeUnmutedViaSliderThrottleHundredthsPercent = 0x19BBC380FD0; // Unknown = 
    inline constexpr uintptr_t FIntPerfInsightsHbMax = 0x19B90290D90; // Unknown = 
    inline constexpr uintptr_t FIntPerfInsightsHbMin = 0x19B90290890; // Unknown = 
    inline constexpr uintptr_t FIntPerfInsightsInMax = 0x19B902910D0; // Unknown = 
    inline constexpr uintptr_t FIntPerfInsightsInMin = 0x19B90290AD0; // Unknown = 
    inline constexpr uintptr_t FIntPersonCardMenuToggledThrottleHundredthsPercent = 0x19B82C1A9D0; // Unknown = 
    inline constexpr uintptr_t FIntPersonaLivenessV2QrPollDelaySec = 0x19BA607CA50; // Unknown = 
    inline constexpr uintptr_t FIntPersonaLivenessV2QrPollMaxRetries = 0x19BA6078350; // Unknown = 
    inline constexpr uintptr_t FIntPlaceIdContainerHttpRetryCount = 0x19BA802EFD0; // Unknown = 
    inline constexpr uintptr_t FIntPlatformEvidenceRolloutPercent = 0x19BA520EA10; // Unknown = 
    inline constexpr uintptr_t FIntPlatformLeaderboardPushWaitTimeoutSeconds = 0x19BACE96A50; // Unknown = 
    inline constexpr uintptr_t FIntPlayButtonContextualMessageImpressionHundredthsPercent = 0x19BA6791E90; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardAdPlaybackAttemptedTelemetryThrottleHundredthsPercent = 0x19B859C9A50; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardAdPlaybackStoppedTelemetryThrottleHundredthsPercent = 0x19B859C9D90; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardAdReceivedTelemetryThrottleHundredthsPercent = 0x19B859C9590; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardAdRequestedTelemetryThrottleHundredthsPercent = 0x19B859CA810; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardBannerShownTelemetryThrottleHundredthsPercent = 0x19B859CA3D0; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardBlackoutCurtainTelemetryThrottleHundredthsPercent = 0x19B859C9F10; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardButtonClickedTelemetryThrottleHundredthsPercent = 0x19B859C9990; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardCoachmarkMaxImpressions = 0x19B90640D50; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardCoachmarkMaxImpressions2 = 0x19B90640F90; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardCoachmarkTelemetryThrottleHundredthsPercent = 0x19B9011FE90; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardCoachmarkWindowDays = 0x19B90640A50; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardFallbackBannerProductImageAssetId = 0x19B906403D0; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardGameJoinInitiatedTelemetryThrottleHundredthsPercent = 0x19B859C9950; // Unknown = 
    inline constexpr uintptr_t FIntPlayWithRewardShimmerShownTelemetryThrottleHundredthsPercent = 0x19B859CA890; // Unknown = 
    inline constexpr uintptr_t FIntPlaytestModeEnabledEventThrottleHundredthsPercent = 0x19D80F669A8; // Unknown = 
    inline constexpr uintptr_t FIntPotentialClientTimeoutSeconds = 0x19BA672C2D0; // Unknown = 
    inline constexpr uintptr_t FIntPresenceEventReceiverErrorEventThrottleHundrethsPercent = 0x19B902909D0; // Unknown = 
    inline constexpr uintptr_t FIntPresenceHttpRetryCount = 0x19BA5BDEBD0; // Unknown = 
    inline constexpr uintptr_t FIntPresenceImpressionLoggingThrottlePerMyriad = 0x19BA6795F10; // Unknown = 
    inline constexpr uintptr_t FIntPresenceStorePollingTtlSec = 0x19BA5BD5510; // Unknown = 
    inline constexpr uintptr_t FIntPresenceStoreProcessDelaySec = 0x19BA5BD8E90; // Unknown = 
    inline constexpr uintptr_t FIntPresetChatCooldownLuaMs = 0x19B8FA13690; // Unknown = 
    inline constexpr uintptr_t FIntProductPurchaseContainerFPSDuration = 0x19D85DC7E90; // Unknown = 
    inline constexpr uintptr_t FIntProfileCTAHttpRetryCount = 0x19BA5BD0910; // Unknown = 
    inline constexpr uintptr_t FIntProfileCTAStoreProcessDelaySec = 0x19BA5BDB5D0; // Unknown = 
    inline constexpr uintptr_t FIntProfileInsightsStoreHttpTimeout = 0x19B9011E750; // Unknown = 
    inline constexpr uintptr_t FIntProfilePlatformAnalyticsThrottlingThousandths = 0x19B90294350; // Unknown = 
    inline constexpr uintptr_t FIntProfilePlatformHttpRetryCount = 0x19BAC87C5D0; // Unknown = 
    inline constexpr uintptr_t FIntProfilePlatformInspectAvatarTooltipMaxImpressions = 0x19D80F5B428; // Unknown = 
    inline constexpr uintptr_t FIntProfileQRCodeHttpRetryCount = 0x19BAFCFBF10; // Unknown = 
    inline constexpr uintptr_t FIntProfileShareLinksAnalyticsThrottlingThousandths = 0x19BAFCF5690; // Unknown = 
    inline constexpr uintptr_t FIntProfileShareLinksHttpRetryCount = 0x19BAFCFE8D0; // Unknown = 
    inline constexpr uintptr_t FIntProgressLoadingBarMargin = 0x19B86E11C50; // Unknown = 
    inline constexpr uintptr_t FIntProgressLoadingBarMaxWidth = 0x19B86E11BD0; // Unknown = 
    inline constexpr uintptr_t FIntProgressLoadingDisplayOrder = 0x19B86E11CD0; // Unknown = 
    inline constexpr uintptr_t FIntProgressLoadingTelemetryThrottleHundredthsPercent = 0x19B86E11D50; // Unknown = 
    inline constexpr uintptr_t FIntPromptFriendRequestModalInputDelayMs = 0x19BA6077F10; // Unknown = 
    inline constexpr uintptr_t FIntPurchaseVolumePercentage = 0x19B8C345B50; // Unknown = 
    inline constexpr uintptr_t FIntPushUpsellChatCooldownPeriod = 0x19B8FA1FC90; // Unknown = 
    inline constexpr uintptr_t FIntPushUpsellChatMaxPromptCount = 0x19B8FA1FAD0; // Unknown = 
    inline constexpr uintptr_t FIntPushUpsellCooldownPeriod = 0x19B8FA1FF10; // Unknown = 
    inline constexpr uintptr_t FIntPushUpsellMaxPromptCount = 0x19B8FA1FF90; // Unknown = 
    inline constexpr uintptr_t FIntQuerySuggestionClickedEventThrottlingHundredthsPercent = 0x19BA6793410; // Unknown = 
    inline constexpr uintptr_t FIntRAMaxAnnotationCount = 0x19D81689110; // Unknown = 
    inline constexpr uintptr_t FIntRAMinEngineVersion = 0x19BA672D7D0; // Unknown = 
    inline constexpr uintptr_t FIntRTEPresenceStorePollingTtlSec = 0x19BA5BD4F10; // Unknown = 
    inline constexpr uintptr_t FIntRapidGameplayPauseIntervalMs = 0x19B9F0A71D0; // Unknown = 
    inline constexpr uintptr_t FIntRapidGameplayPauseMinNotificationDurationMs = 0x19B9F0A7310; // Unknown = 
    inline constexpr uintptr_t FIntReactDeletedTreeCleanUpLevel = 0x19BA5538150; // Unknown = 
    inline constexpr uintptr_t FIntReactHighEndMemoryCutoff = 0x19BBC7A2310; // Unknown = 
    inline constexpr uintptr_t FIntReactLowEndMemoryCutoff = 0x19BBC7A5AD0; // Unknown = 
    inline constexpr uintptr_t FIntReactMicroprofilerLevel5 = 0x19BA553C510; // Unknown = 
    inline constexpr uintptr_t FIntReactPerfTrackerKibana = 0x19B9FD84790; // Unknown = 
    inline constexpr uintptr_t FIntReactPeriodSummaryEventThrottleHunderedthsPercent = 0x19BBC7A6FD0; // Unknown = 
    inline constexpr uintptr_t FIntReactRootSummaryEventThrottleHunderedthsPercent2 = 0x19BBC7A5690; // Unknown = 
    inline constexpr uintptr_t FIntReactSchedulerDesiredFrameRate = 0x19BA5537F90; // Unknown = 
    inline constexpr uintptr_t FIntReactSchedulerMinFrameRate = 0x19BA553A210; // Unknown = 
    inline constexpr uintptr_t FIntReactSchedulerNumberOfLookbackFrames = 0x19BA5533F10; // Unknown = 
    inline constexpr uintptr_t FIntReactSchedulerYieldInterval2 = 0x19BA553A610; // Unknown = 
    inline constexpr uintptr_t FIntReactSchedulingKllSketchMaxSize = 0x19BA366B2D0; // Unknown = 
    inline constexpr uintptr_t FIntReactSchedulingTracker = 0x19BA366F610; // Unknown = 
    inline constexpr uintptr_t FIntReactSchedulingTrackerPeriodMs = 0x19BA366FC90; // Unknown = 
    inline constexpr uintptr_t FIntReactSchedulingTrackerStartUpDelayMs = 0x19B9FD85F90; // Unknown = 
    inline constexpr uintptr_t FIntReactSessionSummaryEventThrottleHunderedthsPercent = 0x19BBC7A0AD0; // Unknown = 
    inline constexpr uintptr_t FIntReferredPlayerJoinRemoteEventTimeout = 0x19B945A7F90; // Unknown = 
    inline constexpr uintptr_t FIntRelocateMobileMenuButtonsVariant = 0x19B9FDDB088; // Unknown = 
    inline constexpr uintptr_t FIntRenderCancelSubscriptionAppHttpRetryCount = 0x19B9FD82A50; // Unknown = 
    inline constexpr uintptr_t FIntReportAnythingAvatarIdentificationCloseDiscardDistanceHundredths = 0x19BAC87F3D0; // Unknown = 
    inline constexpr uintptr_t FIntReportAnythingAvatarIdentificationDiscardFractionSkipThresholdPercent = 0x19BAC87F510; // Unknown = 
    inline constexpr uintptr_t FIntReportAnythingAvatarIdentificationOffScreenDiscardDistancePercent = 0x19BAC87F650; // Unknown = 
    inline constexpr uintptr_t FIntReportDevConsoleTabEventsThrottleHundredthsPercent = 0x19BACFE6A50; // Unknown = 
    inline constexpr uintptr_t FIntReportImmersiveBrandedAdHttpFaulreEventThrottleHundredthsPercent = 0x19BA8A0A550; // Unknown = 
    inline constexpr uintptr_t FIntRequestFriendshipThrottleHundredthsPercent = 0x19BBC385510; // Unknown = 
    inline constexpr uintptr_t FIntRequestRefundClickThrottleHundredthsPercent = 0x19BA679C490; // Unknown = 
    inline constexpr uintptr_t FIntRobloxSubscriptionPurchasePollingTimeoutSeconds = 0x19B8FC33BD0; // Unknown = 
    inline constexpr uintptr_t FIntRobloxSubscriptionUpsellTelemetryEventIngestThrottleHundredthsPercent = 0x19B8FC33790; // Unknown = 
    inline constexpr uintptr_t FIntRobuxTransferFlowEventIngestThrottleHundredthsPercent = 0x19B9F92C810; // Unknown = 
    inline constexpr uintptr_t FIntRomarkStartWithGraphicQualityLevel = 0x19B9FD8CD50; // Unknown = 
    inline constexpr uintptr_t FIntSafetyBubbleRadius = 0x19BBE911590; // Unknown = 
    inline constexpr uintptr_t FIntSafetyBubbleTransparencyPercent = 0x19BBE9136D0; // Unknown = 
    inline constexpr uintptr_t FIntScaleBrazilContentRatingBadge = 0x19B9ACB5ED0; // Unknown = 
    inline constexpr uintptr_t FIntScheduledSquadJustStartedThreshold = 0x19BACE78B50; // Unknown = 
    inline constexpr uintptr_t FIntScriptProfilerLiveUpdateIntervalMS = 0x19BACFE4FD0; // Unknown = 
    inline constexpr uintptr_t FIntScrollDetectorDelayMillis = 0x19BBE916590; // Unknown = 
    inline constexpr uintptr_t FIntScrollDetectorTimeThresholdMillis = 0x19BBE915DD0; // Unknown = 
    inline constexpr uintptr_t FIntScrollingPerfTrackerEventStream = 0x19B948113D0; // Unknown = 
    inline constexpr uintptr_t FIntScrollingPerfTrackerKibana = 0x19B948114D0; // Unknown = 
    inline constexpr uintptr_t FIntScrollingPerfTrackerSampleCountThreshold = 0x19B94811610; // Unknown = 
    inline constexpr uintptr_t FIntScrollingPerfTrackerTargetFPS = 0x19B948117D0; // Unknown = 
    inline constexpr uintptr_t FIntScrollingPickerMaximumPickerChangePerInput = 0x19BBC1C4ED0; // Unknown = 
    inline constexpr uintptr_t FIntScrollingPickerSlowScrollStepWaitMs = 0x19BBC1CF950; // Unknown = 
    inline constexpr uintptr_t FIntScrollingPickerSmallInputDecayFactor = 0x19BBC1C0C90; // Unknown = 
    inline constexpr uintptr_t FIntSduiCreateSduiFeedStoreLogDelayMs = 0x19B9011F210; // Unknown = 
    inline constexpr uintptr_t FIntSduiLoadMoreFromApiEventHundredthsPercent = 0x19B8F9DFED0; // Unknown = 
    inline constexpr uintptr_t FIntSduiOmniFeedItemLogDelayMs = 0x19B9011FC50; // Unknown = 
    inline constexpr uintptr_t FIntSduiPageRequestPriority = 0x19B8FC32290; // Unknown = 
    inline constexpr uintptr_t FIntSduiPageTimerEventHundredthsPercent = 0x19B8F9DFC90; // Unknown = 
    inline constexpr uintptr_t FIntSeamlessVoiceSTUXDisplayCount = 0x19BA5159B90; // Unknown = 
    inline constexpr uintptr_t FIntSearchLandingPageSideMargin = 0x19B90269A50; // Unknown = 
    inline constexpr uintptr_t FIntSelfieQrTimeoutSeconds = 0x19BA6076B90; // Unknown = 
    inline constexpr uintptr_t FIntSendGameLinkMessageHttpRetryCount = 0x19BACE71BD0; // Unknown = 
    inline constexpr uintptr_t FIntServeEnhancedVideoErrorTelemetryThrottleHundredthsPercent = 0x19B9F920710; // Unknown = 
    inline constexpr uintptr_t FIntServerTriggeredModalTrafficPercent = 0x19B90294150; // Unknown = 
    inline constexpr uintptr_t FIntSessionCheckDefaultTimeoutInSeconds = 0x19B90292310; // Unknown = 
    inline constexpr uintptr_t FIntSetAliasAnalyticsThrottlingThousandths = 0x19B90118190; // Unknown = 
    inline constexpr uintptr_t FIntSetAliasHttpRetryCount = 0x19B901185D0; // Unknown = 
    inline constexpr uintptr_t FIntSetupNotificationsUpsellHttpRetryCount = 0x19B8FA1F950; // Unknown = 
    inline constexpr uintptr_t FIntShareGameHttpRetryCount = 0x19BA6077850; // Unknown = 
    inline constexpr uintptr_t FIntShareSheetMaxConversations = 0x19D7C7C5950; // Unknown = 
    inline constexpr uintptr_t FIntShareSheetNumAvatarSkeletons = 0x19D7C7C3D10; // Unknown = 
    inline constexpr uintptr_t FIntShareSheetSnackbarAutoDismissSeconds = 0x19D7C7CDB90; // Unknown = 
    inline constexpr uintptr_t FIntShareSheetTelemetryThrottleHundredthsPercent = 0x19D80F41818; // Unknown = 
    inline constexpr uintptr_t FIntShopPrefetchRetryBackoffMs = 0x19BC2202CC8; // Unknown = 
    inline constexpr uintptr_t FIntShouldShowPushUpsellHideResponseCacheExpirationTime = 0x19B8FA1F250; // Unknown = 
    inline constexpr uintptr_t FIntShowFriendRecommendationsLimit = 0x19B90267590; // Unknown = 
    inline constexpr uintptr_t FIntSideSheetVariant = 0x19B9ACB4C90; // Unknown = 
    inline constexpr uintptr_t FIntSideSheetVariant2 = 0x19B9ACBFED0; // Unknown = 
    inline constexpr uintptr_t FIntSidesheetClosedEventThrottleHundredthsPercent = 0x19BA4E96010; // Unknown = 
    inline constexpr uintptr_t FIntSignUpBirthdayPickerManualSelectVariantOverride = 0x19B9ACB9790; // Unknown = 
    inline constexpr uintptr_t FIntSignupMinimumAge = 0x19B945A3F90; // Unknown = 
    inline constexpr uintptr_t FIntSilentPasskeyUpgradeThrottlingHundredthsPercent = 0x19BBC1C09D0; // Unknown = 
    inline constexpr uintptr_t FIntSilentUpgradeReauthDelaySeconds = 0x19B90291490; // Unknown = 
    inline constexpr uintptr_t FIntSinglePageSignupMinimumAge = 0x19B9ACB4190; // Unknown = 
    inline constexpr uintptr_t FIntSkyStyleDayClockTime = 0x19BA6A33410; // Unknown = 
    inline constexpr uintptr_t FIntSmallCollectionItemFractionalPercent = 0x19BA679C790; // Unknown = 
    inline constexpr uintptr_t FIntSmallCollectionItemMaxItemCount = 0x19BA6797290; // Unknown = 
    inline constexpr uintptr_t FIntSmallCollectionItemMinItemCount = 0x19BA6791A10; // Unknown = 
    inline constexpr uintptr_t FIntSmallCollectionItemMinItemWidth = 0x19BA6792A90; // Unknown = 
    inline constexpr uintptr_t FIntSmallCollectionItemVerticalGap = 0x19BA679F550; // Unknown = 
    inline constexpr uintptr_t FIntSnapLevelInVirtualCursor = 0x19BA59B7F10; // Unknown = 
    inline constexpr uintptr_t FIntSocalCarouselMaxNewRequestsCount = 0x19BB787E650; // Unknown = 
    inline constexpr uintptr_t FIntSocialBlockingModalAnalyticsThrottlingThousandths = 0x19D86D6C568; // Unknown = 
    inline constexpr uintptr_t FIntSocialCarouselAnalyticsThrottlingThousandths = 0x19B8FA1E010; // Unknown = 
    inline constexpr uintptr_t FIntSocialCarouselMaxNewRequestsCount = 0x19B8FA1E850; // Unknown = 
    inline constexpr uintptr_t FIntSocialCarouselShowRecsLimit = 0x19B8FA1DBD0; // Unknown = 
    inline constexpr uintptr_t FIntSocialContextToastDelay = 0x19B91162FA0; // Unknown = 
    inline constexpr uintptr_t FIntSocialContextToastHttpRetryCount = 0x19B9F923190; // Unknown = 
    inline constexpr uintptr_t FIntSocialExperienceJoinAnalyticsThrottlingThousandths = 0x19BA6794A50; // Unknown = 
    inline constexpr uintptr_t FIntSocialExperienceJoinHttpRetryCount = 0x19BA679D550; // Unknown = 
    inline constexpr uintptr_t FIntSocialGraphSyncRequestRetryCount = 0x19B90293450; // Unknown = 
    inline constexpr uintptr_t FIntSocialLinkClickTelemetryThrottlePermyriad = 0x19BA679FFD0; // Unknown = 
    inline constexpr uintptr_t FIntSocialLinksImpressionsEventHundredthsPercent = 0x19BA6794050; // Unknown = 
    inline constexpr uintptr_t FIntSocialStopwatchTelementyThrottleHundrethsPercent = 0x19D86D6F8A8; // Unknown = 
    inline constexpr uintptr_t FIntSocialTabStateHttpRetryCount = 0x19B9026F6D0; // Unknown = 
    inline constexpr uintptr_t FIntSocialTabsPageHttpRetryCount = 0x19B9011F110; // Unknown = 
    inline constexpr uintptr_t FIntSocialUpsellEventThrottleHunderedthsPercent = 0x19BB6B3EF70; // Unknown = 
    inline constexpr uintptr_t FIntSongDetailsRefreshIntervalSeconds = 0x19B88C2EB90; // Unknown = 
    inline constexpr uintptr_t FIntSongbirdTelemetryThrottle = 0x19D8029AD10; // Unknown = 
    inline constexpr uintptr_t FIntSortDeeplinkFailureEventThrottleHundrethsPercent = 0x19BA67232D0; // Unknown = 
    inline constexpr uintptr_t FIntSpatialUIChromeSubMenuHeight = 0x19B9FD87710; // Unknown = 
    inline constexpr uintptr_t FIntSpatialUIDarkenBackgroundTransparency = 0x19B9FD887D0; // Unknown = 
    inline constexpr uintptr_t FIntSpatialUIPanelDistance = 0x19B9FD86F50; // Unknown = 
    inline constexpr uintptr_t FIntSpatialUIPanelDragBarDistance = 0x19B9FD87AD0; // Unknown = 
    inline constexpr uintptr_t FIntSpatialUIPanelZOffset = 0x19B9FD87A50; // Unknown = 
    inline constexpr uintptr_t FIntSpatialUIResolutionScale = 0x19B9FD879D0; // Unknown = 
    inline constexpr uintptr_t FIntSpatialUIVersionTextSizeScaled = 0x19B9FD88910; // Unknown = 
    inline constexpr uintptr_t FIntSquadExperienceInvitePollingIntervalSeconds = 0x19BA802DED0; // Unknown = 
    inline constexpr uintptr_t FIntSquadExperienceInviteTimeoutSeconds = 0x19BA802DF50; // Unknown = 
    inline constexpr uintptr_t FIntSquadHttpRetryCount = 0x19BA6721810; // Unknown = 
    inline constexpr uintptr_t FIntSquadRegroupPromptDebounceTimeMs = 0x19BA8027350; // Unknown = 
    inline constexpr uintptr_t FIntStreamingPauseUIAnalyticsThrottleHP = 0x19B9F0A76D0; // Unknown = 
    inline constexpr uintptr_t FIntSubscriptionPurchaseFlowEventIngestThrottleHundredthsPercent = 0x19B8FC33B50; // Unknown = 
    inline constexpr uintptr_t FIntSurvBloxRequiredCooldownMs = 0x19B90290250; // Unknown = 
    inline constexpr uintptr_t FIntSwitchServerTelemetryThrottleHundrethsPercent = 0x19D80F62328; // Unknown = 
    inline constexpr uintptr_t FIntSystemBarHeightMultiplierPercentageOverride = 0x19B99880650; // Unknown = 
    inline constexpr uintptr_t FIntTTIUnifiedPurchaseSamplingRate = 0x19B9AF1B010; // Unknown = 
    inline constexpr uintptr_t FIntTalkingChangedDebounceTime = 0x19B8FDE8ED0; // Unknown = 
    inline constexpr uintptr_t FIntTeleportBackAttemptLimit = 0x19BBE91C690; // Unknown = 
    inline constexpr uintptr_t FIntTeleportBackRetryDelay = 0x19BBE91DC10; // Unknown = 
    inline constexpr uintptr_t FIntTenFootSkyboxBlockerPositionX = 0x19B859CB510; // Unknown = 
    inline constexpr uintptr_t FIntTenFootSkyboxBlockerPositionY = 0x19B859CB950; // Unknown = 
    inline constexpr uintptr_t FIntTenFootSkyboxBlockerPositionZ = 0x19B859CBBD0; // Unknown = 
    inline constexpr uintptr_t FIntTenFootSkyboxBlockerSizeX = 0x19B859CAFD0; // Unknown = 
    inline constexpr uintptr_t FIntTenFootSkyboxBlockerSizeY = 0x19B859CB1D0; // Unknown = 
    inline constexpr uintptr_t FIntTenFootSkyboxBlockerSizeZ = 0x19B859CB250; // Unknown = 
    inline constexpr uintptr_t FIntThrottleParticipantsUpdateMs2 = 0x19B8FDEAC10; // Unknown = 
    inline constexpr uintptr_t FIntTilePlacedTelemetryThrottleHundredthsPercent = 0x19BBE91F0D0; // Unknown = 
    inline constexpr uintptr_t FIntTileSkippedTelemetryThrottleHundredthsPercent = 0x19BBE91F310; // Unknown = 
    inline constexpr uintptr_t FIntTimeToInteractiveTrackerSampleRate = 0x19B8F7419D0; // Unknown = 
    inline constexpr uintptr_t FIntTooltipHitboxMinSize = 0x19BBC7A8610; // Unknown = 
    inline constexpr uintptr_t FIntTraversalTelemetryThrottleHundrethsPercent = 0x19BBC3888D0; // Unknown = 
    inline constexpr uintptr_t FIntTrustedConnectionsStoreDataTtlSec = 0x19BA5BD3350; // Unknown = 
    inline constexpr uintptr_t FIntTrustedConnectionsStoreIncomingRequestsProcessDelaySec = 0x19BA5BDB390; // Unknown = 
    inline constexpr uintptr_t FIntTrustedConnectionsStoreProcessDelaySec = 0x19BA5BD8250; // Unknown = 
    inline constexpr uintptr_t FIntTrustedContactsHttpRetryCount = 0x19BA5BD2F10; // Unknown = 
    inline constexpr uintptr_t FIntTrustedFriendRequestsPageSize = 0x19B8C2E1390; // Unknown = 
    inline constexpr uintptr_t FIntUIResetDelayInSec = 0x19BB397E250; // Unknown = 
    inline constexpr uintptr_t FIntUSER_VOTE_CACHE_TTL_SECONDS = 0x19BA5BD2110; // Unknown = 
    inline constexpr uintptr_t FIntUXForCameraPerformanceDeviceDelay = 0x19B9F0AC110; // Unknown = 
    inline constexpr uintptr_t FIntUXForCameraPerformanceSessionDelay = 0x19B9F0AC5D0; // Unknown = 
    inline constexpr uintptr_t FIntUiShellOrientationChangedThrottleHundredthsPercent = 0x19BA60963D0; // Unknown = 
    inline constexpr uintptr_t FIntUnauthorizedErrorThrottlingHundredthsPercent = 0x19BBC1CFED0; // Unknown = 
    inline constexpr uintptr_t FIntUnblockUserThrottleHundredthsPercent = 0x19BBC388650; // Unknown = 
    inline constexpr uintptr_t FIntUnblockUserThrottleHundredthsPercent4 = 0x19BBC386D90; // Unknown = 
    inline constexpr uintptr_t FIntUnfilteredMessageTransparencyHundredths = 0x19B9FB745E0; // Unknown = 
    inline constexpr uintptr_t FIntUnfilteredThreadsPvDelayMs = 0x19BA0A56BE8; // Unknown = 
    inline constexpr uintptr_t FIntUnifiedPurchaseTelemetryEventIngestThrottleHundredthsPercent = 0x19D85DC8A50; // Unknown = 
    inline constexpr uintptr_t FIntUniversalAppPolicyFailureTelemetryThrottleHundredthsPercent = 0x19BA8A0F290; // Unknown = 
    inline constexpr uintptr_t FIntUnmuteAllThrottleHundredthsPercent = 0x19BBC3885D0; // Unknown = 
    inline constexpr uintptr_t FIntUnmutePlayerThrottleHundredthsPercent = 0x19BBC3896D0; // Unknown = 
    inline constexpr uintptr_t FIntUnmuteSelfThrottleHundredthsPercent = 0x19BBC387E10; // Unknown = 
    inline constexpr uintptr_t FIntUnmuteSelfThrottleHundredthsPercent4 = 0x19B9CCEC030; // Unknown = 
    inline constexpr uintptr_t FIntUnpublishedPlaytestModeTooltipDisplayLimit = 0x19B9ACB5B50; // Unknown = 
    inline constexpr uintptr_t FIntUpVectorOrentationThreshold1 = 0x19D8952E790; // Unknown = 
    inline constexpr uintptr_t FIntUpsellAccountBalanceRetryAttemps = 0x19D85DC4010; // Unknown = 
    inline constexpr uintptr_t FIntUpsellAccountBalanceRetryIntervalSec = 0x19D85DC5E50; // Unknown = 
    inline constexpr uintptr_t FIntUpsellSuggestionsAPIMaxPackagesV3 = 0x19B9ACBF890; // Unknown = 
    inline constexpr uintptr_t FIntUseAssetFavoritingHttpRetryCount = 0x19D802942D0; // Unknown = 
    inline constexpr uintptr_t FIntUserProfileDefaultRetryCount = 0x19BA5156D10; // Unknown = 
    inline constexpr uintptr_t FIntUserProfileStoreBatchSize = 0x19BA515E1D0; // Unknown = 
    inline constexpr uintptr_t FIntUserProfileStoreHttpTimeout = 0x19BA515F050; // Unknown = 
    inline constexpr uintptr_t FIntUserProfileStoreQueueProcessDelay = 0x19BA5156010; // Unknown = 
    inline constexpr uintptr_t FIntUserProfilesDataLoaderClearTime_v1 = 0x19BADF9C110; // Unknown = 
    inline constexpr uintptr_t FIntUserRelationshipModalsAnalyticsThrottlingThousandths = 0x19BA6077A10; // Unknown = 
    inline constexpr uintptr_t FIntUserSearchHttpRetryCount = 0x19B9011DD90; // Unknown = 
    inline constexpr uintptr_t FIntUserSeenCollectionBatchTimeMs = 0x19B88C2BD50; // Unknown = 
    inline constexpr uintptr_t FIntV1MenuLanguageSelectionFeaturePerMillageRollout = 0x19B9FD8D390; // Unknown = 
    inline constexpr uintptr_t FIntVRAvatarGesturesAnalyticsThrottleHundrethsPercent = 0x19B9F0A61D0; // Unknown = 
    inline constexpr uintptr_t FIntVRBottomBarPositionOffsetDepthNumber = 0x19B9FDD4E88; // Unknown = 
    inline constexpr uintptr_t FIntVRBottomBarPositionOffsetVerticalNumber = 0x19B9FDD4F08; // Unknown = 
    inline constexpr uintptr_t FIntVREnvironmentSettingDarkClockTime = 0x19BA6A36590; // Unknown = 
    inline constexpr uintptr_t FIntVREnvironmentSettingLightClockTime = 0x19BA6A338D0; // Unknown = 
    inline constexpr uintptr_t FIntVRScaleGuiDistance = 0x19BAEB793D0; // Unknown = 
    inline constexpr uintptr_t FIntVRTouchControllerTransparency = 0x19BBE91ACD0; // Unknown = 
    inline constexpr uintptr_t FIntValidCookieForNoCachedUserThrottlingHundredthsPercent = 0x19BBC1CBB10; // Unknown = 
    inline constexpr uintptr_t FIntVideoBlockingTelemetryThrottleHundredthsPercent = 0x19BBE912250; // Unknown = 
    inline constexpr uintptr_t FIntVideoEngagementEventHundredthsPercent = 0x19BBC38A050; // Unknown = 
    inline constexpr uintptr_t FIntVideoPlaybackDetectorScanDebounceInMilliseconds = 0x19B88C2C250; // Unknown = 
    inline constexpr uintptr_t FIntVideoPlayerPlaybackEndThresholdInMs = 0x19BBC383A10; // Unknown = 
    inline constexpr uintptr_t FIntVirtualEventsHttpRetryCount = 0x19B859CAC90; // Unknown = 
    inline constexpr uintptr_t FIntVoiceCapturedDuringVideoCaptureThrottlingPercentage = 0x19B8FDEB750; // Unknown = 
    inline constexpr uintptr_t FIntVoiceChatDeviceChangeDebounceDelay = 0x19B9FD8CE90; // Unknown = 
    inline constexpr uintptr_t FIntVoiceChatTooltipDelay = 0x19BA4E9E550; // Unknown = 
    inline constexpr uintptr_t FIntVoiceJoinM3ToastDurationSeconds = 0x19BA4E9DB90; // Unknown = 
    inline constexpr uintptr_t FIntVoiceReverseNudgeUXDisplayTimeSeconds = 0x19B9F1812A8; // Unknown = 
    inline constexpr uintptr_t FIntVoiceToxicityToastDurationSeconds = 0x19BA4E9FE50; // Unknown = 
    inline constexpr uintptr_t FIntVoiceUsersInteractionExpiryTimeSeconds = 0x19B8FDEA310; // Unknown = 
    inline constexpr uintptr_t FIntVrAppPanelCurvatureOverride = 0x19BA6A3DF10; // Unknown = 
    inline constexpr uintptr_t FIntVrAppPanelWidthMultiplierPercentageOverride = 0x19BA6A31050; // Unknown = 
    inline constexpr uintptr_t FIntVrAvatarPanelsSpreadMultiplierPercentageOverride = 0x19B859C5D50; // Unknown = 
    inline constexpr uintptr_t FIntWaitAfterCloseChallengeWebViewSeconds = 0x19B8FC397D0; // Unknown = 
    inline constexpr uintptr_t FIntWaitForChildOfClassTimeout = 0x19BACE799D0; // Unknown = 
    inline constexpr uintptr_t FIntWebViewLastClosedDurationSeconds = 0x19B90292E90; // Unknown = 
    inline constexpr uintptr_t FIntWebViewOpenDurationCapSeconds = 0x19B90292CD0; // Unknown = 
    inline constexpr uintptr_t FIntWidgetListInitialNumToRender = 0x19B8F9DFAD0; // Unknown = 
    inline constexpr uintptr_t FIntWidgetListWindowSize = 0x19B8F9DFA10; // Unknown = 
    inline constexpr uintptr_t FIntWidgetPaddingSizing = 0x19B8FC32850; // Unknown = 
    inline constexpr uintptr_t FIntXLargeCollectionItemFractionalPercent = 0x19BA6793BD0; // Unknown = 
    inline constexpr uintptr_t FIntXLargeCollectionItemMaxItemCount = 0x19BA6799990; // Unknown = 
    inline constexpr uintptr_t FIntXLargeCollectionItemMinItemCount = 0x19BA6792250; // Unknown = 
    inline constexpr uintptr_t FIntXLargeCollectionItemMinItemWidth = 0x19BA6797E50; // Unknown = 
    inline constexpr uintptr_t FIntXLargeCollectionItemVerticalGap = 0x19BA679D010; // Unknown = 
    inline constexpr uintptr_t FIntXSmallCollectionItemFractionalPercent = 0x19BA679E510; // Unknown = 
    inline constexpr uintptr_t FIntXSmallCollectionItemMaxItemCount = 0x19BA67903D0; // Unknown = 
    inline constexpr uintptr_t FIntXSmallCollectionItemMinItemCount = 0x19BA6794590; // Unknown = 
    inline constexpr uintptr_t FIntXSmallCollectionItemMinItemWidth = 0x19BA679B650; // Unknown = 
    inline constexpr uintptr_t FIntXSmallCollectionItemVerticalGap = 0x19BA6798DD0; // Unknown = 
    inline constexpr uintptr_t FStringAEGIS2AppChatAgeVerifiedRealtimeNamespace = 0x19B8C2E4250; // Unknown = 
    inline constexpr uintptr_t FStringAXAvatarWidgetContentType = 0x19B90644910; // Unknown = 
    inline constexpr uintptr_t FStringAXBackendDrivenCatalogLayersFString = 0x19BBC7A8790; // Unknown = 
    inline constexpr uintptr_t FStringAXBackendDrivenCatalogLayersNames = 0x19BBCCCFAD0; // Unknown = 
    inline constexpr uintptr_t FStringAXBackgroundGenerationCanvasAssetIdDark = 0x19B8F904C10; // Unknown = 
    inline constexpr uintptr_t FStringAXBackgroundGenerationCanvasAssetIdLight = 0x19B9F189700; // Unknown = 
    inline constexpr uintptr_t FStringAXBodyCategoryTooltipKey = 0x19B9026F250; // Unknown = 
    inline constexpr uintptr_t FStringAXCategories = 0x19B9026E490; // Unknown = 
    inline constexpr uintptr_t FStringAXCombineGetOutfitDispatchesIXPLayer3 = 0x19B9026D4D0; // Unknown = 
    inline constexpr uintptr_t FStringAXCycloramaFallbackAssetId = 0x19BBCCCB5F0; // Unknown = 
    inline constexpr uintptr_t FStringAXDefaultAvatarToShopLayer3 = 0x19B90647190; // Unknown = 
    inline constexpr uintptr_t FStringAXDurablesSupportExposureLayer = 0x19BA3A50E10; // Unknown = 
    inline constexpr uintptr_t FStringAXFetchCartPricingDuringInExperienceLayerName = 0x19B9ACBB490; // Unknown = 
    inline constexpr uintptr_t FStringAXInspectAndBuyLayerName = 0x19B9F299050; // Unknown = 
    inline constexpr uintptr_t FStringAXItemDetails3DPreviewIXPLayer = 0x19B9026D310; // Unknown = 
    inline constexpr uintptr_t FStringAXLookWidgetContentType = 0x19B90644D10; // Unknown = 
    inline constexpr uintptr_t FStringAXPlusExclusiveBackgroundIds = 0x19B8F907B10; // Unknown = 
    inline constexpr uintptr_t FStringAXRecommendedItemsExposureLayer = 0x19B8F905390; // Unknown = 
    inline constexpr uintptr_t FStringAXSlotBasedEditorCategoryTooltipKey = 0x19B9026C3D0; // Unknown = 
    inline constexpr uintptr_t FStringAXSlotsDesignUpdatesExposureLayer = 0x19BA3A553D0; // Unknown = 
    inline constexpr uintptr_t FStringAXSortsBodyTabRecLayerName = 0x19B8F907910; // Unknown = 
    inline constexpr uintptr_t FStringAXTallBundleWidgetContentType = 0x19B90644850; // Unknown = 
    inline constexpr uintptr_t FStringAXTaxonomyM20ExperimentLayerName = 0x19B9F18E7A0; // Unknown = 
    inline constexpr uintptr_t FStringAXTaxonomyM21ExperimentLayerName = 0x19B8F907F90; // Unknown = 
    inline constexpr uintptr_t FStringAXTooltipAllowedTooltips = 0x19B9F00E010; // Unknown = 
    inline constexpr uintptr_t FStringAccountRecoveryUILayer = 0x19BA3BBA4D0; // Unknown = 
    inline constexpr uintptr_t FStringAccountSwitcherLayer = 0x19BA3BB3BD0; // Unknown = 
    inline constexpr uintptr_t FStringAdDropdownButtonDefault = 0x19B9F9202D0; // Unknown = 
    inline constexpr uintptr_t FStringAdDropdownButtonOpen = 0x19B9F920410; // Unknown = 
    inline constexpr uintptr_t FStringAdGuiCloseButtonImageLua = 0x19BA8A0E2D0; // Unknown = 
    inline constexpr uintptr_t FStringAdGuiLivePreviewWatermark = 0x19BA8A0E5D0; // Unknown = 
    inline constexpr uintptr_t FStringAdGuiLivePreviewWatermarkV2 = 0x19BA8A0EB90; // Unknown = 
    inline constexpr uintptr_t FStringAdGuiPauseButtonImageLua = 0x19BA8A0E110; // Unknown = 
    inline constexpr uintptr_t FStringAdGuiPlayButtonImageLua = 0x19BA8A0DFD0; // Unknown = 
    inline constexpr uintptr_t FStringAdPlayerExitButton = 0x19B9119EFC0; // Unknown = 
    inline constexpr uintptr_t FStringAdsEnterFullscreenImageLua = 0x19BA8A0CDD0; // Unknown = 
    inline constexpr uintptr_t FStringAdsEudsaPromptActiveImageLua = 0x19BA8A07F50; // Unknown = 
    inline constexpr uintptr_t FStringAdsEudsaPromptInactiveImageLua = 0x19BA8A0DA50; // Unknown = 
    inline constexpr uintptr_t FStringAdsExitFullscreenImageLua = 0x19BA8A0C550; // Unknown = 
    inline constexpr uintptr_t FStringAdsVolumeOffImageLua = 0x19BA8A0C890; // Unknown = 
    inline constexpr uintptr_t FStringAdsVolumeOnImageLua = 0x19BA8A0CA50; // Unknown = 
    inline constexpr uintptr_t FStringAgeCheckAmpNameSpace = 0x19BA8444010; // Unknown = 
    inline constexpr uintptr_t FStringAllFriendsCarouselLoadingTimeDoneStats = 0x19B902677D0; // Unknown = 
    inline constexpr uintptr_t FStringAllFriendsCarouselLoadingTimeFailedStats = 0x19B90267B50; // Unknown = 
    inline constexpr uintptr_t FStringAllFriendsNextPageCarouselLoadingTimeDoneStats = 0x19B90267E90; // Unknown = 
    inline constexpr uintptr_t FStringAllFriendsNextPageCarouselLoadingTimeFailedStats = 0x19B90267D90; // Unknown = 
    inline constexpr uintptr_t FStringAndroidPhoneVerificationLayer = 0x19BA6A33DD0; // Unknown = 
    inline constexpr uintptr_t FStringApisCdnUrl = 0x19B90291290; // Unknown = 
    inline constexpr uintptr_t FStringAppBadgingLayer = 0x19BA3BB02D0; // Unknown = 
    inline constexpr uintptr_t FStringAppChatClosedCounter = 0x19BA60727D0; // Unknown = 
    inline constexpr uintptr_t FStringAppChatConversationPageSyntheticSystemMessageIxpLayer = 0x19BACE78690; // Unknown = 
    inline constexpr uintptr_t FStringAppChatEnableRepliesUIIxpLayer1 = 0x19BACE7D410; // Unknown = 
    inline constexpr uintptr_t FStringAppChatFixRootChatBackNavigationIxpLayer = 0x19B8FA15910; // Unknown = 
    inline constexpr uintptr_t FStringAppChatGroupOsaViewDetailsUrl = 0x19B8FA152D0; // Unknown = 
    inline constexpr uintptr_t FStringAppChatInExperienceIXPLayer = 0x19B8C2EA9D0; // Unknown = 
    inline constexpr uintptr_t FStringAppChatNewChatInputBarIxpLayer = 0x19BACE73BD0; // Unknown = 
    inline constexpr uintptr_t FStringAppChatPerfExperimentLayer = 0x19BBCCC3350; // Unknown = 
    inline constexpr uintptr_t FStringAppChatRemoveConversationListDividerIxpLayer = 0x19B8FA1D510; // Unknown = 
    inline constexpr uintptr_t FStringAppChatSessionName = 0x19BA6079190; // Unknown = 
    inline constexpr uintptr_t FStringAppChatSquadButtonColorUpdateIxpLayer = 0x19BACE76D10; // Unknown = 
    inline constexpr uintptr_t FStringAppChatTcLearnMoreUrl = 0x19B9FB746D0; // Unknown = 
    inline constexpr uintptr_t FStringAppChatTimestampInSubtitleIxpLayer = 0x19B8FA1E1D0; // Unknown = 
    inline constexpr uintptr_t FStringAppChatVisibleCounter = 0x19BA6076490; // Unknown = 
    inline constexpr uintptr_t FStringArgoPartyLayer = 0x19B8FDECC50; // Unknown = 
    inline constexpr uintptr_t FStringArgoPartyVariant = 0x19B8FDECCD0; // Unknown = 
    inline constexpr uintptr_t FStringArgusApiUrlBase = 0x19BB8974598; // Unknown = 
    inline constexpr uintptr_t FStringArgusEntryTypeKey = 0x19D86F0FA10; // Unknown = 
    inline constexpr uintptr_t FStringArgusExperimentLayer = 0x19D86F07490; // Unknown = 
    inline constexpr uintptr_t FStringArgusInfluencerUploadsKey = 0x19D86F0B950; // Unknown = 
    inline constexpr uintptr_t FStringArgusPlatformIntegrationKey = 0x19D86F08FD0; // Unknown = 
    inline constexpr uintptr_t FStringAuthenticationErrorCode = 0x19B88C61A90; // Unknown = 
    inline constexpr uintptr_t FStringAuthenticationErrorCodeAlternative = 0x19BACFDA850; // Unknown = 
    inline constexpr uintptr_t FStringAvatarSwitcherIXPLayer = 0x19B939B5968; // Unknown = 
    inline constexpr uintptr_t FStringAvatarSwitcherTooltipStorageKey = 0x19BABC132D0; // Unknown = 
    inline constexpr uintptr_t FStringBacktraceLogTags = 0x19B8F90B910; // Unknown = 
    inline constexpr uintptr_t FStringBillboardUpdateFrequencyIXPLayerValue = 0x19BBCD7FB10; // Unknown = 
    inline constexpr uintptr_t FStringBiometricPrivacyPolicyLink = 0x19B90113810; // Unknown = 
    inline constexpr uintptr_t FStringBlackbirdUpsellHiddenRequestTypes2 = 0x19B9EE00150; // Unknown = 
    inline constexpr uintptr_t FStringBlackbirdUrl = 0x19BA6A35690; // Unknown = 
    inline constexpr uintptr_t FStringBlackbirdWebviewHeaderName = 0x19B82E09F90; // Unknown = 
    inline constexpr uintptr_t FStringBuildExperienceProductionTemplatePlaceId = 0x19BAD588550; // Unknown = 
    inline constexpr uintptr_t FStringCameraUnavailableUrl = 0x19B9F0AD610; // Unknown = 
    inline constexpr uintptr_t FStringCanAccessTrustedContactsAmpFeature = 0x19BACFD23D0; // Unknown = 
    inline constexpr uintptr_t FStringCanAccessTrustedContactsAmpNameSpace = 0x19BACFD8050; // Unknown = 
    inline constexpr uintptr_t FStringCapturesActivatedInGameMenu = 0x19BAC87CB10; // Unknown = 
    inline constexpr uintptr_t FStringCapturesCarouselOpened = 0x19BAC87CD50; // Unknown = 
    inline constexpr uintptr_t FStringCapturesDeactivatedInGameMenu = 0x19BAC877490; // Unknown = 
    inline constexpr uintptr_t FStringCapturesEntrypointActivated = 0x19BAC87CC90; // Unknown = 
    inline constexpr uintptr_t FStringCapturesIXPLayer = 0x19B8C2EA490; // Unknown = 
    inline constexpr uintptr_t FStringCapturesPageOpenedInGameMenu = 0x19BAC87C650; // Unknown = 
    inline constexpr uintptr_t FStringCapturesShareToastButtonActivated = 0x19BAC87CA10; // Unknown = 
    inline constexpr uintptr_t FStringCapturesTabIXPLayer = 0x19BA6A31450; // Unknown = 
    inline constexpr uintptr_t FStringChatAddFriendsBtnClickedCounter = 0x19BA6074950; // Unknown = 
    inline constexpr uintptr_t FStringChatDetailsAddFriendsBtnClickedCounter = 0x19BA607C5D0; // Unknown = 
    inline constexpr uintptr_t FStringChatDetailsCreateUnfilteredChatCellClickedCounter = 0x19BA607D2D0; // Unknown = 
    inline constexpr uintptr_t FStringChatDetailsCreateUnfilteredChatCellRenderedCounter = 0x19BA6074890; // Unknown = 
    inline constexpr uintptr_t FStringChatDetailsLeaveGroupBtnClickedCounter = 0x19BA607BB10; // Unknown = 
    inline constexpr uintptr_t FStringChatDetailsLeaveGroupDialogLeaveClickedCounter = 0x19BA60729D0; // Unknown = 
    inline constexpr uintptr_t FStringChatDetailsLeaveGroupDialogRenderedCounter = 0x19BA6075310; // Unknown = 
    inline constexpr uintptr_t FStringChatDetailsLeaveGroupDialogStayClickedCounter = 0x19BA60756D0; // Unknown = 
    inline constexpr uintptr_t FStringChatDetailsRenderedCounter = 0x19BA6076910; // Unknown = 
    inline constexpr uintptr_t FStringChatDetailsReportUserClickedCounter = 0x19BA607F110; // Unknown = 
    inline constexpr uintptr_t FStringChatEmptyStateScreenRenderedCounter = 0x19BA6078AD0; // Unknown = 
    inline constexpr uintptr_t FStringChatInputBarReplyComposeCancelBtnActivatedCounter = 0x19BA6076790; // Unknown = 
    inline constexpr uintptr_t FStringChatInputBarReplyComposeRenderedCounter = 0x19BA6078ED0; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingComposeBtnClickedCounter = 0x19BA607C9D0; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingConversationClickedCounter = 0x19BA607F0D0; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingGroupsBtnClicked = 0x19BA6075050; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingNotifBtnClickedCounter = 0x19BA6070150; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingPvUpsellContinueClickedCounter = 0x19BA6074A50; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingPvUpsellDismissedCounter = 0x19BA6072FD0; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingPvUpsellFailedCounter = 0x19BA6071350; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingPvUpsellRenderedCounter = 0x19BA60711D0; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingPvUpsellSucceededCounter = 0x19BA6071390; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingScreenRenderedCounter = 0x19BA6075E50; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingSearchBtnClickedCounter = 0x19BA607C950; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingUnfilteredThreadsFtuxDismissedCounter = 0x19BA6076850; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingUnfilteredThreadsFtuxLearnMoreClickedCounter = 0x19BA607D910; // Unknown = 
    inline constexpr uintptr_t FStringChatLandingUnfilteredThreadsFtuxRenderedCounter = 0x19BA6072550; // Unknown = 
    inline constexpr uintptr_t FStringChatLineReportingSubmittedAbuseTypeStat = 0x19BA5151090; // Unknown = 
    inline constexpr uintptr_t FStringChatLineReportingTimeSpentStat = 0x19BA5153750; // Unknown = 
    inline constexpr uintptr_t FStringChatMessageLongPressedCounter = 0x19BA60755D0; // Unknown = 
    inline constexpr uintptr_t FStringChatMessageMenuCopyBtnActivatedCounter = 0x19BA6077710; // Unknown = 
    inline constexpr uintptr_t FStringChatMessageMenuOpenedCounter = 0x19BA607F890; // Unknown = 
    inline constexpr uintptr_t FStringChatMessageMenuReplyBtnActivatedCounter = 0x19BA607FA50; // Unknown = 
    inline constexpr uintptr_t FStringChatMessageOpenMenuIconClickedCounter = 0x19BA6072A10; // Unknown = 
    inline constexpr uintptr_t FStringChatMessagePressedCounter = 0x19BA6075210; // Unknown = 
    inline constexpr uintptr_t FStringChatMessageReplyIconClickedCounter = 0x19BA607E190; // Unknown = 
    inline constexpr uintptr_t FStringChatTranslationEnabledLocales = 0x19B9FD8C790; // Unknown = 
    inline constexpr uintptr_t FStringChatTranslationLayerName = 0x19B9AF10390; // Unknown = 
    inline constexpr uintptr_t FStringClientToastNotificationsRedirectLayerName = 0x19BACFEB210; // Unknown = 
    inline constexpr uintptr_t FStringClientToastNotificationsRedirectLayerValue = 0x19BACFEB390; // Unknown = 
    inline constexpr uintptr_t FStringCloseContactListButtonCounter = 0x19BAEDDC1A8; // Unknown = 
    inline constexpr uintptr_t FStringCloseContactListCrossCounter = 0x19BAFCFDA10; // Unknown = 
    inline constexpr uintptr_t FStringCommsFAEFeatureName = 0x19B90268650; // Unknown = 
    inline constexpr uintptr_t FStringCommsFAENamespace = 0x19B90268590; // Unknown = 
    inline constexpr uintptr_t FStringConnectionGraphCoreAmpNameSpace = 0x19BA59B97D0; // Unknown = 
    inline constexpr uintptr_t FStringConsoleSignUpLayer = 0x19BA3BB8E90; // Unknown = 
    inline constexpr uintptr_t FStringConsoleVoiceEnabledIXPLayerValue = 0x19B8FDE9390; // Unknown = 
    inline constexpr uintptr_t FStringConsoleVoiceIXPLayerName = 0x19B8FDE9950; // Unknown = 
    inline constexpr uintptr_t FStringConsumerPlatformsIOSUIRefactor = 0x19BA3BB6550; // Unknown = 
    inline constexpr uintptr_t FStringContactImportGreenFindFriendsButtonExperimentVariable = 0x19BAFCFA810; // Unknown = 
    inline constexpr uintptr_t FStringContactImportLayer = 0x19BAFCFAB10; // Unknown = 
    inline constexpr uintptr_t FStringContactImportModalAddFriendsCounter = 0x19BAFCFF190; // Unknown = 
    inline constexpr uintptr_t FStringContactImportModalCloseCounter = 0x19BAFCF9250; // Unknown = 
    inline constexpr uintptr_t FStringContactImportModalContinueCounter = 0x19BAFCFB110; // Unknown = 
    inline constexpr uintptr_t FStringContactImportModalPageLoadCounter = 0x19BAFCFA950; // Unknown = 
    inline constexpr uintptr_t FStringContactImportRemoveCloseButtonExperimentVariable = 0x19BAFCF8FD0; // Unknown = 
    inline constexpr uintptr_t FStringContactImporterFindFriendsUrl = 0x19B994351A0; // Unknown = 
    inline constexpr uintptr_t FStringContactImporterInviteContactCounter = 0x19BAFCFFD90; // Unknown = 
    inline constexpr uintptr_t FStringContactImporterRequestFriendshipCounter = 0x19BAFCFBE50; // Unknown = 
    inline constexpr uintptr_t FStringContactImportingTimeStat = 0x19BAFCFF6D0; // Unknown = 
    inline constexpr uintptr_t FStringContactsListEmojiSortingIxpLayer = 0x19BAFCF7590; // Unknown = 
    inline constexpr uintptr_t FStringContactsListLoadedCounter = 0x19BAFCFD550; // Unknown = 
    inline constexpr uintptr_t FStringConversationIneligibleModalLearnMoreClickedCounter = 0x19BA607E7D0; // Unknown = 
    inline constexpr uintptr_t FStringConversationIneligibleModalLeftGroupCounter = 0x19BA6071410; // Unknown = 
    inline constexpr uintptr_t FStringConversationIneligibleModalRenderedCounter = 0x19BA6075C10; // Unknown = 
    inline constexpr uintptr_t FStringConversationInfoBtnClickedCounter = 0x19BA6072190; // Unknown = 
    inline constexpr uintptr_t FStringConversationLearnMoreBannerActionClickedCounter = 0x19BA60763D0; // Unknown = 
    inline constexpr uintptr_t FStringConversationLearnMoreBannerRenderedCounter = 0x19BA6075690; // Unknown = 
    inline constexpr uintptr_t FStringConversationLearnMoreDialogDismissedCounter = 0x19BA6074550; // Unknown = 
    inline constexpr uintptr_t FStringConversationLearnMoreDialogRenderedCounter = 0x19BA60785D0; // Unknown = 
    inline constexpr uintptr_t FStringConversationMessageSentCounter = 0x19BA6076C10; // Unknown = 
    inline constexpr uintptr_t FStringConversationPvBannerActionClickedCounter = 0x19BA607F950; // Unknown = 
    inline constexpr uintptr_t FStringConversationPvBannerRenderedCounter = 0x19BA607C710; // Unknown = 
    inline constexpr uintptr_t FStringConversationPvDialogActionClickedCounter = 0x19BA6071CD0; // Unknown = 
    inline constexpr uintptr_t FStringConversationPvDialogDismissedCounter = 0x19BA6070F50; // Unknown = 
    inline constexpr uintptr_t FStringConversationPvDialogFailedCounter = 0x19BA6072050; // Unknown = 
    inline constexpr uintptr_t FStringConversationPvDialogRenderedCounter = 0x19BA6073450; // Unknown = 
    inline constexpr uintptr_t FStringConversationPvDialogSucceededCounter = 0x19BA6073590; // Unknown = 
    inline constexpr uintptr_t FStringConversationPvUpsellContinueClickedCounter = 0x19BA6071D50; // Unknown = 
    inline constexpr uintptr_t FStringConversationPvUpsellFailedCounter = 0x19BA60741D0; // Unknown = 
    inline constexpr uintptr_t FStringConversationPvUpsellLeftGroupCounter = 0x19BA6077390; // Unknown = 
    inline constexpr uintptr_t FStringConversationPvUpsellRenderedCounter = 0x19BA60721D0; // Unknown = 
    inline constexpr uintptr_t FStringConversationPvUpsellSucceededCounter = 0x19BA60718D0; // Unknown = 
    inline constexpr uintptr_t FStringConversationScreenExitCounter = 0x19BA6072B50; // Unknown = 
    inline constexpr uintptr_t FStringConversationScreenRenderedCounter = 0x19BA607FCD0; // Unknown = 
    inline constexpr uintptr_t FStringConversationSendBtnClickedCounter = 0x19BA607DA10; // Unknown = 
    inline constexpr uintptr_t FStringConversationUpgradeBannerActionClickedCounter = 0x19BA607F610; // Unknown = 
    inline constexpr uintptr_t FStringConversationUpgradeBannerRenderedCounter = 0x19BA6073950; // Unknown = 
    inline constexpr uintptr_t FStringConversationUpgradeDialogActionClickedCounter = 0x19BA607B850; // Unknown = 
    inline constexpr uintptr_t FStringConversationUpgradeDialogDismissedCounter = 0x19BA6071750; // Unknown = 
    inline constexpr uintptr_t FStringConversationUpgradeDialogRenderedCounter = 0x19BA607EFD0; // Unknown = 
    inline constexpr uintptr_t FStringCoreContentAmpNameSpace = 0x19BA8446010; // Unknown = 
    inline constexpr uintptr_t FStringCoreScriptBacktraceErrorUploadToken = 0x19BA553F750; // Unknown = 
    inline constexpr uintptr_t FStringCountriesWithGenericIllegalContentReporting2 = 0x19BA3A58190; // Unknown = 
    inline constexpr uintptr_t FStringCountriesWithTakeItDownReport = 0x19BA3A50D50; // Unknown = 
    inline constexpr uintptr_t FStringCrossExpEventLoggingLevel = 0x19B8ED7FA50; // Unknown = 
    inline constexpr uintptr_t FStringCrossExpVoiceIXPLayer = 0x19B859C9150; // Unknown = 
    inline constexpr uintptr_t FStringCrossExpVoicePlaceId = 0x19B859C9250; // Unknown = 
    inline constexpr uintptr_t FStringCustomizeNameClearedInput = 0x19B90118310; // Unknown = 
    inline constexpr uintptr_t FStringCustomizeNameMaximumCharLimitTyped = 0x19B90119190; // Unknown = 
    inline constexpr uintptr_t FStringCustomizeNameModalClosed = 0x19B901193D0; // Unknown = 
    inline constexpr uintptr_t FStringCustomizeNameModalOpened = 0x19B90118F50; // Unknown = 
    inline constexpr uintptr_t FStringCustomizeNameSaveAttemptInvalidInput = 0x19B90119610; // Unknown = 
    inline constexpr uintptr_t FStringCustomizeNameSaved = 0x19B90119450; // Unknown = 
    inline constexpr uintptr_t FStringDSAReportingAndTransparencyOverrideUserIds = 0x19BA3A59650; // Unknown = 
    inline constexpr uintptr_t FStringDebugCrossExpVoiceIXPLayer = 0x19B859C9050; // Unknown = 
    inline constexpr uintptr_t FStringDebugDefaultPageOverride = 0x19B9026AED0; // Unknown = 
    inline constexpr uintptr_t FStringDebugFriendsChatConversationId = 0x19BA6B3AE90; // Unknown = 
    inline constexpr uintptr_t FStringDebugHomePageUpsellCardVariationResponseBody = 0x19B902671D0; // Unknown = 
    inline constexpr uintptr_t FStringDebugLogTags = 0x19B8F90BAD0; // Unknown = 
    inline constexpr uintptr_t FStringDebugLuaLogLevel = 0x19B9AF1DF50; // Unknown = 
    inline constexpr uintptr_t FStringDebugLuaLogPattern = 0x19B9AF1DE90; // Unknown = 
    inline constexpr uintptr_t FStringDebugOverrideCrossPlayApiUrl = 0x19B859CAB50; // Unknown = 
    inline constexpr uintptr_t FStringDebugOverrideCrossPlayQueryParam = 0x19BB6BB2F90; // Unknown = 
    inline constexpr uintptr_t FStringDebugOverrideCrossPlaySettingsKey = 0x19BB6BB9390; // Unknown = 
    inline constexpr uintptr_t FStringDebugOverrideCrossPlayUri = 0x19BB6BB2A90; // Unknown = 
    inline constexpr uintptr_t FStringDefaultSkyStyle = 0x19BA6A31D90; // Unknown = 
    inline constexpr uintptr_t FStringDefaultVREnvironmentSetting = 0x19BA6A3F210; // Unknown = 
    inline constexpr uintptr_t FStringDesktopUpsellIXPLayer = 0x19BAC832210; // Unknown = 
    inline constexpr uintptr_t FStringDisableAutocorrectExperimentLayer = 0x19BB6BBECD0; // Unknown = 
    inline constexpr uintptr_t FStringDisableCameraOnLowSpecDevicesIXPField = 0x19B9FD89510; // Unknown = 
    inline constexpr uintptr_t FStringDisableCameraOnLowSpecDevicesIXPLayer = 0x19B9FD89A10; // Unknown = 
    inline constexpr uintptr_t FStringDiscoverabilityModalCloseCounter = 0x19BAFCF2D50; // Unknown = 
    inline constexpr uintptr_t FStringDiscoverabilityModalContinueCounter = 0x19BAFCFD010; // Unknown = 
    inline constexpr uintptr_t FStringDiscoverabilityModalLoadCounter = 0x19BAFCF79D0; // Unknown = 
    inline constexpr uintptr_t FStringDiscoverabilityModalRadioButtonClickCounter = 0x19D86D636E8; // Unknown = 
    inline constexpr uintptr_t FStringDiscoverabilityUpsellNonPrefillDiscoverableUserIdsWhitelist = 0x19BAFCF8450; // Unknown = 
    inline constexpr uintptr_t FStringDisruptiveVoiceNudgeVariantIXPLayerName = 0x19BA5158D50; // Unknown = 
    inline constexpr uintptr_t FStringDisruptiveVoiceNudgeVariantIXPVariableName = 0x19BA5158F10; // Unknown = 
    inline constexpr uintptr_t FStringDummyAMPWizardAccessResponse = 0x19B9F182060; // Unknown = 
    inline constexpr uintptr_t FStringDummyAMPWizardActionsTakenJSON = 0x19B90113F10; // Unknown = 
    inline constexpr uintptr_t FStringEARReportMenuIXPLayer = 0x19BA6A32110; // Unknown = 
    inline constexpr uintptr_t FStringEditProfileExperimentKey = 0x19B90643250; // Unknown = 
    inline constexpr uintptr_t FStringEdpPlayerFeedbackServiceRoute = 0x19B9ACB1C10; // Unknown = 
    inline constexpr uintptr_t FStringEligibleForFacialAgeEstimationAmpFeature = 0x19BA8442050; // Unknown = 
    inline constexpr uintptr_t FStringEligibleToAgeVerifyAmpFeature = 0x19BA8448990; // Unknown = 
    inline constexpr uintptr_t FStringEmoteUtilityFallbackKeyframeSequenceAssetId = 0x19D8952B550; // Unknown = 
    inline constexpr uintptr_t FStringExitModalIXPLayer = 0x19BACE9D210; // Unknown = 
    inline constexpr uintptr_t FStringExpChatChatWithTFAmpFeatureName = 0x19BBC387BD0; // Unknown = 
    inline constexpr uintptr_t FStringExpChatChatWithTFAmpNameSpace = 0x19BBC385350; // Unknown = 
    inline constexpr uintptr_t FStringExpChatCrossAgeChatActivityIXPLayerName = 0x19BA74A4A90; // Unknown = 
    inline constexpr uintptr_t FStringExpChatCrossAgeChatActivityIXPLayerValue = 0x19BA74A4D90; // Unknown = 
    inline constexpr uintptr_t FStringExpChatDictationIXPLayerName = 0x19BABBD2750; // Unknown = 
    inline constexpr uintptr_t FStringExpChatFOMOUpsellIXPLayerName = 0x19BA74A4550; // Unknown = 
    inline constexpr uintptr_t FStringExpChatFOMOUpsellIXPLayerValue = 0x19BA74A4750; // Unknown = 
    inline constexpr uintptr_t FStringExpChatLocalChatEnabledMessageExperimentLayer = 0x19B8FDEBE90; // Unknown = 
    inline constexpr uintptr_t FStringExpChatLocalChatEnabledMessageForcedKey = 0x19B8FDEC2D0; // Unknown = 
    inline constexpr uintptr_t FStringExpChatLocalChatEnabledMessageVariable = 0x19BAED53CC8; // Unknown = 
    inline constexpr uintptr_t FStringExpChatNewSystemMessagesExperimentLayer = 0x19B8FDECA10; // Unknown = 
    inline constexpr uintptr_t FStringExpChatNewSystemMessagesVariant = 0x19B8FDEC650; // Unknown = 
    inline constexpr uintptr_t FStringExpChatPresetAutocompleteIxpLayer = 0x19BABBD2CD0; // Unknown = 
    inline constexpr uintptr_t FStringExpChatPresetChatBadgeFTUXExperimentLayer = 0x19B8FDEC550; // Unknown = 
    inline constexpr uintptr_t FStringExpChatPresetChatBadgeFTUXVariable = 0x19B8FDEC710; // Unknown = 
    inline constexpr uintptr_t FStringExpChatPresetChatIXPLayerName = 0x19BABBD2350; // Unknown = 
    inline constexpr uintptr_t FStringExpChatRewriteInlineIxpLayer = 0x19BA5153650; // Unknown = 
    inline constexpr uintptr_t FStringExpChatSummaryPrefixText = 0x19BA679A4D0; // Unknown = 
    inline constexpr uintptr_t FStringExperienceDetailsLayer = 0x19B8C304290; // Unknown = 
    inline constexpr uintptr_t FStringExperienceMenuGamepadExposureLayer = 0x19BA3BB47D0; // Unknown = 
    inline constexpr uintptr_t FStringExperienceReactDeferredScheduler_LayerName = 0x19B9ACB5210; // Unknown = 
    inline constexpr uintptr_t FStringFAEUpsellDeviceNamePipeDenyList = 0x19B8FDEF590; // Unknown = 
    inline constexpr uintptr_t FStringFAEUpsellSystemVersionPipeDenyList = 0x19BAC879DD0; // Unknown = 
    inline constexpr uintptr_t FStringFRRToastPositionVariantKey = 0x19BA67207D0; // Unknown = 
    inline constexpr uintptr_t FStringFStringBlackbirdWebviewHeaderName = 0x19BC257AAA0; // Unknown = 
    inline constexpr uintptr_t FStringFStringEditProfileToAvatarLayerName = 0x19B906434D0; // Unknown = 
    inline constexpr uintptr_t FStringFStringLuckyRecommendationExpLayer = 0x19B8FDEE890; // Unknown = 
    inline constexpr uintptr_t FStringFStringPartyPageCarouselExpLayer = 0x19B8FDEE210; // Unknown = 
    inline constexpr uintptr_t FStringFStringQueueExpLayer = 0x19B8FDEC8D0; // Unknown = 
    inline constexpr uintptr_t FStringFStringSquadRegroupExpLayer = 0x19B8FDEEE90; // Unknown = 
    inline constexpr uintptr_t FStringFStringTimeoutLoadingLocalPlayerInBackgroundDM = 0x19BACFD84D0; // Unknown = 
    inline constexpr uintptr_t FStringFailedFindContactsCounter = 0x19BAFCF6010; // Unknown = 
    inline constexpr uintptr_t FStringFailedFormatContactsFromDeviceCounter = 0x19BAFCFC310; // Unknown = 
    inline constexpr uintptr_t FStringFailedGetContactEntitiesCounter = 0x19BAFCF01D0; // Unknown = 
    inline constexpr uintptr_t FStringFailedGetContactsFromDeviceCounter = 0x19BAFB23D50; // Unknown = 
    inline constexpr uintptr_t FStringFailedUploadContactsFromDeviceCounter = 0x19BAFCFEFD0; // Unknown = 
    inline constexpr uintptr_t FStringFindFriendsButtonClickedCounter = 0x19BAFCFDED0; // Unknown = 
    inline constexpr uintptr_t FStringFlyoutIxpLayer = 0x19BA461C190; // Unknown = 
    inline constexpr uintptr_t FStringFlyoutIxpVariantKey = 0x19BA4619710; // Unknown = 
    inline constexpr uintptr_t FStringFlyoutLearnPlaceURI = 0x19D7C7CBC90; // Unknown = 
    inline constexpr uintptr_t FStringFlyoutMomentsPlaceURI = 0x19D7C7CE3D0; // Unknown = 
    inline constexpr uintptr_t FStringFoundationImagesWhitelistedIconAssets = 0x19B9CB7C990; // Unknown = 
    inline constexpr uintptr_t FStringFriendRequestModalIxpLayer = 0x19BA6078290; // Unknown = 
    inline constexpr uintptr_t FStringFriendRequestNicknamesCanSendNicknames = 0x19B90115D90; // Unknown = 
    inline constexpr uintptr_t FStringFriendRequestNicknamesSocialFriendsLayer = 0x19B90115E10; // Unknown = 
    inline constexpr uintptr_t FStringFriendsCarouselLoadedWithUsers = 0x19B90268450; // Unknown = 
    inline constexpr uintptr_t FStringFriendsCarouselRequestFriendship = 0x19B90268AD0; // Unknown = 
    inline constexpr uintptr_t FStringFriendsCarouselRevokeFriendRequest = 0x19B90268F50; // Unknown = 
    inline constexpr uintptr_t FStringFriendsCarouselUILoadingTimeStats = 0x19B90267CD0; // Unknown = 
    inline constexpr uintptr_t FStringFriendsCarouselUserPressed = 0x19B90268710; // Unknown = 
    inline constexpr uintptr_t FStringFriendsChatTabName = 0x19BA553F9D0; // Unknown = 
    inline constexpr uintptr_t FStringFriendshipNotifsUseSendrLayerName = 0x19BA672F5D0; // Unknown = 
    inline constexpr uintptr_t FStringFriendshipNotifsUseSendrLayerValue = 0x19BACFEBC10; // Unknown = 
    inline constexpr uintptr_t FStringGenericAbuseReportingSubmittedAbuseTypeStat = 0x19BA3A55350; // Unknown = 
    inline constexpr uintptr_t FStringGenericAbuseReportingTimeSpentStat = 0x19BA3A5CC90; // Unknown = 
    inline constexpr uintptr_t FStringGenericReportLink = 0x19BA3A5D9D0; // Unknown = 
    inline constexpr uintptr_t FStringGetFStringIXPLayerMobileUpsell = 0x19BAC833950; // Unknown = 
    inline constexpr uintptr_t FStringHelpPageIXPLayer = 0x19BBF250A10; // Unknown = 
    inline constexpr uintptr_t FStringHelpPageIxpLayer = 0x19BAC8734D0; // Unknown = 
    inline constexpr uintptr_t FStringHighlightModePreciseSelectionForceVariant = 0x19B8C30D9D0; // Unknown = 
    inline constexpr uintptr_t FStringHighlightModePreciseSelectionIXPField = 0x19B8C30D710; // Unknown = 
    inline constexpr uintptr_t FStringHomePageNavigationViewAddFriends = 0x19B90268110; // Unknown = 
    inline constexpr uintptr_t FStringHomePageNavigationViewAllFriends = 0x19B902688D0; // Unknown = 
    inline constexpr uintptr_t FStringIOSPhoneVerificationLayer = 0x19BA6A33AC8; // Unknown = 
    inline constexpr uintptr_t FStringIXPLayerMobileUpsell = 0x19D84DAE150; // Unknown = 
    inline constexpr uintptr_t FStringImmersiveBrandedAdsLearnMoreUrl = 0x19BA8A084D0; // Unknown = 
    inline constexpr uintptr_t FStringInExpChatRewriteDeviceNameBlackList = 0x19B9CB76C90; // Unknown = 
    inline constexpr uintptr_t FStringInExpChatRewriteLabelKey = 0x19BA5156A10; // Unknown = 
    inline constexpr uintptr_t FStringInExpChatRewriteOsVersionBlackList = 0x19B9CB73BD0; // Unknown = 
    inline constexpr uintptr_t FStringInExpChatRewriteReasonKey = 0x19BA5151FD0; // Unknown = 
    inline constexpr uintptr_t FStringInExperienceMenuIXPLayer = 0x19BACE9C150; // Unknown = 
    inline constexpr uintptr_t FStringInExperienceMenuIXPVar = 0x19BACE9D3D0; // Unknown = 
    inline constexpr uintptr_t FStringInExperienceNotificationsLayer = 0x19BA553EF10; // Unknown = 
    inline constexpr uintptr_t FStringInExperienceShopTooltipStorageKey = 0x19BABC1C990; // Unknown = 
    inline constexpr uintptr_t FStringInGameAssetReportingSubmittedAbuseTypeStat = 0x19BBB7FE9D0; // Unknown = 
    inline constexpr uintptr_t FStringInGameAssetReportingTimeSpentStat = 0x19BBB7FE690; // Unknown = 
    inline constexpr uintptr_t FStringInGameLargerRobuxUpsellIXPLayerParam = 0x19D85DCD810; // Unknown = 
    inline constexpr uintptr_t FStringInGameRobuxUpsellLargerIxpLayer = 0x19BA6A30348; // Unknown = 
    inline constexpr uintptr_t FStringIncompatibleAccountsSupportLink = 0x19BBC1C7610; // Unknown = 
    inline constexpr uintptr_t FStringInspectAndBuyFeature = 0x19B9F0A0590; // Unknown = 
    inline constexpr uintptr_t FStringInternationalNamesIXPExperimentDefinition = 0x19B90643150; // Unknown = 
    inline constexpr uintptr_t FStringInternationalNamesIXPLayer = 0x19B90642B10; // Unknown = 
    inline constexpr uintptr_t FStringIsUserInTcEligibleCountryAmpFeature = 0x19BACFD5B90; // Unknown = 
    inline constexpr uintptr_t FStringIsVerified18PlusAmpFeature = 0x19BA84434D0; // Unknown = 
    inline constexpr uintptr_t FStringLivePreviewPlaceId = 0x19BA8A0EE10; // Unknown = 
    inline constexpr uintptr_t FStringLoginInfoOverflowedCounter = 0x19B90642110; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppAdPreferencesUrl = 0x19BA59B1050; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppAdsPlayWithRewardBetaAndroidLayer = 0x19BA3BB0510; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppAuthenticationStylingLayer = 0x19BA3BB6650; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppBacktraceLogLevel = 0x19B8F90B350; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppBadgeDetailsIxpLayer = 0x19B88C22410; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppBadgesSeeAllIxpLayer = 0x19B88C22110; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppConsoleExperienceMenuLayer = 0x19B9AF10030; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppDevStoreSeeAllSduiIxpLayer = 0x19BC0545CD0; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppEdpAudioManufacturerDenyList = 0x19B88C2DF90; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppEdpFaeIxpLayer = 0x19B9029B690; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppEdpVideoDevicePipeDenyList = 0x19BBC38B810; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppEdpVideoManufacturerPipeDenyList = 0x19BBC3898D0; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppEphemeralCounterPrefix = 0x19B85789450; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppExperienceMenuLayer = 0x19BA6A3D710; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppGameCarouselAmpUpsellActionAccessResponses = 0x19B90269950; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppGameTileMigrationExpLayer = 0x19BBC38AE10; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppGameTileVideoDevicePipeDenyList = 0x19BBE913850; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppGameTileVideoManufacturerPipeDenyList = 0x19BBE912D90; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppIECVRLayerName = 0x19BA3BB2B10; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppIECVRVariantKey = 0x19BA3BB0290; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppIosPasswordSavingLayer = 0x19BA3BB28D0; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppLandingLayer = 0x19BA3BBB610; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppLaunchTrackerMilestones = 0x19BC27AE840; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppNewSlpEndpointIxpLayer = 0x19B9029E7D0; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppOmniRecommendationsTopicIdAndNumberOfItemsToCache = 0x19BA3A71890; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppPlayButtonAgeCheckAmpFeatureName = 0x19B9F18A9C8; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppPlayButtonAgeCheckAmpNameSpace = 0x19B9F18E688; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppPlayWithRewardBetaIxpTreatmentValue = 0x19B90640690; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppPlayWithRewardBetaIxpVariantKey = 0x19B90640490; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppPlayWithRewardBetaUniverses = 0x19B90640250; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppRelativeGuiIxpLayer = 0x19B94811910; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppSduiEdpIxpLayer = 0x19B88C226D0; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppSduiEventDetailsIxpLayer = 0x19B88C23A90; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppSearchTopPageIxpLayer = 0x19B88C23ED0; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppSentryDsn = 0x19B8F90B3D0; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppSignupLayer = 0x19BA3BB5A50; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppSlpIxpLayer = 0x19B948106D0; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppSocialAddFriendsPageLayer = 0x19BA6A3ED10; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppSocialConnectTabLayer = 0x19BA6A39D50; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppSocialFriendsLandingLayer = 0x19BA6A34D10; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppSocialFriendsLayer = 0x19BA6A38948; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppSocialProfileLayer = 0x19BA6A30590; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppSocialUserSearchResultsPageLayer = 0x19BA6A354D0; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppSortsWithDividers = 0x19BC054CF50; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppUpsellMaturityRatingToSettingMapping = 0x19BA6791190; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppVerticalEfficiencyExpLayer = 0x19BA5BD9750; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppVngAppIxpUserLayer = 0x19B94811FD0; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppVngIxpDismissable = 0x19B948120D0; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppVngIxpEnabled = 0x19B94812150; // Unknown = 
    inline constexpr uintptr_t FStringLuaAppVngIxpFrequency = 0x19B94811AD0; // Unknown = 
    inline constexpr uintptr_t FStringLuaDesktopToastNotificationLayer = 0x19B8C303290; // Unknown = 
    inline constexpr uintptr_t FStringLuaEnabledSduiTreatmentTypes = 0x19B88C40AD0; // Unknown = 
    inline constexpr uintptr_t FStringLuaErrorByPlatformCounter = 0x19B8F909490; // Unknown = 
    inline constexpr uintptr_t FStringLuaGameInviteMenuLayer = 0x19B8C303CD0; // Unknown = 
    inline constexpr uintptr_t FStringLuaLoginRevampIxpLayer = 0x19B945A0750; // Unknown = 
    inline constexpr uintptr_t FStringLuaMultiPageSignupIxpLayer = 0x19B945A05D0; // Unknown = 
    inline constexpr uintptr_t FStringLuaShareGameLuaChatInputBarEntryCounter = 0x19BB6BB0C50; // Unknown = 
    inline constexpr uintptr_t FStringLuaShareGameLuaChatInputBarInviteCounter = 0x19BB6BB32D0; // Unknown = 
    inline constexpr uintptr_t FStringLuaShareGameLuaGameDetailsEntryCounter = 0x19BB6BB1AD0; // Unknown = 
    inline constexpr uintptr_t FStringLuaShareGameLuaGameDetailsInviteCounter = 0x19BB6BB1550; // Unknown = 
    inline constexpr uintptr_t FStringLuaShareGameRoactChatInputBarEntryCounter = 0x19D86D68DC8; // Unknown = 
    inline constexpr uintptr_t FStringLuaShareGameRoactChatInputBarInviteCounter = 0x19D86D66DE8; // Unknown = 
    inline constexpr uintptr_t FStringLuaUniversalAppGameInviteMenuLayer = 0x19B9F182520; // Unknown = 
    inline constexpr uintptr_t FStringLuckyRecommendationEnableVariant = 0x19B8FDEDF50; // Unknown = 
    inline constexpr uintptr_t FStringLuckyRecommendationExpLayer = 0x19BAF80AB30; // Unknown = 
    inline constexpr uintptr_t FStringMemoryShellHost = 0x19B8F742010; // Unknown = 
    inline constexpr uintptr_t FStringMicrophoneDevicePermissionsLoggingEventName = 0x19BA4E9E4D0; // Unknown = 
    inline constexpr uintptr_t FStringMobilePopularItemBadgingLayer = 0x19BA4004FE0; // Unknown = 
    inline constexpr uintptr_t FStringMobileSoundAndHapticsLayer = 0x19BA3BBEC50; // Unknown = 
    inline constexpr uintptr_t FStringMomentsEmojiFallbackCatalogJSON = 0x19BA8025910; // Unknown = 
    inline constexpr uintptr_t FStringMomentsFeedWatchPageRouteName = 0x19BAFB60610; // Unknown = 
    inline constexpr uintptr_t FStringMomentsUploadUniverseId = 0x19D86F06250; // Unknown = 
    inline constexpr uintptr_t FStringMrRouterEnvName = 0x19BA3A74350; // Unknown = 
    inline constexpr uintptr_t FStringMyStatsExperienceStatsBaseUrl = 0x19BAD28A610; // Unknown = 
    inline constexpr uintptr_t FStringMyStatsExperienceStatsPath = 0x19BAD288BD0; // Unknown = 
    inline constexpr uintptr_t FStringNewConversationCreatedCounter = 0x19BA6074690; // Unknown = 
    inline constexpr uintptr_t FStringNewFriendRequestsBadgeLayer = 0x19B8C2EAB10; // Unknown = 
    inline constexpr uintptr_t FStringNewInGameMenuForcedUserIds = 0x19BA36661D0; // Unknown = 
    inline constexpr uintptr_t FStringNotificationsOptInImprovementsFieldName = 0x19B8C3043D0; // Unknown = 
    inline constexpr uintptr_t FStringNotificationsStreamNotificationUXLayer = 0x19B8C303650; // Unknown = 
    inline constexpr uintptr_t FStringOffPlatformIXPName = 0x19BAFCF0790; // Unknown = 
    inline constexpr uintptr_t FStringOldAllFriendsCarouselLoadingTimeDoneStats = 0x19B90267750; // Unknown = 
    inline constexpr uintptr_t FStringOldAllFriendsCarouselLoadingTimeFailedStats = 0x19B90267690; // Unknown = 
    inline constexpr uintptr_t FStringOnlineFriendsCarouselLoadingTimeDoneStats = 0x19B90267AD0; // Unknown = 
    inline constexpr uintptr_t FStringOnlineFriendsCarouselLoadingTimeFailedStats = 0x19B90267710; // Unknown = 
    inline constexpr uintptr_t FStringOnlineFriendsRefetchOnFriendshipUpdateCounter = 0x19B902681D0; // Unknown = 
    inline constexpr uintptr_t FStringOnlineFriendsRefetchOnPresenceUpdateCounter = 0x19B90266490; // Unknown = 
    inline constexpr uintptr_t FStringPCGDKFilteredNotificationTypes = 0x19B8C303D10; // Unknown = 
    inline constexpr uintptr_t FStringPYMKCarouselGenericTileClicked = 0x19B8FC3B310; // Unknown = 
    inline constexpr uintptr_t FStringPYMKCarouselLoadedWithUsers = 0x19B8FC3A4D0; // Unknown = 
    inline constexpr uintptr_t FStringPYMKCarouselRequestFriendship = 0x19B8FC3B1D0; // Unknown = 
    inline constexpr uintptr_t FStringPYMKCarouselUserPressed = 0x19B8FC3B110; // Unknown = 
    inline constexpr uintptr_t FStringPaginatedCarouselExperimentLayer = 0x19B8C2EAF10; // Unknown = 
    inline constexpr uintptr_t FStringParentLinkAmpNameSpace = 0x19BA59B3590; // Unknown = 
    inline constexpr uintptr_t FStringPartyPageCarouselExpLayer = 0x19B82C11210; // Unknown = 
    inline constexpr uintptr_t FStringPartyPageCarouselVariant = 0x19B8FDEE590; // Unknown = 
    inline constexpr uintptr_t FStringPartyVoiceEligibilityAllowList = 0x19BA6727590; // Unknown = 
    inline constexpr uintptr_t FStringPerfInsightsIXPLayer = 0x19B90290090; // Unknown = 
    inline constexpr uintptr_t FStringPhoneVerificationCloseCounter = 0x19BAFCF9A90; // Unknown = 
    inline constexpr uintptr_t FStringPhoneVerificationWebviewCounter = 0x19BAFCFBC10; // Unknown = 
    inline constexpr uintptr_t FStringPioneerLaunchPlaceId = 0x19B9ACBFDD0; // Unknown = 
    inline constexpr uintptr_t FStringPlatformEventUrl = 0x19BA59B4790; // Unknown = 
    inline constexpr uintptr_t FStringPlatformLeaderboardUnrankedLabel = 0x19BACE9B4D0; // Unknown = 
    inline constexpr uintptr_t FStringPlatformLeaderboardsExposure2Layer = 0x19BACE994D0; // Unknown = 
    inline constexpr uintptr_t FStringPlayerContextualMenuVendorImagePath = 0x19B859CA190; // Unknown = 
    inline constexpr uintptr_t FStringPlayerListIXPLayer = 0x19BACE98090; // Unknown = 
    inline constexpr uintptr_t FStringPlayerListOverrideType = 0x19BAD286110; // Unknown = 
    inline constexpr uintptr_t FStringPopularFillIconLocation = 0x19BAC832190; // Unknown = 
    inline constexpr uintptr_t FStringPresencePropagationDelayMetricName = 0x19B90290750; // Unknown = 
    inline constexpr uintptr_t FStringPreviousFriendRequestsCountEngineFeature = 0x19BACFD0030; // Unknown = 
    inline constexpr uintptr_t FStringPreviousFriendRequestsCountEngineFeature2 = 0x19BACFD7A50; // Unknown = 
    inline constexpr uintptr_t FStringPriceChangedSubscriptionMembershipCheckProductTypes = 0x19D85DC7910; // Unknown = 
    inline constexpr uintptr_t FStringPrivacyPolicyLink = 0x19B90111590; // Unknown = 
    inline constexpr uintptr_t FStringProfileQRCodeFriendRequestAlertsExperimentKey = 0x19B9011A390; // Unknown = 
    inline constexpr uintptr_t FStringProfileQRCodeFriendRequestAlertsLayer = 0x19B9011A5D0; // Unknown = 
    inline constexpr uintptr_t FStringProfileQRCodeScannerOpened = 0x19BAFCF30D0; // Unknown = 
    inline constexpr uintptr_t FStringProfileQRCodeScannerTooltipShown = 0x19BAFCF3E50; // Unknown = 
    inline constexpr uintptr_t FStringProfileQRPageFriendRequestBannerAccepted = 0x19BAFCF6650; // Unknown = 
    inline constexpr uintptr_t FStringProfileQRPageFriendRequestBannerDismissed = 0x19BAFCF87D0; // Unknown = 
    inline constexpr uintptr_t FStringProfileQRPageFriendRequestBannerShown = 0x19BAFCF6AD0; // Unknown = 
    inline constexpr uintptr_t FStringProfileQRPageLoad = 0x19BAFCF4F90; // Unknown = 
    inline constexpr uintptr_t FStringProfileQRPageLoadFailed = 0x19BAFCF5150; // Unknown = 
    inline constexpr uintptr_t FStringPushUpsellChatVariantName = 0x19B9F18F410; // Unknown = 
    inline constexpr uintptr_t FStringPushUpsellOnFirstTimeVariantName = 0x19B9F18A1A0; // Unknown = 
    inline constexpr uintptr_t FStringPushUpsellVariantName = 0x19B8C303B50; // Unknown = 
    inline constexpr uintptr_t FStringQueueEnableAutoJoinNewServerVariant = 0x19B8FDEB4D0; // Unknown = 
    inline constexpr uintptr_t FStringQueueEnableJoinNewServerVariant = 0x19B8FDED1D0; // Unknown = 
    inline constexpr uintptr_t FStringQueueExpLayer = 0x19BAF80FE50; // Unknown = 
    inline constexpr uintptr_t FStringRMDefinition = 0x19BA6A3CD90; // Unknown = 
    inline constexpr uintptr_t FStringRccInExperienceNameEnabledAllowList = 0x19B9FDD0B08; // Unknown = 
    inline constexpr uintptr_t FStringReactSchedulingContext = 0x19B9ACB1D50; // Unknown = 
    inline constexpr uintptr_t FStringReactSchedulingPercentiles = 0x19BA366ED50; // Unknown = 
    inline constexpr uintptr_t FStringRealNamesInDisplayNamesExperimentDefinition = 0x19B90642210; // Unknown = 
    inline constexpr uintptr_t FStringRealNamesInDisplayNamesIXP_v1 = 0x19B90642450; // Unknown = 
    inline constexpr uintptr_t FStringReferralRewardsTermsURL = 0x19B88BE0030; // Unknown = 
    inline constexpr uintptr_t FStringReportAnalyticsAbandonedSubmissionTimeStat = 0x19BBBE5CF90; // Unknown = 
    inline constexpr uintptr_t FStringReportAnalyticsButtonActivated = 0x19BBBE54250; // Unknown = 
    inline constexpr uintptr_t FStringReportAnalyticsFieldChanged = 0x19BBBE5BD10; // Unknown = 
    inline constexpr uintptr_t FStringReportAnalyticsFormAbandoned = 0x19BBBE51150; // Unknown = 
    inline constexpr uintptr_t FStringReportAnalyticsFormSubmitted = 0x19BBBE51690; // Unknown = 
    inline constexpr uintptr_t FStringReportAnalyticsInGameAbuseReport = 0x19BB7F44E90; // Unknown = 
    inline constexpr uintptr_t FStringReportAnalyticsLegacyMenuContext = 0x19BBBE52DD0; // Unknown = 
    inline constexpr uintptr_t FStringReportAnalyticsLegacySentPageContext = 0x19BBBE52CD0; // Unknown = 
    inline constexpr uintptr_t FStringReportAnalyticsNewMenuContext = 0x19BBBE5D6D0; // Unknown = 
    inline constexpr uintptr_t FStringReportAnalyticsSubmittedMethodOfAbuseStat = 0x19BBBE57D90; // Unknown = 
    inline constexpr uintptr_t FStringReportAnalyticsSuccessfulSubmissionTimeStat = 0x19BBBE52810; // Unknown = 
    inline constexpr uintptr_t FStringReportAnythingAnnotationIXPLayerName = 0x19B8C30B450; // Unknown = 
    inline constexpr uintptr_t FStringReportMenuIXPLayer = 0x19BA6A36B90; // Unknown = 
    inline constexpr uintptr_t FStringReportingIXPLayer = 0x19BA6A36390; // Unknown = 
    inline constexpr uintptr_t FStringRoactChatFetchedOlderConversationCounter = 0x19B9026B290; // Unknown = 
    inline constexpr uintptr_t FStringRoactChatNavigationChatConversationProfileCounter = 0x19D86D61DE8; // Unknown = 
    inline constexpr uintptr_t FStringRoactChatNavigationChatDetailsProfileCounter = 0x19D86D62F68; // Unknown = 
    inline constexpr uintptr_t FStringRoactChatUserLoadedCounter = 0x19BAE70ACE8; // Unknown = 
    inline constexpr uintptr_t FStringRobloxPlusAmpFeatureName = 0x19B8FC33A50; // Unknown = 
    inline constexpr uintptr_t FStringRobloxPlusAmpNamespace = 0x19B8FC33AD0; // Unknown = 
    inline constexpr uintptr_t FStringRobloxSubscriptionTermsOfUseLink = 0x19B9F188B50; // Unknown = 
    inline constexpr uintptr_t FStringRootNavigatorInitialRouteName = 0x19B90641A90; // Unknown = 
    inline constexpr uintptr_t FStringScheduledSquadsListChatLandingScreenEntrypointVariant = 0x19B8FDED9D0; // Unknown = 
    inline constexpr uintptr_t FStringScheduledSquadsListExpLayer = 0x19B8FDED8D0; // Unknown = 
    inline constexpr uintptr_t FStringSduiEagerProcessCollectionIds = 0x19B9011F490; // Unknown = 
    inline constexpr uintptr_t FStringSduiForceImageQualityLevel = 0x19B8FC32D90; // Unknown = 
    inline constexpr uintptr_t FStringSduiForcePerfLevel = 0x19B8FC32F90; // Unknown = 
    inline constexpr uintptr_t FStringSduiNonGameTopicIds = 0x19B9011F590; // Unknown = 
    inline constexpr uintptr_t FStringSelectInSceneIXPField = 0x19BA6A33A10; // Unknown = 
    inline constexpr uintptr_t FStringSelectInSceneReportMenuOverrideUserIds = 0x19BB7F400D0; // Unknown = 
    inline constexpr uintptr_t FStringSelfProfileView = 0x19B8C2E9710; // Unknown = 
    inline constexpr uintptr_t FStringShareCaptureGenerateLinkFailed = 0x19B9298EA78; // Unknown = 
    inline constexpr uintptr_t FStringShareCapturePromptAccepted = 0x19BAC87C550; // Unknown = 
    inline constexpr uintptr_t FStringShareCapturePromptRejected = 0x19D8516A9E0; // Unknown = 
    inline constexpr uintptr_t FStringShowAddTrustedFriendsHeaderTextAmpFeature = 0x19BA8440F50; // Unknown = 
    inline constexpr uintptr_t FStringSocialCaptureIXPLayer = 0x19B8C2EA510; // Unknown = 
    inline constexpr uintptr_t FStringSocialCaptureTakenIXPLayer = 0x19B8C2EA5D0; // Unknown = 
    inline constexpr uintptr_t FStringSocialCarouselTreatment = 0x19BACFD0FD0; // Unknown = 
    inline constexpr uintptr_t FStringSocialCarouselVendorImagePath = 0x19B8FA1CDD0; // Unknown = 
    inline constexpr uintptr_t FStringSocialNavigationHomePageAddFriends = 0x19BB6B29F30; // Unknown = 
    inline constexpr uintptr_t FStringSocialNavigationHomePageCarouselLuaProfile = 0x19BB6BB8BD0; // Unknown = 
    inline constexpr uintptr_t FStringSocialNavigationHomePageFriendsLanding = 0x19BB6BB8D90; // Unknown = 
    inline constexpr uintptr_t FStringSocialNavigationMorePageFriendsLanding = 0x19BB6BB9190; // Unknown = 
    inline constexpr uintptr_t FStringSocialNetworksEditProfileIXPLayer = 0x19B90643AD0; // Unknown = 
    inline constexpr uintptr_t FStringSocialOnboardingExperimentLayer = 0x19B8C2EAD50; // Unknown = 
    inline constexpr uintptr_t FStringSocialProfileCurrentlyWearingClickThroughLayer = 0x19BB7F42BD0; // Unknown = 
    inline constexpr uintptr_t FStringSocialViewFriendSortInGameFriendsLayer = 0x19B8FA1E550; // Unknown = 
    inline constexpr uintptr_t FStringSortInvitesByScoreExperimentLayer = 0x19BADF93950; // Unknown = 
    inline constexpr uintptr_t FStringSpatialRobloxUIIXPLayerName = 0x19B9FDD4F88; // Unknown = 
    inline constexpr uintptr_t FStringSpatialRobloxUIIXPSpatialUIVariantValue = 0x19B9FDD5008; // Unknown = 
    inline constexpr uintptr_t FStringSpatialRobloxUIIXPUITypeVariableName = 0x19B9FDD5088; // Unknown = 
    inline constexpr uintptr_t FStringSquadCoordinationExperienceJoinExperimentLayer = 0x19B8FDEDF90; // Unknown = 
    inline constexpr uintptr_t FStringSquadCoordinationUiExperimentLayer = 0x19B8FDED550; // Unknown = 
    inline constexpr uintptr_t FStringSquadEnablePartyCoordinationUiVariant = 0x19B8FDEC1D0; // Unknown = 
    inline constexpr uintptr_t FStringSquadEnablePartyQuickStartVariant = 0x19B8FDEE950; // Unknown = 
    inline constexpr uintptr_t FStringSquadEnableRegroupVariant = 0x19B8FDEEFD0; // Unknown = 
    inline constexpr uintptr_t FStringSquadQuickStartExperimentLayer = 0x19B8FDEE790; // Unknown = 
    inline constexpr uintptr_t FStringSquadRegroupExpLayer = 0x19BAF804690; // Unknown = 
    inline constexpr uintptr_t FStringSquadsUnifyCoplayExpLayer = 0x19B8FDEDE10; // Unknown = 
    inline constexpr uintptr_t FStringSquadsUnifyCoplayMultiInvitePartyCreationVariant = 0x19B8FDEE390; // Unknown = 
    inline constexpr uintptr_t FStringSquadsUnifyCoplayOneOnOnePartyCreationVariant = 0x19B8FDEE290; // Unknown = 
    inline constexpr uintptr_t FStringStreamNotificationUXDropdownVariant = 0x19B8FA1EF10; // Unknown = 
    inline constexpr uintptr_t FStringStreamNotificationUXExposureLayer = 0x19B8FA1F910; // Unknown = 
    inline constexpr uintptr_t FStringSupportedAppLaunchMilestonesForReactProfilerLogger = 0x19BA6098690; // Unknown = 
    inline constexpr uintptr_t FStringSuppressMutedErrorKeys = 0x19BA3BB6610; // Unknown = 
    inline constexpr uintptr_t FStringTTIMetricsTableName = 0x19B8F741750; // Unknown = 
    inline constexpr uintptr_t FStringTakeItDownReportLink = 0x19BA3A5C8D0; // Unknown = 
    inline constexpr uintptr_t FStringTextureTranscode7FallbackVersionTM1 = 0x19B92244EE0; // Unknown = 
    inline constexpr uintptr_t FStringThrottleParticipantsUpdateIXPLayerValue = 0x19B8FDEB310; // Unknown = 
    inline constexpr uintptr_t FStringThrottleVoiceParticipantsUpdateLayerName = 0x19B8FDEA8D0; // Unknown = 
    inline constexpr uintptr_t FStringThrottleVoiceParticipantsUpdateLayerValue = 0x19B8FDEAAD0; // Unknown = 
    inline constexpr uintptr_t FStringTiltLoadingScreenPreLogoText = 0x19B9AF12B10; // Unknown = 
    inline constexpr uintptr_t FStringTimeoutLoadingLocalPlayerInBackgroundDM = 0x19B82B7F410; // Unknown = 
    inline constexpr uintptr_t FStringToastNotificationEventLoggingLevel = 0x19BA6070AD0; // Unknown = 
    inline constexpr uintptr_t FStringTopSongsSortExploreApiPageType = 0x19B88C4ED10; // Unknown = 
    inline constexpr uintptr_t FStringTriggerAgeCheckUpsellIncludingVPCAmpFeature = 0x19BA844C710; // Unknown = 
    inline constexpr uintptr_t FStringTutorialUpsellIXPLayerName = 0x19B90291850; // Unknown = 
    inline constexpr uintptr_t FStringUXForCameraPerformanceIXPLayerName = 0x19B9AF10850; // Unknown = 
    inline constexpr uintptr_t FStringUnfilteredMessageDarkHexColor = 0x19BA802A890; // Unknown = 
    inline constexpr uintptr_t FStringUnfilteredMessageLightHexColor = 0x19BA80236D0; // Unknown = 
    inline constexpr uintptr_t FStringUnfilteredMessagePressedDarkHexColor = 0x19BA802EED0; // Unknown = 
    inline constexpr uintptr_t FStringUnfilteredMessagePressedLightHexColor = 0x19BA8020AD0; // Unknown = 
    inline constexpr uintptr_t FStringUnfilteredThreadsLearnMoreUrl = 0x19B8FA15E90; // Unknown = 
    inline constexpr uintptr_t FStringUniversalAppCameraIXPLayer = 0x19B90644F90; // Unknown = 
    inline constexpr uintptr_t FStringUniversesExposedToPeopleCardsTooltipKey = 0x19BB7F46610; // Unknown = 
    inline constexpr uintptr_t FStringUserProfileStoreMaxLoggingLevel = 0x19BA515EFD0; // Unknown = 
    inline constexpr uintptr_t FStringUserProfilesRequestBegin = 0x19BA51566D0; // Unknown = 
    inline constexpr uintptr_t FStringUserProfilesRequestFail = 0x19BA515D0D0; // Unknown = 
    inline constexpr uintptr_t FStringUserProfilesRequestFailAfterRetry = 0x19BA515F150; // Unknown = 
    inline constexpr uintptr_t FStringUserProfilesRequestFailAfterRetryDuration = 0x19BA515DA10; // Unknown = 
    inline constexpr uintptr_t FStringUserProfilesRequestFailDuration = 0x19BA5157ED0; // Unknown = 
    inline constexpr uintptr_t FStringUserProfilesRequestSuccess = 0x19BA5152450; // Unknown = 
    inline constexpr uintptr_t FStringUserProfilesRequestSuccessAfterRetry = 0x19BA51589D0; // Unknown = 
    inline constexpr uintptr_t FStringUserProfilesRequestSuccessAfterRetryDuration = 0x19BBB7FDC30; // Unknown = 
    inline constexpr uintptr_t FStringUserProfilesRequestSuccessDuration = 0x19BA515C6D0; // Unknown = 
    inline constexpr uintptr_t FStringUserProfilesUnmountEarly = 0x19BA51563D0; // Unknown = 
    inline constexpr uintptr_t FStringUserSearchLoadingTimeDoneStats = 0x19B9011E550; // Unknown = 
    inline constexpr uintptr_t FStringUserSearchLoadingTimeFailedStats = 0x19B9011E890; // Unknown = 
    inline constexpr uintptr_t FStringUserSearchLoadingTimeNextPageDoneStats = 0x19B9011ECD0; // Unknown = 
    inline constexpr uintptr_t FStringUserSearchLoadingTimeNextPageFailedStats = 0x19B9011EBD0; // Unknown = 
    inline constexpr uintptr_t FStringUserSearchPlayerFriendAcceptCounter = 0x19B9011E490; // Unknown = 
    inline constexpr uintptr_t FStringUserSearchPlayerFriendRequestCounter = 0x19B9011E810; // Unknown = 
    inline constexpr uintptr_t FStringUserSearchPlayerTileClickCounter = 0x19B9011E190; // Unknown = 
    inline constexpr uintptr_t FStringUserSearchPlayerTileImpressionsCounter = 0x19B9011EAD0; // Unknown = 
    inline constexpr uintptr_t FStringV1MenuLanguageSelectionFeatureForcedUserIds = 0x19B9FD8CE50; // Unknown = 
    inline constexpr uintptr_t FStringVNGDownloadNowUrl = 0x19B88C4DBD0; // Unknown = 
    inline constexpr uintptr_t FStringVNGTosUrl = 0x19B88C4B5D0; // Unknown = 
    inline constexpr uintptr_t FStringVNGWebshopUrl = 0x19B88C4A6D0; // Unknown = 
    inline constexpr uintptr_t FStringVoiceExposureIXPLayerName = 0x19B9AF10690; // Unknown = 
    inline constexpr uintptr_t FStringVoicePerformanceIXPLayerName = 0x19BBCD72F90; // Unknown = 
    inline constexpr uintptr_t FStringVoicePerformanceThrottlingIXPLayerName = 0x19B8FDEB0D0; // Unknown = 
    inline constexpr uintptr_t FStringVoiceUIImprovementsIXPLayerName = 0x19B9F185F20; // Unknown = 
    inline constexpr uintptr_t FStringVoiceUpsellLayer = 0x19B88C4E150; // Unknown = 
    inline constexpr uintptr_t FStringVoiceUpsellV2ExperimentLayerLua = 0x19BA3BBE350; // Unknown = 
    inline constexpr uintptr_t FStringVoiceUserAgencyIXPLayerName = 0x19B9AF10C10; // Unknown = 
    inline constexpr uintptr_t FStringVoiceVolumeControlsGlobalVoiceVolumeSliderIxpLayer = 0x19BA5159A90; // Unknown = 
    inline constexpr uintptr_t FStringVrAvatarPanelsDistanceOffsetOverride = 0x19B859C54D0; // Unknown = 
    inline constexpr uintptr_t FStringVrSystemBarXOffSetOverride = 0x19BA6A361D0; // Unknown = 
    inline constexpr uintptr_t FStringVrSystemBarYOffSetOverride = 0x19BA6A37A50; // Unknown = 
    inline constexpr uintptr_t FStringVrSystemBarZOffSetOverride = 0x19BA6A3EAD0; // Unknown = 
    inline constexpr uintptr_t FStringWHAM1707IXPField = 0x19B9FD8F908; // Unknown = 
    inline constexpr uintptr_t FStringWhitelistVerifiedUserId = 0x19B85788090; // Unknown = 
    inline constexpr uintptr_t FStringXboxClassicUILayer = 0x19BA3BBB5D0; // Unknown = 
    inline constexpr uintptr_t SFUClientAnalyticsInfluxReportHundredthsPercent = 0x19B8153E690; // Unknown = 
} // namespace FFlags
