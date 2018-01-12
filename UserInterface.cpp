/**
* Overlord Project
* Copyright (C) 2016-2017 RangeMachine
*/

#include "UserInterface.h"
#include "Settings.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_internal.h"

namespace ImGui
{
	IMGUI_API bool Tab(unsigned int index, const char* label, int* selected, float width = 0)
	{
		ImGuiStyle& style = ImGui::GetStyle();
		ImVec2 itemSpacing = style.ItemSpacing;
		ImVec4 color = style.Colors[ImGuiCol_Button];
		ImVec4 colorActive = style.Colors[ImGuiCol_ButtonActive];
		ImVec4 colorHover = style.Colors[ImGuiCol_ButtonHovered];
		style.ItemSpacing.x = 15;

		if (index > 0)
			ImGui::SameLine();

		if (index == *selected)
		{
			style.Colors[ImGuiCol_Button] = colorActive;
			style.Colors[ImGuiCol_ButtonActive] = colorActive;
			style.Colors[ImGuiCol_ButtonHovered] = colorActive;
		}
		else
		{
			style.Colors[ImGuiCol_Button] = color;
			style.Colors[ImGuiCol_ButtonActive] = colorActive;
			style.Colors[ImGuiCol_ButtonHovered] = colorHover;
		}

		if (ImGui::Button(label, ImVec2(width, 0)))
			*selected = index;

		style.Colors[ImGuiCol_Button] = color;
		style.Colors[ImGuiCol_ButtonActive] = colorActive;
		style.Colors[ImGuiCol_ButtonHovered] = colorHover;
		style.ItemSpacing = itemSpacing;

		return *selected == index;
	}
}

UserInterface* UserInterface::m_pInstance;

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
}

void UserInterface::SetStyle()
{
	ImGuiStyle * style = &ImGui::GetStyle();

	style->WindowPadding = ImVec2(15, 15);
	style->WindowRounding = 2.0f;
	style->FramePadding = ImVec2(5, 5);
	style->FrameRounding = 2.0f;
	style->ItemSpacing = ImVec2(12, 8);
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	style->ScrollbarRounding = 2.0f;
	style->GrabMinSize = 10.0f;
	style->GrabRounding = 2.0f;
	style->ChildWindowRounding = 2.0f;

	style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(4.0f / 255, 8.0f / 255, 12.0f / 255, 1.00f);
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(8.0f / 255, 16.0f / 255, 24.0f / 255, 1.00f);

	style->Colors[ImGuiCol_Button] = ImVec4(14.0f / 255, 28.0f / 255, 40.0f / 255, 1.00f);
	style->Colors[ImGuiCol_ButtonActive] = ImVec4(6.0f / 255, 12.0f / 255, 18.0f / 255, 1.00f);
	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(14.0f / 255, 28.0f / 255, 56.0f / 255, 1.00f);

	style->Colors[ImGuiCol_SliderGrab] = ImVec4(24.0f / 255, 48.0f / 255, 80.0f / 255, 1.00f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(14.0f / 255, 28.0f / 255, 56.0f / 255, 1.00f);

	style->Colors[ImGuiCol_CheckMark] = ImVec4(24.0f / 255, 48.0f / 255, 80.0f / 255, 1.00f);
	style->Colors[ImGuiCol_FrameBg] = ImVec4(6.0f / 255, 12.0f / 255, 18.0f / 255, 1.00f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(14.0f / 255, 28.0f / 255, 56.0f / 255, 1.00f);

	style->Colors[ImGuiCol_WindowBg] = ImVec4(1.0f / 255, 2.0f / 255, 3.0f / 255, 0.98f);
	style->Colors[ImGuiCol_ChildWindowBg] = ImVec4(1.0f / 255, 2.0f / 255, 3.0f / 255, 0.5f);
}

void UserInterface::Render()
{
	if (!Settings::GetInstance()->Menu)
		return;

	ImGui::Begin("Project Frost", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

	ImGuiStyle& style = ImGui::GetStyle();
	ImVec2 itemSpacing = style.ItemSpacing;
	style.ItemSpacing.y = 15;

	static int currentTab = 0;

	ImGui::Tab(0, XorStr("Accuracy"), &currentTab, 99); // too lazy to remove this, do it yourself
	ImGui::Tab(1, XorStr("ESP"), &currentTab, 99);
	ImGui::Tab(2, XorStr("Information"), &currentTab, 96);

	// Accuracy
	if (currentTab == 0)
	{
		style.ItemSpacing = itemSpacing;

		ImGui::SetWindowSize(ImVec2(355, 325));

		ImGui::Columns(2, NULL, false);
		ImGui::SetColumnOffset(1, 173);

		ImGui::Text(XorStr("ESP - Players"));
		ImGui::BeginChild(XorStr("PlayersPanel"), ImVec2(155, 156), true);

		ImGui::Checkbox(XorStr("No Spread"), &Settings::GetInstance()->bAccuracyNoSpread);
		ImGui::SliderFloat(XorStr("Spread value"), &Settings::GetInstance()->fSpread, 0.f, 1.f, "%.0f");
		ImGui::Checkbox(XorStr("No Recoil"), &Settings::GetInstance()->bAccuracyNoRecoil);
		ImGui::SliderFloat(XorStr("Spread value"), &Settings::GetInstance()->fRecoil, 0.f, 1.f, "%.0f");

		ImGui::EndChild();
	}
	// ESP
	else if (currentTab == 1)
	{
		style.ItemSpacing = itemSpacing;

		ImGui::SetWindowSize(ImVec2(355, 325));

		ImGui::Columns(2, NULL, false);
		ImGui::SetColumnOffset(1, 173);

		ImGui::Text(XorStr("ESP - Players"));
		ImGui::BeginChild(XorStr("PlayersPanel"), ImVec2(155, 156), true);

		ImGui::Checkbox(XorStr("Enabled"), &Settings::GetInstance()->bESPEnabled);
		ImGui::Checkbox(XorStr("Box"), &Settings::GetInstance()->bESPBox);
		ImGui::Checkbox(XorStr("Health"), &Settings::GetInstance()->bESPHealth);
		ImGui::Checkbox(XorStr("Health Text"), &Settings::GetInstance()->bESPHealthText);
		ImGui::Checkbox(XorStr("Name"), &Settings::GetInstance()->bESPName);
		ImGui::Checkbox(XorStr("Distance"), &Settings::GetInstance()->bESPDistance);
		ImGui::Checkbox(XorStr("Head"), &Settings::GetInstance()->bESPHead);
		ImGui::Checkbox(XorStr("Enemy Only"), &Settings::GetInstance()->bESPEnemyOnly);
		ImGui::Checkbox(XorStr("Snapline"), &Settings::GetInstance()->bESPSnapline);
		ImGui::Checkbox(XorStr("Show Armor"), &Settings::GetInstance()->bESPHasArmor);

		ImGui::SameLine();

		ImGui::Text(XorStr("Visuals - Misc"));
		ImGui::BeginChild(XorStr("VisualsMisc"), ImVec2(155, 156), true);

		ImGui::Checkbox(XorStr("Crosshair"), &Settings::GetInstance()->bVisualsCrosshair);
		ImGui::Checkbox(XorStr("FPS"), &Settings::GetInstance()->bVisualsFPS);

		ImGui::EndChild();
	}
	else if (currentTab == 2)
	{
		style.ItemSpacing = itemSpacing;

		ImGui::SetWindowSize(ImVec2(355, 325));
	}

	ImGui::End();
}

UserInterface* UserInterface::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new UserInterface();

	return m_pInstance;
}