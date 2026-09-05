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
#pragma pack(push, 1)
namespace structs {

    struct AirProperties {
        char pad_0[0x18];
        float AirDensity;  // 0x18  scanned for 9.67f = 9.67
        char pad_1[0x20];
        Vector3 GlobalWind;  // 0x3C
    };  // sizeof = 0x48

    struct Atmosphere {
        char pad_0[0xB8];
        Color3 Color;  // 0xB8
        Color3 Decay;  // 0xC4
        float Density;  // 0xD0  scanned for 0.324f = 0.324
        float Glare;  // 0xD4  scanned for 0.432f = 0.432
        float Haze;  // 0xD8  scanned for 0.123f = 0.123
        float Offset;  // 0xDC  scanned for 0.561f = 0.561
    };  // sizeof = 0xE0

    struct Attachment {
        char pad_0[0xC4];
        Vector3 Position;  // 0xC4  DataModel>Workspace>TestPartN>SkidAttachN
    };  // sizeof = 0xD0

    struct BasePart {
        char pad_0[0x10C];
        float Reflectance;  // 0x10C
        char pad_1[0x20];
        float Transparency;  // 0x130
        char pad_2[0x1];
        bool CastShadow;  // 0x135
        bool Locked;  // 0x136
        bool Massless;  // 0x137
        char pad_3[0x50];
        uintptr_t Primitive;  // 0x188
        char pad_4[0x18];
        Color3 Color3;  // 0x1A8
        char pad_5[0x5];
        uint8_t Shape;  // 0x1B9
        char pad_6[0xC6];
        Vector3 Velocity;  // 0x280  DataModel>Workspace>TestPartN>BasePart>Primitive
        Vector3 AngularVelocity;  // 0x28C  DataModel>Workspace>TestPartN>BasePart>Primitive
        char pad_7[0xA6];
        uint8_t PrimitiveFlags;  // 0x33E
    };  // sizeof = 0x33F

    struct BloomEffect {
        char pad_0[0xB8];
        float Intensity;  // 0xB8  scanned for 1.23f = 1.23
        float Size;  // 0xBC  scanned for 24.5 = 24.5
        float Threshold;  // 0xC0  scanned for 2.1f = 2.1
    };  // sizeof = 0xC4

    struct BoolValue {
        char pad_0[0xB8];
        bool Value;  // 0xB8  DataModel>Workspace>SkidValueN
    };  // sizeof = 0xB9

    struct ByteCode {
        char pad_0[0x10];
        uintptr_t Pointer;  // 0x10
    };  // sizeof = 0x18

    struct CFrameValue {
        char pad_0[0xDC];
        Vector3 Value;  // 0xDC  DataModel>Workspace>SkidValueN
    };  // sizeof = 0xE8

    struct CachedItem {
        char pad_0[0x28];
        uintptr_t FileMeshData;  // 0x28
    };  // sizeof = 0x30

    struct Camera {
        char pad_0[0xC8];
        uintptr_t CameraSubject;  // 0xC8
        char pad_1[0x8];
        CFrame CFrame;  // 0xD8
        char pad_2[0x38];
        float FieldOfView;  // 0x140  scanned for fov_radians = 1.9757127
        char pad_3[0x188];
        Vector2 ViewportSize;  // 0x2CC
    };  // sizeof = 0x2D4

    struct CharacterMesh {
        char pad_0[0x148];
        uint8_t BodyPart;  // 0x148
    };  // sizeof = 0x149

    struct ClassDescriptor {
        char pad_0[0x40];
        uintptr_t PropertyDescriptors;  // 0x40
        char pad_1[0x40];
        uintptr_t EventDescriptors;  // 0x88
        char pad_2[0x40];
        uintptr_t FunctionDescriptors;  // 0xD0
        char pad_3[0x158];
        uintptr_t Creator;  // 0x230  ICreator vtable, [0] = create fn
    };  // sizeof = 0x238

    struct ClickDetector {
        char pad_0[0xE8];
        float MaxActivationDistance;  // 0xE8  DataModel>Workspace>TestPartN>SkidClickN
    };  // sizeof = 0xEC

    struct DataModel {
        char pad_0[0x10];
        uint32_t HackFlagNodeValue;  // 0x10  Flag dword inside a detection flag list node.
        char pad_1[0x104];
        uintptr_t JobId;  // 0x118
        char pad_2[0x38];
        uintptr_t Workspace;  // 0x158  DataModel instance > Workspace service child
        char pad_3[0x20];
        uint64_t CreatorId;  // 0x180  scanned for data->creator_id = 3672944211
        uint64_t GameId;  // 0x188  scanned for data->game_id = 10735428841
        uint64_t PlaceId;  // 0x190  scanned for data->place_id = 90790446880270
        char pad_4[0x438];
        uint32_t GameLoaded;  // 0x5D0  scanned for 31 = 31
        char pad_5[0x254];
        uintptr_t HackFlagSetMutex;  // 0x828  DMHackFlagSetMutex, guards the per-DataModel detection flag list.
        uintptr_t HackFlagSetList;  // 0x830  Circular std::list sentinel of detection flag nodes. Walk _Next at +0x0.
        char pad_6[0x120];
        uint32_t DataModelType;  // 0x958  DWORD containing the type of datamodel, related to whether you're in game or not.
    };  // sizeof = 0x95C

    struct Decal {
        char pad_0[0x25C];
        float Transparency;  // 0x25C  DataModel>Workspace>TestPartN>SkidDecalN
    };  // sizeof = 0x260

    struct Descriptor {
        char pad_0[0x8];
        uintptr_t Name;  // 0x8
    };  // sizeof = 0x10

    struct EngineDetections {
        char pad_0[0x7EAD1C8];
        uint32_t dwDetectionFlag_0;  // 0x7EAD1C8  Detection flag #0 - referenced by PingItem serializer; absolute RVA, build-specific
        uint32_t dwDetectionFlag_1;  // 0x7EAD1CC  Detection flag #1 - referenced by PingItem serializer; absolute RVA, build-specific
        char pad_1[0x24C6C];
        uint32_t dwDetectionFlag_2;  // 0x7ED1E3C  Detection flag #2 - referenced by PingItem serializer; absolute RVA, build-specific
        char pad_2[0x33C];
        uint32_t dwDetectionFlag_3;  // 0x7ED217C  Detection flag #3 - referenced by PingItem serializer; absolute RVA, build-specific
        char pad_3[0x1CA8];
        uint32_t dwDetectionFlag_4;  // 0x7ED3E28  Detection flag #4 - referenced by PingItem serializer; absolute RVA, build-specific
        uint32_t dwDetectionFlag_5;  // 0x7ED3E2C  Detection flag #5 - referenced by PingItem serializer; absolute RVA, build-specific
        char pad_4[0x9C6C];
        uint32_t dwDetectionFlag_6;  // 0x7EDDA9C  Detection flag #6 - referenced by PingItem serializer; absolute RVA, build-specific
        char pad_5[0x80C];
        uint32_t dwDetectionFlag_7;  // 0x7EDE2AC  Detection flag #7 - referenced by PingItem serializer; absolute RVA, build-specific
        char pad_6[0x8C];
        uint32_t dwDetectionFlag_8;  // 0x7EDE33C  Detection flag #8 - referenced by PingItem serializer; absolute RVA, build-specific
        char pad_7[0x1F8];
        uint32_t dwDetectionFlag_9;  // 0x7EDE538  Detection flag #9 - referenced by PingItem serializer; absolute RVA, build-specific
        uint32_t dwDetectionFlag_10;  // 0x7EDE53C  Detection flag #10 - referenced by PingItem serializer; absolute RVA, build-specific
        char pad_8[0x658];
        uint32_t dwDetectionFlag_11;  // 0x7EDEB98  Detection flag #11 - referenced by PingItem serializer; absolute RVA, build-specific
        uint32_t dwDetectionFlag_12;  // 0x7EDEB9C  Detection flag #12 - referenced by PingItem serializer; absolute RVA, build-specific
        char pad_9[0x7F80];
        uint32_t dwDetectionFlag_13;  // 0x7EE6B20  Detection flag #13 - referenced by PingItem serializer; absolute RVA, build-specific
        uint32_t dwDetectionFlag_14;  // 0x7EE6B24  Detection flag #14 - referenced by PingItem serializer; absolute RVA, build-specific
        uint32_t dwDetectionFlag_15;  // 0x7EE6B28  Detection flag #15 - referenced by PingItem serializer; absolute RVA, build-specific
        uint32_t dwDetectionFlag_16;  // 0x7EE6B2C  Detection flag #16 - referenced by PingItem serializer; absolute RVA, build-specific
        uint32_t dwDetectionFlag_17;  // 0x7EE6B30  Detection flag #17 - referenced by PingItem serializer; absolute RVA, build-specific
    };  // sizeof = 0x7EE6B34

    struct FakeDataModel {
        char pad_0[0x1F8];
        uintptr_t RealDataModel;  // 0x1F8  *(*FakeDataModelPtr)
        char pad_1[0x8CA9AC8];
        uintptr_t Pointer;  // 0x8CA9CC8  global holding the fake DataModel instance - external attach chain entry
    };  // sizeof = 0x8CA9CD0

    struct FileMeshData {
        uintptr_t Vertices;  // 0x0
        uintptr_t VerticesEnd;  // 0x8
        char pad_0[0x20];
        uintptr_t Faces;  // 0x30
        uintptr_t FacesEnd;  // 0x38
        char pad_1[0x270];
        Vector3 AabbMin;  // 0x2B0
        Vector3 AabbMax;  // 0x2BC
    };  // sizeof = 0x2C8

    struct Fire {
        char pad_0[0xD8];
        float Heat;  // 0xD8  DataModel>Workspace>TestPartN>SkidFireN
        float Size;  // 0xDC  DataModel>Workspace>TestPartN>SkidFireN
    };  // sizeof = 0xE0

    struct FunctionDescriptor {
        char pad_0[0x80];
        uintptr_t Function;  // 0x80
    };  // sizeof = 0x88

    struct GuiBase2D {
        char pad_0[0xE8];
        float AbsoluteRotation;  // 0xE8
        char pad_1[0x1C];
        Vector2 AbsolutePosition;  // 0x108
        char pad_2[0x4];
        Vector2 AbsoluteSize;  // 0x114
    };  // sizeof = 0x11C

    struct GuiObject {
        char pad_0[0xE8];
        float Rotation;  // 0xE8
        char pad_1[0x454];
        Color3 BackgroundColor3;  // 0x540
        Color3 BorderColor3;  // 0x54C
        Vector2 AnchorPoint;  // 0x558
        uint8_t AutomaticSize;  // 0x560
        char pad_2[0x3];
        float BackgroundTransparency;  // 0x564
        uint8_t BorderMode;  // 0x568
        char pad_3[0x3];
        int32_t BorderSizePixel;  // 0x56C
        char pad_4[0x8];
        uint8_t GuiState;  // 0x578
        char pad_5[0x7];
        int32_t LayoutOrder;  // 0x580
        char pad_6[0x18];
        int32_t SelectionOrder;  // 0x59C
        uint8_t SizeConstraint;  // 0x5A0
        char pad_7[0x3];
        int32_t ZIndex;  // 0x5A4
        bool Active;  // 0x5A8
        bool ClipsDescendants;  // 0x5A9
        char pad_8[0x1];
        bool Interactable;  // 0x5AB
        bool Selectable;  // 0x5AC
        bool Visible;  // 0x5AD
    };  // sizeof = 0x5AE

    struct Highlight {
        char pad_0[0xB8];
        uintptr_t Adornee;  // 0xB8
        char pad_1[0x8];
        Color3 FillColor;  // 0xC8
        Color3 OutlineColor;  // 0xD4
        uint8_t DepthMode;  // 0xE0
        char pad_2[0x3];
        float FillTransparency;  // 0xE4
        char pad_3[0x4];
        float OutlineTransparency;  // 0xEC
        char pad_4[0x4];
        bool Enabled;  // 0xF4
    };  // sizeof = 0xF5

    struct HopperBin {
        char pad_0[0x468];
        uint32_t BinType;  // 0x468
    };  // sizeof = 0x46C

    struct Humanoid {
        char pad_0[0x108];
        uintptr_t SeatPart;  // 0x108
        char pad_1[0x18];
        Vector3 CameraOffset;  // 0x128
        char pad_2[0x18];
        Vector3 TargetPoint;  // 0x14C
        char pad_3[0xC];
        Vector3 WalkToPoint;  // 0x164
        char pad_4[0x10];
        uint8_t DisplayDistanceType;  // 0x180
        char pad_5[0x7];
        float HealthDisplayDistance;  // 0x188
        uint8_t HealthDisplayType;  // 0x18C
        char pad_6[0x3];
        float Health;  // 0x190  scanned for 67.f = 67
        float HipHeight;  // 0x194
        char pad_7[0x8];
        float JumpHeight;  // 0x1A0
        float JumpPower;  // 0x1A4
        float MaxHealth;  // 0x1A8
        float MaxSlopeAngle;  // 0x1AC
        float NameDisplayDistance;  // 0x1B0
        uint8_t NameOcclusion;  // 0x1B4
        char pad_8[0xB];
        uint8_t RigType;  // 0x1C0
        char pad_9[0xF];
        float WalkSpeed;  // 0x1D0
        bool AutoJumpEnabled;  // 0x1D4
        bool AutoRotate;  // 0x1D5
        bool AutomaticScalingEnabled;  // 0x1D6
        bool BreakJointsOnDeath;  // 0x1D7
        bool EvaluateStateMachine;  // 0x1D8
        char pad_10[0x3];
        bool PlatformStand;  // 0x1DC  DataModel>Workspace>Characters>TestCharN>Humanoid
        bool RequiresNeck;  // 0x1DD
        bool Sit;  // 0x1DE
        char pad_11[0x1];
        bool UseJumpPower;  // 0x1E0
        char pad_12[0x1DB];
        float WalkSpeedCheck;  // 0x3BC
    };  // sizeof = 0x3C0

    struct ImageLabel {
        char pad_0[0xAA4];
        float ImageTransparency;  // 0xAA4  DataModel>Workspace>SkidImage
    };  // sizeof = 0xAA8

    struct InputObject {
        char pad_0[0xD4];
        Vector2 MousePosition;  // 0xD4
    };  // sizeof = 0xDC

    struct Instance {
        char pad_0[0x18];
        uintptr_t ClassDescriptor;  // 0x18
        char pad_1[0x48];
        uintptr_t Parent;  // 0x68
        uintptr_t NameContainer;  // 0x70
        uintptr_t ChildrenStart;  // 0x78
    };  // sizeof = 0x80

    struct IntValue {
        char pad_0[0xB8];
        int32_t Value;  // 0xB8  DataModel>Workspace>SkidValueN
    };  // sizeof = 0xBC

    struct Light {
        char pad_0[0xCC];
        float Brightness;  // 0xCC  DataModel>Workspace>TestPartN>SkidLightN
        char pad_1[0x8];
        float Range;  // 0xD8  DataModel>Workspace>TestPartN>SkidLightN
    };  // sizeof = 0xDC

    struct Lighting {
        char pad_0[0xC8];
        uint64_t ClockTime;  // 0xC8  scanned for 32400000000 = 32400000000
        Color3 Ambient;  // 0xD0
        Color3 ColorShift_Bottom;  // 0xDC
        Color3 ColorShift_Top;  // 0xE8
        Color3 FogColor;  // 0xF4
        Color3 OutdoorAmbient;  // 0x100
        char pad_1[0xC];
        float Brightness;  // 0x118  scanned for 3.567f = 3.567
        float EnvironmentDiffuseScale;  // 0x11C  scanned for 0.678 = 0.678
        float EnvironmentSpecularScale;  // 0x120  scanned for 0.762 = 0.762
        float ExposureCompensation;  // 0x124  scanned for -1.572f = -1.572
        char pad_2[0x4];
        float FogEnd;  // 0x12C  scanned for 60.456f = 60.456
        float FogStart;  // 0x130  scanned for 123.456f = 123.456
        char pad_3[0x8];
        float ShadowSoftness;  // 0x13C  scanned for 0.456f = 0.456
        char pad_4[0x88];
        uintptr_t Sky;  // 0x1C8
        char pad_5[0x8];
        uintptr_t Atmosphere;  // 0x1D8
    };  // sizeof = 0x1E0

    struct LightingParameters {
        char pad_0[0x134];
        float GeographicLatitude;  // 0x134  scanned for 115.9 = 115.9
        Vector3 SkyAmbient2;  // 0x138
        char pad_1[0xC];
        Vector3 SkyAmbient;  // 0x150
        Vector3 LightColor;  // 0x15C
        Vector3 LightDirection;  // 0x168
        uint8_t Source;  // 0x174
        char pad_2[0x3];
        Vector3 TrueSunPosition;  // 0x178
        Vector3 TrueMoonPosition;  // 0x184
    };  // sizeof = 0x190

    struct LinearVelocity {
        char pad_0[0x190];
        float MaxForce;  // 0x190  DataModel>Workspace>SkidLinVelN
        char pad_1[0xB0];
        Vector3 VectorVelocity;  // 0x244  DataModel>Workspace>SkidLinVelN
    };  // sizeof = 0x250

    struct LocalScript {
        char pad_0[0x190];
        uintptr_t Bytecode;  // 0x190
        char pad_1[0x8];
        uintptr_t Hash;  // 0x1A0
    };  // sizeof = 0x1A8

    struct LruHolder {
        char pad_0[0x20];
        uintptr_t MemEnforcedLRUCache;  // 0x20
    };  // sizeof = 0x28

    struct LruNode {
        uintptr_t Next;  // 0x0
        char pad_0[0x8];
        uintptr_t MeshId;  // 0x10
        char pad_1[0x20];
        uintptr_t CachedItem;  // 0x38
    };  // sizeof = 0x40

    struct LuaPage {
        char pad_0[0x8];
        uintptr_t lpListnext;  // 0x8  lua_Page list next page
        char pad_1[0x10];
        uint32_t dwPagesize;  // 0x20  lua_Page pageSize
        uint32_t dwBlocksize;  // 0x24  lua_Page blockSize
        char pad_2[0x8];
        uint32_t dwFreenext;  // 0x30  lua_Page freeNext
        char pad_3[0xC];
        uintptr_t lpData;  // 0x40  lua_Page data start
    };  // sizeof = 0x48

    struct LuaTable {
        char pad_0[0x5];
        uint8_t dwLsizenode;  // 0x5  Table.lsizenode (log2 node size)
        char pad_1[0x2];
        uint32_t dwArraysize;  // 0x8  Table.sizearray
        char pad_2[0xC];
        uintptr_t lpNode;  // 0x18  Table.node (hash part)
        char pad_3[0x8];
        uintptr_t lpArray;  // 0x28  Table.array (array part)
    };  // sizeof = 0x30

    struct LuauGlobalState {
        char pad_0[0x58];
        uint32_t bCurrentwhite;  // 0x58  global_State.currentwhite GC mark bits
        char pad_1[0x294];
        uintptr_t lpAllgcopages;  // 0x2F0  global_State.allgcopages - head of the lua_Page list holding every live GC object; walk pages via LuaPage::lpListnext, enumerate blocks via dwPagesize/dwBlocksize/lpData
    };  // sizeof = 0x2F8

    struct MemEnforcedLRUCache {
        char pad_0[0x8];
        uintptr_t Head;  // 0x8
    };  // sizeof = 0x10

    struct MeshContentProvider {
        char pad_0[0xD8];
        uintptr_t LruHolder;  // 0xD8
    };  // sizeof = 0xE0

    struct Model {
        char pad_0[0x144];
        float Scale;  // 0x144
        char pad_1[0x110];
        uintptr_t PrimaryPart;  // 0x258
    };  // sizeof = 0x260

    struct ModuleScript {
        char pad_0[0xD0];
        uintptr_t Hash;  // 0xD0
        char pad_1[0x60];
        uintptr_t Bytecode;  // 0x138
    };  // sizeof = 0x140

    struct Motor6D {
        char pad_0[0x58];
        uintptr_t C0Container;  // 0x58  DataModel>Workspace>TestPartN>SkidMotorN
        char pad_1[0x360];
        Vector3 C0;  // 0x3C0  Motor6D>C0Container
        char pad_2[0x24];
        Vector3 C1;  // 0x3F0  CFrame stride from C0
    };  // sizeof = 0x3FC

    struct MouseService {
        char pad_0[0x100];
        uintptr_t InputObject;  // 0x100
    };  // sizeof = 0x108

    struct NumberValue {
        char pad_0[0xB8];
        double Value;  // 0xB8  DataModel>Workspace>SkidValueN
    };  // sizeof = 0xC0

    struct ParticleEmitter {
        char pad_0[0x248];
        float Rate;  // 0x248  DataModel>Workspace>SkidParticlesN
        char pad_1[0x1C];
        bool Enabled;  // 0x268  DataModel>Workspace>SkidParticlesN
    };  // sizeof = 0x269

    struct Player {
        char pad_0[0xD0];
        uint64_t UserId;  // 0xD0  scanned for player_info->user_id = 3672944211
        char pad_1[0x1C0];
        uintptr_t Character;  // 0x298
        char pad_2[0x38];
        uintptr_t Team;  // 0x2D8
        char pad_3[0x7C];
        uint32_t AccountAge;  // 0x35C  scanned for player_info->account_age = 1518
        char pad_4[0x8];
        float CameraMaxZoomDistance;  // 0x368  DataModel>Players>LocalPlayer | scanned for player_info->camera_max_zoom = 128
        float CameraMinZoomDistance;  // 0x36C  DataModel>Players>LocalPlayer | scanned for player_info->camera_min_zoom = 0.5
        char pad_5[0x24];
        float HealthDisplayDistance;  // 0x394  scanned for 87.12f = 87.12
        char pad_6[0xC];
        float NameDisplayDistance;  // 0x3A4  scanned for 56.89f = 56.89
        char pad_7[0x8];
        uint32_t TeamColor;  // 0x3B0  scanned for 1004 = 1004
    };  // sizeof = 0x3B4

    struct Players {
        char pad_0[0x130];
        uintptr_t LocalPlayer;  // 0x130
    };  // sizeof = 0x138

    struct Primitive {
        char pad_0[0xC8];
        CFrame CFrame;  // 0xC8
        Vector3 AssemblyLinearVelocity;  // 0xF8
        Vector3 AssemblyAngularVelocity;  // 0x104
        char pad_1[0xA6];
        uint8_t PrimitiveFlags;  // 0x1B6
        char pad_2[0x5];
        Vector3 Size;  // 0x1BC
        char pad_3[0x48];
        uintptr_t Part;  // 0x210
        char pad_4[0x2E];
        uint16_t Material;  // 0x246
    };  // sizeof = 0x248

    struct PropertyDescriptor {
        char pad_0[0x68];
        uintptr_t TType;  // 0x68
        char pad_1[0x20];
        uintptr_t GetSetImpl;  // 0x90
    };  // sizeof = 0x98

    struct ProximityPrompt {
        char pad_0[0x120];
        float HoldDuration;  // 0x120
        uint32_t KeyboardKeyCode;  // 0x124
        float MaxActivationDistance;  // 0x128
        char pad_1[0xA];
        bool Enabled;  // 0x136
        bool RequiresLineOfSight;  // 0x137
    };  // sizeof = 0x138

    struct RenderView {
        char pad_0[0x8];
        uintptr_t DeviceD3D11;  // 0x8
        char pad_1[0x218];
        uint16_t LightingValid;  // 0x228  scanned for 257 = 257
        char pad_2[0x63];
        uint16_t SkyboxValid;  // 0x28D
    };  // sizeof = 0x28F

    struct Seat {
        char pad_0[0x210];
        uintptr_t Occupant;  // 0x210
    };  // sizeof = 0x218

    struct Sky {
        char pad_0[0x238];
        Vector3 SkyboxOrientation;  // 0x238
        float MoonAngularSize;  // 0x244  scanned for 22.56f = 22.56
        uint32_t StarCount;  // 0x248  scanned for 2346 = 2346
        float SunAngularSize;  // 0x24C  scanned for 11.98f = 11.98
    };  // sizeof = 0x250

    struct Sound {
        char pad_0[0x11C];
        float PlaybackSpeed;  // 0x11C  DataModel>Workspace>TestPartN>SkidSoundN
        float MaxDistance;  // 0x120  DataModel>Workspace>TestPartN>SkidSoundN
        float RollOffMinDistance;  // 0x124  DataModel>Workspace>TestPartN>SkidSoundN
        char pad_1[0x8];
        float Volume;  // 0x130  DataModel>Workspace>TestPartN>SkidSoundN
        char pad_2[0x9];
        bool Looped;  // 0x13D  DataModel>Workspace>TestPartN>SkidSoundN
    };  // sizeof = 0x13E

    struct SpawnLocation {
        char pad_0[0xD];
        bool Neutral;  // 0xD  DataModel>Workspace>SkidSpawn
        char pad_1[0x12];
        float Duration;  // 0x20  DataModel>Workspace>SkidSpawn
    };  // sizeof = 0x24

    struct SpecialMesh {
        char pad_0[0xB8];
        Vector3 Offset;  // 0xB8
        Vector3 Scale;  // 0xC4
    };  // sizeof = 0xD0

    struct TaskScheduler {
        char pad_0[0xB0];
        double MaxFps;  // 0xB0
        char pad_1[0x10];
        uintptr_t JobStart;  // 0xC8
        uintptr_t JobEnd;  // 0xD0
    };  // sizeof = 0xD8

    struct Team {
        char pad_0[0xB8];
        uint32_t TeamColor;  // 0xB8
    };  // sizeof = 0xBC

    struct Terrain {
        char pad_0[0x1D8];
        Color3 WaterColor;  // 0x1D8
        char pad_1[0x4];
        float GrassLength;  // 0x1E8  scanned for 0.722f = 0.722
        char pad_2[0x4];
        float WaterReflectance;  // 0x1F0  scanned for 0.935f = 0.935
        float WaterTransparency;  // 0x1F4  scanned for 0.323f = 0.323
        float WaterWaveSize;  // 0x1F8  scanned for 0.159f = 0.159
        float WaterWaveSpeed;  // 0x1FC  scanned for 10.34f = 10.34
        char pad_3[0x2B0];
        uintptr_t MaterialColors;  // 0x4B0
    };  // sizeof = 0x4B8

    struct Tool {
        char pad_0[0x488];
        CFrame Grip;  // 0x488
        bool CanBeDropped;  // 0x4B8
        bool Enabled;  // 0x4B9
        bool ManualActivationOnly;  // 0x4BA
        bool RequiresHandle;  // 0x4BB
    };  // sizeof = 0x4BC

    struct Vector3Value {
        char pad_0[0xB8];
        Vector3 Value;  // 0xB8  DataModel>Workspace>SkidValueN
    };  // sizeof = 0xC4

    struct VehicleSeat {
        char pad_0[0x208];
        uintptr_t Occupant;  // 0x208
        char pad_1[0x18];
        float MaxSpeed;  // 0x228  scanned for 456.2f = 456.2
        float SteerFloat;  // 0x22C  scanned for 0.256f = 0.256
        float ThrottleFloat;  // 0x230  scanned for 0.412f = 0.412
        float Torque;  // 0x234  scanned for 108.1f = 108.1
        float TurnSpeed;  // 0x238  scanned for 26.123f = 26.123
    };  // sizeof = 0x23C

    struct VisualEngine {
        char pad_0[0x180];
        Matrix4x4 ViewMatrix;  // 0x180
        char pad_1[0x900];
        uintptr_t FakeDataModel;  // 0xAC0
        char pad_2[0x18];
        Vector2 Dimensions;  // 0xAE0
        char pad_3[0x118];
        uintptr_t RenderView;  // 0xC00
    };  // sizeof = 0xC08

    struct Workspace {
        char pad_0[0x3F0];
        uintptr_t World;  // 0x3F0  DataModel>Workspace>World (via gravity float)
        char pad_1[0xA0];
        uintptr_t CurrentCamera;  // 0x498  DataModel>Workspace>Camera child
        char pad_2[0x528];
        float ReadOnlyGravity;  // 0x9C8  DataModel>Workspace | scanned for expected_gravity = 196.2
    };  // sizeof = 0x9CC

    struct World {
        char pad_0[0xE8];
        uint32_t dwWorldStepid;  // 0xE8  world step counter: dword, monotonically incrementing
        char pad_1[0x13C];
        float Gravity;  // 0x228  DataModel>Workspace>World
        char pad_2[0xC];
        uintptr_t AirProperties;  // 0x238
        char pad_3[0x68];
        uintptr_t Primitives;  // 0x2A8
        char pad_4[0x110];
        double dLastFrameTimeStamp;  // 0x3C0  world step timing: double, last frame timestamp
        double dLastSendTimeStamp;  // 0x3C8  world step timing: double, last send timestamp
        uint32_t dwLastNumberOfWorldStep;  // 0x3D0  world step timing: dword, step count at last send
        char pad_5[0x4];
        double dWorldStepDt;  // 0x3D8  world step timing: double, accumulated step drift (write to manipulate sim speed)
        char pad_6[0x340];
        float fWorldStepsPerSecond;  // 0x720  simulation steps-per-second scalar (write to change sim speed)
    };  // sizeof = 0x724

    struct WorldRoot {
        char pad_0[0x80];
        uint64_t RaycastBoundFn;  // 0x80
        char pad_1[0x8089E98];
        uintptr_t RaycastBoundDesc;  // 0x8089F20
    };  // sizeof = 0x8089F28

} // namespace structs
#pragma pack(pop)
