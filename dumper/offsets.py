# Dumped With: skidware-dumper 3.8 (by Ox Alpha)
# Fork of jonah/nopjo's roblox-dumper
# Dumped At: 2026-08-28 12:15:34 UTC
# Roblox Version: version-f5a60436d48947d3
# Time Taken: 204178 ms (204.178000 seconds)
# Total Offsets: 1596
# Method:
#   1. Bridge ground truth - an in-game script creates test instances with
#       known unique values and reports them as JSON via ReplicatedStorage.
#   2. Empirical scanning - instance memory is searched for those values;
#       offsets are only accepted when they verify across many instances.
#   3. RTTI / class-descriptor walks resolve services and child pointers.
#   4. String-signature + xref scans locate engine singletons.
#   5. FastFlags - heap registry discovery via name-pointer slots, with
#       statistical per-type payload layout inference.

class Offsets:
    ROBLOX_VERSION = "version-f5a60436d48947d3"

    class Accessory:
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttachmentForward = 16  # instance offset recovered by disassembling this property's GetImpl getter
        AttachmentPoint = 8  # instance offset recovered by disassembling this property's GetImpl getter
        AttachmentPos = 44  # instance offset recovered by disassembling this property's GetImpl getter
        AttachmentRight = 8  # instance offset recovered by disassembling this property's GetImpl getter
        AttachmentUp = 12  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        BackendAccoutrementState = 56  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class AirProperties:  # per-workspace wind/air physics
        AirDensity = 24  # air density for drag calculations
        GlobalWind = 60  # wind vector applied to unanchored parts

    class Animation:  # animation asset reference
        AnimationId = 192  # Animation Id

    class Animator:
        AnimTrackMetadata0 = 756  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata1 = 760  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata10 = 764  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata11 = 768  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata12 = 772  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata13 = 776  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata14 = 780  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata15 = 784  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata2 = 788  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata3 = 792  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata4 = 796  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata5 = 800  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata6 = 804  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata7 = 808  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata8 = 812  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackMetadata9 = 816  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState0 = 756  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState1 = 760  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState10 = 764  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState11 = 768  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState12 = 772  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState13 = 776  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState14 = 780  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState15 = 784  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState2 = 788  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState3 = 792  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState4 = 796  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState5 = 800  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState6 = 804  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState7 = 808  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState8 = 812  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackPlayState9 = 816  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight0 = 760  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight1 = 788  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight10 = 768  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight11 = 772  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight12 = 776  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight13 = 780  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight14 = 784  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight15 = 144  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight2 = 792  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight3 = 796  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight4 = 800  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight5 = 804  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight6 = 808  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight7 = 812  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight8 = 816  # instance offset recovered by disassembling this property's GetImpl getter
        AnimTrackWeight9 = 764  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId0 = 576  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId1 = 584  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId10 = 592  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId11 = 600  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId12 = 608  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId13 = 616  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId14 = 624  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId15 = 632  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId2 = 640  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId3 = 648  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId4 = 656  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId5 = 664  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId6 = 672  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId7 = 680  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId8 = 688  # instance offset recovered by disassembling this property's GetImpl getter
        AnimationId9 = 696  # instance offset recovered by disassembling this property's GetImpl getter
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        EvaluationThrottled = 820  # instance offset recovered by disassembling this property's GetImpl getter
        FacsReplicationData = 184  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PreferLodEnabled = 996  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        RootMotion = 928  # instance offset recovered by disassembling this property's GetImpl getter
        RootMotionWeight = 928  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class AntiCheat:  # Hyperion integrity machinery. Static RVAs from static analysis of this build - not empirically scanned.
        relControlFlowGuardMap = 21346888  # Control Flow Guard Map
        relFpControlFlowCheck = 12922880  # Fp Control Flow Check

    class Atmosphere:
        Color = 184  # Color
        Decay = 196  # Decay
        Density = 208  # Density
        Glare = 212  # Glare
        Haze = 216  # Haze
        Offset = 220  # Offset

    class Attachment:  # attach point on a part
        Position = 196  # attachment offset from its parent part center

    class AudioListener:
        AcousticSimulationEnabled = 60  # instance offset recovered by disassembling this property's GetImpl getter
        AngleAttenuation = 64  # instance offset recovered by disassembling this property's GetImpl getter
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        AudioInteractionGroup = 64  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DiffractionEnabled = 48  # instance offset recovered by disassembling this property's GetImpl getter
        DistanceAttenuation = 64  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        OcclusionEnabled = 60  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PositionInstance = 16  # instance offset recovered by disassembling this property's GetImpl getter
        PositionType = 56  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        ReverbEnabled = 60  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SimulationFidelity = 64  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class BasePart:  # part instance (aliases into Primitive)
        AngularVelocity = 652  # convenience alias: Primitive->AssemblyAngularVelocity
        CastShadow = 309  # Cast Shadow
        Color3 = 424  # Color3
        Locked = 310  # Locked
        Massless = 311  # Massless
        Primitive = 392  # pointer from BasePart to its physics Primitive
        PrimitiveFlags = 830  # Primitive Flags
        Reflectance = 268  # Reflectance
        Shape = 441  # Shape
        Transparency = 304  # Transparency
        Velocity = 640  # convenience alias: Primitive->AssemblyLinearVelocity

    class BloomEffect:
        Intensity = 184  # Intensity
        Size = 188  # Size
        Threshold = 192  # Threshold

    class BodyColors:
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        HeadColor = 36  # instance offset recovered by disassembling this property's GetImpl getter
        HeadColor3 = 36  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        LeftArmColor = 36  # instance offset recovered by disassembling this property's GetImpl getter
        LeftArmColor3 = 36  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RightArmColor = 84  # instance offset recovered by disassembling this property's GetImpl getter
        RightArmColor3 = 84  # instance offset recovered by disassembling this property's GetImpl getter
        RightLegColor = 84  # instance offset recovered by disassembling this property's GetImpl getter
        RightLegColor3 = 84  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class BoolValue:  # bool container
        Value = 184  # the bool payload

    class ByteCode:
        Pointer = 16  # Pointer
        Size = 40  # Size

    class CFrameValue:  # cframe container
        Value = 220  # cframe translation payload

    class CachedItem:
        FileMeshData = 40  # File Mesh Data

    class Camera:  # view camera
        CFrame = 216  # camera position + rotation
        CameraSubject = 200  # instance the camera follows
        FieldOfView = 320  # field of view in degrees (stored as radians here)
        Position = 252  # camera world position
        Rotation = 216  # Rotation
        ViewportInt16 = 652  # Viewport Int16
        ViewportSize = 716  # viewport size in pixels

    class CharacterMesh:
        BaseTextureId = 200  # Base Texture Id
        BodyPart = 328  # Body Part
        MeshId = 248  # Mesh Id
        OverlayTextureId = 296  # Overlay Texture Id

    class ClassDescriptor:
        ClassName = 8  # class name string (e.g. "Part")
        Creator = 560  # Creator
        EventDescriptors = 136  # Event Descriptors
        FunctionDescriptors = 208  # Function Descriptors
        PropertyDescriptors = 64  # Property Descriptors

    class ClickDetector:  # click interaction
        MaxActivationDistance = 232  # max click range in studs

    class Creator:
        MapEnd = 137626584  # Map End
        MapStart = 137626576  # Map Start

    class DataModel:  # root game object (place/session info)
        CreatorId = 384  # user/group ID of the game creator
        DataModelType = 2392  # Data Model Type
        GameId = 392  # ID of the universe (game) this place belongs to
        GameLoaded = 1488  # non-zero once the place finished loading
        HackFlagNodeValue = 16  # Hack Flag Node Value
        HackFlagSetList = 2096  # Hack Flag Set List
        HackFlagSetMutex = 2088  # Hack Flag Set Mutex
        JobId = 280  # server session ID (unique per server join)
        PlaceId = 400  # ID of the current place
        Workspace = 344  # pointer to the Workspace service

    class Decal:  # texture on a face
        Transparency = 604  # 0 = opaque, 1 = invisible

    class Descriptor:
        Name = 8  # Name

    class EngineDetections:  # Hyperion detection flag DWORDs reported through the RBX::PingItem telemetry serializer. Nonzero/non-initial value = that detection fired. Static RVAs from static analysis of this build - not empirically scanned.
        dwDetectionFlag_0 = 132829640  # Detection Flag 0
        dwDetectionFlag_1 = 132829644  # Detection Flag 1
        dwDetectionFlag_10 = 133031228  # Detection Flag 10
        dwDetectionFlag_11 = 133032856  # Detection Flag 11
        dwDetectionFlag_12 = 133032860  # Detection Flag 12
        dwDetectionFlag_13 = 133065504  # Detection Flag 13
        dwDetectionFlag_14 = 133065508  # Detection Flag 14
        dwDetectionFlag_15 = 133065512  # Detection Flag 15
        dwDetectionFlag_16 = 133065516  # Detection Flag 16
        dwDetectionFlag_17 = 133065520  # Detection Flag 17
        dwDetectionFlag_2 = 132980284  # Detection Flag 2
        dwDetectionFlag_3 = 132981116  # Detection Flag 3
        dwDetectionFlag_4 = 132988456  # Detection Flag 4
        dwDetectionFlag_5 = 132988460  # Detection Flag 5
        dwDetectionFlag_6 = 133028508  # Detection Flag 6
        dwDetectionFlag_7 = 133030572  # Detection Flag 7
        dwDetectionFlag_8 = 133030716  # Detection Flag 8
        dwDetectionFlag_9 = 133031224  # Detection Flag 9

    class FaceControls:
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        ChinRaiser = 224  # instance offset recovered by disassembling this property's GetImpl getter
        ChinRaiserUpperLip = 228  # instance offset recovered by disassembling this property's GetImpl getter
        Corrugator = 232  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        EyesLookDown = 236  # instance offset recovered by disassembling this property's GetImpl getter
        EyesLookLeft = 240  # instance offset recovered by disassembling this property's GetImpl getter
        EyesLookRight = 244  # instance offset recovered by disassembling this property's GetImpl getter
        EyesLookUp = 248  # instance offset recovered by disassembling this property's GetImpl getter
        FlatPucker = 252  # instance offset recovered by disassembling this property's GetImpl getter
        Funneler = 256  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        InternalOverrideFACSData = 184  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        JawDrop = 260  # instance offset recovered by disassembling this property's GetImpl getter
        JawLeft = 264  # instance offset recovered by disassembling this property's GetImpl getter
        JawRight = 268  # instance offset recovered by disassembling this property's GetImpl getter
        LeftBrowLowerer = 272  # instance offset recovered by disassembling this property's GetImpl getter
        LeftCheekPuff = 276  # instance offset recovered by disassembling this property's GetImpl getter
        LeftCheekRaiser = 280  # instance offset recovered by disassembling this property's GetImpl getter
        LeftDimpler = 284  # instance offset recovered by disassembling this property's GetImpl getter
        LeftEyeClosed = 288  # instance offset recovered by disassembling this property's GetImpl getter
        LeftEyeUpperLidRaiser = 292  # instance offset recovered by disassembling this property's GetImpl getter
        LeftInnerBrowRaiser = 1328  # instance offset recovered by disassembling this property's GetImpl getter
        LeftLipCornerDown = 300  # instance offset recovered by disassembling this property's GetImpl getter
        LeftLipCornerPuller = 304  # instance offset recovered by disassembling this property's GetImpl getter
        LeftLipStretcher = 308  # instance offset recovered by disassembling this property's GetImpl getter
        LeftLowerLipDepressor = 312  # instance offset recovered by disassembling this property's GetImpl getter
        LeftNoseWrinkler = 1348  # instance offset recovered by disassembling this property's GetImpl getter
        LeftOuterBrowRaiser = 320  # instance offset recovered by disassembling this property's GetImpl getter
        LeftUpperLipRaiser = 324  # instance offset recovered by disassembling this property's GetImpl getter
        LipPresser = 328  # instance offset recovered by disassembling this property's GetImpl getter
        LipsTogether = 332  # instance offset recovered by disassembling this property's GetImpl getter
        LowerLipSuck = 336  # instance offset recovered by disassembling this property's GetImpl getter
        MouthLeft = 340  # instance offset recovered by disassembling this property's GetImpl getter
        MouthRight = 344  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Pucker = 348  # instance offset recovered by disassembling this property's GetImpl getter
        RightBrowLowerer = 1384  # instance offset recovered by disassembling this property's GetImpl getter
        RightCheekPuff = 356  # instance offset recovered by disassembling this property's GetImpl getter
        RightCheekRaiser = 360  # instance offset recovered by disassembling this property's GetImpl getter
        RightDimpler = 364  # instance offset recovered by disassembling this property's GetImpl getter
        RightEyeClosed = 368  # instance offset recovered by disassembling this property's GetImpl getter
        RightEyeUpperLidRaiser = 372  # instance offset recovered by disassembling this property's GetImpl getter
        RightInnerBrowRaiser = 376  # instance offset recovered by disassembling this property's GetImpl getter
        RightLipCornerDown = 380  # instance offset recovered by disassembling this property's GetImpl getter
        RightLipCornerPuller = 384  # instance offset recovered by disassembling this property's GetImpl getter
        RightLipStretcher = 388  # instance offset recovered by disassembling this property's GetImpl getter
        RightLowerLipDepressor = 392  # instance offset recovered by disassembling this property's GetImpl getter
        RightNoseWrinkler = 396  # instance offset recovered by disassembling this property's GetImpl getter
        RightOuterBrowRaiser = 1432  # instance offset recovered by disassembling this property's GetImpl getter
        RightUpperLipRaiser = 404  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        TongueDown = 408  # instance offset recovered by disassembling this property's GetImpl getter
        TongueOut = 412  # instance offset recovered by disassembling this property's GetImpl getter
        TongueUp = 416  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UpperLipSuck = 420  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class FakeDataModel:  # global entry: *(module + Pointer) = FakeDataModel
        Pointer = 147496136  # Pointer
        Pointer = 147496136  # Pointer
        RealDataModel = 504  # offset of the real DataModel pointer inside FakeDataModel

    class FileMeshData:
        AabbMax = 700  # Aabb Max
        AabbMin = 688  # Aabb Min
        Faces = 48  # Faces
        FacesEnd = 56  # Faces End
        Vertices = 0  # Vertices
        VerticesEnd = 8  # Vertices End

    class Fire:  # fire particle effect
        FireProximityPrompt = 50969856  # Fire Proximity Prompt
        Heat = 216  # fire heat intensity
        Size = 220  # fire effect size

    class Folder:
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        ReplicatedGuiInsertionOrder = 8  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class Frame:
        AbsoluteSize = 309  # instance offset recovered by disassembling this property's GetImpl getter
        Active = 1404  # instance offset recovered by disassembling this property's GetImpl getter
        ActiveQueryNames = 992  # instance offset recovered by disassembling this property's GetImpl getter
        AnchorPoint = 1280  # instance offset recovered by disassembling this property's GetImpl getter
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        AutoLocalize = 101  # instance offset recovered by disassembling this property's GetImpl getter
        AutomaticSize = 184  # instance offset recovered by disassembling this property's GetImpl getter
        BorderMode = 184  # instance offset recovered by disassembling this property's GetImpl getter
        BorderSizePixel = 16  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        ClippedRect = 101  # instance offset recovered by disassembling this property's GetImpl getter
        ClipsDescendants = 16  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DragBeginConnectionCount = 184  # instance offset recovered by disassembling this property's GetImpl getter
        DragStoppedConnectionCount = 188  # instance offset recovered by disassembling this property's GetImpl getter
        Draggable = 242  # instance offset recovered by disassembling this property's GetImpl getter
        GuiState = 1400  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        InputSink = 1404  # instance offset recovered by disassembling this property's GetImpl getter
        Interactable = 1451  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        IsNotOccluded = 101  # instance offset recovered by disassembling this property's GetImpl getter
        LayoutOrder = 16  # instance offset recovered by disassembling this property's GetImpl getter
        MouseEnterConnectionCount = 204  # instance offset recovered by disassembling this property's GetImpl getter
        MouseLeaveConnectionCount = 208  # instance offset recovered by disassembling this property's GetImpl getter
        MouseMovedConnectionCount = 212  # instance offset recovered by disassembling this property's GetImpl getter
        MouseWheelBackwardConnectionCount = 216  # instance offset recovered by disassembling this property's GetImpl getter
        MouseWheelForwardConnectionCount = 1428  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        NextSelectionDown = 16  # instance offset recovered by disassembling this property's GetImpl getter
        NextSelectionLeft = 1240  # instance offset recovered by disassembling this property's GetImpl getter
        NextSelectionRight = 1256  # instance offset recovered by disassembling this property's GetImpl getter
        NextSelectionUp = 1272  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Position = 1432  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RawRect2D = 16  # instance offset recovered by disassembling this property's GetImpl getter
        ReplicatedInsertionOrder = 16  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        RootLocalizationTable = 16  # instance offset recovered by disassembling this property's GetImpl getter
        Rotation = 1432  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        Selectable = 1312  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorDown = 80  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorLeft = 84  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorRight = 88  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorUp = 92  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionGroup = 96  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionImageObject = 1280  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionOrder = 1340  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionRect2D = 104  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Size = 1312  # instance offset recovered by disassembling this property's GetImpl getter
        SizeConstraint = 1400  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        TotalGroupScale = 96  # instance offset recovered by disassembling this property's GetImpl getter
        Transparency = 184  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        Visible = 1404  # instance offset recovered by disassembling this property's GetImpl getter
        ZIndex = 1404  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class FunctionDescriptor:
        Function = 128  # Function

    class Functions:
        Clone = 23171440  # Clone
        Destroy = 23171472  # Destroy
        FindPartOnRay = 15414368  # Find Part On Ray
        FindPartOnRayWithIgnoreList = 15414496  # Find Part On Ray With Ignore List
        FindPartOnRayWithWhitelist = 15414640  # Find Part On Ray With Whitelist
        FireServer = 13209616  # Fire Server
        Print = 29790176  # Print
        RaisePropertyChanged = 16119120  # Raise Property Changed
        Raycast = 15378960  # Raycast
        SetParent = 11568360  # Set Parent
        SetParentInternal = 30087888  # Set Parent Internal
        Shapecast = 15385552  # Shapecast

    class GuiBase2D:
        AbsolutePosition = 264  # Absolute Position
        AbsoluteRotation = 232  # Absolute Rotation
        AbsoluteSize = 276  # Absolute Size

    class GuiObject:
        Active = 1448  # Active
        AnchorPoint = 1368  # Anchor Point
        AutomaticSize = 1376  # Automatic Size
        BackgroundColor3 = 1344  # Background Color3
        BackgroundTransparency = 1380  # Background Transparency
        BorderColor3 = 1356  # Border Color3
        BorderMode = 1384  # Border Mode
        BorderSizePixel = 1388  # Border Size Pixel
        ClipsDescendants = 1449  # Clips Descendants
        GuiState = 1400  # Gui State
        Interactable = 1451  # Interactable
        LayoutOrder = 1408  # Layout Order
        Position = 1296  # Position
        Rotation = 232  # Rotation
        Selectable = 1452  # Selectable
        SelectionOrder = 1436  # Selection Order
        Size = 1328  # Size
        SizeConstraint = 1440  # Size Constraint
        Visible = 1453  # Visible
        ZIndex = 1444  # Z Index

    class Highlight:  # selection highlight effect
        Adornee = 184  # instance being highlighted
        DepthMode = 224  # Depth Mode
        Enabled = 244  # Enabled
        FillColor = 200  # highlight fill color
        FillTransparency = 228  # Fill Transparency
        OutlineColor = 212  # highlight outline color
        OutlineTransparency = 236  # Outline Transparency

    class HopperBin:
        BinType = 1128  # Bin Type

    class Humanoid:  # character controller (walk speed, jump, state)
        AutoJumpEnabled = 468  # auto-jump on obstacles (mobile style)
        AutoRotate = 469  # whether the humanoid turns to face movement direction
        AutomaticScalingEnabled = 470  # auto-scale animations to body proportions
        BreakJointsOnDeath = 471  # joints break on death when true
        CameraOffset = 296  # camera offset relative to the humanoid head
        DisplayDistanceType = 384  # Display Distance Type
        DisplayName = 184  # name shown above the character
        EvaluateStateMachine = 472  # engine state machine enabled
        Health = 400  # current health
        HealthDisplayDistance = 392  # max distance at which health bar shows
        HealthDisplayType = 396  # when the health bar is displayed
        HipHeight = 404  # distance of torso above the ground
        JumpHeight = 416  # jump height in studs (modern mode)
        JumpPower = 420  # jump impulse strength (legacy mode)
        MaxHealth = 424  # maximum health
        MaxSlopeAngle = 428  # steepest walkable slope in degrees
        NameDisplayDistance = 432  # max distance at which name shows
        NameOcclusion = 436  # name occlusion behaviour behind walls
        PlatformStand = 476  # when true the humanoid ignores input (ragdoll-ish)
        RequiresNeck = 477  # humanoid dies without a Neck joint when true
        RigType = 448  # R6 or R15 skeleton
        SeatPart = 264  # pointer to the seat being sat on (null if standing)
        Sit = 478  # whether the humanoid is seated
        TargetPoint = 332  # current MoveTo target point
        UseJumpPower = 480  # true = use JumpPower, false = use JumpHeight
        WalkSpeed = 464  # movement speed in studs/s (write to change speed)
        WalkSpeedCheck = 956  # duplicate WalkSpeed cache used by engine checks
        WalkToPoint = 356  # walk target point (same as TargetPoint usually)

    class ICreator:
        Create = 0  # Create

    class ImageLabel:  # GUI image element
        ImageTransparency = 2724  # 0 = opaque image

    class InputObject:
        MousePosition = 212  # Mouse Position

    class Instance:  # base of every Roblox object
        ChildrenEnd = 8  # one-past-end marker inside the children array
        ChildrenStart = 120  # children vector: array-of-slots pointer
        ClassDescriptor = 24  # pointer to RTTI class descriptor (per-class static)
        Name = 8  # offset of the name chars inside the name container
        NameContainer = 112  # pointer to this instance's name string object
        Parent = 104  # pointer to the parent instance

    class IntValue:  # int container
        Value = 184  # the int payload

    class Light:  # point/surface light source
        Brightness = 204  # Brightness
        Range = 216  # Range

    class Lighting:  # lighting/atmosphere settings
        Ambient = 208  # Ambient
        Atmosphere = 472  # Atmosphere
        Brightness = 280  # light brightness multiplier
        ClockTime = 200  # time of day in seconds since midnight * 1000000
        ColorShift_Bottom = 220  # Color Shift Bottom
        ColorShift_Top = 232  # Color Shift Top
        EnvironmentDiffuseScale = 284  # Environment Diffuse Scale
        EnvironmentSpecularScale = 288  # Environment Specular Scale
        ExposureCompensation = 292  # Exposure Compensation
        FogColor = 244  # fog color
        FogEnd = 300  # distance where fog is fully opaque
        FogStart = 304  # distance where fog starts
        OutdoorAmbient = 256  # Outdoor Ambient
        ShadowSoftness = 316  # Shadow Softness
        Sky = 456  # Sky

    class LightingParameters:  # these are in the lighting service
        GeographicLatitude = 308  # Geographic Latitude
        LightColor = 348  # Light Color
        LightDirection = 360  # Light Direction
        SkyAmbient = 336  # Sky Ambient
        SkyAmbient2 = 312  # Sky Ambient2
        Source = 372  # Source
        TrueMoonPosition = 388  # True Moon Position
        TrueSunPosition = 376  # True Sun Position

    class LinearVelocity:  # physics velocity constraint
        MaxForce = 400  # force cap of the constraint
        VectorVelocity = 580  # target velocity vector

    class LocalScript:
        Bytecode = 400  # Bytecode
        Hash = 416  # Hash

    class LruHolder:
        MemEnforcedLRUCache = 32  # Mem Enforced LRU Cache

    class LruNode:
        CachedItem = 56  # Cached Item
        MeshId = 16  # Mesh Id
        Next = 0  # Next

    class LuaPage:
        dwBlocksize = 36  # Blocksize
        dwFreenext = 48  # Freenext
        dwPagesize = 32  # Pagesize
        lpData = 64  # Data
        lpListnext = 8  # Listnext

    class LuaState:
        lpGlobalState = 32  # Global State

    class LuaTable:
        dwArraysize = 8  # Arraysize
        dwLsizenode = 5  # Lsizenode
        lpArray = 40  # Array
        lpNode = 24  # Node

    class LuauBase:  # 'base' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        fpAssert = 40811328  # Assert
        fpError = 40790032  # Error
        fpGcinfo = 40805488  # Gcinfo
        fpGetfenv = 40795760  # Getfenv
        fpGetmetatable = 40792656  # Getmetatable
        fpNewproxy = 40815200  # Newproxy
        fpNext = 40808592  # Next
        fpPrint = 40788928  # Print
        fpRawequal = 40796512  # Rawequal
        fpRawget = 40796784  # Rawget
        fpRawlen = 40805328  # Rawlen
        fpRawset = 40798144  # Rawset
        fpSelect = 40811504  # Select
        fpSetfenv = 40795952  # Setfenv
        fpSetmetatable = 40793040  # Setmetatable
        fpTonumber = 40789136  # Tonumber
        fpTostring = 40815104  # Tostring
        fpType = 40805520  # Type
        fpTypeof = 40807056  # Typeof
        relRegistryTable = 103890144  # Registry Table

    class LuauBit32:  # 'bit32' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        fpAdd = 89021792  # Add
        fpArshift = 89027312  # Arshift
        fpBand = 89024000  # Band
        fpBnot = 89024496  # Bnot
        fpBor = 89024256  # Bor
        fpBswap = 89029360  # Bswap
        fpBtest = 89028896  # Btest
        fpBxor = 89024576  # Bxor
        fpClamp = 89028672  # Clamp
        fpCountlz = 89029248  # Countlz
        fpCountrz = 89029152  # Countrz
        fpCreate = 89020608  # Create
        fpDiv = 89022176  # Div
        fpExtract = 89027824  # Extract
        fpFromstring = 89020880  # Fromstring
        fpGe = 89026176  # Ge
        fpGt = 89025904  # Gt
        fpIdiv = 89022400  # Idiv
        fpLe = 89025088  # Le
        fpLrotate = 89027536  # Lrotate
        fpLshift = 89026992  # Lshift
        fpLt = 89024816  # Lt
        fpMax = 89023696  # Max
        fpMin = 89023392  # Min
        fpMod = 89022832  # Mod
        fpMul = 89022048  # Mul
        fpNeg = 89021712  # Neg
        fpRem = 89022640  # Rem
        fpReplace = 89028208  # Replace
        fpRrotate = 89027680  # Rrotate
        fpRshift = 89027152  # Rshift
        fpSub = 89021920  # Sub
        fpTonumber = 89021536  # Tonumber
        fpUdiv = 89023072  # Udiv
        fpUge = 89026720  # Uge
        fpUgt = 89026448  # Ugt
        fpUle = 89025632  # Ule
        fpUlt = 89025360  # Ult
        fpUrem = 89023232  # Urem
        relRegistryTable = 106086656  # Registry Table

    class LuauBuffer:  # 'buffer' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        fpCopy = 89123840  # Copy
        fpCreate = 89118848  # Create
        fpFill = 89124592  # Fill
        fpFromstring = 89119024  # Fromstring
        fpLen = 89123664  # Len
        fpReadbits = 89125184  # Readbits
        fpReadf32 = 89128704  # Readf32
        fpReadf64 = 89129056  # Readf64
        fpReadi16 = 89127296  # Readi16
        fpReadi32 = 89128000  # Readi32
        fpReadi8 = 89126592  # Readi8
        fpReadinteger = 89120640  # Readinteger
        fpReadstring = 89121232  # Readstring
        fpReadu16 = 89127648  # Readu16
        fpReadu32 = 89128352  # Readu32
        fpReadu8 = 89126944  # Readu8
        fpTostring = 89119232  # Tostring
        fpWritebits = 89125760  # Writebits
        fpWritef32 = 89130560  # Writef32
        fpWritef64 = 89130960  # Writef64
        fpWritei16 = 89129792  # Writei16
        fpWritei32 = 89130176  # Writei32
        fpWritei8 = 89129408  # Writei8
        fpWriteinteger = 89120912  # Writeinteger
        fpWritestring = 89122992  # Writestring
        fpWriteu16 = 89129792  # Writeu16
        fpWriteu32 = 89130176  # Writeu32
        fpWriteu8 = 89129408  # Writeu8
        relRegistryTable = 106089168  # Registry Table

    class LuauCoroutine:  # 'coroutine' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        fpClose = 89146160  # Close
        fpCreate = 89143728  # Create
        fpIsyieldable = 89146032  # Isyieldable
        fpRunning = 89145920  # Running
        fpStatus = 89137984  # Status
        fpWrap = 89145184  # Wrap
        fpYield = 89145824  # Yield
        relRegistryTable = 106090064  # Registry Table

    class LuauDebug:  # 'debug' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        fpDumpcodesize = 68683312  # Dumpcodesize
        fpDumpheap = 68683264  # Dumpheap
        fpDumprefs = 68683280  # Dumprefs
        fpGetmemorycategory = 68682944  # Getmemorycategory
        fpLoadmodule = 68682928  # Loadmodule
        fpProfilebegin = 68682288  # Profilebegin
        fpProfileend = 68682576  # Profileend
        fpResetmemorycategory = 68683008  # Resetmemorycategory
        fpSetmemorycategory = 68682992  # Setmemorycategory
        fpTracerefs = 68683296  # Tracerefs
        relRegistryTable = 105850208  # Registry Table

    class LuauGlobalState:
        bCurrentwhite = 88  # Currentwhite
        lpAllgcopages = 752  # Allgcopages

    class LuauMath:  # 'math' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        fpAbs = 89098688  # Abs
        fpAcos = 89100480  # Acos
        fpAsin = 89100256  # Asin
        fpAtan = 89100704  # Atan
        fpAtan2 = 89100928  # Atan2
        fpCeil = 89101280  # Ceil
        fpClamp = 89108544  # Clamp
        fpCos = 89099360  # Cos
        fpCosh = 89099584  # Cosh
        fpDeg = 89103888  # Deg
        fpExp = 89103664  # Exp
        fpFloor = 89101504  # Floor
        fpFmod = 89101728  # Fmod
        fpFrexp = 89104336  # Frexp
        fpIsfinite = 89111264  # Isfinite
        fpIsinf = 89111024  # Isinf
        fpIsnan = 89110800  # Isnan
        fpLdexp = 89104592  # Ldexp
        fpLerp = 89110320  # Lerp
        fpLog = 89102992  # Log
        fpLog10 = 89103440  # Log10
        fpMap = 89109584  # Map
        fpMax = 89105312  # Max
        fpMin = 89104960  # Min
        fpModf = 89102080  # Modf
        fpNoise = 89107712  # Noise
        fpPow = 89102640  # Pow
        fpRad = 89104112  # Rad
        fpRandom = 89105664  # Random
        fpRandomseed = 89106464  # Randomseed
        fpRound = 89109360  # Round
        fpSign = 89109104  # Sign
        fpSin = 89098912  # Sin
        fpSinh = 89099136  # Sinh
        fpSqrt = 89102384  # Sqrt
        fpTan = 89099808  # Tan
        fpTanh = 89100032  # Tanh
        relRegistryTable = 106088560  # Registry Table

    class LuauOs:  # 'os' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        fpClock = 89040672  # Clock
        fpDate = 89046224  # Date
        fpDifftime = 89048800  # Difftime
        fpTime = 89048016  # Time
        relRegistryTable = 106087440  # Registry Table

    class LuauRoblox:  # 'roblox' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        fpCollectgarbage = 67964128  # Collectgarbage
        fpDelay = 67966224  # Delay
        fpDelay = 67966224  # Delay
        fpElapsedTime = 67968288  # Elapsed Time
        fpElapsedTime = 67968288  # Elapsed Time
        fpGetfenv = 67982480  # Getfenv
        fpLoadstring = 67968416  # Loadstring
        fpPluginManager = 67970320  # Plugin Manager
        fpPrint = 67971616  # Print
        fpPrintidentity = 67971648  # Printidentity
        fpRequire = 67971888  # Require
        fpSetfenv = 67982784  # Setfenv
        fpSettings = 67973152  # Settings
        fpSpawn = 67974432  # Spawn
        fpSpawn = 67974432  # Spawn
        fpStats = 67976496  # Stats
        fpStats = 67976496  # Stats
        fpTick = 67977808  # Tick
        fpTime = 67977936  # Time
        fpUserSettings = 67978448  # User Settings
        fpVersion = 67979632  # Version
        fpVersion = 67979632  # Version
        fpWait = 67979840  # Wait
        fpWait = 67979840  # Wait
        fpWarn = 67980272  # Warn
        relRegistryTable = 112893696  # Registry Table

    class LuauString:  # 'string' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        fpByte = 89054608  # Byte
        fpChar = 89055264  # Char
        fpFind = 89062496  # Find
        fpFormat = 89070656  # Format
        fpGmatch = 89063488  # Gmatch
        fpGsub = 89069104  # Gsub
        fpLen = 89049232  # Len
        fpLower = 89052416  # Lower
        fpMatch = 89062512  # Match
        fpPack = 89077808  # Pack
        fpPacksize = 89080208  # Packsize
        fpRep = 89053088  # Rep
        fpReverse = 89052080  # Reverse
        fpSplit = 89072240  # Split
        fpSub = 89049408  # Sub
        fpUnpack = 89081088  # Unpack
        fpUpper = 89052752  # Upper
        relRegistryTable = 106087520  # Registry Table

    class LuauTable:  # 'table' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        fpClear = 89017152  # Clear
        fpClone = 89017744  # Clone
        fpConcat = 89004944  # Concat
        fpCreate = 89013936  # Create
        fpFind = 89015968  # Find
        fpForeach = 88989216  # Foreach
        fpForeachi = 88985792  # Foreachi
        fpFreeze = 89017232  # Freeze
        fpGetn = 88994368  # Getn
        fpInsert = 88998672  # Insert
        fpIsfrozen = 89017568  # Isfrozen
        fpMaxn = 88993664  # Maxn
        fpMove = 89000064  # Move
        fpPack = 89005744  # Pack
        fpRemove = 88999184  # Remove
        fpSort = 89013552  # Sort
        fpUnpack = 89007856  # Unpack
        relRegistryTable = 106086368  # Registry Table

    class LuauUtf8:  # 'utf8' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        fpChar = 89033520  # Char
        fpCodepoint = 89032592  # Codepoint
        fpCodes = 89036816  # Codes
        fpLen = 89031856  # Len
        fpOffset = 89035456  # Offset
        relRegistryTable = 106087296  # Registry Table

    class LuauVector:  # 'vector' Luau stdlib - resolved by scanning .rdata for the luaL_Reg registration array and matching member names
        fpAbs = 89092112  # Abs
        fpAngle = 89091136  # Angle
        fpCeil = 89091952  # Ceil
        fpClamp = 89092416  # Clamp
        fpCreate = 89089776  # Create
        fpCross = 89090672  # Cross
        fpDot = 89090880  # Dot
        fpFloor = 89091792  # Floor
        fpLerp = 89093760  # Lerp
        fpMagnitude = 89090208  # Magnitude
        fpMax = 89093072  # Max
        fpMin = 89092784  # Min
        fpNormalize = 89090448  # Normalize
        fpSign = 89092224  # Sign
        relRegistryTable = 106087808  # Registry Table

    class MaterialColors:
        Asphalt = 48  # Asphalt
        Basalt = 39  # Basalt
        Brick = 15  # Brick
        Cobblestone = 51  # Cobblestone
        Concrete = 12  # Concrete
        CrackedLava = 45  # Cracked Lava
        Glacier = 27  # Glacier
        Grass = 6  # Grass
        Ground = 42  # Ground
        Ice = 54  # Ice
        LeafyGrass = 57  # Leafy Grass
        Limestone = 63  # Limestone
        Mud = 36  # Mud
        Pavement = 66  # Pavement
        Rock = 24  # Rock
        Salt = 60  # Salt
        Sand = 18  # Sand
        Sandstone = 33  # Sandstone
        Slate = 9  # Slate
        Snow = 30  # Snow
        WoodPlanks = 21  # Wood Planks

    class MemEnforcedLRUCache:
        Head = 8  # Head

    class MeshContentProvider:
        LruHolder = 216  # Lru Holder

    class MeshPart:
        MeshId = 784  # Mesh Id
        TextureId = 832  # Texture Id

    class Model:
        PrimaryPart = 600  # Primary Part
        Scale = 324  # Scale

    class ModuleScript:
        Bytecode = 312  # Bytecode
        Hash = 208  # Hash
        IsRobloxScript = 360  # Is Roblox Script

    class Motor6D:  # joint between two parts (animation bones)
        C0 = 960  # joint offset on Part0 (translation)
        C0Container = 88  # pointer to joint coordinate sub-structure
        C1 = 1008  # joint offset on Part1 (translation)

    class MouseService:
        InputObject = 256  # Input Object

    class NumberValue:  # double container
        Value = 184  # the double payload

    class Pants:  # pants template content
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Color3 = 8  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Outfit1 = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Outfit1Content = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Outfit2 = 56  # instance offset recovered by disassembling this property's GetImpl getter
        Outfit2Content = 56  # instance offset recovered by disassembling this property's GetImpl getter
        PantsTemplate = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PantsTemplateContent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class Part:
        Anchored = 200  # instance offset recovered by disassembling this property's GetImpl getter
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AssemblyAngularVelocity = 200  # instance offset recovered by disassembling this property's GetImpl getter
        AssemblyCenterOfMass = 200  # instance offset recovered by disassembling this property's GetImpl getter
        AssemblyLinearVelocity = 200  # instance offset recovered by disassembling this property's GetImpl getter
        AssemblyMass = 392  # instance offset recovered by disassembling this property's GetImpl getter
        AssemblyRootPart = 392  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        AudioCanCollide = 116  # instance offset recovered by disassembling this property's GetImpl getter
        BackParamA = 200  # instance offset recovered by disassembling this property's GetImpl getter
        BackParamB = 204  # instance offset recovered by disassembling this property's GetImpl getter
        BackSurface = 208  # instance offset recovered by disassembling this property's GetImpl getter
        BackSurfaceInput = 212  # instance offset recovered by disassembling this property's GetImpl getter
        BottomParamA = 216  # instance offset recovered by disassembling this property's GetImpl getter
        BottomParamB = 220  # instance offset recovered by disassembling this property's GetImpl getter
        BrickColor = 424  # instance offset recovered by disassembling this property's GetImpl getter
        CFrame = 392  # instance offset recovered by disassembling this property's GetImpl getter
        CanCollide = 200  # instance offset recovered by disassembling this property's GetImpl getter
        CanQuery = 200  # instance offset recovered by disassembling this property's GetImpl getter
        CanTouch = 200  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        CastShadow = 117  # instance offset recovered by disassembling this property's GetImpl getter
        CenterOfMass = 200  # instance offset recovered by disassembling this property's GetImpl getter
        CollisionGroup = 200  # instance offset recovered by disassembling this property's GetImpl getter
        CollisionGroupId = 200  # instance offset recovered by disassembling this property's GetImpl getter
        CollisionGroupReplicate = 200  # instance offset recovered by disassembling this property's GetImpl getter
        Color = 232  # instance offset recovered by disassembling this property's GetImpl getter
        Color3uint8 = 232  # instance offset recovered by disassembling this property's GetImpl getter
        CurrentPhysicalProperties = 200  # instance offset recovered by disassembling this property's GetImpl getter
        CustomPhysicalProperties = 200  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DraggingV1 = 200  # instance offset recovered by disassembling this property's GetImpl getter
        Elasticity = 200  # instance offset recovered by disassembling this property's GetImpl getter
        ExtentsCFrame = 200  # instance offset recovered by disassembling this property's GetImpl getter
        ExtentsSize = 200  # instance offset recovered by disassembling this property's GetImpl getter
        Friction = 200  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        LocalTransparencyModifier = 72  # instance offset recovered by disassembling this property's GetImpl getter
        Locked = 392  # instance offset recovered by disassembling this property's GetImpl getter
        Mass = 392  # instance offset recovered by disassembling this property's GetImpl getter
        Massless = 311  # instance offset recovered by disassembling this property's GetImpl getter
        Material = 200  # instance offset recovered by disassembling this property's GetImpl getter
        MaterialVariant = 392  # instance offset recovered by disassembling this property's GetImpl getter
        MaterialVariantSerialized = 208  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        NetworkIsSleeping = 392  # instance offset recovered by disassembling this property's GetImpl getter
        NetworkOwnerV3 = 392  # instance offset recovered by disassembling this property's GetImpl getter
        NetworkOwnershipRule = 200  # instance offset recovered by disassembling this property's GetImpl getter
        Orientation = 392  # instance offset recovered by disassembling this property's GetImpl getter
        Origin = 40  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PhysicsRepRootPart = 392  # instance offset recovered by disassembling this property's GetImpl getter
        PhysicsRepRootRef = 392  # instance offset recovered by disassembling this property's GetImpl getter
        PivotOffset = 392  # instance offset recovered by disassembling this property's GetImpl getter
        Position = 392  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        ReceiveAge = 200  # instance offset recovered by disassembling this property's GetImpl getter
        Reflectance = 76  # instance offset recovered by disassembling this property's GetImpl getter
        ReplicationPV = 392  # instance offset recovered by disassembling this property's GetImpl getter
        ResizeIncrement = 392  # instance offset recovered by disassembling this property's GetImpl getter
        ResizeableFaces = 392  # instance offset recovered by disassembling this property's GetImpl getter
        RightSurface = 200  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        RootPriority = 392  # instance offset recovered by disassembling this property's GetImpl getter
        RotVelocity = 200  # instance offset recovered by disassembling this property's GetImpl getter
        Rotation = 392  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Size = 392  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        SpecificGravity = 200  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        TopSurface = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Transparency = 112  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        Velocity = 200  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        brickColor = 232  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter
        shape = 768  # instance offset recovered by disassembling this property's GetImpl getter
        size = 392  # instance offset recovered by disassembling this property's GetImpl getter

    class ParticleEmitter:  # particle effect emitter
        Enabled = 616  # emitter active flag
        Rate = 584  # particles spawned per second

    class Player:  # local player info
        AccountAge = 860  # account age in days
        CameraMaxZoomDistance = 872  # max camera zoom-out distance
        CameraMinZoomDistance = 876  # min camera zoom-in distance
        Character = 664  # pointer to the player's character model
        DisplayName = 312  # display name string
        HealthDisplayDistance = 916  # health bar visibility distance
        LocaleId = 1864  # locale string (e.g. en-us)
        NameDisplayDistance = 932  # name visibility distance
        Team = 728  # pointer to current Team
        TeamColor = 944  # BrickColor enum of the team
        UserId = 208  # account user ID

    class Players:
        LocalPlayer = 304  # pointer to the local player

    class PointLight:
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Brightness = 20  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Color = 16  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Enabled = 24  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Range = 96  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Shadows = 25  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class Primitive:  # per-part physics data (cframe, velocity, size)
        AssemblyAngularVelocity = 260  # angular velocity of the assembly (rad/s)
        AssemblyLinearVelocity = 248  # linear velocity of the assembly (studs/s)
        CFrame = 200  # full rotation matrix + position of the part
        Material = 582  # material enum value
        Orientation = 200  # Orientation
        Part = 528  # back-pointer from Primitive to its BasePart
        Position = 236  # world position (translation part of CFrame)
        PrimitiveFlags = 438  # Primitive Flags
        Rotation = 200  # Rotation
        Size = 444  # part dimensions in studs

    class PrimitiveFlags:  # physics behavior bitfield (anchored/collide/touch/query)
        Anchored = 2  # bit: part is immovable
        CanCollide = 8  # bit: part participates in collisions
        CanQuery = 32  # bit: part is hit by raycasts
        CanTouch = 16  # bit: part fires Touched events

    class PropertyDescriptor:
        GetSetImpl = 144  # Get Set Impl
        TType = 104  # T Type

    class ProximityPrompt:  # interact prompt
        ActionText = 176  # Action Text
        Enabled = 310  # Enabled
        HoldDuration = 288  # Hold Duration
        KeyboardKeyCode = 292  # Keyboard Key Code
        MaxActivationDistance = 296  # Max Activation Distance
        ObjectText = 208  # Object Text
        RequiresLineOfSight = 311  # Requires Line Of Sight

    class RemoteEvent:
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class RemoteFunction:
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class RenderView:  # render target info
        DeviceD3D11 = 8  # Device D3 D11
        LightingValid = 552  # Lighting Valid
        SkyboxValid = 653  # Skybox Valid

    class RigidConstraint:
        Active = 56  # instance offset recovered by disassembling this property's GetImpl getter
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Attachment0 = 88  # instance offset recovered by disassembling this property's GetImpl getter
        Attachment1 = 120  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Color = 64  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Enabled = 9  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        Visible = 68  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class ScreenGui:
        AbsoluteSize = 309  # instance offset recovered by disassembling this property's GetImpl getter
        ActiveQueryNames = 992  # instance offset recovered by disassembling this property's GetImpl getter
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        AutoLocalize = 101  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        ClipToDeviceSafeArea = 20  # instance offset recovered by disassembling this property's GetImpl getter
        ClippedRect = 101  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DisplayOrder = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Enabled = 12  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IgnoreGuiInset = 1856  # instance offset recovered by disassembling this property's GetImpl getter
        IgnoresTitleBarReservation = 21  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        IsNotOccluded = 101  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        OnTopOfCoreBlur = 22  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RawRect2D = 16  # instance offset recovered by disassembling this property's GetImpl getter
        ReplicatedInsertionOrder = 16  # instance offset recovered by disassembling this property's GetImpl getter
        ResetOnSpawn = 13  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        RootLocalizationTable = 16  # instance offset recovered by disassembling this property's GetImpl getter
        SafeAreaCompatibility = 12  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        ScreenInsets = 16  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorDown = 80  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorLeft = 84  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorRight = 88  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorUp = 92  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionGroup = 96  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        TabKeyboardNavigation = 14  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        TotalGroupScale = 96  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        ZIndexBehavior = 8  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class Script:
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        CachedRemoteSource = 8  # instance offset recovered by disassembling this property's GetImpl getter
        CachedRemoteSourceLoadState = 64  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Disabled = 48  # instance offset recovered by disassembling this property's GetImpl getter
        Enabled = 48  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsDifferentFromFileSystem = 32  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        LinkedSource = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        RunContext = 48  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SandboxedSource = 32  # instance offset recovered by disassembling this property's GetImpl getter
        ScriptGuid = 32  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Source = 8  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class ScriptContext:
        RequireBypass = 2560  # Require Bypass

    class Seat:
        Occupant = 528  # Occupant

    class Shirt:  # shirt template content
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Color3 = 8  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Outfit1 = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Outfit1Content = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Outfit2 = 56  # instance offset recovered by disassembling this property's GetImpl getter
        Outfit2Content = 56  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class Sky:
        MoonAngularSize = 580  # Moon Angular Size
        MoonTextureId = 200  # Moon Texture Id
        SkyboxBk = 248  # Skybox Bk
        SkyboxDn = 296  # Skybox Dn
        SkyboxFt = 344  # Skybox Ft
        SkyboxLf = 392  # Skybox Lf
        SkyboxOrientation = 568  # Skybox Orientation
        SkyboxRt = 440  # Skybox Rt
        SkyboxUp = 488  # Skybox Up
        StarCount = 584  # Star Count
        SunAngularSize = 588  # Sun Angular Size
        SunTextureId = 536  # Sun Texture Id

    class Sound:  # sound instance playback props
        Looped = 317  # restart when finished
        MaxDistance = 288  # audible range in studs
        PlaybackSpeed = 284  # pitch/speed multiplier (1 = normal)
        RollOffMinDistance = 292  # distance where volume rolloff begins
        Volume = 304  # volume 0-10

    class SpawnLocation:  # player spawn point
        Duration = 32  # forcefield duration on spawn
        Neutral = 13  # usable by any team

    class SpecialMesh:
        MeshId = 248  # Mesh Id
        Offset = 184  # Offset
        Scale = 196  # Scale
        TextureId = 296  # Texture Id

    class SpotLight:  # cone light source
        Angle = 4  # instance offset recovered by disassembling this property's GetImpl getter
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Brightness = 20  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Color = 16  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Enabled = 24  # instance offset recovered by disassembling this property's GetImpl getter
        Face = 4  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Origin = 40  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Range = 4  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Shadows = 25  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        SpecificGravity = 200  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        TopSurface = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Transparency = 112  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        Velocity = 200  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        brickColor = 232  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter
        size = 392  # instance offset recovered by disassembling this property's GetImpl getter

    class Status:
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        LevelOfDetail = 124  # instance offset recovered by disassembling this property's GetImpl getter
        LodEntity = 16  # instance offset recovered by disassembling this property's GetImpl getter
        ModelMeshCFrame = 64  # instance offset recovered by disassembling this property's GetImpl getter
        ModelMeshData = 40  # instance offset recovered by disassembling this property's GetImpl getter
        ModelMeshSize = 408  # instance offset recovered by disassembling this property's GetImpl getter
        ModelStreamingMode = 128  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        NeedsPivotMigration = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Origin = 40  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PrimaryPart = 408  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        Scale = 132  # instance offset recovered by disassembling this property's GetImpl getter
        ScaleFactor = 132  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SlimAnimationTarget = 32  # instance offset recovered by disassembling this property's GetImpl getter
        SlimHash = 408  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        WorldPivot = 56  # instance offset recovered by disassembling this property's GetImpl getter
        WorldPivotData = 56  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class StringValue:  # string container
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        Value = 184  # SSO string payload offset
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class TaskScheduler:  # frame scheduler (fps cap, job list)
        JobEnd = 208  # Job End
        JobName = 24  # Job Name
        JobStart = 200  # Job Start
        MaxFps = 176  # frame cap as frame-time double (1/fps); write smaller value for higher cap
        Pointer = 144985448  # Pointer

    class Team:  # team definition
        TeamColor = 184  # BrickColor enum of the team

    class Terrain:
        GrassLength = 488  # Grass Length
        MaterialColors = 1200  # Material Colors
        WaterColor = 472  # Water Color
        WaterReflectance = 496  # Water Reflectance
        WaterTransparency = 500  # Water Transparency
        WaterWaveSize = 504  # Water Wave Size
        WaterWaveSpeed = 508  # Water Wave Speed

    class TextButton:
        AbsoluteSize = 309  # instance offset recovered by disassembling this property's GetImpl getter
        Active = 1404  # instance offset recovered by disassembling this property's GetImpl getter
        ActiveQueryNames = 992  # instance offset recovered by disassembling this property's GetImpl getter
        AnchorPoint = 1280  # instance offset recovered by disassembling this property's GetImpl getter
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        AutoButtonColor = 76  # instance offset recovered by disassembling this property's GetImpl getter
        AutoLocalize = 101  # instance offset recovered by disassembling this property's GetImpl getter
        AutomaticSize = 184  # instance offset recovered by disassembling this property's GetImpl getter
        BorderMode = 184  # instance offset recovered by disassembling this property's GetImpl getter
        BorderSizePixel = 16  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        ClippedRect = 101  # instance offset recovered by disassembling this property's GetImpl getter
        ClipsDescendants = 16  # instance offset recovered by disassembling this property's GetImpl getter
        Confidential = 244  # instance offset recovered by disassembling this property's GetImpl getter
        ContentText = 8  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DragBeginConnectionCount = 184  # instance offset recovered by disassembling this property's GetImpl getter
        DragStoppedConnectionCount = 188  # instance offset recovered by disassembling this property's GetImpl getter
        Draggable = 242  # instance offset recovered by disassembling this property's GetImpl getter
        Font = 104  # instance offset recovered by disassembling this property's GetImpl getter
        FontFace = 104  # instance offset recovered by disassembling this property's GetImpl getter
        GuiState = 1400  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        HoverHapticEffect = 16  # instance offset recovered by disassembling this property's GetImpl getter
        InputSink = 1404  # instance offset recovered by disassembling this property's GetImpl getter
        Interactable = 1451  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        IsNotOccluded = 101  # instance offset recovered by disassembling this property's GetImpl getter
        LayoutOrder = 16  # instance offset recovered by disassembling this property's GetImpl getter
        LineHeight = 104  # instance offset recovered by disassembling this property's GetImpl getter
        LocalizationMatchIdentifier = 40  # instance offset recovered by disassembling this property's GetImpl getter
        LocalizationMatchedSourceText = 72  # instance offset recovered by disassembling this property's GetImpl getter
        LocalizedText = 104  # instance offset recovered by disassembling this property's GetImpl getter
        MaxVisibleGraphemes = 72  # instance offset recovered by disassembling this property's GetImpl getter
        Modal = 76  # instance offset recovered by disassembling this property's GetImpl getter
        MouseButton1ClickConnectionCount = 48  # instance offset recovered by disassembling this property's GetImpl getter
        MouseButton1DownConnectionCount = 56  # instance offset recovered by disassembling this property's GetImpl getter
        MouseButton1UpConnectionCount = 56  # instance offset recovered by disassembling this property's GetImpl getter
        MouseButton2ClickConnectionCount = 60  # instance offset recovered by disassembling this property's GetImpl getter
        MouseButton2DownConnectionCount = 64  # instance offset recovered by disassembling this property's GetImpl getter
        MouseButton2UpConnectionCount = 16  # instance offset recovered by disassembling this property's GetImpl getter
        MouseEnterConnectionCount = 204  # instance offset recovered by disassembling this property's GetImpl getter
        MouseLeaveConnectionCount = 208  # instance offset recovered by disassembling this property's GetImpl getter
        MouseMovedConnectionCount = 212  # instance offset recovered by disassembling this property's GetImpl getter
        MouseWheelBackwardConnectionCount = 216  # instance offset recovered by disassembling this property's GetImpl getter
        MouseWheelForwardConnectionCount = 1428  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        NextSelectionDown = 16  # instance offset recovered by disassembling this property's GetImpl getter
        NextSelectionLeft = 1240  # instance offset recovered by disassembling this property's GetImpl getter
        NextSelectionRight = 1256  # instance offset recovered by disassembling this property's GetImpl getter
        NextSelectionUp = 1272  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Position = 1432  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PressHapticEffect = 32  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RawRect2D = 16  # instance offset recovered by disassembling this property's GetImpl getter
        ReplicatedInsertionOrder = 16  # instance offset recovered by disassembling this property's GetImpl getter
        RichText = 72  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        RootLocalizationTable = 16  # instance offset recovered by disassembling this property's GetImpl getter
        Rotation = 1432  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        Selectable = 1312  # instance offset recovered by disassembling this property's GetImpl getter
        Selected = 78  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorDown = 80  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorLeft = 84  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorRight = 88  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorUp = 92  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionGroup = 96  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionImageObject = 1280  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionOrder = 1340  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionRect2D = 104  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Size = 1312  # instance offset recovered by disassembling this property's GetImpl getter
        SizeConstraint = 1400  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Style = 16  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        Text = 72  # instance offset recovered by disassembling this property's GetImpl getter
        TotalGroupScale = 96  # instance offset recovered by disassembling this property's GetImpl getter
        Transparency = 184  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        Visible = 1404  # instance offset recovered by disassembling this property's GetImpl getter
        ZIndex = 1404  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class TextLabel:
        AbsoluteSize = 309  # instance offset recovered by disassembling this property's GetImpl getter
        Active = 1404  # instance offset recovered by disassembling this property's GetImpl getter
        ActiveQueryNames = 992  # instance offset recovered by disassembling this property's GetImpl getter
        AnchorPoint = 1280  # instance offset recovered by disassembling this property's GetImpl getter
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        AutoLocalize = 101  # instance offset recovered by disassembling this property's GetImpl getter
        AutomaticSize = 184  # instance offset recovered by disassembling this property's GetImpl getter
        BorderMode = 184  # instance offset recovered by disassembling this property's GetImpl getter
        BorderSizePixel = 16  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        ClippedRect = 101  # instance offset recovered by disassembling this property's GetImpl getter
        ClipsDescendants = 16  # instance offset recovered by disassembling this property's GetImpl getter
        Confidential = 3804  # instance offset recovered by disassembling this property's GetImpl getter
        ContentText = 3568  # raw text content before rich-text processing
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DragBeginConnectionCount = 184  # instance offset recovered by disassembling this property's GetImpl getter
        DragStoppedConnectionCount = 188  # instance offset recovered by disassembling this property's GetImpl getter
        Draggable = 242  # instance offset recovered by disassembling this property's GetImpl getter
        FontSize = 3592  # instance offset recovered by disassembling this property's GetImpl getter
        GuiState = 1400  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        InputSink = 1404  # instance offset recovered by disassembling this property's GetImpl getter
        Interactable = 1451  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        IsNotOccluded = 101  # instance offset recovered by disassembling this property's GetImpl getter
        LayoutOrder = 16  # instance offset recovered by disassembling this property's GetImpl getter
        LocalizationMatchIdentifier = 3600  # instance offset recovered by disassembling this property's GetImpl getter
        LocalizationMatchedSourceText = 72  # instance offset recovered by disassembling this property's GetImpl getter
        LocalizedText = 3664  # localized text variant
        MaxVisibleGraphemes = 72  # grapheme reveal limit (-1 = all)
        MouseEnterConnectionCount = 204  # instance offset recovered by disassembling this property's GetImpl getter
        MouseLeaveConnectionCount = 208  # instance offset recovered by disassembling this property's GetImpl getter
        MouseMovedConnectionCount = 212  # instance offset recovered by disassembling this property's GetImpl getter
        MouseWheelBackwardConnectionCount = 216  # instance offset recovered by disassembling this property's GetImpl getter
        MouseWheelForwardConnectionCount = 1428  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        NextSelectionDown = 16  # instance offset recovered by disassembling this property's GetImpl getter
        NextSelectionLeft = 1240  # instance offset recovered by disassembling this property's GetImpl getter
        NextSelectionRight = 1256  # instance offset recovered by disassembling this property's GetImpl getter
        NextSelectionUp = 1272  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Position = 1432  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RawRect2D = 16  # instance offset recovered by disassembling this property's GetImpl getter
        ReplicatedInsertionOrder = 16  # instance offset recovered by disassembling this property's GetImpl getter
        RichText = 72  # rich text markup enabled
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        RootLocalizationTable = 16  # instance offset recovered by disassembling this property's GetImpl getter
        Rotation = 1432  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        Selectable = 1312  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorDown = 80  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorLeft = 84  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorRight = 88  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionBehaviorUp = 92  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionGroup = 96  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionImageObject = 1280  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionOrder = 1340  # instance offset recovered by disassembling this property's GetImpl getter
        SelectionRect2D = 104  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Size = 1312  # instance offset recovered by disassembling this property's GetImpl getter
        SizeConstraint = 1400  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        Text = 72  # the rendered text (SSO string)
        TotalGroupScale = 96  # instance offset recovered by disassembling this property's GetImpl getter
        Transparency = 184  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        Visible = 1404  # instance offset recovered by disassembling this property's GetImpl getter
        ZIndex = 1404  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class Texture:
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        ColorMap = 104  # instance offset recovered by disassembling this property's GetImpl getter
        ColorMapContent = 104  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        EmissiveMaskContent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        EmissiveTint = 296  # instance offset recovered by disassembling this property's GetImpl getter
        Face = 16  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        MetalnessMap = 56  # instance offset recovered by disassembling this property's GetImpl getter
        MetalnessMapContent = 56  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        NormalMap = 104  # instance offset recovered by disassembling this property's GetImpl getter
        NormalMapContent = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Rotation = 376  # instance offset recovered by disassembling this property's GetImpl getter
        RoughnessMap = 56  # instance offset recovered by disassembling this property's GetImpl getter
        RoughnessMapContent = 56  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        StudsPerTileV = 36  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        TexturePack = 296  # instance offset recovered by disassembling this property's GetImpl getter
        TexturePackContent = 296  # instance offset recovered by disassembling this property's GetImpl getter
        TexturePackMetadata = 296  # instance offset recovered by disassembling this property's GetImpl getter
        UVOffset = 376  # instance offset recovered by disassembling this property's GetImpl getter
        UVScale = 376  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        ZIndex = 376  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class Tool:
        CanBeDropped = 1208  # Can Be Dropped
        Enabled = 1209  # Enabled
        Grip = 1160  # Grip
        GripForward = 1184  # Grip Forward
        GripPos = 1196  # Grip Pos
        GripRight = 1160  # Grip Right
        GripUp = 1172  # Grip Up
        ManualActivationOnly = 1210  # Manual Activation Only
        RequiresHandle = 1211  # Requires Handle
        Tooltip = 1128  # Tooltip

    class Value:
        Value = 184  # generic ValueBase payload offset

    class Vector3Value:  # vector3 container
        Value = 184  # vector3 payload

    class VehicleSeat:
        MaxSpeed = 552  # Max Speed
        Occupant = 520  # Occupant
        SteerFloat = 556  # Steer Float
        ThrottleFloat = 560  # Throttle Float
        Torque = 564  # Torque
        TurnSpeed = 568  # Turn Speed

    class VisualEngine:  # renderer root (view matrix, render view)
        Dimensions = 2784  # Dimensions
        FakeDataModel = 2752  # Fake Data Model
        Pointer = 137240872  # Pointer
        RenderView = 3072  # Render View
        ViewMatrix = 384  # View Matrix

    class Weld:
        Active = 120  # instance offset recovered by disassembling this property's GetImpl getter
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        C0 = 208  # instance offset recovered by disassembling this property's GetImpl getter
        C1 = 208  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        EnableSkinning = 56  # instance offset recovered by disassembling this property's GetImpl getter
        Enabled = 8  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Part0 = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Part1 = 120  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter
        part1 = 120  # instance offset recovered by disassembling this property's GetImpl getter

    class Wire:
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Connected = 8  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        SourceInstance = 8  # instance offset recovered by disassembling this property's GetImpl getter
        SourceName = 8  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        TargetInstance = 96  # instance offset recovered by disassembling this property's GetImpl getter
        TargetName = 40  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter

    class Workspace:  # 3D world container
        CurrentCamera = 1176  # pointer to the active Camera
        ReadOnlyGravity = 2504  # cached gravity value (studs/s^2)
        World = 1008  # pointer to the physics World

    class World:  # physics simulation container (gravity, sim rate, primitives)
        AirProperties = 568  # air density / global wind container
        Gravity = 552  # live gravity used by the solver (write to change fall speed)
        Primitives = 680  # array of every Primitive in the world
        dLastFrameTimeStamp = 960  # D Last Frame Time Stamp
        dLastSendTimeStamp = 968  # D Last Send Time Stamp
        dWorldStepDt = 984  # D World Step Dt
        dwLastNumberOfWorldStep = 976  # Last Number Of World Step
        dwWorldStepid = 232  # World Stepid
        fWorldStepsPerSecond = 1824  # World Steps Per Second

    class WorldRoot:
        RaycastBoundDesc = 134782752  # Raycast Bound Desc
        RaycastBoundFn = 128  # Raycast Bound Fn

    class WrapTarget:
        Archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        AttributesSerialize = 112  # instance offset recovered by disassembling this property's GetImpl getter
        CageMeshContent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        CageMeshId = 8  # instance offset recovered by disassembling this property's GetImpl getter
        CageOrigin = 176  # instance offset recovered by disassembling this property's GetImpl getter
        CageOriginWorld = 224  # instance offset recovered by disassembling this property's GetImpl getter
        Capabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        Color = 8  # instance offset recovered by disassembling this property's GetImpl getter
        DataCost = 170  # instance offset recovered by disassembling this property's GetImpl getter
        DebugMode = 20  # instance offset recovered by disassembling this property's GetImpl getter
        DefinesCapabilities = 74  # instance offset recovered by disassembling this property's GetImpl getter
        HSRAssetId = 56  # instance offset recovered by disassembling this property's GetImpl getter
        HSRContent = 56  # instance offset recovered by disassembling this property's GetImpl getter
        HSRData = 160  # instance offset recovered by disassembling this property's GetImpl getter
        HSRMeshIdData = 272  # instance offset recovered by disassembling this property's GetImpl getter
        HistoryId = 112  # instance offset recovered by disassembling this property's GetImpl getter
        ImportInProcess = 272  # instance offset recovered by disassembling this property's GetImpl getter
        ImportOrigin = 224  # instance offset recovered by disassembling this property's GetImpl getter
        IsInSandbox = 172  # instance offset recovered by disassembling this property's GetImpl getter
        Name = 112  # instance offset recovered by disassembling this property's GetImpl getter
        Parent = 8  # instance offset recovered by disassembling this property's GetImpl getter
        PredictionMode = 172  # instance offset recovered by disassembling this property's GetImpl getter
        PropertyStatusStudio = 74  # instance offset recovered by disassembling this property's GetImpl getter
        RobloxLocked = 104  # instance offset recovered by disassembling this property's GetImpl getter
        Sandboxed = 170  # instance offset recovered by disassembling this property's GetImpl getter
        SerializedOverrides = 112  # instance offset recovered by disassembling this property's GetImpl getter
        SourceAssetId = 136  # instance offset recovered by disassembling this property's GetImpl getter
        Stiffness = 24  # instance offset recovered by disassembling this property's GetImpl getter
        Tags = 40  # instance offset recovered by disassembling this property's GetImpl getter
        TemporaryCageMeshContent = 104  # instance offset recovered by disassembling this property's GetImpl getter
        TemporaryCageMeshId = 104  # instance offset recovered by disassembling this property's GetImpl getter
        UniqueId = 40  # instance offset recovered by disassembling this property's GetImpl getter
        archivable = 74  # instance offset recovered by disassembling this property's GetImpl getter
        numExpectedDirectChildren = 40  # instance offset recovered by disassembling this property's GetImpl getter


class FFlags:
    """FastFlag value addresses (absolute, this session only)"""

    DFFlagCLI119 = 1767787882941  # Bool = false
    DFFlagCapturePlayerGuiScreenshotAndBuildVideos = 1767620290237  # Bool = false
    DFFlagFixMonitorNullDerefOnBatchConnect = 1767461261405  # Bool = false
    DFFlagFixVoiceAvailabilityRetryInfiniteLoop = 1767461260368  # Unknown = 
    DFFlagGetHlsLodManifest2 = 1767620296797  # Bool = false
    DFFlagTextChatUserMessageIntentRaisedLimitEnabled = 1767724904941  # Bool = true
    DFStringContentProviderToAssetDeliveryMarkFromLodLoadStudy = 1767724977888  # Unknown = 
    DFVideoStudioPreviewPermissionFix2 = 1767420650256  # Unknown = 
    FFlagAEGIS2EnableGatesForExpChat = 1768001204509  # Bool = false
    FFlagAEGIS2EnableGatesForExpChat6 = 1768001213213  # Bool = false
    FFlagAEGIS2UseGuacToShowEnabledMessage = 1768133835408  # Unknown = 
    FFlagAEGIS2UseGuacToShowFAEUpsell = 1768133843728  # Unknown = 
    FFlagAEGISPhase2ShowImageOnFAEOverlay = 1767900720669  # Bool = true
    FFlagAEGetEditableOutfitsType2 = 1767650028445  # Bool = false
    FFlagAFPConnectionsChannelsHeader = 1767583401488  # Unknown = 
    FFlagAIRephraseSettingEnabled3 = 1767583526237  # Bool = true
    FFlagAXAccessoryAdjustmentReturnOnNil = 1767977072861  # Bool = false
    FFlagAXAdaptiveScrollingFixForward = 1768393672784  # Unknown = 
    FFlagAXAddFacesToHeadList = 1767977080912  # Unknown = 
    FFlagAXAddHDCatalogTab = 1767977061584  # Unknown = 
    FFlagAXAddHDCatalogTooltip = 1767977080336  # Unknown = 
    FFlagAXAddHDRowInItemDetailsPage = 1767640160336  # Unknown = 
    FFlagAXAddInventoryItemsListProps = 1768393709200  # Unknown = 
    FFlagAXAddLimitedLabelForCheckout = 1768393672912  # Unknown = 
    FFlagAXAddManageOutfitClickTracking = 1768393720720  # Unknown = 
    FFlagAXAddManageOutfitClickTracking2 = 1768393735056  # Unknown = 
    FFlagAXAddNavigationKeyToEditorSubcategories2 = 1767650025949  # Bool = false
    FFlagAXAddSearchTrendingChips2 = 1767640158480  # Unknown = 
    FFlagAXAddSectionsToItemInfoRowPrompt = 1767640168016  # Unknown = 
    FFlagAXAddTextXAlignmentProp = 1768393697757  # Bool = false
    FFlagAXAddToolTipToIconItemMenu = 1768393682845  # Bool = false
    FFlagAXAddToolTipToIconItemMenu2 = 1768393719952  # Unknown = 
    FFlagAXAddTransparencyToItemCardHeader = 1768393705181  # Bool = false
    FFlagAXAddV1CountersForMISPurchaseSuccess = 1767901875600  # Unknown = 
    FFlagAXAnimatedLooksThumbnails = 1767654067037  # Bool = false
    FFlagAXAppLaunchedCounterEnabled = 1767654064656  # Unknown = 
    FFlagAXAppSystemBarEnableTelemtryForFPS = 1767654068624  # Unknown = 
    FFlagAXAppSystemBarEnableTelemtryForFPSForAll = 1767654068560  # Unknown = 
    FFlagAXAvatarEditorStoresContext = 1768393714640  # Unknown = 
    FFlagAXAvatarFoldersEnabled = 1768393706640  # Unknown = 
    FFlagAXAvatarFoldersEnabledDev = 1768393684957  # Bool = false
    FFlagAXAvatarLoadWithRetry = 1767977088144  # Unknown = 
    FFlagAXAvatarSharingEntryPoint = 1768393717469  # Bool = false
    FFlagAXAvatarSortInDiscoveryUnifiedPurchase = 1767828555088  # Unknown = 
    FFlagAXAvatarTabLooksYouMayAlsoLike = 1768393674141  # Bool = false
    FFlagAXAvatarTabShopForMore = 1767650029597  # Bool = false
    FFlagAXAvatarTabWidgetRecommendation = 1767977062992  # Unknown = 
    FFlagAXAvatarsTabIXP = 1768393735645  # Bool = false
    FFlagAXAvatarsTabIXP1 = 1768393684688  # Unknown = 
    FFlagAXAvatarsTabIXPEnabledForAll = 1768393688656  # Unknown = 
    FFlagAXAvatarsTabNoItemsFound = 1767654066909  # Bool = false
    FFlagAXBackendDrivenCatalogLayers = 1768393693392  # Unknown = 
    FFlagAXBackgroundCycloramaRendering = 1767494509256  # Unknown = 
    FFlagAXBackgroundDisableFogWhileActive = 1767640155229  # Bool = false
    FFlagAXBackgroundGenerationDev = 1767640162256  # Unknown = 
    FFlagAXBackgroundSceneManagerRevamp = 1768393700304  # Unknown = 
    FFlagAXBackgroundSceneManagerRevamp3 = 1768393698448  # Unknown = 
    FFlagAXBackgroundsCustomizeHydration4 = 1767640158621  # Bool = false
    FFlagAXBackgroundsCycloramaVR = 1767640158288  # Unknown = 
    FFlagAXBackgroundsEquipTryOnCounters2 = 1767640161245  # Bool = false
    FFlagAXBackgroundsInAvatarBustThumbnails = 1767526237981  # Bool = false
    FFlagAXBackgroundsInAvatarThumbnails = 1767526237533  # Bool = false
    FFlagAXBackgroundsInHeadshotThumbnails = 1767526238557  # Bool = false
    FFlagAXBackgroundsInOutfitDetails = 1767640159517  # Bool = false
    FFlagAXBackgroundsInOutfitThumbnails = 1767526239005  # Bool = false
    FFlagAXBackgroundsOutfitHighlight = 1767640159837  # Bool = false
    FFlagAXBackgroundsOutfitPersistence = 1767900728373  # Bool = true
    FFlagAXBackgroundsPersistence = 1767640160093  # Bool = false
    FFlagAXBackgroundsRoot = 1767977091792  # Unknown = 
    FFlagAXBackgroundsTryOn = 1767640160925  # Bool = false
    FFlagAXBlockMakeupEquipR6 = 1767977086736  # Unknown = 
    FFlagAXBodyPartsPillLabel = 1768393691728  # Unknown = 
    FFlagAXBuildSubcategoryMapWhenBuildingCategoryInfo = 1767425924829  # Bool = true
    FFlagAXCameraDownwardTilt = 1767654057821  # Bool = false
    FFlagAXCameraLevelHorizon = 1767654057949  # Bool = false
    FFlagAXCameraManagerErrorsEnabled = 1767654056989  # Bool = false
    FFlagAXCatalogBackgroundsFilters = 1767640154461  # Bool = false
    FFlagAXCatalogBackgroundsSupport = 1767640151632  # Unknown = 
    FFlagAXCatalogBodySuits = 1767977110224  # Unknown = 
    FFlagAXCatalogCategoriesSDUI = 1767977101072  # Unknown = 
    FFlagAXCatalogCategoriesSDUI14 = 1767977059472  # Unknown = 
    FFlagAXCatalogCategoriesSDUIDebugDiff = 1767977071632  # Unknown = 
    FFlagAXCatalogCategoriesSDUILinks = 1767977103965  # Bool = true
    FFlagAXCatalogCategoriesSDUIPillTitleNormalization = 1767977072400  # Unknown = 
    FFlagAXCatalogCategoriesSDUITaxonomy = 1767977065104  # Unknown = 
    FFlagAXCatalogCategoriesStoreImprovePerf = 1767977077456  # Unknown = 
    FFlagAXCatalogCategoryTooltip = 1767977075677  # Bool = false
    FFlagAXCatalogItemCardDarkerBackground = 1767640167069  # Bool = false
    FFlagAXCatalogItemCardDarkerBackgroundLogExposure = 1775984823480  # Unknown = 
    FFlagAXCatalogItemInformationPopover2 = 1767640164509  # Bool = false
    FFlagAXCatalogM41CategoriesExposureLogging = 1767977078992  # Unknown = 
    FFlagAXCatalogM41FullMasks = 1767977100112  # Unknown = 
    FFlagAXCatalogM41HandAndArm = 1767977061072  # Unknown = 
    FFlagAXCatalogM41Props = 1767977064976  # Unknown = 
    FFlagAXCatalogM41Props3 = 1767977068752  # Unknown = 
    FFlagAXCatalogMakeupFtuxUseMemStorage = 1767643507792  # Unknown = 
    FFlagAXCatalogMakeupSupport = 1768393714256  # Unknown = 
    FFlagAXCatalogMakeupSupport10 = 1768393714192  # Unknown = 
    FFlagAXCatalogMakeupTaxonomy = 1767977096336  # Unknown = 
    FFlagAXCatalogMakeupTaxonomy2 = 1767977090960  # Unknown = 
    FFlagAXCatalogMultiItemShoppingFtuxUseMemStorage = 1767643507357  # Bool = false
    FFlagAXCatalogOffersAutoOpenFTUXSheet = 1767977097808  # Unknown = 
    FFlagAXCatalogOffersAutoOpenFTUXSheet2 = 1767977065296  # Unknown = 
    FFlagAXCatalogOffersBannerAppStorageUseMemStorage = 1767643486736  # Unknown = 
    FFlagAXCatalogOffersBannerEnabled = 1767977096848  # Unknown = 
    FFlagAXCatalogOffersBannerEnabled2 = 1767977086864  # Unknown = 
    FFlagAXCatalogOffersBannerMockApi = 1767977080016  # Unknown = 
    FFlagAXCatalogOffersClearOnLogout = 1767977120400  # Unknown = 
    FFlagAXCatalogOffersClearOnLogout2 = 1767977099920  # Unknown = 
    FFlagAXCatalogOffersDismissedStorageKeyFix = 1767977106128  # Unknown = 
    FFlagAXCatalogPerfReduxReductionIXP2 = 1767650031056  # Unknown = 
    FFlagAXCatalogPerfReduxReductionIXPEnabledForAll2 = 1767650030736  # Unknown = 
    FFlagAXCatalogRealTimeRecommendationsIXPEnabledForAllV2 = 1767654066781  # Bool = false
    FFlagAXCatalogRealTimeRecommendationsIXPV2 = 1767654066397  # Bool = false
    FFlagAXCatalogSaveOptionsUseMemStorage = 1767643505949  # Bool = false
    FFlagAXCatalogSduiDisableOnSearchRoute = 1767900747805  # Bool = true
    FFlagAXCatalogSduiSingleRetryButtonOnError = 1767977094992  # Unknown = 
    FFlagAXCatalogSduiUseOpaqueRouteForSearch = 1767640148253  # Bool = false
    FFlagAXCatalogSearchSupportDisableFilters = 1767977097104  # Unknown = 
    FFlagAXCatalogSupportDisableFilters = 1767977077712  # Unknown = 
    FFlagAXCatalogSupportDisableFilters3 = 1767977096208  # Unknown = 
    FFlagAXCatalogUseFixedWidgetPadding = 1767972955848  # Unknown = 
    FFlagAXCategoryMenuBadgePositionTokens2 = 1767899165213  # Bool = false
    FFlagAXCategoryMenuVisualFixes = 1767640148637  # Bool = false
    FFlagAXCategoryPillColorAnimation = 1768393708560  # Unknown = 
    FFlagAXCategoryPillPositionAnimation = 1768393701328  # Unknown = 
    FFlagAXCategoryUnifiedLogging = 1768393683472  # Unknown = 
    FFlagAXCharacterToAvatarStrings = 1768393705949  # Bool = false
    FFlagAXCheckApplyDefaultClothingErrorGuards = 1767654061341  # Bool = false
    FFlagAXCloseFilterOnBackgroundTap = 1767470837648  # Unknown = 
    FFlagAXColorAdjustmentButtonShouldAccountForTryOns = 1768393707920  # Unknown = 
    FFlagAXColorGradientRenderFlatWithJustOneColor = 1767899171741  # Bool = false
    FFlagAXCombineGetOutfitDispatchesIXP3 = 1767650025053  # Bool = false
    FFlagAXCombineGetOutfitDispatchesIXPForAll3 = 1767650024848  # Unknown = 
    FFlagAXCommunityAvatarsMakeupEquipping = 1767977079184  # Unknown = 
    FFlagAXCustomGetStateForActionHandler = 1768393684893  # Bool = false
    FFlagAXCustomGetStateForActionHandler3 = 1768393721168  # Unknown = 
    FFlagAXCustomizeBackgrounds = 1767977077328  # Unknown = 
    FFlagAXCycloramaAssetFallback2 = 1767640156573  # Bool = false
    FFlagAXDHEquippedAssetsNilCheck = 1767899179421  # Bool = false
    FFlagAXDebugCreateHumanoidModelError = 1767654057360  # Unknown = 
    FFlagAXDebugForceIsRecentMarketplaceEnabled = 1767654067152  # Unknown = 
    FFlagAXDebugGridShouldErrorOnInvalidRowCount = 1767899163536  # Unknown = 
    FFlagAXDebugMobileRbxlContentProbe = 1767640154384  # Unknown = 
    FFlagAXDebugPanel = 1767640150992  # Unknown = 
    FFlagAXDebugPanelImpressed = 1767977082768  # Unknown = 
    FFlagAXDefaultAvatarToShopEnabled3 = 1767654063632  # Unknown = 
    FFlagAXDefaultAvatarToShopEnabledForAll3 = 1767654061776  # Unknown = 
    FFlagAXDefaultAvatarToShopWidgetEnabled3 = 1767654061200  # Unknown = 
    FFlagAXDeferLookImpressionsForHydration = 1767977106461  # Bool = true
    FFlagAXDeferWidgetLoadedUntilMarketplaceEntered = 1767977082128  # Unknown = 
    FFlagAXDisableControlBarMenuAnimation = 1767650020317  # Bool = false
    FFlagAXDisableHiddenCatalogCategoryPills = 1768393681872  # Unknown = 
    FFlagAXDisableMultiItemShoppingFtux = 1768393683984  # Unknown = 
    FFlagAXDisableTimedOptionsFtux = 1767643500181  # Bool = false
    FFlagAXDisableWidgetHydrationCacheForLooks = 1767654067357  # Bool = false
    FFlagAXDoNotPass356FetchCartPricing = 1767643505501  # Bool = false
    FFlagAXDownrankMakeupCustomize = 1767977076624  # Unknown = 
    FFlagAXDurables2Option = 1767977089936  # Unknown = 
    FFlagAXDurables2Option4 = 1767977117456  # Unknown = 
    FFlagAXDurables2OptionFixes = 1767977078736  # Unknown = 
    FFlagAXDurablesFooter = 1767977084496  # Unknown = 
    FFlagAXDurablesFooter2 = 1767977086032  # Unknown = 
    FFlagAXDurablesFooterWithPermanent = 1767725051245  # Bool = false
    FFlagAXDurablesForMIS = 1768393693840  # Unknown = 
    FFlagAXDurablesForMIS2 = 1768393685264  # Unknown = 
    FFlagAXDurablesSupportExposureLogging = 1767977097872  # Unknown = 
    FFlagAXDurablesSupportForRFYMigration = 1768393713232  # Unknown = 
    FFlagAXDurablesSupportForRFYMigration2 = 1768393705040  # Unknown = 
    FFlagAXDurablesSupportWithPostPurchaseFix = 1768393692752  # Unknown = 
    FFlagAXEditorEnableThumbnailLatencyStore2 = 1767640160848  # Unknown = 
    FFlagAXEditorSubcategoryFilters = 1768393696157  # Bool = false
    FFlagAXEditorSubcategoryFilters2 = 1768393711376  # Unknown = 
    FFlagAXEnableAvatarDataRefreshV4 = 1767650025744  # Unknown = 
    FFlagAXEnableBatchItemDetailsFetchV2 = 1767977066320  # Unknown = 
    FFlagAXEnableBatchUnequips2 = 1767650026832  # Unknown = 
    FFlagAXEnableCategoryPills9 = 1767650023645  # Bool = false
    FFlagAXEnableCategoryPillsExposureLogging = 1767977075280  # Unknown = 
    FFlagAXEnableCategoryPillsExposureLogging2 = 1767977112912  # Unknown = 
    FFlagAXEnableEditorCategoryDeepLink = 1768133873296  # Unknown = 
    FFlagAXEnableErrorLoggingForSubcategorySelectionById = 1767481598821  # Bool = false
    FFlagAXEnableExpiredUserLookCheckout = 1768393694928  # Unknown = 
    FFlagAXEnableExpiredUserLookCheckout10 = 1768393688400  # Unknown = 
    FFlagAXEnableFetchAvatarPreview = 1767899797205  # Bool = false
    FFlagAXEnableFetchAvatarPreview9 = 1767899797405  # Bool = false
    FFlagAXEnableFoundationSegmentedMenu = 1768393689629  # Bool = false
    FFlagAXEnableFullSceneInteractionFrame3 = 1767427005456  # Unknown = 
    FFlagAXEnableHeadCombineHeadPickerIXPTogether2 = 1767650027037  # Bool = false
    FFlagAXEnableHomeTryOnComplexView = 1767526037392  # Unknown = 
    FFlagAXEnableIaBRbxClientFeature = 1767899792669  # Bool = false
    FFlagAXEnableIaBTimedOptionsBulkPurchase = 1767900769493  # Bool = true
    FFlagAXEnableIaBTimedOptionsBulkPurchase3 = 1767640151325  # Bool = false
    FFlagAXEnableInspectAndBuyBulkPurchase = 1767828583184  # Unknown = 
    FFlagAXEnableInspectAndBuyBulkPurchase3 = 1767828569040  # Unknown = 
    FFlagAXEnableInspectAndBuyExposureLogging = 1767901859152  # Unknown = 
    FFlagAXEnableInspectAndBuyFocusNavigation = 1767977065616  # Unknown = 
    FFlagAXEnableInspectAndBuyVersionAnalytics = 1767899793173  # Bool = false
    FFlagAXEnableMakeupOutfitCreation = 1767900750405  # Bool = true
    FFlagAXEnableManualSaving = 1768393676688  # Unknown = 
    FFlagAXEnableManualSaving4 = 1768393719440  # Unknown = 
    FFlagAXEnableManualSavingBlockingPrompt = 1768393729424  # Unknown = 
    FFlagAXEnableManualSavingBlockingPrompt3 = 1768393715216  # Unknown = 
    FFlagAXEnableMaxUndoRedoHistory = 1768385623917  # Bool = false
    FFlagAXEnableModeratedItemsFlowForDurables = 1768393702352  # Unknown = 
    FFlagAXEnableMultiTryOnUI = 1767640171549  # Bool = false
    FFlagAXEnableNewInspectAndBuyContainer = 1767899819029  # Bool = false
    FFlagAXEnableNewInspectAndBuyContainer21 = 1767899817744  # Unknown = 
    FFlagAXEnableNewInventoryItemsList2 = 1767650025488  # Unknown = 
    FFlagAXEnableProfileTab_1 = 1767831060048  # Unknown = 
    FFlagAXEnableRecommendationTypeAllInCustomize2 = 1767650028893  # Bool = false
    FFlagAXEnableRegionalFilteringofAssets = 1767913659413  # Bool = false
    FFlagAXEnableResponsiveHeadRefinementMenu = 1767977112592  # Unknown = 
    FFlagAXEnableSearchLandingFocusedPageFullViewDefault = 1767650023389  # Bool = false
    FFlagAXEnableTaxonomyM20ExposureLoggingCatalog = 1767977080144  # Unknown = 
    FFlagAXEnableTaxonomyM20ExposureLoggingClothing = 1767977060368  # Unknown = 
    FFlagAXEnableTaxonomyM21ExposureLoggingClothing = 1767977075856  # Unknown = 
    FFlagAXEnableTimedOptionsForCatalogRowCard2 = 1767640151901  # Bool = false
    FFlagAXEnableTimedOptionsServerScript = 1767828565200  # Unknown = 
    FFlagAXEnableUnifiedProductPurchaseForMarketplace = 1767977092304  # Unknown = 
    FFlagAXEnableUnifiedProductPurchaseForMarketplace2 = 1767977066960  # Unknown = 
    FFlagAXEnableUnifiedPurchaseFlowForLooks = 1767977082512  # Unknown = 
    FFlagAXEnhancedAvatarHeadsFtuxUseMemStorage = 1767977101968  # Unknown = 
    FFlagAXEnsureOfferBannerRefetchMIS = 1767643506397  # Bool = false
    FFlagAXEnsureOfferBannerRefetchUnified = 1776067324125  # Bool = true
    FFlagAXExpandPeekViewOnFirstScroll = 1768393687824  # Unknown = 
    FFlagAXExpandPeekViewOnFirstScroll1 = 1768393701712  # Unknown = 
    FFlagAXExtendUndoRedoTracking = 1768393687120  # Unknown = 
    FFlagAXExtractEmotesCategory2 = 1767650028573  # Bool = false
    FFlagAXEyebrowEyelashToMakeupCategory = 1767977059024  # Unknown = 
    FFlagAXFPSEventStreamAndCounters = 1768027289232  # Unknown = 
    FFlagAXFavoritePillOnItemDetails4 = 1767640165648  # Unknown = 
    FFlagAXFavoritesManagerNavEntry = 1768393673808  # Unknown = 
    FFlagAXFavoritesManagerSdui = 1767525977117  # Bool = false
    FFlagAXFavoritesPillExposureLogging2 = 1767972949960  # Unknown = 
    FFlagAXFetchCartPricingDuringInExperienceExposure = 1767828590480  # Unknown = 
    FFlagAXFetchCatalogPageReturnsPromise = 1767640147677  # Bool = false
    FFlagAXFetchItemDetailsFromAvatarEditorService = 1767640169040  # Unknown = 
    FFlagAXFilterOutShopOnlyItemsOnBulkPurchase2 = 1767828592464  # Unknown = 
    FFlagAXFixAvatarSaveContext = 1768377614480  # Unknown = 
    FFlagAXFixAvatarScreenVR = 1767977106704  # Unknown = 
    FFlagAXFixAvatarScreenVR2 = 1767977081680  # Unknown = 
    FFlagAXFixAvatarsTabPurchaseLogging = 1768393684765  # Bool = false
    FFlagAXFixAverageFPSCasing = 1767860846493  # Bool = false
    FFlagAXFixBadgeStatusConfigOptions = 1767900770573  # Bool = true
    FFlagAXFixBodyScaleReduxUpdates4 = 1767654056528  # Unknown = 
    FFlagAXFixBottomNavCTAHeight = 1767831053776  # Unknown = 
    FFlagAXFixBundleOutfitFetchForShoes = 1767654065245  # Bool = false
    FFlagAXFixBundleRedirectFromCatalogForSlots = 1767650028304  # Unknown = 
    FFlagAXFixBundleVerifiedBadgeInWidgets = 1767650023248  # Unknown = 
    FFlagAXFixCameraManagerInitialization = 1767654057437  # Bool = false
    FFlagAXFixCatalogPageButtonSduiCrash = 1767977098000  # Unknown = 
    FFlagAXFixCatalogRefreshRendering = 1767977073629  # Bool = false
    FFlagAXFixCatalogRefreshRenderingV3 = 1767977087005  # Bool = false
    FFlagAXFixCatalogSearchZoom = 1767640152861  # Bool = false
    FFlagAXFixCatalogTileThumbnailFlash = 1768399090077  # Bool = false
    FFlagAXFixCatalogTileThumbnailFlash3 = 1768393694365  # Bool = false
    FFlagAXFixCheckOnOutfitAssets = 1767654051024  # Unknown = 
    FFlagAXFixClickItemDetailsSurfaceLogging = 1767526236765  # Bool = false
    FFlagAXFixConditionalUseRefSearchBar = 1767650224221  # Bool = true
    FFlagAXFixContextualActionVisibility = 1767977115344  # Unknown = 
    FFlagAXFixContextualActionVisibility2 = 1767977120464  # Unknown = 
    FFlagAXFixContextualMenuScrimSize = 1767526237213  # Bool = false
    FFlagAXFixControlBarSubMenuOverlap = 1767977096912  # Unknown = 
    FFlagAXFixControlBarSubMenuOverlap2 = 1767977106512  # Unknown = 
    FFlagAXFixCustomOutfitNamesDisabled = 1767977079504  # Unknown = 
    FFlagAXFixCycloramaOrphanRemount = 1767640156317  # Bool = false
    FFlagAXFixDataProcessingMilestoneGating = 1767977103824  # Unknown = 
    FFlagAXFixDeselectOutfitInManage = 1767977080272  # Unknown = 
    FFlagAXFixEditorCategoryRenavigation = 1768133834640  # Unknown = 
    FFlagAXFixEmptyCatalogSearchChrome = 1767640164061  # Bool = false
    FFlagAXFixEmptyDictionaryKeysForSaveDict2 = 1767650019165  # Bool = false
    FFlagAXFixEmptyMakeupLooks = 1768393709840  # Unknown = 
    FFlagAXFixFetchOwnedHeadsPaging = 1767423560656  # Unknown = 
    FFlagAXFixGamepadNavigationOnOutfitManagement = 1767640147101  # Bool = false
    FFlagAXFixHandAndArmWidgetApiContext = 1767977059344  # Unknown = 
    FFlagAXFixHydratedWidgetsParams = 1767977077392  # Unknown = 
    FFlagAXFixHydratedWidgetsParams2 = 1767977120976  # Unknown = 
    FFlagAXFixIaBTimedOptionsPopoverFocus = 1767977065680  # Unknown = 
    FFlagAXFixItemDetailsDescriptionSpacing = 1767640161552  # Unknown = 
    FFlagAXFixItemDetailsPurchaseAttribution = 1767977066704  # Unknown = 
    FFlagAXFixLimitedUniqueResale = 1767640166992  # Unknown = 
    FFlagAXFixLookDetailsContextualMenu = 1767977085469  # Bool = false
    FFlagAXFixLookLinkToCustomize = 1768393729488  # Unknown = 
    FFlagAXFixLookPurchaseMissingPurchaseSuccess = 1767643506845  # Bool = false
    FFlagAXFixLookTryOnReturnRemoval = 1768393674832  # Unknown = 
    FFlagAXFixMakeupLookGrantOutfitHoisting = 1767640146960  # Unknown = 
    FFlagAXFixMinMaxPriceFilterError = 1767654049104  # Unknown = 
    FFlagAXFixOpenPurchasePromptForOffersGamepad = 1767977072144  # Unknown = 
    FFlagAXFixOrderFieldUnlayeredItems = 1767654059664  # Unknown = 
    FFlagAXFixOrientationInputBlocking = 1767470838557  # Bool = false
    FFlagAXFixOutfitEquipCheckEmptyArray = 1767640149520  # Unknown = 
    FFlagAXFixPrefetchMarketplaceStartupCrash = 1767977064720  # Unknown = 
    FFlagAXFixProfileQRCodeTryOnFlash = 1767654059024  # Unknown = 
    FFlagAXFixPurchaseAttemptSurfaceLogging = 1767977061200  # Unknown = 
    FFlagAXFixPurchaseSurfaceLogging = 1767526236317  # Bool = false
    FFlagAXFixR6DefaultHeadShape = 1767977076112  # Unknown = 
    FFlagAXFixRecommendedItemCreatorType = 1767977098128  # Unknown = 
    FFlagAXFixRemoveLookOnMySharedAvatars = 1768393688925  # Bool = false
    FFlagAXFixRobuxButtonShowingInFullView = 1767640146384  # Unknown = 
    FFlagAXFixRobuxUpsellSoftLock = 1776067281437  # Bool = false
    FFlagAXFixSaveManagerOnAXExit = 1767654058397  # Bool = false
    FFlagAXFixScrollingCarouselShowRightButton = 1768017176080  # Unknown = 
    FFlagAXFixSduiCatalogRowJump = 1767977112144  # Unknown = 
    FFlagAXFixSduiWidgetTTITileLatencyCallbackIdentity = 1768393686736  # Unknown = 
    FFlagAXFixSearchLandingQuickButtonsOffset = 1767640171165  # Bool = false
    FFlagAXFixSearchPurchaseSurface = 1768150623029  # Bool = false
    FFlagAXFixSeeAllSpacing = 1768393729168  # Unknown = 
    FFlagAXFixSelectedItemIndexBleed = 1767977083152  # Unknown = 
    FFlagAXFixSingleItemPurchaseWidgetLogging = 1767977070416  # Unknown = 
    FFlagAXFixSortFunctionForMakeupTryOn = 1767654058064  # Unknown = 
    FFlagAXFixTabBarOverrideForWrapperPages = 1767831059088  # Unknown = 
    FFlagAXFixTryOnDefaultClothing = 1767654061021  # Bool = false
    FFlagAXFixTryOnHeadShapeThumbnail = 1767640150429  # Bool = false
    FFlagAXFixVRControlBarFlicker = 1767640170845  # Bool = false
    FFlagAXFixWidgetHydrationPermanentPrice = 1767640163165  # Bool = false
    FFlagAXFixWidgetOnlyTabNoItemsFound = 1767977069456  # Unknown = 
    FFlagAXFlagBasedExposureLoggingCatalogPage = 1767977094608  # Unknown = 
    FFlagAXGeneralizeInventoryItemsList = 1768393711197  # Bool = false
    FFlagAXGuardCharacterSpotLightSideAccess = 1767654062493  # Bool = false
    FFlagAXGuardNavStateNil = 1768393683792  # Unknown = 
    FFlagAXGuardNavStateTraversal = 1768393696208  # Unknown = 
    FFlagAXHeadCategoryCombineEnabled4 = 1767650027485  # Bool = false
    FFlagAXHeadCategoryCombineEnabledForAll4 = 1767650027933  # Bool = false
    FFlagAXHeroUnitUIBloxDarkScope = 1767640166160  # Unknown = 
    FFlagAXHideCatalogShortcutsInFullView = 1767900762717  # Bool = true
    FFlagAXHideEmptySponsoredRow = 1767640163869  # Bool = false
    FFlagAXHideHeadAdjustmentForDefaultHead = 1767977059101  # Bool = false
    FFlagAXHideMenuOnScroll = 1767977077213  # Bool = false
    FFlagAXHideMenuOnScroll3 = 1767977084752  # Unknown = 
    FFlagAXHideMenuOnScrollExposureLogging = 1767977107933  # Bool = false
    FFlagAXHideMenuOnScrollExposureLogging3 = 1767977078173  # Bool = true
    FFlagAXHideUnifiedPurchaseFlowSuccessToastMarketplace = 1768393678493  # Bool = false
    FFlagAXImproveSlotBasedEditorPerformance = 1767654052381  # Bool = false
    FFlagAXIncreaseDefaultPeekViewHeight = 1768399097405  # Bool = false
    FFlagAXInspectAndBuyMakeupSupport = 1767640148048  # Unknown = 
    FFlagAXIntervalPerformanceTrackerFPSStandardDeviation = 1767860817757  # Bool = false
    FFlagAXIntervalPerformanceTrackerScrollFrameTime = 1767860847261  # Bool = false
    FFlagAXInventoryDurablesExpiredFilter = 1767977079312  # Unknown = 
    FFlagAXInventoryDurablesSupport = 1768393724368  # Unknown = 
    FFlagAXInventoryDurablesSupport5 = 1768393682256  # Unknown = 
    FFlagAXInventoryIncludeUnavailableItems = 1767640147984  # Unknown = 
    FFlagAXInventoryItemsListImpressionLogging = 1767977084560  # Unknown = 
    FFlagAXItemCardBadgeCheckText = 1767899160080  # Unknown = 
    FFlagAXItemCardComponentsMemo = 1768393679440  # Unknown = 
    FFlagAXItemDetails3DPreviewEnabled = 1767650019472  # Unknown = 
    FFlagAXItemDetails3DPreviewEnabledForAll = 1767650021597  # Bool = false
    FFlagAXItemDetailsIxpExposure = 1768393709712  # Unknown = 
    FFlagAXItemDetailsIxpExposure2 = 1768393710672  # Unknown = 
    FFlagAXItemDetailsPartialAssetInfoFix = 1767640158544  # Unknown = 
    FFlagAXItemInfoRowWrapInfoData = 1768548735136  # Unknown = 
    FFlagAXItemsViewContentSizeBinding = 1768393680208  # Unknown = 
    FFlagAXKeepTryOnsInAvatarEditor = 1767640171677  # Bool = false
    FFlagAXLaunchUnifiedPurchaseFlowMarketplaceAssetBundles = 1768393681757  # Bool = false
    FFlagAXLaunchUnifiedPurchaseFlowMarketplaceLooks = 1768393700189  # Bool = false
    FFlagAXLeaveCatalogToAvatarPromptHandleSubcategoryFilters = 1768393702480  # Unknown = 
    FFlagAXLegacyIXPExposureLogging = 1767470835536  # Unknown = 
    FFlagAXLimitWidgetLoadedItemCount = 1767977071440  # Unknown = 
    FFlagAXLogFacialAnimationOnHeadChange = 1767977073040  # Unknown = 
    FFlagAXLogFacialAnimationOnHeadChange2 = 1767977088656  # Unknown = 
    FFlagAXLogFacialAnimationToggle = 1767977064912  # Unknown = 
    FFlagAXLogFacialAnimationToggle2 = 1767977068048  # Unknown = 
    FFlagAXLogFavoritePillToggle = 1767977069968  # Unknown = 
    FFlagAXLogNilCategoryAndSubcategorySelection = 1767977071312  # Unknown = 
    FFlagAXLookDetailsBottomBarFavoriteLogging = 1768113136584  # Unknown = 
    FFlagAXLookDetailsBottomBarRobux = 1767425607056  # Unknown = 
    FFlagAXLookDetailsChevronSpacing = 1767423906589  # Bool = false
    FFlagAXM41AllCategoriesToTaxonomy = 1767977083920  # Unknown = 
    FFlagAXMISEnableMultiShopping = 1768399093597  # Bool = false
    FFlagAXMISEnableMultiShopping13 = 1768393731869  # Bool = false
    FFlagAXMISEnableMultiShoppingUnifiedEvents = 1768393677213  # Bool = false
    FFlagAXMISEnableMultiShoppingUnifiedEvents2 = 1768393677328  # Unknown = 
    FFlagAXMISFixAccessoryOverLimits = 1767650025808  # Unknown = 
    FFlagAXMISSaveWearFix = 1768393688208  # Unknown = 
    FFlagAXMISSmallUIChanges = 1768393696029  # Bool = false
    FFlagAXMISWithBlackbird = 1768010021328  # Unknown = 
    FFlagAXMISWithOffers = 1768393732381  # Bool = false
    FFlagAXMISWithOffers4 = 1768393734224  # Unknown = 
    FFlagAXMakeSlidersSmoothWithGamepad = 1767640150749  # Bool = false
    FFlagAXMakeupCategoryPositionExperiment = 1768393678224  # Unknown = 
    FFlagAXMakeupCategoryPositionExperimentExposureLogging = 1768393688272  # Unknown = 
    FFlagAXMakeupEquipping = 1767977091984  # Unknown = 
    FFlagAXMakeupFixAvatarLooksTryOn = 1767977109904  # Unknown = 
    FFlagAXMakeupLayeringTooltipFTUX = 1767977066832  # Unknown = 
    FFlagAXMakeupReleaseFTUX = 1767977101712  # Unknown = 
    FFlagAXManageOutfitsCatalogItemCard = 1767977066525  # Bool = false
    FFlagAXMarketplaceLoadingSkeleton = 1767494516181  # Bool = true
    FFlagAXMeTabTopScrim = 1767640167837  # Bool = false
    FFlagAXMigrateAXToGlobalAutofocus = 1768038489040  # Unknown = 
    FFlagAXMigrateAdjustAccessoryViewToFocusNavigation = 1768001940701  # Bool = true
    FFlagAXMigrateAdjustAccessoryViewToFocusNavigation3 = 1767526159888  # Unknown = 
    FFlagAXMigrateAllTabToSdui8 = 1767640149405  # Bool = false
    FFlagAXMigrateAvatarEditorItemCardInputBindingsToFocusNavigation3 = 1767526162333  # Bool = false
    FFlagAXMigrateAvatarEditorPageInputBindings = 1767470837008  # Unknown = 
    FFlagAXMigrateBuilderIcons = 1767977103696  # Unknown = 
    FFlagAXMigrateBuilderIcons2 = 1767977113552  # Unknown = 
    FFlagAXMigrateCatalogPageInputBindings = 1768038514512  # Unknown = 
    FFlagAXMigrateCatalogPageInputBindings2 = 1767470835920  # Unknown = 
    FFlagAXMigrateCatalogResultListNavigationToMVVM = 1767977102672  # Unknown = 
    FFlagAXMigrateCatalogSearchToFocusNavigation = 1767526158800  # Unknown = 
    FFlagAXMigrateCategoryTooltip = 1767977096656  # Unknown = 
    FFlagAXMigrateCategoryTooltip1 = 1767977087504  # Unknown = 
    FFlagAXMigrateEmoteMenuFromRoactGamepad = 1767470840541  # Bool = false
    FFlagAXMigrateEquipSlotsInputBindingsToRoactGamepad = 1768038508304  # Unknown = 
    FFlagAXMigrateEquipSlotsInputBindingsToRoactGamepad2 = 1767470834960  # Unknown = 
    FFlagAXMigrateItemDetailsContainerInputBindingsToFocusNavigation = 1768008145317  # Bool = false
    FFlagAXMigrateItemDetailsInputBindingsToFocusNavigation = 1767470838365  # Bool = false
    FFlagAXMigrateLookDetailsPeekViewToFocusNavigation = 1767526158736  # Unknown = 
    FFlagAXMigrateMainNavHeightToFInt = 1767650023965  # Bool = false
    FFlagAXMigrateMainNavigationInputBindings = 1768393701469  # Bool = false
    FFlagAXMigrateMakeBackButtonToFocusNavigation3 = 1767723044445  # Bool = false
    FFlagAXMigrateManageOutfitPageInputBindingsToFocusNavigation = 1768038473680  # Unknown = 
    FFlagAXMigrateManageOutfitPageInputBindingsToFocusNavigation3 = 1767470838237  # Bool = false
    FFlagAXMigrateMaterialsToAttributes = 1767640165584  # Unknown = 
    FFlagAXMigrateOutfitsToUserInventory = 1767977060432  # Unknown = 
    FFlagAXMigratePeekViewToFocusNavigation = 1768017200016  # Unknown = 
    FFlagAXMigrateProfilePictureEditorEmotesPageToFocusNavigation = 1767526156240  # Unknown = 
    FFlagAXMigratePurchasePromptInteractiveToFocusNavigation2 = 1767526160656  # Unknown = 
    FFlagAXMigrateQuickButtonsToGlobalAutoFocus = 1767470837584  # Unknown = 
    FFlagAXMigrateRecommendedItemsGridToFocusNavigation = 1767526161744  # Unknown = 
    FFlagAXMigrateResellersInputBindingsToRoactGamepad = 1768393702864  # Unknown = 
    FFlagAXMigrateSaveOutfitPromptFromRoactGamepad = 1767526161949  # Bool = false
    FFlagAXMigrateSceneGamepadHandlerInputBindings = 1768038476496  # Unknown = 
    FFlagAXMigrateSceneGamepadHandlerInputBindings2 = 1767470830288  # Unknown = 
    FFlagAXMigrateSearchBarToFocusNavigation = 1767650218960  # Unknown = 
    FFlagAXMigrateSearchLandingPageToFocusNavigation = 1767650224400  # Unknown = 
    FFlagAXMigrateSlotsSignals = 1768393684304  # Unknown = 
    FFlagAXMigrateSystemSliderToFoundationSlider = 1768038487901  # Bool = false
    FFlagAXMigrateSystemSliderToFoundationSlider2 = 1767470839005  # Bool = false
    FFlagAXModeratedItemIconUpdates = 1767977067613  # Bool = true
    FFlagAXModeratedItemIconUpdates2 = 1767977094685  # Bool = false
    FFlagAXModeratedItemsFlow = 1768393706000  # Unknown = 
    FFlagAXModeratedItemsFlow5 = 1768393708112  # Unknown = 
    FFlagAXMoveAllTabToWidgetOnly = 1767977093776  # Unknown = 
    FFlagAXMoveAllTabToWidgetOnly5 = 1767977113104  # Unknown = 
    FFlagAXMoveCatalogFilterToL1Navigation = 1768113122568  # Unknown = 
    FFlagAXMoveCatalogFilterToL1Navigation2 = 1768393692688  # Unknown = 
    FFlagAXMoveCatalogFilterToL1NavigationExposureLogging = 1768393718288  # Unknown = 
    FFlagAXMoveCatalogFilterToL1NavigationExposureLogging3 = 1768393722128  # Unknown = 
    FFlagAXMoveContextualActionButtons = 1767977068944  # Unknown = 
    FFlagAXMutedErrorLoggingForCategorySelection = 1767977071760  # Unknown = 
    FFlagAXNegativeAvatarSequenceFeatures = 1768393715088  # Unknown = 
    FFlagAXNilCheckEquippedAssets = 1767654057296  # Unknown = 
    FFlagAXNilGuardCharacterManager = 1767654060317  # Bool = false
    FFlagAXNoCarouselsOnCatalogWithGamepad = 1767641051997  # Bool = false
    FFlagAXOnlyHydrateVisibleRows = 1767640152989  # Bool = false
    FFlagAXOpaqueMarketplaceTopbar = 1768393706576  # Unknown = 
    FFlagAXOrganicItemPosition = 1767977058640  # Unknown = 
    FFlagAXOutfitDetailsV4_2 = 1767640159005  # Bool = false
    FFlagAXOutfitPageRevamp = 1767977117008  # Unknown = 
    FFlagAXOutfitPageRevamp3 = 1767977086672  # Unknown = 
    FFlagAXPPEReturnToEntrySurface = 1767831060176  # Unknown = 
    FFlagAXPartialPageModalBackgroundShim = 1767977113629  # Bool = true
    FFlagAXPartialPageModalBackgroundShim2 = 1767977086224  # Unknown = 
    FFlagAXPartialPageModalDockedPadding = 1767899171664  # Unknown = 
    FFlagAXPassScreenSizeToWidgetApi = 1767977115536  # Unknown = 
    FFlagAXPassScreenSizeToWidgetApi5 = 1767977123024  # Unknown = 
    FFlagAXPhotoboothAddTropicalRunway = 1768393685328  # Unknown = 
    FFlagAXPhotoboothAnalytics = 1768393711440  # Unknown = 
    FFlagAXPhotoboothBugBashFixes = 1768393728976  # Unknown = 
    FFlagAXPhotoboothBugBashFixes4 = 1768297299733  # Bool = false
    FFlagAXPhotoboothCaptureServiceScreenshot = 1768393672464  # Unknown = 
    FFlagAXPhotoboothExposure = 1768393693520  # Unknown = 
    FFlagAXPhotoboothFunctionality = 1768393676368  # Unknown = 
    FFlagAXPhotoboothFunctionality12 = 1768393727248  # Unknown = 
    FFlagAXPhotoboothIsStandalone = 1768393710237  # Bool = false
    FFlagAXPhotoboothReplacesFullview = 1768393680080  # Unknown = 
    FFlagAXPhotoboothShareModal = 1768393677469  # Bool = false
    FFlagAXPrefetchMarketplaceIXP5 = 1767654065501  # Bool = false
    FFlagAXPrefetchMarketplaceIXPEnabledForAll5 = 1767654065821  # Bool = false
    FFlagAXPrefetchMarketplaceThumbnailsXPExposureV4 = 1767977094160  # Unknown = 
    FFlagAXPrefetchMarketplaceThumbnailsXPV4 = 1767977060688  # Unknown = 
    FFlagAXPrefetchOnlyWithinTTL = 1767977088464  # Unknown = 
    FFlagAXProfileConfigurationMultiFieldApply = 1767640160413  # Bool = false
    FFlagAXProvideAccessoryAdjustmentDefaults = 1768393699408  # Unknown = 
    FFlagAXPurchaseFromQuantityFirst = 1767977078032  # Unknown = 
    FFlagAXRecentlyViewedCounters = 1767650223184  # Unknown = 
    FFlagAXRecentlyViewedSearchItemsEnabled4 = 1767899197085  # Bool = false
    FFlagAXRecentlyViewedSearchItemsEnabledForAll4 = 1767899197533  # Bool = false
    FFlagAXRecentlyViewedSearchItemsPositionTop4 = 1767899195600  # Unknown = 
    FFlagAXRecentlyViewedSearchItemsSaveInCatalog4 = 1767899196752  # Unknown = 
    FFlagAXRecommendedItemsImpressionExposureLogging = 1767977058896  # Unknown = 
    FFlagAXReduceCatalogFilterWidth = 1768393713296  # Unknown = 
    FFlagAXReduceCatalogFilterWidth2 = 1768393710160  # Unknown = 
    FFlagAXRefactorCatalogItemCard = 1768393706781  # Bool = false
    FFlagAXRefactorCatalogItemCard8 = 1768393698589  # Bool = false
    FFlagAXRefactorToggleEquipAsset3 = 1767650026896  # Unknown = 
    FFlagAXRefetchInventoryOnAssetGrant = 1767977070864  # Unknown = 
    FFlagAXRefreshThumbnailsOnLocalSave = 1767654058141  # Bool = false
    FFlagAXRemoveCatalogCategoryIconOnOff3 = 1767425599517  # Bool = false
    FFlagAXRemoveCatalogCategoryNavKey = 1767977086813  # Bool = false
    FFlagAXRemoveCatalogCategoryNavKey4 = 1767977068445  # Bool = false
    FFlagAXRemoveDynamicHeadAssetsFromTryOn = 1767654060637  # Bool = false
    FFlagAXRemoveExpiredItemsFromInventory = 1767977067280  # Unknown = 
    FFlagAXRemoveMemoizeFromAccessoryAdjustmentUtils = 1768393698781  # Bool = false
    FFlagAXRemoveTimedOptionsSalesTypeEnumCheck = 1767977083664  # Unknown = 
    FFlagAXRenameBackToAddToAvatar = 1767977061776  # Unknown = 
    FFlagAXReplaceDefaultHeadAssetId = 1767650017821  # Bool = false
    FFlagAXRepositionLooksFormKeyboard = 1767423189405  # Bool = false
    FFlagAXResetAvatarButton = 1767977095504  # Unknown = 
    FFlagAXResetAvatarButton2 = 1767977116496  # Unknown = 
    FFlagAXResetAvatarButtonExposureLogging = 1767977086352  # Unknown = 
    FFlagAXResetFetchMarketplaceLogic = 1767977077968  # Unknown = 
    FFlagAXResetFetchMarketplaceLogicV2 = 1767977083984  # Unknown = 
    FFlagAXRevertEquippedAssetsAfterLayeringTryOnMakeup = 1768393674512  # Unknown = 
    FFlagAXRootRFYMigration = 1767977094224  # Unknown = 
    FFlagAXRootSlotBasedEditorFlag = 1768393687504  # Unknown = 
    FFlagAXScrollHighlightedTabIntoView = 1767640148829  # Bool = false
    FFlagAXScrollingCarouselWidgetIndexBugfix = 1768009995088  # Unknown = 
    FFlagAXScrollingFramesShouldAnimateOnFocus3 = 1767526159376  # Unknown = 
    FFlagAXSduiCatalogScrollImpressions = 1767977086160  # Unknown = 
    FFlagAXSduiFeedBackToTopAndNavClearance = 1767977059920  # Unknown = 
    FFlagAXSduiWidgetsTTITracking = 1767640149853  # Bool = false
    FFlagAXSearchTrendingChipLogging = 1767977097040  # Unknown = 
    FFlagAXSelectedBorderWrapsBackground = 1767640166237  # Bool = false
    FFlagAXSendImpressionsForCatalogOffersBanner = 1767643488784  # Unknown = 
    FFlagAXSendModelMismatchCounter = 1767641051677  # Bool = false
    FFlagAXSendPurchaseAttempt = 1767901870045  # Bool = false
    FFlagAXSendSessionForEvents = 1767901867920  # Unknown = 
    FFlagAXSendUnifiedEventLogWithInstance = 1767977075088  # Unknown = 
    FFlagAXSendUnifiedEventsInStudio = 1767901870224  # Unknown = 
    FFlagAXSetAngularVelocityIsOptional = 1768393705808  # Unknown = 
    FFlagAXShowBodySuitsCategoryInCatalog = 1767977074384  # Unknown = 
    FFlagAXShowExpiredItemsFilterTooltip = 1767900721805  # Bool = true
    FFlagAXShowFaeUpsell2 = 1767640146320  # Unknown = 
    FFlagAXShowFavoritePillFtuxTooltip = 1768399088733  # Bool = true
    FFlagAXShowHeadAdjustmentInRightControlBar = 1767977081181  # Bool = false
    FFlagAXShowHeadAdjustmentInRightControlBar2 = 1767977099165  # Bool = true
    FFlagAXSilenceGetOutfitMutedError = 1767654064925  # Bool = false
    FFlagAXSimplifyOutfitEquipCheck = 1767650027856  # Unknown = 
    FFlagAXSkipEmotesInAvatarData = 1767977069085  # Bool = false
    FFlagAXSkipMakeupFTUX = 1768548777856  # Unknown = 
    FFlagAXSkyboxFromBackgroundAsset = 1767640155997  # Bool = false
    FFlagAXSlotAvatarThumbnailPromptFix = 1768393685776  # Unknown = 
    FFlagAXSlotBasedEditorCategoryTooltip = 1767977102416  # Unknown = 
    FFlagAXSlotBasedEditorCategoryTooltip2 = 1767977088400  # Unknown = 
    FFlagAXSlotBasedEditorCustomizeFtuxUseMemStorage2 = 1775985147429  # Bool = false
    FFlagAXSlotEditorCategoryMenu = 1767977108304  # Unknown = 
    FFlagAXSlotsDesignUpdatesExposureLogging = 1767977065040  # Unknown = 
    FFlagAXSlotsDesignUpdatesExposureLogging2 = 1767977065744  # Unknown = 
    FFlagAXSlotsDesktopRedesign = 1767977119696  # Unknown = 
    FFlagAXSlotsDesktopRedesign2 = 1767977081040  # Unknown = 
    FFlagAXSlotsDisableScrollAwayOnLandscape = 1768393678429  # Bool = false
    FFlagAXSlotsFixLeftScroll = 1767977069648  # Unknown = 
    FFlagAXSlotsInventoryLoadableGridView = 1768393701520  # Unknown = 
    FFlagAXSlotsPeekViewScrollFix = 1768393721808  # Unknown = 
    FFlagAXSortsBodyTabRecExposureLogging = 1767640168157  # Bool = false
    FFlagAXStandaloneInventoryDurablesSupport = 1768393708176  # Unknown = 
    FFlagAXStrictCheckForPrefetchMarketplace = 1767977100637  # Bool = true
    FFlagAXSubscriptionRefetchEvictStores = 1767640151056  # Unknown = 
    FFlagAXSubscriptionSignalsPlayersServiceOverride = 1775984780744  # Unknown = 
    FFlagAXSupportRentalPurchaseInUnifiedProductPurchaseFlow = 1767831103632  # Unknown = 
    FFlagAXSupportRentalPurchaseInUnifiedProductPurchaseFlow3 = 1767831097680  # Unknown = 
    FFlagAXSupportShoesInItemViewport = 1767650022877  # Bool = false
    FFlagAXSwapOuterwearSubcategoryOrder = 1767650026397  # Bool = false
    FFlagAXTTIAddNumElementsRendered = 1767638308893  # Bool = false
    FFlagAXTTIEditorColdStartDetection = 1767900750925  # Bool = true
    FFlagAXTTIEditorEnableMilestones4 = 1767640162013  # Bool = false
    FFlagAXTallTilesForAdvancedBodiesWidget = 1767977070160  # Unknown = 
    FFlagAXTallTilesForMakeupLooks = 1767977062736  # Unknown = 
    FFlagAXTestDontUseSkeletonOnloadInCatalog = 1767899163613  # Bool = false
    FFlagAXTestSkeletonInCatalog = 1768150620629  # Bool = false
    FFlagAXThumbTypeNilCheck = 1767493172152  # Unknown = 
    FFlagAXTimedOptionsFTUXModalUseMemStorage = 1767977075792  # Unknown = 
    FFlagAXTimedOptionsFtuxUseMemStorage = 1767643504272  # Unknown = 
    FFlagAXTimedOptionsPopoverSkipFocusOnCursor = 1767977078864  # Unknown = 
    FFlagAXTooltipUseMemStorage = 1767899193437  # Bool = false
    FFlagAXTryOnScreenFixes = 1767977109200  # Unknown = 
    FFlagAXTryOnScreenImprovements6 = 1767526167056  # Unknown = 
    FFlagAXTweakSlotsCameraPositioning = 1767650029341  # Bool = false
    FFlagAXUnifiedFilterWidgetLoadedAndUIImpression = 1767901870301  # Bool = false
    FFlagAXUnifiedImpressionsOnThumbnail = 1768399103005  # Bool = false
    FFlagAXUnifiedMarketplaceResultsFetcher = 1768393722768  # Unknown = 
    FFlagAXUnifiedMarketplaceResultsFetcherV3 = 1768393723600  # Unknown = 
    FFlagAXUnifiedPurchaseExtendRentalsFix = 1767977066576  # Unknown = 
    FFlagAXUnifiedPurchasePromptMakeupLooksSaveLookType = 1767977073117  # Bool = true
    FFlagAXUpdateAvatarOnGameLeave = 1767654050525  # Bool = false
    FFlagAXUpdateSlotBasedEditorToastAndPrompts = 1768393717904  # Unknown = 
    FFlagAXUprankBundles = 1767650029917  # Bool = false
    FFlagAXUseFIntForWidgetListInitialNumToRender = 1767641053341  # Bool = false
    FFlagAXUsePreloadingSwitchView = 1767977079248  # Unknown = 
    FFlagAXUseProfileIconEntryPoint = 1768393691344  # Unknown = 
    FFlagAXUseUnifiedLoggingEnums = 1767977061136  # Unknown = 
    FFlagAXUseVirtualizedFeedInWidgetList2 = 1767640152477  # Bool = false
    FFlagAXVirtualizedFeedVerticalPadding = 1767526002269  # Bool = false
    FFlagAXWearTimeListItemUnifiedLogging = 1768399071485  # Bool = true
    FFlagAXWearTimeSupport = 1768010021392  # Unknown = 
    FFlagAXWearTimeSupport3 = 1768009999824  # Unknown = 
    FFlagAXWidgetHeaderTreatEmptyTextAsNil = 1767640162461  # Bool = false
    FFlagAXWrapInspectAndBuyThunksInTasks = 1767899818773  # Bool = false
    FFlagAbuseReportAttributedRBXSystemMessages = 1767583565725  # Bool = true
    FFlagAbuseReportCheckSceneSelectionAvailabilityOnOpen = 1768317803280  # Unknown = 
    FFlagAbuseReportClientVersion = 1768317804304  # Unknown = 
    FFlagAbuseReportDensifyResolvedArrays = 1768317799312  # Unknown = 
    FFlagAbuseReportEnableReportSentPage = 1767410580752  # Unknown = 
    FFlagAbuseReportForwardCustomTagFields = 1768317802709  # Bool = false
    FFlagAbuseReportImproveErrorEvents = 1768317800400  # Unknown = 
    FFlagAbuseReportInExpPlayerListV3 = 1767583574672  # Unknown = 
    FFlagAbuseReportInExpShowConfigLoadingSkeleton = 1768317790288  # Unknown = 
    FFlagAbuseReportInlineAlertStateOutsideReducer = 1768317815376  # Unknown = 
    FFlagAbuseReportInlineTitleDisclosureFocus = 1767583568784  # Unknown = 
    FFlagAbuseReportLinkOpenedAnalytics = 1767583569424  # Unknown = 
    FFlagAbuseReportMenuOpenCloseSignal = 1768317797392  # Unknown = 
    FFlagAbuseReportMenuV2 = 1767724909677  # Bool = true
    FFlagAbuseReportSceneSelectionNextOnFailure = 1768317781584  # Unknown = 
    FFlagAbuseReportSceneSelectionSubmitTracking = 1768317827856  # Unknown = 
    FFlagAbuseReportSelectItemAddId = 1767583570256  # Unknown = 
    FFlagAbuseReportSlideOutgoingInputSink = 1768317836432  # Unknown = 
    FFlagAbuseReportSubmissionTargetV4 = 1767583573712  # Unknown = 
    FFlagAbuseReportTabClearCapturedScreenshotOnCloseFix = 1768317819792  # Unknown = 
    FFlagAbuseReportV2ScrollNavigation = 1768317796752  # Unknown = 
    FFlagAbuseReportVoiceMute = 1767583573136  # Unknown = 
    FFlagAbuseReportingUseProfileFrameThumbnail = 1768317835216  # Unknown = 
    FFlagAccountLockReceiverClosesModal = 1767583574749  # Bool = true
    FFlagAccountSwitchRelaunchFallback = 1767526160413  # Bool = false
    FFlagAccountUnlockAllowMissingUserId = 1767583575645  # Bool = true
    FFlagAddAEGIS2Analytics = 1768017203984  # Unknown = 
    FFlagAddAbilityToDisableIGMScroll = 1767583568080  # Unknown = 
    FFlagAddAbuseReportOffsetForLandscape = 1767526168925  # Bool = false
    FFlagAddApolloClientToExperienceChat = 1768229404304  # Unknown = 
    FFlagAddBackplateSupportToUserTile = 1767583526352  # Unknown = 
    FFlagAddCenterDialogForUnifiedPurchaseModal = 1767831090128  # Unknown = 
    FFlagAddCenterDialogForUnifiedPurchaseModal2 = 1767831090768  # Unknown = 
    FFlagAddCollaborationCoreGatedConnectionError2 = 1768389393424  # Unknown = 
    FFlagAddCommerceErrors = 1767913304605  # Bool = false
    FFlagAddCommunityLockedToCommunityProfile = 1768133841040  # Unknown = 
    FFlagAddContextualPlayabilityConnectionErrors = 1768024101277  # Bool = false
    FFlagAddCursorProviderToPurchasePromptApp = 1767828574288  # Unknown = 
    FFlagAddCursorProviderToPurchasePromptAppV5 = 1767828575440  # Unknown = 
    FFlagAddDefaultFocusNavSelectorsOnBuyPurchasePrompt = 1775985004632  # Unknown = 
    FFlagAddEventsToCommunityProfile = 1767625364016  # Unknown = 
    FFlagAddFetchProductInfoAsACallback = 1767831093456  # Unknown = 
    FFlagAddFontStyleToTextWithTranslation = 1768317801744  # Unknown = 
    FFlagAddFriendsBannersNewUI_IXP = 1768010019728  # Unknown = 
    FFlagAddFriendsBannersNewUI_exp = 1768010018768  # Unknown = 
    FFlagAddFriendsCINewIcon_exp = 1768009995664  # Unknown = 
    FFlagAddFriendsDeprecateUnusedReducers = 1767583390237  # Bool = false
    FFlagAddFriendsIgnoreAllFoundationMenu = 1767583388125  # Bool = false
    FFlagAddFriendsOldIconForChannelsVariant_exp = 1776002194733  # Bool = true
    FFlagAddFriendsPageCapitalization = 1768009996816  # Unknown = 
    FFlagAddFriendsPageFAEUpsell = 1768165554128  # Unknown = 
    FFlagAddFriendsPageFAEUpsell3 = 1767583402256  # Unknown = 
    FFlagAddFriendsPageTrustedFriendRequestSection_v10 = 1767583384464  # Unknown = 
    FFlagAddFriendsPageUpdateAmpRules = 1767583402448  # Unknown = 
    FFlagAddFriendsPresenceStoreMigration = 1768009976784  # Unknown = 
    FFlagAddFriendsPresenceStoreMigration_v4 = 1768010009040  # Unknown = 
    FFlagAddFriendsRefreshRequestOrder = 1767583389789  # Bool = false
    FFlagAddFriendsSessionId = 1768009987088  # Unknown = 
    FFlagAddFriendsUserListEnabled_v2 = 1767583384080  # Unknown = 
    FFlagAddGamepadBumperNavigation3 = 1768027307357  # Bool = false
    FFlagAddIEMProfilePage = 1768133839376  # Unknown = 
    FFlagAddInviteFriendsIntegration = 1767828575005  # Bool = true
    FFlagAddLayoutOrderToSduiSectionHeaderIconComponent = 1767650210576  # Unknown = 
    FFlagAddMapToNineDot = 1767828578589  # Bool = false
    FFlagAddMenuNavigationToggleDialog = 1767526159965  # Bool = false
    FFlagAddMorePhoneUpsellEvents = 1767583558941  # Bool = true
    FFlagAddNewPlayerListFocusNav = 1768132534813  # Bool = false
    FFlagAddNewPlayerListMobileFocusNav = 1776086739408  # Unknown = 
    FFlagAddNewPlayerListMobileFocusNav2 = 1768132535069  # Bool = false
    FFlagAddOnRobloxSubscriptionUpsellSuccessCallbackToUnifiedPurchaseModal = 1767831096336  # Unknown = 
    FFlagAddPeoplePageCardLayout = 1768389372688  # Unknown = 
    FFlagAddPeoplePageCardLayout4 = 1768389402256  # Unknown = 
    FFlagAddPerformanceMetricsToUnifiedPurchaseModal = 1767831092816  # Unknown = 
    FFlagAddPerformanceMetricsToUnifiedPurchaseModal3 = 1767831092944  # Unknown = 
    FFlagAddPlacelaunchDeviceBlock2 = 1768024100816  # Unknown = 
    FFlagAddPlatformNameToProfileHeader = 1768133849616  # Unknown = 
    FFlagAddPreselectedAbuseTypeAnalytics = 1768372146000  # Unknown = 
    FFlagAddPreselectedAbuseTypeAnalytics2 = 1767583570973  # Bool = true
    FFlagAddPriceBelowCurrentlyWearing = 1767625386269  # Bool = true
    FFlagAddPromCounterToKeystoreOps = 1767828588880  # Unknown = 
    FFlagAddPublishAssetPrompt6 = 1767831048848  # Unknown = 
    FFlagAddPurchaseOptionForProvidingBalance = 1767831090320  # Unknown = 
    FFlagAddReasonToEveryLogout = 1767720485712  # Unknown = 
    FFlagAddReportCharacterLimit = 1768405142829  # Bool = false
    FFlagAddSocialLinksToCommunityProfile = 1768133885840  # Unknown = 
    FFlagAddSocialLinksToCommunityProfile_v3 = 1768133882768  # Unknown = 
    FFlagAddStatusIndicatorToBaseRow_v2 = 1767583389456  # Unknown = 
    FFlagAddSwitchTabHintsToIEM = 1767828590800  # Unknown = 
    FFlagAddTakeItDownReportLinkToSurfaces = 1767583573853  # Bool = true
    FFlagAddThumbnailReportToPlayerFeedback = 1767649980381  # Bool = false
    FFlagAddThumbnailSelectorReport = 1768372143568  # Unknown = 
    FFlagAddThumbnailSelectorReport6 = 1767583567248  # Unknown = 
    FFlagAddTimerToBulkPurchaseBuyButton = 1767908735581  # Bool = false
    FFlagAddTopBarScrim = 1768133943901  # Bool = false
    FFlagAddTraversalBackButton699v1 = 1768389406416  # Unknown = 
    FFlagAddTraversalBackButtonAnimation699v1 = 1768389347216  # Unknown = 
    FFlagAddTraversalHistory699v1 = 1768389360016  # Unknown = 
    FFlagAddTraversalHistoryReactMenuButtons = 1768428791445  # Bool = false
    FFlagAddTypesToWidgetItems = 1767977092496  # Unknown = 
    FFlagAddUILessMode = 1767470839965  # Bool = false
    FFlagAddUnderlineToLinksInTextWithTranslation = 1768317781648  # Unknown = 
    FFlagAddUnifiedPurchaseFlowTTIToEDP = 1767831089488  # Unknown = 
    FFlagAddUnifiedPurchaseRobuxUpsellCompletedTelemetry = 1776067315920  # Unknown = 
    FFlagAddUnifiedPurchaseRobuxUpsellCompletedTelemetry2 = 1776067306000  # Unknown = 
    FFlagAddUpsellEntryComponentToAnalytics = 1768017199568  # Unknown = 
    FFlagAddVideoToCommunityProfile = 1768133847312  # Unknown = 
    FFlagAddVideoToCommunityProfile_v7 = 1768133855888  # Unknown = 
    FFlagAddVipOwnerNotPresentConnectionError = 1768024101853  # Bool = false
    FFlagAdjustHorizontalUserListSizeForMobile = 1768024537552  # Unknown = 
    FFlagAdoptStyleTokens = 1768017062301  # Bool = true
    FFlagAdsInteractivityControlsFixStyleLink = 1768060667600  # Unknown = 
    FFlagAgeBasedUXHomepageVerificationBannerGreyButton = 1767583402128  # Unknown = 
    FFlagAgeBasedUXHomepageVerificationBannerLockIcon = 1768032710045  # Bool = false
    FFlagAgreementItemsOrderFixEnabled = 1767473191888  # Unknown = 
    FFlagAllowAmpV2FeatureAccessCall = 1767526240861  # Bool = false
    FFlagAllowCustomUnifiedEventFilter = 1768229586869  # Bool = true
    FFlagAllowDisconnectGuiForOkUnknown = 1767913638869  # Bool = false
    FFlagAllowDisplayingFoundationIconsForDropdown = 1768136656285  # Bool = false
    FFlagAllowNumberLocalizationSigFigParam = 1767548415181  # Bool = false
    FFlagAllowQrEnlargeUniversally = 1768017062429  # Bool = true
    FFlagAlwaysShowGamepadNavigationDialog = 1767913671061  # Bool = false
    FFlagAlwaysShowVRToggleV3 = 1767913336285  # Bool = false
    FFlagAmpGqlPassSuccessfulActions = 1767648596944  # Unknown = 
    FFlagAmpWizardDeepLinkReplaceOnlyWebView = 1767648605789  # Bool = false
    FFlagAndroidPasswordSuggestionExperimentEnrollmentBypass = 1767996972165  # Bool = false
    FFlagAndroidTVExitWithB2 = 1767831061136  # Unknown = 
    FFlagAppChatAnalyticsUseTelemetryService = 1768024542096  # Unknown = 
    FFlagAppChatAutotranslationRespectsExperienceChatSetting = 1768132385808  # Unknown = 
    FFlagAppChatCatchSendMessageSyncError = 1767650013584  # Unknown = 
    FFlagAppChatChannelsGetNewerMessagesWithPrevCursor = 1767641272592  # Unknown = 
    FFlagAppChatChatLandingScreenRenameFixEnabled = 1767583392912  # Unknown = 
    FFlagAppChatContextCardNameLoadingShimmer = 1768132380112  # Unknown = 
    FFlagAppChatConversationLoadingSkeleton = 1768132436240  # Unknown = 
    FFlagAppChatConversationPageSyntheticSystemMessageIxpEnabled = 1768132428624  # Unknown = 
    FFlagAppChatConversationStore = 1767807365685  # Bool = true
    FFlagAppChatCustomConversationListRow = 1767641304797  # Bool = false
    FFlagAppChatDiscloseUpdateSecondVersion = 1767470823261  # Bool = false
    FFlagAppChatDisclosureUpdateEnabled = 1767583536144  # Unknown = 
    FFlagAppChatDomLocatorFoundationMigration = 1767583387856  # Unknown = 
    FFlagAppChatEnableAutotranslation = 1768028334621  # Bool = false
    FFlagAppChatEnableAutotranslation2 = 1767650009616  # Unknown = 
    FFlagAppChatEnableDoubleOptInRC3 = 1767583392144  # Unknown = 
    FFlagAppChatEnableManualTranslation = 1767650011792  # Unknown = 
    FFlagAppChatEnableMessageContextMenu = 1768050304208  # Unknown = 
    FFlagAppChatEnableOSAConversationFetchForFriendsPlaceholdersFix = 1767423905181  # Bool = false
    FFlagAppChatEnableRepliesUIIxpEnabled2 = 1768132384592  # Unknown = 
    FFlagAppChatEnableRootedNavigation2 = 1768017075920  # Unknown = 
    FFlagAppChatEnabledChromeDropdownFtuxTooltip = 1768334968120  # Unknown = 
    FFlagAppChatExcludeStandardizedFieldsFromCounters = 1767641272016  # Unknown = 
    FFlagAppChatFixBackButtonOnRotation = 1768132406032  # Unknown = 
    FFlagAppChatFixPlusBadgeAlignment = 1768132381648  # Unknown = 
    FFlagAppChatFixRootChatBackNavigation = 1767583538000  # Unknown = 
    FFlagAppChatFixRootChatBackNavigationIxpEnabled = 1767641274077  # Bool = false
    FFlagAppChatFriendsTabIxpEnabled = 1768050306640  # Unknown = 
    FFlagAppChatFriendsTabIxpEnabledRC1 = 1768050300240  # Unknown = 
    FFlagAppChatFullPlaintextBeforeGameCards = 1767650016144  # Unknown = 
    FFlagAppChatGamepadSendButtonNav = 1768132439056  # Unknown = 
    FFlagAppChatGlobalSwipeTracking = 1768132429072  # Unknown = 
    FFlagAppChatHidePlayButtonsInExp = 1768050263952  # Unknown = 
    FFlagAppChatIgnoreUnknownThirdPartyChatStatus = 1768050318736  # Unknown = 
    FFlagAppChatInExpSelectChatMembersMobileHeight = 1768050270800  # Unknown = 
    FFlagAppChatInExpToastSnoozeMenuDismissFix = 1768133851344  # Unknown = 
    FFlagAppChatInExperienceEnabledV654NewIcon = 1767583426576  # Unknown = 
    FFlagAppChatInExperienceTabBarAdjustment = 1768017074896  # Unknown = 
    FFlagAppChatInvalidGameLinkCard = 1768050276176  # Unknown = 
    FFlagAppChatIxpScreenExposure = 1768132391632  # Unknown = 
    FFlagAppChatLoadingIndicatorTransparency = 1767641304221  # Bool = false
    FFlagAppChatMessageTTIMilestones = 1768028353501  # Bool = false
    FFlagAppChatMessageTTIMilestones1 = 1767650014480  # Unknown = 
    FFlagAppChatMigrateScrollIntervalTracker2 = 1768050304848  # Unknown = 
    FFlagAppChatMomentShareCard = 1768132409616  # Unknown = 
    FFlagAppChatMomentShareCardNavigation = 1767828592272  # Unknown = 
    FFlagAppChatMomentShareCardUseFoundationImage = 1768050279568  # Unknown = 
    FFlagAppChatMoveMainComponent = 1767424651037  # Bool = false
    FFlagAppChatNativeFoundationCornerRadii = 1768050269456  # Unknown = 
    FFlagAppChatNavigateBackIfOSAUnacknowledged = 1767583393424  # Unknown = 
    FFlagAppChatNewChatFixEnabled = 1767583394320  # Unknown = 
    FFlagAppChatNewChatInputBar = 1768132390288  # Unknown = 
    FFlagAppChatNewChatInputBar2 = 1768132389776  # Unknown = 
    FFlagAppChatNewChatInputBarIxpEnabled = 1768132383632  # Unknown = 
    FFlagAppChatNewSquadJoinButtonLookIconless = 1768132442960  # Unknown = 
    FFlagAppChatNilGuardMessageSort = 1767650010768  # Unknown = 
    FFlagAppChatNilGuardReceivedChatResponse = 1767650015184  # Unknown = 
    FFlagAppChatOnConsoles_Dev = 1768027303120  # Unknown = 
    FFlagAppChatPCMFixBlocking = 1768133839312  # Unknown = 
    FFlagAppChatParticipantDialogGamepadFocus = 1767641273501  # Bool = false
    FFlagAppChatPerfTracking = 1768017039312  # Unknown = 
    FFlagAppChatPerfTracking3 = 1768017097680  # Unknown = 
    FFlagAppChatPresenceStoreMigration = 1768028371997  # Bool = false
    FFlagAppChatPresenceStoreMigration_v1 = 1768047648141  # Bool = false
    FFlagAppChatReactToFaeForOsa = 1768122207845  # Bool = true
    FFlagAppChatRefactorChatMessage = 1768050289296  # Unknown = 
    FFlagAppChatRemoveConversationListDivider = 1768132421328  # Unknown = 
    FFlagAppChatRemoveConversationListDividerIxpEnabled = 1767641310352  # Unknown = 
    FFlagAppChatRemoveDynamicRequires = 1768158632197  # Bool = true
    FFlagAppChatRemoveNotifications = 1767583388048  # Unknown = 
    FFlagAppChatRemoveToggleChatPaused = 1767583390672  # Unknown = 
    FFlagAppChatRemoveUserProfileTitles2 = 1767725158637  # Bool = true
    FFlagAppChatReplyComposeBarContainer = 1768132390864  # Unknown = 
    FFlagAppChatReplyComposeBarContainer2 = 1768132437008  # Unknown = 
    FFlagAppChatRequestedRoute = 1768017075344  # Unknown = 
    FFlagAppChatResolveShareLinkV2 = 1767650016848  # Unknown = 
    FFlagAppChatSanitizeConversationTitleRichText = 1767583392208  # Unknown = 
    FFlagAppChatScrollFrameTimeTracking = 1768017035856  # Unknown = 
    FFlagAppChatShowOSAOnPageEntry2 = 1767583393808  # Unknown = 
    FFlagAppChatShutdownBeforeLaunch = 1768050306768  # Unknown = 
    FFlagAppChatSignalsMessageStore = 1768028371472  # Unknown = 
    FFlagAppChatSignalsMessageStore5 = 1767641276381  # Bool = false
    FFlagAppChatSignalsReplyStore = 1767641275344  # Unknown = 
    FFlagAppChatSmartSuggestions = 1768132384656  # Unknown = 
    FFlagAppChatSquadButtonColorUpdate = 1768132442832  # Unknown = 
    FFlagAppChatSquadButtonColorUpdateIxpEnabled = 1768132409552  # Unknown = 
    FFlagAppChatSquadButtonColorVariantB = 1768132392720  # Unknown = 
    FFlagAppChatSquadButtonHideGamepadIconOnTvRemote = 1768132403472  # Unknown = 
    FFlagAppChatSquadJoinButtonU13OSA = 1768181167824  # Unknown = 
    FFlagAppChatTimestampInSubtitle = 1768463690005  # Bool = false
    FFlagAppChatTimestampInSubtitleIxpEnabled = 1768297714181  # Bool = false
    FFlagAppChatTopBarConfigDriven = 1768028350749  # Bool = false
    FFlagAppChatTopBarConfigDrivenV6 = 1767641275421  # Bool = false
    FFlagAppChatTopBarSignalsStore = 1768028370525  # Bool = false
    FFlagAppChatTopBarSignalsStoreV2 = 1767641275101  # Bool = false
    FFlagAppChatUnreadMessageCountStore = 1767643510173  # Bool = false
    FFlagAppChatUseNewConversationRow = 1767641304592  # Unknown = 
    FFlagAppChatUseProfileFrameThumbnail = 1768132409232  # Unknown = 
    FFlagAppChatUseSwipeForReplies = 1768050326928  # Unknown = 
    FFlagAppChatUseSwipeForReplies2 = 1768050284368  # Unknown = 
    FFlagAppChatUseSymmetricSwipe = 1767977291277  # Bool = false
    FFlagAppChatUseTextBoxTextOnSend = 1768132441744  # Unknown = 
    FFlagAppChatUseUltimateListConversationList = 1767641303504  # Unknown = 
    FFlagAppContainerReadyToRender = 1768005275600  # Unknown = 
    FFlagAppDebugPanel = 1767831067280  # Unknown = 
    FFlagAppDebugTagAnnotation = 1767831067600  # Unknown = 
    FFlagAppFocusWrapperRefactor = 1768458315792  # Unknown = 
    FFlagAppHeaderBarUseSizeFull = 1768181140432  # Unknown = 
    FFlagAppIaHomeOmniFeedFix = 1767723045200  # Unknown = 
    FFlagAppIaHomeSubTab = 1767828559312  # Unknown = 
    FFlagAppIaHomeSubTabAnalytics = 1767828602640  # Unknown = 
    FFlagAppIaHomeSubTabScrollAwayFull = 1767828560464  # Unknown = 
    FFlagAppIaScopedScrollAway = 1767828565584  # Unknown = 
    FFlagAppIaScrollAway = 1767828581328  # Unknown = 
    FFlagAppIaScrollAway9 = 1767828557968  # Unknown = 
    FFlagAppIaScrollAwayDisableChat = 1767654047709  # Bool = false
    FFlagAppIaScrollAwayFixSocial = 1767828605712  # Unknown = 
    FFlagAppIaScrollAwayGuac = 1767828609552  # Unknown = 
    FFlagAppIaScrollAwayIgnoreHorizontal = 1768017200336  # Unknown = 
    FFlagAppIaScrollAwayPinHeader = 1767828590928  # Unknown = 
    FFlagAppIaStatusBar = 1767828589968  # Unknown = 
    FFlagAppIaStatusBar3 = 1767828561360  # Unknown = 
    FFlagAppNavBarFooterVisibleWithoutScrollAway = 1768017181917  # Bool = false
    FFlagAppNavBarGateFooterVisibleOnPlacement = 1768017177053  # Bool = false
    FFlagAppNavBarPerItemThemeOverride2 = 1767831073360  # Unknown = 
    FFlagAppNavDeviceTier = 1768017196509  # Bool = false
    FFlagAppNavLabelScaling = 1767828582992  # Unknown = 
    FFlagAppNavMyStatsTab3 = 1767831058640  # Unknown = 
    FFlagAppNavTelemetryLogger = 1767828581648  # Unknown = 
    FFlagApplyLaunchContextForNewAccountSwitches = 1767720508368  # Unknown = 
    FFlagApplyResolutionScale = 1767470834397  # Bool = false
    FFlagArgoEnableMoments = 1767828564112  # Unknown = 
    FFlagArgusTabImpliesFlyout = 1767828555600  # Unknown = 
    FFlagAudioPlayerCanSkipTracks = 1767828597200  # Unknown = 
    FFlagAudioPreviewLua = 1776085394640  # Unknown = 
    FFlagAuthBirthdayBarFoundationColors = 1767526149776  # Unknown = 
    FFlagAuthCollapsingValidatorFoundationInput2 = 1767828611792  # Unknown = 
    FFlagAuthFlowProviderEnabled = 1767470828317  # Bool = false
    FFlagAuthFlowStandaloneEnabled = 1776119647557  # Bool = false
    FFlagAuthFlowStandaloneEnabledDev = 1767470828509  # Bool = false
    FFlagAuthNewModalSchematization = 1767650184016  # Unknown = 
    FFlagAuthValidatorStyleOverrides = 1767828564624  # Unknown = 
    FFlagAuthValidatorStyleOverrides3 = 1767828595664  # Unknown = 
    FFlagAvatarAutocompleteEnabledForAll2 = 1767650229968  # Unknown = 
    FFlagAvatarContextMenuItemsChatButtonRefactor = 1768017071453  # Bool = false
    FFlagAvatarHeadshotIconUseProfileFrameThumbnail = 1767473194704  # Unknown = 
    FFlagAvatarJointUpgradeInUA = 1767831088592  # Unknown = 
    FFlagAvatarJointUpgradeInUA3 = 1767805909008  # Unknown = 
    FFlagAvatarPreviewerDisambiguationMenuModal = 1767423602973  # Bool = true
    FFlagAvatarSwitcherAccurateAvatarWarning = 1767977070032  # Unknown = 
    FFlagAvatarSwitcherCounters = 1767977086096  # Unknown = 
    FFlagAvatarSwitcherExpiredItemsWarning = 1767977100829  # Bool = false
    FFlagAvatarSwitcherMakeupSupport = 1768126122760  # Unknown = 
    FFlagAvatarSwitcherUiFixes = 1767977071056  # Unknown = 
    FFlagAvatarSwitcherUseAvatarInventoryEndpoint = 1767977061648  # Unknown = 
    FFlagAvatarSwitcherWarningLayoutFix = 1767977073808  # Unknown = 
    FFlagBackpackResponsiveUnits = 1767831083856  # Unknown = 
    FFlagBadgeVisibilitySettingEnabled = 1768010003216  # Unknown = 
    FFlagBadgeVisibilitySettingEnabled_v3 = 1768010018896  # Unknown = 
    FFlagBasedExposureLoggingCatalogPage = 1767977096144  # Unknown = 
    FFlagBatchVoiceParticipantsUpdates = 1767645292317  # Bool = false
    FFlagBehaviorCollectionControlEnabled = 1768297324957  # Bool = true
    FFlagBlackbirdRequiresIAP = 1768027262928  # Unknown = 
    FFlagBlackbirdUpdateStringFlyoutMenu = 1768027268432  # Unknown = 
    FFlagBlackbirdUpsellGateResale = 1767897041693  # Bool = false
    FFlagBlackbirdUpsellGateResaleAndTimedOption = 1767897040477  # Bool = false
    FFlagBlackbirdUpsellGateTimedOption = 1767897041245  # Bool = false
    FFlagBlackbirdUpsellProd2 = 1767828618192  # Unknown = 
    FFlagBlackbirdUpsellVersion = 1767828587024  # Unknown = 
    FFlagBlendedSerpUserPresenceInLineEnabled = 1768133863440  # Unknown = 
    FFlagBlockEDPClickthrough = 1767583527069  # Bool = true
    FFlagBlockingConsolePreparePaymentCheck = 1768125837533  # Bool = false
    FFlagBlockingUtilityClearUnblockedFromBlockedList = 1767645289053  # Bool = false
    FFlagBlockingUtilityRefireOnReplace = 1767645289373  # Bool = false
    FFlagBoldBlackbirdUpsellBannerStroke = 1767643493661  # Bool = false
    FFlagBoldSearchListPickerSuggestions2 = 1767650227600  # Unknown = 
    FFlagBuildAudiencePublishPrompt = 1768135746637  # Bool = false
    FFlagBuildBackButtonChevron = 1768135777141  # Bool = true
    FFlagBuildDesktopReadiness = 1768134541373  # Bool = false
    FFlagBuildExperienceAskForLogsSeverityRetention = 1768139816477  # Bool = false
    FFlagBuildExperienceAssetLibrary = 1768139835293  # Bool = false
    FFlagBuildExperienceBuyRobuxContext = 1768139837072  # Unknown = 
    FFlagBuildExperienceChatHistoryLoadingSkeleton = 1768139819229  # Bool = false
    FFlagBuildExperienceChatHistoryPrefetch = 1768139817373  # Bool = false
    FFlagBuildExperienceClientDataModelTools2 = 1767831060752  # Unknown = 
    FFlagBuildExperienceConfigurableProductionTemplatePlaceId = 1768139817949  # Bool = false
    FFlagBuildExperienceCopyChatMessages = 1768139827485  # Bool = false
    FFlagBuildExperienceCreatorCreditUsageBadge = 1768139800797  # Bool = false
    FFlagBuildExperienceDontAskAgainPushUpsell = 1768139833437  # Bool = false
    FFlagBuildExperienceExcludeUserWaitFromTurnDuration = 1768139826781  # Bool = false
    FFlagBuildExperienceFixChatBottomLock = 1768139812765  # Bool = false
    FFlagBuildExperienceFixChatComposerInitialSendState = 1768139807965  # Bool = false
    FFlagBuildExperienceMyCreationsUseAudiences = 1768139839248  # Unknown = 
    FFlagBuildExperienceMyCreationsUseUniverseList = 1768139840605  # Bool = false
    FFlagBuildExperiencePersistPlaytestLogs = 1768139813725  # Bool = false
    FFlagBuildExperiencePrivateInvites = 1768139799325  # Bool = false
    FFlagBuildExperienceRichTextUserMessages = 1768139830813  # Bool = false
    FFlagBuildExperienceSecondActivateAfterSetAudiences = 1768139842000  # Unknown = 
    FFlagBuildExperienceShareUseUniverseSummary = 1767831066512  # Unknown = 
    FFlagBuildExperienceShowThinkingBeforeUniverseCreation = 1768139814237  # Bool = false
    FFlagBuildExperienceSinglePlaytestCard = 1768139803933  # Bool = false
    FFlagBuildExperienceStableMyCreationsListItems = 1775971671248  # Unknown = 
    FFlagBuildExperienceStableMyCreationsListItems2 = 1768139842269  # Bool = false
    FFlagBuildExperienceToolResultFailureRecovery = 1768139809245  # Bool = false
    FFlagBuildExperienceTooltipsLightDismiss = 1768136668381  # Bool = false
    FFlagBuildExperienceUseCommonTextArea = 1768139808797  # Bool = false
    FFlagBuildExperienceUseFoundationSheet = 1768136681552  # Unknown = 
    FFlagBuildExperienceUserMessageHapticFeedback = 1768139831709  # Bool = false
    FFlagBuildLocalization = 1767831065488  # Unknown = 
    FFlagBuildNoPublishOnRevert = 1768139786333  # Bool = false
    FFlagBuildPublishAccountTooNewError = 1768132382877  # Bool = false
    FFlagBuildRehydrateOnPublish = 1768139838224  # Unknown = 
    FFlagBuildTabBetweenMeAndChat = 1767473196496  # Unknown = 
    FFlagBuilderSansNavbarFlagSize = 1767654069328  # Unknown = 
    FFlagBulkPurchaseCloseOnEscape = 1767908727325  # Bool = false
    FFlagBulkPurchaseEnablePurchaseOptions = 1767908736208  # Unknown = 
    FFlagBulkPurchaseHandleMissingFulfillmentGroupsKey = 1767908740944  # Unknown = 
    FFlagBulkPurchaseUsesPurchaseOptionDiscount = 1767908741853  # Bool = false
    FFlagBypassKeystoreLoginIxpV2 = 1767828615696  # Unknown = 
    FFlagCIDeeplinkEnabledForAll = 1768133825552  # Unknown = 
    FFlagCTAChangeMorePageFlyoutButtonText = 1768005289936  # Unknown = 
    FFlagCacheCredentialsProtocolIsAvailable = 1767643514256  # Unknown = 
    FFlagCacheReadParsePolicy = 1768297319440  # Unknown = 
    FFlagCacheShouldShowPushUpsellHideResponse = 1767641314896  # Unknown = 
    FFlagCapturePermissionsPromptFreeMouse = 1768158396717  # Bool = true
    FFlagCaptureServiceRetrieveCapturesSafeguard = 1768126143824  # Unknown = 
    FFlagCapturesAddLegacyVideoRecordingLogging_v2 = 1776085398416  # Unknown = 
    FFlagCapturesDragEdgeOffsetEnabled = 1776085404752  # Unknown = 
    FFlagCapturesEnableDownloadPromptForU13 = 1776085371024  # Unknown = 
    FFlagCapturesFetchUseSharedUtility = 1776085114453  # Bool = false
    FFlagCapturesGalleryDespawnOnMenuClose = 1776085395984  # Unknown = 
    FFlagCapturesLayerExposureLoggingEnabled = 1776085385744  # Unknown = 
    FFlagCapturesPostEnabledForAll = 1768133826256  # Unknown = 
    FFlagCapturesPostEnabledForAll_v4 = 1768133837968  # Unknown = 
    FFlagCapturesPromptShareImageFixEnabled = 1776085422544  # Unknown = 
    FFlagCapturesRecursiveCoreUIRemoval = 1768029423773  # Bool = false
    FFlagCapturesUpdateUsePlayShutterSoundTesting = 1768158652717  # Bool = true
    FFlagCapturesVideoBulkManagerStopGap = 1768126137053  # Bool = false
    FFlagCapturesVideoCaptureTriggerHandlerEnabled = 1776086704912  # Unknown = 
    FFlagCapturesVideoDeleteAsync = 1768132522909  # Bool = false
    FFlagCapturesVideoSupportLegacyVideos = 1768126137501  # Bool = false
    FFlagCarouselUseNewUserTileWithPresenceIcon = 1767628643389  # Bool = false
    FFlagCarouselUserTileUseProfileFrameThumbnail = 1767640198237  # Bool = false
    FFlagCenterShiftLockOverride = 1767913338845  # Bool = false
    FFlagChallengeInterceptorResolveOriginalNetworkImpl = 1767650173648  # Unknown = 
    FFlagChangeSocialGraphLifecycleEvent = 1767828609808  # Unknown = 
    FFlagChangeToggleMicText = 1767913625557  # Bool = false
    FFlagCharacterNameHandlerUserProfileApiEnabledForAll = 1767583421136  # Unknown = 
    FFlagChartsHydrationStreaming2 = 1767526010589  # Bool = false
    FFlagChatIntegrationFixShortcut = 1767913625621  # Bool = false
    FFlagChatLineReportingFocusFixesEnabled = 1767583566877  # Bool = true
    FFlagChatLineReportingGlobalMuteEnabled2 = 1767583567453  # Bool = true
    FFlagChatModeratedMaskRandomLength = 1767583535632  # Unknown = 
    FFlagChatOptimizeCommandProcessing = 1767977080669  # Bool = false
    FFlagChatSnoozeMenuDescriptionFixEnabled = 1768181163472  # Unknown = 
    FFlagChatSummariesSettingEnabled3 = 1767583526557  # Bool = true
    FFlagChatTabHideGroupsLinkOnVR = 1767641314461  # Bool = false
    FFlagChatTranslationForceSetting = 1767913341533  # Bool = false
    FFlagChatTranslationHoldoutEnabled = 1767913340112  # Unknown = 
    FFlagChatTranslationNewDefaults = 1767913341981  # Bool = false
    FFlagChatTranslationSettingEnabled3 = 1767831045712  # Unknown = 
    FFlagChatTranslationShowFTUX = 1768028371088  # Unknown = 
    FFlagChatTranslationWaitForIXP = 1767913341085  # Bool = false
    FFlagChatWindowUseCallbackOptimizations = 1768001191069  # Bool = false
    FFlagCheckCameraAvailabilityBeforePermissions = 1767998338128  # Unknown = 
    FFlagCheckForUpdatePromise2 = 1767831088336  # Unknown = 
    FFlagCheckUniversePlaceBeforeSuspending = 1768133883728  # Unknown = 
    FFlagCheckUserModerationAfterLogin = 1767583561552  # Unknown = 
    FFlagChromeCentralizedConfiguration4 = 1767828583888  # Unknown = 
    FFlagChromeChatGamepadSupportFix = 1767828588240  # Unknown = 
    FFlagChromeDeprecateMRUs = 1767723062173  # Bool = false
    FFlagChromeMusicWindowTopbarReappearsOnGamepad = 1767828589776  # Unknown = 
    FFlagChromeShortcutAddRespawnLeaveToIEM = 1767828560656  # Unknown = 
    FFlagChromeShortcutChatOpenKeyboard = 1767828579984  # Unknown = 
    FFlagChromeShortcutRemoveLeaveOnRespawnPage = 1767828566928  # Unknown = 
    FFlagChromeShortcutRemoveRespawnOnLeavePage = 1767828554576  # Unknown = 
    FFlagChromeWindowSignalConstraintsToggle = 1767526167568  # Unknown = 
    FFlagCiDeprecateFindFriendsModal = 1768010016029  # Bool = false
    FFlagCleanUpAXAlternativeLandingPageIXP = 1767654063837  # Bool = false
    FFlagClearPolicyOnLogout = 1768297319632  # Unknown = 
    FFlagClearProductInfoCachesOnPriceChanged = 1776067322960  # Unknown = 
    FFlagClearUserFromRecentVoiceDataOnLeave = 1767645290717  # Bool = false
    FFlagClientErrorAdditionalArgs = 1768387517789  # Bool = false
    FFlagClientToastNotificationsRedirect4 = 1768133930320  # Unknown = 
    FFlagCloseBadgeSheetOnAbuseReport2 = 1768005252688  # Unknown = 
    FFlagCloseFavoritePromptWithB = 1767901833117  # Bool = false
    FFlagCollectiblesCatalogFollowUpForSaleLocation = 1767650031888  # Unknown = 
    FFlagCollectionViewMathChanges = 1767525997520  # Unknown = 
    FFlagCommunitiesUseVisualConfigUtil2 = 1768458316688  # Unknown = 
    FFlagCompleteFlowInStudioAccept = 1768125853661  # Bool = false
    FFlagConfirmationButtonsUseGreyButtons = 1767913319957  # Bool = false
    FFlagConnectionAmpParentalApprovalUpsell = 1768005302160  # Unknown = 
    FFlagConnectionAmpUpsellOnLeave = 1768005283344  # Unknown = 
    FFlagConnectionChannelsTileSize = 1767583401872  # Unknown = 
    FFlagConnectionEnableAutoReconnect = 1768024098525  # Bool = false
    FFlagConnectionManagementChips_V3 = 1767583528157  # Bool = true
    FFlagConnectionRemoveLoadingTimeout = 1767807214493  # Bool = false
    FFlagConnectionUpsellAnalytics = 1768005268816  # Unknown = 
    FFlagConnectionsHubLayerExposure = 1767725048877  # Bool = false
    FFlagConnectionsToFriendsRename = 1768010014416  # Unknown = 
    FFlagConnectionsToFriendsRename1 = 1768010004496  # Unknown = 
    FFlagConnectionsToFriendsRenameP1_v1 = 1768009980253  # Bool = false
    FFlagConsoleApplyTokenizationEdp = 1767470834141  # Bool = false
    FFlagConsoleChatUseChromeFocusUtils = 1767828571088  # Unknown = 
    FFlagConsoleCloseAffordanceFix = 1768017062557  # Bool = true
    FFlagConsoleVoiceIXPEnabled = 1767645288976  # Unknown = 
    FFlagContactImportButtonsExperimentEnabled = 1768181177616  # Unknown = 
    FFlagContactImporterIXPCleanup = 1768009984784  # Unknown = 
    FFlagContactsListEmojiSorting = 1768181181072  # Unknown = 
    FFlagContactsListEmojiSortingIXP = 1767625332016  # Unknown = 
    FFlagContactsListEmojiSortingIxpEnabled = 1768181182288  # Unknown = 
    FFlagContactsListEntryUpdatedTruncationFix = 1768179260240  # Unknown = 
    FFlagContentFeedEnableReactions = 1768133857360  # Unknown = 
    FFlagCoreMicManagerRefactor = 1767645296848  # Unknown = 
    FFlagCoreScriptBacktraceRepeatedErrorRateLimiting = 1768005271261  # Bool = false
    FFlagCoreScriptShowTeleportPrompt = 1767913638997  # Bool = false
    FFlagCoreScriptsProfilerTelemetryContext = 1767831052368  # Unknown = 
    FFlagCoreUiMigrateUIBloxToFoundation = 1767831058320  # Unknown = 
    FFlagCoreUiMigrateUIBloxToFoundation2 = 1767831057552  # Unknown = 
    FFlagCreateConnectionsHub_v6 = 1767583395152  # Unknown = 
    FFlagCreateMomentsToast = 1768438457104  # Unknown = 
    FFlagCreateMomentsToast_v3 = 1768296712597  # Bool = false
    FFlagCreatorAgentChatFilterTerminalClientTools = 1768136671389  # Bool = false
    FFlagCreatorAgentChatParseDirectPublishVersion = 1767831066064  # Unknown = 
    FFlagCreatorAgentChatStrictAskUserToolName = 1768136672285  # Bool = false
    FFlagCreatorSubtitleNavigationIXPEnabled = 1767628369245  # Bool = false
    FFlagCrossPlayActuallyResetErrorStates = 1767473195357  # Bool = false
    FFlagCurrencyTransferCenterRobuxIcon = 1767908745552  # Unknown = 
    FFlagCurrencyTransferDeepLinkValidateSender = 1767583430813  # Bool = false
    FFlagCurrencyTransferFixDesktopInput = 1767908755549  # Bool = false
    FFlagCurrencyTransferFixHeaderTouchPadding = 1767908749584  # Unknown = 
    FFlagCurrencyTransferFixTextBoxInput = 1767908749456  # Unknown = 
    FFlagCurrencyTransferFlowUIImprovementFix = 1767908750608  # Unknown = 
    FFlagCurrencyTransferReceiveLimitExceededError = 1767908758416  # Unknown = 
    FFlagCurrencyTransferSignalRecipientOnComplete = 1767908762973  # Bool = false
    FFlagCurrencyTransferSuccessModal = 1767908768797  # Bool = false
    FFlagCurrencyTransferUseAmpWizardContainerForInApp = 1767908764432  # Unknown = 
    FFlagCurrencyTransferUseBackendTransferLimitsV1 = 1767908756061  # Bool = false
    FFlagCurrencyTransferUseProfileFrameThumbnail = 1767908751312  # Unknown = 
    FFlagCurrencyTransferUseRoactNetworking = 1767908769437  # Bool = false
    FFlagDSAConsequenceTransparency = 1768458294224  # Unknown = 
    FFlagDSAIllegalContentReporting2 = 1768458320464  # Unknown = 
    FFlagDSALuaGeoGateBEDUIDevMode = 1768458314256  # Unknown = 
    FFlagDSAVRSkipFrontendGeoCheck = 1768458294672  # Unknown = 
    FFlagDeactivateAudioDeviceOnVoiceLeave = 1767645296989  # Bool = false
    FFlagDebounceVoiceSelectorIndexChange = 1767913340957  # Bool = false
    FFlagDebugAEGIS1AppChatBanner = 1767650017629  # Bool = false
    FFlagDebugAPPEXP4747B = 1768029424029  # Bool = false
    FFlagDebugAlwaysShowDisableCameraToast = 1767913329872  # Unknown = 
    FFlagDebugAlwaysShowSystemTrayModal = 1767828560144  # Unknown = 
    FFlagDebugAppChat = 1768050289552  # Unknown = 
    FFlagDebugAppChatDisplayOnJoin = 1767807381077  # Bool = true
    FFlagDebugAppChatEnableDomLocators = 1767583387984  # Unknown = 
    FFlagDebugAppChatFae = 1767650017501  # Bool = false
    FFlagDebugCrossPlaySystemUi = 1768297280093  # Bool = false
    FFlagDebugDefaultChannelStartMuted = 1767899838544  # Unknown = 
    FFlagDebugEnableChromeOnUnsupportedDevices = 1767978555344  # Unknown = 
    FFlagDebugEnableErrorStringTesting = 1768024095184  # Unknown = 
    FFlagDebugEnableImageLoadObserver = 1767723051421  # Bool = false
    FFlagDebugEnableImpressionsVisualizer = 1767640198813  # Bool = false
    FFlagDebugEnablePageLoadTrackerVisualizer = 1767470841117  # Bool = false
    FFlagDebugEnablePioneerUX = 1767828584272  # Unknown = 
    FFlagDebugEnableUnibarDummyIntegrations = 1767828580944  # Unknown = 
    FFlagDebugEnableVRFTUXExperienceInStudio = 1768162816528  # Unknown = 
    FFlagDebugExpChat = 1767899841245  # Bool = false
    FFlagDebugExpChatAlwaysRunTCS = 1768133828240  # Unknown = 
    FFlagDebugExpChatPerf = 1768028369565  # Bool = false
    FFlagDebugForceConsoleSafeInsets = 1768027296848  # Unknown = 
    FFlagDebugForceEnableChatButtonOn = 1768028368592  # Unknown = 
    FFlagDebugForceShowIllegalContentReportingUI = 1768297326877  # Bool = true
    FFlagDebugFriendsChat = 1768133843229  # Bool = false
    FFlagDebugImmersionModeNonVR = 1767899816080  # Unknown = 
    FFlagDebugInlineLayout = 1768422348349  # Bool = false
    FFlagDebugLuaAppAlwaysUseGamepad = 1768458345936  # Unknown = 
    FFlagDebugLuaAppEnableScale = 1767989379229  # Bool = false
    FFlagDebugLuaAppEnableTokenScale = 1767977250832  # Unknown = 
    FFlagDebugLuaAppThrowErrorInStarterScript = 1767650186512  # Unknown = 
    FFlagDebugLuaAppValidateProps = 1767470802397  # Bool = false
    FFlagDebugLuaAppsUseDarkTheme = 1767583607133  # Bool = false
    FFlagDebugLuaArgCheck = 1767583608848  # Unknown = 
    FFlagDebugMessageProfiling = 1768001177821  # Bool = false
    FFlagDebugMusicSampleSounds = 1776050383760  # Unknown = 
    FFlagDebugMyStatsExperienceAgentSpec = 1768136668560  # Unknown = 
    FFlagDebugMyStatsExperienceStats = 1768136680221  # Bool = false
    FFlagDebugOverrideCaptureControlsVideoGuacPolicy = 1776085383440  # Unknown = 
    FFlagDebugPrintIntervalPerformanceTrackerResults = 1767860855197  # Bool = false
    FFlagDebugReactSchedulingEnableErrorEvents = 1768393676496  # Unknown = 
    FFlagDebugRomarkAudioPermissionsBypass = 1768297275088  # Unknown = 
    FFlagDebugScreenSizeUseDisplayStore = 1767650010704  # Unknown = 
    FFlagDebugSelfViewPerfBenchmark = 1768133941712  # Unknown = 
    FFlagDebugShowAccountSecurityPromptBanner = 1767650217872  # Unknown = 
    FFlagDebugShowAudioDeviceInputDebuggerV2 = 1768133827792  # Unknown = 
    FFlagDebugShowSiteMessageBanner = 1767650222992  # Unknown = 
    FFlagDebugSimulateConnectDisconnect = 1768001211920  # Unknown = 
    FFlagDebugSkipSeamlessVoiceAPICheck = 1767900736413  # Bool = true
    FFlagDebugSkipVoicePermissionCheck = 1767900752717  # Bool = true
    FFlagDebugSquadLogsEnabled = 1767583396176  # Unknown = 
    FFlagDebugTCUpsellModalEnabled_DEV = 1767583392080  # Unknown = 
    FFlagDebugTimeToInteractiveTracker = 1767972945672  # Unknown = 
    FFlagDebugUnfilteredThreads = 1768133820688  # Unknown = 
    FFlagDebugUnmuteLuaErrors = 1767470823645  # Bool = false
    FFlagDebugUseLegacyCrossPlayApi = 1768297285392  # Unknown = 
    FFlagDebugVRModeInStudio = 1767583423120  # Unknown = 
    FFlagDebugVoiceChatMicPermissionCliBypass = 1767645297488  # Unknown = 
    FFlagDefaultChannelEnableDefaultVoice = 1767899840464  # Unknown = 
    FFlagDefaultKidsToDarkTheme = 1767831074448  # Unknown = 
    FFlagDefaultKidsToDarkTheme2 = 1767831074576  # Unknown = 
    FFlagDeferPlayerInfoRequests = 1768136660509  # Bool = false
    FFlagDeferProgrammaticChange = 1767913340445  # Bool = false
    FFlagDeprecateNavigateToUserInfoJoinable = 1767650182736  # Unknown = 
    FFlagDeprecatePeopleListContextualMenu = 1767900774077  # Bool = true
    FFlagDesktopGameJoinCardUIImprovements = 1767583527709  # Bool = true
    FFlagDetailsPageLayoutSeedContainerSize = 1767525980432  # Unknown = 
    FFlagDevClosedStartupSequence = 1767470803101  # Bool = false
    FFlagDevConsoleAdminSeesDevTabs = 1768133911184  # Unknown = 
    FFlagDevConsoleDownArrowIconFix = 1767911125520  # Unknown = 
    FFlagDevConsoleDropdownFlipFix = 1768133889245  # Bool = false
    FFlagDevConsoleDropdownMultiSelect = 1768133889501  # Bool = false
    FFlagDevConsoleFixTimestampDST = 1768132572125  # Bool = false
    FFlagDevConsoleMemoryTrackingAlert = 1768133892893  # Bool = false
    FFlagDevConsoleMicroProfilerFixAutoTextClear = 1768133898909  # Bool = false
    FFlagDevConsoleMicroProfilerImproveWording = 1768133897744  # Unknown = 
    FFlagDevConsoleMicroProfilerNewLayout = 1768133902173  # Bool = false
    FFlagDevConsoleMpEnableOpenDumpsFolderButton = 1768133900701  # Bool = false
    FFlagDevConsoleRequestOrchestratorTab2 = 1768133914704  # Unknown = 
    FFlagDevConsoleStartDataOnMount = 1768133886301  # Bool = false
    FFlagDevFrameworkMoveEditTree = 1767423603293  # Bool = true
    FFlagDifferentiateAddAuthMethodPasskeyFlow = 1767650172368  # Unknown = 
    FFlagDifferentiateSharingBaseOnPlatform = 1767913311837  # Bool = false
    FFlagDifferentiateVoiceSelectorSystemAndUser = 1767913340189  # Bool = false
    FFlagDisableAppShortcutBarAndroidTV = 1768017084880  # Unknown = 
    FFlagDisableAutocorrectSocialUserSearch = 1768165603152  # Unknown = 
    FFlagDisableAutocorrectSocialUserSearch_v2 = 1767583425296  # Unknown = 
    FFlagDisableBlockAndReport = 1767583390160  # Unknown = 
    FFlagDisableCDLQrCodeForMaquettes = 1768001931637  # Bool = false
    FFlagDisableCameraOnLowSpecDevices2 = 1767913332829  # Bool = false
    FFlagDisableCameraOnLowspecAndroidCalls = 1767899841872  # Unknown = 
    FFlagDisableCameraOnSelfieViewForLowspecDevices = 1768133938960  # Unknown = 
    FFlagDisableConsentModalForExistingUsers = 1767900765661  # Bool = true
    FFlagDisableCopyUsernameOnConsole = 1767583383952  # Unknown = 
    FFlagDisableCorescriptBacktraceReporting = 1768005280592  # Unknown = 
    FFlagDisableEditProfileForVRV2 = 1768458326416  # Unknown = 
    FFlagDisableFeedbackSoothsayerCheck = 1767913346013  # Bool = false
    FFlagDisableGoogleAnalyticsErrorReporting = 1767470827357  # Bool = false
    FFlagDisableHomePageUpsellCardFeedItem = 1768458295184  # Unknown = 
    FFlagDisableLeaveToastInStudio = 1767986626621  # Bool = false
    FFlagDisableLegacyChatSimpleUnreadMessageCount = 1767828556829  # Bool = true
    FFlagDisableListenToSessionTerminalStatus = 1767650171472  # Unknown = 
    FFlagDisableLuobuWarningToast = 1767831050000  # Unknown = 
    FFlagDisableMemStorageServicePasswordEvent = 1767828560272  # Unknown = 
    FFlagDisableMessageBusUnSubscribeError = 1767900766029  # Bool = true
    FFlagDisableNonSchematizedInGameRobuxUpsellEvent = 1768125851549  # Bool = false
    FFlagDisablePVUpsellDataConsent = 1767583537501  # Bool = true
    FFlagDisablePermissionPromptDeeplink = 1768001212573  # Bool = false
    FFlagDisablePlayerListDisplayCloseBtn = 1768136655056  # Unknown = 
    FFlagDisablePurchasePromptFunctionForMaquettes = 1767897044317  # Bool = false
    FFlagDisableReactSchedulingAvgMaxMsStats = 1767972995024  # Unknown = 
    FFlagDisableReactSchedulingTimePctStats = 1767972993680  # Unknown = 
    FFlagDisableRejoinGroupIdDoubleRead = 1767645297565  # Bool = false
    FFlagDisableRobuxUpsell = 1776067328976  # Unknown = 
    FFlagDisableVerifyPhoneViewOnSuccess = 1768389387421  # Bool = false
    FFlagDisableWebViewSupportInStudio = 1768297284880  # Unknown = 
    FFlagDisallowStickyShortcutBarOnNotLoggedIn = 1768017098576  # Unknown = 
    FFlagDisconnectToastClientRewrite = 1767583536669  # Bool = true
    FFlagDiscountInfoForSubscriptionPurchaseModalLua2 = 1767828602960  # Unknown = 
    FFlagDispatchHybridWebviewWithBypassNavigationLock = 1767650170704  # Unknown = 
    FFlagDisplayChannelNameOnErrorPrompt = 1768024093213  # Bool = false
    FFlagDisplayCollectiblesIcon = 1767899806109  # Bool = false
    FFlagDisplayServerChannel = 1767526164701  # Bool = false
    FFlagDontAssertOnUserIDInCaptureMetadata = 1768126142109  # Bool = false
    FFlagDontUseCrossPlayGlobalEffect = 1768027272336  # Unknown = 
    FFlagDrawerScrimCanBeModal = 1767831071005  # Bool = false
    FFlagDropUnroutableMultiReportOptions = 1767583565520  # Unknown = 
    FFlagDynamicHeadsMigration = 1767977083280  # Unknown = 
    FFlagDynamicHeadsMigration7 = 1767977113680  # Unknown = 
    FFlagEDPTTITrackingEnabled = 1767649972496  # Unknown = 
    FFlagEarlierFetchTimeForFriendsCarousel_v1 = 1768181170768  # Unknown = 
    FFlagEasierUnmuting = 1768399802256  # Unknown = 
    FFlagEasierUnmutingTCS5 = 1768399806032  # Unknown = 
    FFlagEasierUnmutingVoiceParticipantsMutedReducer = 1768038205533  # Bool = false
    FFlagEditProfileBackgroundEnabled = 1768133824144  # Unknown = 
    FFlagEditProfileFramesEnabled = 1768027263189  # Bool = false
    FFlagEditProfileImageV2Enabled = 1768133841552  # Unknown = 
    FFlagEditProfileImageV2Telemetry = 1768133848848  # Unknown = 
    FFlagEditProfileLandingV2Enabled = 1767654047197  # Bool = false
    FFlagEditProfileNavigateToAvatar = 1767654044445  # Bool = false
    FFlagEditProfilePPEStartOnEmotesPage = 1767654046877  # Bool = false
    FFlagEditProfileSetupNewExperimentFlow = 1767654041872  # Unknown = 
    FFlagEdpGameLeavePromptsHandlerEnabled = 1768458321168  # Unknown = 
    FFlagEdpPlayerFeedbackCommentsOnly = 1767828583760  # Unknown = 
    FFlagEdpPlayerFeedbackEnabled5 = 1767828558672  # Unknown = 
    FFlagEdpPlayerFeedbackLogIXPExposure2 = 1767828571280  # Unknown = 
    FFlagEdpPlayerFeedbackPromptTitleOnly = 1767828557264  # Unknown = 
    FFlagEmit401WebViewDiagnostics = 1767650177053  # Bool = false
    FFlagEmitPasskeyRegistrationSourceOnFinish = 1767828581008  # Unknown = 
    FFlagEmoteUtilityDefaultMoodFromCharacter = 1776125371024  # Unknown = 
    FFlagEmoteUtilityReportPoseAnimationDownloadFailure = 1776125406480  # Unknown = 
    FFlagEmoteUtilityUseIdleAnimationFallback = 1776125408848  # Unknown = 
    FFlagEmotesStayOpenWithChat = 1768017092240  # Unknown = 
    FFlagEnable2SVRecovery7 = 1767828567376  # Unknown = 
    FFlagEnableAEGIS2AppChatConversationBanner = 1768165576528  # Unknown = 
    FFlagEnableAEGIS2AppChatConversationBannerv699 = 1767583400784  # Unknown = 
    FFlagEnableAEGIS2Upsellv700 = 1767583401296  # Unknown = 
    FFlagEnableARFlowSession = 1775992595088  # Unknown = 
    FFlagEnableAbuseReport10ft2 = 1768027320989  # Bool = true
    FFlagEnableAbuseReportMutedError = 1768027302928  # Unknown = 
    FFlagEnableAbuseReportRevampFeedback = 1767649979933  # Bool = false
    FFlagEnableAbuseReportRevampFlow = 1767611342224  # Unknown = 
    FFlagEnableAbuseReportRevampFlow_1 = 1767583562141  # Bool = true
    FFlagEnableAccessBlockAtAppContainerLevel = 1768458311312  # Unknown = 
    FFlagEnableAccountCarouselEvents1 = 1767828580240  # Unknown = 
    FFlagEnableAccountCountdownLabel = 1767900726221  # Bool = true
    FFlagEnableAccountRecoveryPreAuthDeepLink2 = 1767643520989  # Bool = false
    FFlagEnableAccountSettingsUpsell = 1767654048733  # Bool = false
    FFlagEnableAccountSwitcherAddWithMaxSignedOut = 1767526156752  # Unknown = 
    FFlagEnableAccountSwitcherFoundationDesign9 = 1767526156893  # Bool = false
    FFlagEnableAccountSwitcherIXPTextGatingFix = 1767526155792  # Unknown = 
    FFlagEnableAccountSwitcherManageAccounts6 = 1767526158941  # Bool = false
    FFlagEnableAccountSwitcherSignedOutAccounts5 = 1767526157904  # Unknown = 
    FFlagEnableAccountSwitcherUncheckedBadge = 1767526159517  # Bool = false
    FFlagEnableAccountUnlockDeepLink = 1767583574429  # Bool = true
    FFlagEnableAdConsentAttribution = 1767640199837  # Bool = false
    FFlagEnableAdDataPlayIntentEventIngest = 1767425624221  # Bool = false
    FFlagEnableAdDataReferralEventIngest = 1767423571869  # Bool = true
    FFlagEnableAddAuthMethodPageEmailSignup = 1767720512848  # Unknown = 
    FFlagEnableAddAuthMethodPageEmailSignup5 = 1767720486160  # Unknown = 
    FFlagEnableAddAuthMethodPageFoundationalizeHeader = 1767720521616  # Unknown = 
    FFlagEnableAddAuthMethodPageFoundationalizeHeader2 = 1767720514704  # Unknown = 
    FFlagEnableAddAuthMethodPageFoundationalizeParagraph = 1767720503632  # Unknown = 
    FFlagEnableAddAuthMethodPageFoundationalizeParagraph2 = 1767720509392  # Unknown = 
    FFlagEnableAddAuthMethodPagePasskeyNudgeDirectionalExperiment = 1767720505360  # Unknown = 
    FFlagEnableAddAuthMethodPagePasskeyNudgeDirectionalExperiment10 = 1767720502672  # Unknown = 
    FFlagEnableAffiliateLinksQualifiedSignUpTracking = 1767828602192  # Unknown = 
    FFlagEnableAmpEmailUpsellSupport = 1767648601053  # Bool = false
    FFlagEnableAmpIDVUpsellAnalytics = 1767648607261  # Bool = false
    FFlagEnableAmpIDVUpsellPopOnCompletion = 1767648601629  # Bool = false
    FFlagEnableAmpIDVUpsellSupport = 1767648601309  # Bool = false
    FFlagEnableAmpSubscriptionUpsell = 1767648602077  # Bool = false
    FFlagEnableAmpUpsellGQL = 1767648600861  # Bool = false
    FFlagEnableAmpUpsellLogging = 1767648603101  # Bool = false
    FFlagEnableAmpUpsellWizard = 1767654048989  # Bool = false
    FFlagEnableAmpUserMismatchTelemetry = 1767900759677  # Bool = true
    FFlagEnableAmpV2Wizard = 1767583430493  # Bool = false
    FFlagEnableAmpVPCPrologue = 1767648602333  # Bool = false
    FFlagEnableAmpWizardDeepLink = 1767583400592  # Unknown = 
    FFlagEnableAmpWizardDeepLinkValidateUserId = 1767583400912  # Unknown = 
    FFlagEnableAmpWizardInlineVPCForFAE = 1767648602525  # Bool = false
    FFlagEnableAmpWizardVPCNavigationFix = 1767648602845  # Bool = false
    FFlagEnableAnalyticsForCameraDevicePermissions = 1767998302928  # Unknown = 
    FFlagEnableAndroidAppRatingPromptLua = 1768009961301  # Bool = false
    FFlagEnableAndroidTvAppPolicies = 1768399772240  # Unknown = 
    FFlagEnableAndroidWidgetsLuaIXP2 = 1767526152925  # Bool = false
    FFlagEnableAppAgeSignalsErrorTelemetry = 1767723057616  # Unknown = 
    FFlagEnableAppAgeSignalsService = 1767723058832  # Unknown = 
    FFlagEnableAppChatSnoozeMenuFocus = 1767900725869  # Bool = true
    FFlagEnableAppRatingPromptLua = 1768009962960  # Unknown = 
    FFlagEnableAppRatingPromptLua4 = 1768010009872  # Unknown = 
    FFlagEnableAppStorageJsonCacheInABTest = 1767828617424  # Unknown = 
    FFlagEnableAppStorageJsonDecodeCache = 1767978526096  # Unknown = 
    FFlagEnableAppStoreAgeSignalsOnHomePage = 1767583403677  # Bool = false
    FFlagEnableArgoPartyChanges = 1767645302749  # Bool = false
    FFlagEnableArgoPartyExperimentation7 = 1768126145941  # Bool = true
    FFlagEnableArgus = 1767828593104  # Unknown = 
    FFlagEnableArgus2 = 1767828609936  # Unknown = 
    FFlagEnableArgusFlyoutEntry = 1767828586576  # Unknown = 
    FFlagEnableArgusImmersiveNav = 1767828554448  # Unknown = 
    FFlagEnableArgusTab = 1767828614288  # Unknown = 
    FFlagEnableAttributionContextEventReceiver = 1767650168400  # Unknown = 
    FFlagEnableAuditForSinglePageSignUp4 = 1767828610576  # Unknown = 
    FFlagEnableAuditForSso = 1767828595856  # Unknown = 
    FFlagEnableAuditSystem2 = 1768387524048  # Unknown = 
    FFlagEnableAuthAnalyticsPrintDebuggingDev = 1767720487696  # Unknown = 
    FFlagEnableAuthStatefulTextInputUpdatesRelease1 = 1767526149917  # Bool = false
    FFlagEnableAuthsecImageUpdate = 1767526161501  # Bool = false
    FFlagEnableAutoLoginAfterRecovery = 1767526154525  # Bool = false
    FFlagEnableAutomaticSizeVerticalOffsetWidthFix = 1767913639125  # Bool = false
    FFlagEnableAvatarEditorServiceAPIErrorLogging = 1767654043856  # Unknown = 
    FFlagEnableAvatarExperienceSdui = 1767828557200  # Unknown = 
    FFlagEnableAvatarHeadshotLocalIconBackgroundFix = 1767473193744  # Unknown = 
    FFlagEnableAvatarViewportAutoRotation = 1767899816989  # Bool = false
    FFlagEnableBadgeCheckForUserCreator = 1768136660125  # Bool = false
    FFlagEnableBirthdayOverlayAnalytics = 1767828606288  # Unknown = 
    FFlagEnableBlackbird = 1768027322192  # Unknown = 
    FFlagEnableBlackbirdCheck = 1768027270608  # Unknown = 
    FFlagEnableBlackbirdOnFlyoutMenu = 1768027275728  # Unknown = 
    FFlagEnableBlackbirdOnFlyoutMenu2 = 1768027290448  # Unknown = 
    FFlagEnableBlackbirdOnMorePage = 1768027276560  # Unknown = 
    FFlagEnableBlackbirdOnMorePage2 = 1768027301776  # Unknown = 
    FFlagEnableBlackbirdPageCloseCallback = 1768027307088  # Unknown = 
    FFlagEnableBlackbirdPageCloseCallback2 = 1768027312144  # Unknown = 
    FFlagEnableBlackbirdUpsellImpressionGating = 1767831109200  # Unknown = 
    FFlagEnableBlackbirdUpsellInUnifiedPurchaseModal = 1767831108304  # Unknown = 
    FFlagEnableBlackbirdUpsellInUnifiedPurchaseModal7 = 1767831109392  # Unknown = 
    FFlagEnableBlackbirdV2 = 1768027278096  # Unknown = 
    FFlagEnableBottomNavOnMarketplace_v3 = 1767831061648  # Unknown = 
    FFlagEnableBuildExperienceScrollPerformanceTracking = 1768139785309  # Bool = false
    FFlagEnableBuildOverflowMenuForNewGames = 1768139802013  # Bool = false
    FFlagEnableBuildTabOverride = 1767831057360  # Unknown = 
    FFlagEnableBypassNavigationLockHybridWebview = 1767650174352  # Unknown = 
    FFlagEnableCEVForceInitialize = 1767473189597  # Bool = false
    FFlagEnableCachingforReminderOfNorms = 1768458308688  # Unknown = 
    FFlagEnableCallingLogoutOnResetIXP = 1767720505424  # Unknown = 
    FFlagEnableCancelSubscriptionAppLua = 1767831051920  # Unknown = 
    FFlagEnableCapturesGalleryRetrievalCoreScript = 1768438474640  # Unknown = 
    FFlagEnableCapturesGalleryRetrievalCoreScript_v3 = 1768126133917  # Bool = false
    FFlagEnableCatalogTileLoadingLatencyV2 = 1767650028752  # Unknown = 
    FFlagEnableCentralFoundationOverlayProvider = 1767654069533  # Bool = false
    FFlagEnableCentralOverlayForUpsellPrompt = 1768125849885  # Bool = false
    FFlagEnableChatIconUnibarDropdownFixEnabled = 1768133881232  # Unknown = 
    FFlagEnableChatLineReporting2 = 1767583558813  # Bool = true
    FFlagEnableChatMicPerfBinding = 1768399807120  # Unknown = 
    FFlagEnableChatNewMessage = 1767583530845  # Bool = true
    FFlagEnableChatReportingTextChannelTag = 1767583572176  # Unknown = 
    FFlagEnableChromeWindowsNotInMenu = 1768049903736  # Unknown = 
    FFlagEnableClientToastNotificationsRedirectExperiment = 1768133931293  # Bool = false
    FFlagEnableClientToastNotificationsReducedMotion = 1768024093597  # Bool = false
    FFlagEnableCommonFriendsMenu3 = 1767583426256  # Unknown = 
    FFlagEnableCompensatingScrollingFrame = 1768125844061  # Bool = false
    FFlagEnableCondenseRobuxUpsell = 1768125835101  # Bool = false
    FFlagEnableConfirmSignOutV2 = 1767720501456  # Unknown = 
    FFlagEnableConfirmSignifierOnSignUpPage = 1767828598800  # Unknown = 
    FFlagEnableConnectDisconnect = 1767645294429  # Bool = false
    FFlagEnableConnectDisconnectInSettingsAndChrome = 1768001214237  # Bool = false
    FFlagEnableConsoleAutoFocusForUEN1 = 1767641314653  # Bool = false
    FFlagEnableConsoleDisconnectNetworkingErrorToast = 1767643520221  # Bool = false
    FFlagEnableConsoleExpControls = 1767828575184  # Unknown = 
    FFlagEnableConsoleExpControls684 = 1767828586704  # Unknown = 
    FFlagEnableConsoleExpControlsIXP = 1767828566736  # Unknown = 
    FFlagEnableConsoleExpControlsIXP684 = 1767828588752  # Unknown = 
    FFlagEnableConsoleGameJoinCard_v4 = 1767583523984  # Unknown = 
    FFlagEnableConsolePreparePaymentCheck = 1768125841885  # Bool = false
    FFlagEnableConsoleRobloxLogo = 1767828616912  # Unknown = 
    FFlagEnableContactInvitesForNonPhoneVerifiedForAll = 1767583423453  # Bool = false
    FFlagEnableContextFeaturesForOmniRecommendations = 1768458322832  # Unknown = 
    FFlagEnableContinueRecovery3 = 1767526154192  # Unknown = 
    FFlagEnableConvertPriceChangedToUnknownFailure = 1776067319248  # Unknown = 
    FFlagEnableCoreContentAccountType = 1767831071440  # Unknown = 
    FFlagEnableCoreContentBadge = 1767831070800  # Unknown = 
    FFlagEnableCoreContentBadge2 = 1767831070480  # Unknown = 
    FFlagEnableCoreContentThemeUseGuacForTokenOverrides = 1767831069648  # Unknown = 
    FFlagEnableCoreContentThemeUseGuacForTokenOverrides2 = 1767831070096  # Unknown = 
    FFlagEnableCoreContentThemeVRScene = 1767831073616  # Unknown = 
    FFlagEnableCoreUISystemV2 = 1767831052048  # Unknown = 
    FFlagEnableCorescriptExecutionTime = 1768393676304  # Unknown = 
    FFlagEnableCorescriptMemoryTracker = 1767900756229  # Bool = true
    FFlagEnableCorescriptTrackerForLuaApp = 1767650192208  # Unknown = 
    FFlagEnableCorescriptsProfiler = 1767831052112  # Unknown = 
    FFlagEnableCreatorStorePurchasingCutover = 1776067295888  # Unknown = 
    FFlagEnableCreatorSubtitleNavigation_v2 = 1767628367645  # Bool = true
    FFlagEnableCrossDeviceLoginUsingQRCodes3 = 1767526150736  # Unknown = 
    FFlagEnableCrossExpEventLogging = 1767628077904  # Unknown = 
    FFlagEnableCrossExpVoiceAbuseReport = 1767526152477  # Bool = false
    FFlagEnableCrossExpVoiceMemoryCheck = 1767526152157  # Bool = false
    FFlagEnableCurrencyTransferDeepLink = 1767583430224  # Unknown = 
    FFlagEnableCurrencyTransferFlowV3 = 1767583429328  # Unknown = 
    FFlagEnableCurrencyTransferWizardVPCPrologue = 1767908766672  # Unknown = 
    FFlagEnableDarkerShimmerTransparency = 1768399805968  # Unknown = 
    FFlagEnableDeactivatedUserReactivation = 1767526152848  # Unknown = 
    FFlagEnableDeepLinkHistoryWithModalAPI2 = 1767583395728  # Unknown = 
    FFlagEnableDeeplinkResolutionEventReceiver = 1767650167696  # Unknown = 
    FFlagEnableDeferVoiceConnection = 1767645292624  # Unknown = 
    FFlagEnableDemoModeRegionalAvailability = 1767526039389  # Bool = false
    FFlagEnableDesktopGameJoinCard_v5 = 1775988807240  # Unknown = 
    FFlagEnableDevProductPendingProductsLimitExceededInUnifiedPurchase = 1767483772757  # Bool = true
    FFlagEnableDevSubsFastFollowFixes = 1767828601168  # Unknown = 
    FFlagEnableDeviceGateForInExpChatRewrite = 1767860854749  # Bool = false
    FFlagEnableDialogAfterSquadJoin1 = 1767583392976  # Unknown = 
    FFlagEnableDirectLinkForTablets = 1767648606493  # Bool = false
    FFlagEnableDisableSubPurchase = 1768125850064  # Unknown = 
    FFlagEnableDisconnectPartyVoiceIfNeeded = 1768050266192  # Unknown = 
    FFlagEnableDiscountInfoInUnifiedPurchaseModal = 1767828564880  # Unknown = 
    FFlagEnableDiscountInfoInUnifiedPurchaseModal6 = 1767828571728  # Unknown = 
    FFlagEnableDisplayLoggingForToastsFix = 1768024075805  # Bool = true
    FFlagEnableDrawerAnimatingHook = 1767828609360  # Unknown = 
    FFlagEnableDrawerFocusNav = 1767828554640  # Unknown = 
    FFlagEnableDummyAMPWizard = 1767648608285  # Bool = false
    FFlagEnableDynamicReportV2ForUserProfileReports3 = 1767628640176  # Unknown = 
    FFlagEnableEDPTTIManagerColdWarmDetection = 1767649974544  # Unknown = 
    FFlagEnableExitModalExposure = 1768132567069  # Bool = false
    FFlagEnableExpChatLocalChatEnabledMessageExperimentation2 = 1767645299805  # Bool = false
    FFlagEnableExpChatNewSystemMessagesExperimentation = 1767645299920  # Unknown = 
    FFlagEnableExpChatUniverseChatTabNames2 = 1767641272157  # Bool = false
    FFlagEnableExpJoinMicPermAnalytics = 1768396190133  # Bool = false
    FFlagEnableExperienceDetailsBottomSheet2 = 1768005269861  # Bool = false
    FFlagEnableExperienceDetailsBottomSheetTopBar = 1768001946749  # Bool = true
    FFlagEnableExperienceGenericChallengeRenderingConnection2 = 1768024100752  # Unknown = 
    FFlagEnableExperienceGenericChallengeRenderingOnLoadingScript = 1767831051728  # Unknown = 
    FFlagEnableExperienceNotificationPrompts2 = 1767831051088  # Unknown = 
    FFlagEnableExplicitSettingsChangeAnalytics = 1767913345181  # Bool = false
    FFlagEnableExternalBrowserForVPCPrivacyPolicy = 1767648600349  # Bool = false
    FFlagEnableFAECancellationAnalytics = 1767648604125  # Bool = false
    FFlagEnableFAEQRCodeHandoff = 1767648600208  # Unknown = 
    FFlagEnableFaceIDTextOnAddAuthMethodPage = 1767720489040  # Unknown = 
    FFlagEnableFastScrollingFixTest = 1768017175056  # Unknown = 
    FFlagEnableFeatureRestrictionOnAgeVerificationAttempt = 1767643520784  # Unknown = 
    FFlagEnableFetchCartPricingDuringInExperience = 1767828588688  # Unknown = 
    FFlagEnableFixRobuxUpsellPriceCrash = 1768125835677  # Bool = false
    FFlagEnableFlyoutExposure = 1767989407440  # Unknown = 
    FFlagEnableFlyoutFriendsHeaderFix = 1767831067792  # Unknown = 
    FFlagEnableFlyoutIxp11 = 1767978520208  # Unknown = 
    FFlagEnableFlyoutMenuRobuxCardRefactor = 1768027290512  # Unknown = 
    FFlagEnableFlyoutOnNavRail = 1767470829021  # Bool = false
    FFlagEnableFlyoutSidePanel15 = 1767473195728  # Unknown = 
    FFlagEnableFlyoutUncheckedBadge = 1767831074000  # Unknown = 
    FFlagEnableFlyoutUncheckedBadge2 = 1767831074128  # Unknown = 
    FFlagEnableFlyoutWithScrollAway2 = 1768017185552  # Unknown = 
    FFlagEnableFontStylisticAlternativesOnSocialScreens = 1768133879056  # Unknown = 
    FFlagEnableFoundationUIVPCUpsellForInExperience = 1767648597264  # Unknown = 
    FFlagEnableFriendCarouselInGameFriendExposureLogging_v2 = 1767641310109  # Bool = false
    FFlagEnableFriendsLandingChallengeInterceptor = 1768181172944  # Unknown = 
    FFlagEnableFriendsListSearchNormalizationErrorFix = 1767583534301  # Bool = true
    FFlagEnableFriendsMenuShareGameInviteLink3 = 1768150355984  # Unknown = 
    FFlagEnableFriendsRenamingForAll = 1767583393296  # Unknown = 
    FFlagEnableFtuxExitOnMuteToggle = 1767645293853  # Bool = false
    FFlagEnableGameInviteModalVRSupportV2 = 1767583533277  # Bool = true
    FFlagEnableGameInviteRewardsBanner3 = 1767583536221  # Bool = true
    FFlagEnableGameLeftMessage = 1768229614064  # Unknown = 
    FFlagEnableGamepadHookForCorescriptGlobalEffects = 1767473744792  # Unknown = 
    FFlagEnableGateNotificationPreferencesTab = 1767583532701  # Bool = true
    FFlagEnableGenericIllegalContentReporting3 = 1767977089629  # Bool = false
    FFlagEnableGenericTwoFAMessage = 1767526161245  # Bool = false
    FFlagEnableGetCredentialsInCredentialsProtocolHook = 1768001200464  # Unknown = 
    FFlagEnableGetFriendshipStatus = 1767525992669  # Bool = true
    FFlagEnableGlobalChat3pSummaryLuaApps = 1768038225309  # Bool = false
    FFlagEnableGlobalChatAbuseReporting = 1767583565277  # Bool = true
    FFlagEnableHandleEngineSessionCheckAtStartup = 1767650171536  # Unknown = 
    FFlagEnableHeadShapeForCharacterManager = 1767977084112  # Unknown = 
    FFlagEnableHeadShapeForCharacterManager6 = 1767977070736  # Unknown = 
    FFlagEnableHeaderBarButtonsUpdate = 1768399770973  # Bool = false
    FFlagEnableHeaderBarButtonsUpdate2 = 1768399789072  # Unknown = 
    FFlagEnableHeadlessSubscriptionNativePurchaseCancelCallback = 1767643496413  # Bool = false
    FFlagEnableHearingWithoutMicPermissions = 1767645293136  # Unknown = 
    FFlagEnableHideJoinToastSubtitle = 1767645290384  # Unknown = 
    FFlagEnableHideReportAdModalDuringScreenshot2 = 1768060680093  # Bool = false
    FFlagEnableHomeBetaBadge = 1768040509024  # Unknown = 
    FFlagEnableHomeGameItemOwnershipUpdate = 1768458307280  # Unknown = 
    FFlagEnableHomePageEmailUpsellCard = 1767650184336  # Unknown = 
    FFlagEnableHomePageUpsellCardRelease7 = 1767649994768  # Unknown = 
    FFlagEnableHomeRobloxLogo = 1767828605456  # Unknown = 
    FFlagEnableHomepagePromptsForModalsAndBanners = 1768458303440  # Unknown = 
    FFlagEnableHotbarHide = 1768017071568  # Unknown = 
    FFlagEnableIAFlyoutIXPHomeProfileRemoval = 1767723048016  # Unknown = 
    FFlagEnableIOSUIRefactorLuaIXP2 = 1767526153181  # Bool = false
    FFlagEnableIXPOverrideAccountPicker1 = 1767828572368  # Unknown = 
    FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByCode = 1767643516701  # Bool = false
    FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByEmail = 1767643516829  # Bool = false
    FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByOtp = 1767643516957  # Bool = false
    FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByPhone = 1767643515600  # Unknown = 
    FFlagEnableIllegalChildAccountLinkingErrorMessageOnLoginByUsername = 1767643513744  # Unknown = 
    FFlagEnableIllegalChildAccountLinkingErrorMessageOnSSO = 1767643516573  # Bool = false
    FFlagEnableInAppBugReporting = 1768133838864  # Unknown = 
    FFlagEnableInExpChatPolishSummaryOnLuaForTranslatedMessageV2 = 1768001240861  # Bool = false
    FFlagEnableInExpChatRewrite = 1767860847517  # Bool = false
    FFlagEnableInExpChatSummaryOnLua = 1767860806493  # Bool = false
    FFlagEnableInExpChatSummaryOnLua4 = 1767860852125  # Bool = false
    FFlagEnableInExpChatSummaryOnLuaForTranslatedMessageV2 = 1768001229469  # Bool = false
    FFlagEnableInExpPhoneVoiceUpsellEntrypoints2 = 1767526163101  # Bool = false
    FFlagEnableInExperienceAvatarSwitcher9 = 1767526170397  # Bool = false
    FFlagEnableInExperienceHandheldControls = 1767828572816  # Unknown = 
    FFlagEnableInExperienceShop = 1767828571600  # Unknown = 
    FFlagEnableInExperienceShop3 = 1767828572240  # Unknown = 
    FFlagEnableInExperienceUIPCVRFix_dev = 1768027287696  # Unknown = 
    FFlagEnableInGameMenuChrome = 1767978556368  # Unknown = 
    FFlagEnableInGameMenuDurationLogger = 1767972976669  # Bool = false
    FFlagEnableInitialJoinVoiceButton = 1767645291152  # Unknown = 
    FFlagEnableInlineSurveyOnUserReport = 1767583564061  # Bool = true
    FFlagEnableInspectAndBuyV2RootFlag = 1767828579792  # Unknown = 
    FFlagEnableInspectAndBuyV2RootFlag2 = 1767828579728  # Unknown = 
    FFlagEnableInvitePromptLoadingState2 = 1767901841680  # Unknown = 
    FFlagEnableInvoluntaryLogoutEvent = 1767650164944  # Unknown = 
    FFlagEnableIosAuthServiceLuaIXP = 1767526155101  # Bool = false
    FFlagEnableIosKeychainLoginLua4 = 1767625417040  # Unknown = 
    FFlagEnableJoinV2PreAuthDeepLink = 1767643520541  # Bool = false
    FFlagEnableJoinVoiceIsMutedMic = 1767645292240  # Unknown = 
    FFlagEnableJoinVoiceTooltip = 1767645291664  # Unknown = 
    FFlagEnableJoinVoiceVrTelemetry = 1775992614992  # Unknown = 
    FFlagEnableKeyboardVisibilityCheckOnPasswordFocus = 1768387517840  # Unknown = 
    FFlagEnableKoreaKISACompliance = 1767720496656  # Unknown = 
    FFlagEnableLastLoginMethodTracking = 1767720487120  # Unknown = 
    FFlagEnableLaunchAfterPurchase2 = 1767828559440  # Unknown = 
    FFlagEnableLaunchAppCheckForAccountSwitchGameParams = 1767650171600  # Unknown = 
    FFlagEnableLeaveGameUpsellEntrypoint = 1768132562000  # Unknown = 
    FFlagEnableLeftNavOnConsole14 = 1768027293840  # Unknown = 
    FFlagEnableLimitHit2SVUpsell = 1767908753296  # Unknown = 
    FFlagEnableLinkSharingEvent = 1767831051856  # Unknown = 
    FFlagEnableLocalesForExperienceLanguageSwitcher4 = 1767913347869  # Bool = false
    FFlagEnableLockScreenWidgetLuaIXP = 1767526153373  # Bool = false
    FFlagEnableLoginAccountSelectorRelease1 = 1767526150544  # Unknown = 
    FFlagEnableLoginDisambiguationFoundationSwitcher = 1767526157981  # Bool = false
    FFlagEnableLoginV2Modalization15 = 1767831084112  # Unknown = 
    FFlagEnableLogoutV3 = 1767720490064  # Unknown = 
    FFlagEnableLookFavoriting = 1767426284957  # Bool = true
    FFlagEnableLuaAccountSwitchRelease2 = 1767526155869  # Bool = false
    FFlagEnableLuaAppBootcamp = 1767650181149  # Bool = false
    FFlagEnableLuaAppSessionWithError2 = 1767640174877  # Bool = false
    FFlagEnableLuaAppsAppsflyerIdCounter = 1767650169680  # Unknown = 
    FFlagEnableLuaAppsFollowUserId = 1767831061072  # Unknown = 
    FFlagEnableLuaCommunityList = 1767470829277  # Bool = false
    FFlagEnableLuaLogReporterMultipleLogs = 1767526165981  # Bool = false
    FFlagEnableLuafiedRecoveryFlow2 = 1767526151504  # Unknown = 
    FFlagEnableLuckyRecommendationExperimentation = 1767583399325  # Bool = false
    FFlagEnableLuobuInGameUpsell = 1776067302288  # Unknown = 
    FFlagEnableMagicLogin = 1767828603984  # Unknown = 
    FFlagEnableMagicLogin_debug = 1767828571536  # Unknown = 
    FFlagEnableManageAccountsRedesign8 = 1767526156688  # Unknown = 
    FFlagEnableMaquettesShortLinkCDLInstructions = 1768458302416  # Unknown = 
    FFlagEnableMeTabMarketplaceNav = 1768005279184  # Unknown = 
    FFlagEnableMeTabProfile = 1768005285648  # Unknown = 
    FFlagEnableMemoryShell = 1768492002832  # Unknown = 
    FFlagEnableMemorySnapshotCategories = 1767638310429  # Bool = false
    FFlagEnableMenuTrailingBadge = 1767828565008  # Unknown = 
    FFlagEnableMergeOmniFeedSorts3 = 1768001196957  # Bool = false
    FFlagEnableMessageBusUnSubscribeErrorTelemetry = 1767583608080  # Unknown = 
    FFlagEnableMicrosoftStorePaymentsPlatform = 1767470836061  # Bool = false
    FFlagEnableMilkyWayPaymentsPlatformV2 = 1767470836637  # Bool = false
    FFlagEnableMobileGameJoinCard_V14 = 1767583525072  # Unknown = 
    FFlagEnableMobilePlayerListOnConsole = 1776081090152  # Unknown = 
    FFlagEnableModerateChatRemoteEvent = 1767583525981  # Bool = true
    FFlagEnableModerateChatUseChatService = 1768005285968  # Unknown = 
    FFlagEnableModularExternalNavigationHandler = 1768050266064  # Unknown = 
    FFlagEnableModularizedUserAgreementsList = 1768027291536  # Unknown = 
    FFlagEnableMomentTextGeneration3 = 1776085380496  # Unknown = 
    FFlagEnableMorePageDirectionalLayoutRolloutFix = 1767828557085  # Bool = false
    FFlagEnableMorePageExitButtonSupport = 1767828599197  # Bool = true
    FFlagEnableMorePageExitButtonSupport2 = 1767828607632  # Unknown = 
    FFlagEnableMotionJitterMetric2 = 1768458342352  # Unknown = 
    FFlagEnableMoveSnapInVirtualCursor = 1768009997904  # Unknown = 
    FFlagEnableMultiPageSignup5 = 1767720518608  # Unknown = 
    FFlagEnableMultiPageSignupExperimentRelease2 = 1767650171088  # Unknown = 
    FFlagEnableMultiPageSignupV2Updates = 1767720507152  # Unknown = 
    FFlagEnableMultipageSignupNonInteractiveUserAgreementsPage = 1767720510416  # Unknown = 
    FFlagEnableMutexOnGenericChallengeInterceptorMount = 1767424939549  # Bool = false
    FFlagEnableNapIxpLayerExposure = 1767583562448  # Unknown = 
    FFlagEnableNativePersonaInquiryForAmpIDVUpsell = 1767648606813  # Bool = false
    FFlagEnableNativeToWebviewMiddleware = 1768001209744  # Unknown = 
    FFlagEnableNativeWrapperAppPage = 1767654043421  # Bool = false
    FFlagEnableNavBarLabels3 = 1767470830493  # Bool = false
    FFlagEnableNavigateToLoginAfterLogoutAll = 1767526156317  # Bool = false
    FFlagEnableNavigationPerformanceIntervals2 = 1768027318160  # Unknown = 
    FFlagEnableNewAddFriendsTileForAll = 1768133859280  # Unknown = 
    FFlagEnableNewAvatarViewportProps = 1767899812693  # Bool = false
    FFlagEnableNewBackpack = 1767831085008  # Unknown = 
    FFlagEnableNewBackpackV5 = 1767831083152  # Unknown = 
    FFlagEnableNewCustomizeBundleEquip3 = 1767650026768  # Unknown = 
    FFlagEnableNewDeviceIntegrityFailureHandling = 1768017098448  # Unknown = 
    FFlagEnableNewInviteMenuCustomization2 = 1767901843101  # Bool = false
    FFlagEnableNewInviteMenuCustomizationIXP2 = 1767901843344  # Unknown = 
    FFlagEnableNewInviteMenuIXP2 = 1768005271696  # Unknown = 
    FFlagEnableNewInviteMenuStyle = 1767901844957  # Bool = false
    FFlagEnableNewInviteSendEndpoint = 1767901849437  # Bool = false
    FFlagEnableNewInviteSendEndpointIXP = 1767901849629  # Bool = false
    FFlagEnableNonFlyoutUncheckedBadge = 1767831074960  # Unknown = 
    FFlagEnableNonFlyoutUncheckedBadge2 = 1767831075152  # Unknown = 
    FFlagEnableNotApprovedCheckBoxTextABTest = 1768458335568  # Unknown = 
    FFlagEnableNotApprovedForeshadowingConsequenceABTest = 1768458297232  # Unknown = 
    FFlagEnableNotificationsDeeplink = 1767831091216  # Unknown = 
    FFlagEnableNotificationsToastTTLFix = 1768024080221  # Bool = false
    FFlagEnableOffersOnInExperienceSurface = 1767828569680  # Unknown = 
    FFlagEnableOnPlatformSharingExperiment = 1768133844496  # Unknown = 
    FFlagEnableOnPlatformSharingExperiment_v5 = 1768133828752  # Unknown = 
    FFlagEnableOtpEmailLoginRelease1 = 1767654065680  # Unknown = 
    FFlagEnablePLTPrefetchCallbacks = 1768017099024  # Unknown = 
    FFlagEnablePWManagerSignupCheck = 1767828600016  # Unknown = 
    FFlagEnablePalisadesPaymentsPlatform = 1776067289936  # Unknown = 
    FFlagEnableParentalControlsScreentimeEnforcement3 = 1776050425168  # Unknown = 
    FFlagEnablePartyNudgeAfterJoin2 = 1767583395024  # Unknown = 
    FFlagEnablePartyNudgeV1_DEV = 1768133866832  # Unknown = 
    FFlagEnablePartyPageCarouselExperimentation4 = 1767645311837  # Bool = false
    FFlagEnablePartyQuickStartButton = 1768133883408  # Unknown = 
    FFlagEnablePartyQuickStartButton3 = 1768133841424  # Unknown = 
    FFlagEnablePartyQuickStartChanges2 = 1767645309725  # Bool = false
    FFlagEnablePartyVoiceChangersInLua = 1768133867664  # Unknown = 
    FFlagEnablePartyVoiceOnlyForEligibleUsers = 1768024085981  # Bool = false
    FFlagEnablePartyVoiceOnlyForUnfilteredThreads = 1768024101533  # Bool = true
    FFlagEnablePartyVoiceRestrictionStatus = 1768050296720  # Unknown = 
    FFlagEnablePartyVoiceStatusChangedDetailAnalytics = 1767473191965  # Bool = false
    FFlagEnablePartyVoiceVolumeOnlyWhenInEligibleParty = 1767526150813  # Bool = false
    FFlagEnablePasskeyLoginErrorLogging = 1767720513488  # Unknown = 
    FFlagEnablePasskeyOnlyUserErrorMessage = 1767643514960  # Unknown = 
    FFlagEnablePasswordStatusRemoval = 1767650169232  # Unknown = 
    FFlagEnablePaymentSessionIdInRobuxPurchase = 1767897048336  # Unknown = 
    FFlagEnablePeekViewFocusNav = 1768458303120  # Unknown = 
    FFlagEnablePeekViewStateOnMountParam = 1767470831005  # Bool = false
    FFlagEnablePeopleListLazyRender = 1768389356496  # Unknown = 
    FFlagEnablePeoplePageButtonOnMount = 1768389405648  # Unknown = 
    FFlagEnablePerfRegressionTest = 1767650001872  # Unknown = 
    FFlagEnablePerformPurchaseGCSHandling = 1776067337488  # Unknown = 
    FFlagEnablePersonaLivenessQR = 1767583575325  # Bool = true
    FFlagEnablePinnedShortcutsOnHomeScreenLua2 = 1767831054736  # Unknown = 
    FFlagEnablePioneerLandingPageLayout = 1767828578397  # Bool = false
    FFlagEnablePioneerPaymentsPlatform = 1776067294237  # Bool = true
    FFlagEnablePioneerPostAuthGameJoin = 1767828559965  # Bool = false
    FFlagEnablePlatformEvidence = 1768458302480  # Unknown = 
    FFlagEnablePlatformProfileContextualMenuOption = 1768009980880  # Unknown = 
    FFlagEnablePlatformRestrictedEventReceiver3 = 1767831071632  # Unknown = 
    FFlagEnablePlayWithRewardComponent = 1768374753360  # Unknown = 
    FFlagEnablePlayWithRewardComponent10 = 1767526117085  # Bool = false
    FFlagEnablePlayWithRewardNonPeekviewEdp = 1767828596240  # Unknown = 
    FFlagEnablePlayerListExposureEvents = 1768132539088  # Unknown = 
    FFlagEnablePlayerSupportCaptureAttachments = 1767897086813  # Bool = false
    FFlagEnablePlayerSupportCaptureAttachments2 = 1768017052432  # Unknown = 
    FFlagEnablePlayerSupportPrompt = 1768017054493  # Bool = true
    FFlagEnablePlaytestModeUnibar2 = 1767828563536  # Unknown = 
    FFlagEnablePlusUpsellDeepLink = 1768001901165  # Bool = false
    FFlagEnablePopLatencyOverlay = 1767470826768  # Unknown = 
    FFlagEnablePostAuthRoutingInAllCases = 1767720543504  # Unknown = 
    FFlagEnablePostAuthRoutingInAllCases2 = 1767720500688  # Unknown = 
    FFlagEnablePreAuthDeepLinkHandler2 = 1767643518416  # Unknown = 
    FFlagEnablePriceChangedErrorHandling = 1776067298448  # Unknown = 
    FFlagEnableProfileCompletion = 1768027310165  # Bool = false
    FFlagEnableProfileInsightsApolloMigration_v3 = 1767583396304  # Unknown = 
    FFlagEnableProfilePlatformChallengeInterceptor = 1768317788112  # Unknown = 
    FFlagEnableProfilePlatformDisabledActions = 1768133847952  # Unknown = 
    FFlagEnableProgressLoadingAssetsAppContainer = 1767654090845  # Bool = false
    FFlagEnableProgressLoadingAssetsTenFoot = 1767654038941  # Bool = false
    FFlagEnablePromptAgeCheckListener = 1767831049040  # Unknown = 
    FFlagEnablePromptPurchaseRequestedV2 = 1776067319952  # Unknown = 
    FFlagEnablePromptPurchaseRequestedV2Take2 = 1776067321744  # Unknown = 
    FFlagEnablePromptRobloxSubscriptionPurchaseBinding = 1776067282192  # Unknown = 
    FFlagEnablePromptRobloxSubscriptionPurchaseBinding2 = 1776067306384  # Unknown = 
    FFlagEnableProvisionalRating = 1768135741389  # Bool = true
    FFlagEnablePurchaseFlowUUIDMigration = 1776067316560  # Unknown = 
    FFlagEnablePurchasePayloadInExperienceShop = 1767828557328  # Unknown = 
    FFlagEnablePushNotificationsUpsellModal6 = 1767583533136  # Unknown = 
    FFlagEnablePushNotificationsUpsellModalChat4 = 1767900718269  # Bool = true
    FFlagEnablePymkCarouselChallengeInterceptor = 1767643522576  # Unknown = 
    FFlagEnableQuestIAPAnalytics = 1776067287184  # Unknown = 
    FFlagEnableQueueExperimentation2 = 1767645304733  # Bool = false
    FFlagEnableRMOnMorePageForAll = 1768027302608  # Unknown = 
    FFlagEnableRMOnMorePageGUAC = 1768027290576  # Unknown = 
    FFlagEnableReactSchedulerIXP = 1767828554768  # Unknown = 
    FFlagEnableReadAloudInUA2 = 1767470843421  # Bool = false
    FFlagEnableRecentActivityInspectAndBuy = 1767900772797  # Bool = true
    FFlagEnableRecentActivitySingleItemDetails = 1767900756221  # Bool = true
    FFlagEnableRecommendationsForPCGDK = 1767583391261  # Bool = false
    FFlagEnableRecordLogin = 1767828579600  # Unknown = 
    FFlagEnableRecordLogin1 = 1767828559760  # Unknown = 
    FFlagEnableRecordSignOut = 1767650165200  # Unknown = 
    FFlagEnableReferredPlayerJoinRemoteEvent = 1767720498064  # Unknown = 
    FFlagEnableReferredPlayerJoinRemoteEventForAll = 1767720501648  # Unknown = 
    FFlagEnableRejectPromiseOnWebviewClosed = 1768001211408  # Unknown = 
    FFlagEnableReminderOfNormsABTest = 1768458306768  # Unknown = 
    FFlagEnableReportAdDropdown5 = 1768060678301  # Bool = false
    FFlagEnableReportingFlowForDevSubs = 1767828603728  # Unknown = 
    FFlagEnableReportingFlowForDevSubs2 = 1767828618256  # Unknown = 
    FFlagEnableReportingFlowForExperienceShop2 = 1767828616656  # Unknown = 
    FFlagEnableReportingFlowForMomentsFeed = 1767828601488  # Unknown = 
    FFlagEnableRequestLocationTypeForSduiPurchase = 1776067292816  # Unknown = 
    FFlagEnableRetryForLinkingProtocolFetch = 1767470835037  # Bool = false
    FFlagEnableRetryOnPrefetch401 = 1767977235216  # Unknown = 
    FFlagEnableReusableVPCPrologue = 1767648600733  # Bool = false
    FFlagEnableRewardsWebViewOverlay = 1776125392080  # Unknown = 
    FFlagEnableRichTextForBubbleChat = 1767410594269  # Bool = false
    FFlagEnableRoactNetworkingForChallengeInteception = 1767648603485  # Bool = false
    FFlagEnableRobloxSubscriptionEventListener = 1767831077328  # Unknown = 
    FFlagEnableRobuxInExperienceShop = 1767828598608  # Unknown = 
    FFlagEnableRobuxInExperienceShop3 = 1767828604432  # Unknown = 
    FFlagEnableRobuxTransferFlowEventIngest = 1767583431504  # Unknown = 
    FFlagEnableSafetyDashboard = 1767418852413  # Bool = true
    FFlagEnableSavePasswordAfterRecovery = 1767526154845  # Bool = false
    FFlagEnableScheduledSquadsListExperimentation_dev = 1767645305565  # Bool = false
    FFlagEnableScheduledSquadsTopBarEntrypoint_dev = 1768371882589  # Bool = false
    FFlagEnableSchedulerFlagOverrides = 1767828607440  # Unknown = 
    FFlagEnableSchematizedInGameRobuxUpsellEvent2 = 1768158661901  # Bool = true
    FFlagEnableSchoolEntry = 1767583401744  # Unknown = 
    FFlagEnableScreentimeMoreTimeOption = 1768009993360  # Unknown = 
    FFlagEnableScrollAwayContentScrollableFix = 1767828588304  # Unknown = 
    FFlagEnableSduiRegistriesforTenFootUiContainer = 1767654039517  # Bool = false
    FFlagEnableSduiV2HomepagePrompts2 = 1767526168272  # Unknown = 
    FFlagEnableSeamlessVoiceDataConsentToast = 1768001208733  # Bool = false
    FFlagEnableSeamlessVoiceFeature = 1767645294301  # Bool = false
    FFlagEnableSearchOmniAutocompletePageByDefault5 = 1767526163997  # Bool = false
    FFlagEnableSecurityAlertDeeplink = 1767583561245  # Bool = true
    FFlagEnableSecurityAlertToastCallback = 1767583563741  # Bool = true
    FFlagEnableSendCameraAccessAnalytics = 1767831050576  # Unknown = 
    FFlagEnableSessionCheckManagerToListenOnce = 1767650174416  # Unknown = 
    FFlagEnableSetCoreGuiEnabledExpChat = 1767410592029  # Bool = false
    FFlagEnableSettingsHubUIDelegateRollout = 1768027296464  # Unknown = 
    FFlagEnableShareLinksInGameDetailEvent = 1767828568592  # Unknown = 
    FFlagEnableShareSheetForBuild = 1767831083984  # Unknown = 
    FFlagEnableSharedInviteStore = 1768266562109  # Bool = false
    FFlagEnableShopGiftCardsURL = 1768012217616  # Unknown = 
    FFlagEnableShortLinkCodeForVRCDLv2 = 1768458289808  # Unknown = 
    FFlagEnableSideSheet = 1767828573277  # Bool = true
    FFlagEnableSideSheet6 = 1767828598045  # Bool = false
    FFlagEnableSignUpExitModal = 1767828598416  # Unknown = 
    FFlagEnableSignUpExitModal3 = 1767828608208  # Unknown = 
    FFlagEnableSignupFoundationText2 = 1767720500880  # Unknown = 
    FFlagEnableSignupFoundationalizeBackgroundAndText = 1767720509264  # Unknown = 
    FFlagEnableSilentUpgradeOnSignUp = 1767828562064  # Unknown = 
    FFlagEnableSilentUpgradeOnSignUp2 = 1767828612624  # Unknown = 
    FFlagEnableSkyStyle = 1768027321885  # Bool = false
    FFlagEnableSlotsHeadShapeThumbnail = 1767977064528  # Unknown = 
    FFlagEnableSlotsHeadShapeThumbnail2 = 1767977076176  # Unknown = 
    FFlagEnableSnapInVirtualCursor2 = 1768010004048  # Unknown = 
    FFlagEnableSocialCards2 = 1767583398480  # Unknown = 
    FFlagEnableSocialContextToast = 1768458295568  # Unknown = 
    FFlagEnableSocialProofOnItemDetails = 1768133828893  # Bool = false
    FFlagEnableSocialProofOnItemDetailsRoactGamepadNavigation = 1768133841168  # Unknown = 
    FFlagEnableSocialProofUserList = 1768133860816  # Unknown = 
    FFlagEnableSocialProofUserList_4 = 1768133865680  # Unknown = 
    FFlagEnableSocialProofVerticalUserListSheet = 1768038473744  # Unknown = 
    FFlagEnableSocialProofVerticalUserListSheet_2 = 1767470829456  # Unknown = 
    FFlagEnableSocialTabsPage = 1768133858000  # Unknown = 
    FFlagEnableSocialTabsPage_DEV = 1768133876752  # Unknown = 
    FFlagEnableSortInvitesByScoreExperiment = 1768150377693  # Bool = true
    FFlagEnableSoundSessionTelemetry5 = 1767831053264  # Unknown = 
    FFlagEnableSpatialRobloxGui = 1767913639253  # Bool = false
    FFlagEnableSpatialRobloxGui4 = 1768229399248  # Unknown = 
    FFlagEnableSpatialUIBottomBarFixPlaceFilter = 1767913325469  # Bool = false
    FFlagEnableSpatialUICameraTypeFix8 = 1767978506448  # Unknown = 
    FFlagEnableSpatialUIPlaceFilter = 1767978509648  # Unknown = 
    FFlagEnableSpatialUIScalingFix = 1767978537232  # Unknown = 
    FFlagEnableSplitPanel = 1767470820752  # Unknown = 
    FFlagEnableSquadCoplayAnalytic = 1767526018333  # Bool = false
    FFlagEnableSquadDeeplinkWithChatId = 1767583398544  # Unknown = 
    FFlagEnableSquadLobbyUpsellCardShortScreenFix = 1767425287901  # Bool = false
    FFlagEnableSquadPromptAnalytics = 1768050264656  # Unknown = 
    FFlagEnableSquadRegroupExperimentation = 1767900768189  # Bool = true
    FFlagEnableSquadRegroupExperimentation1 = 1767583523101  # Bool = true
    FFlagEnableSquadRegroupExperimentationSmallScreenFix = 1767583523613  # Bool = true
    FFlagEnableSquadRegroupServerCapacityCheck = 1767583524061  # Bool = true
    FFlagEnableSquadTopBannerWideMode = 1767583399760  # Unknown = 
    FFlagEnableSquadUserCardHoverFix = 1768133825040  # Unknown = 
    FFlagEnableSquadsUnifyCoplayExperimentation_dev = 1767645308381  # Bool = false
    FFlagEnableSquadsUnifyCoplayMultiInvitePartyCreation_dev = 1767645308061  # Bool = false
    FFlagEnableSquadsUnifyCoplayOneOnOnePartyCreation_dev = 1767645307933  # Bool = false
    FFlagEnableStandaloneAppChat = 1768024105181  # Bool = false
    FFlagEnableStorePreviousAccountData = 1767720491216  # Unknown = 
    FFlagEnableStreamAvatarImageUrlThumbnail = 1768017062224  # Unknown = 
    FFlagEnableStudioMockPurchaseRobloxSubscription = 1767900755901  # Bool = true
    FFlagEnableSubTabForSpatial = 1767828553936  # Unknown = 
    FFlagEnableSubscriptionPurchaseFlowEventIngest = 1767643495581  # Bool = false
    FFlagEnableSubscriptionPurchaseToast = 1767897047261  # Bool = false
    FFlagEnableSubscriptionUpsellUnifiedPurchaseEventTelemetry = 1767708418064  # Unknown = 
    FFlagEnableSummarySystemMessageOnLua = 1767470815645  # Bool = false
    FFlagEnableSupportCenter = 1767583574237  # Bool = true
    FFlagEnableSystemScrim = 1767831051984  # Unknown = 
    FFlagEnableSystemScrimInSettingsHub = 1768132566173  # Bool = false
    FFlagEnableSystemTrayModals = 1767828560080  # Unknown = 
    FFlagEnableSystemTrayModals3 = 1767828586896  # Unknown = 
    FFlagEnableTFFeedbackModeEntryCheck = 1767913346525  # Bool = false
    FFlagEnableTTIRecordWebViewMilestones = 1767470842461  # Bool = false
    FFlagEnableTeamTestLua = 1767828565136  # Unknown = 
    FFlagEnableTeamTestLuaVersionCheck = 1767828594640  # Unknown = 
    FFlagEnableTelemetryProtocol = 1767583608720  # Unknown = 
    FFlagEnableTenftUiDetailsMoreDropupMenu = 1768027297808  # Unknown = 
    FFlagEnableTiltLoadingScreen = 1767831054544  # Unknown = 
    FFlagEnableTiltLoadingScreen2 = 1767831054800  # Unknown = 
    FFlagEnableTimeoutUI = 1768017062685  # Bool = true
    FFlagEnableToSwitchToSettingsAppWithRouteLua = 1767640199453  # Bool = false
    FFlagEnableToastIconSupport = 1767583560592  # Unknown = 
    FFlagEnableToastLiteRender = 1776067336912  # Unknown = 
    FFlagEnableToastNotificationsDeeplinkConfirmationModalHeightFix = 1768017076304  # Unknown = 
    FFlagEnableTopBarAnalytics = 1768444924584  # Unknown = 
    FFlagEnableTopSongsSort7 = 1767526166493  # Bool = false
    FFlagEnableTradesEntryForNonPremium = 1768027272080  # Unknown = 
    FFlagEnableTransparentDeviceIntegrityChallengeSpinner = 1768017071888  # Unknown = 
    FFlagEnableTransparentNativeChallengeWrapper = 1767654049309  # Bool = false
    FFlagEnableUIManagerPackgify = 1768027265360  # Unknown = 
    FFlagEnableUIManagerPackgify8 = 1768027259088  # Unknown = 
    FFlagEnableUISelector3 = 1767989385821  # Bool = false
    FFlagEnableUnifiedProductPurchaseFlow = 1767828579536  # Unknown = 
    FFlagEnableUnifiedProductPurchaseFlowV37 = 1767828591312  # Unknown = 
    FFlagEnableUnifiedPurchaseFlowForDevSubs = 1767828589136  # Unknown = 
    FFlagEnableUnifiedPurchaseFlowForDevSubs10 = 1767828558544  # Unknown = 
    FFlagEnableUniveralVoiceToasts = 1768001207901  # Bool = false
    FFlagEnableUpdateAddPhoneDescriptionTextExperimentRelease1 = 1767650184592  # Unknown = 
    FFlagEnableUpdatedCaptureControls = 1776085417680  # Unknown = 
    FFlagEnableUpdatedCaptureControls_v9 = 1776085398736  # Unknown = 
    FFlagEnableUpdatedLogoutUpsellModal = 1767720514960  # Unknown = 
    FFlagEnableUpsellSuggestionsAnalyticsId = 1767828597904  # Unknown = 
    FFlagEnableUpsellVirtualItemBadge = 1768125840221  # Bool = false
    FFlagEnableUseShowTopBar4 = 1767470830365  # Bool = false
    FFlagEnableUserAccessServiceIntegration = 1767611332752  # Unknown = 
    FFlagEnableUserAccessServiceIntegration3 = 1767583559965  # Bool = true
    FFlagEnableUserInputCFrameLogging = 1768428738192  # Unknown = 
    FFlagEnableUserListModule = 1768133860048  # Unknown = 
    FFlagEnableUserListModule_2 = 1768133848912  # Unknown = 
    FFlagEnableUserRecentActivityEntryPoint = 1767900756525  # Bool = true
    FFlagEnableUserRecentActivityEntryPoint_v2 = 1767583528733  # Bool = true
    FFlagEnableUserSearchChallengeInterceptor = 1767648646544  # Unknown = 
    FFlagEnableVNGNewAppAvailableModal = 1767654068701  # Bool = false
    FFlagEnableVPCUpsellFoundationDialogHardening = 1767648595920  # Unknown = 
    FFlagEnableVRChartsTab = 1768458348304  # Unknown = 
    FFlagEnableVREnvironmentSetting3 = 1768027310608  # Unknown = 
    FFlagEnableVRFTUXExperienceV2 = 1768181192720  # Unknown = 
    FFlagEnableVRPreparePaymentCheck = 1768125838813  # Bool = false
    FFlagEnableVRWrapperTransparency = 1768458292944  # Unknown = 
    FFlagEnableValidateFAEVerificationLink = 1767648602768  # Unknown = 
    FFlagEnableVerifiedBadgeStore = 1768158273904  # Unknown = 
    FFlagEnableVerifiedCheckViaOverlay = 1768001213597  # Bool = false
    FFlagEnableVirtualCursorDebugging = 1768010020624  # Unknown = 
    FFlagEnableVirtualizedListBacktraceTag = 1767650175005  # Bool = false
    FFlagEnableVoiceChatStorybookFix = 1767411146904  # Unknown = 
    FFlagEnableVoiceChatVoiceUISync = 1768132430301  # Bool = false
    FFlagEnableVoiceEuConsentPrompt = 1768133830173  # Bool = false
    FFlagEnableVoicePromptReasonText = 1768001206928  # Unknown = 
    FFlagEnableVoiceReverseNudge = 1767645286160  # Unknown = 
    FFlagEnableVoiceTrialUpsellCard = 1767654047581  # Bool = false
    FFlagEnableVoiceTrustedConnectionsToasts = 1768001209629  # Bool = false
    FFlagEnableVoiceUxUpdates5_AEGIS2 = 1767583537693  # Bool = true
    FFlagEnableVoiceVrVoiceConnectDisconnect_AEGIS2 = 1767583538141  # Bool = true
    FFlagEnableVolumeSliderQOLFix = 1768027322768  # Unknown = 
    FFlagEnableVpcForInExperiencePremiumUpsell = 1767897046941  # Bool = false
    FFlagEnableVpcForInExperienceSubscriptionPurchase = 1767897047709  # Bool = false
    FFlagEnableVrVoiceParity = 1768027313168  # Unknown = 
    FFlagEnableWebAmpWizardForFAEHandoff = 1767648600976  # Unknown = 
    FFlagEnableWebViewOpenDurationCap = 1767650175888  # Unknown = 
    FFlagEnableWebViewStateTracker = 1767828576976  # Unknown = 
    FFlagEnableWebViewStateTracker3 = 1767828601552  # Unknown = 
    FFlagEnableWhatsNew2 = 1767828564560  # Unknown = 
    FFlagEnableWhiteOrGreyRobuxIcon = 1767723042256  # Unknown = 
    FFlagEnableWhiteRobuxIcon = 1767723043088  # Unknown = 
    FFlagEnableWidgetLUAIXP = 1767526152733  # Bool = false
    FFlagEncodeSquadMembersUpdated = 1768024048029  # Bool = true
    FFlagEngineAudioSTTIsDictationEnabled = 1768112853981  # Bool = false
    FFlagEnhancedPersonaLivenessEvents = 1767583575965  # Bool = true
    FFlagEraseFPSFromDefaultSetting = 1767913346128  # Unknown = 
    FFlagErrorPromptUseLeaveGameHelper = 1768009971280  # Unknown = 
    FFlagEventsInExperienceAppFixStyleLink = 1768017051165  # Bool = true
    FFlagExpChatAddUserAsyncNilCheck = 1767900762229  # Bool = true
    FFlagExpChatAddWindowSettingDependency = 1768001192285  # Bool = false
    FFlagExpChatAddressFrame0Flash = 1767860814608  # Unknown = 
    FFlagExpChatAlignSystemMessageStyling = 1767900737893  # Bool = true
    FFlagExpChatBackspaceExitsTargetChannelInGlobalTabs = 1767977068701  # Bool = false
    FFlagExpChatBubbleChatRerenderOnAncestryChange = 1768335080680  # Unknown = 
    FFlagExpChatCanShowFriendsTab = 1768133878096  # Unknown = 
    FFlagExpChatCanShowFriendsTabRC1 = 1768133844880  # Unknown = 
    FFlagExpChatChannelBarDropdownZIndexFix = 1768001177693  # Bool = false
    FFlagExpChatChannelTabSizingUpdate2 = 1768024570845  # Bool = false
    FFlagExpChatClearHiddenMessagesPostAgeCheck = 1767860836125  # Bool = false
    FFlagExpChatComposerFigmaParity = 1767860847197  # Bool = false
    FFlagExpChatConditionallyMountAppLayout2 = 1768028368413  # Bool = false
    FFlagExpChatContinuousDictation = 1768009967696  # Unknown = 
    FFlagExpChatDebounceRephraseIndexSelection = 1767913346704  # Unknown = 
    FFlagExpChatDictatedSpeechEnabled = 1768399796944  # Unknown = 
    FFlagExpChatDictation = 1768009960912  # Unknown = 
    FFlagExpChatDictation3 = 1768009964573  # Bool = false
    FFlagExpChatDictationFTUX = 1768444724232  # Unknown = 
    FFlagExpChatDictationFTUX2 = 1768112849437  # Bool = false
    FFlagExpChatDictationFadeOverride = 1768005238845  # Bool = false
    FFlagExpChatDictationIXPExposure = 1768112858525  # Bool = false
    FFlagExpChatDictationMicToastFix = 1768112851280  # Unknown = 
    FFlagExpChatDictationU13PolicyToast = 1768112852765  # Bool = false
    FFlagExpChatDisableUniverseBubbleChat2 = 1767641265040  # Unknown = 
    FFlagExpChatDoNotSetCursorPosition = 1767977073360  # Unknown = 
    FFlagExpChatDynamicV2Pool = 1768001219677  # Bool = false
    FFlagExpChatEmojiInputParity = 1768010013008  # Unknown = 
    FFlagExpChatEnableCrossAgeChatActivity = 1768001217949  # Bool = false
    FFlagExpChatEnableFOMOUpsell = 1767415653381  # Bool = false
    FFlagExpChatEnableFriendsTab = 1768133835984  # Unknown = 
    FFlagExpChatEnableFriendsTabRC1 = 1768133856784  # Unknown = 
    FFlagExpChatEnableGlobalChatSummarySystemMessage = 1768038225949  # Bool = false
    FFlagExpChatEnableGlobalOnlineCommand = 1767900774333  # Bool = true
    FFlagExpChatEnableNewBottomLockedScrollView = 1767583202653  # Bool = false
    FFlagExpChatEnablePresetChatBadgeFTUXExperimentation = 1767645301021  # Bool = false
    FFlagExpChatEnableTabsImpressionAnalytics = 1768001227549  # Bool = false
    FFlagExpChatEnableV2ChatWindow = 1767978555805  # Bool = false
    FFlagExpChatEnableV2ChatWindow6 = 1767847907093  # Bool = false
    FFlagExpChatEnableVirtualLocalOnlineCommand = 1767641267152  # Unknown = 
    FFlagExpChatEnableVoiceReverseNudge = 1768399781968  # Unknown = 
    FFlagExpChatEvictFloodcheckedFromWindowOrder = 1768005271837  # Bool = false
    FFlagExpChatExcludeFOMORenders = 1767860822992  # Unknown = 
    FFlagExpChatFixBackspaceNilTargetChannel = 1767641268829  # Bool = false
    FFlagExpChatFixChannelBarInitialWidth = 1768001196048  # Unknown = 
    FFlagExpChatFixChannelTabsMidExperienceToggle = 1768038214365  # Bool = false
    FFlagExpChatFixInputBarSendEligibility = 1767860846557  # Bool = false
    FFlagExpChatFixLocalUserVerifiedBadge = 1767860809437  # Bool = false
    FFlagExpChatFixRateLimitedMessageRemoval = 1768001177757  # Bool = false
    FFlagExpChatFixRateLimitedMessageRemoval2 = 1768001212125  # Bool = false
    FFlagExpChatFixTeamChangeOverwriteChannel = 1767641270032  # Unknown = 
    FFlagExpChatFixTopPaddingColor = 1768028365328  # Unknown = 
    FFlagExpChatFixWarmMountBottomLock = 1767977076317  # Bool = false
    FFlagExpChatFlipDictationPriority = 1768399796368  # Unknown = 
    FFlagExpChatFocusChannelBarSupport = 1768001189661  # Bool = false
    FFlagExpChatFocusViaLastModeFix = 1767989383696  # Unknown = 
    FFlagExpChatFocusViaLastModeFix2 = 1768112859344  # Unknown = 
    FFlagExpChatFocusablePlaceholderText = 1768107866589  # Bool = false
    FFlagExpChatFriendsTabUsePolicy = 1768027322256  # Unknown = 
    FFlagExpChatGlobalCommandAutocompletePrimaryAliasOnly = 1767989407248  # Unknown = 
    FFlagExpChatGuacChatDisabledReason = 1767583395472  # Unknown = 
    FFlagExpChatInputBarV2CornerAndTruncationFix = 1768107867088  # Unknown = 
    FFlagExpChatInputBarV2CustomSendButton = 1768107867357  # Bool = false
    FFlagExpChatKeepV2PoolMounted = 1768001201821  # Bool = false
    FFlagExpChatLimitScrollingV2Window = 1767977089565  # Bool = false
    FFlagExpChatLogGlobalChatTabClicked = 1768001176157  # Bool = false
    FFlagExpChatLogTabClicked = 1768001176272  # Unknown = 
    FFlagExpChatLongPressContinuousDictation = 1768009988637  # Bool = false
    FFlagExpChatMainInputBarClickAnalytics = 1768112861213  # Bool = false
    FFlagExpChatMemoBillboardGui = 1768399770000  # Unknown = 
    FFlagExpChatMessagesStoreBatch = 1768005246877  # Bool = false
    FFlagExpChatMessagesStoreKeepInByMessageId = 1768005251549  # Bool = false
    FFlagExpChatMessagesStoreMemoryCleanup = 1768005242013  # Bool = false
    FFlagExpChatMessagesStoreUseProxy = 1768005246365  # Bool = false
    FFlagExpChatMicBubbleSingleImage = 1768399799440  # Unknown = 
    FFlagExpChatMigrateScrollIntervalTracker = 1767860805840  # Unknown = 
    FFlagExpChatMigrationReplicationFix = 1768133821840  # Unknown = 
    FFlagExpChatMoveMessagesStoreToInit = 1768001236253  # Bool = false
    FFlagExpChatMuteByUserIdBeforeUsernameCheck = 1768001233181  # Bool = false
    FFlagExpChatNewInputBar = 1768399782160  # Unknown = 
    FFlagExpChatNewInputBar4 = 1768399776016  # Unknown = 
    FFlagExpChatNewInputBarDictation = 1768112856976  # Unknown = 
    FFlagExpChatOnlyWakeTextForSelectedTab = 1768038221392  # Unknown = 
    FFlagExpChatPerfTrackerTabName = 1767860808784  # Unknown = 
    FFlagExpChatPolishSummaryMessageUI = 1768024534800  # Unknown = 
    FFlagExpChatPresetAutocompleteIxpEnabled = 1768112859677  # Bool = false
    FFlagExpChatPresetBoltInMessageLayout = 1767860811229  # Bool = false
    FFlagExpChatPresetButtonOldInputBarV2 = 1768028366096  # Unknown = 
    FFlagExpChatPresetChatAutocompleteAnalyticsEnabled = 1768112854800  # Unknown = 
    FFlagExpChatPresetChatAutocompleteEnabled = 1768036572677  # Bool = false
    FFlagExpChatPresetChatEnabled10 = 1767641269341  # Bool = false
    FFlagExpChatPresetChatFixesEnabled = 1768028369117  # Bool = false
    FFlagExpChatPresetChatGamepadEnabled = 1768107867984  # Unknown = 
    FFlagExpChatPresetChatIXPExposure = 1768112857501  # Bool = false
    FFlagExpChatPresetChatLoadTestEnabled = 1767641269661  # Bool = false
    FFlagExpChatPresetChatSendEnabled = 1767900760205  # Bool = true
    FFlagExpChatPresetChatVREnabled = 1767641269213  # Bool = false
    FFlagExpChatPresetFixChatHotkey = 1768028367568  # Unknown = 
    FFlagExpChatReconcileOnAgeVerifiedChange = 1768038214032  # Unknown = 
    FFlagExpChatRefactorEnabledMessageLogic = 1768389375069  # Bool = false
    FFlagExpChatRemoveBubbleChatAppUserMessagesState = 1768365406725  # Bool = false
    FFlagExpChatRemoveSpaceFromTeamPrefix = 1768218608240  # Unknown = 
    FFlagExpChatReportChatEnabledUserCountMetrics = 1768389367696  # Unknown = 
    FFlagExpChatReportVirtualCommandTelemetry = 1776007067941  # Bool = false
    FFlagExpChatRewriteInline = 1768001240605  # Bool = false
    FFlagExpChatRewriteInline3 = 1768001207645  # Bool = false
    FFlagExpChatRewriteInlineIxpEnabled = 1768001213277  # Bool = true
    FFlagExpChatRewriteToggleAnalytics = 1768001178973  # Bool = true
    FFlagExpChatScrollbarInset = 1767977116752  # Unknown = 
    FFlagExpChatSelectTextChatTabByName = 1768133846544  # Unknown = 
    FFlagExpChatSendWindowScrollEvent = 1767977116368  # Unknown = 
    FFlagExpChatShowPresetTooltipToNonAgeChecked2 = 1768488535088  # Unknown = 
    FFlagExpChatSuppressGlobalSummaryTabUnread = 1768038227357  # Bool = false
    FFlagExpChatSuppressWelcomeMessageTabUnread = 1767641270928  # Unknown = 
    FFlagExpChatSyntheticSystemMessageRichText = 1767641271581  # Bool = false
    FFlagExpChatTelemetryEventTrigger3 = 1767900731149  # Bool = true
    FFlagExpChatTopBannerForPresetChatAccess = 1768001191389  # Bool = false
    FFlagExpChatTopBannerZIndexFix = 1768296733520  # Unknown = 
    FFlagExpChatTranslationToggleSpacingFix = 1768001207517  # Bool = false
    FFlagExpChatTransparentFocusSupport = 1768005249309  # Bool = false
    FFlagExpChatTriggerWindowStatusEvent = 1768028370256  # Unknown = 
    FFlagExpChatUniverseChatPresetEnabled = 1767989426909  # Bool = false
    FFlagExpChatUniverseChatPresetEnabled2 = 1768036594589  # Bool = true
    FFlagExpChatUnreadTabIndicatorV2Window = 1768218575517  # Bool = true
    FFlagExpChatUseAdorneeStore = 1768133837520  # Unknown = 
    FFlagExpChatUseAdorneeStoreV4 = 1768133824784  # Unknown = 
    FFlagExpChatUseChannelTabsStore = 1768133827741  # Bool = true
    FFlagExpChatUseChannelTabsStore3 = 1768133826205  # Bool = true
    FFlagExpChatUseChatConfigStore = 1768133834960  # Unknown = 
    FFlagExpChatUseChatMuteStore = 1768133849168  # Unknown = 
    FFlagExpChatUseGuacForCrossAgeChat = 1767583403216  # Unknown = 
    FFlagExpChatUseGuacForFOMOUpsell = 1767583402896  # Unknown = 
    FFlagExpChatUseInternalTextChatAPIs2 = 1768133829072  # Unknown = 
    FFlagExpChatUseMessagesStore = 1768133823376  # Unknown = 
    FFlagExpChatUseMessagesStore9 = 1768133856733  # Bool = true
    FFlagExpChatUseProximityStore = 1768133875728  # Unknown = 
    FFlagExpChatUseSharedChannelTabDisplayLabel2 = 1768133849808  # Unknown = 
    FFlagExpChatUseTooltipPromptStyle = 1768399786896  # Unknown = 
    FFlagExpChatUseUnifiedTooltipStore = 1767900760269  # Bool = true
    FFlagExpChatUseUpdatedMessageRendered = 1768399815568  # Unknown = 
    FFlagExpChatUseUpdatedUserCountStrings = 1767641265744  # Unknown = 
    FFlagExpChatUseVirtualCommandRunner = 1768399797520  # Unknown = 
    FFlagExpChatUseVoiceParticipantsStore2 = 1768133869776  # Unknown = 
    FFlagExpChatWindowSyncUnibar = 1768009958173  # Bool = false
    FFlagExpDetailsUseSelectionBumpers = 1768001953469  # Bool = true
    FFlagExperienceBannerImageAllowCustomDimensions = 1767649977437  # Bool = false
    FFlagExperienceBannerImageDefaultFallback = 1767649978013  # Bool = false
    FFlagExperienceChatUserProfileApiEnabledForAll_v1 = 1768001236829  # Bool = false
    FFlagExperienceLoadingScreenFixStyleLink = 1768060652125  # Bool = false
    FFlagExperienceMenuGamepadExposureEnabled = 1767828577040  # Unknown = 
    FFlagExperienceMenuGamepadExposureEnabled684 = 1767828575696  # Unknown = 
    FFlagExperienceShopGlobalIconSkipCoreGuiCheck = 1768317829968  # Unknown = 
    FFlagExperiencesOnProfile = 1768009964432  # Unknown = 
    FFlagExperiencesOnProfile_v2 = 1768010006800  # Unknown = 
    FFlagExtendScrollingFramesBySafeInsets2 = 1767470827933  # Bool = false
    FFlagFFlagAXFixAvatarSaveContext = 1767650018717  # Bool = false
    FFlagFFlagAddDefaultFocusNavSelectorsOnBuyPurchasePrompt = 1768125829277  # Bool = false
    FFlagFFlagBlackbirdUpdateStringFlyoutMenu = 1768027284432  # Unknown = 
    FFlagFFlagDebugInlineLayout = 1767643498704  # Unknown = 
    FFlagFFlagEnableCallingLogoutOnResetIXP = 1767720502544  # Unknown = 
    FFlagFFlagEnableFontStylisticAlternativesOnSocialScreens = 1768133834704  # Unknown = 
    FFlagFFlagEnableLookFavoriting = 1767650017744  # Unknown = 
    FFlagFFlagEnableMutexOnGenericChallengeInterceptorMount = 1768017097360  # Unknown = 
    FFlagFFlagFixDetailsPageIconShadowSlicing = 1768017211472  # Unknown = 
    FFlagFFlagFixLayeredSorting = 1768393719760  # Unknown = 
    FFlagFFlagLogAllGuacRead = 1768297319312  # Unknown = 
    FFlagFFlagLogFirstGuacRead = 1768297319248  # Unknown = 
    FFlagFFlagLuaAppEnableWindowsHandheldScale = 1767989424605  # Bool = false
    FFlagFFlagLuaAppFixToastNotificationClosePosition = 1768017052496  # Unknown = 
    FFlagFFlagPCMAcceptWidthAsProp = 1767473193104  # Unknown = 
    FFlagFFlagSongEdpCarouselIxp2 = 1767526107088  # Unknown = 
    FFlagFFlagTimeoutRemoteEvent = 1768132416285  # Bool = false
    FFlagFFlagUpdateNoInternetConnectionText = 1768393710608  # Unknown = 
    FFlagFacialAnimationStreamingClearAllConnectionsFix2 = 1767899844445  # Bool = false
    FFlagFacialAnimationStreamingClearTrackImprovementsV2 = 1767899844061  # Bool = false
    FFlagFacialAnimationStreamingFixNilMutedCheck = 1767899844560  # Unknown = 
    FFlagFacialAnimationStreamingIfNoDynamicHeadDisableA2C = 1767899844637  # Bool = false
    FFlagFacialAnimationStreamingSearchForReplacementWhenRemovingAnimator = 1767899844189  # Bool = false
    FFlagFacialAnimationStreamingValidateAnimatorBeforeRemoving = 1767899844125  # Bool = false
    FFlagFeedbackEntryPointButtonSizeAdjustment2 = 1767913346845  # Bool = false
    FFlagFeedbackEntryPointImprovedStrictnessCheck = 1767913347293  # Bool = false
    FFlagFilterNewPlayerListValueStat = 1768132533469  # Bool = false
    FFlagFilterOutDeletedAccountsGameInvites = 1768150397661  # Bool = true
    FFlagFilterOutShopOnlyItemsonBulkPurchase = 1767828602768  # Unknown = 
    FFlagFilterSecurityAlertsVRToastEnabled = 1767583559760  # Unknown = 
    FFlagFindFriendsClickedEventEnabled = 1768181150416  # Unknown = 
    FFlagFireErrorRCCTimeoutSignal = 1767473189725  # Bool = false
    FFlagFix10ftGlobalNavSelection = 1768027264477  # Bool = true
    FFlagFixAbuseReportInExpPhantomAnalytics = 1768317812688  # Unknown = 
    FFlagFixAccountSwitcherOverlayBackgroundTap = 1767526157469  # Bool = false
    FFlagFixAnalyticsForDynamicReportV2 = 1767583570832  # Unknown = 
    FFlagFixAppNavContainerShortcutBarHeight = 1768399771344  # Unknown = 
    FFlagFixBackOnTopBarTriggeringDevUI = 1767424982493  # Bool = false
    FFlagFixBannerButtonSize = 1767650184976  # Unknown = 
    FFlagFixBulkPurchaseInputPerf = 1767908742864  # Unknown = 
    FFlagFixBulkPurchaseStarterGuiRename = 1767908743581  # Bool = false
    FFlagFixBundlePromptThumbnail = 1776067319760  # Unknown = 
    FFlagFixBundleThumbnailOnDetailPage = 1767899806352  # Unknown = 
    FFlagFixBuyRobuxForAndroid = 1767908743453  # Bool = false
    FFlagFixCameraSetupBeforeMood = 1767462818717  # Bool = false
    FFlagFixCarouselTileSizeScaling = 1767641312464  # Unknown = 
    FFlagFixCharacterManagerValueConversionWarning = 1767654059805  # Bool = false
    FFlagFixCharacterNameHandlerNilProfileCrash = 1767908711965  # Bool = false
    FFlagFixChatLanguageSwitcherLabel = 1767913342365  # Bool = false
    FFlagFixChatsBottomInsetBackgroundColor = 1767641272656  # Unknown = 
    FFlagFixCohubExposureLayer = 1768009969872  # Unknown = 
    FFlagFixCohubSearchYNavigation = 1768009975824  # Unknown = 
    FFlagFixCohubUiBugs = 1768009994832  # Unknown = 
    FFlagFixConnectTabSearchBarHeight = 1768133844752  # Unknown = 
    FFlagFixConsoleEDPDirectionalNavigation = 1768017230096  # Unknown = 
    FFlagFixContextualMenu = 1767425957469  # Bool = true
    FFlagFixCountersForUpsellModalShown = 1767897045085  # Bool = false
    FFlagFixCrossExperienceVoiceExecutePrint = 1767831082960  # Unknown = 
    FFlagFixCyclicFullscreenIndexEvent = 1767913345821  # Bool = false
    FFlagFixDefaultThemeOverride = 1767831072528  # Unknown = 
    FFlagFixDetailsPageIconShadowSlicing = 1767425608605  # Bool = false
    FFlagFixDeveloperConsoleButtonSizeAndPositioning = 1767913346269  # Bool = false
    FFlagFixDeviceSafePaddingAccess = 1768017231696  # Unknown = 
    FFlagFixDisableTopPaddingError = 1768132560669  # Bool = false
    FFlagFixDisabledScrollOnIos = 1768132566365  # Bool = false
    FFlagFixDoubleSubmit = 1767648650269  # Bool = false
    FFlagFixDrawerNavigateBackWhileClosing = 1767831045597  # Bool = false
    FFlagFixEmptyLimitedBadges = 1767650024733  # Bool = false
    FFlagFixEmptyLimitedBadgesForBundles = 1767650022096  # Unknown = 
    FFlagFixFeedItemRenderedRowsEqualityCheck = 1767650011293  # Bool = false
    FFlagFixFetchNextOmniWithoutPageToken3 = 1767649979485  # Bool = false
    FFlagFixFiatPaidAccessPlayButton = 1767640197213  # Bool = false
    FFlagFixFocusWhenInGameMenuIsOpen = 1768017050717  # Bool = true
    FFlagFixFullscreenTitleBarPromiseCancel = 1775992631568  # Unknown = 
    FFlagFixGameInviteModalLoadTimeIncrease = 1776125366736  # Unknown = 
    FFlagFixGetPlayerByUserIdStringCast = 1767645292176  # Unknown = 
    FFlagFixGlobalChat3pSummarySystemMessage = 1768038226781  # Bool = false
    FFlagFixHeadShapeColorSlider = 1767977082192  # Unknown = 
    FFlagFixIGMTabTransitions = 1767913318800  # Unknown = 
    FFlagFixInactiveChildStateForwarding = 1767831087568  # Unknown = 
    FFlagFixIosAuthServiceCredentialSheetBackends = 1768387534928  # Unknown = 
    FFlagFixIosOtpAutofill = 1768389370896  # Unknown = 
    FFlagFixIsConsoleCheckForSocialCarousel = 1767583391709  # Bool = false
    FFlagFixJoinVoiceDelayedAFMInit = 1767913295517  # Bool = false
    FFlagFixLayeredSorting = 1767424955741  # Bool = false
    FFlagFixLimitedBundleResalePrerequisite = 1776067298128  # Unknown = 
    FFlagFixLocalizationOfMissingAgreementTitles = 1767473191389  # Bool = true
    FFlagFixLocalizationOfStudioTermsForVNGSKU = 1767473190480  # Unknown = 
    FFlagFixLoginV2LandscapeLayout = 1767831084176  # Unknown = 
    FFlagFixMediaGalleryOversized = 1768215380368  # Unknown = 
    FFlagFixMomentsExperienceFallback = 1767828556496  # Unknown = 
    FFlagFixMomentsTabReactiveIXPRace = 1767470814928  # Unknown = 
    FFlagFixMoreSubMenuTitleFlash = 1768399776208  # Unknown = 
    FFlagFixNavBarStartupDuplicateAnim = 1767654043613  # Bool = false
    FFlagFixNavigationInsetsOnHiddenTabBar = 1767828572560  # Unknown = 
    FFlagFixNonTruncatedText = 1767654047453  # Bool = false
    FFlagFixOffSaleCurrentlyWearingItemNavigation = 1767470837213  # Bool = false
    FFlagFixOnBadgeAwardedError = 1768133935069  # Bool = false
    FFlagFixOneNameManyFacesDisconnectCrash = 1767908721181  # Bool = false
    FFlagFixPartyNudgeNilThunkWhenLeave = 1768050322896  # Unknown = 
    FFlagFixPartyVoiceGetPermissions2 = 1767583396765  # Bool = false
    FFlagFixPeekViewAnimationJitter = 1768017215504  # Unknown = 
    FFlagFixPeoplePageCardTooltip = 1768389373968  # Unknown = 
    FFlagFixPlainTextAutomaticSizeClippingText = 1768297307600  # Unknown = 
    FFlagFixPlatformRestrictedHomeClobber = 1767831069136  # Unknown = 
    FFlagFixPlayerGuiSelectionBugOnPromptExit = 1767897048413  # Bool = false
    FFlagFixPolicyStalePlayerUpdates = 1768297319568  # Unknown = 
    FFlagFixPromptGameInviteUIButtonScaling = 1767411151944  # Unknown = 
    FFlagFixPurchasingErrorCounter = 1776067313680  # Unknown = 
    FFlagFixReportAdInfoDuringRotation = 1768060622928  # Unknown = 
    FFlagFixReportButtonCutOff = 1767913319197  # Bool = false
    FFlagFixResaleDisplayPrice = 1776067289565  # Bool = false
    FFlagFixSTUXShowingIncorrectly = 1768001210512  # Unknown = 
    FFlagFixSafetyBubbleWidth = 1767913656213  # Bool = false
    FFlagFixSduiCardFocusNavScroll = 1767526000016  # Unknown = 
    FFlagFixSduiEdpTtiPeekCategory = 1768458310224  # Unknown = 
    FFlagFixSeamlessVoiceIntegrationWithPrivateVoice2 = 1767583394576  # Unknown = 
    FFlagFixSelectionWithWebViews = 1767831088272  # Unknown = 
    FFlagFixSettingshubImportOrder = 1768389355165  # Bool = false
    FFlagFixSignalFinishedOnError = 1767643496285  # Bool = false
    FFlagFixSpatialUICaptures = 1767583390736  # Unknown = 
    FFlagFixSquadTopBannerMemo = 1767650167376  # Unknown = 
    FFlagFixTabletEDPNavBarVisibility = 1767654045712  # Unknown = 
    FFlagFixTimedOptionRefresh = 1776067301853  # Bool = false
    FFlagFixToastNotificationRightPosition = 1767404770077  # Bool = true
    FFlagFixUnifiedPurchaseResalePurchases = 1767977063312  # Unknown = 
    FFlagFixUnifiedUpsellCompletionModal = 1768125852509  # Bool = false
    FFlagFixUnnecessaryPaddingInUnifiedPurchaseModal = 1767427340381  # Bool = false
    FFlagFixUpsellModalUnevenLayout = 1768125849309  # Bool = false
    FFlagFixUpsellVerificationToNavigateToOverlays = 1768389355037  # Bool = false
    FFlagFixUseDeviceOrientationNilViewportSize = 1767473174480  # Unknown = 
    FFlagFixUserInfoSelection = 1767650178512  # Unknown = 
    FFlagFixUserInfoWidgetPlusBadge = 1768027306576  # Unknown = 
    FFlagFixUserRowCombinedName = 1767583519248  # Unknown = 
    FFlagFixUsernameSelectionStuck = 1767650177936  # Unknown = 
    FFlagFixUsernameValidationAlreadyInUse = 1768005259024  # Unknown = 
    FFlagFixUsernameValidationBackendCriteria = 1767526242461  # Bool = false
    FFlagFixVRAvatarPlacement = 1767654059165  # Bool = false
    FFlagFixVRBottomBarAnalytics = 1768162825885  # Bool = false
    FFlagFixVirtualizedGridNumItems = 1768389408976  # Unknown = 
    FFlagFixWindowDragError = 1775992585104  # Unknown = 
    FFlagFixWindowDragStaleConnection = 1775992570256  # Unknown = 
    FFlagFlyoutDisablePremiumEntrypoint1 = 1768297325277  # Bool = true
    FFlagFlyoutDisallowAlternativeEntryOnProfileEntryEnabled = 1767989381968  # Unknown = 
    FFlagFlyoutEnableGiftcardsWithRedeem = 1768297285213  # Bool = true
    FFlagFlyoutFacepileEnableProfileEntry = 1767989401424  # Unknown = 
    FFlagFlyoutHamburgerEnableProfileEntry = 1768019127709  # Bool = true
    FFlagFlyoutHideFriendsHeader = 1767641308253  # Bool = false
    FFlagFlyoutNavigationInMarketplace = 1767831063312  # Unknown = 
    FFlagFlyoutRemoveAddSessionInfo = 1767470905973  # Bool = false
    FFlagFlyoutResolveItemContextOnActivation = 1768444149493  # Bool = false
    FFlagFlyoutShowFriendsSortForCurrentVariant = 1767989396944  # Unknown = 
    FFlagFlyoutSidePanelTradesEntry = 1775910054608  # Unknown = 
    FFlagFlyoutUseOpenHook = 1767470829149  # Bool = false
    FFlagFocusRootUseHooks = 1767640172957  # Bool = false
    FFlagForceAegisPhase2Modal = 1767650006365  # Bool = false
    FFlagForceEnableArgoPartyChanges7 = 1767645302173  # Bool = false
    FFlagForceEnableExpChatNewSystemMessages = 1767645299216  # Unknown = 
    FFlagForceEnableLuckyRecommendation = 1767583398864  # Unknown = 
    FFlagForceEnablePartyCoordinationUiChanges3 = 1767645305808  # Unknown = 
    FFlagForceEnableQueueAutoJoinNewServer2 = 1767645303709  # Bool = false
    FFlagForceEnableQueueJoinNewServerButton2 = 1767645304285  # Bool = false
    FFlagForceEnableSocialCarouselPartyPage5 = 1767645311261  # Bool = false
    FFlagForceEnableSquad = 1767583399120  # Unknown = 
    FFlagForceEnableSquadRegroup = 1767583520848  # Unknown = 
    FFlagForceGetGameIconsFromThumbnailsDeliveryApi = 1767525997149  # Bool = true
    FFlagForceReportAnythingAnnotationEnabled = 1767831105168  # Unknown = 
    FFlagFoundationActionEmphasisStatusIndicator = 1767831094416  # Unknown = 
    FFlagFoundationAvatarBeta3 = 1767831088848  # Unknown = 
    FFlagFoundationAvatarBindableUserId = 1767831049488  # Unknown = 
    FFlagFoundationAvatarIncludeProfileFrame = 1767831080592  # Unknown = 
    FFlagFoundationBadgeBetaUpdate3 = 1767860800221  # Bool = false
    FFlagFoundationBaseMenuContentSizing = 1767831072080  # Unknown = 
    FFlagFoundationBaseMenuSubmenuMaxHeight = 1767831096080  # Unknown = 
    FFlagFoundationBottomSheetFixHeightCap = 1767831102160  # Unknown = 
    FFlagFoundationBottomSheetGestureInteractionSink = 1767831058704  # Unknown = 
    FFlagFoundationBottomSheetOnSnapPointChanged = 1767831065424  # Unknown = 
    FFlagFoundationBottomSheetScrollAtMaxTolerance = 1767831055760  # Unknown = 
    FFlagFoundationButtonLabelTypography = 1767831084496  # Unknown = 
    FFlagFoundationCheckboxBeta = 1767831104656  # Unknown = 
    FFlagFoundationCoachmarkPressedOutside = 1767860855261  # Bool = false
    FFlagFoundationDateTimePickerBetaUpdate = 1767860798621  # Bool = false
    FFlagFoundationDateTimePickerDSTFix = 1767426990800  # Unknown = 
    FFlagFoundationDialogBetaUpdate = 1767860810013  # Bool = false
    FFlagFoundationDisableTokenScaling2 = 1767831108688  # Unknown = 
    FFlagFoundationDropdownSelectionProps = 1767831077584  # Unknown = 
    FFlagFoundationDropdownSizeGap = 1767831083536  # Unknown = 
    FFlagFoundationFixTabsBorderPosition = 1767860818589  # Bool = false
    FFlagFoundationFixTabsFitBorderWidth2 = 1767831106768  # Unknown = 
    FFlagFoundationGuiObjectInputSinkProperty = 1767831105936  # Unknown = 
    FFlagFoundationImageContentSupport = 1767831106384  # Unknown = 
    FFlagFoundationIncludeSpaceRequiredLabel = 1767860803485  # Bool = false
    FFlagFoundationInputGroup = 1767831104848  # Unknown = 
    FFlagFoundationInteractableSecondaryActivated = 1767831093968  # Unknown = 
    FFlagFoundationInternalInputBeta2 = 1767831097744  # Unknown = 
    FFlagFoundationListItemDecoupledInput = 1767860807773  # Bool = false
    FFlagFoundationListItemTypographySpacing = 1767860859165  # Bool = false
    FFlagFoundationListStableContextValue = 1767860827421  # Bool = false
    FFlagFoundationNumberInputBeta = 1767831047504  # Unknown = 
    FFlagFoundationNumberInputOnTextChanged = 1767831081360  # Unknown = 
    FFlagFoundationNumberInputScrubCallbackProps = 1767860858205  # Bool = false
    FFlagFoundationOptionSelectorGroupBeta = 1767860841693  # Bool = false
    FFlagFoundationOptionSelectorGroupFixes = 1767831070736  # Unknown = 
    FFlagFoundationOverlayResilientMainGui = 1767831062800  # Unknown = 
    FFlagFoundationPopoverClickOutsideInGuiShadow = 1767860856989  # Bool = false
    FFlagFoundationPopoverContentAnchorFix = 1767860844189  # Bool = false
    FFlagFoundationPopoverPluginAnchorRefresh = 1767860845981  # Bool = true
    FFlagFoundationPopoverPluginOverlayMeasurement2 = 1767831046800  # Unknown = 
    FFlagFoundationPopoverRecomputeContentSize = 1767860848669  # Bool = false
    FFlagFoundationProgressBarBetaUpdate = 1767860858141  # Bool = false
    FFlagFoundationProgressCircleRoundCaps = 1767860859549  # Bool = false
    FFlagFoundationRadioBeta = 1767831100368  # Unknown = 
    FFlagFoundationRemoveSecondUIDDFromScrubbableTextboxes = 1767831058896  # Unknown = 
    FFlagFoundationSegmentedControlBeta = 1767860844381  # Bool = true
    FFlagFoundationSkeletonCommonShimmerToken = 1767860815197  # Bool = false
    FFlagFoundationSliderAsSeenOnTV = 1767831092560  # Unknown = 
    FFlagFoundationSliderOffloadDraggingMath = 1767831073488  # Unknown = 
    FFlagFoundationStableContextValues = 1767860855965  # Bool = false
    FFlagFoundationStatusIndicatorVariantExperiment2 = 1767720501781  # Bool = false
    FFlagFoundationStyleSheetRefCounting = 1767831098704  # Unknown = 
    FFlagFoundationStylingOnSignUp = 1767828611856  # Unknown = 
    FFlagFoundationStylingOnSignUp3 = 1767828610640  # Unknown = 
    FFlagFoundationThemeName = 1767831097488  # Unknown = 
    FFlagFoundationToggleBetaUpdate = 1767796971184  # Unknown = 
    FFlagFoundationTokenOverrides2 = 1767831087888  # Unknown = 
    FFlagFoundationTooltipBeta = 1767860821533  # Bool = false
    FFlagFoundationTooltipPressedOutside = 1767860843613  # Bool = false
    FFlagFoundationUnifiedScrimScrolling = 1767860851933  # Bool = false
    FFlagFoundationUsePath2DSpinner = 1767831103504  # Unknown = 
    FFlagFoundationViewMemoizationChanges = 1767831052176  # Unknown = 
    FFlagFoundationWidgetManagerSnapshotFlush = 1767860840989  # Bool = false
    FFlagFriendCarouselHas10ftPolicies = 1767649997917  # Bool = false
    FFlagFriendRequestModalIxpEnabled = 1768017068368  # Unknown = 
    FFlagFriendRequestModalRevampV4 = 1768017067536  # Unknown = 
    FFlagFriendRequestNicknames = 1768133854928  # Unknown = 
    FFlagFriendRequestNicknamesUIBugFixes = 1767648615389  # Bool = false
    FFlagFriendRequestNicknamesV9 = 1768133842192  # Unknown = 
    FFlagFriendSortedByPresenceSignalsImplementation_v2 = 1767473743509  # Bool = false
    FFlagFriendsActivityFeedEnabled = 1768009971216  # Unknown = 
    FFlagFriendsActivityFeedFetchItemNames = 1767900740333  # Bool = true
    FFlagFriendsCarouselProfileFrameEnabled = 1767965157269  # Bool = false
    FFlagFriendsCarouselUseFindFriendsOnDesktop = 1768133883024  # Unknown = 
    FFlagFriendsCarouselUseFindFriendsOnDesktop_v2 = 1768133877904  # Unknown = 
    FFlagFriendsChatConversationListFadeScrollbar = 1768028344413  # Bool = false
    FFlagFriendsChatConversationListShowScrollBar = 1768133862109  # Bool = true
    FFlagFriendsChatEnableConversationConsent = 1768297328349  # Bool = true
    FFlagFriendsChatEnforceInputCharacterLimit = 1768028356381  # Bool = false
    FFlagFriendsChatFacePileGroupPresence = 1768028352912  # Unknown = 
    FFlagFriendsChatNavIconSizeFixEnabled = 1767473190352  # Unknown = 
    FFlagFriendsChatOsaSystemMessage = 1768133866768  # Unknown = 
    FFlagFriendsChatPlaceholderRenameFix = 1767583538717  # Bool = true
    FFlagFriendsChatRefreshListForNewConversation = 1768038217501  # Bool = false
    FFlagFriendsCountDataHydrationMigrationEnabled = 1768009991504  # Unknown = 
    FFlagFriendsEmptyStateIllustrationTheming = 1768444527112  # Unknown = 
    FFlagFriendsMenuDummyLoadingFriendsFixV3 = 1767583540112  # Unknown = 
    FFlagFriendsMenuUseProfileFrameThumbnail = 1768150395997  # Bool = false
    FFlagFriendsPageAlwaysOpenPPV = 1768010016656  # Unknown = 
    FFlagFriendsPageUnifiedOpenProfileLogic = 1768009974813  # Bool = false
    FFlagFriendsPageUserListEnabled = 1768009981648  # Unknown = 
    FFlagFriendsPageUserListEnabled_v2 = 1768010018960  # Unknown = 
    FFlagFriendsPageViewBtnEnabled = 1767420354925  # Bool = false
    FFlagFriendsPageViewBtnWidth = 1767683775136  # Unknown = 
    FFlagFriendsSignalMigrationTelemetry = 1768133856464  # Unknown = 
    FFlagFriendsSignalMigrationTelemetry_v1 = 1768133823120  # Unknown = 
    FFlagFriendsStoreSortOnlineFriendsByRank = 1768010007568  # Unknown = 
    FFlagFriendshipNotifsUseSendrEnabledForAll = 1768133932829  # Bool = false
    FFlagFriendshipNotifsUseSendrExperiment = 1767611306640  # Unknown = 
    FFlagFriendshipNotifsUseSendrExperiment_v2 = 1768133933405  # Bool = false
    FFlagFriendshipNotifsUseSendrExperiment_v3 = 1767583560720  # Unknown = 
    FFlagFullscreenElementsIgnoreSafeArea = 1768399774608  # Unknown = 
    FFlagFullscreenTitleBarInjectGameServices = 1768162809949  # Bool = false
    FFlagGameInviteModalAnalyticsEmptyEventContextFix = 1776125411152  # Unknown = 
    FFlagGameInviteModalIncludeLinkIdInShareButton = 1776125360464  # Unknown = 
    FFlagGameInviteModalUnlockMouse = 1767583534045  # Bool = true
    FFlagGameInviteOpenModalWithoutBlockingOnCanPrompt = 1767583533789  # Bool = true
    FFlagGameJoinCardOnBeforeJoinCallback = 1768024533533  # Bool = false
    FFlagGameJoinTimeoutChatAttemptEnabled = 1767583562589  # Bool = true
    FFlagGameSettingsCameraModeFixEnabled = 1768458314896  # Unknown = 
    FFlagGameTileMigrateOffLegacyPresence = 1767526108368  # Unknown = 
    FFlagGamepadIconSupportCheck = 1767526240669  # Bool = false
    FFlagGamepadNavigationDialogABTest = 1767913671189  # Bool = false
    FFlagGamepadNavigationDialogABTest2 = 1775992618384  # Unknown = 
    FFlagGateAbuseReportInExpSceneSelectionOnIXP = 1768317825808  # Unknown = 
    FFlagGateEducationalPopupVisibilityViaGUAC = 1767828613456  # Unknown = 
    FFlagGateLeaderboardPlayerDropdownViaGUAC = 1767828579664  # Unknown = 
    FFlagGenerateLinkWithChannel = 1767583562384  # Unknown = 
    FFlagGenericAbuseReportingGranularExports = 1767583566301  # Bool = true
    FFlagGetFFlagCountryCodeBoldPrefixEnabled = 1768387546896  # Unknown = 
    FFlagGetFFlagLuaAppChallengeDialogContainerPageEnabled = 1767654042973  # Bool = false
    FFlagGetGameIconsFromThumbnailsDeliveryApiIxp = 1767525996573  # Bool = false
    FFlagGetHumanoidDescription = 1768027316944  # Unknown = 
    FFlagGetHumanoidDescriptionUpdates = 1768377229648  # Unknown = 
    FFlagGetHumanoidDescriptionUpdatesV2A = 1768383946448  # Unknown = 
    FFlagGetHumanoidDescriptionUpdatesV2B = 1768126151197  # Bool = false
    FFlagGetHumanoidDescriptionUpdatesV2E2 = 1767583563165  # Bool = true
    FFlagGlobalFocusFailureTelemetry = 1767640172701  # Bool = false
    FFlagGlobalTextChatAddPlaySessionField = 1768001178461  # Bool = false
    FFlagGranularExportsBucket = 1767650186896  # Unknown = 
    FFlagGridHomeUserInfoUseProfileFrameThumbnail = 1767723045328  # Unknown = 
    FFlagGuacAppPolicyDisableSignupCheckbox = 1768297279440  # Unknown = 
    FFlagGuacCanRenderTransferOnProfile = 1767583395792  # Unknown = 
    FFlagGuacDisableBlackbirdEntrypoints = 1768297287645  # Bool = true
    FFlagGuacStickyShortcutBarEnabled = 1768399789520  # Unknown = 
    FFlagGuardVoiceInExpUpsellVariant = 1767900772613  # Bool = true
    FFlagHeadRefinementFacialAnimationToggle = 1767977106973  # Bool = false
    FFlagHeadRefinementFacialAnimationToggle4 = 1767977077917  # Bool = false
    FFlagHelpPageIXPExposure = 1768438451805  # Bool = true
    FFlagHelpPageIXPExposure3 = 1768126100253  # Bool = false
    FFlagHelpPageMountVR = 1768438483037  # Bool = true
    FFlagHelpPageMountVR3 = 1768126099933  # Bool = false
    FFlagHiddenFriendsSortHeaderAddSubTabDependency = 1767989423248  # Unknown = 
    FFlagHiddenFriendsSortHeaderRemoveFlyoutDependency = 1767828571024  # Unknown = 
    FFlagHideConnectPageWebViewItemsForVRV2 = 1768458293392  # Unknown = 
    FFlagHideContextualButtonBasedOnStateForVR = 1768458307920  # Unknown = 
    FFlagHideDevSubsPriceIfSubscribed = 1767828567760  # Unknown = 
    FFlagHideLaunchAtStartupMac = 1768010004688  # Unknown = 
    FFlagHideLookDiscountPercentWithIneligibleItems = 1776067292637  # Bool = false
    FFlagHideNotificationIconForVR = 1767641274000  # Unknown = 
    FFlagHidePeoplePageInviteFriends = 1767828610077  # Bool = false
    FFlagHidePremiumIconography = 1768027310864  # Unknown = 
    FFlagHideShortcutsOnReportDropdown = 1767913355285  # Bool = false
    FFlagHideShortcutsWhileIemDropdownActive = 1768049876776  # Unknown = 
    FFlagHideVoiceChatSelectorForFae_AEGIS2 = 1767913338589  # Bool = false
    FFlagHighlightModePreciseSelectionEnabled3 = 1767583568989  # Bool = true
    FFlagHomePYMKUseProfileFrameThumbnail = 1767916299949  # Bool = false
    FFlagHomePagePromptsHandlerEnabled = 1768458294032  # Unknown = 
    FFlagHomePhoneVerificationUpsellNewCopy = 1776007030384  # Unknown = 
    FFlagHomepagePromptsPaddingFix = 1768458309776  # Unknown = 
    FFlagIAPExperienceEnableBestValueBadge = 1768125825181  # Bool = false
    FFlagIAPExperienceEnableMultiDisplayUpsellV3 = 1768125827677  # Bool = false
    FFlagIAPExperienceUseUpsellBadgeHelper = 1768125828573  # Bool = false
    FFlagIBEnableCollectiblesSystemSupport = 1767899795741  # Bool = false
    FFlagIBGateUGC4ACollectibleAssetsBundles1 = 1767899809168  # Unknown = 
    FFlagIDVGuardStartPollingAfterUnmount = 1767643521501  # Bool = false
    FFlagIEMFocusNavPeoplePageToButtons = 1767828563933  # Bool = false
    FFlagIEMFocusNavSupportNewButtons2 = 1768126101456  # Unknown = 
    FFlagIEMReportScrollingFix = 1768317803728  # Unknown = 
    FFlagIEMSettingsGroups = 1767913318357  # Bool = false
    FFlagIEMSettingsGroups709 = 1767913318416  # Unknown = 
    FFlagIEMSettingsLogExposureIXPFlags = 1768132555600  # Unknown = 
    FFlagIEMSettingsPageDisplaying = 1767583570320  # Unknown = 
    FFlagIEMTabFocusNav = 1767828578077  # Bool = false
    FFlagIEMTabFocusNav2 = 1767828593373  # Bool = false
    FFlagIGMAlwaysResetGfxLv5 = 1767913344029  # Bool = false
    FFlagIGMChangeCapturesToGallery = 1767807636013  # Bool = false
    FFlagIGMChangeGalleryHeaderIcon = 1767913664149  # Bool = false
    FFlagIGMEnableGFXReset = 1767913345104  # Unknown = 
    FFlagIGMGamepadSelectionHistory = 1775992602525  # Bool = false
    FFlagIGMResetGfxLv5Only = 1767913343965  # Bool = false
    FFlagIGMResetGfxQuality = 1767913343773  # Bool = false
    FFlagIGMRevertGfxLv5Only = 1767913343901  # Bool = false
    FFlagIGMRevertGfxQuality = 1767913343837  # Bool = false
    FFlagIGMSelectionGroup = 1768132566941  # Bool = false
    FFlagIXPServiceWrapperWaitRefactor = 1768399790864  # Unknown = 
    FFlagIconHostSetZIndexToDefault = 1767424958429  # Bool = false
    FFlagImmutableJoinDictionariesUseTableClone = 1767583404688  # Unknown = 
    FFlagImportVirtualCursorToUA = 1768010015824  # Unknown = 
    FFlagImproveIllegalContentReportingLinkLook = 1767977076240  # Unknown = 
    FFlagImprovePageTitleCloseButton = 1768132566749  # Bool = false
    FFlagImproveSearchSelectionUX2 = 1767650227024  # Unknown = 
    FFlagInAppBugReporterIxpBypass = 1767650180432  # Unknown = 
    FFlagInAppBugReporterIxpEnabled = 1767650180304  # Unknown = 
    FFlagInExperienceAddPhoneViewNewCopy = 1767583556624  # Unknown = 
    FFlagInExperienceAvatarSwitcherPlaceFilter = 1767526168784  # Unknown = 
    FFlagInExperienceContainerAppLinking = 1767583563920  # Unknown = 
    FFlagInExperienceContainerRespectUserTheme = 1767583568285  # Bool = true
    FFlagInExperienceContainerScreenSizeReducer = 1767583565648  # Unknown = 
    FFlagInExperienceInterventionApp = 1768133930909  # Bool = false
    FFlagInExperiencePhoneUpsellNewCopy = 1767583559453  # Bool = true
    FFlagInExperienceReportClosingBugfix = 1767828570448  # Unknown = 
    FFlagInExperienceRequestProfileSettings = 1768049885496  # Unknown = 
    FFlagInExperienceShopFtuxTooltip = 1768113113813  # Bool = true
    FFlagInExperienceUseAppStyleProvider = 1767828567005  # Bool = false
    FFlagInExperienceUserProfileSettingsEnabled = 1768049898536  # Unknown = 
    FFlagInExperienceUserProfileSettingsEnabled_v3 = 1768133914141  # Bool = false
    FFlagInGameLargerRobuxUpsellEnabled = 1776067327389  # Bool = false
    FFlagInGameLargerRobuxUpsellIXP = 1776067343645  # Bool = false
    FFlagInGameLargerRobuxUpsellIXPRolledOut = 1776067323869  # Bool = false
    FFlagIncludeWaitingForPartyInCondition = 1768024527005  # Bool = false
    FFlagIncreaseLegacyPeopleRowButtonSize = 1767998348957  # Bool = false
    FFlagIncreaseLoadingScreenOrder = 1767831063248  # Unknown = 
    FFlagIncreaseMarketplaceContentHeight = 1767831062608  # Unknown = 
    FFlagIncreaseUtilityRowTextSizeConsole = 1768001217808  # Unknown = 
    FFlagInitializeAutocompleteOnlyIfEnabled = 1776002185248  # Unknown = 
    FFlagInjectAnalyticsService = 1767650180560  # Unknown = 
    FFlagInlineRichTextUseWebViewService = 1767831081424  # Unknown = 
    FFlagInlineSurveyBranching = 1767583564765  # Bool = true
    FFlagInlineSurveyChoiceTextEntry = 1767583564957  # Bool = true
    FFlagInlineSurveyEnhancements = 1768372141840  # Unknown = 
    FFlagInlineSurveyEnhancements2 = 1767583564317  # Bool = true
    FFlagInlineSurveyFocusRoot = 1768317814429  # Bool = false
    FFlagInlineSurveyOnInExpReport = 1768317787216  # Unknown = 
    FFlagInlineSurveyPartialResponse = 1775988827528  # Unknown = 
    FFlagInspectAndBuyFixStyleLink = 1775992574288  # Unknown = 
    FFlagIntegrateDiscountsWithEDP = 1767831095120  # Unknown = 
    FFlagIntegrateDiscountsWithEDP2 = 1767831093904  # Unknown = 
    FFlagIntegratePhoneUpsellJoinVoice = 1767583559133  # Bool = true
    FFlagIntegrateTraversalHistoryInSideSheet2 = 1767828612317  # Bool = false
    FFlagIntegrationsChromeShortcutTelemetry = 1768049872376  # Unknown = 
    FFlagInternationalNamesEnabledForAll = 1767654041232  # Unknown = 
    FFlagIntroduceMetricsLegacyUpsell = 1768125836317  # Bool = false
    FFlagInviteListRerank = 1767805911696  # Unknown = 
    FFlagIsPublishOnBuildRevert = 1768136702557  # Bool = false
    FFlagIsSquadCoordinationExperienceJoinExperimentExposureEnabled = 1767645305424  # Unknown = 
    FFlagIsSquadLobbySessionEnabled = 1767645305488  # Unknown = 
    FFlagIssueTrackerUseFoundationIcon = 1768387563280  # Unknown = 
    FFlagItemImpressionsAddGameMetadata = 1767526032400  # Unknown = 
    FFlagJoinCardAgeCheckUpsell_V3 = 1767583523536  # Unknown = 
    FFlagJoinGameCardPassThroughUniversePlaceInfoFromFriendsCarousel = 1768133821328  # Unknown = 
    FFlagJoinGameCardViewProfileNavigateToProfilePlatform = 1767473743493  # Bool = false
    FFlagJoinWithoutMicPermissions3 = 1768133848208  # Unknown = 
    FFlagKISAUserAgreementsRedesign = 1767720488272  # Unknown = 
    FFlagKeepDarkThemeOverrideWhenLoggedOut = 1767831068816  # Unknown = 
    FFlagKeepSideSheetOpenFromGrid = 1767998335517  # Bool = false
    FFlagLazyInitiateExperienceLanguageSwitcher = 1767913348573  # Bool = false
    FFlagLazyPerfStatsInit = 1768132422429  # Bool = false
    FFlagLeaderstatsWithASideOfClient = 1768136645469  # Bool = false
    FFlagLeaveActionChromeShortcutTelemetry = 1767913625685  # Bool = false
    FFlagLeaveChromeShortcutTelemetry = 1767913625813  # Bool = false
    FFlagLeaveSquadIfChatDisabled = 1768050311248  # Unknown = 
    FFlagLocalUserGameVoteCounterReducer = 1767650006864  # Unknown = 
    FFlagLocalizeGameplayPaused = 1767899820381  # Bool = false
    FFlagLocalizeMenuNavigationToggleDialog = 1767913671317  # Bool = false
    FFlagLogAllGuacRead = 1768175975677  # Bool = false
    FFlagLogFirstGuacRead = 1768175970749  # Bool = false
    FFlagLogInputTypeChangedTvRemote1 = 1768399081725  # Bool = false
    FFlagLogKeyboardFocusModeEntered = 1767654090397  # Bool = false
    FFlagLogSessionOnOrientationChange = 1768017214672  # Unknown = 
    FFlagLoggingGamepadOpenExpControlsMenu = 1768136639069  # Bool = false
    FFlagLoggingRethrowUsingError = 1767583424541  # Bool = false
    FFlagLoginV2FullFlowDevOverride = 1767831084048  # Unknown = 
    FFlagLogoutPhoneVerificationUpsellCopy = 1767611310608  # Unknown = 
    FFlagLogoutPhoneVerificationUpsellCopy_v3 = 1767583553424  # Unknown = 
    FFlagLowCogsBannerExperiment = 1767526166365  # Bool = false
    FFlagLowCogsBannerInfoIcon = 1768125834397  # Bool = false
    FFlagLuaAppAbuseReportAnalyticsHasLaunchData = 1767901848733  # Bool = false
    FFlagLuaAppAccountSecurityPromptEnabled = 1767654064784  # Unknown = 
    FFlagLuaAppAccountSecurityPromptRolloutEnabledForAll = 1767650226128  # Unknown = 
    FFlagLuaAppAddAnalyticsDataToSeeAllImpressions = 1767526161872  # Unknown = 
    FFlagLuaAppAddCarouselAmpUpsellAccessResponses = 1767650007005  # Bool = false
    FFlagLuaAppAddComponentTypeToSearchImpressions2 = 1768458326493  # Bool = true
    FFlagLuaAppAddIgrsImages = 1767525979677  # Bool = false
    FFlagLuaAppAddPlaceholderRecoveryCounter = 1767650007965  # Bool = false
    FFlagLuaAppAddRequestIdToRfySignalApportioning = 1767526120989  # Bool = false
    FFlagLuaAppAddSeeAllFlagToGameDetailReferral = 1767526167773  # Bool = false
    FFlagLuaAppAddSessionIdToUserSignals = 1767525999696  # Unknown = 
    FFlagLuaAppAddSocialLinkClickTelemetryToEdp = 1767526000157  # Bool = false
    FFlagLuaAppAddSocialLinkImpressionsTelemetryToEdp = 1768032698429  # Bool = false
    FFlagLuaAppAddSortDataToSocialCarouselClicks = 1767526020893  # Bool = false
    FFlagLuaAppAddTestIdsForArrow = 1767525993936  # Unknown = 
    FFlagLuaAppAddUniverseIdToGameDetailsEvents = 1767526118416  # Unknown = 
    FFlagLuaAppAddVideoIneligiblePlayabilityStatus = 1767525978973  # Bool = false
    FFlagLuaAppAdjustOverflowMenuVisual = 1767526025245  # Bool = false
    FFlagLuaAppAlignHeroUnitBottomRowCtaButton = 1768125801437  # Bool = false
    FFlagLuaAppApportioningInCollectionViews = 1768179530512  # Unknown = 
    FFlagLuaAppApportioningInCollectionViews2 = 1767470815197  # Bool = false
    FFlagLuaAppAttachChallengeInterceptor = 1767650177181  # Bool = false
    FFlagLuaAppAutocompleteIXPConfig4 = 1767650185168  # Unknown = 
    FFlagLuaAppAvoidPushUpsellConflicts = 1767650185744  # Unknown = 
    FFlagLuaAppBadgeDetailsEnabled6 = 1767525982749  # Bool = false
    FFlagLuaAppBadgeDetailsLogExposure = 1767525982941  # Bool = false
    FFlagLuaAppBadgesSeeAllEnabled4 = 1767525980368  # Unknown = 
    FFlagLuaAppBadgesSeeAllLogExposure = 1767525979280  # Unknown = 
    FFlagLuaAppBlockedUnplayableError = 1767526019421  # Bool = false
    FFlagLuaAppBottomAlignDetailsHeaderInfoFrame = 1768017181328  # Unknown = 
    FFlagLuaAppBroadenVideoAnalytics = 1768458290960  # Unknown = 
    FFlagLuaAppChallengeCaptchaV2ForceWebViewVisible = 1767650174224  # Unknown = 
    FFlagLuaAppChallengeDialogEventReceiverEnabled = 1767654042589  # Bool = false
    FFlagLuaAppChallengeDialogFetchDialogConditionally = 1767654034576  # Unknown = 
    FFlagLuaAppChallengeDisableForceWebViewVisible = 1767650175824  # Unknown = 
    FFlagLuaAppChallengeTurnstileForceWebViewVisible = 1767650173520  # Unknown = 
    FFlagLuaAppChartsActiveFilterChips = 1768458323421  # Bool = true
    FFlagLuaAppChartsActiveFilterChips3 = 1768458300189  # Bool = true
    FFlagLuaAppChartsAppPage = 1767526008413  # Bool = false
    FFlagLuaAppChartsAppUseHoverTile = 1767418861533  # Bool = true
    FFlagLuaAppChartsFilterOptionTextTag = 1768458289744  # Unknown = 
    FFlagLuaAppChartsFilterOptionTextTag2 = 1768458302544  # Unknown = 
    FFlagLuaAppChartsPreloadingEnabled = 1767650013085  # Bool = false
    FFlagLuaAppChartsResetFetchingStatusOnFilterChange = 1768458307677  # Bool = false
    FFlagLuaAppChartsResetFetchingStatusOnFilterChange2 = 1768458318992  # Unknown = 
    FFlagLuaAppCheckboxFeedbackFormTitleTextWrapping = 1768017182992  # Unknown = 
    FFlagLuaAppClampBannerPaddingToViewport = 1767525982173  # Bool = false
    FFlagLuaAppCompositionAlways4 = 1768005274064  # Unknown = 
    FFlagLuaAppCompositionAppChat = 1767831086288  # Unknown = 
    FFlagLuaAppCompositionAvatar = 1767831086416  # Unknown = 
    FFlagLuaAppCompositionCharts = 1767831086352  # Unknown = 
    FFlagLuaAppCompositionFixDetailClip = 1768017208912  # Unknown = 
    FFlagLuaAppCompositionFixEmphasisApportioning = 1767650007760  # Unknown = 
    FFlagLuaAppCompositionHome = 1767831087760  # Unknown = 
    FFlagLuaAppCompositionHomeHeaderFullBleed = 1767831088144  # Unknown = 
    FFlagLuaAppCompositionLegacyLayout = 1767831085904  # Unknown = 
    FFlagLuaAppCompositionPlayerGrid = 1767831085072  # Unknown = 
    FFlagLuaAppCompositionSearch = 1767831085136  # Unknown = 
    FFlagLuaAppCompositionTopBarFullBleed = 1767831086736  # Unknown = 
    FFlagLuaAppContinueSortInstantPlay = 1768374772125  # Bool = false
    FFlagLuaAppContinueSortInstantPlay_DEV = 1767526028816  # Unknown = 
    FFlagLuaAppCreatorSuccessVirtualEventsLayerUseRoactExperiment = 1767897074384  # Unknown = 
    FFlagLuaAppCreatorSuccessVirtualEventsLayerUseRoactExperiment2 = 1768017043728  # Unknown = 
    FFlagLuaAppCredentialSheetEventStream = 1768387537245  # Bool = false
    FFlagLuaAppCustomizableEntryPoint = 1768027265173  # Bool = false
    FFlagLuaAppDataCacheBatch = 1768012212176  # Unknown = 
    FFlagLuaAppDataHydrationConnectionsPlayedStore = 1767470832976  # Unknown = 
    FFlagLuaAppDataHydrationDataResolverOnClear = 1767470831901  # Bool = false
    FFlagLuaAppDataHydrationOptimisticMutationLayer = 1767470831248  # Unknown = 
    FFlagLuaAppDataHydrationPlayerCountGameInfoStore = 1767470833437  # Bool = false
    FFlagLuaAppDataHydrationSanitizeItem = 1767470833053  # Bool = false
    FFlagLuaAppDataHydrationUpdateItem = 1767470832733  # Bool = false
    FFlagLuaAppDataHydrationVotesStoreTrackOptimisticVotes = 1767470831581  # Bool = false
    FFlagLuaAppDefaultHttpRetry = 1767470840221  # Bool = false
    FFlagLuaAppDefaultInitialItemsPerRowForSearch = 1767650008861  # Bool = false
    FFlagLuaAppDeferLaunch = 1767650173392  # Unknown = 
    FFlagLuaAppDemoModePlayButton = 1767526038493  # Bool = false
    FFlagLuaAppDemoModePlayButtonTelemetry2 = 1767526038813  # Bool = false
    FFlagLuaAppDerivedStackAndSwitchState = 1767470839581  # Bool = false
    FFlagLuaAppDesignFoundationsBridge = 1767470841936  # Unknown = 
    FFlagLuaAppDesktopFriendCarouselClicks = 1767526016861  # Bool = false
    FFlagLuaAppDesktopMediaGalleryTelemetry = 1767526015632  # Unknown = 
    FFlagLuaAppDevStoreSeeAllForceRefreshOnNavigate = 1768001929149  # Bool = true
    FFlagLuaAppDevStoreSeeAllSduiEnabled = 1768001905789  # Bool = true
    FFlagLuaAppDevStoreSeeAllSduiLogExposure = 1768458305488  # Unknown = 
    FFlagLuaAppDisableChevronSeeAll = 1767526017245  # Bool = false
    FFlagLuaAppDisableDataModelStreamingInStudio = 1767650188880  # Unknown = 
    FFlagLuaAppDisablePlayableWhenLoadingForce = 1767526015824  # Unknown = 
    FFlagLuaAppDisableStickyBarMediaGallery = 1768017184400  # Unknown = 
    FFlagLuaAppDiscoveryClientAppStorageEmptyCacheTelemetry = 1767977248144  # Unknown = 
    FFlagLuaAppDismissUnlockUpsell = 1768458343837  # Bool = true
    FFlagLuaAppEdpBackendV2AddUserVote = 1767526113040  # Unknown = 
    FFlagLuaAppEdpBackendV2HydrateLegacyDefault = 1768374767568  # Unknown = 
    FFlagLuaAppEdpBackendV2HydrateLegacyDefault9 = 1767526114781  # Bool = false
    FFlagLuaAppEdpBackendV2HydrateLegacyIxp = 1768374775504  # Unknown = 
    FFlagLuaAppEdpBackendV2HydrateLegacyIxp9 = 1767526115357  # Bool = false
    FFlagLuaAppEdpBackendV2LogFetchSuccessAndFailure2 = 1767526115152  # Unknown = 
    FFlagLuaAppEdpBackendV2LogUniverseIdForEvents = 1767526114000  # Unknown = 
    FFlagLuaAppEdpBackendV2SduiInterleaveDefault = 1768374751760  # Unknown = 
    FFlagLuaAppEdpBackendV2SduiInterleaveDefault3 = 1767526115933  # Bool = false
    FFlagLuaAppEdpBackendV2SduiInterleaveIxp = 1768374748688  # Unknown = 
    FFlagLuaAppEdpBackendV2SduiInterleaveIxp3 = 1767526116509  # Bool = false
    FFlagLuaAppEdpBottomSheetPeekViewEvents2 = 1768001909237  # Bool = false
    FFlagLuaAppEdpConsoleMediaGalleryVideo = 1767526018000  # Unknown = 
    FFlagLuaAppEdpConsoleMediaGalleryVideoMute = 1768374752925  # Bool = false
    FFlagLuaAppEdpConsoleMediaGalleryVideoPlayIcon = 1768374752405  # Bool = false
    FFlagLuaAppEdpFaeIxpEnabled = 1767650211728  # Unknown = 
    FFlagLuaAppEdpFetchLatencyTracking = 1767526117904  # Unknown = 
    FFlagLuaAppEdpFixDefaultBanner = 1767526019677  # Bool = false
    FFlagLuaAppEdpHideSystemBarOnPeekViewMount = 1767525992848  # Unknown = 
    FFlagLuaAppEdpKeepCachedDetailsOnRefetch = 1767525994128  # Unknown = 
    FFlagLuaAppEdpKeepFullPageOnPortraitRotation = 1767525995101  # Bool = true
    FFlagLuaAppEdpMediaGalleryAutoAdvance = 1768374765213  # Bool = false
    FFlagLuaAppEdpMediaGalleryAutoAdvance5 = 1767526028957  # Bool = false
    FFlagLuaAppEdpMediaGalleryFullScreen = 1768374768221  # Bool = false
    FFlagLuaAppEdpMediaGalleryFullScreen4 = 1767526030109  # Bool = false
    FFlagLuaAppEdpMediaGalleryHeightJitterFix = 1767525995677  # Bool = false
    FFlagLuaAppEdpMediaGalleryPreloadImage = 1767526029533  # Bool = false
    FFlagLuaAppEdpMediaGalleryRedesign = 1768374754141  # Bool = false
    FFlagLuaAppEdpMediaGalleryRedesign5 = 1767526020445  # Bool = false
    FFlagLuaAppEdpMediaGalleryRedesignIxp = 1768374751581  # Bool = false
    FFlagLuaAppEdpMediaGalleryRedesignIxp5 = 1767526019997  # Bool = false
    FFlagLuaAppEdpMediaGalleryRedesignTelemetry = 1767526030685  # Bool = false
    FFlagLuaAppEdpMediaGalleryVideoPreview = 1768374785949  # Bool = false
    FFlagLuaAppEdpMediaGalleryVideoPreview5 = 1767526020752  # Unknown = 
    FFlagLuaAppEdpMediaGalleryVideoPreviewIxp = 1768374750045  # Bool = false
    FFlagLuaAppEdpMediaGalleryVideoPreviewIxp5 = 1767526021840  # Unknown = 
    FFlagLuaAppEdpNonSduiBuildAttribution = 1767526114205  # Bool = false
    FFlagLuaAppEdpPeekViewReserveBottomDockHeight = 1767525990800  # Unknown = 
    FFlagLuaAppEdpShowBuildTag = 1767583576349  # Bool = true
    FFlagLuaAppEdpUseHidePlayWithRewardVisibilityVariable = 1776006992752  # Unknown = 
    FFlagLuaAppEdpVideoAvailableRamDeny = 1768389405712  # Unknown = 
    FFlagLuaAppEdpVideoDeviceDeny = 1768389348112  # Unknown = 
    FFlagLuaAppEdpVideoManufacturerDeny2 = 1768389402576  # Unknown = 
    FFlagLuaAppEdpVideoMaxMemoryDeny = 1768389352272  # Unknown = 
    FFlagLuaAppEmail2SVUpsellPopUpEnabled = 1767470799069  # Bool = false
    FFlagLuaAppEmphasisGameTileVideo = 1767526023632  # Unknown = 
    FFlagLuaAppEnable10ftSignUpView = 1767720507216  # Unknown = 
    FFlagLuaAppEnableAndroidPushUpsell = 1767583534621  # Bool = true
    FFlagLuaAppEnableBacktraceSessionInfo = 1767900727949  # Bool = true
    FFlagLuaAppEnableChartsPageProfileLink = 1767900765741  # Bool = true
    FFlagLuaAppEnableChatMilestones = 1767470842141  # Bool = false
    FFlagLuaAppEnableCommunityLinksRedirect = 1767650011869  # Bool = false
    FFlagLuaAppEnableCompactDataModelPayload = 1767650188176  # Unknown = 
    FFlagLuaAppEnableConsolidatedGameRefundPolicy = 1767526110160  # Unknown = 
    FFlagLuaAppEnableContainedRewardUi = 1767654031517  # Bool = false
    FFlagLuaAppEnableContentfulPaintTracking = 1767470843037  # Bool = false
    FFlagLuaAppEnableCredentialsProtocol = 1767643518685  # Bool = false
    FFlagLuaAppEnableCustomAnalyticsEvent = 1767654037789  # Bool = false
    FFlagLuaAppEnableDataModelStreamForConsoles = 1767650188688  # Unknown = 
    FFlagLuaAppEnableDesktopDualLoginABTest = 1768458316624  # Unknown = 
    FFlagLuaAppEnableEnhancedVideoExperienceAssetAndTimeline = 1767908706269  # Bool = false
    FFlagLuaAppEnableEnhancedVideoExperienceGroupIdCheck = 1767908707165  # Bool = false
    FFlagLuaAppEnableFeatureTileAdPlayer = 1768001908117  # Bool = false
    FFlagLuaAppEnableGameGridTable2 = 1767649988125  # Bool = false
    FFlagLuaAppEnableHeroUnitV2 = 1767526112464  # Unknown = 
    FFlagLuaAppEnableHomepageOneByTwoTile = 1768125813712  # Unknown = 
    FFlagLuaAppEnableInExperienceDataModelStreamStarter = 1767831055632  # Unknown = 
    FFlagLuaAppEnableLogoHeaderByDefault = 1767723044240  # Unknown = 
    FFlagLuaAppEnableLumberyakLogBound = 1767640183261  # Bool = false
    FFlagLuaAppEnableMilestoneDeduplication = 1767470829840  # Unknown = 
    FFlagLuaAppEnableMorePageProfileLink = 1767526012829  # Bool = false
    FFlagLuaAppEnableNativePurchaseFinishedV2Signals = 1767831097872  # Unknown = 
    FFlagLuaAppEnableNativeRobuxProducts = 1767650005776  # Unknown = 
    FFlagLuaAppEnableNxMApportioningExtraLogging = 1768125809488  # Unknown = 
    FFlagLuaAppEnableNxMRoduxApportioning = 1767470814621  # Bool = false
    FFlagLuaAppEnableOpenTypeIGMFix = 1767828613712  # Unknown = 
    FFlagLuaAppEnableOpenTypeSignUpPageFix = 1767828610320  # Unknown = 
    FFlagLuaAppEnableOpenTypeSupport4 = 1768133845008  # Unknown = 
    FFlagLuaAppEnablePageLoadTracker = 1767470841565  # Bool = false
    FFlagLuaAppEnablePlayButtonThrottle = 1767526027216  # Unknown = 
    FFlagLuaAppEnablePlaySquadButton = 1768374735760  # Unknown = 
    FFlagLuaAppEnablePlaySquadButton3 = 1767526018077  # Bool = false
    FFlagLuaAppEnablePlayableStateWhenLoading = 1767526018653  # Bool = false
    FFlagLuaAppEnablePushUpsellOnFirstTime = 1767583534992  # Unknown = 
    FFlagLuaAppEnableRecommendedCarouselForDesktop = 1768297287760  # Unknown = 
    FFlagLuaAppEnableRelativeGuiHomeForAll = 1768372141392  # Unknown = 
    FFlagLuaAppEnableRelativeGuiHomeForAll2 = 1768215373840  # Unknown = 
    FFlagLuaAppEnableRelativeGuiHomeWithIxp = 1768372115920  # Unknown = 
    FFlagLuaAppEnableRelativeGuiHomeWithIxp2 = 1767526004368  # Unknown = 
    FFlagLuaAppEnableReportBadge = 1768009967248  # Unknown = 
    FFlagLuaAppEnableSduiHomePageDev = 1767900762869  # Bool = true
    FFlagLuaAppEnableSearchStreamingEndpoint = 1767831063184  # Unknown = 
    FFlagLuaAppEnableSinglePageSignUp = 1767650011088  # Unknown = 
    FFlagLuaAppEnableSlpForVr = 1767723042973  # Bool = false
    FFlagLuaAppEnableSponsoredReportAd = 1768125763088  # Unknown = 
    FFlagLuaAppEnableSponsoredReportAd3 = 1768125762960  # Unknown = 
    FFlagLuaAppEnableSquadPage4 = 1767583399696  # Unknown = 
    FFlagLuaAppEnableStickyShortcutBar = 1767526169373  # Bool = false
    FFlagLuaAppEnableStratusStreamingCheck = 1767526109853  # Bool = false
    FFlagLuaAppEnableStratusStreamingTestOnly = 1767526106128  # Unknown = 
    FFlagLuaAppEnableToastNotificationsCoreScripts4 = 1767831049616  # Unknown = 
    FFlagLuaAppEnableTokenBucketLimiter = 1767640167952  # Unknown = 
    FFlagLuaAppEnableTopBanner3 = 1767583402000  # Unknown = 
    FFlagLuaAppEnableVRCarouselScrolling = 1767526123421  # Bool = false
    FFlagLuaAppEnableVirtualEventPlaceId = 1767470834589  # Bool = false
    FFlagLuaAppEnableWaitForPropWrapperAssert = 1768428784720  # Unknown = 
    FFlagLuaAppEnableWebViewStateTrackerInDataModelStreaming = 1767650188560  # Unknown = 
    FFlagLuaAppEnableWebViewTelemetry = 1768458307536  # Unknown = 
    FFlagLuaAppEnableWindowsHandheldScale = 1767591403517  # Bool = true
    FFlagLuaAppEnableWindowsHandheldTokenScale = 1767977243664  # Unknown = 
    FFlagLuaAppEnhancedVideoAdLabelPropUpdate = 1767908704797  # Bool = false
    FFlagLuaAppErrorOnBadSortGroup = 1767649996637  # Bool = false
    FFlagLuaAppErrorReportCountryCode = 1767640179280  # Unknown = 
    FFlagLuaAppEventDetailsPageDisableCtaOnUnplayable = 1767526031824  # Unknown = 
    FFlagLuaAppExpandableTextAdjustClipToContent = 1768017205341  # Bool = false
    FFlagLuaAppExpandableTextImpressionsEnabled = 1767526001117  # Bool = false
    FFlagLuaAppExpandableTextNewLineStrip = 1768017219280  # Unknown = 
    FFlagLuaAppExperienceDetailsLayoutOrderConfig = 1768374779856  # Unknown = 
    FFlagLuaAppExperienceDetailsLayoutOrderConfig2 = 1767526116240  # Unknown = 
    FFlagLuaAppExperienceJoinIdempotencyKey = 1776125389008  # Unknown = 
    FFlagLuaAppExtendPlayWithRewardPeekView = 1768374768784  # Unknown = 
    FFlagLuaAppExtraInviteModalStringValidation = 1767901842576  # Unknown = 
    FFlagLuaAppFetchContentMaturityWithPlayability = 1768024109917  # Bool = false
    FFlagLuaAppFetchPlayabilityKillSwitch1 = 1768024516061  # Bool = true
    FFlagLuaAppFix10ftGlobalNavAppHeaderBarSelection = 1767473198160  # Unknown = 
    FFlagLuaAppFixActiveGameLoadingCheck = 1767977189712  # Unknown = 
    FFlagLuaAppFixAppExperienceActionRowLoadingState = 1768389347152  # Unknown = 
    FFlagLuaAppFixAppNavHeaderIconsAlignment = 1767828592720  # Unknown = 
    FFlagLuaAppFixApportioningTileTailConflict = 1768024560080  # Unknown = 
    FFlagLuaAppFixAutocompleteEntryDups = 1767650012637  # Bool = false
    FFlagLuaAppFixCarouselCanvasOverflow = 1767525979421  # Bool = false
    FFlagLuaAppFixCarouselPeekInControl = 1767831076112  # Unknown = 
    FFlagLuaAppFixCentralOverlayDeviceSafe = 1767654070109  # Bool = false
    FFlagLuaAppFixChartsRenderOnFail = 1767526119901  # Bool = false
    FFlagLuaAppFixCollectionGridWindowAbsoluteCanvasSize = 1768024555984  # Unknown = 
    FFlagLuaAppFixCollectionSizeBindingsZero = 1768024529424  # Unknown = 
    FFlagLuaAppFixCommunityLinksRedirect = 1767650012317  # Bool = false
    FFlagLuaAppFixCompositionSizeOverrideGap = 1767831076496  # Unknown = 
    FFlagLuaAppFixComputedSideMarginResponsiveBreakpoint = 1768024534928  # Unknown = 
    FFlagLuaAppFixConsoleSeeAllGridContainment = 1767649968336  # Unknown = 
    FFlagLuaAppFixCursorHooks = 1767526148688  # Unknown = 
    FFlagLuaAppFixDetailsPageThumbnailRenderInPhone = 1767526011792  # Unknown = 
    FFlagLuaAppFixEdpRecommendedCarouselHoverZIndex = 1768215394000  # Unknown = 
    FFlagLuaAppFixEventNotFoundErrorStateExit = 1768017044445  # Bool = true
    FFlagLuaAppFixExplicitFeedbackConsoleTelemetry = 1767525999261  # Bool = false
    FFlagLuaAppFixExplicitFeedbackTelemetry = 1767525996944  # Unknown = 
    FFlagLuaAppFixFrameBoundsImpressions = 1767640197456  # Unknown = 
    FFlagLuaAppFixGameGridTableNilRelativeHeight = 1767649987741  # Bool = false
    FFlagLuaAppFixGamesListSortTokenExpiringTime = 1767526118109  # Bool = false
    FFlagLuaAppFixHiddenTileVideoCleanup = 1767526028509  # Bool = false
    FFlagLuaAppFixHomeGridPlaceholderFlowIssues = 1767526120848  # Unknown = 
    FFlagLuaAppFixImpressionsHookDependencies = 1767640198672  # Unknown = 
    FFlagLuaAppFixInlineSignalsReactPattern = 1767526119453  # Bool = false
    FFlagLuaAppFixLaunchGameSourceParam = 1767526028368  # Unknown = 
    FFlagLuaAppFixNotificationBadgeCountsSync = 1767525984157  # Bool = false
    FFlagLuaAppFixPassesPageStoreFetch = 1767525983709  # Bool = false
    FFlagLuaAppFixPlayButtonDefaultLaunchSource = 1768024554845  # Bool = false
    FFlagLuaAppFixRecommendedImpressionsInterface = 1768428787536  # Unknown = 
    FFlagLuaAppFixRsvpPromptDescriptionScrolling = 1768017050269  # Bool = true
    FFlagLuaAppFixSDPLayout = 1767828584528  # Unknown = 
    FFlagLuaAppFixSduiHeroUnitTitle = 1767424227549  # Bool = false
    FFlagLuaAppFixSearchImpressions = 1767526117789  # Bool = false
    FFlagLuaAppFixSelectionCursor = 1767526149597  # Bool = false
    FFlagLuaAppFixSmallScreenFooterStatsOverlap = 1767526111248  # Unknown = 
    FFlagLuaAppFixStudioNotchSupport3 = 1767654056669  # Bool = false
    FFlagLuaAppFixToastNotificationClosePosition = 1767420615773  # Bool = false
    FFlagLuaAppFixTotalColsBound = 1768458320413  # Bool = true
    FFlagLuaAppFixUnifiedPlayButtonStickyActionBar = 1768017207824  # Unknown = 
    FFlagLuaAppFixWebViewUnderlyingBackButton = 1767723043869  # Bool = false
    FFlagLuaAppForceLowResMural = 1767650007517  # Bool = false
    FFlagLuaAppForceVrAppPanelWidthRollout = 1767526109008  # Unknown = 
    FFlagLuaAppForumsDeeplinkFix = 1768009985104  # Unknown = 
    FFlagLuaAppFriendCarouselImpressionsTimestamp = 1768215350557  # Bool = false
    FFlagLuaAppFriendsSortHeaderByPosition = 1768215394384  # Unknown = 
    FFlagLuaAppGameCarouselUseAutoSizing = 1767650182288  # Unknown = 
    FFlagLuaAppGameDetailEventMobileAdsId = 1767526167197  # Bool = false
    FFlagLuaAppGameDetailsAttributionFix = 1768374788752  # Unknown = 
    FFlagLuaAppGameEventsTelemetryServiceShadowTraffic = 1767525992336  # Unknown = 
    FFlagLuaAppGameImpressionsAddUnifiedFields = 1767526162448  # Unknown = 
    FFlagLuaAppGameImpressionsMobileAdsId = 1767526162960  # Unknown = 
    FFlagLuaAppGamePassesDataHydrationMigrationEnabled = 1768229351493  # Bool = false
    FFlagLuaAppGamePlayIntentEventMobileAdsId = 1767526168349  # Bool = false
    FFlagLuaAppGameStatsFallbackRendering = 1767526123869  # Bool = false
    FFlagLuaAppGameTileExtractGameDetailsCallback = 1767526029904  # Unknown = 
    FFlagLuaAppGameTileInteractionFeedback = 1768215357328  # Unknown = 
    FFlagLuaAppGameTileNotInterestedDirectAction = 1767526025693  # Bool = false
    FFlagLuaAppGameTileOverflowMenuSelectionCloseFix = 1768428746704  # Unknown = 
    FFlagLuaAppGameTileSelectionVideoPlayback = 1767526026845  # Bool = false
    FFlagLuaAppGameTileVideoAvailableRamDeny = 1768428740688  # Unknown = 
    FFlagLuaAppGameTileVideoDeviceDeny = 1768428744208  # Unknown = 
    FFlagLuaAppGameTileVideoManufacturerDeny = 1768428741392  # Unknown = 
    FFlagLuaAppGameTileVideoMaxMemoryDeny = 1768428742096  # Unknown = 
    FFlagLuaAppGameViewTileBackgroundColorOverride = 1767526106717  # Bool = false
    FFlagLuaAppGateVideoPlaybackOnNavigationFocus = 1767526026269  # Bool = false
    FFlagLuaAppGenreRatingFooter = 1767526108304  # Unknown = 
    FFlagLuaAppHapticTriggeredTelemetry = 1767525997712  # Unknown = 
    FFlagLuaAppHeadShapeInventory = 1767470828893  # Bool = false
    FFlagLuaAppHeaderButtonText = 1768215353501  # Bool = false
    FFlagLuaAppHideEdpStoreForUnplayable = 1767526017360  # Unknown = 
    FFlagLuaAppHideEmptyCarouselHeader = 1767831067984  # Unknown = 
    FFlagLuaAppHomeFirstTileThumbnailLoadedMilestone = 1767470839312  # Unknown = 
    FFlagLuaAppHomeGameCarouselRemount = 1767526118685  # Bool = false
    FFlagLuaAppHomeJoinYourFriendsPresenceFix = 1767650165520  # Unknown = 
    FFlagLuaAppHomePageFirstImageLoadObserver2 = 1768005297360  # Unknown = 
    FFlagLuaAppHomePageLoadTracker = 1768005283472  # Unknown = 
    FFlagLuaAppHomePageReadyToRender = 1768005295504  # Unknown = 
    FFlagLuaAppHomePageSharedEffects = 1767723051101  # Bool = false
    FFlagLuaAppHomeReduceRenders = 1767526023568  # Unknown = 
    FFlagLuaAppHomeThumbnailPrefetch = 1767470838864  # Unknown = 
    FFlagLuaAppHomeUseFeedVideoPlaybackContext = 1767723045776  # Unknown = 
    FFlagLuaAppHomeVngAppUpsell = 1767526153949  # Bool = false
    FFlagLuaAppHttpSupportNoContent = 1767977204496  # Unknown = 
    FFlagLuaAppIECVREnabled8 = 1767978502800  # Unknown = 
    FFlagLuaAppIECVRIxpEnabled8 = 1767978535056  # Unknown = 
    FFlagLuaAppIaHomeSubTab = 1767828613840  # Unknown = 
    FFlagLuaAppIconPlayButton = 1767526037789  # Bool = false
    FFlagLuaAppIconTextPlayButton = 1767526036624  # Unknown = 
    FFlagLuaAppIedpFixPlayButton = 1767526123229  # Bool = false
    FFlagLuaAppIedpOverlayAndNavigationFix = 1767526122461  # Bool = false
    FFlagLuaAppIedpSendPoints = 1767526122973  # Bool = false
    FFlagLuaAppIedpSwitchChipToBadge = 1767913315229  # Bool = false
    FFlagLuaAppImproveAccountSwitcherPeekView = 1767723043293  # Bool = false
    FFlagLuaAppImproveComponentTrackingTiming = 1767470839376  # Unknown = 
    FFlagLuaAppInExperienceDetailsPrompt3 = 1767526121885  # Bool = false
    FFlagLuaAppIncorrectWebViewProperty = 1767654043165  # Bool = false
    FFlagLuaAppInfoTableResponsiveProviderOverride = 1768017200413  # Bool = true
    FFlagLuaAppInfoTableWorkaroundGridJank2 = 1768017200528  # Unknown = 
    FFlagLuaAppInitializeToastNotificationEventParams2 = 1768017096528  # Unknown = 
    FFlagLuaAppInlineRequireAppConfigurer = 1767473192208  # Unknown = 
    FFlagLuaAppIsClickoutEnabledUniverse = 1767908708381  # Bool = false
    FFlagLuaAppIsEnhancedVideoUniverse = 1767908706896  # Unknown = 
    FFlagLuaAppItemEventsTelemetryServiceShadowTraffic = 1767525991184  # Unknown = 
    FFlagLuaAppJoinTextPlayableButton = 1767526037533  # Bool = false
    FFlagLuaAppKeepTileBadgesDuringVideo = 1768428747088  # Unknown = 
    FFlagLuaAppLCPTimingFix = 1768009980432  # Unknown = 
    FFlagLuaAppLaunchTrackThunks = 1768494389184  # Unknown = 
    FFlagLuaAppLaunchWhenLoadingEdp = 1767526019037  # Bool = false
    FFlagLuaAppLaunchWhenLoadingForce = 1767526018448  # Unknown = 
    FFlagLuaAppLayoutParamsInContext2 = 1768005275408  # Unknown = 
    FFlagLuaAppLazyComponentAsyncChunkLoad = 1767989418013  # Bool = false
    FFlagLuaAppLimitEventThumbnailToOne = 1768017037853  # Bool = true
    FFlagLuaAppLogChartsAppPageExposure = 1767525989341  # Bool = false
    FFlagLuaAppLogExposurePlayButtonUX = 1767526035984  # Unknown = 
    FFlagLuaAppLogGameAttributionError = 1768374775952  # Unknown = 
    FFlagLuaAppLogGameAttributionError2 = 1767526119005  # Bool = false
    FFlagLuaAppLogMorePageLayerExposure = 1767423164893  # Bool = false
    FFlagLuaAppLogOmniRecommendationsMetadata2 = 1767525979997  # Bool = false
    FFlagLuaAppLogSearchTopPageExposure = 1767525989661  # Bool = false
    FFlagLuaAppLoosenCollectionIdTypeInterface = 1767526017565  # Bool = false
    FFlagLuaAppLuaBuyRobuxPage = 1767654048541  # Bool = false
    FFlagLuaAppMakeDisclaimerOptInForFeedbackForm = 1767525996368  # Unknown = 
    FFlagLuaAppMediaGalleryGamepadSupportsPagingIcons = 1767654037213  # Bool = false
    FFlagLuaAppMediaGalleryNilImageIdFix = 1767831059216  # Unknown = 
    FFlagLuaAppMigrateGameEventsTelemetryService = 1767525994269  # Bool = true
    FFlagLuaAppMigrateGameTileActiveFriendsFix = 1767526108573  # Bool = false
    FFlagLuaAppMigrateGameTileActiveFriendsHydrationFix2 = 1767526109085  # Bool = false
    FFlagLuaAppMigrateGameTileFixConsoleMetadataText = 1767526113757  # Bool = false
    FFlagLuaAppMigrateGameTileFooterValueFixes = 1767526105744  # Unknown = 
    FFlagLuaAppMigrateGameTileHoverFixes = 1767526106269  # Bool = false
    FFlagLuaAppMigrateItemEventsTelemetryService = 1767525993424  # Unknown = 
    FFlagLuaAppMobileEdpPlayButtonPartialUnificationIXP = 1767526037213  # Bool = false
    FFlagLuaAppMorePageLayerExposure = 1767424250717  # Bool = false
    FFlagLuaAppMoveProfileIntoTopBar = 1767900732045  # Bool = true
    FFlagLuaAppMoveProfileIntoTopBarIXP = 1768179506768  # Unknown = 
    FFlagLuaAppMoveSocialLinksImpressions = 1767461277597  # Bool = false
    FFlagLuaAppMutedSetNetworkingErrorToast = 1767640197661  # Bool = false
    FFlagLuaAppNarrowTileHidePlayerCount2 = 1767526110352  # Unknown = 
    FFlagLuaAppNarrowTileHideRating2 = 1767526105680  # Unknown = 
    FFlagLuaAppNarrowTileSmallerFooterFont2 = 1767526110224  # Unknown = 
    FFlagLuaAppNewSlpEndpointIxpEnabled = 1767468740253  # Bool = true
    FFlagLuaAppNilApportionedItems = 1767648654813  # Bool = false
    FFlagLuaAppNormalizeUnifiedPasskeyResponse = 1767643513360  # Unknown = 
    FFlagLuaAppNotInterestedFeedbackFormTelemetry = 1767525993296  # Unknown = 
    FFlagLuaAppNotInterestedReportPlaceId = 1767525996496  # Unknown = 
    FFlagLuaAppNullableGridLayoutTelemetryFields = 1768428796304  # Unknown = 
    FFlagLuaAppPYMKSendUserSeenCollection = 1767526021469  # Bool = false
    FFlagLuaAppPageLoadTrackerJoinExperienceFix = 1767470843741  # Bool = false
    FFlagLuaAppParentApprovedExperiences = 1767526016413  # Bool = false
    FFlagLuaAppParentUpsellPolicy = 1767526011280  # Unknown = 
    FFlagLuaAppPersistentMusicPlayerDev = 1767828589456  # Unknown = 
    FFlagLuaAppPlatformRestrictionVPC = 1767831065936  # Unknown = 
    FFlagLuaAppPlayButtonAmpAgeCheckFlow = 1767526014288  # Unknown = 
    FFlagLuaAppPlayButtonLaunchOnReleaseAfterUnmountEdp = 1767526017424  # Unknown = 
    FFlagLuaAppPlayButtonLaunchOnReleaseAfterUnmountForce = 1767526016720  # Unknown = 
    FFlagLuaAppPlayButtonLoadingDurationTelemetry = 1767526029392  # Unknown = 
    FFlagLuaAppPlayButtonLoadingPrimary = 1768372144656  # Unknown = 
    FFlagLuaAppPlayButtonLoadingPrimary2 = 1767526003933  # Bool = false
    FFlagLuaAppPlayButtonLoadingSkeleton3 = 1767526038109  # Bool = false
    FFlagLuaAppPlayButtonOptOutFoundationButton = 1767526039248  # Unknown = 
    FFlagLuaAppPlayButtonViewRefactor = 1767470822813  # Bool = false
    FFlagLuaAppPlayButtonWizardCloseDelay = 1767526032605  # Bool = false
    FFlagLuaAppPlayLoadingClickTelemetryMobile = 1767526030992  # Unknown = 
    FFlagLuaAppPlayWithRewardSkipIxpForShimmer = 1767654033501  # Bool = false
    FFlagLuaAppPlayWithRewardUsePlatformSpecificLayerValueForShimmer = 1767654033885  # Bool = false
    FFlagLuaAppPlayableUxTreatment = 1767526111888  # Unknown = 
    FFlagLuaAppProcessGameSocialLinks = 1767526115728  # Unknown = 
    FFlagLuaAppPromotionalEmailsCheckboxEnabledInAppPolicy = 1768297278557  # Bool = true
    FFlagLuaAppPromptsHomepageConfigName = 1767650183120  # Unknown = 
    FFlagLuaAppPropagateFriendsCarouselHeader = 1768215347536  # Unknown = 
    FFlagLuaAppPushSystemUpsellDevOverride = 1767583534160  # Unknown = 
    FFlagLuaAppPushUpsellDeprecateOldEvents = 1767583531792  # Unknown = 
    FFlagLuaAppReduceGameIconFetches = 1767526107792  # Unknown = 
    FFlagLuaAppRefactorSelectRouteDev = 1768027272400  # Unknown = 
    FFlagLuaAppRemoveNumericalSortIndexSearch = 1768024090320  # Unknown = 
    FFlagLuaAppRemoveOmniFeedDividersAndExtraPadding = 1768458297757  # Bool = true
    FFlagLuaAppRemovePlayWithRewardBetaAllowlist = 1768367004144  # Unknown = 
    FFlagLuaAppRemovePlayWithRewardBetaAllowlist2 = 1767526116368  # Unknown = 
    FFlagLuaAppRenameFriendsToConnectionsEdp = 1768374774864  # Unknown = 
    FFlagLuaAppResetHoverOnSduiPlayButtonActivation = 1767525981597  # Bool = false
    FFlagLuaAppRespectClipAncestorImpressions = 1767525988944  # Unknown = 
    FFlagLuaAppResponsiveEnginePreferredInput = 1767526003472  # Unknown = 
    FFlagLuaAppResponsiveFixHookDeps = 1767473181392  # Unknown = 
    FFlagLuaAppRfyRevealRows2 = 1767525978768  # Unknown = 
    FFlagLuaAppRfyRevealRowsFocusFix = 1767525978896  # Unknown = 
    FFlagLuaAppRfySignalApportioning4 = 1767526120541  # Bool = false
    FFlagLuaAppRfySignalApportioningIxp4 = 1768005261840  # Unknown = 
    FFlagLuaAppScaleDetailWidth = 1768017189520  # Unknown = 
    FFlagLuaAppScaleDiscoveryWidth = 1768017223248  # Unknown = 
    FFlagLuaAppScrollDetectorLifecycleHardening = 1767526107293  # Bool = false
    FFlagLuaAppScrollTelemetryIntegration = 1768027261904  # Unknown = 
    FFlagLuaAppSduiAttributionRow5 = 1767525996048  # Unknown = 
    FFlagLuaAppSduiColorPropMigration = 1767525998992  # Unknown = 
    FFlagLuaAppSduiEdpEnabled2 = 1767525983517  # Bool = false
    FFlagLuaAppSduiEdpFallbackAttributionFromCache2 = 1767525985232  # Unknown = 
    FFlagLuaAppSduiEdpFallbackPlayButtonPassUiBlox = 1767526030544  # Unknown = 
    FFlagLuaAppSduiEdpFallbackPlayButtonUseUiBlox = 1767526034832  # Unknown = 
    FFlagLuaAppSduiEdpHideSystemBarOnPeekViewMount = 1768005261776  # Unknown = 
    FFlagLuaAppSduiEdpLogExposure = 1767525984541  # Bool = false
    FFlagLuaAppSduiEdpLogExposureLayoutEffect = 1767525984861  # Bool = false
    FFlagLuaAppSduiEdpPassPageTimerThroughNav = 1767525985437  # Bool = false
    FFlagLuaAppSduiEdpRouteAwareSessionRemoval = 1767525986013  # Bool = false
    FFlagLuaAppSduiErrorPage = 1767643490973  # Bool = false
    FFlagLuaAppSduiEventDetailsActionBarInFeed = 1767525988573  # Bool = false
    FFlagLuaAppSduiEventDetailsCenterSheet2 = 1767525987421  # Bool = false
    FFlagLuaAppSduiEventDetailsEnabled = 1767525982032  # Unknown = 
    FFlagLuaAppSduiEventDetailsLoadingSlot = 1767525987997  # Bool = false
    FFlagLuaAppSduiEventDetailsLogExposure = 1767525986845  # Bool = false
    FFlagLuaAppSduiGameSortDropDown2 = 1768458327453  # Bool = false
    FFlagLuaAppSduiGameTileHoverShadow = 1767526010781  # Bool = false
    FFlagLuaAppSduiGameTilePlayButtonDefaults = 1767900774165  # Bool = true
    FFlagLuaAppSduiLandingPageEnabled = 1767525984720  # Unknown = 
    FFlagLuaAppSduiOpenSearchResultsWithQueryAction = 1767525991376  # Unknown = 
    FFlagLuaAppSduiPageEntryPointSnackbar2 = 1768005292944  # Unknown = 
    FFlagLuaAppSduiPageEntryScrollAway = 1767525974077  # Bool = false
    FFlagLuaAppSduiPlaceholderSupport2 = 1767526005840  # Unknown = 
    FFlagLuaAppSduiQuerySuggestionClickedTelemetry = 1767526012176  # Unknown = 
    FFlagLuaAppSduiRemoveAbuseReportActionFromLegacyRegistry = 1767526002640  # Unknown = 
    FFlagLuaAppSduiSeeAllArrowIconMigration2 = 1767650210704  # Unknown = 
    FFlagLuaAppSduiSeeAllLayoutParamsFix = 1767526120221  # Bool = false
    FFlagLuaAppSduiStickyHeaderScrollAway = 1767525974557  # Bool = false
    FFlagLuaAppSduiStreamingChunkedResponses = 1767831063696  # Unknown = 
    FFlagLuaAppSduiStreamingFirstDataTiming = 1767831060624  # Unknown = 
    FFlagLuaAppSduiUpdateUserSettingsAction = 1767526113181  # Bool = false
    FFlagLuaAppSduiVerificationUpsellActions2 = 1768458328349  # Bool = true
    FFlagLuaAppSduiVerticalFeedThresholdRefresh = 1767654036189  # Bool = false
    FFlagLuaAppSduiVideoThumbnail = 1768372129808  # Unknown = 
    FFlagLuaAppSduiVideoThumbnailDev = 1767526003037  # Bool = false
    FFlagLuaAppSearchListFramesSelectable = 1767650215376  # Unknown = 
    FFlagLuaAppSearchPeopleUnifiedSchemaFields = 1767526022941  # Bool = false
    FFlagLuaAppSearchPlaceholderGrid = 1767526119312  # Unknown = 
    FFlagLuaAppSearchResultsPageGameTileVideo = 1768374784221  # Bool = false
    FFlagLuaAppSearchResultsPageGameTileVideo2 = 1767526024144  # Unknown = 
    FFlagLuaAppSearchStandardizeAssetCategorization = 1768001959709  # Bool = true
    FFlagLuaAppSendTTIEventsPerDM = 1767977592336  # Unknown = 
    FFlagLuaAppSentryAddAppPolicyMetadata2 = 1767640179216  # Unknown = 
    FFlagLuaAppSentryReporterIncludeInTags = 1767640184093  # Bool = false
    FFlagLuaAppShareEdpVideoBlockingConfig = 1768005242704  # Unknown = 
    FFlagLuaAppSharedHomePageInteractive = 1768179534320  # Unknown = 
    FFlagLuaAppShouldTrackTopThunks = 1767583607056  # Unknown = 
    FFlagLuaAppSignupPasskeyAvailabilityPreflight2 = 1767720502608  # Unknown = 
    FFlagLuaAppSortDeeplinkFix = 1768009962000  # Unknown = 
    FFlagLuaAppSortHeaderAnchorTag = 1767525979344  # Unknown = 
    FFlagLuaAppSponsoredAdVideoViewabilityEnabled = 1768125774544  # Unknown = 
    FFlagLuaAppSponsoredAdViewabilityEnabled = 1768125786973  # Bool = false
    FFlagLuaAppStratusBugReportAfterConnect = 1767526110557  # Bool = false
    FFlagLuaAppSupportDeviceSafeInsets = 1767828613136  # Unknown = 
    FFlagLuaAppSupportDisablePlayableWhenLoading = 1767470818589  # Bool = false
    FFlagLuaAppSupportHomeBackToTop = 1767526118493  # Bool = false
    FFlagLuaAppSupportNonSduiTypeForServerTriggeredModals = 1768032739989  # Bool = false
    FFlagLuaAppTextFeedbackFormModal = 1767525995472  # Unknown = 
    FFlagLuaAppTextFeedbackFormModalStandardInput = 1768017167312  # Unknown = 
    FFlagLuaAppTextOnlyPlayButton = 1767526036496  # Unknown = 
    FFlagLuaAppThrottleInviteSendEndpoint = 1767901850269  # Bool = false
    FFlagLuaAppThrottleViewportBoundsScreenSize = 1767640195664  # Unknown = 
    FFlagLuaAppTileVideoCandidateOnly = 1767526025552  # Unknown = 
    FFlagLuaAppTileVideoKeepPlayingOnScroll = 1767526024656  # Unknown = 
    FFlagLuaAppToastV2PerMessageDuration = 1767525998096  # Unknown = 
    FFlagLuaAppUnifiedLoggingDialogContentType = 1767641053136  # Unknown = 
    FFlagLuaAppUnifiedPlayButtonSquadMenuDirection = 1767526105245  # Bool = false
    FFlagLuaAppUnifyPlayButtonAllSurfacesIxp = 1768374763165  # Bool = false
    FFlagLuaAppUnifyPlayButtonAllSurfacesIxp5 = 1767526035677  # Bool = false
    FFlagLuaAppUnifyPlayButtonMobileEdp = 1768374792720  # Unknown = 
    FFlagLuaAppUnifyPlayButtonMobileEdp3 = 1767526036253  # Bool = false
    FFlagLuaAppUnifyPlayButtonNonMobileEdp = 1768374794640  # Unknown = 
    FFlagLuaAppUnifyPlayButtonNonMobileEdp3 = 1767526036701  # Bool = false
    FFlagLuaAppUnifyPlayButtonTile = 1768374790749  # Bool = false
    FFlagLuaAppUnifyPlayButtonTile4 = 1767526036061  # Bool = false
    FFlagLuaAppUnifyPlayButtonTileIxp = 1768374761885  # Bool = false
    FFlagLuaAppUnifyPlayButtonTileIxp2 = 1767526034128  # Unknown = 
    FFlagLuaAppUnlockUpsellSupport = 1767470814173  # Bool = false
    FFlagLuaAppUpdateContentDescriptorsTranslation = 1767526114128  # Unknown = 
    FFlagLuaAppUpdateFailedStateEdpIcon = 1767525996125  # Bool = false
    FFlagLuaAppUpdateGameSortGridRowHeight10ft2 = 1767649977872  # Unknown = 
    FFlagLuaAppUpdatePlayButtonText = 1767526027408  # Unknown = 
    FFlagLuaAppUpdateRevealMoreButtonUi = 1767650008413  # Bool = false
    FFlagLuaAppUseAppHttpStore = 1767470828765  # Bool = false
    FFlagLuaAppUseAppHttpStoreInExperience = 1768060633360  # Unknown = 
    FFlagLuaAppUseDeviceSafeInsetsForAppContainer3 = 1767828557648  # Unknown = 
    FFlagLuaAppUseDisplayStoreForCollectionLayoutParams = 1768024555472  # Unknown = 
    FFlagLuaAppUseEffectInSignalPreprocessing = 1767525980573  # Bool = false
    FFlagLuaAppUseExperienceLogoTrayInGameInfoList = 1767526112605  # Bool = false
    FFlagLuaAppUseFoundationCheckbox = 1767620282877  # Bool = false
    FFlagLuaAppUseFoundationLoading = 1767620283184  # Unknown = 
    FFlagLuaAppUseFrameBoundsImpressions = 1767831088912  # Unknown = 
    FFlagLuaAppUseGameTransactionsApiForReceipts = 1767828577680  # Unknown = 
    FFlagLuaAppUseOverlayInAppContainer = 1767526002768  # Unknown = 
    FFlagLuaAppUsePrevalidatedVideoGamePlayability = 1767526105821  # Bool = false
    FFlagLuaAppUseRatingFormatHelper2 = 1768428747472  # Unknown = 
    FFlagLuaAppUseScreenFillBoundsForFrameBoundsImpressions = 1767831086160  # Unknown = 
    FFlagLuaAppUseSettingsNativeWrapper2 = 1767654048285  # Bool = false
    FFlagLuaAppUseSnackbarForProvideFeedbackToast = 1767525998301  # Bool = false
    FFlagLuaAppUseSortsWithDividersFString2 = 1768458328976  # Unknown = 
    FFlagLuaAppUseSpanTileOverflowMenuTwoByOne2 = 1768428797904  # Unknown = 
    FFlagLuaAppUseTokenHeightForPlayButton = 1767526037456  # Unknown = 
    FFlagLuaAppUseViewportBoundsInsetFix = 1767640197136  # Unknown = 
    FFlagLuaAppUseWithLocalization = 1767654071325  # Bool = false
    FFlagLuaAppUserSearchGridReactiveContainer = 1767650183632  # Unknown = 
    FFlagLuaAppUserSeenCollectionUnifiedFields = 1767526022045  # Bool = false
    FFlagLuaAppUsingSecurityQuestionsForLuaLogin2 = 1767526150416  # Unknown = 
    FFlagLuaAppVideoAutoplayElectOnNewCandidate = 1768389376144  # Unknown = 
    FFlagLuaAppVideoAutoplayFeedElection = 1767526027280  # Unknown = 
    FFlagLuaAppVideoPlaybackRefCount = 1767526111005  # Bool = false
    FFlagLuaAppVideoServerDisplayWakeLock = 1767526111453  # Bool = false
    FFlagLuaAppVideoTileDisableActivation = 1767526027485  # Bool = false
    FFlagLuaAppVideoTileHideCenterPlayButton = 1767526028061  # Bool = false
    FFlagLuaAppVngUpsellAlwaysCanClose = 1767723050141  # Bool = false
    FFlagLuaAppVngUpsellAlwaysEnabled = 1767723049821  # Bool = false
    FFlagLuaAppVoteOptimisticUpdateRaceFix = 1768005295120  # Unknown = 
    FFlagLuaAppWireAudioDeviceInputOnRequest = 1767526112029  # Bool = false
    FFlagLuaAppWizardContainerBypassNavigationLock = 1768458332957  # Bool = true
    FFlagLuaAppWrapChartsFilterOptionLabels = 1767649988445  # Bool = false
    FFlagLuaAppsDefaultSelection = 1768027290064  # Unknown = 
    FFlagLuaAppsServerTriggeredModals = 1767526168144  # Unknown = 
    FFlagLuaConsumePlayerModerated = 1767645289744  # Unknown = 
    FFlagLuaEnableCustomizedInviteLandingPage = 1767720515216  # Unknown = 
    FFlagLuaEnableCustomizedInviteLandingPageForTesting = 1767720491344  # Unknown = 
    FFlagLuaEnableDidSwitchAccount = 1767526160221  # Bool = false
    FFlagLuaEnableGameInviteModal2023V5 = 1776125379216  # Unknown = 
    FFlagLuaEnableGameInviteModalInvitePromptV2 = 1767901840733  # Bool = false
    FFlagLuaEnableGameInviteModalSettingsHub = 1768132560349  # Bool = false
    FFlagLuaEnableGenreDeeplinkSortId = 1767481206088  # Unknown = 
    FFlagLuaEnableGenreLandingDeeplink = 1767525985808  # Unknown = 
    FFlagLuaEnableLandingPageTTIMeasurements = 1767720485200  # Unknown = 
    FFlagLuaEnableLoginAndSignupDifferentiatedStatusValues = 1767720489808  # Unknown = 
    FFlagLuaEnableScreenTimeSignalR = 1767977619472  # Unknown = 
    FFlagLuaEnableShowUpsellMethod2 = 1767583534877  # Bool = true
    FFlagLuaFlagVoiceChatDisableSubscribeRetryForMultistream = 1768028357149  # Bool = false
    FFlagLuaIdentityGetPhoneNumber = 1768458337872  # Unknown = 
    FFlagLuaIdentityGetSMSOTP = 1768458317392  # Unknown = 
    FFlagLuaIdentityProtocol = 1768389366032  # Unknown = 
    FFlagLuaIdentityVerifySNA = 1768458346064  # Unknown = 
    FFlagLuaInExperienceCoreScriptsGameInviteUnificationV3 = 1767831047760  # Unknown = 
    FFlagLuaMenuPerfImprovements = 1767805736528  # Unknown = 
    FFlagLuaMultiPageSignupForceDeviceBoundPasskey = 1767720486288  # Unknown = 
    FFlagLuaUsePhoneNumberTextTypeForPhoneUpsellV2 = 1768389364560  # Unknown = 
    FFlagLuaVoiceChatAnalyticsBanMessage = 1767645287965  # Bool = false
    FFlagLuaVoiceChatAnalyticsUseCounterV2 = 1767645286941  # Bool = false
    FFlagLuaVoiceChatAnalyticsUseEventsV2 = 1767645287517  # Bool = false
    FFlagLuaVoiceChatAnalyticsUsePointsV2 = 1767645283024  # Unknown = 
    FFlagLuaVoiceChatReconnectMissedSequence = 1767645288413  # Bool = false
    FFlagLuafiedReportEntryPoints = 1767583543261  # Bool = true
    FFlagLuafiedReportErrorStates = 1767583542096  # Unknown = 
    FFlagLuafiedReportFullFlow = 1768444654344  # Unknown = 
    FFlagLuafiedReportThumbnail = 1767583542736  # Unknown = 
    FFlagLuafiedWechatQQLogin8 = 1767526161629  # Bool = false
    FFlagMacMenuBarContentUpdates = 1768009976528  # Unknown = 
    FFlagMacUnifyKeyCodeMapping = 1767418833053  # Bool = true
    FFlagMakeCreateOrJoinSquadAThunks = 1768133838096  # Unknown = 
    FFlagMakeVPCFAECheckMoreGeneric = 1767583402717  # Bool = false
    FFlagManagerAddDisplayOrderAndBackgroundDismiss = 1767643503709  # Bool = false
    FFlagManuallyInvokeAmpUpsell2 = 1767650004048  # Unknown = 
    FFlagManuallyMigrateDeprecatedIconUsage = 1767470828432  # Unknown = 
    FFlagMarketplaceCatalogCategoryTrackLastReceived = 1767525975824  # Unknown = 
    FFlagMarketplaceCatalogSortTrackLastReceived = 1767525977616  # Unknown = 
    FFlagMarketplaceOffersOptOutRoot = 1767831104400  # Unknown = 
    FFlagMarketplaceOffersOptOutRootLowSpender = 1767831098448  # Unknown = 
    FFlagMarketplaceOffersOptOutRootNoSpender = 1767831103248  # Unknown = 
    FFlagMarketplaceOffersOptOutRootRandom = 1767831106128  # Unknown = 
    FFlagMarketplaceOffersRoot = 1767828559184  # Unknown = 
    FFlagMarketplaceOffersRootLowSpender = 1767828580112  # Unknown = 
    FFlagMarketplaceOffersRootNoSpender = 1767831098640  # Unknown = 
    FFlagMarketplaceOffersRootRandom = 1767831104912  # Unknown = 
    FFlagMeTabBadgeEnabled = 1767473196880  # Unknown = 
    FFlagMeTabRightOfPartyBottomNav = 1767473196304  # Unknown = 
    FFlagMediaAccordionAndFullTelemetry = 1768215362512  # Unknown = 
    FFlagMediaGalleryVideoVisiblePercent = 1767831060560  # Unknown = 
    FFlagMediaSelectorErrorLogging = 1768132388509  # Bool = false
    FFlagMemoizeBubbleChatApp = 1768399805392  # Unknown = 
    FFlagMemoizeChatInputApp = 1767989420688  # Unknown = 
    FFlagMemoizeChatReportingMenu = 1768133871696  # Unknown = 
    FFlagMenuButtonsDisconnectGamepadConnected = 1768126100496  # Unknown = 
    FFlagMenuButtonsIncreaseIconSize = 1768126103056  # Unknown = 
    FFlagMenuButtonsMountWithIEM = 1768132564253  # Bool = false
    FFlagMenuButtonsUseGreyResumeButton = 1768126103709  # Bool = false
    FFlagMicroProfilerReadOnlyInformationLabel = 1767913339549  # Bool = false
    FFlagMigrateAllOsaMessagingToCentralService = 1767583571549  # Bool = true
    FFlagMigrateCameraCFrameDatamodel = 1767404482653  # Bool = false
    FFlagMigrateCameraFocusDatamodel = 1767404482461  # Bool = false
    FFlagMigrateCameraFovDatamodel = 1767404482333  # Bool = false
    FFlagMigrateFriendshipStatusesPYMK = 1767643526237  # Bool = false
    FFlagMigrateFriendshipStatusesRemainingActions = 1767525992989  # Bool = false
    FFlagMigrateFriendshipStatusesSocialCarousel = 1767641307165  # Bool = false
    FFlagMigrateFriendshipStatusesUserSearch = 1767648635293  # Bool = false
    FFlagMigrateGameIconsToStore = 1768005278480  # Unknown = 
    FFlagMigrateGameInfoToStoreDev = 1767525976464  # Unknown = 
    FFlagMigrateNoFriendsViewToFoundation = 1767641303069  # Bool = false
    FFlagMigratePymkCarouselHttpRequestToRequestInternal = 1767643510749  # Bool = false
    FFlagMigrateRoactUtilsToReactUtils = 1767470831325  # Bool = false
    FFlagMigrateSocialNetworking = 1768458334544  # Unknown = 
    FFlagMigrateUserSearchHttpRequestToRequestInternal = 1767648648912  # Unknown = 
    FFlagMinMaxPriceValidation = 1768393680656  # Unknown = 
    FFlagMobileGameJoinCardEDPFromThumbnail = 1767641305309  # Bool = false
    FFlagMobileGameJoinCardEDPFromTitle = 1767641300304  # Unknown = 
    FFlagMobileGameJoinCardHideUserAvatar = 1767641306013  # Bool = false
    FFlagMobileGameJoinCardShowExperienceNameOnly = 1767641306589  # Bool = false
    FFlagMobileGameJoinCardTTITracking = 1767583527261  # Bool = true
    FFlagMobileGameJoinCardThumbnail = 1767641302992  # Unknown = 
    FFlagMobilePopularItemBadgingExperimentEnabled = 1767838273197  # Bool = false
    FFlagMobilePopularItemBadgingExperimentEnabledV2 = 1768125840861  # Bool = false
    FFlagMobileSoundAndHapticsEnabledIXP = 1768389359952  # Unknown = 
    FFlagMobileSoundAndHapticsIXPBypass = 1768389393296  # Unknown = 
    FFlagMockDevSubPurchaseInStudio = 1776067293904  # Unknown = 
    FFlagModalImpressionEventAddSessionInfo = 1767650182544  # Unknown = 
    FFlagModalSelectorCloseButton = 1768377271440  # Unknown = 
    FFlagMomentTextGenerationFilteredSignal = 1776085378448  # Unknown = 
    FFlagMomentsAnalyticsClientEventTimestamp = 1768438452496  # Unknown = 
    FFlagMomentsAnalyticsProducerPrereqs = 1768438487440  # Unknown = 
    FFlagMomentsAnalyticsSchemaIdentity = 1768438490768  # Unknown = 
    FFlagMomentsAutoplayAmpPolicy = 1767470819600  # Unknown = 
    FFlagMomentsCarouselVideoHandoff = 1767583432848  # Unknown = 
    FFlagMomentsContentStatsTelemetry = 1776085385872  # Unknown = 
    FFlagMomentsCreationAccurateDirtyTracking = 1776085419280  # Unknown = 
    FFlagMomentsCreationBlockBackgroundInteraction = 1776085416605  # Bool = false
    FFlagMomentsCreationGalleryPreviewSwapFix = 1776085414493  # Bool = true
    FFlagMomentsCreationMusicSearchStateFix = 1776085370000  # Unknown = 
    FFlagMomentsCreationNormalizeMetadataEnums = 1776085388432  # Unknown = 
    FFlagMomentsCreationPersistEditSession = 1776085399581  # Bool = false
    FFlagMomentsCreationSaveDraft = 1768225479477  # Bool = true
    FFlagMomentsCreationTextOverlayResolutionScale = 1776074625984  # Unknown = 
    FFlagMomentsDarkAppNavBar = 1767831073040  # Unknown = 
    FFlagMomentsDescriptionKeyboardAvoidance = 1776085409501  # Bool = true
    FFlagMomentsEmojiSetsApi = 1768328491429  # Bool = true
    FFlagMomentsEntryImmersiveNav = 1767828580688  # Unknown = 
    FFlagMomentsFeedHealthAnalytics = 1776085381264  # Unknown = 
    FFlagMomentsFeedWatchPageAttribution = 1767470819357  # Bool = false
    FFlagMomentsFixBatchedGetMomentsQueryParams = 1768132379024  # Unknown = 
    FFlagMomentsIPReporting = 1767470820048  # Unknown = 
    FFlagMomentsLoopOnEndSeek = 1776085402768  # Unknown = 
    FFlagMomentsMediaSmoothnessTelemetry = 1776085385488  # Unknown = 
    FFlagMomentsMuteVideoAudioOnly = 1776085398301  # Bool = true
    FFlagMomentsOverlayContainerScaleFallback = 1776085408976  # Unknown = 
    FFlagMomentsPassFeedItemIdToBackendApis = 1767900715333  # Bool = true
    FFlagMomentsPostCtaUseCaptureUniverse = 1776085381776  # Unknown = 
    FFlagMomentsProfileGridInfiniteLoad = 1776085400400  # Unknown = 
    FFlagMomentsReactToFeedItemV2 = 1767807353701  # Bool = true
    FFlagMomentsRealtimeObservability = 1776085382992  # Unknown = 
    FFlagMomentsRealtimeSessionTelemetry = 1776085373968  # Unknown = 
    FFlagMomentsRefreshOwnMomentsAfterPublish = 1767470821277  # Bool = false
    FFlagMomentsRemoveDeletedFromProfile = 1767470820829  # Bool = false
    FFlagMomentsReportWithFeedId = 1767831073104  # Unknown = 
    FFlagMomentsRequireApiFeedItemId = 1768050286045  # Bool = false
    FFlagMomentsRespectAccountTheme = 1767831072400  # Unknown = 
    FFlagMomentsScreenshotMusicScrubber = 1776085371869  # Bool = false
    FFlagMomentsSessionHeartbeat = 1776085385104  # Unknown = 
    FFlagMomentsStickerButton3 = 1776085373392  # Unknown = 
    FFlagMomentsStickerOverlayMediaRect = 1776085408144  # Unknown = 
    FFlagMomentsStickerOverlayNormalization = 1768050290128  # Unknown = 
    FFlagMomentsStickerOverlayNormalization2 = 1768050317584  # Unknown = 
    FFlagMomentsSurfaceLoadTTI = 1767470819933  # Bool = false
    FFlagMomentsTTSAudioOverlayLua2 = 1776085388573  # Bool = false
    FFlagMomentsTabReactiveIXP = 1767470808080  # Unknown = 
    FFlagMomentsTextDragToDelete = 1776085394064  # Unknown = 
    FFlagMomentsTextOverlayAfterVideoLoaded = 1776085377104  # Unknown = 
    FFlagMomentsTextOverlayClampToBounds = 1776085381584  # Unknown = 
    FFlagMomentsTextOverlayMediaRect = 1776085395152  # Unknown = 
    FFlagMomentsTileSkeletonPoster = 1776085391248  # Unknown = 
    FFlagMomentsUseBackendPostStatusNotification = 1776085424976  # Unknown = 
    FFlagMomentsUseUploadPostAsync = 1776085404560  # Unknown = 
    FFlagMomentsVideoCropRoundedCorners = 1776085380880  # Unknown = 
    FFlagMomentsVideoSurfaceMediaRect = 1776085393360  # Unknown = 
    FFlagMomentsWatchSessionalization = 1767470819037  # Bool = false
    FFlagMoreFramerateOptions = 1767972970397  # Bool = false
    FFlagMountCoreGuiBackpack = 1768017070224  # Unknown = 
    FFlagMountUnmountSideSheet = 1767998345757  # Bool = false
    FFlagMoveAmpUpsellOffNavigateDown = 1767583563984  # Unknown = 
    FFlagMoveInExperienceModeToEditProfile_V2 = 1767583398096  # Unknown = 
    FFlagMoveLimitedBadgeToTopLeft = 1767899169245  # Bool = false
    FFlagMoveLuaExpLaunchBegin = 1767989389533  # Bool = false
    FFlagMoveReducerCreationOutOfReducer = 1767410400280  # Unknown = 
    FFlagMusicPlayerUseDynamicNavBarHeight = 1767828608912  # Unknown = 
    FFlagMutualConnectionsListPagination = 1768133877213  # Bool = false
    FFlagMyStatsMediaSelector3 = 1767831065680  # Unknown = 
    FFlagNavigateToSafetyDashboardForAppeals = 1768372146640  # Unknown = 
    FFlagNavigateToSafetyDashboardForAppeals2 = 1767583573277  # Bool = true
    FFlagNewEventIngestPlayerScriptsDimensions = 1768132561821  # Bool = false
    FFlagNewInGameMenuDisabledInVR = 1767972959453  # Bool = false
    FFlagNewPeopleButtonOrder = 1768389373584  # Unknown = 
    FFlagNewPeopleButtonOrder4 = 1768389407056  # Unknown = 
    FFlagNewPeoplePageIcons = 1768389384912  # Unknown = 
    FFlagNewPeoplePageIcons5 = 1768389384464  # Unknown = 
    FFlagNewUpsellModalExperiment = 1776050398416  # Unknown = 
    FFlagNewUpsellModalExperimentForDesktopV2 = 1768125833437  # Bool = false
    FFlagNewUpsellModalExperimentForPlatform = 1768125831568  # Unknown = 
    FFlagNewUpsellModalExperimentV2 = 1768125833181  # Bool = false
    FFlagNoShortcutBarWithTvRemote = 1768017088848  # Unknown = 
    FFlagNonVoiceFTUX = 1768133852432  # Unknown = 
    FFlagNormalizePriceDiscountAcceptLowercase = 1776067337360  # Unknown = 
    FFlagNotApprovedPageIXPExposure = 1767583562064  # Unknown = 
    FFlagNotificationModalSetMenuIsOpen = 1767526165533  # Bool = false
    FFlagNotificationThumbnailUseProfileFrameThumbnail = 1768017087568  # Unknown = 
    FFlagNotificationsComplianceShouldRestrictStream = 1767583531536  # Unknown = 
    FFlagNotificationsForceEnableEDPDiscoverability = 1767583535773  # Bool = true
    FFlagNotificationsRenameFriendRequestToConnection = 1768133934557  # Bool = false
    FFlagNotificationsUpsellDisableBackgroundDismiss = 1767641316189  # Bool = false
    FFlagOffNetworkAnalytics = 1768458301712  # Unknown = 
    FFlagOnlyEnableJoinVoiceInVoiceEnabledUniversesV2 = 1768001206429  # Bool = false
    FFlagOnlyShowToastOnce2 = 1767913328797  # Bool = false
    FFlagOnlyShowToastOnceInLifetime2 = 1767913329744  # Unknown = 
    FFlagOpenVngTosForVngRobuxUpsell = 1767526151261  # Bool = false
    FFlagOrientationUseTelemetryService = 1768017221520  # Unknown = 
    FFlagOverflowMenuRemoveCloseMenuChecks = 1768017221328  # Unknown = 
    FFlagOverrideInExperienceMenuReorderFirstVariant = 1767913664213  # Bool = false
    FFlagOverridePlayerVerifiedBadge = 1767470825744  # Unknown = 
    FFlagPCMAcceptWidthAsProp = 1767423155408  # Unknown = 
    FFlagPPDebugLogging = 1776067289424  # Unknown = 
    FFlagPPVBackgroundUse2DAsLoadingState = 1767583390813  # Bool = false
    FFlagPPVEnable3DBackground = 1768009997840  # Unknown = 
    FFlagPPVEnabledOnConsole_V3 = 1767583384656  # Unknown = 
    FFlagPYMKAddFriendsEntry_v3 = 1767583404048  # Unknown = 
    FFlagPYMKDisableButtonsOnFetch = 1767648613405  # Bool = false
    FFlagPYMKFriendsToastRename = 1767648613277  # Bool = false
    FFlagPYMKShowAddFriendsButton_DEV = 1767650183197  # Bool = false
    FFlagPackagifySettingsShowSignal = 1767526165213  # Bool = false
    FFlagPageLoadAllowImprovedDisconnectTiming = 1767470840976  # Unknown = 
    FFlagParseHeadShapeFromAPIResponse = 1767977099613  # Bool = false
    FFlagParseHeadShapeFromAPIResponse6 = 1767977096541  # Bool = false
    FFlagPartyCoordinationUIExposureEnabled = 1767645303632  # Unknown = 
    FFlagPartyDevAPIToRespectThirdPartySettingsEnabled = 1767583394064  # Unknown = 
    FFlagPartyFormationCreateUserExposureEnabled = 1767645310173  # Bool = false
    FFlagPartyFoundationIconFixEnabled = 1767583388880  # Unknown = 
    FFlagPartyVoiceDisallowIXPLayerExposureOnInit = 1767473188573  # Bool = false
    FFlagPartyVoiceLogActiveDM = 1767473189853  # Bool = false
    FFlagPassNavigationToContactsRevoked = 1768181197200  # Unknown = 
    FFlagPassShopPurchaseSurfaceToBuyModal = 1767828602384  # Unknown = 
    FFlagPasskeySignupEnabled5 = 1767650170781  # Bool = false
    FFlagPasskeyUpsellEnabled = 1767720514576  # Unknown = 
    FFlagPasskeyUpsellEnabled1 = 1767720496144  # Unknown = 
    FFlagPasskeyUpsellFilteringEnabled = 1767720499024  # Unknown = 
    FFlagPasswordErrorLength = 1767583570653  # Bool = true
    FFlagPasswordErrorSimple = 1767526242845  # Bool = false
    FFlagPeekViewFixBriefHeightLayoutRace = 1768458303568  # Unknown = 
    FFlagPeopleCardsEnableVirtualizedGrid = 1768389352720  # Unknown = 
    FFlagPeopleListContextualMenuFixFocusNavigation = 1768133878416  # Unknown = 
    FFlagPeoplePageCardMenuUseVisibleProperty = 1768317832789  # Bool = false
    FFlagPeoplePageDismissCardMenuOnScrollOutOfView = 1768389351184  # Unknown = 
    FFlagPeoplePageDismissVolumePopoverOnScrollOutOfView = 1768389390416  # Unknown = 
    FFlagPeoplePageEnablePersonSignalStore = 1768389348176  # Unknown = 
    FFlagPeoplePageFlipVolumePopoverToFitViewport = 1768389347472  # Unknown = 
    FFlagPeoplePageLazyRenderCards = 1768389375824  # Unknown = 
    FFlagPeoplePagePostponeInitialRender = 1768389350352  # Unknown = 
    FFlagPeoplePageRemoveSkeletons = 1768389399184  # Unknown = 
    FFlagPeoplePageRemoveUseMemoElements = 1768389350992  # Unknown = 
    FFlagPeopleTabUseProfileFrameThumbnail = 1768317806557  # Bool = false
    FFlagPerfInsightsEnabled = 1767650166224  # Unknown = 
    FFlagPermissionAlertContentUpgrade = 1768187262181  # Bool = true
    FFlagPhoneUseParentSizeForScreenSize = 1768389364304  # Unknown = 
    FFlagPhoneVerificationWebviewShouldBeFullscreen1 = 1768458310032  # Unknown = 
    FFlagPlatformEventEnabled2 = 1768010004240  # Unknown = 
    FFlagPlatformLeaderboardDebugLogging = 1768009958608  # Unknown = 
    FFlagPlatformLeaderboardEnabled = 1768132546320  # Unknown = 
    FFlagPlatformLeaderboardLocalizedUnitEnabled = 1768132548445  # Bool = false
    FFlagPlatformLeaderboardPersistStoreOnRemount = 1767725046112  # Unknown = 
    FFlagPlatformLeaderboardRccEnabled = 1768009990096  # Unknown = 
    FFlagPlatformLeaderboardRccEnabled2 = 1768009983133  # Bool = false
    FFlagPlatformLeaderboardsExposure2Enabled_V2 = 1768132547101  # Bool = false
    FFlagPlatformLeaderboardsIXPNoLeaderboardsShown_V3 = 1768132548893  # Bool = false
    FFlagPlayStationBumperHint = 1768027288080  # Unknown = 
    FFlagPlayWithRewardClearOnExperienceLeave = 1767828569488  # Unknown = 
    FFlagPlayWithRewardCoachmarkOverlayFix = 1767828573072  # Unknown = 
    FFlagPlayWithRewardCoachmarkWindowResets = 1767654034205  # Bool = false
    FFlagPlayerListClosedNoRender = 1767628627216  # Unknown = 
    FFlagPlayerListClosedNoRenderWithTenFoot = 1767628630736  # Unknown = 
    FFlagPlayerListDropDownShowPlatformName = 1768132540253  # Bool = false
    FFlagPlayerListFilterInputServiceDispatches = 1768136661917  # Bool = false
    FFlagPlayerListFixLeaderstatsStacking2 = 1768399829149  # Bool = false
    FFlagPlayerListFixMobileScrolling = 1768136655952  # Unknown = 
    FFlagPlayerListFoundationSubscriptionIcon = 1768132541149  # Bool = false
    FFlagPlayerListHideUnusedStats = 1768132533661  # Bool = false
    FFlagPlayerListIgnoreDevGamepadBindings = 1776086695120  # Unknown = 
    FFlagPlayerListIgnoreDevGamepadBindings2 = 1768132539357  # Bool = false
    FFlagPlayerListLocalizeGameText = 1768132540816  # Unknown = 
    FFlagPlayerListPersistVisibility = 1768047651872  # Unknown = 
    FFlagPlayerListReduceRerenders = 1768136653085  # Bool = false
    FFlagPlayerListRefactorUsernameFormatting = 1768317821264  # Unknown = 
    FFlagPlayerListRemoveTopStat = 1768040511245  # Bool = false
    FFlagPlayerListReskin = 1768296579429  # Bool = false
    FFlagPlayerListReskin3 = 1768132541661  # Bool = false
    FFlagPlayerListSortByLowercaseUsername = 1768132534045  # Bool = false
    FFlagPlayerListTopStatCheckGamepad = 1768136661648  # Unknown = 
    FFlagPlayerListTwoTabs = 1768132541981  # Bool = false
    FFlagPlayerListTwoTabsOnLegacy = 1768132542301  # Bool = false
    FFlagPlayerListUseFocusNavHook = 1768218570717  # Bool = true
    FFlagPlayerListUseFocusNavHook2 = 1768132535261  # Bool = false
    FFlagPlayerListUseMobileOnSmallDisplay = 1776086724752  # Unknown = 
    FFlagPlayerListUseMobileOnSmallDisplay2 = 1768132534864  # Unknown = 
    FFlagPlayerSearchEnableOnlineFrequents = 1768009957840  # Unknown = 
    FFlagPlayerSearchEnableOnlineFrequentsForAll = 1768009968720  # Unknown = 
    FFlagPlayerViewRemoteEnabled = 1767908724125  # Bool = false
    FFlagPlaytestModeExcludeStudio = 1768385628781  # Bool = false
    FFlagPopularFillIconEnabled = 1768125838224  # Unknown = 
    FFlagPreHomePageRoutingEnabled = 1767720546192  # Unknown = 
    FFlagPreciseSelectionBugfixesEnabled = 1768377281424  # Unknown = 
    FFlagPrefetchFriendGameMedia = 1768444720584  # Unknown = 
    FFlagPrefetchProfileNamesOnStartup_v2 = 1768181185424  # Unknown = 
    FFlagPrefillPreciseSelectionChoices = 1767583571344  # Unknown = 
    FFlagPreselectedPlayerReportBugfix = 1768317817040  # Unknown = 
    FFlagPresencePropagationDelayMonitoringEnabledV2 = 1767650166032  # Unknown = 
    FFlagPreventHiddenSwitchPage = 1768029408709  # Bool = true
    FFlagPreventMicToggleIfGameConsumedEvent = 1768399765776  # Unknown = 
    FFlagPreventSuperBriefPeekViewClose2 = 1768458329808  # Unknown = 
    FFlagPriceSummaryV2UseLocalizedBreakdown = 1768158662285  # Bool = true
    FFlagProfileAboutDetailsUseSheet = 1767583426896  # Unknown = 
    FFlagProfileContextualMenuDisableFix = 1767583434960  # Unknown = 
    FFlagProfileEnableSocialNetworksUsernames = 1768133861968  # Unknown = 
    FFlagProfileFixMenuNavigation = 1768165599056  # Unknown = 
    FFlagProfileFixMenuNavigation_V2 = 1767583435280  # Unknown = 
    FFlagProfileFrameThumbnailEnabled = 1768133856016  # Unknown = 
    FFlagProfileHideTabBarOnAboutSheet = 1767654036752  # Unknown = 
    FFlagProfileInspectAndBuyRefactorTooltip = 1768317831760  # Unknown = 
    FFlagProfileInspectAvatarCWEntry = 1768317789456  # Unknown = 
    FFlagProfileMomentsFeedHideTabBar = 1767654037648  # Unknown = 
    FFlagProfileMomentsFeedRootRoute = 1767831060240  # Unknown = 
    FFlagProfileMomentsOrderingAndReactions = 1767583430736  # Unknown = 
    FFlagProfileMomentsVideoPlaybackFix = 1767583431312  # Unknown = 
    FFlagProfilePlatformAboutBeforeActionClient = 1767418842960  # Unknown = 
    FFlagProfilePlatformAddCurrentlyPlaying_V4 = 1767418829680  # Unknown = 
    FFlagProfilePlatformAddTC = 1768165593424  # Unknown = 
    FFlagProfilePlatformAddTC_v10 = 1767583433232  # Unknown = 
    FFlagProfilePlatformCTAsRefactor = 1775910005968  # Unknown = 
    FFlagProfilePlatformCTAsRefactor_V3 = 1767411613392  # Unknown = 
    FFlagProfilePlatformEditBackgroundMenuItem = 1767473199824  # Unknown = 
    FFlagProfilePlatformEnableAvatarBackground = 1768009973533  # Bool = false
    FFlagProfilePlatformEnableBundlesInAssetsCarousel = 1768133833744  # Unknown = 
    FFlagProfilePlatformEnableChipSocialRow_v6 = 1767418835133  # Bool = true
    FFlagProfilePlatformEnableClickToCopyUsername = 1767418883133  # Bool = true
    FFlagProfilePlatformEnableCoverPhotoPeekViewFix_v2 = 1767625364976  # Unknown = 
    FFlagProfilePlatformEnableCurrencyTransfer = 1768165548304  # Unknown = 
    FFlagProfilePlatformEnableCurrencyTransferV1 = 1767583429789  # Bool = false
    FFlagProfilePlatformEnableEditAppearanceMenu = 1767473200349  # Bool = false
    FFlagProfilePlatformEnableImpressions = 1767583421712  # Unknown = 
    FFlagProfilePlatformEnableInventory = 1768165584272  # Unknown = 
    FFlagProfilePlatformEnableInventory_V2 = 1767583425104  # Unknown = 
    FFlagProfilePlatformEnableLazyLoadingComponents = 1768317822288  # Unknown = 
    FFlagProfilePlatformEnableLazyLoadingComponentsV5 = 1767473197789  # Bool = false
    FFlagProfilePlatformEnableMoments = 1767473199056  # Unknown = 
    FFlagProfilePlatformEnableSchoolChip = 1767583429008  # Unknown = 
    FFlagProfilePlatformEnableStore = 1768165554973  # Bool = false
    FFlagProfilePlatformEnableStore_V2 = 1767583424464  # Unknown = 
    FFlagProfilePlatformEnableTradeItems = 1767473200797  # Bool = false
    FFlagProfilePlatformEnableUnlockChat_V2 = 1767418832893  # Bool = true
    FFlagProfilePlatformEnableVR = 1768385633957  # Bool = true
    FFlagProfilePlatformEnableVR_v2 = 1768385633837  # Bool = false
    FFlagProfilePlatformFavoritesEnableGameDetailAnalytics = 1768133831504  # Unknown = 
    FFlagProfilePlatformFixPresenceReducer = 1767473198608  # Unknown = 
    FFlagProfilePlatformImproveGameDetailsAnalytics = 1768133834064  # Unknown = 
    FFlagProfilePlatformMeTabMobileProfileHero = 1775988797704  # Unknown = 
    FFlagProfilePlatformNewAboutSection_v9 = 1767418843600  # Unknown = 
    FFlagProfilePlatformNewProfileHeader = 1768165550800  # Unknown = 
    FFlagProfilePlatformNewProfileHeader_v4 = 1767583432656  # Unknown = 
    FFlagProfilePlatformPassPresenceToJoinUserInExperience = 1767583433104  # Unknown = 
    FFlagProfilePlatformPeekDraggerContrast = 1767583430608  # Unknown = 
    FFlagProfilePlatformPresenceStoreMigration = 1768317843472  # Unknown = 
    FFlagProfilePlatformPresenceStoreMigration_v1 = 1767473197213  # Bool = false
    FFlagProfilePlatformTrustedConnectionsMVP = 1767583432080  # Unknown = 
    FFlagProfilePlatformUseCatalogItemOpenedNewFields = 1768317786512  # Unknown = 
    FFlagProfilePlatformUseNewLayoutForAssetsCarousel = 1775985076981  # Bool = false
    FFlagProfilePlatformUseProfileTypeContext = 1767650170653  # Bool = true
    FFlagProfilePlatformUseRoduxNetworkingRefactor = 1767473201245  # Bool = false
    FFlagProfileQRCodeFixFocusNavigation = 1768181163984  # Unknown = 
    FFlagProfileQrCodeDeprecateUserRedux = 1768181176720  # Unknown = 
    FFlagPromptBannerWaitInSmallIntervals = 1767723041885  # Bool = false
    FFlagPromptCreatorTransientDialog = 1768017063901  # Bool = true
    FFlagPromptFriendRequestModalRevampFriendsRename = 1768017067280  # Unknown = 
    FFlagPromptPurchaseClearStateOnCompletion = 1776067306960  # Unknown = 
    FFlagPromptsHandlerCoachmarkEnabled = 1768458308560  # Unknown = 
    FFlagPromptsHandlerEnabled = 1768458325200  # Unknown = 
    FFlagPromptsHandlerEnabled2 = 1768458303376  # Unknown = 
    FFlagPromptsImpressionUsesTitle = 1768458322768  # Unknown = 
    FFlagPurchaseModalTimedOptionExtension = 1767831094608  # Unknown = 
    FFlagPurchasePromptAppConditionalFocusNavigation = 1767897049501  # Bool = false
    FFlagPurchasePromptAppFixStyleLink = 1767897050205  # Bool = false
    FFlagPurchasePromptAppTrackRenderPerformance = 1767897049885  # Bool = false
    FFlagPurchasePromptCartPricingEnabled = 1776067341456  # Unknown = 
    FFlagPurchasePromptCartPricingRequireOffer2 = 1767640165789  # Bool = false
    FFlagPurchasePromptCartPricingSkipFreeItems2 = 1767900762173  # Bool = true
    FFlagPurchasePromptCartPricingSkipLimitedCollectibles = 1775984820520  # Unknown = 
    FFlagPurchasePromptCartPricingSkipLimitedCollectibles2 = 1767640165469  # Bool = false
    FFlagPurchasePromptElevateDisplayOrder = 1767897051165  # Bool = false
    FFlagPurchasePromptFetchCartPricing = 1767831106320  # Unknown = 
    FFlagPurchasePromptFetchCartPricing2 = 1767831106192  # Unknown = 
    FFlagPurchasePromptFetchCartPricingForLooks = 1767831100112  # Unknown = 
    FFlagPurchasePromptFetchCartPricingForLooks2 = 1767831099152  # Unknown = 
    FFlagPurchasePromptFixOfferMarginUpsell = 1767831099408  # Unknown = 
    FFlagPurchasePromptOfferMarginUpsellEnabled = 1776067317469  # Bool = false
    FFlagPurchasePromptPreviewMakeupHead = 1768132437213  # Bool = false
    FFlagPurchasePromptPriceShouldUseProductInfoPrice = 1776067301712  # Unknown = 
    FFlagPurchasePromptPriceShouldUseProductInfoPrice4 = 1776067332048  # Unknown = 
    FFlagPurchasePromptSubtitleForTimedOptions = 1767831096592  # Unknown = 
    FFlagPurchasePromptSubtitleForTimedOptions2 = 1767831096208  # Unknown = 
    FFlagPurchasePromptUnifiedEventsUseOfferAdjustedPrice = 1767831101776  # Unknown = 
    FFlagPymkCarouselPresenceStoreMigration_v2 = 1767643521360  # Unknown = 
    FFlagQRCodeCopyUpdates_v2 = 1767583526941  # Bool = true
    FFlagQRCodeFriendRequestNotificationV2 = 1768181156816  # Unknown = 
    FFlagQRCodeItemRedemptionEnabled = 1767650032336  # Unknown = 
    FFlagQRCodeScannerDeeplinkEnabledForAll = 1768133882896  # Unknown = 
    FFlagQRInSearchProfileQR = 1768054617424  # Unknown = 
    FFlagQRInSearchScanner = 1768376847037  # Bool = false
    FFlagRAEnableCircleRegion = 1768027314640  # Unknown = 
    FFlagRAKickLogic2 = 1768024102749  # Bool = false
    FFlagRateLimitNudgeDialog = 1768132413405  # Bool = false
    FFlagRateLimitNudgeToast = 1768132413149  # Bool = false
    FFlagRateLimitTimeoutDialog = 1768132413533  # Bool = false
    FFlagRateLimitTimeoutToast = 1768132413277  # Bool = false
    FFlagReactCatchYieldingInDEV = 1768005274256  # Unknown = 
    FFlagReactCleanQueueOnUpdateBailout = 1767650186384  # Unknown = 
    FFlagReactDevtoolsFixTopbar = 1768133939613  # Bool = false
    FFlagReactEnableNewTreeCleanupPath = 1768005257168  # Unknown = 
    FFlagReactEnableSchedulingProfiler = 1768005263312  # Unknown = 
    FFlagReactFilterInternalStackFrames = 1768005297168  # Unknown = 
    FFlagReactFixBindingMemoryLeak = 1768005252189  # Bool = true
    FFlagReactInlineMergeLanes = 1768005271197  # Bool = true
    FFlagReactInstanceMapDisableErrorChecking = 1768005253520  # Unknown = 
    FFlagReactIsProtectedTypeOf = 1767860840541  # Bool = false
    FFlagReactIsolatedGlobalsEnabled = 1767900729277  # Bool = true
    FFlagReactPreventAssigningKeyToChildren = 1767650186000  # Unknown = 
    FFlagReactSchedulerEnableDeferredWork = 1768005283997  # Bool = false
    FFlagReactSchedulerLookbackUseRingBuffer = 1768005247261  # Bool = true
    FFlagReactSchedulerSetFrameMarkerOnHeartbeatEnd = 1768005272144  # Unknown = 
    FFlagReactSchedulerSetTargetMsByHeartbeatDelta = 1768005249693  # Bool = false
    FFlagReactSchedulingTrackerDataModelUpdate = 1768399094493  # Bool = false
    FFlagReactSchedulingTrackerLayoutEffects = 1768393710928  # Unknown = 
    FFlagReactTelemetryEnabled = 1767828568477  # Bool = true
    FFlagReadAppChatFetchingVariable = 1768133839440  # Unknown = 
    FFlagRealNamesInDisplayNamesEnabledForAll = 1767654039696  # Unknown = 
    FFlagReducePromiseTaskDefer = 1767583405456  # Unknown = 
    FFlagReduceTopBarInsetsWhileHidden = 1767828590992  # Unknown = 
    FFlagRefactorButtonTileCircular = 1768133881104  # Unknown = 
    FFlagRefactorHelpPage = 1768438443933  # Bool = false
    FFlagRefactorHelpPage5 = 1768126099613  # Bool = false
    FFlagRefactorInExpSettingsInDevelopment = 1768132559389  # Bool = false
    FFlagRefactorMenuConfirmationButtons = 1767913664277  # Bool = false
    FFlagRefactorMenuConfirmationButtons5 = 1768001222173  # Bool = false
    FFlagRefactorPeoplePage = 1767913664405  # Bool = false
    FFlagRefactorPeoplePage9 = 1767628316989  # Bool = false
    FFlagRefactorReconnectUnblockTeleport = 1768024098077  # Bool = false
    FFlagRefreshAuthSessionAfterLanguageChange = 1767828595152  # Unknown = 
    FFlagRefreshDevSubPriceOnRetryAfterUpsell2 = 1776067299792  # Unknown = 
    FFlagRefreshLookPriceOnRetryAfterUpsell = 1776067284125  # Bool = false
    FFlagRefreshPriceOnRetryAfterUpsell = 1776067306256  # Unknown = 
    FFlagRegisterQRCodeKeyInEngine = 1768133828624  # Unknown = 
    FFlagRegisterQRCodeKeyInEngine_v2 = 1768133859037  # Bool = true
    FFlagRelocateMobileMenuButtons = 1767913664469  # Bool = false
    FFlagRelocateMobileMenuButtons4 = 1768001219024  # Unknown = 
    FFlagReminderAPIFetchErrorLogging = 1767723050461  # Bool = false
    FFlagRemoveAcountInfoFetchFromPurchase = 1776067240576  # Unknown = 
    FFlagRemoveAssetVersionEndpoint = 1768132561117  # Bool = false
    FFlagRemoveAvatarSwitcherIfUnsupported = 1767526162704  # Unknown = 
    FFlagRemoveBottomNavOnLookDetails = 1767831065168  # Unknown = 
    FFlagRemoveCentralOverlayBackgroundSafeArea = 1767654070685  # Bool = false
    FFlagRemoveCentralOverlayScrimForUnifiedPurchaseModal = 1767828558160  # Unknown = 
    FFlagRemoveClassicHeadsAndFaces = 1767977108701  # Bool = false
    FFlagRemoveDataLoaderTimer = 1767583423696  # Unknown = 
    FFlagRemoveDelayedInputForUnifiedPurchaseModal = 1767897042333  # Bool = false
    FFlagRemoveDiscoverabilityModal = 1767650184848  # Unknown = 
    FFlagRemoveExitModal = 1767913664533  # Bool = false
    FFlagRemoveFetchFriendsCarouselAtStartup = 1767649996944  # Unknown = 
    FFlagRemoveFriendsChatUnibarEntrypoints = 1767583394653  # Bool = false
    FFlagRemoveHardCodedFriendLimitPrompt = 1768133928208  # Unknown = 
    FFlagRemoveHttpErrorLog2 = 1767650175696  # Unknown = 
    FFlagRemoveKeystoreIxpLogic = 1767828572176  # Unknown = 
    FFlagRemoveLeaveShortcutFromLeaveConfirm = 1768049915976  # Unknown = 
    FFlagRemoveLoadingTimeout = 1768389386965  # Bool = false
    FFlagRemoveLoggingHookForCorescriptGlobalEffects2 = 1767908711248  # Unknown = 
    FFlagRemoveMobileHomeProfileHeader_v2 = 1767723046288  # Unknown = 
    FFlagRemoveNameRegex = 1767897051677  # Bool = false
    FFlagRemoveNewPlayerListOverlay = 1768132537501  # Bool = false
    FFlagRemovePeekViewScrimBorder = 1768393684112  # Unknown = 
    FFlagRemovePhoneUpsellWebview = 1767650184720  # Unknown = 
    FFlagRemoveRecordPage = 1768132559837  # Bool = false
    FFlagRemoveRefToMissingLocInConnection = 1768389390160  # Unknown = 
    FFlagRemoveRespawnShortcutFromRespawnConfirmation = 1768049889096  # Unknown = 
    FFlagRemoveUnusedConnectionStateRoduxSlice = 1767831081168  # Unknown = 
    FFlagRemoveUnusedFriendStatusesRoduxSlice = 1767831081488  # Unknown = 
    FFlagRemoveUnusedGameThumbnailsRoduxSlice = 1767831077136  # Unknown = 
    FFlagRemoveUnusedLoginResultRoduxSlice = 1767831077776  # Unknown = 
    FFlagRemoveUnusedRoactChatRoduxSlice = 1767583392656  # Unknown = 
    FFlagRemoveUnusedSignUpInfoRoduxSlice = 1767831080144  # Unknown = 
    FFlagRemoveUnusedUserStatusesRoduxSlice = 1767831078224  # Unknown = 
    FFlagRemoveUnusedUsersAsyncRoduxSlice = 1767831078736  # Unknown = 
    FFlagRemoveVirtualEventsExperiment = 1767470826192  # Unknown = 
    FFlagRenameAvatarToMe = 1767831064464  # Unknown = 
    FFlagRenameDeprecatedUIBloxTokens3 = 1767470827152  # Unknown = 
    FFlagRenameParentEmailForVerificationUpsell = 1767583561693  # Bool = true
    FFlagRenameRespawnConfirmationPage = 1768399771229  # Bool = false
    FFlagRenameVolumeToMainVolume = 1767913340565  # Bool = false
    FFlagRenderChatConversationOnlyWhenVisible = 1768132440208  # Unknown = 
    FFlagRenderChatConversationOnlyWhenVisible3 = 1768132427344  # Unknown = 
    FFlagRenderPeoplePageOnTabSwitch = 1768317826845  # Bool = false
    FFlagRenderUseTextureManager224 = 1767833468989  # Bool = false
    FFlagReplaceChatLineReportingIcon = 1768001191645  # Bool = false
    FFlagReplaceMissingDesignTokens = 1767720485973  # Bool = false
    FFlagReplaceNavbarIconsWithFoundation = 1767831060368  # Unknown = 
    FFlagReplacePlayerIconRoduxWithSignal_2 = 1767526169821  # Bool = false
    FFlagReportAbuseMenuEntrypointAnalytics = 1768132562717  # Bool = false
    FFlagReportAnythingAnnotationIXP = 1767583560349  # Bool = true
    FFlagReportAnythingDebugCanvas = 1775992576080  # Unknown = 
    FFlagReportAnythingEnableAdReport = 1768027270800  # Unknown = 
    FFlagReportAnythingFixConvexHullCalculation = 1768126152413  # Bool = false
    FFlagReportAnythingLocalizationEnabled = 1775992628688  # Unknown = 
    FFlagReportAnythingMultistepScreenshot = 1775992583312  # Unknown = 
    FFlagReportAnythingScreenshot = 1775992585296  # Unknown = 
    FFlagReportFirstExperienceCancelled = 1768024083741  # Bool = false
    FFlagReportFocusNavIEMButtons = 1767913355413  # Bool = false
    FFlagReportFocusNavIEMButtons2 = 1768377262992  # Unknown = 
    FFlagReportListRadioSelectable = 1768317845072  # Unknown = 
    FFlagReportNotificationStreamCTA = 1767723042320  # Unknown = 
    FFlagRepositionDropDownScrim = 1768001222493  # Bool = false
    FFlagRepositionInExperienceVRToasts = 1768024052445  # Bool = false
    FFlagRespawnActionChromeShortcutTelemetry = 1767913321621  # Bool = false
    FFlagRespawnChromeShortcutTelemetry = 1768049909736  # Unknown = 
    FFlagRespectBalanceInfoForBundleUpsellInStudio = 1776067309712  # Unknown = 
    FFlagResponsiveUnitsProfileHeader = 1768317826960  # Unknown = 
    FFlagRetryAfterUpsellV2 = 1776067295376  # Unknown = 
    FFlagReworkPurchaseRobuxPage = 1767654045648  # Unknown = 
    FFlagRoactPolicyLoggerName = 1768297278493  # Bool = false
    FFlagRobloxExperienceKickOverride = 1768389389648  # Unknown = 
    FFlagRobloxPlusAmpSubscriptionCheck = 1767643496029  # Bool = false
    FFlagRobloxPlusFAEFreeTrial = 1768458345181  # Bool = true
    FFlagRobloxPlusUpdateDiscountIcons = 1767900715373  # Bool = true
    FFlagRobloxPlusUpsellRefreshOnComplete = 1768458311133  # Bool = true
    FFlagRobuxBadgeEnabled = 1767650005277  # Bool = false
    FFlagRobuxIconColorHotfix = 1767723043152  # Unknown = 
    FFlagRoduxRemoveConnectTraceback = 1768029424720  # Unknown = 
    FFlagRoduxSignalsNavigationMigration2 = 1767470816221  # Bool = false
    FFlagRoutePremiumToBlackbirdUpsell = 1776067320528  # Unknown = 
    FFlagSAToolEquipLuauFlag = 1768017071056  # Unknown = 
    FFlagScopeBadUtterancePlayerNameToChatDialogs = 1768050296784  # Unknown = 
    FFlagScopedSubscribersForPermissionsProtocol2 = 1768297317584  # Unknown = 
    FFlagScriptProfilerShowPlugins2 = 1768133903453  # Bool = false
    FFlagSduiActionSequence = 1767525978653  # Bool = false
    FFlagSduiActionSkipUnifiedLogging = 1767900749045  # Bool = true
    FFlagSduiActionTelemetryHandler2 = 1767900747773  # Bool = true
    FFlagSduiActionsUpdateFiresOwnTelemetry = 1767526013277  # Bool = false
    FFlagSduiAddMarketplaceEntityDataHydration = 1767525977757  # Bool = false
    FFlagSduiAgeCheckUpsellRaisePeekViewBriefHeight = 1768458315933  # Bool = true
    FFlagSduiAiOverviewEnabled = 1767525989904  # Unknown = 
    FFlagSduiAllowNoConfigsBuilt = 1768458353501  # Bool = true
    FFlagSduiAlwaysCacheWithIdentifier = 1768372136656  # Unknown = 
    FFlagSduiAlwaysCacheWithIdentifier3 = 1767583576464  # Unknown = 
    FFlagSduiApiStoreExposeGetInputData = 1768005244560  # Unknown = 
    FFlagSduiApiStoreOnSuccessAndRefresh = 1768005254160  # Unknown = 
    FFlagSduiAppPolicyBindings = 1767583579037  # Bool = true
    FFlagSduiArrayMapSupport = 1767720500560  # Unknown = 
    FFlagSduiBadgeComponent = 1767648652304  # Unknown = 
    FFlagSduiCapabilityBindings2 = 1767583579165  # Bool = true
    FFlagSduiCapabilityDevStoreSeeAllWebviewFallback = 1767583579421  # Bool = true
    FFlagSduiCardComponent = 1768372171408  # Unknown = 
    FFlagSduiCardComponent_v3 = 1767526001949  # Bool = true
    FFlagSduiCarouselUseNestedImpressionsFeedContext = 1767525987344  # Unknown = 
    FFlagSduiCatalogCategoryMenu = 1767525999952  # Unknown = 
    FFlagSduiCatalogItemGrid = 1767525976989  # Bool = false
    FFlagSduiCatalogVirtualizedFeed = 1768372169296  # Unknown = 
    FFlagSduiCatalogVirtualizedFeed4 = 1767526000528  # Unknown = 
    FFlagSduiChartsAnalyticsPage = 1767650177680  # Unknown = 
    FFlagSduiChartsDedupSessionRotation = 1767526010205  # Bool = false
    FFlagSduiChartsPlaceholderMergeStrategySupport = 1768005286800  # Unknown = 
    FFlagSduiChartsPostBody = 1767526010461  # Bool = false
    FFlagSduiChartsRequestPlaceholders = 1767900716005  # Bool = true
    FFlagSduiChartsResetSessionOnRefresh = 1767526009885  # Bool = false
    FFlagSduiChartsSortDetailGenreFilter = 1767526009245  # Bool = false
    FFlagSduiChartsSupport2 = 1768005262672  # Unknown = 
    FFlagSduiChipAccessoryProps = 1767470832336  # Unknown = 
    FFlagSduiClientPageScope2 = 1768005278800  # Unknown = 
    FFlagSduiClientTemplateCache = 1767470821789  # Bool = false
    FFlagSduiCoachmarkComponent = 1767654037469  # Bool = false
    FFlagSduiCollectionCarouselOverrides = 1767526011933  # Bool = false
    FFlagSduiCollectionCarouselPlaceholderItem = 1767526011485  # Bool = false
    FFlagSduiCollectionGridMaxNumRows = 1767583577629  # Bool = true
    FFlagSduiCommunitySectionSupport = 1767583572496  # Unknown = 
    FFlagSduiConfigFetchTakesPostBody = 1767470821533  # Bool = false
    FFlagSduiCreateSocialTelemetryRegistries = 1767654038365  # Bool = false
    FFlagSduiDataBindingShallowEquals = 1767643491088  # Unknown = 
    FFlagSduiDeferredListItems2 = 1767583577181  # Bool = true
    FFlagSduiDevStoreSeeAllImpressionsLogging = 1767526014813  # Bool = false
    FFlagSduiDevStoreSeeAllSupportDev2 = 1768458336656  # Unknown = 
    FFlagSduiDismissPromptAction = 1767470814301  # Bool = false
    FFlagSduiDividerThemeAwareStroke = 1767525999120  # Unknown = 
    FFlagSduiEdpClientTemplateCache = 1767470821917  # Bool = false
    FFlagSduiEdpInheritGameDetailSourceSession = 1767583576669  # Bool = true
    FFlagSduiEdpPageScopeIsTenFoot = 1767649978397  # Bool = false
    FFlagSduiEdpPersistentActionBarPlayButton = 1767900734077  # Bool = true
    FFlagSduiEdpPersistentActionBarPlayButton2 = 1767900720445  # Bool = true
    FFlagSduiEdpPrefetchPlayability = 1768458311184  # Unknown = 
    FFlagSduiEdpStoreImpressionsLogging = 1767526014365  # Bool = false
    FFlagSduiEnableAssociatedItemsRow = 1767526001693  # Bool = true
    FFlagSduiEnableBackToTop = 1767654036573  # Bool = false
    FFlagSduiEnableClearOnEmptyResponse = 1767643489296  # Unknown = 
    FFlagSduiEnableHeroUnitBottomRow = 1767648655504  # Unknown = 
    FFlagSduiErrorCleanup = 1767583577309  # Bool = true
    FFlagSduiEventDetailsSupport = 1767583577437  # Bool = true
    FFlagSduiEventRsvpFacePile = 1767583579677  # Bool = true
    FFlagSduiExperienceDetailsSocialProof = 1768038502928  # Unknown = 
    FFlagSduiExperienceDetailsSocialProof_3 = 1767470833680  # Unknown = 
    FFlagSduiExperienceDetailsSupport = 1768005288976  # Unknown = 
    FFlagSduiFavoritesHydrationStructured = 1768005300432  # Unknown = 
    FFlagSduiFeatureEntryPointTakesAbsoluteSizeHandler = 1767470795472  # Unknown = 
    FFlagSduiFeedDebugNameWithImpressionsTag = 1767654031760  # Unknown = 
    FFlagSduiFeedIndexInExtraLocalProps = 1767654033360  # Unknown = 
    FFlagSduiFixEmptyRobloxComponentInPropBuilder = 1767583578333  # Bool = true
    FFlagSduiFocusNavActionsStructured = 1767525981149  # Bool = false
    FFlagSduiFormatArgFormatters3 = 1767525975952  # Unknown = 
    FFlagSduiGameIconSupport = 1768005292816  # Unknown = 
    FFlagSduiGameItemsComponent = 1768458319120  # Unknown = 
    FFlagSduiGenericContainerDispatch = 1767470813789  # Bool = false
    FFlagSduiGetItemCollectionKeys = 1767526001501  # Bool = true
    FFlagSduiGlobalRegistryFallback = 1767470814045  # Bool = false
    FFlagSduiHydrationClientHints = 1767470795920  # Unknown = 
    FFlagSduiHydrationDataCamelCasePropertyKeys = 1767470796240  # Unknown = 
    FFlagSduiHydrationDataCamelCaseTopLevelKeys = 1767583579600  # Unknown = 
    FFlagSduiHydrationFetchIfMissing = 1768005274768  # Unknown = 
    FFlagSduiImprovedErrorDimensions = 1767525974480  # Unknown = 
    FFlagSduiInlineNestedComponentSchema2 = 1768005303056  # Unknown = 
    FFlagSduiInputDataMergeStrategy = 1768005252304  # Unknown = 
    FFlagSduiInputDataMergeStrategy2 = 1768005274896  # Unknown = 
    FFlagSduiIsEmptyConditions = 1768005264720  # Unknown = 
    FFlagSduiLaunchExperienceAction = 1768005265296  # Unknown = 
    FFlagSduiLazyNestedComponentArrayMapItemResolutionSupport = 1767583578013  # Bool = true
    FFlagSduiLazyNestedComponentProp = 1768005243408  # Unknown = 
    FFlagSduiLinkActionSharedWebLink = 1767583578128  # Unknown = 
    FFlagSduiMarketplaceCatalogActions4 = 1767525977309  # Bool = false
    FFlagSduiMarketplaceCatalogCategorySupport2 = 1767525976029  # Bool = false
    FFlagSduiMarketplaceCatalogSortSupport6 = 1767525976605  # Bool = false
    FFlagSduiNestedComponentListProp = 1767525974928  # Unknown = 
    FFlagSduiNilHydrationGuard = 1768005240400  # Unknown = 
    FFlagSduiOneofPropSupport = 1767525980957  # Bool = false
    FFlagSduiOpenIncomingTransferUpsellAction = 1767831054160  # Unknown = 
    FFlagSduiOpenSearchResultsTabAction = 1767525990941  # Bool = false
    FFlagSduiOptionImpressionsEventName = 1768215355664  # Unknown = 
    FFlagSduiOptionSelectorCollection = 1768215381712  # Unknown = 
    FFlagSduiOptionalUniverseHydration = 1768005253264  # Unknown = 
    FFlagSduiOrderedTemplateDataSupport = 1767583578781  # Bool = true
    FFlagSduiPageEntryPointResolvedSlot = 1768005245328  # Unknown = 
    FFlagSduiPageEntrySurfacing = 1768458314525  # Bool = true
    FFlagSduiPageEntryUseSharedHooks = 1767470799632  # Unknown = 
    FFlagSduiPaginatePostBody = 1767470822045  # Bool = false
    FFlagSduiPinShortcutAction = 1767831053968  # Unknown = 
    FFlagSduiPlayWithReward = 1767525974864  # Unknown = 
    FFlagSduiPlayWithRewardGapFix = 1767525978269  # Bool = false
    FFlagSduiPoolBackedFeed = 1768215379088  # Unknown = 
    FFlagSduiPromptImpressions = 1767525978397  # Bool = false
    FFlagSduiPropBuilderSupportNilHydration = 1767720497104  # Unknown = 
    FFlagSduiPropParsersShouldHandleTokens = 1767525975133  # Bool = false
    FFlagSduiProtobufJsonDecode = 1767525997981  # Bool = true
    FFlagSduiQueryImpressionsLogging = 1767900726765  # Bool = true
    FFlagSduiRegisterSocialActions = 1767525978525  # Bool = false
    FFlagSduiRenderPerf = 1767525974352  # Unknown = 
    FFlagSduiRequestFriendshipAction4 = 1767525992413  # Bool = true
    FFlagSduiRequestFriendshipActionHandler = 1767525993565  # Bool = false
    FFlagSduiRevealTextComponentEnabled = 1768458318800  # Unknown = 
    FFlagSduiScalePlayButtonAndImageSizes = 1767583579997  # Bool = true
    FFlagSduiSearchPeoplePlayerTileTelemetry = 1767900743837  # Bool = true
    FFlagSduiSearchResultsPageEnabled = 1768005285584  # Unknown = 
    FFlagSduiShimmerTextComponentEnabled = 1768458302672  # Unknown = 
    FFlagSduiShowToastAction_v2 = 1768458350621  # Bool = true
    FFlagSduiSocialDataMigrateOffLegacyPresence = 1767525991952  # Unknown = 
    FFlagSduiSrpScrollAway = 1767831060112  # Unknown = 
    FFlagSduiSrpShowNavOnNewSearch = 1767831059984  # Unknown = 
    FFlagSduiStickyHeaderDividerLayoutOrderConstant = 1767654035613  # Bool = false
    FFlagSduiStringPropToString = 1767470795792  # Unknown = 
    FFlagSduiSubscriptionCellPostPurchaseSync = 1767831073872  # Unknown = 
    FFlagSduiSupportRatingNoPercent = 1768458332432  # Unknown = 
    FFlagSduiSurfaceBannerAlwaysMounted = 1768458316368  # Unknown = 
    FFlagSduiSurfaceBannerScrollAwaySticky = 1768458317584  # Unknown = 
    FFlagSduiSystemBannerComponent = 1768458344976  # Unknown = 
    FFlagSduiTileBottomButton = 1768458295824  # Unknown = 
    FFlagSduiTileDisableLegacyHover = 1767648656080  # Unknown = 
    FFlagSduiTileHoldAction = 1768458298832  # Unknown = 
    FFlagSduiTileImagePaddingInset = 1768458321104  # Unknown = 
    FFlagSduiTileThumbnailPadding = 1768458291088  # Unknown = 
    FFlagSduiTileTitleTextAlignment = 1768005291152  # Unknown = 
    FFlagSduiTooltipComponentEnabled = 1768458291024  # Unknown = 
    FFlagSduiUniversalPageEntry = 1767583577885  # Bool = true
    FFlagSduiUnwrapStructPropEnvelope = 1767525975581  # Bool = false
    FFlagSduiUsageTelemetry = 1767583577053  # Bool = true
    FFlagSduiUseInputData = 1768005299920  # Unknown = 
    FFlagSduiUseSharedUiStatusHook = 1767470795600  # Unknown = 
    FFlagSduiVerticalFeedBottomSpacerLayoutOrderConstant = 1767654036829  # Bool = false
    FFlagSduiVerticalListWithImpressionsEnabled = 1767525987216  # Unknown = 
    FFlagSduiViewContainerRefEnabled = 1767525986704  # Unknown = 
    FFlagSeamlessVoiceConsentToastPolicy = 1767583397648  # Unknown = 
    FFlagSeamlessVoiceFTUXV2 = 1768133869840  # Unknown = 
    FFlagSeamlessVoiceV2JoinVoiceToast = 1768001209296  # Unknown = 
    FFlagSearchOmniAutocompletePageIXP5 = 1767526163549  # Bool = false
    FFlagSearchTopResultsTabEnabledForAll = 1768133868176  # Unknown = 
    FFlagSeedAccountThemeFromDisk = 1767831072912  # Unknown = 
    FFlagSelfViewCameraSettings = 1768458310544  # Unknown = 
    FFlagSelfViewNeckCheck = 1768133936016  # Unknown = 
    FFlagSelfViewNewPoseSynchronization = 1768133940880  # Unknown = 
    FFlagSelfViewNoApi = 1768399785040  # Unknown = 
    FFlagSelfViewVisibilityFix = 1768458301136  # Unknown = 
    FFlagSelfieFrontendConsoleDesktop3 = 1767831051408  # Unknown = 
    FFlagSendConsentDeniedOnCancel = 1767897054237  # Bool = false
    FFlagSendUserConnectionStatus = 1768001209936  # Unknown = 
    FFlagSendVoiceCapturedDuringVideoCaptureEvent = 1767645288272  # Unknown = 
    FFlagSentryIncludeRolloutFlagsContext = 1767900717181  # Bool = true
    FFlagServerTriggeredModalsAccepts2xxImpressionResponses = 1767650183440  # Unknown = 
    FFlagSessionL2ValidationCountResetFix = 1767725047008  # Unknown = 
    FFlagSetAliasFixFocusNavigation = 1767648630877  # Bool = false
    FFlagSetMenuOnPurchasePrompt = 1767897042717  # Bool = false
    FFlagSetMenuOnPurchasePrompt3 = 1767897042781  # Bool = false
    FFlagSetRSFNotSelectable = 1767723042384  # Unknown = 
    FFlagSetUpBubbleChatConfigurationChildProperties = 1768389353181  # Bool = false
    FFlagSettingsHubIndependentBackgroundVisibility = 1768133843152  # Unknown = 
    FFlagSettingsHubRaceConditionFix = 1767913319069  # Bool = false
    FFlagShareGameSearchBoxFocusAnalytics = 1767901847005  # Bool = false
    FFlagShareGetPlatformTargetImpl = 1768458304528  # Unknown = 
    FFlagShareSheetTelemetryRefactor = 1775910039376  # Unknown = 
    FFlagShareSheetTelemetryRefactor_Dev2 = 1775910057040  # Unknown = 
    FFlagShareTargetGameCleanup = 1768010013392  # Unknown = 
    FFlagShipUnifiedPurchaseFlowToPaidAccess = 1767831085712  # Unknown = 
    FFlagShipUnifiedPurchaseInExperience = 1767831085328  # Unknown = 
    FFlagShopProductsUseDisplayName = 1768181197264  # Unknown = 
    FFlagShortcutBarMinSize = 1768017040784  # Unknown = 
    FFlagShortcutUseDispatchSyntheticEvent = 1768017089104  # Unknown = 
    FFlagShouldApplyDevSubsUpsellFix = 1768125826269  # Bool = false
    FFlagShouldFixDevSubsFlashingTitle = 1768125826909  # Bool = false
    FFlagShouldMuteUnlocalizedError = 1768024096400  # Unknown = 
    FFlagShowAccountUnlockMismatchDialog = 1767583575069  # Bool = true
    FFlagShowAntiHarassmentSettings = 1767913337501  # Bool = false
    FFlagShowConfirmationScreenForOOAP2 = 1767526164893  # Bool = false
    FFlagShowContextMenuWhenButtonsArePresent = 1775992617488  # Unknown = 
    FFlagShowCreatorNameOnEmphasisSearchTileIXP2 = 1767648657117  # Bool = false
    FFlagShowDOTADogfoodSiteMessage = 1767650227280  # Unknown = 
    FFlagShowDevicePermissionsModal3 = 1767526164445  # Bool = false
    FFlagShowFAELoadingModalForWebView = 1767648603805  # Bool = false
    FFlagShowGameAgeRating = 1767831083600  # Unknown = 
    FFlagShowInvoluntarilySignedOutAccounts = 1767526155280  # Unknown = 
    FFlagShowJoinVoiceRaceConditionFix = 1767972941512  # Unknown = 
    FFlagShowJoinVoiceWhenDisconnectedV3 = 1768001215709  # Bool = false
    FFlagShowScreentimeLockoutKickMessage = 1768024097053  # Bool = false
    FFlagShowStartupMessageOnUnhide = 1767640173085  # Bool = false
    FFlagShowSwitchServerButton = 1768389376400  # Unknown = 
    FFlagShowSwitchServerButton2 = 1768389363984  # Unknown = 
    FFlagShowTeleportHistoryFrontButton = 1768126102749  # Bool = false
    FFlagShowUnibarOnVirtualCursor = 1767828571856  # Unknown = 
    FFlagShrinkAppNavBar = 1767828556880  # Unknown = 
    FFlagSideSheetAndroidBack = 1768132566493  # Bool = false
    FFlagSideSheetFocusNav_DEV = 1767828555728  # Unknown = 
    FFlagSignUpBirthdayPickerRemoveBottomBarOffset = 1767828562576  # Unknown = 
    FFlagSignUpBirthdayPickerRequireManualSelection = 1767828606992  # Unknown = 
    FFlagSignUpBirthdayPickerShowAgeCalculator = 1767828562384  # Unknown = 
    FFlagSignUpBirthdayRefactorNestedDefinition = 1767828614672  # Unknown = 
    FFlagSignUpTrackFailedRequest = 1767720543696  # Unknown = 
    FFlagSignalsNavP2NavigationPrimitives5 = 1767470816797  # Bool = false
    FFlagSignalsNavP3Dispatch5 = 1767470817885  # Bool = false
    FFlagSignalsNavP3Final = 1767470818013  # Bool = false
    FFlagSignalsNavP3aWrapAppPage2 = 1768010020757  # Bool = false
    FFlagSignalsNavP3bTopBar4 = 1767470817309  # Bool = false
    FFlagSignalsNavP3cEvents4 = 1767470816720  # Unknown = 
    FFlagSignalsNavP3dRouteGated2 = 1767470816592  # Unknown = 
    FFlagSignalsNavP3eAuth3 = 1767470816016  # Unknown = 
    FFlagSignalsNavP3fGameDetails3 = 1767470816144  # Unknown = 
    FFlagSignalsNavP3gAvatarExperience4 = 1767470814992  # Unknown = 
    FFlagSignalsNavP3hMisc3 = 1767470814416  # Unknown = 
    FFlagSignalsNavProjected2 = 1767470818141  # Bool = false
    FFlagSignalsReactUseMutableSource = 1767473170320  # Unknown = 
    FFlagSignupDisplayNameLogging = 1767650184144  # Unknown = 
    FFlagSignupLogoAspectRatioFix = 1767424221981  # Bool = false
    FFlagSignupTrackFailedRequestv1 = 1767720512720  # Unknown = 
    FFlagSilentUpgradeOnSignupIXPBypass = 1767650169616  # Unknown = 
    FFlagSilentlyFailIfChallenge = 1767650177552  # Unknown = 
    FFlagSingleUploadMakeupSupport4 = 1767897053072  # Unknown = 
    FFlagSingleUserInvitePageKeybind = 1767901856029  # Bool = false
    FFlagSkipBlockModal = 1767583390032  # Unknown = 
    FFlagSkipBuyDelayForExperienceShop = 1767828606224  # Unknown = 
    FFlagSkipCompletionModalForMarketplace = 1767828573840  # Unknown = 
    FFlagSkipCompletionModalForMarketplace3 = 1767828565328  # Unknown = 
    FFlagSlimDevConsole2 = 1768132568861  # Bool = false
    FFlagSlimTintContextFilter = 1768132571536  # Unknown = 
    FFlagSnoozeMenuTextXAlignment = 1768017035792  # Unknown = 
    FFlagSocialBlockingModalFocusNavSupport = 1775962098029  # Bool = true
    FFlagSocialCarouselEnableNewFriendRequestsBadgeForAll = 1767641312285  # Bool = false
    FFlagSocialCarouselEnableUserSeenEvents = 1768310637712  # Unknown = 
    FFlagSocialCarouselEnableUserSeenEvents2 = 1767641307741  # Bool = false
    FFlagSocialCarouselFixColdStartJitter = 1767641312605  # Bool = false
    FFlagSocialCarouselFixConsoleCtaForInGame = 1767641307472  # Unknown = 
    FFlagSocialCarouselFixGameJoinCardDismiss = 1767641309725  # Bool = false
    FFlagSocialCarouselFixLoadingSkeletonSizing = 1767641313181  # Bool = false
    FFlagSocialCarouselMigrateRecommendations = 1768133847888  # Unknown = 
    FFlagSocialCarouselPressXToViewProfile = 1768133849744  # Unknown = 
    FFlagSocialCarouselShareQRBackToAddFriends = 1767831068176  # Unknown = 
    FFlagSocialCarouselShareQRBackToAddFriends_v2 = 1767831066704  # Unknown = 
    FFlagSocialCarouselShareQREnabled = 1767831068560  # Unknown = 
    FFlagSocialCarouselShareQREnabled_v5 = 1767831068496  # Unknown = 
    FFlagSocialCarouselShowLoadingSkeleton = 1767641308573  # Bool = false
    FFlagSocialCarouselUpdateVerticalSpacing = 1767641302288  # Unknown = 
    FFlagSocialCarouselUseConsolePolicyForCta = 1767641303376  # Unknown = 
    FFlagSocialCarouselUseProfileStore_v2 = 1768133873168  # Unknown = 
    FFlagSocialContextToastEventStream3 = 1768164779336  # Unknown = 
    FFlagSocialEnableProfileInspectAndBuy = 1768165597072  # Unknown = 
    FFlagSocialEnableProfileInspectAndBuyAnalytics = 1767583434128  # Unknown = 
    FFlagSocialEnableProfileInspectAndBuyAnalyticsV2 = 1767827661749  # Bool = false
    FFlagSocialEnableProfileInspectAndBuyAnalyticsV3 = 1768317822800  # Unknown = 
    FFlagSocialEnableProfileInspectAndBuyConsoleFocusNav = 1767583434653  # Bool = false
    FFlagSocialEnableProfileInspectAndBuy_8 = 1767583433565  # Bool = false
    FFlagSocialExperienceJoinPresenceStoreMigration = 1767911121373  # Bool = false
    FFlagSocialExperienceJoinPresenceStoreMigration_v1 = 1768024562973  # Bool = false
    FFlagSocialJoinPassPlaceIdToLaunch = 1768024545885  # Bool = false
    FFlagSocialJoinUseUnifiedPurchaseFlow = 1768024540637  # Bool = false
    FFlagSocialLibrariesSelectableAlertViewShim = 1768297271517  # Bool = false
    FFlagSocialLuaAnalyticsUseTelemetryServiceAsDefault = 1768393289808  # Unknown = 
    FFlagSocialMetadataSectionMigrateUserProfileToSignals = 1768494419168  # Unknown = 
    FFlagSocialNetworksInEditProfileIXPEnabled = 1767654045853  # Bool = false
    FFlagSocialNetworksInEditProfileIXPSetupEnabled_v6 = 1767654045405  # Bool = false
    FFlagSocialTabReplaceRefreshConversations = 1767583403152  # Unknown = 
    FFlagSocialTabsPagePresenceSignalsMigration = 1767648654045  # Bool = false
    FFlagSongCarouselPropUpdate = 1767526107216  # Unknown = 
    FFlagSongDetailsPageDesignPass3 = 1767828582288  # Unknown = 
    FFlagSongEdpCarouselIxp = 1768374782224  # Unknown = 
    FFlagSongEdpCarouselIxp2 = 1767424251600  # Unknown = 
    FFlagSongbirdMusicIconThumbnail = 1776050373776  # Unknown = 
    FFlagSongbirdPopoverSubmenu2 = 1767470903541  # Bool = false
    FFlagSoothsayerCheckForContactImporterV1 = 1768458316061  # Bool = false
    FFlagSortInvitesByScoreEnabledForAll = 1768150386448  # Unknown = 
    FFlagSpatialUIDisableBottomBarFading = 1767913323600  # Unknown = 
    FFlagSpatialUIDisableBottomBarInteractionOnAnimating = 1767913317904  # Unknown = 
    FFlagSpatialUIEnableDrag8 = 1767978518672  # Unknown = 
    FFlagSpatialUIEnableMovePanelToCenter8 = 1767978514896  # Unknown = 
    FFlagSpatialUIEnablePanelsRefocusing = 1767913322640  # Unknown = 
    FFlagSpatialUIFixGameInviteChatExclusive = 1767913327197  # Bool = false
    FFlagSpatialUIFixMenuPanelChatExclusive = 1768132564957  # Bool = false
    FFlagSquadAppChatRTNFixWithSquadMainFlag = 1767583400208  # Unknown = 
    FFlagSquadEnabled = 1767583399248  # Unknown = 
    FFlagSquadExperienceInviteRetryAfter = 1768024077213  # Bool = false
    FFlagSquadLaunchExperienceMobileFix = 1767526164368  # Unknown = 
    FFlagSquadsPresenceStoreMigration = 1768024063389  # Bool = false
    FFlagSquadsUseProfileFrameThumbnail = 1768181188624  # Unknown = 
    FFlagStackedBottomNavMarketplaceCTA = 1767831064976  # Unknown = 
    FFlagStandardizeSafetyIcon = 1767526151069  # Bool = false
    FFlagStopBubbleChatReactWarning = 1768399771472  # Unknown = 
    FFlagStopModerationConnectionOnLeave = 1767645296541  # Bool = false
    FFlagStopStreamTrackOnDeath = 1767665953901  # Bool = true
    FFlagStreamNotificationBellEntryPoint = 1767900768317  # Bool = true
    FFlagStreamNotificationDropdownFocusedOwner = 1767583542301  # Bool = true
    FFlagStreamNotificationDropdownSingleOwner = 1767583541725  # Bool = true
    FFlagStreamNotificationImpressionLogging = 1767900720797  # Bool = true
    FFlagStreamNotificationUXDropdown2 = 1767583540701  # Bool = true
    FFlagStreamNotificationUXSettingsHeader = 1767583541149  # Bool = true
    FFlagStreamNotificationsStandardizeClickEvents = 1767583540253  # Bool = true
    FFlagStreamingPauseUIAnalyticsEnabled = 1767899821341  # Bool = false
    FFlagStringKeyFixForParticipantsTable = 1767645290000  # Unknown = 
    FFlagSubTabAddDesktopTopMargin = 1767828586768  # Unknown = 
    FFlagSubTabAddMomentsFlagGating = 1767828556240  # Unknown = 
    FFlagSubTabFixMissingProfileWidget = 1767828608528  # Unknown = 
    FFlagSubTabNavigationTTITracking = 1767828590736  # Unknown = 
    FFlagSubTabRemoveFlyoutDependency = 1767828587664  # Unknown = 
    FFlagSubscriptionPurchaseModalLiveStatus = 1767831076560  # Unknown = 
    FFlagSubscriptionUpsellCounterWithErrorReasonV2 = 1774951063528  # Unknown = 
    FFlagSuggestedCalleeBugFixEnabledV2 = 1768001935317  # Bool = false
    FFlagSupportFreeTrial = 1767643504093  # Bool = false
    FFlagSupportFreeTrialPriceRow = 1767643494416  # Unknown = 
    FFlagSupportGamepadNavInVoiceModals = 1767900718389  # Bool = true
    FFlagSupportNewBadgeRobloxPlus = 1767643493149  # Bool = false
    FFlagSupportSubmissionOnAllReportNodes = 1767583568208  # Unknown = 
    FFlagSupportTerminalMilestoneInReactProfilerLogger = 1768017187280  # Unknown = 
    FFlagSupportViewingUserProfileOnOSA = 1768028301405  # Bool = true
    FFlagSupportViewingUserProfileOnOSA1 = 1767641272733  # Bool = false
    FFlagSurvBloxAddSurveyLinkParamsEnabled = 1767650166416  # Unknown = 
    FFlagSurvBloxEnabled = 1767650167568  # Unknown = 
    FFlagSurvBloxEventTypeEnabled = 1768372166672  # Unknown = 
    FFlagSurvBloxEventTypeEnabled2 = 1767583575453  # Bool = true
    FFlagSurvBloxLocalStorageEnabled = 1767650166288  # Unknown = 
    FFlagSurvBloxTrackingFixes = 1767650165456  # Unknown = 
    FFlagSwitchCSRootProviderTranslationsPackage = 1768389387344  # Unknown = 
    FFlagSwitchOverToAbuseReportMenuV2 = 1768317792208  # Unknown = 
    FFlagSwitchProfileWidthHookToSocialCommon = 1768133885264  # Unknown = 
    FFlagSwitchProfileWidthHookToSocialCommon_v2 = 1768133883984  # Unknown = 
    FFlagSwitchTnSTranslationsPackage = 1775992625744  # Unknown = 
    FFlagSystemTrayDeviceSettings2 = 1768010001245  # Bool = false
    FFlagTCEducationModalSideBarPolicy = 1767654046224  # Unknown = 
    FFlagTCModalUseFoundationOverlay = 1768009972496  # Unknown = 
    FFlagTCParentChildAutoUpgrade = 1768010006352  # Unknown = 
    FFlagTCParentChildAutoUpgrade2 = 1768009993424  # Unknown = 
    FFlagTCPolicyCheckRedirect = 1767583528413  # Bool = true
    FFlagTCShareLinkErrorModal = 1768010013328  # Unknown = 
    FFlagTCShareLinkErrorModalTextRename = 1768009959248  # Unknown = 
    FFlagTCShareLinkReceiverUI4 = 1768010017872  # Unknown = 
    FFlagTCStreamNotifEventReceiver = 1767583395280  # Unknown = 
    FFlagTCUpdateProfileCTAButton = 1768010000912  # Unknown = 
    FFlagTFPassQRCodeSource = 1768494423440  # Unknown = 
    FFlagTFProfileInsightsBypassCache = 1768009999056  # Unknown = 
    FFlagTFWithActionsCheck = 1768009996752  # Unknown = 
    FFlagTFWithActionsCheck_4 = 1768009990928  # Unknown = 
    FFlagTTITrackerMemoryTracking = 1768492009568  # Unknown = 
    FFlagTTITrackerMemoryTracking3 = 1767638308573  # Bool = false
    FFlagTakeAScreenshotOfThis = 1775992598608  # Unknown = 
    FFlagTalkingChangedWithDebounceV2 = 1767645286800  # Unknown = 
    FFlagTempFixInfiniteHomePYMK = 1767643524048  # Unknown = 
    FFlagTemporaryAvatarKickWarningDialog = 1768132411869  # Bool = false
    FFlagTenFootUiCorrectAutoFocusLoggingBehavior = 1767640172125  # Bool = false
    FFlagTenFootUiGlobalNavFixOptionText = 1767473201040  # Unknown = 
    FFlagTenFootUiSupportSortHeaderTooltip2 = 1768001958589  # Bool = true
    FFlagTenFootUiSupportSortSubtitle2 = 1767526149341  # Bool = false
    FFlagTestDeviceForFAEUpsell = 1767645312221  # Bool = false
    FFlagTextChannelWindowPerfTrackingEnabled = 1767860852061  # Bool = false
    FFlagTextChatEnableUniverseChatTabs11 = 1767900760029  # Bool = true
    FFlagTextFilterEducationNudgeEnabled = 1767723050781  # Bool = false
    FFlagTiltLoadingScreenConsoleHints = 1767831052816  # Unknown = 
    FFlagTiltLoadingScreenEnterExitHold = 1767831055184  # Unknown = 
    FFlagTiltLoadingScreenEnterExitHold2 = 1767831055568  # Unknown = 
    FFlagTimeToInteractiveTrackerWarningsRequireDebug = 1767638309200  # Unknown = 
    FFlagTimeoutRemoteEvent = 1768213807421  # Bool = false
    FFlagTokenizeUnibarConstantsWithStyleProvider = 1768049873096  # Unknown = 
    FFlagTopBarDeprecateChatRodux = 1775910057365  # Bool = false
    FFlagTopBarDeprecateChatRodux2 = 1768136665501  # Bool = false
    FFlagTopBarDeprecateCoreGuiRodux = 1767913671445  # Bool = false
    FFlagTopBarDeprecateCoreGuiRodux2 = 1775992614288  # Unknown = 
    FFlagTopBarDeprecateDisplayOptionsRodux = 1775910050901  # Bool = false
    FFlagTopBarDeprecateDisplayOptionsRodux2 = 1768136666269  # Bool = false
    FFlagTopBarDeprecateGameInfoRodux = 1768136664541  # Bool = false
    FFlagTopBarDeprecateGamepadNavigationDialogRodux = 1768136665053  # Bool = false
    FFlagTopBarDeprecateMoreMenuRodux = 1767913671573  # Bool = false
    FFlagTopBarDeprecateRespawnRodux = 1767913671701  # Bool = false
    FFlagTopBarDeprecateRespawnRodux2 = 1775992572368  # Unknown = 
    FFlagTopBarRefactor2 = 1767989398877  # Bool = false
    FFlagTopBarSignalizeHealthBar4 = 1767989411421  # Bool = false
    FFlagTopBarSignalizeKeepOutAreas5 = 1767989384989  # Bool = false
    FFlagTopBarSignalizeMenuOpen = 1767989387805  # Bool = false
    FFlagTopBarSignalizeScreenSize2 = 1767989429277  # Bool = false
    FFlagTopBarSignalizeSetCores = 1767989420560  # Unknown = 
    FFlagTouchHelpPageResponsiveUnits = 1768428787664  # Unknown = 
    FFlagTrackerPromptNewCopyForCameraPerformanceEnabled = 1767899845968  # Unknown = 
    FFlagTranslateDevProducts = 1776067288272  # Unknown = 
    FFlagTraversalExpPagePaddingFixes709 = 1768389346384  # Unknown = 
    FFlagTraversalHistoryDiscoveryTelemetry = 1767526026640  # Unknown = 
    FFlagTraversalUseDiscoveryCollectionViews = 1768428792272  # Unknown = 
    FFlagTraversalUseXSmallCollectionItems = 1768428779984  # Unknown = 
    FFlagTriggerLogoutOnAuthErrorCode = 1768027277456  # Unknown = 
    FFlagTrimLongTitleForTOSEnabled = 1767473190928  # Unknown = 
    FFlagTruncateDeviceSelection = 1775992625168  # Unknown = 
    FFlagTrustedFriendsUseEnumCTA = 1768009993488  # Unknown = 
    FFlagTrustedFriendsUseEnumCTA_2 = 1768009991120  # Unknown = 
    FFlagTrustedFriendsUseFoundationSheet = 1768009958736  # Unknown = 
    FFlagTutorialUpsellEnabled = 1767720485648  # Unknown = 
    FFlagTutorialUpsellOverrideIXPEnabled = 1767650172176  # Unknown = 
    FFlagUFRImprovements = 1767998337109  # Bool = true
    FFlagUFRImprovements3 = 1767998339477  # Bool = true
    FFlagUFRInlineAppealLink = 1768050277136  # Unknown = 
    FFlagUIBloxAddFoundationNavigationTabIcon = 1767470826397  # Bool = false
    FFlagUIBloxAddTestIdToActionBar = 1767470822160  # Unknown = 
    FFlagUIBloxAppShortcutBarUseTokens = 1767470824400  # Unknown = 
    FFlagUIBloxDeprecateComponentGlobalSemanticTokenUse = 1767470826909  # Bool = false
    FFlagUIBloxDidMountUpdateFullPageModal = 1767470824925  # Bool = false
    FFlagUIBloxDisableTokenScaling = 1767470822288  # Unknown = 
    FFlagUIBloxEnableActionBarButtonOverride = 1767470823120  # Unknown = 
    FFlagUIBloxEnableTooltipV2BodyFontFix = 1767900758077  # Bool = true
    FFlagUIBloxEnableTooltipV2HoverControllerReRenderFix = 1767470824477  # Bool = false
    FFlagUIBloxFixCoplayFooterConditionalHooks = 1768211877597  # Bool = true
    FFlagUIBloxRemoveStackedNavigationTabIconLabelSpacing = 1767470817680  # Unknown = 
    FFlagUIBloxToastFoundationButtonSizing = 1767470825821  # Bool = false
    FFlagUIBloxUseEngineRichTextBounds = 1767470824720  # Unknown = 
    FFlagUIBloxUseFoundationButton5 = 1767470825309  # Bool = false
    FFlagUIBloxUseFoundationButtonInGame2 = 1767620282717  # Bool = true
    FFlagUIBloxUseFoundationSkeleton = 1767473743680  # Unknown = 
    FFlagUIBloxUseGridInfoForTile = 1767583808477  # Bool = false
    FFlagUIBloxUseNewZindex = 1767583808349  # Bool = false
    FFlagUXForCameraPerformanceEnabled = 1767899843472  # Unknown = 
    FFlagUXForCameraPerformanceIXPEnabled = 1767831047632  # Unknown = 
    FFlagUnibarLuaOcclusionMetrics = 1767828609232  # Unknown = 
    FFlagUnibarMenuOpenHamburger = 1767913625941  # Bool = false
    FFlagUnibarMenuOpenHamburgerGamepadIXP = 1767828575632  # Unknown = 
    FFlagUnibarMenuOpenHamburgerGamepadIXP684 = 1767828614032  # Unknown = 
    FFlagUnibarMenuOpenSelectionIXP = 1767828556432  # Unknown = 
    FFlagUnibarMenuOpenSelectionIXP2 = 1767828573392  # Unknown = 
    FFlagUnibarMenuOpenSubmenu = 1767913626005  # Bool = false
    FFlagUnifiedPurchaseAddSkeleton = 1767828559504  # Unknown = 
    FFlagUnifiedPurchaseFlowMarketplaceUIImprovements = 1767828610896  # Unknown = 
    FFlagUnifiedPurchaseFlowMarketplaceUIImprovementsV4 = 1767828606672  # Unknown = 
    FFlagUnifiedPurchaseGamepassAddProductUniverseId = 1767828585360  # Unknown = 
    FFlagUnifiedPurchaseOptimizeTTIMarketplace = 1767831083088  # Unknown = 
    FFlagUnifiedPurchaseOptimizeTTIMarketplaceIntegration = 1767977082704  # Unknown = 
    FFlagUnifiedPurchasePassInProductInfoEDP = 1767831090704  # Unknown = 
    FFlagUnifiedPurchasePassInProductInfoEDP2 = 1767831093264  # Unknown = 
    FFlagUnifiedPurchaseSupportRefetchingLooksAfterUpsell = 1767828555280  # Unknown = 
    FFlagUnifyConsoleSettingsPage5 = 1767831053648  # Unknown = 
    FFlagUnifyVerifiedBadgeComponent = 1767470826128  # Unknown = 
    FFlagUniversalAppCameraEnabled5 = 1767654050845  # Bool = false
    FFlagUniversalAppCameraEnabledForAll4 = 1767654051165  # Bool = false
    FFlagUniversalFeatureRestrictionReceivers = 1768372171664  # Unknown = 
    FFlagUniversalFeatureRestrictionReceivers10 = 1767583572701  # Bool = true
    FFlagUnreduxLastInputTypeChanged = 1767989398224  # Unknown = 
    FFlagUpdateDeviceInputPlayerChanged = 1767645290077  # Bool = false
    FFlagUpdateDiscoveryEventErrorDetailsLogging = 1767977192989  # Bool = false
    FFlagUpdateDividerStartBounds = 1767723041680  # Unknown = 
    FFlagUpdateInGameAssetReportingCTAs = 1767583566736  # Unknown = 
    FFlagUpdateInvitesToUsePaginatedFriends = 1768132386896  # Unknown = 
    FFlagUpdateNoInternetConnectionText = 1767424243549  # Bool = false
    FFlagUpdatePeopleNamesSettingCopy = 1767913337941  # Bool = false
    FFlagUpdateRephraseSettingUI = 1767913338768  # Unknown = 
    FFlagUpdateSocialCarouselAddFriendsIcon = 1767628643709  # Bool = false
    FFlagUpdateSongCarouselClipDefault = 1767526106576  # Unknown = 
    FFlagUpdateTranslateInReportRevamp = 1767583572253  # Bool = true
    FFlagUpdateUnifiedPurchasePriceTelemetry = 1767828554320  # Unknown = 
    FFlagUpdateVisibilitySettingsCopy = 1767913347088  # Unknown = 
    FFlagUpdateVoiceConnectionToasts_AEGIS2 = 1768001198480  # Unknown = 
    FFlagUpdatedTrimMemoryLevelPropagation = 1767423541405  # Bool = true
    FFlagUploadMakeupSupport = 1767897058333  # Bool = false
    FFlagUseAccountPickerAmpEligibility = 1767828554064  # Unknown = 
    FFlagUseAnimateScrollViewToSelectionHelper = 1767828610384  # Unknown = 
    FFlagUseAudioAnalyzerForLocalMetering2 = 1767645295965  # Bool = false
    FFlagUseBindingForUnreadChat = 1767628631869  # Bool = false
    FFlagUseCameraDevicesListener = 1767913332509  # Bool = false
    FFlagUseCaptureCommonComponents = 1776085375632  # Unknown = 
    FFlagUseCharacterStore2 = 1767641268752  # Unknown = 
    FFlagUseCommunitiesTranslation = 1768458321232  # Unknown = 
    FFlagUseCoreScriptsRootProviderForUpsellModal = 1767897043421  # Bool = false
    FFlagUseDefaultOverrideColorsFor10ftModels = 1767831070032  # Unknown = 
    FFlagUseEnablePremiumUserFeaturesAppPolicy = 1768458313040  # Unknown = 
    FFlagUseExternalBrowserForAgeGuidelines10ft = 1768027306064  # Unknown = 
    FFlagUseExtraATCProperties = 1767462806544  # Unknown = 
    FFlagUseFriendsListOrderedByIdPresenceImpressionEventsEnabled = 1768024567965  # Bool = false
    FFlagUseIsAvailableCheckForIOSKeychainFetch = 1767720547600  # Unknown = 
    FFlagUseLocalTraversalHistory699v1 = 1768389405520  # Unknown = 
    FFlagUseMediaPlayerInCarousel = 1768133873424  # Unknown = 
    FFlagUseMediaPlayerInCarousel_v2 = 1768133864080  # Unknown = 
    FFlagUseNavigationSelectors = 1767831085456  # Unknown = 
    FFlagUseNewDiscoverabilityModal = 1767462036269  # Bool = false
    FFlagUseNewDiscoverabilityModal_v2 = 1768009974160  # Unknown = 
    FFlagUseNewHurtOverlayAnimation = 1767989389661  # Bool = false
    FFlagUseNewHurtOverlayImage = 1767989407773  # Bool = false
    FFlagUseNewPlayerList3 = 1767628634749  # Bool = false
    FFlagUseNotificationServiceIsConnected = 1767899837776  # Unknown = 
    FFlagUseObservableDefaultForChromeFocused = 1768133950224  # Unknown = 
    FFlagUseOmniFeedDividerOverrides = 1768458349712  # Unknown = 
    FFlagUseOriginalPlatformChatPolicy = 1768297325469  # Bool = true
    FFlagUsePlaceInfoController2 = 1767640196893  # Bool = false
    FFlagUsePlatformNameForUnknown = 1776067342352  # Unknown = 
    FFlagUsePlaystationPaymentsProtocolCommonFunctions = 1768125838429  # Bool = false
    FFlagUsePresenceDataFromRtn = 1767625377629  # Bool = false
    FFlagUseRbxStorageInCapturesCommon = 1767988669229  # Bool = false
    FFlagUseRbxstorageInGallery = 1767797191704  # Unknown = 
    FFlagUseRoactGlobalConfigInCoreScripts = 1767913639317  # Bool = false
    FFlagUseSessionServiceWrapper = 1767650180688  # Unknown = 
    FFlagUseSessionServiceWrapperModule = 1767650175440  # Unknown = 
    FFlagUseSharedLoadingScreenView = 1768060656477  # Bool = false
    FFlagUseSignalsForAccountSecurityPrompt = 1768005247760  # Unknown = 
    FFlagUseSignalsForAppTopBanner = 1768005304208  # Unknown = 
    FFlagUseSignalsForAuthenticationStatus7 = 1768005245584  # Unknown = 
    FFlagUseSignalsForCountryCode = 1768005264528  # Unknown = 
    FFlagUseSignalsForCountryCodeList = 1767470811280  # Unknown = 
    FFlagUseSignalsForGameInvitesStatus = 1768005247184  # Unknown = 
    FFlagUseSignalsForGlobalContextMenuInset1 = 1768005289360  # Unknown = 
    FFlagUseSignalsForIsLocalUserSoothsayer = 1767470815568  # Unknown = 
    FFlagUseSignalsForIsLocalUserUnder13 = 1768005292432  # Unknown = 
    FFlagUseSignalsForModeration = 1767470817757  # Bool = false
    FFlagUseSignalsForPlatform = 1768005262224  # Unknown = 
    FFlagUseSignalsForScreenGuiBlur = 1768005254032  # Unknown = 
    FFlagUseSignalsForSearchBar = 1768005267088  # Unknown = 
    FFlagUseSignalsForSiteMessage = 1768005265744  # Unknown = 
    FFlagUseSignalsForSquadExperienceInviteStatus = 1767583397008  # Unknown = 
    FFlagUseSignalsForStartup = 1768005239056  # Unknown = 
    FFlagUseSignalsNavigation2 = 1767470815901  # Bool = false
    FFlagUseSignalsRoduxStore3 = 1767470818269  # Bool = false
    FFlagUseTeleportTraversalHistory699v1 = 1768389352912  # Unknown = 
    FFlagUseUniverseVotesController = 1767640197021  # Bool = false
    FFlagUseUpdatedBackgroundSceneSettingsOnMobile1 = 1767650018576  # Unknown = 
    FFlagUseUpdatedVNGAgreementsWorkflow = 1767526147664  # Unknown = 
    FFlagUseV2LivePreviewWatermark = 1768060678045  # Bool = false
    FFlagUseVRSpecificLeaveButton = 1775992574480  # Unknown = 
    FFlagUseVoiceExitBetaLanguageV2 = 1768458299856  # Unknown = 
    FFlagUserBlockingApiPlayerContextMenuEnabled = 1767473194832  # Unknown = 
    FFlagUserInfoWidgetUseProfileFrameThumbnail = 1767650179037  # Bool = true
    FFlagUserListCtaAnalyticsEnabled = 1768133847517  # Bool = false
    FFlagUserListCtaIntegrationEnabled = 1768133881181  # Bool = true
    FFlagUserListCtaIntegrationEnabled_v2 = 1768133827408  # Unknown = 
    FFlagUserListFooterViewMore = 1768009988496  # Unknown = 
    FFlagUserListPresenceStoreMigration = 1768024101661  # Bool = false
    FFlagUserListPresenceStoreMigration_v2 = 1768024065885  # Bool = false
    FFlagUserListTightHeaderSpacing = 1768024520797  # Bool = false
    FFlagUserListUseActionAddTranslation = 1768024510237  # Bool = false
    FFlagUserListUseSheet = 1768133862032  # Unknown = 
    FFlagUserListUsernameFallbackConfig = 1768133843024  # Unknown = 
    FFlagUserPresenceTokenRccCheckPermissionsLua = 1767913622165  # Bool = false
    FFlagUserProfileBetterErrors = 1768150336272  # Unknown = 
    FFlagUserProfileConsoleUseNewReportFlow = 1767473194205  # Bool = false
    FFlagUserProfileStoreDataFetchFix = 1768024049309  # Bool = false
    FFlagUserProfileStoreQueryRefetch = 1768133825808  # Unknown = 
    FFlagUserProfileTurnCacheBackOn = 1767420608349  # Bool = false
    FFlagUserProfilesDataLoaderEnabled = 1768458337040  # Unknown = 
    FFlagUserProfilesEnableRetries = 1768001221149  # Bool = false
    FFlagUserProfilesFilterInvalidUserIds = 1768001194013  # Bool = false
    FFlagUserProfilesLogCancelledRequests = 1768001181277  # Bool = false
    FFlagUserProfilesLogErrorCodes = 1767803460053  # Bool = true
    FFlagUserProfilesUseIsRobloxSubscriberGetter = 1768001192029  # Bool = false
    FFlagUserSearchAddFocusActionsSupport_1 = 1767583386448  # Unknown = 
    FFlagUserSearchEmptyPageNewIcons = 1768009958480  # Unknown = 
    FFlagUserSearchGoBackOnCancel = 1768009973328  # Unknown = 
    FFlagUserSearchPresenceStoreMigration_v2 = 1767648645776  # Unknown = 
    FFlagUserSearchUseProfileFrameThumbnail = 1767648649885  # Bool = false
    FFlagUserSearchUseThisIsYou = 1767583385680  # Unknown = 
    FFlagUserTM2Experiment = 1767628651229  # Bool = false
    FFlagUserTileAddContextualInfoIcon = 1767583524765  # Bool = true
    FFlagUserTileAddDataHydrationWrapper = 1768024082461  # Bool = false
    FFlagUserTileIncludeProfileFrameProp = 1768024506909  # Bool = false
    FFlagUserTileRemoveContextualInfoTag = 1768024570397  # Bool = false
    FFlagUserTileShowBadges = 1767583524573  # Bool = true
    FFlagUserTileShowShimmerWhenLoading = 1768024530333  # Bool = false
    FFlagUserTileShowShimmerWhenLoading_v2 = 1768024527325  # Bool = false
    FFlagUserTileTextTCIndicator_V3 = 1767583524445  # Bool = true
    FFlagUserTileTitleStackAddExtraInfo_DEV = 1767583525213  # Bool = true
    FFlagUserTileUnfilteredChatIndicator = 1767583525661  # Bool = true
    FFlagUserTileUseProfileFrameThumbnail = 1768024547037  # Bool = false
    FFlagUsesCancelSearchAppPolicy = 1768399775376  # Unknown = 
    FFlagVCWasDisabledFromMenuOpen = 1768458299792  # Unknown = 
    FFlagVRAbuseReportLocales = 1767583542160  # Unknown = 
    FFlagVRBottomBarDebugPositionConfig = 1767913639445  # Bool = false
    FFlagVRLaserPointerRaycastChange = 1768428736144  # Unknown = 
    FFlagVRPanelWidthIXPEnabledV5 = 1767828593488  # Unknown = 
    FFlagVRPanelWidthIXPLocalOverrideEnabled = 1768027291152  # Unknown = 
    FFlagVRSpatialUIGuardNilHeadScale = 1767913324893  # Bool = false
    FFlagValidateDescription = 1767897052189  # Bool = false
    FFlagValidateUGCContentMakeupAssetTypes = 1767427324560  # Unknown = 
    FFlagVideoPlaybackDetectorCancelPendingScanTask = 1767526022800  # Unknown = 
    FFlagVipOwnerNotPresentEnableReconnect = 1768024102429  # Bool = false
    FFlagVirtualCursorDisplayOrder = 1767828555408  # Unknown = 
    FFlagVirtualCursorForTVRemoteKeycodes = 1768009975312  # Unknown = 
    FFlagVirtualCursorModularization4 = 1768009966992  # Unknown = 
    FFlagVirtualCursorSnapLevelBasedOnDirection = 1768009974672  # Unknown = 
    FFlagVirtualCursorSnapStopsWhenInputStops = 1768009988176  # Unknown = 
    FFlagVirtualizedFeedFooterWrapperProp = 1767526002064  # Unknown = 
    FFlagVngAppUpsellPcLayout = 1767526154077  # Bool = false
    FFlagVngLogoutGlobalAppSessionsOnConversion = 1767526146448  # Unknown = 
    FFlagVngTOSRevisedEnabled = 1767828590096  # Unknown = 
    FFlagVoiceARUnblockingUnmutingEnabled = 1768317795485  # Bool = false
    FFlagVoiceChatDisruptiveVoiceNudgeEnableVariant2 = 1768001210397  # Bool = false
    FFlagVoiceChatDisruptiveVoiceNudgeForceUseNewDACopy = 1768001211229  # Bool = false
    FFlagVoiceChatLocalMutedNilFix = 1768133857232  # Unknown = 
    FFlagVoiceChatMuteAllSyncMutedPlayers = 1767645298397  # Bool = false
    FFlagVoiceChatOnlyReportVoiceBans = 1767998355920  # Unknown = 
    FFlagVoiceChatSelectorReconnectFocus2_AEGIS2 = 1767913339101  # Bool = false
    FFlagVoiceChatServiceManagerUseAvatarChat = 1767645291869  # Bool = false
    FFlagVoiceChatUILogging = 1767913343184  # Unknown = 
    FFlagVoiceChatVolumePerUserDisableInteractionWhenMuted = 1768389348048  # Unknown = 
    FFlagVoiceChatVolumePerUserMuteVolumeSync = 1767574845325  # Bool = false
    FFlagVoiceConnectToastCapturesTrustedFriendsSubtitle = 1767998336912  # Unknown = 
    FFlagVoiceEndedCheckDisregardIdleState = 1767900733021  # Bool = true
    FFlagVoiceNudgeUseNewConfirmButton = 1767998332688  # Unknown = 
    FFlagVoiceRewarmTelemetryV2 = 1767583538525  # Bool = true
    FFlagVoiceSelectorAvailableAfterFae = 1767913339869  # Bool = false
    FFlagVoiceSelectorIgnoreFailedStateDisconnect = 1767913339792  # Unknown = 
    FFlagVoiceUserAgency3 = 1767831050384  # Unknown = 
    FFlagVoiceUserAgencyEnableIXP = 1767831046288  # Unknown = 
    FFlagVoiceVolumeControlsApplyPerUserMultiplier = 1767725040544  # Unknown = 
    FFlagVoiceVolumeControlsDisableInteractionWhenNoMasterVolume = 1767913338896  # Unknown = 
    FFlagVoiceVolumeControlsEnableNotAudibleVoiceChatVolumeToast = 1767913676117  # Bool = false
    FFlagVoiceVolumeControlsEnablePerUserVolumeInteractionTelemetry = 1768389362845  # Bool = true
    FFlagVoiceVolumeControlsEnableVoiceChatVolumeSlider = 1767913664597  # Bool = false
    FFlagVoiceVolumeControlsEnableVoiceVolumeEligibilityTelemetry = 1767645297949  # Bool = false
    FFlagVoiceVolumeControlsEnableVoiceVolumeImpressionsTelemetry = 1767645298077  # Bool = false
    FFlagVoiceVolumeControlsFixSliderVisibilityOnEligibleGames = 1767913339472  # Unknown = 
    FFlagVoiceVolumeControlsGlobalVoiceVolumeSliderIxpExposure = 1768001215005  # Bool = false
    FFlagVoiceVolumeControlsPerUserPlayerGridMenu = 1768389405968  # Unknown = 
    FFlagVoiceVolumeControlsPerUserPlayerListButton = 1768389354768  # Unknown = 
    FFlagVoiceVolumeControlsPerUserPlayerListButton5 = 1768389358480  # Unknown = 
    FFlagVoiceVolumeControlsSuppressInExperienceUiForPartyVoice = 1767913338960  # Unknown = 
    FFlagWHAM1707ExperimentForceEnabled = 1768384384357  # Bool = false
    FFlagWebViewHideLuaSideBar = 1767654047120  # Unknown = 
    FFlagWebViewServiceHasBackButtonVisibility = 1767654045200  # Unknown = 
    FFlagWhisperEmoteOnAvatarContextMenuWithExpChat = 1768017070288  # Unknown = 
    FFlagWrapEmphasisTileDescriptionText = 1768428734032  # Unknown = 
    FIntAXAnimatedScrollingFrameScrollTimeMs = 1767899191568  # Unknown = 
    FIntAXAvatarLoadRetryCount = 1767654064336  # Unknown = 
    FIntAXAvatarLoadRetryDelayMs = 1767654064464  # Unknown = 
    FIntAXAvatarUpdateOnGameLeaveDelay = 1767654050256  # Unknown = 
    FIntAXBackgroundFogDisabledDistance = 1767640155664  # Unknown = 
    FIntAXBackgroundGenerationMaxConsecutivePollFailures = 1775984814008  # Unknown = 
    FIntAXBackgroundGenerationMaxPromptLength = 1768113163016  # Unknown = 
    FIntAXBackgroundGenerationPollIntervalSeconds = 1768371866056  # Unknown = 
    FIntAXBackgroundGenerationPollTimeoutSeconds = 1767640155600  # Unknown = 
    FIntAXBackgroundsCatalogTabPosition = 1767625357936  # Unknown = 
    FIntAXBuyDelayMilliseconds = 1767643505296  # Unknown = 
    FIntAXCarouselItemsBasedOnFrameSize = 1767643492880  # Unknown = 
    FIntAXCarouselLoadingBuffer = 1767643492560  # Unknown = 
    FIntAXCarouselMaxItems = 1767643489872  # Unknown = 
    FIntAXCarouselPeakFraction = 1767643492688  # Unknown = 
    FIntAXCatalogMainNavHeight = 1767650023760  # Unknown = 
    FIntAXCatalogMultiItemShoppingFtuxOtherPromptMaxCount = 1767643507600  # Unknown = 
    FIntAXCatalogPartialPageModalBottomInsetMultiplier = 1767899169488  # Unknown = 
    FIntAXCategoryPillPositionAnimationDampingRatio = 1767899184656  # Unknown = 
    FIntAXCategoryPillPositionAnimationFrequency = 1767899184848  # Unknown = 
    FIntAXCategoryPillTransparencyAnimationDampingRatio = 1767899182416  # Unknown = 
    FIntAXCategoryPillTransparencyAnimationFrequency = 1767899184016  # Unknown = 
    FIntAXCheckoutButtonTooltipExpireTime = 1767643508496  # Unknown = 
    FIntAXCheckoutButtonTooltipFtuxDelay = 1767643507920  # Unknown = 
    FIntAXClusterCompositionTimeoutMs = 1767899154384  # Unknown = 
    FIntAXDefaultInventoryPageSize = 1767977089744  # Unknown = 
    FIntAXEnhancedAvatarHeadsFtuxDelay = 1768300694256  # Unknown = 
    FIntAXEnhancedAvatarHeadsFtuxDelayMs = 1767640146512  # Unknown = 
    FIntAXEyeMakeupZoomRadius = 1767899176336  # Unknown = 
    FIntAXEyebrowsZoomRadius = 1767899176144  # Unknown = 
    FIntAXEyelashesZoomRadius = 1767899176080  # Unknown = 
    FIntAXFPSDurationForCatSubCat = 1767654052048  # Unknown = 
    FIntAXFaceMakeupZoomRadius = 1767899176208  # Unknown = 
    FIntAXGetAvatarDataThrottleInterval = 1767654044368  # Unknown = 
    FIntAXGuiObjectIsObscuredPadding = 1767908739728  # Unknown = 
    FIntAXHDCatalogTabPosition = 1767650030032  # Unknown = 
    FIntAXHeadRefinementTooltipExpirationDurationDays = 1767650018064  # Unknown = 
    FIntAXLipMakeupZoomRadius = 1767899176272  # Unknown = 
    FIntAXLookImpressionDeferTimeoutMs = 1767977085008  # Unknown = 
    FIntAXLookOutfitCreationDelayMs = 1767977104400  # Unknown = 
    FIntAXLookOutfitCreationDelayMs1 = 1767977105232  # Unknown = 
    FIntAXLooksImageOffsetMultiplierX = 1767641052560  # Unknown = 
    FIntAXLooksImageOffsetMultiplierY = 1767641052880  # Unknown = 
    FIntAXLooksImageZoom = 1767641052368  # Unknown = 
    FIntAXMainNavHeight = 1767650024208  # Unknown = 
    FIntAXMakeupCategoryPosition = 1768393688720  # Unknown = 
    FIntAXMakeupLayeringTooltipDismissTimeoutSeconds = 1767643505424  # Unknown = 
    FIntAXMakeupLayeringTooltipMaxSeenCount = 1767643506704  # Unknown = 
    FIntAXMakeupLayeringTooltipShowDelayMS = 1767643506640  # Unknown = 
    FIntAXMakeupLooksZoomRadius = 1767899176016  # Unknown = 
    FIntAXMakeupMax6LayersPromptMaxSeenCount = 1767643505104  # Unknown = 
    FIntAXMakeupReleaseFtuxPromptDelayMS = 1767643508880  # Unknown = 
    FIntAXMakeupZoomRadius = 1767899175952  # Unknown = 
    FIntAXMaxAutocompleteSearchTextLen = 1767708379280  # Unknown = 
    FIntAXMaxRecentSearchTerms = 1767650224272  # Unknown = 
    FIntAXMaxRecentlyViewedSearchItems = 1767708379056  # Unknown = 
    FIntAXMaxRecentlyViewedSearchItemsInCarousel = 1767708380400  # Unknown = 
    FIntAXMaxThumbnailsToPrefetchPerWidgetLargeScreen = 1767654066320  # Unknown = 
    FIntAXMaxThumbnailsToPrefetchPerWidgetSmallScreen = 1767654064848  # Unknown = 
    FIntAXMaxUndoRedoHistory = 1767650019856  # Unknown = 
    FIntAXMinSaveIntervalSeconds = 1768377622096  # Unknown = 
    FIntAXMinSecsToRefreshRecommendedCatalogPage = 1767977061264  # Unknown = 
    FIntAXOutfitNameMaxLength = 1767640162832  # Unknown = 
    FIntAXPrefetchTTL = 1767977071824  # Unknown = 
    FIntAXPrefetchWidgetHydrationRowsLandscape = 1767640153872  # Unknown = 
    FIntAXPrefetchWidgetHydrationRowsPortrait = 1767640153296  # Unknown = 
    FIntAXSearchAutocompleteDebounceMs = 1767708388928  # Unknown = 
    FIntAXSkyboxBlockerPositionX = 1767654063248  # Unknown = 
    FIntAXSkyboxBlockerPositionY = 1767654063376  # Unknown = 
    FIntAXSkyboxBlockerPositionZ = 1767654063504  # Unknown = 
    FIntAXSkyboxBlockerSizeX = 1767654062864  # Unknown = 
    FIntAXSkyboxBlockerSizeY = 1767654062992  # Unknown = 
    FIntAXSkyboxBlockerSizeZ = 1767654063120  # Unknown = 
    FIntAXSlotBasedEditorAvatarSwitcherFtuxDelay2 = 1767650020176  # Unknown = 
    FIntAXSlotBasedEditorCustomizeFtuxDelay2 = 1767650021264  # Unknown = 
    FIntAXSponsoredItemsRow = 1767650023120  # Unknown = 
    FIntAXSubcategoryPillFadeAnimationDampingRatio = 1767899184336  # Unknown = 
    FIntAXSubcategoryPillFadeAnimationDurationMs = 1767899185296  # Unknown = 
    FIntAXSubcategoryPillFadeAnimationFrequency = 1767899185168  # Unknown = 
    FIntAXTooltipMaxNumberOfTimesSeen = 1768049876184  # Unknown = 
    FIntAXTooltipTimeToDismiss = 1767899192016  # Unknown = 
    FIntAXViewportCameraFieldOfView = 1767899817232  # Unknown = 
    FIntAXWidgetLoadedItemCountLimit = 1767977085968  # Unknown = 
    FIntAbuseReportMenuScreenshotReduceMotionWaitFrames = 1768317796944  # Unknown = 
    FIntAbuseReportMenuScreenshotWaitFrames = 1768317789200  # Unknown = 
    FIntAbuseReportTabClearCapturedScreenshotOnCloseFixDelay = 1767913355464  # Unknown = 
    FIntAccountPickerVariantOverride2 = 1767828574608  # Unknown = 
    FIntAccountRecoverySecondsBetweenResends = 1767526155408  # Unknown = 
    FIntAccountSwitchRelaunchFallbackSeconds = 1767526160848  # Unknown = 
    FIntAccountSwitcherAccountLimit = 1767526157392  # Unknown = 
    FIntAchievementGrantedThrottleHundrethsPercent = 1767908718480  # Unknown = 
    FIntActiveSquadInitPollingDelaySeconds = 1768050322384  # Unknown = 
    FIntActiveSquadPollingCardIntervalSeconds = 1768050283280  # Unknown = 
    FIntActiveSquadPollingIdleIntervalSeconds = 1768050273488  # Unknown = 
    FIntActiveSquadPollingLobbyIntervalSeconds = 1768050302480  # Unknown = 
    FIntAdGuiInteractivityPixelsPerStud = 1768060681744  # Unknown = 
    FIntAdIdentificationMinimumAreaPerMyriad = 1768377272784  # Unknown = 
    FIntAdIdentifiedTelemetryThrottleHundredthsPercent = 1768377255248  # Unknown = 
    FIntAddFriendsHttpRetryCount = 1767648652048  # Unknown = 
    FIntAddUILessModeVariant = 1767462083424  # Unknown = 
    FIntAgentTurnFeedbackEventThrottleHundredthsPercent = 1768139829712  # Unknown = 
    FIntAiOverviewExplicitFeedbackThrottleHundrethsPercent = 1768024520720  # Unknown = 
    FIntAiOverviewSentimentThrottleHundrethsPercent = 1768024525712  # Unknown = 
    FIntAllFriendsCacheTtlSec = 1767640196112  # Unknown = 
    FIntAppChatBehaviorCollectionEnabledPercentage = 1768132423824  # Unknown = 
    FIntAppChatChatLandingInitialFetchLimit = 1767641311120  # Unknown = 
    FIntAppChatChatLandingInitialFetchMinimumConversations = 1767641310416  # Unknown = 
    FIntAppChatGetAllMessagesDepth = 1768122205272  # Unknown = 
    FIntAppChatInExperienceDisplayOrder = 1768050279248  # Unknown = 
    FIntAppChatInExperienceMountMinLoadingTimeMs = 1768050299024  # Unknown = 
    FIntAppChatInitialMessageFetchLimit = 1768132410000  # Unknown = 
    FIntAppChatMessageFetchRetryDelayMs = 1768132403280  # Unknown = 
    FIntAppChatMessageInitialFetchMinMessages = 1768132413776  # Unknown = 
    FIntAppChatMessageLongPressDismissDelayMs = 1768132383056  # Unknown = 
    FIntAppChatMessageLongPressDistanceThreshold = 1768132381584  # Unknown = 
    FIntAppChatModalSeenImpressionDelayMs = 1768132434384  # Unknown = 
    FIntAppChatNetworkingHttpRetryCount = 1768017097104  # Unknown = 
    FIntAppChatNetworkingTelemetryThrottlingThousandths = 1768001219600  # Unknown = 
    FIntAppChatNewMessageFetchMaxDepth = 1767650015120  # Unknown = 
    FIntAppChatOsaAutoScrollDelayMs = 1768132420176  # Unknown = 
    FIntAppChatPerfChatConversationPaginationInitialRender = 1768132443024  # Unknown = 
    FIntAppChatPerfChatConversationPaginationOnEndReached = 1768179510448  # Unknown = 
    FIntAppChatPerfChatConversationPaginationOnStartReached = 1768132398160  # Unknown = 
    FIntAppChatPerfChatConversationPaginationWindowSize = 1768132427920  # Unknown = 
    FIntAppChatPerfChatLandingPaginationInitialRender = 1767641313936  # Unknown = 
    FIntAppChatPerfChatLandingPaginationOnEndReachedUnits = 1767641314320  # Unknown = 
    FIntAppChatPerfChatLandingPaginationOnStartReachedUnits = 1767641314192  # Unknown = 
    FIntAppChatPerfChatLandingPaginationWindowSize = 1767641313424  # Unknown = 
    FIntAppChatReplyIconSwipeOffset = 1768132390096  # Unknown = 
    FIntAppChatRoduxNetworkingHttpRetryCount = 1767650013520  # Unknown = 
    FIntAppChatScrollPerfMinDistancePx = 1768050314576  # Unknown = 
    FIntAppChatScrollPerfMinStableFrames = 1768050296528  # Unknown = 
    FIntAppChatSwipeCompleteThreshold = 1768132402384  # Unknown = 
    FIntAppChatSwipeMaxVerticalDrift = 1768132383184  # Unknown = 
    FIntAppChatSwipeStartThreshold = 1767994022024  # Unknown = 
    FIntAppChatWideBreakpointMinHeight = 1767494498440  # Unknown = 
    FIntAppChatWideBreakpointMinWidth = 1767641276816  # Unknown = 
    FIntAppHover1VolumePercentage = 1767583799312  # Unknown = 
    FIntAppIaScrollAwayThreshold = 1768017222608  # Unknown = 
    FIntAppLaunchReactProfilerLoggerCollectionTimeoutSec = 1768017215376  # Unknown = 
    FIntAppLaunchTrackerEnableHundredthsPercent = 1767583602960  # Unknown = 
    FIntAppMusicVolumePercentage = 1767650177808  # Unknown = 
    FIntAppNotificationHighVolumePercentage = 1767583799632  # Unknown = 
    FIntAppSelectVolumePercentage = 1767583800016  # Unknown = 
    FIntAttributionContextRecordedThrottleHundredthsPercent = 1767650168784  # Unknown = 
    FIntAuthButtonClickedThrottlingHundredthsPercent = 1768387551184  # Unknown = 
    FIntAuthPageMountThrottlingHundredthsPercent = 1768387569104  # Unknown = 
    FIntAutoFocusFailsafeThreshold = 1767640172496  # Unknown = 
    FIntAutoJoinNewServerTimeMs = 1767831061840  # Unknown = 
    FIntAvatarChatHeartbeatStatsEventThrottleHundrethsPercent = 1767899841616  # Unknown = 
    FIntAvatarEditorParticleEmitterRateOverride = 1767654061904  # Unknown = 
    FIntAvatarEditorTimeBetweenSaves = 1767654058576  # Unknown = 
    FIntAvatarGoldenRatio = 1776125408016  # Unknown = 
    FIntAvatarSwitcherGridOnEndReachedThreshold = 1768488524624  # Unknown = 
    FIntBlackbirdUpsellBannerMaxSessionImpressions = 1767897040016  # Unknown = 
    FIntBlackbirdUpsellMaxPriceForDiscountInclusive = 1767831096272  # Unknown = 
    FIntBlackbirdUpsellMinPriceForDiscountInclusive = 1767831093776  # Unknown = 
    FIntBlockUserButtonClickThrottleHundredthsPercent = 1768389371920  # Unknown = 
    FIntBlockUserButtonClickThrottleHundredthsPercent4 = 1768389400336  # Unknown = 
    FIntBlockUserThrottleHundredthsPercent = 1768389366544  # Unknown = 
    FIntBlockUserThrottleHundredthsPercent4 = 1768389384592  # Unknown = 
    FIntBubbleChatAddMessageRolloutPercent = 1768132428688  # Unknown = 
    FIntBugReporterErrorHundredthsPercent = 1767650179792  # Unknown = 
    FIntBugReporterMilestoneHundredthsPercent = 1767650179216  # Unknown = 
    FIntBugReportingHttpRetryCount = 1767650180176  # Unknown = 
    FIntBuildAgentDetailsStatusMenuWidth = 1768139833680  # Unknown = 
    FIntBuildCreatorCreditPostTurnRefreshDelaySeconds = 1768139837264  # Unknown = 
    FIntBuildCreatorCreditResetRefreshBufferSeconds = 1768139836752  # Unknown = 
    FIntBuildExperienceAssistantStatusSwapIntervalSeconds = 1768136698640  # Unknown = 
    FIntBuildExperienceAssistantThinkingDurationSuffixDelaySeconds = 1768136697616  # Unknown = 
    FIntBuildExperienceAudienceTooltipMaxWidth = 1768139846096  # Unknown = 
    FIntBuildExperienceEventThrottleHundredthsPercent = 1767473192144  # Unknown = 
    FIntBuildExperienceRollbackPlaceMaxRetries = 1768136703696  # Unknown = 
    FIntBuildExperienceRollbackPlaceRetryDelayMs = 1768136703248  # Unknown = 
    FIntBuildExperienceSetAudiencesMaxRetries = 1768139845520  # Unknown = 
    FIntBuildExperienceSetAudiencesRetryDelayMs = 1768139844880  # Unknown = 
    FIntBuildExperienceTurnActivityGapMsThrottleHundredthsPercent = 1768139827920  # Unknown = 
    FIntBuildExperienceUserPickerSearchDebounceMs = 1768139849104  # Unknown = 
    FIntBuildHistoryLoadTriggerViewportHeightPercent = 1768139816272  # Unknown = 
    FIntBuildMinimumUsableRobuxBalance = 1768139836944  # Unknown = 
    FIntBuildOverflowMenuWidth = 1768139805840  # Unknown = 
    FIntBuildPolicyRefreshTimeoutMs = 1768132391696  # Unknown = 
    FIntBuildPublishPreviewCardMaxWidth = 1768132384080  # Unknown = 
    FIntBuilderSansNavBarMaxSize = 1767654069200  # Unknown = 
    FIntBuilderSansNavBarMinSize = 1767654069392  # Unknown = 
    FIntBulkPurchaseEnabledCountdownMS = 1767908736080  # Unknown = 
    FIntBulkPurchaseMaxHttpRequestRetries = 1767908742352  # Unknown = 
    FIntBulkPurchaseMaxHttpRequestWaitTime = 1767908745744  # Unknown = 
    FIntBulkPurchaseMissingPurchaseOptionsCounterThrottleHundredthsPercent = 1768494494592  # Unknown = 
    FIntBulkPurchaseRequestLimit = 1767828592080  # Unknown = 
    FIntBulkPurchaseThrottleLimit = 1767828586960  # Unknown = 
    FIntCameraPresetHeadshotExtentScaleHundredths = 1776125409488  # Unknown = 
    FIntCaptureControlsStoredAnchorPoints = 1776085413200  # Unknown = 
    FIntCaptureMetadataGetAvatarsTimeoutMs = 1768126151696  # Unknown = 
    FIntCaptureMetadataMaxAvatars = 1768126150800  # Unknown = 
    FIntCaptureMetadataMinAvatarBoundingBoxPixels = 1768029421616  # Unknown = 
    FIntCaptureMetadataMinHitRatePercentage = 1776053173872  # Unknown = 
    FIntCapturesCommonMaxHttpRequestRetries = 1768126112912  # Unknown = 
    FIntCapturesCommonMaxHttpRequestWaitTime = 1767691054048  # Unknown = 
    FIntCapturesCoreGuiEventsPerMyriad = 1768132529808  # Unknown = 
    FIntCapturesMaxHttpRequestRetries = 1768126143312  # Unknown = 
    FIntCapturesMaxHttpRequestWaitTime = 1768126143632  # Unknown = 
    FIntCapturesSaveToExternalStorageLimit = 1767988665696  # Unknown = 
    FIntCapturesTelemetryThrottlingThousandths = 1768126141072  # Unknown = 
    FIntChallengeDialogEventReceiverHttpRetryCount = 1767654036112  # Unknown = 
    FIntChallengeDialogModalContainerHttpRetryCount = 1767654042000  # Unknown = 
    FIntCharacterNameHandlerUserProfileApiRollout = 1767583423376  # Unknown = 
    FIntChatAutocompleteMaxVisibleEntries = 1767860843536  # Unknown = 
    FIntChatGetConversationsPageSize = 1768017087760  # Unknown = 
    FIntChatInterventionUIRateLimitWindowSec = 1768132412816  # Unknown = 
    FIntChatModerationFrameLayoutOrder = 1767913338192  # Unknown = 
    FIntCheckLeaveGameUpsellCooldown = 1768132558928  # Unknown = 
    FIntChromeWindowLayoutOrder = 1775992609872  # Unknown = 
    FIntCloseReactPageThrottleHundredthsPercent = 1768133918096  # Unknown = 
    FIntCommercePurchaseMaxHttpRequestRetries = 1767913308240  # Unknown = 
    FIntCommercePurchaseMaxHttpRequestWaitTime = 1767913304272  # Unknown = 
    FIntCommsFAELockTimestamp = 1768393716496  # Unknown = 
    FIntCompactUpsellModalBreakpoint = 1768125825616  # Unknown = 
    FIntConnectionAmpGameJoinUpsellImpressionThrottleHundredthsPercent = 1768389394704  # Unknown = 
    FIntConnectionAmpUnlockPlayIntentThrottleHundredthsPercent = 1768389355664  # Unknown = 
    FIntConnectionAutoReconnectBaseDelayMs = 1768024099536  # Unknown = 
    FIntConnectionAutoReconnectFirstDelayMs = 1768024098960  # Unknown = 
    FIntConnectionAutoReconnectJitterMs = 1768024100560  # Unknown = 
    FIntConnectionAutoReconnectMaxDelayMs = 1768024100112  # Unknown = 
    FIntConnectionAutoReconnectMaxDurationSeconds = 1768024100368  # Unknown = 
    FIntContactImporterHttpRetryCount = 1768181189136  # Unknown = 
    FIntContactImporterModalDisplayMaxCount = 1768181142416  # Unknown = 
    FIntContactImporterModalDisplayMinDays = 1768179275792  # Unknown = 
    FIntContactImporterSyncMinHours = 1768181148176  # Unknown = 
    FIntContactImporterUploadContactsMax = 1768181150608  # Unknown = 
    FIntContactImporterUploadContactsMin = 1768181165520  # Unknown = 
    FIntContactsSyncWarningImpressionsCountCap = 1768181176400  # Unknown = 
    FIntContentPostsThumbnailsInitialDelayTimeMs = 1768126114320  # Unknown = 
    FIntContentPostsThumbnailsMaxRetries = 1768126114896  # Unknown = 
    FIntCoreScriptBacktraceErrorReportPercentage = 1768005241168  # Unknown = 
    FIntCoreScriptBacktracePIIFilterEraseTimeoutSeconds = 1768005280528  # Unknown = 
    FIntCoreScriptBacktraceRepeatedErrorRateLimitCount = 1768005290704  # Unknown = 
    FIntCoreScriptBacktraceRepeatedErrorRateLimitPeriod = 1768005261520  # Unknown = 
    FIntCoreScriptBacktraceRepeatedErrorRateLimitProcessIntervalTenths = 1768005297808  # Unknown = 
    FIntCoreScriptsProfilerDelaySeconds = 1767913317712  # Unknown = 
    FIntCoreScriptsProfilerDurationSeconds = 1767913318032  # Unknown = 
    FIntCoreScriptsProfilerSamplingHundredthsPercentv1 = 1767913317456  # Unknown = 
    FIntCoreScriptsProfilerTelemetryLimit = 1767913318480  # Unknown = 
    FIntCorescriptMemoryPeriodSeconds = 1767638309776  # Unknown = 
    FIntCreatorAgentChatMaxCachedSessionHistories = 1768136679504  # Unknown = 
    FIntCreatorAgentChatMaxReconciliationHistoryPages = 1768136678992  # Unknown = 
    FIntCreatorAgentChatPollBackoffMultiplier = 1768136678544  # Unknown = 
    FIntCreatorAgentChatPollMaxIntervalSeconds = 1768136677968  # Unknown = 
    FIntCreatorAgentChatPollMinIntervalSeconds = 1768136677392  # Unknown = 
    FIntCreatorAgentChatPrefetchHistoryPagesOnRefresh = 1768136678352  # Unknown = 
    FIntCreatorAgentChatRpcTimeoutSeconds = 1768136675856  # Unknown = 
    FIntCreatorAgentChatRtnIdleFallbackSeconds = 1768136676432  # Unknown = 
    FIntCreatorAgentChatRtnSequenceGapFallbackSeconds = 1768136676880  # Unknown = 
    FIntCrossDeviceLoginRollout2 = 1767650011728  # Unknown = 
    FIntCrossExperienceEventThrottleHunderedthsPercent = 1767591394992  # Unknown = 
    FIntCurrencyTransferDeveloperCommissionRate = 1767908760208  # Unknown = 
    FIntCurrencyTransferMaxAmount = 1767908755088  # Unknown = 
    FIntCurrencyTransferMinAmount = 1767908754704  # Unknown = 
    FIntCurrencyTransferPlatformFeeRate = 1767908760848  # Unknown = 
    FIntCurrencyTransferTelemetryCounterThrottleHundredthsPercent = 1767908756624  # Unknown = 
    FIntDebounceAIRephraseSettingDelay = 1767913335184  # Unknown = 
    FIntDebounceChatSummariesSettingDelay = 1767913337232  # Unknown = 
    FIntDebounceDisconnectButtonDelay = 1767913336720  # Unknown = 
    FIntDebugAvatarDataDelay = 1767654048208  # Unknown = 
    FIntDebugConnectDisconnectInterval = 1768001209424  # Unknown = 
    FIntDebugForceMSAASamples = 1767464157488  # Unknown = 
    FIntDebugLuaAppForceGamepad = 1768458322384  # Unknown = 
    FIntDeepLinkNavigationLockThrottlingHundredthsPercent = 1768387574672  # Unknown = 
    FIntDefaultInfiniteScrollRecommendationsFetchSize = 1767650023888  # Unknown = 
    FIntDefaultMaxPruneAccounts = 1767643516304  # Unknown = 
    FIntDeferredDeeplinkResolvedThrottleHundredthsPercent = 1767650168080  # Unknown = 
    FIntDeviceIntegrityNativeTimeoutMilliseconds = 1768017093456  # Unknown = 
    FIntDiscoverabilityModalHttpRetryCount = 1768181192400  # Unknown = 
    FIntDiscoveryAppLaunchErrorHundredthsPercent = 1767583605520  # Unknown = 
    FIntDiscoveryAppLaunchMilestonesHundredthsPercent = 1776083702632  # Unknown = 
    FIntDiscoveryClientAppStorageGetItemErrorThrottleHundredthsPercent = 1767977205520  # Unknown = 
    FIntDiscoveryEventErrorDetailsHundredthsPercent = 1767977193936  # Unknown = 
    FIntDiscoveryFeedStatsHundredthsPercent = 1767630908056  # Unknown = 
    FIntDiscoveryResponseErrorEventHundredthsPercent = 1767977227664  # Unknown = 
    FIntDiscoveryResponseSizeEventHundredthsPercent = 1767977193424  # Unknown = 
    FIntDiscoverySduiErrorHundredthsPercent = 1767643489424  # Unknown = 
    FIntDiscoverySduiInstrumentationHundredthsPercent = 1776083668072  # Unknown = 
    FIntDiscoverySduiParamUsageHundredthsPercent = 1767643491856  # Unknown = 
    FIntDiscoverySduiTimerEventsHundredthsPercent = 1767643490000  # Unknown = 
    FIntDiscoverySduiTypeUsageHundredthsPercent = 1767643491280  # Unknown = 
    FIntDiscoveryVideoEndEventHundredthsPercent = 1768024052944  # Unknown = 
    FIntDiscoveryVideoLoadEventHundredthsPercent = 1768024082256  # Unknown = 
    FIntDiscoveryVideoLoopEventHundredthsPercent = 1768024111696  # Unknown = 
    FIntDiscoveryVideoPlayEventHundredthsPercent = 1768024079568  # Unknown = 
    FIntDiscoveryWarningEventHundredthsPercent = 1768024530960  # Unknown = 
    FIntDrawerSwipeThresholdPercent = 1767831072144  # Unknown = 
    FIntDrawerSwipeVelocityThreshold = 1767831063504  # Unknown = 
    FIntDynamicAbuseReportV2ThrottleHundredthsPercent = 1768317809936  # Unknown = 
    FIntEditProfileMaxHttpRetries = 1767473196112  # Unknown = 
    FIntEdpBannerBottomVisiblePercent = 1767649978704  # Unknown = 
    FIntEdpFallbackActionBarPlayButtonWidth = 1767649976848  # Unknown = 
    FIntEdpFullBleedOverlapOffset = 1767649978512  # Unknown = 
    FIntEducationalPopupDisplayMaxCount = 1768300712400  # Unknown = 
    FIntEnableContactInvitesForNonPhoneVerifiedRollout = 1767583423824  # Unknown = 
    FIntEnableNewInviteMenuStyleRollout = 1767901844816  # Unknown = 
    FIntEnableSentryUARolloutPercentage = 1767650186064  # Unknown = 
    FIntEnableUnifiedProductPurchaseFlowThrottleHundredthsPercent = 1776067312400  # Unknown = 
    FIntEventNetworkHttpRetryCount = 1767643510416  # Unknown = 
    FIntEventStatusCheckIntervalSec = 1767640196752  # Unknown = 
    FIntExpChatChatableUserCountSystemMessageMinUsers = 1768389351312  # Unknown = 
    FIntExpChatDefaultARButtonPadding = 1768001237264  # Unknown = 
    FIntExpChatDefaultARButtonPaddingInset = 1768001226128  # Unknown = 
    FIntExpChatGlobalChatTabClickedThrottlePerMyriad = 1768365383368  # Unknown = 
    FIntExpChatHiddenMessagesPromptThresholdLowerBound = 1768038220944  # Unknown = 
    FIntExpChatHiddenMessagesPromptThresholdUpperBound = 1768038223824  # Unknown = 
    FIntExpChatMessageRenderUserThrottlePermyriad = 1768399769552  # Unknown = 
    FIntExpChatMessageResponseThrottlePermyriad = 1768038223440  # Unknown = 
    FIntExpChatMessageResponseUserSamplePermyriad = 1768038222288  # Unknown = 
    FIntExpChatMicActivityHeartbeatIncrement = 1768399794832  # Unknown = 
    FIntExpChatPresetActionThrottlePerMyriad = 1767641266768  # Unknown = 
    FIntExpChatPresetChatIconBadgeOverride = 1768176002160  # Unknown = 
    FIntExpChatPresetChatLoadAnalyticsTimeoutMs = 1768038215568  # Unknown = 
    FIntExpChatProximityStoreExtraRendersBeforeUnmount = 1767481493368  # Unknown = 
    FIntExpChatRandomCharChangeLowerBound = 1767860818320  # Unknown = 
    FIntExpChatRandomCharChangeUpperBound = 1767860804368  # Unknown = 
    FIntExpChatRewriteDropdownToggledThrottlePerMyriad = 1767641260496  # Unknown = 
    FIntExpChatScrollLockThreshold = 1767977097616  # Unknown = 
    FIntExpChatSlotBatchSize = 1768001209168  # Unknown = 
    FIntExpChatTabClickedThrottlePerMyriad = 1767641264720  # Unknown = 
    FIntExpChatTabImpressionThrottlePerMyriad = 1767641266384  # Unknown = 
    FIntExpChatVisibleARButtonPadding = 1768001215248  # Unknown = 
    FIntExpChatVisibleARButtonPaddingInset = 1768001218960  # Unknown = 
    FIntExpChatWindowScrollV3Debounce = 1767977120528  # Unknown = 
    FIntExpChatWindowTransparencyRewriteInteractableThreshold = 1768001231184  # Unknown = 
    FIntExpChatWindowTransparencyRewriteInteractableThresholdHundredth = 1768001198096  # Unknown = 
    FIntExperienceChatHeartbeatIncrement = 1768399774992  # Unknown = 
    FIntExperienceChatUserProfileApiRollout_v1 = 1768001221712  # Unknown = 
    FIntExperienceDetailsMotionJitterHundredthsPercent = 1767649974416  # Unknown = 
    FIntFAEBackgroundOnlyPollDelay = 1767648603344  # Unknown = 
    FIntFAEBackgroundOnlyPollMaxRetries = 1767648604432  # Unknown = 
    FIntFAEWithCallbackPollDelay = 1767648600272  # Unknown = 
    FIntFAEWithCallbackPollMaxRetries = 1767648603408  # Unknown = 
    FIntFAEWithWebViewCallbackPollDelay = 1767648604752  # Unknown = 
    FIntFAEWithWebViewCallbackPollMaxRetries = 1767648605200  # Unknown = 
    FIntFIntAXMinSaveIntervalSeconds = 1767650019600  # Unknown = 
    FIntFIntCrossExperienceEventThrottleHunderedthsPercent = 1767628077456  # Unknown = 
    FIntFIntInGameBuildChatSheetSnapPoint = 1768132391312  # Unknown = 
    FIntFIntLegacyPurchaseFPSTrackingTimeout = 1767831092304  # Unknown = 
    FIntFIntMuteSelfThrottleHundredthsPercent4 = 1768389370000  # Unknown = 
    FIntFIntPeoplePageLayoutChangedThrottleHundredthsPercent = 1768389372752  # Unknown = 
    FIntFIntPersonCardMenuToggledThrottleHundredthsPercent = 1768389385360  # Unknown = 
    FIntFIntSocialUpsellEventThrottleHunderedthsPercent = 1768017193936  # Unknown = 
    FIntFIntUIResetDelayInSec = 1767665953664  # Unknown = 
    FIntFIntUnmuteSelfThrottleHundredthsPercent4 = 1768389372560  # Unknown = 
    FIntFPSAwareSplashScreenTimeout = 1768060651728  # Unknown = 
    FIntFTUXPanelXOffset = 1775992610256  # Unknown = 
    FIntFacialAnimationStreamingHeartbeatStatsIntervalSec = 1767489918240  # Unknown = 
    FIntFallbackExclusiveUnderageCutoffForMultiPageSignup = 1767720520656  # Unknown = 
    FIntFeatureTileAdPlayerOverlayTransparencyPercent = 1767654043920  # Unknown = 
    FIntFeedItemRowDataCounterThrottle = 1768428776976  # Unknown = 
    FIntFlyoutContentItemClickEventThrottleHunderedthsPercent = 1776083695912  # Unknown = 
    FIntFlyoutSidePanelCloseEventThrottleHunderedthsPercent = 1775910028752  # Unknown = 
    FIntFlyoutSidePanelOpenEventThrottleHunderedthsPercent = 1776083722152  # Unknown = 
    FIntFlyoutTestVariantRollout12 = 1767978544080  # Unknown = 
    FIntFlyoutTooltipDismissEventThrottleHunderedthsPercent = 1775910031760  # Unknown = 
    FIntFlyoutTooltipShowEventThrottleHunderedthsPercent = 1775910027728  # Unknown = 
    FIntFriendCarouselRefreshThrottleInterval = 1767641307600  # Unknown = 
    FIntFriendPlayerJoinedRemoteEventTimeout = 1768229425232  # Unknown = 
    FIntFriendRequestNicknameMaxChars = 1767648614608  # Unknown = 
    FIntFriendRequestNicknameMaxHistory = 1767648614928  # Unknown = 
    FIntFriendRequestNicknameMinChars = 1767648614288  # Unknown = 
    FIntFriendRequestNicknamesMaxHttpRetries = 1767648613712  # Unknown = 
    FIntFriendRequestNicknamesTelemetryThrottlingThousandths = 1767648614096  # Unknown = 
    FIntFriendsCarouselFetchPageDistance = 1767583424720  # Unknown = 
    FIntFriendsCarouselHttpRetryCount = 1767649997584  # Unknown = 
    FIntFriendsCarouselInitialFetchSize = 1767583428240  # Unknown = 
    FIntFriendsCarouselSocialBtnFriendsLimit = 1767583427472  # Unknown = 
    FIntFriendsChatConversationListAutoscrollToTopThreshold = 1768028349136  # Unknown = 
    FIntFriendsChatConversationListInitialNumToRender = 1768028349392  # Unknown = 
    FIntFriendsChatConversationListPaginationThresholdRows = 1768028349648  # Unknown = 
    FIntFriendsChatConversationListScrollbarIdleHideMs = 1768028349904  # Unknown = 
    FIntFriendsChatConversationListScrollbarThickness = 1768028350288  # Unknown = 
    FIntFriendsChatConversationListWindowSize = 1768028350800  # Unknown = 
    FIntFriendsChatModeratedMaskMaxLength = 1767900732736  # Unknown = 
    FIntFriendsChatModeratedMaskMinLength = 1767900743440  # Unknown = 
    FIntFriendsCommonAnalyticsThrottlingThousandths = 1767640195344  # Unknown = 
    FIntFriendsCountCacheTtlSec = 1767640196368  # Unknown = 
    FIntFriendsHttpRetryCount = 1768012236304  # Unknown = 
    FIntFriendsLandingHttpRetryCount = 1768179259504  # Unknown = 
    FIntFriendsMenuHttpRetryCount = 1768132404368  # Unknown = 
    FIntFriendsPageSize = 1767640196496  # Unknown = 
    FIntFriendsStoreProcessDelaySec = 1767640195728  # Unknown = 
    FIntFriendshipStatusCacheTtlSec = 1768491960480  # Unknown = 
    FIntFullscreenTitleBarTriggerDelayMillis = 1776125350160  # Unknown = 
    FIntGameCardContainerHttpRetryCount = 1768050294160  # Unknown = 
    FIntGameConnectionsPlayedChipClickedThrottleHundredthsPercent = 1768024072720  # Unknown = 
    FIntGameCopyExperienceLinkThrottleHundrethsPercent = 1768024097936  # Unknown = 
    FIntGameCreatePrivateGameThrottleHundrethsPercent = 1768024062928  # Unknown = 
    FIntGameDetailsSubpageThrottleHundrethsPercent = 1768024109328  # Unknown = 
    FIntGameFavoriteThrottleHundrethsPercent = 1768024062160  # Unknown = 
    FIntGameFollowThrottleHundrethsPercent = 1768024075600  # Unknown = 
    FIntGameGridFlexFeedItemTileNumPerFeed = 1767526034704  # Unknown = 
    FIntGameInviteEntryPointThrottleHundredthsPercent = 1768389346576  # Unknown = 
    FIntGameInviteHttpRetryCount = 1776125410256  # Unknown = 
    FIntGameJoinCardAnalyticsThrottleHundredthsPercent = 1767641297360  # Unknown = 
    FIntGameJoinFriendsInGameThrottleHundrethsPercent = 1768024061328  # Unknown = 
    FIntGameShareExperienceLinkThrottleHundrethsPercent = 1767909001048  # Unknown = 
    FIntGameTileOverflowMenuActionThrottleHundrethsPercent = 1768024107088  # Unknown = 
    FIntGameVoteThrottleHundrethsPercent = 1768024108944  # Unknown = 
    FIntGamepadMenuActionThrottleHundrethsPercent = 1768136640464  # Unknown = 
    FIntGamepadOpenExperienceControlsMenuThrottleHundrethsPercent = 1768136639376  # Unknown = 
    FIntGameplayPauseShowDelayMs = 1767899821072  # Unknown = 
    FIntGenericInterventionSnackbarAutoDismissDelaySeconds = 1768050290384  # Unknown = 
    FIntGetRewardMetadataHttpRetryCount = 1776125390992  # Unknown = 
    FIntGetServerChannelRetries = 1768132558160  # Unknown = 
    FIntHapticTriggerAttemptThrottleHundredthsPercent = 1767649975056  # Unknown = 
    FIntHelpPageThrottleHundredthsPercent = 1768250570712  # Unknown = 
    FIntHomePagePYMKPercentageOfViewPortToStartFetch = 1767648613008  # Unknown = 
    FIntHomePagePYMKPresenceFetchThrottleInterval = 1767648614224  # Unknown = 
    FIntHomepageReadyFailsafeTimeoutSeconds = 1767654067920  # Unknown = 
    FIntIAFlyoutDailyTooltipMaxShownCount = 1775910045968  # Unknown = 
    FIntIAFlyoutTooltipMaxShownCount = 1775910042000  # Unknown = 
    FIntIDVMaxRetries = 1767643521168  # Unknown = 
    FIntIDVPollDelay = 1767643515728  # Unknown = 
    FIntIGARRaycastTargetCount = 1768377249872  # Unknown = 
    FIntIGARSubtreeDivergenceThresholdPerMille = 1768377231760  # Unknown = 
    FIntIGMTempOverrideGfxLv5 = 1767913344080  # Unknown = 
    FIntIconSelectionTimeout = 1767828617744  # Unknown = 
    FIntImageLoadObserverPollIntervalMs = 1767723051728  # Unknown = 
    FIntInAppAchievementManagerHttpRetryCount = 1767908721616  # Unknown = 
    FIntInAppBugReporterMaxTitleLength = 1767650178576  # Unknown = 
    FIntInAppBugReporterMinCommentLength = 1767650180752  # Unknown = 
    FIntInExpAchievementManagerHttpRetryCount = 1767908723216  # Unknown = 
    FIntInExpAmpWizardDisplayOrder = 1767648607632  # Unknown = 
    FIntInExperienceClickoutToggledTelemetryThrottleHundredthsPercent = 1767908708240  # Unknown = 
    FIntInExperienceDetailsPromptClosedHundredthsPercent = 1768024565264  # Unknown = 
    FIntInExperienceDetailsPromptDisplayOrder = 1767913316432  # Unknown = 
    FIntInExperienceDetailsPromptLoadedHundredthsPercent = 1768024536336  # Unknown = 
    FIntInExperienceDetailsPromptOpenedHundredthsPercent = 1768024551120  # Unknown = 
    FIntInExperienceDetailsPromptPlayClickedHundredthsPercent = 1768001745576  # Unknown = 
    FIntInExperienceInterventionDisplayOrder = 1768132416656  # Unknown = 
    FIntInExperienceInterventionToastDuration = 1768132411600  # Unknown = 
    FIntInExperienceShopTelemetryThrottleHundredthsPercent = 1775985101832  # Unknown = 
    FIntInExperienceTransferMaxHttpRequestRetries = 1767913293584  # Unknown = 
    FIntInExperienceTransferMaxHttpRequestWaitTime = 1767913294032  # Unknown = 
    FIntInGameBuildChatSheetSnapPoint = 1768213804272  # Unknown = 
    FIntInGameRobuxUpsellEventThrottleHundredthsPercent = 1768125850576  # Unknown = 
    FIntInitialFriendsPageSize = 1767640196624  # Unknown = 
    FIntInitialTrustedFriendRequestsPageSize = 1767583389008  # Unknown = 
    FIntInitializeFmodMsDelay = 1776085423760  # Unknown = 
    FIntInspectAndBuyClusterCompositionTimeoutMs = 1767899812368  # Unknown = 
    FIntInspectButtonThrottleHundredthsPercent = 1768389403472  # Unknown = 
    FIntIntervalPerformanceTrackerEventStream = 1768027275536  # Unknown = 
    FIntIntervalPerformanceTrackerEventThrottleHundrethsPercent = 1767860818896  # Unknown = 
    FIntInviteLinkExpiredModalHttpRetryCount = 1767473196688  # Unknown = 
    FIntIosAuthServiceHealthCounterThrottlingHundredthsPercent = 1768387531856  # Unknown = 
    FIntIosAuthServiceLoginThrottlingHundredthsPercent = 1768387574608  # Unknown = 
    FIntIsFriendsWithCacheTtlSec = 1767640195984  # Unknown = 
    FIntIxpFlyoutControl = 1767989423376  # Unknown = 
    FIntIxpFlyoutVariantAlternateEntry = 1767989405712  # Unknown = 
    FIntIxpFlyoutVariantHamburger = 1767989412368  # Unknown = 
    FIntIxpFlyoutVariantNoSubTabs = 1767989410832  # Unknown = 
    FIntIxpFlyoutVariantRemovalRobuxIcon = 1767989403088  # Unknown = 
    FIntKeystoreTelemetryThrottlingHundredthsPercent = 1768387561872  # Unknown = 
    FIntKeystoreTimeout = 1768387522448  # Unknown = 
    FIntLargeCollectionItemFractionalPercent = 1768024514512  # Unknown = 
    FIntLargeCollectionItemMaxItemCount = 1768024531600  # Unknown = 
    FIntLargeCollectionItemMinItemCount = 1768024529552  # Unknown = 
    FIntLargeCollectionItemMinItemWidth = 1768024568336  # Unknown = 
    FIntLargeCollectionItemVerticalGap = 1768024507600  # Unknown = 
    FIntLegacyPurchaseFPSTrackingTimeout = 1767526328048  # Unknown = 
    FIntLinkingProtocolFetchRetries = 1767470835408  # Unknown = 
    FIntLinkingProtocolFetchTimeoutMS = 1767470835600  # Unknown = 
    FIntLivenessBackgroundOnlyPollDelay = 1768017090512  # Unknown = 
    FIntLivenessBackgroundOnlyPollMaxRetries = 1768017095568  # Unknown = 
    FIntLivenessWithCallbackPollDelay = 1768017036112  # Unknown = 
    FIntLivenessWithCallbackPollMaxRetries = 1768017059984  # Unknown = 
    FIntLoadingScreenQueuedStateButtonClickThrottleHundredthsPercent = 1767831062288  # Unknown = 
    FIntLogTreeMaxLogsToBacktrace = 1767640184784  # Unknown = 
    FIntLoginByUsernameSSOErrorsThrottleHundrethsPercent = 1776108544152  # Unknown = 
    FIntLookAvatarRotationDegree1 = 1776125407824  # Unknown = 
    FIntLuaAppAccountSecurityPromptForcePopUpRenderAfterSeconds = 1767650226832  # Unknown = 
    FIntLuaAppAccountSecurityPromptPollingIntervalSeconds = 1767473210256  # Unknown = 
    FIntLuaAppAccountSecurityPromptPollingIntervalSecondsVisible = 1767723040976  # Unknown = 
    FIntLuaAppAccountSecurityPromptPopUpSpawnDelay = 1767723041296  # Unknown = 
    FIntLuaAppAccountSecurityPromptRollout = 1767468740256  # Unknown = 
    FIntLuaAppAutocompleteSearchTextMaxLen = 1767650225104  # Unknown = 
    FIntLuaAppBackToTopClickEventThrottlingHundredthsPercent = 1768024512976  # Unknown = 
    FIntLuaAppBatchFetchingStatusDelayMs = 1767470829968  # Unknown = 
    FIntLuaAppChallengeDeviceAccessEventThrottlingPercent = 1768001222672  # Unknown = 
    FIntLuaAppChallengeDialogEventReceiverRetryIntervalSeconds = 1767654035984  # Unknown = 
    FIntLuaAppChallengeDialogEventReceiverRetryTimes = 1767654035152  # Unknown = 
    FIntLuaAppChallengeDialogPollingIntervalSeconds = 1767654041424  # Unknown = 
    FIntLuaAppCredentialsProtocolAvailableTimeout = 1767643519696  # Unknown = 
    FIntLuaAppCredentialsProtocolTimeout = 1767643519120  # Unknown = 
    FIntLuaAppDataHydrationDefaultBatchSize = 1768012201744  # Unknown = 
    FIntLuaAppDataHydrationDefaultRequestTimeoutSec = 1768012245520  # Unknown = 
    FIntLuaAppDataHydrationQueueProcessDelaySec = 1768012223888  # Unknown = 
    FIntLuaAppDefaultDataTtlSec = 1768012240784  # Unknown = 
    FIntLuaAppDefaultFailedDataTtlSec = 1768012193680  # Unknown = 
    FIntLuaAppDelayImpressionsMaxUpdates = 1767526034896  # Unknown = 
    FIntLuaAppDiscoveryClientAppStorageCacheTtlDays = 1767977219536  # Unknown = 
    FIntLuaAppEdpMediaGalleryItemVisiblePercent = 1767526019792  # Unknown = 
    FIntLuaAppEdpVideoAvailableRamThresholdMb = 1768389379920  # Unknown = 
    FIntLuaAppEdpVideoMaxMemoryThresholdMb = 1768389362128  # Unknown = 
    FIntLuaAppEnableReactProfilerHundredthsPercent = 1767470802704  # Unknown = 
    FIntLuaAppFeedImpressionsHundredthsPercent = 1767641050576  # Unknown = 
    FIntLuaAppFriendsSortHeaderMaxHiddenPosition = 1768215390224  # Unknown = 
    FIntLuaAppGameAttributionErrorEventThrottleHundrethsPercent = 1768024528016  # Unknown = 
    FIntLuaAppGameDetailReferralEventThrottlingHundredthsPercent = 1768024081680  # Unknown = 
    FIntLuaAppGameDetailReferralShadowThrottlingHundredthsPercent = 1768001745608  # Unknown = 
    FIntLuaAppGameGridBufferRowsAboveScreen = 1768428778128  # Unknown = 
    FIntLuaAppGameGridBufferRowsBelowScreen = 1768428777168  # Unknown = 
    FIntLuaAppGameGridRevealMoreButtonGapPx = 1767526033616  # Unknown = 
    FIntLuaAppGameIconLargeSizePx = 1768012246864  # Unknown = 
    FIntLuaAppGameIconSmallSizePx = 1768012248144  # Unknown = 
    FIntLuaAppGameImpressionsEventThrottlingHundredthsPercent = 1768428777488  # Unknown = 
    FIntLuaAppGameImpressionsShadowThrottlingHundredthsPercent = 1768428774800  # Unknown = 
    FIntLuaAppGamePlayIntentEventThrottlingHundredthsPercent = 1768024065680  # Unknown = 
    FIntLuaAppGamePlayIntentShadowThrottlingHundredthsPercent = 1768024110160  # Unknown = 
    FIntLuaAppGameTileHoverDelayMs = 1768428738000  # Unknown = 
    FIntLuaAppGameTileVideoAvailableRamThresholdMb = 1768428744016  # Unknown = 
    FIntLuaAppGameTileVideoDwellTimeInSec = 1767526024208  # Unknown = 
    FIntLuaAppGameTileVideoMaxMemoryThresholdMb = 1768428742416  # Unknown = 
    FIntLuaAppGameTileVideoVisiblePercent = 1767526024784  # Unknown = 
    FIntLuaAppGamesListSortTokenExpiryInSec = 1767649995856  # Unknown = 
    FIntLuaAppHomeFeedFriendsPosition = 1767723048080  # Unknown = 
    FIntLuaAppHomeFeedProfilePosition = 1767723047760  # Unknown = 
    FIntLuaAppHomeFeedUpsellCardPosition = 1767723048528  # Unknown = 
    FIntLuaAppIECVRVariantNoSpatialUI = 1767978513040  # Unknown = 
    FIntLuaAppIECVRVariantSpatialUIMovePanelToCenter = 1767978530896  # Unknown = 
    FIntLuaAppIECVRVariantSpatialUIWithDragging = 1767900756064  # Unknown = 
    FIntLuaAppIECVRVariantSpatialUIWithoutDragging = 1767900756960  # Unknown = 
    FIntLuaAppInvalidPlayIntentThrottlingHundredthsPercent = 1768024085840  # Unknown = 
    FIntLuaAppItemActionEventThrottlingHundredthsPercent = 1767641054672  # Unknown = 
    FIntLuaAppItemActionShadowThrottlingHundredthsPercent = 1776083672232  # Unknown = 
    FIntLuaAppItemImpressionsEventThrottlingHundredthsPercent = 1767641052496  # Unknown = 
    FIntLuaAppItemImpressionsShadowThrottlingHundredthsPercent = 1767641051792  # Unknown = 
    FIntLuaAppJoinGameFailureInfluxHundredthsPercentage = 1768024538576  # Unknown = 
    FIntLuaAppLaunchTrackerTimeoutSec = 1767583608976  # Unknown = 
    FIntLuaAppLoginRollout = 1767650012560  # Unknown = 
    FIntLuaAppLoginRolloutIos = 1767650011664  # Unknown = 
    FIntLuaAppLumberyakLogBound = 1767640183504  # Unknown = 
    FIntLuaAppNxMApportioningDiagnosticThrottleHundredthsPercent = 1768012200720  # Unknown = 
    FIntLuaAppOmniFeedInitialNumRows = 1767723041104  # Unknown = 
    FIntLuaAppOmniFeedLoadNumRows = 1767723045072  # Unknown = 
    FIntLuaAppOmniFeedScrollAnimDurationMs = 1767723045392  # Unknown = 
    FIntLuaAppOneByTwoTileGradientBottomHeightPercent = 1768428792080  # Unknown = 
    FIntLuaAppOneByTwoTileGradientBottomTransparencyPercent = 1768428790352  # Unknown = 
    FIntLuaAppOneByTwoTileGradientTopTransparencyPercent = 1768428796368  # Unknown = 
    FIntLuaAppOneByTwoTileLogoWidthPercentLandscape = 1768428790416  # Unknown = 
    FIntLuaAppOneByTwoTileLogoWidthPercentSquare = 1768428795664  # Unknown = 
    FIntLuaAppPlayButtonLoadingDurationTelemetryThrottleHundredthsPercent = 1768024051920  # Unknown = 
    FIntLuaAppPlayButtonSecondaryButtonGap = 1767526032016  # Unknown = 
    FIntLuaAppPlayButtonThrottleTimeSeconds = 1767526033168  # Unknown = 
    FIntLuaAppPlayButtonWizardCloseDelayMs = 1767526033744  # Unknown = 
    FIntLuaAppPlayWithRewardMobileEdpLayoutOrder = 1767654032272  # Unknown = 
    FIntLuaAppRecommendedGamesCount = 1768012199184  # Unknown = 
    FIntLuaAppSchedulerDeferredWork = 1767828565392  # Unknown = 
    FIntLuaAppSchedulerDesiredFrameRate = 1767828600400  # Unknown = 
    FIntLuaAppSchedulerHeartbeatFrameMarker = 1767828600080  # Unknown = 
    FIntLuaAppSchedulerLookbackUseRingBuffer = 1767828607248  # Unknown = 
    FIntLuaAppSchedulerMinimumFrameRate = 1767828600208  # Unknown = 
    FIntLuaAppSchedulerNumberOfLookbackFrames = 1767828596112  # Unknown = 
    FIntLuaAppSchedulerTargetMsByHeartbeatDelta = 1767828602000  # Unknown = 
    FIntLuaAppSchedulerYieldInterval = 1767828561936  # Unknown = 
    FIntLuaAppSduiCarouselPlaceholderHeaderHeightPx = 1767526007760  # Unknown = 
    FIntLuaAppSduiCarouselPlaceholderHeaderMaxWidthPct = 1767650212048  # Unknown = 
    FIntLuaAppSduiCarouselPlaceholderHeaderMinWidthPct = 1767650213008  # Unknown = 
    FIntLuaAppSearchAutocompleteDebounceMs = 1767807299816  # Unknown = 
    FIntLuaAppSessionWithErrorThrottlePercentage = 1767640175312  # Unknown = 
    FIntLuaAppShowMoreClickEventThrottlingHundredthsPercent = 1768024541648  # Unknown = 
    FIntLuaAppSmallScreenDesignWidth = 1767473178960  # Unknown = 
    FIntLuaAppSponsoredAdLoadTelemetryThrottlingHundredthsPercent = 1768428787152  # Unknown = 
    FIntLuaAppSponsoredAdUnloadTelemetryThrottlingHundredthsPercent = 1768428786832  # Unknown = 
    FIntLuaAppSponsoredAdViewableImpressionTelemetryThrottlingHundredthsPercent = 1768428796432  # Unknown = 
    FIntLuaAppStartupReactSchedulerDelayMs = 1767640173648  # Unknown = 
    FIntLuaAppStartupReactSchedulerInterval = 1767640174224  # Unknown = 
    FIntLuaAppSubTabTopPadding = 1767828572688  # Unknown = 
    FIntLuaAppThrottleInviteSendEndpointDelay = 1767901851024  # Unknown = 
    FIntLuaAppThrottleRefreshPlayabilityIntervalSeconds = 1768458318864  # Unknown = 
    FIntLuaAppTransparentPageMaxCount = 1767654044688  # Unknown = 
    FIntLuaAppTwoByOneTileGradientEndOpacityPercent = 1768428790928  # Unknown = 
    FIntLuaAppTwoByOneTileGradientStartOpacityPercent = 1768428797584  # Unknown = 
    FIntLuaAppTwoByOneTileGradientWidthPercent = 1768428775184  # Unknown = 
    FIntLuaAppTwoByOneTileLogoHeightPercentLandscape = 1768428786960  # Unknown = 
    FIntLuaAppTwoByOneTileLogoHeightPercentSquare = 1768428789520  # Unknown = 
    FIntLuaAppTwoByOneTileSmallScreenBreakpoint = 1768428783056  # Unknown = 
    FIntLuaAppUpdateImpressionsViewportBoundsPositionThreshold = 1767525988880  # Unknown = 
    FIntLuaAppVideoAutoplayMaxDistanceToWinnerLinePercent = 1768389389392  # Unknown = 
    FIntLuaAppVideoAutoplayWinnerLineOffsetFromTopBarPx = 1768389385488  # Unknown = 
    FIntLuaAppViewportBoundsScreenSizeThreshold = 1767525990480  # Unknown = 
    FIntLuaAppVngUpsellNagFrequencySec = 1767723049488  # Unknown = 
    FIntLuaAppsAppsflyerIdCounterThrottle = 1767650170128  # Unknown = 
    FIntLuaCoreScriptsErrorV2ThrottleHundredthPercentage = 1768005421456  # Unknown = 
    FIntLuaErrorV2ThrottleHundredthPercentage = 1767640173456  # Unknown = 
    FIntLuaFetchUpdatedUserAgreementsErrorsThrottling = 1767473189968  # Unknown = 
    FIntLuaHttpClientPayloadSizeEventHundredthsPercent = 1768012227856  # Unknown = 
    FIntLuaHttpClientRequestStatusEventHundredthsPercent = 1768012213776  # Unknown = 
    FIntLuaHttpClientRequestTimerEventHundredthsPercent = 1768012231312  # Unknown = 
    FIntLuaInExpSchedulerDeferredWork = 1767828565712  # Unknown = 
    FIntLuaInExpSchedulerDesiredFrameRate = 1767828594832  # Unknown = 
    FIntLuaInExpSchedulerHeartbeatFrameMarker = 1767828614224  # Unknown = 
    FIntLuaInExpSchedulerLookbackUseRingBuffer = 1767828609040  # Unknown = 
    FIntLuaInExpSchedulerMinimumFrameRate = 1767828557456  # Unknown = 
    FIntLuaInExpSchedulerNumberOfLookbackFrames = 1767828607376  # Unknown = 
    FIntLuaInExpSchedulerTargetMsByHeartbeatDelta = 1767828584656  # Unknown = 
    FIntLuaInExpSchedulerYieldInterval = 1767828601808  # Unknown = 
    FIntLuaJoinYourFriendsRefreshInterval = 1767723041168  # Unknown = 
    FIntLuaLogoutReasonsThrottleHundrethsPercent = 1767641313744  # Unknown = 
    FIntLuaLogoutThrottlingHundredthsPercent = 1768387525648  # Unknown = 
    FIntLuaMaxCatalogTopics = 1767650024464  # Unknown = 
    FIntLuaMaxItemsInTopicsRequest = 1767650024592  # Unknown = 
    FIntLuaPushUpsellEventThrottleHundrethsPercent = 1767641316624  # Unknown = 
    FIntLuaUIOcclusionMetricsReportingPeriodSeconds = 1767828556368  # Unknown = 
    FIntLuaVoiceChatAnalyticsPointsThrottle = 1768395988240  # Unknown = 
    FIntLuaVoiceChatThrottleHundrethsPercent = 1767645286224  # Unknown = 
    FIntLuaVoiceVolumeControlsEligibilityThrottleHundredthsPercent = 1767645284752  # Unknown = 
    FIntLuaVoiceVolumeControlsImpressionsThrottleHundredthsPercent = 1767645284816  # Unknown = 
    FIntMaquetesAppPanelDistanceMultiplierPercentage = 1767583541584  # Unknown = 
    FIntMaxDaysToShowCountDownLabel = 1768017175824  # Unknown = 
    FIntMaxIGMBackgroundTransparencyPercent = 1767998333328  # Unknown = 
    FIntMaxKickMessageLength = 1768024097680  # Unknown = 
    FIntMaxNumUniversesExposedToCardTooltip = 1768317823376  # Unknown = 
    FIntMaxReferredPlayerJoinToasts = 1767720490640  # Unknown = 
    FIntMaxTraversalHistoryCardsPerRow709 = 1768428779728  # Unknown = 
    FIntMaxVideoCaptureDurationSeconds = 1776085419088  # Unknown = 
    FIntMaximumTraversalHistoryItemsFetch = 1768389381392  # Unknown = 
    FIntMediumCollectionItemFractionalPercent = 1768024534416  # Unknown = 
    FIntMediumCollectionItemMaxItemCount = 1768024510288  # Unknown = 
    FIntMediumCollectionItemMinItemCount = 1768024520016  # Unknown = 
    FIntMediumCollectionItemMinItemWidth = 1768210621696  # Unknown = 
    FIntMediumCollectionItemVerticalGap = 1768024515792  # Unknown = 
    FIntMenuButtonsThrottleHundredthsPercent = 1768133916752  # Unknown = 
    FIntMinDaysToShowCountDownLabel = 1768017229968  # Unknown = 
    FIntMinDaysToShowCountdownLabel = 1768017187408  # Unknown = 
    FIntMobileBreakpointInspectAndBuy = 1767473198032  # Unknown = 
    FIntMobileGameJoinCardBannerLoadCounterThrottleHundredthsPercent = 1767641305680  # Unknown = 
    FIntModalChallengeDialogApprovalHttpRetryCount = 1767654040272  # Unknown = 
    FIntModalChallengeDialogExpiredHttpRetryCount = 1767654040848  # Unknown = 
    FIntModalImpressionThrottleHundrethsPercent = 1767650179152  # Unknown = 
    FIntMomentDraftTTLDays = 1776085373136  # Unknown = 
    FIntMomentsPreloadDecodeRetryDelayMs = 1776085379664  # Unknown = 
    FIntMomentsPreloadDecodeWindowBack = 1776085393424  # Unknown = 
    FIntMomentsPreloadDecodeWindowForward = 1776085402256  # Unknown = 
    FIntMomentsPreloadDownloadWindowBack = 1776085403536  # Unknown = 
    FIntMomentsPreloadDownloadWindowForward = 1776085427792  # Unknown = 
    FIntMomentsPreloadMaxDecodeRetries = 1776085428496  # Unknown = 
    FIntMomentsScreenshotDurationSeconds = 1776085383760  # Unknown = 
    FIntMomentsSurfaceLoadTTIMaxMs = 1767470820624  # Unknown = 
    FIntMomentsSurfaceLoadTTISamplingRate = 1767470820240  # Unknown = 
    FIntMomentsTTSDefaultVoiceId = 1776085408784  # Unknown = 
    FIntMomentsTTSMaxCharacters = 1776085423440  # Unknown = 
    FIntMomentsTTSWaveformMaxBarHeightPercent = 1776085382096  # Unknown = 
    FIntMomentsTTSWaveformMaxSamples = 1776085379216  # Unknown = 
    FIntMomentsTTSWaveformMinBarHeightPercent = 1768158596024  # Unknown = 
    FIntMomentsTTSWaveformMinSamples = 1776085381840  # Unknown = 
    FIntMomentsTTSWaveformSamplesPerSecond = 1776085384592  # Unknown = 
    FIntMuteAllThrottleHundredthsPercent = 1768389389712  # Unknown = 
    FIntMutePlayerThrottleHundredthsPercent = 1768389402384  # Unknown = 
    FIntMuteSelfThrottleHundredthsPercent = 1768389409744  # Unknown = 
    FIntMuteSelfThrottleHundredthsPercent4 = 1767862313424  # Unknown = 
    FIntMyCreationsSessionListPollingIntervalSeconds = 1768139839760  # Unknown = 
    FIntMyStatsExperienceAskForLogsMaxEntries = 1768139817040  # Unknown = 
    FIntMyStatsExperienceSearchDebounceMs = 1768139839056  # Unknown = 
    FIntNewBadgeMaximumImpressionCount = 1767643493328  # Unknown = 
    FIntNewInGameMenuPercentRollout3 = 1767972957904  # Unknown = 
    FIntNotInterestedFeedbackFormActionThrottleHundredthsPercent = 1768428751376  # Unknown = 
    FIntNotificationsUpsellModalHttpRetryCount = 1767641315088  # Unknown = 
    FIntOffPlatformFriendRequestsRolloutEnabled = 1768181153232  # Unknown = 
    FIntOldestUAVersionToReportErrors = 1767900742768  # Unknown = 
    FIntOmniFeedDividerHeightOverride = 1768001917704  # Unknown = 
    FIntOmniFeedDividerPaddingOverride = 1768458335696  # Unknown = 
    FIntOmniRecommendationsMetadataEventThrottlingHundredthsPercent = 1767649997008  # Unknown = 
    FIntOnlineFriendsCacheTtlSec = 1767640195856  # Unknown = 
    FIntOpenLeavingRobloxModalThrottleHundrethsPercent = 1768024520912  # Unknown = 
    FIntOpenReactPageThrottleHundredthsPercent = 1768133918352  # Unknown = 
    FIntOpenSearchResultsWithQueryDeeplinkEventThrottlingHundredthsPercent = 1768024521808  # Unknown = 
    FIntPYMKCarouselHttpRetryCount = 1767643523600  # Unknown = 
    FIntPYMKSeeAllTileLimit = 1767648612752  # Unknown = 
    FIntParentalControlsScreentimeLockoutPollIntervalMs = 1767650168272  # Unknown = 
    FIntPartyVoiceAudioFaderVolumePerc = 1767628078160  # Unknown = 
    FIntPartyVoiceJoinRequestPulseCheckTimeout = 1767583397200  # Unknown = 
    FIntPartyVoiceRestrictionStatusMaxAttempts = 1768050289744  # Unknown = 
    FIntPartyVoiceTelemetryThrottlingThousandths = 1767900735184  # Unknown = 
    FIntPartyVoiceTopbarActivityIndicatorAnimationMs = 1775985163992  # Unknown = 
    FIntPartyVoiceUndeafenDelayMS = 1767526151952  # Unknown = 
    FIntPasskeyUpsellDisableButtonTimer = 1767650171920  # Unknown = 
    FIntPeekViewTransitionDelayTiming = 1767526153680  # Unknown = 
    FIntPeoplePageLayoutChangedThrottleHundredthsPercent = 1767425288592  # Unknown = 
    FIntPeoplePageLazyRenderThreshold = 1768317825488  # Unknown = 
    FIntPeoplePageVirtualizedGridBuffer = 1768317833744  # Unknown = 
    FIntPeopleServiceGameInviteEntryPointThrottleHundredthsPercent4 = 1768389374288  # Unknown = 
    FIntPeopleServiceInspectButtonThrottleHundredthsPercent4 = 1768389395408  # Unknown = 
    FIntPeopleServiceMuteAllThrottleHundredthsPercent4 = 1768389366736  # Unknown = 
    FIntPeopleServiceMutePlayerThrottleHundredthsPercent4 = 1768389369744  # Unknown = 
    FIntPeopleServicePerUserVoiceVolumeChangedThrottleHundredthsPercent = 1768389362960  # Unknown = 
    FIntPeopleServicePerUserVoiceVolumeMutedViaSliderThrottleHundredthsPercent = 1768389368272  # Unknown = 
    FIntPeopleServicePerUserVoiceVolumeSessionThrottleHundredthsPercent = 1768389405136  # Unknown = 
    FIntPeopleServicePerUserVoiceVolumeSliderTouchThrottleHundredthsPercent = 1768389360464  # Unknown = 
    FIntPeopleServicePerUserVoiceVolumeUnmutedViaSliderThrottleHundredthsPercent = 1768389369424  # Unknown = 
    FIntPeopleServiceRequestFriendshipThrottleHundredthsPercent4 = 1768389395792  # Unknown = 
    FIntPeopleServiceUnmuteAllThrottleHundredthsPercent4 = 1768389381264  # Unknown = 
    FIntPeopleServiceUnmutePlayerThrottleHundredthsPercent4 = 1768389403536  # Unknown = 
    FIntPerUserVoiceVolumeChangedThrottleHundredthsPercent = 1768389369040  # Unknown = 
    FIntPerUserVoiceVolumeMutedViaSliderThrottleHundredthsPercent = 1768389363408  # Unknown = 
    FIntPerUserVoiceVolumeSessionThrottleHundredthsPercent = 1768389385744  # Unknown = 
    FIntPerUserVoiceVolumeSliderTouchThrottleHundredthsPercent = 1768389372432  # Unknown = 
    FIntPerUserVoiceVolumeUnmutedViaSliderThrottleHundredthsPercent = 1768389349328  # Unknown = 
    FIntPerfInsightsHbMax = 1767650168208  # Unknown = 
    FIntPerfInsightsHbMin = 1767650166928  # Unknown = 
    FIntPerfInsightsInMax = 1767650169040  # Unknown = 
    FIntPerfInsightsInMin = 1767650167504  # Unknown = 
    FIntPersonCardMenuToggledThrottleHundredthsPercent = 1767425288656  # Unknown = 
    FIntPersonaLivenessV2QrPollDelaySec = 1768017087056  # Unknown = 
    FIntPersonaLivenessV2QrPollMaxRetries = 1768017068880  # Unknown = 
    FIntPlaceIdContainerHttpRetryCount = 1768050323408  # Unknown = 
    FIntPlatformEvidenceRolloutPercent = 1768001956368  # Unknown = 
    FIntPlatformLeaderboardPushWaitTimeoutSeconds = 1768132536912  # Unknown = 
    FIntPlayButtonContextualMessageImpressionHundredthsPercent = 1768024514192  # Unknown = 
    FIntPlayWithRewardAdPlaybackAttemptedTelemetryThrottleHundredthsPercent = 1767473191504  # Unknown = 
    FIntPlayWithRewardAdPlaybackStoppedTelemetryThrottleHundredthsPercent = 1767473192336  # Unknown = 
    FIntPlayWithRewardAdReceivedTelemetryThrottleHundredthsPercent = 1767473190288  # Unknown = 
    FIntPlayWithRewardAdRequestedTelemetryThrottleHundredthsPercent = 1767473195024  # Unknown = 
    FIntPlayWithRewardBannerShownTelemetryThrottleHundredthsPercent = 1767473193936  # Unknown = 
    FIntPlayWithRewardBlackoutCurtainTelemetryThrottleHundredthsPercent = 1767473192720  # Unknown = 
    FIntPlayWithRewardButtonClickedTelemetryThrottleHundredthsPercent = 1767473191312  # Unknown = 
    FIntPlayWithRewardCoachmarkMaxImpressions = 1767654034768  # Unknown = 
    FIntPlayWithRewardCoachmarkMaxImpressions2 = 1767654035344  # Unknown = 
    FIntPlayWithRewardCoachmarkTelemetryThrottleHundredthsPercent = 1767648657040  # Unknown = 
    FIntPlayWithRewardCoachmarkWindowDays = 1767654034000  # Unknown = 
    FIntPlayWithRewardFallbackBannerProductImageAssetId = 1767654032336  # Unknown = 
    FIntPlayWithRewardGameJoinInitiatedTelemetryThrottleHundredthsPercent = 1767473191248  # Unknown = 
    FIntPlayWithRewardShimmerShownTelemetryThrottleHundredthsPercent = 1767473195152  # Unknown = 
    FIntPlaytestModeEnabledEventThrottleHundredthsPercent = 1775985125800  # Unknown = 
    FIntPotentialClientTimeoutSeconds = 1768024097488  # Unknown = 
    FIntPresenceEventReceiverErrorEventThrottleHundrethsPercent = 1767650167248  # Unknown = 
    FIntPresenceHttpRetryCount = 1768012245968  # Unknown = 
    FIntPresenceImpressionLoggingThrottlePerMyriad = 1768024530704  # Unknown = 
    FIntPresenceStorePollingTtlSec = 1768012207376  # Unknown = 
    FIntPresenceStoreProcessDelaySec = 1768012222096  # Unknown = 
    FIntPresetChatCooldownLuaMs = 1767641265808  # Unknown = 
    FIntProductPurchaseContainerFPSDuration = 1776067313296  # Unknown = 
    FIntProfileCTAHttpRetryCount = 1768012187920  # Unknown = 
    FIntProfileCTAStoreProcessDelaySec = 1768012232144  # Unknown = 
    FIntProfileInsightsStoreHttpTimeout = 1767648651088  # Unknown = 
    FIntProfilePlatformAnalyticsThrottlingThousandths = 1767650181968  # Unknown = 
    FIntProfilePlatformHttpRetryCount = 1768126137808  # Unknown = 
    FIntProfilePlatformInspectAvatarTooltipMaxImpressions = 1775985079336  # Unknown = 
    FIntProfileQRCodeHttpRetryCount = 1768181186320  # Unknown = 
    FIntProfileShareLinksAnalyticsThrottlingThousandths = 1768181159568  # Unknown = 
    FIntProfileShareLinksHttpRetryCount = 1768181197008  # Unknown = 
    FIntProgressLoadingBarMargin = 1767494458448  # Unknown = 
    FIntProgressLoadingBarMaxWidth = 1767494458320  # Unknown = 
    FIntProgressLoadingDisplayOrder = 1767494458576  # Unknown = 
    FIntProgressLoadingTelemetryThrottleHundredthsPercent = 1767494458704  # Unknown = 
    FIntPromptFriendRequestModalInputDelayMs = 1768017067792  # Unknown = 
    FIntPurchaseVolumePercentage = 1767583800144  # Unknown = 
    FIntPushUpsellChatCooldownPeriod = 1767641316496  # Unknown = 
    FIntPushUpsellChatMaxPromptCount = 1767641316048  # Unknown = 
    FIntPushUpsellCooldownPeriod = 1767641317136  # Unknown = 
    FIntPushUpsellMaxPromptCount = 1767641317264  # Unknown = 
    FIntQuerySuggestionClickedEventThrottlingHundredthsPercent = 1768024519696  # Unknown = 
    FIntRAMaxAnnotationCount = 1775992606992  # Unknown = 
    FIntRAMinEngineVersion = 1768024102864  # Unknown = 
    FIntRTEPresenceStorePollingTtlSec = 1768012205840  # Unknown = 
    FIntRapidGameplayPauseIntervalMs = 1767899820496  # Unknown = 
    FIntRapidGameplayPauseMinNotificationDurationMs = 1767899820816  # Unknown = 
    FIntReactDeletedTreeCleanUpLevel = 1768005271888  # Unknown = 
    FIntReactHighEndMemoryCutoff = 1768393679632  # Unknown = 
    FIntReactLowEndMemoryCutoff = 1768393693904  # Unknown = 
    FIntReactMicroprofilerLevel5 = 1768005289232  # Unknown = 
    FIntReactPerfTrackerKibana = 1767913310096  # Unknown = 
    FIntReactPeriodSummaryEventThrottleHunderedthsPercent = 1768393699280  # Unknown = 
    FIntReactRootSummaryEventThrottleHunderedthsPercent2 = 1768393692816  # Unknown = 
    FIntReactSchedulerDesiredFrameRate = 1768005271440  # Unknown = 
    FIntReactSchedulerMinFrameRate = 1768005280272  # Unknown = 
    FIntReactSchedulerNumberOfLookbackFrames = 1768005254928  # Unknown = 
    FIntReactSchedulerYieldInterval2 = 1768005281296  # Unknown = 
    FIntReactSchedulingKllSketchMaxSize = 1767972975312  # Unknown = 
    FIntReactSchedulingTracker = 1767972992528  # Unknown = 
    FIntReactSchedulingTrackerPeriodMs = 1767972994192  # Unknown = 
    FIntReactSchedulingTrackerStartUpDelayMs = 1767913316240  # Unknown = 
    FIntReactSessionSummaryEventThrottleHunderedthsPercent = 1768393673424  # Unknown = 
    FIntReferredPlayerJoinRemoteEventTimeout = 1767720517520  # Unknown = 
    FIntRelocateMobileMenuButtonsVariant = 1767913664648  # Unknown = 
    FIntRenderCancelSubscriptionAppHttpRetryCount = 1767913302608  # Unknown = 
    FIntReportAnythingAvatarIdentificationCloseDiscardDistanceHundredths = 1768126149584  # Unknown = 
    FIntReportAnythingAvatarIdentificationDiscardFractionSkipThresholdPercent = 1768126149904  # Unknown = 
    FIntReportAnythingAvatarIdentificationOffScreenDiscardDistancePercent = 1768126150224  # Unknown = 
    FIntReportDevConsoleTabEventsThrottleHundredthsPercent = 1768133913168  # Unknown = 
    FIntReportImmersiveBrandedAdHttpFaulreEventThrottleHundredthsPercent = 1768060659024  # Unknown = 
    FIntRequestFriendshipThrottleHundredthsPercent = 1768389367056  # Unknown = 
    FIntRequestRefundClickThrottleHundredthsPercent = 1768024556688  # Unknown = 
    FIntRobloxSubscriptionPurchasePollingTimeoutSeconds = 1767643495376  # Unknown = 
    FIntRobloxSubscriptionUpsellTelemetryEventIngestThrottleHundredthsPercent = 1767643494288  # Unknown = 
    FIntRobuxTransferFlowEventIngestThrottleHundredthsPercent = 1767908755472  # Unknown = 
    FIntRomarkStartWithGraphicQualityLevel = 1767913344336  # Unknown = 
    FIntSafetyBubbleRadius = 1768428737936  # Unknown = 
    FIntSafetyBubbleTransparencyPercent = 1768428746448  # Unknown = 
    FIntScaleBrazilContentRatingBadge = 1767828578000  # Unknown = 
    FIntScheduledSquadJustStartedThreshold = 1768132414288  # Unknown = 
    FIntScriptProfilerLiveUpdateIntervalMS = 1768133906384  # Unknown = 
    FIntScrollDetectorDelayMillis = 1768428758416  # Unknown = 
    FIntScrollDetectorTimeThresholdMillis = 1768428756432  # Unknown = 
    FIntScrollingPerfTrackerEventStream = 1767723045840  # Unknown = 
    FIntScrollingPerfTrackerKibana = 1767723046096  # Unknown = 
    FIntScrollingPerfTrackerSampleCountThreshold = 1767723046416  # Unknown = 
    FIntScrollingPerfTrackerTargetFPS = 1767723046864  # Unknown = 
    FIntScrollingPickerMaximumPickerChangePerInput = 1768387530448  # Unknown = 
    FIntScrollingPickerSlowScrollStepWaitMs = 1768387574096  # Unknown = 
    FIntScrollingPickerSmallInputDecayFactor = 1768387513488  # Unknown = 
    FIntSduiCreateSduiFeedStoreLogDelayMs = 1767648653840  # Unknown = 
    FIntSduiLoadMoreFromApiEventHundredthsPercent = 1767641054928  # Unknown = 
    FIntSduiOmniFeedItemLogDelayMs = 1767648656464  # Unknown = 
    FIntSduiPageRequestPriority = 1767643488912  # Unknown = 
    FIntSduiPageTimerEventHundredthsPercent = 1767641054352  # Unknown = 
    FIntSeamlessVoiceSTUXDisplayCount = 1768001215376  # Unknown = 
    FIntSearchLandingPageSideMargin = 1767650007632  # Unknown = 
    FIntSelfieQrTimeoutSeconds = 1768017062800  # Unknown = 
    FIntSendGameLinkMessageHttpRetryCount = 1768132385744  # Unknown = 
    FIntServeEnhancedVideoErrorTelemetryThrottleHundredthsPercent = 1767908706064  # Unknown = 
    FIntServerTriggeredModalTrafficPercent = 1767650181456  # Unknown = 
    FIntSessionCheckDefaultTimeoutInSeconds = 1767650173712  # Unknown = 
    FIntSetAliasAnalyticsThrottlingThousandths = 1767648625040  # Unknown = 
    FIntSetAliasHttpRetryCount = 1767648626128  # Unknown = 
    FIntSetupNotificationsUpsellHttpRetryCount = 1767641315664  # Unknown = 
    FIntShareGameHttpRetryCount = 1768017066064  # Unknown = 
    FIntShareSheetMaxConversations = 1775910017360  # Unknown = 
    FIntShareSheetNumAvatarSkeletons = 1775910010128  # Unknown = 
    FIntShareSheetSnackbarAutoDismissSeconds = 1775910050704  # Unknown = 
    FIntShareSheetTelemetryThrottleHundredthsPercent = 1775984973848  # Unknown = 
    FIntShopPrefetchRetryBackoffMs = 1768488447176  # Unknown = 
    FIntShouldShowPushUpsellHideResponseCacheExpirationTime = 1767641313872  # Unknown = 
    FIntShowFriendRecommendationsLimit = 1767649998224  # Unknown = 
    FIntSideSheetVariant = 1767828573328  # Unknown = 
    FIntSideSheetVariant2 = 1767828618960  # Unknown = 
    FIntSidesheetClosedEventThrottleHundredthsPercent = 1767998316560  # Unknown = 
    FIntSignUpBirthdayPickerManualSelectVariantOverride = 1767828592528  # Unknown = 
    FIntSignupMinimumAge = 1767720501136  # Unknown = 
    FIntSilentPasskeyUpgradeThrottlingHundredthsPercent = 1768387512784  # Unknown = 
    FIntSilentUpgradeReauthDelaySeconds = 1767650170000  # Unknown = 
    FIntSinglePageSignupMinimumAge = 1767828570512  # Unknown = 
    FIntSkyStyleDayClockTime = 1768027272208  # Unknown = 
    FIntSmallCollectionItemFractionalPercent = 1768024557456  # Unknown = 
    FIntSmallCollectionItemMaxItemCount = 1768024535696  # Unknown = 
    FIntSmallCollectionItemMinItemCount = 1768024513040  # Unknown = 
    FIntSmallCollectionItemMinItemWidth = 1768024517264  # Unknown = 
    FIntSmallCollectionItemVerticalGap = 1768024569168  # Unknown = 
    FIntSnapLevelInVirtualCursor = 1768009989904  # Unknown = 
    FIntSocalCarouselMaxNewRequestsCount = 1768310695504  # Unknown = 
    FIntSocialBlockingModalAnalyticsThrottlingThousandths = 1776083715432  # Unknown = 
    FIntSocialCarouselAnalyticsThrottlingThousandths = 1767641309200  # Unknown = 
    FIntSocialCarouselMaxNewRequestsCount = 1767641311312  # Unknown = 
    FIntSocialCarouselShowRecsLimit = 1767641308112  # Unknown = 
    FIntSocialContextToastDelay = 1767665708960  # Unknown = 
    FIntSocialContextToastHttpRetryCount = 1767908716944  # Unknown = 
    FIntSocialExperienceJoinAnalyticsThrottlingThousandths = 1768024525392  # Unknown = 
    FIntSocialExperienceJoinHttpRetryCount = 1768024560976  # Unknown = 
    FIntSocialGraphSyncRequestRetryCount = 1767650178128  # Unknown = 
    FIntSocialLinkClickTelemetryThrottlePermyriad = 1768024571856  # Unknown = 
    FIntSocialLinksImpressionsEventHundredthsPercent = 1768024522832  # Unknown = 
    FIntSocialStopwatchTelementyThrottleHundrethsPercent = 1776083728552  # Unknown = 
    FIntSocialTabStateHttpRetryCount = 1767650031312  # Unknown = 
    FIntSocialTabsPageHttpRetryCount = 1767648653584  # Unknown = 
    FIntSocialUpsellEventThrottleHunderedthsPercent = 1768296804208  # Unknown = 
    FIntSongDetailsRefreshIntervalSeconds = 1767526034320  # Unknown = 
    FIntSongbirdTelemetryThrottle = 1775971708176  # Unknown = 
    FIntSortDeeplinkFailureEventThrottleHundrethsPercent = 1768024060624  # Unknown = 
    FIntSpatialUIChromeSubMenuHeight = 1767913322256  # Unknown = 
    FIntSpatialUIDarkenBackgroundTransparency = 1767913326544  # Unknown = 
    FIntSpatialUIPanelDistance = 1767913320272  # Unknown = 
    FIntSpatialUIPanelDragBarDistance = 1767913323216  # Unknown = 
    FIntSpatialUIPanelZOffset = 1767913323088  # Unknown = 
    FIntSpatialUIResolutionScale = 1767913322960  # Unknown = 
    FIntSpatialUIVersionTextSizeScaled = 1767913326864  # Unknown = 
    FIntSquadExperienceInvitePollingIntervalSeconds = 1768050319056  # Unknown = 
    FIntSquadExperienceInviteTimeoutSeconds = 1768050319184  # Unknown = 
    FIntSquadHttpRetryCount = 1768024053776  # Unknown = 
    FIntSquadRegroupPromptDebounceTimeMs = 1768050291536  # Unknown = 
    FIntStreamingPauseUIAnalyticsThrottleHP = 1767899821776  # Unknown = 
    FIntSubscriptionPurchaseFlowEventIngestThrottleHundredthsPercent = 1767643495248  # Unknown = 
    FIntSurvBloxRequiredCooldownMs = 1767650165328  # Unknown = 
    FIntSwitchServerTelemetryThrottleHundrethsPercent = 1775985107752  # Unknown = 
    FIntSystemBarHeightMultiplierPercentageOverride = 1767807387216  # Unknown = 
    FIntTTIUnifiedPurchaseSamplingRate = 1767831089168  # Unknown = 
    FIntTalkingChangedDebounceTime = 1767645286096  # Unknown = 
    FIntTeleportBackAttemptLimit = 1768428783248  # Unknown = 
    FIntTeleportBackRetryDelay = 1768428788752  # Unknown = 
    FIntTenFootSkyboxBlockerPositionX = 1767473198352  # Unknown = 
    FIntTenFootSkyboxBlockerPositionY = 1767473199440  # Unknown = 
    FIntTenFootSkyboxBlockerPositionZ = 1767473200080  # Unknown = 
    FIntTenFootSkyboxBlockerSizeX = 1767473197008  # Unknown = 
    FIntTenFootSkyboxBlockerSizeY = 1767473197520  # Unknown = 
    FIntTenFootSkyboxBlockerSizeZ = 1767473197648  # Unknown = 
    FIntThrottleParticipantsUpdateMs2 = 1767645293584  # Unknown = 
    FIntTilePlacedTelemetryThrottleHundredthsPercent = 1768428794064  # Unknown = 
    FIntTileSkippedTelemetryThrottleHundredthsPercent = 1768428794640  # Unknown = 
    FIntTimeToInteractiveTrackerSampleRate = 1767638309328  # Unknown = 
    FIntTooltipHitboxMinSize = 1768393704976  # Unknown = 
    FIntTraversalTelemetryThrottleHundrethsPercent = 1768389380304  # Unknown = 
    FIntTrustedConnectionsStoreDataTtlSec = 1768012198736  # Unknown = 
    FIntTrustedConnectionsStoreIncomingRequestsProcessDelaySec = 1768012231568  # Unknown = 
    FIntTrustedConnectionsStoreProcessDelaySec = 1768012218960  # Unknown = 
    FIntTrustedContactsHttpRetryCount = 1768012197648  # Unknown = 
    FIntTrustedFriendRequestsPageSize = 1767583388560  # Unknown = 
    FIntUIResetDelayInSec = 1768244634192  # Unknown = 
    FIntUSER_VOTE_CACHE_TTL_SECONDS = 1768012194064  # Unknown = 
    FIntUXForCameraPerformanceDeviceDelay = 1767899840784  # Unknown = 
    FIntUXForCameraPerformanceSessionDelay = 1767899842000  # Unknown = 
    FIntUiShellOrientationChangedThrottleHundredthsPercent = 1768017191888  # Unknown = 
    FIntUnauthorizedErrorThrottlingHundredthsPercent = 1768387575504  # Unknown = 
    FIntUnblockUserThrottleHundredthsPercent = 1768389379664  # Unknown = 
    FIntUnblockUserThrottleHundredthsPercent4 = 1768389373328  # Unknown = 
    FIntUnfilteredMessageTransparencyHundredths = 1767911146976  # Unknown = 
    FIntUnfilteredThreadsPvDelayMs = 1767926754280  # Unknown = 
    FIntUnifiedPurchaseTelemetryEventIngestThrottleHundredthsPercent = 1776067316304  # Unknown = 
    FIntUniversalAppPolicyFailureTelemetryThrottleHundredthsPercent = 1768060678800  # Unknown = 
    FIntUnmuteAllThrottleHundredthsPercent = 1768389379536  # Unknown = 
    FIntUnmutePlayerThrottleHundredthsPercent = 1768389383888  # Unknown = 
    FIntUnmuteSelfThrottleHundredthsPercent = 1768389377552  # Unknown = 
    FIntUnmuteSelfThrottleHundredthsPercent4 = 1767862353968  # Unknown = 
    FIntUnpublishedPlaytestModeTooltipDisplayLimit = 1767828577104  # Unknown = 
    FIntUpVectorOrentationThreshold1 = 1776125405072  # Unknown = 
    FIntUpsellAccountBalanceRetryAttemps = 1776067297296  # Unknown = 
    FIntUpsellAccountBalanceRetryIntervalSec = 1776067305040  # Unknown = 
    FIntUpsellSuggestionsAPIMaxPackagesV3 = 1767828617360  # Unknown = 
    FIntUseAssetFavoritingHttpRetryCount = 1775971680976  # Unknown = 
    FIntUserProfileDefaultRetryCount = 1768001203472  # Unknown = 
    FIntUserProfileStoreBatchSize = 1768001233360  # Unknown = 
    FIntUserProfileStoreHttpTimeout = 1768001237072  # Unknown = 
    FIntUserProfileStoreQueueProcessDelay = 1768001200144  # Unknown = 
    FIntUserProfilesDataLoaderClearTime_v1 = 1768150384912  # Unknown = 
    FIntUserRelationshipModalsAnalyticsThrottlingThousandths = 1768017066512  # Unknown = 
    FIntUserSearchHttpRetryCount = 1767648648592  # Unknown = 
    FIntUserSeenCollectionBatchTimeMs = 1767526022480  # Unknown = 
    FIntV1MenuLanguageSelectionFeaturePerMillageRollout = 1767913345936  # Unknown = 
    FIntVRAvatarGesturesAnalyticsThrottleHundrethsPercent = 1767899816400  # Unknown = 
    FIntVRBottomBarPositionOffsetDepthNumber = 1767913639560  # Unknown = 
    FIntVRBottomBarPositionOffsetVerticalNumber = 1767913639688  # Unknown = 
    FIntVREnvironmentSettingDarkClockTime = 1768027284880  # Unknown = 
    FIntVREnvironmentSettingLightClockTime = 1768027273424  # Unknown = 
    FIntVRScaleGuiDistance = 1768162825168  # Unknown = 
    FIntVRTouchControllerTransparency = 1768428776656  # Unknown = 
    FIntValidCookieForNoCachedUserThrottlingHundredthsPercent = 1768387558160  # Unknown = 
    FIntVideoBlockingTelemetryThrottleHundredthsPercent = 1768428741200  # Unknown = 
    FIntVideoEngagementEventHundredthsPercent = 1768389386320  # Unknown = 
    FIntVideoPlaybackDetectorScanDebounceInMilliseconds = 1767526023760  # Unknown = 
    FIntVideoPlayerPlaybackEndThresholdInMs = 1768389360144  # Unknown = 
    FIntVirtualEventsHttpRetryCount = 1767473196176  # Unknown = 
    FIntVoiceCapturedDuringVideoCaptureThrottlingPercentage = 1767645296464  # Unknown = 
    FIntVoiceChatDeviceChangeDebounceDelay = 1767913344656  # Unknown = 
    FIntVoiceChatTooltipDelay = 1767998350672  # Unknown = 
    FIntVoiceJoinM3ToastDurationSeconds = 1767998348176  # Unknown = 
    FIntVoiceReverseNudgeUXDisplayTimeSeconds = 1767900713640  # Unknown = 
    FIntVoiceToxicityToastDurationSeconds = 1767998357072  # Unknown = 
    FIntVoiceUsersInteractionExpiryTimeSeconds = 1767645291280  # Unknown = 
    FIntVrAppPanelCurvatureOverride = 1768027315984  # Unknown = 
    FIntVrAppPanelWidthMultiplierPercentageOverride = 1768027263056  # Unknown = 
    FIntVrAvatarPanelsSpreadMultiplierPercentageOverride = 1767473175888  # Unknown = 
    FIntWaitAfterCloseChallengeWebViewSeconds = 1767643518928  # Unknown = 
    FIntWaitForChildOfClassTimeout = 1768132418000  # Unknown = 
    FIntWebViewLastClosedDurationSeconds = 1767650176656  # Unknown = 
    FIntWebViewOpenDurationCapSeconds = 1767650176208  # Unknown = 
    FIntWidgetListInitialNumToRender = 1767641053904  # Unknown = 
    FIntWidgetListWindowSize = 1767641053712  # Unknown = 
    FIntWidgetPaddingSizing = 1767643490384  # Unknown = 
    FIntXLargeCollectionItemFractionalPercent = 1768024521680  # Unknown = 
    FIntXLargeCollectionItemMaxItemCount = 1768024545680  # Unknown = 
    FIntXLargeCollectionItemMinItemCount = 1768024515152  # Unknown = 
    FIntXLargeCollectionItemMinItemWidth = 1768024538704  # Unknown = 
    FIntXLargeCollectionItemVerticalGap = 1768024559632  # Unknown = 
    FIntXSmallCollectionItemFractionalPercent = 1768024565008  # Unknown = 
    FIntXSmallCollectionItemMaxItemCount = 1768024507344  # Unknown = 
    FIntXSmallCollectionItemMinItemCount = 1768024524176  # Unknown = 
    FIntXSmallCollectionItemMinItemWidth = 1768024553040  # Unknown = 
    FIntXSmallCollectionItemVerticalGap = 1768024542672  # Unknown = 
    FStringAEGIS2AppChatAgeVerifiedRealtimeNamespace = 1767583400528  # Unknown = 
    FStringAXAvatarWidgetContentType = 1767654050064  # Unknown = 
    FStringAXBackendDrivenCatalogLayersFString = 1768393705360  # Unknown = 
    FStringAXBackendDrivenCatalogLayersNames = 1768399108816  # Unknown = 
    FStringAXBackgroundGenerationCanvasAssetIdDark = 1767640157200  # Unknown = 
    FStringAXBackgroundGenerationCanvasAssetIdLight = 1767900747520  # Unknown = 
    FStringAXBodyCategoryTooltipKey = 1767650030160  # Unknown = 
    FStringAXCategories = 1767650026640  # Unknown = 
    FStringAXCombineGetOutfitDispatchesIXPLayer3 = 1767650022608  # Unknown = 
    FStringAXCycloramaFallbackAssetId = 1768399091184  # Unknown = 
    FStringAXDefaultAvatarToShopLayer3 = 1767654060432  # Unknown = 
    FStringAXDurablesSupportExposureLayer = 1767977061904  # Unknown = 
    FStringAXFetchCartPricingDuringInExperienceLayerName = 1767828599952  # Unknown = 
    FStringAXInspectAndBuyLayerName = 1767901859920  # Unknown = 
    FStringAXItemDetails3DPreviewIXPLayer = 1767650022160  # Unknown = 
    FStringAXLookWidgetContentType = 1767654051088  # Unknown = 
    FStringAXPlusExclusiveBackgroundIds = 1767640169232  # Unknown = 
    FStringAXRecommendedItemsExposureLayer = 1767640159120  # Unknown = 
    FStringAXSlotBasedEditorCategoryTooltipKey = 1767650018256  # Unknown = 
    FStringAXSlotsDesignUpdatesExposureLayer = 1767977079760  # Unknown = 
    FStringAXSortsBodyTabRecLayerName = 1767640168720  # Unknown = 
    FStringAXTallBundleWidgetContentType = 1767654049872  # Unknown = 
    FStringAXTaxonomyM20ExperimentLayerName = 1767900768160  # Unknown = 
    FStringAXTaxonomyM21ExperimentLayerName = 1767640170384  # Unknown = 
    FStringAXTooltipAllowedTooltips = 1767899193360  # Unknown = 
    FStringAccountRecoveryUILayer = 1767978542288  # Unknown = 
    FStringAccountSwitcherLayer = 1767978515408  # Unknown = 
    FStringAdDropdownButtonDefault = 1767908704976  # Unknown = 
    FStringAdDropdownButtonOpen = 1767908705296  # Unknown = 
    FStringAdGuiCloseButtonImageLua = 1768060674768  # Unknown = 
    FStringAdGuiLivePreviewWatermark = 1768060675536  # Unknown = 
    FStringAdGuiLivePreviewWatermarkV2 = 1768060677008  # Unknown = 
    FStringAdGuiPauseButtonImageLua = 1768060674320  # Unknown = 
    FStringAdGuiPlayButtonImageLua = 1768060674000  # Unknown = 
    FStringAdPlayerExitButton = 1767665954752  # Unknown = 
    FStringAdsEnterFullscreenImageLua = 1768060669392  # Unknown = 
    FStringAdsEudsaPromptActiveImageLua = 1768060649296  # Unknown = 
    FStringAdsEudsaPromptInactiveImageLua = 1768060672592  # Unknown = 
    FStringAdsExitFullscreenImageLua = 1768060667216  # Unknown = 
    FStringAdsVolumeOffImageLua = 1768060668048  # Unknown = 
    FStringAdsVolumeOnImageLua = 1768060668496  # Unknown = 
    FStringAgeCheckAmpNameSpace = 1768054603792  # Unknown = 
    FStringAllFriendsCarouselLoadingTimeDoneStats = 1767649998800  # Unknown = 
    FStringAllFriendsCarouselLoadingTimeFailedStats = 1767649999696  # Unknown = 
    FStringAllFriendsNextPageCarouselLoadingTimeDoneStats = 1767650000528  # Unknown = 
    FStringAllFriendsNextPageCarouselLoadingTimeFailedStats = 1767650000272  # Unknown = 
    FStringAndroidPhoneVerificationLayer = 1768027274704  # Unknown = 
    FStringApisCdnUrl = 1767650169488  # Unknown = 
    FStringAppBadgingLayer = 1767978500816  # Unknown = 
    FStringAppChatClosedCounter = 1768017045456  # Unknown = 
    FStringAppChatConversationPageSyntheticSystemMessageIxpLayer = 1768132413072  # Unknown = 
    FStringAppChatEnableRepliesUIIxpLayer1 = 1768132432912  # Unknown = 
    FStringAppChatFixRootChatBackNavigationIxpLayer = 1767641274640  # Unknown = 
    FStringAppChatGroupOsaViewDetailsUrl = 1767641273040  # Unknown = 
    FStringAppChatInExperienceIXPLayer = 1767583427024  # Unknown = 
    FStringAppChatNewChatInputBarIxpLayer = 1768132393936  # Unknown = 
    FStringAppChatPerfExperimentLayer = 1768399057744  # Unknown = 
    FStringAppChatRemoveConversationListDividerIxpLayer = 1767641306384  # Unknown = 
    FStringAppChatSessionName = 1768017072528  # Unknown = 
    FStringAppChatSquadButtonColorUpdateIxpLayer = 1768132406544  # Unknown = 
    FStringAppChatTcLearnMoreUrl = 1767911147216  # Unknown = 
    FStringAppChatTimestampInSubtitleIxpLayer = 1767641309648  # Unknown = 
    FStringAppChatVisibleCounter = 1768017061008  # Unknown = 
    FStringArgoPartyLayer = 1767645301840  # Unknown = 
    FStringArgoPartyVariant = 1767645301968  # Unknown = 
    FStringArgusApiUrlBase = 1768328480152  # Unknown = 
    FStringArgusEntryTypeKey = 1776085432848  # Unknown = 
    FStringArgusExperimentLayer = 1776085398672  # Unknown = 
    FStringArgusInfluencerUploadsKey = 1776085416272  # Unknown = 
    FStringArgusPlatformIntegrationKey = 1776085405648  # Unknown = 
    FStringAuthenticationErrorCode = 1767526242960  # Unknown = 
    FStringAuthenticationErrorCodeAlternative = 1768133863504  # Unknown = 
    FStringAvatarSwitcherIXPLayer = 1767707990376  # Unknown = 
    FStringAvatarSwitcherTooltipStorageKey = 1768113124048  # Unknown = 
    FStringBacktraceLogTags = 1767640185104  # Unknown = 
    FStringBillboardUpdateFrequencyIXPLayerValue = 1768399829776  # Unknown = 
    FStringBiometricPrivacyPolicyLink = 1767648606224  # Unknown = 
    FStringBlackbirdUpsellHiddenRequestTypes2 = 1767897039184  # Unknown = 
    FStringBlackbirdUrl = 1768027281040  # Unknown = 
    FStringBlackbirdWebviewHeaderName = 1767427317648  # Unknown = 
    FStringBuildExperienceProductionTemplatePlaceId = 1768139818320  # Unknown = 
    FStringCameraUnavailableUrl = 1767899846160  # Unknown = 
    FStringCanAccessTrustedContactsAmpFeature = 1768133829584  # Unknown = 
    FStringCanAccessTrustedContactsAmpNameSpace = 1768133853264  # Unknown = 
    FStringCapturesActivatedInGameMenu = 1768126139152  # Unknown = 
    FStringCapturesCarouselOpened = 1768126139728  # Unknown = 
    FStringCapturesDeactivatedInGameMenu = 1768126117008  # Unknown = 
    FStringCapturesEntrypointActivated = 1768126139536  # Unknown = 
    FStringCapturesIXPLayer = 1767583425680  # Unknown = 
    FStringCapturesPageOpenedInGameMenu = 1768126137936  # Unknown = 
    FStringCapturesShareToastButtonActivated = 1768126138896  # Unknown = 
    FStringCapturesTabIXPLayer = 1768027264080  # Unknown = 
    FStringChatAddFriendsBtnClickedCounter = 1768017054032  # Unknown = 
    FStringChatDetailsAddFriendsBtnClickedCounter = 1768017085904  # Unknown = 
    FStringChatDetailsCreateUnfilteredChatCellClickedCounter = 1768017089232  # Unknown = 
    FStringChatDetailsCreateUnfilteredChatCellRenderedCounter = 1768017053840  # Unknown = 
    FStringChatDetailsLeaveGroupBtnClickedCounter = 1768017083152  # Unknown = 
    FStringChatDetailsLeaveGroupDialogLeaveClickedCounter = 1768017045968  # Unknown = 
    FStringChatDetailsLeaveGroupDialogRenderedCounter = 1768017056528  # Unknown = 
    FStringChatDetailsLeaveGroupDialogStayClickedCounter = 1768017057488  # Unknown = 
    FStringChatDetailsRenderedCounter = 1768017062160  # Unknown = 
    FStringChatDetailsReportUserClickedCounter = 1768017096976  # Unknown = 
    FStringChatEmptyStateScreenRenderedCounter = 1768017070800  # Unknown = 
    FStringChatInputBarReplyComposeCancelBtnActivatedCounter = 1768017061776  # Unknown = 
    FStringChatInputBarReplyComposeRenderedCounter = 1768017071824  # Unknown = 
    FStringChatLandingComposeBtnClickedCounter = 1768017086928  # Unknown = 
    FStringChatLandingConversationClickedCounter = 1768017096912  # Unknown = 
    FStringChatLandingGroupsBtnClicked = 1768017055824  # Unknown = 
    FStringChatLandingNotifBtnClickedCounter = 1768017035600  # Unknown = 
    FStringChatLandingPvUpsellContinueClickedCounter = 1768017054288  # Unknown = 
    FStringChatLandingPvUpsellDismissedCounter = 1768017047504  # Unknown = 
    FStringChatLandingPvUpsellFailedCounter = 1768017040208  # Unknown = 
    FStringChatLandingPvUpsellRenderedCounter = 1768017039824  # Unknown = 
    FStringChatLandingPvUpsellSucceededCounter = 1768017040272  # Unknown = 
    FStringChatLandingScreenRenderedCounter = 1768017059408  # Unknown = 
    FStringChatLandingSearchBtnClickedCounter = 1768017086800  # Unknown = 
    FStringChatLandingUnfilteredThreadsFtuxDismissedCounter = 1768017061968  # Unknown = 
    FStringChatLandingUnfilteredThreadsFtuxLearnMoreClickedCounter = 1768017090832  # Unknown = 
    FStringChatLandingUnfilteredThreadsFtuxRenderedCounter = 1768017044816  # Unknown = 
    FStringChatLineReportingSubmittedAbuseTypeStat = 1768001179792  # Unknown = 
    FStringChatLineReportingTimeSpentStat = 1768001189712  # Unknown = 
    FStringChatMessageLongPressedCounter = 1768017057232  # Unknown = 
    FStringChatMessageMenuCopyBtnActivatedCounter = 1768017065744  # Unknown = 
    FStringChatMessageMenuOpenedCounter = 1768017098896  # Unknown = 
    FStringChatMessageMenuReplyBtnActivatedCounter = 1768017099344  # Unknown = 
    FStringChatMessageOpenMenuIconClickedCounter = 1768017046032  # Unknown = 
    FStringChatMessagePressedCounter = 1768017056272  # Unknown = 
    FStringChatMessageReplyIconClickedCounter = 1768017093008  # Unknown = 
    FStringChatTranslationEnabledLocales = 1767913342864  # Unknown = 
    FStringChatTranslationLayerName = 1767831045008  # Unknown = 
    FStringClientToastNotificationsRedirectLayerName = 1768133931536  # Unknown = 
    FStringClientToastNotificationsRedirectLayerValue = 1768133931920  # Unknown = 
    FStringCloseContactListButtonCounter = 1768165327272  # Unknown = 
    FStringCloseContactListCrossCounter = 1768181193232  # Unknown = 
    FStringCommsFAEFeatureName = 1767650002512  # Unknown = 
    FStringCommsFAENamespace = 1767650002320  # Unknown = 
    FStringConnectionGraphCoreAmpNameSpace = 1768009996240  # Unknown = 
    FStringConsoleSignUpLayer = 1767978536592  # Unknown = 
    FStringConsoleVoiceEnabledIXPLayerValue = 1767645287312  # Unknown = 
    FStringConsoleVoiceIXPLayerName = 1767645288784  # Unknown = 
    FStringConsumerPlatformsIOSUIRefactor = 1767978526032  # Unknown = 
    FStringContactImportGreenFindFriendsButtonExperimentVariable = 1768181180432  # Unknown = 
    FStringContactImportLayer = 1768181181200  # Unknown = 
    FStringContactImportModalAddFriendsCounter = 1768181199248  # Unknown = 
    FStringContactImportModalCloseCounter = 1768181174864  # Unknown = 
    FStringContactImportModalContinueCounter = 1768181182736  # Unknown = 
    FStringContactImportModalPageLoadCounter = 1768181180752  # Unknown = 
    FStringContactImportRemoveCloseButtonExperimentVariable = 1768181174224  # Unknown = 
    FStringContactImporterFindFriendsUrl = 1767802884512  # Unknown = 
    FStringContactImporterInviteContactCounter = 1768181202320  # Unknown = 
    FStringContactImporterRequestFriendshipCounter = 1768181186128  # Unknown = 
    FStringContactImportingTimeStat = 1768181200592  # Unknown = 
    FStringContactsListEmojiSortingIxpLayer = 1768181167504  # Unknown = 
    FStringContactsListLoadedCounter = 1768181192016  # Unknown = 
    FStringConversationIneligibleModalLearnMoreClickedCounter = 1768017094608  # Unknown = 
    FStringConversationIneligibleModalLeftGroupCounter = 1768017040400  # Unknown = 
    FStringConversationIneligibleModalRenderedCounter = 1768017058832  # Unknown = 
    FStringConversationInfoBtnClickedCounter = 1768017043856  # Unknown = 
    FStringConversationLearnMoreBannerActionClickedCounter = 1768017060816  # Unknown = 
    FStringConversationLearnMoreBannerRenderedCounter = 1768017057424  # Unknown = 
    FStringConversationLearnMoreDialogDismissedCounter = 1768017053008  # Unknown = 
    FStringConversationLearnMoreDialogRenderedCounter = 1768017069520  # Unknown = 
    FStringConversationMessageSentCounter = 1768017062928  # Unknown = 
    FStringConversationPvBannerActionClickedCounter = 1768017099088  # Unknown = 
    FStringConversationPvBannerRenderedCounter = 1768017086224  # Unknown = 
    FStringConversationPvDialogActionClickedCounter = 1768017042640  # Unknown = 
    FStringConversationPvDialogDismissedCounter = 1768017039184  # Unknown = 
    FStringConversationPvDialogFailedCounter = 1768017043536  # Unknown = 
    FStringConversationPvDialogRenderedCounter = 1768017048656  # Unknown = 
    FStringConversationPvDialogSucceededCounter = 1768017048976  # Unknown = 
    FStringConversationPvUpsellContinueClickedCounter = 1768017042768  # Unknown = 
    FStringConversationPvUpsellFailedCounter = 1768017052112  # Unknown = 
    FStringConversationPvUpsellLeftGroupCounter = 1768017064848  # Unknown = 
    FStringConversationPvUpsellRenderedCounter = 1768017043920  # Unknown = 
    FStringConversationPvUpsellSucceededCounter = 1768017041616  # Unknown = 
    FStringConversationScreenExitCounter = 1768017046352  # Unknown = 
    FStringConversationScreenRenderedCounter = 1768017099984  # Unknown = 
    FStringConversationSendBtnClickedCounter = 1768017091088  # Unknown = 
    FStringConversationUpgradeBannerActionClickedCounter = 1768017098256  # Unknown = 
    FStringConversationUpgradeBannerRenderedCounter = 1768017049936  # Unknown = 
    FStringConversationUpgradeDialogActionClickedCounter = 1768017082448  # Unknown = 
    FStringConversationUpgradeDialogDismissedCounter = 1768017041232  # Unknown = 
    FStringConversationUpgradeDialogRenderedCounter = 1768017096656  # Unknown = 
    FStringCoreContentAmpNameSpace = 1768054611984  # Unknown = 
    FStringCoreScriptBacktraceErrorUploadToken = 1768005302096  # Unknown = 
    FStringCountriesWithGenericIllegalContentReporting2 = 1767977091472  # Unknown = 
    FStringCountriesWithTakeItDownReport = 1767977061712  # Unknown = 
    FStringCrossExpEventLoggingLevel = 1767628077648  # Unknown = 
    FStringCrossExpVoiceIXPLayer = 1767473189200  # Unknown = 
    FStringCrossExpVoicePlaceId = 1767473189456  # Unknown = 
    FStringCustomizeNameClearedInput = 1767648625424  # Unknown = 
    FStringCustomizeNameMaximumCharLimitTyped = 1767648629136  # Unknown = 
    FStringCustomizeNameModalClosed = 1767648629712  # Unknown = 
    FStringCustomizeNameModalOpened = 1767648628560  # Unknown = 
    FStringCustomizeNameSaveAttemptInvalidInput = 1767648630288  # Unknown = 
    FStringCustomizeNameSaved = 1767648629840  # Unknown = 
    FStringDSAReportingAndTransparencyOverrideUserIds = 1767977096784  # Unknown = 
    FStringDebugCrossExpVoiceIXPLayer = 1767473188944  # Unknown = 
    FStringDebugDefaultPageOverride = 1767650012880  # Unknown = 
    FStringDebugFriendsChatConversationId = 1768028352144  # Unknown = 
    FStringDebugHomePageUpsellCardVariationResponseBody = 1767649997264  # Unknown = 
    FStringDebugLogTags = 1767640185552  # Unknown = 
    FStringDebugLuaLogLevel = 1767831101264  # Unknown = 
    FStringDebugLuaLogPattern = 1767831101072  # Unknown = 
    FStringDebugOverrideCrossPlayApiUrl = 1767473195856  # Unknown = 
    FStringDebugOverrideCrossPlayQueryParam = 1768297279376  # Unknown = 
    FStringDebugOverrideCrossPlaySettingsKey = 1768297304976  # Unknown = 
    FStringDebugOverrideCrossPlayUri = 1768297278096  # Unknown = 
    FStringDefaultSkyStyle = 1768027266448  # Unknown = 
    FStringDefaultVREnvironmentSetting = 1768027320848  # Unknown = 
    FStringDesktopUpsellIXPLayer = 1768125833744  # Unknown = 
    FStringDisableAutocorrectExperimentLayer = 1768297327824  # Unknown = 
    FStringDisableCameraOnLowSpecDevicesIXPField = 1767913329936  # Unknown = 
    FStringDisableCameraOnLowSpecDevicesIXPLayer = 1767913331216  # Unknown = 
    FStringDiscoverabilityModalCloseCounter = 1768181149008  # Unknown = 
    FStringDiscoverabilityModalContinueCounter = 1768181190672  # Unknown = 
    FStringDiscoverabilityModalLoadCounter = 1768181168592  # Unknown = 
    FStringDiscoverabilityModalRadioButtonClickCounter = 1776083678952  # Unknown = 
    FStringDiscoverabilityUpsellNonPrefillDiscoverableUserIdsWhitelist = 1768181171280  # Unknown = 
    FStringDisruptiveVoiceNudgeVariantIXPLayerName = 1768001211728  # Unknown = 
    FStringDisruptiveVoiceNudgeVariantIXPVariableName = 1768001212176  # Unknown = 
    FStringDummyAMPWizardAccessResponse = 1767900717152  # Unknown = 
    FStringDummyAMPWizardActionsTakenJSON = 1767648608016  # Unknown = 
    FStringEARReportMenuIXPLayer = 1768027267344  # Unknown = 
    FStringEditProfileExperimentKey = 1767654044240  # Unknown = 
    FStringEdpPlayerFeedbackServiceRoute = 1767828560912  # Unknown = 
    FStringEligibleForFacialAgeEstimationAmpFeature = 1768054595664  # Unknown = 
    FStringEligibleToAgeVerifyAmpFeature = 1768054622608  # Unknown = 
    FStringEmoteUtilityFallbackKeyframeSequenceAssetId = 1776125392208  # Unknown = 
    FStringExitModalIXPLayer = 1768132563472  # Unknown = 
    FStringExpChatChatWithTFAmpFeatureName = 1768389376976  # Unknown = 
    FStringExpChatChatWithTFAmpNameSpace = 1768389366608  # Unknown = 
    FStringExpChatCrossAgeChatActivityIXPLayerName = 1768038222480  # Unknown = 
    FStringExpChatCrossAgeChatActivityIXPLayerValue = 1768038223248  # Unknown = 
    FStringExpChatDictationIXPLayerName = 1768112858960  # Unknown = 
    FStringExpChatFOMOUpsellIXPLayerName = 1768038221136  # Unknown = 
    FStringExpChatFOMOUpsellIXPLayerValue = 1768038221648  # Unknown = 
    FStringExpChatLocalChatEnabledMessageExperimentLayer = 1767645298320  # Unknown = 
    FStringExpChatLocalChatEnabledMessageForcedKey = 1767645299408  # Unknown = 
    FStringExpChatLocalChatEnabledMessageVariable = 1768164768968  # Unknown = 
    FStringExpChatNewSystemMessagesExperimentLayer = 1767645301264  # Unknown = 
    FStringExpChatNewSystemMessagesVariant = 1767645300304  # Unknown = 
    FStringExpChatPresetAutocompleteIxpLayer = 1768112860368  # Unknown = 
    FStringExpChatPresetChatBadgeFTUXExperimentLayer = 1767645300048  # Unknown = 
    FStringExpChatPresetChatBadgeFTUXVariable = 1767645300496  # Unknown = 
    FStringExpChatPresetChatIXPLayerName = 1768112857936  # Unknown = 
    FStringExpChatRewriteInlineIxpLayer = 1768001189456  # Unknown = 
    FStringExpChatSummaryPrefixText = 1768024548560  # Unknown = 
    FStringExperienceDetailsLayer = 1767583531664  # Unknown = 
    FStringExperienceMenuGamepadExposureLayer = 1767978518480  # Unknown = 
    FStringExperienceReactDeferredScheduler_LayerName = 1767828574736  # Unknown = 
    FStringFAEUpsellDeviceNamePipeDenyList = 1767645312400  # Unknown = 
    FStringFAEUpsellSystemVersionPipeDenyList = 1768126127568  # Unknown = 
    FStringFRRToastPositionVariantKey = 1768024049616  # Unknown = 
    FStringFStringBlackbirdWebviewHeaderName = 1768492083872  # Unknown = 
    FStringFStringEditProfileToAvatarLayerName = 1767654044880  # Unknown = 
    FStringFStringLuckyRecommendationExpLayer = 1767645309072  # Unknown = 
    FStringFStringPartyPageCarouselExpLayer = 1767645307408  # Unknown = 
    FStringFStringQueueExpLayer = 1767645300944  # Unknown = 
    FStringFStringSquadRegroupExpLayer = 1767645310608  # Unknown = 
    FStringFStringTimeoutLoadingLocalPlayerInBackgroundDM = 1768133854416  # Unknown = 
    FStringFailedFindContactsCounter = 1768181162000  # Unknown = 
    FStringFailedFormatContactsFromDeviceCounter = 1768181187344  # Unknown = 
    FStringFailedGetContactEntitiesCounter = 1768181137872  # Unknown = 
    FStringFailedGetContactsFromDeviceCounter = 1768179252560  # Unknown = 
    FStringFailedUploadContactsFromDeviceCounter = 1768181198800  # Unknown = 
    FStringFindFriendsButtonClickedCounter = 1768181194448  # Unknown = 
    FStringFlyoutIxpLayer = 1767989428624  # Unknown = 
    FStringFlyoutIxpVariantKey = 1767989417744  # Unknown = 
    FStringFlyoutLearnPlaceURI = 1775910042768  # Unknown = 
    FStringFlyoutMomentsPlaceURI = 1775910052816  # Unknown = 
    FStringFoundationImagesWhitelistedIconAssets = 1767860849040  # Unknown = 
    FStringFriendRequestModalIxpLayer = 1768017068688  # Unknown = 
    FStringFriendRequestNicknamesCanSendNicknames = 1767648615824  # Unknown = 
    FStringFriendRequestNicknamesSocialFriendsLayer = 1767648615952  # Unknown = 
    FStringFriendsCarouselLoadedWithUsers = 1767650002000  # Unknown = 
    FStringFriendsCarouselRequestFriendship = 1767650003664  # Unknown = 
    FStringFriendsCarouselRevokeFriendRequest = 1767650004816  # Unknown = 
    FStringFriendsCarouselUILoadingTimeStats = 1767650000080  # Unknown = 
    FStringFriendsCarouselUserPressed = 1767650002704  # Unknown = 
    FStringFriendsChatTabName = 1768005302736  # Unknown = 
    FStringFriendshipNotifsUseSendrLayerName = 1768024110544  # Unknown = 
    FStringFriendshipNotifsUseSendrLayerValue = 1768133934096  # Unknown = 
    FStringGenericAbuseReportingSubmittedAbuseTypeStat = 1767977079632  # Unknown = 
    FStringGenericAbuseReportingTimeSpentStat = 1767977110672  # Unknown = 
    FStringGenericReportLink = 1767977114064  # Unknown = 
    FStringGetFStringIXPLayerMobileUpsell = 1768125839696  # Unknown = 
    FStringHelpPageIXPLayer = 1768438434320  # Unknown = 
    FStringHelpPageIxpLayer = 1768126100688  # Unknown = 
    FStringHighlightModePreciseSelectionForceVariant = 1767583570384  # Unknown = 
    FStringHighlightModePreciseSelectionIXPField = 1767583569680  # Unknown = 
    FStringHomePageNavigationViewAddFriends = 1767650001168  # Unknown = 
    FStringHomePageNavigationViewAllFriends = 1767650003152  # Unknown = 
    FStringIOSPhoneVerificationLayer = 1768027273928  # Unknown = 
    FStringIXPLayerMobileUpsell = 1776050430288  # Unknown = 
    FStringImmersiveBrandedAdsLearnMoreUrl = 1768060650704  # Unknown = 
    FStringInExpChatRewriteDeviceNameBlackList = 1767860825232  # Unknown = 
    FStringInExpChatRewriteLabelKey = 1768001202704  # Unknown = 
    FStringInExpChatRewriteOsVersionBlackList = 1767860812752  # Unknown = 
    FStringInExpChatRewriteReasonKey = 1768001183696  # Unknown = 
    FStringInExperienceMenuIXPLayer = 1768132559184  # Unknown = 
    FStringInExperienceMenuIXPVar = 1768132563920  # Unknown = 
    FStringInExperienceNotificationsLayer = 1768005299984  # Unknown = 
    FStringInExperienceShopTooltipStorageKey = 1768113162640  # Unknown = 
    FStringInGameAssetReportingSubmittedAbuseTypeStat = 1768377280976  # Unknown = 
    FStringInGameAssetReportingTimeSpentStat = 1768377280144  # Unknown = 
    FStringInGameLargerRobuxUpsellIXPLayerParam = 1776067336208  # Unknown = 
    FStringInGameRobuxUpsellLargerIxpLayer = 1768027259720  # Unknown = 
    FStringIncompatibleAccountsSupportLink = 1768387540496  # Unknown = 
    FStringInspectAndBuyFeature = 1767899792784  # Unknown = 
    FStringInternationalNamesIXPExperimentDefinition = 1767654043984  # Unknown = 
    FStringInternationalNamesIXPLayer = 1767654042384  # Unknown = 
    FStringIsUserInTcEligibleCountryAmpFeature = 1768133843856  # Unknown = 
    FStringIsVerified18PlusAmpFeature = 1768054600912  # Unknown = 
    FStringLivePreviewPlaceId = 1768060677648  # Unknown = 
    FStringLoginInfoOverflowedCounter = 1767654039824  # Unknown = 
    FStringLuaAppAdPreferencesUrl = 1768009961552  # Unknown = 
    FStringLuaAppAdsPlayWithRewardBetaAndroidLayer = 1767978501392  # Unknown = 
    FStringLuaAppAuthenticationStylingLayer = 1767978526288  # Unknown = 
    FStringLuaAppBacktraceLogLevel = 1767640183632  # Unknown = 
    FStringLuaAppBadgeDetailsIxpLayer = 1767525983248  # Unknown = 
    FStringLuaAppBadgesSeeAllIxpLayer = 1767525982480  # Unknown = 
    FStringLuaAppConsoleExperienceMenuLayer = 1767831044144  # Unknown = 
    FStringLuaAppDevStoreSeeAllSduiIxpLayer = 1768458312912  # Unknown = 
    FStringLuaAppEdpAudioManufacturerDenyList = 1767526031248  # Unknown = 
    FStringLuaAppEdpFaeIxpLayer = 1767650211472  # Unknown = 
    FStringLuaAppEdpVideoDevicePipeDenyList = 1768389392400  # Unknown = 
    FStringLuaAppEdpVideoManufacturerPipeDenyList = 1768389384400  # Unknown = 
    FStringLuaAppEphemeralCounterPrefix = 1767470830672  # Unknown = 
    FStringLuaAppExperienceMenuLayer = 1768027313936  # Unknown = 
    FStringLuaAppGameCarouselAmpUpsellActionAccessResponses = 1767650007376  # Unknown = 
    FStringLuaAppGameTileMigrationExpLayer = 1768389389840  # Unknown = 
    FStringLuaAppGameTileVideoDevicePipeDenyList = 1768428746832  # Unknown = 
    FStringLuaAppGameTileVideoManufacturerPipeDenyList = 1768428744080  # Unknown = 
    FStringLuaAppIECVRLayerName = 1767978511120  # Unknown = 
    FStringLuaAppIECVRVariantKey = 1767978500752  # Unknown = 
    FStringLuaAppIosPasswordSavingLayer = 1767978510544  # Unknown = 
    FStringLuaAppLandingLayer = 1767978546704  # Unknown = 
    FStringLuaAppLaunchTrackerMilestones = 1768494393408  # Unknown = 
    FStringLuaAppNewSlpEndpointIxpLayer = 1767650224080  # Unknown = 
    FStringLuaAppOmniRecommendationsTopicIdAndNumberOfItemsToCache = 1767977195664  # Unknown = 
    FStringLuaAppPlayButtonAgeCheckAmpFeatureName = 1767900752328  # Unknown = 
    FStringLuaAppPlayButtonAgeCheckAmpNameSpace = 1767900767880  # Unknown = 
    FStringLuaAppPlayWithRewardBetaIxpTreatmentValue = 1767654033040  # Unknown = 
    FStringLuaAppPlayWithRewardBetaIxpVariantKey = 1767654032528  # Unknown = 
    FStringLuaAppPlayWithRewardBetaUniverses = 1767654031952  # Unknown = 
    FStringLuaAppRelativeGuiIxpLayer = 1767723047184  # Unknown = 
    FStringLuaAppSduiEdpIxpLayer = 1767525983952  # Unknown = 
    FStringLuaAppSduiEventDetailsIxpLayer = 1767525989008  # Unknown = 
    FStringLuaAppSearchTopPageIxpLayer = 1767525990096  # Unknown = 
    FStringLuaAppSentryDsn = 1767640183760  # Unknown = 
    FStringLuaAppSignupLayer = 1767978523216  # Unknown = 
    FStringLuaAppSlpIxpLayer = 1767723042512  # Unknown = 
    FStringLuaAppSocialAddFriendsPageLayer = 1768027319568  # Unknown = 
    FStringLuaAppSocialConnectTabLayer = 1768027299152  # Unknown = 
    FStringLuaAppSocialFriendsLandingLayer = 1768027278608  # Unknown = 
    FStringLuaAppSocialFriendsLayer = 1768027294024  # Unknown = 
    FStringLuaAppSocialProfileLayer = 1768027260304  # Unknown = 
    FStringLuaAppSocialUserSearchResultsPageLayer = 1768027280592  # Unknown = 
    FStringLuaAppSortsWithDividers = 1768458342224  # Unknown = 
    FStringLuaAppUpsellMaturityRatingToSettingMapping = 1768024510864  # Unknown = 
    FStringLuaAppVerticalEfficiencyExpLayer = 1768012224336  # Unknown = 
    FStringLuaAppVngAppIxpUserLayer = 1767723048912  # Unknown = 
    FStringLuaAppVngIxpDismissable = 1767723049168  # Unknown = 
    FStringLuaAppVngIxpEnabled = 1767723049296  # Unknown = 
    FStringLuaAppVngIxpFrequency = 1767723047632  # Unknown = 
    FStringLuaDesktopToastNotificationLayer = 1767583527568  # Unknown = 
    FStringLuaEnabledSduiTreatmentTypes = 1767526107856  # Unknown = 
    FStringLuaErrorByPlatformCounter = 1767640175760  # Unknown = 
    FStringLuaGameInviteMenuLayer = 1767583530192  # Unknown = 
    FStringLuaLoginRevampIxpLayer = 1767720486736  # Unknown = 
    FStringLuaMultiPageSignupIxpLayer = 1767720486352  # Unknown = 
    FStringLuaShareGameLuaChatInputBarEntryCounter = 1768297270352  # Unknown = 
    FStringLuaShareGameLuaChatInputBarInviteCounter = 1768297280208  # Unknown = 
    FStringLuaShareGameLuaGameDetailsEntryCounter = 1768297274064  # Unknown = 
    FStringLuaShareGameLuaGameDetailsInviteCounter = 1768297272656  # Unknown = 
    FStringLuaShareGameRoactChatInputBarEntryCounter = 1776083701192  # Unknown = 
    FStringLuaShareGameRoactChatInputBarInviteCounter = 1776083693032  # Unknown = 
    FStringLuaUniversalAppGameInviteMenuLayer = 1767900718368  # Unknown = 
    FStringLuckyRecommendationEnableVariant = 1767645306704  # Unknown = 
    FStringLuckyRecommendationExpLayer = 1768176003888  # Unknown = 
    FStringMemoryShellHost = 1767638310928  # Unknown = 
    FStringMicrophoneDevicePermissionsLoggingEventName = 1767998350544  # Unknown = 
    FStringMobilePopularItemBadgingLayer = 1767983042528  # Unknown = 
    FStringMobileSoundAndHapticsLayer = 1767978560592  # Unknown = 
    FStringMomentsEmojiFallbackCatalogJSON = 1768050284816  # Unknown = 
    FStringMomentsFeedWatchPageRouteName = 1768179500560  # Unknown = 
    FStringMomentsUploadUniverseId = 1776085394000  # Unknown = 
    FStringMrRouterEnvName = 1767977206608  # Unknown = 
    FStringMyStatsExperienceStatsBaseUrl = 1768136680976  # Unknown = 
    FStringMyStatsExperienceStatsPath = 1768136674256  # Unknown = 
    FStringNewConversationCreatedCounter = 1768017053328  # Unknown = 
    FStringNewFriendRequestsBadgeLayer = 1767583427344  # Unknown = 
    FStringNewInGameMenuForcedUserIds = 1767972954576  # Unknown = 
    FStringNotificationsOptInImprovementsFieldName = 1767583531984  # Unknown = 
    FStringNotificationsStreamNotificationUXLayer = 1767583528528  # Unknown = 
    FStringOffPlatformIXPName = 1768181139344  # Unknown = 
    FStringOldAllFriendsCarouselLoadingTimeDoneStats = 1767649998672  # Unknown = 
    FStringOldAllFriendsCarouselLoadingTimeFailedStats = 1767649998480  # Unknown = 
    FStringOnlineFriendsCarouselLoadingTimeDoneStats = 1767649999568  # Unknown = 
    FStringOnlineFriendsCarouselLoadingTimeFailedStats = 1767649998608  # Unknown = 
    FStringOnlineFriendsRefetchOnFriendshipUpdateCounter = 1767650001360  # Unknown = 
    FStringOnlineFriendsRefetchOnPresenceUpdateCounter = 1767649993872  # Unknown = 
    FStringPCGDKFilteredNotificationTypes = 1767583530256  # Unknown = 
    FStringPYMKCarouselGenericTileClicked = 1767643525904  # Unknown = 
    FStringPYMKCarouselLoadedWithUsers = 1767643522256  # Unknown = 
    FStringPYMKCarouselRequestFriendship = 1767643525584  # Unknown = 
    FStringPYMKCarouselUserPressed = 1767643525392  # Unknown = 
    FStringPaginatedCarouselExperimentLayer = 1767583428368  # Unknown = 
    FStringParentLinkAmpNameSpace = 1768009971088  # Unknown = 
    FStringPartyPageCarouselExpLayer = 1767425249808  # Unknown = 
    FStringPartyPageCarouselVariant = 1767645308304  # Unknown = 
    FStringPartyVoiceEligibilityAllowList = 1768024077712  # Unknown = 
    FStringPerfInsightsIXPLayer = 1767650164880  # Unknown = 
    FStringPhoneVerificationCloseCounter = 1768181176976  # Unknown = 
    FStringPhoneVerificationWebviewCounter = 1768181185552  # Unknown = 
    FStringPioneerLaunchPlaceId = 1767828618704  # Unknown = 
    FStringPlatformEventUrl = 1768009975696  # Unknown = 
    FStringPlatformLeaderboardUnrankedLabel = 1768132555984  # Unknown = 
    FStringPlatformLeaderboardsExposure2Layer = 1768132547792  # Unknown = 
    FStringPlayerContextualMenuVendorImagePath = 1767473193360  # Unknown = 
    FStringPlayerListIXPLayer = 1768132542608  # Unknown = 
    FStringPlayerListOverrideType = 1768136663312  # Unknown = 
    FStringPopularFillIconLocation = 1768125833616  # Unknown = 
    FStringPresencePropagationDelayMetricName = 1767650166608  # Unknown = 
    FStringPreviousFriendRequestsCountEngineFeature = 1768133820464  # Unknown = 
    FStringPreviousFriendRequestsCountEngineFeature2 = 1768133851728  # Unknown = 
    FStringPriceChangedSubscriptionMembershipCheckProductTypes = 1776067311888  # Unknown = 
    FStringPrivacyPolicyLink = 1767648597392  # Unknown = 
    FStringProfileQRCodeFriendRequestAlertsExperimentKey = 1767648633744  # Unknown = 
    FStringProfileQRCodeFriendRequestAlertsLayer = 1767648634320  # Unknown = 
    FStringProfileQRCodeScannerOpened = 1768181149904  # Unknown = 
    FStringProfileQRCodeScannerTooltipShown = 1768181153360  # Unknown = 
    FStringProfileQRPageFriendRequestBannerAccepted = 1768181163600  # Unknown = 
    FStringProfileQRPageFriendRequestBannerDismissed = 1768181172176  # Unknown = 
    FStringProfileQRPageFriendRequestBannerShown = 1768181164752  # Unknown = 
    FStringProfileQRPageLoad = 1768181157776  # Unknown = 
    FStringProfileQRPageLoadFailed = 1768181158224  # Unknown = 
    FStringPushUpsellChatVariantName = 1767900771344  # Unknown = 
    FStringPushUpsellOnFirstTimeVariantName = 1767900750240  # Unknown = 
    FStringPushUpsellVariantName = 1767583529808  # Unknown = 
    FStringQueueEnableAutoJoinNewServerVariant = 1767645295824  # Unknown = 
    FStringQueueEnableJoinNewServerVariant = 1767645303248  # Unknown = 
    FStringQueueExpLayer = 1768176025168  # Unknown = 
    FStringRMDefinition = 1768027311504  # Unknown = 
    FStringRccInExperienceNameEnabledAllowList = 1767913622280  # Unknown = 
    FStringReactSchedulingContext = 1767828561232  # Unknown = 
    FStringReactSchedulingPercentiles = 1767972990288  # Unknown = 
    FStringRealNamesInDisplayNamesExperimentDefinition = 1767654040080  # Unknown = 
    FStringRealNamesInDisplayNamesIXP_v1 = 1767654040656  # Unknown = 
    FStringReferralRewardsTermsURL = 1767525711920  # Unknown = 
    FStringReportAnalyticsAbandonedSubmissionTimeStat = 1768383958928  # Unknown = 
    FStringReportAnalyticsButtonActivated = 1768383922768  # Unknown = 
    FStringReportAnalyticsFieldChanged = 1768383954192  # Unknown = 
    FStringReportAnalyticsFormAbandoned = 1768383910224  # Unknown = 
    FStringReportAnalyticsFormSubmitted = 1768383911568  # Unknown = 
    FStringReportAnalyticsInGameAbuseReport = 1768317800080  # Unknown = 
    FStringReportAnalyticsLegacyMenuContext = 1768383917520  # Unknown = 
    FStringReportAnalyticsLegacySentPageContext = 1768383917264  # Unknown = 
    FStringReportAnalyticsNewMenuContext = 1768383960784  # Unknown = 
    FStringReportAnalyticsSubmittedMethodOfAbuseStat = 1768383937936  # Unknown = 
    FStringReportAnalyticsSuccessfulSubmissionTimeStat = 1768383916048  # Unknown = 
    FStringReportAnythingAnnotationIXPLayerName = 1767583560784  # Unknown = 
    FStringReportMenuIXPLayer = 1768027286416  # Unknown = 
    FStringReportingIXPLayer = 1768027284368  # Unknown = 
    FStringRoactChatFetchedOlderConversationCounter = 1767650013840  # Unknown = 
    FStringRoactChatNavigationChatConversationProfileCounter = 1776083672552  # Unknown = 
    FStringRoactChatNavigationChatDetailsProfileCounter = 1776083677032  # Unknown = 
    FStringRoactChatUserLoadedCounter = 1768158178536  # Unknown = 
    FStringRobloxPlusAmpFeatureName = 1767643494992  # Unknown = 
    FStringRobloxPlusAmpNamespace = 1767643495120  # Unknown = 
    FStringRobloxSubscriptionTermsOfUseLink = 1767900744528  # Unknown = 
    FStringRootNavigatorInitialRouteName = 1767654038160  # Unknown = 
    FStringScheduledSquadsListChatLandingScreenEntrypointVariant = 1767645305296  # Unknown = 
    FStringScheduledSquadsListExpLayer = 1767645305040  # Unknown = 
    FStringSduiEagerProcessCollectionIds = 1767648654480  # Unknown = 
    FStringSduiForceImageQualityLevel = 1767643491728  # Unknown = 
    FStringSduiForcePerfLevel = 1767643492240  # Unknown = 
    FStringSduiNonGameTopicIds = 1767648654736  # Unknown = 
    FStringSelectInSceneIXPField = 1768027273744  # Unknown = 
    FStringSelectInSceneReportMenuOverrideUserIds = 1768317780176  # Unknown = 
    FStringSelfProfileView = 1767583422224  # Unknown = 
    FStringShareCaptureGenerateLinkFailed = 1767691053688  # Unknown = 
    FStringShareCapturePromptAccepted = 1768126137680  # Unknown = 
    FStringShareCapturePromptRejected = 1776054348256  # Unknown = 
    FStringShowAddTrustedFriendsHeaderTextAmpFeature = 1768054591312  # Unknown = 
    FStringSocialCaptureIXPLayer = 1767583425808  # Unknown = 
    FStringSocialCaptureTakenIXPLayer = 1767583426000  # Unknown = 
    FStringSocialCarouselTreatment = 1768133824464  # Unknown = 
    FStringSocialCarouselVendorImagePath = 1767641304528  # Unknown = 
    FStringSocialNavigationHomePageAddFriends = 1768296718128  # Unknown = 
    FStringSocialNavigationHomePageCarouselLuaProfile = 1768297302992  # Unknown = 
    FStringSocialNavigationHomePageFriendsLanding = 1768297303440  # Unknown = 
    FStringSocialNavigationMorePageFriendsLanding = 1768297304464  # Unknown = 
    FStringSocialNetworksEditProfileIXPLayer = 1767654046416  # Unknown = 
    FStringSocialOnboardingExperimentLayer = 1767583427920  # Unknown = 
    FStringSocialProfileCurrentlyWearingClickThroughLayer = 1768317791184  # Unknown = 
    FStringSocialViewFriendSortInGameFriendsLayer = 1767641310544  # Unknown = 
    FStringSortInvitesByScoreExperimentLayer = 1768150350160  # Unknown = 
    FStringSpatialRobloxUIIXPLayerName = 1767913639816  # Unknown = 
    FStringSpatialRobloxUIIXPSpatialUIVariantValue = 1767913639944  # Unknown = 
    FStringSpatialRobloxUIIXPUITypeVariableName = 1767913640072  # Unknown = 
    FStringSquadCoordinationExperienceJoinExperimentLayer = 1767645306768  # Unknown = 
    FStringSquadCoordinationUiExperimentLayer = 1767645304144  # Unknown = 
    FStringSquadEnablePartyCoordinationUiVariant = 1767645299152  # Unknown = 
    FStringSquadEnablePartyQuickStartVariant = 1767645309264  # Unknown = 
    FStringSquadEnableRegroupVariant = 1767645310928  # Unknown = 
    FStringSquadQuickStartExperimentLayer = 1767645308816  # Unknown = 
    FStringSquadRegroupExpLayer = 1768175978128  # Unknown = 
    FStringSquadsUnifyCoplayExpLayer = 1767645306384  # Unknown = 
    FStringSquadsUnifyCoplayMultiInvitePartyCreationVariant = 1767645307792  # Unknown = 
    FStringSquadsUnifyCoplayOneOnOnePartyCreationVariant = 1767645307536  # Unknown = 
    FStringStreamNotificationUXDropdownVariant = 1767641313040  # Unknown = 
    FStringStreamNotificationUXExposureLayer = 1767641315600  # Unknown = 
    FStringSupportedAppLaunchMilestonesForReactProfilerLogger = 1768017200784  # Unknown = 
    FStringSuppressMutedErrorKeys = 1767978526224  # Unknown = 
    FStringTTIMetricsTableName = 1767638308688  # Unknown = 
    FStringTakeItDownReportLink = 1767977109712  # Unknown = 
    FStringTextureTranscode7FallbackVersionTM1 = 1767683411680  # Unknown = 
    FStringThrottleParticipantsUpdateIXPLayerValue = 1767645295376  # Unknown = 
    FStringThrottleVoiceParticipantsUpdateLayerName = 1767645292752  # Unknown = 
    FStringThrottleVoiceParticipantsUpdateLayerValue = 1767645293264  # Unknown = 
    FStringTiltLoadingScreenPreLogoText = 1767831055120  # Unknown = 
    FStringTimeoutLoadingLocalPlayerInBackgroundDM = 1767424652304  # Unknown = 
    FStringToastNotificationEventLoggingLevel = 1768017038032  # Unknown = 
    FStringTopSongsSortExploreApiPageType = 1767526165776  # Unknown = 
    FStringTriggerAgeCheckUpsellIncludingVPCAmpFeature = 1768054638352  # Unknown = 
    FStringTutorialUpsellIXPLayerName = 1767650170960  # Unknown = 
    FStringUXForCameraPerformanceIXPLayerName = 1767831046224  # Unknown = 
    FStringUnfilteredMessageDarkHexColor = 1768050305168  # Unknown = 
    FStringUnfilteredMessageLightHexColor = 1768050276048  # Unknown = 
    FStringUnfilteredMessagePressedDarkHexColor = 1768050323152  # Unknown = 
    FStringUnfilteredMessagePressedLightHexColor = 1768050264784  # Unknown = 
    FStringUnfilteredThreadsLearnMoreUrl = 1767641276048  # Unknown = 
    FStringUniversalAppCameraIXPLayer = 1767654051728  # Unknown = 
    FStringUniversesExposedToPeopleCardsTooltipKey = 1768317806096  # Unknown = 
    FStringUserProfileStoreMaxLoggingLevel = 1768001236944  # Unknown = 
    FStringUserProfilesRequestBegin = 1768001201872  # Unknown = 
    FStringUserProfilesRequestFail = 1768001229008  # Unknown = 
    FStringUserProfilesRequestFailAfterRetry = 1768001237328  # Unknown = 
    FStringUserProfilesRequestFailAfterRetryDuration = 1768001231376  # Unknown = 
    FStringUserProfilesRequestFailDuration = 1768001208016  # Unknown = 
    FStringUserProfilesRequestSuccess = 1768001184848  # Unknown = 
    FStringUserProfilesRequestSuccessAfterRetry = 1768001210832  # Unknown = 
    FStringUserProfilesRequestSuccessAfterRetryDuration = 1768377277488  # Unknown = 
    FStringUserProfilesRequestSuccessDuration = 1768001226448  # Unknown = 
    FStringUserProfilesUnmountEarly = 1768001201104  # Unknown = 
    FStringUserSearchLoadingTimeDoneStats = 1767648650576  # Unknown = 
    FStringUserSearchLoadingTimeFailedStats = 1767648651408  # Unknown = 
    FStringUserSearchLoadingTimeNextPageDoneStats = 1767648652496  # Unknown = 
    FStringUserSearchLoadingTimeNextPageFailedStats = 1767648652240  # Unknown = 
    FStringUserSearchPlayerFriendAcceptCounter = 1767648650384  # Unknown = 
    FStringUserSearchPlayerFriendRequestCounter = 1767648651280  # Unknown = 
    FStringUserSearchPlayerTileClickCounter = 1767648649616  # Unknown = 
    FStringUserSearchPlayerTileImpressionsCounter = 1767648651984  # Unknown = 
    FStringV1MenuLanguageSelectionFeatureForcedUserIds = 1767913344592  # Unknown = 
    FStringVNGDownloadNowUrl = 1767526161360  # Unknown = 
    FStringVNGTosUrl = 1767526151632  # Unknown = 
    FStringVNGWebshopUrl = 1767526147792  # Unknown = 
    FStringVoiceExposureIXPLayerName = 1767831045776  # Unknown = 
    FStringVoicePerformanceIXPLayerName = 1768399777680  # Unknown = 
    FStringVoicePerformanceThrottlingIXPLayerName = 1767645294800  # Unknown = 
    FStringVoiceUIImprovementsIXPLayerName = 1767900733216  # Unknown = 
    FStringVoiceUpsellLayer = 1767526162768  # Unknown = 
    FStringVoiceUpsellV2ExperimentLayerLua = 1767978558288  # Unknown = 
    FStringVoiceUserAgencyIXPLayerName = 1767831047184  # Unknown = 
    FStringVoiceVolumeControlsGlobalVoiceVolumeSliderIxpLayer = 1768001215120  # Unknown = 
    FStringVrAvatarPanelsDistanceOffsetOverride = 1767473173712  # Unknown = 
    FStringVrSystemBarXOffSetOverride = 1768027283920  # Unknown = 
    FStringVrSystemBarYOffSetOverride = 1768027290192  # Unknown = 
    FStringVrSystemBarZOffSetOverride = 1768027318992  # Unknown = 
    FStringWHAM1707IXPField = 1767913355528  # Unknown = 
    FStringWhitelistVerifiedUserId = 1767470825616  # Unknown = 
    FStringXboxClassicUILayer = 1767978546640  # Unknown = 
    SFUClientAnalyticsInfluxReportHundredthsPercent = 1767401318032  # Unknown = 
