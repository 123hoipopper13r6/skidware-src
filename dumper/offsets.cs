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

using System;

namespace RobloxOffsets
{
    public static class Metadata
    {
        public const string RobloxVersion = "version-f5a60436d48947d3";
    }

    public static class Accessory
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttachmentForward = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttachmentPoint = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttachmentPos = 0x2C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttachmentRight = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttachmentUp = 0xC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BackendAccoutrementState = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    // per-workspace wind/air physics
    public static class AirProperties
    {
        public const ulong AirDensity = 0x18; // air density for drag calculations
        public const ulong GlobalWind = 0x3C; // wind vector applied to unanchored parts
    }

    // animation asset reference
    public static class Animation
    {
        public const ulong AnimationId = 0xC0; // Animation Id
    }

    public static class Animator
    {
        public const ulong AnimTrackMetadata0 = 0x2F4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata1 = 0x2F8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata10 = 0x2FC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata11 = 0x300; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata12 = 0x304; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata13 = 0x308; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata14 = 0x30C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata15 = 0x310; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata2 = 0x314; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata3 = 0x318; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata4 = 0x31C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata5 = 0x320; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata6 = 0x324; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata7 = 0x328; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata8 = 0x32C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackMetadata9 = 0x330; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState0 = 0x2F4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState1 = 0x2F8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState10 = 0x2FC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState11 = 0x300; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState12 = 0x304; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState13 = 0x308; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState14 = 0x30C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState15 = 0x310; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState2 = 0x314; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState3 = 0x318; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState4 = 0x31C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState5 = 0x320; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState6 = 0x324; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState7 = 0x328; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState8 = 0x32C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackPlayState9 = 0x330; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight0 = 0x2F8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight1 = 0x314; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight10 = 0x300; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight11 = 0x304; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight12 = 0x308; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight13 = 0x30C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight14 = 0x310; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight15 = 0x90; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight2 = 0x318; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight3 = 0x31C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight4 = 0x320; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight5 = 0x324; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight6 = 0x328; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight7 = 0x32C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight8 = 0x330; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimTrackWeight9 = 0x2FC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId0 = 0x240; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId1 = 0x248; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId10 = 0x250; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId11 = 0x258; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId12 = 0x260; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId13 = 0x268; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId14 = 0x270; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId15 = 0x278; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId2 = 0x280; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId3 = 0x288; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId4 = 0x290; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId5 = 0x298; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId6 = 0x2A0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId7 = 0x2A8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId8 = 0x2B0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnimationId9 = 0x2B8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong EvaluationThrottled = 0x334; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong FacsReplicationData = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PreferLodEnabled = 0x3E4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RootMotion = 0x3A0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RootMotionWeight = 0x3A0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    // Hyperion integrity machinery. Static RVAs from static analysis of this build - not empirically scanned.
    public static class AntiCheat
    {
        public const ulong relControlFlowGuardMap = 0x145BA48; // Control Flow Guard Map
        public const ulong relFpControlFlowCheck = 0xC53000; // Fp Control Flow Check
    }

    public static class Atmosphere
    {
        public const ulong Color = 0xB8; // Color
        public const ulong Decay = 0xC4; // Decay
        public const ulong Density = 0xD0; // Density
        public const ulong Glare = 0xD4; // Glare
        public const ulong Haze = 0xD8; // Haze
        public const ulong Offset = 0xDC; // Offset
    }

    // attach point on a part
    public static class Attachment
    {
        public const ulong Position = 0xC4; // attachment offset from its parent part center
    }

    public static class AudioListener
    {
        public const ulong AcousticSimulationEnabled = 0x3C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AngleAttenuation = 0x40; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AudioInteractionGroup = 0x40; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DiffractionEnabled = 0x30; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DistanceAttenuation = 0x40; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong OcclusionEnabled = 0x3C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PositionInstance = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PositionType = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ReverbEnabled = 0x3C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SimulationFidelity = 0x40; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    // part instance (aliases into Primitive)
    public static class BasePart
    {
        public const ulong AngularVelocity = 0x28C; // convenience alias: Primitive->AssemblyAngularVelocity
        public const ulong CastShadow = 0x135; // Cast Shadow
        public const ulong Color3 = 0x1A8; // Color3
        public const ulong Locked = 0x136; // Locked
        public const ulong Massless = 0x137; // Massless
        public const ulong Primitive = 0x188; // pointer from BasePart to its physics Primitive
        public const ulong PrimitiveFlags = 0x33E; // Primitive Flags
        public const ulong Reflectance = 0x10C; // Reflectance
        public const ulong Shape = 0x1B9; // Shape
        public const ulong Transparency = 0x130; // Transparency
        public const ulong Velocity = 0x280; // convenience alias: Primitive->AssemblyLinearVelocity
    }

    public static class BloomEffect
    {
        public const ulong Intensity = 0xB8; // Intensity
        public const ulong Size = 0xBC; // Size
        public const ulong Threshold = 0xC0; // Threshold
    }

    public static class BodyColors
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HeadColor = 0x24; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HeadColor3 = 0x24; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftArmColor = 0x24; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftArmColor3 = 0x24; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightArmColor = 0x54; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightArmColor3 = 0x54; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightLegColor = 0x54; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightLegColor3 = 0x54; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    // bool container
    public static class BoolValue
    {
        public const ulong Value = 0xB8; // the bool payload
    }

    public static class ByteCode
    {
        public const ulong Pointer = 0x10; // Pointer
        public const ulong Size = 0x28; // Size
    }

    // cframe container
    public static class CFrameValue
    {
        public const ulong Value = 0xDC; // cframe translation payload
    }

    public static class CachedItem
    {
        public const ulong FileMeshData = 0x28; // File Mesh Data
    }

    // view camera
    public static class Camera
    {
        public const ulong CFrame = 0xD8; // camera position + rotation
        public const ulong CameraSubject = 0xC8; // instance the camera follows
        public const ulong FieldOfView = 0x140; // field of view in degrees (stored as radians here)
        public const ulong Position = 0xFC; // camera world position
        public const ulong Rotation = 0xD8; // Rotation
        public const ulong ViewportInt16 = 0x28C; // Viewport Int16
        public const ulong ViewportSize = 0x2CC; // viewport size in pixels
    }

    public static class CharacterMesh
    {
        public const ulong BaseTextureId = 0xC8; // Base Texture Id
        public const ulong BodyPart = 0x148; // Body Part
        public const ulong MeshId = 0xF8; // Mesh Id
        public const ulong OverlayTextureId = 0x128; // Overlay Texture Id
    }

    public static class ClassDescriptor
    {
        public const ulong ClassName = 0x8; // class name string (e.g. "Part")
        public const ulong Creator = 0x230; // Creator
        public const ulong EventDescriptors = 0x88; // Event Descriptors
        public const ulong FunctionDescriptors = 0xD0; // Function Descriptors
        public const ulong PropertyDescriptors = 0x40; // Property Descriptors
    }

    // click interaction
    public static class ClickDetector
    {
        public const ulong MaxActivationDistance = 0xE8; // max click range in studs
    }

    public static class Creator
    {
        public const ulong MapEnd = 0x83403D8; // Map End
        public const ulong MapStart = 0x83403D0; // Map Start
    }

    // root game object (place/session info)
    public static class DataModel
    {
        public const ulong CreatorId = 0x180; // user/group ID of the game creator
        public const ulong DataModelType = 0x958; // Data Model Type
        public const ulong GameId = 0x188; // ID of the universe (game) this place belongs to
        public const ulong GameLoaded = 0x5D0; // non-zero once the place finished loading
        public const ulong HackFlagNodeValue = 0x10; // Hack Flag Node Value
        public const ulong HackFlagSetList = 0x830; // Hack Flag Set List
        public const ulong HackFlagSetMutex = 0x828; // Hack Flag Set Mutex
        public const ulong JobId = 0x118; // server session ID (unique per server join)
        public const ulong PlaceId = 0x190; // ID of the current place
        public const ulong Workspace = 0x158; // pointer to the Workspace service
    }

    // texture on a face
    public static class Decal
    {
        public const ulong Transparency = 0x25C; // 0 = opaque, 1 = invisible
    }

    public static class Descriptor
    {
        public const ulong Name = 0x8; // Name
    }

    // Hyperion detection flag DWORDs reported through the RBX::PingItem telemetry serializer. Nonzero/non-initial value = that detection fired. Static RVAs from static analysis of this build - not empirically scanned.
    public static class EngineDetections
    {
        public const ulong dwDetectionFlag_0 = 0x7EAD1C8; // Detection Flag 0
        public const ulong dwDetectionFlag_1 = 0x7EAD1CC; // Detection Flag 1
        public const ulong dwDetectionFlag_10 = 0x7EDE53C; // Detection Flag 10
        public const ulong dwDetectionFlag_11 = 0x7EDEB98; // Detection Flag 11
        public const ulong dwDetectionFlag_12 = 0x7EDEB9C; // Detection Flag 12
        public const ulong dwDetectionFlag_13 = 0x7EE6B20; // Detection Flag 13
        public const ulong dwDetectionFlag_14 = 0x7EE6B24; // Detection Flag 14
        public const ulong dwDetectionFlag_15 = 0x7EE6B28; // Detection Flag 15
        public const ulong dwDetectionFlag_16 = 0x7EE6B2C; // Detection Flag 16
        public const ulong dwDetectionFlag_17 = 0x7EE6B30; // Detection Flag 17
        public const ulong dwDetectionFlag_2 = 0x7ED1E3C; // Detection Flag 2
        public const ulong dwDetectionFlag_3 = 0x7ED217C; // Detection Flag 3
        public const ulong dwDetectionFlag_4 = 0x7ED3E28; // Detection Flag 4
        public const ulong dwDetectionFlag_5 = 0x7ED3E2C; // Detection Flag 5
        public const ulong dwDetectionFlag_6 = 0x7EDDA9C; // Detection Flag 6
        public const ulong dwDetectionFlag_7 = 0x7EDE2AC; // Detection Flag 7
        public const ulong dwDetectionFlag_8 = 0x7EDE33C; // Detection Flag 8
        public const ulong dwDetectionFlag_9 = 0x7EDE538; // Detection Flag 9
    }

    public static class FaceControls
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ChinRaiser = 0xE0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ChinRaiserUpperLip = 0xE4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Corrugator = 0xE8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong EyesLookDown = 0xEC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong EyesLookLeft = 0xF0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong EyesLookRight = 0xF4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong EyesLookUp = 0xF8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong FlatPucker = 0xFC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Funneler = 0x100; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong InternalOverrideFACSData = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong JawDrop = 0x104; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong JawLeft = 0x108; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong JawRight = 0x10C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftBrowLowerer = 0x110; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftCheekPuff = 0x114; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftCheekRaiser = 0x118; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftDimpler = 0x11C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftEyeClosed = 0x120; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftEyeUpperLidRaiser = 0x124; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftInnerBrowRaiser = 0x530; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftLipCornerDown = 0x12C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftLipCornerPuller = 0x130; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftLipStretcher = 0x134; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftLowerLipDepressor = 0x138; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftNoseWrinkler = 0x544; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftOuterBrowRaiser = 0x140; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LeftUpperLipRaiser = 0x144; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LipPresser = 0x148; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LipsTogether = 0x14C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LowerLipSuck = 0x150; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouthLeft = 0x154; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouthRight = 0x158; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Pucker = 0x15C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightBrowLowerer = 0x568; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightCheekPuff = 0x164; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightCheekRaiser = 0x168; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightDimpler = 0x16C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightEyeClosed = 0x170; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightEyeUpperLidRaiser = 0x174; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightInnerBrowRaiser = 0x178; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightLipCornerDown = 0x17C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightLipCornerPuller = 0x180; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightLipStretcher = 0x184; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightLowerLipDepressor = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightNoseWrinkler = 0x18C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightOuterBrowRaiser = 0x598; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightUpperLipRaiser = 0x194; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TongueDown = 0x198; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TongueOut = 0x19C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TongueUp = 0x1A0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UpperLipSuck = 0x1A4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    // global entry: *(module + Pointer) = FakeDataModel
    public static class FakeDataModel
    {
        public const ulong Pointer = 0x8CA9CC8; // Pointer
        public const ulong Pointer = 0x8CA9CC8; // Pointer
        public const ulong RealDataModel = 0x1F8; // offset of the real DataModel pointer inside FakeDataModel
    }

    public static class FileMeshData
    {
        public const ulong AabbMax = 0x2BC; // Aabb Max
        public const ulong AabbMin = 0x2B0; // Aabb Min
        public const ulong Faces = 0x30; // Faces
        public const ulong FacesEnd = 0x38; // Faces End
        public const ulong Vertices = 0x0; // Vertices
        public const ulong VerticesEnd = 0x8; // Vertices End
    }

    // fire particle effect
    public static class Fire
    {
        public const ulong FireProximityPrompt = 0x309BD00; // Fire Proximity Prompt
        public const ulong Heat = 0xD8; // fire heat intensity
        public const ulong Size = 0xDC; // fire effect size
    }

    public static class Folder
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ReplicatedGuiInsertionOrder = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    public static class Frame
    {
        public const ulong AbsoluteSize = 0x135; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Active = 0x57C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ActiveQueryNames = 0x3E0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnchorPoint = 0x500; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AutoLocalize = 0x65; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AutomaticSize = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BorderMode = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BorderSizePixel = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ClippedRect = 0x65; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ClipsDescendants = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DragBeginConnectionCount = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DragStoppedConnectionCount = 0xBC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Draggable = 0xF2; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong GuiState = 0x578; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong InputSink = 0x57C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Interactable = 0x5AB; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsNotOccluded = 0x65; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LayoutOrder = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseEnterConnectionCount = 0xCC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseLeaveConnectionCount = 0xD0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseMovedConnectionCount = 0xD4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseWheelBackwardConnectionCount = 0xD8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseWheelForwardConnectionCount = 0x594; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NextSelectionDown = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NextSelectionLeft = 0x4D8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NextSelectionRight = 0x4E8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NextSelectionUp = 0x4F8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Position = 0x598; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RawRect2D = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ReplicatedInsertionOrder = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RootLocalizationTable = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Rotation = 0x598; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Selectable = 0x520; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorDown = 0x50; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorLeft = 0x54; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorRight = 0x58; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorUp = 0x5C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionGroup = 0x60; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionImageObject = 0x500; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionOrder = 0x53C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionRect2D = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Size = 0x520; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SizeConstraint = 0x578; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TotalGroupScale = 0x60; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Transparency = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Visible = 0x57C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ZIndex = 0x57C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    public static class FunctionDescriptor
    {
        public const ulong Function = 0x80; // Function
    }

    public static class Functions
    {
        public const ulong Clone = 0x1619170; // Clone
        public const ulong Destroy = 0x1619190; // Destroy
        public const ulong FindPartOnRay = 0xEB3460; // Find Part On Ray
        public const ulong FindPartOnRayWithIgnoreList = 0xEB34E0; // Find Part On Ray With Ignore List
        public const ulong FindPartOnRayWithWhitelist = 0xEB3570; // Find Part On Ray With Whitelist
        public const ulong FireServer = 0xC99010; // Fire Server
        public const ulong Print = 0x1C68FE0; // Print
        public const ulong RaisePropertyChanged = 0xF5F550; // Raise Property Changed
        public const ulong Raycast = 0xEAAA10; // Raycast
        public const ulong SetParent = 0xB084E8; // Set Parent
        public const ulong SetParentInternal = 0x1CB1AD0; // Set Parent Internal
        public const ulong Shapecast = 0xEAC3D0; // Shapecast
    }

    public static class GuiBase2D
    {
        public const ulong AbsolutePosition = 0x108; // Absolute Position
        public const ulong AbsoluteRotation = 0xE8; // Absolute Rotation
        public const ulong AbsoluteSize = 0x114; // Absolute Size
    }

    public static class GuiObject
    {
        public const ulong Active = 0x5A8; // Active
        public const ulong AnchorPoint = 0x558; // Anchor Point
        public const ulong AutomaticSize = 0x560; // Automatic Size
        public const ulong BackgroundColor3 = 0x540; // Background Color3
        public const ulong BackgroundTransparency = 0x564; // Background Transparency
        public const ulong BorderColor3 = 0x54C; // Border Color3
        public const ulong BorderMode = 0x568; // Border Mode
        public const ulong BorderSizePixel = 0x56C; // Border Size Pixel
        public const ulong ClipsDescendants = 0x5A9; // Clips Descendants
        public const ulong GuiState = 0x578; // Gui State
        public const ulong Interactable = 0x5AB; // Interactable
        public const ulong LayoutOrder = 0x580; // Layout Order
        public const ulong Position = 0x510; // Position
        public const ulong Rotation = 0xE8; // Rotation
        public const ulong Selectable = 0x5AC; // Selectable
        public const ulong SelectionOrder = 0x59C; // Selection Order
        public const ulong Size = 0x530; // Size
        public const ulong SizeConstraint = 0x5A0; // Size Constraint
        public const ulong Visible = 0x5AD; // Visible
        public const ulong ZIndex = 0x5A4; // Z Index
    }

    // selection highlight effect
    public static class Highlight
    {
        public const ulong Adornee = 0xB8; // instance being highlighted
        public const ulong DepthMode = 0xE0; // Depth Mode
        public const ulong Enabled = 0xF4; // Enabled
        public const ulong FillColor = 0xC8; // highlight fill color
        public const ulong FillTransparency = 0xE4; // Fill Transparency
        public const ulong OutlineColor = 0xD4; // highlight outline color
        public const ulong OutlineTransparency = 0xEC; // Outline Transparency
    }

    public static class HopperBin
    {
        public const ulong BinType = 0x468; // Bin Type
    }

    // character controller (walk speed, jump, state)
    public static class Humanoid
    {
        public const ulong AutoJumpEnabled = 0x1D4; // auto-jump on obstacles (mobile style)
        public const ulong AutoRotate = 0x1D5; // whether the humanoid turns to face movement direction
        public const ulong AutomaticScalingEnabled = 0x1D6; // auto-scale animations to body proportions
        public const ulong BreakJointsOnDeath = 0x1D7; // joints break on death when true
        public const ulong CameraOffset = 0x128; // camera offset relative to the humanoid head
        public const ulong DisplayDistanceType = 0x180; // Display Distance Type
        public const ulong DisplayName = 0xB8; // name shown above the character
        public const ulong EvaluateStateMachine = 0x1D8; // engine state machine enabled
        public const ulong Health = 0x190; // current health
        public const ulong HealthDisplayDistance = 0x188; // max distance at which health bar shows
        public const ulong HealthDisplayType = 0x18C; // when the health bar is displayed
        public const ulong HipHeight = 0x194; // distance of torso above the ground
        public const ulong JumpHeight = 0x1A0; // jump height in studs (modern mode)
        public const ulong JumpPower = 0x1A4; // jump impulse strength (legacy mode)
        public const ulong MaxHealth = 0x1A8; // maximum health
        public const ulong MaxSlopeAngle = 0x1AC; // steepest walkable slope in degrees
        public const ulong NameDisplayDistance = 0x1B0; // max distance at which name shows
        public const ulong NameOcclusion = 0x1B4; // name occlusion behaviour behind walls
        public const ulong PlatformStand = 0x1DC; // when true the humanoid ignores input (ragdoll-ish)
        public const ulong RequiresNeck = 0x1DD; // humanoid dies without a Neck joint when true
        public const ulong RigType = 0x1C0; // R6 or R15 skeleton
        public const ulong SeatPart = 0x108; // pointer to the seat being sat on (null if standing)
        public const ulong Sit = 0x1DE; // whether the humanoid is seated
        public const ulong TargetPoint = 0x14C; // current MoveTo target point
        public const ulong UseJumpPower = 0x1E0; // true = use JumpPower, false = use JumpHeight
        public const ulong WalkSpeed = 0x1D0; // movement speed in studs/s (write to change speed)
        public const ulong WalkSpeedCheck = 0x3BC; // duplicate WalkSpeed cache used by engine checks
        public const ulong WalkToPoint = 0x164; // walk target point (same as TargetPoint usually)
    }

    public static class ICreator
    {
        public const ulong Create = 0x0; // Create
    }

    // GUI image element
    public static class ImageLabel
    {
        public const ulong ImageTransparency = 0xAA4; // 0 = opaque image
    }

    public static class InputObject
    {
        public const ulong MousePosition = 0xD4; // Mouse Position
    }

    // base of every Roblox object
    public static class Instance
    {
        public const ulong ChildrenEnd = 0x8; // one-past-end marker inside the children array
        public const ulong ChildrenStart = 0x78; // children vector: array-of-slots pointer
        public const ulong ClassDescriptor = 0x18; // pointer to RTTI class descriptor (per-class static)
        public const ulong Name = 0x8; // offset of the name chars inside the name container
        public const ulong NameContainer = 0x70; // pointer to this instance's name string object
        public const ulong Parent = 0x68; // pointer to the parent instance
    }

    // int container
    public static class IntValue
    {
        public const ulong Value = 0xB8; // the int payload
    }

    // point/surface light source
    public static class Light
    {
        public const ulong Brightness = 0xCC; // Brightness
        public const ulong Range = 0xD8; // Range
    }

    // lighting/atmosphere settings
    public static class Lighting
    {
        public const ulong Ambient = 0xD0; // Ambient
        public const ulong Atmosphere = 0x1D8; // Atmosphere
        public const ulong Brightness = 0x118; // light brightness multiplier
        public const ulong ClockTime = 0xC8; // time of day in seconds since midnight * 1000000
        public const ulong ColorShift_Bottom = 0xDC; // Color Shift Bottom
        public const ulong ColorShift_Top = 0xE8; // Color Shift Top
        public const ulong EnvironmentDiffuseScale = 0x11C; // Environment Diffuse Scale
        public const ulong EnvironmentSpecularScale = 0x120; // Environment Specular Scale
        public const ulong ExposureCompensation = 0x124; // Exposure Compensation
        public const ulong FogColor = 0xF4; // fog color
        public const ulong FogEnd = 0x12C; // distance where fog is fully opaque
        public const ulong FogStart = 0x130; // distance where fog starts
        public const ulong OutdoorAmbient = 0x100; // Outdoor Ambient
        public const ulong ShadowSoftness = 0x13C; // Shadow Softness
        public const ulong Sky = 0x1C8; // Sky
    }

    // these are in the lighting service
    public static class LightingParameters
    {
        public const ulong GeographicLatitude = 0x134; // Geographic Latitude
        public const ulong LightColor = 0x15C; // Light Color
        public const ulong LightDirection = 0x168; // Light Direction
        public const ulong SkyAmbient = 0x150; // Sky Ambient
        public const ulong SkyAmbient2 = 0x138; // Sky Ambient2
        public const ulong Source = 0x174; // Source
        public const ulong TrueMoonPosition = 0x184; // True Moon Position
        public const ulong TrueSunPosition = 0x178; // True Sun Position
    }

    // physics velocity constraint
    public static class LinearVelocity
    {
        public const ulong MaxForce = 0x190; // force cap of the constraint
        public const ulong VectorVelocity = 0x244; // target velocity vector
    }

    public static class LocalScript
    {
        public const ulong Bytecode = 0x190; // Bytecode
        public const ulong Hash = 0x1A0; // Hash
    }

    public static class LruHolder
    {
        public const ulong MemEnforcedLRUCache = 0x20; // Mem Enforced LRU Cache
    }

    public static class LruNode
    {
        public const ulong CachedItem = 0x38; // Cached Item
        public const ulong MeshId = 0x10; // Mesh Id
        public const ulong Next = 0x0; // Next
    }

    public static class LuaPage
    {
        public const ulong dwBlocksize = 0x24; // Blocksize
        public const ulong dwFreenext = 0x30; // Freenext
        public const ulong dwPagesize = 0x20; // Pagesize
        public const ulong lpData = 0x40; // Data
        public const ulong lpListnext = 0x8; // Listnext
    }

    public static class LuaState
    {
        public const ulong lpGlobalState = 0x20; // Global State
    }

    public static class LuaTable
    {
        public const ulong dwArraysize = 0x8; // Arraysize
        public const ulong dwLsizenode = 0x5; // Lsizenode
        public const ulong lpArray = 0x28; // Array
        public const ulong lpNode = 0x18; // Node
    }

    // 'base' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
    public static class LuauBase
    {
        public const ulong fpAssert = 0x26EBB40; // Assert
        public const ulong fpError = 0x26E6810; // Error
        public const ulong fpGcinfo = 0x26EA470; // Gcinfo
        public const ulong fpGetfenv = 0x26E7E70; // Getfenv
        public const ulong fpGetmetatable = 0x26E7250; // Getmetatable
        public const ulong fpNewproxy = 0x26ECA60; // Newproxy
        public const ulong fpNext = 0x26EB090; // Next
        public const ulong fpPrint = 0x26E63C0; // Print
        public const ulong fpRawequal = 0x26E8160; // Rawequal
        public const ulong fpRawget = 0x26E8270; // Rawget
        public const ulong fpRawlen = 0x26EA3D0; // Rawlen
        public const ulong fpRawset = 0x26E87C0; // Rawset
        public const ulong fpSelect = 0x26EBBF0; // Select
        public const ulong fpSetfenv = 0x26E7F30; // Setfenv
        public const ulong fpSetmetatable = 0x26E73D0; // Setmetatable
        public const ulong fpTonumber = 0x26E6490; // Tonumber
        public const ulong fpTostring = 0x26ECA00; // Tostring
        public const ulong fpType = 0x26EA490; // Type
        public const ulong fpTypeof = 0x26EAA90; // Typeof
        public const ulong relRegistryTable = 0x6313CE0; // Registry Table
    }

    // 'bit32' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
    public static class LuauBit32
    {
        public const ulong fpAdd = 0x54E5D60; // Add
        public const ulong fpArshift = 0x54E72F0; // Arshift
        public const ulong fpBand = 0x54E6600; // Band
        public const ulong fpBnot = 0x54E67F0; // Bnot
        public const ulong fpBor = 0x54E6700; // Bor
        public const ulong fpBswap = 0x54E7AF0; // Bswap
        public const ulong fpBtest = 0x54E7920; // Btest
        public const ulong fpBxor = 0x54E6840; // Bxor
        public const ulong fpClamp = 0x54E7840; // Clamp
        public const ulong fpCountlz = 0x54E7A80; // Countlz
        public const ulong fpCountrz = 0x54E7A20; // Countrz
        public const ulong fpCreate = 0x54E58C0; // Create
        public const ulong fpDiv = 0x54E5EE0; // Div
        public const ulong fpExtract = 0x54E74F0; // Extract
        public const ulong fpFromstring = 0x54E59D0; // Fromstring
        public const ulong fpGe = 0x54E6E80; // Ge
        public const ulong fpGt = 0x54E6D70; // Gt
        public const ulong fpIdiv = 0x54E5FC0; // Idiv
        public const ulong fpLe = 0x54E6A40; // Le
        public const ulong fpLrotate = 0x54E73D0; // Lrotate
        public const ulong fpLshift = 0x54E71B0; // Lshift
        public const ulong fpLt = 0x54E6930; // Lt
        public const ulong fpMax = 0x54E64D0; // Max
        public const ulong fpMin = 0x54E63A0; // Min
        public const ulong fpMod = 0x54E6170; // Mod
        public const ulong fpMul = 0x54E5E60; // Mul
        public const ulong fpNeg = 0x54E5D10; // Neg
        public const ulong fpRem = 0x54E60B0; // Rem
        public const ulong fpReplace = 0x54E7670; // Replace
        public const ulong fpRrotate = 0x54E7460; // Rrotate
        public const ulong fpRshift = 0x54E7250; // Rshift
        public const ulong fpSub = 0x54E5DE0; // Sub
        public const ulong fpTonumber = 0x54E5C60; // Tonumber
        public const ulong fpUdiv = 0x54E6260; // Udiv
        public const ulong fpUge = 0x54E70A0; // Uge
        public const ulong fpUgt = 0x54E6F90; // Ugt
        public const ulong fpUle = 0x54E6C60; // Ule
        public const ulong fpUlt = 0x54E6B50; // Ult
        public const ulong fpUrem = 0x54E6300; // Urem
        public const ulong relRegistryTable = 0x652C100; // Registry Table
    }

    // 'buffer' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
    public static class LuauBuffer
    {
        public const ulong fpCopy = 0x54FEC00; // Copy
        public const ulong fpCreate = 0x54FD880; // Create
        public const ulong fpFill = 0x54FEEF0; // Fill
        public const ulong fpFromstring = 0x54FD930; // Fromstring
        public const ulong fpLen = 0x54FEB50; // Len
        public const ulong fpReadbits = 0x54FF140; // Readbits
        public const ulong fpReadf32 = 0x54FFF00; // Readf32
        public const ulong fpReadf64 = 0x5500060; // Readf64
        public const ulong fpReadi16 = 0x54FF980; // Readi16
        public const ulong fpReadi32 = 0x54FFC40; // Readi32
        public const ulong fpReadi8 = 0x54FF6C0; // Readi8
        public const ulong fpReadinteger = 0x54FDF80; // Readinteger
        public const ulong fpReadstring = 0x54FE1D0; // Readstring
        public const ulong fpReadu16 = 0x54FFAE0; // Readu16
        public const ulong fpReadu32 = 0x54FFDA0; // Readu32
        public const ulong fpReadu8 = 0x54FF820; // Readu8
        public const ulong fpTostring = 0x54FDA00; // Tostring
        public const ulong fpWritebits = 0x54FF380; // Writebits
        public const ulong fpWritef32 = 0x5500640; // Writef32
        public const ulong fpWritef64 = 0x55007D0; // Writef64
        public const ulong fpWritei16 = 0x5500340; // Writei16
        public const ulong fpWritei32 = 0x55004C0; // Writei32
        public const ulong fpWritei8 = 0x55001C0; // Writei8
        public const ulong fpWriteinteger = 0x54FE090; // Writeinteger
        public const ulong fpWritestring = 0x54FE8B0; // Writestring
        public const ulong fpWriteu16 = 0x5500340; // Writeu16
        public const ulong fpWriteu32 = 0x55004C0; // Writeu32
        public const ulong fpWriteu8 = 0x55001C0; // Writeu8
        public const ulong relRegistryTable = 0x652CAD0; // Registry Table
    }

    // 'coroutine' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
    public static class LuauCoroutine
    {
        public const ulong fpClose = 0x5504330; // Close
        public const ulong fpCreate = 0x55039B0; // Create
        public const ulong fpIsyieldable = 0x55042B0; // Isyieldable
        public const ulong fpRunning = 0x5504240; // Running
        public const ulong fpStatus = 0x5502340; // Status
        public const ulong fpWrap = 0x5503F60; // Wrap
        public const ulong fpYield = 0x55041E0; // Yield
        public const ulong relRegistryTable = 0x652CE50; // Registry Table
    }

    // 'debug' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
    public static class LuauDebug
    {
        public const ulong fpDumpcodesize = 0x4180630; // Dumpcodesize
        public const ulong fpDumpheap = 0x4180600; // Dumpheap
        public const ulong fpDumprefs = 0x4180610; // Dumprefs
        public const ulong fpGetmemorycategory = 0x41804C0; // Getmemorycategory
        public const ulong fpLoadmodule = 0x41804B0; // Loadmodule
        public const ulong fpProfilebegin = 0x4180230; // Profilebegin
        public const ulong fpProfileend = 0x4180350; // Profileend
        public const ulong fpResetmemorycategory = 0x4180500; // Resetmemorycategory
        public const ulong fpSetmemorycategory = 0x41804F0; // Setmemorycategory
        public const ulong fpTracerefs = 0x4180620; // Tracerefs
        public const ulong relRegistryTable = 0x64F2560; // Registry Table
    }

    public static class LuauGlobalState
    {
        public const ulong bCurrentwhite = 0x58; // Currentwhite
        public const ulong lpAllgcopages = 0x2F0; // Allgcopages
    }

    // 'math' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
    public static class LuauMath
    {
        public const ulong fpAbs = 0x54F89C0; // Abs
        public const ulong fpAcos = 0x54F90C0; // Acos
        public const ulong fpAsin = 0x54F8FE0; // Asin
        public const ulong fpAtan = 0x54F91A0; // Atan
        public const ulong fpAtan2 = 0x54F9280; // Atan2
        public const ulong fpCeil = 0x54F93E0; // Ceil
        public const ulong fpClamp = 0x54FB040; // Clamp
        public const ulong fpCos = 0x54F8C60; // Cos
        public const ulong fpCosh = 0x54F8D40; // Cosh
        public const ulong fpDeg = 0x54F9E10; // Deg
        public const ulong fpExp = 0x54F9D30; // Exp
        public const ulong fpFloor = 0x54F94C0; // Floor
        public const ulong fpFmod = 0x54F95A0; // Fmod
        public const ulong fpFrexp = 0x54F9FD0; // Frexp
        public const ulong fpIsfinite = 0x54FBAE0; // Isfinite
        public const ulong fpIsinf = 0x54FB9F0; // Isinf
        public const ulong fpIsnan = 0x54FB910; // Isnan
        public const ulong fpLdexp = 0x54FA0D0; // Ldexp
        public const ulong fpLerp = 0x54FB730; // Lerp
        public const ulong fpLog = 0x54F9A90; // Log
        public const ulong fpLog10 = 0x54F9C50; // Log10
        public const ulong fpMap = 0x54FB450; // Map
        public const ulong fpMax = 0x54FA3A0; // Max
        public const ulong fpMin = 0x54FA240; // Min
        public const ulong fpModf = 0x54F9700; // Modf
        public const ulong fpNoise = 0x54FAD00; // Noise
        public const ulong fpPow = 0x54F9930; // Pow
        public const ulong fpRad = 0x54F9EF0; // Rad
        public const ulong fpRandom = 0x54FA500; // Random
        public const ulong fpRandomseed = 0x54FA820; // Randomseed
        public const ulong fpRound = 0x54FB370; // Round
        public const ulong fpSign = 0x54FB270; // Sign
        public const ulong fpSin = 0x54F8AA0; // Sin
        public const ulong fpSinh = 0x54F8B80; // Sinh
        public const ulong fpSqrt = 0x54F9830; // Sqrt
        public const ulong fpTan = 0x54F8E20; // Tan
        public const ulong fpTanh = 0x54F8F00; // Tanh
        public const ulong relRegistryTable = 0x652C870; // Registry Table
    }

    // 'os' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
    public static class LuauOs
    {
        public const ulong fpClock = 0x54EA720; // Clock
        public const ulong fpDate = 0x54EBCD0; // Date
        public const ulong fpDifftime = 0x54EC6E0; // Difftime
        public const ulong fpTime = 0x54EC3D0; // Time
        public const ulong relRegistryTable = 0x652C410; // Registry Table
    }

    // 'roblox' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
    public static class LuauRoblox
    {
        public const ulong fpCollectgarbage = 0x40D0CE0; // Collectgarbage
        public const ulong fpDelay = 0x40D1510; // Delay
        public const ulong fpDelay = 0x40D1510; // Delay
        public const ulong fpElapsedTime = 0x40D1D20; // Elapsed Time
        public const ulong fpElapsedTime = 0x40D1D20; // Elapsed Time
        public const ulong fpGetfenv = 0x40D5490; // Getfenv
        public const ulong fpLoadstring = 0x40D1DA0; // Loadstring
        public const ulong fpPluginManager = 0x40D2510; // Plugin Manager
        public const ulong fpPrint = 0x40D2A20; // Print
        public const ulong fpPrintidentity = 0x40D2A40; // Printidentity
        public const ulong fpRequire = 0x40D2B30; // Require
        public const ulong fpSetfenv = 0x40D55C0; // Setfenv
        public const ulong fpSettings = 0x40D3020; // Settings
        public const ulong fpSpawn = 0x40D3520; // Spawn
        public const ulong fpSpawn = 0x40D3520; // Spawn
        public const ulong fpStats = 0x40D3D30; // Stats
        public const ulong fpStats = 0x40D3D30; // Stats
        public const ulong fpTick = 0x40D4250; // Tick
        public const ulong fpTime = 0x40D42D0; // Time
        public const ulong fpUserSettings = 0x40D44D0; // User Settings
        public const ulong fpVersion = 0x40D4970; // Version
        public const ulong fpVersion = 0x40D4970; // Version
        public const ulong fpWait = 0x40D4A40; // Wait
        public const ulong fpWait = 0x40D4A40; // Wait
        public const ulong fpWarn = 0x40D4BF0; // Warn
        public const ulong relRegistryTable = 0x6BA9F00; // Registry Table
    }

    // 'string' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
    public static class LuauString
    {
        public const ulong fpByte = 0x54EDD90; // Byte
        public const ulong fpChar = 0x54EE020; // Char
        public const ulong fpFind = 0x54EFC60; // Find
        public const ulong fpFormat = 0x54F1C40; // Format
        public const ulong fpGmatch = 0x54F0040; // Gmatch
        public const ulong fpGsub = 0x54F1630; // Gsub
        public const ulong fpLen = 0x54EC890; // Len
        public const ulong fpLower = 0x54ED500; // Lower
        public const ulong fpMatch = 0x54EFC70; // Match
        public const ulong fpPack = 0x54F3830; // Pack
        public const ulong fpPacksize = 0x54F4190; // Packsize
        public const ulong fpRep = 0x54ED7A0; // Rep
        public const ulong fpReverse = 0x54ED3B0; // Reverse
        public const ulong fpSplit = 0x54F2270; // Split
        public const ulong fpSub = 0x54EC940; // Sub
        public const ulong fpUnpack = 0x54F4500; // Unpack
        public const ulong fpUpper = 0x54ED650; // Upper
        public const ulong relRegistryTable = 0x652C460; // Registry Table
    }

    // 'table' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
    public static class LuauTable
    {
        public const ulong fpClear = 0x54E4B40; // Clear
        public const ulong fpClone = 0x54E4D90; // Clone
        public const ulong fpConcat = 0x54E1B90; // Concat
        public const ulong fpCreate = 0x54E3EB0; // Create
        public const ulong fpFind = 0x54E46A0; // Find
        public const ulong fpForeach = 0x54DDE20; // Foreach
        public const ulong fpForeachi = 0x54DD0C0; // Foreachi
        public const ulong fpFreeze = 0x54E4B90; // Freeze
        public const ulong fpGetn = 0x54DF240; // Getn
        public const ulong fpInsert = 0x54E0310; // Insert
        public const ulong fpIsfrozen = 0x54E4CE0; // Isfrozen
        public const ulong fpMaxn = 0x54DEF80; // Maxn
        public const ulong fpMove = 0x54E0880; // Move
        public const ulong fpPack = 0x54E1EB0; // Pack
        public const ulong fpRemove = 0x54E0510; // Remove
        public const ulong fpSort = 0x54E3D30; // Sort
        public const ulong fpUnpack = 0x54E26F0; // Unpack
        public const ulong relRegistryTable = 0x652BFE0; // Registry Table
    }

    // 'utf8' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
    public static class LuauUtf8
    {
        public const ulong fpChar = 0x54E8B30; // Char
        public const ulong fpCodepoint = 0x54E8790; // Codepoint
        public const ulong fpCodes = 0x54E9810; // Codes
        public const ulong fpLen = 0x54E84B0; // Len
        public const ulong fpOffset = 0x54E92C0; // Offset
        public const ulong relRegistryTable = 0x652C380; // Registry Table
    }

    // 'vector' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
    public static class LuauVector
    {
        public const ulong fpAbs = 0x54F7010; // Abs
        public const ulong fpAngle = 0x54F6C40; // Angle
        public const ulong fpCeil = 0x54F6F70; // Ceil
        public const ulong fpClamp = 0x54F7140; // Clamp
        public const ulong fpCreate = 0x54F66F0; // Create
        public const ulong fpCross = 0x54F6A70; // Cross
        public const ulong fpDot = 0x54F6B40; // Dot
        public const ulong fpFloor = 0x54F6ED0; // Floor
        public const ulong fpLerp = 0x54F7680; // Lerp
        public const ulong fpMagnitude = 0x54F68A0; // Magnitude
        public const ulong fpMax = 0x54F73D0; // Max
        public const ulong fpMin = 0x54F72B0; // Min
        public const ulong fpNormalize = 0x54F6990; // Normalize
        public const ulong fpSign = 0x54F7080; // Sign
        public const ulong relRegistryTable = 0x652C580; // Registry Table
    }

    public static class MaterialColors
    {
        public const ulong Asphalt = 0x30; // Asphalt
        public const ulong Basalt = 0x27; // Basalt
        public const ulong Brick = 0xF; // Brick
        public const ulong Cobblestone = 0x33; // Cobblestone
        public const ulong Concrete = 0xC; // Concrete
        public const ulong CrackedLava = 0x2D; // Cracked Lava
        public const ulong Glacier = 0x1B; // Glacier
        public const ulong Grass = 0x6; // Grass
        public const ulong Ground = 0x2A; // Ground
        public const ulong Ice = 0x36; // Ice
        public const ulong LeafyGrass = 0x39; // Leafy Grass
        public const ulong Limestone = 0x3F; // Limestone
        public const ulong Mud = 0x24; // Mud
        public const ulong Pavement = 0x42; // Pavement
        public const ulong Rock = 0x18; // Rock
        public const ulong Salt = 0x3C; // Salt
        public const ulong Sand = 0x12; // Sand
        public const ulong Sandstone = 0x21; // Sandstone
        public const ulong Slate = 0x9; // Slate
        public const ulong Snow = 0x1E; // Snow
        public const ulong WoodPlanks = 0x15; // Wood Planks
    }

    public static class MemEnforcedLRUCache
    {
        public const ulong Head = 0x8; // Head
    }

    public static class MeshContentProvider
    {
        public const ulong LruHolder = 0xD8; // Lru Holder
    }

    public static class MeshPart
    {
        public const ulong MeshId = 0x310; // Mesh Id
        public const ulong TextureId = 0x340; // Texture Id
    }

    public static class Model
    {
        public const ulong PrimaryPart = 0x258; // Primary Part
        public const ulong Scale = 0x144; // Scale
    }

    public static class ModuleScript
    {
        public const ulong Bytecode = 0x138; // Bytecode
        public const ulong Hash = 0xD0; // Hash
        public const ulong IsRobloxScript = 0x168; // Is Roblox Script
    }

    // joint between two parts (animation bones)
    public static class Motor6D
    {
        public const ulong C0 = 0x3C0; // joint offset on Part0 (translation)
        public const ulong C0Container = 0x58; // pointer to joint coordinate sub-structure
        public const ulong C1 = 0x3F0; // joint offset on Part1 (translation)
    }

    public static class MouseService
    {
        public const ulong InputObject = 0x100; // Input Object
    }

    // double container
    public static class NumberValue
    {
        public const ulong Value = 0xB8; // the double payload
    }

    // pants template content
    public static class Pants
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Color3 = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Outfit1 = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Outfit1Content = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Outfit2 = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Outfit2Content = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PantsTemplate = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PantsTemplateContent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    public static class Part
    {
        public const ulong Anchored = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AssemblyAngularVelocity = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AssemblyCenterOfMass = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AssemblyLinearVelocity = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AssemblyMass = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AssemblyRootPart = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AudioCanCollide = 0x74; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BackParamA = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BackParamB = 0xCC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BackSurface = 0xD0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BackSurfaceInput = 0xD4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BottomParamA = 0xD8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BottomParamB = 0xDC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BrickColor = 0x1A8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CFrame = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CanCollide = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CanQuery = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CanTouch = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CastShadow = 0x75; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CenterOfMass = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CollisionGroup = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CollisionGroupId = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CollisionGroupReplicate = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Color = 0xE8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Color3uint8 = 0xE8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CurrentPhysicalProperties = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CustomPhysicalProperties = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DraggingV1 = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Elasticity = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ExtentsCFrame = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ExtentsSize = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Friction = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LocalTransparencyModifier = 0x48; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Locked = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Mass = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Massless = 0x137; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Material = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MaterialVariant = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MaterialVariantSerialized = 0xD0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NetworkIsSleeping = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NetworkOwnerV3 = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NetworkOwnershipRule = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Orientation = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Origin = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PhysicsRepRootPart = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PhysicsRepRootRef = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PivotOffset = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Position = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ReceiveAge = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Reflectance = 0x4C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ReplicationPV = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ResizeIncrement = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ResizeableFaces = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RightSurface = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RootPriority = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RotVelocity = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Rotation = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Size = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SpecificGravity = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TopSurface = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Transparency = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Velocity = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong brickColor = 0xE8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong shape = 0x300; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong size = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
    }

    // particle effect emitter
    public static class ParticleEmitter
    {
        public const ulong Enabled = 0x268; // emitter active flag
        public const ulong Rate = 0x248; // particles spawned per second
    }

    // local player info
    public static class Player
    {
        public const ulong AccountAge = 0x35C; // account age in days
        public const ulong CameraMaxZoomDistance = 0x368; // max camera zoom-out distance
        public const ulong CameraMinZoomDistance = 0x36C; // min camera zoom-in distance
        public const ulong Character = 0x298; // pointer to the player's character model
        public const ulong DisplayName = 0x138; // display name string
        public const ulong HealthDisplayDistance = 0x394; // health bar visibility distance
        public const ulong LocaleId = 0x748; // locale string (e.g. en-us)
        public const ulong NameDisplayDistance = 0x3A4; // name visibility distance
        public const ulong Team = 0x2D8; // pointer to current Team
        public const ulong TeamColor = 0x3B0; // BrickColor enum of the team
        public const ulong UserId = 0xD0; // account user ID
    }

    public static class Players
    {
        public const ulong LocalPlayer = 0x130; // pointer to the local player
    }

    public static class PointLight
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Brightness = 0x14; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Color = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Enabled = 0x18; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Range = 0x60; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Shadows = 0x19; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    // per-part physics data (cframe, velocity, size)
    public static class Primitive
    {
        public const ulong AssemblyAngularVelocity = 0x104; // angular velocity of the assembly (rad/s)
        public const ulong AssemblyLinearVelocity = 0xF8; // linear velocity of the assembly (studs/s)
        public const ulong CFrame = 0xC8; // full rotation matrix + position of the part
        public const ulong Material = 0x246; // material enum value
        public const ulong Orientation = 0xC8; // Orientation
        public const ulong Part = 0x210; // back-pointer from Primitive to its BasePart
        public const ulong Position = 0xEC; // world position (translation part of CFrame)
        public const ulong PrimitiveFlags = 0x1B6; // Primitive Flags
        public const ulong Rotation = 0xC8; // Rotation
        public const ulong Size = 0x1BC; // part dimensions in studs
    }

    // physics behavior bitfield (anchored/collide/touch/query)
    public static class PrimitiveFlags
    {
        public const ulong Anchored = 0x2; // bit: part is immovable
        public const ulong CanCollide = 0x8; // bit: part participates in collisions
        public const ulong CanQuery = 0x20; // bit: part is hit by raycasts
        public const ulong CanTouch = 0x10; // bit: part fires Touched events
    }

    public static class PropertyDescriptor
    {
        public const ulong GetSetImpl = 0x90; // Get Set Impl
        public const ulong TType = 0x68; // T Type
    }

    // interact prompt
    public static class ProximityPrompt
    {
        public const ulong ActionText = 0xB0; // Action Text
        public const ulong Enabled = 0x136; // Enabled
        public const ulong HoldDuration = 0x120; // Hold Duration
        public const ulong KeyboardKeyCode = 0x124; // Keyboard Key Code
        public const ulong MaxActivationDistance = 0x128; // Max Activation Distance
        public const ulong ObjectText = 0xD0; // Object Text
        public const ulong RequiresLineOfSight = 0x137; // Requires Line Of Sight
    }

    public static class RemoteEvent
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    public static class RemoteFunction
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    // render target info
    public static class RenderView
    {
        public const ulong DeviceD3D11 = 0x8; // Device D3 D11
        public const ulong LightingValid = 0x228; // Lighting Valid
        public const ulong SkyboxValid = 0x28D; // Skybox Valid
    }

    public static class RigidConstraint
    {
        public const ulong Active = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Attachment0 = 0x58; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Attachment1 = 0x78; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Color = 0x40; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Enabled = 0x9; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Visible = 0x44; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    public static class ScreenGui
    {
        public const ulong AbsoluteSize = 0x135; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ActiveQueryNames = 0x3E0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AutoLocalize = 0x65; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ClipToDeviceSafeArea = 0x14; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ClippedRect = 0x65; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DisplayOrder = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Enabled = 0xC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IgnoreGuiInset = 0x740; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IgnoresTitleBarReservation = 0x15; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsNotOccluded = 0x65; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong OnTopOfCoreBlur = 0x16; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RawRect2D = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ReplicatedInsertionOrder = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ResetOnSpawn = 0xD; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RootLocalizationTable = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SafeAreaCompatibility = 0xC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ScreenInsets = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorDown = 0x50; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorLeft = 0x54; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorRight = 0x58; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorUp = 0x5C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionGroup = 0x60; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TabKeyboardNavigation = 0xE; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TotalGroupScale = 0x60; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ZIndexBehavior = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    public static class Script
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CachedRemoteSource = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CachedRemoteSourceLoadState = 0x40; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Disabled = 0x30; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Enabled = 0x30; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsDifferentFromFileSystem = 0x20; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LinkedSource = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RunContext = 0x30; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SandboxedSource = 0x20; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ScriptGuid = 0x20; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Source = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    public static class ScriptContext
    {
        public const ulong RequireBypass = 0xA00; // Require Bypass
    }

    public static class Seat
    {
        public const ulong Occupant = 0x210; // Occupant
    }

    // shirt template content
    public static class Shirt
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Color3 = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Outfit1 = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Outfit1Content = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Outfit2 = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Outfit2Content = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    public static class Sky
    {
        public const ulong MoonAngularSize = 0x244; // Moon Angular Size
        public const ulong MoonTextureId = 0xC8; // Moon Texture Id
        public const ulong SkyboxBk = 0xF8; // Skybox Bk
        public const ulong SkyboxDn = 0x128; // Skybox Dn
        public const ulong SkyboxFt = 0x158; // Skybox Ft
        public const ulong SkyboxLf = 0x188; // Skybox Lf
        public const ulong SkyboxOrientation = 0x238; // Skybox Orientation
        public const ulong SkyboxRt = 0x1B8; // Skybox Rt
        public const ulong SkyboxUp = 0x1E8; // Skybox Up
        public const ulong StarCount = 0x248; // Star Count
        public const ulong SunAngularSize = 0x24C; // Sun Angular Size
        public const ulong SunTextureId = 0x218; // Sun Texture Id
    }

    // sound instance playback props
    public static class Sound
    {
        public const ulong Looped = 0x13D; // restart when finished
        public const ulong MaxDistance = 0x120; // audible range in studs
        public const ulong PlaybackSpeed = 0x11C; // pitch/speed multiplier (1 = normal)
        public const ulong RollOffMinDistance = 0x124; // distance where volume rolloff begins
        public const ulong Volume = 0x130; // volume 0-10
    }

    // player spawn point
    public static class SpawnLocation
    {
        public const ulong Duration = 0x20; // forcefield duration on spawn
        public const ulong Neutral = 0xD; // usable by any team
    }

    public static class SpecialMesh
    {
        public const ulong MeshId = 0xF8; // Mesh Id
        public const ulong Offset = 0xB8; // Offset
        public const ulong Scale = 0xC4; // Scale
        public const ulong TextureId = 0x128; // Texture Id
    }

    // cone light source
    public static class SpotLight
    {
        public const ulong Angle = 0x4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Brightness = 0x14; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Color = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Enabled = 0x18; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Face = 0x4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Origin = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Range = 0x4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Shadows = 0x19; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SpecificGravity = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TopSurface = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Transparency = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Velocity = 0xC8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong brickColor = 0xE8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong size = 0x188; // instance offset recovered by disassembling this property's GetImpl getter
    }

    public static class Status
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LevelOfDetail = 0x7C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LodEntity = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ModelMeshCFrame = 0x40; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ModelMeshData = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ModelMeshSize = 0x198; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ModelStreamingMode = 0x80; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NeedsPivotMigration = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Origin = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PrimaryPart = 0x198; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Scale = 0x84; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ScaleFactor = 0x84; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SlimAnimationTarget = 0x20; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SlimHash = 0x198; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong WorldPivot = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong WorldPivotData = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    // string container
    public static class StringValue
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Value = 0xB8; // SSO string payload offset
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    // frame scheduler (fps cap, job list)
    public static class TaskScheduler
    {
        public const ulong JobEnd = 0xD0; // Job End
        public const ulong JobName = 0x18; // Job Name
        public const ulong JobStart = 0xC8; // Job Start
        public const ulong MaxFps = 0xB0; // frame cap as frame-time double (1/fps); write smaller value for higher cap
        public const ulong Pointer = 0x8A44D68; // Pointer
    }

    // team definition
    public static class Team
    {
        public const ulong TeamColor = 0xB8; // BrickColor enum of the team
    }

    public static class Terrain
    {
        public const ulong GrassLength = 0x1E8; // Grass Length
        public const ulong MaterialColors = 0x4B0; // Material Colors
        public const ulong WaterColor = 0x1D8; // Water Color
        public const ulong WaterReflectance = 0x1F0; // Water Reflectance
        public const ulong WaterTransparency = 0x1F4; // Water Transparency
        public const ulong WaterWaveSize = 0x1F8; // Water Wave Size
        public const ulong WaterWaveSpeed = 0x1FC; // Water Wave Speed
    }

    public static class TextButton
    {
        public const ulong AbsoluteSize = 0x135; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Active = 0x57C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ActiveQueryNames = 0x3E0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnchorPoint = 0x500; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AutoButtonColor = 0x4C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AutoLocalize = 0x65; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AutomaticSize = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BorderMode = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BorderSizePixel = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ClippedRect = 0x65; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ClipsDescendants = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Confidential = 0xF4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ContentText = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DragBeginConnectionCount = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DragStoppedConnectionCount = 0xBC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Draggable = 0xF2; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Font = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong FontFace = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong GuiState = 0x578; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HoverHapticEffect = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong InputSink = 0x57C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Interactable = 0x5AB; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsNotOccluded = 0x65; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LayoutOrder = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LineHeight = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LocalizationMatchIdentifier = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LocalizationMatchedSourceText = 0x48; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LocalizedText = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MaxVisibleGraphemes = 0x48; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Modal = 0x4C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseButton1ClickConnectionCount = 0x30; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseButton1DownConnectionCount = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseButton1UpConnectionCount = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseButton2ClickConnectionCount = 0x3C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseButton2DownConnectionCount = 0x40; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseButton2UpConnectionCount = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseEnterConnectionCount = 0xCC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseLeaveConnectionCount = 0xD0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseMovedConnectionCount = 0xD4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseWheelBackwardConnectionCount = 0xD8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseWheelForwardConnectionCount = 0x594; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NextSelectionDown = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NextSelectionLeft = 0x4D8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NextSelectionRight = 0x4E8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NextSelectionUp = 0x4F8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Position = 0x598; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PressHapticEffect = 0x20; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RawRect2D = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ReplicatedInsertionOrder = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RichText = 0x48; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RootLocalizationTable = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Rotation = 0x598; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Selectable = 0x520; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Selected = 0x4E; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorDown = 0x50; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorLeft = 0x54; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorRight = 0x58; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorUp = 0x5C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionGroup = 0x60; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionImageObject = 0x500; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionOrder = 0x53C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionRect2D = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Size = 0x520; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SizeConstraint = 0x578; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Style = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Text = 0x48; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TotalGroupScale = 0x60; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Transparency = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Visible = 0x57C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ZIndex = 0x57C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    public static class TextLabel
    {
        public const ulong AbsoluteSize = 0x135; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Active = 0x57C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ActiveQueryNames = 0x3E0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AnchorPoint = 0x500; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AutoLocalize = 0x65; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AutomaticSize = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BorderMode = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong BorderSizePixel = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ClippedRect = 0x65; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ClipsDescendants = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Confidential = 0xEDC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ContentText = 0xDF0; // raw text content before rich-text processing
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DragBeginConnectionCount = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DragStoppedConnectionCount = 0xBC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Draggable = 0xF2; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong FontSize = 0xE08; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong GuiState = 0x578; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong InputSink = 0x57C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Interactable = 0x5AB; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsNotOccluded = 0x65; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LayoutOrder = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LocalizationMatchIdentifier = 0xE10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LocalizationMatchedSourceText = 0x48; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong LocalizedText = 0xE50; // localized text variant
        public const ulong MaxVisibleGraphemes = 0x48; // grapheme reveal limit (-1 = all)
        public const ulong MouseEnterConnectionCount = 0xCC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseLeaveConnectionCount = 0xD0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseMovedConnectionCount = 0xD4; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseWheelBackwardConnectionCount = 0xD8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MouseWheelForwardConnectionCount = 0x594; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NextSelectionDown = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NextSelectionLeft = 0x4D8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NextSelectionRight = 0x4E8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NextSelectionUp = 0x4F8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Position = 0x598; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RawRect2D = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ReplicatedInsertionOrder = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RichText = 0x48; // rich text markup enabled
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RootLocalizationTable = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Rotation = 0x598; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Selectable = 0x520; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorDown = 0x50; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorLeft = 0x54; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorRight = 0x58; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionBehaviorUp = 0x5C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionGroup = 0x60; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionImageObject = 0x500; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionOrder = 0x53C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SelectionRect2D = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Size = 0x520; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SizeConstraint = 0x578; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Text = 0x48; // the rendered text (SSO string)
        public const ulong TotalGroupScale = 0x60; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Transparency = 0xB8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Visible = 0x57C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ZIndex = 0x57C; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    public static class Texture
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ColorMap = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ColorMapContent = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong EmissiveMaskContent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong EmissiveTint = 0x128; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Face = 0x10; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MetalnessMap = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong MetalnessMapContent = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NormalMap = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong NormalMapContent = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Rotation = 0x178; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RoughnessMap = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RoughnessMapContent = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong StudsPerTileV = 0x24; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TexturePack = 0x128; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TexturePackContent = 0x128; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TexturePackMetadata = 0x128; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UVOffset = 0x178; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UVScale = 0x178; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ZIndex = 0x178; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    public static class Tool
    {
        public const ulong CanBeDropped = 0x4B8; // Can Be Dropped
        public const ulong Enabled = 0x4B9; // Enabled
        public const ulong Grip = 0x488; // Grip
        public const ulong GripForward = 0x4A0; // Grip Forward
        public const ulong GripPos = 0x4AC; // Grip Pos
        public const ulong GripRight = 0x488; // Grip Right
        public const ulong GripUp = 0x494; // Grip Up
        public const ulong ManualActivationOnly = 0x4BA; // Manual Activation Only
        public const ulong RequiresHandle = 0x4BB; // Requires Handle
        public const ulong Tooltip = 0x468; // Tooltip
    }

    public static class Value
    {
        public const ulong Value = 0xB8; // generic ValueBase payload offset
    }

    // vector3 container
    public static class Vector3Value
    {
        public const ulong Value = 0xB8; // vector3 payload
    }

    public static class VehicleSeat
    {
        public const ulong MaxSpeed = 0x228; // Max Speed
        public const ulong Occupant = 0x208; // Occupant
        public const ulong SteerFloat = 0x22C; // Steer Float
        public const ulong ThrottleFloat = 0x230; // Throttle Float
        public const ulong Torque = 0x234; // Torque
        public const ulong TurnSpeed = 0x238; // Turn Speed
    }

    // renderer root (view matrix, render view)
    public static class VisualEngine
    {
        public const ulong Dimensions = 0xAE0; // Dimensions
        public const ulong FakeDataModel = 0xAC0; // Fake Data Model
        public const ulong Pointer = 0x82E2128; // Pointer
        public const ulong RenderView = 0xC00; // Render View
        public const ulong ViewMatrix = 0x180; // View Matrix
    }

    public static class Weld
    {
        public const ulong Active = 0x78; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong C0 = 0xD0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong C1 = 0xD0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong EnableSkinning = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Enabled = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Part0 = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Part1 = 0x78; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong part1 = 0x78; // instance offset recovered by disassembling this property's GetImpl getter
    }

    public static class Wire
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Connected = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceInstance = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceName = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TargetInstance = 0x60; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TargetName = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    // 3D world container
    public static class Workspace
    {
        public const ulong CurrentCamera = 0x498; // pointer to the active Camera
        public const ulong ReadOnlyGravity = 0x9C8; // cached gravity value (studs/s^2)
        public const ulong World = 0x3F0; // pointer to the physics World
    }

    // physics simulation container (gravity, sim rate, primitives)
    public static class World
    {
        public const ulong AirProperties = 0x238; // air density / global wind container
        public const ulong Gravity = 0x228; // live gravity used by the solver (write to change fall speed)
        public const ulong Primitives = 0x2A8; // array of every Primitive in the world
        public const ulong dLastFrameTimeStamp = 0x3C0; // D Last Frame Time Stamp
        public const ulong dLastSendTimeStamp = 0x3C8; // D Last Send Time Stamp
        public const ulong dWorldStepDt = 0x3D8; // D World Step Dt
        public const ulong dwLastNumberOfWorldStep = 0x3D0; // Last Number Of World Step
        public const ulong dwWorldStepid = 0xE8; // World Stepid
        public const ulong fWorldStepsPerSecond = 0x720; // World Steps Per Second
    }

    public static class WorldRoot
    {
        public const ulong RaycastBoundDesc = 0x8089F20; // Raycast Bound Desc
        public const ulong RaycastBoundFn = 0x80; // Raycast Bound Fn
    }

    public static class WrapTarget
    {
        public const ulong Archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong AttributesSerialize = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CageMeshContent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CageMeshId = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CageOrigin = 0xB0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong CageOriginWorld = 0xE0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Capabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Color = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DataCost = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DebugMode = 0x14; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong DefinesCapabilities = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HSRAssetId = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HSRContent = 0x38; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HSRData = 0xA0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HSRMeshIdData = 0x110; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong HistoryId = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ImportInProcess = 0x110; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong ImportOrigin = 0xE0; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong IsInSandbox = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Name = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Parent = 0x8; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PredictionMode = 0xAC; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong PropertyStatusStudio = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong RobloxLocked = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Sandboxed = 0xAA; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SerializedOverrides = 0x70; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong SourceAssetId = 0x88; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Stiffness = 0x18; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong Tags = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TemporaryCageMeshContent = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong TemporaryCageMeshId = 0x68; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong UniqueId = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong archivable = 0x4A; // instance offset recovered by disassembling this property's GetImpl getter
        public const ulong numExpectedDirectChildren = 0x28; // instance offset recovered by disassembling this property's GetImpl getter
    }

    // FastFlag value addresses (absolute, this session only)
    public static class FFlags
    {
        public const ulong DFFlagCLI119 = 0x19B985E69BD; // Bool = false
        public const ulong DFFlagCapturePlayerGuiScreenshotAndBuildVideos = 0x19B8E6126BD; // Bool = false
        public const ulong DFFlagFixMonitorNullDerefOnBatchConnect = 0x19B84E6905D; // Bool = false
        public const ulong DFFlagFixVoiceAvailabilityRetryInfiniteLoop = 0x19B84E68C50; // Unknown = 
        public const ulong DFFlagGetHlsLodManifest2 = 0x19B8E61405D; // Bool = false
        public const ulong DFFlagTextChatUserMessageIntentRaisedLimitEnabled = 0x19B949D71ED; // Bool = true
        public const ulong DFStringContentProviderToAssetDeliveryMarkFromLodLoadStudy = 0x19B949E8EE0; // Unknown = 
        public const ulong DFVideoStudioPreviewPermissionFix2 = 0x19B827AE310; // Unknown = 
        public const ulong FFlagAEGIS2EnableGatesForExpChat = 0x19BA515711D; // Bool = false
        public const ulong FFlagAEGIS2EnableGatesForExpChat6 = 0x19BA515931D; // Bool = false
        public const ulong FFlagAEGIS2UseGuacToShowEnabledMessage = 0x19BACFD3A90; // Unknown = 
        public const ulong FFlagAEGIS2UseGuacToShowFAEUpsell = 0x19BACFD5B10; // Unknown = 
        public const ulong FFlagAEGISPhase2ShowImageOnFAEOverlay = 0x19B9F182E1D; // Bool = true
        public const ulong FFlagAEGetEditableOutfitsType2 = 0x19B9026EB9D; // Bool = false
        public const ulong FFlagAFPConnectionsChannelsHeader = 0x19B8C2E4610; // Unknown = 
        public const ulong FFlagAIRephraseSettingEnabled3 = 0x19B8C302D5D; // Bool = true
        public const ulong FFlagAXAccessoryAdjustmentReturnOnNil = 0x19BA3A538DD; // Bool = false
        public const ulong FFlagAXAdaptiveScrollingFixForward = 0x19BBC7A0850; // Unknown = 
        public const ulong FFlagAXAddFacesToHeadList = 0x19BA3A55850; // Unknown = 
        public const ulong FFlagAXAddHDCatalogTab = 0x19BA3A50CD0; // Unknown = 
        public const ulong FFlagAXAddHDCatalogTooltip = 0x19BA3A55610; // Unknown = 
        public const ulong FFlagAXAddHDRowInItemDetailsPage = 0x19B8F905850; // Unknown = 
        public const ulong FFlagAXAddInventoryItemsListProps = 0x19BBC7A9690; // Unknown = 
        public const ulong FFlagAXAddLimitedLabelForCheckout = 0x19BBC7A08D0; // Unknown = 
        public const ulong FFlagAXAddManageOutfitClickTracking = 0x19BBC7AC390; // Unknown = 
        public const ulong FFlagAXAddManageOutfitClickTracking2 = 0x19BBC7AFB90; // Unknown = 
        public const ulong FFlagAXAddNavigationKeyToEditorSubcategories2 = 0x19B9026E1DD; // Bool = false
        public const ulong FFlagAXAddSearchTrendingChips2 = 0x19B8F905110; // Unknown = 
        public const ulong FFlagAXAddSectionsToItemInfoRowPrompt = 0x19B8F907650; // Unknown = 
        public const ulong FFlagAXAddTextXAlignmentProp = 0x19BBC7A69DD; // Bool = false
        public const ulong FFlagAXAddToolTipToIconItemMenu = 0x19BBC7A2F9D; // Bool = false
        public const ulong FFlagAXAddToolTipToIconItemMenu2 = 0x19BBC7AC090; // Unknown = 
        public const ulong FFlagAXAddTransparencyToItemCardHeader = 0x19BBC7A86DD; // Bool = false
        public const ulong FFlagAXAddV1CountersForMISPurchaseSuccess = 0x19B9F29CD90; // Unknown = 
        public const ulong FFlagAXAnimatedLooksThumbnails = 0x19B90648B5D; // Bool = false
        public const ulong FFlagAXAppLaunchedCounterEnabled = 0x19B90648210; // Unknown = 
        public const ulong FFlagAXAppSystemBarEnableTelemtryForFPS = 0x19B90649190; // Unknown = 
        public const ulong FFlagAXAppSystemBarEnableTelemtryForFPSForAll = 0x19B90649150; // Unknown = 
        public const ulong FFlagAXAvatarEditorStoresContext = 0x19BBC7AABD0; // Unknown = 
        public const ulong FFlagAXAvatarFoldersEnabled = 0x19BBC7A8C90; // Unknown = 
        public const ulong FFlagAXAvatarFoldersEnabledDev = 0x19BBC7A37DD; // Bool = false
        public const ulong FFlagAXAvatarLoadWithRetry = 0x19BA3A57490; // Unknown = 
        public const ulong FFlagAXAvatarSharingEntryPoint = 0x19BBC7AB6DD; // Bool = false
        public const ulong FFlagAXAvatarSortInDiscoveryUnifiedPurchase = 0x19B9ACB0550; // Unknown = 
        public const ulong FFlagAXAvatarTabLooksYouMayAlsoLike = 0x19BBC7A0D9D; // Bool = false
        public const ulong FFlagAXAvatarTabShopForMore = 0x19B9026F01D; // Bool = false
        public const ulong FFlagAXAvatarTabWidgetRecommendation = 0x19BA3A51250; // Unknown = 
        public const ulong FFlagAXAvatarsTabIXP = 0x19BBC7AFDDD; // Bool = false
        public const ulong FFlagAXAvatarsTabIXP1 = 0x19BBC7A36D0; // Unknown = 
        public const ulong FFlagAXAvatarsTabIXPEnabledForAll = 0x19BBC7A4650; // Unknown = 
        public const ulong FFlagAXAvatarsTabNoItemsFound = 0x19B90648ADD; // Bool = false
        public const ulong FFlagAXBackendDrivenCatalogLayers = 0x19BBC7A58D0; // Unknown = 
        public const ulong FFlagAXBackgroundCycloramaRendering = 0x19B86E1E2C8; // Unknown = 
        public const ulong FFlagAXBackgroundDisableFogWhileActive = 0x19B8F90445D; // Bool = false
        public const ulong FFlagAXBackgroundGenerationDev = 0x19B8F905FD0; // Unknown = 
        public const ulong FFlagAXBackgroundSceneManagerRevamp = 0x19BBC7A73D0; // Unknown = 
        public const ulong FFlagAXBackgroundSceneManagerRevamp3 = 0x19BBC7A6C90; // Unknown = 
        public const ulong FFlagAXBackgroundsCustomizeHydration4 = 0x19B8F90519D; // Bool = false
        public const ulong FFlagAXBackgroundsCycloramaVR = 0x19B8F905050; // Unknown = 
        public const ulong FFlagAXBackgroundsEquipTryOnCounters2 = 0x19B8F905BDD; // Bool = false
        public const ulong FFlagAXBackgroundsInAvatarBustThumbnails = 0x19B88C6071D; // Bool = false
        public const ulong FFlagAXBackgroundsInAvatarThumbnails = 0x19B88C6055D; // Bool = false
        public const ulong FFlagAXBackgroundsInHeadshotThumbnails = 0x19B88C6095D; // Bool = false
        public const ulong FFlagAXBackgroundsInOutfitDetails = 0x19B8F90551D; // Bool = false
        public const ulong FFlagAXBackgroundsInOutfitThumbnails = 0x19B88C60B1D; // Bool = false
        public const ulong FFlagAXBackgroundsOutfitHighlight = 0x19B8F90565D; // Bool = false
        public const ulong FFlagAXBackgroundsOutfitPersistence = 0x19B9F184C35; // Bool = true
        public const ulong FFlagAXBackgroundsPersistence = 0x19B8F90575D; // Bool = false
        public const ulong FFlagAXBackgroundsRoot = 0x19BA3A582D0; // Unknown = 
        public const ulong FFlagAXBackgroundsTryOn = 0x19B8F905A9D; // Bool = false
        public const ulong FFlagAXBlockMakeupEquipR6 = 0x19BA3A56F10; // Unknown = 
        public const ulong FFlagAXBodyPartsPillLabel = 0x19BBC7A5250; // Unknown = 
        public const ulong FFlagAXBuildSubcategoryMapWhenBuildingCategoryInfo = 0x19B82CB5EDD; // Bool = true
        public const ulong FFlagAXCameraDownwardTilt = 0x19B9064675D; // Bool = false
        public const ulong FFlagAXCameraLevelHorizon = 0x19B906467DD; // Bool = false
        public const ulong FFlagAXCameraManagerErrorsEnabled = 0x19B9064641D; // Bool = false
        public const ulong FFlagAXCatalogBackgroundsFilters = 0x19B8F90415D; // Bool = false
        public const ulong FFlagAXCatalogBackgroundsSupport = 0x19B8F903650; // Unknown = 
        public const ulong FFlagAXCatalogBodySuits = 0x19BA3A5CAD0; // Unknown = 
        public const ulong FFlagAXCatalogCategoriesSDUI = 0x19BA3A5A710; // Unknown = 
        public const ulong FFlagAXCatalogCategoriesSDUI14 = 0x19BA3A50490; // Unknown = 
        public const ulong FFlagAXCatalogCategoriesSDUIDebugDiff = 0x19BA3A53410; // Unknown = 
        public const ulong FFlagAXCatalogCategoriesSDUILinks = 0x19BA3A5B25D; // Bool = true
        public const ulong FFlagAXCatalogCategoriesSDUIPillTitleNormalization = 0x19BA3A53710; // Unknown = 
        public const ulong FFlagAXCatalogCategoriesSDUITaxonomy = 0x19BA3A51A90; // Unknown = 
        public const ulong FFlagAXCatalogCategoriesStoreImprovePerf = 0x19BA3A54AD0; // Unknown = 
        public const ulong FFlagAXCatalogCategoryTooltip = 0x19BA3A543DD; // Bool = false
        public const ulong FFlagAXCatalogItemCardDarkerBackground = 0x19B8F90729D; // Bool = false
        public const ulong FFlagAXCatalogItemCardDarkerBackgroundLogExposure = 0x19D80F1CCB8; // Unknown = 
        public const ulong FFlagAXCatalogItemInformationPopover2 = 0x19B8F90689D; // Bool = false
        public const ulong FFlagAXCatalogM41CategoriesExposureLogging = 0x19BA3A550D0; // Unknown = 
        public const ulong FFlagAXCatalogM41FullMasks = 0x19BA3A5A350; // Unknown = 
        public const ulong FFlagAXCatalogM41HandAndArm = 0x19BA3A50AD0; // Unknown = 
        public const ulong FFlagAXCatalogM41Props = 0x19BA3A51A10; // Unknown = 
        public const ulong FFlagAXCatalogM41Props3 = 0x19BA3A528D0; // Unknown = 
        public const ulong FFlagAXCatalogMakeupFtuxUseMemStorage = 0x19B8FC36C50; // Unknown = 
        public const ulong FFlagAXCatalogMakeupSupport = 0x19BBC7AAA50; // Unknown = 
        public const ulong FFlagAXCatalogMakeupSupport10 = 0x19BBC7AAA10; // Unknown = 
        public const ulong FFlagAXCatalogMakeupTaxonomy = 0x19BA3A59490; // Unknown = 
        public const ulong FFlagAXCatalogMakeupTaxonomy2 = 0x19BA3A57F90; // Unknown = 
        public const ulong FFlagAXCatalogMultiItemShoppingFtuxUseMemStorage = 0x19B8FC36A9D; // Bool = false
        public const ulong FFlagAXCatalogOffersAutoOpenFTUXSheet = 0x19BA3A59A50; // Unknown = 
        public const ulong FFlagAXCatalogOffersAutoOpenFTUXSheet2 = 0x19BA3A51B50; // Unknown = 
        public const ulong FFlagAXCatalogOffersBannerAppStorageUseMemStorage = 0x19B8FC31A10; // Unknown = 
        public const ulong FFlagAXCatalogOffersBannerEnabled = 0x19BA3A59690; // Unknown = 
        public const ulong FFlagAXCatalogOffersBannerEnabled2 = 0x19BA3A56F90; // Unknown = 
        public const ulong FFlagAXCatalogOffersBannerMockApi = 0x19BA3A554D0; // Unknown = 
        public const ulong FFlagAXCatalogOffersClearOnLogout = 0x19BA3A5F290; // Unknown = 
        public const ulong FFlagAXCatalogOffersClearOnLogout2 = 0x19BA3A5A290; // Unknown = 
        public const ulong FFlagAXCatalogOffersDismissedStorageKeyFix = 0x19BA3A5BAD0; // Unknown = 
        public const ulong FFlagAXCatalogPerfReduxReductionIXP2 = 0x19B9026F5D0; // Unknown = 
        public const ulong FFlagAXCatalogPerfReduxReductionIXPEnabledForAll2 = 0x19B9026F490; // Unknown = 
        public const ulong FFlagAXCatalogRealTimeRecommendationsIXPEnabledForAllV2 = 0x19B90648A5D; // Bool = false
        public const ulong FFlagAXCatalogRealTimeRecommendationsIXPV2 = 0x19B906488DD; // Bool = false
        public const ulong FFlagAXCatalogSaveOptionsUseMemStorage = 0x19B8FC3651D; // Bool = false
        public const ulong FFlagAXCatalogSduiDisableOnSearchRoute = 0x19B9F18981D; // Bool = true
        public const ulong FFlagAXCatalogSduiSingleRetryButtonOnError = 0x19BA3A58F50; // Unknown = 
        public const ulong FFlagAXCatalogSduiUseOpaqueRouteForSearch = 0x19B8F90291D; // Bool = false
        public const ulong FFlagAXCatalogSearchSupportDisableFilters = 0x19BA3A59790; // Unknown = 
        public const ulong FFlagAXCatalogSupportDisableFilters = 0x19BA3A54BD0; // Unknown = 
        public const ulong FFlagAXCatalogSupportDisableFilters3 = 0x19BA3A59410; // Unknown = 
        public const ulong FFlagAXCatalogUseFixedWidgetPadding = 0x19BA36666C8; // Unknown = 
        public const ulong FFlagAXCategoryMenuBadgePositionTokens2 = 0x19B9F00721D; // Bool = false
        public const ulong FFlagAXCategoryMenuVisualFixes = 0x19B8F902A9D; // Bool = false
        public const ulong FFlagAXCategoryPillColorAnimation = 0x19BBC7A9410; // Unknown = 
        public const ulong FFlagAXCategoryPillPositionAnimation = 0x19BBC7A77D0; // Unknown = 
        public const ulong FFlagAXCategoryUnifiedLogging = 0x19BBC7A3210; // Unknown = 
        public const ulong FFlagAXCharacterToAvatarStrings = 0x19BBC7A89DD; // Bool = false
        public const ulong FFlagAXCheckApplyDefaultClothingErrorGuards = 0x19B9064751D; // Bool = false
        public const ulong FFlagAXCloseFilterOnBackgroundTap = 0x19B8578AF90; // Unknown = 
        public const ulong FFlagAXColorAdjustmentButtonShouldAccountForTryOns = 0x19BBC7A9190; // Unknown = 
        public const ulong FFlagAXColorGradientRenderFlatWithJustOneColor = 0x19B9F008B9D; // Bool = false
        public const ulong FFlagAXCombineGetOutfitDispatchesIXP3 = 0x19B9026DE5D; // Bool = false
        public const ulong FFlagAXCombineGetOutfitDispatchesIXPForAll3 = 0x19B9026DD90; // Unknown = 
        public const ulong FFlagAXCommunityAvatarsMakeupEquipping = 0x19BA3A55190; // Unknown = 
        public const ulong FFlagAXCustomGetStateForActionHandler = 0x19BBC7A379D; // Bool = false
        public const ulong FFlagAXCustomGetStateForActionHandler3 = 0x19BBC7AC550; // Unknown = 
        public const ulong FFlagAXCustomizeBackgrounds = 0x19BA3A54A50; // Unknown = 
        public const ulong FFlagAXCycloramaAssetFallback2 = 0x19B8F90499D; // Bool = false
        public const ulong FFlagAXDHEquippedAssetsNilCheck = 0x19B9F00A99D; // Bool = false
        public const ulong FFlagAXDebugCreateHumanoidModelError = 0x19B90646590; // Unknown = 
        public const ulong FFlagAXDebugForceIsRecentMarketplaceEnabled = 0x19B90648BD0; // Unknown = 
        public const ulong FFlagAXDebugGridShouldErrorOnInvalidRowCount = 0x19B9F006B90; // Unknown = 
        public const ulong FFlagAXDebugMobileRbxlContentProbe = 0x19B8F904110; // Unknown = 
        public const ulong FFlagAXDebugPanel = 0x19B8F9033D0; // Unknown = 
        public const ulong FFlagAXDebugPanelImpressed = 0x19BA3A55F90; // Unknown = 
        public const ulong FFlagAXDefaultAvatarToShopEnabled3 = 0x19B90647E10; // Unknown = 
        public const ulong FFlagAXDefaultAvatarToShopEnabledForAll3 = 0x19B906476D0; // Unknown = 
        public const ulong FFlagAXDefaultAvatarToShopWidgetEnabled3 = 0x19B90647490; // Unknown = 
        public const ulong FFlagAXDeferLookImpressionsForHydration = 0x19BA3A5BC1D; // Bool = true
        public const ulong FFlagAXDeferWidgetLoadedUntilMarketplaceEntered = 0x19BA3A55D10; // Unknown = 
        public const ulong FFlagAXDisableControlBarMenuAnimation = 0x19B9026CBDD; // Bool = false
        public const ulong FFlagAXDisableHiddenCatalogCategoryPills = 0x19BBC7A2BD0; // Unknown = 
        public const ulong FFlagAXDisableMultiItemShoppingFtux = 0x19BBC7A3410; // Unknown = 
        public const ulong FFlagAXDisableTimedOptionsFtux = 0x19B8FC34E95; // Bool = false
        public const ulong FFlagAXDisableWidgetHydrationCacheForLooks = 0x19B90648C9D; // Bool = false
        public const ulong FFlagAXDoNotPass356FetchCartPricing = 0x19B8FC3635D; // Bool = false
        public const ulong FFlagAXDownrankMakeupCustomize = 0x19BA3A54790; // Unknown = 
        public const ulong FFlagAXDurables2Option = 0x19BA3A57B90; // Unknown = 
        public const ulong FFlagAXDurables2Option4 = 0x19BA3A5E710; // Unknown = 
        public const ulong FFlagAXDurables2OptionFixes = 0x19BA3A54FD0; // Unknown = 
        public const ulong FFlagAXDurablesFooter = 0x19BA3A56650; // Unknown = 
        public const ulong FFlagAXDurablesFooter2 = 0x19BA3A56C50; // Unknown = 
        public const ulong FFlagAXDurablesFooterWithPermanent = 0x19B949FAD6D; // Bool = false
        public const ulong FFlagAXDurablesForMIS = 0x19BBC7A5A90; // Unknown = 
        public const ulong FFlagAXDurablesForMIS2 = 0x19BBC7A3910; // Unknown = 
        public const ulong FFlagAXDurablesSupportExposureLogging = 0x19BA3A59A90; // Unknown = 
        public const ulong FFlagAXDurablesSupportForRFYMigration = 0x19BBC7AA650; // Unknown = 
        public const ulong FFlagAXDurablesSupportForRFYMigration2 = 0x19BBC7A8650; // Unknown = 
        public const ulong FFlagAXDurablesSupportWithPostPurchaseFix = 0x19BBC7A5650; // Unknown = 
        public const ulong FFlagAXEditorEnableThumbnailLatencyStore2 = 0x19B8F905A50; // Unknown = 
        public const ulong FFlagAXEditorSubcategoryFilters = 0x19BBC7A639D; // Bool = false
        public const ulong FFlagAXEditorSubcategoryFilters2 = 0x19BBC7A9F10; // Unknown = 
        public const ulong FFlagAXEnableAvatarDataRefreshV4 = 0x19B9026E110; // Unknown = 
        public const ulong FFlagAXEnableBatchItemDetailsFetchV2 = 0x19BA3A51F50; // Unknown = 
        public const ulong FFlagAXEnableBatchUnequips2 = 0x19B9026E550; // Unknown = 
        public const ulong FFlagAXEnableCategoryPills9 = 0x19B9026D8DD; // Bool = false
        public const ulong FFlagAXEnableCategoryPillsExposureLogging = 0x19BA3A54250; // Unknown = 
        public const ulong FFlagAXEnableCategoryPillsExposureLogging2 = 0x19BA3A5D550; // Unknown = 
        public const ulong FFlagAXEnableEditorCategoryDeepLink = 0x19BACFDCE90; // Unknown = 
        public const ulong FFlagAXEnableErrorLoggingForSubcategorySelectionById = 0x19B861CE365; // Bool = false
        public const ulong FFlagAXEnableExpiredUserLookCheckout = 0x19BBC7A5ED0; // Unknown = 
        public const ulong FFlagAXEnableExpiredUserLookCheckout10 = 0x19BBC7A4550; // Unknown = 
        public const ulong FFlagAXEnableFetchAvatarPreview = 0x19B9F0A16D5; // Bool = false
        public const ulong FFlagAXEnableFetchAvatarPreview9 = 0x19B9F0A179D; // Bool = false
        public const ulong FFlagAXEnableFoundationSegmentedMenu = 0x19BBC7A4A1D; // Bool = false
        public const ulong FFlagAXEnableFullSceneInteractionFrame3 = 0x19B82DBDC10; // Unknown = 
        public const ulong FFlagAXEnableHeadCombineHeadPickerIXPTogether2 = 0x19B9026E61D; // Bool = false
        public const ulong FFlagAXEnableHomeTryOnComplexView = 0x19B88C2F790; // Unknown = 
        public const ulong FFlagAXEnableIaBRbxClientFeature = 0x19B9F0A051D; // Bool = false
        public const ulong FFlagAXEnableIaBTimedOptionsBulkPurchase = 0x19B9F18ECD5; // Bool = true
        public const ulong FFlagAXEnableIaBTimedOptionsBulkPurchase3 = 0x19B8F90351D; // Bool = false
        public const ulong FFlagAXEnableInspectAndBuyBulkPurchase = 0x19B9ACB7310; // Unknown = 
        public const ulong FFlagAXEnableInspectAndBuyBulkPurchase3 = 0x19B9ACB3BD0; // Unknown = 
        public const ulong FFlagAXEnableInspectAndBuyExposureLogging = 0x19B9F298D50; // Unknown = 
        public const ulong FFlagAXEnableInspectAndBuyFocusNavigation = 0x19BA3A51C90; // Unknown = 
        public const ulong FFlagAXEnableInspectAndBuyVersionAnalytics = 0x19B9F0A0715; // Bool = false
        public const ulong FFlagAXEnableMakeupOutfitCreation = 0x19B9F18A245; // Bool = true
        public const ulong FFlagAXEnableManualSaving = 0x19BBC7A1790; // Unknown = 
        public const ulong FFlagAXEnableManualSaving4 = 0x19BBC7ABE90; // Unknown = 
        public const ulong FFlagAXEnableManualSavingBlockingPrompt = 0x19BBC7AE590; // Unknown = 
        public const ulong FFlagAXEnableManualSavingBlockingPrompt3 = 0x19BBC7AAE10; // Unknown = 
        public const ulong FFlagAXEnableMaxUndoRedoHistory = 0x19BBBFF376D; // Bool = false
        public const ulong FFlagAXEnableModeratedItemsFlowForDurables = 0x19BBC7A7BD0; // Unknown = 
        public const ulong FFlagAXEnableMultiTryOnUI = 0x19B8F90841D; // Bool = false
        public const ulong FFlagAXEnableNewInspectAndBuyContainer = 0x19B9F0A6C15; // Bool = false
        public const ulong FFlagAXEnableNewInspectAndBuyContainer21 = 0x19B9F0A6710; // Unknown = 
        public const ulong FFlagAXEnableNewInventoryItemsList2 = 0x19B9026E010; // Unknown = 
        public const ulong FFlagAXEnableProfileTab_1 = 0x19B9AF13E50; // Unknown = 
        public const ulong FFlagAXEnableRecommendationTypeAllInCustomize2 = 0x19B9026ED5D; // Bool = false
        public const ulong FFlagAXEnableRegionalFilteringofAssets = 0x19B9FDD9C15; // Bool = false
        public const ulong FFlagAXEnableResponsiveHeadRefinementMenu = 0x19BA3A5D410; // Unknown = 
        public const ulong FFlagAXEnableSearchLandingFocusedPageFullViewDefault = 0x19B9026D7DD; // Bool = false
        public const ulong FFlagAXEnableTaxonomyM20ExposureLoggingCatalog = 0x19BA3A55550; // Unknown = 
        public const ulong FFlagAXEnableTaxonomyM20ExposureLoggingClothing = 0x19BA3A50810; // Unknown = 
        public const ulong FFlagAXEnableTaxonomyM21ExposureLoggingClothing = 0x19BA3A54490; // Unknown = 
        public const ulong FFlagAXEnableTimedOptionsForCatalogRowCard2 = 0x19B8F90375D; // Bool = false
        public const ulong FFlagAXEnableTimedOptionsServerScript = 0x19B9ACB2CD0; // Unknown = 
        public const ulong FFlagAXEnableUnifiedProductPurchaseForMarketplace = 0x19BA3A584D0; // Unknown = 
        public const ulong FFlagAXEnableUnifiedProductPurchaseForMarketplace2 = 0x19BA3A521D0; // Unknown = 
        public const ulong FFlagAXEnableUnifiedPurchaseFlowForLooks = 0x19BA3A55E90; // Unknown = 
        public const ulong FFlagAXEnhancedAvatarHeadsFtuxUseMemStorage = 0x19BA3A5AA90; // Unknown = 
        public const ulong FFlagAXEnsureOfferBannerRefetchMIS = 0x19B8FC366DD; // Bool = false
        public const ulong FFlagAXEnsureOfferBannerRefetchUnified = 0x19D85DCA8DD; // Bool = true
        public const ulong FFlagAXExpandPeekViewOnFirstScroll = 0x19BBC7A4310; // Unknown = 
        public const ulong FFlagAXExpandPeekViewOnFirstScroll1 = 0x19BBC7A7950; // Unknown = 
        public const ulong FFlagAXExtendUndoRedoTracking = 0x19BBC7A4050; // Unknown = 
        public const ulong FFlagAXExtractEmotesCategory2 = 0x19B9026EC1D; // Bool = false
        public const ulong FFlagAXEyebrowEyelashToMakeupCategory = 0x19BA3A502D0; // Unknown = 
        public const ulong FFlagAXFPSEventStreamAndCounters = 0x19BA6A37690; // Unknown = 
        public const ulong FFlagAXFavoritePillOnItemDetails4 = 0x19B8F906D10; // Unknown = 
        public const ulong FFlagAXFavoritesManagerNavEntry = 0x19BBC7A0C50; // Unknown = 
        public const ulong FFlagAXFavoritesManagerSdui = 0x19B88C20C1D; // Bool = false
        public const ulong FFlagAXFavoritesPillExposureLogging2 = 0x19BA3664FC8; // Unknown = 
        public const ulong FFlagAXFetchCartPricingDuringInExperienceExposure = 0x19B9ACB8F90; // Unknown = 
        public const ulong FFlagAXFetchCatalogPageReturnsPromise = 0x19B8F9026DD; // Bool = false
        public const ulong FFlagAXFetchItemDetailsFromAvatarEditorService = 0x19B8F907A50; // Unknown = 
        public const ulong FFlagAXFilterOutShopOnlyItemsOnBulkPurchase2 = 0x19B9ACB9750; // Unknown = 
        public const ulong FFlagAXFixAvatarSaveContext = 0x19BBB850090; // Unknown = 
        public const ulong FFlagAXFixAvatarScreenVR = 0x19BA3A5BD10; // Unknown = 
        public const ulong FFlagAXFixAvatarScreenVR2 = 0x19BA3A55B50; // Unknown = 
        public const ulong FFlagAXFixAvatarsTabPurchaseLogging = 0x19BBC7A371D; // Bool = false
        public const ulong FFlagAXFixAverageFPSCasing = 0x19B9CB7BF9D; // Bool = false
        public const ulong FFlagAXFixBadgeStatusConfigOptions = 0x19B9F18F10D; // Bool = true
        public const ulong FFlagAXFixBodyScaleReduxUpdates4 = 0x19B90646250; // Unknown = 
        public const ulong FFlagAXFixBottomNavCTAHeight = 0x19B9AF125D0; // Unknown = 
        public const ulong FFlagAXFixBundleOutfitFetchForShoes = 0x19B9064845D; // Bool = false
        public const ulong FFlagAXFixBundleRedirectFromCatalogForSlots = 0x19B9026EB10; // Unknown = 
        public const ulong FFlagAXFixBundleVerifiedBadgeInWidgets = 0x19B9026D750; // Unknown = 
        public const ulong FFlagAXFixCameraManagerInitialization = 0x19B906465DD; // Bool = false
        public const ulong FFlagAXFixCatalogPageButtonSduiCrash = 0x19BA3A59B10; // Unknown = 
        public const ulong FFlagAXFixCatalogRefreshRendering = 0x19BA3A53BDD; // Bool = false
        public const ulong FFlagAXFixCatalogRefreshRenderingV3 = 0x19BA3A5701D; // Bool = false
        public const ulong FFlagAXFixCatalogSearchZoom = 0x19B8F903B1D; // Bool = false
        public const ulong FFlagAXFixCatalogTileThumbnailFlash = 0x19BBCCCB19D; // Bool = false
        public const ulong FFlagAXFixCatalogTileThumbnailFlash3 = 0x19BBC7A5C9D; // Bool = false
        public const ulong FFlagAXFixCheckOnOutfitAssets = 0x19B90644CD0; // Unknown = 
        public const ulong FFlagAXFixClickItemDetailsSurfaceLogging = 0x19B88C6025D; // Bool = false
        public const ulong FFlagAXFixConditionalUseRefSearchBar = 0x19B9029E85D; // Bool = true
        public const ulong FFlagAXFixContextualActionVisibility = 0x19BA3A5DED0; // Unknown = 
        public const ulong FFlagAXFixContextualActionVisibility2 = 0x19BA3A5F2D0; // Unknown = 
        public const ulong FFlagAXFixContextualMenuScrimSize = 0x19B88C6041D; // Bool = false
        public const ulong FFlagAXFixControlBarSubMenuOverlap = 0x19BA3A596D0; // Unknown = 
        public const ulong FFlagAXFixControlBarSubMenuOverlap2 = 0x19BA3A5BC50; // Unknown = 
        public const ulong FFlagAXFixCustomOutfitNamesDisabled = 0x19BA3A552D0; // Unknown = 
        public const ulong FFlagAXFixCycloramaOrphanRemount = 0x19B8F90489D; // Bool = false
        public const ulong FFlagAXFixDataProcessingMilestoneGating = 0x19BA3A5B1D0; // Unknown = 
        public const ulong FFlagAXFixDeselectOutfitInManage = 0x19BA3A555D0; // Unknown = 
        public const ulong FFlagAXFixEditorCategoryRenavigation = 0x19BACFD3790; // Unknown = 
        public const ulong FFlagAXFixEmptyCatalogSearchChrome = 0x19B8F9066DD; // Bool = false
        public const ulong FFlagAXFixEmptyDictionaryKeysForSaveDict2 = 0x19B9026C75D; // Bool = false
        public const ulong FFlagAXFixEmptyMakeupLooks = 0x19BBC7A9910; // Unknown = 
        public const ulong FFlagAXFixFetchOwnedHeadsPaging = 0x19B82A74BD0; // Unknown = 
        public const ulong FFlagAXFixGamepadNavigationOnOutfitManagement = 0x19B8F90249D; // Bool = false
        public const ulong FFlagAXFixHandAndArmWidgetApiContext = 0x19BA3A50410; // Unknown = 
        public const ulong FFlagAXFixHydratedWidgetsParams = 0x19BA3A54A90; // Unknown = 
        public const ulong FFlagAXFixHydratedWidgetsParams2 = 0x19BA3A5F4D0; // Unknown = 
        public const ulong FFlagAXFixIaBTimedOptionsPopoverFocus = 0x19BA3A51CD0; // Unknown = 
        public const ulong FFlagAXFixItemDetailsDescriptionSpacing = 0x19B8F905D10; // Unknown = 
        public const ulong FFlagAXFixItemDetailsPurchaseAttribution = 0x19BA3A520D0; // Unknown = 
        public const ulong FFlagAXFixLimitedUniqueResale = 0x19B8F907250; // Unknown = 
        public const ulong FFlagAXFixLookDetailsContextualMenu = 0x19BA3A56A1D; // Bool = false
        public const ulong FFlagAXFixLookLinkToCustomize = 0x19BBC7AE5D0; // Unknown = 
        public const ulong FFlagAXFixLookPurchaseMissingPurchaseSuccess = 0x19B8FC3689D; // Bool = false
        public const ulong FFlagAXFixLookTryOnReturnRemoval = 0x19BBC7A1050; // Unknown = 
        public const ulong FFlagAXFixMakeupLookGrantOutfitHoisting = 0x19B8F902410; // Unknown = 
        public const ulong FFlagAXFixMinMaxPriceFilterError = 0x19B90644550; // Unknown = 
        public const ulong FFlagAXFixOpenPurchasePromptForOffersGamepad = 0x19BA3A53610; // Unknown = 
        public const ulong FFlagAXFixOrderFieldUnlayeredItems = 0x19B90646E90; // Unknown = 
        public const ulong FFlagAXFixOrientationInputBlocking = 0x19B8578B31D; // Bool = false
        public const ulong FFlagAXFixOutfitEquipCheckEmptyArray = 0x19B8F902E10; // Unknown = 
        public const ulong FFlagAXFixPrefetchMarketplaceStartupCrash = 0x19BA3A51910; // Unknown = 
        public const ulong FFlagAXFixProfileQRCodeTryOnFlash = 0x19B90646C10; // Unknown = 
        public const ulong FFlagAXFixPurchaseAttemptSurfaceLogging = 0x19BA3A50B50; // Unknown = 
        public const ulong FFlagAXFixPurchaseSurfaceLogging = 0x19B88C6009D; // Bool = false
        public const ulong FFlagAXFixR6DefaultHeadShape = 0x19BA3A54590; // Unknown = 
        public const ulong FFlagAXFixRecommendedItemCreatorType = 0x19BA3A59B90; // Unknown = 
        public const ulong FFlagAXFixRemoveLookOnMySharedAvatars = 0x19BBC7A475D; // Bool = false
        public const ulong FFlagAXFixRobuxButtonShowingInFullView = 0x19B8F9021D0; // Unknown = 
        public const ulong FFlagAXFixRobuxUpsellSoftLock = 0x19D85DC021D; // Bool = false
        public const ulong FFlagAXFixSaveManagerOnAXExit = 0x19B9064699D; // Bool = false
        public const ulong FFlagAXFixScrollingCarouselShowRightButton = 0x19BA6092610; // Unknown = 
        public const ulong FFlagAXFixSduiCatalogRowJump = 0x19BA3A5D250; // Unknown = 
        public const ulong FFlagAXFixSduiWidgetTTITileLatencyCallbackIdentity = 0x19BBC7A3ED0; // Unknown = 
        public const ulong FFlagAXFixSearchLandingQuickButtonsOffset = 0x19B8F90829D; // Bool = false
        public const ulong FFlagAXFixSearchPurchaseSurface = 0x19BADFD6335; // Bool = false
        public const ulong FFlagAXFixSeeAllSpacing = 0x19BBC7AE490; // Unknown = 
        public const ulong FFlagAXFixSelectedItemIndexBleed = 0x19BA3A56110; // Unknown = 
        public const ulong FFlagAXFixSingleItemPurchaseWidgetLogging = 0x19BA3A52F50; // Unknown = 
        public const ulong FFlagAXFixSortFunctionForMakeupTryOn = 0x19B90646850; // Unknown = 
        public const ulong FFlagAXFixTabBarOverrideForWrapperPages = 0x19B9AF13A90; // Unknown = 
        public const ulong FFlagAXFixTryOnDefaultClothing = 0x19B906473DD; // Bool = false
        public const ulong FFlagAXFixTryOnHeadShapeThumbnail = 0x19B8F90319D; // Bool = false
        public const ulong FFlagAXFixVRControlBarFlicker = 0x19B8F90815D; // Bool = false
        public const ulong FFlagAXFixWidgetHydrationPermanentPrice = 0x19B8F90635D; // Bool = false
        public const ulong FFlagAXFixWidgetOnlyTabNoItemsFound = 0x19BA3A52B90; // Unknown = 
        public const ulong FFlagAXFlagBasedExposureLoggingCatalogPage = 0x19BA3A58DD0; // Unknown = 
        public const ulong FFlagAXGeneralizeInventoryItemsList = 0x19BBC7A9E5D; // Bool = false
        public const ulong FFlagAXGuardCharacterSpotLightSideAccess = 0x19B9064799D; // Bool = false
        public const ulong FFlagAXGuardNavStateNil = 0x19BBC7A3350; // Unknown = 
        public const ulong FFlagAXGuardNavStateTraversal = 0x19BBC7A63D0; // Unknown = 
        public const ulong FFlagAXHeadCategoryCombineEnabled4 = 0x19B9026E7DD; // Bool = false
        public const ulong FFlagAXHeadCategoryCombineEnabledForAll4 = 0x19B9026E99D; // Bool = false
        public const ulong FFlagAXHeroUnitUIBloxDarkScope = 0x19B8F906F10; // Unknown = 
        public const ulong FFlagAXHideCatalogShortcutsInFullView = 0x19B9F18D25D; // Bool = true
        public const ulong FFlagAXHideEmptySponsoredRow = 0x19B8F90661D; // Bool = false
        public const ulong FFlagAXHideHeadAdjustmentForDefaultHead = 0x19BA3A5031D; // Bool = false
        public const ulong FFlagAXHideMenuOnScroll = 0x19BA3A549DD; // Bool = false
        public const ulong FFlagAXHideMenuOnScroll3 = 0x19BA3A56750; // Unknown = 
        public const ulong FFlagAXHideMenuOnScrollExposureLogging = 0x19BA3A5C1DD; // Bool = false
        public const ulong FFlagAXHideMenuOnScrollExposureLogging3 = 0x19BA3A54D9D; // Bool = true
        public const ulong FFlagAXHideUnifiedPurchaseFlowSuccessToastMarketplace = 0x19BBC7A1E9D; // Bool = false
        public const ulong FFlagAXImproveSlotBasedEditorPerformance = 0x19B9064521D; // Bool = false
        public const ulong FFlagAXIncreaseDefaultPeekViewHeight = 0x19BBCCCCE3D; // Bool = false
        public const ulong FFlagAXInspectAndBuyMakeupSupport = 0x19B8F902850; // Unknown = 
        public const ulong FFlagAXIntervalPerformanceTrackerFPSStandardDeviation = 0x19B9CB74F5D; // Bool = false
        public const ulong FFlagAXIntervalPerformanceTrackerScrollFrameTime = 0x19B9CB7C29D; // Bool = false
        public const ulong FFlagAXInventoryDurablesExpiredFilter = 0x19BA3A55210; // Unknown = 
        public const ulong FFlagAXInventoryDurablesSupport = 0x19BBC7AD1D0; // Unknown = 
        public const ulong FFlagAXInventoryDurablesSupport5 = 0x19BBC7A2D50; // Unknown = 
        public const ulong FFlagAXInventoryIncludeUnavailableItems = 0x19B8F902810; // Unknown = 
        public const ulong FFlagAXInventoryItemsListImpressionLogging = 0x19BA3A56690; // Unknown = 
        public const ulong FFlagAXItemCardBadgeCheckText = 0x19B9F005E10; // Unknown = 
        public const ulong FFlagAXItemCardComponentsMemo = 0x19BBC7A2250; // Unknown = 
        public const ulong FFlagAXItemDetails3DPreviewEnabled = 0x19B9026C890; // Unknown = 
        public const ulong FFlagAXItemDetails3DPreviewEnabledForAll = 0x19B9026D0DD; // Bool = false
        public const ulong FFlagAXItemDetailsIxpExposure = 0x19BBC7A9890; // Unknown = 
        public const ulong FFlagAXItemDetailsIxpExposure2 = 0x19BBC7A9C50; // Unknown = 
        public const ulong FFlagAXItemDetailsPartialAssetInfoFix = 0x19B8F905150; // Unknown = 
        public const ulong FFlagAXItemInfoRowWrapInfoData = 0x19BC5B818A0; // Unknown = 
        public const ulong FFlagAXItemsViewContentSizeBinding = 0x19BBC7A2550; // Unknown = 
        public const ulong FFlagAXKeepTryOnsInAvatarEditor = 0x19B8F90849D; // Bool = false
        public const ulong FFlagAXLaunchUnifiedPurchaseFlowMarketplaceAssetBundles = 0x19BBC7A2B5D; // Bool = false
        public const ulong FFlagAXLaunchUnifiedPurchaseFlowMarketplaceLooks = 0x19BBC7A735D; // Bool = false
        public const ulong FFlagAXLeaveCatalogToAvatarPromptHandleSubcategoryFilters = 0x19BBC7A7C50; // Unknown = 
        public const ulong FFlagAXLegacyIXPExposureLogging = 0x19B8578A750; // Unknown = 
        public const ulong FFlagAXLimitWidgetLoadedItemCount = 0x19BA3A53350; // Unknown = 
        public const ulong FFlagAXLogFacialAnimationOnHeadChange = 0x19BA3A53990; // Unknown = 
        public const ulong FFlagAXLogFacialAnimationOnHeadChange2 = 0x19BA3A57690; // Unknown = 
        public const ulong FFlagAXLogFacialAnimationToggle = 0x19BA3A519D0; // Unknown = 
        public const ulong FFlagAXLogFacialAnimationToggle2 = 0x19BA3A52610; // Unknown = 
        public const ulong FFlagAXLogFavoritePillToggle = 0x19BA3A52D90; // Unknown = 
        public const ulong FFlagAXLogNilCategoryAndSubcategorySelection = 0x19BA3A532D0; // Unknown = 
        public const ulong FFlagAXLookDetailsBottomBarFavoriteLogging = 0x19BABC163C8; // Unknown = 
        public const ulong FFlagAXLookDetailsBottomBarRobux = 0x19B82C68590; // Unknown = 
        public const ulong FFlagAXLookDetailsChevronSpacing = 0x19B82AC931D; // Bool = false
        public const ulong FFlagAXM41AllCategoriesToTaxonomy = 0x19BA3A56410; // Unknown = 
        public const ulong FFlagAXMISEnableMultiShopping = 0x19BBCCCBF5D; // Bool = false
        public const ulong FFlagAXMISEnableMultiShopping13 = 0x19BBC7AEF1D; // Bool = false
        public const ulong FFlagAXMISEnableMultiShoppingUnifiedEvents = 0x19BBC7A199D; // Bool = false
        public const ulong FFlagAXMISEnableMultiShoppingUnifiedEvents2 = 0x19BBC7A1A10; // Unknown = 
        public const ulong FFlagAXMISFixAccessoryOverLimits = 0x19B9026E150; // Unknown = 
        public const ulong FFlagAXMISSaveWearFix = 0x19BBC7A4490; // Unknown = 
        public const ulong FFlagAXMISSmallUIChanges = 0x19BBC7A631D; // Bool = false
        public const ulong FFlagAXMISWithBlackbird = 0x19BA59BF9D0; // Unknown = 
        public const ulong FFlagAXMISWithOffers = 0x19BBC7AF11D; // Bool = false
        public const ulong FFlagAXMISWithOffers4 = 0x19BBC7AF850; // Unknown = 
        public const ulong FFlagAXMakeSlidersSmoothWithGamepad = 0x19B8F9032DD; // Bool = false
        public const ulong FFlagAXMakeupCategoryPositionExperiment = 0x19BBC7A1D90; // Unknown = 
        public const ulong FFlagAXMakeupCategoryPositionExperimentExposureLogging = 0x19BBC7A44D0; // Unknown = 
        public const ulong FFlagAXMakeupEquipping = 0x19BA3A58390; // Unknown = 
        public const ulong FFlagAXMakeupFixAvatarLooksTryOn = 0x19BA3A5C990; // Unknown = 
        public const ulong FFlagAXMakeupLayeringTooltipFTUX = 0x19BA3A52150; // Unknown = 
        public const ulong FFlagAXMakeupReleaseFTUX = 0x19BA3A5A990; // Unknown = 
        public const ulong FFlagAXManageOutfitsCatalogItemCard = 0x19BA3A5201D; // Bool = false
        public const ulong FFlagAXMarketplaceLoadingSkeleton = 0x19B86E1FDD5; // Bool = true
        public const ulong FFlagAXMeTabTopScrim = 0x19B8F90759D; // Bool = false
        public const ulong FFlagAXMigrateAXToGlobalAutofocus = 0x19BA74E5BD0; // Unknown = 
        public const ulong FFlagAXMigrateAdjustAccessoryViewToFocusNavigation = 0x19BA520ACDD; // Bool = true
        public const ulong FFlagAXMigrateAdjustAccessoryViewToFocusNavigation3 = 0x19B88C4D610; // Unknown = 
        public const ulong FFlagAXMigrateAllTabToSdui8 = 0x19B8F902D9D; // Bool = false
        public const ulong FFlagAXMigrateAvatarEditorItemCardInputBindingsToFocusNavigation3 = 0x19B88C4DF9D; // Bool = false
        public const ulong FFlagAXMigrateAvatarEditorPageInputBindings = 0x19B8578AD10; // Unknown = 
        public const ulong FFlagAXMigrateBuilderIcons = 0x19BA3A5B150; // Unknown = 
        public const ulong FFlagAXMigrateBuilderIcons2 = 0x19BA3A5D7D0; // Unknown = 
        public const ulong FFlagAXMigrateCatalogPageInputBindings = 0x19BA74EBF50; // Unknown = 
        public const ulong FFlagAXMigrateCatalogPageInputBindings2 = 0x19B8578A8D0; // Unknown = 
        public const ulong FFlagAXMigrateCatalogResultListNavigationToMVVM = 0x19BA3A5AD50; // Unknown = 
        public const ulong FFlagAXMigrateCatalogSearchToFocusNavigation = 0x19B88C4D1D0; // Unknown = 
        public const ulong FFlagAXMigrateCategoryTooltip = 0x19BA3A595D0; // Unknown = 
        public const ulong FFlagAXMigrateCategoryTooltip1 = 0x19BA3A57210; // Unknown = 
        public const ulong FFlagAXMigrateEmoteMenuFromRoactGamepad = 0x19B8578BADD; // Bool = false
        public const ulong FFlagAXMigrateEquipSlotsInputBindingsToRoactGamepad = 0x19BA74EA710; // Unknown = 
        public const ulong FFlagAXMigrateEquipSlotsInputBindingsToRoactGamepad2 = 0x19B8578A510; // Unknown = 
        public const ulong FFlagAXMigrateItemDetailsContainerInputBindingsToFocusNavigation = 0x19BA57F59A5; // Bool = false
        public const ulong FFlagAXMigrateItemDetailsInputBindingsToFocusNavigation = 0x19B8578B25D; // Bool = false
        public const ulong FFlagAXMigrateLookDetailsPeekViewToFocusNavigation = 0x19B88C4D190; // Unknown = 
        public const ulong FFlagAXMigrateMainNavHeightToFInt = 0x19B9026DA1D; // Bool = false
        public const ulong FFlagAXMigrateMainNavigationInputBindings = 0x19BBC7A785D; // Bool = false
        public const ulong FFlagAXMigrateMakeBackButtonToFocusNavigation3 = 0x19B94810E5D; // Bool = false
        public const ulong FFlagAXMigrateManageOutfitPageInputBindingsToFocusNavigation = 0x19BA74E1FD0; // Unknown = 
        public const ulong FFlagAXMigrateManageOutfitPageInputBindingsToFocusNavigation3 = 0x19B8578B1DD; // Bool = false
        public const ulong FFlagAXMigrateMaterialsToAttributes = 0x19B8F906CD0; // Unknown = 
        public const ulong FFlagAXMigrateOutfitsToUserInventory = 0x19BA3A50850; // Unknown = 
        public const ulong FFlagAXMigratePeekViewToFocusNavigation = 0x19BA6098390; // Unknown = 
        public const ulong FFlagAXMigrateProfilePictureEditorEmotesPageToFocusNavigation = 0x19B88C4C7D0; // Unknown = 
        public const ulong FFlagAXMigratePurchasePromptInteractiveToFocusNavigation2 = 0x19B88C4D910; // Unknown = 
        public const ulong FFlagAXMigrateQuickButtonsToGlobalAutoFocus = 0x19B8578AF50; // Unknown = 
        public const ulong FFlagAXMigrateRecommendedItemsGridToFocusNavigation = 0x19B88C4DD50; // Unknown = 
        public const ulong FFlagAXMigrateResellersInputBindingsToRoactGamepad = 0x19BBC7A7DD0; // Unknown = 
        public const ulong FFlagAXMigrateSaveOutfitPromptFromRoactGamepad = 0x19B88C4DE1D; // Bool = false
        public const ulong FFlagAXMigrateSceneGamepadHandlerInputBindings = 0x19BA74E2AD0; // Unknown = 
        public const ulong FFlagAXMigrateSceneGamepadHandlerInputBindings2 = 0x19B857892D0; // Unknown = 
        public const ulong FFlagAXMigrateSearchBarToFocusNavigation = 0x19B9029D3D0; // Unknown = 
        public const ulong FFlagAXMigrateSearchLandingPageToFocusNavigation = 0x19B9029E910; // Unknown = 
        public const ulong FFlagAXMigrateSlotsSignals = 0x19BBC7A3550; // Unknown = 
        public const ulong FFlagAXMigrateSystemSliderToFoundationSlider = 0x19BA74E575D; // Bool = false
        public const ulong FFlagAXMigrateSystemSliderToFoundationSlider2 = 0x19B8578B4DD; // Bool = false
        public const ulong FFlagAXModeratedItemIconUpdates = 0x19BA3A5245D; // Bool = true
        public const ulong FFlagAXModeratedItemIconUpdates2 = 0x19BA3A58E1D; // Bool = false
        public const ulong FFlagAXModeratedItemsFlow = 0x19BBC7A8A10; // Unknown = 
        public const ulong FFlagAXModeratedItemsFlow5 = 0x19BBC7A9250; // Unknown = 
        public const ulong FFlagAXMoveAllTabToWidgetOnly = 0x19BA3A58A90; // Unknown = 
        public const ulong FFlagAXMoveAllTabToWidgetOnly5 = 0x19BA3A5D610; // Unknown = 
        public const ulong FFlagAXMoveCatalogFilterToL1Navigation = 0x19BABC12D08; // Unknown = 
        public const ulong FFlagAXMoveCatalogFilterToL1Navigation2 = 0x19BBC7A5610; // Unknown = 
        public const ulong FFlagAXMoveCatalogFilterToL1NavigationExposureLogging = 0x19BBC7ABA10; // Unknown = 
        public const ulong FFlagAXMoveCatalogFilterToL1NavigationExposureLogging3 = 0x19BBC7AC910; // Unknown = 
        public const ulong FFlagAXMoveContextualActionButtons = 0x19BA3A52990; // Unknown = 
        public const ulong FFlagAXMutedErrorLoggingForCategorySelection = 0x19BA3A53490; // Unknown = 
        public const ulong FFlagAXNegativeAvatarSequenceFeatures = 0x19BBC7AAD90; // Unknown = 
        public const ulong FFlagAXNilCheckEquippedAssets = 0x19B90646550; // Unknown = 
        public const ulong FFlagAXNilGuardCharacterManager = 0x19B9064711D; // Bool = false
        public const ulong FFlagAXNoCarouselsOnCatalogWithGamepad = 0x19B8F9DF35D; // Bool = false
        public const ulong FFlagAXOnlyHydrateVisibleRows = 0x19B8F903B9D; // Bool = false
        public const ulong FFlagAXOpaqueMarketplaceTopbar = 0x19BBC7A8C50; // Unknown = 
        public const ulong FFlagAXOrganicItemPosition = 0x19BA3A50150; // Unknown = 
        public const ulong FFlagAXOutfitDetailsV4_2 = 0x19B8F90531D; // Bool = false
        public const ulong FFlagAXOutfitPageRevamp = 0x19BA3A5E550; // Unknown = 
        public const ulong FFlagAXOutfitPageRevamp3 = 0x19BA3A56ED0; // Unknown = 
        public const ulong FFlagAXPPEReturnToEntrySurface = 0x19B9AF13ED0; // Unknown = 
        public const ulong FFlagAXPartialPageModalBackgroundShim = 0x19BA3A5D81D; // Bool = true
        public const ulong FFlagAXPartialPageModalBackgroundShim2 = 0x19BA3A56D10; // Unknown = 
        public const ulong FFlagAXPartialPageModalDockedPadding = 0x19B9F008B50; // Unknown = 
        public const ulong FFlagAXPassScreenSizeToWidgetApi = 0x19BA3A5DF90; // Unknown = 
        public const ulong FFlagAXPassScreenSizeToWidgetApi5 = 0x19BA3A5FCD0; // Unknown = 
        public const ulong FFlagAXPhotoboothAddTropicalRunway = 0x19BBC7A3950; // Unknown = 
        public const ulong FFlagAXPhotoboothAnalytics = 0x19BBC7A9F50; // Unknown = 
        public const ulong FFlagAXPhotoboothBugBashFixes = 0x19BBC7AE3D0; // Unknown = 
        public const ulong FFlagAXPhotoboothBugBashFixes4 = 0x19BB6BB7F15; // Bool = false
        public const ulong FFlagAXPhotoboothCaptureServiceScreenshot = 0x19BBC7A0710; // Unknown = 
        public const ulong FFlagAXPhotoboothExposure = 0x19BBC7A5950; // Unknown = 
        public const ulong FFlagAXPhotoboothFunctionality = 0x19BBC7A1650; // Unknown = 
        public const ulong FFlagAXPhotoboothFunctionality12 = 0x19BBC7ADD10; // Unknown = 
        public const ulong FFlagAXPhotoboothIsStandalone = 0x19BBC7A9A9D; // Bool = false
        public const ulong FFlagAXPhotoboothReplacesFullview = 0x19BBC7A24D0; // Unknown = 
        public const ulong FFlagAXPhotoboothShareModal = 0x19BBC7A1A9D; // Bool = false
        public const ulong FFlagAXPrefetchMarketplaceIXP5 = 0x19B9064855D; // Bool = false
        public const ulong FFlagAXPrefetchMarketplaceIXPEnabledForAll5 = 0x19B9064869D; // Bool = false
        public const ulong FFlagAXPrefetchMarketplaceThumbnailsXPExposureV4 = 0x19BA3A58C10; // Unknown = 
        public const ulong FFlagAXPrefetchMarketplaceThumbnailsXPV4 = 0x19BA3A50950; // Unknown = 
        public const ulong FFlagAXPrefetchOnlyWithinTTL = 0x19BA3A575D0; // Unknown = 
        public const ulong FFlagAXProfileConfigurationMultiFieldApply = 0x19B8F90589D; // Bool = false
        public const ulong FFlagAXProvideAccessoryAdjustmentDefaults = 0x19BBC7A7050; // Unknown = 
        public const ulong FFlagAXPurchaseFromQuantityFirst = 0x19BA3A54D10; // Unknown = 
        public const ulong FFlagAXRecentlyViewedCounters = 0x19B9029E450; // Unknown = 
        public const ulong FFlagAXRecentlyViewedSearchItemsEnabled4 = 0x19B9F00EE9D; // Bool = false
        public const ulong FFlagAXRecentlyViewedSearchItemsEnabledForAll4 = 0x19B9F00F05D; // Bool = false
        public const ulong FFlagAXRecentlyViewedSearchItemsPositionTop4 = 0x19B9F00E8D0; // Unknown = 
        public const ulong FFlagAXRecentlyViewedSearchItemsSaveInCatalog4 = 0x19B9F00ED50; // Unknown = 
        public const ulong FFlagAXRecommendedItemsImpressionExposureLogging = 0x19BA3A50250; // Unknown = 
        public const ulong FFlagAXReduceCatalogFilterWidth = 0x19BBC7AA690; // Unknown = 
        public const ulong FFlagAXReduceCatalogFilterWidth2 = 0x19BBC7A9A50; // Unknown = 
        public const ulong FFlagAXRefactorCatalogItemCard = 0x19BBC7A8D1D; // Bool = false
        public const ulong FFlagAXRefactorCatalogItemCard8 = 0x19BBC7A6D1D; // Bool = false
        public const ulong FFlagAXRefactorToggleEquipAsset3 = 0x19B9026E590; // Unknown = 
        public const ulong FFlagAXRefetchInventoryOnAssetGrant = 0x19BA3A53110; // Unknown = 
        public const ulong FFlagAXRefreshThumbnailsOnLocalSave = 0x19B9064689D; // Bool = false
        public const ulong FFlagAXRemoveCatalogCategoryIconOnOff3 = 0x19B82C6681D; // Bool = false
        public const ulong FFlagAXRemoveCatalogCategoryNavKey = 0x19BA3A56F5D; // Bool = false
        public const ulong FFlagAXRemoveCatalogCategoryNavKey4 = 0x19BA3A5279D; // Bool = false
        public const ulong FFlagAXRemoveDynamicHeadAssetsFromTryOn = 0x19B9064725D; // Bool = false
        public const ulong FFlagAXRemoveExpiredItemsFromInventory = 0x19BA3A52310; // Unknown = 
        public const ulong FFlagAXRemoveMemoizeFromAccessoryAdjustmentUtils = 0x19BBC7A6DDD; // Bool = false
        public const ulong FFlagAXRemoveTimedOptionsSalesTypeEnumCheck = 0x19BA3A56310; // Unknown = 
        public const ulong FFlagAXRenameBackToAddToAvatar = 0x19BA3A50D90; // Unknown = 
        public const ulong FFlagAXReplaceDefaultHeadAssetId = 0x19B9026C21D; // Bool = false
        public const ulong FFlagAXRepositionLooksFormKeyboard = 0x19B82A1A19D; // Bool = false
        public const ulong FFlagAXResetAvatarButton = 0x19BA3A59150; // Unknown = 
        public const ulong FFlagAXResetAvatarButton2 = 0x19BA3A5E350; // Unknown = 
        public const ulong FFlagAXResetAvatarButtonExposureLogging = 0x19BA3A56D90; // Unknown = 
        public const ulong FFlagAXResetFetchMarketplaceLogic = 0x19BA3A54CD0; // Unknown = 
        public const ulong FFlagAXResetFetchMarketplaceLogicV2 = 0x19BA3A56450; // Unknown = 
        public const ulong FFlagAXRevertEquippedAssetsAfterLayeringTryOnMakeup = 0x19BBC7A0F10; // Unknown = 
        public const ulong FFlagAXRootRFYMigration = 0x19BA3A58C50; // Unknown = 
        public const ulong FFlagAXRootSlotBasedEditorFlag = 0x19BBC7A41D0; // Unknown = 
        public const ulong FFlagAXScrollHighlightedTabIntoView = 0x19B8F902B5D; // Bool = false
        public const ulong FFlagAXScrollingCarouselWidgetIndexBugfix = 0x19BA59B9350; // Unknown = 
        public const ulong FFlagAXScrollingFramesShouldAnimateOnFocus3 = 0x19B88C4D410; // Unknown = 
        public const ulong FFlagAXSduiCatalogScrollImpressions = 0x19BA3A56CD0; // Unknown = 
        public const ulong FFlagAXSduiFeedBackToTopAndNavClearance = 0x19BA3A50650; // Unknown = 
        public const ulong FFlagAXSduiWidgetsTTITracking = 0x19B8F902F5D; // Bool = false
        public const ulong FFlagAXSearchTrendingChipLogging = 0x19BA3A59750; // Unknown = 
        public const ulong FFlagAXSelectedBorderWrapsBackground = 0x19B8F906F5D; // Bool = false
        public const ulong FFlagAXSendImpressionsForCatalogOffersBanner = 0x19B8FC32210; // Unknown = 
        public const ulong FFlagAXSendModelMismatchCounter = 0x19B8F9DF21D; // Bool = false
        public const ulong FFlagAXSendPurchaseAttempt = 0x19B9F29B7DD; // Bool = false
        public const ulong FFlagAXSendSessionForEvents = 0x19B9F29AF90; // Unknown = 
        public const ulong FFlagAXSendUnifiedEventLogWithInstance = 0x19BA3A54190; // Unknown = 
        public const ulong FFlagAXSendUnifiedEventsInStudio = 0x19B9F29B890; // Unknown = 
        public const ulong FFlagAXSetAngularVelocityIsOptional = 0x19BBC7A8950; // Unknown = 
        public const ulong FFlagAXShowBodySuitsCategoryInCatalog = 0x19BA3A53ED0; // Unknown = 
        public const ulong FFlagAXShowExpiredItemsFilterTooltip = 0x19B9F18328D; // Bool = true
        public const ulong FFlagAXShowFaeUpsell2 = 0x19B8F902190; // Unknown = 
        public const ulong FFlagAXShowFavoritePillFtuxTooltip = 0x19BBCCCAC5D; // Bool = true
        public const ulong FFlagAXShowHeadAdjustmentInRightControlBar = 0x19BA3A5595D; // Bool = false
        public const ulong FFlagAXShowHeadAdjustmentInRightControlBar2 = 0x19BA3A59F9D; // Bool = true
        public const ulong FFlagAXSilenceGetOutfitMutedError = 0x19B9064831D; // Bool = false
        public const ulong FFlagAXSimplifyOutfitEquipCheck = 0x19B9026E950; // Unknown = 
        public const ulong FFlagAXSkipEmotesInAvatarData = 0x19BA3A52A1D; // Bool = false
        public const ulong FFlagAXSkipMakeupFTUX = 0x19BC5B8BF80; // Unknown = 
        public const ulong FFlagAXSkyboxFromBackgroundAsset = 0x19B8F90475D; // Bool = false
        public const ulong FFlagAXSlotAvatarThumbnailPromptFix = 0x19BBC7A3B10; // Unknown = 
        public const ulong FFlagAXSlotBasedEditorCategoryTooltip = 0x19BA3A5AC50; // Unknown = 
        public const ulong FFlagAXSlotBasedEditorCategoryTooltip2 = 0x19BA3A57590; // Unknown = 
        public const ulong FFlagAXSlotBasedEditorCustomizeFtuxUseMemStorage2 = 0x19D80F6BE25; // Bool = false
        public const ulong FFlagAXSlotEditorCategoryMenu = 0x19BA3A5C350; // Unknown = 
        public const ulong FFlagAXSlotsDesignUpdatesExposureLogging = 0x19BA3A51A50; // Unknown = 
        public const ulong FFlagAXSlotsDesignUpdatesExposureLogging2 = 0x19BA3A51D10; // Unknown = 
        public const ulong FFlagAXSlotsDesktopRedesign = 0x19BA3A5EFD0; // Unknown = 
        public const ulong FFlagAXSlotsDesktopRedesign2 = 0x19BA3A558D0; // Unknown = 
        public const ulong FFlagAXSlotsDisableScrollAwayOnLandscape = 0x19BBC7A1E5D; // Bool = false
        public const ulong FFlagAXSlotsFixLeftScroll = 0x19BA3A52C50; // Unknown = 
        public const ulong FFlagAXSlotsInventoryLoadableGridView = 0x19BBC7A7890; // Unknown = 
        public const ulong FFlagAXSlotsPeekViewScrollFix = 0x19BBC7AC7D0; // Unknown = 
        public const ulong FFlagAXSortsBodyTabRecExposureLogging = 0x19B8F9076DD; // Bool = false
        public const ulong FFlagAXStandaloneInventoryDurablesSupport = 0x19BBC7A9290; // Unknown = 
        public const ulong FFlagAXStrictCheckForPrefetchMarketplace = 0x19BA3A5A55D; // Bool = true
        public const ulong FFlagAXSubscriptionRefetchEvictStores = 0x19B8F903410; // Unknown = 
        public const ulong FFlagAXSubscriptionSignalsPlayersServiceOverride = 0x19D80F125C8; // Unknown = 
        public const ulong FFlagAXSupportRentalPurchaseInUnifiedProductPurchaseFlow = 0x19B9AF1E890; // Unknown = 
        public const ulong FFlagAXSupportRentalPurchaseInUnifiedProductPurchaseFlow3 = 0x19B9AF1D150; // Unknown = 
        public const ulong FFlagAXSupportShoesInItemViewport = 0x19B9026D5DD; // Bool = false
        public const ulong FFlagAXSwapOuterwearSubcategoryOrder = 0x19B9026E39D; // Bool = false
        public const ulong FFlagAXTTIAddNumElementsRendered = 0x19B8F74181D; // Bool = false
        public const ulong FFlagAXTTIEditorColdStartDetection = 0x19B9F18A44D; // Bool = true
        public const ulong FFlagAXTTIEditorEnableMilestones4 = 0x19B8F905EDD; // Bool = false
        public const ulong FFlagAXTallTilesForAdvancedBodiesWidget = 0x19BA3A52E50; // Unknown = 
        public const ulong FFlagAXTallTilesForMakeupLooks = 0x19BA3A51150; // Unknown = 
        public const ulong FFlagAXTestDontUseSkeletonOnloadInCatalog = 0x19B9F006BDD; // Bool = false
        public const ulong FFlagAXTestSkeletonInCatalog = 0x19BADFD59D5; // Bool = false
        public const ulong FFlagAXThumbTypeNilCheck = 0x19B86CD7BB8; // Unknown = 
        public const ulong FFlagAXTimedOptionsFTUXModalUseMemStorage = 0x19BA3A54450; // Unknown = 
        public const ulong FFlagAXTimedOptionsFtuxUseMemStorage = 0x19B8FC35E90; // Unknown = 
        public const ulong FFlagAXTimedOptionsPopoverSkipFocusOnCursor = 0x19BA3A55050; // Unknown = 
        public const ulong FFlagAXTooltipUseMemStorage = 0x19B9F00E05D; // Bool = false
        public const ulong FFlagAXTryOnScreenFixes = 0x19BA3A5C6D0; // Unknown = 
        public const ulong FFlagAXTryOnScreenImprovements6 = 0x19B88C4F210; // Unknown = 
        public const ulong FFlagAXTweakSlotsCameraPositioning = 0x19B9026EF1D; // Bool = false
        public const ulong FFlagAXUnifiedFilterWidgetLoadedAndUIImpression = 0x19B9F29B8DD; // Bool = false
        public const ulong FFlagAXUnifiedImpressionsOnThumbnail = 0x19BBCCCE41D; // Bool = false
        public const ulong FFlagAXUnifiedMarketplaceResultsFetcher = 0x19BBC7ACB90; // Unknown = 
        public const ulong FFlagAXUnifiedMarketplaceResultsFetcherV3 = 0x19BBC7ACED0; // Unknown = 
        public const ulong FFlagAXUnifiedPurchaseExtendRentalsFix = 0x19BA3A52050; // Unknown = 
        public const ulong FFlagAXUnifiedPurchasePromptMakeupLooksSaveLookType = 0x19BA3A539DD; // Bool = true
        public const ulong FFlagAXUpdateAvatarOnGameLeave = 0x19B90644ADD; // Bool = false
        public const ulong FFlagAXUpdateSlotBasedEditorToastAndPrompts = 0x19BBC7AB890; // Unknown = 
        public const ulong FFlagAXUprankBundles = 0x19B9026F15D; // Bool = false
        public const ulong FFlagAXUseFIntForWidgetListInitialNumToRender = 0x19B8F9DF89D; // Bool = false
        public const ulong FFlagAXUsePreloadingSwitchView = 0x19BA3A551D0; // Unknown = 
        public const ulong FFlagAXUseProfileIconEntryPoint = 0x19BBC7A50D0; // Unknown = 
        public const ulong FFlagAXUseUnifiedLoggingEnums = 0x19BA3A50B10; // Unknown = 
        public const ulong FFlagAXUseVirtualizedFeedInWidgetList2 = 0x19B8F90399D; // Bool = false
        public const ulong FFlagAXVirtualizedFeedVerticalPadding = 0x19B88C26E5D; // Bool = false
        public const ulong FFlagAXWearTimeListItemUnifiedLogging = 0x19BBCCC68FD; // Bool = true
        public const ulong FFlagAXWearTimeSupport = 0x19BA59BFA10; // Unknown = 
        public const ulong FFlagAXWearTimeSupport3 = 0x19BA59BA5D0; // Unknown = 
        public const ulong FFlagAXWidgetHeaderTreatEmptyTextAsNil = 0x19B8F90609D; // Bool = false
        public const ulong FFlagAXWrapInspectAndBuyThunksInTasks = 0x19B9F0A6B15; // Bool = false
        public const ulong FFlagAbuseReportAttributedRBXSystemMessages = 0x19B8C30C79D; // Bool = true
        public const ulong FFlagAbuseReportCheckSceneSelectionAvailabilityOnOpen = 0x19BB7F45B10; // Unknown = 
        public const ulong FFlagAbuseReportClientVersion = 0x19BB7F45F10; // Unknown = 
        public const ulong FFlagAbuseReportDensifyResolvedArrays = 0x19BB7F44B90; // Unknown = 
        public const ulong FFlagAbuseReportEnableReportSentPage = 0x19B81E13D10; // Unknown = 
        public const ulong FFlagAbuseReportForwardCustomTagFields = 0x19BB7F458D5; // Bool = false
        public const ulong FFlagAbuseReportImproveErrorEvents = 0x19BB7F44FD0; // Unknown = 
        public const ulong FFlagAbuseReportInExpPlayerListV3 = 0x19B8C30EA90; // Unknown = 
        public const ulong FFlagAbuseReportInExpShowConfigLoadingSkeleton = 0x19BB7F42850; // Unknown = 
        public const ulong FFlagAbuseReportInlineAlertStateOutsideReducer = 0x19BB7F48A50; // Unknown = 
        public const ulong FFlagAbuseReportInlineTitleDisclosureFocus = 0x19B8C30D390; // Unknown = 
        public const ulong FFlagAbuseReportLinkOpenedAnalytics = 0x19B8C30D610; // Unknown = 
        public const ulong FFlagAbuseReportMenuOpenCloseSignal = 0x19BB7F44410; // Unknown = 
        public const ulong FFlagAbuseReportMenuV2 = 0x19B949D846D; // Bool = true
        public const ulong FFlagAbuseReportSceneSelectionNextOnFailure = 0x19BB7F40650; // Unknown = 
        public const ulong FFlagAbuseReportSceneSelectionSubmitTracking = 0x19BB7F4BB10; // Unknown = 
        public const ulong FFlagAbuseReportSelectItemAddId = 0x19B8C30D950; // Unknown = 
        public const ulong FFlagAbuseReportSlideOutgoingInputSink = 0x19BB7F4DC90; // Unknown = 
        public const ulong FFlagAbuseReportSubmissionTargetV4 = 0x19B8C30E6D0; // Unknown = 
        public const ulong FFlagAbuseReportTabClearCapturedScreenshotOnCloseFix = 0x19BB7F49B90; // Unknown = 
        public const ulong FFlagAbuseReportV2ScrollNavigation = 0x19BB7F44190; // Unknown = 
        public const ulong FFlagAbuseReportVoiceMute = 0x19B8C30E490; // Unknown = 
        public const ulong FFlagAbuseReportingUseProfileFrameThumbnail = 0x19BB7F4D7D0; // Unknown = 
        public const ulong FFlagAccountLockReceiverClosesModal = 0x19B8C30EADD; // Bool = true
        public const ulong FFlagAccountSwitchRelaunchFallback = 0x19B88C4D81D; // Bool = false
        public const ulong FFlagAccountUnlockAllowMissingUserId = 0x19B8C30EE5D; // Bool = true
        public const ulong FFlagAddAEGIS2Analytics = 0x19BA6099310; // Unknown = 
        public const ulong FFlagAddAbilityToDisableIGMScroll = 0x19B8C30D0D0; // Unknown = 
        public const ulong FFlagAddAbuseReportOffsetForLandscape = 0x19B88C4F95D; // Bool = false
        public const ulong FFlagAddApolloClientToExperienceChat = 0x19BB2AF7E90; // Unknown = 
        public const ulong FFlagAddBackplateSupportToUserTile = 0x19B8C302DD0; // Unknown = 
        public const ulong FFlagAddCenterDialogForUnifiedPurchaseModal = 0x19B9AF1B3D0; // Unknown = 
        public const ulong FFlagAddCenterDialogForUnifiedPurchaseModal2 = 0x19B9AF1B650; // Unknown = 
        public const ulong FFlagAddCollaborationCoreGatedConnectionError2 = 0x19BBC38BC10; // Unknown = 
        public const ulong FFlagAddCommerceErrors = 0x19B9FD8321D; // Bool = false
        public const ulong FFlagAddCommunityLockedToCommunityProfile = 0x19BACFD5090; // Unknown = 
        public const ulong FFlagAddContextualPlayabilityConnectionErrors = 0x19BA672D19D; // Bool = false
        public const ulong FFlagAddCursorProviderToPurchasePromptApp = 0x19B9ACB5050; // Unknown = 
        public const ulong FFlagAddCursorProviderToPurchasePromptAppV5 = 0x19B9ACB54D0; // Unknown = 
        public const ulong FFlagAddDefaultFocusNavSelectorsOnBuyPurchasePrompt = 0x19D80F49058; // Unknown = 
        public const ulong FFlagAddEventsToCommunityProfile = 0x19B8EAE9230; // Unknown = 
        public const ulong FFlagAddFetchProductInfoAsACallback = 0x19B9AF1C0D0; // Unknown = 
        public const ulong FFlagAddFontStyleToTextWithTranslation = 0x19BB7F45510; // Unknown = 
        public const ulong FFlagAddFriendsBannersNewUI_IXP = 0x19BA59BF390; // Unknown = 
        public const ulong FFlagAddFriendsBannersNewUI_exp = 0x19BA59BEFD0; // Unknown = 
        public const ulong FFlagAddFriendsCINewIcon_exp = 0x19BA59B9590; // Unknown = 
        public const ulong FFlagAddFriendsDeprecateUnusedReducers = 0x19B8C2E1A1D; // Bool = false
        public const ulong FFlagAddFriendsIgnoreAllFoundationMenu = 0x19B8C2E11DD; // Bool = false
        public const ulong FFlagAddFriendsOldIconForChannelsVariant_exp = 0x19D81FADD2D; // Bool = true
        public const ulong FFlagAddFriendsPageCapitalization = 0x19BA59B9A10; // Unknown = 
        public const ulong FFlagAddFriendsPageFAEUpsell = 0x19BAEE137D0; // Unknown = 
        public const ulong FFlagAddFriendsPageFAEUpsell3 = 0x19B8C2E4910; // Unknown = 
        public const ulong FFlagAddFriendsPageTrustedFriendRequestSection_v10 = 0x19B8C2E0390; // Unknown = 
        public const ulong FFlagAddFriendsPageUpdateAmpRules = 0x19B8C2E49D0; // Unknown = 
        public const ulong FFlagAddFriendsPresenceStoreMigration = 0x19BA59B4BD0; // Unknown = 
        public const ulong FFlagAddFriendsPresenceStoreMigration_v4 = 0x19BA59BC9D0; // Unknown = 
        public const ulong FFlagAddFriendsRefreshRequestOrder = 0x19B8C2E185D; // Bool = false
        public const ulong FFlagAddFriendsSessionId = 0x19BA59B7410; // Unknown = 
        public const ulong FFlagAddFriendsUserListEnabled_v2 = 0x19B8C2E0210; // Unknown = 
        public const ulong FFlagAddGamepadBumperNavigation3 = 0x19BA6A3BD5D; // Bool = false
        public const ulong FFlagAddIEMProfilePage = 0x19BACFD4A10; // Unknown = 
        public const ulong FFlagAddInviteFriendsIntegration = 0x19B9ACB531D; // Bool = true
        public const ulong FFlagAddLayoutOrderToSduiSectionHeaderIconComponent = 0x19B9029B310; // Unknown = 
        public const ulong FFlagAddMapToNineDot = 0x19B9ACB611D; // Bool = false
        public const ulong FFlagAddMenuNavigationToggleDialog = 0x19B88C4D65D; // Bool = false
        public const ulong FFlagAddMorePhoneUpsellEvents = 0x19B8C30AD1D; // Bool = true
        public const ulong FFlagAddNewPlayerListFocusNav = 0x19BACE9621D; // Bool = false
        public const ulong FFlagAddNewPlayerListMobileFocusNav = 0x19D8704E9D0; // Unknown = 
        public const ulong FFlagAddNewPlayerListMobileFocusNav2 = 0x19BACE9631D; // Bool = false
        public const ulong FFlagAddOnRobloxSubscriptionUpsellSuccessCallbackToUnifiedPurchaseModal = 0x19B9AF1CC10; // Unknown = 
        public const ulong FFlagAddPeoplePageCardLayout = 0x19BBC386B10; // Unknown = 
        public const ulong FFlagAddPeoplePageCardLayout4 = 0x19BBC38DE90; // Unknown = 
        public const ulong FFlagAddPerformanceMetricsToUnifiedPurchaseModal = 0x19B9AF1BE50; // Unknown = 
        public const ulong FFlagAddPerformanceMetricsToUnifiedPurchaseModal3 = 0x19B9AF1BED0; // Unknown = 
        public const ulong FFlagAddPlacelaunchDeviceBlock2 = 0x19BA672CFD0; // Unknown = 
        public const ulong FFlagAddPlatformNameToProfileHeader = 0x19BACFD7210; // Unknown = 
        public const ulong FFlagAddPreselectedAbuseTypeAnalytics = 0x19BBB318F50; // Unknown = 
        public const ulong FFlagAddPreselectedAbuseTypeAnalytics2 = 0x19B8C30DC1D; // Bool = true
        public const ulong FFlagAddPriceBelowCurrentlyWearing = 0x19B8EAEE91D; // Bool = true
        public const ulong FFlagAddPromCounterToKeystoreOps = 0x19B9ACB8950; // Unknown = 
        public const ulong FFlagAddPublishAssetPrompt6 = 0x19B9AF11290; // Unknown = 
        public const ulong FFlagAddPurchaseOptionForProvidingBalance = 0x19B9AF1B490; // Unknown = 
        public const ulong FFlagAddReasonToEveryLogout = 0x19B945A0350; // Unknown = 
        public const ulong FFlagAddReportCharacterLimit = 0x19BBD290D2D; // Bool = false
        public const ulong FFlagAddSocialLinksToCommunityProfile = 0x19BACFDFF90; // Unknown = 
        public const ulong FFlagAddSocialLinksToCommunityProfile_v3 = 0x19BACFDF390; // Unknown = 
        public const ulong FFlagAddStatusIndicatorToBaseRow_v2 = 0x19B8C2E1710; // Unknown = 
        public const ulong FFlagAddSwitchTabHintsToIEM = 0x19B9ACB90D0; // Unknown = 
        public const ulong FFlagAddTakeItDownReportLinkToSurfaces = 0x19B8C30E75D; // Bool = true
        public const ulong FFlagAddThumbnailReportToPlayerFeedback = 0x19B90262FDD; // Bool = false
        public const ulong FFlagAddThumbnailSelectorReport = 0x19BBB3185D0; // Unknown = 
        public const ulong FFlagAddThumbnailSelectorReport6 = 0x19B8C30CD90; // Unknown = 
        public const ulong FFlagAddTimerToBulkPurchaseBuyButton = 0x19B9F927A5D; // Bool = false
        public const ulong FFlagAddTopBarScrim = 0x19BACFEE25D; // Bool = false
        public const ulong FFlagAddTraversalBackButton699v1 = 0x19BBC38EED0; // Unknown = 
        public const ulong FFlagAddTraversalBackButtonAnimation699v1 = 0x19BBC380790; // Unknown = 
        public const ulong FFlagAddTraversalHistory699v1 = 0x19BBC383990; // Unknown = 
        public const ulong FFlagAddTraversalHistoryReactMenuButtons = 0x19BBE91E695; // Bool = false
        public const ulong FFlagAddTypesToWidgetItems = 0x19BA3A58590; // Unknown = 
        public const ulong FFlagAddUILessMode = 0x19B8578B89D; // Bool = false
        public const ulong FFlagAddUnderlineToLinksInTextWithTranslation = 0x19BB7F40690; // Unknown = 
        public const ulong FFlagAddUnifiedPurchaseFlowTTIToEDP = 0x19B9AF1B150; // Unknown = 
        public const ulong FFlagAddUnifiedPurchaseRobuxUpsellCompletedTelemetry = 0x19D85DC88D0; // Unknown = 
        public const ulong FFlagAddUnifiedPurchaseRobuxUpsellCompletedTelemetry2 = 0x19D85DC6210; // Unknown = 
        public const ulong FFlagAddUpsellEntryComponentToAnalytics = 0x19BA60981D0; // Unknown = 
        public const ulong FFlagAddVideoToCommunityProfile = 0x19BACFD6910; // Unknown = 
        public const ulong FFlagAddVideoToCommunityProfile_v7 = 0x19BACFD8A90; // Unknown = 
        public const ulong FFlagAddVipOwnerNotPresentConnectionError = 0x19BA672D3DD; // Bool = false
        public const ulong FFlagAdjustHorizontalUserListSizeForMobile = 0x19BA67979D0; // Unknown = 
        public const ulong FFlagAdoptStyleTokens = 0x19BA607699D; // Bool = true
        public const ulong FFlagAdsInteractivityControlsFixStyleLink = 0x19BA8A0C6D0; // Unknown = 
        public const ulong FFlagAgeBasedUXHomepageVerificationBannerGreyButton = 0x19B8C2E4890; // Unknown = 
        public const ulong FFlagAgeBasedUXHomepageVerificationBannerLockIcon = 0x19BA6F62D9D; // Bool = false
        public const ulong FFlagAgreementItemsOrderFixEnabled = 0x19B859C9BD0; // Unknown = 
        public const ulong FFlagAllowAmpV2FeatureAccessCall = 0x19B88C6125D; // Bool = false
        public const ulong FFlagAllowCustomUnifiedEventFilter = 0x19BB2B247B5; // Bool = true
        public const ulong FFlagAllowDisconnectGuiForOkUnknown = 0x19B9FDD4BD5; // Bool = false
        public const ulong FFlagAllowDisplayingFoundationIconsForDropdown = 0x19BAD28459D; // Bool = false
        public const ulong FFlagAllowNumberLocalizationSigFigParam = 0x19B8A186CCD; // Bool = false
        public const ulong FFlagAllowQrEnlargeUniversally = 0x19BA6076A1D; // Bool = true
        public const ulong FFlagAlwaysShowGamepadNavigationDialog = 0x19B9FDDC995; // Bool = false
        public const ulong FFlagAlwaysShowVRToggleV3 = 0x19B9FD8ADDD; // Bool = false
        public const ulong FFlagAmpGqlPassSuccessfulActions = 0x19B901113D0; // Unknown = 
        public const ulong FFlagAmpWizardDeepLinkReplaceOnlyWebView = 0x19B9011365D; // Bool = false
        public const ulong FFlagAndroidPasswordSuggestionExperimentEnrollmentBypass = 0x19BA4D4DC85; // Bool = false
        public const ulong FFlagAndroidTVExitWithB2 = 0x19B9AF14290; // Unknown = 
        public const ulong FFlagAppChatAnalyticsUseTelemetryService = 0x19BA6798B90; // Unknown = 
        public const ulong FFlagAppChatAutotranslationRespectsExperienceChatSetting = 0x19BACE71C10; // Unknown = 
        public const ulong FFlagAppChatCatchSendMessageSyncError = 0x19B9026B190; // Unknown = 
        public const ulong FFlagAppChatChannelsGetNewerMessagesWithPrevCursor = 0x19B8FA15110; // Unknown = 
        public const ulong FFlagAppChatChatLandingScreenRenameFixEnabled = 0x19B8C2E2490; // Unknown = 
        public const ulong FFlagAppChatContextCardNameLoadingShimmer = 0x19BACE705D0; // Unknown = 
        public const ulong FFlagAppChatConversationLoadingSkeleton = 0x19BACE7E110; // Unknown = 
        public const ulong FFlagAppChatConversationPageSyntheticSystemMessageIxpEnabled = 0x19BACE7C350; // Unknown = 
        public const ulong FFlagAppChatConversationStore = 0x19B9987B235; // Bool = true
        public const ulong FFlagAppChatCustomConversationListRow = 0x19B8FA1CEDD; // Bool = false
        public const ulong FFlagAppChatDiscloseUpdateSecondVersion = 0x19B8578775D; // Bool = false
        public const ulong FFlagAppChatDisclosureUpdateEnabled = 0x19B8C305410; // Unknown = 
        public const ulong FFlagAppChatDomLocatorFoundationMigration = 0x19B8C2E10D0; // Unknown = 
        public const ulong FFlagAppChatEnableAutotranslation = 0x19BA6B36A1D; // Bool = false
        public const ulong FFlagAppChatEnableAutotranslation2 = 0x19B9026A210; // Unknown = 
        public const ulong FFlagAppChatEnableDoubleOptInRC3 = 0x19B8C2E2190; // Unknown = 
        public const ulong FFlagAppChatEnableManualTranslation = 0x19B9026AA90; // Unknown = 
        public const ulong FFlagAppChatEnableMessageContextMenu = 0x19BA802A4D0; // Unknown = 
        public const ulong FFlagAppChatEnableOSAConversationFetchForFriendsPlaceholdersFix = 0x19B82AC8D9D; // Bool = false
        public const ulong FFlagAppChatEnableRepliesUIIxpEnabled2 = 0x19BACE71750; // Unknown = 
        public const ulong FFlagAppChatEnableRootedNavigation2 = 0x19BA6079ED0; // Unknown = 
        public const ulong FFlagAppChatEnabledChromeDropdownFtuxTooltip = 0x19BB8FA4538; // Unknown = 
        public const ulong FFlagAppChatExcludeStandardizedFieldsFromCounters = 0x19B8FA14ED0; // Unknown = 
        public const ulong FFlagAppChatFixBackButtonOnRotation = 0x19BACE76B10; // Unknown = 
        public const ulong FFlagAppChatFixPlusBadgeAlignment = 0x19BACE70BD0; // Unknown = 
        public const ulong FFlagAppChatFixRootChatBackNavigation = 0x19B8C305B50; // Unknown = 
        public const ulong FFlagAppChatFixRootChatBackNavigationIxpEnabled = 0x19B8FA156DD; // Bool = false
        public const ulong FFlagAppChatFriendsTabIxpEnabled = 0x19BA802AE50; // Unknown = 
        public const ulong FFlagAppChatFriendsTabIxpEnabledRC1 = 0x19BA8029550; // Unknown = 
        public const ulong FFlagAppChatFullPlaintextBeforeGameCards = 0x19B9026BB90; // Unknown = 
        public const ulong FFlagAppChatGamepadSendButtonNav = 0x19BACE7EC10; // Unknown = 
        public const ulong FFlagAppChatGlobalSwipeTracking = 0x19BACE7C510; // Unknown = 
        public const ulong FFlagAppChatHidePlayButtonsInExp = 0x19BA8020790; // Unknown = 
        public const ulong FFlagAppChatIgnoreUnknownThirdPartyChatStatus = 0x19BA802DD90; // Unknown = 
        public const ulong FFlagAppChatInExpSelectChatMembersMobileHeight = 0x19BA8022250; // Unknown = 
        public const ulong FFlagAppChatInExpToastSnoozeMenuDismissFix = 0x19BACFD78D0; // Unknown = 
        public const ulong FFlagAppChatInExperienceEnabledV654NewIcon = 0x19B8C2EA810; // Unknown = 
        public const ulong FFlagAppChatInExperienceTabBarAdjustment = 0x19BA6079AD0; // Unknown = 
        public const ulong FFlagAppChatInvalidGameLinkCard = 0x19BA8023750; // Unknown = 
        public const ulong FFlagAppChatIxpScreenExposure = 0x19BACE732D0; // Unknown = 
        public const ulong FFlagAppChatLoadingIndicatorTransparency = 0x19B8FA1CC9D; // Bool = false
        public const ulong FFlagAppChatMessageTTIMilestones = 0x19BA6B3B3DD; // Bool = false
        public const ulong FFlagAppChatMessageTTIMilestones1 = 0x19B9026B510; // Unknown = 
        public const ulong FFlagAppChatMigrateScrollIntervalTracker2 = 0x19BA802A750; // Unknown = 
        public const ulong FFlagAppChatMomentShareCard = 0x19BACE77910; // Unknown = 
        public const ulong FFlagAppChatMomentShareCardNavigation = 0x19B9ACB9690; // Unknown = 
        public const ulong FFlagAppChatMomentShareCardUseFoundationImage = 0x19BA8024490; // Unknown = 
        public const ulong FFlagAppChatMoveMainComponent = 0x19B82B7EF1D; // Bool = false
        public const ulong FFlagAppChatNativeFoundationCornerRadii = 0x19BA8021D10; // Unknown = 
        public const ulong FFlagAppChatNavigateBackIfOSAUnacknowledged = 0x19B8C2E2690; // Unknown = 
        public const ulong FFlagAppChatNewChatFixEnabled = 0x19B8C2E2A10; // Unknown = 
        public const ulong FFlagAppChatNewChatInputBar = 0x19BACE72D90; // Unknown = 
        public const ulong FFlagAppChatNewChatInputBar2 = 0x19BACE72B90; // Unknown = 
        public const ulong FFlagAppChatNewChatInputBarIxpEnabled = 0x19BACE71390; // Unknown = 
        public const ulong FFlagAppChatNewSquadJoinButtonLookIconless = 0x19BACE7FB50; // Unknown = 
        public const ulong FFlagAppChatNilGuardMessageSort = 0x19B9026A690; // Unknown = 
        public const ulong FFlagAppChatNilGuardReceivedChatResponse = 0x19B9026B7D0; // Unknown = 
        public const ulong FFlagAppChatOnConsoles_Dev = 0x19BA6A3ACD0; // Unknown = 
        public const ulong FFlagAppChatPCMFixBlocking = 0x19BACFD49D0; // Unknown = 
        public const ulong FFlagAppChatParticipantDialogGamepadFocus = 0x19B8FA1549D; // Bool = false
        public const ulong FFlagAppChatPerfTracking = 0x19BA6070FD0; // Unknown = 
        public const ulong FFlagAppChatPerfTracking3 = 0x19BA607F3D0; // Unknown = 
        public const ulong FFlagAppChatPresenceStoreMigration = 0x19BA6B3FC1D; // Bool = false
        public const ulong FFlagAppChatPresenceStoreMigration_v1 = 0x19BA7DA1D8D; // Bool = false
        public const ulong FFlagAppChatReactToFaeForOsa = 0x19BAC4BCE65; // Bool = true
        public const ulong FFlagAppChatRefactorChatMessage = 0x19BA8026A90; // Unknown = 
        public const ulong FFlagAppChatRemoveConversationListDivider = 0x19BACE7A6D0; // Unknown = 
        public const ulong FFlagAppChatRemoveConversationListDividerIxpEnabled = 0x19B8FA1E490; // Unknown = 
        public const ulong FFlagAppChatRemoveDynamicRequires = 0x19BAE779905; // Bool = true
        public const ulong FFlagAppChatRemoveNotifications = 0x19B8C2E1190; // Unknown = 
        public const ulong FFlagAppChatRemoveToggleChatPaused = 0x19B8C2E1BD0; // Unknown = 
        public const ulong FFlagAppChatRemoveUserProfileTitles2 = 0x19B94A150ED; // Bool = true
        public const ulong FFlagAppChatReplyComposeBarContainer = 0x19BACE72FD0; // Unknown = 
        public const ulong FFlagAppChatReplyComposeBarContainer2 = 0x19BACE7E410; // Unknown = 
        public const ulong FFlagAppChatRequestedRoute = 0x19BA6079C90; // Unknown = 
        public const ulong FFlagAppChatResolveShareLinkV2 = 0x19B9026BE50; // Unknown = 
        public const ulong FFlagAppChatSanitizeConversationTitleRichText = 0x19B8C2E21D0; // Unknown = 
        public const ulong FFlagAppChatScrollFrameTimeTracking = 0x19BA6070250; // Unknown = 
        public const ulong FFlagAppChatShowOSAOnPageEntry2 = 0x19B8C2E2810; // Unknown = 
        public const ulong FFlagAppChatShutdownBeforeLaunch = 0x19BA802AED0; // Unknown = 
        public const ulong FFlagAppChatSignalsMessageStore = 0x19BA6B3FA10; // Unknown = 
        public const ulong FFlagAppChatSignalsMessageStore5 = 0x19B8FA15FDD; // Bool = false
        public const ulong FFlagAppChatSignalsReplyStore = 0x19B8FA15BD0; // Unknown = 
        public const ulong FFlagAppChatSmartSuggestions = 0x19BACE71790; // Unknown = 
        public const ulong FFlagAppChatSquadButtonColorUpdate = 0x19BACE7FAD0; // Unknown = 
        public const ulong FFlagAppChatSquadButtonColorUpdateIxpEnabled = 0x19BACE778D0; // Unknown = 
        public const ulong FFlagAppChatSquadButtonColorVariantB = 0x19BACE73710; // Unknown = 
        public const ulong FFlagAppChatSquadButtonHideGamepadIconOnTvRemote = 0x19BACE76110; // Unknown = 
        public const ulong FFlagAppChatSquadJoinButtonU13OSA = 0x19BAFCF76D0; // Unknown = 
        public const ulong FFlagAppChatTimestampInSubtitle = 0x19BC0A66915; // Bool = false
        public const ulong FFlagAppChatTimestampInSubtitleIxpEnabled = 0x19BB6C1D205; // Bool = false
        public const ulong FFlagAppChatTopBarConfigDriven = 0x19BA6B3A91D; // Bool = false
        public const ulong FFlagAppChatTopBarConfigDrivenV6 = 0x19B8FA15C1D; // Bool = false
        public const ulong FFlagAppChatTopBarSignalsStore = 0x19BA6B3F65D; // Bool = false
        public const ulong FFlagAppChatTopBarSignalsStoreV2 = 0x19B8FA15ADD; // Bool = false
        public const ulong FFlagAppChatUnreadMessageCountStore = 0x19B8FC3759D; // Bool = false
        public const ulong FFlagAppChatUseNewConversationRow = 0x19B8FA1CE10; // Unknown = 
        public const ulong FFlagAppChatUseProfileFrameThumbnail = 0x19BACE77790; // Unknown = 
        public const ulong FFlagAppChatUseSwipeForReplies = 0x19BA802FD90; // Unknown = 
        public const ulong FFlagAppChatUseSwipeForReplies2 = 0x19BA8025750; // Unknown = 
        public const ulong FFlagAppChatUseSymmetricSwipe = 0x19BA3A88E0D; // Bool = false
        public const ulong FFlagAppChatUseTextBoxTextOnSend = 0x19BACE7F690; // Unknown = 
        public const ulong FFlagAppChatUseUltimateListConversationList = 0x19B8FA1C9D0; // Unknown = 
        public const ulong FFlagAppContainerReadyToRender = 0x19BA5538FD0; // Unknown = 
        public const ulong FFlagAppDebugPanel = 0x19B9AF15A90; // Unknown = 
        public const ulong FFlagAppDebugTagAnnotation = 0x19B9AF15BD0; // Unknown = 
        public const ulong FFlagAppFocusWrapperRefactor = 0x19BC0546810; // Unknown = 
        public const ulong FFlagAppHeaderBarUseSizeFull = 0x19BAFCF0BD0; // Unknown = 
        public const ulong FFlagAppIaHomeOmniFeedFix = 0x19B94811150; // Unknown = 
        public const ulong FFlagAppIaHomeSubTab = 0x19B9ACB15D0; // Unknown = 
        public const ulong FFlagAppIaHomeSubTabAnalytics = 0x19B9ACBBF10; // Unknown = 
        public const ulong FFlagAppIaHomeSubTabScrollAwayFull = 0x19B9ACB1A50; // Unknown = 
        public const ulong FFlagAppIaScopedScrollAway = 0x19B9ACB2E50; // Unknown = 
        public const ulong FFlagAppIaScrollAway = 0x19B9ACB6BD0; // Unknown = 
        public const ulong FFlagAppIaScrollAway9 = 0x19B9ACB1090; // Unknown = 
        public const ulong FFlagAppIaScrollAwayDisableChat = 0x19B90643FDD; // Bool = false
        public const ulong FFlagAppIaScrollAwayFixSocial = 0x19B9ACBCB10; // Unknown = 
        public const ulong FFlagAppIaScrollAwayGuac = 0x19B9ACBDA10; // Unknown = 
        public const ulong FFlagAppIaScrollAwayIgnoreHorizontal = 0x19BA60984D0; // Unknown = 
        public const ulong FFlagAppIaScrollAwayPinHeader = 0x19B9ACB9150; // Unknown = 
        public const ulong FFlagAppIaStatusBar = 0x19B9ACB8D90; // Unknown = 
        public const ulong FFlagAppIaStatusBar3 = 0x19B9ACB1DD0; // Unknown = 
        public const ulong FFlagAppNavBarFooterVisibleWithoutScrollAway = 0x19BA6093CDD; // Bool = false
        public const ulong FFlagAppNavBarGateFooterVisibleOnPlacement = 0x19BA60929DD; // Bool = false
        public const ulong FFlagAppNavBarPerItemThemeOverride2 = 0x19B9AF17250; // Unknown = 
        public const ulong FFlagAppNavDeviceTier = 0x19BA60975DD; // Bool = false
        public const ulong FFlagAppNavLabelScaling = 0x19B9ACB7250; // Unknown = 
        public const ulong FFlagAppNavMyStatsTab3 = 0x19B9AF138D0; // Unknown = 
        public const ulong FFlagAppNavTelemetryLogger = 0x19B9ACB6D10; // Unknown = 
        public const ulong FFlagApplyLaunchContextForNewAccountSwitches = 0x19B945A5BD0; // Unknown = 
        public const ulong FFlagApplyResolutionScale = 0x19B8578A2DD; // Bool = false
        public const ulong FFlagArgoEnableMoments = 0x19B9ACB2890; // Unknown = 
        public const ulong FFlagArgusTabImpliesFlyout = 0x19B9ACB0750; // Unknown = 
        public const ulong FFlagAudioPlayerCanSkipTracks = 0x19B9ACBA9D0; // Unknown = 
        public const ulong FFlagAudioPreviewLua = 0x19D86F064D0; // Unknown = 
        public const ulong FFlagAuthBirthdayBarFoundationColors = 0x19B88C4AE90; // Unknown = 
        public const ulong FFlagAuthCollapsingValidatorFoundationInput2 = 0x19B9ACBE2D0; // Unknown = 
        public const ulong FFlagAuthFlowProviderEnabled = 0x19B85788B1D; // Bool = false
        public const ulong FFlagAuthFlowStandaloneEnabled = 0x19D88FB0D45; // Bool = false
        public const ulong FFlagAuthFlowStandaloneEnabledDev = 0x19B85788BDD; // Bool = false
        public const ulong FFlagAuthNewModalSchematization = 0x19B90294B50; // Unknown = 
        public const ulong FFlagAuthValidatorStyleOverrides = 0x19B9ACB2A90; // Unknown = 
        public const ulong FFlagAuthValidatorStyleOverrides3 = 0x19B9ACBA3D0; // Unknown = 
        public const ulong FFlagAvatarAutocompleteEnabledForAll2 = 0x19B9029FED0; // Unknown = 
        public const ulong FFlagAvatarContextMenuItemsChatButtonRefactor = 0x19BA6078D5D; // Bool = false
        public const ulong FFlagAvatarHeadshotIconUseProfileFrameThumbnail = 0x19B859CA6D0; // Unknown = 
        public const ulong FFlagAvatarJointUpgradeInUA = 0x19B9AF1ADD0; // Unknown = 
        public const ulong FFlagAvatarJointUpgradeInUA3 = 0x19B99717810; // Unknown = 
        public const ulong FFlagAvatarPreviewerDisambiguationMenuModal = 0x19B82A7F11D; // Bool = true
        public const ulong FFlagAvatarSwitcherAccurateAvatarWarning = 0x19BA3A52DD0; // Unknown = 
        public const ulong FFlagAvatarSwitcherCounters = 0x19BA3A56C90; // Unknown = 
        public const ulong FFlagAvatarSwitcherExpiredItemsWarning = 0x19BA3A5A61D; // Bool = false
        public const ulong FFlagAvatarSwitcherMakeupSupport = 0x19BAC878B08; // Unknown = 
        public const ulong FFlagAvatarSwitcherUiFixes = 0x19BA3A531D0; // Unknown = 
        public const ulong FFlagAvatarSwitcherUseAvatarInventoryEndpoint = 0x19BA3A50D10; // Unknown = 
        public const ulong FFlagAvatarSwitcherWarningLayoutFix = 0x19BA3A53C90; // Unknown = 
        public const ulong FFlagBackpackResponsiveUnits = 0x19B9AF19B50; // Unknown = 
        public const ulong FFlagBadgeVisibilitySettingEnabled = 0x19BA59BB310; // Unknown = 
        public const ulong FFlagBadgeVisibilitySettingEnabled_v3 = 0x19BA59BF050; // Unknown = 
        public const ulong FFlagBasedExposureLoggingCatalogPage = 0x19BA3A593D0; // Unknown = 
        public const ulong FFlagBatchVoiceParticipantsUpdates = 0x19B8FDEA71D; // Bool = false
        public const ulong FFlagBehaviorCollectionControlEnabled = 0x19BB6BBE19D; // Bool = true
        public const ulong FFlagBlackbirdRequiresIAP = 0x19BA6A30FD0; // Unknown = 
        public const ulong FFlagBlackbirdUpdateStringFlyoutMenu = 0x19BA6A32550; // Unknown = 
        public const ulong FFlagBlackbirdUpsellGateResale = 0x19B9EE00B1D; // Bool = false
        public const ulong FFlagBlackbirdUpsellGateResaleAndTimedOption = 0x19B9EE0065D; // Bool = false
        public const ulong FFlagBlackbirdUpsellGateTimedOption = 0x19B9EE0095D; // Bool = false
        public const ulong FFlagBlackbirdUpsellProd2 = 0x19B9ACBFBD0; // Unknown = 
        public const ulong FFlagBlackbirdUpsellVersion = 0x19B9ACB8210; // Unknown = 
        public const ulong FFlagBlendedSerpUserPresenceInLineEnabled = 0x19BACFDA810; // Unknown = 
        public const ulong FFlagBlockEDPClickthrough = 0x19B8C30309D; // Bool = true
        public const ulong FFlagBlockingConsolePreparePaymentCheck = 0x19BAC8330DD; // Bool = false
        public const ulong FFlagBlockingUtilityClearUnblockedFromBlockedList = 0x19B8FDE9A5D; // Bool = false
        public const ulong FFlagBlockingUtilityRefireOnReplace = 0x19B8FDE9B9D; // Bool = false
        public const ulong FFlagBoldBlackbirdUpsellBannerStroke = 0x19B8FC3351D; // Bool = false
        public const ulong FFlagBoldSearchListPickerSuggestions2 = 0x19B9029F590; // Unknown = 
        public const ulong FFlagBuildAudiencePublishPrompt = 0x19BAD1A644D; // Bool = false
        public const ulong FFlagBuildBackButtonChevron = 0x19BAD1ADB75; // Bool = true
        public const ulong FFlagBuildDesktopReadiness = 0x19BAD08003D; // Bool = false
        public const ulong FFlagBuildExperienceAskForLogsSeverityRetention = 0x19BAD587E1D; // Bool = false
        public const ulong FFlagBuildExperienceAssetLibrary = 0x19BAD58C79D; // Bool = false
        public const ulong FFlagBuildExperienceBuyRobuxContext = 0x19BAD58CE90; // Unknown = 
        public const ulong FFlagBuildExperienceChatHistoryLoadingSkeleton = 0x19BAD5888DD; // Bool = false
        public const ulong FFlagBuildExperienceChatHistoryPrefetch = 0x19BAD58819D; // Bool = false
        public const ulong FFlagBuildExperienceClientDataModelTools2 = 0x19B9AF14110; // Unknown = 
        public const ulong FFlagBuildExperienceConfigurableProductionTemplatePlaceId = 0x19BAD5883DD; // Bool = false
        public const ulong FFlagBuildExperienceCopyChatMessages = 0x19BAD58A91D; // Bool = false
        public const ulong FFlagBuildExperienceCreatorCreditUsageBadge = 0x19BAD5840DD; // Bool = false
        public const ulong FFlagBuildExperienceDontAskAgainPushUpsell = 0x19BAD58C05D; // Bool = false
        public const ulong FFlagBuildExperienceExcludeUserWaitFromTurnDuration = 0x19BAD58A65D; // Bool = false
        public const ulong FFlagBuildExperienceFixChatBottomLock = 0x19BAD586F9D; // Bool = false
        public const ulong FFlagBuildExperienceFixChatComposerInitialSendState = 0x19BAD585CDD; // Bool = false
        public const ulong FFlagBuildExperienceMyCreationsUseAudiences = 0x19BAD58D710; // Unknown = 
        public const ulong FFlagBuildExperienceMyCreationsUseUniverseList = 0x19BAD58DC5D; // Bool = false
        public const ulong FFlagBuildExperiencePersistPlaytestLogs = 0x19BAD58735D; // Bool = false
        public const ulong FFlagBuildExperiencePrivateInvites = 0x19BAD583B1D; // Bool = false
        public const ulong FFlagBuildExperienceRichTextUserMessages = 0x19BAD58B61D; // Bool = false
        public const ulong FFlagBuildExperienceSecondActivateAfterSetAudiences = 0x19BAD58E1D0; // Unknown = 
        public const ulong FFlagBuildExperienceShareUseUniverseSummary = 0x19B9AF15790; // Unknown = 
        public const ulong FFlagBuildExperienceShowThinkingBeforeUniverseCreation = 0x19BAD58755D; // Bool = false
        public const ulong FFlagBuildExperienceSinglePlaytestCard = 0x19BAD584D1D; // Bool = false
        public const ulong FFlagBuildExperienceStableMyCreationsListItems = 0x19D80291CD0; // Unknown = 
        public const ulong FFlagBuildExperienceStableMyCreationsListItems2 = 0x19BAD58E2DD; // Bool = false
        public const ulong FFlagBuildExperienceToolResultFailureRecovery = 0x19BAD5861DD; // Bool = false
        public const ulong FFlagBuildExperienceTooltipsLightDismiss = 0x19BAD2874DD; // Bool = false
        public const ulong FFlagBuildExperienceUseCommonTextArea = 0x19BAD58601D; // Bool = false
        public const ulong FFlagBuildExperienceUseFoundationSheet = 0x19BAD28A850; // Unknown = 
        public const ulong FFlagBuildExperienceUserMessageHapticFeedback = 0x19BAD58B99D; // Bool = false
        public const ulong FFlagBuildLocalization = 0x19B9AF15390; // Unknown = 
        public const ulong FFlagBuildNoPublishOnRevert = 0x19BAD58085D; // Bool = false
        public const ulong FFlagBuildPublishAccountTooNewError = 0x19BACE7109D; // Bool = false
        public const ulong FFlagBuildRehydrateOnPublish = 0x19BAD58D310; // Unknown = 
        public const ulong FFlagBuildTabBetweenMeAndChat = 0x19B859CADD0; // Unknown = 
        public const ulong FFlagBuilderSansNavbarFlagSize = 0x19B90649450; // Unknown = 
        public const ulong FFlagBulkPurchaseCloseOnEscape = 0x19B9F925A1D; // Bool = false
        public const ulong FFlagBulkPurchaseEnablePurchaseOptions = 0x19B9F927CD0; // Unknown = 
        public const ulong FFlagBulkPurchaseHandleMissingFulfillmentGroupsKey = 0x19B9F928F50; // Unknown = 
        public const ulong FFlagBulkPurchaseUsesPurchaseOptionDiscount = 0x19B9F9292DD; // Bool = false
        public const ulong FFlagBypassKeystoreLoginIxpV2 = 0x19B9ACBF210; // Unknown = 
        public const ulong FFlagCIDeeplinkEnabledForAll = 0x19BACFD1410; // Unknown = 
        public const ulong FFlagCTAChangeMorePageFlyoutButtonText = 0x19BA553C7D0; // Unknown = 
        public const ulong FFlagCacheCredentialsProtocolIsAvailable = 0x19B8FC38590; // Unknown = 
        public const ulong FFlagCacheReadParsePolicy = 0x19BB6BBCC10; // Unknown = 
        public const ulong FFlagCacheShouldShowPushUpsellHideResponse = 0x19B8FA1F650; // Unknown = 
        public const ulong FFlagCapturePermissionsPromptFreeMouse = 0x19BAE74012D; // Bool = true
        public const ulong FFlagCaptureServiceRetrieveCapturesSafeguard = 0x19BAC87DD50; // Unknown = 
        public const ulong FFlagCapturesAddLegacyVideoRecordingLogging_v2 = 0x19D86F07390; // Unknown = 
        public const ulong FFlagCapturesDragEdgeOffsetEnabled = 0x19D86F08C50; // Unknown = 
        public const ulong FFlagCapturesEnableDownloadPromptForU13 = 0x19D86F00890; // Unknown = 
        public const ulong FFlagCapturesFetchUseSharedUtility = 0x19D86EC1E55; // Bool = false
        public const ulong FFlagCapturesGalleryDespawnOnMenuClose = 0x19D86F06A10; // Unknown = 
        public const ulong FFlagCapturesLayerExposureLoggingEnabled = 0x19D86F04210; // Unknown = 
        public const ulong FFlagCapturesPostEnabledForAll = 0x19BACFD16D0; // Unknown = 
        public const ulong FFlagCapturesPostEnabledForAll_v4 = 0x19BACFD4490; // Unknown = 
        public const ulong FFlagCapturesPromptShareImageFixEnabled = 0x19D86F0D1D0; // Unknown = 
        public const ulong FFlagCapturesRecursiveCoreUIRemoval = 0x19BA6C4089D; // Bool = false
        public const ulong FFlagCapturesUpdateUsePlayShutterSoundTesting = 0x19BAE77E92D; // Bool = true
        public const ulong FFlagCapturesVideoBulkManagerStopGap = 0x19BAC87C2DD; // Bool = false
        public const ulong FFlagCapturesVideoCaptureTriggerHandlerEnabled = 0x19D87046310; // Unknown = 
        public const ulong FFlagCapturesVideoDeleteAsync = 0x19BACE9339D; // Bool = false
        public const ulong FFlagCapturesVideoSupportLegacyVideos = 0x19BAC87C49D; // Bool = false
        public const ulong FFlagCarouselUseNewUserTileWithPresenceIcon = 0x19B8EE09C3D; // Bool = false
        public const ulong FFlagCarouselUserTileUseProfileFrameThumbnail = 0x19B8F90EC5D; // Bool = false
        public const ulong FFlagCenterShiftLockOverride = 0x19B9FD8B7DD; // Bool = false
        public const ulong FFlagChallengeInterceptorResolveOriginalNetworkImpl = 0x19B902922D0; // Unknown = 
        public const ulong FFlagChangeSocialGraphLifecycleEvent = 0x19B9ACBDB10; // Unknown = 
        public const ulong FFlagChangeToggleMicText = 0x19B9FDD17D5; // Bool = false
        public const ulong FFlagCharacterNameHandlerUserProfileApiEnabledForAll = 0x19B8C2E92D0; // Unknown = 
        public const ulong FFlagChartsHydrationStreaming2 = 0x19B88C28EDD; // Bool = false
        public const ulong FFlagChatIntegrationFixShortcut = 0x19B9FDD1815; // Bool = false
        public const ulong FFlagChatLineReportingFocusFixesEnabled = 0x19B8C30CC1D; // Bool = true
        public const ulong FFlagChatLineReportingGlobalMuteEnabled2 = 0x19B8C30CE5D; // Bool = true
        public const ulong FFlagChatModeratedMaskRandomLength = 0x19B8C305210; // Unknown = 
        public const ulong FFlagChatOptimizeCommandProcessing = 0x19BA3A5575D; // Bool = false
        public const ulong FFlagChatSnoozeMenuDescriptionFixEnabled = 0x19BAFCF65D0; // Unknown = 
        public const ulong FFlagChatSummariesSettingEnabled3 = 0x19B8C302E9D; // Bool = true
        public const ulong FFlagChatTabHideGroupsLinkOnVR = 0x19B8FA1F49D; // Bool = false
        public const ulong FFlagChatTranslationForceSetting = 0x19B9FD8C25D; // Bool = false
        public const ulong FFlagChatTranslationHoldoutEnabled = 0x19B9FD8BCD0; // Unknown = 
        public const ulong FFlagChatTranslationNewDefaults = 0x19B9FD8C41D; // Bool = false
        public const ulong FFlagChatTranslationSettingEnabled3 = 0x19B9AF10650; // Unknown = 
        public const ulong FFlagChatTranslationShowFTUX = 0x19BA6B3F890; // Unknown = 
        public const ulong FFlagChatTranslationWaitForIXP = 0x19B9FD8C09D; // Bool = false
        public const ulong FFlagChatWindowUseCallbackOptimizations = 0x19BA5153C9D; // Bool = false
        public const ulong FFlagCheckCameraAvailabilityBeforePermissions = 0x19BA4E9B450; // Unknown = 
        public const ulong FFlagCheckForUpdatePromise2 = 0x19B9AF1ACD0; // Unknown = 
        public const ulong FFlagCheckUniversePlaceBeforeSuspending = 0x19BACFDF750; // Unknown = 
        public const ulong FFlagCheckUserModerationAfterLogin = 0x19B8C30B750; // Unknown = 
        public const ulong FFlagChromeCentralizedConfiguration4 = 0x19B9ACB75D0; // Unknown = 
        public const ulong FFlagChromeChatGamepadSupportFix = 0x19B9ACB86D0; // Unknown = 
        public const ulong FFlagChromeDeprecateMRUs = 0x19B9481539D; // Bool = false
        public const ulong FFlagChromeMusicWindowTopbarReappearsOnGamepad = 0x19B9ACB8CD0; // Unknown = 
        public const ulong FFlagChromeShortcutAddRespawnLeaveToIEM = 0x19B9ACB1B10; // Unknown = 
        public const ulong FFlagChromeShortcutChatOpenKeyboard = 0x19B9ACB6690; // Unknown = 
        public const ulong FFlagChromeShortcutRemoveLeaveOnRespawnPage = 0x19B9ACB3390; // Unknown = 
        public const ulong FFlagChromeShortcutRemoveRespawnOnLeavePage = 0x19B9ACB0350; // Unknown = 
        public const ulong FFlagChromeWindowSignalConstraintsToggle = 0x19B88C4F410; // Unknown = 
        public const ulong FFlagCiDeprecateFindFriendsModal = 0x19BA59BE51D; // Bool = false
        public const ulong FFlagCleanUpAXAlternativeLandingPageIXP = 0x19B90647EDD; // Bool = false
        public const ulong FFlagClearPolicyOnLogout = 0x19BB6BBCCD0; // Unknown = 
        public const ulong FFlagClearProductInfoCachesOnPriceChanged = 0x19D85DCA450; // Unknown = 
        public const ulong FFlagClearUserFromRecentVoiceDataOnLeave = 0x19B8FDEA0DD; // Bool = false
        public const ulong FFlagClientErrorAdditionalArgs = 0x19BBC1C1D5D; // Bool = false
        public const ulong FFlagClientToastNotificationsRedirect4 = 0x19BACFEAD50; // Unknown = 
        public const ulong FFlagCloseBadgeSheetOnAbuseReport2 = 0x19BA5533650; // Unknown = 
        public const ulong FFlagCloseFavoritePromptWithB = 0x19B9F29279D; // Bool = false
        public const ulong FFlagCollectiblesCatalogFollowUpForSaleLocation = 0x19B9026F910; // Unknown = 
        public const ulong FFlagCollectionViewMathChanges = 0x19B88C25BD0; // Unknown = 
        public const ulong FFlagCommunitiesUseVisualConfigUtil2 = 0x19BC0546B90; // Unknown = 
        public const ulong FFlagCompleteFlowInStudioAccept = 0x19BAC836FDD; // Bool = false
        public const ulong FFlagConfirmationButtonsUseGreyButtons = 0x19B9FD86E15; // Bool = false
        public const ulong FFlagConnectionAmpParentalApprovalUpsell = 0x19BA553F790; // Unknown = 
        public const ulong FFlagConnectionAmpUpsellOnLeave = 0x19BA553AE10; // Unknown = 
        public const ulong FFlagConnectionChannelsTileSize = 0x19B8C2E4790; // Unknown = 
        public const ulong FFlagConnectionEnableAutoReconnect = 0x19BA672C6DD; // Bool = false
        public const ulong FFlagConnectionManagementChips_V3 = 0x19B8C3034DD; // Bool = true
        public const ulong FFlagConnectionRemoveLoadingTimeout = 0x19B9985639D; // Bool = false
        public const ulong FFlagConnectionUpsellAnalytics = 0x19BA5537550; // Unknown = 
        public const ulong FFlagConnectionsHubLayerExposure = 0x19B949FA42D; // Bool = false
        public const ulong FFlagConnectionsToFriendsRename = 0x19BA59BDED0; // Unknown = 
        public const ulong FFlagConnectionsToFriendsRename1 = 0x19BA59BB810; // Unknown = 
        public const ulong FFlagConnectionsToFriendsRenameP1_v1 = 0x19BA59B595D; // Bool = false
        public const ulong FFlagConsoleApplyTokenizationEdp = 0x19B8578A1DD; // Bool = false
        public const ulong FFlagConsoleChatUseChromeFocusUtils = 0x19B9ACB43D0; // Unknown = 
        public const ulong FFlagConsoleCloseAffordanceFix = 0x19BA6076A9D; // Bool = true
        public const ulong FFlagConsoleVoiceIXPEnabled = 0x19B8FDE9A10; // Unknown = 
        public const ulong FFlagContactImportButtonsExperimentEnabled = 0x19BAFCF9D10; // Unknown = 
        public const ulong FFlagContactImporterIXPCleanup = 0x19BA59B6B10; // Unknown = 
        public const ulong FFlagContactsListEmojiSorting = 0x19BAFCFAA90; // Unknown = 
        public const ulong FFlagContactsListEmojiSortingIXP = 0x19B8EAE1530; // Unknown = 
        public const ulong FFlagContactsListEmojiSortingIxpEnabled = 0x19BAFCFAF50; // Unknown = 
        public const ulong FFlagContactsListEntryUpdatedTruncationFix = 0x19BAFB25B50; // Unknown = 
        public const ulong FFlagContentFeedEnableReactions = 0x19BACFD9050; // Unknown = 
        public const ulong FFlagCoreMicManagerRefactor = 0x19B8FDEB8D0; // Unknown = 
        public const ulong FFlagCoreScriptBacktraceRepeatedErrorRateLimiting = 0x19BA5537EDD; // Bool = false
        public const ulong FFlagCoreScriptShowTeleportPrompt = 0x19B9FDD4C55; // Bool = false
        public const ulong FFlagCoreScriptsProfilerTelemetryContext = 0x19B9AF12050; // Unknown = 
        public const ulong FFlagCoreUiMigrateUIBloxToFoundation = 0x19B9AF13790; // Unknown = 
        public const ulong FFlagCoreUiMigrateUIBloxToFoundation2 = 0x19B9AF13490; // Unknown = 
        public const ulong FFlagCreateConnectionsHub_v6 = 0x19B8C2E2D50; // Unknown = 
        public const ulong FFlagCreateMomentsToast = 0x19BBF256310; // Unknown = 
        public const ulong FFlagCreateMomentsToast_v3 = 0x19BB6B28995; // Bool = false
        public const ulong FFlagCreatorAgentChatFilterTerminalClientTools = 0x19BAD28809D; // Bool = false
        public const ulong FFlagCreatorAgentChatParseDirectPublishVersion = 0x19B9AF155D0; // Unknown = 
        public const ulong FFlagCreatorAgentChatStrictAskUserToolName = 0x19BAD28841D; // Bool = false
        public const ulong FFlagCreatorSubtitleNavigationIXPEnabled = 0x19B8EDC6D5D; // Bool = false
        public const ulong FFlagCrossPlayActuallyResetErrorStates = 0x19B859CA95D; // Bool = false
        public const ulong FFlagCurrencyTransferCenterRobuxIcon = 0x19B9F92A150; // Unknown = 
        public const ulong FFlagCurrencyTransferDeepLinkValidateSender = 0x19B8C2EB89D; // Bool = false
        public const ulong FFlagCurrencyTransferFixDesktopInput = 0x19B9F92C85D; // Bool = false
        public const ulong FFlagCurrencyTransferFixHeaderTouchPadding = 0x19B9F92B110; // Unknown = 
        public const ulong FFlagCurrencyTransferFixTextBoxInput = 0x19B9F92B090; // Unknown = 
        public const ulong FFlagCurrencyTransferFlowUIImprovementFix = 0x19B9F92B510; // Unknown = 
        public const ulong FFlagCurrencyTransferReceiveLimitExceededError = 0x19B9F92D390; // Unknown = 
        public const ulong FFlagCurrencyTransferSignalRecipientOnComplete = 0x19B9F92E55D; // Bool = false
        public const ulong FFlagCurrencyTransferSuccessModal = 0x19B9F92FC1D; // Bool = false
        public const ulong FFlagCurrencyTransferUseAmpWizardContainerForInApp = 0x19B9F92EB10; // Unknown = 
        public const ulong FFlagCurrencyTransferUseBackendTransferLimitsV1 = 0x19B9F92CA5D; // Bool = false
        public const ulong FFlagCurrencyTransferUseProfileFrameThumbnail = 0x19B9F92B7D0; // Unknown = 
        public const ulong FFlagCurrencyTransferUseRoactNetworking = 0x19B9F92FE9D; // Bool = false
        public const ulong FFlagDSAConsequenceTransparency = 0x19BC05413D0; // Unknown = 
        public const ulong FFlagDSAIllegalContentReporting2 = 0x19BC0547A50; // Unknown = 
        public const ulong FFlagDSALuaGeoGateBEDUIDevMode = 0x19BC0546210; // Unknown = 
        public const ulong FFlagDSAVRSkipFrontendGeoCheck = 0x19BC0541590; // Unknown = 
        public const ulong FFlagDeactivateAudioDeviceOnVoiceLeave = 0x19B8FDEB95D; // Bool = false
        public const ulong FFlagDebounceVoiceSelectorIndexChange = 0x19B9FD8C01D; // Bool = false
        public const ulong FFlagDebugAEGIS1AppChatBanner = 0x19B9026C15D; // Bool = false
        public const ulong FFlagDebugAPPEXP4747B = 0x19BA6C4099D; // Bool = false
        public const ulong FFlagDebugAlwaysShowDisableCameraToast = 0x19B9FD894D0; // Unknown = 
        public const ulong FFlagDebugAlwaysShowSystemTrayModal = 0x19B9ACB1910; // Unknown = 
        public const ulong FFlagDebugAppChat = 0x19BA8026B90; // Unknown = 
        public const ulong FFlagDebugAppChatDisplayOnJoin = 0x19B9987EE55; // Bool = true
        public const ulong FFlagDebugAppChatEnableDomLocators = 0x19B8C2E1150; // Unknown = 
        public const ulong FFlagDebugAppChatFae = 0x19B9026C0DD; // Bool = false
        public const ulong FFlagDebugCrossPlaySystemUi = 0x19BB6BB325D; // Bool = false
        public const ulong FFlagDebugDefaultChannelStartMuted = 0x19B9F0AB850; // Unknown = 
        public const ulong FFlagDebugEnableChromeOnUnsupportedDevices = 0x19BA3BBD7D0; // Unknown = 
        public const ulong FFlagDebugEnableErrorStringTesting = 0x19BA672B9D0; // Unknown = 
        public const ulong FFlagDebugEnableImageLoadObserver = 0x19B9481299D; // Bool = false
        public const ulong FFlagDebugEnableImpressionsVisualizer = 0x19B8F90EE9D; // Bool = false
        public const ulong FFlagDebugEnablePageLoadTrackerVisualizer = 0x19B8578BD1D; // Bool = false
        public const ulong FFlagDebugEnablePioneerUX = 0x19B9ACB7750; // Unknown = 
        public const ulong FFlagDebugEnableUnibarDummyIntegrations = 0x19B9ACB6A50; // Unknown = 
        public const ulong FFlagDebugEnableVRFTUXExperienceInStudio = 0x19BAEB77210; // Unknown = 
        public const ulong FFlagDebugExpChat = 0x19B9F0AC2DD; // Bool = false
        public const ulong FFlagDebugExpChatAlwaysRunTCS = 0x19BACFD1E90; // Unknown = 
        public const ulong FFlagDebugExpChatPerf = 0x19BA6B3F29D; // Bool = false
        public const ulong FFlagDebugForceConsoleSafeInsets = 0x19BA6A39450; // Unknown = 
        public const ulong FFlagDebugForceEnableChatButtonOn = 0x19BA6B3EED0; // Unknown = 
        public const ulong FFlagDebugForceShowIllegalContentReportingUI = 0x19BB6BBE91D; // Bool = true
        public const ulong FFlagDebugFriendsChat = 0x19BACFD591D; // Bool = false
        public const ulong FFlagDebugImmersionModeNonVR = 0x19B9F0A6090; // Unknown = 
        public const ulong FFlagDebugInlineLayout = 0x19BBE2F963D; // Bool = false
        public const ulong FFlagDebugLuaAppAlwaysUseGamepad = 0x19BC054DDD0; // Unknown = 
        public const ulong FFlagDebugLuaAppEnableScale = 0x19BA461009D; // Bool = false
        public const ulong FFlagDebugLuaAppEnableTokenScale = 0x19BA3A7F010; // Unknown = 
        public const ulong FFlagDebugLuaAppThrowErrorInStarterScript = 0x19B90295510; // Unknown = 
        public const ulong FFlagDebugLuaAppValidateProps = 0x19B857825DD; // Bool = false
        public const ulong FFlagDebugLuaAppsUseDarkTheme = 0x19B8C31695D; // Bool = false
        public const ulong FFlagDebugLuaArgCheck = 0x19B8C317010; // Unknown = 
        public const ulong FFlagDebugMessageProfiling = 0x19BA51508DD; // Bool = false
        public const ulong FFlagDebugMusicSampleSounds = 0x19D84DA2B90; // Unknown = 
        public const ulong FFlagDebugMyStatsExperienceAgentSpec = 0x19BAD287590; // Unknown = 
        public const ulong FFlagDebugMyStatsExperienceStats = 0x19BAD28A31D; // Bool = false
        public const ulong FFlagDebugOverrideCaptureControlsVideoGuacPolicy = 0x19D86F03910; // Unknown = 
        public const ulong FFlagDebugPrintIntervalPerformanceTrackerResults = 0x19B9CB7E19D; // Bool = false
        public const ulong FFlagDebugReactSchedulingEnableErrorEvents = 0x19BBC7A16D0; // Unknown = 
        public const ulong FFlagDebugRomarkAudioPermissionsBypass = 0x19BB6BB1ED0; // Unknown = 
        public const ulong FFlagDebugScreenSizeUseDisplayStore = 0x19B9026A650; // Unknown = 
        public const ulong FFlagDebugSelfViewPerfBenchmark = 0x19BACFED9D0; // Unknown = 
        public const ulong FFlagDebugShowAccountSecurityPromptBanner = 0x19B9029CF90; // Unknown = 
        public const ulong FFlagDebugShowAudioDeviceInputDebuggerV2 = 0x19BACFD1CD0; // Unknown = 
        public const ulong FFlagDebugShowSiteMessageBanner = 0x19B9029E390; // Unknown = 
        public const ulong FFlagDebugSimulateConnectDisconnect = 0x19BA5158E10; // Unknown = 
        public const ulong FFlagDebugSkipSeamlessVoiceAPICheck = 0x19B9F186B9D; // Bool = true
        public const ulong FFlagDebugSkipVoicePermissionCheck = 0x19B9F18AB4D; // Bool = true
        public const ulong FFlagDebugSquadLogsEnabled = 0x19B8C2E3150; // Unknown = 
        public const ulong FFlagDebugTCUpsellModalEnabled_DEV = 0x19B8C2E2150; // Unknown = 
        public const ulong FFlagDebugTimeToInteractiveTracker = 0x19BA3663F08; // Unknown = 
        public const ulong FFlagDebugUnfilteredThreads = 0x19BACFD0110; // Unknown = 
        public const ulong FFlagDebugUnmuteLuaErrors = 0x19B857878DD; // Bool = false
        public const ulong FFlagDebugUseLegacyCrossPlayApi = 0x19BB6BB4710; // Unknown = 
        public const ulong FFlagDebugVRModeInStudio = 0x19B8C2E9A90; // Unknown = 
        public const ulong FFlagDebugVoiceChatMicPermissionCliBypass = 0x19B8FDEBB50; // Unknown = 
        public const ulong FFlagDefaultChannelEnableDefaultVoice = 0x19B9F0ABFD0; // Unknown = 
        public const ulong FFlagDefaultKidsToDarkTheme = 0x19B9AF17690; // Unknown = 
        public const ulong FFlagDefaultKidsToDarkTheme2 = 0x19B9AF17710; // Unknown = 
        public const ulong FFlagDeferPlayerInfoRequests = 0x19BAD28561D; // Bool = false
        public const ulong FFlagDeferProgrammaticChange = 0x19B9FD8BE1D; // Bool = false
        public const ulong FFlagDeprecateNavigateToUserInfoJoinable = 0x19B90294650; // Unknown = 
        public const ulong FFlagDeprecatePeopleListContextualMenu = 0x19B9F18FEBD; // Bool = true
        public const ulong FFlagDesktopGameJoinCardUIImprovements = 0x19B8C30331D; // Bool = true
        public const ulong FFlagDetailsPageLayoutSeedContainerSize = 0x19B88C21910; // Unknown = 
        public const ulong FFlagDevClosedStartupSequence = 0x19B8578289D; // Bool = false
        public const ulong FFlagDevConsoleAdminSeesDevTabs = 0x19BACFE6290; // Unknown = 
        public const ulong FFlagDevConsoleDownArrowIconFix = 0x19B9FB6F210; // Unknown = 
        public const ulong FFlagDevConsoleDropdownFlipFix = 0x19BACFE0CDD; // Bool = false
        public const ulong FFlagDevConsoleDropdownMultiSelect = 0x19BACFE0DDD; // Bool = false
        public const ulong FFlagDevConsoleFixTimestampDST = 0x19BACE9F3DD; // Bool = false
        public const ulong FFlagDevConsoleMemoryTrackingAlert = 0x19BACFE1B1D; // Bool = false
        public const ulong FFlagDevConsoleMicroProfilerFixAutoTextClear = 0x19BACFE329D; // Bool = false
        public const ulong FFlagDevConsoleMicroProfilerImproveWording = 0x19BACFE2E10; // Unknown = 
        public const ulong FFlagDevConsoleMicroProfilerNewLayout = 0x19BACFE3F5D; // Bool = false
        public const ulong FFlagDevConsoleMpEnableOpenDumpsFolderButton = 0x19BACFE399D; // Bool = false
        public const ulong FFlagDevConsoleRequestOrchestratorTab2 = 0x19BACFE7050; // Unknown = 
        public const ulong FFlagDevConsoleStartDataOnMount = 0x19BACFE015D; // Bool = false
        public const ulong FFlagDevFrameworkMoveEditTree = 0x19B82A7F25D; // Bool = true
        public const ulong FFlagDifferentiateAddAuthMethodPasskeyFlow = 0x19B90291DD0; // Unknown = 
        public const ulong FFlagDifferentiateSharingBaseOnPlatform = 0x19B9FD84E5D; // Bool = false
        public const ulong FFlagDifferentiateVoiceSelectorSystemAndUser = 0x19B9FD8BD1D; // Bool = false
        public const ulong FFlagDisableAppShortcutBarAndroidTV = 0x19BA607C1D0; // Unknown = 
        public const ulong FFlagDisableAutocorrectSocialUserSearch = 0x19BAEE1F750; // Unknown = 
        public const ulong FFlagDisableAutocorrectSocialUserSearch_v2 = 0x19B8C2EA310; // Unknown = 
        public const ulong FFlagDisableBlockAndReport = 0x19B8C2E19D0; // Unknown = 
        public const ulong FFlagDisableCDLQrCodeForMaquettes = 0x19BA5208975; // Bool = false
        public const ulong FFlagDisableCameraOnLowSpecDevices2 = 0x19B9FD8A05D; // Bool = false
        public const ulong FFlagDisableCameraOnLowspecAndroidCalls = 0x19B9F0AC550; // Unknown = 
        public const ulong FFlagDisableCameraOnSelfieViewForLowspecDevices = 0x19BACFECF10; // Unknown = 
        public const ulong FFlagDisableConsentModalForExistingUsers = 0x19B9F18DDDD; // Bool = true
        public const ulong FFlagDisableCopyUsernameOnConsole = 0x19B8C2E0190; // Unknown = 
        public const ulong FFlagDisableCorescriptBacktraceReporting = 0x19BA553A350; // Unknown = 
        public const ulong FFlagDisableEditProfileForVRV2 = 0x19BC0549190; // Unknown = 
        public const ulong FFlagDisableFeedbackSoothsayerCheck = 0x19B9FD8D3DD; // Bool = false
        public const ulong FFlagDisableGoogleAnalyticsErrorReporting = 0x19B8578875D; // Bool = false
        public const ulong FFlagDisableHomePageUpsellCardFeedItem = 0x19BC0541790; // Unknown = 
        public const ulong FFlagDisableLeaveToastInStudio = 0x19BA437003D; // Bool = false
        public const ulong FFlagDisableLegacyChatSimpleUnreadMessageCount = 0x19B9ACB0C1D; // Bool = true
        public const ulong FFlagDisableListenToSessionTerminalStatus = 0x19B90291A50; // Unknown = 
        public const ulong FFlagDisableLuobuWarningToast = 0x19B9AF11710; // Unknown = 
        public const ulong FFlagDisableMemStorageServicePasswordEvent = 0x19B9ACB1990; // Unknown = 
        public const ulong FFlagDisableMessageBusUnSubscribeError = 0x19B9F18DF4D; // Bool = true
        public const ulong FFlagDisableNonSchematizedInGameRobuxUpsellEvent = 0x19BAC83679D; // Bool = false
        public const ulong FFlagDisablePVUpsellDataConsent = 0x19B8C30595D; // Bool = true
        public const ulong FFlagDisablePermissionPromptDeeplink = 0x19BA515909D; // Bool = false
        public const ulong FFlagDisablePlayerListDisplayCloseBtn = 0x19BAD2840D0; // Unknown = 
        public const ulong FFlagDisablePurchasePromptFunctionForMaquettes = 0x19B9EE0155D; // Bool = false
        public const ulong FFlagDisableReactSchedulingAvgMaxMsStats = 0x19BA366FFD0; // Unknown = 
        public const ulong FFlagDisableReactSchedulingTimePctStats = 0x19BA366FA90; // Unknown = 
        public const ulong FFlagDisableRejoinGroupIdDoubleRead = 0x19B8FDEBB9D; // Bool = false
        public const ulong FFlagDisableRobuxUpsell = 0x19D85DCBBD0; // Unknown = 
        public const ulong FFlagDisableVerifyPhoneViewOnSuccess = 0x19BBC38A49D; // Bool = false
        public const ulong FFlagDisableWebViewSupportInStudio = 0x19BB6BB4510; // Unknown = 
        public const ulong FFlagDisallowStickyShortcutBarOnNotLoggedIn = 0x19BA607F750; // Unknown = 
        public const ulong FFlagDisconnectToastClientRewrite = 0x19B8C30561D; // Bool = true
        public const ulong FFlagDiscountInfoForSubscriptionPurchaseModalLua2 = 0x19B9ACBC050; // Unknown = 
        public const ulong FFlagDispatchHybridWebviewWithBypassNavigationLock = 0x19B90291750; // Unknown = 
        public const ulong FFlagDisplayChannelNameOnErrorPrompt = 0x19BA672B21D; // Bool = false
        public const ulong FFlagDisplayCollectiblesIcon = 0x19B9F0A399D; // Bool = false
        public const ulong FFlagDisplayServerChannel = 0x19B88C4E8DD; // Bool = false
        public const ulong FFlagDontAssertOnUserIDInCaptureMetadata = 0x19BAC87D69D; // Bool = false
        public const ulong FFlagDontUseCrossPlayGlobalEffect = 0x19BA6A33490; // Unknown = 
        public const ulong FFlagDrawerScrimCanBeModal = 0x19B9AF1691D; // Bool = false
        public const ulong FFlagDropUnroutableMultiReportOptions = 0x19B8C30C6D0; // Unknown = 
        public const ulong FFlagDynamicHeadsMigration = 0x19BA3A56190; // Unknown = 
        public const ulong FFlagDynamicHeadsMigration7 = 0x19BA3A5D850; // Unknown = 
        public const ulong FFlagEDPTTITrackingEnabled = 0x19B90261110; // Unknown = 
        public const ulong FFlagEarlierFetchTimeForFriendsCarousel_v1 = 0x19BAFCF8250; // Unknown = 
        public const ulong FFlagEasierUnmuting = 0x19BBCD78F90; // Unknown = 
        public const ulong FFlagEasierUnmutingTCS5 = 0x19BBCD79E50; // Unknown = 
        public const ulong FFlagEasierUnmutingVoiceParticipantsMutedReducer = 0x19BA74A085D; // Bool = false
        public const ulong FFlagEditProfileBackgroundEnabled = 0x19BACFD0E90; // Unknown = 
        public const ulong FFlagEditProfileFramesEnabled = 0x19BA6A310D5; // Bool = false
        public const ulong FFlagEditProfileImageV2Enabled = 0x19BACFD5290; // Unknown = 
        public const ulong FFlagEditProfileImageV2Telemetry = 0x19BACFD6F10; // Unknown = 
        public const ulong FFlagEditProfileLandingV2Enabled = 0x19B90643DDD; // Bool = false
        public const ulong FFlagEditProfileNavigateToAvatar = 0x19B9064331D; // Bool = false
        public const ulong FFlagEditProfilePPEStartOnEmotesPage = 0x19B90643C9D; // Bool = false
        public const ulong FFlagEditProfileSetupNewExperimentFlow = 0x19B90642910; // Unknown = 
        public const ulong FFlagEdpGameLeavePromptsHandlerEnabled = 0x19BC0547D10; // Unknown = 
        public const ulong FFlagEdpPlayerFeedbackCommentsOnly = 0x19B9ACB7550; // Unknown = 
        public const ulong FFlagEdpPlayerFeedbackEnabled5 = 0x19B9ACB1350; // Unknown = 
        public const ulong FFlagEdpPlayerFeedbackLogIXPExposure2 = 0x19B9ACB4490; // Unknown = 
        public const ulong FFlagEdpPlayerFeedbackPromptTitleOnly = 0x19B9ACB0DD0; // Unknown = 
        public const ulong FFlagEmit401WebViewDiagnostics = 0x19B9029301D; // Bool = false
        public const ulong FFlagEmitPasskeyRegistrationSourceOnFinish = 0x19B9ACB6A90; // Unknown = 
        public const ulong FFlagEmoteUtilityDefaultMoodFromCharacter = 0x19D89526290; // Unknown = 
        public const ulong FFlagEmoteUtilityReportPoseAnimationDownloadFailure = 0x19D8952ED10; // Unknown = 
        public const ulong FFlagEmoteUtilityUseIdleAnimationFallback = 0x19D8952F650; // Unknown = 
        public const ulong FFlagEmotesStayOpenWithChat = 0x19BA607DE90; // Unknown = 
        public const ulong FFlagEnable2SVRecovery7 = 0x19B9ACB3550; // Unknown = 
        public const ulong FFlagEnableAEGIS2AppChatConversationBanner = 0x19BAEE18F50; // Unknown = 
        public const ulong FFlagEnableAEGIS2AppChatConversationBannerv699 = 0x19B8C2E4350; // Unknown = 
        public const ulong FFlagEnableAEGIS2Upsellv700 = 0x19B8C2E4550; // Unknown = 
        public const ulong FFlagEnableARFlowSession = 0x19D81686290; // Unknown = 
        public const ulong FFlagEnableAbuseReport10ft2 = 0x19BA6A3F29D; // Bool = true
        public const ulong FFlagEnableAbuseReportMutedError = 0x19BA6A3AC10; // Unknown = 
        public const ulong FFlagEnableAbuseReportRevampFeedback = 0x19B90262E1D; // Bool = false
        public const ulong FFlagEnableAbuseReportRevampFlow = 0x19B8DD89D90; // Unknown = 
        public const ulong FFlagEnableAbuseReportRevampFlow_1 = 0x19B8C30B99D; // Bool = true
        public const ulong FFlagEnableAccessBlockAtAppContainerLevel = 0x19BC0545690; // Unknown = 
        public const ulong FFlagEnableAccountCarouselEvents1 = 0x19B9ACB6790; // Unknown = 
        public const ulong FFlagEnableAccountCountdownLabel = 0x19B9F1843CD; // Bool = true
        public const ulong FFlagEnableAccountRecoveryPreAuthDeepLink2 = 0x19B8FC39FDD; // Bool = false
        public const ulong FFlagEnableAccountSettingsUpsell = 0x19B906443DD; // Bool = false
        public const ulong FFlagEnableAccountSwitcherAddWithMaxSignedOut = 0x19B88C4C9D0; // Unknown = 
        public const ulong FFlagEnableAccountSwitcherFoundationDesign9 = 0x19B88C4CA5D; // Bool = false
        public const ulong FFlagEnableAccountSwitcherIXPTextGatingFix = 0x19B88C4C610; // Unknown = 
        public const ulong FFlagEnableAccountSwitcherManageAccounts6 = 0x19B88C4D25D; // Bool = false
        public const ulong FFlagEnableAccountSwitcherSignedOutAccounts5 = 0x19B88C4CE50; // Unknown = 
        public const ulong FFlagEnableAccountSwitcherUncheckedBadge = 0x19B88C4D49D; // Bool = false
        public const ulong FFlagEnableAccountUnlockDeepLink = 0x19B8C30E99D; // Bool = true
        public const ulong FFlagEnableAdConsentAttribution = 0x19B8F90F29D; // Bool = false
        public const ulong FFlagEnableAdDataPlayIntentEventIngest = 0x19B82C6C89D; // Bool = false
        public const ulong FFlagEnableAdDataReferralEventIngest = 0x19B82A7779D; // Bool = true
        public const ulong FFlagEnableAddAuthMethodPageEmailSignup = 0x19B945A6D50; // Unknown = 
        public const ulong FFlagEnableAddAuthMethodPageEmailSignup5 = 0x19B945A0510; // Unknown = 
        public const ulong FFlagEnableAddAuthMethodPageFoundationalizeHeader = 0x19B945A8F90; // Unknown = 
        public const ulong FFlagEnableAddAuthMethodPageFoundationalizeHeader2 = 0x19B945A7490; // Unknown = 
        public const ulong FFlagEnableAddAuthMethodPageFoundationalizeParagraph = 0x19B945A4950; // Unknown = 
        public const ulong FFlagEnableAddAuthMethodPageFoundationalizeParagraph2 = 0x19B945A5FD0; // Unknown = 
        public const ulong FFlagEnableAddAuthMethodPagePasskeyNudgeDirectionalExperiment = 0x19B945A5010; // Unknown = 
        public const ulong FFlagEnableAddAuthMethodPagePasskeyNudgeDirectionalExperiment10 = 0x19B945A4590; // Unknown = 
        public const ulong FFlagEnableAffiliateLinksQualifiedSignUpTracking = 0x19B9ACBBD50; // Unknown = 
        public const ulong FFlagEnableAmpEmailUpsellSupport = 0x19B901123DD; // Bool = false
        public const ulong FFlagEnableAmpIDVUpsellAnalytics = 0x19B90113C1D; // Bool = false
        public const ulong FFlagEnableAmpIDVUpsellPopOnCompletion = 0x19B9011261D; // Bool = false
        public const ulong FFlagEnableAmpIDVUpsellSupport = 0x19B901124DD; // Bool = false
        public const ulong FFlagEnableAmpSubscriptionUpsell = 0x19B901127DD; // Bool = false
        public const ulong FFlagEnableAmpUpsellGQL = 0x19B9011231D; // Bool = false
        public const ulong FFlagEnableAmpUpsellLogging = 0x19B90112BDD; // Bool = false
        public const ulong FFlagEnableAmpUpsellWizard = 0x19B906444DD; // Bool = false
        public const ulong FFlagEnableAmpUserMismatchTelemetry = 0x19B9F18C67D; // Bool = true
        public const ulong FFlagEnableAmpV2Wizard = 0x19B8C2EB75D; // Bool = false
        public const ulong FFlagEnableAmpVPCPrologue = 0x19B901128DD; // Bool = false
        public const ulong FFlagEnableAmpWizardDeepLink = 0x19B8C2E4290; // Unknown = 
        public const ulong FFlagEnableAmpWizardDeepLinkValidateUserId = 0x19B8C2E43D0; // Unknown = 
        public const ulong FFlagEnableAmpWizardInlineVPCForFAE = 0x19B9011299D; // Bool = false
        public const ulong FFlagEnableAmpWizardVPCNavigationFix = 0x19B90112ADD; // Bool = false
        public const ulong FFlagEnableAnalyticsForCameraDevicePermissions = 0x19BA4E92AD0; // Unknown = 
        public const ulong FFlagEnableAndroidAppRatingPromptLua = 0x19BA59B0F55; // Bool = false
        public const ulong FFlagEnableAndroidTvAppPolicies = 0x19BBCD71A50; // Unknown = 
        public const ulong FFlagEnableAndroidWidgetsLuaIXP2 = 0x19B88C4BADD; // Bool = false
        public const ulong FFlagEnableAppAgeSignalsErrorTelemetry = 0x19B948141D0; // Unknown = 
        public const ulong FFlagEnableAppAgeSignalsService = 0x19B94814690; // Unknown = 
        public const ulong FFlagEnableAppChatSnoozeMenuFocus = 0x19B9F18426D; // Bool = true
        public const ulong FFlagEnableAppRatingPromptLua = 0x19BA59B15D0; // Unknown = 
        public const ulong FFlagEnableAppRatingPromptLua4 = 0x19BA59BCD10; // Unknown = 
        public const ulong FFlagEnableAppStorageJsonCacheInABTest = 0x19B9ACBF8D0; // Unknown = 
        public const ulong FFlagEnableAppStorageJsonDecodeCache = 0x19BA3BB6590; // Unknown = 
        public const ulong FFlagEnableAppStoreAgeSignalsOnHomePage = 0x19B8C2E4E9D; // Bool = false
        public const ulong FFlagEnableArgoPartyChanges = 0x19B8FDECFDD; // Bool = false
        public const ulong FFlagEnableArgoPartyExperimentation7 = 0x19BAC87E595; // Bool = true
        public const ulong FFlagEnableArgus = 0x19B9ACB99D0; // Unknown = 
        public const ulong FFlagEnableArgus2 = 0x19B9ACBDB90; // Unknown = 
        public const ulong FFlagEnableArgusFlyoutEntry = 0x19B9ACB8050; // Unknown = 
        public const ulong FFlagEnableArgusImmersiveNav = 0x19B9ACB02D0; // Unknown = 
        public const ulong FFlagEnableArgusTab = 0x19B9ACBEC90; // Unknown = 
        public const ulong FFlagEnableAttributionContextEventReceiver = 0x19B90290E50; // Unknown = 
        public const ulong FFlagEnableAuditForSinglePageSignUp4 = 0x19B9ACBDE10; // Unknown = 
        public const ulong FFlagEnableAuditForSso = 0x19B9ACBA490; // Unknown = 
        public const ulong FFlagEnableAuditSystem2 = 0x19BBC1C35D0; // Unknown = 
        public const ulong FFlagEnableAuthAnalyticsPrintDebuggingDev = 0x19B945A0B10; // Unknown = 
        public const ulong FFlagEnableAuthStatefulTextInputUpdatesRelease1 = 0x19B88C4AF1D; // Bool = false
        public const ulong FFlagEnableAuthsecImageUpdate = 0x19B88C4DC5D; // Bool = false
        public const ulong FFlagEnableAutoLoginAfterRecovery = 0x19B88C4C11D; // Bool = false
        public const ulong FFlagEnableAutomaticSizeVerticalOffsetWidthFix = 0x19B9FDD4CD5; // Bool = false
        public const ulong FFlagEnableAvatarEditorServiceAPIErrorLogging = 0x19B906430D0; // Unknown = 
        public const ulong FFlagEnableAvatarExperienceSdui = 0x19B9ACB0D90; // Unknown = 
        public const ulong FFlagEnableAvatarHeadshotLocalIconBackgroundFix = 0x19B859CA310; // Unknown = 
        public const ulong FFlagEnableAvatarViewportAutoRotation = 0x19B9F0A641D; // Bool = false
        public const ulong FFlagEnableBadgeCheckForUserCreator = 0x19BAD28549D; // Bool = false
        public const ulong FFlagEnableBirthdayOverlayAnalytics = 0x19B9ACBCD50; // Unknown = 
        public const ulong FFlagEnableBlackbird = 0x19BA6A3F750; // Unknown = 
        public const ulong FFlagEnableBlackbirdCheck = 0x19BA6A32DD0; // Unknown = 
        public const ulong FFlagEnableBlackbirdOnFlyoutMenu = 0x19BA6A341D0; // Unknown = 
        public const ulong FFlagEnableBlackbirdOnFlyoutMenu2 = 0x19BA6A37B50; // Unknown = 
        public const ulong FFlagEnableBlackbirdOnMorePage = 0x19BA6A34510; // Unknown = 
        public const ulong FFlagEnableBlackbirdOnMorePage2 = 0x19BA6A3A790; // Unknown = 
        public const ulong FFlagEnableBlackbirdPageCloseCallback = 0x19BA6A3BC50; // Unknown = 
        public const ulong FFlagEnableBlackbirdPageCloseCallback2 = 0x19BA6A3D010; // Unknown = 
        public const ulong FFlagEnableBlackbirdUpsellImpressionGating = 0x19B9AF1FE50; // Unknown = 
        public const ulong FFlagEnableBlackbirdUpsellInUnifiedPurchaseModal = 0x19B9AF1FAD0; // Unknown = 
        public const ulong FFlagEnableBlackbirdUpsellInUnifiedPurchaseModal7 = 0x19B9AF1FF10; // Unknown = 
        public const ulong FFlagEnableBlackbirdV2 = 0x19BA6A34B10; // Unknown = 
        public const ulong FFlagEnableBottomNavOnMarketplace_v3 = 0x19B9AF14490; // Unknown = 
        public const ulong FFlagEnableBuildExperienceScrollPerformanceTracking = 0x19BAD58045D; // Bool = false
        public const ulong FFlagEnableBuildOverflowMenuForNewGames = 0x19BAD58459D; // Bool = false
        public const ulong FFlagEnableBuildTabOverride = 0x19B9AF133D0; // Unknown = 
        public const ulong FFlagEnableBypassNavigationLockHybridWebview = 0x19B90292590; // Unknown = 
        public const ulong FFlagEnableCEVForceInitialize = 0x19B859C92DD; // Bool = false
        public const ulong FFlagEnableCachingforReminderOfNorms = 0x19BC0544C50; // Unknown = 
        public const ulong FFlagEnableCallingLogoutOnResetIXP = 0x19B945A5050; // Unknown = 
        public const ulong FFlagEnableCancelSubscriptionAppLua = 0x19B9AF11E90; // Unknown = 
        public const ulong FFlagEnableCapturesGalleryRetrievalCoreScript = 0x19BBF25A790; // Unknown = 
        public const ulong FFlagEnableCapturesGalleryRetrievalCoreScript_v3 = 0x19BAC87B69D; // Bool = false
        public const ulong FFlagEnableCatalogTileLoadingLatencyV2 = 0x19B9026ECD0; // Unknown = 
        public const ulong FFlagEnableCentralFoundationOverlayProvider = 0x19B9064951D; // Bool = false
        public const ulong FFlagEnableCentralOverlayForUpsellPrompt = 0x19BAC83611D; // Bool = false
        public const ulong FFlagEnableChatIconUnibarDropdownFixEnabled = 0x19BACFDED90; // Unknown = 
        public const ulong FFlagEnableChatLineReporting2 = 0x19B8C30AC9D; // Bool = true
        public const ulong FFlagEnableChatMicPerfBinding = 0x19BBCD7A290; // Unknown = 
        public const ulong FFlagEnableChatNewMessage = 0x19B8C303F5D; // Bool = true
        public const ulong FFlagEnableChatReportingTextChannelTag = 0x19B8C30E0D0; // Unknown = 
        public const ulong FFlagEnableChromeWindowsNotInMenu = 0x19BA7FC8878; // Unknown = 
        public const ulong FFlagEnableClientToastNotificationsRedirectExperiment = 0x19BACFEB11D; // Bool = false
        public const ulong FFlagEnableClientToastNotificationsReducedMotion = 0x19BA672B39D; // Bool = false
        public const ulong FFlagEnableCommonFriendsMenu3 = 0x19B8C2EA6D0; // Unknown = 
        public const ulong FFlagEnableCompensatingScrollingFrame = 0x19BAC834A5D; // Bool = false
        public const ulong FFlagEnableCondenseRobuxUpsell = 0x19BAC83275D; // Bool = false
        public const ulong FFlagEnableConfirmSignOutV2 = 0x19B945A40D0; // Unknown = 
        public const ulong FFlagEnableConfirmSignifierOnSignUpPage = 0x19B9ACBB010; // Unknown = 
        public const ulong FFlagEnableConnectDisconnect = 0x19B8FDEAF5D; // Bool = false
        public const ulong FFlagEnableConnectDisconnectInSettingsAndChrome = 0x19BA515971D; // Bool = false
        public const ulong FFlagEnableConsoleAutoFocusForUEN1 = 0x19B8FA1F55D; // Bool = false
        public const ulong FFlagEnableConsoleDisconnectNetworkingErrorToast = 0x19B8FC39CDD; // Bool = false
        public const ulong FFlagEnableConsoleExpControls = 0x19B9ACB53D0; // Unknown = 
        public const ulong FFlagEnableConsoleExpControls684 = 0x19B9ACB80D0; // Unknown = 
        public const ulong FFlagEnableConsoleExpControlsIXP = 0x19B9ACB32D0; // Unknown = 
        public const ulong FFlagEnableConsoleExpControlsIXP684 = 0x19B9ACB88D0; // Unknown = 
        public const ulong FFlagEnableConsoleGameJoinCard_v4 = 0x19B8C302490; // Unknown = 
        public const ulong FFlagEnableConsolePreparePaymentCheck = 0x19BAC8341DD; // Bool = false
        public const ulong FFlagEnableConsoleRobloxLogo = 0x19B9ACBF6D0; // Unknown = 
        public const ulong FFlagEnableContactInvitesForNonPhoneVerifiedForAll = 0x19B8C2E9BDD; // Bool = false
        public const ulong FFlagEnableContextFeaturesForOmniRecommendations = 0x19BC0548390; // Unknown = 
        public const ulong FFlagEnableContinueRecovery3 = 0x19B88C4BFD0; // Unknown = 
        public const ulong FFlagEnableConvertPriceChangedToUnknownFailure = 0x19D85DC95D0; // Unknown = 
        public const ulong FFlagEnableCoreContentAccountType = 0x19B9AF16AD0; // Unknown = 
        public const ulong FFlagEnableCoreContentBadge = 0x19B9AF16850; // Unknown = 
        public const ulong FFlagEnableCoreContentBadge2 = 0x19B9AF16710; // Unknown = 
        public const ulong FFlagEnableCoreContentThemeUseGuacForTokenOverrides = 0x19B9AF163D0; // Unknown = 
        public const ulong FFlagEnableCoreContentThemeUseGuacForTokenOverrides2 = 0x19B9AF16590; // Unknown = 
        public const ulong FFlagEnableCoreContentThemeVRScene = 0x19B9AF17350; // Unknown = 
        public const ulong FFlagEnableCoreUISystemV2 = 0x19B9AF11F10; // Unknown = 
        public const ulong FFlagEnableCorescriptExecutionTime = 0x19BBC7A1610; // Unknown = 
        public const ulong FFlagEnableCorescriptMemoryTracker = 0x19B9F18B905; // Bool = true
        public const ulong FFlagEnableCorescriptTrackerForLuaApp = 0x19B90296B50; // Unknown = 
        public const ulong FFlagEnableCorescriptsProfiler = 0x19B9AF11F50; // Unknown = 
        public const ulong FFlagEnableCreatorStorePurchasingCutover = 0x19D85DC3A90; // Unknown = 
        public const ulong FFlagEnableCreatorSubtitleNavigation_v2 = 0x19B8EDC671D; // Bool = true
        public const ulong FFlagEnableCrossDeviceLoginUsingQRCodes3 = 0x19B88C4B250; // Unknown = 
        public const ulong FFlagEnableCrossExpEventLogging = 0x19B8ED7FB50; // Unknown = 
        public const ulong FFlagEnableCrossExpVoiceAbuseReport = 0x19B88C4B91D; // Bool = false
        public const ulong FFlagEnableCrossExpVoiceMemoryCheck = 0x19B88C4B7DD; // Bool = false
        public const ulong FFlagEnableCurrencyTransferDeepLink = 0x19B8C2EB650; // Unknown = 
        public const ulong FFlagEnableCurrencyTransferFlowV3 = 0x19B8C2EB2D0; // Unknown = 
        public const ulong FFlagEnableCurrencyTransferWizardVPCPrologue = 0x19B9F92F3D0; // Unknown = 
        public const ulong FFlagEnableDarkerShimmerTransparency = 0x19BBCD79E10; // Unknown = 
        public const ulong FFlagEnableDeactivatedUserReactivation = 0x19B88C4BA90; // Unknown = 
        public const ulong FFlagEnableDeepLinkHistoryWithModalAPI2 = 0x19B8C2E2F90; // Unknown = 
        public const ulong FFlagEnableDeeplinkResolutionEventReceiver = 0x19B90290B90; // Unknown = 
        public const ulong FFlagEnableDeferVoiceConnection = 0x19B8FDEA850; // Unknown = 
        public const ulong FFlagEnableDemoModeRegionalAvailability = 0x19B88C2FF5D; // Bool = false
        public const ulong FFlagEnableDesktopGameJoinCard_v5 = 0x19D812E9648; // Unknown = 
        public const ulong FFlagEnableDevProductPendingProductsLimitExceededInUnifiedPurchase = 0x19B863E0F55; // Bool = true
        public const ulong FFlagEnableDevSubsFastFollowFixes = 0x19B9ACBB950; // Unknown = 
        public const ulong FFlagEnableDeviceGateForInExpChatRewrite = 0x19B9CB7DFDD; // Bool = false
        public const ulong FFlagEnableDialogAfterSquadJoin1 = 0x19B8C2E24D0; // Unknown = 
        public const ulong FFlagEnableDirectLinkForTablets = 0x19B9011391D; // Bool = false
        public const ulong FFlagEnableDisableSubPurchase = 0x19BAC8361D0; // Unknown = 
        public const ulong FFlagEnableDisconnectPartyVoiceIfNeeded = 0x19BA8021050; // Unknown = 
        public const ulong FFlagEnableDiscountInfoInUnifiedPurchaseModal = 0x19B9ACB2B90; // Unknown = 
        public const ulong FFlagEnableDiscountInfoInUnifiedPurchaseModal6 = 0x19B9ACB4650; // Unknown = 
        public const ulong FFlagEnableDisplayLoggingForToastsFix = 0x19BA6726E1D; // Bool = true
        public const ulong FFlagEnableDrawerAnimatingHook = 0x19B9ACBD950; // Unknown = 
        public const ulong FFlagEnableDrawerFocusNav = 0x19B9ACB0390; // Unknown = 
        public const ulong FFlagEnableDummyAMPWizard = 0x19B9011401D; // Bool = false
        public const ulong FFlagEnableDynamicReportV2ForUserProfileReports3 = 0x19B8EE08FB0; // Unknown = 
        public const ulong FFlagEnableEDPTTIManagerColdWarmDetection = 0x19B90261910; // Unknown = 
        public const ulong FFlagEnableExitModalExposure = 0x19BACE9E01D; // Bool = false
        public const ulong FFlagEnableExpChatLocalChatEnabledMessageExperimentation2 = 0x19B8FDEC45D; // Bool = false
        public const ulong FFlagEnableExpChatNewSystemMessagesExperimentation = 0x19B8FDEC4D0; // Unknown = 
        public const ulong FFlagEnableExpChatUniverseChatTabNames2 = 0x19B8FA14F5D; // Bool = false
        public const ulong FFlagEnableExpJoinMicPermAnalytics = 0x19BBCA071B5; // Bool = false
        public const ulong FFlagEnableExperienceDetailsBottomSheet2 = 0x19BA5537965; // Bool = false
        public const ulong FFlagEnableExperienceDetailsBottomSheetTopBar = 0x19BA520C47D; // Bool = true
        public const ulong FFlagEnableExperienceGenericChallengeRenderingConnection2 = 0x19BA672CF90; // Unknown = 
        public const ulong FFlagEnableExperienceGenericChallengeRenderingOnLoadingScript = 0x19B9AF11DD0; // Unknown = 
        public const ulong FFlagEnableExperienceNotificationPrompts2 = 0x19B9AF11B50; // Unknown = 
        public const ulong FFlagEnableExplicitSettingsChangeAnalytics = 0x19B9FD8D09D; // Bool = false
        public const ulong FFlagEnableExternalBrowserForVPCPrivacyPolicy = 0x19B9011211D; // Bool = false
        public const ulong FFlagEnableFAECancellationAnalytics = 0x19B90112FDD; // Bool = false
        public const ulong FFlagEnableFAEQRCodeHandoff = 0x19B90112090; // Unknown = 
        public const ulong FFlagEnableFaceIDTextOnAddAuthMethodPage = 0x19B945A1050; // Unknown = 
        public const ulong FFlagEnableFastScrollingFixTest = 0x19BA6092210; // Unknown = 
        public const ulong FFlagEnableFeatureRestrictionOnAgeVerificationAttempt = 0x19B8FC39F10; // Unknown = 
        public const ulong FFlagEnableFetchCartPricingDuringInExperience = 0x19B9ACB8890; // Unknown = 
        public const ulong FFlagEnableFixRobuxUpsellPriceCrash = 0x19BAC83299D; // Bool = false
        public const ulong FFlagEnableFlyoutExposure = 0x19BA4616ED0; // Unknown = 
        public const ulong FFlagEnableFlyoutFriendsHeaderFix = 0x19B9AF15C90; // Unknown = 
        public const ulong FFlagEnableFlyoutIxp11 = 0x19BA3BB4E90; // Unknown = 
        public const ulong FFlagEnableFlyoutMenuRobuxCardRefactor = 0x19BA6A37B90; // Unknown = 
        public const ulong FFlagEnableFlyoutOnNavRail = 0x19B85788DDD; // Bool = false
        public const ulong FFlagEnableFlyoutSidePanel15 = 0x19B859CAAD0; // Unknown = 
        public const ulong FFlagEnableFlyoutUncheckedBadge = 0x19B9AF174D0; // Unknown = 
        public const ulong FFlagEnableFlyoutUncheckedBadge2 = 0x19B9AF17550; // Unknown = 
        public const ulong FFlagEnableFlyoutWithScrollAway2 = 0x19BA6094B10; // Unknown = 
        public const ulong FFlagEnableFontStylisticAlternativesOnSocialScreens = 0x19BACFDE510; // Unknown = 
        public const ulong FFlagEnableFoundationUIVPCUpsellForInExperience = 0x19B90111510; // Unknown = 
        public const ulong FFlagEnableFriendCarouselInGameFriendExposureLogging_v2 = 0x19B8FA1E39D; // Bool = false
        public const ulong FFlagEnableFriendsLandingChallengeInterceptor = 0x19BAFCF8AD0; // Unknown = 
        public const ulong FFlagEnableFriendsListSearchNormalizationErrorFix = 0x19B8C304CDD; // Bool = true
        public const ulong FFlagEnableFriendsMenuShareGameInviteLink3 = 0x19BADF95010; // Unknown = 
        public const ulong FFlagEnableFriendsRenamingForAll = 0x19B8C2E2610; // Unknown = 
        public const ulong FFlagEnableFtuxExitOnMuteToggle = 0x19B8FDEAD1D; // Bool = false
        public const ulong FFlagEnableGameInviteModalVRSupportV2 = 0x19B8C3048DD; // Bool = true
        public const ulong FFlagEnableGameInviteRewardsBanner3 = 0x19B8C30545D; // Bool = true
        public const ulong FFlagEnableGameLeftMessage = 0x19BB2B2B1F0; // Unknown = 
        public const ulong FFlagEnableGamepadHookForCorescriptGlobalEffects = 0x19B85A50B98; // Unknown = 
        public const ulong FFlagEnableGateNotificationPreferencesTab = 0x19B8C30469D; // Bool = true
        public const ulong FFlagEnableGenericIllegalContentReporting3 = 0x19BA3A57A5D; // Bool = false
        public const ulong FFlagEnableGenericTwoFAMessage = 0x19B88C4DB5D; // Bool = false
        public const ulong FFlagEnableGetCredentialsInCredentialsProtocolHook = 0x19BA5156150; // Unknown = 
        public const ulong FFlagEnableGetFriendshipStatus = 0x19B88C248DD; // Bool = true
        public const ulong FFlagEnableGlobalChat3pSummaryLuaApps = 0x19BA74A559D; // Bool = false
        public const ulong FFlagEnableGlobalChatAbuseReporting = 0x19B8C30C5DD; // Bool = true
        public const ulong FFlagEnableHandleEngineSessionCheckAtStartup = 0x19B90291A90; // Unknown = 
        public const ulong FFlagEnableHeadShapeForCharacterManager = 0x19BA3A564D0; // Unknown = 
        public const ulong FFlagEnableHeadShapeForCharacterManager6 = 0x19BA3A53090; // Unknown = 
        public const ulong FFlagEnableHeaderBarButtonsUpdate = 0x19BBCD7155D; // Bool = false
        public const ulong FFlagEnableHeaderBarButtonsUpdate2 = 0x19BBCD75C10; // Unknown = 
        public const ulong FFlagEnableHeadlessSubscriptionNativePurchaseCancelCallback = 0x19B8FC33FDD; // Bool = false
        public const ulong FFlagEnableHearingWithoutMicPermissions = 0x19B8FDEAA50; // Unknown = 
        public const ulong FFlagEnableHideJoinToastSubtitle = 0x19B8FDE9F90; // Unknown = 
        public const ulong FFlagEnableHideReportAdModalDuringScreenshot2 = 0x19BA8A0F79D; // Bool = false
        public const ulong FFlagEnableHomeBetaBadge = 0x19BA76D2E60; // Unknown = 
        public const ulong FFlagEnableHomeGameItemOwnershipUpdate = 0x19BC05446D0; // Unknown = 
        public const ulong FFlagEnableHomePageEmailUpsellCard = 0x19B90294C90; // Unknown = 
        public const ulong FFlagEnableHomePageUpsellCardRelease7 = 0x19B90266810; // Unknown = 
        public const ulong FFlagEnableHomeRobloxLogo = 0x19B9ACBCA10; // Unknown = 
        public const ulong FFlagEnableHomepagePromptsForModalsAndBanners = 0x19BC05437D0; // Unknown = 
        public const ulong FFlagEnableHotbarHide = 0x19BA6078DD0; // Unknown = 
        public const ulong FFlagEnableIAFlyoutIXPHomeProfileRemoval = 0x19B94811C50; // Unknown = 
        public const ulong FFlagEnableIOSUIRefactorLuaIXP2 = 0x19B88C4BBDD; // Bool = false
        public const ulong FFlagEnableIXPOverrideAccountPicker1 = 0x19B9ACB48D0; // Unknown = 
        public const ulong FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByCode = 0x19B8FC38F1D; // Bool = false
        public const ulong FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByEmail = 0x19B8FC38F9D; // Bool = false
        public const ulong FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByOtp = 0x19B8FC3901D; // Bool = false
        public const ulong FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByPhone = 0x19B8FC38AD0; // Unknown = 
        public const ulong FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByUsername = 0x19B8FC38390; // Unknown = 
        public const ulong FFlagEnableIllegalChildAccountLinkingErrorMessageOnSSO = 0x19B8FC38E9D; // Bool = false
        public const ulong FFlagEnableInAppBugReporting = 0x19BACFD4810; // Unknown = 
        public const ulong FFlagEnableInExpChatPolishSummaryOnLuaForTranslatedMessageV2 = 0x19BA515FF1D; // Bool = false
        public const ulong FFlagEnableInExpChatRewrite = 0x19B9CB7C39D; // Bool = false
        public const ulong FFlagEnableInExpChatSummaryOnLua = 0x19B9CB7235D; // Bool = false
        public const ulong FFlagEnableInExpChatSummaryOnLua4 = 0x19B9CB7D59D; // Bool = false
        public const ulong FFlagEnableInExpChatSummaryOnLuaForTranslatedMessageV2 = 0x19BA515D29D; // Bool = false
        public const ulong FFlagEnableInExpPhoneVoiceUpsellEntrypoints2 = 0x19B88C4E29D; // Bool = false
        public const ulong FFlagEnableInExperienceAvatarSwitcher9 = 0x19B88C4FF1D; // Bool = false
        public const ulong FFlagEnableInExperienceHandheldControls = 0x19B9ACB4A90; // Unknown = 
        public const ulong FFlagEnableInExperienceShop = 0x19B9ACB45D0; // Unknown = 
        public const ulong FFlagEnableInExperienceShop3 = 0x19B9ACB4850; // Unknown = 
        public const ulong FFlagEnableInExperienceUIPCVRFix_dev = 0x19BA6A37090; // Unknown = 
        public const ulong FFlagEnableInGameMenuChrome = 0x19BA3BBDBD0; // Unknown = 
        public const ulong FFlagEnableInGameMenuDurationLogger = 0x19BA366B81D; // Bool = false
        public const ulong FFlagEnableInitialJoinVoiceButton = 0x19B8FDEA290; // Unknown = 
        public const ulong FFlagEnableInlineSurveyOnUserReport = 0x19B8C30C11D; // Bool = true
        public const ulong FFlagEnableInspectAndBuyV2RootFlag = 0x19B9ACB65D0; // Unknown = 
        public const ulong FFlagEnableInspectAndBuyV2RootFlag2 = 0x19B9ACB6590; // Unknown = 
        public const ulong FFlagEnableInvitePromptLoadingState2 = 0x19B9F294910; // Unknown = 
        public const ulong FFlagEnableInvoluntaryLogoutEvent = 0x19B902900D0; // Unknown = 
        public const ulong FFlagEnableIosAuthServiceLuaIXP = 0x19B88C4C35D; // Bool = false
        public const ulong FFlagEnableIosKeychainLoginLua4 = 0x19B8EAF6150; // Unknown = 
        public const ulong FFlagEnableJoinV2PreAuthDeepLink = 0x19B8FC39E1D; // Bool = false
        public const ulong FFlagEnableJoinVoiceIsMutedMic = 0x19B8FDEA6D0; // Unknown = 
        public const ulong FFlagEnableJoinVoiceTooltip = 0x19B8FDEA490; // Unknown = 
        public const ulong FFlagEnableJoinVoiceVrTelemetry = 0x19D8168B050; // Unknown = 
        public const ulong FFlagEnableKeyboardVisibilityCheckOnPasswordFocus = 0x19BBC1C1D90; // Unknown = 
        public const ulong FFlagEnableKoreaKISACompliance = 0x19B945A2E10; // Unknown = 
        public const ulong FFlagEnableLastLoginMethodTracking = 0x19B945A08D0; // Unknown = 
        public const ulong FFlagEnableLaunchAfterPurchase2 = 0x19B9ACB1650; // Unknown = 
        public const ulong FFlagEnableLaunchAppCheckForAccountSwitchGameParams = 0x19B90291AD0; // Unknown = 
        public const ulong FFlagEnableLeaveGameUpsellEntrypoint = 0x19BACE9CC50; // Unknown = 
        public const ulong FFlagEnableLeftNavOnConsole14 = 0x19BA6A38890; // Unknown = 
        public const ulong FFlagEnableLimitHit2SVUpsell = 0x19B9F92BF90; // Unknown = 
        public const ulong FFlagEnableLinkSharingEvent = 0x19B9AF11E50; // Unknown = 
        public const ulong FFlagEnableLocalesForExperienceLanguageSwitcher4 = 0x19B9FD8DB1D; // Bool = false
        public const ulong FFlagEnableLockScreenWidgetLuaIXP = 0x19B88C4BC9D; // Bool = false
        public const ulong FFlagEnableLoginAccountSelectorRelease1 = 0x19B88C4B190; // Unknown = 
        public const ulong FFlagEnableLoginDisambiguationFoundationSwitcher = 0x19B88C4CE9D; // Bool = false
        public const ulong FFlagEnableLoginV2Modalization15 = 0x19B9AF19C50; // Unknown = 
        public const ulong FFlagEnableLogoutV3 = 0x19B945A1450; // Unknown = 
        public const ulong FFlagEnableLookFavoriting = 0x19B82D0DD9D; // Bool = true
        public const ulong FFlagEnableLuaAccountSwitchRelease2 = 0x19B88C4C65D; // Bool = false
        public const ulong FFlagEnableLuaAppBootcamp = 0x19B9029401D; // Bool = false
        public const ulong FFlagEnableLuaAppSessionWithError2 = 0x19B8F90911D; // Bool = false
        public const ulong FFlagEnableLuaAppsAppsflyerIdCounter = 0x19B90291350; // Unknown = 
        public const ulong FFlagEnableLuaAppsFollowUserId = 0x19B9AF14250; // Unknown = 
        public const ulong FFlagEnableLuaCommunityList = 0x19B85788EDD; // Bool = false
        public const ulong FFlagEnableLuaLogReporterMultipleLogs = 0x19B88C4EDDD; // Bool = false
        public const ulong FFlagEnableLuafiedRecoveryFlow2 = 0x19B88C4B550; // Unknown = 
        public const ulong FFlagEnableLuckyRecommendationExperimentation = 0x19B8C2E3D9D; // Bool = false
        public const ulong FFlagEnableLuobuInGameUpsell = 0x19D85DC5390; // Unknown = 
        public const ulong FFlagEnableMagicLogin = 0x19B9ACBC450; // Unknown = 
        public const ulong FFlagEnableMagicLogin_debug = 0x19B9ACB4590; // Unknown = 
        public const ulong FFlagEnableManageAccountsRedesign8 = 0x19B88C4C990; // Unknown = 
        public const ulong FFlagEnableMaquettesShortLinkCDLInstructions = 0x19BC05433D0; // Unknown = 
        public const ulong FFlagEnableMeTabMarketplaceNav = 0x19BA5539DD0; // Unknown = 
        public const ulong FFlagEnableMeTabProfile = 0x19BA553B710; // Unknown = 
        public const ulong FFlagEnableMemoryShell = 0x19BC2566E10; // Unknown = 
        public const ulong FFlagEnableMemorySnapshotCategories = 0x19B8F741E1D; // Bool = false
        public const ulong FFlagEnableMenuTrailingBadge = 0x19B9ACB2C10; // Unknown = 
        public const ulong FFlagEnableMergeOmniFeedSorts3 = 0x19BA515539D; // Bool = false
        public const ulong FFlagEnableMessageBusUnSubscribeErrorTelemetry = 0x19B8C316D10; // Unknown = 
        public const ulong FFlagEnableMicrosoftStorePaymentsPlatform = 0x19B8578A95D; // Bool = false
        public const ulong FFlagEnableMilkyWayPaymentsPlatformV2 = 0x19B8578AB9D; // Bool = false
        public const ulong FFlagEnableMobileGameJoinCard_V14 = 0x19B8C3028D0; // Unknown = 
        public const ulong FFlagEnableMobilePlayerListOnConsole = 0x19D86AEB668; // Unknown = 
        public const ulong FFlagEnableModerateChatRemoteEvent = 0x19B8C302C5D; // Bool = true
        public const ulong FFlagEnableModerateChatUseChatService = 0x19BA553B850; // Unknown = 
        public const ulong FFlagEnableModularExternalNavigationHandler = 0x19BA8020FD0; // Unknown = 
        public const ulong FFlagEnableModularizedUserAgreementsList = 0x19BA6A37F90; // Unknown = 
        public const ulong FFlagEnableMomentTextGeneration3 = 0x19D86F02D90; // Unknown = 
        public const ulong FFlagEnableMorePageDirectionalLayoutRolloutFix = 0x19B9ACB0D1D; // Bool = false
        public const ulong FFlagEnableMorePageExitButtonSupport = 0x19B9ACBB19D; // Bool = true
        public const ulong FFlagEnableMorePageExitButtonSupport2 = 0x19B9ACBD290; // Unknown = 
        public const ulong FFlagEnableMotionJitterMetric2 = 0x19BC054CFD0; // Unknown = 
        public const ulong FFlagEnableMoveSnapInVirtualCursor = 0x19BA59B9E50; // Unknown = 
        public const ulong FFlagEnableMultiPageSignup5 = 0x19B945A83D0; // Unknown = 
        public const ulong FFlagEnableMultiPageSignupExperimentRelease2 = 0x19B902918D0; // Unknown = 
        public const ulong FFlagEnableMultiPageSignupV2Updates = 0x19B945A5710; // Unknown = 
        public const ulong FFlagEnableMultipageSignupNonInteractiveUserAgreementsPage = 0x19B945A63D0; // Unknown = 
        public const ulong FFlagEnableMutexOnGenericChallengeInterceptorMount = 0x19B82BC561D; // Bool = false
        public const ulong FFlagEnableNapIxpLayerExposure = 0x19B8C30BAD0; // Unknown = 
        public const ulong FFlagEnableNativePersonaInquiryForAmpIDVUpsell = 0x19B90113A5D; // Bool = false
        public const ulong FFlagEnableNativeToWebviewMiddleware = 0x19BA5158590; // Unknown = 
        public const ulong FFlagEnableNativeWrapperAppPage = 0x19B90642F1D; // Bool = false
        public const ulong FFlagEnableNavBarLabels3 = 0x19B8578939D; // Bool = false
        public const ulong FFlagEnableNavigateToLoginAfterLogoutAll = 0x19B88C4C81D; // Bool = false
        public const ulong FFlagEnableNavigationPerformanceIntervals2 = 0x19BA6A3E790; // Unknown = 
        public const ulong FFlagEnableNewAddFriendsTileForAll = 0x19BACFD97D0; // Unknown = 
        public const ulong FFlagEnableNewAvatarViewportProps = 0x19B9F0A5355; // Bool = false
        public const ulong FFlagEnableNewBackpack = 0x19B9AF19FD0; // Unknown = 
        public const ulong FFlagEnableNewBackpackV5 = 0x19B9AF19890; // Unknown = 
        public const ulong FFlagEnableNewCustomizeBundleEquip3 = 0x19B9026E510; // Unknown = 
        public const ulong FFlagEnableNewDeviceIntegrityFailureHandling = 0x19BA607F6D0; // Unknown = 
        public const ulong FFlagEnableNewInviteMenuCustomization2 = 0x19B9F294E9D; // Bool = false
        public const ulong FFlagEnableNewInviteMenuCustomizationIXP2 = 0x19B9F294F90; // Unknown = 
        public const ulong FFlagEnableNewInviteMenuIXP2 = 0x19BA5538090; // Unknown = 
        public const ulong FFlagEnableNewInviteMenuStyle = 0x19B9F2955DD; // Bool = false
        public const ulong FFlagEnableNewInviteSendEndpoint = 0x19B9F29675D; // Bool = false
        public const ulong FFlagEnableNewInviteSendEndpointIXP = 0x19B9F29681D; // Bool = false
        public const ulong FFlagEnableNonFlyoutUncheckedBadge = 0x19B9AF17890; // Unknown = 
        public const ulong FFlagEnableNonFlyoutUncheckedBadge2 = 0x19B9AF17950; // Unknown = 
        public const ulong FFlagEnableNotApprovedCheckBoxTextABTest = 0x19BC054B550; // Unknown = 
        public const ulong FFlagEnableNotApprovedForeshadowingConsequenceABTest = 0x19BC0541F90; // Unknown = 
        public const ulong FFlagEnableNotificationsDeeplink = 0x19B9AF1B810; // Unknown = 
        public const ulong FFlagEnableNotificationsToastTTLFix = 0x19BA6727F5D; // Bool = false
        public const ulong FFlagEnableOffersOnInExperienceSurface = 0x19B9ACB3E50; // Unknown = 
        public const ulong FFlagEnableOnPlatformSharingExperiment = 0x19BACFD5E10; // Unknown = 
        public const ulong FFlagEnableOnPlatformSharingExperiment_v5 = 0x19BACFD2090; // Unknown = 
        public const ulong FFlagEnableOtpEmailLoginRelease1 = 0x19B90648610; // Unknown = 
        public const ulong FFlagEnablePLTPrefetchCallbacks = 0x19BA607F910; // Unknown = 
        public const ulong FFlagEnablePWManagerSignupCheck = 0x19B9ACBB4D0; // Unknown = 
        public const ulong FFlagEnablePalisadesPaymentsPlatform = 0x19D85DC2350; // Unknown = 
        public const ulong FFlagEnableParentalControlsScreentimeEnforcement3 = 0x19D84DACD50; // Unknown = 
        public const ulong FFlagEnablePartyNudgeAfterJoin2 = 0x19B8C2E2CD0; // Unknown = 
        public const ulong FFlagEnablePartyNudgeV1_DEV = 0x19BACFDB550; // Unknown = 
        public const ulong FFlagEnablePartyPageCarouselExperimentation4 = 0x19B8FDEF35D; // Bool = false
        public const ulong FFlagEnablePartyQuickStartButton = 0x19BACFDF610; // Unknown = 
        public const ulong FFlagEnablePartyQuickStartButton3 = 0x19BACFD5210; // Unknown = 
        public const ulong FFlagEnablePartyQuickStartChanges2 = 0x19B8FDEEB1D; // Bool = false
        public const ulong FFlagEnablePartyVoiceChangersInLua = 0x19BACFDB890; // Unknown = 
        public const ulong FFlagEnablePartyVoiceOnlyForEligibleUsers = 0x19BA67295DD; // Bool = false
        public const ulong FFlagEnablePartyVoiceOnlyForUnfilteredThreads = 0x19BA672D29D; // Bool = true
        public const ulong FFlagEnablePartyVoiceRestrictionStatus = 0x19BA8028790; // Unknown = 
        public const ulong FFlagEnablePartyVoiceStatusChangedDetailAnalytics = 0x19B859C9C1D; // Bool = false
        public const ulong FFlagEnablePartyVoiceVolumeOnlyWhenInEligibleParty = 0x19B88C4B29D; // Bool = false
        public const ulong FFlagEnablePasskeyLoginErrorLogging = 0x19B945A6FD0; // Unknown = 
        public const ulong FFlagEnablePasskeyOnlyUserErrorMessage = 0x19B8FC38850; // Unknown = 
        public const ulong FFlagEnablePasswordStatusRemoval = 0x19B90291190; // Unknown = 
        public const ulong FFlagEnablePaymentSessionIdInRobuxPurchase = 0x19B9EE02510; // Unknown = 
        public const ulong FFlagEnablePeekViewFocusNav = 0x19BC0543690; // Unknown = 
        public const ulong FFlagEnablePeekViewStateOnMountParam = 0x19B8578959D; // Bool = false
        public const ulong FFlagEnablePeopleListLazyRender = 0x19BBC382BD0; // Unknown = 
        public const ulong FFlagEnablePeoplePageButtonOnMount = 0x19BBC38EBD0; // Unknown = 
        public const ulong FFlagEnablePerfRegressionTest = 0x19B902683D0; // Unknown = 
        public const ulong FFlagEnablePerformPurchaseGCSHandling = 0x19D85DCDD10; // Unknown = 
        public const ulong FFlagEnablePersonaLivenessQR = 0x19B8C30ED1D; // Bool = true
        public const ulong FFlagEnablePinnedShortcutsOnHomeScreenLua2 = 0x19B9AF12990; // Unknown = 
        public const ulong FFlagEnablePioneerLandingPageLayout = 0x19B9ACB605D; // Bool = false
        public const ulong FFlagEnablePioneerPaymentsPlatform = 0x19D85DC341D; // Bool = true
        public const ulong FFlagEnablePioneerPostAuthGameJoin = 0x19B9ACB185D; // Bool = false
        public const ulong FFlagEnablePlatformEvidence = 0x19BC0543410; // Unknown = 
        public const ulong FFlagEnablePlatformProfileContextualMenuOption = 0x19BA59B5BD0; // Unknown = 
        public const ulong FFlagEnablePlatformRestrictedEventReceiver3 = 0x19B9AF16B90; // Unknown = 
        public const ulong FFlagEnablePlayWithRewardComponent = 0x19BBB595850; // Unknown = 
        public const ulong FFlagEnablePlayWithRewardComponent10 = 0x19B88C42EDD; // Bool = false
        public const ulong FFlagEnablePlayWithRewardNonPeekviewEdp = 0x19B9ACBA610; // Unknown = 
        public const ulong FFlagEnablePlayerListExposureEvents = 0x19BACE972D0; // Unknown = 
        public const ulong FFlagEnablePlayerSupportCaptureAttachments = 0x19B9EE0BB5D; // Bool = false
        public const ulong FFlagEnablePlayerSupportCaptureAttachments2 = 0x19BA6074310; // Unknown = 
        public const ulong FFlagEnablePlayerSupportPrompt = 0x19BA6074B1D; // Bool = true
        public const ulong FFlagEnablePlaytestModeUnibar2 = 0x19B9ACB2650; // Unknown = 
        public const ulong FFlagEnablePlusUpsellDeepLink = 0x19BA520126D; // Bool = false
        public const ulong FFlagEnablePopLatencyOverlay = 0x19B85788510; // Unknown = 
        public const ulong FFlagEnablePostAuthRoutingInAllCases = 0x19B945AE510; // Unknown = 
        public const ulong FFlagEnablePostAuthRoutingInAllCases2 = 0x19B945A3DD0; // Unknown = 
        public const ulong FFlagEnablePreAuthDeepLinkHandler2 = 0x19B8FC395D0; // Unknown = 
        public const ulong FFlagEnablePriceChangedErrorHandling = 0x19D85DC4490; // Unknown = 
        public const ulong FFlagEnableProfileCompletion = 0x19BA6A3C855; // Bool = false
        public const ulong FFlagEnableProfileInsightsApolloMigration_v3 = 0x19B8C2E31D0; // Unknown = 
        public const ulong FFlagEnableProfilePlatformChallengeInterceptor = 0x19BB7F41FD0; // Unknown = 
        public const ulong FFlagEnableProfilePlatformDisabledActions = 0x19BACFD6B90; // Unknown = 
        public const ulong FFlagEnableProgressLoadingAssetsAppContainer = 0x19B9064E85D; // Bool = false
        public const ulong FFlagEnableProgressLoadingAssetsTenFoot = 0x19B90641D9D; // Bool = false
        public const ulong FFlagEnablePromptAgeCheckListener = 0x19B9AF11350; // Unknown = 
        public const ulong FFlagEnablePromptPurchaseRequestedV2 = 0x19D85DC9890; // Unknown = 
        public const ulong FFlagEnablePromptPurchaseRequestedV2Take2 = 0x19D85DC9F90; // Unknown = 
        public const ulong FFlagEnablePromptRobloxSubscriptionPurchaseBinding = 0x19D85DC0510; // Unknown = 
        public const ulong FFlagEnablePromptRobloxSubscriptionPurchaseBinding2 = 0x19D85DC6390; // Unknown = 
        public const ulong FFlagEnableProvisionalRating = 0x19BAD1A4FCD; // Bool = true
        public const ulong FFlagEnablePurchaseFlowUUIDMigration = 0x19D85DC8B50; // Unknown = 
        public const ulong FFlagEnablePurchasePayloadInExperienceShop = 0x19B9ACB0E10; // Unknown = 
        public const ulong FFlagEnablePushNotificationsUpsellModal6 = 0x19B8C304850; // Unknown = 
        public const ulong FFlagEnablePushNotificationsUpsellModalChat4 = 0x19B9F1824BD; // Bool = true
        public const ulong FFlagEnablePymkCarouselChallengeInterceptor = 0x19B8FC3A610; // Unknown = 
        public const ulong FFlagEnableQuestIAPAnalytics = 0x19D85DC1890; // Unknown = 
        public const ulong FFlagEnableQueueExperimentation2 = 0x19B8FDED79D; // Bool = false
        public const ulong FFlagEnableRMOnMorePageForAll = 0x19BA6A3AAD0; // Unknown = 
        public const ulong FFlagEnableRMOnMorePageGUAC = 0x19BA6A37BD0; // Unknown = 
        public const ulong FFlagEnableReactSchedulerIXP = 0x19B9ACB0410; // Unknown = 
        public const ulong FFlagEnableReadAloudInUA2 = 0x19B8578C61D; // Bool = false
        public const ulong FFlagEnableRecentActivityInspectAndBuy = 0x19B9F18F9BD; // Bool = true
        public const ulong FFlagEnableRecentActivitySingleItemDetails = 0x19B9F18B8FD; // Bool = true
        public const ulong FFlagEnableRecommendationsForPCGDK = 0x19B8C2E1E1D; // Bool = false
        public const ulong FFlagEnableRecordLogin = 0x19B9ACB6510; // Unknown = 
        public const ulong FFlagEnableRecordLogin1 = 0x19B9ACB1790; // Unknown = 
        public const ulong FFlagEnableRecordSignOut = 0x19B902901D0; // Unknown = 
        public const ulong FFlagEnableReferredPlayerJoinRemoteEvent = 0x19B945A3390; // Unknown = 
        public const ulong FFlagEnableReferredPlayerJoinRemoteEventForAll = 0x19B945A4190; // Unknown = 
        public const ulong FFlagEnableRejectPromiseOnWebviewClosed = 0x19BA5158C10; // Unknown = 
        public const ulong FFlagEnableReminderOfNormsABTest = 0x19BC05444D0; // Unknown = 
        public const ulong FFlagEnableReportAdDropdown5 = 0x19BA8A0F09D; // Bool = false
        public const ulong FFlagEnableReportingFlowForDevSubs = 0x19B9ACBC350; // Unknown = 
        public const ulong FFlagEnableReportingFlowForDevSubs2 = 0x19B9ACBFC10; // Unknown = 
        public const ulong FFlagEnableReportingFlowForExperienceShop2 = 0x19B9ACBF5D0; // Unknown = 
        public const ulong FFlagEnableReportingFlowForMomentsFeed = 0x19B9ACBBA90; // Unknown = 
        public const ulong FFlagEnableRequestLocationTypeForSduiPurchase = 0x19D85DC2E90; // Unknown = 
        public const ulong FFlagEnableRetryForLinkingProtocolFetch = 0x19B8578A55D; // Bool = false
        public const ulong FFlagEnableRetryOnPrefetch401 = 0x19BA3A7B310; // Unknown = 
        public const ulong FFlagEnableReusableVPCPrologue = 0x19B9011229D; // Bool = false
        public const ulong FFlagEnableRewardsWebViewOverlay = 0x19D8952B4D0; // Unknown = 
        public const ulong FFlagEnableRichTextForBubbleChat = 0x19B81E171DD; // Bool = false
        public const ulong FFlagEnableRoactNetworkingForChallengeInteception = 0x19B90112D5D; // Bool = false
        public const ulong FFlagEnableRobloxSubscriptionEventListener = 0x19B9AF181D0; // Unknown = 
        public const ulong FFlagEnableRobuxInExperienceShop = 0x19B9ACBAF50; // Unknown = 
        public const ulong FFlagEnableRobuxInExperienceShop3 = 0x19B9ACBC610; // Unknown = 
        public const ulong FFlagEnableRobuxTransferFlowEventIngest = 0x19B8C2EBB50; // Unknown = 
        public const ulong FFlagEnableSafetyDashboard = 0x19B825F743D; // Bool = true
        public const ulong FFlagEnableSavePasswordAfterRecovery = 0x19B88C4C25D; // Bool = false
        public const ulong FFlagEnableScheduledSquadsListExperimentation_dev = 0x19B8FDEDADD; // Bool = false
        public const ulong FFlagEnableScheduledSquadsTopBarEntrypoint_dev = 0x19BBB2D8A5D; // Bool = false
        public const ulong FFlagEnableSchedulerFlagOverrides = 0x19B9ACBD1D0; // Unknown = 
        public const ulong FFlagEnableSchematizedInGameRobuxUpsellEvent2 = 0x19BAE780D0D; // Bool = true
        public const ulong FFlagEnableSchoolEntry = 0x19B8C2E4710; // Unknown = 
        public const ulong FFlagEnableScreentimeMoreTimeOption = 0x19BA59B8C90; // Unknown = 
        public const ulong FFlagEnableScrollAwayContentScrollableFix = 0x19B9ACB8710; // Unknown = 
        public const ulong FFlagEnableSduiRegistriesforTenFootUiContainer = 0x19B90641FDD; // Bool = false
        public const ulong FFlagEnableSduiV2HomepagePrompts2 = 0x19B88C4F6D0; // Unknown = 
        public const ulong FFlagEnableSeamlessVoiceDataConsentToast = 0x19BA515819D; // Bool = false
        public const ulong FFlagEnableSeamlessVoiceFeature = 0x19B8FDEAEDD; // Bool = false
        public const ulong FFlagEnableSearchOmniAutocompletePageByDefault5 = 0x19B88C4E61D; // Bool = false
        public const ulong FFlagEnableSecurityAlertDeeplink = 0x19B8C30B61D; // Bool = true
        public const ulong FFlagEnableSecurityAlertToastCallback = 0x19B8C30BFDD; // Bool = true
        public const ulong FFlagEnableSendCameraAccessAnalytics = 0x19B9AF11950; // Unknown = 
        public const ulong FFlagEnableSessionCheckManagerToListenOnce = 0x19B902925D0; // Unknown = 
        public const ulong FFlagEnableSetCoreGuiEnabledExpChat = 0x19B81E1691D; // Bool = false
        public const ulong FFlagEnableSettingsHubUIDelegateRollout = 0x19BA6A392D0; // Unknown = 
        public const ulong FFlagEnableShareLinksInGameDetailEvent = 0x19B9ACB3A10; // Unknown = 
        public const ulong FFlagEnableShareSheetForBuild = 0x19B9AF19BD0; // Unknown = 
        public const ulong FFlagEnableSharedInviteStore = 0x19BB4E67A3D; // Bool = false
        public const ulong FFlagEnableShopGiftCardsURL = 0x19BA5BD7D10; // Unknown = 
        public const ulong FFlagEnableShortLinkCodeForVRCDLv2 = 0x19BC0540290; // Unknown = 
        public const ulong FFlagEnableSideSheet = 0x19B9ACB4C5D; // Bool = true
        public const ulong FFlagEnableSideSheet6 = 0x19B9ACBAD1D; // Bool = false
        public const ulong FFlagEnableSignUpExitModal = 0x19B9ACBAE90; // Unknown = 
        public const ulong FFlagEnableSignUpExitModal3 = 0x19B9ACBD4D0; // Unknown = 
        public const ulong FFlagEnableSignupFoundationText2 = 0x19B945A3E90; // Unknown = 
        public const ulong FFlagEnableSignupFoundationalizeBackgroundAndText = 0x19B945A5F50; // Unknown = 
        public const ulong FFlagEnableSilentUpgradeOnSignUp = 0x19B9ACB2090; // Unknown = 
        public const ulong FFlagEnableSilentUpgradeOnSignUp2 = 0x19B9ACBE610; // Unknown = 
        public const ulong FFlagEnableSkyStyle = 0x19BA6A3F61D; // Bool = false
        public const ulong FFlagEnableSlotsHeadShapeThumbnail = 0x19BA3A51850; // Unknown = 
        public const ulong FFlagEnableSlotsHeadShapeThumbnail2 = 0x19BA3A545D0; // Unknown = 
        public const ulong FFlagEnableSnapInVirtualCursor2 = 0x19BA59BB650; // Unknown = 
        public const ulong FFlagEnableSocialCards2 = 0x19B8C2E3A50; // Unknown = 
        public const ulong FFlagEnableSocialContextToast = 0x19BC0541910; // Unknown = 
        public const ulong FFlagEnableSocialProofOnItemDetails = 0x19BACFD211D; // Bool = false
        public const ulong FFlagEnableSocialProofOnItemDetailsRoactGamepadNavigation = 0x19BACFD5110; // Unknown = 
        public const ulong FFlagEnableSocialProofUserList = 0x19BACFD9DD0; // Unknown = 
        public const ulong FFlagEnableSocialProofUserList_4 = 0x19BACFDB0D0; // Unknown = 
        public const ulong FFlagEnableSocialProofVerticalUserListSheet = 0x19BA74E2010; // Unknown = 
        public const ulong FFlagEnableSocialProofVerticalUserListSheet_2 = 0x19B85788F90; // Unknown = 
        public const ulong FFlagEnableSocialTabsPage = 0x19BACFD92D0; // Unknown = 
        public const ulong FFlagEnableSocialTabsPage_DEV = 0x19BACFDDC10; // Unknown = 
        public const ulong FFlagEnableSortInvitesByScoreExperiment = 0x19BADF9A4DD; // Bool = true
        public const ulong FFlagEnableSoundSessionTelemetry5 = 0x19B9AF123D0; // Unknown = 
        public const ulong FFlagEnableSpatialRobloxGui = 0x19B9FDD4D55; // Bool = false
        public const ulong FFlagEnableSpatialRobloxGui4 = 0x19BB2AF6AD0; // Unknown = 
        public const ulong FFlagEnableSpatialUIBottomBarFixPlaceFilter = 0x19B9FD8839D; // Bool = false
        public const ulong FFlagEnableSpatialUICameraTypeFix8 = 0x19BA3BB18D0; // Unknown = 
        public const ulong FFlagEnableSpatialUIPlaceFilter = 0x19BA3BB2550; // Unknown = 
        public const ulong FFlagEnableSpatialUIScalingFix = 0x19BA3BB9110; // Unknown = 
        public const ulong FFlagEnableSplitPanel = 0x19B85786D90; // Unknown = 
        public const ulong FFlagEnableSquadCoplayAnalytic = 0x19B88C2AD1D; // Bool = false
        public const ulong FFlagEnableSquadDeeplinkWithChatId = 0x19B8C2E3A90; // Unknown = 
        public const ulong FFlagEnableSquadLobbyUpsellCardShortScreenFix = 0x19B82C1A6DD; // Bool = false
        public const ulong FFlagEnableSquadPromptAnalytics = 0x19BA8020A50; // Unknown = 
        public const ulong FFlagEnableSquadRegroupExperimentation = 0x19B9F18E7BD; // Bool = true
        public const ulong FFlagEnableSquadRegroupExperimentation1 = 0x19B8C30211D; // Bool = true
        public const ulong FFlagEnableSquadRegroupExperimentationSmallScreenFix = 0x19B8C30231D; // Bool = true
        public const ulong FFlagEnableSquadRegroupServerCapacityCheck = 0x19B8C3024DD; // Bool = true
        public const ulong FFlagEnableSquadTopBannerWideMode = 0x19B8C2E3F50; // Unknown = 
        public const ulong FFlagEnableSquadUserCardHoverFix = 0x19BACFD1210; // Unknown = 
        public const ulong FFlagEnableSquadsUnifyCoplayExperimentation_dev = 0x19B8FDEE5DD; // Bool = false
        public const ulong FFlagEnableSquadsUnifyCoplayMultiInvitePartyCreation_dev = 0x19B8FDEE49D; // Bool = false
        public const ulong FFlagEnableSquadsUnifyCoplayOneOnOnePartyCreation_dev = 0x19B8FDEE41D; // Bool = false
        public const ulong FFlagEnableStandaloneAppChat = 0x19BA672E0DD; // Bool = false
        public const ulong FFlagEnableStorePreviousAccountData = 0x19B945A18D0; // Unknown = 
        public const ulong FFlagEnableStreamAvatarImageUrlThumbnail = 0x19BA6076950; // Unknown = 
        public const ulong FFlagEnableStudioMockPurchaseRobloxSubscription = 0x19B9F18B7BD; // Bool = true
        public const ulong FFlagEnableSubTabForSpatial = 0x19B9ACB00D0; // Unknown = 
        public const ulong FFlagEnableSubscriptionPurchaseFlowEventIngest = 0x19B8FC33C9D; // Bool = false
        public const ulong FFlagEnableSubscriptionPurchaseToast = 0x19B9EE020DD; // Bool = false
        public const ulong FFlagEnableSubscriptionUpsellUnifiedPurchaseEventTelemetry = 0x19B93A1E010; // Unknown = 
        public const ulong FFlagEnableSummarySystemMessageOnLua = 0x19B8578599D; // Bool = false
        public const ulong FFlagEnableSupportCenter = 0x19B8C30E8DD; // Bool = true
        public const ulong FFlagEnableSystemScrim = 0x19B9AF11ED0; // Unknown = 
        public const ulong FFlagEnableSystemScrimInSettingsHub = 0x19BACE9DC9D; // Bool = false
        public const ulong FFlagEnableSystemTrayModals = 0x19B9ACB18D0; // Unknown = 
        public const ulong FFlagEnableSystemTrayModals3 = 0x19B9ACB8190; // Unknown = 
        public const ulong FFlagEnableTFFeedbackModeEntryCheck = 0x19B9FD8D5DD; // Bool = false
        public const ulong FFlagEnableTTIRecordWebViewMilestones = 0x19B8578C25D; // Bool = false
        public const ulong FFlagEnableTeamTestLua = 0x19B9ACB2C90; // Unknown = 
        public const ulong FFlagEnableTeamTestLuaVersionCheck = 0x19B9ACB9FD0; // Unknown = 
        public const ulong FFlagEnableTelemetryProtocol = 0x19B8C316F90; // Unknown = 
        public const ulong FFlagEnableTenftUiDetailsMoreDropupMenu = 0x19BA6A39810; // Unknown = 
        public const ulong FFlagEnableTiltLoadingScreen = 0x19B9AF128D0; // Unknown = 
        public const ulong FFlagEnableTiltLoadingScreen2 = 0x19B9AF129D0; // Unknown = 
        public const ulong FFlagEnableTimeoutUI = 0x19BA6076B1D; // Bool = true
        public const ulong FFlagEnableToSwitchToSettingsAppWithRouteLua = 0x19B8F90F11D; // Bool = false
        public const ulong FFlagEnableToastIconSupport = 0x19B8C30B390; // Unknown = 
        public const ulong FFlagEnableToastLiteRender = 0x19D85DCDAD0; // Unknown = 
        public const ulong FFlagEnableToastNotificationsDeeplinkConfirmationModalHeightFix = 0x19BA607A050; // Unknown = 
        public const ulong FFlagEnableTopBarAnalytics = 0x19BBF8812A8; // Unknown = 
        public const ulong FFlagEnableTopSongsSort7 = 0x19B88C4EFDD; // Bool = false
        public const ulong FFlagEnableTradesEntryForNonPremium = 0x19BA6A33390; // Unknown = 
        public const ulong FFlagEnableTransparentDeviceIntegrityChallengeSpinner = 0x19BA6078F10; // Unknown = 
        public const ulong FFlagEnableTransparentNativeChallengeWrapper = 0x19B9064461D; // Bool = false
        public const ulong FFlagEnableUIManagerPackgify = 0x19BA6A31950; // Unknown = 
        public const ulong FFlagEnableUIManagerPackgify8 = 0x19BA6A300D0; // Unknown = 
        public const ulong FFlagEnableUISelector3 = 0x19BA4611A5D; // Bool = false
        public const ulong FFlagEnableUnifiedProductPurchaseFlow = 0x19B9ACB64D0; // Unknown = 
        public const ulong FFlagEnableUnifiedProductPurchaseFlowV37 = 0x19B9ACB92D0; // Unknown = 
        public const ulong FFlagEnableUnifiedPurchaseFlowForDevSubs = 0x19B9ACB8A50; // Unknown = 
        public const ulong FFlagEnableUnifiedPurchaseFlowForDevSubs10 = 0x19B9ACB12D0; // Unknown = 
        public const ulong FFlagEnableUniveralVoiceToasts = 0x19BA5157E5D; // Bool = false
        public const ulong FFlagEnableUpdateAddPhoneDescriptionTextExperimentRelease1 = 0x19B90294D90; // Unknown = 
        public const ulong FFlagEnableUpdatedCaptureControls = 0x19D86F0BED0; // Unknown = 
        public const ulong FFlagEnableUpdatedCaptureControls_v9 = 0x19D86F074D0; // Unknown = 
        public const ulong FFlagEnableUpdatedLogoutUpsellModal = 0x19B945A7590; // Unknown = 
        public const ulong FFlagEnableUpsellSuggestionsAnalyticsId = 0x19B9ACBAC90; // Unknown = 
        public const ulong FFlagEnableUpsellVirtualItemBadge = 0x19BAC833B5D; // Bool = false
        public const ulong FFlagEnableUseShowTopBar4 = 0x19B8578931D; // Bool = false
        public const ulong FFlagEnableUserAccessServiceIntegration = 0x19B8DD87890; // Unknown = 
        public const ulong FFlagEnableUserAccessServiceIntegration3 = 0x19B8C30B11D; // Bool = true
        public const ulong FFlagEnableUserInputCFrameLogging = 0x19BBE911690; // Unknown = 
        public const ulong FFlagEnableUserListModule = 0x19BACFD9AD0; // Unknown = 
        public const ulong FFlagEnableUserListModule_2 = 0x19BACFD6F50; // Unknown = 
        public const ulong FFlagEnableUserRecentActivityEntryPoint = 0x19B9F18BA2D; // Bool = true
        public const ulong FFlagEnableUserRecentActivityEntryPoint_v2 = 0x19B8C30371D; // Bool = true
        public const ulong FFlagEnableUserSearchChallengeInterceptor = 0x19B9011D590; // Unknown = 
        public const ulong FFlagEnableVNGNewAppAvailableModal = 0x19B906491DD; // Bool = false
        public const ulong FFlagEnableVPCUpsellFoundationDialogHardening = 0x19B90110FD0; // Unknown = 
        public const ulong FFlagEnableVRChartsTab = 0x19BC054E710; // Unknown = 
        public const ulong FFlagEnableVREnvironmentSetting3 = 0x19BA6A3CA10; // Unknown = 
        public const ulong FFlagEnableVRFTUXExperienceV2 = 0x19BAFCFD810; // Unknown = 
        public const ulong FFlagEnableVRPreparePaymentCheck = 0x19BAC8335DD; // Bool = false
        public const ulong FFlagEnableVRWrapperTransparency = 0x19BC0540ED0; // Unknown = 
        public const ulong FFlagEnableValidateFAEVerificationLink = 0x19B90112A90; // Unknown = 
        public const ulong FFlagEnableVerifiedBadgeStore = 0x19BAE722170; // Unknown = 
        public const ulong FFlagEnableVerifiedCheckViaOverlay = 0x19BA515949D; // Bool = false
        public const ulong FFlagEnableVirtualCursorDebugging = 0x19BA59BF710; // Unknown = 
        public const ulong FFlagEnableVirtualizedListBacktraceTag = 0x19B9029281D; // Bool = false
        public const ulong FFlagEnableVoiceChatStorybookFix = 0x19B81E9E098; // Unknown = 
        public const ulong FFlagEnableVoiceChatVoiceUISync = 0x19BACE7C9DD; // Bool = false
        public const ulong FFlagEnableVoiceEuConsentPrompt = 0x19BACFD261D; // Bool = false
        public const ulong FFlagEnableVoicePromptReasonText = 0x19BA5157A90; // Unknown = 
        public const ulong FFlagEnableVoiceReverseNudge = 0x19B8FDE8F10; // Unknown = 
        public const ulong FFlagEnableVoiceTrialUpsellCard = 0x19B90643F5D; // Bool = false
        public const ulong FFlagEnableVoiceTrustedConnectionsToasts = 0x19BA515851D; // Bool = false
        public const ulong FFlagEnableVoiceUxUpdates5_AEGIS2 = 0x19B8C305A1D; // Bool = true
        public const ulong FFlagEnableVoiceVrVoiceConnectDisconnect_AEGIS2 = 0x19B8C305BDD; // Bool = true
        public const ulong FFlagEnableVolumeSliderQOLFix = 0x19BA6A3F990; // Unknown = 
        public const ulong FFlagEnableVpcForInExperiencePremiumUpsell = 0x19B9EE01F9D; // Bool = false
        public const ulong FFlagEnableVpcForInExperienceSubscriptionPurchase = 0x19B9EE0229D; // Bool = false
        public const ulong FFlagEnableVrVoiceParity = 0x19BA6A3D410; // Unknown = 
        public const ulong FFlagEnableWebAmpWizardForFAEHandoff = 0x19B90112390; // Unknown = 
        public const ulong FFlagEnableWebViewOpenDurationCap = 0x19B90292B90; // Unknown = 
        public const ulong FFlagEnableWebViewStateTracker = 0x19B9ACB5AD0; // Unknown = 
        public const ulong FFlagEnableWebViewStateTracker3 = 0x19B9ACBBAD0; // Unknown = 
        public const ulong FFlagEnableWhatsNew2 = 0x19B9ACB2A50; // Unknown = 
        public const ulong FFlagEnableWhiteOrGreyRobuxIcon = 0x19B948105D0; // Unknown = 
        public const ulong FFlagEnableWhiteRobuxIcon = 0x19B94810910; // Unknown = 
        public const ulong FFlagEnableWidgetLUAIXP = 0x19B88C4BA1D; // Bool = false
        public const ulong FFlagEncodeSquadMembersUpdated = 0x19BA672019D; // Bool = true
        public const ulong FFlagEngineAudioSTTIsDictationEnabled = 0x19BABBD13DD; // Bool = false
        public const ulong FFlagEnhancedPersonaLivenessEvents = 0x19B8C30EF9D; // Bool = true
        public const ulong FFlagEraseFPSFromDefaultSetting = 0x19B9FD8D450; // Unknown = 
        public const ulong FFlagErrorPromptUseLeaveGameHelper = 0x19BA59B3650; // Unknown = 
        public const ulong FFlagEventsInExperienceAppFixStyleLink = 0x19BA6073E1D; // Bool = true
        public const ulong FFlagExpChatAddUserAsyncNilCheck = 0x19B9F18D075; // Bool = true
        public const ulong FFlagExpChatAddWindowSettingDependency = 0x19BA515415D; // Bool = false
        public const ulong FFlagExpChatAddressFrame0Flash = 0x19B9CB74310; // Unknown = 
        public const ulong FFlagExpChatAlignSystemMessageStyling = 0x19B9F187165; // Bool = true
        public const ulong FFlagExpChatBackspaceExitsTargetChannelInGlobalTabs = 0x19BA3A5289D; // Bool = false
        public const ulong FFlagExpChatBubbleChatRerenderOnAncestryChange = 0x19BB8FBFCE8; // Unknown = 
        public const ulong FFlagExpChatCanShowFriendsTab = 0x19BACFDE150; // Unknown = 
        public const ulong FFlagExpChatCanShowFriendsTabRC1 = 0x19BACFD5F90; // Unknown = 
        public const ulong FFlagExpChatChannelBarDropdownZIndexFix = 0x19BA515085D; // Bool = false
        public const ulong FFlagExpChatChannelTabSizingUpdate2 = 0x19BA679FBDD; // Bool = false
        public const ulong FFlagExpChatClearHiddenMessagesPostAgeCheck = 0x19B9CB7971D; // Bool = false
        public const ulong FFlagExpChatComposerFigmaParity = 0x19B9CB7C25D; // Bool = false
        public const ulong FFlagExpChatConditionallyMountAppLayout2 = 0x19BA6B3EE1D; // Bool = false
        public const ulong FFlagExpChatContinuousDictation = 0x19BA59B2850; // Unknown = 
        public const ulong FFlagExpChatDebounceRephraseIndexSelection = 0x19B9FD8D690; // Unknown = 
        public const ulong FFlagExpChatDictatedSpeechEnabled = 0x19BBCD77AD0; // Unknown = 
        public const ulong FFlagExpChatDictation = 0x19BA59B0DD0; // Unknown = 
        public const ulong FFlagExpChatDictation3 = 0x19BA59B1C1D; // Bool = false
        public const ulong FFlagExpChatDictationFTUX = 0x19BBF850408; // Unknown = 
        public const ulong FFlagExpChatDictationFTUX2 = 0x19BABBD021D; // Bool = false
        public const ulong FFlagExpChatDictationFadeOverride = 0x19BA553003D; // Bool = false
        public const ulong FFlagExpChatDictationIXPExposure = 0x19BABBD259D; // Bool = false
        public const ulong FFlagExpChatDictationMicToastFix = 0x19BABBD0950; // Unknown = 
        public const ulong FFlagExpChatDictationU13PolicyToast = 0x19BABBD0F1D; // Bool = false
        public const ulong FFlagExpChatDisableUniverseBubbleChat2 = 0x19B8FA13390; // Unknown = 
        public const ulong FFlagExpChatDoNotSetCursorPosition = 0x19BA3A53AD0; // Unknown = 
        public const ulong FFlagExpChatDynamicV2Pool = 0x19BA515AC5D; // Bool = false
        public const ulong FFlagExpChatEmojiInputParity = 0x19BA59BD950; // Unknown = 
        public const ulong FFlagExpChatEnableCrossAgeChatActivity = 0x19BA515A59D; // Bool = false
        public const ulong FFlagExpChatEnableFOMOUpsell = 0x19B822EA405; // Bool = false
        public const ulong FFlagExpChatEnableFriendsTab = 0x19BACFD3CD0; // Unknown = 
        public const ulong FFlagExpChatEnableFriendsTabRC1 = 0x19BACFD8E10; // Unknown = 
        public const ulong FFlagExpChatEnableGlobalChatSummarySystemMessage = 0x19BA74A581D; // Bool = false
        public const ulong FFlagExpChatEnableGlobalOnlineCommand = 0x19B9F18FFBD; // Bool = true
        public const ulong FFlagExpChatEnableNewBottomLockedScrollView = 0x19B8C2B3D5D; // Bool = false
        public const ulong FFlagExpChatEnablePresetChatBadgeFTUXExperimentation = 0x19B8FDEC91D; // Bool = false
        public const ulong FFlagExpChatEnableTabsImpressionAnalytics = 0x19BA515CB1D; // Bool = false
        public const ulong FFlagExpChatEnableV2ChatWindow = 0x19BA3BBD99D; // Bool = false
        public const ulong FFlagExpChatEnableV2ChatWindow6 = 0x19B9BF24F15; // Bool = false
        public const ulong FFlagExpChatEnableVirtualLocalOnlineCommand = 0x19B8FA13BD0; // Unknown = 
        public const ulong FFlagExpChatEnableVoiceReverseNudge = 0x19BBCD74050; // Unknown = 
        public const ulong FFlagExpChatEvictFloodcheckedFromWindowOrder = 0x19BA553811D; // Bool = false
        public const ulong FFlagExpChatExcludeFOMORenders = 0x19B9CB763D0; // Unknown = 
        public const ulong FFlagExpChatFixBackspaceNilTargetChannel = 0x19B8FA1425D; // Bool = false
        public const ulong FFlagExpChatFixChannelBarInitialWidth = 0x19BA5155010; // Unknown = 
        public const ulong FFlagExpChatFixChannelTabsMidExperienceToggle = 0x19BA74A2ADD; // Bool = false
        public const ulong FFlagExpChatFixInputBarSendEligibility = 0x19B9CB7BFDD; // Bool = false
        public const ulong FFlagExpChatFixLocalUserVerifiedBadge = 0x19B9CB72EDD; // Bool = false
        public const ulong FFlagExpChatFixRateLimitedMessageRemoval = 0x19BA515089D; // Bool = false
        public const ulong FFlagExpChatFixRateLimitedMessageRemoval2 = 0x19BA5158EDD; // Bool = false
        public const ulong FFlagExpChatFixTeamChangeOverwriteChannel = 0x19B8FA14710; // Unknown = 
        public const ulong FFlagExpChatFixTopPaddingColor = 0x19BA6B3E210; // Unknown = 
        public const ulong FFlagExpChatFixWarmMountBottomLock = 0x19BA3A5465D; // Bool = false
        public const ulong FFlagExpChatFlipDictationPriority = 0x19BBCD77890; // Unknown = 
        public const ulong FFlagExpChatFocusChannelBarSupport = 0x19BA515371D; // Bool = false
        public const ulong FFlagExpChatFocusViaLastModeFix = 0x19BA4611210; // Unknown = 
        public const ulong FFlagExpChatFocusViaLastModeFix2 = 0x19BABBD28D0; // Unknown = 
        public const ulong FFlagExpChatFocusablePlaceholderText = 0x19BAB70F9DD; // Bool = false
        public const ulong FFlagExpChatFriendsTabUsePolicy = 0x19BA6A3F790; // Unknown = 
        public const ulong FFlagExpChatGlobalCommandAutocompletePrimaryAliasOnly = 0x19BA4616E10; // Unknown = 
        public const ulong FFlagExpChatGuacChatDisabledReason = 0x19B8C2E2E90; // Unknown = 
        public const ulong FFlagExpChatInputBarV2CornerAndTruncationFix = 0x19BAB70FBD0; // Unknown = 
        public const ulong FFlagExpChatInputBarV2CustomSendButton = 0x19BAB70FCDD; // Bool = false
        public const ulong FFlagExpChatKeepV2PoolMounted = 0x19BA515669D; // Bool = false
        public const ulong FFlagExpChatLimitScrollingV2Window = 0x19BA3A57A1D; // Bool = false
        public const ulong FFlagExpChatLogGlobalChatTabClicked = 0x19BA515025D; // Bool = false
        public const ulong FFlagExpChatLogTabClicked = 0x19BA51502D0; // Unknown = 
        public const ulong FFlagExpChatLongPressContinuousDictation = 0x19BA59B7A1D; // Bool = false
        public const ulong FFlagExpChatMainInputBarClickAnalytics = 0x19BABBD301D; // Bool = false
        public const ulong FFlagExpChatMemoBillboardGui = 0x19BBCD71190; // Unknown = 
        public const ulong FFlagExpChatMessagesStoreBatch = 0x19BA5531F9D; // Bool = false
        public const ulong FFlagExpChatMessagesStoreKeepInByMessageId = 0x19BA55331DD; // Bool = false
        public const ulong FFlagExpChatMessagesStoreMemoryCleanup = 0x19BA5530C9D; // Bool = false
        public const ulong FFlagExpChatMessagesStoreUseProxy = 0x19BA5531D9D; // Bool = false
        public const ulong FFlagExpChatMicBubbleSingleImage = 0x19BBCD78490; // Unknown = 
        public const ulong FFlagExpChatMigrateScrollIntervalTracker = 0x19B9CB720D0; // Unknown = 
        public const ulong FFlagExpChatMigrationReplicationFix = 0x19BACFD0590; // Unknown = 
        public const ulong FFlagExpChatMoveMessagesStoreToInit = 0x19BA515ED1D; // Bool = false
        public const ulong FFlagExpChatMuteByUserIdBeforeUsernameCheck = 0x19BA515E11D; // Bool = false
        public const ulong FFlagExpChatNewInputBar = 0x19BBCD74110; // Unknown = 
        public const ulong FFlagExpChatNewInputBar4 = 0x19BBCD72910; // Unknown = 
        public const ulong FFlagExpChatNewInputBarDictation = 0x19BABBD1F90; // Unknown = 
        public const ulong FFlagExpChatOnlyWakeTextForSelectedTab = 0x19BA74A4650; // Unknown = 
        public const ulong FFlagExpChatPerfTrackerTabName = 0x19B9CB72C50; // Unknown = 
        public const ulong FFlagExpChatPolishSummaryMessageUI = 0x19BA6796F10; // Unknown = 
        public const ulong FFlagExpChatPresetAutocompleteIxpEnabled = 0x19BABBD2A1D; // Bool = false
        public const ulong FFlagExpChatPresetBoltInMessageLayout = 0x19B9CB735DD; // Bool = false
        public const ulong FFlagExpChatPresetButtonOldInputBarV2 = 0x19BA6B3E510; // Unknown = 
        public const ulong FFlagExpChatPresetChatAutocompleteAnalyticsEnabled = 0x19BABBD1710; // Unknown = 
        public const ulong FFlagExpChatPresetChatAutocompleteEnabled = 0x19BA7311E05; // Bool = false
        public const ulong FFlagExpChatPresetChatEnabled10 = 0x19B8FA1445D; // Bool = false
        public const ulong FFlagExpChatPresetChatFixesEnabled = 0x19BA6B3F0DD; // Bool = false
        public const ulong FFlagExpChatPresetChatGamepadEnabled = 0x19BAB70FF50; // Unknown = 
        public const ulong FFlagExpChatPresetChatIXPExposure = 0x19BABBD219D; // Bool = false
        public const ulong FFlagExpChatPresetChatLoadTestEnabled = 0x19B8FA1459D; // Bool = false
        public const ulong FFlagExpChatPresetChatSendEnabled = 0x19B9F18C88D; // Bool = true
        public const ulong FFlagExpChatPresetChatVREnabled = 0x19B8FA143DD; // Bool = false
        public const ulong FFlagExpChatPresetFixChatHotkey = 0x19BA6B3EAD0; // Unknown = 
        public const ulong FFlagExpChatReconcileOnAgeVerifiedChange = 0x19BA74A2990; // Unknown = 
        public const ulong FFlagExpChatRefactorEnabledMessageLogic = 0x19BBC38745D; // Bool = false
        public const ulong FFlagExpChatRemoveBubbleChatAppUserMessagesState = 0x19BBACABA05; // Bool = false
        public const ulong FFlagExpChatRemoveSpaceFromTeamPrefix = 0x19BB20AC270; // Unknown = 
        public const ulong FFlagExpChatReportChatEnabledUserCountMetrics = 0x19BBC385790; // Unknown = 
        public const ulong FFlagExpChatReportVirtualCommandTelemetry = 0x19D82453925; // Bool = false
        public const ulong FFlagExpChatRewriteInline = 0x19BA515FE1D; // Bool = false
        public const ulong FFlagExpChatRewriteInline3 = 0x19BA5157D5D; // Bool = false
        public const ulong FFlagExpChatRewriteInlineIxpEnabled = 0x19BA515935D; // Bool = true
        public const ulong FFlagExpChatRewriteToggleAnalytics = 0x19BA5150D5D; // Bool = true
        public const ulong FFlagExpChatScrollbarInset = 0x19BA3A5E450; // Unknown = 
        public const ulong FFlagExpChatSelectTextChatTabByName = 0x19BACFD6610; // Unknown = 
        public const ulong FFlagExpChatSendWindowScrollEvent = 0x19BA3A5E2D0; // Unknown = 
        public const ulong FFlagExpChatShowPresetTooltipToNonAgeChecked2 = 0x19BC2218430; // Unknown = 
        public const ulong FFlagExpChatSuppressGlobalSummaryTabUnread = 0x19BA74A5D9D; // Bool = false
        public const ulong FFlagExpChatSuppressWelcomeMessageTabUnread = 0x19B8FA14A90; // Unknown = 
        public const ulong FFlagExpChatSyntheticSystemMessageRichText = 0x19B8FA14D1D; // Bool = false
        public const ulong FFlagExpChatTelemetryEventTrigger3 = 0x19B9F18570D; // Bool = true
        public const ulong FFlagExpChatTopBannerForPresetChatAccess = 0x19BA5153DDD; // Bool = false
        public const ulong FFlagExpChatTopBannerZIndexFix = 0x19BB6B2DB50; // Unknown = 
        public const ulong FFlagExpChatTranslationToggleSpacingFix = 0x19BA5157CDD; // Bool = false
        public const ulong FFlagExpChatTransparentFocusSupport = 0x19BA553291D; // Bool = false
        public const ulong FFlagExpChatTriggerWindowStatusEvent = 0x19BA6B3F550; // Unknown = 
        public const ulong FFlagExpChatUniverseChatPresetEnabled = 0x19BA461BADD; // Bool = false
        public const ulong FFlagExpChatUniverseChatPresetEnabled2 = 0x19BA731739D; // Bool = true
        public const ulong FFlagExpChatUnreadTabIndicatorV2Window = 0x19BB20A429D; // Bool = true
        public const ulong FFlagExpChatUseAdorneeStore = 0x19BACFD42D0; // Unknown = 
        public const ulong FFlagExpChatUseAdorneeStoreV4 = 0x19BACFD1110; // Unknown = 
        public const ulong FFlagExpChatUseChannelTabsStore = 0x19BACFD1C9D; // Bool = true
        public const ulong FFlagExpChatUseChannelTabsStore3 = 0x19BACFD169D; // Bool = true
        public const ulong FFlagExpChatUseChatConfigStore = 0x19BACFD38D0; // Unknown = 
        public const ulong FFlagExpChatUseChatMuteStore = 0x19BACFD7050; // Unknown = 
        public const ulong FFlagExpChatUseGuacForCrossAgeChat = 0x19B8C2E4CD0; // Unknown = 
        public const ulong FFlagExpChatUseGuacForFOMOUpsell = 0x19B8C2E4B90; // Unknown = 
        public const ulong FFlagExpChatUseInternalTextChatAPIs2 = 0x19BACFD21D0; // Unknown = 
        public const ulong FFlagExpChatUseMessagesStore = 0x19BACFD0B90; // Unknown = 
        public const ulong FFlagExpChatUseMessagesStore9 = 0x19BACFD8DDD; // Bool = true
        public const ulong FFlagExpChatUseProximityStore = 0x19BACFDD810; // Unknown = 
        public const ulong FFlagExpChatUseSharedChannelTabDisplayLabel2 = 0x19BACFD72D0; // Unknown = 
        public const ulong FFlagExpChatUseTooltipPromptStyle = 0x19BBCD75390; // Unknown = 
        public const ulong FFlagExpChatUseUnifiedTooltipStore = 0x19B9F18C8CD; // Bool = true
        public const ulong FFlagExpChatUseUpdatedMessageRendered = 0x19BBCD7C390; // Unknown = 
        public const ulong FFlagExpChatUseUpdatedUserCountStrings = 0x19B8FA13650; // Unknown = 
        public const ulong FFlagExpChatUseVirtualCommandRunner = 0x19BBCD77D10; // Unknown = 
        public const ulong FFlagExpChatUseVoiceParticipantsStore2 = 0x19BACFDC0D0; // Unknown = 
        public const ulong FFlagExpChatWindowSyncUnibar = 0x19BA59B031D; // Bool = false
        public const ulong FFlagExpDetailsUseSelectionBumpers = 0x19BA520DEBD; // Bool = true
        public const ulong FFlagExperienceBannerImageAllowCustomDimensions = 0x19B9026245D; // Bool = false
        public const ulong FFlagExperienceBannerImageDefaultFallback = 0x19B9026269D; // Bool = false
        public const ulong FFlagExperienceChatUserProfileApiEnabledForAll_v1 = 0x19BA515EF5D; // Bool = false
        public const ulong FFlagExperienceLoadingScreenFixStyleLink = 0x19BA8A08A5D; // Bool = false
        public const ulong FFlagExperienceMenuGamepadExposureEnabled = 0x19B9ACB5B10; // Unknown = 
        public const ulong FFlagExperienceMenuGamepadExposureEnabled684 = 0x19B9ACB55D0; // Unknown = 
        public const ulong FFlagExperienceShopGlobalIconSkipCoreGuiCheck = 0x19BB7F4C350; // Unknown = 
        public const ulong FFlagExperiencesOnProfile = 0x19BA59B1B90; // Unknown = 
        public const ulong FFlagExperiencesOnProfile_v2 = 0x19BA59BC110; // Unknown = 
        public const ulong FFlagExtendScrollingFramesBySafeInsets2 = 0x19B8578899D; // Bool = false
        public const ulong FFlagFFlagAXFixAvatarSaveContext = 0x19B9026C59D; // Bool = false
        public const ulong FFlagFFlagAddDefaultFocusNavSelectorsOnBuyPurchasePrompt = 0x19BAC83109D; // Bool = false
        public const ulong FFlagFFlagBlackbirdUpdateStringFlyoutMenu = 0x19BA6A363D0; // Unknown = 
        public const ulong FFlagFFlagDebugInlineLayout = 0x19B8FC348D0; // Unknown = 
        public const ulong FFlagFFlagEnableCallingLogoutOnResetIXP = 0x19B945A4510; // Unknown = 
        public const ulong FFlagFFlagEnableFontStylisticAlternativesOnSocialScreens = 0x19BACFD37D0; // Unknown = 
        public const ulong FFlagFFlagEnableLookFavoriting = 0x19B9026C1D0; // Unknown = 
        public const ulong FFlagFFlagEnableMutexOnGenericChallengeInterceptorMount = 0x19BA607F290; // Unknown = 
        public const ulong FFlagFFlagFixDetailsPageIconShadowSlicing = 0x19BA609B050; // Unknown = 
        public const ulong FFlagFFlagFixLayeredSorting = 0x19BBC7ABFD0; // Unknown = 
        public const ulong FFlagFFlagLogAllGuacRead = 0x19BB6BBCB90; // Unknown = 
        public const ulong FFlagFFlagLogFirstGuacRead = 0x19BB6BBCB50; // Unknown = 
        public const ulong FFlagFFlagLuaAppEnableWindowsHandheldScale = 0x19BA461B1DD; // Bool = false
        public const ulong FFlagFFlagLuaAppFixToastNotificationClosePosition = 0x19BA6074350; // Unknown = 
        public const ulong FFlagFFlagPCMAcceptWidthAsProp = 0x19B859CA090; // Unknown = 
        public const ulong FFlagFFlagSongEdpCarouselIxp2 = 0x19B88C407D0; // Unknown = 
        public const ulong FFlagFFlagTimeoutRemoteEvent = 0x19BACE7931D; // Bool = false
        public const ulong FFlagFFlagUpdateNoInternetConnectionText = 0x19BBC7A9C10; // Unknown = 
        public const ulong FFlagFacialAnimationStreamingClearAllConnectionsFix2 = 0x19B9F0ACF5D; // Bool = false
        public const ulong FFlagFacialAnimationStreamingClearTrackImprovementsV2 = 0x19B9F0ACDDD; // Bool = false
        public const ulong FFlagFacialAnimationStreamingFixNilMutedCheck = 0x19B9F0ACFD0; // Unknown = 
        public const ulong FFlagFacialAnimationStreamingIfNoDynamicHeadDisableA2C = 0x19B9F0AD01D; // Bool = false
        public const ulong FFlagFacialAnimationStreamingSearchForReplacementWhenRemovingAnimator = 0x19B9F0ACE5D; // Bool = false
        public const ulong FFlagFacialAnimationStreamingValidateAnimatorBeforeRemoving = 0x19B9F0ACE1D; // Bool = false
        public const ulong FFlagFeedbackEntryPointButtonSizeAdjustment2 = 0x19B9FD8D71D; // Bool = false
        public const ulong FFlagFeedbackEntryPointImprovedStrictnessCheck = 0x19B9FD8D8DD; // Bool = false
        public const ulong FFlagFilterNewPlayerListValueStat = 0x19BACE95CDD; // Bool = false
        public const ulong FFlagFilterOutDeletedAccountsGameInvites = 0x19BADF9F2DD; // Bool = true
        public const ulong FFlagFilterOutShopOnlyItemsonBulkPurchase = 0x19B9ACBBF90; // Unknown = 
        public const ulong FFlagFilterSecurityAlertsVRToastEnabled = 0x19B8C30B050; // Unknown = 
        public const ulong FFlagFindFriendsClickedEventEnabled = 0x19BAFCF32D0; // Unknown = 
        public const ulong FFlagFireErrorRCCTimeoutSignal = 0x19B859C935D; // Bool = false
        public const ulong FFlagFix10ftGlobalNavSelection = 0x19BA6A315DD; // Bool = true
        public const ulong FFlagFixAbuseReportInExpPhantomAnalytics = 0x19BB7F47FD0; // Unknown = 
        public const ulong FFlagFixAccountSwitcherOverlayBackgroundTap = 0x19B88C4CC9D; // Bool = false
        public const ulong FFlagFixAnalyticsForDynamicReportV2 = 0x19B8C30DB90; // Unknown = 
        public const ulong FFlagFixAppNavContainerShortcutBarHeight = 0x19BBCD716D0; // Unknown = 
        public const ulong FFlagFixBackOnTopBarTriggeringDevUI = 0x19B82BCFDDD; // Bool = false
        public const ulong FFlagFixBannerButtonSize = 0x19B90294F10; // Unknown = 
        public const ulong FFlagFixBulkPurchaseInputPerf = 0x19B9F9296D0; // Unknown = 
        public const ulong FFlagFixBulkPurchaseStarterGuiRename = 0x19B9F92999D; // Bool = false
        public const ulong FFlagFixBundlePromptThumbnail = 0x19D85DC97D0; // Unknown = 
        public const ulong FFlagFixBundleThumbnailOnDetailPage = 0x19B9F0A3A90; // Unknown = 
        public const ulong FFlagFixBuyRobuxForAndroid = 0x19B9F92991D; // Bool = false
        public const ulong FFlagFixCameraSetupBeforeMood = 0x19B84FE539D; // Bool = false
        public const ulong FFlagFixCarouselTileSizeScaling = 0x19B8FA1ECD0; // Unknown = 
        public const ulong FFlagFixCharacterManagerValueConversionWarning = 0x19B90646F1D; // Bool = false
        public const ulong FFlagFixCharacterNameHandlerNilProfileCrash = 0x19B9F921E1D; // Bool = false
        public const ulong FFlagFixChatLanguageSwitcherLabel = 0x19B9FD8C59D; // Bool = false
        public const ulong FFlagFixChatsBottomInsetBackgroundColor = 0x19B8FA15150; // Unknown = 
        public const ulong FFlagFixCohubExposureLayer = 0x19BA59B30D0; // Unknown = 
        public const ulong FFlagFixCohubSearchYNavigation = 0x19BA59B4810; // Unknown = 
        public const ulong FFlagFixCohubUiBugs = 0x19BA59B9250; // Unknown = 
        public const ulong FFlagFixConnectTabSearchBarHeight = 0x19BACFD5F10; // Unknown = 
        public const ulong FFlagFixConsoleEDPDirectionalNavigation = 0x19BA609F910; // Unknown = 
        public const ulong FFlagFixContextualMenu = 0x19B82CBDE5D; // Bool = true
        public const ulong FFlagFixCountersForUpsellModalShown = 0x19B9EE0185D; // Bool = false
        public const ulong FFlagFixCrossExperienceVoiceExecutePrint = 0x19B9AF197D0; // Unknown = 
        public const ulong FFlagFixCyclicFullscreenIndexEvent = 0x19B9FD8D31D; // Bool = false
        public const ulong FFlagFixDefaultThemeOverride = 0x19B9AF16F10; // Unknown = 
        public const ulong FFlagFixDetailsPageIconShadowSlicing = 0x19B82C68B9D; // Bool = false
        public const ulong FFlagFixDeveloperConsoleButtonSizeAndPositioning = 0x19B9FD8D4DD; // Bool = false
        public const ulong FFlagFixDeviceSafePaddingAccess = 0x19BA609FF50; // Unknown = 
        public const ulong FFlagFixDisableTopPaddingError = 0x19BACE9C71D; // Bool = false
        public const ulong FFlagFixDisabledScrollOnIos = 0x19BACE9DD5D; // Bool = false
        public const ulong FFlagFixDoubleSubmit = 0x19B9011E41D; // Bool = false
        public const ulong FFlagFixDrawerNavigateBackWhileClosing = 0x19B9AF105DD; // Bool = false
        public const ulong FFlagFixEmptyLimitedBadges = 0x19B9026DD1D; // Bool = false
        public const ulong FFlagFixEmptyLimitedBadgesForBundles = 0x19B9026D2D0; // Unknown = 
        public const ulong FFlagFixFeedItemRenderedRowsEqualityCheck = 0x19B9026A89D; // Bool = false
        public const ulong FFlagFixFetchNextOmniWithoutPageToken3 = 0x19B90262C5D; // Bool = false
        public const ulong FFlagFixFiatPaidAccessPlayButton = 0x19B8F90E85D; // Bool = false
        public const ulong FFlagFixFocusWhenInGameMenuIsOpen = 0x19BA6073C5D; // Bool = true
        public const ulong FFlagFixFullscreenTitleBarPromiseCancel = 0x19D8168F110; // Unknown = 
        public const ulong FFlagFixGameInviteModalLoadTimeIncrease = 0x19D895251D0; // Unknown = 
        public const ulong FFlagFixGetPlayerByUserIdStringCast = 0x19B8FDEA690; // Unknown = 
        public const ulong FFlagFixGlobalChat3pSummarySystemMessage = 0x19BA74A5B5D; // Bool = false
        public const ulong FFlagFixHeadShapeColorSlider = 0x19BA3A55D50; // Unknown = 
        public const ulong FFlagFixIGMTabTransitions = 0x19B9FD86990; // Unknown = 
        public const ulong FFlagFixInactiveChildStateForwarding = 0x19B9AF1A9D0; // Unknown = 
        public const ulong FFlagFixIosAuthServiceCredentialSheetBackends = 0x19BBC1C6050; // Unknown = 
        public const ulong FFlagFixIosOtpAutofill = 0x19BBC386410; // Unknown = 
        public const ulong FFlagFixIsConsoleCheckForSocialCarousel = 0x19B8C2E1FDD; // Bool = false
        public const ulong FFlagFixJoinVoiceDelayedAFMInit = 0x19B9FD80E9D; // Bool = false
        public const ulong FFlagFixLayeredSorting = 0x19B82BC955D; // Bool = false
        public const ulong FFlagFixLimitedBundleResalePrerequisite = 0x19D85DC4350; // Unknown = 
        public const ulong FFlagFixLocalizationOfMissingAgreementTitles = 0x19B859C99DD; // Bool = true
        public const ulong FFlagFixLocalizationOfStudioTermsForVNGSKU = 0x19B859C9650; // Unknown = 
        public const ulong FFlagFixLoginV2LandscapeLayout = 0x19B9AF19C90; // Unknown = 
        public const ulong FFlagFixMediaGalleryOversized = 0x19BB1D98190; // Unknown = 
        public const ulong FFlagFixMomentsExperienceFallback = 0x19B9ACB0AD0; // Unknown = 
        public const ulong FFlagFixMomentsTabReactiveIXPRace = 0x19B857856D0; // Unknown = 
        public const ulong FFlagFixMoreSubMenuTitleFlash = 0x19BBCD729D0; // Unknown = 
        public const ulong FFlagFixNavBarStartupDuplicateAnim = 0x19B90642FDD; // Bool = false
        public const ulong FFlagFixNavigationInsetsOnHiddenTabBar = 0x19B9ACB4990; // Unknown = 
        public const ulong FFlagFixNonTruncatedText = 0x19B90643EDD; // Bool = false
        public const ulong FFlagFixOffSaleCurrentlyWearingItemNavigation = 0x19B8578ADDD; // Bool = false
        public const ulong FFlagFixOnBadgeAwardedError = 0x19BACFEBFDD; // Bool = false
        public const ulong FFlagFixOneNameManyFacesDisconnectCrash = 0x19B9F92421D; // Bool = false
        public const ulong FFlagFixPartyNudgeNilThunkWhenLeave = 0x19BA802EDD0; // Unknown = 
        public const ulong FFlagFixPartyVoiceGetPermissions2 = 0x19B8C2E339D; // Bool = false
        public const ulong FFlagFixPeekViewAnimationJitter = 0x19BA609C010; // Unknown = 
        public const ulong FFlagFixPeoplePageCardTooltip = 0x19BBC387010; // Unknown = 
        public const ulong FFlagFixPlainTextAutomaticSizeClippingText = 0x19BB6BB9DD0; // Unknown = 
        public const ulong FFlagFixPlatformRestrictedHomeClobber = 0x19B9AF161D0; // Unknown = 
        public const ulong FFlagFixPlayerGuiSelectionBugOnPromptExit = 0x19B9EE0255D; // Bool = false
        public const ulong FFlagFixPolicyStalePlayerUpdates = 0x19BB6BBCC90; // Unknown = 
        public const ulong FFlagFixPromptGameInviteUIButtonScaling = 0x19B81E9F448; // Unknown = 
        public const ulong FFlagFixPurchasingErrorCounter = 0x19D85DC8010; // Unknown = 
        public const ulong FFlagFixReportAdInfoDuringRotation = 0x19BA8A01850; // Unknown = 
        public const ulong FFlagFixReportButtonCutOff = 0x19B9FD86B1D; // Bool = false
        public const ulong FFlagFixResaleDisplayPrice = 0x19D85DC21DD; // Bool = false
        public const ulong FFlagFixSTUXShowingIncorrectly = 0x19BA5158890; // Unknown = 
        public const ulong FFlagFixSafetyBubbleWidth = 0x19B9FDD8F95; // Bool = false
        public const ulong FFlagFixSduiCardFocusNavScroll = 0x19B88C26590; // Unknown = 
        public const ulong FFlagFixSduiEdpTtiPeekCategory = 0x19BC0545250; // Unknown = 
        public const ulong FFlagFixSeamlessVoiceIntegrationWithPrivateVoice2 = 0x19B8C2E2B10; // Unknown = 
        public const ulong FFlagFixSelectionWithWebViews = 0x19B9AF1AC90; // Unknown = 
        public const ulong FFlagFixSettingshubImportOrder = 0x19BBC38269D; // Bool = false
        public const ulong FFlagFixSignalFinishedOnError = 0x19B8FC33F5D; // Bool = false
        public const ulong FFlagFixSpatialUICaptures = 0x19B8C2E1C10; // Unknown = 
        public const ulong FFlagFixSquadTopBannerMemo = 0x19B90290A50; // Unknown = 
        public const ulong FFlagFixTabletEDPNavBarVisibility = 0x19B90643810; // Unknown = 
        public const ulong FFlagFixTimedOptionRefresh = 0x19D85DC51DD; // Bool = false
        public const ulong FFlagFixToastNotificationRightPosition = 0x19B8188931D; // Bool = true
        public const ulong FFlagFixUnifiedPurchaseResalePurchases = 0x19BA3A51390; // Unknown = 
        public const ulong FFlagFixUnifiedUpsellCompletionModal = 0x19BAC836B5D; // Bool = false
        public const ulong FFlagFixUnnecessaryPaddingInUnifiedPurchaseModal = 0x19B82E0F85D; // Bool = false
        public const ulong FFlagFixUpsellModalUnevenLayout = 0x19BAC835EDD; // Bool = false
        public const ulong FFlagFixUpsellVerificationToNavigateToOverlays = 0x19BBC38261D; // Bool = false
        public const ulong FFlagFixUseDeviceOrientationNilViewportSize = 0x19B859C57D0; // Unknown = 
        public const ulong FFlagFixUserInfoSelection = 0x19B902935D0; // Unknown = 
        public const ulong FFlagFixUserInfoWidgetPlusBadge = 0x19BA6A3BA50; // Unknown = 
        public const ulong FFlagFixUserRowCombinedName = 0x19B8C301210; // Unknown = 
        public const ulong FFlagFixUsernameSelectionStuck = 0x19B90293390; // Unknown = 
        public const ulong FFlagFixUsernameValidationAlreadyInUse = 0x19BA5534F10; // Unknown = 
        public const ulong FFlagFixUsernameValidationBackendCriteria = 0x19B88C6189D; // Bool = false
        public const ulong FFlagFixVRAvatarPlacement = 0x19B90646C9D; // Bool = false
        public const ulong FFlagFixVRBottomBarAnalytics = 0x19BAEB7969D; // Bool = false
        public const ulong FFlagFixVirtualizedGridNumItems = 0x19BBC38F8D0; // Unknown = 
        public const ulong FFlagFixWindowDragError = 0x19D81683B90; // Unknown = 
        public const ulong FFlagFixWindowDragStaleConnection = 0x19D81680190; // Unknown = 
        public const ulong FFlagFlyoutDisablePremiumEntrypoint1 = 0x19BB6BBE2DD; // Bool = true
        public const ulong FFlagFlyoutDisallowAlternativeEntryOnProfileEntryEnabled = 0x19BA4610B50; // Unknown = 
        public const ulong FFlagFlyoutEnableGiftcardsWithRedeem = 0x19BB6BB465D; // Bool = true
        public const ulong FFlagFlyoutFacepileEnableProfileEntry = 0x19BA4615750; // Unknown = 
        public const ulong FFlagFlyoutHamburgerEnableProfileEntry = 0x19BA626ED9D; // Bool = true
        public const ulong FFlagFlyoutHideFriendsHeader = 0x19B8FA1DC5D; // Bool = false
        public const ulong FFlagFlyoutNavigationInMarketplace = 0x19B9AF14B10; // Unknown = 
        public const ulong FFlagFlyoutRemoveAddSessionInfo = 0x19B8579BA75; // Bool = false
        public const ulong FFlagFlyoutResolveItemContextOnActivation = 0x19BBF7C3EF5; // Bool = false
        public const ulong FFlagFlyoutShowFriendsSortForCurrentVariant = 0x19BA46145D0; // Unknown = 
        public const ulong FFlagFlyoutSidePanelTradesEntry = 0x19D7C7CEAD0; // Unknown = 
        public const ulong FFlagFlyoutUseOpenHook = 0x19B85788E5D; // Bool = false
        public const ulong FFlagFocusRootUseHooks = 0x19B8F90899D; // Bool = false
        public const ulong FFlagForceAegisPhase2Modal = 0x19B9026955D; // Bool = false
        public const ulong FFlagForceEnableArgoPartyChanges7 = 0x19B8FDECD9D; // Bool = false
        public const ulong FFlagForceEnableExpChatNewSystemMessages = 0x19B8FDEC210; // Unknown = 
        public const ulong FFlagForceEnableLuckyRecommendation = 0x19B8C2E3BD0; // Unknown = 
        public const ulong FFlagForceEnablePartyCoordinationUiChanges3 = 0x19B8FDEDBD0; // Unknown = 
        public const ulong FFlagForceEnableQueueAutoJoinNewServer2 = 0x19B8FDED39D; // Bool = false
        public const ulong FFlagForceEnableQueueJoinNewServerButton2 = 0x19B8FDED5DD; // Bool = false
        public const ulong FFlagForceEnableSocialCarouselPartyPage5 = 0x19B8FDEF11D; // Bool = false
        public const ulong FFlagForceEnableSquad = 0x19B8C2E3CD0; // Unknown = 
        public const ulong FFlagForceEnableSquadRegroup = 0x19B8C301850; // Unknown = 
        public const ulong FFlagForceGetGameIconsFromThumbnailsDeliveryApi = 0x19B88C25A5D; // Bool = true
        public const ulong FFlagForceReportAnythingAnnotationEnabled = 0x19B9AF1EE90; // Unknown = 
        public const ulong FFlagFoundationActionEmphasisStatusIndicator = 0x19B9AF1C490; // Unknown = 
        public const ulong FFlagFoundationAvatarBeta3 = 0x19B9AF1AED0; // Unknown = 
        public const ulong FFlagFoundationAvatarBindableUserId = 0x19B9AF11510; // Unknown = 
        public const ulong FFlagFoundationAvatarIncludeProfileFrame = 0x19B9AF18E90; // Unknown = 
        public const ulong FFlagFoundationBadgeBetaUpdate3 = 0x19B9CB70ADD; // Bool = false
        public const ulong FFlagFoundationBaseMenuContentSizing = 0x19B9AF16D50; // Unknown = 
        public const ulong FFlagFoundationBaseMenuSubmenuMaxHeight = 0x19B9AF1CB10; // Unknown = 
        public const ulong FFlagFoundationBottomSheetFixHeightCap = 0x19B9AF1E2D0; // Unknown = 
        public const ulong FFlagFoundationBottomSheetGestureInteractionSink = 0x19B9AF13910; // Unknown = 
        public const ulong FFlagFoundationBottomSheetOnSnapPointChanged = 0x19B9AF15350; // Unknown = 
        public const ulong FFlagFoundationBottomSheetScrollAtMaxTolerance = 0x19B9AF12D90; // Unknown = 
        public const ulong FFlagFoundationButtonLabelTypography = 0x19B9AF19DD0; // Unknown = 
        public const ulong FFlagFoundationCheckboxBeta = 0x19B9AF1EC90; // Unknown = 
        public const ulong FFlagFoundationCoachmarkPressedOutside = 0x19B9CB7E1DD; // Bool = false
        public const ulong FFlagFoundationDateTimePickerBetaUpdate = 0x19B9CB7049D; // Bool = false
        public const ulong FFlagFoundationDateTimePickerDSTFix = 0x19B82DBA2D0; // Unknown = 
        public const ulong FFlagFoundationDialogBetaUpdate = 0x19B9CB7311D; // Bool = false
        public const ulong FFlagFoundationDisableTokenScaling2 = 0x19B9AF1FC50; // Unknown = 
        public const ulong FFlagFoundationDropdownSelectionProps = 0x19B9AF182D0; // Unknown = 
        public const ulong FFlagFoundationDropdownSizeGap = 0x19B9AF19A10; // Unknown = 
        public const ulong FFlagFoundationFixTabsBorderPosition = 0x19B9CB7529D; // Bool = false
        public const ulong FFlagFoundationFixTabsFitBorderWidth2 = 0x19B9AF1F4D0; // Unknown = 
        public const ulong FFlagFoundationGuiObjectInputSinkProperty = 0x19B9AF1F190; // Unknown = 
        public const ulong FFlagFoundationImageContentSupport = 0x19B9AF1F350; // Unknown = 
        public const ulong FFlagFoundationIncludeSpaceRequiredLabel = 0x19B9CB7179D; // Bool = false
        public const ulong FFlagFoundationInputGroup = 0x19B9AF1ED50; // Unknown = 
        public const ulong FFlagFoundationInteractableSecondaryActivated = 0x19B9AF1C2D0; // Unknown = 
        public const ulong FFlagFoundationInternalInputBeta2 = 0x19B9AF1D190; // Unknown = 
        public const ulong FFlagFoundationListItemDecoupledInput = 0x19B9CB7285D; // Bool = false
        public const ulong FFlagFoundationListItemTypographySpacing = 0x19B9CB7F11D; // Bool = false
        public const ulong FFlagFoundationListStableContextValue = 0x19B9CB7751D; // Bool = false
        public const ulong FFlagFoundationNumberInputBeta = 0x19B9AF10D50; // Unknown = 
        public const ulong FFlagFoundationNumberInputOnTextChanged = 0x19B9AF19190; // Unknown = 
        public const ulong FFlagFoundationNumberInputScrubCallbackProps = 0x19B9CB7ED5D; // Bool = false
        public const ulong FFlagFoundationOptionSelectorGroupBeta = 0x19B9CB7ACDD; // Bool = false
        public const ulong FFlagFoundationOptionSelectorGroupFixes = 0x19B9AF16810; // Unknown = 
        public const ulong FFlagFoundationOverlayResilientMainGui = 0x19B9AF14910; // Unknown = 
        public const ulong FFlagFoundationPopoverClickOutsideInGuiShadow = 0x19B9CB7E89D; // Bool = false
        public const ulong FFlagFoundationPopoverContentAnchorFix = 0x19B9CB7B69D; // Bool = false
        public const ulong FFlagFoundationPopoverPluginAnchorRefresh = 0x19B9CB7BD9D; // Bool = true
        public const ulong FFlagFoundationPopoverPluginOverlayMeasurement2 = 0x19B9AF10A90; // Unknown = 
        public const ulong FFlagFoundationPopoverRecomputeContentSize = 0x19B9CB7C81D; // Bool = false
        public const ulong FFlagFoundationProgressBarBetaUpdate = 0x19B9CB7ED1D; // Bool = false
        public const ulong FFlagFoundationProgressCircleRoundCaps = 0x19B9CB7F29D; // Bool = false
        public const ulong FFlagFoundationRadioBeta = 0x19B9AF1DBD0; // Unknown = 
        public const ulong FFlagFoundationRemoveSecondUIDDFromScrubbableTextboxes = 0x19B9AF139D0; // Unknown = 
        public const ulong FFlagFoundationSegmentedControlBeta = 0x19B9CB7B75D; // Bool = true
        public const ulong FFlagFoundationSkeletonCommonShimmerToken = 0x19B9CB7455D; // Bool = false
        public const ulong FFlagFoundationSliderAsSeenOnTV = 0x19B9AF1BD50; // Unknown = 
        public const ulong FFlagFoundationSliderOffloadDraggingMath = 0x19B9AF172D0; // Unknown = 
        public const ulong FFlagFoundationStableContextValues = 0x19B9CB7E49D; // Bool = false
        public const ulong FFlagFoundationStatusIndicatorVariantExperiment2 = 0x19B945A4215; // Bool = false
        public const ulong FFlagFoundationStyleSheetRefCounting = 0x19B9AF1D550; // Unknown = 
        public const ulong FFlagFoundationStylingOnSignUp = 0x19B9ACBE310; // Unknown = 
        public const ulong FFlagFoundationStylingOnSignUp3 = 0x19B9ACBDE50; // Unknown = 
        public const ulong FFlagFoundationThemeName = 0x19B9AF1D090; // Unknown = 
        public const ulong FFlagFoundationToggleBetaUpdate = 0x19B98E916B0; // Unknown = 
        public const ulong FFlagFoundationTokenOverrides2 = 0x19B9AF1AB10; // Unknown = 
        public const ulong FFlagFoundationTooltipBeta = 0x19B9CB75E1D; // Bool = false
        public const ulong FFlagFoundationTooltipPressedOutside = 0x19B9CB7B45D; // Bool = false
        public const ulong FFlagFoundationUnifiedScrimScrolling = 0x19B9CB7D4DD; // Bool = false
        public const ulong FFlagFoundationUsePath2DSpinner = 0x19B9AF1E810; // Unknown = 
        public const ulong FFlagFoundationViewMemoizationChanges = 0x19B9AF11F90; // Unknown = 
        public const ulong FFlagFoundationWidgetManagerSnapshotFlush = 0x19B9CB7AA1D; // Bool = false
        public const ulong FFlagFriendCarouselHas10ftPolicies = 0x19B9026745D; // Bool = false
        public const ulong FFlagFriendRequestModalIxpEnabled = 0x19BA6078150; // Unknown = 
        public const ulong FFlagFriendRequestModalRevampV4 = 0x19BA6077E10; // Unknown = 
        public const ulong FFlagFriendRequestNicknames = 0x19BACFD86D0; // Unknown = 
        public const ulong FFlagFriendRequestNicknamesUIBugFixes = 0x19B90115BDD; // Bool = false
        public const ulong FFlagFriendRequestNicknamesV9 = 0x19BACFD5510; // Unknown = 
        public const ulong FFlagFriendSortedByPresenceSignalsImplementation_v2 = 0x19B85A50695; // Bool = false
        public const ulong FFlagFriendsActivityFeedEnabled = 0x19BA59B3610; // Unknown = 
        public const ulong FFlagFriendsActivityFeedFetchItemNames = 0x19B9F187AED; // Bool = true
        public const ulong FFlagFriendsCarouselProfileFrameEnabled = 0x19BA2EF6795; // Bool = false
        public const ulong FFlagFriendsCarouselUseFindFriendsOnDesktop = 0x19BACFDF490; // Unknown = 
        public const ulong FFlagFriendsCarouselUseFindFriendsOnDesktop_v2 = 0x19BACFDE090; // Unknown = 
        public const ulong FFlagFriendsChatConversationListFadeScrollbar = 0x19BA6B3905D; // Bool = false
        public const ulong FFlagFriendsChatConversationListShowScrollBar = 0x19BACFDA2DD; // Bool = true
        public const ulong FFlagFriendsChatEnableConversationConsent = 0x19BB6BBEEDD; // Bool = true
        public const ulong FFlagFriendsChatEnforceInputCharacterLimit = 0x19BA6B3BF1D; // Bool = false
        public const ulong FFlagFriendsChatFacePileGroupPresence = 0x19BA6B3B190; // Unknown = 
        public const ulong FFlagFriendsChatNavIconSizeFixEnabled = 0x19B859C95D0; // Unknown = 
        public const ulong FFlagFriendsChatOsaSystemMessage = 0x19BACFDB510; // Unknown = 
        public const ulong FFlagFriendsChatPlaceholderRenameFix = 0x19B8C305E1D; // Bool = true
        public const ulong FFlagFriendsChatRefreshListForNewConversation = 0x19BA74A371D; // Bool = false
        public const ulong FFlagFriendsCountDataHydrationMigrationEnabled = 0x19BA59B8550; // Unknown = 
        public const ulong FFlagFriendsEmptyStateIllustrationTheming = 0x19BBF820208; // Unknown = 
        public const ulong FFlagFriendsMenuDummyLoadingFriendsFixV3 = 0x19B8C306390; // Unknown = 
        public const ulong FFlagFriendsMenuUseProfileFrameThumbnail = 0x19BADF9EC5D; // Bool = false
        public const ulong FFlagFriendsPageAlwaysOpenPPV = 0x19BA59BE790; // Unknown = 
        public const ulong FFlagFriendsPageUnifiedOpenProfileLogic = 0x19BA59B441D; // Bool = false
        public const ulong FFlagFriendsPageUserListEnabled = 0x19BA59B5ED0; // Unknown = 
        public const ulong FFlagFriendsPageUserListEnabled_v2 = 0x19BA59BF090; // Unknown = 
        public const ulong FFlagFriendsPageViewBtnEnabled = 0x19B8276616D; // Bool = false
        public const ulong FFlagFriendsPageViewBtnWidth = 0x19B9229DAA0; // Unknown = 
        public const ulong FFlagFriendsSignalMigrationTelemetry = 0x19BACFD8CD0; // Unknown = 
        public const ulong FFlagFriendsSignalMigrationTelemetry_v1 = 0x19BACFD0A90; // Unknown = 
        public const ulong FFlagFriendsStoreSortOnlineFriendsByRank = 0x19BA59BC410; // Unknown = 
        public const ulong FFlagFriendshipNotifsUseSendrEnabledForAll = 0x19BACFEB71D; // Bool = false
        public const ulong FFlagFriendshipNotifsUseSendrExperiment = 0x19B8DD81290; // Unknown = 
        public const ulong FFlagFriendshipNotifsUseSendrExperiment_v2 = 0x19BACFEB95D; // Bool = false
        public const ulong FFlagFriendshipNotifsUseSendrExperiment_v3 = 0x19B8C30B410; // Unknown = 
        public const ulong FFlagFullscreenElementsIgnoreSafeArea = 0x19BBCD72390; // Unknown = 
        public const ulong FFlagFullscreenTitleBarInjectGameServices = 0x19BAEB7585D; // Bool = false
        public const ulong FFlagGameInviteModalAnalyticsEmptyEventContextFix = 0x19D8952FF50; // Unknown = 
        public const ulong FFlagGameInviteModalIncludeLinkIdInShareButton = 0x19D89523950; // Unknown = 
        public const ulong FFlagGameInviteModalUnlockMouse = 0x19B8C304BDD; // Bool = true
        public const ulong FFlagGameInviteOpenModalWithoutBlockingOnCanPrompt = 0x19B8C304ADD; // Bool = true
        public const ulong FFlagGameJoinCardOnBeforeJoinCallback = 0x19BA6796A1D; // Bool = false
        public const ulong FFlagGameJoinTimeoutChatAttemptEnabled = 0x19B8C30BB5D; // Bool = true
        public const ulong FFlagGameSettingsCameraModeFixEnabled = 0x19BC0546490; // Unknown = 
        public const ulong FFlagGameTileMigrateOffLegacyPresence = 0x19B88C40CD0; // Unknown = 
        public const ulong FFlagGamepadIconSupportCheck = 0x19B88C6119D; // Bool = false
        public const ulong FFlagGamepadNavigationDialogABTest = 0x19B9FDDCA15; // Bool = false
        public const ulong FFlagGamepadNavigationDialogABTest2 = 0x19D8168BD90; // Unknown = 
        public const ulong FFlagGateAbuseReportInExpSceneSelectionOnIXP = 0x19BB7F4B310; // Unknown = 
        public const ulong FFlagGateEducationalPopupVisibilityViaGUAC = 0x19B9ACBE950; // Unknown = 
        public const ulong FFlagGateLeaderboardPlayerDropdownViaGUAC = 0x19B9ACB6550; // Unknown = 
        public const ulong FFlagGenerateLinkWithChannel = 0x19B8C30BA90; // Unknown = 
        public const ulong FFlagGenericAbuseReportingGranularExports = 0x19B8C30C9DD; // Bool = true
        public const ulong FFlagGetFFlagCountryCodeBoldPrefixEnabled = 0x19BBC1C8F10; // Unknown = 
        public const ulong FFlagGetFFlagLuaAppChallengeDialogContainerPageEnabled = 0x19B90642D5D; // Bool = false
        public const ulong FFlagGetGameIconsFromThumbnailsDeliveryApiIxp = 0x19B88C2581D; // Bool = false
        public const ulong FFlagGetHumanoidDescription = 0x19BA6A3E2D0; // Unknown = 
        public const ulong FFlagGetHumanoidDescriptionUpdates = 0x19BBB7F2150; // Unknown = 
        public const ulong FFlagGetHumanoidDescriptionUpdatesV2A = 0x19BBBE59ED0; // Unknown = 
        public const ulong FFlagGetHumanoidDescriptionUpdatesV2B = 0x19BAC87FA1D; // Bool = false
        public const ulong FFlagGetHumanoidDescriptionUpdatesV2E2 = 0x19B8C30BD9D; // Bool = true
        public const ulong FFlagGlobalFocusFailureTelemetry = 0x19B8F90889D; // Bool = false
        public const ulong FFlagGlobalTextChatAddPlaySessionField = 0x19BA5150B5D; // Bool = false
        public const ulong FFlagGranularExportsBucket = 0x19B90295690; // Unknown = 
        public const ulong FFlagGridHomeUserInfoUseProfileFrameThumbnail = 0x19B948111D0; // Unknown = 
        public const ulong FFlagGuacAppPolicyDisableSignupCheckbox = 0x19BB6BB2FD0; // Unknown = 
        public const ulong FFlagGuacCanRenderTransferOnProfile = 0x19B8C2E2FD0; // Unknown = 
        public const ulong FFlagGuacDisableBlackbirdEntrypoints = 0x19BB6BB4FDD; // Bool = true
        public const ulong FFlagGuacStickyShortcutBarEnabled = 0x19BBCD75DD0; // Unknown = 
        public const ulong FFlagGuardVoiceInExpUpsellVariant = 0x19B9F18F905; // Bool = true
        public const ulong FFlagHeadRefinementFacialAnimationToggle = 0x19BA3A5BE1D; // Bool = false
        public const ulong FFlagHeadRefinementFacialAnimationToggle4 = 0x19BA3A54C9D; // Bool = false
        public const ulong FFlagHelpPageIXPExposure = 0x19BBF254E5D; // Bool = true
        public const ulong FFlagHelpPageIXPExposure3 = 0x19BAC87331D; // Bool = false
        public const ulong FFlagHelpPageMountVR = 0x19BBF25C85D; // Bool = true
        public const ulong FFlagHelpPageMountVR3 = 0x19BAC8731DD; // Bool = false
        public const ulong FFlagHiddenFriendsSortHeaderAddSubTabDependency = 0x19BA461AC90; // Unknown = 
        public const ulong FFlagHiddenFriendsSortHeaderRemoveFlyoutDependency = 0x19B9ACB4390; // Unknown = 
        public const ulong FFlagHideConnectPageWebViewItemsForVRV2 = 0x19BC0541090; // Unknown = 
        public const ulong FFlagHideContextualButtonBasedOnStateForVR = 0x19BC0544950; // Unknown = 
        public const ulong FFlagHideDevSubsPriceIfSubscribed = 0x19B9ACB36D0; // Unknown = 
        public const ulong FFlagHideLaunchAtStartupMac = 0x19BA59BB8D0; // Unknown = 
        public const ulong FFlagHideLookDiscountPercentWithIneligibleItems = 0x19D85DC2DDD; // Bool = false
        public const ulong FFlagHideNotificationIconForVR = 0x19B8FA15690; // Unknown = 
        public const ulong FFlagHidePeoplePageInviteFriends = 0x19B9ACBDC1D; // Bool = false
        public const ulong FFlagHidePremiumIconography = 0x19BA6A3CB10; // Unknown = 
        public const ulong FFlagHideShortcutsOnReportDropdown = 0x19B9FD8F815; // Bool = false
        public const ulong FFlagHideShortcutsWhileIemDropdownActive = 0x19BA7FC1F28; // Unknown = 
        public const ulong FFlagHideVoiceChatSelectorForFae_AEGIS2 = 0x19B9FD8B6DD; // Bool = false
        public const ulong FFlagHighlightModePreciseSelectionEnabled3 = 0x19B8C30D45D; // Bool = true
        public const ulong FFlagHomePYMKUseProfileFrameThumbnail = 0x19BA005E6AD; // Bool = false
        public const ulong FFlagHomePagePromptsHandlerEnabled = 0x19BC0541310; // Unknown = 
        public const ulong FFlagHomePhoneVerificationUpsellNewCopy = 0x19D8244A670; // Unknown = 
        public const ulong FFlagHomepagePromptsPaddingFix = 0x19BC0545090; // Unknown = 
        public const ulong FFlagIAPExperienceEnableBestValueBadge = 0x19BAC83009D; // Bool = false
        public const ulong FFlagIAPExperienceEnableMultiDisplayUpsellV3 = 0x19BAC830A5D; // Bool = false
        public const ulong FFlagIAPExperienceUseUpsellBadgeHelper = 0x19BAC830DDD; // Bool = false
        public const ulong FFlagIBEnableCollectiblesSystemSupport = 0x19B9F0A111D; // Bool = false
        public const ulong FFlagIBGateUGC4ACollectibleAssetsBundles1 = 0x19B9F0A4590; // Unknown = 
        public const ulong FFlagIDVGuardStartPollingAfterUnmount = 0x19B8FC3A1DD; // Bool = false
        public const ulong FFlagIEMFocusNavPeoplePageToButtons = 0x19B9ACB27DD; // Bool = false
        public const ulong FFlagIEMFocusNavSupportNewButtons2 = 0x19BAC8737D0; // Unknown = 
        public const ulong FFlagIEMReportScrollingFix = 0x19BB7F45CD0; // Unknown = 
        public const ulong FFlagIEMSettingsGroups = 0x19B9FD867D5; // Bool = false
        public const ulong FFlagIEMSettingsGroups709 = 0x19B9FD86810; // Unknown = 
        public const ulong FFlagIEMSettingsLogExposureIXPFlags = 0x19BACE9B350; // Unknown = 
        public const ulong FFlagIEMSettingsPageDisplaying = 0x19B8C30D990; // Unknown = 
        public const ulong FFlagIEMTabFocusNav = 0x19B9ACB5F1D; // Bool = false
        public const ulong FFlagIEMTabFocusNav2 = 0x19B9ACB9ADD; // Bool = false
        public const ulong FFlagIGMAlwaysResetGfxLv5 = 0x19B9FD8CC1D; // Bool = false
        public const ulong FFlagIGMChangeCapturesToGallery = 0x19B998BD22D; // Bool = false
        public const ulong FFlagIGMChangeGalleryHeaderIcon = 0x19B9FDDAE95; // Bool = false
        public const ulong FFlagIGMEnableGFXReset = 0x19B9FD8D050; // Unknown = 
        public const ulong FFlagIGMGamepadSelectionHistory = 0x19D81687F9D; // Bool = false
        public const ulong FFlagIGMResetGfxLv5Only = 0x19B9FD8CBDD; // Bool = false
        public const ulong FFlagIGMResetGfxQuality = 0x19B9FD8CB1D; // Bool = false
        public const ulong FFlagIGMRevertGfxLv5Only = 0x19B9FD8CB9D; // Bool = false
        public const ulong FFlagIGMRevertGfxQuality = 0x19B9FD8CB5D; // Bool = false
        public const ulong FFlagIGMSelectionGroup = 0x19BACE9DF9D; // Bool = false
        public const ulong FFlagIXPServiceWrapperWaitRefactor = 0x19BBCD76310; // Unknown = 
        public const ulong FFlagIconHostSetZIndexToDefault = 0x19B82BC9FDD; // Bool = false
        public const ulong FFlagImmutableJoinDictionariesUseTableClone = 0x19B8C2E5290; // Unknown = 
        public const ulong FFlagImportVirtualCursorToUA = 0x19BA59BE450; // Unknown = 
        public const ulong FFlagImproveIllegalContentReportingLinkLook = 0x19BA3A54610; // Unknown = 
        public const ulong FFlagImprovePageTitleCloseButton = 0x19BACE9DEDD; // Bool = false
        public const ulong FFlagImproveSearchSelectionUX2 = 0x19B9029F350; // Unknown = 
        public const ulong FFlagInAppBugReporterIxpBypass = 0x19B90293D50; // Unknown = 
        public const ulong FFlagInAppBugReporterIxpEnabled = 0x19B90293CD0; // Unknown = 
        public const ulong FFlagInExperienceAddPhoneViewNewCopy = 0x19B8C30A410; // Unknown = 
        public const ulong FFlagInExperienceAvatarSwitcherPlaceFilter = 0x19B88C4F8D0; // Unknown = 
        public const ulong FFlagInExperienceContainerAppLinking = 0x19B8C30C090; // Unknown = 
        public const ulong FFlagInExperienceContainerRespectUserTheme = 0x19B8C30D19D; // Bool = true
        public const ulong FFlagInExperienceContainerScreenSizeReducer = 0x19B8C30C750; // Unknown = 
        public const ulong FFlagInExperienceInterventionApp = 0x19BACFEAF9D; // Bool = false
        public const ulong FFlagInExperiencePhoneUpsellNewCopy = 0x19B8C30AF1D; // Bool = true
        public const ulong FFlagInExperienceReportClosingBugfix = 0x19B9ACB4150; // Unknown = 
        public const ulong FFlagInExperienceRequestProfileSettings = 0x19BA7FC4138; // Unknown = 
        public const ulong FFlagInExperienceShopFtuxTooltip = 0x19BABC10AD5; // Bool = true
        public const ulong FFlagInExperienceUseAppStyleProvider = 0x19B9ACB33DD; // Bool = false
        public const ulong FFlagInExperienceUserProfileSettingsEnabled = 0x19BA7FC7428; // Unknown = 
        public const ulong FFlagInExperienceUserProfileSettingsEnabled_v3 = 0x19BACFE6E1D; // Bool = false
        public const ulong FFlagInGameLargerRobuxUpsellEnabled = 0x19D85DCB59D; // Bool = false
        public const ulong FFlagInGameLargerRobuxUpsellIXP = 0x19D85DCF51D; // Bool = false
        public const ulong FFlagInGameLargerRobuxUpsellIXPRolledOut = 0x19D85DCA7DD; // Bool = false
        public const ulong FFlagIncludeWaitingForPartyInCondition = 0x19BA679509D; // Bool = false
        public const ulong FFlagIncreaseLegacyPeopleRowButtonSize = 0x19BA4E9DE9D; // Bool = false
        public const ulong FFlagIncreaseLoadingScreenOrder = 0x19B9AF14AD0; // Unknown = 
        public const ulong FFlagIncreaseMarketplaceContentHeight = 0x19B9AF14850; // Unknown = 
        public const ulong FFlagIncreaseUtilityRowTextSizeConsole = 0x19BA515A510; // Unknown = 
        public const ulong FFlagInitializeAutocompleteOnlyIfEnabled = 0x19D81FAB820; // Unknown = 
        public const ulong FFlagInjectAnalyticsService = 0x19B90293DD0; // Unknown = 
        public const ulong FFlagInlineRichTextUseWebViewService = 0x19B9AF191D0; // Unknown = 
        public const ulong FFlagInlineSurveyBranching = 0x19B8C30C3DD; // Bool = true
        public const ulong FFlagInlineSurveyChoiceTextEntry = 0x19B8C30C49D; // Bool = true
        public const ulong FFlagInlineSurveyEnhancements = 0x19BBB317F10; // Unknown = 
        public const ulong FFlagInlineSurveyEnhancements2 = 0x19B8C30C21D; // Bool = true
        public const ulong FFlagInlineSurveyFocusRoot = 0x19BB7F4869D; // Bool = false
        public const ulong FFlagInlineSurveyOnInExpReport = 0x19BB7F41C50; // Unknown = 
        public const ulong FFlagInlineSurveyPartialResponse = 0x19D812EE588; // Unknown = 
        public const ulong FFlagInspectAndBuyFixStyleLink = 0x19D81681150; // Unknown = 
        public const ulong FFlagIntegrateDiscountsWithEDP = 0x19B9AF1C750; // Unknown = 
        public const ulong FFlagIntegrateDiscountsWithEDP2 = 0x19B9AF1C290; // Unknown = 
        public const ulong FFlagIntegratePhoneUpsellJoinVoice = 0x19B8C30ADDD; // Bool = true
        public const ulong FFlagIntegrateTraversalHistoryInSideSheet2 = 0x19B9ACBE4DD; // Bool = false
        public const ulong FFlagIntegrationsChromeShortcutTelemetry = 0x19BA7FC0DF8; // Unknown = 
        public const ulong FFlagInternationalNamesEnabledForAll = 0x19B90642690; // Unknown = 
        public const ulong FFlagIntroduceMetricsLegacyUpsell = 0x19BAC832C1D; // Bool = false
        public const ulong FFlagInviteListRerank = 0x19B99718290; // Unknown = 
        public const ulong FFlagIsPublishOnBuildRevert = 0x19BAD28FA5D; // Bool = false
        public const ulong FFlagIsSquadCoordinationExperienceJoinExperimentExposureEnabled = 0x19B8FDEDA50; // Unknown = 
        public const ulong FFlagIsSquadLobbySessionEnabled = 0x19B8FDEDA90; // Unknown = 
        public const ulong FFlagIssueTrackerUseFoundationIcon = 0x19BBC1CCF10; // Unknown = 
        public const ulong FFlagItemImpressionsAddGameMetadata = 0x19B88C2E410; // Unknown = 
        public const ulong FFlagJoinCardAgeCheckUpsell_V3 = 0x19B8C3022D0; // Unknown = 
        public const ulong FFlagJoinGameCardPassThroughUniversePlaceInfoFromFriendsCarousel = 0x19BACFD0390; // Unknown = 
        public const ulong FFlagJoinGameCardViewProfileNavigateToProfilePlatform = 0x19B85A50685; // Bool = false
        public const ulong FFlagJoinWithoutMicPermissions3 = 0x19BACFD6C90; // Unknown = 
        public const ulong FFlagKISAUserAgreementsRedesign = 0x19B945A0D50; // Unknown = 
        public const ulong FFlagKeepDarkThemeOverrideWhenLoggedOut = 0x19B9AF16090; // Unknown = 
        public const ulong FFlagKeepSideSheetOpenFromGrid = 0x19BA4E9AA1D; // Bool = false
        public const ulong FFlagLazyInitiateExperienceLanguageSwitcher = 0x19B9FD8DDDD; // Bool = false
        public const ulong FFlagLazyPerfStatsInit = 0x19BACE7AB1D; // Bool = false
        public const ulong FFlagLeaderstatsWithASideOfClient = 0x19BAD281B5D; // Bool = false
        public const ulong FFlagLeaveActionChromeShortcutTelemetry = 0x19B9FDD1855; // Bool = false
        public const ulong FFlagLeaveChromeShortcutTelemetry = 0x19B9FDD18D5; // Bool = false
        public const ulong FFlagLeaveSquadIfChatDisabled = 0x19BA802C050; // Unknown = 
        public const ulong FFlagLocalUserGameVoteCounterReducer = 0x19B90269750; // Unknown = 
        public const ulong FFlagLocalizeGameplayPaused = 0x19B9F0A715D; // Bool = false
        public const ulong FFlagLocalizeMenuNavigationToggleDialog = 0x19B9FDDCA95; // Bool = false
        public const ulong FFlagLogAllGuacRead = 0x19BAF803CFD; // Bool = false
        public const ulong FFlagLogFirstGuacRead = 0x19BAF8029BD; // Bool = false
        public const ulong FFlagLogInputTypeChangedTvRemote1 = 0x19BBCCC90FD; // Bool = false
        public const ulong FFlagLogKeyboardFocusModeEntered = 0x19B9064E69D; // Bool = false
        public const ulong FFlagLogSessionOnOrientationChange = 0x19BA609BCD0; // Unknown = 
        public const ulong FFlagLoggingGamepadOpenExpControlsMenu = 0x19BAD28025D; // Bool = false
        public const ulong FFlagLoggingRethrowUsingError = 0x19B8C2EA01D; // Bool = false
        public const ulong FFlagLoginV2FullFlowDevOverride = 0x19B9AF19C10; // Unknown = 
        public const ulong FFlagLogoutPhoneVerificationUpsellCopy = 0x19B8DD82210; // Unknown = 
        public const ulong FFlagLogoutPhoneVerificationUpsellCopy_v3 = 0x19B8C309790; // Unknown = 
        public const ulong FFlagLowCogsBannerExperiment = 0x19B88C4EF5D; // Bool = false
        public const ulong FFlagLowCogsBannerInfoIcon = 0x19BAC83249D; // Bool = false
        public const ulong FFlagLuaAppAbuseReportAnalyticsHasLaunchData = 0x19B9F29649D; // Bool = false
        public const ulong FFlagLuaAppAccountSecurityPromptEnabled = 0x19B90648290; // Unknown = 
        public const ulong FFlagLuaAppAccountSecurityPromptRolloutEnabledForAll = 0x19B9029EFD0; // Unknown = 
        public const ulong FFlagLuaAppAddAnalyticsDataToSeeAllImpressions = 0x19B88C4DDD0; // Unknown = 
        public const ulong FFlagLuaAppAddCarouselAmpUpsellAccessResponses = 0x19B902697DD; // Bool = false
        public const ulong FFlagLuaAppAddComponentTypeToSearchImpressions2 = 0x19BC05491DD; // Bool = true
        public const ulong FFlagLuaAppAddIgrsImages = 0x19B88C2161D; // Bool = false
        public const ulong FFlagLuaAppAddPlaceholderRecoveryCounter = 0x19B90269B9D; // Bool = false
        public const ulong FFlagLuaAppAddRequestIdToRfySignalApportioning = 0x19B88C43E1D; // Bool = false
        public const ulong FFlagLuaAppAddSeeAllFlagToGameDetailReferral = 0x19B88C4F4DD; // Bool = false
        public const ulong FFlagLuaAppAddSessionIdToUserSignals = 0x19B88C26450; // Unknown = 
        public const ulong FFlagLuaAppAddSocialLinkClickTelemetryToEdp = 0x19B88C2661D; // Bool = false
        public const ulong FFlagLuaAppAddSocialLinkImpressionsTelemetryToEdp = 0x19BA6F6003D; // Bool = false
        public const ulong FFlagLuaAppAddSortDataToSocialCarouselClicks = 0x19B88C2B71D; // Bool = false
        public const ulong FFlagLuaAppAddTestIdsForArrow = 0x19B88C24DD0; // Unknown = 
        public const ulong FFlagLuaAppAddUniverseIdToGameDetailsEvents = 0x19B88C43410; // Unknown = 
        public const ulong FFlagLuaAppAddVideoIneligiblePlayabilityStatus = 0x19B88C2135D; // Bool = false
        public const ulong FFlagLuaAppAdjustOverflowMenuVisual = 0x19B88C2C81D; // Bool = false
        public const ulong FFlagLuaAppAlignHeroUnitBottomRowCtaButton = 0x19BAC82A3DD; // Bool = false
        public const ulong FFlagLuaAppApportioningInCollectionViews = 0x19BAFB67B10; // Unknown = 
        public const ulong FFlagLuaAppApportioningInCollectionViews2 = 0x19B857857DD; // Bool = false
        public const ulong FFlagLuaAppAttachChallengeInterceptor = 0x19B9029309D; // Bool = false
        public const ulong FFlagLuaAppAutocompleteIXPConfig4 = 0x19B90294FD0; // Unknown = 
        public const ulong FFlagLuaAppAvoidPushUpsellConflicts = 0x19B90295210; // Unknown = 
        public const ulong FFlagLuaAppBadgeDetailsEnabled6 = 0x19B88C2221D; // Bool = false
        public const ulong FFlagLuaAppBadgeDetailsLogExposure = 0x19B88C222DD; // Bool = false
        public const ulong FFlagLuaAppBadgesSeeAllEnabled4 = 0x19B88C218D0; // Unknown = 
        public const ulong FFlagLuaAppBadgesSeeAllLogExposure = 0x19B88C21490; // Unknown = 
        public const ulong FFlagLuaAppBlockedUnplayableError = 0x19B88C2B15D; // Bool = false
        public const ulong FFlagLuaAppBottomAlignDetailsHeaderInfoFrame = 0x19BA6093A90; // Unknown = 
        public const ulong FFlagLuaAppBroadenVideoAnalytics = 0x19BC0540710; // Unknown = 
        public const ulong FFlagLuaAppChallengeCaptchaV2ForceWebViewVisible = 0x19B90292510; // Unknown = 
        public const ulong FFlagLuaAppChallengeDialogEventReceiverEnabled = 0x19B90642BDD; // Bool = false
        public const ulong FFlagLuaAppChallengeDialogFetchDialogConditionally = 0x19B90640C90; // Unknown = 
        public const ulong FFlagLuaAppChallengeDisableForceWebViewVisible = 0x19B90292B50; // Unknown = 
        public const ulong FFlagLuaAppChallengeTurnstileForceWebViewVisible = 0x19B90292250; // Unknown = 
        public const ulong FFlagLuaAppChartsActiveFilterChips = 0x19BC05485DD; // Bool = true
        public const ulong FFlagLuaAppChartsActiveFilterChips3 = 0x19BC0542B1D; // Bool = true
        public const ulong FFlagLuaAppChartsAppPage = 0x19B88C2865D; // Bool = false
        public const ulong FFlagLuaAppChartsAppUseHoverTile = 0x19B825F97DD; // Bool = true
        public const ulong FFlagLuaAppChartsFilterOptionTextTag = 0x19BC0540250; // Unknown = 
        public const ulong FFlagLuaAppChartsFilterOptionTextTag2 = 0x19BC0543450; // Unknown = 
        public const ulong FFlagLuaAppChartsPreloadingEnabled = 0x19B9026AF9D; // Bool = false
        public const ulong FFlagLuaAppChartsResetFetchingStatusOnFilterChange = 0x19BC054485D; // Bool = false
        public const ulong FFlagLuaAppChartsResetFetchingStatusOnFilterChange2 = 0x19BC0547490; // Unknown = 
        public const ulong FFlagLuaAppCheckboxFeedbackFormTitleTextWrapping = 0x19BA6094110; // Unknown = 
        public const ulong FFlagLuaAppClampBannerPaddingToViewport = 0x19B88C21FDD; // Bool = false
        public const ulong FFlagLuaAppCompositionAlways4 = 0x19BA55389D0; // Unknown = 
        public const ulong FFlagLuaAppCompositionAppChat = 0x19B9AF1A4D0; // Unknown = 
        public const ulong FFlagLuaAppCompositionAvatar = 0x19B9AF1A550; // Unknown = 
        public const ulong FFlagLuaAppCompositionCharts = 0x19B9AF1A510; // Unknown = 
        public const ulong FFlagLuaAppCompositionFixDetailClip = 0x19BA609A650; // Unknown = 
        public const ulong FFlagLuaAppCompositionFixEmphasisApportioning = 0x19B90269AD0; // Unknown = 
        public const ulong FFlagLuaAppCompositionHome = 0x19B9AF1AA90; // Unknown = 
        public const ulong FFlagLuaAppCompositionHomeHeaderFullBleed = 0x19B9AF1AC10; // Unknown = 
        public const ulong FFlagLuaAppCompositionLegacyLayout = 0x19B9AF1A350; // Unknown = 
        public const ulong FFlagLuaAppCompositionPlayerGrid = 0x19B9AF1A010; // Unknown = 
        public const ulong FFlagLuaAppCompositionSearch = 0x19B9AF1A050; // Unknown = 
        public const ulong FFlagLuaAppCompositionTopBarFullBleed = 0x19B9AF1A690; // Unknown = 
        public const ulong FFlagLuaAppContinueSortInstantPlay = 0x19BBB59A19D; // Bool = false
        public const ulong FFlagLuaAppContinueSortInstantPlay_DEV = 0x19B88C2D610; // Unknown = 
        public const ulong FFlagLuaAppCreatorSuccessVirtualEventsLayerUseRoactExperiment = 0x19B9EE08AD0; // Unknown = 
        public const ulong FFlagLuaAppCreatorSuccessVirtualEventsLayerUseRoactExperiment2 = 0x19BA6072110; // Unknown = 
        public const ulong FFlagLuaAppCredentialSheetEventStream = 0x19BBC1C695D; // Bool = false
        public const ulong FFlagLuaAppCustomizableEntryPoint = 0x19BA6A31895; // Bool = false
        public const ulong FFlagLuaAppDataCacheBatch = 0x19BA5BD67D0; // Unknown = 
        public const ulong FFlagLuaAppDataHydrationConnectionsPlayedStore = 0x19B85789D50; // Unknown = 
        public const ulong FFlagLuaAppDataHydrationDataResolverOnClear = 0x19B8578991D; // Bool = false
        public const ulong FFlagLuaAppDataHydrationOptimisticMutationLayer = 0x19B85789690; // Unknown = 
        public const ulong FFlagLuaAppDataHydrationPlayerCountGameInfoStore = 0x19B85789F1D; // Bool = false
        public const ulong FFlagLuaAppDataHydrationSanitizeItem = 0x19B85789D9D; // Bool = false
        public const ulong FFlagLuaAppDataHydrationUpdateItem = 0x19B85789C5D; // Bool = false
        public const ulong FFlagLuaAppDataHydrationVotesStoreTrackOptimisticVotes = 0x19B857897DD; // Bool = false
        public const ulong FFlagLuaAppDefaultHttpRetry = 0x19B8578B99D; // Bool = false
        public const ulong FFlagLuaAppDefaultInitialItemsPerRowForSearch = 0x19B90269F1D; // Bool = false
        public const ulong FFlagLuaAppDeferLaunch = 0x19B902921D0; // Unknown = 
        public const ulong FFlagLuaAppDemoModePlayButton = 0x19B88C2FBDD; // Bool = false
        public const ulong FFlagLuaAppDemoModePlayButtonTelemetry2 = 0x19B88C2FD1D; // Bool = false
        public const ulong FFlagLuaAppDerivedStackAndSwitchState = 0x19B8578B71D; // Bool = false
        public const ulong FFlagLuaAppDesignFoundationsBridge = 0x19B8578C050; // Unknown = 
        public const ulong FFlagLuaAppDesktopFriendCarouselClicks = 0x19B88C2A75D; // Bool = false
        public const ulong FFlagLuaAppDesktopMediaGalleryTelemetry = 0x19B88C2A290; // Unknown = 
        public const ulong FFlagLuaAppDevStoreSeeAllForceRefreshOnNavigate = 0x19BA5207FBD; // Bool = true
        public const ulong FFlagLuaAppDevStoreSeeAllSduiEnabled = 0x19BA520247D; // Bool = true
        public const ulong FFlagLuaAppDevStoreSeeAllSduiLogExposure = 0x19BC0543FD0; // Unknown = 
        public const ulong FFlagLuaAppDisableChevronSeeAll = 0x19B88C2A8DD; // Bool = false
        public const ulong FFlagLuaAppDisableDataModelStreamingInStudio = 0x19B90295E50; // Unknown = 
        public const ulong FFlagLuaAppDisablePlayableWhenLoadingForce = 0x19B88C2A350; // Unknown = 
        public const ulong FFlagLuaAppDisableStickyBarMediaGallery = 0x19BA6094690; // Unknown = 
        public const ulong FFlagLuaAppDiscoveryClientAppStorageEmptyCacheTelemetry = 0x19BA3A7E590; // Unknown = 
        public const ulong FFlagLuaAppDismissUnlockUpsell = 0x19BC054D59D; // Bool = true
        public const ulong FFlagLuaAppEdpBackendV2AddUserVote = 0x19B88C41F10; // Unknown = 
        public const ulong FFlagLuaAppEdpBackendV2HydrateLegacyDefault = 0x19BBB598FD0; // Unknown = 
        public const ulong FFlagLuaAppEdpBackendV2HydrateLegacyDefault9 = 0x19B88C425DD; // Bool = false
        public const ulong FFlagLuaAppEdpBackendV2HydrateLegacyIxp = 0x19BBB59AED0; // Unknown = 
        public const ulong FFlagLuaAppEdpBackendV2HydrateLegacyIxp9 = 0x19B88C4281D; // Bool = false
        public const ulong FFlagLuaAppEdpBackendV2LogFetchSuccessAndFailure2 = 0x19B88C42750; // Unknown = 
        public const ulong FFlagLuaAppEdpBackendV2LogUniverseIdForEvents = 0x19B88C422D0; // Unknown = 
        public const ulong FFlagLuaAppEdpBackendV2SduiInterleaveDefault = 0x19BBB595210; // Unknown = 
        public const ulong FFlagLuaAppEdpBackendV2SduiInterleaveDefault3 = 0x19B88C42A5D; // Bool = false
        public const ulong FFlagLuaAppEdpBackendV2SduiInterleaveIxp = 0x19BBB594610; // Unknown = 
        public const ulong FFlagLuaAppEdpBackendV2SduiInterleaveIxp3 = 0x19B88C42C9D; // Bool = false
        public const ulong FFlagLuaAppEdpBottomSheetPeekViewEvents2 = 0x19BA52031F5; // Bool = false
        public const ulong FFlagLuaAppEdpConsoleMediaGalleryVideo = 0x19B88C2ABD0; // Unknown = 
        public const ulong FFlagLuaAppEdpConsoleMediaGalleryVideoMute = 0x19BBB59569D; // Bool = false
        public const ulong FFlagLuaAppEdpConsoleMediaGalleryVideoPlayIcon = 0x19BBB595495; // Bool = false
        public const ulong FFlagLuaAppEdpFaeIxpEnabled = 0x19B9029B790; // Unknown = 
        public const ulong FFlagLuaAppEdpFetchLatencyTracking = 0x19B88C43210; // Unknown = 
        public const ulong FFlagLuaAppEdpFixDefaultBanner = 0x19B88C2B25D; // Bool = false
        public const ulong FFlagLuaAppEdpHideSystemBarOnPeekViewMount = 0x19B88C24990; // Unknown = 
        public const ulong FFlagLuaAppEdpKeepCachedDetailsOnRefetch = 0x19B88C24E90; // Unknown = 
        public const ulong FFlagLuaAppEdpKeepFullPageOnPortraitRotation = 0x19B88C2525D; // Bool = true
        public const ulong FFlagLuaAppEdpMediaGalleryAutoAdvance = 0x19BBB59869D; // Bool = false
        public const ulong FFlagLuaAppEdpMediaGalleryAutoAdvance5 = 0x19B88C2D69D; // Bool = false
        public const ulong FFlagLuaAppEdpMediaGalleryFullScreen = 0x19BBB59925D; // Bool = false
        public const ulong FFlagLuaAppEdpMediaGalleryFullScreen4 = 0x19B88C2DB1D; // Bool = false
        public const ulong FFlagLuaAppEdpMediaGalleryHeightJitterFix = 0x19B88C2549D; // Bool = false
        public const ulong FFlagLuaAppEdpMediaGalleryPreloadImage = 0x19B88C2D8DD; // Bool = false
        public const ulong FFlagLuaAppEdpMediaGalleryRedesign = 0x19BBB595B5D; // Bool = false
        public const ulong FFlagLuaAppEdpMediaGalleryRedesign5 = 0x19B88C2B55D; // Bool = false
        public const ulong FFlagLuaAppEdpMediaGalleryRedesignIxp = 0x19BBB59515D; // Bool = false
        public const ulong FFlagLuaAppEdpMediaGalleryRedesignIxp5 = 0x19B88C2B39D; // Bool = false
        public const ulong FFlagLuaAppEdpMediaGalleryRedesignTelemetry = 0x19B88C2DD5D; // Bool = false
        public const ulong FFlagLuaAppEdpMediaGalleryVideoPreview = 0x19BBB59D79D; // Bool = false
        public const ulong FFlagLuaAppEdpMediaGalleryVideoPreview5 = 0x19B88C2B690; // Unknown = 
        public const ulong FFlagLuaAppEdpMediaGalleryVideoPreviewIxp = 0x19BBB594B5D; // Bool = false
        public const ulong FFlagLuaAppEdpMediaGalleryVideoPreviewIxp5 = 0x19B88C2BAD0; // Unknown = 
        public const ulong FFlagLuaAppEdpNonSduiBuildAttribution = 0x19B88C4239D; // Bool = false
        public const ulong FFlagLuaAppEdpPeekViewReserveBottomDockHeight = 0x19B88C24190; // Unknown = 
        public const ulong FFlagLuaAppEdpShowBuildTag = 0x19B8C30F11D; // Bool = true
        public const ulong FFlagLuaAppEdpUseHidePlayWithRewardVisibilityVariable = 0x19D82441370; // Unknown = 
        public const ulong FFlagLuaAppEdpVideoAvailableRamDeny = 0x19BBC38EC10; // Unknown = 
        public const ulong FFlagLuaAppEdpVideoDeviceDeny = 0x19BBC380B10; // Unknown = 
        public const ulong FFlagLuaAppEdpVideoManufacturerDeny2 = 0x19BBC38DFD0; // Unknown = 
        public const ulong FFlagLuaAppEdpVideoMaxMemoryDeny = 0x19BBC381B50; // Unknown = 
        public const ulong FFlagLuaAppEmail2SVUpsellPopUpEnabled = 0x19B857818DD; // Bool = false
        public const ulong FFlagLuaAppEmphasisGameTileVideo = 0x19B88C2C1D0; // Unknown = 
        public const ulong FFlagLuaAppEnable10ftSignUpView = 0x19B945A5750; // Unknown = 
        public const ulong FFlagLuaAppEnableAndroidPushUpsell = 0x19B8C304E1D; // Bool = true
        public const ulong FFlagLuaAppEnableBacktraceSessionInfo = 0x19B9F184A8D; // Bool = true
        public const ulong FFlagLuaAppEnableChartsPageProfileLink = 0x19B9F18DE2D; // Bool = true
        public const ulong FFlagLuaAppEnableChatMilestones = 0x19B8578C11D; // Bool = false
        public const ulong FFlagLuaAppEnableCommunityLinksRedirect = 0x19B9026AADD; // Bool = false
        public const ulong FFlagLuaAppEnableCompactDataModelPayload = 0x19B90295B90; // Unknown = 
        public const ulong FFlagLuaAppEnableConsolidatedGameRefundPolicy = 0x19B88C413D0; // Unknown = 
        public const ulong FFlagLuaAppEnableContainedRewardUi = 0x19B9064009D; // Bool = false
        public const ulong FFlagLuaAppEnableContentfulPaintTracking = 0x19B8578C49D; // Bool = false
        public const ulong FFlagLuaAppEnableCredentialsProtocol = 0x19B8FC396DD; // Bool = false
        public const ulong FFlagLuaAppEnableCustomAnalyticsEvent = 0x19B9064191D; // Bool = false
        public const ulong FFlagLuaAppEnableDataModelStreamForConsoles = 0x19B90295D90; // Unknown = 
        public const ulong FFlagLuaAppEnableDesktopDualLoginABTest = 0x19BC0546B50; // Unknown = 
        public const ulong FFlagLuaAppEnableEnhancedVideoExperienceAssetAndTimeline = 0x19B9F9207DD; // Bool = false
        public const ulong FFlagLuaAppEnableEnhancedVideoExperienceGroupIdCheck = 0x19B9F920B5D; // Bool = false
        public const ulong FFlagLuaAppEnableFeatureTileAdPlayer = 0x19BA5202D95; // Bool = false
        public const ulong FFlagLuaAppEnableGameGridTable2 = 0x19B90264E1D; // Bool = false
        public const ulong FFlagLuaAppEnableHeroUnitV2 = 0x19B88C41CD0; // Unknown = 
        public const ulong FFlagLuaAppEnableHomepageOneByTwoTile = 0x19BAC82D3D0; // Unknown = 
        public const ulong FFlagLuaAppEnableInExperienceDataModelStreamStarter = 0x19B9AF12D10; // Unknown = 
        public const ulong FFlagLuaAppEnableLogoHeaderByDefault = 0x19B94810D90; // Unknown = 
        public const ulong FFlagLuaAppEnableLumberyakLogBound = 0x19B8F90B1DD; // Bool = false
        public const ulong FFlagLuaAppEnableMilestoneDeduplication = 0x19B85789110; // Unknown = 
        public const ulong FFlagLuaAppEnableMorePageProfileLink = 0x19B88C2979D; // Bool = false
        public const ulong FFlagLuaAppEnableNativePurchaseFinishedV2Signals = 0x19B9AF1D210; // Unknown = 
        public const ulong FFlagLuaAppEnableNativeRobuxProducts = 0x19B90269310; // Unknown = 
        public const ulong FFlagLuaAppEnableNxMApportioningExtraLogging = 0x19BAC82C350; // Unknown = 
        public const ulong FFlagLuaAppEnableNxMRoduxApportioning = 0x19B8578559D; // Bool = false
        public const ulong FFlagLuaAppEnableOpenTypeIGMFix = 0x19B9ACBEA50; // Unknown = 
        public const ulong FFlagLuaAppEnableOpenTypeSignUpPageFix = 0x19B9ACBDD10; // Unknown = 
        public const ulong FFlagLuaAppEnableOpenTypeSupport4 = 0x19BACFD6010; // Unknown = 
        public const ulong FFlagLuaAppEnablePageLoadTracker = 0x19B8578BEDD; // Bool = false
        public const ulong FFlagLuaAppEnablePlayButtonThrottle = 0x19B88C2CFD0; // Unknown = 
        public const ulong FFlagLuaAppEnablePlaySquadButton = 0x19BBB591390; // Unknown = 
        public const ulong FFlagLuaAppEnablePlaySquadButton3 = 0x19B88C2AC1D; // Bool = false
        public const ulong FFlagLuaAppEnablePlayableStateWhenLoading = 0x19B88C2AE5D; // Bool = false
        public const ulong FFlagLuaAppEnablePushUpsellOnFirstTime = 0x19B8C304F90; // Unknown = 
        public const ulong FFlagLuaAppEnableRecommendedCarouselForDesktop = 0x19BB6BB5050; // Unknown = 
        public const ulong FFlagLuaAppEnableRelativeGuiHomeForAll = 0x19BBB317D50; // Unknown = 
        public const ulong FFlagLuaAppEnableRelativeGuiHomeForAll2 = 0x19BB1D96810; // Unknown = 
        public const ulong FFlagLuaAppEnableRelativeGuiHomeWithIxp = 0x19BBB3119D0; // Unknown = 
        public const ulong FFlagLuaAppEnableRelativeGuiHomeWithIxp2 = 0x19B88C27690; // Unknown = 
        public const ulong FFlagLuaAppEnableReportBadge = 0x19BA59B2690; // Unknown = 
        public const ulong FFlagLuaAppEnableSduiHomePageDev = 0x19B9F18D2F5; // Bool = true
        public const ulong FFlagLuaAppEnableSearchStreamingEndpoint = 0x19B9AF14A90; // Unknown = 
        public const ulong FFlagLuaAppEnableSinglePageSignUp = 0x19B9026A7D0; // Unknown = 
        public const ulong FFlagLuaAppEnableSlpForVr = 0x19B9481089D; // Bool = false
        public const ulong FFlagLuaAppEnableSponsoredReportAd = 0x19BAC820E10; // Unknown = 
        public const ulong FFlagLuaAppEnableSponsoredReportAd3 = 0x19BAC820D90; // Unknown = 
        public const ulong FFlagLuaAppEnableSquadPage4 = 0x19B8C2E3F10; // Unknown = 
        public const ulong FFlagLuaAppEnableStickyShortcutBar = 0x19B88C4FB1D; // Bool = false
        public const ulong FFlagLuaAppEnableStratusStreamingCheck = 0x19B88C4129D; // Bool = false
        public const ulong FFlagLuaAppEnableStratusStreamingTestOnly = 0x19B88C40410; // Unknown = 
        public const ulong FFlagLuaAppEnableToastNotificationsCoreScripts4 = 0x19B9AF11590; // Unknown = 
        public const ulong FFlagLuaAppEnableTokenBucketLimiter = 0x19B8F907610; // Unknown = 
        public const ulong FFlagLuaAppEnableTopBanner3 = 0x19B8C2E4810; // Unknown = 
        public const ulong FFlagLuaAppEnableVRCarouselScrolling = 0x19B88C4479D; // Bool = false
        public const ulong FFlagLuaAppEnableVirtualEventPlaceId = 0x19B8578A39D; // Bool = false
        public const ulong FFlagLuaAppEnableWaitForPropWrapperAssert = 0x19BBE91CC50; // Unknown = 
        public const ulong FFlagLuaAppEnableWebViewStateTrackerInDataModelStreaming = 0x19B90295D10; // Unknown = 
        public const ulong FFlagLuaAppEnableWebViewTelemetry = 0x19BC05447D0; // Unknown = 
        public const ulong FFlagLuaAppEnableWindowsHandheldScale = 0x19B8CA85FFD; // Bool = true
        public const ulong FFlagLuaAppEnableWindowsHandheldTokenScale = 0x19BA3A7D410; // Unknown = 
        public const ulong FFlagLuaAppEnhancedVideoAdLabelPropUpdate = 0x19B9F92021D; // Bool = false
        public const ulong FFlagLuaAppErrorOnBadSortGroup = 0x19B90266F5D; // Bool = false
        public const ulong FFlagLuaAppErrorReportCountryCode = 0x19B8F90A250; // Unknown = 
        public const ulong FFlagLuaAppEventDetailsPageDisableCtaOnUnplayable = 0x19B88C2E1D0; // Unknown = 
        public const ulong FFlagLuaAppExpandableTextAdjustClipToContent = 0x19BA609985D; // Bool = false
        public const ulong FFlagLuaAppExpandableTextImpressionsEnabled = 0x19B88C269DD; // Bool = false
        public const ulong FFlagLuaAppExpandableTextNewLineStrip = 0x19BA609CED0; // Unknown = 
        public const ulong FFlagLuaAppExperienceDetailsLayoutOrderConfig = 0x19BBB59BFD0; // Unknown = 
        public const ulong FFlagLuaAppExperienceDetailsLayoutOrderConfig2 = 0x19B88C42B90; // Unknown = 
        public const ulong FFlagLuaAppExperienceJoinIdempotencyKey = 0x19D8952A8D0; // Unknown = 
        public const ulong FFlagLuaAppExtendPlayWithRewardPeekView = 0x19BBB599490; // Unknown = 
        public const ulong FFlagLuaAppExtraInviteModalStringValidation = 0x19B9F294C90; // Unknown = 
        public const ulong FFlagLuaAppFetchContentMaturityWithPlayability = 0x19BA672F35D; // Bool = false
        public const ulong FFlagLuaAppFetchPlayabilityKillSwitch1 = 0x19BA67925DD; // Bool = true
        public const ulong FFlagLuaAppFix10ftGlobalNavAppHeaderBarSelection = 0x19B859CB450; // Unknown = 
        public const ulong FFlagLuaAppFixActiveGameLoadingCheck = 0x19BA3A70150; // Unknown = 
        public const ulong FFlagLuaAppFixAppExperienceActionRowLoadingState = 0x19BBC380750; // Unknown = 
        public const ulong FFlagLuaAppFixAppNavHeaderIconsAlignment = 0x19B9ACB9850; // Unknown = 
        public const ulong FFlagLuaAppFixApportioningTileTailConflict = 0x19BA679D1D0; // Unknown = 
        public const ulong FFlagLuaAppFixAutocompleteEntryDups = 0x19B9026ADDD; // Bool = false
        public const ulong FFlagLuaAppFixCarouselCanvasOverflow = 0x19B88C2151D; // Bool = false
        public const ulong FFlagLuaAppFixCarouselPeekInControl = 0x19B9AF17D10; // Unknown = 
        public const ulong FFlagLuaAppFixCentralOverlayDeviceSafe = 0x19B9064975D; // Bool = false
        public const ulong FFlagLuaAppFixChartsRenderOnFail = 0x19B88C439DD; // Bool = false
        public const ulong FFlagLuaAppFixCollectionGridWindowAbsoluteCanvasSize = 0x19BA679C1D0; // Unknown = 
        public const ulong FFlagLuaAppFixCollectionSizeBindingsZero = 0x19BA6795A10; // Unknown = 
        public const ulong FFlagLuaAppFixCommunityLinksRedirect = 0x19B9026AC9D; // Bool = false
        public const ulong FFlagLuaAppFixCompositionSizeOverrideGap = 0x19B9AF17E90; // Unknown = 
        public const ulong FFlagLuaAppFixComputedSideMarginResponsiveBreakpoint = 0x19BA6796F90; // Unknown = 
        public const ulong FFlagLuaAppFixConsoleSeeAllGridContainment = 0x19B902600D0; // Unknown = 
        public const ulong FFlagLuaAppFixCursorHooks = 0x19B88C4AA50; // Unknown = 
        public const ulong FFlagLuaAppFixDetailsPageThumbnailRenderInPhone = 0x19B88C29390; // Unknown = 
        public const ulong FFlagLuaAppFixEdpRecommendedCarouselHoverZIndex = 0x19BB1D9B6D0; // Unknown = 
        public const ulong FFlagLuaAppFixEventNotFoundErrorStateExit = 0x19BA60723DD; // Bool = true
        public const ulong FFlagLuaAppFixExplicitFeedbackConsoleTelemetry = 0x19B88C2629D; // Bool = false
        public const ulong FFlagLuaAppFixExplicitFeedbackTelemetry = 0x19B88C25990; // Unknown = 
        public const ulong FFlagLuaAppFixFrameBoundsImpressions = 0x19B8F90E950; // Unknown = 
        public const ulong FFlagLuaAppFixGameGridTableNilRelativeHeight = 0x19B90264C9D; // Bool = false
        public const ulong FFlagLuaAppFixGamesListSortTokenExpiringTime = 0x19B88C432DD; // Bool = false
        public const ulong FFlagLuaAppFixHiddenTileVideoCleanup = 0x19B88C2D4DD; // Bool = false
        public const ulong FFlagLuaAppFixHomeGridPlaceholderFlowIssues = 0x19B88C43D90; // Unknown = 
        public const ulong FFlagLuaAppFixImpressionsHookDependencies = 0x19B8F90EE10; // Unknown = 
        public const ulong FFlagLuaAppFixInlineSignalsReactPattern = 0x19B88C4381D; // Bool = false
        public const ulong FFlagLuaAppFixLaunchGameSourceParam = 0x19B88C2D450; // Unknown = 
        public const ulong FFlagLuaAppFixNotificationBadgeCountsSync = 0x19B88C2279D; // Bool = false
        public const ulong FFlagLuaAppFixPassesPageStoreFetch = 0x19B88C225DD; // Bool = false
        public const ulong FFlagLuaAppFixPlayButtonDefaultLaunchSource = 0x19BA679BD5D; // Bool = false
        public const ulong FFlagLuaAppFixRecommendedImpressionsInterface = 0x19BBE91D750; // Unknown = 
        public const ulong FFlagLuaAppFixRsvpPromptDescriptionScrolling = 0x19BA6073A9D; // Bool = true
        public const ulong FFlagLuaAppFixSDPLayout = 0x19B9ACB7850; // Unknown = 
        public const ulong FFlagLuaAppFixSduiHeroUnitTitle = 0x19B82B178DD; // Bool = false
        public const ulong FFlagLuaAppFixSearchImpressions = 0x19B88C4319D; // Bool = false
        public const ulong FFlagLuaAppFixSelectionCursor = 0x19B88C4ADDD; // Bool = false
        public const ulong FFlagLuaAppFixSmallScreenFooterStatsOverlap = 0x19B88C41810; // Unknown = 
        public const ulong FFlagLuaAppFixStudioNotchSupport3 = 0x19B906462DD; // Bool = false
        public const ulong FFlagLuaAppFixToastNotificationClosePosition = 0x19B827A5C5D; // Bool = false
        public const ulong FFlagLuaAppFixTotalColsBound = 0x19BC0547A1D; // Bool = true
        public const ulong FFlagLuaAppFixUnifiedPlayButtonStickyActionBar = 0x19BA609A210; // Unknown = 
        public const ulong FFlagLuaAppFixWebViewUnderlyingBackButton = 0x19B94810C1D; // Bool = false
        public const ulong FFlagLuaAppForceLowResMural = 0x19B902699DD; // Bool = false
        public const ulong FFlagLuaAppForceVrAppPanelWidthRollout = 0x19B88C40F50; // Unknown = 
        public const ulong FFlagLuaAppForumsDeeplinkFix = 0x19BA59B6C50; // Unknown = 
        public const ulong FFlagLuaAppFriendCarouselImpressionsTimestamp = 0x19BB1D90D1D; // Bool = false
        public const ulong FFlagLuaAppFriendsSortHeaderByPosition = 0x19BB1D9B850; // Unknown = 
        public const ulong FFlagLuaAppGameCarouselUseAutoSizing = 0x19B90294490; // Unknown = 
        public const ulong FFlagLuaAppGameDetailEventMobileAdsId = 0x19B88C4F29D; // Bool = false
        public const ulong FFlagLuaAppGameDetailsAttributionFix = 0x19BBB59E290; // Unknown = 
        public const ulong FFlagLuaAppGameEventsTelemetryServiceShadowTraffic = 0x19B88C24790; // Unknown = 
        public const ulong FFlagLuaAppGameImpressionsAddUnifiedFields = 0x19B88C4E010; // Unknown = 
        public const ulong FFlagLuaAppGameImpressionsMobileAdsId = 0x19B88C4E210; // Unknown = 
        public const ulong FFlagLuaAppGamePassesDataHydrationMigrationEnabled = 0x19BB2AEB045; // Bool = false
        public const ulong FFlagLuaAppGamePlayIntentEventMobileAdsId = 0x19B88C4F71D; // Bool = false
        public const ulong FFlagLuaAppGameStatsFallbackRendering = 0x19B88C4495D; // Bool = false
        public const ulong FFlagLuaAppGameTileExtractGameDetailsCallback = 0x19B88C2DA50; // Unknown = 
        public const ulong FFlagLuaAppGameTileInteractionFeedback = 0x19BB1D92790; // Unknown = 
        public const ulong FFlagLuaAppGameTileNotInterestedDirectAction = 0x19B88C2C9DD; // Bool = false
        public const ulong FFlagLuaAppGameTileOverflowMenuSelectionCloseFix = 0x19BBE9137D0; // Unknown = 
        public const ulong FFlagLuaAppGameTileSelectionVideoPlayback = 0x19B88C2CE5D; // Bool = false
        public const ulong FFlagLuaAppGameTileVideoAvailableRamDeny = 0x19BBE912050; // Unknown = 
        public const ulong FFlagLuaAppGameTileVideoDeviceDeny = 0x19BBE912E10; // Unknown = 
        public const ulong FFlagLuaAppGameTileVideoManufacturerDeny = 0x19BBE912310; // Unknown = 
        public const ulong FFlagLuaAppGameTileVideoMaxMemoryDeny = 0x19BBE9125D0; // Unknown = 
        public const ulong FFlagLuaAppGameViewTileBackgroundColorOverride = 0x19B88C4065D; // Bool = false
        public const ulong FFlagLuaAppGateVideoPlaybackOnNavigationFocus = 0x19B88C2CC1D; // Bool = false
        public const ulong FFlagLuaAppGenreRatingFooter = 0x19B88C40C90; // Unknown = 
        public const ulong FFlagLuaAppHapticTriggeredTelemetry = 0x19B88C25C90; // Unknown = 
        public const ulong FFlagLuaAppHeadShapeInventory = 0x19B85788D5D; // Bool = false
        public const ulong FFlagLuaAppHeaderButtonText = 0x19BB1D9189D; // Bool = false
        public const ulong FFlagLuaAppHideEdpStoreForUnplayable = 0x19B88C2A950; // Unknown = 
        public const ulong FFlagLuaAppHideEmptyCarouselHeader = 0x19B9AF15D50; // Unknown = 
        public const ulong FFlagLuaAppHomeFirstTileThumbnailLoadedMilestone = 0x19B8578B610; // Unknown = 
        public const ulong FFlagLuaAppHomeGameCarouselRemount = 0x19B88C4351D; // Bool = false
        public const ulong FFlagLuaAppHomeJoinYourFriendsPresenceFix = 0x19B90290310; // Unknown = 
        public const ulong FFlagLuaAppHomePageFirstImageLoadObserver2 = 0x19BA553E4D0; // Unknown = 
        public const ulong FFlagLuaAppHomePageLoadTracker = 0x19BA553AE90; // Unknown = 
        public const ulong FFlagLuaAppHomePageReadyToRender = 0x19BA553DD90; // Unknown = 
        public const ulong FFlagLuaAppHomePageSharedEffects = 0x19B9481285D; // Bool = false
        public const ulong FFlagLuaAppHomeReduceRenders = 0x19B88C2C190; // Unknown = 
        public const ulong FFlagLuaAppHomeThumbnailPrefetch = 0x19B8578B450; // Unknown = 
        public const ulong FFlagLuaAppHomeUseFeedVideoPlaybackContext = 0x19B94811390; // Unknown = 
        public const ulong FFlagLuaAppHomeVngAppUpsell = 0x19B88C4BEDD; // Bool = false
        public const ulong FFlagLuaAppHttpSupportNoContent = 0x19BA3A73B10; // Unknown = 
        public const ulong FFlagLuaAppIECVREnabled8 = 0x19BA3BB0A90; // Unknown = 
        public const ulong FFlagLuaAppIECVRIxpEnabled8 = 0x19BA3BB8890; // Unknown = 
        public const ulong FFlagLuaAppIaHomeSubTab = 0x19B9ACBEAD0; // Unknown = 
        public const ulong FFlagLuaAppIconPlayButton = 0x19B88C2F91D; // Bool = false
        public const ulong FFlagLuaAppIconTextPlayButton = 0x19B88C2F490; // Unknown = 
        public const ulong FFlagLuaAppIedpFixPlayButton = 0x19B88C446DD; // Bool = false
        public const ulong FFlagLuaAppIedpOverlayAndNavigationFix = 0x19B88C443DD; // Bool = false
        public const ulong FFlagLuaAppIedpSendPoints = 0x19B88C445DD; // Bool = false
        public const ulong FFlagLuaAppIedpSwitchChipToBadge = 0x19B9FD85B9D; // Bool = false
        public const ulong FFlagLuaAppImproveAccountSwitcherPeekView = 0x19B948109DD; // Bool = false
        public const ulong FFlagLuaAppImproveComponentTrackingTiming = 0x19B8578B650; // Unknown = 
        public const ulong FFlagLuaAppInExperienceDetailsPrompt3 = 0x19B88C4419D; // Bool = false
        public const ulong FFlagLuaAppIncorrectWebViewProperty = 0x19B90642E1D; // Bool = false
        public const ulong FFlagLuaAppInfoTableResponsiveProviderOverride = 0x19BA609851D; // Bool = true
        public const ulong FFlagLuaAppInfoTableWorkaroundGridJank2 = 0x19BA6098590; // Unknown = 
        public const ulong FFlagLuaAppInitializeToastNotificationEventParams2 = 0x19BA607EF50; // Unknown = 
        public const ulong FFlagLuaAppInlineRequireAppConfigurer = 0x19B859C9D10; // Unknown = 
        public const ulong FFlagLuaAppIsClickoutEnabledUniverse = 0x19B9F92101D; // Bool = false
        public const ulong FFlagLuaAppIsEnhancedVideoUniverse = 0x19B9F920A50; // Unknown = 
        public const ulong FFlagLuaAppItemEventsTelemetryServiceShadowTraffic = 0x19B88C24310; // Unknown = 
        public const ulong FFlagLuaAppJoinTextPlayableButton = 0x19B88C2F81D; // Bool = false
        public const ulong FFlagLuaAppKeepTileBadgesDuringVideo = 0x19BBE913950; // Unknown = 
        public const ulong FFlagLuaAppLCPTimingFix = 0x19BA59B5A10; // Unknown = 
        public const ulong FFlagLuaAppLaunchTrackThunks = 0x19BC27AD7C0; // Unknown = 
        public const ulong FFlagLuaAppLaunchWhenLoadingEdp = 0x19B88C2AFDD; // Bool = false
        public const ulong FFlagLuaAppLaunchWhenLoadingForce = 0x19B88C2AD90; // Unknown = 
        public const ulong FFlagLuaAppLayoutParamsInContext2 = 0x19BA5538F10; // Unknown = 
        public const ulong FFlagLuaAppLazyComponentAsyncChunkLoad = 0x19BA461981D; // Bool = false
        public const ulong FFlagLuaAppLimitEventThumbnailToOne = 0x19BA6070A1D; // Bool = true
        public const ulong FFlagLuaAppLogChartsAppPageExposure = 0x19B88C23BDD; // Bool = false
        public const ulong FFlagLuaAppLogExposurePlayButtonUX = 0x19B88C2F210; // Unknown = 
        public const ulong FFlagLuaAppLogGameAttributionError = 0x19BBB59B090; // Unknown = 
        public const ulong FFlagLuaAppLogGameAttributionError2 = 0x19B88C4365D; // Bool = false
        public const ulong FFlagLuaAppLogMorePageLayerExposure = 0x19B82A141DD; // Bool = false
        public const ulong FFlagLuaAppLogOmniRecommendationsMetadata2 = 0x19B88C2175D; // Bool = false
        public const ulong FFlagLuaAppLogSearchTopPageExposure = 0x19B88C23D1D; // Bool = false
        public const ulong FFlagLuaAppLoosenCollectionIdTypeInterface = 0x19B88C2AA1D; // Bool = false
        public const ulong FFlagLuaAppLuaBuyRobuxPage = 0x19B9064431D; // Bool = false
        public const ulong FFlagLuaAppMakeDisclaimerOptInForFeedbackForm = 0x19B88C25750; // Unknown = 
        public const ulong FFlagLuaAppMediaGalleryGamepadSupportsPagingIcons = 0x19B906416DD; // Bool = false
        public const ulong FFlagLuaAppMediaGalleryNilImageIdFix = 0x19B9AF13B10; // Unknown = 
        public const ulong FFlagLuaAppMigrateGameEventsTelemetryService = 0x19B88C24F1D; // Bool = true
        public const ulong FFlagLuaAppMigrateGameTileActiveFriendsFix = 0x19B88C40D9D; // Bool = false
        public const ulong FFlagLuaAppMigrateGameTileActiveFriendsHydrationFix2 = 0x19B88C40F9D; // Bool = false
        public const ulong FFlagLuaAppMigrateGameTileFixConsoleMetadataText = 0x19B88C421DD; // Bool = false
        public const ulong FFlagLuaAppMigrateGameTileFooterValueFixes = 0x19B88C40290; // Unknown = 
        public const ulong FFlagLuaAppMigrateGameTileHoverFixes = 0x19B88C4049D; // Bool = false
        public const ulong FFlagLuaAppMigrateItemEventsTelemetryService = 0x19B88C24BD0; // Unknown = 
        public const ulong FFlagLuaAppMobileEdpPlayButtonPartialUnificationIXP = 0x19B88C2F6DD; // Bool = false
        public const ulong FFlagLuaAppMorePageLayerExposure = 0x19B82B1D35D; // Bool = false
        public const ulong FFlagLuaAppMoveProfileIntoTopBar = 0x19B9F185A8D; // Bool = true
        public const ulong FFlagLuaAppMoveProfileIntoTopBarIXP = 0x19BAFB61E50; // Unknown = 
        public const ulong FFlagLuaAppMoveSocialLinksImpressions = 0x19B84E6CF9D; // Bool = false
        public const ulong FFlagLuaAppMutedSetNetworkingErrorToast = 0x19B8F90EA1D; // Bool = false
        public const ulong FFlagLuaAppNarrowTileHidePlayerCount2 = 0x19B88C41490; // Unknown = 
        public const ulong FFlagLuaAppNarrowTileHideRating2 = 0x19B88C40250; // Unknown = 
        public const ulong FFlagLuaAppNarrowTileSmallerFooterFont2 = 0x19B88C41410; // Unknown = 
        public const ulong FFlagLuaAppNewSlpEndpointIxpEnabled = 0x19B8558AE9D; // Bool = true
        public const ulong FFlagLuaAppNilApportionedItems = 0x19B9011F5DD; // Bool = false
        public const ulong FFlagLuaAppNormalizeUnifiedPasskeyResponse = 0x19B8FC38210; // Unknown = 
        public const ulong FFlagLuaAppNotInterestedFeedbackFormTelemetry = 0x19B88C24B50; // Unknown = 
        public const ulong FFlagLuaAppNotInterestedReportPlaceId = 0x19B88C257D0; // Unknown = 
        public const ulong FFlagLuaAppNullableGridLayoutTelemetryFields = 0x19BBE91F990; // Unknown = 
        public const ulong FFlagLuaAppPYMKSendUserSeenCollection = 0x19B88C2B95D; // Bool = false
        public const ulong FFlagLuaAppPageLoadTrackerJoinExperienceFix = 0x19B8578C75D; // Bool = false
        public const ulong FFlagLuaAppParentApprovedExperiences = 0x19B88C2A59D; // Bool = false
        public const ulong FFlagLuaAppParentUpsellPolicy = 0x19B88C29190; // Unknown = 
        public const ulong FFlagLuaAppPersistentMusicPlayerDev = 0x19B9ACB8B90; // Unknown = 
        public const ulong FFlagLuaAppPlatformRestrictionVPC = 0x19B9AF15550; // Unknown = 
        public const ulong FFlagLuaAppPlayButtonAmpAgeCheckFlow = 0x19B88C29D50; // Unknown = 
        public const ulong FFlagLuaAppPlayButtonLaunchOnReleaseAfterUnmountEdp = 0x19B88C2A990; // Unknown = 
        public const ulong FFlagLuaAppPlayButtonLaunchOnReleaseAfterUnmountForce = 0x19B88C2A6D0; // Unknown = 
        public const ulong FFlagLuaAppPlayButtonLoadingDurationTelemetry = 0x19B88C2D850; // Unknown = 
        public const ulong FFlagLuaAppPlayButtonLoadingPrimary = 0x19BBB318A10; // Unknown = 
        public const ulong FFlagLuaAppPlayButtonLoadingPrimary2 = 0x19B88C274DD; // Bool = false
        public const ulong FFlagLuaAppPlayButtonLoadingSkeleton3 = 0x19B88C2FA5D; // Bool = false
        public const ulong FFlagLuaAppPlayButtonOptOutFoundationButton = 0x19B88C2FED0; // Unknown = 
        public const ulong FFlagLuaAppPlayButtonViewRefactor = 0x19B8578759D; // Bool = false
        public const ulong FFlagLuaAppPlayButtonWizardCloseDelay = 0x19B88C2E4DD; // Bool = false
        public const ulong FFlagLuaAppPlayLoadingClickTelemetryMobile = 0x19B88C2DE90; // Unknown = 
        public const ulong FFlagLuaAppPlayWithRewardSkipIxpForShimmer = 0x19B9064085D; // Bool = false
        public const ulong FFlagLuaAppPlayWithRewardUsePlatformSpecificLayerValueForShimmer = 0x19B906409DD; // Bool = false
        public const ulong FFlagLuaAppPlayableUxTreatment = 0x19B88C41A90; // Unknown = 
        public const ulong FFlagLuaAppProcessGameSocialLinks = 0x19B88C42990; // Unknown = 
        public const ulong FFlagLuaAppPromotionalEmailsCheckboxEnabledInAppPolicy = 0x19BB6BB2C5D; // Bool = true
        public const ulong FFlagLuaAppPromptsHomepageConfigName = 0x19B902947D0; // Unknown = 
        public const ulong FFlagLuaAppPropagateFriendsCarouselHeader = 0x19BB1D90150; // Unknown = 
        public const ulong FFlagLuaAppPushSystemUpsellDevOverride = 0x19B8C304C50; // Unknown = 
        public const ulong FFlagLuaAppPushUpsellDeprecateOldEvents = 0x19B8C304310; // Unknown = 
        public const ulong FFlagLuaAppReduceGameIconFetches = 0x19B88C40A90; // Unknown = 
        public const ulong FFlagLuaAppRefactorSelectRouteDev = 0x19BA6A334D0; // Unknown = 
        public const ulong FFlagLuaAppRemoveNumericalSortIndexSearch = 0x19BA672A6D0; // Unknown = 
        public const ulong FFlagLuaAppRemoveOmniFeedDividersAndExtraPadding = 0x19BC054219D; // Bool = true
        public const ulong FFlagLuaAppRemovePlayWithRewardBetaAllowlist = 0x19BBAE319F0; // Unknown = 
        public const ulong FFlagLuaAppRemovePlayWithRewardBetaAllowlist2 = 0x19B88C42C10; // Unknown = 
        public const ulong FFlagLuaAppRenameFriendsToConnectionsEdp = 0x19BBB59AC50; // Unknown = 
        public const ulong FFlagLuaAppResetHoverOnSduiPlayButtonActivation = 0x19B88C21D9D; // Bool = false
        public const ulong FFlagLuaAppRespectClipAncestorImpressions = 0x19B88C23A50; // Unknown = 
        public const ulong FFlagLuaAppResponsiveEnginePreferredInput = 0x19B88C27310; // Unknown = 
        public const ulong FFlagLuaAppResponsiveFixHookDeps = 0x19B859C72D0; // Unknown = 
        public const ulong FFlagLuaAppRfyRevealRows2 = 0x19B88C21290; // Unknown = 
        public const ulong FFlagLuaAppRfyRevealRowsFocusFix = 0x19B88C21310; // Unknown = 
        public const ulong FFlagLuaAppRfySignalApportioning4 = 0x19B88C43C5D; // Bool = false
        public const ulong FFlagLuaAppRfySignalApportioningIxp4 = 0x19BA5535A10; // Unknown = 
        public const ulong FFlagLuaAppScaleDetailWidth = 0x19BA6095A90; // Unknown = 
        public const ulong FFlagLuaAppScaleDiscoveryWidth = 0x19BA609DE50; // Unknown = 
        public const ulong FFlagLuaAppScrollDetectorLifecycleHardening = 0x19B88C4089D; // Bool = false
        public const ulong FFlagLuaAppScrollTelemetryIntegration = 0x19BA6A30BD0; // Unknown = 
        public const ulong FFlagLuaAppSduiAttributionRow5 = 0x19B88C25610; // Unknown = 
        public const ulong FFlagLuaAppSduiColorPropMigration = 0x19B88C26190; // Unknown = 
        public const ulong FFlagLuaAppSduiEdpEnabled2 = 0x19B88C2251D; // Bool = false
        public const ulong FFlagLuaAppSduiEdpFallbackAttributionFromCache2 = 0x19B88C22BD0; // Unknown = 
        public const ulong FFlagLuaAppSduiEdpFallbackPlayButtonPassUiBlox = 0x19B88C2DCD0; // Unknown = 
        public const ulong FFlagLuaAppSduiEdpFallbackPlayButtonUseUiBlox = 0x19B88C2ED90; // Unknown = 
        public const ulong FFlagLuaAppSduiEdpHideSystemBarOnPeekViewMount = 0x19BA55359D0; // Unknown = 
        public const ulong FFlagLuaAppSduiEdpLogExposure = 0x19B88C2291D; // Bool = false
        public const ulong FFlagLuaAppSduiEdpLogExposureLayoutEffect = 0x19B88C22A5D; // Bool = false
        public const ulong FFlagLuaAppSduiEdpPassPageTimerThroughNav = 0x19B88C22C9D; // Bool = false
        public const ulong FFlagLuaAppSduiEdpRouteAwareSessionRemoval = 0x19B88C22EDD; // Bool = false
        public const ulong FFlagLuaAppSduiErrorPage = 0x19B8FC32A9D; // Bool = false
        public const ulong FFlagLuaAppSduiEventDetailsActionBarInFeed = 0x19B88C238DD; // Bool = false
        public const ulong FFlagLuaAppSduiEventDetailsCenterSheet2 = 0x19B88C2345D; // Bool = false
        public const ulong FFlagLuaAppSduiEventDetailsEnabled = 0x19B88C21F50; // Unknown = 
        public const ulong FFlagLuaAppSduiEventDetailsLoadingSlot = 0x19B88C2369D; // Bool = false
        public const ulong FFlagLuaAppSduiEventDetailsLogExposure = 0x19B88C2321D; // Bool = false
        public const ulong FFlagLuaAppSduiGameSortDropDown2 = 0x19BC054959D; // Bool = false
        public const ulong FFlagLuaAppSduiGameTileHoverShadow = 0x19B88C28F9D; // Bool = false
        public const ulong FFlagLuaAppSduiGameTilePlayButtonDefaults = 0x19B9F18FF15; // Bool = true
        public const ulong FFlagLuaAppSduiLandingPageEnabled = 0x19B88C229D0; // Unknown = 
        public const ulong FFlagLuaAppSduiOpenSearchResultsWithQueryAction = 0x19B88C243D0; // Unknown = 
        public const ulong FFlagLuaAppSduiPageEntryPointSnackbar2 = 0x19BA553D390; // Unknown = 
        public const ulong FFlagLuaAppSduiPageEntryScrollAway = 0x19B88C2003D; // Bool = false
        public const ulong FFlagLuaAppSduiPlaceholderSupport2 = 0x19B88C27C50; // Unknown = 
        public const ulong FFlagLuaAppSduiQuerySuggestionClickedTelemetry = 0x19B88C29510; // Unknown = 
        public const ulong FFlagLuaAppSduiRemoveAbuseReportActionFromLegacyRegistry = 0x19B88C26FD0; // Unknown = 
        public const ulong FFlagLuaAppSduiSeeAllArrowIconMigration2 = 0x19B9029B390; // Unknown = 
        public const ulong FFlagLuaAppSduiSeeAllLayoutParamsFix = 0x19B88C43B1D; // Bool = false
        public const ulong FFlagLuaAppSduiStickyHeaderScrollAway = 0x19B88C2021D; // Bool = false
        public const ulong FFlagLuaAppSduiStreamingChunkedResponses = 0x19B9AF14C90; // Unknown = 
        public const ulong FFlagLuaAppSduiStreamingFirstDataTiming = 0x19B9AF14090; // Unknown = 
        public const ulong FFlagLuaAppSduiUpdateUserSettingsAction = 0x19B88C41F9D; // Bool = false
        public const ulong FFlagLuaAppSduiVerificationUpsellActions2 = 0x19BC054991D; // Bool = true
        public const ulong FFlagLuaAppSduiVerticalFeedThresholdRefresh = 0x19B906412DD; // Bool = false
        public const ulong FFlagLuaAppSduiVideoThumbnail = 0x19BBB315010; // Unknown = 
        public const ulong FFlagLuaAppSduiVideoThumbnailDev = 0x19B88C2715D; // Bool = false
        public const ulong FFlagLuaAppSearchListFramesSelectable = 0x19B9029C5D0; // Unknown = 
        public const ulong FFlagLuaAppSearchPeopleUnifiedSchemaFields = 0x19B88C2BF1D; // Bool = false
        public const ulong FFlagLuaAppSearchPlaceholderGrid = 0x19B88C43790; // Unknown = 
        public const ulong FFlagLuaAppSearchResultsPageGameTileVideo = 0x19BBB59D0DD; // Bool = false
        public const ulong FFlagLuaAppSearchResultsPageGameTileVideo2 = 0x19B88C2C3D0; // Unknown = 
        public const ulong FFlagLuaAppSearchStandardizeAssetCategorization = 0x19BA520F71D; // Bool = true
        public const ulong FFlagLuaAppSendTTIEventsPerDM = 0x19BA3AD2610; // Unknown = 
        public const ulong FFlagLuaAppSentryAddAppPolicyMetadata2 = 0x19B8F90A210; // Unknown = 
        public const ulong FFlagLuaAppSentryReporterIncludeInTags = 0x19B8F90B51D; // Bool = false
        public const ulong FFlagLuaAppShareEdpVideoBlockingConfig = 0x19BA5530F50; // Unknown = 
        public const ulong FFlagLuaAppSharedHomePageInteractive = 0x19BAFB689F0; // Unknown = 
        public const ulong FFlagLuaAppShouldTrackTopThunks = 0x19B8C316910; // Unknown = 
        public const ulong FFlagLuaAppSignupPasskeyAvailabilityPreflight2 = 0x19B945A4550; // Unknown = 
        public const ulong FFlagLuaAppSortDeeplinkFix = 0x19BA59B1210; // Unknown = 
        public const ulong FFlagLuaAppSortHeaderAnchorTag = 0x19B88C214D0; // Unknown = 
        public const ulong FFlagLuaAppSponsoredAdVideoViewabilityEnabled = 0x19BAC823AD0; // Unknown = 
        public const ulong FFlagLuaAppSponsoredAdViewabilityEnabled = 0x19BAC826B5D; // Bool = false
        public const ulong FFlagLuaAppStratusBugReportAfterConnect = 0x19B88C4155D; // Bool = false
        public const ulong FFlagLuaAppSupportDeviceSafeInsets = 0x19B9ACBE810; // Unknown = 
        public const ulong FFlagLuaAppSupportDisablePlayableWhenLoading = 0x19B8578651D; // Bool = false
        public const ulong FFlagLuaAppSupportHomeBackToTop = 0x19B88C4345D; // Bool = false
        public const ulong FFlagLuaAppSupportNonSduiTypeForServerTriggeredModals = 0x19BA6F6A295; // Bool = false
        public const ulong FFlagLuaAppTextFeedbackFormModal = 0x19B88C253D0; // Unknown = 
        public const ulong FFlagLuaAppTextFeedbackFormModalStandardInput = 0x19BA60903D0; // Unknown = 
        public const ulong FFlagLuaAppTextOnlyPlayButton = 0x19B88C2F410; // Unknown = 
        public const ulong FFlagLuaAppThrottleInviteSendEndpoint = 0x19B9F296A9D; // Bool = false
        public const ulong FFlagLuaAppThrottleViewportBoundsScreenSize = 0x19B8F90E250; // Unknown = 
        public const ulong FFlagLuaAppTileVideoCandidateOnly = 0x19B88C2C950; // Unknown = 
        public const ulong FFlagLuaAppTileVideoKeepPlayingOnScroll = 0x19B88C2C5D0; // Unknown = 
        public const ulong FFlagLuaAppToastV2PerMessageDuration = 0x19B88C25E10; // Unknown = 
        public const ulong FFlagLuaAppUnifiedLoggingDialogContentType = 0x19B8F9DF7D0; // Unknown = 
        public const ulong FFlagLuaAppUnifiedPlayButtonSquadMenuDirection = 0x19B88C4009D; // Bool = false
        public const ulong FFlagLuaAppUnifyPlayButtonAllSurfacesIxp = 0x19BBB597E9D; // Bool = false
        public const ulong FFlagLuaAppUnifyPlayButtonAllSurfacesIxp5 = 0x19B88C2F0DD; // Bool = false
        public const ulong FFlagLuaAppUnifyPlayButtonMobileEdp = 0x19BBB59F210; // Unknown = 
        public const ulong FFlagLuaAppUnifyPlayButtonMobileEdp3 = 0x19B88C2F31D; // Bool = false
        public const ulong FFlagLuaAppUnifyPlayButtonNonMobileEdp = 0x19BBB59F990; // Unknown = 
        public const ulong FFlagLuaAppUnifyPlayButtonNonMobileEdp3 = 0x19B88C2F4DD; // Bool = false
        public const ulong FFlagLuaAppUnifyPlayButtonTile = 0x19BBB59EA5D; // Bool = false
        public const ulong FFlagLuaAppUnifyPlayButtonTile4 = 0x19B88C2F25D; // Bool = false
        public const ulong FFlagLuaAppUnifyPlayButtonTileIxp = 0x19BBB59799D; // Bool = false
        public const ulong FFlagLuaAppUnifyPlayButtonTileIxp2 = 0x19B88C2EAD0; // Unknown = 
        public const ulong FFlagLuaAppUnlockUpsellSupport = 0x19B857853DD; // Bool = false
        public const ulong FFlagLuaAppUpdateContentDescriptorsTranslation = 0x19B88C42350; // Unknown = 
        public const ulong FFlagLuaAppUpdateFailedStateEdpIcon = 0x19B88C2565D; // Bool = false
        public const ulong FFlagLuaAppUpdateGameSortGridRowHeight10ft2 = 0x19B90262610; // Unknown = 
        public const ulong FFlagLuaAppUpdatePlayButtonText = 0x19B88C2D090; // Unknown = 
        public const ulong FFlagLuaAppUpdateRevealMoreButtonUi = 0x19B90269D5D; // Bool = false
        public const ulong FFlagLuaAppUseAppHttpStore = 0x19B85788CDD; // Bool = false
        public const ulong FFlagLuaAppUseAppHttpStoreInExperience = 0x19BA8A04110; // Unknown = 
        public const ulong FFlagLuaAppUseDeviceSafeInsetsForAppContainer3 = 0x19B9ACB0F50; // Unknown = 
        public const ulong FFlagLuaAppUseDisplayStoreForCollectionLayoutParams = 0x19BA679BFD0; // Unknown = 
        public const ulong FFlagLuaAppUseEffectInSignalPreprocessing = 0x19B88C2199D; // Bool = false
        public const ulong FFlagLuaAppUseExperienceLogoTrayInGameInfoList = 0x19B88C41D5D; // Bool = false
        public const ulong FFlagLuaAppUseFoundationCheckbox = 0x19B8E6109FD; // Bool = false
        public const ulong FFlagLuaAppUseFoundationLoading = 0x19B8E610B30; // Unknown = 
        public const ulong FFlagLuaAppUseFrameBoundsImpressions = 0x19B9AF1AF10; // Unknown = 
        public const ulong FFlagLuaAppUseGameTransactionsApiForReceipts = 0x19B9ACB5D90; // Unknown = 
        public const ulong FFlagLuaAppUseOverlayInAppContainer = 0x19B88C27050; // Unknown = 
        public const ulong FFlagLuaAppUsePrevalidatedVideoGamePlayability = 0x19B88C402DD; // Bool = false
        public const ulong FFlagLuaAppUseRatingFormatHelper2 = 0x19BBE913AD0; // Unknown = 
        public const ulong FFlagLuaAppUseScreenFillBoundsForFrameBoundsImpressions = 0x19B9AF1A450; // Unknown = 
        public const ulong FFlagLuaAppUseSettingsNativeWrapper2 = 0x19B9064421D; // Bool = false
        public const ulong FFlagLuaAppUseSnackbarForProvideFeedbackToast = 0x19B88C25EDD; // Bool = false
        public const ulong FFlagLuaAppUseSortsWithDividersFString2 = 0x19BC0549B90; // Unknown = 
        public const ulong FFlagLuaAppUseSpanTileOverflowMenuTwoByOne2 = 0x19BBE91FFD0; // Unknown = 
        public const ulong FFlagLuaAppUseTokenHeightForPlayButton = 0x19B88C2F7D0; // Unknown = 
        public const ulong FFlagLuaAppUseViewportBoundsInsetFix = 0x19B8F90E810; // Unknown = 
        public const ulong FFlagLuaAppUseWithLocalization = 0x19B90649C1D; // Bool = false
        public const ulong FFlagLuaAppUserSearchGridReactiveContainer = 0x19B902949D0; // Unknown = 
        public const ulong FFlagLuaAppUserSeenCollectionUnifiedFields = 0x19B88C2BB9D; // Bool = false
        public const ulong FFlagLuaAppUsingSecurityQuestionsForLuaLogin2 = 0x19B88C4B110; // Unknown = 
        public const ulong FFlagLuaAppVideoAutoplayElectOnNewCandidate = 0x19BBC387890; // Unknown = 
        public const ulong FFlagLuaAppVideoAutoplayFeedElection = 0x19B88C2D010; // Unknown = 
        public const ulong FFlagLuaAppVideoPlaybackRefCount = 0x19B88C4171D; // Bool = false
        public const ulong FFlagLuaAppVideoServerDisplayWakeLock = 0x19B88C418DD; // Bool = false
        public const ulong FFlagLuaAppVideoTileDisableActivation = 0x19B88C2D0DD; // Bool = false
        public const ulong FFlagLuaAppVideoTileHideCenterPlayButton = 0x19B88C2D31D; // Bool = false
        public const ulong FFlagLuaAppVngUpsellAlwaysCanClose = 0x19B9481249D; // Bool = false
        public const ulong FFlagLuaAppVngUpsellAlwaysEnabled = 0x19B9481235D; // Bool = false
        public const ulong FFlagLuaAppVoteOptimisticUpdateRaceFix = 0x19BA553DC10; // Unknown = 
        public const ulong FFlagLuaAppWireAudioDeviceInputOnRequest = 0x19B88C41B1D; // Bool = false
        public const ulong FFlagLuaAppWizardContainerBypassNavigationLock = 0x19BC054AB1D; // Bool = true
        public const ulong FFlagLuaAppWrapChartsFilterOptionLabels = 0x19B90264F5D; // Bool = false
        public const ulong FFlagLuaAppsDefaultSelection = 0x19BA6A379D0; // Unknown = 
        public const ulong FFlagLuaAppsServerTriggeredModals = 0x19B88C4F650; // Unknown = 
        public const ulong FFlagLuaConsumePlayerModerated = 0x19B8FDE9D10; // Unknown = 
        public const ulong FFlagLuaEnableCustomizedInviteLandingPage = 0x19B945A7690; // Unknown = 
        public const ulong FFlagLuaEnableCustomizedInviteLandingPageForTesting = 0x19B945A1950; // Unknown = 
        public const ulong FFlagLuaEnableDidSwitchAccount = 0x19B88C4D75D; // Bool = false
        public const ulong FFlagLuaEnableGameInviteModal2023V5 = 0x19D89528290; // Unknown = 
        public const ulong FFlagLuaEnableGameInviteModalInvitePromptV2 = 0x19B9F29455D; // Bool = false
        public const ulong FFlagLuaEnableGameInviteModalSettingsHub = 0x19BACE9C5DD; // Bool = false
        public const ulong FFlagLuaEnableGenreDeeplinkSortId = 0x19B8616E548; // Unknown = 
        public const ulong FFlagLuaEnableGenreLandingDeeplink = 0x19B88C22E10; // Unknown = 
        public const ulong FFlagLuaEnableLandingPageTTIMeasurements = 0x19B945A0150; // Unknown = 
        public const ulong FFlagLuaEnableLoginAndSignupDifferentiatedStatusValues = 0x19B945A1350; // Unknown = 
        public const ulong FFlagLuaEnableScreenTimeSignalR = 0x19BA3AD9010; // Unknown = 
        public const ulong FFlagLuaEnableShowUpsellMethod2 = 0x19B8C304F1D; // Bool = true
        public const ulong FFlagLuaFlagVoiceChatDisableSubscribeRetryForMultistream = 0x19BA6B3C21D; // Bool = false
        public const ulong FFlagLuaIdentityGetPhoneNumber = 0x19BC054BE50; // Unknown = 
        public const ulong FFlagLuaIdentityGetSMSOTP = 0x19BC0546E50; // Unknown = 
        public const ulong FFlagLuaIdentityProtocol = 0x19BBC385110; // Unknown = 
        public const ulong FFlagLuaIdentityVerifySNA = 0x19BC054DE50; // Unknown = 
        public const ulong FFlagLuaInExperienceCoreScriptsGameInviteUnificationV3 = 0x19B9AF10E50; // Unknown = 
        public const ulong FFlagLuaMenuPerfImprovements = 0x19B996ED650; // Unknown = 
        public const ulong FFlagLuaMultiPageSignupForceDeviceBoundPasskey = 0x19B945A0590; // Unknown = 
        public const ulong FFlagLuaUsePhoneNumberTextTypeForPhoneUpsellV2 = 0x19BBC384B50; // Unknown = 
        public const ulong FFlagLuaVoiceChatAnalyticsBanMessage = 0x19B8FDE961D; // Bool = false
        public const ulong FFlagLuaVoiceChatAnalyticsUseCounterV2 = 0x19B8FDE921D; // Bool = false
        public const ulong FFlagLuaVoiceChatAnalyticsUseEventsV2 = 0x19B8FDE945D; // Bool = false
        public const ulong FFlagLuaVoiceChatAnalyticsUsePointsV2 = 0x19B8FDE82D0; // Unknown = 
        public const ulong FFlagLuaVoiceChatReconnectMissedSequence = 0x19B8FDE97DD; // Bool = false
        public const ulong FFlagLuafiedReportEntryPoints = 0x19B8C306FDD; // Bool = true
        public const ulong FFlagLuafiedReportErrorStates = 0x19B8C306B50; // Unknown = 
        public const ulong FFlagLuafiedReportFullFlow = 0x19BBF83F308; // Unknown = 
        public const ulong FFlagLuafiedReportThumbnail = 0x19B8C306DD0; // Unknown = 
        public const ulong FFlagLuafiedWechatQQLogin8 = 0x19B88C4DCDD; // Bool = false
        public const ulong FFlagMacMenuBarContentUpdates = 0x19BA59B4AD0; // Unknown = 
        public const ulong FFlagMacUnifyKeyCodeMapping = 0x19B825F289D; // Bool = true
        public const ulong FFlagMakeCreateOrJoinSquadAThunks = 0x19BACFD4510; // Unknown = 
        public const ulong FFlagMakeVPCFAECheckMoreGeneric = 0x19B8C2E4ADD; // Bool = false
        public const ulong FFlagManagerAddDisplayOrderAndBackgroundDismiss = 0x19B8FC35C5D; // Bool = false
        public const ulong FFlagManuallyInvokeAmpUpsell2 = 0x19B90268C50; // Unknown = 
        public const ulong FFlagManuallyMigrateDeprecatedIconUsage = 0x19B85788B90; // Unknown = 
        public const ulong FFlagMarketplaceCatalogCategoryTrackLastReceived = 0x19B88C20710; // Unknown = 
        public const ulong FFlagMarketplaceCatalogSortTrackLastReceived = 0x19B88C20E10; // Unknown = 
        public const ulong FFlagMarketplaceOffersOptOutRoot = 0x19B9AF1EB90; // Unknown = 
        public const ulong FFlagMarketplaceOffersOptOutRootLowSpender = 0x19B9AF1D450; // Unknown = 
        public const ulong FFlagMarketplaceOffersOptOutRootNoSpender = 0x19B9AF1E710; // Unknown = 
        public const ulong FFlagMarketplaceOffersOptOutRootRandom = 0x19B9AF1F250; // Unknown = 
        public const ulong FFlagMarketplaceOffersRoot = 0x19B9ACB1550; // Unknown = 
        public const ulong FFlagMarketplaceOffersRootLowSpender = 0x19B9ACB6710; // Unknown = 
        public const ulong FFlagMarketplaceOffersRootNoSpender = 0x19B9AF1D510; // Unknown = 
        public const ulong FFlagMarketplaceOffersRootRandom = 0x19B9AF1ED90; // Unknown = 
        public const ulong FFlagMeTabBadgeEnabled = 0x19B859CAF50; // Unknown = 
        public const ulong FFlagMeTabRightOfPartyBottomNav = 0x19B859CAD10; // Unknown = 
        public const ulong FFlagMediaAccordionAndFullTelemetry = 0x19BB1D93BD0; // Unknown = 
        public const ulong FFlagMediaGalleryVideoVisiblePercent = 0x19B9AF14050; // Unknown = 
        public const ulong FFlagMediaSelectorErrorLogging = 0x19BACE7269D; // Bool = false
        public const ulong FFlagMemoizeBubbleChatApp = 0x19BBCD79BD0; // Unknown = 
        public const ulong FFlagMemoizeChatInputApp = 0x19BA461A290; // Unknown = 
        public const ulong FFlagMemoizeChatReportingMenu = 0x19BACFDC850; // Unknown = 
        public const ulong FFlagMenuButtonsDisconnectGamepadConnected = 0x19BAC873410; // Unknown = 
        public const ulong FFlagMenuButtonsIncreaseIconSize = 0x19BAC873E10; // Unknown = 
        public const ulong FFlagMenuButtonsMountWithIEM = 0x19BACE9D51D; // Bool = false
        public const ulong FFlagMenuButtonsUseGreyResumeButton = 0x19BAC87409D; // Bool = false
        public const ulong FFlagMicroProfilerReadOnlyInformationLabel = 0x19B9FD8BA9D; // Bool = false
        public const ulong FFlagMigrateAllOsaMessagingToCentralService = 0x19B8C30DE5D; // Bool = true
        public const ulong FFlagMigrateCameraCFrameDatamodel = 0x19B8184305D; // Bool = false
        public const ulong FFlagMigrateCameraFocusDatamodel = 0x19B81842F9D; // Bool = false
        public const ulong FFlagMigrateCameraFovDatamodel = 0x19B81842F1D; // Bool = false
        public const ulong FFlagMigrateFriendshipStatusesPYMK = 0x19B8FC3B45D; // Bool = false
        public const ulong FFlagMigrateFriendshipStatusesRemainingActions = 0x19B88C24A1D; // Bool = false
        public const ulong FFlagMigrateFriendshipStatusesSocialCarousel = 0x19B8FA1D81D; // Bool = false
        public const ulong FFlagMigrateFriendshipStatusesUserSearch = 0x19B9011A99D; // Bool = false
        public const ulong FFlagMigrateGameIconsToStore = 0x19BA5539B10; // Unknown = 
        public const ulong FFlagMigrateGameInfoToStoreDev = 0x19B88C20990; // Unknown = 
        public const ulong FFlagMigrateNoFriendsViewToFoundation = 0x19B8FA1C81D; // Bool = false
        public const ulong FFlagMigratePymkCarouselHttpRequestToRequestInternal = 0x19B8FC377DD; // Bool = false
        public const ulong FFlagMigrateRoactUtilsToReactUtils = 0x19B857896DD; // Bool = false
        public const ulong FFlagMigrateSocialNetworking = 0x19BC054B150; // Unknown = 
        public const ulong FFlagMigrateUserSearchHttpRequestToRequestInternal = 0x19B9011DED0; // Unknown = 
        public const ulong FFlagMinMaxPriceValidation = 0x19BBC7A2710; // Unknown = 
        public const ulong FFlagMobileGameJoinCardEDPFromThumbnail = 0x19B8FA1D0DD; // Bool = false
        public const ulong FFlagMobileGameJoinCardEDPFromTitle = 0x19B8FA1BD50; // Unknown = 
        public const ulong FFlagMobileGameJoinCardHideUserAvatar = 0x19B8FA1D39D; // Bool = false
        public const ulong FFlagMobileGameJoinCardShowExperienceNameOnly = 0x19B8FA1D5DD; // Bool = false
        public const ulong FFlagMobileGameJoinCardTTITracking = 0x19B8C30315D; // Bool = true
        public const ulong FFlagMobileGameJoinCardThumbnail = 0x19B8FA1C7D0; // Unknown = 
        public const ulong FFlagMobilePopularItemBadgingExperimentEnabled = 0x19B9B5F4EAD; // Bool = false
        public const ulong FFlagMobilePopularItemBadgingExperimentEnabledV2 = 0x19BAC833DDD; // Bool = false
        public const ulong FFlagMobileSoundAndHapticsEnabledIXP = 0x19BBC383950; // Unknown = 
        public const ulong FFlagMobileSoundAndHapticsIXPBypass = 0x19BBC38BB90; // Unknown = 
        public const ulong FFlagMockDevSubPurchaseInStudio = 0x19D85DC32D0; // Unknown = 
        public const ulong FFlagModalImpressionEventAddSessionInfo = 0x19B90294590; // Unknown = 
        public const ulong FFlagModalSelectorCloseButton = 0x19BBB7FC490; // Unknown = 
        public const ulong FFlagMomentTextGenerationFilteredSignal = 0x19D86F02590; // Unknown = 
        public const ulong FFlagMomentsAnalyticsClientEventTimestamp = 0x19BBF255110; // Unknown = 
        public const ulong FFlagMomentsAnalyticsProducerPrereqs = 0x19BBF25D990; // Unknown = 
        public const ulong FFlagMomentsAnalyticsSchemaIdentity = 0x19BBF25E690; // Unknown = 
        public const ulong FFlagMomentsAutoplayAmpPolicy = 0x19B85786910; // Unknown = 
        public const ulong FFlagMomentsCarouselVideoHandoff = 0x19B8C2EC090; // Unknown = 
        public const ulong FFlagMomentsContentStatsTelemetry = 0x19D86F04290; // Unknown = 
        public const ulong FFlagMomentsCreationAccurateDirtyTracking = 0x19D86F0C510; // Unknown = 
        public const ulong FFlagMomentsCreationBlockBackgroundInteraction = 0x19D86F0BA9D; // Bool = false
        public const ulong FFlagMomentsCreationGalleryPreviewSwapFix = 0x19D86F0B25D; // Bool = true
        public const ulong FFlagMomentsCreationMusicSearchStateFix = 0x19D86F00490; // Unknown = 
        public const ulong FFlagMomentsCreationNormalizeMetadataEnums = 0x19D86F04C90; // Unknown = 
        public const ulong FFlagMomentsCreationPersistEditSession = 0x19D86F0781D; // Bool = false
        public const ulong FFlagMomentsCreationSaveDraft = 0x19BB2739B35; // Bool = true
        public const ulong FFlagMomentsCreationTextOverlayResolutionScale = 0x19D864C13C0; // Unknown = 
        public const ulong FFlagMomentsDarkAppNavBar = 0x19B9AF17110; // Unknown = 
        public const ulong FFlagMomentsDescriptionKeyboardAvoidance = 0x19D86F09EDD; // Bool = true
        public const ulong FFlagMomentsEmojiSetsApi = 0x19BB89771A5; // Bool = true
        public const ulong FFlagMomentsEntryImmersiveNav = 0x19B9ACB6950; // Unknown = 
        public const ulong FFlagMomentsFeedHealthAnalytics = 0x19D86F03090; // Unknown = 
        public const ulong FFlagMomentsFeedWatchPageAttribution = 0x19B8578681D; // Bool = false
        public const ulong FFlagMomentsFixBatchedGetMomentsQueryParams = 0x19BACE70190; // Unknown = 
        public const ulong FFlagMomentsIPReporting = 0x19B85786AD0; // Unknown = 
        public const ulong FFlagMomentsLoopOnEndSeek = 0x19D86F08490; // Unknown = 
        public const ulong FFlagMomentsMediaSmoothnessTelemetry = 0x19D86F04110; // Unknown = 
        public const ulong FFlagMomentsMuteVideoAudioOnly = 0x19D86F0731D; // Bool = true
        public const ulong FFlagMomentsOverlayContainerScaleFallback = 0x19D86F09CD0; // Unknown = 
        public const ulong FFlagMomentsPassFeedItemIdToBackendApis = 0x19B9F181945; // Bool = true
        public const ulong FFlagMomentsPostCtaUseCaptureUniverse = 0x19D86F03290; // Unknown = 
        public const ulong FFlagMomentsProfileGridInfiniteLoad = 0x19D86F07B50; // Unknown = 
        public const ulong FFlagMomentsReactToFeedItemV2 = 0x19B99878365; // Bool = true
        public const ulong FFlagMomentsRealtimeObservability = 0x19D86F03750; // Unknown = 
        public const ulong FFlagMomentsRealtimeSessionTelemetry = 0x19D86F01410; // Unknown = 
        public const ulong FFlagMomentsRefreshOwnMomentsAfterPublish = 0x19B85786F9D; // Bool = false
        public const ulong FFlagMomentsRemoveDeletedFromProfile = 0x19B85786DDD; // Bool = false
        public const ulong FFlagMomentsReportWithFeedId = 0x19B9AF17150; // Unknown = 
        public const ulong FFlagMomentsRequireApiFeedItemId = 0x19BA8025DDD; // Bool = false
        public const ulong FFlagMomentsRespectAccountTheme = 0x19B9AF16E90; // Unknown = 
        public const ulong FFlagMomentsScreenshotMusicScrubber = 0x19D86F00BDD; // Bool = false
        public const ulong FFlagMomentsSessionHeartbeat = 0x19D86F03F90; // Unknown = 
        public const ulong FFlagMomentsStickerButton3 = 0x19D86F011D0; // Unknown = 
        public const ulong FFlagMomentsStickerOverlayMediaRect = 0x19D86F09990; // Unknown = 
        public const ulong FFlagMomentsStickerOverlayNormalization = 0x19BA8026DD0; // Unknown = 
        public const ulong FFlagMomentsStickerOverlayNormalization2 = 0x19BA802D910; // Unknown = 
        public const ulong FFlagMomentsSurfaceLoadTTI = 0x19B85786A5D; // Bool = false
        public const ulong FFlagMomentsTTSAudioOverlayLua2 = 0x19D86F04D1D; // Bool = false
        public const ulong FFlagMomentsTabReactiveIXP = 0x19B85783C10; // Unknown = 
        public const ulong FFlagMomentsTextDragToDelete = 0x19D86F06290; // Unknown = 
        public const ulong FFlagMomentsTextOverlayAfterVideoLoaded = 0x19D86F02050; // Unknown = 
        public const ulong FFlagMomentsTextOverlayClampToBounds = 0x19D86F031D0; // Unknown = 
        public const ulong FFlagMomentsTextOverlayMediaRect = 0x19D86F066D0; // Unknown = 
        public const ulong FFlagMomentsTileSkeletonPoster = 0x19D86F05790; // Unknown = 
        public const ulong FFlagMomentsUseBackendPostStatusNotification = 0x19D86F0DB50; // Unknown = 
        public const ulong FFlagMomentsUseUploadPostAsync = 0x19D86F08B90; // Unknown = 
        public const ulong FFlagMomentsVideoCropRoundedCorners = 0x19D86F02F10; // Unknown = 
        public const ulong FFlagMomentsVideoSurfaceMediaRect = 0x19D86F05FD0; // Unknown = 
        public const ulong FFlagMomentsWatchSessionalization = 0x19B857866DD; // Bool = false
        public const ulong FFlagMoreFramerateOptions = 0x19BA3669F9D; // Bool = false
        public const ulong FFlagMountCoreGuiBackpack = 0x19BA6078890; // Unknown = 
        public const ulong FFlagMountUnmountSideSheet = 0x19BA4E9D21D; // Bool = false
        public const ulong FFlagMoveAmpUpsellOffNavigateDown = 0x19B8C30C0D0; // Unknown = 
        public const ulong FFlagMoveInExperienceModeToEditProfile_V2 = 0x19B8C2E38D0; // Unknown = 
        public const ulong FFlagMoveLimitedBadgeToTopLeft = 0x19B9F0081DD; // Bool = false
        public const ulong FFlagMoveLuaExpLaunchBegin = 0x19BA46128DD; // Bool = false
        public const ulong FFlagMoveReducerCreationOutOfReducer = 0x19B81DE7C18; // Unknown = 
        public const ulong FFlagMusicPlayerUseDynamicNavBarHeight = 0x19B9ACBD790; // Unknown = 
        public const ulong FFlagMutualConnectionsListPagination = 0x19BACFDDDDD; // Bool = false
        public const ulong FFlagMyStatsMediaSelector3 = 0x19B9AF15450; // Unknown = 
        public const ulong FFlagNavigateToSafetyDashboardForAppeals = 0x19BBB3191D0; // Unknown = 
        public const ulong FFlagNavigateToSafetyDashboardForAppeals2 = 0x19B8C30E51D; // Bool = true
        public const ulong FFlagNewEventIngestPlayerScriptsDimensions = 0x19BACE9CB9D; // Bool = false
        public const ulong FFlagNewInGameMenuDisabledInVR = 0x19BA36674DD; // Bool = false
        public const ulong FFlagNewPeopleButtonOrder = 0x19BBC386E90; // Unknown = 
        public const ulong FFlagNewPeopleButtonOrder4 = 0x19BBC38F150; // Unknown = 
        public const ulong FFlagNewPeoplePageIcons = 0x19BBC389AD0; // Unknown = 
        public const ulong FFlagNewPeoplePageIcons5 = 0x19BBC389910; // Unknown = 
        public const ulong FFlagNewUpsellModalExperiment = 0x19D84DA64D0; // Unknown = 
        public const ulong FFlagNewUpsellModalExperimentForDesktopV2 = 0x19BAC8320DD; // Bool = false
        public const ulong FFlagNewUpsellModalExperimentForPlatform = 0x19BAC831990; // Unknown = 
        public const ulong FFlagNewUpsellModalExperimentV2 = 0x19BAC831FDD; // Bool = false
        public const ulong FFlagNoShortcutBarWithTvRemote = 0x19BA607D150; // Unknown = 
        public const ulong FFlagNonVoiceFTUX = 0x19BACFD7D10; // Unknown = 
        public const ulong FFlagNormalizePriceDiscountAcceptLowercase = 0x19D85DCDC90; // Unknown = 
        public const ulong FFlagNotApprovedPageIXPExposure = 0x19B8C30B950; // Unknown = 
        public const ulong FFlagNotificationModalSetMenuIsOpen = 0x19B88C4EC1D; // Bool = false
        public const ulong FFlagNotificationThumbnailUseProfileFrameThumbnail = 0x19BA607CC50; // Unknown = 
        public const ulong FFlagNotificationsComplianceShouldRestrictStream = 0x19B8C304210; // Unknown = 
        public const ulong FFlagNotificationsForceEnableEDPDiscoverability = 0x19B8C30529D; // Bool = true
        public const ulong FFlagNotificationsRenameFriendRequestToConnection = 0x19BACFEBDDD; // Bool = false
        public const ulong FFlagNotificationsUpsellDisableBackgroundDismiss = 0x19B8FA1FB5D; // Bool = false
        public const ulong FFlagOffNetworkAnalytics = 0x19BC0543110; // Unknown = 
        public const ulong FFlagOnlyEnableJoinVoiceInVoiceEnabledUniversesV2 = 0x19BA515789D; // Bool = false
        public const ulong FFlagOnlyShowToastOnce2 = 0x19B9FD8909D; // Bool = false
        public const ulong FFlagOnlyShowToastOnceInLifetime2 = 0x19B9FD89450; // Unknown = 
        public const ulong FFlagOpenVngTosForVngRobuxUpsell = 0x19B88C4B45D; // Bool = false
        public const ulong FFlagOrientationUseTelemetryService = 0x19BA609D790; // Unknown = 
        public const ulong FFlagOverflowMenuRemoveCloseMenuChecks = 0x19BA609D6D0; // Unknown = 
        public const ulong FFlagOverrideInExperienceMenuReorderFirstVariant = 0x19B9FDDAED5; // Bool = false
        public const ulong FFlagOverridePlayerVerifiedBadge = 0x19B85788110; // Unknown = 
        public const ulong FFlagPCMAcceptWidthAsProp = 0x19B82A11CD0; // Unknown = 
        public const ulong FFlagPPDebugLogging = 0x19D85DC2150; // Unknown = 
        public const ulong FFlagPPVBackgroundUse2DAsLoadingState = 0x19B8C2E1C5D; // Bool = false
        public const ulong FFlagPPVEnable3DBackground = 0x19BA59B9E10; // Unknown = 
        public const ulong FFlagPPVEnabledOnConsole_V3 = 0x19B8C2E0450; // Unknown = 
        public const ulong FFlagPYMKAddFriendsEntry_v3 = 0x19B8C2E5010; // Unknown = 
        public const ulong FFlagPYMKDisableButtonsOnFetch = 0x19B9011541D; // Bool = false
        public const ulong FFlagPYMKFriendsToastRename = 0x19B9011539D; // Bool = false
        public const ulong FFlagPYMKShowAddFriendsButton_DEV = 0x19B9029481D; // Bool = false
        public const ulong FFlagPackagifySettingsShowSignal = 0x19B88C4EADD; // Bool = false
        public const ulong FFlagPageLoadAllowImprovedDisconnectTiming = 0x19B8578BC90; // Unknown = 
        public const ulong FFlagParseHeadShapeFromAPIResponse = 0x19BA3A5A15D; // Bool = false
        public const ulong FFlagParseHeadShapeFromAPIResponse6 = 0x19BA3A5955D; // Bool = false
        public const ulong FFlagPartyCoordinationUIExposureEnabled = 0x19B8FDED350; // Unknown = 
        public const ulong FFlagPartyDevAPIToRespectThirdPartySettingsEnabled = 0x19B8C2E2910; // Unknown = 
        public const ulong FFlagPartyFormationCreateUserExposureEnabled = 0x19B8FDEECDD; // Bool = false
        public const ulong FFlagPartyFoundationIconFixEnabled = 0x19B8C2E14D0; // Unknown = 
        public const ulong FFlagPartyVoiceDisallowIXPLayerExposureOnInit = 0x19B859C8EDD; // Bool = false
        public const ulong FFlagPartyVoiceLogActiveDM = 0x19B859C93DD; // Bool = false
        public const ulong FFlagPassNavigationToContactsRevoked = 0x19BAFCFE990; // Unknown = 
        public const ulong FFlagPassShopPurchaseSurfaceToBuyModal = 0x19B9ACBBE10; // Unknown = 
        public const ulong FFlagPasskeySignupEnabled5 = 0x19B9029179D; // Bool = false
        public const ulong FFlagPasskeyUpsellEnabled = 0x19B945A7410; // Unknown = 
        public const ulong FFlagPasskeyUpsellEnabled1 = 0x19B945A2C10; // Unknown = 
        public const ulong FFlagPasskeyUpsellFilteringEnabled = 0x19B945A3750; // Unknown = 
        public const ulong FFlagPasswordErrorLength = 0x19B8C30DADD; // Bool = true
        public const ulong FFlagPasswordErrorSimple = 0x19B88C61A1D; // Bool = false
        public const ulong FFlagPeekViewFixBriefHeightLayoutRace = 0x19BC0543850; // Unknown = 
        public const ulong FFlagPeopleCardsEnableVirtualizedGrid = 0x19BBC381D10; // Unknown = 
        public const ulong FFlagPeopleListContextualMenuFixFocusNavigation = 0x19BACFDE290; // Unknown = 
        public const ulong FFlagPeoplePageCardMenuUseVisibleProperty = 0x19BB7F4CE55; // Bool = false
        public const ulong FFlagPeoplePageDismissCardMenuOnScrollOutOfView = 0x19BBC381710; // Unknown = 
        public const ulong FFlagPeoplePageDismissVolumePopoverOnScrollOutOfView = 0x19BBC38B050; // Unknown = 
        public const ulong FFlagPeoplePageEnablePersonSignalStore = 0x19BBC380B50; // Unknown = 
        public const ulong FFlagPeoplePageFlipVolumePopoverToFitViewport = 0x19BBC380890; // Unknown = 
        public const ulong FFlagPeoplePageLazyRenderCards = 0x19BBC387750; // Unknown = 
        public const ulong FFlagPeoplePagePostponeInitialRender = 0x19BBC3813D0; // Unknown = 
        public const ulong FFlagPeoplePageRemoveSkeletons = 0x19BBC38D290; // Unknown = 
        public const ulong FFlagPeoplePageRemoveUseMemoElements = 0x19BBC381650; // Unknown = 
        public const ulong FFlagPeopleTabUseProfileFrameThumbnail = 0x19BB7F467DD; // Bool = false
        public const ulong FFlagPerfInsightsEnabled = 0x19B902905D0; // Unknown = 
        public const ulong FFlagPermissionAlertContentUpgrade = 0x19BB02C74E5; // Bool = true
        public const ulong FFlagPhoneUseParentSizeForScreenSize = 0x19BBC384A50; // Unknown = 
        public const ulong FFlagPhoneVerificationWebviewShouldBeFullscreen1 = 0x19BC0545190; // Unknown = 
        public const ulong FFlagPlatformEventEnabled2 = 0x19BA59BB710; // Unknown = 
        public const ulong FFlagPlatformLeaderboardDebugLogging = 0x19BA59B04D0; // Unknown = 
        public const ulong FFlagPlatformLeaderboardEnabled = 0x19BACE98F10; // Unknown = 
        public const ulong FFlagPlatformLeaderboardLocalizedUnitEnabled = 0x19BACE9975D; // Bool = false
        public const ulong FFlagPlatformLeaderboardPersistStoreOnRemount = 0x19B949F9960; // Unknown = 
        public const ulong FFlagPlatformLeaderboardRccEnabled = 0x19BA59B7FD0; // Unknown = 
        public const ulong FFlagPlatformLeaderboardRccEnabled2 = 0x19BA59B649D; // Bool = false
        public const ulong FFlagPlatformLeaderboardsExposure2Enabled_V2 = 0x19BACE9921D; // Bool = false
        public const ulong FFlagPlatformLeaderboardsIXPNoLeaderboardsShown_V3 = 0x19BACE9991D; // Bool = false
        public const ulong FFlagPlayStationBumperHint = 0x19BA6A37210; // Unknown = 
        public const ulong FFlagPlayWithRewardClearOnExperienceLeave = 0x19B9ACB3D90; // Unknown = 
        public const ulong FFlagPlayWithRewardCoachmarkOverlayFix = 0x19B9ACB4B90; // Unknown = 
        public const ulong FFlagPlayWithRewardCoachmarkWindowResets = 0x19B90640B1D; // Bool = false
        public const ulong FFlagPlayerListClosedNoRender = 0x19B8EE05D10; // Unknown = 
        public const ulong FFlagPlayerListClosedNoRenderWithTenFoot = 0x19B8EE06AD0; // Unknown = 
        public const ulong FFlagPlayerListDropDownShowPlatformName = 0x19BACE9775D; // Bool = false
        public const ulong FFlagPlayerListFilterInputServiceDispatches = 0x19BAD285B9D; // Bool = false
        public const ulong FFlagPlayerListFixLeaderstatsStacking2 = 0x19BBCD7F89D; // Bool = false
        public const ulong FFlagPlayerListFixMobileScrolling = 0x19BAD284450; // Unknown = 
        public const ulong FFlagPlayerListFoundationSubscriptionIcon = 0x19BACE97ADD; // Bool = false
        public const ulong FFlagPlayerListHideUnusedStats = 0x19BACE95D9D; // Bool = false
        public const ulong FFlagPlayerListIgnoreDevGamepadBindings = 0x19D87043CD0; // Unknown = 
        public const ulong FFlagPlayerListIgnoreDevGamepadBindings2 = 0x19BACE973DD; // Bool = false
        public const ulong FFlagPlayerListLocalizeGameText = 0x19BACE97990; // Unknown = 
        public const ulong FFlagPlayerListPersistVisibility = 0x19BA7DA2C20; // Unknown = 
        public const ulong FFlagPlayerListReduceRerenders = 0x19BAD28391D; // Bool = false
        public const ulong FFlagPlayerListRefactorUsernameFormatting = 0x19BB7F4A150; // Unknown = 
        public const ulong FFlagPlayerListRemoveTopStat = 0x19BA76D370D; // Bool = false
        public const ulong FFlagPlayerListReskin = 0x19BB6B08165; // Bool = false
        public const ulong FFlagPlayerListReskin3 = 0x19BACE97CDD; // Bool = false
        public const ulong FFlagPlayerListSortByLowercaseUsername = 0x19BACE95F1D; // Bool = false
        public const ulong FFlagPlayerListTopStatCheckGamepad = 0x19BAD285A90; // Unknown = 
        public const ulong FFlagPlayerListTwoTabs = 0x19BACE97E1D; // Bool = false
        public const ulong FFlagPlayerListTwoTabsOnLegacy = 0x19BACE97F5D; // Bool = false
        public const ulong FFlagPlayerListUseFocusNavHook = 0x19BB20A2FDD; // Bool = true
        public const ulong FFlagPlayerListUseFocusNavHook2 = 0x19BACE963DD; // Bool = false
        public const ulong FFlagPlayerListUseMobileOnSmallDisplay = 0x19D8704B090; // Unknown = 
        public const ulong FFlagPlayerListUseMobileOnSmallDisplay2 = 0x19BACE96250; // Unknown = 
        public const ulong FFlagPlayerSearchEnableOnlineFrequents = 0x19BA59B01D0; // Unknown = 
        public const ulong FFlagPlayerSearchEnableOnlineFrequentsForAll = 0x19BA59B2C50; // Unknown = 
        public const ulong FFlagPlayerViewRemoteEnabled = 0x19B9F924D9D; // Bool = false
        public const ulong FFlagPlaytestModeExcludeStudio = 0x19BBBFF4A6D; // Bool = false
        public const ulong FFlagPopularFillIconEnabled = 0x19BAC833390; // Unknown = 
        public const ulong FFlagPreHomePageRoutingEnabled = 0x19B945AEF90; // Unknown = 
        public const ulong FFlagPreciseSelectionBugfixesEnabled = 0x19BBB7FEB90; // Unknown = 
        public const ulong FFlagPrefetchFriendGameMedia = 0x19BBF84F5C8; // Unknown = 
        public const ulong FFlagPrefetchProfileNamesOnStartup_v2 = 0x19BAFCFBB90; // Unknown = 
        public const ulong FFlagPrefillPreciseSelectionChoices = 0x19B8C30DD90; // Unknown = 
        public const ulong FFlagPreselectedPlayerReportBugfix = 0x19BB7F490D0; // Unknown = 
        public const ulong FFlagPresencePropagationDelayMonitoringEnabledV2 = 0x19B90290510; // Unknown = 
        public const ulong FFlagPreventHiddenSwitchPage = 0x19BA6C3CDC5; // Bool = true
        public const ulong FFlagPreventMicToggleIfGameConsumedEvent = 0x19BBCD70110; // Unknown = 
        public const ulong FFlagPreventSuperBriefPeekViewClose2 = 0x19BC0549ED0; // Unknown = 
        public const ulong FFlagPriceSummaryV2UseLocalizedBreakdown = 0x19BAE780E8D; // Bool = true
        public const ulong FFlagProfileAboutDetailsUseSheet = 0x19B8C2EA950; // Unknown = 
        public const ulong FFlagProfileContextualMenuDisableFix = 0x19B8C2EC8D0; // Unknown = 
        public const ulong FFlagProfileEnableSocialNetworksUsernames = 0x19BACFDA250; // Unknown = 
        public const ulong FFlagProfileFixMenuNavigation = 0x19BAEE1E750; // Unknown = 
        public const ulong FFlagProfileFixMenuNavigation_V2 = 0x19B8C2ECA10; // Unknown = 
        public const ulong FFlagProfileFrameThumbnailEnabled = 0x19BACFD8B10; // Unknown = 
        public const ulong FFlagProfileHideTabBarOnAboutSheet = 0x19B90641510; // Unknown = 
        public const ulong FFlagProfileInspectAndBuyRefactorTooltip = 0x19BB7F4CA50; // Unknown = 
        public const ulong FFlagProfileInspectAvatarCWEntry = 0x19BB7F42510; // Unknown = 
        public const ulong FFlagProfileMomentsFeedHideTabBar = 0x19B90641890; // Unknown = 
        public const ulong FFlagProfileMomentsFeedRootRoute = 0x19B9AF13F10; // Unknown = 
        public const ulong FFlagProfileMomentsOrderingAndReactions = 0x19B8C2EB850; // Unknown = 
        public const ulong FFlagProfileMomentsVideoPlaybackFix = 0x19B8C2EBA90; // Unknown = 
        public const ulong FFlagProfilePlatformAboutBeforeActionClient = 0x19B825F4F50; // Unknown = 
        public const ulong FFlagProfilePlatformAddCurrentlyPlaying_V4 = 0x19B825F1B70; // Unknown = 
        public const ulong FFlagProfilePlatformAddTC = 0x19BAEE1D150; // Unknown = 
        public const ulong FFlagProfilePlatformAddTC_v10 = 0x19B8C2EC210; // Unknown = 
        public const ulong FFlagProfilePlatformCTAsRefactor = 0x19D7C7C2CD0; // Unknown = 
        public const ulong FFlagProfilePlatformCTAsRefactor_V3 = 0x19B81F0FED0; // Unknown = 
        public const ulong FFlagProfilePlatformEditBackgroundMenuItem = 0x19B859CBAD0; // Unknown = 
        public const ulong FFlagProfilePlatformEnableAvatarBackground = 0x19BA59B3F1D; // Bool = false
        public const ulong FFlagProfilePlatformEnableBundlesInAssetsCarousel = 0x19BACFD3410; // Unknown = 
        public const ulong FFlagProfilePlatformEnableChipSocialRow_v6 = 0x19B825F30BD; // Bool = true
        public const ulong FFlagProfilePlatformEnableClickToCopyUsername = 0x19B825FEC3D; // Bool = true
        public const ulong FFlagProfilePlatformEnableCoverPhotoPeekViewFix_v2 = 0x19B8EAE95F0; // Unknown = 
        public const ulong FFlagProfilePlatformEnableCurrencyTransfer = 0x19BAEE12110; // Unknown = 
        public const ulong FFlagProfilePlatformEnableCurrencyTransferV1 = 0x19B8C2EB49D; // Bool = false
        public const ulong FFlagProfilePlatformEnableEditAppearanceMenu = 0x19B859CBCDD; // Bool = false
        public const ulong FFlagProfilePlatformEnableImpressions = 0x19B8C2E9510; // Unknown = 
        public const ulong FFlagProfilePlatformEnableInventory = 0x19BAEE1AD90; // Unknown = 
        public const ulong FFlagProfilePlatformEnableInventory_V2 = 0x19B8C2EA250; // Unknown = 
        public const ulong FFlagProfilePlatformEnableLazyLoadingComponents = 0x19BB7F4A550; // Unknown = 
        public const ulong FFlagProfilePlatformEnableLazyLoadingComponentsV5 = 0x19B859CB2DD; // Bool = false
        public const ulong FFlagProfilePlatformEnableMoments = 0x19B859CB7D0; // Unknown = 
        public const ulong FFlagProfilePlatformEnableSchoolChip = 0x19B8C2EB190; // Unknown = 
        public const ulong FFlagProfilePlatformEnableStore = 0x19BAEE13B1D; // Bool = false
        public const ulong FFlagProfilePlatformEnableStore_V2 = 0x19B8C2E9FD0; // Unknown = 
        public const ulong FFlagProfilePlatformEnableTradeItems = 0x19B859CBE9D; // Bool = false
        public const ulong FFlagProfilePlatformEnableUnlockChat_V2 = 0x19B825F27FD; // Bool = true
        public const ulong FFlagProfilePlatformEnableVR = 0x19BBBFF5EA5; // Bool = true
        public const ulong FFlagProfilePlatformEnableVR_v2 = 0x19BBBFF5E2D; // Bool = false
        public const ulong FFlagProfilePlatformFavoritesEnableGameDetailAnalytics = 0x19BACFD2B50; // Unknown = 
        public const ulong FFlagProfilePlatformFixPresenceReducer = 0x19B859CB610; // Unknown = 
        public const ulong FFlagProfilePlatformImproveGameDetailsAnalytics = 0x19BACFD3550; // Unknown = 
        public const ulong FFlagProfilePlatformMeTabMobileProfileHero = 0x19D812E7108; // Unknown = 
        public const ulong FFlagProfilePlatformNewAboutSection_v9 = 0x19B825F51D0; // Unknown = 
        public const ulong FFlagProfilePlatformNewProfileHeader = 0x19BAEE12AD0; // Unknown = 
        public const ulong FFlagProfilePlatformNewProfileHeader_v4 = 0x19B8C2EBFD0; // Unknown = 
        public const ulong FFlagProfilePlatformPassPresenceToJoinUserInExperience = 0x19B8C2EC190; // Unknown = 
        public const ulong FFlagProfilePlatformPeekDraggerContrast = 0x19B8C2EB7D0; // Unknown = 
        public const ulong FFlagProfilePlatformPresenceStoreMigration = 0x19BB7F4F810; // Unknown = 
        public const ulong FFlagProfilePlatformPresenceStoreMigration_v1 = 0x19B859CB09D; // Bool = false
        public const ulong FFlagProfilePlatformTrustedConnectionsMVP = 0x19B8C2EBD90; // Unknown = 
        public const ulong FFlagProfilePlatformUseCatalogItemOpenedNewFields = 0x19BB7F41990; // Unknown = 
        public const ulong FFlagProfilePlatformUseNewLayoutForAssetsCarousel = 0x19D80F5AAF5; // Bool = false
        public const ulong FFlagProfilePlatformUseProfileTypeContext = 0x19B9029171D; // Bool = true
        public const ulong FFlagProfilePlatformUseRoduxNetworkingRefactor = 0x19B859CC05D; // Bool = false
        public const ulong FFlagProfileQRCodeFixFocusNavigation = 0x19BAFCF67D0; // Unknown = 
        public const ulong FFlagProfileQrCodeDeprecateUserRedux = 0x19BAFCF9990; // Unknown = 
        public const ulong FFlagPromptBannerWaitInSmallIntervals = 0x19B9481045D; // Bool = false
        public const ulong FFlagPromptCreatorTransientDialog = 0x19BA6076FDD; // Bool = true
        public const ulong FFlagPromptFriendRequestModalRevampFriendsRename = 0x19BA6077D10; // Unknown = 
        public const ulong FFlagPromptPurchaseClearStateOnCompletion = 0x19D85DC65D0; // Unknown = 
        public const ulong FFlagPromptsHandlerCoachmarkEnabled = 0x19BC0544BD0; // Unknown = 
        public const ulong FFlagPromptsHandlerEnabled = 0x19BC0548CD0; // Unknown = 
        public const ulong FFlagPromptsHandlerEnabled2 = 0x19BC0543790; // Unknown = 
        public const ulong FFlagPromptsImpressionUsesTitle = 0x19BC0548350; // Unknown = 
        public const ulong FFlagPurchaseModalTimedOptionExtension = 0x19B9AF1C550; // Unknown = 
        public const ulong FFlagPurchasePromptAppConditionalFocusNavigation = 0x19B9EE0299D; // Bool = false
        public const ulong FFlagPurchasePromptAppFixStyleLink = 0x19B9EE02C5D; // Bool = false
        public const ulong FFlagPurchasePromptAppTrackRenderPerformance = 0x19B9EE02B1D; // Bool = false
        public const ulong FFlagPurchasePromptCartPricingEnabled = 0x19D85DCEC90; // Unknown = 
        public const ulong FFlagPurchasePromptCartPricingRequireOffer2 = 0x19B8F906D9D; // Bool = false
        public const ulong FFlagPurchasePromptCartPricingSkipFreeItems2 = 0x19B9F18D03D; // Bool = true
        public const ulong FFlagPurchasePromptCartPricingSkipLimitedCollectibles = 0x19D80F1C128; // Unknown = 
        public const ulong FFlagPurchasePromptCartPricingSkipLimitedCollectibles2 = 0x19B8F906C5D; // Bool = false
        public const ulong FFlagPurchasePromptElevateDisplayOrder = 0x19B9EE0301D; // Bool = false
        public const ulong FFlagPurchasePromptFetchCartPricing = 0x19B9AF1F310; // Unknown = 
        public const ulong FFlagPurchasePromptFetchCartPricing2 = 0x19B9AF1F290; // Unknown = 
        public const ulong FFlagPurchasePromptFetchCartPricingForLooks = 0x19B9AF1DAD0; // Unknown = 
        public const ulong FFlagPurchasePromptFetchCartPricingForLooks2 = 0x19B9AF1D710; // Unknown = 
        public const ulong FFlagPurchasePromptFixOfferMarginUpsell = 0x19B9AF1D810; // Unknown = 
        public const ulong FFlagPurchasePromptOfferMarginUpsellEnabled = 0x19D85DC8EDD; // Bool = false
        public const ulong FFlagPurchasePromptPreviewMakeupHead = 0x19BACE7E4DD; // Bool = false
        public const ulong FFlagPurchasePromptPriceShouldUseProductInfoPrice = 0x19D85DC5150; // Unknown = 
        public const ulong FFlagPurchasePromptPriceShouldUseProductInfoPrice4 = 0x19D85DCC7D0; // Unknown = 
        public const ulong FFlagPurchasePromptSubtitleForTimedOptions = 0x19B9AF1CD10; // Unknown = 
        public const ulong FFlagPurchasePromptSubtitleForTimedOptions2 = 0x19B9AF1CB90; // Unknown = 
        public const ulong FFlagPurchasePromptUnifiedEventsUseOfferAdjustedPrice = 0x19B9AF1E150; // Unknown = 
        public const ulong FFlagPymkCarouselPresenceStoreMigration_v2 = 0x19B8FC3A150; // Unknown = 
        public const ulong FFlagQRCodeCopyUpdates_v2 = 0x19B8C30301D; // Bool = true
        public const ulong FFlagQRCodeFriendRequestNotificationV2 = 0x19BAFCF4BD0; // Unknown = 
        public const ulong FFlagQRCodeItemRedemptionEnabled = 0x19B9026FAD0; // Unknown = 
        public const ulong FFlagQRCodeScannerDeeplinkEnabledForAll = 0x19BACFDF410; // Unknown = 
        public const ulong FFlagQRInSearchProfileQR = 0x19BA8447550; // Unknown = 
        public const ulong FFlagQRInSearchScanner = 0x19BBB794ABD; // Bool = false
        public const ulong FFlagRAEnableCircleRegion = 0x19BA6A3D9D0; // Unknown = 
        public const ulong FFlagRAKickLogic2 = 0x19BA672D75D; // Bool = false
        public const ulong FFlagRateLimitNudgeDialog = 0x19BACE787DD; // Bool = false
        public const ulong FFlagRateLimitNudgeToast = 0x19BACE786DD; // Bool = false
        public const ulong FFlagRateLimitTimeoutDialog = 0x19BACE7885D; // Bool = false
        public const ulong FFlagRateLimitTimeoutToast = 0x19BACE7875D; // Bool = false
        public const ulong FFlagReactCatchYieldingInDEV = 0x19BA5538A90; // Unknown = 
        public const ulong FFlagReactCleanQueueOnUpdateBailout = 0x19B90295490; // Unknown = 
        public const ulong FFlagReactDevtoolsFixTopbar = 0x19BACFED19D; // Bool = false
        public const ulong FFlagReactEnableNewTreeCleanupPath = 0x19BA55347D0; // Unknown = 
        public const ulong FFlagReactEnableSchedulingProfiler = 0x19BA5535FD0; // Unknown = 
        public const ulong FFlagReactFilterInternalStackFrames = 0x19BA553E410; // Unknown = 
        public const ulong FFlagReactFixBindingMemoryLeak = 0x19BA553345D; // Bool = true
        public const ulong FFlagReactInlineMergeLanes = 0x19BA5537E9D; // Bool = true
        public const ulong FFlagReactInstanceMapDisableErrorChecking = 0x19BA5533990; // Unknown = 
        public const ulong FFlagReactIsProtectedTypeOf = 0x19B9CB7A85D; // Bool = false
        public const ulong FFlagReactIsolatedGlobalsEnabled = 0x19B9F184FBD; // Bool = true
        public const ulong FFlagReactPreventAssigningKeyToChildren = 0x19B90295310; // Unknown = 
        public const ulong FFlagReactSchedulerEnableDeferredWork = 0x19BA553B09D; // Bool = false
        public const ulong FFlagReactSchedulerLookbackUseRingBuffer = 0x19BA553211D; // Bool = true
        public const ulong FFlagReactSchedulerSetFrameMarkerOnHeartbeatEnd = 0x19BA5538250; // Unknown = 
        public const ulong FFlagReactSchedulerSetTargetMsByHeartbeatDelta = 0x19BA5532A9D; // Bool = false
        public const ulong FFlagReactSchedulingTrackerDataModelUpdate = 0x19BBCCCC2DD; // Bool = false
        public const ulong FFlagReactSchedulingTrackerLayoutEffects = 0x19BBC7A9D50; // Unknown = 
        public const ulong FFlagReactTelemetryEnabled = 0x19B9ACB399D; // Bool = true
        public const ulong FFlagReadAppChatFetchingVariable = 0x19BACFD4A50; // Unknown = 
        public const ulong FFlagRealNamesInDisplayNamesEnabledForAll = 0x19B90642090; // Unknown = 
        public const ulong FFlagReducePromiseTaskDefer = 0x19B8C2E5590; // Unknown = 
        public const ulong FFlagReduceTopBarInsetsWhileHidden = 0x19B9ACB9190; // Unknown = 
        public const ulong FFlagRefactorButtonTileCircular = 0x19BACFDED10; // Unknown = 
        public const ulong FFlagRefactorHelpPage = 0x19BBF252F9D; // Bool = false
        public const ulong FFlagRefactorHelpPage5 = 0x19BAC87309D; // Bool = false
        public const ulong FFlagRefactorInExpSettingsInDevelopment = 0x19BACE9C21D; // Bool = false
        public const ulong FFlagRefactorMenuConfirmationButtons = 0x19B9FDDAF15; // Bool = false
        public const ulong FFlagRefactorMenuConfirmationButtons5 = 0x19BA515B61D; // Bool = false
        public const ulong FFlagRefactorPeoplePage = 0x19B9FDDAF95; // Bool = false
        public const ulong FFlagRefactorPeoplePage9 = 0x19B8EDBA13D; // Bool = false
        public const ulong FFlagRefactorReconnectUnblockTeleport = 0x19BA672C51D; // Bool = false
        public const ulong FFlagRefreshAuthSessionAfterLanguageChange = 0x19B9ACBA1D0; // Unknown = 
        public const ulong FFlagRefreshDevSubPriceOnRetryAfterUpsell2 = 0x19D85DC49D0; // Unknown = 
        public const ulong FFlagRefreshLookPriceOnRetryAfterUpsell = 0x19D85DC0C9D; // Bool = false
        public const ulong FFlagRefreshPriceOnRetryAfterUpsell = 0x19D85DC6310; // Unknown = 
        public const ulong FFlagRegisterQRCodeKeyInEngine = 0x19BACFD2010; // Unknown = 
        public const ulong FFlagRegisterQRCodeKeyInEngine_v2 = 0x19BACFD96DD; // Bool = true
        public const ulong FFlagRelocateMobileMenuButtons = 0x19B9FDDAFD5; // Bool = false
        public const ulong FFlagRelocateMobileMenuButtons4 = 0x19BA515A9D0; // Unknown = 
        public const ulong FFlagReminderAPIFetchErrorLogging = 0x19B948125DD; // Bool = false
        public const ulong FFlagRemoveAcountInfoFetchFromPurchase = 0x19D85DB6280; // Unknown = 
        public const ulong FFlagRemoveAssetVersionEndpoint = 0x19BACE9C8DD; // Bool = false
        public const ulong FFlagRemoveAvatarSwitcherIfUnsupported = 0x19B88C4E110; // Unknown = 
        public const ulong FFlagRemoveBottomNavOnLookDetails = 0x19B9AF15250; // Unknown = 
        public const ulong FFlagRemoveCentralOverlayBackgroundSafeArea = 0x19B9064999D; // Bool = false
        public const ulong FFlagRemoveCentralOverlayScrimForUnifiedPurchaseModal = 0x19B9ACB1150; // Unknown = 
        public const ulong FFlagRemoveClassicHeadsAndFaces = 0x19BA3A5C4DD; // Bool = false
        public const ulong FFlagRemoveDataLoaderTimer = 0x19B8C2E9CD0; // Unknown = 
        public const ulong FFlagRemoveDelayedInputForUnifiedPurchaseModal = 0x19B9EE00D9D; // Bool = false
        public const ulong FFlagRemoveDiscoverabilityModal = 0x19B90294E90; // Unknown = 
        public const ulong FFlagRemoveExitModal = 0x19B9FDDB015; // Bool = false
        public const ulong FFlagRemoveFetchFriendsCarouselAtStartup = 0x19B90267090; // Unknown = 
        public const ulong FFlagRemoveFriendsChatUnibarEntrypoints = 0x19B8C2E2B5D; // Bool = false
        public const ulong FFlagRemoveHardCodedFriendLimitPrompt = 0x19BACFEA510; // Unknown = 
        public const ulong FFlagRemoveHttpErrorLog2 = 0x19B90292AD0; // Unknown = 
        public const ulong FFlagRemoveKeystoreIxpLogic = 0x19B9ACB4810; // Unknown = 
        public const ulong FFlagRemoveLeaveShortcutFromLeaveConfirm = 0x19BA7FCB848; // Unknown = 
        public const ulong FFlagRemoveLoadingTimeout = 0x19BBC38A2D5; // Bool = false
        public const ulong FFlagRemoveLoggingHookForCorescriptGlobalEffects2 = 0x19B9F921B50; // Unknown = 
        public const ulong FFlagRemoveMobileHomeProfileHeader_v2 = 0x19B94811590; // Unknown = 
        public const ulong FFlagRemoveNameRegex = 0x19B9EE0321D; // Bool = false
        public const ulong FFlagRemoveNewPlayerListOverlay = 0x19BACE96C9D; // Bool = false
        public const ulong FFlagRemovePeekViewScrimBorder = 0x19BBC7A3490; // Unknown = 
        public const ulong FFlagRemovePhoneUpsellWebview = 0x19B90294E10; // Unknown = 
        public const ulong FFlagRemoveRecordPage = 0x19BACE9C3DD; // Bool = false
        public const ulong FFlagRemoveRefToMissingLocInConnection = 0x19BBC38AF50; // Unknown = 
        public const ulong FFlagRemoveRespawnShortcutFromRespawnConfirmation = 0x19BA7FC4F48; // Unknown = 
        public const ulong FFlagRemoveUnusedConnectionStateRoduxSlice = 0x19B9AF190D0; // Unknown = 
        public const ulong FFlagRemoveUnusedFriendStatusesRoduxSlice = 0x19B9AF19210; // Unknown = 
        public const ulong FFlagRemoveUnusedGameThumbnailsRoduxSlice = 0x19B9AF18110; // Unknown = 
        public const ulong FFlagRemoveUnusedLoginResultRoduxSlice = 0x19B9AF18390; // Unknown = 
        public const ulong FFlagRemoveUnusedRoactChatRoduxSlice = 0x19B8C2E2390; // Unknown = 
        public const ulong FFlagRemoveUnusedSignUpInfoRoduxSlice = 0x19B9AF18CD0; // Unknown = 
        public const ulong FFlagRemoveUnusedUserStatusesRoduxSlice = 0x19B9AF18550; // Unknown = 
        public const ulong FFlagRemoveUnusedUsersAsyncRoduxSlice = 0x19B9AF18750; // Unknown = 
        public const ulong FFlagRemoveVirtualEventsExperiment = 0x19B857882D0; // Unknown = 
        public const ulong FFlagRenameAvatarToMe = 0x19B9AF14F90; // Unknown = 
        public const ulong FFlagRenameDeprecatedUIBloxTokens3 = 0x19B85788690; // Unknown = 
        public const ulong FFlagRenameParentEmailForVerificationUpsell = 0x19B8C30B7DD; // Bool = true
        public const ulong FFlagRenameRespawnConfirmationPage = 0x19BBCD7165D; // Bool = false
        public const ulong FFlagRenameVolumeToMainVolume = 0x19B9FD8BE95; // Bool = false
        public const ulong FFlagRenderChatConversationOnlyWhenVisible = 0x19BACE7F090; // Unknown = 
        public const ulong FFlagRenderChatConversationOnlyWhenVisible3 = 0x19BACE7BE50; // Unknown = 
        public const ulong FFlagRenderPeoplePageOnTabSwitch = 0x19BB7F4B71D; // Bool = false
        public const ulong FFlagRenderUseTextureManager224 = 0x19B9B16003D; // Bool = false
        public const ulong FFlagReplaceChatLineReportingIcon = 0x19BA5153EDD; // Bool = false
        public const ulong FFlagReplaceMissingDesignTokens = 0x19B945A0455; // Bool = false
        public const ulong FFlagReplaceNavbarIconsWithFoundation = 0x19B9AF13F90; // Unknown = 
        public const ulong FFlagReplacePlayerIconRoduxWithSignal_2 = 0x19B88C4FCDD; // Bool = false
        public const ulong FFlagReportAbuseMenuEntrypointAnalytics = 0x19BACE9CF1D; // Bool = false
        public const ulong FFlagReportAnythingAnnotationIXP = 0x19B8C30B29D; // Bool = true
        public const ulong FFlagReportAnythingDebugCanvas = 0x19D81681850; // Unknown = 
        public const ulong FFlagReportAnythingEnableAdReport = 0x19BA6A32E90; // Unknown = 
        public const ulong FFlagReportAnythingFixConvexHullCalculation = 0x19BAC87FEDD; // Bool = false
        public const ulong FFlagReportAnythingLocalizationEnabled = 0x19D8168E5D0; // Unknown = 
        public const ulong FFlagReportAnythingMultistepScreenshot = 0x19D81683490; // Unknown = 
        public const ulong FFlagReportAnythingScreenshot = 0x19D81683C50; // Unknown = 
        public const ulong FFlagReportFirstExperienceCancelled = 0x19BA6728D1D; // Bool = false
        public const ulong FFlagReportFocusNavIEMButtons = 0x19B9FD8F895; // Bool = false
        public const ulong FFlagReportFocusNavIEMButtons2 = 0x19BBB7FA390; // Unknown = 
        public const ulong FFlagReportListRadioSelectable = 0x19BB7F4FE50; // Unknown = 
        public const ulong FFlagReportNotificationStreamCTA = 0x19B94810610; // Unknown = 
        public const ulong FFlagRepositionDropDownScrim = 0x19BA515B75D; // Bool = false
        public const ulong FFlagRepositionInExperienceVRToasts = 0x19BA67212DD; // Bool = false
        public const ulong FFlagRespawnActionChromeShortcutTelemetry = 0x19B9FD87495; // Bool = false
        public const ulong FFlagRespawnChromeShortcutTelemetry = 0x19BA7FC9FE8; // Unknown = 
        public const ulong FFlagRespectBalanceInfoForBundleUpsellInStudio = 0x19D85DC7090; // Unknown = 
        public const ulong FFlagResponsiveUnitsProfileHeader = 0x19BB7F4B790; // Unknown = 
        public const ulong FFlagRetryAfterUpsellV2 = 0x19D85DC3890; // Unknown = 
        public const ulong FFlagReworkPurchaseRobuxPage = 0x19B906437D0; // Unknown = 
        public const ulong FFlagRoactPolicyLoggerName = 0x19BB6BB2C1D; // Bool = false
        public const ulong FFlagRobloxExperienceKickOverride = 0x19BBC38AD50; // Unknown = 
        public const ulong FFlagRobloxPlusAmpSubscriptionCheck = 0x19B8FC33E5D; // Bool = false
        public const ulong FFlagRobloxPlusFAEFreeTrial = 0x19BC054DADD; // Bool = true
        public const ulong FFlagRobloxPlusUpdateDiscountIcons = 0x19B9F18196D; // Bool = true
        public const ulong FFlagRobloxPlusUpsellRefreshOnComplete = 0x19BC05455DD; // Bool = true
        public const ulong FFlagRobuxBadgeEnabled = 0x19B9026911D; // Bool = false
        public const ulong FFlagRobuxIconColorHotfix = 0x19B94810950; // Unknown = 
        public const ulong FFlagRoduxRemoveConnectTraceback = 0x19BA6C40C50; // Unknown = 
        public const ulong FFlagRoduxSignalsNavigationMigration2 = 0x19B85785BDD; // Bool = false
        public const ulong FFlagRoutePremiumToBlackbirdUpsell = 0x19D85DC9AD0; // Unknown = 
        public const ulong FFlagSAToolEquipLuauFlag = 0x19BA6078BD0; // Unknown = 
        public const ulong FFlagScopeBadUtterancePlayerNameToChatDialogs = 0x19BA80287D0; // Unknown = 
        public const ulong FFlagScopedSubscribersForPermissionsProtocol2 = 0x19BB6BBC4D0; // Unknown = 
        public const ulong FFlagScriptProfilerShowPlugins2 = 0x19BACFE445D; // Bool = false
        public const ulong FFlagSduiActionSequence = 0x19B88C2121D; // Bool = false
        public const ulong FFlagSduiActionSkipUnifiedLogging = 0x19B9F189CF5; // Bool = true
        public const ulong FFlagSduiActionTelemetryHandler2 = 0x19B9F1897FD; // Bool = true
        public const ulong FFlagSduiActionsUpdateFiresOwnTelemetry = 0x19B88C2995D; // Bool = false
        public const ulong FFlagSduiAddMarketplaceEntityDataHydration = 0x19B88C20E9D; // Bool = false
        public const ulong FFlagSduiAgeCheckUpsellRaisePeekViewBriefHeight = 0x19BC054689D; // Bool = true
        public const ulong FFlagSduiAiOverviewEnabled = 0x19B88C23E10; // Unknown = 
        public const ulong FFlagSduiAllowNoConfigsBuilt = 0x19BC054FB5D; // Bool = true
        public const ulong FFlagSduiAlwaysCacheWithIdentifier = 0x19BBB316AD0; // Unknown = 
        public const ulong FFlagSduiAlwaysCacheWithIdentifier3 = 0x19B8C30F190; // Unknown = 
        public const ulong FFlagSduiApiStoreExposeGetInputData = 0x19BA5531690; // Unknown = 
        public const ulong FFlagSduiApiStoreOnSuccessAndRefresh = 0x19BA5533C10; // Unknown = 
        public const ulong FFlagSduiAppPolicyBindings = 0x19B8C30FB9D; // Bool = true
        public const ulong FFlagSduiArrayMapSupport = 0x19B945A3D50; // Unknown = 
        public const ulong FFlagSduiBadgeComponent = 0x19B9011EC10; // Unknown = 
        public const ulong FFlagSduiCapabilityBindings2 = 0x19B8C30FC1D; // Bool = true
        public const ulong FFlagSduiCapabilityDevStoreSeeAllWebviewFallback = 0x19B8C30FD1D; // Bool = true
        public const ulong FFlagSduiCardComponent = 0x19BBB31F290; // Unknown = 
        public const ulong FFlagSduiCardComponent_v3 = 0x19B88C26D1D; // Bool = true
        public const ulong FFlagSduiCarouselUseNestedImpressionsFeedContext = 0x19B88C23410; // Unknown = 
        public const ulong FFlagSduiCatalogCategoryMenu = 0x19B88C26550; // Unknown = 
        public const ulong FFlagSduiCatalogItemGrid = 0x19B88C20B9D; // Bool = false
        public const ulong FFlagSduiCatalogVirtualizedFeed = 0x19BBB31EA50; // Unknown = 
        public const ulong FFlagSduiCatalogVirtualizedFeed4 = 0x19B88C26790; // Unknown = 
        public const ulong FFlagSduiChartsAnalyticsPage = 0x19B90293290; // Unknown = 
        public const ulong FFlagSduiChartsDedupSessionRotation = 0x19B88C28D5D; // Bool = false
        public const ulong FFlagSduiChartsPlaceholderMergeStrategySupport = 0x19BA553BB90; // Unknown = 
        public const ulong FFlagSduiChartsPostBody = 0x19B88C28E5D; // Bool = false
        public const ulong FFlagSduiChartsRequestPlaceholders = 0x19B9F181BE5; // Bool = true
        public const ulong FFlagSduiChartsResetSessionOnRefresh = 0x19B88C28C1D; // Bool = false
        public const ulong FFlagSduiChartsSortDetailGenreFilter = 0x19B88C2899D; // Bool = false
        public const ulong FFlagSduiChartsSupport2 = 0x19BA5535D50; // Unknown = 
        public const ulong FFlagSduiChipAccessoryProps = 0x19B85789AD0; // Unknown = 
        public const ulong FFlagSduiClientPageScope2 = 0x19BA5539C50; // Unknown = 
        public const ulong FFlagSduiClientTemplateCache = 0x19B8578719D; // Bool = false
        public const ulong FFlagSduiCoachmarkComponent = 0x19B906417DD; // Bool = false
        public const ulong FFlagSduiCollectionCarouselOverrides = 0x19B88C2941D; // Bool = false
        public const ulong FFlagSduiCollectionCarouselPlaceholderItem = 0x19B88C2925D; // Bool = false
        public const ulong FFlagSduiCollectionGridMaxNumRows = 0x19B8C30F61D; // Bool = true
        public const ulong FFlagSduiCommunitySectionSupport = 0x19B8C30E210; // Unknown = 
        public const ulong FFlagSduiConfigFetchTakesPostBody = 0x19B8578709D; // Bool = false
        public const ulong FFlagSduiCreateSocialTelemetryRegistries = 0x19B90641B5D; // Bool = false
        public const ulong FFlagSduiDataBindingShallowEquals = 0x19B8FC32B10; // Unknown = 
        public const ulong FFlagSduiDeferredListItems2 = 0x19B8C30F45D; // Bool = true
        public const ulong FFlagSduiDevStoreSeeAllImpressionsLogging = 0x19B88C29F5D; // Bool = false
        public const ulong FFlagSduiDevStoreSeeAllSupportDev2 = 0x19BC054B990; // Unknown = 
        public const ulong FFlagSduiDismissPromptAction = 0x19B8578545D; // Bool = false
        public const ulong FFlagSduiDividerThemeAwareStroke = 0x19B88C26210; // Unknown = 
        public const ulong FFlagSduiEdpClientTemplateCache = 0x19B8578721D; // Bool = false
        public const ulong FFlagSduiEdpInheritGameDetailSourceSession = 0x19B8C30F25D; // Bool = true
        public const ulong FFlagSduiEdpPageScopeIsTenFoot = 0x19B9026281D; // Bool = false
        public const ulong FFlagSduiEdpPersistentActionBarPlayButton = 0x19B9F18627D; // Bool = true
        public const ulong FFlagSduiEdpPersistentActionBarPlayButton2 = 0x19B9F182D3D; // Bool = true
        public const ulong FFlagSduiEdpPrefetchPlayability = 0x19BC0545610; // Unknown = 
        public const ulong FFlagSduiEdpStoreImpressionsLogging = 0x19B88C29D9D; // Bool = false
        public const ulong FFlagSduiEnableAssociatedItemsRow = 0x19B88C26C1D; // Bool = true
        public const ulong FFlagSduiEnableBackToTop = 0x19B9064145D; // Bool = false
        public const ulong FFlagSduiEnableClearOnEmptyResponse = 0x19B8FC32410; // Unknown = 
        public const ulong FFlagSduiEnableHeroUnitBottomRow = 0x19B9011F890; // Unknown = 
        public const ulong FFlagSduiErrorCleanup = 0x19B8C30F4DD; // Bool = true
        public const ulong FFlagSduiEventDetailsSupport = 0x19B8C30F55D; // Bool = true
        public const ulong FFlagSduiEventRsvpFacePile = 0x19B8C30FE1D; // Bool = true
        public const ulong FFlagSduiExperienceDetailsSocialProof = 0x19BA74E9210; // Unknown = 
        public const ulong FFlagSduiExperienceDetailsSocialProof_3 = 0x19B8578A010; // Unknown = 
        public const ulong FFlagSduiExperienceDetailsSupport = 0x19BA553C410; // Unknown = 
        public const ulong FFlagSduiFavoritesHydrationStructured = 0x19BA553F0D0; // Unknown = 
        public const ulong FFlagSduiFeatureEntryPointTakesAbsoluteSizeHandler = 0x19B85780AD0; // Unknown = 
        public const ulong FFlagSduiFeedDebugNameWithImpressionsTag = 0x19B90640190; // Unknown = 
        public const ulong FFlagSduiFeedIndexInExtraLocalProps = 0x19B906407D0; // Unknown = 
        public const ulong FFlagSduiFixEmptyRobloxComponentInPropBuilder = 0x19B8C30F8DD; // Bool = true
        public const ulong FFlagSduiFocusNavActionsStructured = 0x19B88C21BDD; // Bool = false
        public const ulong FFlagSduiFormatArgFormatters3 = 0x19B88C20790; // Unknown = 
        public const ulong FFlagSduiGameIconSupport = 0x19BA553D310; // Unknown = 
        public const ulong FFlagSduiGameItemsComponent = 0x19BC0547510; // Unknown = 
        public const ulong FFlagSduiGenericContainerDispatch = 0x19B8578525D; // Bool = false
        public const ulong FFlagSduiGetItemCollectionKeys = 0x19B88C26B5D; // Bool = true
        public const ulong FFlagSduiGlobalRegistryFallback = 0x19B8578535D; // Bool = false
        public const ulong FFlagSduiHydrationClientHints = 0x19B85780C90; // Unknown = 
        public const ulong FFlagSduiHydrationDataCamelCasePropertyKeys = 0x19B85780DD0; // Unknown = 
        public const ulong FFlagSduiHydrationDataCamelCaseTopLevelKeys = 0x19B8C30FDD0; // Unknown = 
        public const ulong FFlagSduiHydrationFetchIfMissing = 0x19BA5538C90; // Unknown = 
        public const ulong FFlagSduiImprovedErrorDimensions = 0x19B88C201D0; // Unknown = 
        public const ulong FFlagSduiInlineNestedComponentSchema2 = 0x19BA553FB10; // Unknown = 
        public const ulong FFlagSduiInputDataMergeStrategy = 0x19BA55334D0; // Unknown = 
        public const ulong FFlagSduiInputDataMergeStrategy2 = 0x19BA5538D10; // Unknown = 
        public const ulong FFlagSduiIsEmptyConditions = 0x19BA5536550; // Unknown = 
        public const ulong FFlagSduiLaunchExperienceAction = 0x19BA5536790; // Unknown = 
        public const ulong FFlagSduiLazyNestedComponentArrayMapItemResolutionSupport = 0x19B8C30F79D; // Bool = true
        public const ulong FFlagSduiLazyNestedComponentProp = 0x19BA5531210; // Unknown = 
        public const ulong FFlagSduiLinkActionSharedWebLink = 0x19B8C30F810; // Unknown = 
        public const ulong FFlagSduiMarketplaceCatalogActions4 = 0x19B88C20CDD; // Bool = false
        public const ulong FFlagSduiMarketplaceCatalogCategorySupport2 = 0x19B88C207DD; // Bool = false
        public const ulong FFlagSduiMarketplaceCatalogSortSupport6 = 0x19B88C20A1D; // Bool = false
        public const ulong FFlagSduiNestedComponentListProp = 0x19B88C20390; // Unknown = 
        public const ulong FFlagSduiNilHydrationGuard = 0x19BA5530650; // Unknown = 
        public const ulong FFlagSduiOneofPropSupport = 0x19B88C21B1D; // Bool = false
        public const ulong FFlagSduiOpenIncomingTransferUpsellAction = 0x19B9AF12750; // Unknown = 
        public const ulong FFlagSduiOpenSearchResultsTabAction = 0x19B88C2421D; // Bool = false
        public const ulong FFlagSduiOptionImpressionsEventName = 0x19BB1D92110; // Unknown = 
        public const ulong FFlagSduiOptionSelectorCollection = 0x19BB1D986D0; // Unknown = 
        public const ulong FFlagSduiOptionalUniverseHydration = 0x19BA5533890; // Unknown = 
        public const ulong FFlagSduiOrderedTemplateDataSupport = 0x19B8C30FA9D; // Bool = true
        public const ulong FFlagSduiPageEntryPointResolvedSlot = 0x19BA5531990; // Unknown = 
        public const ulong FFlagSduiPageEntrySurfacing = 0x19BC054631D; // Bool = true
        public const ulong FFlagSduiPageEntryUseSharedHooks = 0x19B85781B10; // Unknown = 
        public const ulong FFlagSduiPaginatePostBody = 0x19B8578729D; // Bool = false
        public const ulong FFlagSduiPinShortcutAction = 0x19B9AF12690; // Unknown = 
        public const ulong FFlagSduiPlayWithReward = 0x19B88C20350; // Unknown = 
        public const ulong FFlagSduiPlayWithRewardGapFix = 0x19B88C2109D; // Bool = false
        public const ulong FFlagSduiPoolBackedFeed = 0x19BB1D97C90; // Unknown = 
        public const ulong FFlagSduiPromptImpressions = 0x19B88C2111D; // Bool = false
        public const ulong FFlagSduiPropBuilderSupportNilHydration = 0x19B945A2FD0; // Unknown = 
        public const ulong FFlagSduiPropParsersShouldHandleTokens = 0x19B88C2045D; // Bool = false
        public const ulong FFlagSduiProtobufJsonDecode = 0x19B88C25D9D; // Bool = true
        public const ulong FFlagSduiQueryImpressionsLogging = 0x19B9F1845ED; // Bool = true
        public const ulong FFlagSduiRegisterSocialActions = 0x19B88C2119D; // Bool = false
        public const ulong FFlagSduiRenderPerf = 0x19B88C20150; // Unknown = 
        public const ulong FFlagSduiRequestFriendshipAction4 = 0x19B88C247DD; // Bool = true
        public const ulong FFlagSduiRequestFriendshipActionHandler = 0x19B88C24C5D; // Bool = false
        public const ulong FFlagSduiRevealTextComponentEnabled = 0x19BC05473D0; // Unknown = 
        public const ulong FFlagSduiScalePlayButtonAndImageSizes = 0x19B8C30FF5D; // Bool = true
        public const ulong FFlagSduiSearchPeoplePlayerTileTelemetry = 0x19B9F18889D; // Bool = true
        public const ulong FFlagSduiSearchResultsPageEnabled = 0x19BA553B6D0; // Unknown = 
        public const ulong FFlagSduiShimmerTextComponentEnabled = 0x19BC05434D0; // Unknown = 
        public const ulong FFlagSduiShowToastAction_v2 = 0x19BC054F01D; // Bool = true
        public const ulong FFlagSduiSocialDataMigrateOffLegacyPresence = 0x19B88C24610; // Unknown = 
        public const ulong FFlagSduiSrpScrollAway = 0x19B9AF13E90; // Unknown = 
        public const ulong FFlagSduiSrpShowNavOnNewSearch = 0x19B9AF13E10; // Unknown = 
        public const ulong FFlagSduiStickyHeaderDividerLayoutOrderConstant = 0x19B9064109D; // Bool = false
        public const ulong FFlagSduiStringPropToString = 0x19B85780C10; // Unknown = 
        public const ulong FFlagSduiSubscriptionCellPostPurchaseSync = 0x19B9AF17450; // Unknown = 
        public const ulong FFlagSduiSupportRatingNoPercent = 0x19BC054A910; // Unknown = 
        public const ulong FFlagSduiSurfaceBannerAlwaysMounted = 0x19BC0546A50; // Unknown = 
        public const ulong FFlagSduiSurfaceBannerScrollAwaySticky = 0x19BC0546F10; // Unknown = 
        public const ulong FFlagSduiSystemBannerComponent = 0x19BC054DA10; // Unknown = 
        public const ulong FFlagSduiTileBottomButton = 0x19BC0541A10; // Unknown = 
        public const ulong FFlagSduiTileDisableLegacyHover = 0x19B9011FAD0; // Unknown = 
        public const ulong FFlagSduiTileHoldAction = 0x19BC05425D0; // Unknown = 
        public const ulong FFlagSduiTileImagePaddingInset = 0x19BC0547CD0; // Unknown = 
        public const ulong FFlagSduiTileThumbnailPadding = 0x19BC0540790; // Unknown = 
        public const ulong FFlagSduiTileTitleTextAlignment = 0x19BA553CC90; // Unknown = 
        public const ulong FFlagSduiTooltipComponentEnabled = 0x19BC0540750; // Unknown = 
        public const ulong FFlagSduiUniversalPageEntry = 0x19B8C30F71D; // Bool = true
        public const ulong FFlagSduiUnwrapStructPropEnvelope = 0x19B88C2061D; // Bool = false
        public const ulong FFlagSduiUsageTelemetry = 0x19B8C30F3DD; // Bool = true
        public const ulong FFlagSduiUseInputData = 0x19BA553EED0; // Unknown = 
        public const ulong FFlagSduiUseSharedUiStatusHook = 0x19B85780B50; // Unknown = 
        public const ulong FFlagSduiVerticalFeedBottomSpacerLayoutOrderConstant = 0x19B9064155D; // Bool = false
        public const ulong FFlagSduiVerticalListWithImpressionsEnabled = 0x19B88C23390; // Unknown = 
        public const ulong FFlagSduiViewContainerRefEnabled = 0x19B88C23190; // Unknown = 
        public const ulong FFlagSeamlessVoiceConsentToastPolicy = 0x19B8C2E3710; // Unknown = 
        public const ulong FFlagSeamlessVoiceFTUXV2 = 0x19BACFDC110; // Unknown = 
        public const ulong FFlagSeamlessVoiceV2JoinVoiceToast = 0x19BA51583D0; // Unknown = 
        public const ulong FFlagSearchOmniAutocompletePageIXP5 = 0x19B88C4E45D; // Bool = false
        public const ulong FFlagSearchTopResultsTabEnabledForAll = 0x19BACFDBA90; // Unknown = 
        public const ulong FFlagSeedAccountThemeFromDisk = 0x19B9AF17090; // Unknown = 
        public const ulong FFlagSelfViewCameraSettings = 0x19BC0545390; // Unknown = 
        public const ulong FFlagSelfViewNeckCheck = 0x19BACFEC390; // Unknown = 
        public const ulong FFlagSelfViewNewPoseSynchronization = 0x19BACFED690; // Unknown = 
        public const ulong FFlagSelfViewNoApi = 0x19BBCD74C50; // Unknown = 
        public const ulong FFlagSelfViewVisibilityFix = 0x19BC0542ED0; // Unknown = 
        public const ulong FFlagSelfieFrontendConsoleDesktop3 = 0x19B9AF11C90; // Unknown = 
        public const ulong FFlagSendConsentDeniedOnCancel = 0x19B9EE03C1D; // Bool = false
        public const ulong FFlagSendUserConnectionStatus = 0x19BA5158650; // Unknown = 
        public const ulong FFlagSendVoiceCapturedDuringVideoCaptureEvent = 0x19B8FDE9750; // Unknown = 
        public const ulong FFlagSentryIncludeRolloutFlagsContext = 0x19B9F18207D; // Bool = true
        public const ulong FFlagServerTriggeredModalsAccepts2xxImpressionResponses = 0x19B90294910; // Unknown = 
        public const ulong FFlagSessionL2ValidationCountResetFix = 0x19B949F9CE0; // Unknown = 
        public const ulong FFlagSetAliasFixFocusNavigation = 0x19B9011985D; // Bool = false
        public const ulong FFlagSetMenuOnPurchasePrompt = 0x19B9EE00F1D; // Bool = false
        public const ulong FFlagSetMenuOnPurchasePrompt3 = 0x19B9EE00F5D; // Bool = false
        public const ulong FFlagSetRSFNotSelectable = 0x19B94810650; // Unknown = 
        public const ulong FFlagSetUpBubbleChatConfigurationChildProperties = 0x19BBC381EDD; // Bool = false
        public const ulong FFlagSettingsHubIndependentBackgroundVisibility = 0x19BACFD58D0; // Unknown = 
        public const ulong FFlagSettingsHubRaceConditionFix = 0x19B9FD86A9D; // Bool = false
        public const ulong FFlagShareGameSearchBoxFocusAnalytics = 0x19B9F295DDD; // Bool = false
        public const ulong FFlagShareGetPlatformTargetImpl = 0x19BC0543C10; // Unknown = 
        public const ulong FFlagShareSheetTelemetryRefactor = 0x19D7C7CAF50; // Unknown = 
        public const ulong FFlagShareSheetTelemetryRefactor_Dev2 = 0x19D7C7CF450; // Unknown = 
        public const ulong FFlagShareTargetGameCleanup = 0x19BA59BDAD0; // Unknown = 
        public const ulong FFlagShipUnifiedPurchaseFlowToPaidAccess = 0x19B9AF1A290; // Unknown = 
        public const ulong FFlagShipUnifiedPurchaseInExperience = 0x19B9AF1A110; // Unknown = 
        public const ulong FFlagShopProductsUseDisplayName = 0x19BAFCFE9D0; // Unknown = 
        public const ulong FFlagShortcutBarMinSize = 0x19BA6071590; // Unknown = 
        public const ulong FFlagShortcutUseDispatchSyntheticEvent = 0x19BA607D250; // Unknown = 
        public const ulong FFlagShouldApplyDevSubsUpsellFix = 0x19BAC8304DD; // Bool = false
        public const ulong FFlagShouldFixDevSubsFlashingTitle = 0x19BAC83075D; // Bool = false
        public const ulong FFlagShouldMuteUnlocalizedError = 0x19BA672BE90; // Unknown = 
        public const ulong FFlagShowAccountUnlockMismatchDialog = 0x19B8C30EC1D; // Bool = true
        public const ulong FFlagShowAntiHarassmentSettings = 0x19B9FD8B29D; // Bool = false
        public const ulong FFlagShowConfirmationScreenForOOAP2 = 0x19B88C4E99D; // Bool = false
        public const ulong FFlagShowContextMenuWhenButtonsArePresent = 0x19D8168BA10; // Unknown = 
        public const ulong FFlagShowCreatorNameOnEmphasisSearchTileIXP2 = 0x19B9011FEDD; // Bool = false
        public const ulong FFlagShowDOTADogfoodSiteMessage = 0x19B9029F450; // Unknown = 
        public const ulong FFlagShowDevicePermissionsModal3 = 0x19B88C4E7DD; // Bool = false
        public const ulong FFlagShowFAELoadingModalForWebView = 0x19B90112E9D; // Bool = false
        public const ulong FFlagShowGameAgeRating = 0x19B9AF19A50; // Unknown = 
        public const ulong FFlagShowInvoluntarilySignedOutAccounts = 0x19B88C4C410; // Unknown = 
        public const ulong FFlagShowJoinVoiceRaceConditionFix = 0x19BA3662EC8; // Unknown = 
        public const ulong FFlagShowJoinVoiceWhenDisconnectedV3 = 0x19BA5159CDD; // Bool = false
        public const ulong FFlagShowScreentimeLockoutKickMessage = 0x19BA672C11D; // Bool = false
        public const ulong FFlagShowStartupMessageOnUnhide = 0x19B8F908A1D; // Bool = false
        public const ulong FFlagShowSwitchServerButton = 0x19BBC387990; // Unknown = 
        public const ulong FFlagShowSwitchServerButton2 = 0x19BBC384910; // Unknown = 
        public const ulong FFlagShowTeleportHistoryFrontButton = 0x19BAC873CDD; // Bool = false
        public const ulong FFlagShowUnibarOnVirtualCursor = 0x19B9ACB46D0; // Unknown = 
        public const ulong FFlagShrinkAppNavBar = 0x19B9ACB0C50; // Unknown = 
        public const ulong FFlagSideSheetAndroidBack = 0x19BACE9DDDD; // Bool = false
        public const ulong FFlagSideSheetFocusNav_DEV = 0x19B9ACB07D0; // Unknown = 
        public const ulong FFlagSignUpBirthdayPickerRemoveBottomBarOffset = 0x19B9ACB2290; // Unknown = 
        public const ulong FFlagSignUpBirthdayPickerRequireManualSelection = 0x19B9ACBD010; // Unknown = 
        public const ulong FFlagSignUpBirthdayPickerShowAgeCalculator = 0x19B9ACB21D0; // Unknown = 
        public const ulong FFlagSignUpBirthdayRefactorNestedDefinition = 0x19B9ACBEE10; // Unknown = 
        public const ulong FFlagSignUpTrackFailedRequest = 0x19B945AE5D0; // Unknown = 
        public const ulong FFlagSignalsNavP2NavigationPrimitives5 = 0x19B85785E1D; // Bool = false
        public const ulong FFlagSignalsNavP3Dispatch5 = 0x19B8578625D; // Bool = false
        public const ulong FFlagSignalsNavP3Final = 0x19B857862DD; // Bool = false
        public const ulong FFlagSignalsNavP3aWrapAppPage2 = 0x19BA59BF795; // Bool = false
        public const ulong FFlagSignalsNavP3bTopBar4 = 0x19B8578601D; // Bool = false
        public const ulong FFlagSignalsNavP3cEvents4 = 0x19B85785DD0; // Unknown = 
        public const ulong FFlagSignalsNavP3dRouteGated2 = 0x19B85785D50; // Unknown = 
        public const ulong FFlagSignalsNavP3eAuth3 = 0x19B85785B10; // Unknown = 
        public const ulong FFlagSignalsNavP3fGameDetails3 = 0x19B85785B90; // Unknown = 
        public const ulong FFlagSignalsNavP3gAvatarExperience4 = 0x19B85785710; // Unknown = 
        public const ulong FFlagSignalsNavP3hMisc3 = 0x19B857854D0; // Unknown = 
        public const ulong FFlagSignalsNavProjected2 = 0x19B8578635D; // Bool = false
        public const ulong FFlagSignalsReactUseMutableSource = 0x19B859C4790; // Unknown = 
        public const ulong FFlagSignupDisplayNameLogging = 0x19B90294BD0; // Unknown = 
        public const ulong FFlagSignupLogoAspectRatioFix = 0x19B82B1631D; // Bool = false
        public const ulong FFlagSignupTrackFailedRequestv1 = 0x19B945A6CD0; // Unknown = 
        public const ulong FFlagSilentUpgradeOnSignupIXPBypass = 0x19B90291310; // Unknown = 
        public const ulong FFlagSilentlyFailIfChallenge = 0x19B90293210; // Unknown = 
        public const ulong FFlagSingleUploadMakeupSupport4 = 0x19B9EE03790; // Unknown = 
        public const ulong FFlagSingleUserInvitePageKeybind = 0x19B9F29811D; // Bool = false
        public const ulong FFlagSkipBlockModal = 0x19B8C2E1950; // Unknown = 
        public const ulong FFlagSkipBuyDelayForExperienceShop = 0x19B9ACBCD10; // Unknown = 
        public const ulong FFlagSkipCompletionModalForMarketplace = 0x19B9ACB4E90; // Unknown = 
        public const ulong FFlagSkipCompletionModalForMarketplace3 = 0x19B9ACB2D50; // Unknown = 
        public const ulong FFlagSlimDevConsole2 = 0x19BACE9E71D; // Bool = false
        public const ulong FFlagSlimTintContextFilter = 0x19BACE9F190; // Unknown = 
        public const ulong FFlagSnoozeMenuTextXAlignment = 0x19BA6070210; // Unknown = 
        public const ulong FFlagSocialBlockingModalFocusNavSupport = 0x19D7F97096D; // Bool = true
        public const ulong FFlagSocialCarouselEnableNewFriendRequestsBadgeForAll = 0x19B8FA1EC1D; // Bool = false
        public const ulong FFlagSocialCarouselEnableUserSeenEvents = 0x19BB7870490; // Unknown = 
        public const ulong FFlagSocialCarouselEnableUserSeenEvents2 = 0x19B8FA1DA5D; // Bool = false
        public const ulong FFlagSocialCarouselFixColdStartJitter = 0x19B8FA1ED5D; // Bool = false
        public const ulong FFlagSocialCarouselFixConsoleCtaForInGame = 0x19B8FA1D950; // Unknown = 
        public const ulong FFlagSocialCarouselFixGameJoinCardDismiss = 0x19B8FA1E21D; // Bool = false
        public const ulong FFlagSocialCarouselFixLoadingSkeletonSizing = 0x19B8FA1EF9D; // Bool = false
        public const ulong FFlagSocialCarouselMigrateRecommendations = 0x19BACFD6B50; // Unknown = 
        public const ulong FFlagSocialCarouselPressXToViewProfile = 0x19BACFD7290; // Unknown = 
        public const ulong FFlagSocialCarouselShareQRBackToAddFriends = 0x19B9AF15E10; // Unknown = 
        public const ulong FFlagSocialCarouselShareQRBackToAddFriends_v2 = 0x19B9AF15850; // Unknown = 
        public const ulong FFlagSocialCarouselShareQREnabled = 0x19B9AF15F90; // Unknown = 
        public const ulong FFlagSocialCarouselShareQREnabled_v5 = 0x19B9AF15F50; // Unknown = 
        public const ulong FFlagSocialCarouselShowLoadingSkeleton = 0x19B8FA1DD9D; // Bool = false
        public const ulong FFlagSocialCarouselUpdateVerticalSpacing = 0x19B8FA1C510; // Unknown = 
        public const ulong FFlagSocialCarouselUseConsolePolicyForCta = 0x19B8FA1C950; // Unknown = 
        public const ulong FFlagSocialCarouselUseProfileStore_v2 = 0x19BACFDCE10; // Unknown = 
        public const ulong FFlagSocialContextToastEventStream3 = 0x19BAED56548; // Unknown = 
        public const ulong FFlagSocialEnableProfileInspectAndBuy = 0x19BAEE1DF90; // Unknown = 
        public const ulong FFlagSocialEnableProfileInspectAndBuyAnalytics = 0x19B8C2EC590; // Unknown = 
        public const ulong FFlagSocialEnableProfileInspectAndBuyAnalyticsV2 = 0x19B9ABD63B5; // Bool = false
        public const ulong FFlagSocialEnableProfileInspectAndBuyAnalyticsV3 = 0x19BB7F4A750; // Unknown = 
        public const ulong FFlagSocialEnableProfileInspectAndBuyConsoleFocusNav = 0x19B8C2EC79D; // Bool = false
        public const ulong FFlagSocialEnableProfileInspectAndBuy_8 = 0x19B8C2EC35D; // Bool = false
        public const ulong FFlagSocialExperienceJoinPresenceStoreMigration = 0x19B9FB6E1DD; // Bool = false
        public const ulong FFlagSocialExperienceJoinPresenceStoreMigration_v1 = 0x19BA679DD1D; // Bool = false
        public const ulong FFlagSocialJoinPassPlaceIdToLaunch = 0x19BA6799A5D; // Bool = false
        public const ulong FFlagSocialJoinUseUnifiedPurchaseFlow = 0x19BA67985DD; // Bool = false
        public const ulong FFlagSocialLibrariesSelectableAlertViewShim = 0x19BB6BB10DD; // Bool = false
        public const ulong FFlagSocialLuaAnalyticsUseTelemetryServiceAsDefault = 0x19BBC743050; // Unknown = 
        public const ulong FFlagSocialMetadataSectionMigrateUserProfileToSignals = 0x19BC27B4CE0; // Unknown = 
        public const ulong FFlagSocialNetworksInEditProfileIXPEnabled = 0x19B9064389D; // Bool = false
        public const ulong FFlagSocialNetworksInEditProfileIXPSetupEnabled_v6 = 0x19B906436DD; // Bool = false
        public const ulong FFlagSocialTabReplaceRefreshConversations = 0x19B8C2E4C90; // Unknown = 
        public const ulong FFlagSocialTabsPagePresenceSignalsMigration = 0x19B9011F2DD; // Bool = false
        public const ulong FFlagSongCarouselPropUpdate = 0x19B88C40850; // Unknown = 
        public const ulong FFlagSongDetailsPageDesignPass3 = 0x19B9ACB6F90; // Unknown = 
        public const ulong FFlagSongEdpCarouselIxp = 0x19BBB59C910; // Unknown = 
        public const ulong FFlagSongEdpCarouselIxp2 = 0x19B82B1D6D0; // Unknown = 
        public const ulong FFlagSongbirdMusicIconThumbnail = 0x19D84DA0490; // Unknown = 
        public const ulong FFlagSongbirdPopoverSubmenu2 = 0x19B8579B0F5; // Bool = false
        public const ulong FFlagSoothsayerCheckForContactImporterV1 = 0x19BC054691D; // Bool = false
        public const ulong FFlagSortInvitesByScoreEnabledForAll = 0x19BADF9C710; // Unknown = 
        public const ulong FFlagSpatialUIDisableBottomBarFading = 0x19B9FD87C50; // Unknown = 
        public const ulong FFlagSpatialUIDisableBottomBarInteractionOnAnimating = 0x19B9FD86610; // Unknown = 
        public const ulong FFlagSpatialUIEnableDrag8 = 0x19BA3BB4890; // Unknown = 
        public const ulong FFlagSpatialUIEnableMovePanelToCenter8 = 0x19BA3BB39D0; // Unknown = 
        public const ulong FFlagSpatialUIEnablePanelsRefocusing = 0x19B9FD87890; // Unknown = 
        public const ulong FFlagSpatialUIFixGameInviteChatExclusive = 0x19B9FD88A5D; // Bool = false
        public const ulong FFlagSpatialUIFixMenuPanelChatExclusive = 0x19BACE9D7DD; // Bool = false
        public const ulong FFlagSquadAppChatRTNFixWithSquadMainFlag = 0x19B8C2E4110; // Unknown = 
        public const ulong FFlagSquadEnabled = 0x19B8C2E3D50; // Unknown = 
        public const ulong FFlagSquadExperienceInviteRetryAfter = 0x19BA672739D; // Bool = false
        public const ulong FFlagSquadLaunchExperienceMobileFix = 0x19B88C4E790; // Unknown = 
        public const ulong FFlagSquadsPresenceStoreMigration = 0x19BA6723D9D; // Bool = false
        public const ulong FFlagSquadsUseProfileFrameThumbnail = 0x19BAFCFC810; // Unknown = 
        public const ulong FFlagStackedBottomNavMarketplaceCTA = 0x19B9AF15190; // Unknown = 
        public const ulong FFlagStandardizeSafetyIcon = 0x19B88C4B39D; // Bool = false
        public const ulong FFlagStopBubbleChatReactWarning = 0x19BBCD71750; // Unknown = 
        public const ulong FFlagStopModerationConnectionOnLeave = 0x19B8FDEB79D; // Bool = false
        public const ulong FFlagStopStreamTrackOnDeath = 0x19B9119EC6D; // Bool = true
        public const ulong FFlagStreamNotificationBellEntryPoint = 0x19B9F18E83D; // Bool = true
        public const ulong FFlagStreamNotificationDropdownFocusedOwner = 0x19B8C306C1D; // Bool = true
        public const ulong FFlagStreamNotificationDropdownSingleOwner = 0x19B8C3069DD; // Bool = true
        public const ulong FFlagStreamNotificationImpressionLogging = 0x19B9F182E9D; // Bool = true
        public const ulong FFlagStreamNotificationUXDropdown2 = 0x19B8C3065DD; // Bool = true
        public const ulong FFlagStreamNotificationUXSettingsHeader = 0x19B8C30679D; // Bool = true
        public const ulong FFlagStreamNotificationsStandardizeClickEvents = 0x19B8C30641D; // Bool = true
        public const ulong FFlagStreamingPauseUIAnalyticsEnabled = 0x19B9F0A751D; // Bool = false
        public const ulong FFlagStringKeyFixForParticipantsTable = 0x19B8FDE9E10; // Unknown = 
        public const ulong FFlagSubTabAddDesktopTopMargin = 0x19B9ACB8110; // Unknown = 
        public const ulong FFlagSubTabAddMomentsFlagGating = 0x19B9ACB09D0; // Unknown = 
        public const ulong FFlagSubTabFixMissingProfileWidget = 0x19B9ACBD610; // Unknown = 
        public const ulong FFlagSubTabNavigationTTITracking = 0x19B9ACB9090; // Unknown = 
        public const ulong FFlagSubTabRemoveFlyoutDependency = 0x19B9ACB8490; // Unknown = 
        public const ulong FFlagSubscriptionPurchaseModalLiveStatus = 0x19B9AF17ED0; // Unknown = 
        public const ulong FFlagSubscriptionUpsellCounterWithErrorReasonV2 = 0x19D4353DFE8; // Unknown = 
        public const ulong FFlagSuggestedCalleeBugFixEnabledV2 = 0x19BA52097D5; // Bool = false
        public const ulong FFlagSupportFreeTrial = 0x19B8FC35DDD; // Bool = false
        public const ulong FFlagSupportFreeTrialPriceRow = 0x19B8FC33810; // Unknown = 
        public const ulong FFlagSupportGamepadNavInVoiceModals = 0x19B9F182535; // Bool = true
        public const ulong FFlagSupportNewBadgeRobloxPlus = 0x19B8FC3331D; // Bool = false
        public const ulong FFlagSupportSubmissionOnAllReportNodes = 0x19B8C30D150; // Unknown = 
        public const ulong FFlagSupportTerminalMilestoneInReactProfilerLogger = 0x19BA60951D0; // Unknown = 
        public const ulong FFlagSupportViewingUserProfileOnOSA = 0x19BA6B2E85D; // Bool = true
        public const ulong FFlagSupportViewingUserProfileOnOSA1 = 0x19B8FA1519D; // Bool = false
        public const ulong FFlagSurvBloxAddSurveyLinkParamsEnabled = 0x19B90290690; // Unknown = 
        public const ulong FFlagSurvBloxEnabled = 0x19B90290B10; // Unknown = 
        public const ulong FFlagSurvBloxEventTypeEnabled = 0x19BBB31E010; // Unknown = 
        public const ulong FFlagSurvBloxEventTypeEnabled2 = 0x19B8C30ED9D; // Bool = true
        public const ulong FFlagSurvBloxLocalStorageEnabled = 0x19B90290610; // Unknown = 
        public const ulong FFlagSurvBloxTrackingFixes = 0x19B902902D0; // Unknown = 
        public const ulong FFlagSwitchCSRootProviderTranslationsPackage = 0x19BBC38A450; // Unknown = 
        public const ulong FFlagSwitchOverToAbuseReportMenuV2 = 0x19BB7F42FD0; // Unknown = 
        public const ulong FFlagSwitchProfileWidthHookToSocialCommon = 0x19BACFDFD50; // Unknown = 
        public const ulong FFlagSwitchProfileWidthHookToSocialCommon_v2 = 0x19BACFDF850; // Unknown = 
        public const ulong FFlagSwitchTnSTranslationsPackage = 0x19D8168DA50; // Unknown = 
        public const ulong FFlagSystemTrayDeviceSettings2 = 0x19BA59BAB5D; // Bool = false
        public const ulong FFlagTCEducationModalSideBarPolicy = 0x19B90643A10; // Unknown = 
        public const ulong FFlagTCModalUseFoundationOverlay = 0x19BA59B3B10; // Unknown = 
        public const ulong FFlagTCParentChildAutoUpgrade = 0x19BA59BBF50; // Unknown = 
        public const ulong FFlagTCParentChildAutoUpgrade2 = 0x19BA59B8CD0; // Unknown = 
        public const ulong FFlagTCPolicyCheckRedirect = 0x19B8C3035DD; // Bool = true
        public const ulong FFlagTCShareLinkErrorModal = 0x19BA59BDA90; // Unknown = 
        public const ulong FFlagTCShareLinkErrorModalTextRename = 0x19BA59B0750; // Unknown = 
        public const ulong FFlagTCShareLinkReceiverUI4 = 0x19BA59BEC50; // Unknown = 
        public const ulong FFlagTCStreamNotifEventReceiver = 0x19B8C2E2DD0; // Unknown = 
        public const ulong FFlagTCUpdateProfileCTAButton = 0x19BA59BAA10; // Unknown = 
        public const ulong FFlagTFPassQRCodeSource = 0x19BC27B5D90; // Unknown = 
        public const ulong FFlagTFProfileInsightsBypassCache = 0x19BA59BA2D0; // Unknown = 
        public const ulong FFlagTFWithActionsCheck = 0x19BA59B99D0; // Unknown = 
        public const ulong FFlagTFWithActionsCheck_4 = 0x19BA59B8310; // Unknown = 
        public const ulong FFlagTTITrackerMemoryTracking = 0x19BC2568860; // Unknown = 
        public const ulong FFlagTTITrackerMemoryTracking3 = 0x19B8F7416DD; // Bool = false
        public const ulong FFlagTakeAScreenshotOfThis = 0x19D81687050; // Unknown = 
        public const ulong FFlagTalkingChangedWithDebounceV2 = 0x19B8FDE9190; // Unknown = 
        public const ulong FFlagTempFixInfiniteHomePYMK = 0x19B8FC3ABD0; // Unknown = 
        public const ulong FFlagTemporaryAvatarKickWarningDialog = 0x19BACE781DD; // Bool = false
        public const ulong FFlagTenFootUiCorrectAutoFocusLoggingBehavior = 0x19B8F90865D; // Bool = false
        public const ulong FFlagTenFootUiGlobalNavFixOptionText = 0x19B859CBF90; // Unknown = 
        public const ulong FFlagTenFootUiSupportSortHeaderTooltip2 = 0x19BA520F2BD; // Bool = true
        public const ulong FFlagTenFootUiSupportSortSubtitle2 = 0x19B88C4ACDD; // Bool = false
        public const ulong FFlagTestDeviceForFAEUpsell = 0x19B8FDEF4DD; // Bool = false
        public const ulong FFlagTextChannelWindowPerfTrackingEnabled = 0x19B9CB7D55D; // Bool = false
        public const ulong FFlagTextChatEnableUniverseChatTabs11 = 0x19B9F18C7DD; // Bool = true
        public const ulong FFlagTextFilterEducationNudgeEnabled = 0x19B9481271D; // Bool = false
        public const ulong FFlagTiltLoadingScreenConsoleHints = 0x19B9AF12210; // Unknown = 
        public const ulong FFlagTiltLoadingScreenEnterExitHold = 0x19B9AF12B50; // Unknown = 
        public const ulong FFlagTiltLoadingScreenEnterExitHold2 = 0x19B9AF12CD0; // Unknown = 
        public const ulong FFlagTimeToInteractiveTrackerWarningsRequireDebug = 0x19B8F741950; // Unknown = 
        public const ulong FFlagTimeoutRemoteEvent = 0x19BB1C1813D; // Bool = false
        public const ulong FFlagTokenizeUnibarConstantsWithStyleProvider = 0x19BA7FC10C8; // Unknown = 
        public const ulong FFlagTopBarDeprecateChatRodux = 0x19D7C7CF595; // Bool = false
        public const ulong FFlagTopBarDeprecateChatRodux2 = 0x19BAD28699D; // Bool = false
        public const ulong FFlagTopBarDeprecateCoreGuiRodux = 0x19B9FDDCB15; // Bool = false
        public const ulong FFlagTopBarDeprecateCoreGuiRodux2 = 0x19D8168AD90; // Unknown = 
        public const ulong FFlagTopBarDeprecateDisplayOptionsRodux = 0x19D7C7CDC55; // Bool = false
        public const ulong FFlagTopBarDeprecateDisplayOptionsRodux2 = 0x19BAD286C9D; // Bool = false
        public const ulong FFlagTopBarDeprecateGameInfoRodux = 0x19BAD2865DD; // Bool = false
        public const ulong FFlagTopBarDeprecateGamepadNavigationDialogRodux = 0x19BAD2867DD; // Bool = false
        public const ulong FFlagTopBarDeprecateMoreMenuRodux = 0x19B9FDDCB95; // Bool = false
        public const ulong FFlagTopBarDeprecateRespawnRodux = 0x19B9FDDCC15; // Bool = false
        public const ulong FFlagTopBarDeprecateRespawnRodux2 = 0x19D816809D0; // Unknown = 
        public const ulong FFlagTopBarRefactor2 = 0x19BA4614D5D; // Bool = false
        public const ulong FFlagTopBarSignalizeHealthBar4 = 0x19BA4617E5D; // Bool = false
        public const ulong FFlagTopBarSignalizeKeepOutAreas5 = 0x19BA461171D; // Bool = false
        public const ulong FFlagTopBarSignalizeMenuOpen = 0x19BA461221D; // Bool = false
        public const ulong FFlagTopBarSignalizeScreenSize2 = 0x19BA461C41D; // Bool = false
        public const ulong FFlagTopBarSignalizeSetCores = 0x19BA461A210; // Unknown = 
        public const ulong FFlagTouchHelpPageResponsiveUnits = 0x19BBE91D7D0; // Unknown = 
        public const ulong FFlagTrackerPromptNewCopyForCameraPerformanceEnabled = 0x19B9F0AD550; // Unknown = 
        public const ulong FFlagTranslateDevProducts = 0x19D85DC1CD0; // Unknown = 
        public const ulong FFlagTraversalExpPagePaddingFixes709 = 0x19BBC380450; // Unknown = 
        public const ulong FFlagTraversalHistoryDiscoveryTelemetry = 0x19B88C2CD90; // Unknown = 
        public const ulong FFlagTraversalUseDiscoveryCollectionViews = 0x19BBE91E9D0; // Unknown = 
        public const ulong FFlagTraversalUseXSmallCollectionItems = 0x19BBE91B9D0; // Unknown = 
        public const ulong FFlagTriggerLogoutOnAuthErrorCode = 0x19BA6A34890; // Unknown = 
        public const ulong FFlagTrimLongTitleForTOSEnabled = 0x19B859C9810; // Unknown = 
        public const ulong FFlagTruncateDeviceSelection = 0x19D8168D810; // Unknown = 
        public const ulong FFlagTrustedFriendsUseEnumCTA = 0x19BA59B8D10; // Unknown = 
        public const ulong FFlagTrustedFriendsUseEnumCTA_2 = 0x19BA59B83D0; // Unknown = 
        public const ulong FFlagTrustedFriendsUseFoundationSheet = 0x19BA59B0550; // Unknown = 
        public const ulong FFlagTutorialUpsellEnabled = 0x19B945A0310; // Unknown = 
        public const ulong FFlagTutorialUpsellOverrideIXPEnabled = 0x19B90291D10; // Unknown = 
        public const ulong FFlagUFRImprovements = 0x19BA4E9B055; // Bool = true
        public const ulong FFlagUFRImprovements3 = 0x19BA4E9B995; // Bool = true
        public const ulong FFlagUFRInlineAppealLink = 0x19BA8023B10; // Unknown = 
        public const ulong FFlagUIBloxAddFoundationNavigationTabIcon = 0x19B8578839D; // Bool = false
        public const ulong FFlagUIBloxAddTestIdToActionBar = 0x19B85787310; // Unknown = 
        public const ulong FFlagUIBloxAppShortcutBarUseTokens = 0x19B85787BD0; // Unknown = 
        public const ulong FFlagUIBloxDeprecateComponentGlobalSemanticTokenUse = 0x19B8578859D; // Bool = false
        public const ulong FFlagUIBloxDidMountUpdateFullPageModal = 0x19B85787DDD; // Bool = false
        public const ulong FFlagUIBloxDisableTokenScaling = 0x19B85787390; // Unknown = 
        public const ulong FFlagUIBloxEnableActionBarButtonOverride = 0x19B857876D0; // Unknown = 
        public const ulong FFlagUIBloxEnableTooltipV2BodyFontFix = 0x19B9F18C03D; // Bool = true
        public const ulong FFlagUIBloxEnableTooltipV2HoverControllerReRenderFix = 0x19B85787C1D; // Bool = false
        public const ulong FFlagUIBloxFixCoplayFooterConditionalHooks = 0x19BB1A40EDD; // Bool = true
        public const ulong FFlagUIBloxRemoveStackedNavigationTabIconLabelSpacing = 0x19B85786190; // Unknown = 
        public const ulong FFlagUIBloxToastFoundationButtonSizing = 0x19B8578815D; // Bool = false
        public const ulong FFlagUIBloxUseEngineRichTextBounds = 0x19B85787D10; // Unknown = 
        public const ulong FFlagUIBloxUseFoundationButton5 = 0x19B85787F5D; // Bool = false
        public const ulong FFlagUIBloxUseFoundationButtonInGame2 = 0x19B8E61095D; // Bool = true
        public const ulong FFlagUIBloxUseFoundationSkeleton = 0x19B85A50740; // Unknown = 
        public const ulong FFlagUIBloxUseGridInfoForTile = 0x19B8C347BDD; // Bool = false
        public const ulong FFlagUIBloxUseNewZindex = 0x19B8C347B5D; // Bool = false
        public const ulong FFlagUXForCameraPerformanceEnabled = 0x19B9F0ACB90; // Unknown = 
        public const ulong FFlagUXForCameraPerformanceIXPEnabled = 0x19B9AF10DD0; // Unknown = 
        public const ulong FFlagUnibarLuaOcclusionMetrics = 0x19B9ACBD8D0; // Unknown = 
        public const ulong FFlagUnibarMenuOpenHamburger = 0x19B9FDD1955; // Bool = false
        public const ulong FFlagUnibarMenuOpenHamburgerGamepadIXP = 0x19B9ACB5590; // Unknown = 
        public const ulong FFlagUnibarMenuOpenHamburgerGamepadIXP684 = 0x19B9ACBEB90; // Unknown = 
        public const ulong FFlagUnibarMenuOpenSelectionIXP = 0x19B9ACB0A90; // Unknown = 
        public const ulong FFlagUnibarMenuOpenSelectionIXP2 = 0x19B9ACB4CD0; // Unknown = 
        public const ulong FFlagUnibarMenuOpenSubmenu = 0x19B9FDD1995; // Bool = false
        public const ulong FFlagUnifiedPurchaseAddSkeleton = 0x19B9ACB1690; // Unknown = 
        public const ulong FFlagUnifiedPurchaseFlowMarketplaceUIImprovements = 0x19B9ACBDF50; // Unknown = 
        public const ulong FFlagUnifiedPurchaseFlowMarketplaceUIImprovementsV4 = 0x19B9ACBCED0; // Unknown = 
        public const ulong FFlagUnifiedPurchaseGamepassAddProductUniverseId = 0x19B9ACB7B90; // Unknown = 
        public const ulong FFlagUnifiedPurchaseOptimizeTTIMarketplace = 0x19B9AF19850; // Unknown = 
        public const ulong FFlagUnifiedPurchaseOptimizeTTIMarketplaceIntegration = 0x19BA3A55F50; // Unknown = 
        public const ulong FFlagUnifiedPurchasePassInProductInfoEDP = 0x19B9AF1B610; // Unknown = 
        public const ulong FFlagUnifiedPurchasePassInProductInfoEDP2 = 0x19B9AF1C010; // Unknown = 
        public const ulong FFlagUnifiedPurchaseSupportRefetchingLooksAfterUpsell = 0x19B9ACB0610; // Unknown = 
        public const ulong FFlagUnifyConsoleSettingsPage5 = 0x19B9AF12550; // Unknown = 
        public const ulong FFlagUnifyVerifiedBadgeComponent = 0x19B85788290; // Unknown = 
        public const ulong FFlagUniversalAppCameraEnabled5 = 0x19B90644C1D; // Bool = false
        public const ulong FFlagUniversalAppCameraEnabledForAll4 = 0x19B90644D5D; // Bool = false
        public const ulong FFlagUniversalFeatureRestrictionReceivers = 0x19BBB31F390; // Unknown = 
        public const ulong FFlagUniversalFeatureRestrictionReceivers10 = 0x19B8C30E2DD; // Bool = true
        public const ulong FFlagUnreduxLastInputTypeChanged = 0x19BA4614AD0; // Unknown = 
        public const ulong FFlagUpdateDeviceInputPlayerChanged = 0x19B8FDE9E5D; // Bool = false
        public const ulong FFlagUpdateDiscoveryEventErrorDetailsLogging = 0x19BA3A70E1D; // Bool = false
        public const ulong FFlagUpdateDividerStartBounds = 0x19B94810390; // Unknown = 
        public const ulong FFlagUpdateInGameAssetReportingCTAs = 0x19B8C30CB90; // Unknown = 
        public const ulong FFlagUpdateInvitesToUsePaginatedFriends = 0x19BACE72050; // Unknown = 
        public const ulong FFlagUpdateNoInternetConnectionText = 0x19B82B1B75D; // Bool = false
        public const ulong FFlagUpdatePeopleNamesSettingCopy = 0x19B9FD8B455; // Bool = false
        public const ulong FFlagUpdateRephraseSettingUI = 0x19B9FD8B790; // Unknown = 
        public const ulong FFlagUpdateSocialCarouselAddFriendsIcon = 0x19B8EE09D7D; // Bool = false
        public const ulong FFlagUpdateSongCarouselClipDefault = 0x19B88C405D0; // Unknown = 
        public const ulong FFlagUpdateTranslateInReportRevamp = 0x19B8C30E11D; // Bool = true
        public const ulong FFlagUpdateUnifiedPurchasePriceTelemetry = 0x19B9ACB0250; // Unknown = 
        public const ulong FFlagUpdateVisibilitySettingsCopy = 0x19B9FD8D810; // Unknown = 
        public const ulong FFlagUpdateVoiceConnectionToasts_AEGIS2 = 0x19BA5155990; // Unknown = 
        public const ulong FFlagUpdatedTrimMemoryLevelPropagation = 0x19B82A7009D; // Bool = true
        public const ulong FFlagUploadMakeupSupport = 0x19B9EE04C1D; // Bool = false
        public const ulong FFlagUseAccountPickerAmpEligibility = 0x19B9ACB0150; // Unknown = 
        public const ulong FFlagUseAnimateScrollViewToSelectionHelper = 0x19B9ACBDD50; // Unknown = 
        public const ulong FFlagUseAudioAnalyzerForLocalMetering2 = 0x19B8FDEB55D; // Bool = false
        public const ulong FFlagUseBindingForUnreadChat = 0x19B8EE06F3D; // Bool = false
        public const ulong FFlagUseCameraDevicesListener = 0x19B9FD89F1D; // Bool = false
        public const ulong FFlagUseCaptureCommonComponents = 0x19D86F01A90; // Unknown = 
        public const ulong FFlagUseCharacterStore2 = 0x19B8FA14210; // Unknown = 
        public const ulong FFlagUseCommunitiesTranslation = 0x19BC0547D50; // Unknown = 
        public const ulong FFlagUseCoreScriptsRootProviderForUpsellModal = 0x19B9EE011DD; // Bool = false
        public const ulong FFlagUseDefaultOverrideColorsFor10ftModels = 0x19B9AF16550; // Unknown = 
        public const ulong FFlagUseEnablePremiumUserFeaturesAppPolicy = 0x19BC0545D50; // Unknown = 
        public const ulong FFlagUseExternalBrowserForAgeGuidelines10ft = 0x19BA6A3B850; // Unknown = 
        public const ulong FFlagUseExtraATCProperties = 0x19B84FE2410; // Unknown = 
        public const ulong FFlagUseFriendsListOrderedByIdPresenceImpressionEventsEnabled = 0x19BA679F09D; // Bool = false
        public const ulong FFlagUseIsAvailableCheckForIOSKeychainFetch = 0x19B945AF510; // Unknown = 
        public const ulong FFlagUseLocalTraversalHistory699v1 = 0x19BBC38EB50; // Unknown = 
        public const ulong FFlagUseMediaPlayerInCarousel = 0x19BACFDCF10; // Unknown = 
        public const ulong FFlagUseMediaPlayerInCarousel_v2 = 0x19BACFDAA90; // Unknown = 
        public const ulong FFlagUseNavigationSelectors = 0x19B9AF1A190; // Unknown = 
        public const ulong FFlagUseNewDiscoverabilityModal = 0x19B84F2632D; // Bool = false
        public const ulong FFlagUseNewDiscoverabilityModal_v2 = 0x19BA59B4190; // Unknown = 
        public const ulong FFlagUseNewHurtOverlayAnimation = 0x19BA461295D; // Bool = false
        public const ulong FFlagUseNewHurtOverlayImage = 0x19BA461701D; // Bool = false
        public const ulong FFlagUseNewPlayerList3 = 0x19B8EE07A7D; // Bool = false
        public const ulong FFlagUseNotificationServiceIsConnected = 0x19B9F0AB550; // Unknown = 
        public const ulong FFlagUseObservableDefaultForChromeFocused = 0x19BACFEFB10; // Unknown = 
        public const ulong FFlagUseOmniFeedDividerOverrides = 0x19BC054EC90; // Unknown = 
        public const ulong FFlagUseOriginalPlatformChatPolicy = 0x19BB6BBE39D; // Bool = true
        public const ulong FFlagUsePlaceInfoController2 = 0x19B8F90E71D; // Bool = false
        public const ulong FFlagUsePlatformNameForUnknown = 0x19D85DCF010; // Unknown = 
        public const ulong FFlagUsePlaystationPaymentsProtocolCommonFunctions = 0x19BAC83345D; // Bool = false
        public const ulong FFlagUsePresenceDataFromRtn = 0x19B8EAEC75D; // Bool = false
        public const ulong FFlagUseRbxStorageInCapturesCommon = 0x19BA4562B2D; // Bool = false
        public const ulong FFlagUseRbxstorageInGallery = 0x19B98EC7418; // Unknown = 
        public const ulong FFlagUseRoactGlobalConfigInCoreScripts = 0x19B9FDD4D95; // Bool = false
        public const ulong FFlagUseSessionServiceWrapper = 0x19B90293E50; // Unknown = 
        public const ulong FFlagUseSessionServiceWrapperModule = 0x19B902929D0; // Unknown = 
        public const ulong FFlagUseSharedLoadingScreenView = 0x19BA8A09B5D; // Bool = false
        public const ulong FFlagUseSignalsForAccountSecurityPrompt = 0x19BA5532310; // Unknown = 
        public const ulong FFlagUseSignalsForAppTopBanner = 0x19BA553FF90; // Unknown = 
        public const ulong FFlagUseSignalsForAuthenticationStatus7 = 0x19BA5531A90; // Unknown = 
        public const ulong FFlagUseSignalsForCountryCode = 0x19BA5536490; // Unknown = 
        public const ulong FFlagUseSignalsForCountryCodeList = 0x19B85784890; // Unknown = 
        public const ulong FFlagUseSignalsForGameInvitesStatus = 0x19BA55320D0; // Unknown = 
        public const ulong FFlagUseSignalsForGlobalContextMenuInset1 = 0x19BA553C590; // Unknown = 
        public const ulong FFlagUseSignalsForIsLocalUserSoothsayer = 0x19B85785950; // Unknown = 
        public const ulong FFlagUseSignalsForIsLocalUserUnder13 = 0x19BA553D190; // Unknown = 
        public const ulong FFlagUseSignalsForModeration = 0x19B857861DD; // Bool = false
        public const ulong FFlagUseSignalsForPlatform = 0x19BA5535B90; // Unknown = 
        public const ulong FFlagUseSignalsForScreenGuiBlur = 0x19BA5533B90; // Unknown = 
        public const ulong FFlagUseSignalsForSearchBar = 0x19BA5536E90; // Unknown = 
        public const ulong FFlagUseSignalsForSiteMessage = 0x19BA5536950; // Unknown = 
        public const ulong FFlagUseSignalsForSquadExperienceInviteStatus = 0x19B8C2E3490; // Unknown = 
        public const ulong FFlagUseSignalsForStartup = 0x19BA5530110; // Unknown = 
        public const ulong FFlagUseSignalsNavigation2 = 0x19B85785A9D; // Bool = false
        public const ulong FFlagUseSignalsRoduxStore3 = 0x19B857863DD; // Bool = false
        public const ulong FFlagUseTeleportTraversalHistory699v1 = 0x19BBC381DD0; // Unknown = 
        public const ulong FFlagUseUniverseVotesController = 0x19B8F90E79D; // Bool = false
        public const ulong FFlagUseUpdatedBackgroundSceneSettingsOnMobile1 = 0x19B9026C510; // Unknown = 
        public const ulong FFlagUseUpdatedVNGAgreementsWorkflow = 0x19B88C4A650; // Unknown = 
        public const ulong FFlagUseV2LivePreviewWatermark = 0x19BA8A0EF9D; // Bool = false
        public const ulong FFlagUseVRSpecificLeaveButton = 0x19D81681210; // Unknown = 
        public const ulong FFlagUseVoiceExitBetaLanguageV2 = 0x19BC05429D0; // Unknown = 
        public const ulong FFlagUserBlockingApiPlayerContextMenuEnabled = 0x19B859CA750; // Unknown = 
        public const ulong FFlagUserInfoWidgetUseProfileFrameThumbnail = 0x19B902937DD; // Bool = true
        public const ulong FFlagUserListCtaAnalyticsEnabled = 0x19BACFD69DD; // Bool = false
        public const ulong FFlagUserListCtaIntegrationEnabled = 0x19BACFDED5D; // Bool = true
        public const ulong FFlagUserListCtaIntegrationEnabled_v2 = 0x19BACFD1B50; // Unknown = 
        public const ulong FFlagUserListFooterViewMore = 0x19BA59B7990; // Unknown = 
        public const ulong FFlagUserListPresenceStoreMigration = 0x19BA672D31D; // Bool = false
        public const ulong FFlagUserListPresenceStoreMigration_v2 = 0x19BA672475D; // Bool = false
        public const ulong FFlagUserListTightHeaderSpacing = 0x19BA679385D; // Bool = false
        public const ulong FFlagUserListUseActionAddTranslation = 0x19BA6790F1D; // Bool = false
        public const ulong FFlagUserListUseSheet = 0x19BACFDA290; // Unknown = 
        public const ulong FFlagUserListUsernameFallbackConfig = 0x19BACFD5850; // Unknown = 
        public const ulong FFlagUserPresenceTokenRccCheckPermissionsLua = 0x19B9FDD0A95; // Bool = false
        public const ulong FFlagUserProfileBetterErrors = 0x19BADF90310; // Unknown = 
        public const ulong FFlagUserProfileConsoleUseNewReportFlow = 0x19B859CA4DD; // Bool = false
        public const ulong FFlagUserProfileStoreDataFetchFix = 0x19BA672069D; // Bool = false
        public const ulong FFlagUserProfileStoreQueryRefetch = 0x19BACFD1510; // Unknown = 
        public const ulong FFlagUserProfileTurnCacheBackOn = 0x19B827A3F5D; // Bool = false
        public const ulong FFlagUserProfilesDataLoaderEnabled = 0x19BC054BB10; // Unknown = 
        public const ulong FFlagUserProfilesEnableRetries = 0x19BA515B21D; // Bool = false
        public const ulong FFlagUserProfilesFilterInvalidUserIds = 0x19BA515481D; // Bool = false
        public const ulong FFlagUserProfilesLogCancelledRequests = 0x19BA515165D; // Bool = false
        public const ulong FFlagUserProfilesLogErrorCodes = 0x19B994C19D5; // Bool = true
        public const ulong FFlagUserProfilesUseIsRobloxSubscriberGetter = 0x19BA515405D; // Bool = false
        public const ulong FFlagUserSearchAddFocusActionsSupport_1 = 0x19B8C2E0B50; // Unknown = 
        public const ulong FFlagUserSearchEmptyPageNewIcons = 0x19BA59B0450; // Unknown = 
        public const ulong FFlagUserSearchGoBackOnCancel = 0x19BA59B3E50; // Unknown = 
        public const ulong FFlagUserSearchPresenceStoreMigration_v2 = 0x19B9011D290; // Unknown = 
        public const ulong FFlagUserSearchUseProfileFrameThumbnail = 0x19B9011E29D; // Bool = false
        public const ulong FFlagUserSearchUseThisIsYou = 0x19B8C2E0850; // Unknown = 
        public const ulong FFlagUserTM2Experiment = 0x19B8EE0BADD; // Bool = false
        public const ulong FFlagUserTileAddContextualInfoIcon = 0x19B8C30279D; // Bool = true
        public const ulong FFlagUserTileAddDataHydrationWrapper = 0x19BA672881D; // Bool = false
        public const ulong FFlagUserTileIncludeProfileFrameProp = 0x19BA679021D; // Bool = false
        public const ulong FFlagUserTileRemoveContextualInfoTag = 0x19BA679FA1D; // Bool = false
        public const ulong FFlagUserTileShowBadges = 0x19B8C3026DD; // Bool = true
        public const ulong FFlagUserTileShowShimmerWhenLoading = 0x19BA6795D9D; // Bool = false
        public const ulong FFlagUserTileShowShimmerWhenLoading_v2 = 0x19BA67951DD; // Bool = false
        public const ulong FFlagUserTileTextTCIndicator_V3 = 0x19B8C30265D; // Bool = true
        public const ulong FFlagUserTileTitleStackAddExtraInfo_DEV = 0x19B8C30295D; // Bool = true
        public const ulong FFlagUserTileUnfilteredChatIndicator = 0x19B8C302B1D; // Bool = true
        public const ulong FFlagUserTileUseProfileFrameThumbnail = 0x19BA6799EDD; // Bool = false
        public const ulong FFlagUsesCancelSearchAppPolicy = 0x19BBCD72690; // Unknown = 
        public const ulong FFlagVCWasDisabledFromMenuOpen = 0x19BC0542990; // Unknown = 
        public const ulong FFlagVRAbuseReportLocales = 0x19B8C306B90; // Unknown = 
        public const ulong FFlagVRBottomBarDebugPositionConfig = 0x19B9FDD4E15; // Bool = false
        public const ulong FFlagVRLaserPointerRaycastChange = 0x19BBE910E90; // Unknown = 
        public const ulong FFlagVRPanelWidthIXPEnabledV5 = 0x19B9ACB9B50; // Unknown = 
        public const ulong FFlagVRPanelWidthIXPLocalOverrideEnabled = 0x19BA6A37E10; // Unknown = 
        public const ulong FFlagVRSpatialUIGuardNilHeadScale = 0x19B9FD8815D; // Bool = false
        public const ulong FFlagValidateDescription = 0x19B9EE0341D; // Bool = false
        public const ulong FFlagValidateUGCContentMakeupAssetTypes = 0x19B82E0BA90; // Unknown = 
        public const ulong FFlagVideoPlaybackDetectorCancelPendingScanTask = 0x19B88C2BE90; // Unknown = 
        public const ulong FFlagVipOwnerNotPresentEnableReconnect = 0x19BA672D61D; // Bool = false
        public const ulong FFlagVirtualCursorDisplayOrder = 0x19B9ACB0690; // Unknown = 
        public const ulong FFlagVirtualCursorForTVRemoteKeycodes = 0x19BA59B4610; // Unknown = 
        public const ulong FFlagVirtualCursorModularization4 = 0x19BA59B2590; // Unknown = 
        public const ulong FFlagVirtualCursorSnapLevelBasedOnDirection = 0x19BA59B4390; // Unknown = 
        public const ulong FFlagVirtualCursorSnapStopsWhenInputStops = 0x19BA59B7850; // Unknown = 
        public const ulong FFlagVirtualizedFeedFooterWrapperProp = 0x19B88C26D90; // Unknown = 
        public const ulong FFlagVngAppUpsellPcLayout = 0x19B88C4BF5D; // Bool = false
        public const ulong FFlagVngLogoutGlobalAppSessionsOnConversion = 0x19B88C4A190; // Unknown = 
        public const ulong FFlagVngTOSRevisedEnabled = 0x19B9ACB8E10; // Unknown = 
        public const ulong FFlagVoiceARUnblockingUnmutingEnabled = 0x19BB7F43C9D; // Bool = false
        public const ulong FFlagVoiceChatDisruptiveVoiceNudgeEnableVariant2 = 0x19BA515881D; // Bool = false
        public const ulong FFlagVoiceChatDisruptiveVoiceNudgeForceUseNewDACopy = 0x19BA5158B5D; // Bool = false
        public const ulong FFlagVoiceChatLocalMutedNilFix = 0x19BACFD8FD0; // Unknown = 
        public const ulong FFlagVoiceChatMuteAllSyncMutedPlayers = 0x19B8FDEBEDD; // Bool = false
        public const ulong FFlagVoiceChatOnlyReportVoiceBans = 0x19BA4E9F9D0; // Unknown = 
        public const ulong FFlagVoiceChatSelectorReconnectFocus2_AEGIS2 = 0x19B9FD8B8DD; // Bool = false
        public const ulong FFlagVoiceChatServiceManagerUseAvatarChat = 0x19B8FDEA55D; // Bool = false
        public const ulong FFlagVoiceChatUILogging = 0x19B9FD8C8D0; // Unknown = 
        public const ulong FFlagVoiceChatVolumePerUserDisableInteractionWhenMuted = 0x19BBC380AD0; // Unknown = 
        public const ulong FFlagVoiceChatVolumePerUserMuteVolumeSync = 0x19B8BABB78D; // Bool = false
        public const ulong FFlagVoiceConnectToastCapturesTrustedFriendsSubtitle = 0x19BA4E9AF90; // Unknown = 
        public const ulong FFlagVoiceEndedCheckDisregardIdleState = 0x19B9F185E5D; // Bool = true
        public const ulong FFlagVoiceNudgeUseNewConfirmButton = 0x19BA4E99F10; // Unknown = 
        public const ulong FFlagVoiceRewarmTelemetryV2 = 0x19B8C305D5D; // Bool = true
        public const ulong FFlagVoiceSelectorAvailableAfterFae = 0x19B9FD8BBDD; // Bool = false
        public const ulong FFlagVoiceSelectorIgnoreFailedStateDisconnect = 0x19B9FD8BB90; // Unknown = 
        public const ulong FFlagVoiceUserAgency3 = 0x19B9AF11890; // Unknown = 
        public const ulong FFlagVoiceUserAgencyEnableIXP = 0x19B9AF10890; // Unknown = 
        public const ulong FFlagVoiceVolumeControlsApplyPerUserMultiplier = 0x19B949F83A0; // Unknown = 
        public const ulong FFlagVoiceVolumeControlsDisableInteractionWhenNoMasterVolume = 0x19B9FD8B810; // Unknown = 
        public const ulong FFlagVoiceVolumeControlsEnableNotAudibleVoiceChatVolumeToast = 0x19B9FDDDD55; // Bool = false
        public const ulong FFlagVoiceVolumeControlsEnablePerUserVolumeInteractionTelemetry = 0x19BBC38449D; // Bool = true
        public const ulong FFlagVoiceVolumeControlsEnableVoiceChatVolumeSlider = 0x19B9FDDB055; // Bool = false
        public const ulong FFlagVoiceVolumeControlsEnableVoiceVolumeEligibilityTelemetry = 0x19B8FDEBD1D; // Bool = false
        public const ulong FFlagVoiceVolumeControlsEnableVoiceVolumeImpressionsTelemetry = 0x19B8FDEBD9D; // Bool = false
        public const ulong FFlagVoiceVolumeControlsFixSliderVisibilityOnEligibleGames = 0x19B9FD8BA50; // Unknown = 
        public const ulong FFlagVoiceVolumeControlsGlobalVoiceVolumeSliderIxpExposure = 0x19BA5159A1D; // Bool = false
        public const ulong FFlagVoiceVolumeControlsPerUserPlayerGridMenu = 0x19BBC38ED10; // Unknown = 
        public const ulong FFlagVoiceVolumeControlsPerUserPlayerListButton = 0x19BBC382510; // Unknown = 
        public const ulong FFlagVoiceVolumeControlsPerUserPlayerListButton5 = 0x19BBC383390; // Unknown = 
        public const ulong FFlagVoiceVolumeControlsSuppressInExperienceUiForPartyVoice = 0x19B9FD8B850; // Unknown = 
        public const ulong FFlagWHAM1707ExperimentForceEnabled = 0x19BBBEC4D65; // Bool = false
        public const ulong FFlagWebViewHideLuaSideBar = 0x19B90643D90; // Unknown = 
        public const ulong FFlagWebViewServiceHasBackButtonVisibility = 0x19B90643610; // Unknown = 
        public const ulong FFlagWhisperEmoteOnAvatarContextMenuWithExpChat = 0x19BA60788D0; // Unknown = 
        public const ulong FFlagWrapEmphasisTileDescriptionText = 0x19BBE910650; // Unknown = 
        public const ulong FIntAXAnimatedScrollingFrameScrollTimeMs = 0x19B9F00D910; // Unknown = 
        public const ulong FIntAXAvatarLoadRetryCount = 0x19B906480D0; // Unknown = 
        public const ulong FIntAXAvatarLoadRetryDelayMs = 0x19B90648150; // Unknown = 
        public const ulong FIntAXAvatarUpdateOnGameLeaveDelay = 0x19B906449D0; // Unknown = 
        public const ulong FIntAXBackgroundFogDisabledDistance = 0x19B8F904610; // Unknown = 
        public const ulong FIntAXBackgroundGenerationMaxConsecutivePollFailures = 0x19D80F1A7B8; // Unknown = 
        public const ulong FIntAXBackgroundGenerationMaxPromptLength = 0x19BABC1CB08; // Unknown = 
        public const ulong FIntAXBackgroundGenerationPollIntervalSeconds = 0x19BBB2D49C8; // Unknown = 
        public const ulong FIntAXBackgroundGenerationPollTimeoutSeconds = 0x19B8F9045D0; // Unknown = 
        public const ulong FIntAXBackgroundsCatalogTabPosition = 0x19B8EAE7A70; // Unknown = 
        public const ulong FIntAXBuyDelayMilliseconds = 0x19B8FC36290; // Unknown = 
        public const ulong FIntAXCarouselItemsBasedOnFrameSize = 0x19B8FC33210; // Unknown = 
        public const ulong FIntAXCarouselLoadingBuffer = 0x19B8FC330D0; // Unknown = 
        public const ulong FIntAXCarouselMaxItems = 0x19B8FC32650; // Unknown = 
        public const ulong FIntAXCarouselPeakFraction = 0x19B8FC33150; // Unknown = 
        public const ulong FIntAXCatalogMainNavHeight = 0x19B9026D950; // Unknown = 
        public const ulong FIntAXCatalogMultiItemShoppingFtuxOtherPromptMaxCount = 0x19B8FC36B90; // Unknown = 
        public const ulong FIntAXCatalogPartialPageModalBottomInsetMultiplier = 0x19B9F0082D0; // Unknown = 
        public const ulong FIntAXCategoryPillPositionAnimationDampingRatio = 0x19B9F00BE10; // Unknown = 
        public const ulong FIntAXCategoryPillPositionAnimationFrequency = 0x19B9F00BED0; // Unknown = 
        public const ulong FIntAXCategoryPillTransparencyAnimationDampingRatio = 0x19B9F00B550; // Unknown = 
        public const ulong FIntAXCategoryPillTransparencyAnimationFrequency = 0x19B9F00BB90; // Unknown = 
        public const ulong FIntAXCheckoutButtonTooltipExpireTime = 0x19B8FC36F10; // Unknown = 
        public const ulong FIntAXCheckoutButtonTooltipFtuxDelay = 0x19B8FC36CD0; // Unknown = 
        public const ulong FIntAXClusterCompositionTimeoutMs = 0x19B9F0047D0; // Unknown = 
        public const ulong FIntAXDefaultInventoryPageSize = 0x19BA3A57AD0; // Unknown = 
        public const ulong FIntAXEnhancedAvatarHeadsFtuxDelay = 0x19BB6EF4AF0; // Unknown = 
        public const ulong FIntAXEnhancedAvatarHeadsFtuxDelayMs = 0x19B8F902250; // Unknown = 
        public const ulong FIntAXEyeMakeupZoomRadius = 0x19B9F009D90; // Unknown = 
        public const ulong FIntAXEyebrowsZoomRadius = 0x19B9F009CD0; // Unknown = 
        public const ulong FIntAXEyelashesZoomRadius = 0x19B9F009C90; // Unknown = 
        public const ulong FIntAXFPSDurationForCatSubCat = 0x19B906450D0; // Unknown = 
        public const ulong FIntAXFaceMakeupZoomRadius = 0x19B9F009D10; // Unknown = 
        public const ulong FIntAXGetAvatarDataThrottleInterval = 0x19B906432D0; // Unknown = 
        public const ulong FIntAXGuiObjectIsObscuredPadding = 0x19B9F928A90; // Unknown = 
        public const ulong FIntAXHDCatalogTabPosition = 0x19B9026F1D0; // Unknown = 
        public const ulong FIntAXHeadRefinementTooltipExpirationDurationDays = 0x19B9026C310; // Unknown = 
        public const ulong FIntAXLipMakeupZoomRadius = 0x19B9F009D50; // Unknown = 
        public const ulong FIntAXLookImpressionDeferTimeoutMs = 0x19BA3A56850; // Unknown = 
        public const ulong FIntAXLookOutfitCreationDelayMs = 0x19BA3A5B410; // Unknown = 
        public const ulong FIntAXLookOutfitCreationDelayMs1 = 0x19BA3A5B750; // Unknown = 
        public const ulong FIntAXLooksImageOffsetMultiplierX = 0x19B8F9DF590; // Unknown = 
        public const ulong FIntAXLooksImageOffsetMultiplierY = 0x19B8F9DF6D0; // Unknown = 
        public const ulong FIntAXLooksImageZoom = 0x19B8F9DF4D0; // Unknown = 
        public const ulong FIntAXMainNavHeight = 0x19B9026DB10; // Unknown = 
        public const ulong FIntAXMakeupCategoryPosition = 0x19BBC7A4690; // Unknown = 
        public const ulong FIntAXMakeupLayeringTooltipDismissTimeoutSeconds = 0x19B8FC36310; // Unknown = 
        public const ulong FIntAXMakeupLayeringTooltipMaxSeenCount = 0x19B8FC36810; // Unknown = 
        public const ulong FIntAXMakeupLayeringTooltipShowDelayMS = 0x19B8FC367D0; // Unknown = 
        public const ulong FIntAXMakeupLooksZoomRadius = 0x19B9F009C50; // Unknown = 
        public const ulong FIntAXMakeupMax6LayersPromptMaxSeenCount = 0x19B8FC361D0; // Unknown = 
        public const ulong FIntAXMakeupReleaseFtuxPromptDelayMS = 0x19B8FC37090; // Unknown = 
        public const ulong FIntAXMakeupZoomRadius = 0x19B9F009C10; // Unknown = 
        public const ulong FIntAXMaxAutocompleteSearchTextLen = 0x19B93A14890; // Unknown = 
        public const ulong FIntAXMaxRecentSearchTerms = 0x19B9029E890; // Unknown = 
        public const ulong FIntAXMaxRecentlyViewedSearchItems = 0x19B93A147B0; // Unknown = 
        public const ulong FIntAXMaxRecentlyViewedSearchItemsInCarousel = 0x19B93A14CF0; // Unknown = 
        public const ulong FIntAXMaxThumbnailsToPrefetchPerWidgetLargeScreen = 0x19B90648890; // Unknown = 
        public const ulong FIntAXMaxThumbnailsToPrefetchPerWidgetSmallScreen = 0x19B906482D0; // Unknown = 
        public const ulong FIntAXMaxUndoRedoHistory = 0x19B9026CA10; // Unknown = 
        public const ulong FIntAXMinSaveIntervalSeconds = 0x19BBB851E50; // Unknown = 
        public const ulong FIntAXMinSecsToRefreshRecommendedCatalogPage = 0x19BA3A50B90; // Unknown = 
        public const ulong FIntAXOutfitNameMaxLength = 0x19B8F906210; // Unknown = 
        public const ulong FIntAXPrefetchTTL = 0x19BA3A534D0; // Unknown = 
        public const ulong FIntAXPrefetchWidgetHydrationRowsLandscape = 0x19B8F903F10; // Unknown = 
        public const ulong FIntAXPrefetchWidgetHydrationRowsPortrait = 0x19B8F903CD0; // Unknown = 
        public const ulong FIntAXSearchAutocompleteDebounceMs = 0x19B93A16E40; // Unknown = 
        public const ulong FIntAXSkyboxBlockerPositionX = 0x19B90647C90; // Unknown = 
        public const ulong FIntAXSkyboxBlockerPositionY = 0x19B90647D10; // Unknown = 
        public const ulong FIntAXSkyboxBlockerPositionZ = 0x19B90647D90; // Unknown = 
        public const ulong FIntAXSkyboxBlockerSizeX = 0x19B90647B10; // Unknown = 
        public const ulong FIntAXSkyboxBlockerSizeY = 0x19B90647B90; // Unknown = 
        public const ulong FIntAXSkyboxBlockerSizeZ = 0x19B90647C10; // Unknown = 
        public const ulong FIntAXSlotBasedEditorAvatarSwitcherFtuxDelay2 = 0x19B9026CB50; // Unknown = 
        public const ulong FIntAXSlotBasedEditorCustomizeFtuxDelay2 = 0x19B9026CF90; // Unknown = 
        public const ulong FIntAXSponsoredItemsRow = 0x19B9026D6D0; // Unknown = 
        public const ulong FIntAXSubcategoryPillFadeAnimationDampingRatio = 0x19B9F00BCD0; // Unknown = 
        public const ulong FIntAXSubcategoryPillFadeAnimationDurationMs = 0x19B9F00C090; // Unknown = 
        public const ulong FIntAXSubcategoryPillFadeAnimationFrequency = 0x19B9F00C010; // Unknown = 
        public const ulong FIntAXTooltipMaxNumberOfTimesSeen = 0x19BA7FC1CD8; // Unknown = 
        public const ulong FIntAXTooltipTimeToDismiss = 0x19B9F00DAD0; // Unknown = 
        public const ulong FIntAXViewportCameraFieldOfView = 0x19B9F0A6510; // Unknown = 
        public const ulong FIntAXWidgetLoadedItemCountLimit = 0x19BA3A56C10; // Unknown = 
        public const ulong FIntAbuseReportMenuScreenshotReduceMotionWaitFrames = 0x19BB7F44250; // Unknown = 
        public const ulong FIntAbuseReportMenuScreenshotWaitFrames = 0x19BB7F42410; // Unknown = 
        public const ulong FIntAbuseReportTabClearCapturedScreenshotOnCloseFixDelay = 0x19B9FD8F8C8; // Unknown = 
        public const ulong FIntAccountPickerVariantOverride2 = 0x19B9ACB5190; // Unknown = 
        public const ulong FIntAccountRecoverySecondsBetweenResends = 0x19B88C4C490; // Unknown = 
        public const ulong FIntAccountSwitchRelaunchFallbackSeconds = 0x19B88C4D9D0; // Unknown = 
        public const ulong FIntAccountSwitcherAccountLimit = 0x19B88C4CC50; // Unknown = 
        public const ulong FIntAchievementGrantedThrottleHundrethsPercent = 0x19B9F923790; // Unknown = 
        public const ulong FIntActiveSquadInitPollingDelaySeconds = 0x19BA802EBD0; // Unknown = 
        public const ulong FIntActiveSquadPollingCardIntervalSeconds = 0x19BA8025310; // Unknown = 
        public const ulong FIntActiveSquadPollingIdleIntervalSeconds = 0x19BA8022CD0; // Unknown = 
        public const ulong FIntActiveSquadPollingLobbyIntervalSeconds = 0x19BA8029E10; // Unknown = 
        public const ulong FIntAdGuiInteractivityPixelsPerStud = 0x19BA8A0FE10; // Unknown = 
        public const ulong FIntAdIdentificationMinimumAreaPerMyriad = 0x19BBB7FC9D0; // Unknown = 
        public const ulong FIntAdIdentifiedTelemetryThrottleHundredthsPercent = 0x19BBB7F8550; // Unknown = 
        public const ulong FIntAddFriendsHttpRetryCount = 0x19B9011EB10; // Unknown = 
        public const ulong FIntAddUILessModeVariant = 0x19B84F31B60; // Unknown = 
        public const ulong FIntAgentTurnFeedbackEventThrottleHundredthsPercent = 0x19BAD58B1D0; // Unknown = 
        public const ulong FIntAiOverviewExplicitFeedbackThrottleHundrethsPercent = 0x19BA6793810; // Unknown = 
        public const ulong FIntAiOverviewSentimentThrottleHundrethsPercent = 0x19BA6794B90; // Unknown = 
        public const ulong FIntAllFriendsCacheTtlSec = 0x19B8F90E410; // Unknown = 
        public const ulong FIntAppChatBehaviorCollectionEnabledPercentage = 0x19BACE7B090; // Unknown = 
        public const ulong FIntAppChatChatLandingInitialFetchLimit = 0x19B8FA1E790; // Unknown = 
        public const ulong FIntAppChatChatLandingInitialFetchMinimumConversations = 0x19B8FA1E4D0; // Unknown = 
        public const ulong FIntAppChatGetAllMessagesDepth = 0x19BAC4BC458; // Unknown = 
        public const ulong FIntAppChatInExperienceDisplayOrder = 0x19BA8024350; // Unknown = 
        public const ulong FIntAppChatInExperienceMountMinLoadingTimeMs = 0x19BA8029090; // Unknown = 
        public const ulong FIntAppChatInitialMessageFetchLimit = 0x19BACE77A90; // Unknown = 
        public const ulong FIntAppChatMessageFetchRetryDelayMs = 0x19BACE76050; // Unknown = 
        public const ulong FIntAppChatMessageInitialFetchMinMessages = 0x19BACE78950; // Unknown = 
        public const ulong FIntAppChatMessageLongPressDismissDelayMs = 0x19BACE71150; // Unknown = 
        public const ulong FIntAppChatMessageLongPressDistanceThreshold = 0x19BACE70B90; // Unknown = 
        public const ulong FIntAppChatModalSeenImpressionDelayMs = 0x19BACE7D9D0; // Unknown = 
        public const ulong FIntAppChatNetworkingHttpRetryCount = 0x19BA607F190; // Unknown = 
        public const ulong FIntAppChatNetworkingTelemetryThrottlingThousandths = 0x19BA515AC10; // Unknown = 
        public const ulong FIntAppChatNewMessageFetchMaxDepth = 0x19B9026B790; // Unknown = 
        public const ulong FIntAppChatOsaAutoScrollDelayMs = 0x19BACE7A250; // Unknown = 
        public const ulong FIntAppChatPerfChatConversationPaginationInitialRender = 0x19BACE7FB90; // Unknown = 
        public const ulong FIntAppChatPerfChatConversationPaginationOnEndReached = 0x19BAFB62CB0; // Unknown = 
        public const ulong FIntAppChatPerfChatConversationPaginationOnStartReached = 0x19BACE74C50; // Unknown = 
        public const ulong FIntAppChatPerfChatConversationPaginationWindowSize = 0x19BACE7C090; // Unknown = 
        public const ulong FIntAppChatPerfChatLandingPaginationInitialRender = 0x19B8FA1F290; // Unknown = 
        public const ulong FIntAppChatPerfChatLandingPaginationOnEndReachedUnits = 0x19B8FA1F410; // Unknown = 
        public const ulong FIntAppChatPerfChatLandingPaginationOnStartReachedUnits = 0x19B8FA1F390; // Unknown = 
        public const ulong FIntAppChatPerfChatLandingPaginationWindowSize = 0x19B8FA1F090; // Unknown = 
        public const ulong FIntAppChatReplyIconSwipeOffset = 0x19BACE72CD0; // Unknown = 
        public const ulong FIntAppChatRoduxNetworkingHttpRetryCount = 0x19B9026B150; // Unknown = 
        public const ulong FIntAppChatScrollPerfMinDistancePx = 0x19BA802CD50; // Unknown = 
        public const ulong FIntAppChatScrollPerfMinStableFrames = 0x19BA80286D0; // Unknown = 
        public const ulong FIntAppChatSwipeCompleteThreshold = 0x19BACE75CD0; // Unknown = 
        public const ulong FIntAppChatSwipeMaxVerticalDrift = 0x19BACE711D0; // Unknown = 
        public const ulong FIntAppChatSwipeStartThreshold = 0x19BA4A7D888; // Unknown = 
        public const ulong FIntAppChatWideBreakpointMinHeight = 0x19B86E1B888; // Unknown = 
        public const ulong FIntAppChatWideBreakpointMinWidth = 0x19B8FA16190; // Unknown = 
        public const ulong FIntAppHover1VolumePercentage = 0x19B8C345810; // Unknown = 
        public const ulong FIntAppIaScrollAwayThreshold = 0x19BA609DBD0; // Unknown = 
        public const ulong FIntAppLaunchReactProfilerLoggerCollectionTimeoutSec = 0x19BA609BF90; // Unknown = 
        public const ulong FIntAppLaunchTrackerEnableHundredthsPercent = 0x19B8C315910; // Unknown = 
        public const ulong FIntAppMusicVolumePercentage = 0x19B90293310; // Unknown = 
        public const ulong FIntAppNotificationHighVolumePercentage = 0x19B8C345950; // Unknown = 
        public const ulong FIntAppSelectVolumePercentage = 0x19B8C345AD0; // Unknown = 
        public const ulong FIntAttributionContextRecordedThrottleHundredthsPercent = 0x19B90290FD0; // Unknown = 
        public const ulong FIntAuthButtonClickedThrottlingHundredthsPercent = 0x19BBC1C9FD0; // Unknown = 
        public const ulong FIntAuthPageMountThrottlingHundredthsPercent = 0x19BBC1CE5D0; // Unknown = 
        public const ulong FIntAutoFocusFailsafeThreshold = 0x19B8F9087D0; // Unknown = 
        public const ulong FIntAutoJoinNewServerTimeMs = 0x19B9AF14550; // Unknown = 
        public const ulong FIntAvatarChatHeartbeatStatsEventThrottleHundrethsPercent = 0x19B9F0AC450; // Unknown = 
        public const ulong FIntAvatarEditorParticleEmitterRateOverride = 0x19B90647750; // Unknown = 
        public const ulong FIntAvatarEditorTimeBetweenSaves = 0x19B90646A50; // Unknown = 
        public const ulong FIntAvatarGoldenRatio = 0x19D8952F310; // Unknown = 
        public const ulong FIntAvatarSwitcherGridOnEndReachedThreshold = 0x19BC2215B50; // Unknown = 
        public const ulong FIntBlackbirdUpsellBannerMaxSessionImpressions = 0x19B9EE00490; // Unknown = 
        public const ulong FIntBlackbirdUpsellMaxPriceForDiscountInclusive = 0x19B9AF1CBD0; // Unknown = 
        public const ulong FIntBlackbirdUpsellMinPriceForDiscountInclusive = 0x19B9AF1C210; // Unknown = 
        public const ulong FIntBlockUserButtonClickThrottleHundredthsPercent = 0x19BBC386810; // Unknown = 
        public const ulong FIntBlockUserButtonClickThrottleHundredthsPercent4 = 0x19BBC38D710; // Unknown = 
        public const ulong FIntBlockUserThrottleHundredthsPercent = 0x19BBC385310; // Unknown = 
        public const ulong FIntBlockUserThrottleHundredthsPercent4 = 0x19BBC389990; // Unknown = 
        public const ulong FIntBubbleChatAddMessageRolloutPercent = 0x19BACE7C390; // Unknown = 
        public const ulong FIntBugReporterErrorHundredthsPercent = 0x19B90293AD0; // Unknown = 
        public const ulong FIntBugReporterMilestoneHundredthsPercent = 0x19B90293890; // Unknown = 
        public const ulong FIntBugReportingHttpRetryCount = 0x19B90293C50; // Unknown = 
        public const ulong FIntBuildAgentDetailsStatusMenuWidth = 0x19BAD58C150; // Unknown = 
        public const ulong FIntBuildCreatorCreditPostTurnRefreshDelaySeconds = 0x19BAD58CF50; // Unknown = 
        public const ulong FIntBuildCreatorCreditResetRefreshBufferSeconds = 0x19BAD58CD50; // Unknown = 
        public const ulong FIntBuildExperienceAssistantStatusSwapIntervalSeconds = 0x19BAD28EB10; // Unknown = 
        public const ulong FIntBuildExperienceAssistantThinkingDurationSuffixDelaySeconds = 0x19BAD28E710; // Unknown = 
        public const ulong FIntBuildExperienceAudienceTooltipMaxWidth = 0x19BAD58F1D0; // Unknown = 
        public const ulong FIntBuildExperienceEventThrottleHundredthsPercent = 0x19B859C9CD0; // Unknown = 
        public const ulong FIntBuildExperienceRollbackPlaceMaxRetries = 0x19BAD28FED0; // Unknown = 
        public const ulong FIntBuildExperienceRollbackPlaceRetryDelayMs = 0x19BAD28FD10; // Unknown = 
        public const ulong FIntBuildExperienceSetAudiencesMaxRetries = 0x19BAD58EF90; // Unknown = 
        public const ulong FIntBuildExperienceSetAudiencesRetryDelayMs = 0x19BAD58ED10; // Unknown = 
        public const ulong FIntBuildExperienceTurnActivityGapMsThrottleHundredthsPercent = 0x19BAD58AAD0; // Unknown = 
        public const ulong FIntBuildExperienceUserPickerSearchDebounceMs = 0x19BAD58FD90; // Unknown = 
        public const ulong FIntBuildHistoryLoadTriggerViewportHeightPercent = 0x19BAD587D50; // Unknown = 
        public const ulong FIntBuildMinimumUsableRobuxBalance = 0x19BAD58CE10; // Unknown = 
        public const ulong FIntBuildOverflowMenuWidth = 0x19BAD585490; // Unknown = 
        public const ulong FIntBuildPolicyRefreshTimeoutMs = 0x19BACE73310; // Unknown = 
        public const ulong FIntBuildPublishPreviewCardMaxWidth = 0x19BACE71550; // Unknown = 
        public const ulong FIntBuilderSansNavBarMaxSize = 0x19B906493D0; // Unknown = 
        public const ulong FIntBuilderSansNavBarMinSize = 0x19B90649490; // Unknown = 
        public const ulong FIntBulkPurchaseEnabledCountdownMS = 0x19B9F927C50; // Unknown = 
        public const ulong FIntBulkPurchaseMaxHttpRequestRetries = 0x19B9F9294D0; // Unknown = 
        public const ulong FIntBulkPurchaseMaxHttpRequestWaitTime = 0x19B9F92A210; // Unknown = 
        public const ulong FIntBulkPurchaseMissingPurchaseOptionsCounterThrottleHundredthsPercent = 0x19BC27C7380; // Unknown = 
        public const ulong FIntBulkPurchaseRequestLimit = 0x19B9ACB95D0; // Unknown = 
        public const ulong FIntBulkPurchaseThrottleLimit = 0x19B9ACB81D0; // Unknown = 
        public const ulong FIntCameraPresetHeadshotExtentScaleHundredths = 0x19D8952F8D0; // Unknown = 
        public const ulong FIntCaptureControlsStoredAnchorPoints = 0x19D86F0AD50; // Unknown = 
        public const ulong FIntCaptureMetadataGetAvatarsTimeoutMs = 0x19BAC87FC10; // Unknown = 
        public const ulong FIntCaptureMetadataMaxAvatars = 0x19BAC87F890; // Unknown = 
        public const ulong FIntCaptureMetadataMinAvatarBoundingBoxPixels = 0x19BA6C40030; // Unknown = 
        public const ulong FIntCaptureMetadataMinHitRatePercentage = 0x19D8504BE70; // Unknown = 
        public const ulong FIntCapturesCommonMaxHttpRequestRetries = 0x19BAC876490; // Unknown = 
        public const ulong FIntCapturesCommonMaxHttpRequestWaitTime = 0x19B9298EBE0; // Unknown = 
        public const ulong FIntCapturesCoreGuiEventsPerMyriad = 0x19BACE94E90; // Unknown = 
        public const ulong FIntCapturesMaxHttpRequestRetries = 0x19BAC87DB50; // Unknown = 
        public const ulong FIntCapturesMaxHttpRequestWaitTime = 0x19BAC87DC90; // Unknown = 
        public const ulong FIntCapturesSaveToExternalStorageLimit = 0x19BA4561D60; // Unknown = 
        public const ulong FIntCapturesTelemetryThrottlingThousandths = 0x19BAC87D290; // Unknown = 
        public const ulong FIntChallengeDialogEventReceiverHttpRetryCount = 0x19B90641290; // Unknown = 
        public const ulong FIntChallengeDialogModalContainerHttpRetryCount = 0x19B90642990; // Unknown = 
        public const ulong FIntCharacterNameHandlerUserProfileApiRollout = 0x19B8C2E9B90; // Unknown = 
        public const ulong FIntChatAutocompleteMaxVisibleEntries = 0x19B9CB7B410; // Unknown = 
        public const ulong FIntChatGetConversationsPageSize = 0x19BA607CD10; // Unknown = 
        public const ulong FIntChatInterventionUIRateLimitWindowSec = 0x19BACE78590; // Unknown = 
        public const ulong FIntChatModerationFrameLayoutOrder = 0x19B9FD8B550; // Unknown = 
        public const ulong FIntCheckLeaveGameUpsellCooldown = 0x19BACE9C050; // Unknown = 
        public const ulong FIntChromeWindowLayoutOrder = 0x19D81689C50; // Unknown = 
        public const ulong FIntCloseReactPageThrottleHundredthsPercent = 0x19BACFE7D90; // Unknown = 
        public const ulong FIntCommercePurchaseMaxHttpRequestRetries = 0x19B9FD84050; // Unknown = 
        public const ulong FIntCommercePurchaseMaxHttpRequestWaitTime = 0x19B9FD830D0; // Unknown = 
        public const ulong FIntCommsFAELockTimestamp = 0x19BBC7AB310; // Unknown = 
        public const ulong FIntCompactUpsellModalBreakpoint = 0x19BAC830250; // Unknown = 
        public const ulong FIntConnectionAmpGameJoinUpsellImpressionThrottleHundredthsPercent = 0x19BBC38C110; // Unknown = 
        public const ulong FIntConnectionAmpUnlockPlayIntentThrottleHundredthsPercent = 0x19BBC382890; // Unknown = 
        public const ulong FIntConnectionAutoReconnectBaseDelayMs = 0x19BA672CAD0; // Unknown = 
        public const ulong FIntConnectionAutoReconnectFirstDelayMs = 0x19BA672C890; // Unknown = 
        public const ulong FIntConnectionAutoReconnectJitterMs = 0x19BA672CED0; // Unknown = 
        public const ulong FIntConnectionAutoReconnectMaxDelayMs = 0x19BA672CD10; // Unknown = 
        public const ulong FIntConnectionAutoReconnectMaxDurationSeconds = 0x19BA672CE10; // Unknown = 
        public const ulong FIntContactImporterHttpRetryCount = 0x19BAFCFCA10; // Unknown = 
        public const ulong FIntContactImporterModalDisplayMaxCount = 0x19BAFCF1390; // Unknown = 
        public const ulong FIntContactImporterModalDisplayMinDays = 0x19BAFB29810; // Unknown = 
        public const ulong FIntContactImporterSyncMinHours = 0x19BAFCF2A10; // Unknown = 
        public const ulong FIntContactImporterUploadContactsMax = 0x19BAFCF3390; // Unknown = 
        public const ulong FIntContactImporterUploadContactsMin = 0x19BAFCF6DD0; // Unknown = 
        public const ulong FIntContactsSyncWarningImpressionsCountCap = 0x19BAFCF9850; // Unknown = 
        public const ulong FIntContentPostsThumbnailsInitialDelayTimeMs = 0x19BAC876A10; // Unknown = 
        public const ulong FIntContentPostsThumbnailsMaxRetries = 0x19BAC876C50; // Unknown = 
        public const ulong FIntCoreScriptBacktraceErrorReportPercentage = 0x19BA5530950; // Unknown = 
        public const ulong FIntCoreScriptBacktracePIIFilterEraseTimeoutSeconds = 0x19BA553A310; // Unknown = 
        public const ulong FIntCoreScriptBacktraceRepeatedErrorRateLimitCount = 0x19BA553CAD0; // Unknown = 
        public const ulong FIntCoreScriptBacktraceRepeatedErrorRateLimitPeriod = 0x19BA55358D0; // Unknown = 
        public const ulong FIntCoreScriptBacktraceRepeatedErrorRateLimitProcessIntervalTenths = 0x19BA553E690; // Unknown = 
        public const ulong FIntCoreScriptsProfilerDelaySeconds = 0x19B9FD86550; // Unknown = 
        public const ulong FIntCoreScriptsProfilerDurationSeconds = 0x19B9FD86690; // Unknown = 
        public const ulong FIntCoreScriptsProfilerSamplingHundredthsPercentv1 = 0x19B9FD86450; // Unknown = 
        public const ulong FIntCoreScriptsProfilerTelemetryLimit = 0x19B9FD86850; // Unknown = 
        public const ulong FIntCorescriptMemoryPeriodSeconds = 0x19B8F741B90; // Unknown = 
        public const ulong FIntCreatorAgentChatMaxCachedSessionHistories = 0x19BAD28A050; // Unknown = 
        public const ulong FIntCreatorAgentChatMaxReconciliationHistoryPages = 0x19BAD289E50; // Unknown = 
        public const ulong FIntCreatorAgentChatPollBackoffMultiplier = 0x19BAD289C90; // Unknown = 
        public const ulong FIntCreatorAgentChatPollMaxIntervalSeconds = 0x19BAD289A50; // Unknown = 
        public const ulong FIntCreatorAgentChatPollMinIntervalSeconds = 0x19BAD289810; // Unknown = 
        public const ulong FIntCreatorAgentChatPrefetchHistoryPagesOnRefresh = 0x19BAD289BD0; // Unknown = 
        public const ulong FIntCreatorAgentChatRpcTimeoutSeconds = 0x19BAD289210; // Unknown = 
        public const ulong FIntCreatorAgentChatRtnIdleFallbackSeconds = 0x19BAD289450; // Unknown = 
        public const ulong FIntCreatorAgentChatRtnSequenceGapFallbackSeconds = 0x19BAD289610; // Unknown = 
        public const ulong FIntCrossDeviceLoginRollout2 = 0x19B9026AA50; // Unknown = 
        public const ulong FIntCrossExperienceEventThrottleHunderedthsPercent = 0x19B8CA83EB0; // Unknown = 
        public const ulong FIntCurrencyTransferDeveloperCommissionRate = 0x19B9F92DA90; // Unknown = 
        public const ulong FIntCurrencyTransferMaxAmount = 0x19B9F92C690; // Unknown = 
        public const ulong FIntCurrencyTransferMinAmount = 0x19B9F92C510; // Unknown = 
        public const ulong FIntCurrencyTransferPlatformFeeRate = 0x19B9F92DD10; // Unknown = 
        public const ulong FIntCurrencyTransferTelemetryCounterThrottleHundredthsPercent = 0x19B9F92CC90; // Unknown = 
        public const ulong FIntDebounceAIRephraseSettingDelay = 0x19B9FD8A990; // Unknown = 
        public const ulong FIntDebounceChatSummariesSettingDelay = 0x19B9FD8B190; // Unknown = 
        public const ulong FIntDebounceDisconnectButtonDelay = 0x19B9FD8AF90; // Unknown = 
        public const ulong FIntDebugAvatarDataDelay = 0x19B906441D0; // Unknown = 
        public const ulong FIntDebugConnectDisconnectInterval = 0x19BA5158450; // Unknown = 
        public const ulong FIntDebugForceMSAASamples = 0x19B8512C130; // Unknown = 
        public const ulong FIntDebugLuaAppForceGamepad = 0x19BC05481D0; // Unknown = 
        public const ulong FIntDeepLinkNavigationLockThrottlingHundredthsPercent = 0x19BBC1CFB90; // Unknown = 
        public const ulong FIntDefaultInfiniteScrollRecommendationsFetchSize = 0x19B9026D9D0; // Unknown = 
        public const ulong FIntDefaultMaxPruneAccounts = 0x19B8FC38D90; // Unknown = 
        public const ulong FIntDeferredDeeplinkResolvedThrottleHundredthsPercent = 0x19B90290D10; // Unknown = 
        public const ulong FIntDeviceIntegrityNativeTimeoutMilliseconds = 0x19BA607E350; // Unknown = 
        public const ulong FIntDiscoverabilityModalHttpRetryCount = 0x19BAFCFD6D0; // Unknown = 
        public const ulong FIntDiscoveryAppLaunchErrorHundredthsPercent = 0x19B8C316310; // Unknown = 
        public const ulong FIntDiscoveryAppLaunchMilestonesHundredthsPercent = 0x19D86D69368; // Unknown = 
        public const ulong FIntDiscoveryClientAppStorageGetItemErrorThrottleHundredthsPercent = 0x19BA3A73F10; // Unknown = 
        public const ulong FIntDiscoveryEventErrorDetailsHundredthsPercent = 0x19BA3A711D0; // Unknown = 
        public const ulong FIntDiscoveryFeedStatsHundredthsPercent = 0x19B8F032A98; // Unknown = 
        public const ulong FIntDiscoveryResponseErrorEventHundredthsPercent = 0x19BA3A79590; // Unknown = 
        public const ulong FIntDiscoveryResponseSizeEventHundredthsPercent = 0x19BA3A70FD0; // Unknown = 
        public const ulong FIntDiscoverySduiErrorHundredthsPercent = 0x19B8FC32490; // Unknown = 
        public const ulong FIntDiscoverySduiInstrumentationHundredthsPercent = 0x19D86D60C68; // Unknown = 
        public const ulong FIntDiscoverySduiParamUsageHundredthsPercent = 0x19B8FC32E10; // Unknown = 
        public const ulong FIntDiscoverySduiTimerEventsHundredthsPercent = 0x19B8FC326D0; // Unknown = 
        public const ulong FIntDiscoverySduiTypeUsageHundredthsPercent = 0x19B8FC32BD0; // Unknown = 
        public const ulong FIntDiscoveryVideoEndEventHundredthsPercent = 0x19BA67214D0; // Unknown = 
        public const ulong FIntDiscoveryVideoLoadEventHundredthsPercent = 0x19BA6728750; // Unknown = 
        public const ulong FIntDiscoveryVideoLoopEventHundredthsPercent = 0x19BA672FA50; // Unknown = 
        public const ulong FIntDiscoveryVideoPlayEventHundredthsPercent = 0x19BA6727CD0; // Unknown = 
        public const ulong FIntDiscoveryWarningEventHundredthsPercent = 0x19BA6796010; // Unknown = 
        public const ulong FIntDrawerSwipeThresholdPercent = 0x19B9AF16D90; // Unknown = 
        public const ulong FIntDrawerSwipeVelocityThreshold = 0x19B9AF14BD0; // Unknown = 
        public const ulong FIntDynamicAbuseReportV2ThrottleHundredthsPercent = 0x19BB7F47510; // Unknown = 
        public const ulong FIntEditProfileMaxHttpRetries = 0x19B859CAC50; // Unknown = 
        public const ulong FIntEdpBannerBottomVisiblePercent = 0x19B90262950; // Unknown = 
        public const ulong FIntEdpFallbackActionBarPlayButtonWidth = 0x19B90262210; // Unknown = 
        public const ulong FIntEdpFullBleedOverlapOffset = 0x19B90262890; // Unknown = 
        public const ulong FIntEducationalPopupDisplayMaxCount = 0x19BB6EF91D0; // Unknown = 
        public const ulong FIntEnableContactInvitesForNonPhoneVerifiedRollout = 0x19B8C2E9D50; // Unknown = 
        public const ulong FIntEnableNewInviteMenuStyleRollout = 0x19B9F295550; // Unknown = 
        public const ulong FIntEnableSentryUARolloutPercentage = 0x19B90295350; // Unknown = 
        public const ulong FIntEnableUnifiedProductPurchaseFlowThrottleHundredthsPercent = 0x19D85DC7B10; // Unknown = 
        public const ulong FIntEventNetworkHttpRetryCount = 0x19B8FC37690; // Unknown = 
        public const ulong FIntEventStatusCheckIntervalSec = 0x19B8F90E690; // Unknown = 
        public const ulong FIntExpChatChatableUserCountSystemMessageMinUsers = 0x19BBC381790; // Unknown = 
        public const ulong FIntExpChatDefaultARButtonPadding = 0x19BA515F110; // Unknown = 
        public const ulong FIntExpChatDefaultARButtonPaddingInset = 0x19BA515C590; // Unknown = 
        public const ulong FIntExpChatGlobalChatTabClickedThrottlePerMyriad = 0x19BBACA5EC8; // Unknown = 
        public const ulong FIntExpChatHiddenMessagesPromptThresholdLowerBound = 0x19BA74A4490; // Unknown = 
        public const ulong FIntExpChatHiddenMessagesPromptThresholdUpperBound = 0x19BA74A4FD0; // Unknown = 
        public const ulong FIntExpChatMessageRenderUserThrottlePermyriad = 0x19BBCD70FD0; // Unknown = 
        public const ulong FIntExpChatMessageResponseThrottlePermyriad = 0x19BA74A4E50; // Unknown = 
        public const ulong FIntExpChatMessageResponseUserSamplePermyriad = 0x19BA74A49D0; // Unknown = 
        public const ulong FIntExpChatMicActivityHeartbeatIncrement = 0x19BBCD77290; // Unknown = 
        public const ulong FIntExpChatPresetActionThrottlePerMyriad = 0x19B8FA13A50; // Unknown = 
        public const ulong FIntExpChatPresetChatIconBadgeOverride = 0x19BAF80A470; // Unknown = 
        public const ulong FIntExpChatPresetChatLoadAnalyticsTimeoutMs = 0x19BA74A2F90; // Unknown = 
        public const ulong FIntExpChatProximityStoreExtraRendersBeforeUnmount = 0x19B861B4778; // Unknown = 
        public const ulong FIntExpChatRandomCharChangeLowerBound = 0x19B9CB75190; // Unknown = 
        public const ulong FIntExpChatRandomCharChangeUpperBound = 0x19B9CB71B10; // Unknown = 
        public const ulong FIntExpChatRewriteDropdownToggledThrottlePerMyriad = 0x19B8FA121D0; // Unknown = 
        public const ulong FIntExpChatScrollLockThreshold = 0x19BA3A59990; // Unknown = 
        public const ulong FIntExpChatSlotBatchSize = 0x19BA5158350; // Unknown = 
        public const ulong FIntExpChatTabClickedThrottlePerMyriad = 0x19B8FA13250; // Unknown = 
        public const ulong FIntExpChatTabImpressionThrottlePerMyriad = 0x19B8FA138D0; // Unknown = 
        public const ulong FIntExpChatVisibleARButtonPadding = 0x19BA5159B10; // Unknown = 
        public const ulong FIntExpChatVisibleARButtonPaddingInset = 0x19BA515A990; // Unknown = 
        public const ulong FIntExpChatWindowScrollV3Debounce = 0x19BA3A5F310; // Unknown = 
        public const ulong FIntExpChatWindowTransparencyRewriteInteractableThreshold = 0x19BA515D950; // Unknown = 
        public const ulong FIntExpChatWindowTransparencyRewriteInteractableThresholdHundredth = 0x19BA5155810; // Unknown = 
        public const ulong FIntExperienceChatHeartbeatIncrement = 0x19BBCD72510; // Unknown = 
        public const ulong FIntExperienceChatUserProfileApiRollout_v1 = 0x19BA515B450; // Unknown = 
        public const ulong FIntExperienceDetailsMotionJitterHundredthsPercent = 0x19B90261890; // Unknown = 
        public const ulong FIntFAEBackgroundOnlyPollDelay = 0x19B90112CD0; // Unknown = 
        public const ulong FIntFAEBackgroundOnlyPollMaxRetries = 0x19B90113110; // Unknown = 
        public const ulong FIntFAEWithCallbackPollDelay = 0x19B901120D0; // Unknown = 
        public const ulong FIntFAEWithCallbackPollMaxRetries = 0x19B90112D10; // Unknown = 
        public const ulong FIntFAEWithWebViewCallbackPollDelay = 0x19B90113250; // Unknown = 
        public const ulong FIntFAEWithWebViewCallbackPollMaxRetries = 0x19B90113410; // Unknown = 
        public const ulong FIntFIntAXMinSaveIntervalSeconds = 0x19B9026C910; // Unknown = 
        public const ulong FIntFIntCrossExperienceEventThrottleHunderedthsPercent = 0x19B8ED7F990; // Unknown = 
        public const ulong FIntFIntInGameBuildChatSheetSnapPoint = 0x19BACE73190; // Unknown = 
        public const ulong FIntFIntLegacyPurchaseFPSTrackingTimeout = 0x19B9AF1BC50; // Unknown = 
        public const ulong FIntFIntMuteSelfThrottleHundredthsPercent4 = 0x19BBC386090; // Unknown = 
        public const ulong FIntFIntPeoplePageLayoutChangedThrottleHundredthsPercent = 0x19BBC386B50; // Unknown = 
        public const ulong FIntFIntPersonCardMenuToggledThrottleHundredthsPercent = 0x19BBC389C90; // Unknown = 
        public const ulong FIntFIntSocialUpsellEventThrottleHunderedthsPercent = 0x19BA6096BD0; // Unknown = 
        public const ulong FIntFIntUIResetDelayInSec = 0x19B9119EB80; // Unknown = 
        public const ulong FIntFIntUnmuteSelfThrottleHundredthsPercent4 = 0x19BBC386A90; // Unknown = 
        public const ulong FIntFPSAwareSplashScreenTimeout = 0x19BA8A088D0; // Unknown = 
        public const ulong FIntFTUXPanelXOffset = 0x19D81689DD0; // Unknown = 
        public const ulong FIntFacialAnimationStreamingHeartbeatStatsIntervalSec = 0x19B869BD520; // Unknown = 
        public const ulong FIntFallbackExclusiveUnderageCutoffForMultiPageSignup = 0x19B945A8BD0; // Unknown = 
        public const ulong FIntFeatureTileAdPlayerOverlayTransparencyPercent = 0x19B90643110; // Unknown = 
        public const ulong FIntFeedItemRowDataCounterThrottle = 0x19BBE91AE10; // Unknown = 
        public const ulong FIntFlyoutContentItemClickEventThrottleHunderedthsPercent = 0x19D86D67928; // Unknown = 
        public const ulong FIntFlyoutSidePanelCloseEventThrottleHunderedthsPercent = 0x19D7C7C85D0; // Unknown = 
        public const ulong FIntFlyoutSidePanelOpenEventThrottleHunderedthsPercent = 0x19D86D6DFA8; // Unknown = 
        public const ulong FIntFlyoutTestVariantRollout12 = 0x19BA3BBABD0; // Unknown = 
        public const ulong FIntFlyoutTooltipDismissEventThrottleHunderedthsPercent = 0x19D7C7C9190; // Unknown = 
        public const ulong FIntFlyoutTooltipShowEventThrottleHunderedthsPercent = 0x19D7C7C81D0; // Unknown = 
        public const ulong FIntFriendCarouselRefreshThrottleInterval = 0x19B8FA1D9D0; // Unknown = 
        public const ulong FIntFriendPlayerJoinedRemoteEventTimeout = 0x19BB2AFD050; // Unknown = 
        public const ulong FIntFriendRequestNicknameMaxChars = 0x19B901158D0; // Unknown = 
        public const ulong FIntFriendRequestNicknameMaxHistory = 0x19B90115A10; // Unknown = 
        public const ulong FIntFriendRequestNicknameMinChars = 0x19B90115790; // Unknown = 
        public const ulong FIntFriendRequestNicknamesMaxHttpRetries = 0x19B90115550; // Unknown = 
        public const ulong FIntFriendRequestNicknamesTelemetryThrottlingThousandths = 0x19B901156D0; // Unknown = 
        public const ulong FIntFriendsCarouselFetchPageDistance = 0x19B8C2EA0D0; // Unknown = 
        public const ulong FIntFriendsCarouselHttpRetryCount = 0x19B90267310; // Unknown = 
        public const ulong FIntFriendsCarouselInitialFetchSize = 0x19B8C2EAE90; // Unknown = 
        public const ulong FIntFriendsCarouselSocialBtnFriendsLimit = 0x19B8C2EAB90; // Unknown = 
        public const ulong FIntFriendsChatConversationListAutoscrollToTopThreshold = 0x19BA6B3A2D0; // Unknown = 
        public const ulong FIntFriendsChatConversationListInitialNumToRender = 0x19BA6B3A3D0; // Unknown = 
        public const ulong FIntFriendsChatConversationListPaginationThresholdRows = 0x19BA6B3A4D0; // Unknown = 
        public const ulong FIntFriendsChatConversationListScrollbarIdleHideMs = 0x19BA6B3A5D0; // Unknown = 
        public const ulong FIntFriendsChatConversationListScrollbarThickness = 0x19BA6B3A750; // Unknown = 
        public const ulong FIntFriendsChatConversationListWindowSize = 0x19BA6B3A950; // Unknown = 
        public const ulong FIntFriendsChatModeratedMaskMaxLength = 0x19B9F185D40; // Unknown = 
        public const ulong FIntFriendsChatModeratedMaskMinLength = 0x19B9F188710; // Unknown = 
        public const ulong FIntFriendsCommonAnalyticsThrottlingThousandths = 0x19B8F90E110; // Unknown = 
        public const ulong FIntFriendsCountCacheTtlSec = 0x19B8F90E510; // Unknown = 
        public const ulong FIntFriendsHttpRetryCount = 0x19BA5BDC610; // Unknown = 
        public const ulong FIntFriendsLandingHttpRetryCount = 0x19BAFB25870; // Unknown = 
        public const ulong FIntFriendsMenuHttpRetryCount = 0x19BACE76490; // Unknown = 
        public const ulong FIntFriendsPageSize = 0x19B8F90E590; // Unknown = 
        public const ulong FIntFriendsStoreProcessDelaySec = 0x19B8F90E290; // Unknown = 
        public const ulong FIntFriendshipStatusCacheTtlSec = 0x19BC255C8A0; // Unknown = 
        public const ulong FIntFullscreenTitleBarTriggerDelayMillis = 0x19D89521110; // Unknown = 
        public const ulong FIntGameCardContainerHttpRetryCount = 0x19BA8027D90; // Unknown = 
        public const ulong FIntGameConnectionsPlayedChipClickedThrottleHundredthsPercent = 0x19BA6726210; // Unknown = 
        public const ulong FIntGameCopyExperienceLinkThrottleHundrethsPercent = 0x19BA672C490; // Unknown = 
        public const ulong FIntGameCreatePrivateGameThrottleHundrethsPercent = 0x19BA6723BD0; // Unknown = 
        public const ulong FIntGameDetailsSubpageThrottleHundrethsPercent = 0x19BA672F110; // Unknown = 
        public const ulong FIntGameFavoriteThrottleHundrethsPercent = 0x19BA67238D0; // Unknown = 
        public const ulong FIntGameFollowThrottleHundrethsPercent = 0x19BA6726D50; // Unknown = 
        public const ulong FIntGameGridFlexFeedItemTileNumPerFeed = 0x19B88C2ED10; // Unknown = 
        public const ulong FIntGameInviteEntryPointThrottleHundredthsPercent = 0x19BBC380510; // Unknown = 
        public const ulong FIntGameInviteHttpRetryCount = 0x19D8952FBD0; // Unknown = 
        public const ulong FIntGameJoinCardAnalyticsThrottleHundredthsPercent = 0x19B8FA1B1D0; // Unknown = 
        public const ulong FIntGameJoinFriendsInGameThrottleHundrethsPercent = 0x19BA6723590; // Unknown = 
        public const ulong FIntGameShareExperienceLinkThrottleHundrethsPercent = 0x19B9F968758; // Unknown = 
        public const ulong FIntGameTileOverflowMenuActionThrottleHundrethsPercent = 0x19BA672E850; // Unknown = 
        public const ulong FIntGameVoteThrottleHundrethsPercent = 0x19BA672EF90; // Unknown = 
        public const ulong FIntGamepadMenuActionThrottleHundrethsPercent = 0x19BAD2807D0; // Unknown = 
        public const ulong FIntGamepadOpenExperienceControlsMenuThrottleHundrethsPercent = 0x19BAD280390; // Unknown = 
        public const ulong FIntGameplayPauseShowDelayMs = 0x19B9F0A7410; // Unknown = 
        public const ulong FIntGenericInterventionSnackbarAutoDismissDelaySeconds = 0x19BA8026ED0; // Unknown = 
        public const ulong FIntGetRewardMetadataHttpRetryCount = 0x19D8952B090; // Unknown = 
        public const ulong FIntGetServerChannelRetries = 0x19BACE9BD50; // Unknown = 
        public const ulong FIntHapticTriggerAttemptThrottleHundredthsPercent = 0x19B90261B10; // Unknown = 
        public const ulong FIntHelpPageThrottleHundredthsPercent = 0x19BB3F277D8; // Unknown = 
        public const ulong FIntHomePagePYMKPercentageOfViewPortToStartFetch = 0x19B90115290; // Unknown = 
        public const ulong FIntHomePagePYMKPresenceFetchThrottleInterval = 0x19B90115750; // Unknown = 
        public const ulong FIntHomepageReadyFailsafeTimeoutSeconds = 0x19B90648ED0; // Unknown = 
        public const ulong FIntIAFlyoutDailyTooltipMaxShownCount = 0x19D7C7CC910; // Unknown = 
        public const ulong FIntIAFlyoutTooltipMaxShownCount = 0x19D7C7CB990; // Unknown = 
        public const ulong FIntIDVMaxRetries = 0x19B8FC3A090; // Unknown = 
        public const ulong FIntIDVPollDelay = 0x19B8FC38B50; // Unknown = 
        public const ulong FIntIGARRaycastTargetCount = 0x19BBB7F7050; // Unknown = 
        public const ulong FIntIGARSubtreeDivergenceThresholdPerMille = 0x19BBB7F2990; // Unknown = 
        public const ulong FIntIGMTempOverrideGfxLv5 = 0x19B9FD8CC50; // Unknown = 
        public const ulong FIntIconSelectionTimeout = 0x19B9ACBFA10; // Unknown = 
        public const ulong FIntImageLoadObserverPollIntervalMs = 0x19B94812AD0; // Unknown = 
        public const ulong FIntInAppAchievementManagerHttpRetryCount = 0x19B9F9243D0; // Unknown = 
        public const ulong FIntInAppBugReporterMaxTitleLength = 0x19B90293610; // Unknown = 
        public const ulong FIntInAppBugReporterMinCommentLength = 0x19B90293E90; // Unknown = 
        public const ulong FIntInExpAchievementManagerHttpRetryCount = 0x19B9F924A10; // Unknown = 
        public const ulong FIntInExpAmpWizardDisplayOrder = 0x19B90113D90; // Unknown = 
        public const ulong FIntInExperienceClickoutToggledTelemetryThrottleHundredthsPercent = 0x19B9F920F90; // Unknown = 
        public const ulong FIntInExperienceDetailsPromptClosedHundredthsPercent = 0x19BA679E610; // Unknown = 
        public const ulong FIntInExperienceDetailsPromptDisplayOrder = 0x19B9FD86050; // Unknown = 
        public const ulong FIntInExperienceDetailsPromptLoadedHundredthsPercent = 0x19BA6797510; // Unknown = 
        public const ulong FIntInExperienceDetailsPromptOpenedHundredthsPercent = 0x19BA679AED0; // Unknown = 
        public const ulong FIntInExperienceDetailsPromptPlayClickedHundredthsPercent = 0x19BA51DB2A8; // Unknown = 
        public const ulong FIntInExperienceInterventionDisplayOrder = 0x19BACE79490; // Unknown = 
        public const ulong FIntInExperienceInterventionToastDuration = 0x19BACE780D0; // Unknown = 
        public const ulong FIntInExperienceShopTelemetryThrottleHundredthsPercent = 0x19D80F60C08; // Unknown = 
        public const ulong FIntInExperienceTransferMaxHttpRequestRetries = 0x19B9FD80710; // Unknown = 
        public const ulong FIntInExperienceTransferMaxHttpRequestWaitTime = 0x19B9FD808D0; // Unknown = 
        public const ulong FIntInGameBuildChatSheetSnapPoint = 0x19BB1C174F0; // Unknown = 
        public const ulong FIntInGameRobuxUpsellEventThrottleHundredthsPercent = 0x19BAC8363D0; // Unknown = 
        public const ulong FIntInitialFriendsPageSize = 0x19B8F90E610; // Unknown = 
        public const ulong FIntInitialTrustedFriendRequestsPageSize = 0x19B8C2E1550; // Unknown = 
        public const ulong FIntInitializeFmodMsDelay = 0x19D86F0D690; // Unknown = 
        public const ulong FIntInspectAndBuyClusterCompositionTimeoutMs = 0x19B9F0A5210; // Unknown = 
        public const ulong FIntInspectButtonThrottleHundredthsPercent = 0x19BBC38E350; // Unknown = 
        public const ulong FIntIntervalPerformanceTrackerEventStream = 0x19BA6A34110; // Unknown = 
        public const ulong FIntIntervalPerformanceTrackerEventThrottleHundrethsPercent = 0x19B9CB753D0; // Unknown = 
        public const ulong FIntInviteLinkExpiredModalHttpRetryCount = 0x19B859CAE90; // Unknown = 
        public const ulong FIntIosAuthServiceHealthCounterThrottlingHundredthsPercent = 0x19BBC1C5450; // Unknown = 
        public const ulong FIntIosAuthServiceLoginThrottlingHundredthsPercent = 0x19BBC1CFB50; // Unknown = 
        public const ulong FIntIsFriendsWithCacheTtlSec = 0x19B8F90E390; // Unknown = 
        public const ulong FIntIxpFlyoutControl = 0x19BA461AD10; // Unknown = 
        public const ulong FIntIxpFlyoutVariantAlternateEntry = 0x19BA4616810; // Unknown = 
        public const ulong FIntIxpFlyoutVariantHamburger = 0x19BA4618210; // Unknown = 
        public const ulong FIntIxpFlyoutVariantNoSubTabs = 0x19BA4617C10; // Unknown = 
        public const ulong FIntIxpFlyoutVariantRemovalRobuxIcon = 0x19BA4615DD0; // Unknown = 
        public const ulong FIntKeystoreTelemetryThrottlingHundredthsPercent = 0x19BBC1CC990; // Unknown = 
        public const ulong FIntKeystoreTimeout = 0x19BBC1C2F90; // Unknown = 
        public const ulong FIntLargeCollectionItemFractionalPercent = 0x19BA6791FD0; // Unknown = 
        public const ulong FIntLargeCollectionItemMaxItemCount = 0x19BA6796290; // Unknown = 
        public const ulong FIntLargeCollectionItemMinItemCount = 0x19BA6795A90; // Unknown = 
        public const ulong FIntLargeCollectionItemMinItemWidth = 0x19BA679F210; // Unknown = 
        public const ulong FIntLargeCollectionItemVerticalGap = 0x19BA67904D0; // Unknown = 
        public const ulong FIntLegacyPurchaseFPSTrackingTimeout = 0x19B88C766F0; // Unknown = 
        public const ulong FIntLinkingProtocolFetchRetries = 0x19B8578A6D0; // Unknown = 
        public const ulong FIntLinkingProtocolFetchTimeoutMS = 0x19B8578A790; // Unknown = 
        public const ulong FIntLivenessBackgroundOnlyPollDelay = 0x19BA607D7D0; // Unknown = 
        public const ulong FIntLivenessBackgroundOnlyPollMaxRetries = 0x19BA607EB90; // Unknown = 
        public const ulong FIntLivenessWithCallbackPollDelay = 0x19BA6070350; // Unknown = 
        public const ulong FIntLivenessWithCallbackPollMaxRetries = 0x19BA6076090; // Unknown = 
        public const ulong FIntLoadingScreenQueuedStateButtonClickThrottleHundredthsPercent = 0x19B9AF14710; // Unknown = 
        public const ulong FIntLogTreeMaxLogsToBacktrace = 0x19B8F90B7D0; // Unknown = 
        public const ulong FIntLoginByUsernameSSOErrorsThrottleHundrethsPercent = 0x19D8851A098; // Unknown = 
        public const ulong FIntLookAvatarRotationDegree1 = 0x19D8952F250; // Unknown = 
        public const ulong FIntLuaAppAccountSecurityPromptForcePopUpRenderAfterSeconds = 0x19B9029F290; // Unknown = 
        public const ulong FIntLuaAppAccountSecurityPromptPollingIntervalSeconds = 0x19B859CE390; // Unknown = 
        public const ulong FIntLuaAppAccountSecurityPromptPollingIntervalSecondsVisible = 0x19B948100D0; // Unknown = 
        public const ulong FIntLuaAppAccountSecurityPromptPopUpSpawnDelay = 0x19B94810210; // Unknown = 
        public const ulong FIntLuaAppAccountSecurityPromptRollout = 0x19B8558AEA0; // Unknown = 
        public const ulong FIntLuaAppAutocompleteSearchTextMaxLen = 0x19B9029EBD0; // Unknown = 
        public const ulong FIntLuaAppBackToTopClickEventThrottlingHundredthsPercent = 0x19BA67919D0; // Unknown = 
        public const ulong FIntLuaAppBatchFetchingStatusDelayMs = 0x19B85789190; // Unknown = 
        public const ulong FIntLuaAppChallengeDeviceAccessEventThrottlingPercent = 0x19BA515B810; // Unknown = 
        public const ulong FIntLuaAppChallengeDialogEventReceiverRetryIntervalSeconds = 0x19B90641210; // Unknown = 
        public const ulong FIntLuaAppChallengeDialogEventReceiverRetryTimes = 0x19B90640ED0; // Unknown = 
        public const ulong FIntLuaAppChallengeDialogPollingIntervalSeconds = 0x19B90642750; // Unknown = 
        public const ulong FIntLuaAppCredentialsProtocolAvailableTimeout = 0x19B8FC39AD0; // Unknown = 
        public const ulong FIntLuaAppCredentialsProtocolTimeout = 0x19B8FC39890; // Unknown = 
        public const ulong FIntLuaAppDataHydrationDefaultBatchSize = 0x19BA5BD3F10; // Unknown = 
        public const ulong FIntLuaAppDataHydrationDefaultRequestTimeoutSec = 0x19BA5BDEA10; // Unknown = 
        public const ulong FIntLuaAppDataHydrationQueueProcessDelaySec = 0x19BA5BD9590; // Unknown = 
        public const ulong FIntLuaAppDefaultDataTtlSec = 0x19BA5BDD790; // Unknown = 
        public const ulong FIntLuaAppDefaultFailedDataTtlSec = 0x19BA5BD1F90; // Unknown = 
        public const ulong FIntLuaAppDelayImpressionsMaxUpdates = 0x19B88C2EDD0; // Unknown = 
        public const ulong FIntLuaAppDiscoveryClientAppStorageCacheTtlDays = 0x19BA3A775D0; // Unknown = 
        public const ulong FIntLuaAppEdpMediaGalleryItemVisiblePercent = 0x19B88C2B2D0; // Unknown = 
        public const ulong FIntLuaAppEdpVideoAvailableRamThresholdMb = 0x19BBC388750; // Unknown = 
        public const ulong FIntLuaAppEdpVideoMaxMemoryThresholdMb = 0x19BBC3841D0; // Unknown = 
        public const ulong FIntLuaAppEnableReactProfilerHundredthsPercent = 0x19B85782710; // Unknown = 
        public const ulong FIntLuaAppFeedImpressionsHundredthsPercent = 0x19B8F9DEDD0; // Unknown = 
        public const ulong FIntLuaAppFriendsSortHeaderMaxHiddenPosition = 0x19BB1D9A810; // Unknown = 
        public const ulong FIntLuaAppGameAttributionErrorEventThrottleHundrethsPercent = 0x19BA6795490; // Unknown = 
        public const ulong FIntLuaAppGameDetailReferralEventThrottlingHundredthsPercent = 0x19BA6728510; // Unknown = 
        public const ulong FIntLuaAppGameDetailReferralShadowThrottlingHundredthsPercent = 0x19BA51DB2C8; // Unknown = 
        public const ulong FIntLuaAppGameGridBufferRowsAboveScreen = 0x19BBE91B290; // Unknown = 
        public const ulong FIntLuaAppGameGridBufferRowsBelowScreen = 0x19BBE91AED0; // Unknown = 
        public const ulong FIntLuaAppGameGridRevealMoreButtonGapPx = 0x19B88C2E8D0; // Unknown = 
        public const ulong FIntLuaAppGameIconLargeSizePx = 0x19BA5BDEF50; // Unknown = 
        public const ulong FIntLuaAppGameIconSmallSizePx = 0x19BA5BDF450; // Unknown = 
        public const ulong FIntLuaAppGameImpressionsEventThrottlingHundredthsPercent = 0x19BBE91B010; // Unknown = 
        public const ulong FIntLuaAppGameImpressionsShadowThrottlingHundredthsPercent = 0x19BBE91A590; // Unknown = 
        public const ulong FIntLuaAppGamePlayIntentEventThrottlingHundredthsPercent = 0x19BA6724690; // Unknown = 
        public const ulong FIntLuaAppGamePlayIntentShadowThrottlingHundredthsPercent = 0x19BA672F450; // Unknown = 
        public const ulong FIntLuaAppGameTileHoverDelayMs = 0x19BBE9115D0; // Unknown = 
        public const ulong FIntLuaAppGameTileVideoAvailableRamThresholdMb = 0x19BBE912D50; // Unknown = 
        public const ulong FIntLuaAppGameTileVideoDwellTimeInSec = 0x19B88C2C410; // Unknown = 
        public const ulong FIntLuaAppGameTileVideoMaxMemoryThresholdMb = 0x19BBE912710; // Unknown = 
        public const ulong FIntLuaAppGameTileVideoVisiblePercent = 0x19B88C2C650; // Unknown = 
        public const ulong FIntLuaAppGamesListSortTokenExpiryInSec = 0x19B90266C50; // Unknown = 
        public const ulong FIntLuaAppHomeFeedFriendsPosition = 0x19B94811C90; // Unknown = 
        public const ulong FIntLuaAppHomeFeedProfilePosition = 0x19B94811B50; // Unknown = 
        public const ulong FIntLuaAppHomeFeedUpsellCardPosition = 0x19B94811E50; // Unknown = 
        public const ulong FIntLuaAppIECVRVariantNoSpatialUI = 0x19BA3BB3290; // Unknown = 
        public const ulong FIntLuaAppIECVRVariantSpatialUIMovePanelToCenter = 0x19BA3BB7850; // Unknown = 
        public const ulong FIntLuaAppIECVRVariantSpatialUIWithDragging = 0x19B9F18B860; // Unknown = 
        public const ulong FIntLuaAppIECVRVariantSpatialUIWithoutDragging = 0x19B9F18BBE0; // Unknown = 
        public const ulong FIntLuaAppInvalidPlayIntentThrottlingHundredthsPercent = 0x19BA6729550; // Unknown = 
        public const ulong FIntLuaAppItemActionEventThrottlingHundredthsPercent = 0x19B8F9DFDD0; // Unknown = 
        public const ulong FIntLuaAppItemActionShadowThrottlingHundredthsPercent = 0x19D86D61CA8; // Unknown = 
        public const ulong FIntLuaAppItemImpressionsEventThrottlingHundredthsPercent = 0x19B8F9DF550; // Unknown = 
        public const ulong FIntLuaAppItemImpressionsShadowThrottlingHundredthsPercent = 0x19B8F9DF290; // Unknown = 
        public const ulong FIntLuaAppJoinGameFailureInfluxHundredthsPercentage = 0x19BA6797DD0; // Unknown = 
        public const ulong FIntLuaAppLaunchTrackerTimeoutSec = 0x19B8C317090; // Unknown = 
        public const ulong FIntLuaAppLoginRollout = 0x19B9026AD90; // Unknown = 
        public const ulong FIntLuaAppLoginRolloutIos = 0x19B9026AA10; // Unknown = 
        public const ulong FIntLuaAppLumberyakLogBound = 0x19B8F90B2D0; // Unknown = 
        public const ulong FIntLuaAppNxMApportioningDiagnosticThrottleHundredthsPercent = 0x19BA5BD3B10; // Unknown = 
        public const ulong FIntLuaAppOmniFeedInitialNumRows = 0x19B94810150; // Unknown = 
        public const ulong FIntLuaAppOmniFeedLoadNumRows = 0x19B948110D0; // Unknown = 
        public const ulong FIntLuaAppOmniFeedScrollAnimDurationMs = 0x19B94811210; // Unknown = 
        public const ulong FIntLuaAppOneByTwoTileGradientBottomHeightPercent = 0x19BBE91E910; // Unknown = 
        public const ulong FIntLuaAppOneByTwoTileGradientBottomTransparencyPercent = 0x19BBE91E250; // Unknown = 
        public const ulong FIntLuaAppOneByTwoTileGradientTopTransparencyPercent = 0x19BBE91F9D0; // Unknown = 
        public const ulong FIntLuaAppOneByTwoTileLogoWidthPercentLandscape = 0x19BBE91E290; // Unknown = 
        public const ulong FIntLuaAppOneByTwoTileLogoWidthPercentSquare = 0x19BBE91F710; // Unknown = 
        public const ulong FIntLuaAppPlayButtonLoadingDurationTelemetryThrottleHundredthsPercent = 0x19BA67210D0; // Unknown = 
        public const ulong FIntLuaAppPlayButtonSecondaryButtonGap = 0x19B88C2E290; // Unknown = 
        public const ulong FIntLuaAppPlayButtonThrottleTimeSeconds = 0x19B88C2E710; // Unknown = 
        public const ulong FIntLuaAppPlayButtonWizardCloseDelayMs = 0x19B88C2E950; // Unknown = 
        public const ulong FIntLuaAppPlayWithRewardMobileEdpLayoutOrder = 0x19B90640390; // Unknown = 
        public const ulong FIntLuaAppRecommendedGamesCount = 0x19BA5BD3510; // Unknown = 
        public const ulong FIntLuaAppSchedulerDeferredWork = 0x19B9ACB2D90; // Unknown = 
        public const ulong FIntLuaAppSchedulerDesiredFrameRate = 0x19B9ACBB650; // Unknown = 
        public const ulong FIntLuaAppSchedulerHeartbeatFrameMarker = 0x19B9ACBB510; // Unknown = 
        public const ulong FIntLuaAppSchedulerLookbackUseRingBuffer = 0x19B9ACBD110; // Unknown = 
        public const ulong FIntLuaAppSchedulerMinimumFrameRate = 0x19B9ACBB590; // Unknown = 
        public const ulong FIntLuaAppSchedulerNumberOfLookbackFrames = 0x19B9ACBA590; // Unknown = 
        public const ulong FIntLuaAppSchedulerTargetMsByHeartbeatDelta = 0x19B9ACBBC90; // Unknown = 
        public const ulong FIntLuaAppSchedulerYieldInterval = 0x19B9ACB2010; // Unknown = 
        public const ulong FIntLuaAppSduiCarouselPlaceholderHeaderHeightPx = 0x19B88C283D0; // Unknown = 
        public const ulong FIntLuaAppSduiCarouselPlaceholderHeaderMaxWidthPct = 0x19B9029B8D0; // Unknown = 
        public const ulong FIntLuaAppSduiCarouselPlaceholderHeaderMinWidthPct = 0x19B9029BC90; // Unknown = 
        public const ulong FIntLuaAppSearchAutocompleteDebounceMs = 0x19B9986B0E8; // Unknown = 
        public const ulong FIntLuaAppSessionWithErrorThrottlePercentage = 0x19B8F9092D0; // Unknown = 
        public const ulong FIntLuaAppShowMoreClickEventThrottlingHundredthsPercent = 0x19BA67989D0; // Unknown = 
        public const ulong FIntLuaAppSmallScreenDesignWidth = 0x19B859C6950; // Unknown = 
        public const ulong FIntLuaAppSponsoredAdLoadTelemetryThrottlingHundredthsPercent = 0x19BBE91D5D0; // Unknown = 
        public const ulong FIntLuaAppSponsoredAdUnloadTelemetryThrottlingHundredthsPercent = 0x19BBE91D490; // Unknown = 
        public const ulong FIntLuaAppSponsoredAdViewableImpressionTelemetryThrottlingHundredthsPercent = 0x19BBE91FA10; // Unknown = 
        public const ulong FIntLuaAppStartupReactSchedulerDelayMs = 0x19B8F908C50; // Unknown = 
        public const ulong FIntLuaAppStartupReactSchedulerInterval = 0x19B8F908E90; // Unknown = 
        public const ulong FIntLuaAppSubTabTopPadding = 0x19B9ACB4A10; // Unknown = 
        public const ulong FIntLuaAppThrottleInviteSendEndpointDelay = 0x19B9F296D90; // Unknown = 
        public const ulong FIntLuaAppThrottleRefreshPlayabilityIntervalSeconds = 0x19BC0547410; // Unknown = 
        public const ulong FIntLuaAppTransparentPageMaxCount = 0x19B90643410; // Unknown = 
        public const ulong FIntLuaAppTwoByOneTileGradientEndOpacityPercent = 0x19BBE91E490; // Unknown = 
        public const ulong FIntLuaAppTwoByOneTileGradientStartOpacityPercent = 0x19BBE91FE90; // Unknown = 
        public const ulong FIntLuaAppTwoByOneTileGradientWidthPercent = 0x19BBE91A710; // Unknown = 
        public const ulong FIntLuaAppTwoByOneTileLogoHeightPercentLandscape = 0x19BBE91D510; // Unknown = 
        public const ulong FIntLuaAppTwoByOneTileLogoHeightPercentSquare = 0x19BBE91DF10; // Unknown = 
        public const ulong FIntLuaAppTwoByOneTileSmallScreenBreakpoint = 0x19BBE91C5D0; // Unknown = 
        public const ulong FIntLuaAppUpdateImpressionsViewportBoundsPositionThreshold = 0x19B88C23A10; // Unknown = 
        public const ulong FIntLuaAppVideoAutoplayMaxDistanceToWinnerLinePercent = 0x19BBC38AC50; // Unknown = 
        public const ulong FIntLuaAppVideoAutoplayWinnerLineOffsetFromTopBarPx = 0x19BBC389D10; // Unknown = 
        public const ulong FIntLuaAppViewportBoundsScreenSizeThreshold = 0x19B88C24050; // Unknown = 
        public const ulong FIntLuaAppVngUpsellNagFrequencySec = 0x19B94812210; // Unknown = 
        public const ulong FIntLuaAppsAppsflyerIdCounterThrottle = 0x19B90291510; // Unknown = 
        public const ulong FIntLuaCoreScriptsErrorV2ThrottleHundredthPercentage = 0x19BA555C990; // Unknown = 
        public const ulong FIntLuaErrorV2ThrottleHundredthPercentage = 0x19B8F908B90; // Unknown = 
        public const ulong FIntLuaFetchUpdatedUserAgreementsErrorsThrottling = 0x19B859C9450; // Unknown = 
        public const ulong FIntLuaHttpClientPayloadSizeEventHundredthsPercent = 0x19BA5BDA510; // Unknown = 
        public const ulong FIntLuaHttpClientRequestStatusEventHundredthsPercent = 0x19BA5BD6E10; // Unknown = 
        public const ulong FIntLuaHttpClientRequestTimerEventHundredthsPercent = 0x19BA5BDB290; // Unknown = 
        public const ulong FIntLuaInExpSchedulerDeferredWork = 0x19B9ACB2ED0; // Unknown = 
        public const ulong FIntLuaInExpSchedulerDesiredFrameRate = 0x19B9ACBA090; // Unknown = 
        public const ulong FIntLuaInExpSchedulerHeartbeatFrameMarker = 0x19B9ACBEC50; // Unknown = 
        public const ulong FIntLuaInExpSchedulerLookbackUseRingBuffer = 0x19B9ACBD810; // Unknown = 
        public const ulong FIntLuaInExpSchedulerMinimumFrameRate = 0x19B9ACB0E90; // Unknown = 
        public const ulong FIntLuaInExpSchedulerNumberOfLookbackFrames = 0x19B9ACBD190; // Unknown = 
        public const ulong FIntLuaInExpSchedulerTargetMsByHeartbeatDelta = 0x19B9ACB78D0; // Unknown = 
        public const ulong FIntLuaInExpSchedulerYieldInterval = 0x19B9ACBBBD0; // Unknown = 
        public const ulong FIntLuaJoinYourFriendsRefreshInterval = 0x19B94810190; // Unknown = 
        public const ulong FIntLuaLogoutReasonsThrottleHundrethsPercent = 0x19B8FA1F1D0; // Unknown = 
        public const ulong FIntLuaLogoutThrottlingHundredthsPercent = 0x19BBC1C3C10; // Unknown = 
        public const ulong FIntLuaMaxCatalogTopics = 0x19B9026DC10; // Unknown = 
        public const ulong FIntLuaMaxItemsInTopicsRequest = 0x19B9026DC90; // Unknown = 
        public const ulong FIntLuaPushUpsellEventThrottleHundrethsPercent = 0x19B8FA1FD10; // Unknown = 
        public const ulong FIntLuaUIOcclusionMetricsReportingPeriodSeconds = 0x19B9ACB0A50; // Unknown = 
        public const ulong FIntLuaVoiceChatAnalyticsPointsThrottle = 0x19BBC9D5D10; // Unknown = 
        public const ulong FIntLuaVoiceChatThrottleHundrethsPercent = 0x19B8FDE8F50; // Unknown = 
        public const ulong FIntLuaVoiceVolumeControlsEligibilityThrottleHundredthsPercent = 0x19B8FDE8990; // Unknown = 
        public const ulong FIntLuaVoiceVolumeControlsImpressionsThrottleHundredthsPercent = 0x19B8FDE89D0; // Unknown = 
        public const ulong FIntMaquetesAppPanelDistanceMultiplierPercentage = 0x19B8C306950; // Unknown = 
        public const ulong FIntMaxDaysToShowCountDownLabel = 0x19BA6092510; // Unknown = 
        public const ulong FIntMaxIGMBackgroundTransparencyPercent = 0x19BA4E9A190; // Unknown = 
        public const ulong FIntMaxKickMessageLength = 0x19BA672C390; // Unknown = 
        public const ulong FIntMaxNumUniversesExposedToCardTooltip = 0x19BB7F4A990; // Unknown = 
        public const ulong FIntMaxReferredPlayerJoinToasts = 0x19B945A1690; // Unknown = 
        public const ulong FIntMaxTraversalHistoryCardsPerRow709 = 0x19BBE91B8D0; // Unknown = 
        public const ulong FIntMaxVideoCaptureDurationSeconds = 0x19D86F0C450; // Unknown = 
        public const ulong FIntMaximumTraversalHistoryItemsFetch = 0x19BBC388D10; // Unknown = 
        public const ulong FIntMediumCollectionItemFractionalPercent = 0x19BA6796D90; // Unknown = 
        public const ulong FIntMediumCollectionItemMaxItemCount = 0x19BA6790F50; // Unknown = 
        public const ulong FIntMediumCollectionItemMinItemCount = 0x19BA6793550; // Unknown = 
        public const ulong FIntMediumCollectionItemMinItemWidth = 0x19BB190E500; // Unknown = 
        public const ulong FIntMediumCollectionItemVerticalGap = 0x19BA67924D0; // Unknown = 
        public const ulong FIntMenuButtonsThrottleHundredthsPercent = 0x19BACFE7850; // Unknown = 
        public const ulong FIntMinDaysToShowCountDownLabel = 0x19BA609F890; // Unknown = 
        public const ulong FIntMinDaysToShowCountdownLabel = 0x19BA6095250; // Unknown = 
        public const ulong FIntMobileBreakpointInspectAndBuy = 0x19B859CB3D0; // Unknown = 
        public const ulong FIntMobileGameJoinCardBannerLoadCounterThrottleHundredthsPercent = 0x19B8FA1D250; // Unknown = 
        public const ulong FIntModalChallengeDialogApprovalHttpRetryCount = 0x19B906422D0; // Unknown = 
        public const ulong FIntModalChallengeDialogExpiredHttpRetryCount = 0x19B90642510; // Unknown = 
        public const ulong FIntModalImpressionThrottleHundrethsPercent = 0x19B90293850; // Unknown = 
        public const ulong FIntMomentDraftTTLDays = 0x19D86F010D0; // Unknown = 
        public const ulong FIntMomentsPreloadDecodeRetryDelayMs = 0x19D86F02A50; // Unknown = 
        public const ulong FIntMomentsPreloadDecodeWindowBack = 0x19D86F06010; // Unknown = 
        public const ulong FIntMomentsPreloadDecodeWindowForward = 0x19D86F08290; // Unknown = 
        public const ulong FIntMomentsPreloadDownloadWindowBack = 0x19D86F08790; // Unknown = 
        public const ulong FIntMomentsPreloadDownloadWindowForward = 0x19D86F0E650; // Unknown = 
        public const ulong FIntMomentsPreloadMaxDecodeRetries = 0x19D86F0E910; // Unknown = 
        public const ulong FIntMomentsScreenshotDurationSeconds = 0x19D86F03A50; // Unknown = 
        public const ulong FIntMomentsSurfaceLoadTTIMaxMs = 0x19B85786D10; // Unknown = 
        public const ulong FIntMomentsSurfaceLoadTTISamplingRate = 0x19B85786B90; // Unknown = 
        public const ulong FIntMomentsTTSDefaultVoiceId = 0x19D86F09C10; // Unknown = 
        public const ulong FIntMomentsTTSMaxCharacters = 0x19D86F0D550; // Unknown = 
        public const ulong FIntMomentsTTSWaveformMaxBarHeightPercent = 0x19D86F033D0; // Unknown = 
        public const ulong FIntMomentsTTSWaveformMaxSamples = 0x19D86F02890; // Unknown = 
        public const ulong FIntMomentsTTSWaveformMinBarHeightPercent = 0x19BAE770BB8; // Unknown = 
        public const ulong FIntMomentsTTSWaveformMinSamples = 0x19D86F032D0; // Unknown = 
        public const ulong FIntMomentsTTSWaveformSamplesPerSecond = 0x19D86F03D90; // Unknown = 
        public const ulong FIntMuteAllThrottleHundredthsPercent = 0x19BBC38AD90; // Unknown = 
        public const ulong FIntMutePlayerThrottleHundredthsPercent = 0x19BBC38DF10; // Unknown = 
        public const ulong FIntMuteSelfThrottleHundredthsPercent = 0x19BBC38FBD0; // Unknown = 
        public const ulong FIntMuteSelfThrottleHundredthsPercent4 = 0x19B9CCE21D0; // Unknown = 
        public const ulong FIntMyCreationsSessionListPollingIntervalSeconds = 0x19BAD58D910; // Unknown = 
        public const ulong FIntMyStatsExperienceAskForLogsMaxEntries = 0x19BAD588050; // Unknown = 
        public const ulong FIntMyStatsExperienceSearchDebounceMs = 0x19BAD58D650; // Unknown = 
        public const ulong FIntNewBadgeMaximumImpressionCount = 0x19B8FC333D0; // Unknown = 
        public const ulong FIntNewInGameMenuPercentRollout3 = 0x19BA3666ED0; // Unknown = 
        public const ulong FIntNotInterestedFeedbackFormActionThrottleHundredthsPercent = 0x19BBE914A10; // Unknown = 
        public const ulong FIntNotificationsUpsellModalHttpRetryCount = 0x19B8FA1F710; // Unknown = 
        public const ulong FIntOffPlatformFriendRequestsRolloutEnabled = 0x19BAFCF3DD0; // Unknown = 
        public const ulong FIntOldestUAVersionToReportErrors = 0x19B9F188470; // Unknown = 
        public const ulong FIntOmniFeedDividerHeightOverride = 0x19BA5205308; // Unknown = 
        public const ulong FIntOmniFeedDividerPaddingOverride = 0x19BC054B5D0; // Unknown = 
        public const ulong FIntOmniRecommendationsMetadataEventThrottlingHundredthsPercent = 0x19B902670D0; // Unknown = 
        public const ulong FIntOnlineFriendsCacheTtlSec = 0x19B8F90E310; // Unknown = 
        public const ulong FIntOpenLeavingRobloxModalThrottleHundrethsPercent = 0x19BA67938D0; // Unknown = 
        public const ulong FIntOpenReactPageThrottleHundredthsPercent = 0x19BACFE7E90; // Unknown = 
        public const ulong FIntOpenSearchResultsWithQueryDeeplinkEventThrottlingHundredthsPercent = 0x19BA6793C50; // Unknown = 
        public const ulong FIntPYMKCarouselHttpRetryCount = 0x19B8FC3AA10; // Unknown = 
        public const ulong FIntPYMKSeeAllTileLimit = 0x19B90115190; // Unknown = 
        public const ulong FIntParentalControlsScreentimeLockoutPollIntervalMs = 0x19B90290DD0; // Unknown = 
        public const ulong FIntPartyVoiceAudioFaderVolumePerc = 0x19B8ED7FC50; // Unknown = 
        public const ulong FIntPartyVoiceJoinRequestPulseCheckTimeout = 0x19B8C2E3550; // Unknown = 
        public const ulong FIntPartyVoiceRestrictionStatusMaxAttempts = 0x19BA8026C50; // Unknown = 
        public const ulong FIntPartyVoiceTelemetryThrottlingThousandths = 0x19B9F1866D0; // Unknown = 
        public const ulong FIntPartyVoiceTopbarActivityIndicatorAnimationMs = 0x19D80F6FED8; // Unknown = 
        public const ulong FIntPartyVoiceUndeafenDelayMS = 0x19B88C4B710; // Unknown = 
        public const ulong FIntPasskeyUpsellDisableButtonTimer = 0x19B90291C10; // Unknown = 
        public const ulong FIntPeekViewTransitionDelayTiming = 0x19B88C4BDD0; // Unknown = 
        public const ulong FIntPeoplePageLayoutChangedThrottleHundredthsPercent = 0x19B82C1A990; // Unknown = 
        public const ulong FIntPeoplePageLazyRenderThreshold = 0x19BB7F4B1D0; // Unknown = 
        public const ulong FIntPeoplePageVirtualizedGridBuffer = 0x19BB7F4D210; // Unknown = 
        public const ulong FIntPeopleServiceGameInviteEntryPointThrottleHundredthsPercent4 = 0x19BBC387150; // Unknown = 
        public const ulong FIntPeopleServiceInspectButtonThrottleHundredthsPercent4 = 0x19BBC38C3D0; // Unknown = 
        public const ulong FIntPeopleServiceMuteAllThrottleHundredthsPercent4 = 0x19BBC3853D0; // Unknown = 
        public const ulong FIntPeopleServiceMutePlayerThrottleHundredthsPercent4 = 0x19BBC385F90; // Unknown = 
        public const ulong FIntPeopleServicePerUserVoiceVolumeChangedThrottleHundredthsPercent = 0x19BBC384510; // Unknown = 
        public const ulong FIntPeopleServicePerUserVoiceVolumeMutedViaSliderThrottleHundredthsPercent = 0x19BBC3859D0; // Unknown = 
        public const ulong FIntPeopleServicePerUserVoiceVolumeSessionThrottleHundredthsPercent = 0x19BBC38E9D0; // Unknown = 
        public const ulong FIntPeopleServicePerUserVoiceVolumeSliderTouchThrottleHundredthsPercent = 0x19BBC383B50; // Unknown = 
        public const ulong FIntPeopleServicePerUserVoiceVolumeUnmutedViaSliderThrottleHundredthsPercent = 0x19BBC385E50; // Unknown = 
        public const ulong FIntPeopleServiceRequestFriendshipThrottleHundredthsPercent4 = 0x19BBC38C550; // Unknown = 
        public const ulong FIntPeopleServiceUnmuteAllThrottleHundredthsPercent4 = 0x19BBC388C90; // Unknown = 
        public const ulong FIntPeopleServiceUnmutePlayerThrottleHundredthsPercent4 = 0x19BBC38E390; // Unknown = 
        public const ulong FIntPerUserVoiceVolumeChangedThrottleHundredthsPercent = 0x19BBC385CD0; // Unknown = 
        public const ulong FIntPerUserVoiceVolumeMutedViaSliderThrottleHundredthsPercent = 0x19BBC3846D0; // Unknown = 
        public const ulong FIntPerUserVoiceVolumeSessionThrottleHundredthsPercent = 0x19BBC389E10; // Unknown = 
        public const ulong FIntPerUserVoiceVolumeSliderTouchThrottleHundredthsPercent = 0x19BBC386A10; // Unknown = 
        public const ulong FIntPerUserVoiceVolumeUnmutedViaSliderThrottleHundredthsPercent = 0x19BBC380FD0; // Unknown = 
        public const ulong FIntPerfInsightsHbMax = 0x19B90290D90; // Unknown = 
        public const ulong FIntPerfInsightsHbMin = 0x19B90290890; // Unknown = 
        public const ulong FIntPerfInsightsInMax = 0x19B902910D0; // Unknown = 
        public const ulong FIntPerfInsightsInMin = 0x19B90290AD0; // Unknown = 
        public const ulong FIntPersonCardMenuToggledThrottleHundredthsPercent = 0x19B82C1A9D0; // Unknown = 
        public const ulong FIntPersonaLivenessV2QrPollDelaySec = 0x19BA607CA50; // Unknown = 
        public const ulong FIntPersonaLivenessV2QrPollMaxRetries = 0x19BA6078350; // Unknown = 
        public const ulong FIntPlaceIdContainerHttpRetryCount = 0x19BA802EFD0; // Unknown = 
        public const ulong FIntPlatformEvidenceRolloutPercent = 0x19BA520EA10; // Unknown = 
        public const ulong FIntPlatformLeaderboardPushWaitTimeoutSeconds = 0x19BACE96A50; // Unknown = 
        public const ulong FIntPlayButtonContextualMessageImpressionHundredthsPercent = 0x19BA6791E90; // Unknown = 
        public const ulong FIntPlayWithRewardAdPlaybackAttemptedTelemetryThrottleHundredthsPercent = 0x19B859C9A50; // Unknown = 
        public const ulong FIntPlayWithRewardAdPlaybackStoppedTelemetryThrottleHundredthsPercent = 0x19B859C9D90; // Unknown = 
        public const ulong FIntPlayWithRewardAdReceivedTelemetryThrottleHundredthsPercent = 0x19B859C9590; // Unknown = 
        public const ulong FIntPlayWithRewardAdRequestedTelemetryThrottleHundredthsPercent = 0x19B859CA810; // Unknown = 
        public const ulong FIntPlayWithRewardBannerShownTelemetryThrottleHundredthsPercent = 0x19B859CA3D0; // Unknown = 
        public const ulong FIntPlayWithRewardBlackoutCurtainTelemetryThrottleHundredthsPercent = 0x19B859C9F10; // Unknown = 
        public const ulong FIntPlayWithRewardButtonClickedTelemetryThrottleHundredthsPercent = 0x19B859C9990; // Unknown = 
        public const ulong FIntPlayWithRewardCoachmarkMaxImpressions = 0x19B90640D50; // Unknown = 
        public const ulong FIntPlayWithRewardCoachmarkMaxImpressions2 = 0x19B90640F90; // Unknown = 
        public const ulong FIntPlayWithRewardCoachmarkTelemetryThrottleHundredthsPercent = 0x19B9011FE90; // Unknown = 
        public const ulong FIntPlayWithRewardCoachmarkWindowDays = 0x19B90640A50; // Unknown = 
        public const ulong FIntPlayWithRewardFallbackBannerProductImageAssetId = 0x19B906403D0; // Unknown = 
        public const ulong FIntPlayWithRewardGameJoinInitiatedTelemetryThrottleHundredthsPercent = 0x19B859C9950; // Unknown = 
        public const ulong FIntPlayWithRewardShimmerShownTelemetryThrottleHundredthsPercent = 0x19B859CA890; // Unknown = 
        public const ulong FIntPlaytestModeEnabledEventThrottleHundredthsPercent = 0x19D80F669A8; // Unknown = 
        public const ulong FIntPotentialClientTimeoutSeconds = 0x19BA672C2D0; // Unknown = 
        public const ulong FIntPresenceEventReceiverErrorEventThrottleHundrethsPercent = 0x19B902909D0; // Unknown = 
        public const ulong FIntPresenceHttpRetryCount = 0x19BA5BDEBD0; // Unknown = 
        public const ulong FIntPresenceImpressionLoggingThrottlePerMyriad = 0x19BA6795F10; // Unknown = 
        public const ulong FIntPresenceStorePollingTtlSec = 0x19BA5BD5510; // Unknown = 
        public const ulong FIntPresenceStoreProcessDelaySec = 0x19BA5BD8E90; // Unknown = 
        public const ulong FIntPresetChatCooldownLuaMs = 0x19B8FA13690; // Unknown = 
        public const ulong FIntProductPurchaseContainerFPSDuration = 0x19D85DC7E90; // Unknown = 
        public const ulong FIntProfileCTAHttpRetryCount = 0x19BA5BD0910; // Unknown = 
        public const ulong FIntProfileCTAStoreProcessDelaySec = 0x19BA5BDB5D0; // Unknown = 
        public const ulong FIntProfileInsightsStoreHttpTimeout = 0x19B9011E750; // Unknown = 
        public const ulong FIntProfilePlatformAnalyticsThrottlingThousandths = 0x19B90294350; // Unknown = 
        public const ulong FIntProfilePlatformHttpRetryCount = 0x19BAC87C5D0; // Unknown = 
        public const ulong FIntProfilePlatformInspectAvatarTooltipMaxImpressions = 0x19D80F5B428; // Unknown = 
        public const ulong FIntProfileQRCodeHttpRetryCount = 0x19BAFCFBF10; // Unknown = 
        public const ulong FIntProfileShareLinksAnalyticsThrottlingThousandths = 0x19BAFCF5690; // Unknown = 
        public const ulong FIntProfileShareLinksHttpRetryCount = 0x19BAFCFE8D0; // Unknown = 
        public const ulong FIntProgressLoadingBarMargin = 0x19B86E11C50; // Unknown = 
        public const ulong FIntProgressLoadingBarMaxWidth = 0x19B86E11BD0; // Unknown = 
        public const ulong FIntProgressLoadingDisplayOrder = 0x19B86E11CD0; // Unknown = 
        public const ulong FIntProgressLoadingTelemetryThrottleHundredthsPercent = 0x19B86E11D50; // Unknown = 
        public const ulong FIntPromptFriendRequestModalInputDelayMs = 0x19BA6077F10; // Unknown = 
        public const ulong FIntPurchaseVolumePercentage = 0x19B8C345B50; // Unknown = 
        public const ulong FIntPushUpsellChatCooldownPeriod = 0x19B8FA1FC90; // Unknown = 
        public const ulong FIntPushUpsellChatMaxPromptCount = 0x19B8FA1FAD0; // Unknown = 
        public const ulong FIntPushUpsellCooldownPeriod = 0x19B8FA1FF10; // Unknown = 
        public const ulong FIntPushUpsellMaxPromptCount = 0x19B8FA1FF90; // Unknown = 
        public const ulong FIntQuerySuggestionClickedEventThrottlingHundredthsPercent = 0x19BA6793410; // Unknown = 
        public const ulong FIntRAMaxAnnotationCount = 0x19D81689110; // Unknown = 
        public const ulong FIntRAMinEngineVersion = 0x19BA672D7D0; // Unknown = 
        public const ulong FIntRTEPresenceStorePollingTtlSec = 0x19BA5BD4F10; // Unknown = 
        public const ulong FIntRapidGameplayPauseIntervalMs = 0x19B9F0A71D0; // Unknown = 
        public const ulong FIntRapidGameplayPauseMinNotificationDurationMs = 0x19B9F0A7310; // Unknown = 
        public const ulong FIntReactDeletedTreeCleanUpLevel = 0x19BA5538150; // Unknown = 
        public const ulong FIntReactHighEndMemoryCutoff = 0x19BBC7A2310; // Unknown = 
        public const ulong FIntReactLowEndMemoryCutoff = 0x19BBC7A5AD0; // Unknown = 
        public const ulong FIntReactMicroprofilerLevel5 = 0x19BA553C510; // Unknown = 
        public const ulong FIntReactPerfTrackerKibana = 0x19B9FD84790; // Unknown = 
        public const ulong FIntReactPeriodSummaryEventThrottleHunderedthsPercent = 0x19BBC7A6FD0; // Unknown = 
        public const ulong FIntReactRootSummaryEventThrottleHunderedthsPercent2 = 0x19BBC7A5690; // Unknown = 
        public const ulong FIntReactSchedulerDesiredFrameRate = 0x19BA5537F90; // Unknown = 
        public const ulong FIntReactSchedulerMinFrameRate = 0x19BA553A210; // Unknown = 
        public const ulong FIntReactSchedulerNumberOfLookbackFrames = 0x19BA5533F10; // Unknown = 
        public const ulong FIntReactSchedulerYieldInterval2 = 0x19BA553A610; // Unknown = 
        public const ulong FIntReactSchedulingKllSketchMaxSize = 0x19BA366B2D0; // Unknown = 
        public const ulong FIntReactSchedulingTracker = 0x19BA366F610; // Unknown = 
        public const ulong FIntReactSchedulingTrackerPeriodMs = 0x19BA366FC90; // Unknown = 
        public const ulong FIntReactSchedulingTrackerStartUpDelayMs = 0x19B9FD85F90; // Unknown = 
        public const ulong FIntReactSessionSummaryEventThrottleHunderedthsPercent = 0x19BBC7A0AD0; // Unknown = 
        public const ulong FIntReferredPlayerJoinRemoteEventTimeout = 0x19B945A7F90; // Unknown = 
        public const ulong FIntRelocateMobileMenuButtonsVariant = 0x19B9FDDB088; // Unknown = 
        public const ulong FIntRenderCancelSubscriptionAppHttpRetryCount = 0x19B9FD82A50; // Unknown = 
        public const ulong FIntReportAnythingAvatarIdentificationCloseDiscardDistanceHundredths = 0x19BAC87F3D0; // Unknown = 
        public const ulong FIntReportAnythingAvatarIdentificationDiscardFractionSkipThresholdPercent = 0x19BAC87F510; // Unknown = 
        public const ulong FIntReportAnythingAvatarIdentificationOffScreenDiscardDistancePercent = 0x19BAC87F650; // Unknown = 
        public const ulong FIntReportDevConsoleTabEventsThrottleHundredthsPercent = 0x19BACFE6A50; // Unknown = 
        public const ulong FIntReportImmersiveBrandedAdHttpFaulreEventThrottleHundredthsPercent = 0x19BA8A0A550; // Unknown = 
        public const ulong FIntRequestFriendshipThrottleHundredthsPercent = 0x19BBC385510; // Unknown = 
        public const ulong FIntRequestRefundClickThrottleHundredthsPercent = 0x19BA679C490; // Unknown = 
        public const ulong FIntRobloxSubscriptionPurchasePollingTimeoutSeconds = 0x19B8FC33BD0; // Unknown = 
        public const ulong FIntRobloxSubscriptionUpsellTelemetryEventIngestThrottleHundredthsPercent = 0x19B8FC33790; // Unknown = 
        public const ulong FIntRobuxTransferFlowEventIngestThrottleHundredthsPercent = 0x19B9F92C810; // Unknown = 
        public const ulong FIntRomarkStartWithGraphicQualityLevel = 0x19B9FD8CD50; // Unknown = 
        public const ulong FIntSafetyBubbleRadius = 0x19BBE911590; // Unknown = 
        public const ulong FIntSafetyBubbleTransparencyPercent = 0x19BBE9136D0; // Unknown = 
        public const ulong FIntScaleBrazilContentRatingBadge = 0x19B9ACB5ED0; // Unknown = 
        public const ulong FIntScheduledSquadJustStartedThreshold = 0x19BACE78B50; // Unknown = 
        public const ulong FIntScriptProfilerLiveUpdateIntervalMS = 0x19BACFE4FD0; // Unknown = 
        public const ulong FIntScrollDetectorDelayMillis = 0x19BBE916590; // Unknown = 
        public const ulong FIntScrollDetectorTimeThresholdMillis = 0x19BBE915DD0; // Unknown = 
        public const ulong FIntScrollingPerfTrackerEventStream = 0x19B948113D0; // Unknown = 
        public const ulong FIntScrollingPerfTrackerKibana = 0x19B948114D0; // Unknown = 
        public const ulong FIntScrollingPerfTrackerSampleCountThreshold = 0x19B94811610; // Unknown = 
        public const ulong FIntScrollingPerfTrackerTargetFPS = 0x19B948117D0; // Unknown = 
        public const ulong FIntScrollingPickerMaximumPickerChangePerInput = 0x19BBC1C4ED0; // Unknown = 
        public const ulong FIntScrollingPickerSlowScrollStepWaitMs = 0x19BBC1CF950; // Unknown = 
        public const ulong FIntScrollingPickerSmallInputDecayFactor = 0x19BBC1C0C90; // Unknown = 
        public const ulong FIntSduiCreateSduiFeedStoreLogDelayMs = 0x19B9011F210; // Unknown = 
        public const ulong FIntSduiLoadMoreFromApiEventHundredthsPercent = 0x19B8F9DFED0; // Unknown = 
        public const ulong FIntSduiOmniFeedItemLogDelayMs = 0x19B9011FC50; // Unknown = 
        public const ulong FIntSduiPageRequestPriority = 0x19B8FC32290; // Unknown = 
        public const ulong FIntSduiPageTimerEventHundredthsPercent = 0x19B8F9DFC90; // Unknown = 
        public const ulong FIntSeamlessVoiceSTUXDisplayCount = 0x19BA5159B90; // Unknown = 
        public const ulong FIntSearchLandingPageSideMargin = 0x19B90269A50; // Unknown = 
        public const ulong FIntSelfieQrTimeoutSeconds = 0x19BA6076B90; // Unknown = 
        public const ulong FIntSendGameLinkMessageHttpRetryCount = 0x19BACE71BD0; // Unknown = 
        public const ulong FIntServeEnhancedVideoErrorTelemetryThrottleHundredthsPercent = 0x19B9F920710; // Unknown = 
        public const ulong FIntServerTriggeredModalTrafficPercent = 0x19B90294150; // Unknown = 
        public const ulong FIntSessionCheckDefaultTimeoutInSeconds = 0x19B90292310; // Unknown = 
        public const ulong FIntSetAliasAnalyticsThrottlingThousandths = 0x19B90118190; // Unknown = 
        public const ulong FIntSetAliasHttpRetryCount = 0x19B901185D0; // Unknown = 
        public const ulong FIntSetupNotificationsUpsellHttpRetryCount = 0x19B8FA1F950; // Unknown = 
        public const ulong FIntShareGameHttpRetryCount = 0x19BA6077850; // Unknown = 
        public const ulong FIntShareSheetMaxConversations = 0x19D7C7C5950; // Unknown = 
        public const ulong FIntShareSheetNumAvatarSkeletons = 0x19D7C7C3D10; // Unknown = 
        public const ulong FIntShareSheetSnackbarAutoDismissSeconds = 0x19D7C7CDB90; // Unknown = 
        public const ulong FIntShareSheetTelemetryThrottleHundredthsPercent = 0x19D80F41818; // Unknown = 
        public const ulong FIntShopPrefetchRetryBackoffMs = 0x19BC2202CC8; // Unknown = 
        public const ulong FIntShouldShowPushUpsellHideResponseCacheExpirationTime = 0x19B8FA1F250; // Unknown = 
        public const ulong FIntShowFriendRecommendationsLimit = 0x19B90267590; // Unknown = 
        public const ulong FIntSideSheetVariant = 0x19B9ACB4C90; // Unknown = 
        public const ulong FIntSideSheetVariant2 = 0x19B9ACBFED0; // Unknown = 
        public const ulong FIntSidesheetClosedEventThrottleHundredthsPercent = 0x19BA4E96010; // Unknown = 
        public const ulong FIntSignUpBirthdayPickerManualSelectVariantOverride = 0x19B9ACB9790; // Unknown = 
        public const ulong FIntSignupMinimumAge = 0x19B945A3F90; // Unknown = 
        public const ulong FIntSilentPasskeyUpgradeThrottlingHundredthsPercent = 0x19BBC1C09D0; // Unknown = 
        public const ulong FIntSilentUpgradeReauthDelaySeconds = 0x19B90291490; // Unknown = 
        public const ulong FIntSinglePageSignupMinimumAge = 0x19B9ACB4190; // Unknown = 
        public const ulong FIntSkyStyleDayClockTime = 0x19BA6A33410; // Unknown = 
        public const ulong FIntSmallCollectionItemFractionalPercent = 0x19BA679C790; // Unknown = 
        public const ulong FIntSmallCollectionItemMaxItemCount = 0x19BA6797290; // Unknown = 
        public const ulong FIntSmallCollectionItemMinItemCount = 0x19BA6791A10; // Unknown = 
        public const ulong FIntSmallCollectionItemMinItemWidth = 0x19BA6792A90; // Unknown = 
        public const ulong FIntSmallCollectionItemVerticalGap = 0x19BA679F550; // Unknown = 
        public const ulong FIntSnapLevelInVirtualCursor = 0x19BA59B7F10; // Unknown = 
        public const ulong FIntSocalCarouselMaxNewRequestsCount = 0x19BB787E650; // Unknown = 
        public const ulong FIntSocialBlockingModalAnalyticsThrottlingThousandths = 0x19D86D6C568; // Unknown = 
        public const ulong FIntSocialCarouselAnalyticsThrottlingThousandths = 0x19B8FA1E010; // Unknown = 
        public const ulong FIntSocialCarouselMaxNewRequestsCount = 0x19B8FA1E850; // Unknown = 
        public const ulong FIntSocialCarouselShowRecsLimit = 0x19B8FA1DBD0; // Unknown = 
        public const ulong FIntSocialContextToastDelay = 0x19B91162FA0; // Unknown = 
        public const ulong FIntSocialContextToastHttpRetryCount = 0x19B9F923190; // Unknown = 
        public const ulong FIntSocialExperienceJoinAnalyticsThrottlingThousandths = 0x19BA6794A50; // Unknown = 
        public const ulong FIntSocialExperienceJoinHttpRetryCount = 0x19BA679D550; // Unknown = 
        public const ulong FIntSocialGraphSyncRequestRetryCount = 0x19B90293450; // Unknown = 
        public const ulong FIntSocialLinkClickTelemetryThrottlePermyriad = 0x19BA679FFD0; // Unknown = 
        public const ulong FIntSocialLinksImpressionsEventHundredthsPercent = 0x19BA6794050; // Unknown = 
        public const ulong FIntSocialStopwatchTelementyThrottleHundrethsPercent = 0x19D86D6F8A8; // Unknown = 
        public const ulong FIntSocialTabStateHttpRetryCount = 0x19B9026F6D0; // Unknown = 
        public const ulong FIntSocialTabsPageHttpRetryCount = 0x19B9011F110; // Unknown = 
        public const ulong FIntSocialUpsellEventThrottleHunderedthsPercent = 0x19BB6B3EF70; // Unknown = 
        public const ulong FIntSongDetailsRefreshIntervalSeconds = 0x19B88C2EB90; // Unknown = 
        public const ulong FIntSongbirdTelemetryThrottle = 0x19D8029AD10; // Unknown = 
        public const ulong FIntSortDeeplinkFailureEventThrottleHundrethsPercent = 0x19BA67232D0; // Unknown = 
        public const ulong FIntSpatialUIChromeSubMenuHeight = 0x19B9FD87710; // Unknown = 
        public const ulong FIntSpatialUIDarkenBackgroundTransparency = 0x19B9FD887D0; // Unknown = 
        public const ulong FIntSpatialUIPanelDistance = 0x19B9FD86F50; // Unknown = 
        public const ulong FIntSpatialUIPanelDragBarDistance = 0x19B9FD87AD0; // Unknown = 
        public const ulong FIntSpatialUIPanelZOffset = 0x19B9FD87A50; // Unknown = 
        public const ulong FIntSpatialUIResolutionScale = 0x19B9FD879D0; // Unknown = 
        public const ulong FIntSpatialUIVersionTextSizeScaled = 0x19B9FD88910; // Unknown = 
        public const ulong FIntSquadExperienceInvitePollingIntervalSeconds = 0x19BA802DED0; // Unknown = 
        public const ulong FIntSquadExperienceInviteTimeoutSeconds = 0x19BA802DF50; // Unknown = 
        public const ulong FIntSquadHttpRetryCount = 0x19BA6721810; // Unknown = 
        public const ulong FIntSquadRegroupPromptDebounceTimeMs = 0x19BA8027350; // Unknown = 
        public const ulong FIntStreamingPauseUIAnalyticsThrottleHP = 0x19B9F0A76D0; // Unknown = 
        public const ulong FIntSubscriptionPurchaseFlowEventIngestThrottleHundredthsPercent = 0x19B8FC33B50; // Unknown = 
        public const ulong FIntSurvBloxRequiredCooldownMs = 0x19B90290250; // Unknown = 
        public const ulong FIntSwitchServerTelemetryThrottleHundrethsPercent = 0x19D80F62328; // Unknown = 
        public const ulong FIntSystemBarHeightMultiplierPercentageOverride = 0x19B99880650; // Unknown = 
        public const ulong FIntTTIUnifiedPurchaseSamplingRate = 0x19B9AF1B010; // Unknown = 
        public const ulong FIntTalkingChangedDebounceTime = 0x19B8FDE8ED0; // Unknown = 
        public const ulong FIntTeleportBackAttemptLimit = 0x19BBE91C690; // Unknown = 
        public const ulong FIntTeleportBackRetryDelay = 0x19BBE91DC10; // Unknown = 
        public const ulong FIntTenFootSkyboxBlockerPositionX = 0x19B859CB510; // Unknown = 
        public const ulong FIntTenFootSkyboxBlockerPositionY = 0x19B859CB950; // Unknown = 
        public const ulong FIntTenFootSkyboxBlockerPositionZ = 0x19B859CBBD0; // Unknown = 
        public const ulong FIntTenFootSkyboxBlockerSizeX = 0x19B859CAFD0; // Unknown = 
        public const ulong FIntTenFootSkyboxBlockerSizeY = 0x19B859CB1D0; // Unknown = 
        public const ulong FIntTenFootSkyboxBlockerSizeZ = 0x19B859CB250; // Unknown = 
        public const ulong FIntThrottleParticipantsUpdateMs2 = 0x19B8FDEAC10; // Unknown = 
        public const ulong FIntTilePlacedTelemetryThrottleHundredthsPercent = 0x19BBE91F0D0; // Unknown = 
        public const ulong FIntTileSkippedTelemetryThrottleHundredthsPercent = 0x19BBE91F310; // Unknown = 
        public const ulong FIntTimeToInteractiveTrackerSampleRate = 0x19B8F7419D0; // Unknown = 
        public const ulong FIntTooltipHitboxMinSize = 0x19BBC7A8610; // Unknown = 
        public const ulong FIntTraversalTelemetryThrottleHundrethsPercent = 0x19BBC3888D0; // Unknown = 
        public const ulong FIntTrustedConnectionsStoreDataTtlSec = 0x19BA5BD3350; // Unknown = 
        public const ulong FIntTrustedConnectionsStoreIncomingRequestsProcessDelaySec = 0x19BA5BDB390; // Unknown = 
        public const ulong FIntTrustedConnectionsStoreProcessDelaySec = 0x19BA5BD8250; // Unknown = 
        public const ulong FIntTrustedContactsHttpRetryCount = 0x19BA5BD2F10; // Unknown = 
        public const ulong FIntTrustedFriendRequestsPageSize = 0x19B8C2E1390; // Unknown = 
        public const ulong FIntUIResetDelayInSec = 0x19BB397E250; // Unknown = 
        public const ulong FIntUSER_VOTE_CACHE_TTL_SECONDS = 0x19BA5BD2110; // Unknown = 
        public const ulong FIntUXForCameraPerformanceDeviceDelay = 0x19B9F0AC110; // Unknown = 
        public const ulong FIntUXForCameraPerformanceSessionDelay = 0x19B9F0AC5D0; // Unknown = 
        public const ulong FIntUiShellOrientationChangedThrottleHundredthsPercent = 0x19BA60963D0; // Unknown = 
        public const ulong FIntUnauthorizedErrorThrottlingHundredthsPercent = 0x19BBC1CFED0; // Unknown = 
        public const ulong FIntUnblockUserThrottleHundredthsPercent = 0x19BBC388650; // Unknown = 
        public const ulong FIntUnblockUserThrottleHundredthsPercent4 = 0x19BBC386D90; // Unknown = 
        public const ulong FIntUnfilteredMessageTransparencyHundredths = 0x19B9FB745E0; // Unknown = 
        public const ulong FIntUnfilteredThreadsPvDelayMs = 0x19BA0A56BE8; // Unknown = 
        public const ulong FIntUnifiedPurchaseTelemetryEventIngestThrottleHundredthsPercent = 0x19D85DC8A50; // Unknown = 
        public const ulong FIntUniversalAppPolicyFailureTelemetryThrottleHundredthsPercent = 0x19BA8A0F290; // Unknown = 
        public const ulong FIntUnmuteAllThrottleHundredthsPercent = 0x19BBC3885D0; // Unknown = 
        public const ulong FIntUnmutePlayerThrottleHundredthsPercent = 0x19BBC3896D0; // Unknown = 
        public const ulong FIntUnmuteSelfThrottleHundredthsPercent = 0x19BBC387E10; // Unknown = 
        public const ulong FIntUnmuteSelfThrottleHundredthsPercent4 = 0x19B9CCEC030; // Unknown = 
        public const ulong FIntUnpublishedPlaytestModeTooltipDisplayLimit = 0x19B9ACB5B50; // Unknown = 
        public const ulong FIntUpVectorOrentationThreshold1 = 0x19D8952E790; // Unknown = 
        public const ulong FIntUpsellAccountBalanceRetryAttemps = 0x19D85DC4010; // Unknown = 
        public const ulong FIntUpsellAccountBalanceRetryIntervalSec = 0x19D85DC5E50; // Unknown = 
        public const ulong FIntUpsellSuggestionsAPIMaxPackagesV3 = 0x19B9ACBF890; // Unknown = 
        public const ulong FIntUseAssetFavoritingHttpRetryCount = 0x19D802942D0; // Unknown = 
        public const ulong FIntUserProfileDefaultRetryCount = 0x19BA5156D10; // Unknown = 
        public const ulong FIntUserProfileStoreBatchSize = 0x19BA515E1D0; // Unknown = 
        public const ulong FIntUserProfileStoreHttpTimeout = 0x19BA515F050; // Unknown = 
        public const ulong FIntUserProfileStoreQueueProcessDelay = 0x19BA5156010; // Unknown = 
        public const ulong FIntUserProfilesDataLoaderClearTime_v1 = 0x19BADF9C110; // Unknown = 
        public const ulong FIntUserRelationshipModalsAnalyticsThrottlingThousandths = 0x19BA6077A10; // Unknown = 
        public const ulong FIntUserSearchHttpRetryCount = 0x19B9011DD90; // Unknown = 
        public const ulong FIntUserSeenCollectionBatchTimeMs = 0x19B88C2BD50; // Unknown = 
        public const ulong FIntV1MenuLanguageSelectionFeaturePerMillageRollout = 0x19B9FD8D390; // Unknown = 
        public const ulong FIntVRAvatarGesturesAnalyticsThrottleHundrethsPercent = 0x19B9F0A61D0; // Unknown = 
        public const ulong FIntVRBottomBarPositionOffsetDepthNumber = 0x19B9FDD4E88; // Unknown = 
        public const ulong FIntVRBottomBarPositionOffsetVerticalNumber = 0x19B9FDD4F08; // Unknown = 
        public const ulong FIntVREnvironmentSettingDarkClockTime = 0x19BA6A36590; // Unknown = 
        public const ulong FIntVREnvironmentSettingLightClockTime = 0x19BA6A338D0; // Unknown = 
        public const ulong FIntVRScaleGuiDistance = 0x19BAEB793D0; // Unknown = 
        public const ulong FIntVRTouchControllerTransparency = 0x19BBE91ACD0; // Unknown = 
        public const ulong FIntValidCookieForNoCachedUserThrottlingHundredthsPercent = 0x19BBC1CBB10; // Unknown = 
        public const ulong FIntVideoBlockingTelemetryThrottleHundredthsPercent = 0x19BBE912250; // Unknown = 
        public const ulong FIntVideoEngagementEventHundredthsPercent = 0x19BBC38A050; // Unknown = 
        public const ulong FIntVideoPlaybackDetectorScanDebounceInMilliseconds = 0x19B88C2C250; // Unknown = 
        public const ulong FIntVideoPlayerPlaybackEndThresholdInMs = 0x19BBC383A10; // Unknown = 
        public const ulong FIntVirtualEventsHttpRetryCount = 0x19B859CAC90; // Unknown = 
        public const ulong FIntVoiceCapturedDuringVideoCaptureThrottlingPercentage = 0x19B8FDEB750; // Unknown = 
        public const ulong FIntVoiceChatDeviceChangeDebounceDelay = 0x19B9FD8CE90; // Unknown = 
        public const ulong FIntVoiceChatTooltipDelay = 0x19BA4E9E550; // Unknown = 
        public const ulong FIntVoiceJoinM3ToastDurationSeconds = 0x19BA4E9DB90; // Unknown = 
        public const ulong FIntVoiceReverseNudgeUXDisplayTimeSeconds = 0x19B9F1812A8; // Unknown = 
        public const ulong FIntVoiceToxicityToastDurationSeconds = 0x19BA4E9FE50; // Unknown = 
        public const ulong FIntVoiceUsersInteractionExpiryTimeSeconds = 0x19B8FDEA310; // Unknown = 
        public const ulong FIntVrAppPanelCurvatureOverride = 0x19BA6A3DF10; // Unknown = 
        public const ulong FIntVrAppPanelWidthMultiplierPercentageOverride = 0x19BA6A31050; // Unknown = 
        public const ulong FIntVrAvatarPanelsSpreadMultiplierPercentageOverride = 0x19B859C5D50; // Unknown = 
        public const ulong FIntWaitAfterCloseChallengeWebViewSeconds = 0x19B8FC397D0; // Unknown = 
        public const ulong FIntWaitForChildOfClassTimeout = 0x19BACE799D0; // Unknown = 
        public const ulong FIntWebViewLastClosedDurationSeconds = 0x19B90292E90; // Unknown = 
        public const ulong FIntWebViewOpenDurationCapSeconds = 0x19B90292CD0; // Unknown = 
        public const ulong FIntWidgetListInitialNumToRender = 0x19B8F9DFAD0; // Unknown = 
        public const ulong FIntWidgetListWindowSize = 0x19B8F9DFA10; // Unknown = 
        public const ulong FIntWidgetPaddingSizing = 0x19B8FC32850; // Unknown = 
        public const ulong FIntXLargeCollectionItemFractionalPercent = 0x19BA6793BD0; // Unknown = 
        public const ulong FIntXLargeCollectionItemMaxItemCount = 0x19BA6799990; // Unknown = 
        public const ulong FIntXLargeCollectionItemMinItemCount = 0x19BA6792250; // Unknown = 
        public const ulong FIntXLargeCollectionItemMinItemWidth = 0x19BA6797E50; // Unknown = 
        public const ulong FIntXLargeCollectionItemVerticalGap = 0x19BA679D010; // Unknown = 
        public const ulong FIntXSmallCollectionItemFractionalPercent = 0x19BA679E510; // Unknown = 
        public const ulong FIntXSmallCollectionItemMaxItemCount = 0x19BA67903D0; // Unknown = 
        public const ulong FIntXSmallCollectionItemMinItemCount = 0x19BA6794590; // Unknown = 
        public const ulong FIntXSmallCollectionItemMinItemWidth = 0x19BA679B650; // Unknown = 
        public const ulong FIntXSmallCollectionItemVerticalGap = 0x19BA6798DD0; // Unknown = 
        public const ulong FStringAEGIS2AppChatAgeVerifiedRealtimeNamespace = 0x19B8C2E4250; // Unknown = 
        public const ulong FStringAXAvatarWidgetContentType = 0x19B90644910; // Unknown = 
        public const ulong FStringAXBackendDrivenCatalogLayersFString = 0x19BBC7A8790; // Unknown = 
        public const ulong FStringAXBackendDrivenCatalogLayersNames = 0x19BBCCCFAD0; // Unknown = 
        public const ulong FStringAXBackgroundGenerationCanvasAssetIdDark = 0x19B8F904C10; // Unknown = 
        public const ulong FStringAXBackgroundGenerationCanvasAssetIdLight = 0x19B9F189700; // Unknown = 
        public const ulong FStringAXBodyCategoryTooltipKey = 0x19B9026F250; // Unknown = 
        public const ulong FStringAXCategories = 0x19B9026E490; // Unknown = 
        public const ulong FStringAXCombineGetOutfitDispatchesIXPLayer3 = 0x19B9026D4D0; // Unknown = 
        public const ulong FStringAXCycloramaFallbackAssetId = 0x19BBCCCB5F0; // Unknown = 
        public const ulong FStringAXDefaultAvatarToShopLayer3 = 0x19B90647190; // Unknown = 
        public const ulong FStringAXDurablesSupportExposureLayer = 0x19BA3A50E10; // Unknown = 
        public const ulong FStringAXFetchCartPricingDuringInExperienceLayerName = 0x19B9ACBB490; // Unknown = 
        public const ulong FStringAXInspectAndBuyLayerName = 0x19B9F299050; // Unknown = 
        public const ulong FStringAXItemDetails3DPreviewIXPLayer = 0x19B9026D310; // Unknown = 
        public const ulong FStringAXLookWidgetContentType = 0x19B90644D10; // Unknown = 
        public const ulong FStringAXPlusExclusiveBackgroundIds = 0x19B8F907B10; // Unknown = 
        public const ulong FStringAXRecommendedItemsExposureLayer = 0x19B8F905390; // Unknown = 
        public const ulong FStringAXSlotBasedEditorCategoryTooltipKey = 0x19B9026C3D0; // Unknown = 
        public const ulong FStringAXSlotsDesignUpdatesExposureLayer = 0x19BA3A553D0; // Unknown = 
        public const ulong FStringAXSortsBodyTabRecLayerName = 0x19B8F907910; // Unknown = 
        public const ulong FStringAXTallBundleWidgetContentType = 0x19B90644850; // Unknown = 
        public const ulong FStringAXTaxonomyM20ExperimentLayerName = 0x19B9F18E7A0; // Unknown = 
        public const ulong FStringAXTaxonomyM21ExperimentLayerName = 0x19B8F907F90; // Unknown = 
        public const ulong FStringAXTooltipAllowedTooltips = 0x19B9F00E010; // Unknown = 
        public const ulong FStringAccountRecoveryUILayer = 0x19BA3BBA4D0; // Unknown = 
        public const ulong FStringAccountSwitcherLayer = 0x19BA3BB3BD0; // Unknown = 
        public const ulong FStringAdDropdownButtonDefault = 0x19B9F9202D0; // Unknown = 
        public const ulong FStringAdDropdownButtonOpen = 0x19B9F920410; // Unknown = 
        public const ulong FStringAdGuiCloseButtonImageLua = 0x19BA8A0E2D0; // Unknown = 
        public const ulong FStringAdGuiLivePreviewWatermark = 0x19BA8A0E5D0; // Unknown = 
        public const ulong FStringAdGuiLivePreviewWatermarkV2 = 0x19BA8A0EB90; // Unknown = 
        public const ulong FStringAdGuiPauseButtonImageLua = 0x19BA8A0E110; // Unknown = 
        public const ulong FStringAdGuiPlayButtonImageLua = 0x19BA8A0DFD0; // Unknown = 
        public const ulong FStringAdPlayerExitButton = 0x19B9119EFC0; // Unknown = 
        public const ulong FStringAdsEnterFullscreenImageLua = 0x19BA8A0CDD0; // Unknown = 
        public const ulong FStringAdsEudsaPromptActiveImageLua = 0x19BA8A07F50; // Unknown = 
        public const ulong FStringAdsEudsaPromptInactiveImageLua = 0x19BA8A0DA50; // Unknown = 
        public const ulong FStringAdsExitFullscreenImageLua = 0x19BA8A0C550; // Unknown = 
        public const ulong FStringAdsVolumeOffImageLua = 0x19BA8A0C890; // Unknown = 
        public const ulong FStringAdsVolumeOnImageLua = 0x19BA8A0CA50; // Unknown = 
        public const ulong FStringAgeCheckAmpNameSpace = 0x19BA8444010; // Unknown = 
        public const ulong FStringAllFriendsCarouselLoadingTimeDoneStats = 0x19B902677D0; // Unknown = 
        public const ulong FStringAllFriendsCarouselLoadingTimeFailedStats = 0x19B90267B50; // Unknown = 
        public const ulong FStringAllFriendsNextPageCarouselLoadingTimeDoneStats = 0x19B90267E90; // Unknown = 
        public const ulong FStringAllFriendsNextPageCarouselLoadingTimeFailedStats = 0x19B90267D90; // Unknown = 
        public const ulong FStringAndroidPhoneVerificationLayer = 0x19BA6A33DD0; // Unknown = 
        public const ulong FStringApisCdnUrl = 0x19B90291290; // Unknown = 
        public const ulong FStringAppBadgingLayer = 0x19BA3BB02D0; // Unknown = 
        public const ulong FStringAppChatClosedCounter = 0x19BA60727D0; // Unknown = 
        public const ulong FStringAppChatConversationPageSyntheticSystemMessageIxpLayer = 0x19BACE78690; // Unknown = 
        public const ulong FStringAppChatEnableRepliesUIIxpLayer1 = 0x19BACE7D410; // Unknown = 
        public const ulong FStringAppChatFixRootChatBackNavigationIxpLayer = 0x19B8FA15910; // Unknown = 
        public const ulong FStringAppChatGroupOsaViewDetailsUrl = 0x19B8FA152D0; // Unknown = 
        public const ulong FStringAppChatInExperienceIXPLayer = 0x19B8C2EA9D0; // Unknown = 
        public const ulong FStringAppChatNewChatInputBarIxpLayer = 0x19BACE73BD0; // Unknown = 
        public const ulong FStringAppChatPerfExperimentLayer = 0x19BBCCC3350; // Unknown = 
        public const ulong FStringAppChatRemoveConversationListDividerIxpLayer = 0x19B8FA1D510; // Unknown = 
        public const ulong FStringAppChatSessionName = 0x19BA6079190; // Unknown = 
        public const ulong FStringAppChatSquadButtonColorUpdateIxpLayer = 0x19BACE76D10; // Unknown = 
        public const ulong FStringAppChatTcLearnMoreUrl = 0x19B9FB746D0; // Unknown = 
        public const ulong FStringAppChatTimestampInSubtitleIxpLayer = 0x19B8FA1E1D0; // Unknown = 
        public const ulong FStringAppChatVisibleCounter = 0x19BA6076490; // Unknown = 
        public const ulong FStringArgoPartyLayer = 0x19B8FDECC50; // Unknown = 
        public const ulong FStringArgoPartyVariant = 0x19B8FDECCD0; // Unknown = 
        public const ulong FStringArgusApiUrlBase = 0x19BB8974598; // Unknown = 
        public const ulong FStringArgusEntryTypeKey = 0x19D86F0FA10; // Unknown = 
        public const ulong FStringArgusExperimentLayer = 0x19D86F07490; // Unknown = 
        public const ulong FStringArgusInfluencerUploadsKey = 0x19D86F0B950; // Unknown = 
        public const ulong FStringArgusPlatformIntegrationKey = 0x19D86F08FD0; // Unknown = 
        public const ulong FStringAuthenticationErrorCode = 0x19B88C61A90; // Unknown = 
        public const ulong FStringAuthenticationErrorCodeAlternative = 0x19BACFDA850; // Unknown = 
        public const ulong FStringAvatarSwitcherIXPLayer = 0x19B939B5968; // Unknown = 
        public const ulong FStringAvatarSwitcherTooltipStorageKey = 0x19BABC132D0; // Unknown = 
        public const ulong FStringBacktraceLogTags = 0x19B8F90B910; // Unknown = 
        public const ulong FStringBillboardUpdateFrequencyIXPLayerValue = 0x19BBCD7FB10; // Unknown = 
        public const ulong FStringBiometricPrivacyPolicyLink = 0x19B90113810; // Unknown = 
        public const ulong FStringBlackbirdUpsellHiddenRequestTypes2 = 0x19B9EE00150; // Unknown = 
        public const ulong FStringBlackbirdUrl = 0x19BA6A35690; // Unknown = 
        public const ulong FStringBlackbirdWebviewHeaderName = 0x19B82E09F90; // Unknown = 
        public const ulong FStringBuildExperienceProductionTemplatePlaceId = 0x19BAD588550; // Unknown = 
        public const ulong FStringCameraUnavailableUrl = 0x19B9F0AD610; // Unknown = 
        public const ulong FStringCanAccessTrustedContactsAmpFeature = 0x19BACFD23D0; // Unknown = 
        public const ulong FStringCanAccessTrustedContactsAmpNameSpace = 0x19BACFD8050; // Unknown = 
        public const ulong FStringCapturesActivatedInGameMenu = 0x19BAC87CB10; // Unknown = 
        public const ulong FStringCapturesCarouselOpened = 0x19BAC87CD50; // Unknown = 
        public const ulong FStringCapturesDeactivatedInGameMenu = 0x19BAC877490; // Unknown = 
        public const ulong FStringCapturesEntrypointActivated = 0x19BAC87CC90; // Unknown = 
        public const ulong FStringCapturesIXPLayer = 0x19B8C2EA490; // Unknown = 
        public const ulong FStringCapturesPageOpenedInGameMenu = 0x19BAC87C650; // Unknown = 
        public const ulong FStringCapturesShareToastButtonActivated = 0x19BAC87CA10; // Unknown = 
        public const ulong FStringCapturesTabIXPLayer = 0x19BA6A31450; // Unknown = 
        public const ulong FStringChatAddFriendsBtnClickedCounter = 0x19BA6074950; // Unknown = 
        public const ulong FStringChatDetailsAddFriendsBtnClickedCounter = 0x19BA607C5D0; // Unknown = 
        public const ulong FStringChatDetailsCreateUnfilteredChatCellClickedCounter = 0x19BA607D2D0; // Unknown = 
        public const ulong FStringChatDetailsCreateUnfilteredChatCellRenderedCounter = 0x19BA6074890; // Unknown = 
        public const ulong FStringChatDetailsLeaveGroupBtnClickedCounter = 0x19BA607BB10; // Unknown = 
        public const ulong FStringChatDetailsLeaveGroupDialogLeaveClickedCounter = 0x19BA60729D0; // Unknown = 
        public const ulong FStringChatDetailsLeaveGroupDialogRenderedCounter = 0x19BA6075310; // Unknown = 
        public const ulong FStringChatDetailsLeaveGroupDialogStayClickedCounter = 0x19BA60756D0; // Unknown = 
        public const ulong FStringChatDetailsRenderedCounter = 0x19BA6076910; // Unknown = 
        public const ulong FStringChatDetailsReportUserClickedCounter = 0x19BA607F110; // Unknown = 
        public const ulong FStringChatEmptyStateScreenRenderedCounter = 0x19BA6078AD0; // Unknown = 
        public const ulong FStringChatInputBarReplyComposeCancelBtnActivatedCounter = 0x19BA6076790; // Unknown = 
        public const ulong FStringChatInputBarReplyComposeRenderedCounter = 0x19BA6078ED0; // Unknown = 
        public const ulong FStringChatLandingComposeBtnClickedCounter = 0x19BA607C9D0; // Unknown = 
        public const ulong FStringChatLandingConversationClickedCounter = 0x19BA607F0D0; // Unknown = 
        public const ulong FStringChatLandingGroupsBtnClicked = 0x19BA6075050; // Unknown = 
        public const ulong FStringChatLandingNotifBtnClickedCounter = 0x19BA6070150; // Unknown = 
        public const ulong FStringChatLandingPvUpsellContinueClickedCounter = 0x19BA6074A50; // Unknown = 
        public const ulong FStringChatLandingPvUpsellDismissedCounter = 0x19BA6072FD0; // Unknown = 
        public const ulong FStringChatLandingPvUpsellFailedCounter = 0x19BA6071350; // Unknown = 
        public const ulong FStringChatLandingPvUpsellRenderedCounter = 0x19BA60711D0; // Unknown = 
        public const ulong FStringChatLandingPvUpsellSucceededCounter = 0x19BA6071390; // Unknown = 
        public const ulong FStringChatLandingScreenRenderedCounter = 0x19BA6075E50; // Unknown = 
        public const ulong FStringChatLandingSearchBtnClickedCounter = 0x19BA607C950; // Unknown = 
        public const ulong FStringChatLandingUnfilteredThreadsFtuxDismissedCounter = 0x19BA6076850; // Unknown = 
        public const ulong FStringChatLandingUnfilteredThreadsFtuxLearnMoreClickedCounter = 0x19BA607D910; // Unknown = 
        public const ulong FStringChatLandingUnfilteredThreadsFtuxRenderedCounter = 0x19BA6072550; // Unknown = 
        public const ulong FStringChatLineReportingSubmittedAbuseTypeStat = 0x19BA5151090; // Unknown = 
        public const ulong FStringChatLineReportingTimeSpentStat = 0x19BA5153750; // Unknown = 
        public const ulong FStringChatMessageLongPressedCounter = 0x19BA60755D0; // Unknown = 
        public const ulong FStringChatMessageMenuCopyBtnActivatedCounter = 0x19BA6077710; // Unknown = 
        public const ulong FStringChatMessageMenuOpenedCounter = 0x19BA607F890; // Unknown = 
        public const ulong FStringChatMessageMenuReplyBtnActivatedCounter = 0x19BA607FA50; // Unknown = 
        public const ulong FStringChatMessageOpenMenuIconClickedCounter = 0x19BA6072A10; // Unknown = 
        public const ulong FStringChatMessagePressedCounter = 0x19BA6075210; // Unknown = 
        public const ulong FStringChatMessageReplyIconClickedCounter = 0x19BA607E190; // Unknown = 
        public const ulong FStringChatTranslationEnabledLocales = 0x19B9FD8C790; // Unknown = 
        public const ulong FStringChatTranslationLayerName = 0x19B9AF10390; // Unknown = 
        public const ulong FStringClientToastNotificationsRedirectLayerName = 0x19BACFEB210; // Unknown = 
        public const ulong FStringClientToastNotificationsRedirectLayerValue = 0x19BACFEB390; // Unknown = 
        public const ulong FStringCloseContactListButtonCounter = 0x19BAEDDC1A8; // Unknown = 
        public const ulong FStringCloseContactListCrossCounter = 0x19BAFCFDA10; // Unknown = 
        public const ulong FStringCommsFAEFeatureName = 0x19B90268650; // Unknown = 
        public const ulong FStringCommsFAENamespace = 0x19B90268590; // Unknown = 
        public const ulong FStringConnectionGraphCoreAmpNameSpace = 0x19BA59B97D0; // Unknown = 
        public const ulong FStringConsoleSignUpLayer = 0x19BA3BB8E90; // Unknown = 
        public const ulong FStringConsoleVoiceEnabledIXPLayerValue = 0x19B8FDE9390; // Unknown = 
        public const ulong FStringConsoleVoiceIXPLayerName = 0x19B8FDE9950; // Unknown = 
        public const ulong FStringConsumerPlatformsIOSUIRefactor = 0x19BA3BB6550; // Unknown = 
        public const ulong FStringContactImportGreenFindFriendsButtonExperimentVariable = 0x19BAFCFA810; // Unknown = 
        public const ulong FStringContactImportLayer = 0x19BAFCFAB10; // Unknown = 
        public const ulong FStringContactImportModalAddFriendsCounter = 0x19BAFCFF190; // Unknown = 
        public const ulong FStringContactImportModalCloseCounter = 0x19BAFCF9250; // Unknown = 
        public const ulong FStringContactImportModalContinueCounter = 0x19BAFCFB110; // Unknown = 
        public const ulong FStringContactImportModalPageLoadCounter = 0x19BAFCFA950; // Unknown = 
        public const ulong FStringContactImportRemoveCloseButtonExperimentVariable = 0x19BAFCF8FD0; // Unknown = 
        public const ulong FStringContactImporterFindFriendsUrl = 0x19B994351A0; // Unknown = 
        public const ulong FStringContactImporterInviteContactCounter = 0x19BAFCFFD90; // Unknown = 
        public const ulong FStringContactImporterRequestFriendshipCounter = 0x19BAFCFBE50; // Unknown = 
        public const ulong FStringContactImportingTimeStat = 0x19BAFCFF6D0; // Unknown = 
        public const ulong FStringContactsListEmojiSortingIxpLayer = 0x19BAFCF7590; // Unknown = 
        public const ulong FStringContactsListLoadedCounter = 0x19BAFCFD550; // Unknown = 
        public const ulong FStringConversationIneligibleModalLearnMoreClickedCounter = 0x19BA607E7D0; // Unknown = 
        public const ulong FStringConversationIneligibleModalLeftGroupCounter = 0x19BA6071410; // Unknown = 
        public const ulong FStringConversationIneligibleModalRenderedCounter = 0x19BA6075C10; // Unknown = 
        public const ulong FStringConversationInfoBtnClickedCounter = 0x19BA6072190; // Unknown = 
        public const ulong FStringConversationLearnMoreBannerActionClickedCounter = 0x19BA60763D0; // Unknown = 
        public const ulong FStringConversationLearnMoreBannerRenderedCounter = 0x19BA6075690; // Unknown = 
        public const ulong FStringConversationLearnMoreDialogDismissedCounter = 0x19BA6074550; // Unknown = 
        public const ulong FStringConversationLearnMoreDialogRenderedCounter = 0x19BA60785D0; // Unknown = 
        public const ulong FStringConversationMessageSentCounter = 0x19BA6076C10; // Unknown = 
        public const ulong FStringConversationPvBannerActionClickedCounter = 0x19BA607F950; // Unknown = 
        public const ulong FStringConversationPvBannerRenderedCounter = 0x19BA607C710; // Unknown = 
        public const ulong FStringConversationPvDialogActionClickedCounter = 0x19BA6071CD0; // Unknown = 
        public const ulong FStringConversationPvDialogDismissedCounter = 0x19BA6070F50; // Unknown = 
        public const ulong FStringConversationPvDialogFailedCounter = 0x19BA6072050; // Unknown = 
        public const ulong FStringConversationPvDialogRenderedCounter = 0x19BA6073450; // Unknown = 
        public const ulong FStringConversationPvDialogSucceededCounter = 0x19BA6073590; // Unknown = 
        public const ulong FStringConversationPvUpsellContinueClickedCounter = 0x19BA6071D50; // Unknown = 
        public const ulong FStringConversationPvUpsellFailedCounter = 0x19BA60741D0; // Unknown = 
        public const ulong FStringConversationPvUpsellLeftGroupCounter = 0x19BA6077390; // Unknown = 
        public const ulong FStringConversationPvUpsellRenderedCounter = 0x19BA60721D0; // Unknown = 
        public const ulong FStringConversationPvUpsellSucceededCounter = 0x19BA60718D0; // Unknown = 
        public const ulong FStringConversationScreenExitCounter = 0x19BA6072B50; // Unknown = 
        public const ulong FStringConversationScreenRenderedCounter = 0x19BA607FCD0; // Unknown = 
        public const ulong FStringConversationSendBtnClickedCounter = 0x19BA607DA10; // Unknown = 
        public const ulong FStringConversationUpgradeBannerActionClickedCounter = 0x19BA607F610; // Unknown = 
        public const ulong FStringConversationUpgradeBannerRenderedCounter = 0x19BA6073950; // Unknown = 
        public const ulong FStringConversationUpgradeDialogActionClickedCounter = 0x19BA607B850; // Unknown = 
        public const ulong FStringConversationUpgradeDialogDismissedCounter = 0x19BA6071750; // Unknown = 
        public const ulong FStringConversationUpgradeDialogRenderedCounter = 0x19BA607EFD0; // Unknown = 
        public const ulong FStringCoreContentAmpNameSpace = 0x19BA8446010; // Unknown = 
        public const ulong FStringCoreScriptBacktraceErrorUploadToken = 0x19BA553F750; // Unknown = 
        public const ulong FStringCountriesWithGenericIllegalContentReporting2 = 0x19BA3A58190; // Unknown = 
        public const ulong FStringCountriesWithTakeItDownReport = 0x19BA3A50D50; // Unknown = 
        public const ulong FStringCrossExpEventLoggingLevel = 0x19B8ED7FA50; // Unknown = 
        public const ulong FStringCrossExpVoiceIXPLayer = 0x19B859C9150; // Unknown = 
        public const ulong FStringCrossExpVoicePlaceId = 0x19B859C9250; // Unknown = 
        public const ulong FStringCustomizeNameClearedInput = 0x19B90118310; // Unknown = 
        public const ulong FStringCustomizeNameMaximumCharLimitTyped = 0x19B90119190; // Unknown = 
        public const ulong FStringCustomizeNameModalClosed = 0x19B901193D0; // Unknown = 
        public const ulong FStringCustomizeNameModalOpened = 0x19B90118F50; // Unknown = 
        public const ulong FStringCustomizeNameSaveAttemptInvalidInput = 0x19B90119610; // Unknown = 
        public const ulong FStringCustomizeNameSaved = 0x19B90119450; // Unknown = 
        public const ulong FStringDSAReportingAndTransparencyOverrideUserIds = 0x19BA3A59650; // Unknown = 
        public const ulong FStringDebugCrossExpVoiceIXPLayer = 0x19B859C9050; // Unknown = 
        public const ulong FStringDebugDefaultPageOverride = 0x19B9026AED0; // Unknown = 
        public const ulong FStringDebugFriendsChatConversationId = 0x19BA6B3AE90; // Unknown = 
        public const ulong FStringDebugHomePageUpsellCardVariationResponseBody = 0x19B902671D0; // Unknown = 
        public const ulong FStringDebugLogTags = 0x19B8F90BAD0; // Unknown = 
        public const ulong FStringDebugLuaLogLevel = 0x19B9AF1DF50; // Unknown = 
        public const ulong FStringDebugLuaLogPattern = 0x19B9AF1DE90; // Unknown = 
        public const ulong FStringDebugOverrideCrossPlayApiUrl = 0x19B859CAB50; // Unknown = 
        public const ulong FStringDebugOverrideCrossPlayQueryParam = 0x19BB6BB2F90; // Unknown = 
        public const ulong FStringDebugOverrideCrossPlaySettingsKey = 0x19BB6BB9390; // Unknown = 
        public const ulong FStringDebugOverrideCrossPlayUri = 0x19BB6BB2A90; // Unknown = 
        public const ulong FStringDefaultSkyStyle = 0x19BA6A31D90; // Unknown = 
        public const ulong FStringDefaultVREnvironmentSetting = 0x19BA6A3F210; // Unknown = 
        public const ulong FStringDesktopUpsellIXPLayer = 0x19BAC832210; // Unknown = 
        public const ulong FStringDisableAutocorrectExperimentLayer = 0x19BB6BBECD0; // Unknown = 
        public const ulong FStringDisableCameraOnLowSpecDevicesIXPField = 0x19B9FD89510; // Unknown = 
        public const ulong FStringDisableCameraOnLowSpecDevicesIXPLayer = 0x19B9FD89A10; // Unknown = 
        public const ulong FStringDiscoverabilityModalCloseCounter = 0x19BAFCF2D50; // Unknown = 
        public const ulong FStringDiscoverabilityModalContinueCounter = 0x19BAFCFD010; // Unknown = 
        public const ulong FStringDiscoverabilityModalLoadCounter = 0x19BAFCF79D0; // Unknown = 
        public const ulong FStringDiscoverabilityModalRadioButtonClickCounter = 0x19D86D636E8; // Unknown = 
        public const ulong FStringDiscoverabilityUpsellNonPrefillDiscoverableUserIdsWhitelist = 0x19BAFCF8450; // Unknown = 
        public const ulong FStringDisruptiveVoiceNudgeVariantIXPLayerName = 0x19BA5158D50; // Unknown = 
        public const ulong FStringDisruptiveVoiceNudgeVariantIXPVariableName = 0x19BA5158F10; // Unknown = 
        public const ulong FStringDummyAMPWizardAccessResponse = 0x19B9F182060; // Unknown = 
        public const ulong FStringDummyAMPWizardActionsTakenJSON = 0x19B90113F10; // Unknown = 
        public const ulong FStringEARReportMenuIXPLayer = 0x19BA6A32110; // Unknown = 
        public const ulong FStringEditProfileExperimentKey = 0x19B90643250; // Unknown = 
        public const ulong FStringEdpPlayerFeedbackServiceRoute = 0x19B9ACB1C10; // Unknown = 
        public const ulong FStringEligibleForFacialAgeEstimationAmpFeature = 0x19BA8442050; // Unknown = 
        public const ulong FStringEligibleToAgeVerifyAmpFeature = 0x19BA8448990; // Unknown = 
        public const ulong FStringEmoteUtilityFallbackKeyframeSequenceAssetId = 0x19D8952B550; // Unknown = 
        public const ulong FStringExitModalIXPLayer = 0x19BACE9D210; // Unknown = 
        public const ulong FStringExpChatChatWithTFAmpFeatureName = 0x19BBC387BD0; // Unknown = 
        public const ulong FStringExpChatChatWithTFAmpNameSpace = 0x19BBC385350; // Unknown = 
        public const ulong FStringExpChatCrossAgeChatActivityIXPLayerName = 0x19BA74A4A90; // Unknown = 
        public const ulong FStringExpChatCrossAgeChatActivityIXPLayerValue = 0x19BA74A4D90; // Unknown = 
        public const ulong FStringExpChatDictationIXPLayerName = 0x19BABBD2750; // Unknown = 
        public const ulong FStringExpChatFOMOUpsellIXPLayerName = 0x19BA74A4550; // Unknown = 
        public const ulong FStringExpChatFOMOUpsellIXPLayerValue = 0x19BA74A4750; // Unknown = 
        public const ulong FStringExpChatLocalChatEnabledMessageExperimentLayer = 0x19B8FDEBE90; // Unknown = 
        public const ulong FStringExpChatLocalChatEnabledMessageForcedKey = 0x19B8FDEC2D0; // Unknown = 
        public const ulong FStringExpChatLocalChatEnabledMessageVariable = 0x19BAED53CC8; // Unknown = 
        public const ulong FStringExpChatNewSystemMessagesExperimentLayer = 0x19B8FDECA10; // Unknown = 
        public const ulong FStringExpChatNewSystemMessagesVariant = 0x19B8FDEC650; // Unknown = 
        public const ulong FStringExpChatPresetAutocompleteIxpLayer = 0x19BABBD2CD0; // Unknown = 
        public const ulong FStringExpChatPresetChatBadgeFTUXExperimentLayer = 0x19B8FDEC550; // Unknown = 
        public const ulong FStringExpChatPresetChatBadgeFTUXVariable = 0x19B8FDEC710; // Unknown = 
        public const ulong FStringExpChatPresetChatIXPLayerName = 0x19BABBD2350; // Unknown = 
        public const ulong FStringExpChatRewriteInlineIxpLayer = 0x19BA5153650; // Unknown = 
        public const ulong FStringExpChatSummaryPrefixText = 0x19BA679A4D0; // Unknown = 
        public const ulong FStringExperienceDetailsLayer = 0x19B8C304290; // Unknown = 
        public const ulong FStringExperienceMenuGamepadExposureLayer = 0x19BA3BB47D0; // Unknown = 
        public const ulong FStringExperienceReactDeferredScheduler_LayerName = 0x19B9ACB5210; // Unknown = 
        public const ulong FStringFAEUpsellDeviceNamePipeDenyList = 0x19B8FDEF590; // Unknown = 
        public const ulong FStringFAEUpsellSystemVersionPipeDenyList = 0x19BAC879DD0; // Unknown = 
        public const ulong FStringFRRToastPositionVariantKey = 0x19BA67207D0; // Unknown = 
        public const ulong FStringFStringBlackbirdWebviewHeaderName = 0x19BC257AAA0; // Unknown = 
        public const ulong FStringFStringEditProfileToAvatarLayerName = 0x19B906434D0; // Unknown = 
        public const ulong FStringFStringLuckyRecommendationExpLayer = 0x19B8FDEE890; // Unknown = 
        public const ulong FStringFStringPartyPageCarouselExpLayer = 0x19B8FDEE210; // Unknown = 
        public const ulong FStringFStringQueueExpLayer = 0x19B8FDEC8D0; // Unknown = 
        public const ulong FStringFStringSquadRegroupExpLayer = 0x19B8FDEEE90; // Unknown = 
        public const ulong FStringFStringTimeoutLoadingLocalPlayerInBackgroundDM = 0x19BACFD84D0; // Unknown = 
        public const ulong FStringFailedFindContactsCounter = 0x19BAFCF6010; // Unknown = 
        public const ulong FStringFailedFormatContactsFromDeviceCounter = 0x19BAFCFC310; // Unknown = 
        public const ulong FStringFailedGetContactEntitiesCounter = 0x19BAFCF01D0; // Unknown = 
        public const ulong FStringFailedGetContactsFromDeviceCounter = 0x19BAFB23D50; // Unknown = 
        public const ulong FStringFailedUploadContactsFromDeviceCounter = 0x19BAFCFEFD0; // Unknown = 
        public const ulong FStringFindFriendsButtonClickedCounter = 0x19BAFCFDED0; // Unknown = 
        public const ulong FStringFlyoutIxpLayer = 0x19BA461C190; // Unknown = 
        public const ulong FStringFlyoutIxpVariantKey = 0x19BA4619710; // Unknown = 
        public const ulong FStringFlyoutLearnPlaceURI = 0x19D7C7CBC90; // Unknown = 
        public const ulong FStringFlyoutMomentsPlaceURI = 0x19D7C7CE3D0; // Unknown = 
        public const ulong FStringFoundationImagesWhitelistedIconAssets = 0x19B9CB7C990; // Unknown = 
        public const ulong FStringFriendRequestModalIxpLayer = 0x19BA6078290; // Unknown = 
        public const ulong FStringFriendRequestNicknamesCanSendNicknames = 0x19B90115D90; // Unknown = 
        public const ulong FStringFriendRequestNicknamesSocialFriendsLayer = 0x19B90115E10; // Unknown = 
        public const ulong FStringFriendsCarouselLoadedWithUsers = 0x19B90268450; // Unknown = 
        public const ulong FStringFriendsCarouselRequestFriendship = 0x19B90268AD0; // Unknown = 
        public const ulong FStringFriendsCarouselRevokeFriendRequest = 0x19B90268F50; // Unknown = 
        public const ulong FStringFriendsCarouselUILoadingTimeStats = 0x19B90267CD0; // Unknown = 
        public const ulong FStringFriendsCarouselUserPressed = 0x19B90268710; // Unknown = 
        public const ulong FStringFriendsChatTabName = 0x19BA553F9D0; // Unknown = 
        public const ulong FStringFriendshipNotifsUseSendrLayerName = 0x19BA672F5D0; // Unknown = 
        public const ulong FStringFriendshipNotifsUseSendrLayerValue = 0x19BACFEBC10; // Unknown = 
        public const ulong FStringGenericAbuseReportingSubmittedAbuseTypeStat = 0x19BA3A55350; // Unknown = 
        public const ulong FStringGenericAbuseReportingTimeSpentStat = 0x19BA3A5CC90; // Unknown = 
        public const ulong FStringGenericReportLink = 0x19BA3A5D9D0; // Unknown = 
        public const ulong FStringGetFStringIXPLayerMobileUpsell = 0x19BAC833950; // Unknown = 
        public const ulong FStringHelpPageIXPLayer = 0x19BBF250A10; // Unknown = 
        public const ulong FStringHelpPageIxpLayer = 0x19BAC8734D0; // Unknown = 
        public const ulong FStringHighlightModePreciseSelectionForceVariant = 0x19B8C30D9D0; // Unknown = 
        public const ulong FStringHighlightModePreciseSelectionIXPField = 0x19B8C30D710; // Unknown = 
        public const ulong FStringHomePageNavigationViewAddFriends = 0x19B90268110; // Unknown = 
        public const ulong FStringHomePageNavigationViewAllFriends = 0x19B902688D0; // Unknown = 
        public const ulong FStringIOSPhoneVerificationLayer = 0x19BA6A33AC8; // Unknown = 
        public const ulong FStringIXPLayerMobileUpsell = 0x19D84DAE150; // Unknown = 
        public const ulong FStringImmersiveBrandedAdsLearnMoreUrl = 0x19BA8A084D0; // Unknown = 
        public const ulong FStringInExpChatRewriteDeviceNameBlackList = 0x19B9CB76C90; // Unknown = 
        public const ulong FStringInExpChatRewriteLabelKey = 0x19BA5156A10; // Unknown = 
        public const ulong FStringInExpChatRewriteOsVersionBlackList = 0x19B9CB73BD0; // Unknown = 
        public const ulong FStringInExpChatRewriteReasonKey = 0x19BA5151FD0; // Unknown = 
        public const ulong FStringInExperienceMenuIXPLayer = 0x19BACE9C150; // Unknown = 
        public const ulong FStringInExperienceMenuIXPVar = 0x19BACE9D3D0; // Unknown = 
        public const ulong FStringInExperienceNotificationsLayer = 0x19BA553EF10; // Unknown = 
        public const ulong FStringInExperienceShopTooltipStorageKey = 0x19BABC1C990; // Unknown = 
        public const ulong FStringInGameAssetReportingSubmittedAbuseTypeStat = 0x19BBB7FE9D0; // Unknown = 
        public const ulong FStringInGameAssetReportingTimeSpentStat = 0x19BBB7FE690; // Unknown = 
        public const ulong FStringInGameLargerRobuxUpsellIXPLayerParam = 0x19D85DCD810; // Unknown = 
        public const ulong FStringInGameRobuxUpsellLargerIxpLayer = 0x19BA6A30348; // Unknown = 
        public const ulong FStringIncompatibleAccountsSupportLink = 0x19BBC1C7610; // Unknown = 
        public const ulong FStringInspectAndBuyFeature = 0x19B9F0A0590; // Unknown = 
        public const ulong FStringInternationalNamesIXPExperimentDefinition = 0x19B90643150; // Unknown = 
        public const ulong FStringInternationalNamesIXPLayer = 0x19B90642B10; // Unknown = 
        public const ulong FStringIsUserInTcEligibleCountryAmpFeature = 0x19BACFD5B90; // Unknown = 
        public const ulong FStringIsVerified18PlusAmpFeature = 0x19BA84434D0; // Unknown = 
        public const ulong FStringLivePreviewPlaceId = 0x19BA8A0EE10; // Unknown = 
        public const ulong FStringLoginInfoOverflowedCounter = 0x19B90642110; // Unknown = 
        public const ulong FStringLuaAppAdPreferencesUrl = 0x19BA59B1050; // Unknown = 
        public const ulong FStringLuaAppAdsPlayWithRewardBetaAndroidLayer = 0x19BA3BB0510; // Unknown = 
        public const ulong FStringLuaAppAuthenticationStylingLayer = 0x19BA3BB6650; // Unknown = 
        public const ulong FStringLuaAppBacktraceLogLevel = 0x19B8F90B350; // Unknown = 
        public const ulong FStringLuaAppBadgeDetailsIxpLayer = 0x19B88C22410; // Unknown = 
        public const ulong FStringLuaAppBadgesSeeAllIxpLayer = 0x19B88C22110; // Unknown = 
        public const ulong FStringLuaAppConsoleExperienceMenuLayer = 0x19B9AF10030; // Unknown = 
        public const ulong FStringLuaAppDevStoreSeeAllSduiIxpLayer = 0x19BC0545CD0; // Unknown = 
        public const ulong FStringLuaAppEdpAudioManufacturerDenyList = 0x19B88C2DF90; // Unknown = 
        public const ulong FStringLuaAppEdpFaeIxpLayer = 0x19B9029B690; // Unknown = 
        public const ulong FStringLuaAppEdpVideoDevicePipeDenyList = 0x19BBC38B810; // Unknown = 
        public const ulong FStringLuaAppEdpVideoManufacturerPipeDenyList = 0x19BBC3898D0; // Unknown = 
        public const ulong FStringLuaAppEphemeralCounterPrefix = 0x19B85789450; // Unknown = 
        public const ulong FStringLuaAppExperienceMenuLayer = 0x19BA6A3D710; // Unknown = 
        public const ulong FStringLuaAppGameCarouselAmpUpsellActionAccessResponses = 0x19B90269950; // Unknown = 
        public const ulong FStringLuaAppGameTileMigrationExpLayer = 0x19BBC38AE10; // Unknown = 
        public const ulong FStringLuaAppGameTileVideoDevicePipeDenyList = 0x19BBE913850; // Unknown = 
        public const ulong FStringLuaAppGameTileVideoManufacturerPipeDenyList = 0x19BBE912D90; // Unknown = 
        public const ulong FStringLuaAppIECVRLayerName = 0x19BA3BB2B10; // Unknown = 
        public const ulong FStringLuaAppIECVRVariantKey = 0x19BA3BB0290; // Unknown = 
        public const ulong FStringLuaAppIosPasswordSavingLayer = 0x19BA3BB28D0; // Unknown = 
        public const ulong FStringLuaAppLandingLayer = 0x19BA3BBB610; // Unknown = 
        public const ulong FStringLuaAppLaunchTrackerMilestones = 0x19BC27AE840; // Unknown = 
        public const ulong FStringLuaAppNewSlpEndpointIxpLayer = 0x19B9029E7D0; // Unknown = 
        public const ulong FStringLuaAppOmniRecommendationsTopicIdAndNumberOfItemsToCache = 0x19BA3A71890; // Unknown = 
        public const ulong FStringLuaAppPlayButtonAgeCheckAmpFeatureName = 0x19B9F18A9C8; // Unknown = 
        public const ulong FStringLuaAppPlayButtonAgeCheckAmpNameSpace = 0x19B9F18E688; // Unknown = 
        public const ulong FStringLuaAppPlayWithRewardBetaIxpTreatmentValue = 0x19B90640690; // Unknown = 
        public const ulong FStringLuaAppPlayWithRewardBetaIxpVariantKey = 0x19B90640490; // Unknown = 
        public const ulong FStringLuaAppPlayWithRewardBetaUniverses = 0x19B90640250; // Unknown = 
        public const ulong FStringLuaAppRelativeGuiIxpLayer = 0x19B94811910; // Unknown = 
        public const ulong FStringLuaAppSduiEdpIxpLayer = 0x19B88C226D0; // Unknown = 
        public const ulong FStringLuaAppSduiEventDetailsIxpLayer = 0x19B88C23A90; // Unknown = 
        public const ulong FStringLuaAppSearchTopPageIxpLayer = 0x19B88C23ED0; // Unknown = 
        public const ulong FStringLuaAppSentryDsn = 0x19B8F90B3D0; // Unknown = 
        public const ulong FStringLuaAppSignupLayer = 0x19BA3BB5A50; // Unknown = 
        public const ulong FStringLuaAppSlpIxpLayer = 0x19B948106D0; // Unknown = 
        public const ulong FStringLuaAppSocialAddFriendsPageLayer = 0x19BA6A3ED10; // Unknown = 
        public const ulong FStringLuaAppSocialConnectTabLayer = 0x19BA6A39D50; // Unknown = 
        public const ulong FStringLuaAppSocialFriendsLandingLayer = 0x19BA6A34D10; // Unknown = 
        public const ulong FStringLuaAppSocialFriendsLayer = 0x19BA6A38948; // Unknown = 
        public const ulong FStringLuaAppSocialProfileLayer = 0x19BA6A30590; // Unknown = 
        public const ulong FStringLuaAppSocialUserSearchResultsPageLayer = 0x19BA6A354D0; // Unknown = 
        public const ulong FStringLuaAppSortsWithDividers = 0x19BC054CF50; // Unknown = 
        public const ulong FStringLuaAppUpsellMaturityRatingToSettingMapping = 0x19BA6791190; // Unknown = 
        public const ulong FStringLuaAppVerticalEfficiencyExpLayer = 0x19BA5BD9750; // Unknown = 
        public const ulong FStringLuaAppVngAppIxpUserLayer = 0x19B94811FD0; // Unknown = 
        public const ulong FStringLuaAppVngIxpDismissable = 0x19B948120D0; // Unknown = 
        public const ulong FStringLuaAppVngIxpEnabled = 0x19B94812150; // Unknown = 
        public const ulong FStringLuaAppVngIxpFrequency = 0x19B94811AD0; // Unknown = 
        public const ulong FStringLuaDesktopToastNotificationLayer = 0x19B8C303290; // Unknown = 
        public const ulong FStringLuaEnabledSduiTreatmentTypes = 0x19B88C40AD0; // Unknown = 
        public const ulong FStringLuaErrorByPlatformCounter = 0x19B8F909490; // Unknown = 
        public const ulong FStringLuaGameInviteMenuLayer = 0x19B8C303CD0; // Unknown = 
        public const ulong FStringLuaLoginRevampIxpLayer = 0x19B945A0750; // Unknown = 
        public const ulong FStringLuaMultiPageSignupIxpLayer = 0x19B945A05D0; // Unknown = 
        public const ulong FStringLuaShareGameLuaChatInputBarEntryCounter = 0x19BB6BB0C50; // Unknown = 
        public const ulong FStringLuaShareGameLuaChatInputBarInviteCounter = 0x19BB6BB32D0; // Unknown = 
        public const ulong FStringLuaShareGameLuaGameDetailsEntryCounter = 0x19BB6BB1AD0; // Unknown = 
        public const ulong FStringLuaShareGameLuaGameDetailsInviteCounter = 0x19BB6BB1550; // Unknown = 
        public const ulong FStringLuaShareGameRoactChatInputBarEntryCounter = 0x19D86D68DC8; // Unknown = 
        public const ulong FStringLuaShareGameRoactChatInputBarInviteCounter = 0x19D86D66DE8; // Unknown = 
        public const ulong FStringLuaUniversalAppGameInviteMenuLayer = 0x19B9F182520; // Unknown = 
        public const ulong FStringLuckyRecommendationEnableVariant = 0x19B8FDEDF50; // Unknown = 
        public const ulong FStringLuckyRecommendationExpLayer = 0x19BAF80AB30; // Unknown = 
        public const ulong FStringMemoryShellHost = 0x19B8F742010; // Unknown = 
        public const ulong FStringMicrophoneDevicePermissionsLoggingEventName = 0x19BA4E9E4D0; // Unknown = 
        public const ulong FStringMobilePopularItemBadgingLayer = 0x19BA4004FE0; // Unknown = 
        public const ulong FStringMobileSoundAndHapticsLayer = 0x19BA3BBEC50; // Unknown = 
        public const ulong FStringMomentsEmojiFallbackCatalogJSON = 0x19BA8025910; // Unknown = 
        public const ulong FStringMomentsFeedWatchPageRouteName = 0x19BAFB60610; // Unknown = 
        public const ulong FStringMomentsUploadUniverseId = 0x19D86F06250; // Unknown = 
        public const ulong FStringMrRouterEnvName = 0x19BA3A74350; // Unknown = 
        public const ulong FStringMyStatsExperienceStatsBaseUrl = 0x19BAD28A610; // Unknown = 
        public const ulong FStringMyStatsExperienceStatsPath = 0x19BAD288BD0; // Unknown = 
        public const ulong FStringNewConversationCreatedCounter = 0x19BA6074690; // Unknown = 
        public const ulong FStringNewFriendRequestsBadgeLayer = 0x19B8C2EAB10; // Unknown = 
        public const ulong FStringNewInGameMenuForcedUserIds = 0x19BA36661D0; // Unknown = 
        public const ulong FStringNotificationsOptInImprovementsFieldName = 0x19B8C3043D0; // Unknown = 
        public const ulong FStringNotificationsStreamNotificationUXLayer = 0x19B8C303650; // Unknown = 
        public const ulong FStringOffPlatformIXPName = 0x19BAFCF0790; // Unknown = 
        public const ulong FStringOldAllFriendsCarouselLoadingTimeDoneStats = 0x19B90267750; // Unknown = 
        public const ulong FStringOldAllFriendsCarouselLoadingTimeFailedStats = 0x19B90267690; // Unknown = 
        public const ulong FStringOnlineFriendsCarouselLoadingTimeDoneStats = 0x19B90267AD0; // Unknown = 
        public const ulong FStringOnlineFriendsCarouselLoadingTimeFailedStats = 0x19B90267710; // Unknown = 
        public const ulong FStringOnlineFriendsRefetchOnFriendshipUpdateCounter = 0x19B902681D0; // Unknown = 
        public const ulong FStringOnlineFriendsRefetchOnPresenceUpdateCounter = 0x19B90266490; // Unknown = 
        public const ulong FStringPCGDKFilteredNotificationTypes = 0x19B8C303D10; // Unknown = 
        public const ulong FStringPYMKCarouselGenericTileClicked = 0x19B8FC3B310; // Unknown = 
        public const ulong FStringPYMKCarouselLoadedWithUsers = 0x19B8FC3A4D0; // Unknown = 
        public const ulong FStringPYMKCarouselRequestFriendship = 0x19B8FC3B1D0; // Unknown = 
        public const ulong FStringPYMKCarouselUserPressed = 0x19B8FC3B110; // Unknown = 
        public const ulong FStringPaginatedCarouselExperimentLayer = 0x19B8C2EAF10; // Unknown = 
        public const ulong FStringParentLinkAmpNameSpace = 0x19BA59B3590; // Unknown = 
        public const ulong FStringPartyPageCarouselExpLayer = 0x19B82C11210; // Unknown = 
        public const ulong FStringPartyPageCarouselVariant = 0x19B8FDEE590; // Unknown = 
        public const ulong FStringPartyVoiceEligibilityAllowList = 0x19BA6727590; // Unknown = 
        public const ulong FStringPerfInsightsIXPLayer = 0x19B90290090; // Unknown = 
        public const ulong FStringPhoneVerificationCloseCounter = 0x19BAFCF9A90; // Unknown = 
        public const ulong FStringPhoneVerificationWebviewCounter = 0x19BAFCFBC10; // Unknown = 
        public const ulong FStringPioneerLaunchPlaceId = 0x19B9ACBFDD0; // Unknown = 
        public const ulong FStringPlatformEventUrl = 0x19BA59B4790; // Unknown = 
        public const ulong FStringPlatformLeaderboardUnrankedLabel = 0x19BACE9B4D0; // Unknown = 
        public const ulong FStringPlatformLeaderboardsExposure2Layer = 0x19BACE994D0; // Unknown = 
        public const ulong FStringPlayerContextualMenuVendorImagePath = 0x19B859CA190; // Unknown = 
        public const ulong FStringPlayerListIXPLayer = 0x19BACE98090; // Unknown = 
        public const ulong FStringPlayerListOverrideType = 0x19BAD286110; // Unknown = 
        public const ulong FStringPopularFillIconLocation = 0x19BAC832190; // Unknown = 
        public const ulong FStringPresencePropagationDelayMetricName = 0x19B90290750; // Unknown = 
        public const ulong FStringPreviousFriendRequestsCountEngineFeature = 0x19BACFD0030; // Unknown = 
        public const ulong FStringPreviousFriendRequestsCountEngineFeature2 = 0x19BACFD7A50; // Unknown = 
        public const ulong FStringPriceChangedSubscriptionMembershipCheckProductTypes = 0x19D85DC7910; // Unknown = 
        public const ulong FStringPrivacyPolicyLink = 0x19B90111590; // Unknown = 
        public const ulong FStringProfileQRCodeFriendRequestAlertsExperimentKey = 0x19B9011A390; // Unknown = 
        public const ulong FStringProfileQRCodeFriendRequestAlertsLayer = 0x19B9011A5D0; // Unknown = 
        public const ulong FStringProfileQRCodeScannerOpened = 0x19BAFCF30D0; // Unknown = 
        public const ulong FStringProfileQRCodeScannerTooltipShown = 0x19BAFCF3E50; // Unknown = 
        public const ulong FStringProfileQRPageFriendRequestBannerAccepted = 0x19BAFCF6650; // Unknown = 
        public const ulong FStringProfileQRPageFriendRequestBannerDismissed = 0x19BAFCF87D0; // Unknown = 
        public const ulong FStringProfileQRPageFriendRequestBannerShown = 0x19BAFCF6AD0; // Unknown = 
        public const ulong FStringProfileQRPageLoad = 0x19BAFCF4F90; // Unknown = 
        public const ulong FStringProfileQRPageLoadFailed = 0x19BAFCF5150; // Unknown = 
        public const ulong FStringPushUpsellChatVariantName = 0x19B9F18F410; // Unknown = 
        public const ulong FStringPushUpsellOnFirstTimeVariantName = 0x19B9F18A1A0; // Unknown = 
        public const ulong FStringPushUpsellVariantName = 0x19B8C303B50; // Unknown = 
        public const ulong FStringQueueEnableAutoJoinNewServerVariant = 0x19B8FDEB4D0; // Unknown = 
        public const ulong FStringQueueEnableJoinNewServerVariant = 0x19B8FDED1D0; // Unknown = 
        public const ulong FStringQueueExpLayer = 0x19BAF80FE50; // Unknown = 
        public const ulong FStringRMDefinition = 0x19BA6A3CD90; // Unknown = 
        public const ulong FStringRccInExperienceNameEnabledAllowList = 0x19B9FDD0B08; // Unknown = 
        public const ulong FStringReactSchedulingContext = 0x19B9ACB1D50; // Unknown = 
        public const ulong FStringReactSchedulingPercentiles = 0x19BA366ED50; // Unknown = 
        public const ulong FStringRealNamesInDisplayNamesExperimentDefinition = 0x19B90642210; // Unknown = 
        public const ulong FStringRealNamesInDisplayNamesIXP_v1 = 0x19B90642450; // Unknown = 
        public const ulong FStringReferralRewardsTermsURL = 0x19B88BE0030; // Unknown = 
        public const ulong FStringReportAnalyticsAbandonedSubmissionTimeStat = 0x19BBBE5CF90; // Unknown = 
        public const ulong FStringReportAnalyticsButtonActivated = 0x19BBBE54250; // Unknown = 
        public const ulong FStringReportAnalyticsFieldChanged = 0x19BBBE5BD10; // Unknown = 
        public const ulong FStringReportAnalyticsFormAbandoned = 0x19BBBE51150; // Unknown = 
        public const ulong FStringReportAnalyticsFormSubmitted = 0x19BBBE51690; // Unknown = 
        public const ulong FStringReportAnalyticsInGameAbuseReport = 0x19BB7F44E90; // Unknown = 
        public const ulong FStringReportAnalyticsLegacyMenuContext = 0x19BBBE52DD0; // Unknown = 
        public const ulong FStringReportAnalyticsLegacySentPageContext = 0x19BBBE52CD0; // Unknown = 
        public const ulong FStringReportAnalyticsNewMenuContext = 0x19BBBE5D6D0; // Unknown = 
        public const ulong FStringReportAnalyticsSubmittedMethodOfAbuseStat = 0x19BBBE57D90; // Unknown = 
        public const ulong FStringReportAnalyticsSuccessfulSubmissionTimeStat = 0x19BBBE52810; // Unknown = 
        public const ulong FStringReportAnythingAnnotationIXPLayerName = 0x19B8C30B450; // Unknown = 
        public const ulong FStringReportMenuIXPLayer = 0x19BA6A36B90; // Unknown = 
        public const ulong FStringReportingIXPLayer = 0x19BA6A36390; // Unknown = 
        public const ulong FStringRoactChatFetchedOlderConversationCounter = 0x19B9026B290; // Unknown = 
        public const ulong FStringRoactChatNavigationChatConversationProfileCounter = 0x19D86D61DE8; // Unknown = 
        public const ulong FStringRoactChatNavigationChatDetailsProfileCounter = 0x19D86D62F68; // Unknown = 
        public const ulong FStringRoactChatUserLoadedCounter = 0x19BAE70ACE8; // Unknown = 
        public const ulong FStringRobloxPlusAmpFeatureName = 0x19B8FC33A50; // Unknown = 
        public const ulong FStringRobloxPlusAmpNamespace = 0x19B8FC33AD0; // Unknown = 
        public const ulong FStringRobloxSubscriptionTermsOfUseLink = 0x19B9F188B50; // Unknown = 
        public const ulong FStringRootNavigatorInitialRouteName = 0x19B90641A90; // Unknown = 
        public const ulong FStringScheduledSquadsListChatLandingScreenEntrypointVariant = 0x19B8FDED9D0; // Unknown = 
        public const ulong FStringScheduledSquadsListExpLayer = 0x19B8FDED8D0; // Unknown = 
        public const ulong FStringSduiEagerProcessCollectionIds = 0x19B9011F490; // Unknown = 
        public const ulong FStringSduiForceImageQualityLevel = 0x19B8FC32D90; // Unknown = 
        public const ulong FStringSduiForcePerfLevel = 0x19B8FC32F90; // Unknown = 
        public const ulong FStringSduiNonGameTopicIds = 0x19B9011F590; // Unknown = 
        public const ulong FStringSelectInSceneIXPField = 0x19BA6A33A10; // Unknown = 
        public const ulong FStringSelectInSceneReportMenuOverrideUserIds = 0x19BB7F400D0; // Unknown = 
        public const ulong FStringSelfProfileView = 0x19B8C2E9710; // Unknown = 
        public const ulong FStringShareCaptureGenerateLinkFailed = 0x19B9298EA78; // Unknown = 
        public const ulong FStringShareCapturePromptAccepted = 0x19BAC87C550; // Unknown = 
        public const ulong FStringShareCapturePromptRejected = 0x19D8516A9E0; // Unknown = 
        public const ulong FStringShowAddTrustedFriendsHeaderTextAmpFeature = 0x19BA8440F50; // Unknown = 
        public const ulong FStringSocialCaptureIXPLayer = 0x19B8C2EA510; // Unknown = 
        public const ulong FStringSocialCaptureTakenIXPLayer = 0x19B8C2EA5D0; // Unknown = 
        public const ulong FStringSocialCarouselTreatment = 0x19BACFD0FD0; // Unknown = 
        public const ulong FStringSocialCarouselVendorImagePath = 0x19B8FA1CDD0; // Unknown = 
        public const ulong FStringSocialNavigationHomePageAddFriends = 0x19BB6B29F30; // Unknown = 
        public const ulong FStringSocialNavigationHomePageCarouselLuaProfile = 0x19BB6BB8BD0; // Unknown = 
        public const ulong FStringSocialNavigationHomePageFriendsLanding = 0x19BB6BB8D90; // Unknown = 
        public const ulong FStringSocialNavigationMorePageFriendsLanding = 0x19BB6BB9190; // Unknown = 
        public const ulong FStringSocialNetworksEditProfileIXPLayer = 0x19B90643AD0; // Unknown = 
        public const ulong FStringSocialOnboardingExperimentLayer = 0x19B8C2EAD50; // Unknown = 
        public const ulong FStringSocialProfileCurrentlyWearingClickThroughLayer = 0x19BB7F42BD0; // Unknown = 
        public const ulong FStringSocialViewFriendSortInGameFriendsLayer = 0x19B8FA1E550; // Unknown = 
        public const ulong FStringSortInvitesByScoreExperimentLayer = 0x19BADF93950; // Unknown = 
        public const ulong FStringSpatialRobloxUIIXPLayerName = 0x19B9FDD4F88; // Unknown = 
        public const ulong FStringSpatialRobloxUIIXPSpatialUIVariantValue = 0x19B9FDD5008; // Unknown = 
        public const ulong FStringSpatialRobloxUIIXPUITypeVariableName = 0x19B9FDD5088; // Unknown = 
        public const ulong FStringSquadCoordinationExperienceJoinExperimentLayer = 0x19B8FDEDF90; // Unknown = 
        public const ulong FStringSquadCoordinationUiExperimentLayer = 0x19B8FDED550; // Unknown = 
        public const ulong FStringSquadEnablePartyCoordinationUiVariant = 0x19B8FDEC1D0; // Unknown = 
        public const ulong FStringSquadEnablePartyQuickStartVariant = 0x19B8FDEE950; // Unknown = 
        public const ulong FStringSquadEnableRegroupVariant = 0x19B8FDEEFD0; // Unknown = 
        public const ulong FStringSquadQuickStartExperimentLayer = 0x19B8FDEE790; // Unknown = 
        public const ulong FStringSquadRegroupExpLayer = 0x19BAF804690; // Unknown = 
        public const ulong FStringSquadsUnifyCoplayExpLayer = 0x19B8FDEDE10; // Unknown = 
        public const ulong FStringSquadsUnifyCoplayMultiInvitePartyCreationVariant = 0x19B8FDEE390; // Unknown = 
        public const ulong FStringSquadsUnifyCoplayOneOnOnePartyCreationVariant = 0x19B8FDEE290; // Unknown = 
        public const ulong FStringStreamNotificationUXDropdownVariant = 0x19B8FA1EF10; // Unknown = 
        public const ulong FStringStreamNotificationUXExposureLayer = 0x19B8FA1F910; // Unknown = 
        public const ulong FStringSupportedAppLaunchMilestonesForReactProfilerLogger = 0x19BA6098690; // Unknown = 
        public const ulong FStringSuppressMutedErrorKeys = 0x19BA3BB6610; // Unknown = 
        public const ulong FStringTTIMetricsTableName = 0x19B8F741750; // Unknown = 
        public const ulong FStringTakeItDownReportLink = 0x19BA3A5C8D0; // Unknown = 
        public const ulong FStringTextureTranscode7FallbackVersionTM1 = 0x19B92244EE0; // Unknown = 
        public const ulong FStringThrottleParticipantsUpdateIXPLayerValue = 0x19B8FDEB310; // Unknown = 
        public const ulong FStringThrottleVoiceParticipantsUpdateLayerName = 0x19B8FDEA8D0; // Unknown = 
        public const ulong FStringThrottleVoiceParticipantsUpdateLayerValue = 0x19B8FDEAAD0; // Unknown = 
        public const ulong FStringTiltLoadingScreenPreLogoText = 0x19B9AF12B10; // Unknown = 
        public const ulong FStringTimeoutLoadingLocalPlayerInBackgroundDM = 0x19B82B7F410; // Unknown = 
        public const ulong FStringToastNotificationEventLoggingLevel = 0x19BA6070AD0; // Unknown = 
        public const ulong FStringTopSongsSortExploreApiPageType = 0x19B88C4ED10; // Unknown = 
        public const ulong FStringTriggerAgeCheckUpsellIncludingVPCAmpFeature = 0x19BA844C710; // Unknown = 
        public const ulong FStringTutorialUpsellIXPLayerName = 0x19B90291850; // Unknown = 
        public const ulong FStringUXForCameraPerformanceIXPLayerName = 0x19B9AF10850; // Unknown = 
        public const ulong FStringUnfilteredMessageDarkHexColor = 0x19BA802A890; // Unknown = 
        public const ulong FStringUnfilteredMessageLightHexColor = 0x19BA80236D0; // Unknown = 
        public const ulong FStringUnfilteredMessagePressedDarkHexColor = 0x19BA802EED0; // Unknown = 
        public const ulong FStringUnfilteredMessagePressedLightHexColor = 0x19BA8020AD0; // Unknown = 
        public const ulong FStringUnfilteredThreadsLearnMoreUrl = 0x19B8FA15E90; // Unknown = 
        public const ulong FStringUniversalAppCameraIXPLayer = 0x19B90644F90; // Unknown = 
        public const ulong FStringUniversesExposedToPeopleCardsTooltipKey = 0x19BB7F46610; // Unknown = 
        public const ulong FStringUserProfileStoreMaxLoggingLevel = 0x19BA515EFD0; // Unknown = 
        public const ulong FStringUserProfilesRequestBegin = 0x19BA51566D0; // Unknown = 
        public const ulong FStringUserProfilesRequestFail = 0x19BA515D0D0; // Unknown = 
        public const ulong FStringUserProfilesRequestFailAfterRetry = 0x19BA515F150; // Unknown = 
        public const ulong FStringUserProfilesRequestFailAfterRetryDuration = 0x19BA515DA10; // Unknown = 
        public const ulong FStringUserProfilesRequestFailDuration = 0x19BA5157ED0; // Unknown = 
        public const ulong FStringUserProfilesRequestSuccess = 0x19BA5152450; // Unknown = 
        public const ulong FStringUserProfilesRequestSuccessAfterRetry = 0x19BA51589D0; // Unknown = 
        public const ulong FStringUserProfilesRequestSuccessAfterRetryDuration = 0x19BBB7FDC30; // Unknown = 
        public const ulong FStringUserProfilesRequestSuccessDuration = 0x19BA515C6D0; // Unknown = 
        public const ulong FStringUserProfilesUnmountEarly = 0x19BA51563D0; // Unknown = 
        public const ulong FStringUserSearchLoadingTimeDoneStats = 0x19B9011E550; // Unknown = 
        public const ulong FStringUserSearchLoadingTimeFailedStats = 0x19B9011E890; // Unknown = 
        public const ulong FStringUserSearchLoadingTimeNextPageDoneStats = 0x19B9011ECD0; // Unknown = 
        public const ulong FStringUserSearchLoadingTimeNextPageFailedStats = 0x19B9011EBD0; // Unknown = 
        public const ulong FStringUserSearchPlayerFriendAcceptCounter = 0x19B9011E490; // Unknown = 
        public const ulong FStringUserSearchPlayerFriendRequestCounter = 0x19B9011E810; // Unknown = 
        public const ulong FStringUserSearchPlayerTileClickCounter = 0x19B9011E190; // Unknown = 
        public const ulong FStringUserSearchPlayerTileImpressionsCounter = 0x19B9011EAD0; // Unknown = 
        public const ulong FStringV1MenuLanguageSelectionFeatureForcedUserIds = 0x19B9FD8CE50; // Unknown = 
        public const ulong FStringVNGDownloadNowUrl = 0x19B88C4DBD0; // Unknown = 
        public const ulong FStringVNGTosUrl = 0x19B88C4B5D0; // Unknown = 
        public const ulong FStringVNGWebshopUrl = 0x19B88C4A6D0; // Unknown = 
        public const ulong FStringVoiceExposureIXPLayerName = 0x19B9AF10690; // Unknown = 
        public const ulong FStringVoicePerformanceIXPLayerName = 0x19BBCD72F90; // Unknown = 
        public const ulong FStringVoicePerformanceThrottlingIXPLayerName = 0x19B8FDEB0D0; // Unknown = 
        public const ulong FStringVoiceUIImprovementsIXPLayerName = 0x19B9F185F20; // Unknown = 
        public const ulong FStringVoiceUpsellLayer = 0x19B88C4E150; // Unknown = 
        public const ulong FStringVoiceUpsellV2ExperimentLayerLua = 0x19BA3BBE350; // Unknown = 
        public const ulong FStringVoiceUserAgencyIXPLayerName = 0x19B9AF10C10; // Unknown = 
        public const ulong FStringVoiceVolumeControlsGlobalVoiceVolumeSliderIxpLayer = 0x19BA5159A90; // Unknown = 
        public const ulong FStringVrAvatarPanelsDistanceOffsetOverride = 0x19B859C54D0; // Unknown = 
        public const ulong FStringVrSystemBarXOffSetOverride = 0x19BA6A361D0; // Unknown = 
        public const ulong FStringVrSystemBarYOffSetOverride = 0x19BA6A37A50; // Unknown = 
        public const ulong FStringVrSystemBarZOffSetOverride = 0x19BA6A3EAD0; // Unknown = 
        public const ulong FStringWHAM1707IXPField = 0x19B9FD8F908; // Unknown = 
        public const ulong FStringWhitelistVerifiedUserId = 0x19B85788090; // Unknown = 
        public const ulong FStringXboxClassicUILayer = 0x19BA3BBB5D0; // Unknown = 
        public const ulong SFUClientAnalyticsInfluxReportHundredthsPercent = 0x19B8153E690; // Unknown = 
    }

} // namespace RobloxOffsets
