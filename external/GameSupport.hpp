#pragma once
#include "../Includes.hpp"

namespace GameSupport
{
    inline void RenderMM2(ImColor titleColor)
    {
        if (Globals::Esp::Team && Globals::Esp::TeamMode >= 1)
        {
            ImGui::Separator();
            ImGui::TextColored(titleColor.Value, "MM2 Team Colors");
            ImGui::Text("Murderer"); ImGui::SameLine();
            ImGui::ColorEdit4("##Murderer Color", Globals::Esp::Colors::Murderer, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaPreview);
            ImGui::Text("Sheriff"); ImGui::SameLine();
            ImGui::ColorEdit4("##Sheriff Color", Globals::Esp::Colors::Sheriff, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaPreview);
            ImGui::Text("Innocent"); ImGui::SameLine();
            ImGui::ColorEdit4("##Innocent Color", Globals::Esp::Colors::Innocent, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaPreview);
        }

        ImGui::Separator();
        ImGui::TextColored(titleColor.Value, "MM2 Items");
        ImGui::Checkbox("Dropped Gun ESP", &Globals::Esp::DroppedGun);
        ImGui::SameLine();
        ImGui::ColorEdit4("##DroppedGun Color", Globals::Esp::Colors::DroppedGun, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaPreview);
    }

    inline void Render(ImColor titleColor)
    {
        if (Globals::GameID == SDK::Games::MurderMystery2)
        {
            RenderMM2(titleColor);
        }
    }
}
