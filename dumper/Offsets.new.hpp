#pragma once
#include <cstdint>

namespace SDK::Offsets
{
    inline uintptr_t Adornee = 0xB8;
    inline uintptr_t Anchored = 0x1AE;
    inline uintptr_t AnchoredMask = 0x2;
    inline uintptr_t AnimationId = 0xD0;
    inline uintptr_t AttributeToNext = 0x58;
    inline uintptr_t AttributeToValue = 0x18;
    inline uintptr_t AutoJumpEnabled = 0x1D4;
    inline uintptr_t AutoRotate = 0x1D5;
    inline uintptr_t BanningEnabled = 0x14C;
    inline uintptr_t BeamBrightness = 0x190;
    inline uintptr_t BeamColor = 0x120;
    inline uintptr_t BeamLightEmission = 0x19C;
    inline uintptr_t BeamLightInfuence = 0x1A0;
    inline uintptr_t CFrame = 0xC8;
    inline uintptr_t Camera = 0x498;
    inline uintptr_t CameraMaxZoomDistance = 0x320;
    inline uintptr_t CameraMinZoomDistance = 0x324;
    inline uintptr_t CameraMode = 0x328;
    inline uintptr_t CameraOffset = 0x128;
    inline uintptr_t CameraPos = 0xFC;
    inline uintptr_t CameraRotation = 0xD8;
    inline uintptr_t CameraSubject = 0xC8;
    inline uintptr_t CameraType = 0x158;
    inline uintptr_t CanCollide = 0x1AE;
    inline uintptr_t CanCollideMask = 0x8;
    inline uintptr_t CanTouch = 0x1AE;
    inline uintptr_t CanTouchMask = 0x10;
    inline uintptr_t Character = 0x298;
    inline uintptr_t Children = 0x78;
    inline uintptr_t ChildrenEnd = 0x8;
    inline uintptr_t ChildrenStart = 0x78;
    inline uintptr_t ClassDescriptor = 0x18;
    inline uintptr_t ClassName = 0x8;
    inline uintptr_t CreatorId = 0x178;
    inline uintptr_t CurrentCamera = 0x498;
    inline uintptr_t DataModel = 0x158;
    inline uintptr_t Dimensions = 0xAE0;
    inline uintptr_t DisplayName = 0x138;
    inline uintptr_t FOV = 0x140;
    inline uintptr_t FakeDataModelPointer = 0x8C426F8;
    inline uintptr_t FakeDataModelToDataModel = 0x1D8;
    inline uintptr_t FieldOfView = 0x140;
    inline uintptr_t FramePositionOffsetX = 0xF4;
    inline uintptr_t FramePositionOffsetY = 0x100;
    inline uintptr_t GameId = 0x180;
    inline uintptr_t GameLoaded = 0x5C0;
    inline uintptr_t Health = 0x190;
    inline uintptr_t HipHeight = 0x194;
    inline uintptr_t Humanoid = 0x1D0;
    inline uintptr_t HumanoidDisplayName = 0x148;
    inline uintptr_t HumanoidRootPart = 0x1D0;
    inline uintptr_t JobId = 0x118;
    inline uintptr_t JumpPower = 0x1A4;
    inline uintptr_t LocalPlayer = 0x130;
    inline uintptr_t MaterialType = 0x246;
    inline uintptr_t MaxHealth = 0x1A8;
    inline uintptr_t MeshPartColor3 = 0x1A8;
    inline uintptr_t ModelInstance = 0x298;
    inline uintptr_t MousePosition = 0xD4;
    inline uintptr_t Name = 0x8;
    inline uintptr_t NameContainer = 0x70;
    inline uintptr_t NextGenReplicatorEnabledWrite4 = 0x2C0;
    inline uintptr_t Parent = 0x68;
    inline uintptr_t PlatformStand = 0x1DC;
    inline uintptr_t PartSize = 0x1BC;
    inline uintptr_t PlaceId = 0x188;
    inline uintptr_t Player = 0x130;
    inline uintptr_t Position = 0xEC;
    inline uintptr_t Primitive = 0x188;
    inline uintptr_t RigType = 0x1C0;
    inline uintptr_t Rotation = 0xC8;
    inline uintptr_t Size = 0x1BC;
    inline uintptr_t Team = 0x2D8;
    inline uintptr_t TeamColor = 0xB8;
    inline uintptr_t Transparency = 0x130;
    inline uintptr_t UserId = 0x300;
    inline uintptr_t Value = 0xB8;
    inline uintptr_t Velocity = 0xF8;
    inline uintptr_t ViewMatrix = 0x180;
    inline uintptr_t ViewportInt16 = 0x28C;
    inline uintptr_t ViewportSize = 0x2CC;
    inline uintptr_t VisualEngine = 0x10;
    inline uintptr_t VisualEnginePointer = 0x827DD88;
    inline uintptr_t VisualEngineToDataModel1 = 0xAC0;
    inline uintptr_t VisualEngineToDataModel2 = 0x1C0;
    inline uintptr_t WalkSpeed = 0x1D0;
    inline uintptr_t WalkSpeedCheck = 0x3BC;
    inline uintptr_t Workspace = 0x158;
    inline uintptr_t WorkspaceToWorld = 0x3F0;
    inline uintptr_t WorldGravity = 0x210;
    inline uintptr_t viewmatrix = 0x180;

    namespace WorldRoot
    {
        inline uintptr_t RaycastBoundDesc = 0x82012A0;
        inline uintptr_t RaycastBoundFn = 0x80;
    }
}
