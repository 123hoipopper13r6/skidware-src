param(
    [string]$DumpJson = "$PSScriptRoot\offsets.json",
    [string]$OffsetsHpp = "$PSScriptRoot\..\skidware\Roblox\Offsets.hpp",
    [switch]$Apply
)

# dumper offset name -> value (Namespace::Name)
$root = Get-Content $DumpJson -Raw | ConvertFrom-Json
$dump = $root.offsets
$lookup = @{}
foreach ($ns in $dump.PSObject.Properties) {
    foreach ($o in $ns.Value.PSObject.Properties) { $lookup["$($ns.Name)::$($o.Name)"] = $o.Value }
}

# skidware flat name -> dumper path. Omitted names keep their current value.
$map = @{
    Adornee                    = 'Highlight::Adornee'
    Anchored                   = 'BasePart::PrimitiveFlags'
    AnchoredMask               = 'PrimitiveFlags::Anchored'
    AutoJumpEnabled            = 'Humanoid::AutoJumpEnabled'
    AutoRotate                 = 'Humanoid::AutoRotate'
    AnimationId                = 'Animation::AnimationId'
    HumanoidDisplayName        = 'Humanoid::DisplayName'
    CFrame                     = 'Primitive::CFrame'
    Camera                     = 'Workspace::CurrentCamera'
    CameraOffset               = 'Humanoid::CameraOffset'
    CameraPos                  = 'Camera::Position'
    CameraRotation             = 'Camera::Rotation'
    CameraSubject              = 'Camera::CameraSubject'
    CanCollide                 = 'BasePart::PrimitiveFlags'
    CanCollideMask             = 'PrimitiveFlags::CanCollide'
    CanTouch                   = 'BasePart::PrimitiveFlags'
    CanTouchMask               = 'PrimitiveFlags::CanTouch'
    Character                  = 'Player::Character'
    Children                   = 'Instance::ChildrenStart'
    ChildrenEnd                = 'Instance::ChildrenEnd'
    ChildrenStart              = 'Instance::ChildrenStart'
    ClassDescriptor            = 'Instance::ClassDescriptor'
    ClassName                  = 'ClassDescriptor::ClassName'
    CreatorId                  = 'DataModel::CreatorId'
    CurrentCamera              = 'Workspace::CurrentCamera'
    DataModel                  = 'DataModel::Workspace'
    Dimensions                 = 'VisualEngine::Dimensions'
    DisplayName                = 'Player::DisplayName'
    FOV                        = 'Camera::FieldOfView'
    FakeDataModelPointer       = 'FakeDataModel::Pointer'
    FakeDataModelToDataModel   = 'FakeDataModel::RealDataModel'
    FieldOfView                = 'Camera::FieldOfView'
    GameId                     = 'DataModel::GameId'
    GameLoaded                 = 'DataModel::GameLoaded'
    Health                     = 'Humanoid::Health'
    HipHeight                  = 'Humanoid::HipHeight'
    JobId                      = 'DataModel::JobId'
    JumpPower                  = 'Humanoid::JumpPower'
    LocalPlayer                = 'Players::LocalPlayer'
    MaterialType               = 'Primitive::Material'
    MaxHealth                  = 'Humanoid::MaxHealth'
    MeshPartColor3             = 'BasePart::Color3'
    ModelInstance              = 'Player::Character'
    MousePosition              = 'InputObject::MousePosition'
    Name                       = 'Instance::Name'
    NameContainer              = 'Instance::NameContainer'
    Parent                     = 'Instance::Parent'
    PartSize                   = 'Primitive::Size'
    PlaceId                    = 'DataModel::PlaceId'
    Player                     = 'Players::LocalPlayer'
    Position                   = 'Primitive::Position'
    Primitive                  = 'BasePart::Primitive'
    RigType                    = 'Humanoid::RigType'
    Rotation                   = 'Primitive::Rotation'
    Size                       = 'Primitive::Size'
    Team                       = 'Player::Team'
    TeamColor                  = 'Team::TeamColor'
    Transparency               = 'BasePart::Transparency'
    UserId                     = 'Player::UserId'
    Value                      = 'Value::Value'
    Velocity                   = 'Primitive::AssemblyLinearVelocity'
    ViewMatrix                 = 'VisualEngine::ViewMatrix'
    ViewportInt16              = 'Camera::ViewportInt16'
    ViewportSize               = 'Camera::ViewportSize'
    VisualEnginePointer        = 'VisualEngine::Pointer'
    VisualEngineToDataModel1   = 'VisualEngine::FakeDataModel'
    WalkSpeed                  = 'Humanoid::WalkSpeed'
    WalkSpeedCheck             = 'Humanoid::WalkSpeedCheck'
    Workspace                  = 'DataModel::Workspace'
    WorkspaceToWorld           = 'Workspace::World'
    WorldGravity               = 'World::Gravity'
    RaycastBoundDesc           = 'WorldRoot::RaycastBoundDesc'
    RaycastBoundFn             = 'WorldRoot::RaycastBoundFn'
}

$lines = Get-Content $OffsetsHpp
$changed = @()
$out = foreach ($line in $lines) {
    if ($line -match '^\s*inline uintptr_t (\w+)\s*=\s*0x([0-9A-Fa-f]+);') {
        $name = $Matches[1]; $cur = $Matches[2]
        if ($name -ceq 'viewmatrix') { $key = 'VisualEngine::ViewMatrix' }
        elseif ($map.ContainsKey($name)) { $key = $map[$name] }
        else { $key = $null }
        if ($key) {
            $key = $map[$name]
            if ($lookup.ContainsKey($key)) {
                $nv = ('{0:X}' -f $lookup[$key])
                if ($nv -ne $cur) {
                    $changed += [pscustomobject]@{ Name = $name; DumpSource = $key; Old = ('0x' + $cur); New = ('0x' + $nv) }
                    $line -replace ('0x' + $cur + ';'), ('0x' + $nv + ';')
                    continue
                }
            } else {
                Write-Host "WARN: dump has no '$key' (mapping for $name) - keeping 0x$cur" -ForegroundColor Yellow
            }
        }
    }
    $line
}

Write-Host "roblox-dumper version: $($root.metadata.roblox_version)" -ForegroundColor Cyan
if ($changed.Count -eq 0) { Write-Host "No offset changes."; return }

$changed | Format-Table -AutoSize | Out-String | Write-Host
$bak = "$OffsetsHpp.bak"
Copy-Item $OffsetsHpp $bak -Force
Write-Host "Backup: $bak"

if ($Apply) {
    Set-Content $OffsetsHpp $out -Encoding utf8
    Write-Host "Applied $($changed.Count) changes to $OffsetsHpp"
} else {
    Set-Content "$PSScriptRoot\Offsets.new.hpp" $out -Encoding utf8
    Write-Host "Dry run: $($changed.Count) changes ready. New file: $PSScriptRoot\Offsets.new.hpp"
    Write-Host "Re-run with -Apply to write directly into Offsets.hpp."
}