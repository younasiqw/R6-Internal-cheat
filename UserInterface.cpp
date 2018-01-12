#include "UserInterface.h"
#include "Settings.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_internal.h"
#include "GameManager.h"

UserInterface* UserInterface::m_pInstance;

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
}

void UserInterface::SetStyle()
{
	ImGuiStyle& style = ImGui::GetStyle();

	static int hue = 140;

	ImVec4 col_text = ImColor::HSV(hue / 255.f, 20.f / 255.f, 235.f / 255.f);
	ImVec4 col_main = ImColor(9, 82, 128);
	ImVec4 col_back = ImColor(31, 44, 54);
	ImVec4 col_area = ImColor(4, 32, 41);


	style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.1f, 0.95f);
	style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.11f, 0.11f, 0.11f, 0.95f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.27f, 0.27f, .27f, 1.00f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.09f, .09f, .09f, 1.f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.13, 0.13, 0.13, 1.f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.11, 0.11, 0.11, 1.f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(.0f, 0.54f, 0.54f, .7f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(.0f, 0.54f, 0.54f, .7);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(.0f, 0.54f, 0.54f, .7f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(.0f, 0.54f, 0.54f, .7f); // main color thingy
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.1f, 0.1f, 0.1f, 0.95f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f); //main half
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.50f, 0.50f, 0.50f, 0.70f); //main half
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(.0f, 0.54f, 0.54f, 1.f);
	style.Colors[ImGuiCol_ComboBg] = ImVec4(0.15, 0.15, 0.15, 1.00f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(.0f, 0.54f, 0.54f, 1.f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(.0f, 0.50f, 0.50f, 1.00f); //main half
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(.0f, 0.54f, 0.54f, 1.f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.12, 0.12, 0.12, 1.f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.12, 0.12, 0.12, 1.f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.12, 0.12, 0.12, 1.f);
	style.Colors[ImGuiCol_Header] = ImVec4(.0f, 0.54f, 0.54f, .7f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(.50f, 0.50f, 0.50f, .3f); // combobox hover
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(.0f, 0.54f, 0.54f, .87f);
	style.Colors[ImGuiCol_Column] = ImVec4(col_text.x, col_text.y, col_text.z, 0.32f);
	style.Colors[ImGuiCol_ColumnHovered] = ImVec4(col_text.x, col_text.y, col_text.z, 0.78f);
	style.Colors[ImGuiCol_ColumnActive] = ImVec4(col_text.x, col_text.y, col_text.z, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(col_main.x, col_main.y, col_main.z, 0.20f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(col_main.x, col_main.y, col_main.z, 0.78f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(col_main.x, col_main.y, col_main.z, 1.00f);
	style.Colors[ImGuiCol_CloseButton] = ImVec4(col_text.x, col_text.y, col_text.z, 0.f);
	style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(col_text.x, col_text.y, col_text.z, 0);
	style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(col_text.x, col_text.y, col_text.z, 0);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(col_text.x, col_text.y, col_text.z, 0.63f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(col_main.x, col_main.y, col_main.z, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(col_text.x, col_text.y, col_text.z, 0.63f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(col_main.x, col_main.y, col_main.z, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(col_main.x, col_main.y, col_main.z, 0.43f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(col_main.x, col_main.y, col_main.z, 0.92f);
	style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);

	//style.Alpha = .0f;
	style.Alpha = 1.f;
	style.WindowPadding = ImVec2(8, 8);
	style.WindowMinSize = ImVec2(32, 32);
	style.WindowRounding = 4.0f; //4.0
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.ChildWindowRounding = 0.0f;
	style.FramePadding = ImVec2(4, 2);
	style.FrameRounding = 0.0f; //2.0
	style.ItemSpacing = ImVec2(8, 4);
	style.ItemInnerSpacing = ImVec2(4, 4);
	style.TouchExtraPadding = ImVec2(0, 0);
	style.IndentSpacing = 21.0f;
	style.ColumnsMinSpacing = 3.0f;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = 16.0f; //16.0
	style.GrabMinSize = 0.1f;
	style.GrabRounding = 16.0f; //16.0
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.DisplayWindowPadding = ImVec2(22, 22);
	style.DisplaySafeAreaPadding = ImVec2(4, 4);
	style.AntiAliasedLines = true;
	style.AntiAliasedShapes = true;
	style.CurveTessellationTol = 1.25f;
}

void UserInterface::TextColor(bool active)
{
	auto& style = ImGui::GetStyle();

	if (active)
	{
		style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.f);
	}
	else
		style.Colors[ImGuiCol_Text] = ImVec4(0.39f, 0.39f, 0.39f, 1.f);
}

void UserInterface::DefineTab()
{
	if (MenuTab == 0)
	{
		rage = true;
		legit = false;
		visuals = false;
		misc = false;
		skins = false;
		colors = false;
	}
	else if (MenuTab == 1)
	{
		rage = false;
		legit = true;
		visuals = false;
		misc = false;
		skins = false;
		colors = false;
	}
	else if (MenuTab == 2)
	{
		rage = false;
		legit = false;
		visuals = true;
		misc = false;
		skins = false;
		colors = false;
	}
	else if (MenuTab == 3)
	{
		rage = false;
		legit = false;
		visuals = false;
		misc = true;
		skins = false;
		colors = false;
	}
	else if (MenuTab == 4)
	{
		rage = false;
		legit = false;
		visuals = false;
		misc = false;
		skins = true;
		colors = false;
	}
	else if (MenuTab == 5)
	{
		rage = false;
		legit = false;
		visuals = false;
		misc = false;
		skins = false;
		colors = true;
	}
}

void UserInterface::BtnNormal()
{
	auto& style = ImGui::GetStyle();

	style.Colors[ImGuiCol_Button] = ImVec4(0.10, 0.10, 0.10, .98f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.13f, 0.13f, 0.13f, 1.f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.f);
}

void UserInterface::BtnActive()
{
	auto& style = ImGui::GetStyle();

	style.Colors[ImGuiCol_Button] = ImVec4(0.15f, 0.15f, 0.15f, .98f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.15f, 0.15f, 0.15f, 1.f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.15f, 0.15f, 0.15f, 1.f);
}


void UserInterface::DrawAccuracyTab()
{
	auto& style = ImGui::GetStyle();
	BtnNormal();

	style.ItemSpacing = ImVec2(0, 4);

	// Sub-Tabs ghetto
	if (RageSubTab == 0)
		style.Colors[ImGuiCol_Text] = ImVec4(1.f, 1.f, 1.f, 1.f);
	else
		style.Colors[ImGuiCol_Text] = ImVec4(.3f, .3f, .3f, 1.f);

	if (ImGui::Button("Aimbot", ImVec2(386, 32))) RageSubTab = 0;
	ImGui::SameLine();

	if (RageSubTab == 1)
		style.Colors[ImGuiCol_Text] = ImVec4(1.f, 1.f, 1.f, 1.f);
	else
		style.Colors[ImGuiCol_Text] = ImVec4(.3f, .3f, .3f, 1.f);
	if (ImGui::Button("Misc", ImVec2(386, 32))) RageSubTab = 1;

	style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.f);

	style.WindowPadding = ImVec2(8, 8);
	style.ItemSpacing = ImVec2(4, 4);

	if (RageSubTab == 0)
	{
		ImGui::BeginChild("Aimbot - General", ImVec2(190, 398), true);
		{
			ImGui::Text("Aimbot - General");
			ImGui::Separator();
			ImGui::Checkbox("Enable", &Settings::GetInstance()->bAccuracyAimbot);
		}ImGui::EndChild();

		ImGui::SameLine();

		ImGui::BeginChild(XorStr("Aimbot - Accuracy"), ImVec2(190, 398), true);
		{
			ImGui::Text(XorStr("Aimbot - Accuracy"));
			ImGui::Separator();
		}ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("Hack vs Hack", ImVec2(190, 398), true);
		{
			ImGui::Text(XorStr("Hack vs Hack"));
			ImGui::Separator();
		}ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("Work in Progress", ImVec2(190, 398), true);
		{
			ImGui::Text("Work in Progress");
			ImGui::Separator();
		}ImGui::EndChild();
	}
	else if (RageSubTab == 1)
	{
		ImGui::BeginChild("##recoil", ImVec2(190, 398), true);
		{
			ImGui::Text("Recoil");
			ImGui::Separator();
			ImGui::Checkbox("Enable", &Settings::GetInstance()->bAccuracyNoRecoil);
			ImGui::SliderFloat("Spread Amount", &Settings::GetInstance()->fRecoil, 0.f, 1.f, "%.2f");
		}ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("##spread", ImVec2(190, 398), true);
		{
			ImGui::Text("Spread");
			ImGui::Separator();
			ImGui::Checkbox("Enable", &Settings::GetInstance()->bAccuracyNoSpread);
			ImGui::SliderFloat("Spread Amount", &Settings::GetInstance()->fSpread, 0.f, 1.f, "%.2f");
		}ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("##trigger", ImVec2(190, 398), true);
		{
			ImGui::Text("Triggerbot");
			ImGui::Separator();
			ImGui::Checkbox("Enable", &Settings::GetInstance()->bAccuracyTrigger);
		}ImGui::EndChild();
	}
}

void UserInterface::DrawLegitTab()
{
	auto& style = ImGui::GetStyle();
	BtnNormal();
	ImGui::PushFont(Renderer::GetInstance()->m_pSubTabs);
	style.ItemSpacing = ImVec2(0, 4);

	if (LegitSubTab == 0)
		style.Colors[ImGuiCol_Text] = ImVec4(1.f, 1.f, 1.f, 1.f);
	else
		style.Colors[ImGuiCol_Text] = ImVec4(.3f, .3f, .3f, 1.f);

	if (ImGui::Button("G", ImVec2(128.5, 32))) LegitSubTab = 0;
	ImGui::SameLine();

	if (LegitSubTab == 1)
		style.Colors[ImGuiCol_Text] = ImVec4(1.f, 1.f, 1.f, 1.f);
	else
		style.Colors[ImGuiCol_Text] = ImVec4(.3f, .3f, .3f, 1.f);
	if (ImGui::Button("P", ImVec2(128.5, 32))) LegitSubTab = 1;
	ImGui::SameLine();

	if (LegitSubTab == 2)
		style.Colors[ImGuiCol_Text] = ImVec4(1.f, 1.f, 1.f, 1.f);
	else
		style.Colors[ImGuiCol_Text] = ImVec4(.3f, .3f, .3f, 1.f);
	if (ImGui::Button("W", ImVec2(128.5, 32))) LegitSubTab = 2;
	ImGui::SameLine();

	if (LegitSubTab == 3)
		style.Colors[ImGuiCol_Text] = ImVec4(1.f, 1.f, 1.f, 1.f);
	else
		style.Colors[ImGuiCol_Text] = ImVec4(.3f, .3f, .3f, 1.f);
	if (ImGui::Button("d", ImVec2(128.5, 32))) LegitSubTab = 3;
	ImGui::SameLine();

	if (LegitSubTab == 4)
		style.Colors[ImGuiCol_Text] = ImVec4(1.f, 1.f, 1.f, 1.f);
	else
		style.Colors[ImGuiCol_Text] = ImVec4(.3f, .3f, .3f, 1.f);

	if (ImGui::Button("f", ImVec2(128.5, 32))) LegitSubTab = 4;
	ImGui::SameLine();

	if (LegitSubTab == 5)
		style.Colors[ImGuiCol_Text] = ImVec4(1.f, 1.f, 1.f, 1.f);
	else
		style.Colors[ImGuiCol_Text] = ImVec4(.3f, .3f, .3f, 1.f);
	if (ImGui::Button("a", ImVec2(128.5, 32))) LegitSubTab = 5;


	style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.f);

	style.WindowPadding = ImVec2(8, 8);
	style.ItemSpacing = ImVec2(4, 4);

	ImGui::PushFont(Renderer::GetInstance()->m_pDefault);
	if (LegitSubTab == 0)
	{
		ImGui::BeginChild("Pistols##aimbot", ImVec2(200, 398), true);
		{
			ImGui::Text("Aimbot - Pistols");
			ImGui::Separator();


		}ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("Pistols##trigger", ImVec2(200, 398), true);
		{
			ImGui::Text("Trigger - Pistols");
			ImGui::Separator();

		}ImGui::EndChild();
		ImGui::SameLine();
	}

	if (LegitSubTab == 1)
	{
		ImGui::BeginChild("Smgs##aimbot", ImVec2(200, 398), true);
		{

			ImGui::Text("Aimbot - Smgs");
			ImGui::Separator();


		}ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("Smgs##trigger", ImVec2(200, 398), true);
		{
			ImGui::Text("Trigger - Smgs");
			ImGui::Separator();

		}ImGui::EndChild();
		ImGui::SameLine();
	}

	if (LegitSubTab == 2)
	{
		ImGui::BeginChild("Rifles##aimbot", ImVec2(200, 398), true);
		{
			ImGui::Text("Aimbot - Rifles");
			ImGui::Separator();

		}ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("Rifles##trigger", ImVec2(200, 398), true);
		{
			ImGui::Text("Trigger - Rifles");
			ImGui::Separator();

		}ImGui::EndChild();
		ImGui::SameLine();
	}

	if (LegitSubTab == 3)
	{
		ImGui::BeginChild("Shotguns##aimbot", ImVec2(200, 398), true);
		{
			ImGui::Text("Aimbot - Shotguns");
			ImGui::Separator();

		}ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("Shotguns##trigger", ImVec2(200, 398), true);
		{
			ImGui::Text("Trigger - Shotguns");
			ImGui::Separator();

		}ImGui::EndChild();
		ImGui::SameLine();
	}

	if (LegitSubTab == 4)
	{
		ImGui::BeginChild("Heavy##aimbot", ImVec2(200, 398), true);
		{
			ImGui::Text("Aimbot - Heavy");
			ImGui::Separator();

		}ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("Heavy##trigger", ImVec2(200, 398), true);
		{
			ImGui::Text("Trigger - Heavy");
			ImGui::Separator();

		}ImGui::EndChild();
		ImGui::SameLine();
	}

	if (LegitSubTab == 5)
	{
		ImGui::BeginChild("Snipers##aimbot", ImVec2(200, 398), true);
		{
			ImGui::Text("Aimbot - Snipers");
			ImGui::Separator();


		}ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("Snipers##trigger", ImVec2(200, 398), true);
		{
			ImGui::Text("Trigger - Snipers");
			ImGui::Separator();

		}ImGui::EndChild();
		ImGui::SameLine();
	}

}

void UserInterface::DrawVisualsTab()
{
	auto& style = ImGui::GetStyle();
	BtnNormal();

	style.ItemSpacing = ImVec2(0, 4);
	style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.f);

	style.WindowPadding = ImVec2(8, 8);
	style.ItemSpacing = ImVec2(4, 4);

	ImGui::BeginChild("ESP - General", ImVec2(190, 398), true);
	{
		ImGui::Text("ESP - Main");
		ImGui::Separator();
		ImGui::Checkbox("Enable", &Settings::GetInstance()->bESPEnabled);
		ImGui::Checkbox("Box", &Settings::GetInstance()->bESPBox);
		ImGui::Checkbox("Name", &Settings::GetInstance()->bESPName);
		ImGui::Checkbox("Head", &Settings::GetInstance()->bESPHead);
		ImGui::Checkbox("Distance", &Settings::GetInstance()->bESPDistance);
		ImGui::Checkbox("Health", &Settings::GetInstance()->bESPHealth);
		ImGui::NewLine();
		ImGui::SameLine(28);
		ImGui::Checkbox("HP Text", &Settings::GetInstance()->bESPHealthText);
		ImGui::Checkbox("Armor", &Settings::GetInstance()->bESPHasArmor);
		//ImGui::Checkbox("Player Ammo", &Options.Visuals.Esp.EspMisc.bAmmo);
		//ImGui::Checkbox("Skeleton", &Options.Visuals.Esp.EspBox.bSkeleton);
		ImGui::Checkbox("Snaplines", &Settings::GetInstance()->bESPSnapline);
		//ImGui::Checkbox("Visible Only", &Options.Visuals.Esp.EspFilter.bXQZ);  // DOES NOT WORK
		//ImGui::Checkbox("Enemy Only", &Options.Visuals.Esp.EspFilter.bEnemyOnly);
		//ImGui::Checkbox("Planted C4", &Options.Visuals.Esp.EspFilter.bC4);
		//ImGui::Checkbox("Hostages", &Options.Visuals.Esp.EspFilter.bHostage);
		//ImGui::Checkbox("Is Scoped", &Options.Visuals.Esp.EspMisc.bIsScoped);
		//ImGui::Checkbox("Is Flashed", &Options.Visuals.Esp.EspMisc.bIsFlashed);
		//ImGui::Checkbox("Dropped Weapons", &Options.Visuals.Esp.EspFilter.bDroppedWeapons);
		//ImGui::Checkbox("Pitch", &Options.Visuals.Esp.EspBox.bPitch);
		//ImGui::Checkbox("Yaw", &Options.Visuals.Esp.EspBox.bYaw);
	}ImGui::EndChild();

	ImGui::SameLine();

	ImGui::BeginChild("ESP - Filters", ImVec2(190, 398), true);
	{
		ImGui::Text("ESP - Filters");
		ImGui::Separator();

	}ImGui::EndChild();

	ImGui::SameLine();
	ImGui::BeginChild("Visuals - Misc", ImVec2(190, 398), true);
	{
		ImGui::Text("Visuals - Misc");
		ImGui::Separator();

	}ImGui::EndChild();
	ImGui::SameLine();
}

void UserInterface::DrawMiscTab()
{
	auto& style = ImGui::GetStyle();
	BtnNormal();

	style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.f);

	style.WindowPadding = ImVec2(8, 8);
	style.ItemSpacing = ImVec2(4, 4);

	ImGui::BeginChild("Misc I", ImVec2(190, 398), true);
	{
		ImGui::Text("Misc I");
		ImGui::Separator();

	}ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild("Misc II", ImVec2(190, 398), true);
	{
		ImGui::Text("Misc II");
		ImGui::Separator();

	}ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild("Movements", ImVec2(190, 398), true);
	{
		ImGui::Text("Movement");
		ImGui::Separator();

	}ImGui::EndChild();
	ImGui::SameLine();

}

void UserInterface::DrawColorsTab()
{
	ImGui::BeginChild("##visualscolors", ImVec2(772, 434), true);
	{

	}ImGui::EndChild();


}

void UserInterface::Render()
{
	ImGuiIO& io = ImGui::GetIO();
	auto& style = ImGui::GetStyle();
	int W, H;
	W = io.DisplaySize.x;
	H = io.DisplaySize.y;

	DefineTab();

	if (Settings::GetInstance()->Menu)
	{
		/*	if (style.Alpha > 1.f)
		style.Alpha = 1.f;
		else if (style.Alpha != 1.f)
		style.Alpha += 0.05f;*/

		style.WindowMinSize = ImVec2(0, 0);
		ImGui::PushFont(Renderer::GetInstance()->m_pDefault);
		style.Colors[ImGuiCol_Border] = ImVec4(0.27f, 0.27f, .27f, 1.00f);
		ImVec2 mainWindowPos; // wir brauchen die main window pos um nen vernünftigen border zu drawen

							  //Erstmal drawen wir das main menu
		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiSetCond_Appearing);
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1, 0.1f, 1.f);
		ImGui::Begin("##bg", &Settings::GetInstance()->Menu, ImVec2(W, H), .5f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoTitleBar);
		{

		}ImGui::End();



		style.WindowPadding = ImVec2(1, 1);
		style.Colors[ImGuiCol_Button] = ImVec4(0.0, 0.54f, 0.54, 1.f);
		style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.0, 0.54f, 0.54, 1.f);
		style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.0, 0.54f, 0.54, 1.f);
		ImGui::SetNextWindowSize(ImVec2(800, 20));
		ImGui::Begin("RGBGANG | Project Frost", &Settings::GetInstance()->Menu, ImVec2(800, 0), 1.f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_ShowBorders);
		{
			mainWindowPos = ImGui::GetWindowPos();
			//ImGui::Button("Astrium.cc", ImVec2(798, 8));
		}ImGui::End();

		// Als Border machen wir ein 3-lagigen: farbe-grau
		style.WindowPadding = ImVec2(8, 8);
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.1f, 0.95f);
		ImGui::SetNextWindowPosCenter(ImGuiSetCond_Appearing);
		ImGui::SetNextWindowPos(ImVec2(mainWindowPos.x + 6, mainWindowPos.y + 80));
		BtnNormal();
		//style.WindowPadding = ImVec2(0, 0);


		ImGui::Begin("Hurensohn Visual Studio", &Settings::GetInstance()->Menu, ImVec2(788, 450), 0.98f, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_ShowBorders);
		{
			//mainWindowPos = ImGui::GetWindowPos();

			if (MenuTab == 0)
				DrawAccuracyTab();
			if (MenuTab == 1)
				DrawLegitTab();
			if (MenuTab == 2)
				DrawVisualsTab();
			if (MenuTab == 3)
				DrawMiscTab();
			if (MenuTab == 4)
				DrawMiscTab();
			if (MenuTab == 5)
				DrawColorsTab();
		}ImGui::End();

		ImGui::SetNextWindowPos(ImVec2(mainWindowPos.x, mainWindowPos.y + 26));
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.f);
		ImGui::Begin("##border2", &Settings::GetInstance()->Menu, ImVec2(800, 510), 0.98f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_ShowBorders);
		{

		}ImGui::End();

		// So jetzt die tabs



		ImGui::SetNextWindowPos(ImVec2(mainWindowPos.x + 6, mainWindowPos.y + 32));
		style.Colors[ImGuiCol_WindowBg] = ImVec4(1.f, 1.f, 1.f, 0.f);
		style.WindowPadding = ImVec2(0, 0);
		style.ItemSpacing = ImVec2(4, 0);
		ImGui::SetNextWindowSize(ImVec2(788, 42));
		ImGui::Begin("##tabarea", &Settings::GetInstance()->Menu, ImVec2(788, 42), 0.f, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_ShowBorders);
		{
			if (MenuTab == 0) BtnActive(); else BtnNormal();
			if (ImGui::Button("RAGEBOT", ImVec2(128, 42))) MenuTab = 0;
			ImGui::SameLine();
			if (MenuTab == 1) BtnActive(); else BtnNormal();
			if (ImGui::Button("LEGITBOT", ImVec2(128, 42))) MenuTab = 1;
			ImGui::SameLine();
			if (MenuTab == 2) BtnActive(); else BtnNormal();
			if (ImGui::Button("VISUALS", ImVec2(128, 42))) MenuTab = 2;
			ImGui::SameLine();
			if (MenuTab == 3) BtnActive(); else BtnNormal();
			if (ImGui::Button("MISC", ImVec2(128, 42))) MenuTab = 3;
			ImGui::SameLine();
			if (MenuTab == 4) BtnActive(); else BtnNormal();
			if (ImGui::Button("SKINS", ImVec2(128, 42))) MenuTab = 4;
			ImGui::SameLine();
			if (MenuTab == 5) BtnActive(); else BtnNormal();
			if (ImGui::Button("COLORS", ImVec2(128, 42))) MenuTab = 5;
			// lila


		}ImGui::End();
		/*
		if (curLil < -1)
		{
		curLil = 0;
		}

		if (MenuTab == 0)
		{
		if (curLil > 0)
		curLil -= 4;
		}
		else if (MenuTab == 1)
		{
		if (curLil > 132)
		curLil -= 4;
		else if (curLil < 132)
		curLil += 4;
		}
		else if (MenuTab == 2)
		{
		if (curLil > 264)
		curLil -= 4;
		else if (curLil < 264)
		curLil += 4;
		}
		else if (MenuTab == 3)
		{
		if (curLil > 396)
		curLil -= 4;
		else if (curLil < 396)
		curLil += 4;
		}
		else if (MenuTab == 4)
		{
		if (curLil > 528)
		curLil -= 4;
		else if (curLil < 528)
		curLil += 4;
		}
		else if (MenuTab == 5)
		{
		if (curLil > 660)
		curLil -= 4;
		else if (curLil < 660)
		curLil += 4;
		}	*/
		/*
		curR += rand() % 3;
		curG += rand() % 4;
		curB += rand() % 5;

		style.Colors[ImGuiCol_TitleBg] = ImVec4(curR, curG, curB, .7f);
		style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(curR, curG, curB, .7);
		style.Colors[ImGuiCol_TitleBgActive] = ImVec4(curR, curG, curB, .7f);
		style.Colors[ImGuiCol_MenuBarBg] = ImVec4(curR, curG, curB, .7f); // main color thingy
		style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.1f, 0.1f, 0.1f, 0.95f);
		style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f); //main half
		style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.50f, 0.50f, 0.50f, 0.70f); //main half
		style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(curR, curG, curB, 1.f);
		style.Colors[ImGuiCol_ComboBg] = ImVec4(0.15, 0.15, 0.15, 1.00f);
		style.Colors[ImGuiCol_CheckMark] = ImVec4(curR, curG, curB, 1.f);
		style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f); //main half
		style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(curR, curG, curB, 1.f);
		style.Colors[ImGuiCol_Button] = ImVec4(0.12, 0.12, 0.12, 1.f);
		style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.12, 0.12, 0.12, 1.f);
		style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.12, 0.12, 0.12, 1.f);
		style.Colors[ImGuiCol_Header] = ImVec4(curR, curG, curB, .7f);
		style.Colors[ImGuiCol_HeaderHovered] = ImVec4(.50f, 0.50f, 0.50f, .3f); // combobox hover
		style.Colors[ImGuiCol_HeaderActive] = ImVec4(curR, curG, 0.54f, .87f);*/

		ImGui::SetNextWindowPos(ImVec2(mainWindowPos.x + 6 + curLil, mainWindowPos.y + 72), ImGuiSetCond_Always);
		style.Colors[ImGuiCol_WindowBg] = ImVec4(1.f, 1.f, 1.f, 0.f);
		style.Colors[ImGuiCol_Border] = ImVec4(0.27f, 0.27f, .27f, 0.00f);
		style.WindowPadding = ImVec2(0, 0);
		style.ItemSpacing = ImVec2(0, 0);
		ImGui::Begin("##tabarea", &Settings::GetInstance()->Menu, ImVec2(500, 7), 0.f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoTitleBar);
		{
			// lila

			style.Colors[ImGuiCol_Button] = ImVec4(0.0, 0.54f, 0.54, 1.f);
			style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.0, 0.54f, 0.54, 1.f);
			style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.0, 0.54f, 0.54, 1.f);
		}ImGui::End();

		//background

	}
	/*	else
	{
	if (style.Alpha < 0.f)
	style.Alpha = 0.f;
	else if (style.Alpha != 0.f)
	style.Alpha -= 0.05f;
	}*/
}

UserInterface* UserInterface::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new UserInterface();

	return m_pInstance;
}