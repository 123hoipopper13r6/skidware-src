#include "Explorer.h"
#include "../../Includes.hpp"
#include "ClassImages.h"
#include <unordered_map>

static void renderClassIcon(const char* className, ImVec2 size = ImVec2(16, 16));
static bool classMatchInst(const std::string& filter, const std::string& cls);
static std::string ExplorerHex(uintptr_t value);
static void ContextMenu(SDK::Instance instance, const std::string& instancePath, const std::string& instanceName);

ID3D11ShaderResourceView* ClassImagesPallete = nullptr;
bool FirstTime = true;

CachedNode s_pausedRoot;

static std::vector<FilterResult> s_filterResults;
static std::string s_lastFilter;
static std::string s_lastClassFilter;
static std::unordered_map<uintptr_t, bool> s_hasChildrenCache;

SDK::Vector3 FindFirstPartPosition(SDK::Instance& inst)
{
    for (SDK::Instance child : inst.Children())
    {
        if (!child.Address) continue;
        std::string cc = child.Class();
        if (cc == "Part" || cc == "MeshPart" || cc == "UnionOperation")
        {
            SDK::Vector3 p = child.Primitive().Position();
            if (p.x != 0 || p.y != 0 || p.z != 0)
                return p;
        }
        SDK::Vector3 nested = FindFirstPartPosition(child);
        if (nested.x != 0 || nested.y != 0 || nested.z != 0)
            return nested;
    }
    return SDK::Vector3(0, 0, 0);
}

void Hacks::Explorer::Render()
{
    if (FirstTime)
    {
        int width, height, channels;
        unsigned char* imageData = stbi_load_from_memory(
            ClassImagesRawData,
            sizeof(ClassImagesRawData),
            &width,
            &height,
            &channels,
            4
        );
        if (imageData && width > 0 && height > 0) {
            D3D11_TEXTURE2D_DESC desc = {};
            desc.Width = width;
            desc.Height = height;
            desc.MipLevels = 1;
            desc.ArraySize = 1;
            desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            desc.SampleDesc.Count = 1;
            desc.Usage = D3D11_USAGE_DEFAULT;
            desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
            desc.CPUAccessFlags = 0;

            D3D11_SUBRESOURCE_DATA initData = {};
            initData.pSysMem = imageData;
            initData.SysMemPitch = width * 4;

            ID3D11Texture2D* texture = nullptr;
            if (SUCCEEDED(Globals::g_pd3dDevice->CreateTexture2D(&desc, &initData, &texture))) {
                Globals::g_pd3dDevice->CreateShaderResourceView(texture, nullptr, &ClassImagesPallete);
                if (texture) texture->Release();
            }
            stbi_image_free(imageData);
        }
        FirstTime = false;
    }
}

static bool isValid(const std::string& str) {
    if (str.empty()) return false;
    bool startsWithNumber = std::isdigit(str[0]);
    bool containsSymbol = false;
    for (char ch : str) {
        if (!std::isalnum(ch) && ch != '_') {
            containsSymbol = true;
            break;
        }
    }
    return startsWithNumber || containsSymbol;
}

static std::string BuildPath(const std::string& parentPath, const std::string& name) {
    if (parentPath == "NULL") return "game:GetService(\"";
    if (parentPath == "game:GetService(\"") return parentPath + name + "\")";
    if (isValid(name)) return parentPath + "." + name;
    return parentPath + "[\"" + name + "\"]";
}

static std::string ExplorerHex(uintptr_t value)
{
    char buf[32];
    sprintf_s(buf, "0x%llX", (unsigned long long)value);
    return std::string(buf);
}

static bool classMatchInst(const std::string& filter, const std::string& cls)
{
    if (filter == "_seat") return cls.find("seat") != std::string::npos;
    std::string lowerFilter = filter;
    std::transform(lowerFilter.begin(), lowerFilter.end(), lowerFilter.begin(), ::tolower);
    return cls == lowerFilter;
}

static void ContextMenu(SDK::Instance instance, const std::string& instancePath, const std::string& instanceName)
{
    if (ImGui::BeginPopupContextItem(("ExplorerCtx##" + std::to_string(instance.Address)).c_str(), ImGuiPopupFlags_MouseButtonRight))
    {
        Globals::Explorer::SelectedAddress = instance.Address;
        Globals::Explorer::SelectedName = instanceName;
        Globals::Explorer::SelectedClass = instance.Class();
        Globals::Explorer::SelectedPath = instancePath;
        if (ImGui::MenuItem("Copy Path"))
            ImGui::SetClipboardText(instancePath.c_str());
        if (ImGui::MenuItem("Copy Name"))
            ImGui::SetClipboardText(instanceName.c_str());
        if (ImGui::MenuItem("Copy Class"))
            ImGui::SetClipboardText(instance.Class().c_str());
        if (ImGui::MenuItem("Copy Address"))
            ImGui::SetClipboardText(ExplorerHex(instance.Address).c_str());
        ImGui::Separator();
        if (ImGui::MenuItem("Select"))
        {
            Globals::Explorer::SelectedAddress = instance.Address;
        }
        {
            std::string cls = instance.Class();
            bool isBasePart = (cls == "Part" || cls == "MeshPart" || cls == "UnionOperation"
                || cls == "TrussPart" || cls == "WedgePart" || cls == "CornerWedgePart"
                || cls == "NegateOperation" || cls == "Seat" || cls == "VehicleSeat");
            bool isModel = (cls == "Model");
            if (isBasePart || isModel)
            {
                if (ImGui::MenuItem(isModel ? "Teleport To Model" : "Teleport To Part"))
                {
                    Globals::Explorer::TeleportAddress = instance.Address;
                    Globals::Explorer::TeleportRequest = true;
                }
            }
        }
        ImGui::EndPopup();
    }
}

void renderClassIcon(const char* className, ImVec2 size) {
    if (!ClassImagesPallete) {
        ImGui::Dummy(size);
        return;
    }

    static std::unordered_map<std::string, int> classIconMap = {
     {"Default", 0},
     {"Part", 1},
     {"Model", 2},
     {"Model", 4},
     {"Camera", 5},
     {"Script", 6},
     {"ImageFrame", 7},
     {"Mesh", 8},
     {"SpecialMesh", 8},
     {"Humanoid", 9},
     {"Texture", 10},
     {"Sound", 11},
     {"Players", 21},
     {"SpotLight", 13},
     {"SurfaceLight", 14},
     {"RocketPropulsion", 15},
     {"Tool", 17},
     {"LocalScript", 18},
     {"Workspace", 19},
     {"Player", 12},
     {"Folder", 77},
     {"MeshPart", 1},
    };

    int iconIndex = 0;
    auto it = classIconMap.find(className);
    if (it != classIconMap.end()) {
        iconIndex = it->second;
    }
    else {
        iconIndex = classIconMap["Default"];
    }

    float iconWidth = 16.0f / (float)2352.0f;
    float startU = iconIndex * iconWidth;
    float endU = startU + iconWidth;

    ImGui::Image(
        (ImTextureID)(uintptr_t)ClassImagesPallete,
        size,
        ImVec2(startU, 0),
        ImVec2(endU, 1.0f)
    );
}

static bool HasChildrenCached(uintptr_t address)
{
    if (!address) return false;
    auto it = s_hasChildrenCache.find(address);
    if (it != s_hasChildrenCache.end()) return it->second;
    SDK::Instance inst;
    inst.Address = address;
    bool has = !inst.Children().empty();
    s_hasChildrenCache[address] = has;
    return has;
}

static CachedNode BuildCacheNode(SDK::Instance instance, const std::string& parentPath)
{
    CachedNode node;
    if (!instance.Address) return node;
    node.address = instance.Address;
    node.name = instance.Name();
    node.className = instance.Class();
    node.path = BuildPath(parentPath, node.name);
    auto children = instance.Children();
    for (auto& child : children)
    {
        if (!child.Address) continue;
        node.children.push_back(BuildCacheNode(child, node.path));
    }
    return node;
}

void CacheTree()
{
    s_hasChildrenCache.clear();
    s_pausedRoot = BuildCacheNode(Globals::DataModel, "NULL");
}

static void RenderCachedNode(const CachedNode& node)
{
    std::string filter = Globals::Explorer::SearchBuf;
    std::transform(filter.begin(), filter.end(), filter.begin(), ::tolower);
    std::string classFilter = Globals::Explorer::ClassFilterBuf;

    std::string lowerClass = node.className;
    std::transform(lowerClass.begin(), lowerClass.end(), lowerClass.begin(), ::tolower);

    if (!classFilter.empty())
    {
        std::string lf = classFilter;
        std::transform(lf.begin(), lf.end(), lf.begin(), ::tolower);
        if (lowerClass != lf)
        {
            for (auto& child : node.children) RenderCachedNode(child);
            return;
        }
    }

    if (!filter.empty())
    {
        std::string lowerName = node.name;
        std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        if (lowerName.find(filter) == std::string::npos && lowerClass.find(filter) == std::string::npos)
        {
            for (auto& child : node.children) RenderCachedNode(child);
            return;
        }
    }

    std::string unique_id = node.name + " [" + node.className + "]" + "##" + std::to_string(node.address);
    renderClassIcon(node.className.c_str());
    ImGui::SameLine();
    bool isSelected = (Globals::Explorer::SelectedAddress == node.address);

    if (!node.children.empty())
    {
        if (ImGui::TreeNode(unique_id.c_str()))
        {
            if (ImGui::IsItemClicked(0))
            {
                Globals::Explorer::SelectedAddress = node.address;
                Globals::Explorer::SelectedName = node.name;
                Globals::Explorer::SelectedClass = node.className;
                Globals::Explorer::SelectedPath = node.path;
            }
            for (auto& child : node.children) RenderCachedNode(child);
            ImGui::TreePop();
        }
        else
        {
            if (ImGui::IsItemClicked(0))
            {
                Globals::Explorer::SelectedAddress = node.address;
                Globals::Explorer::SelectedName = node.name;
                Globals::Explorer::SelectedClass = node.className;
                Globals::Explorer::SelectedPath = node.path;
            }
        }
    }
    else
    {
        if (ImGui::Selectable(unique_id.c_str(), &isSelected))
        {
            Globals::Explorer::SelectedAddress = node.address;
            Globals::Explorer::SelectedName = node.name;
            Globals::Explorer::SelectedClass = node.className;
            Globals::Explorer::SelectedPath = node.path;
        }
    }
}

void RenderPausedTree()
{
    RenderCachedNode(s_pausedRoot);
}

static void CollectFilterResults(SDK::Instance instance, const std::string& parentPath, const std::string& filter, const std::string& classFilter)
{
    if (!instance.Address) return;

    std::string name = instance.Name();
    std::string cls = instance.Class();
    std::string lowerClass = cls;
    std::transform(lowerClass.begin(), lowerClass.end(), lowerClass.begin(), ::tolower);
    std::string path = BuildPath(parentPath, name);

    bool classOk = classFilter.empty() || classMatchInst(classFilter, lowerClass);

    bool searchOk = filter.empty();
    if (!searchOk)
    {
        std::string lowerName = name;
        std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        searchOk = lowerName.find(filter) != std::string::npos || lowerClass.find(filter) != std::string::npos;
    }

    if (classOk && searchOk)
        s_filterResults.push_back({ instance.Address, std::move(name), std::move(cls), std::move(path) });

    auto children = instance.Children();
    for (auto& child : children)
    {
        if (!child.Address) continue;
        CollectFilterResults(child, path, filter, classFilter);
    }
}

static void RenderFilterResults()
{
    for (const auto& result : s_filterResults)
    {
        std::string unique_id = result.name + " [" + result.className + "]" + "##" + std::to_string(result.address);
        renderClassIcon(result.className.c_str());
        ImGui::SameLine();

        bool isSelected = (Globals::Explorer::SelectedAddress == result.address);
        if (ImGui::Selectable(unique_id.c_str(), &isSelected))
        {
            Globals::Explorer::SelectedAddress = result.address;
            Globals::Explorer::SelectedName = result.name;
            Globals::Explorer::SelectedClass = result.className;
            Globals::Explorer::SelectedPath = result.path;
        }

        SDK::Instance inst;
        inst.Address = result.address;
        ContextMenu(inst, result.path, result.name);
    }
}

void RecursiveDraw(SDK::Instance instance, std::string parentPath)
{
    if (!instance.Address) return;

    std::string istanceName = instance.Name();
    std::string cls = instance.Class();
    std::string instancePath = BuildPath(parentPath, istanceName);

    std::string unique_id = istanceName + " [" + cls + "]" + "##" + std::to_string(instance.Address);

    renderClassIcon(cls.c_str());
    ImGui::SameLine();
    bool isSelected = (Globals::Explorer::SelectedAddress == instance.Address);
    bool hasChildren = HasChildrenCached(instance.Address);

    if (hasChildren)
    {
        if (ImGui::TreeNode(unique_id.c_str()))
        {
            if (ImGui::IsItemClicked(0))
            {
                Globals::Explorer::SelectedAddress = instance.Address;
                Globals::Explorer::SelectedName = istanceName;
                Globals::Explorer::SelectedClass = cls;
                Globals::Explorer::SelectedPath = instancePath;
            }
            ContextMenu(instance, instancePath, istanceName);

            auto children = instance.Children();
            for (SDK::Instance child : children)
                RecursiveDraw(child, instancePath);

            ImGui::TreePop();
        }
        else
        {
            if (ImGui::IsItemClicked(0))
            {
                Globals::Explorer::SelectedAddress = instance.Address;
                Globals::Explorer::SelectedName = istanceName;
                Globals::Explorer::SelectedClass = cls;
                Globals::Explorer::SelectedPath = instancePath;
            }
            ContextMenu(instance, instancePath, istanceName);
        }
    }
    else
    {
        if (ImGui::Selectable(unique_id.c_str(), &isSelected))
        {
            Globals::Explorer::SelectedAddress = instance.Address;
            Globals::Explorer::SelectedName = istanceName;
            Globals::Explorer::SelectedClass = cls;
            Globals::Explorer::SelectedPath = instancePath;
        }
        ContextMenu(instance, instancePath, istanceName);
    }
}

void Hacks::Explorer::RenderTree()
{
    std::string filter = Globals::Explorer::SearchBuf;
    std::transform(filter.begin(), filter.end(), filter.begin(), ::tolower);
    std::string classFilter = Globals::Explorer::ClassFilterBuf;

    bool hasFilter = !filter.empty() || !classFilter.empty();

    if (hasFilter)
    {
        if (filter != s_lastFilter || classFilter != s_lastClassFilter)
        {
            s_filterResults.clear();
            CollectFilterResults(Globals::DataModel, "NULL", filter, classFilter);
            s_lastFilter = filter;
            s_lastClassFilter = classFilter;
        }
        RenderFilterResults();
    }
    else
    {
        s_filterResults.clear();
        s_lastFilter.clear();
        s_lastClassFilter.clear();
        RecursiveDraw(Globals::DataModel, "NULL");
    }
}
