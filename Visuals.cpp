#include "Visuals.h"

Visuals* Visuals::m_pInstance;

Visuals::Visuals()
{
}

Visuals::~Visuals()
{
}

void Visuals::VisualsMain()
{
	Visuals::DrawESP();
	Visuals::DrawVisuals();
}

void Visuals::DrawESP()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	auto pGameManager = Engine::GameManager::GetInstance();
	auto pCamera = Engine::GameRenderer::GetInstance()->GetCamera();

	if (pGameManager->IsInGame())
	{
		for (uint64_t i = 0; i < pGameManager->GetEntities().GetSize(); i++)
		{
			Engine::Entity* pEntity = pGameManager->GetEntities()[i];
			Engine::Entity* pLocal = pGameManager->GetLocalPlayer();

			if (pEntity == nullptr)
				return;

			INT8 Health = pEntity->GetHealth();

			if (Health > 0)
			{
				float distance = pCamera->GetViewTranslation().Distance(pEntity->GetPosition());

				// Ghetto localplayer check, lul
				if (1.7f < distance)
				{
					// Get the rest of em cheeky variables
					Engine::Vector3 Position = pCamera->WorldToScreen(pEntity->GetPosition());
					Engine::Vector3 HeadPosition = pCamera->WorldToScreen(pEntity->GetHead());

					if (Settings::GetInstance()->bESPEnabled)
					{
						if (Position.z >= 1.0f)
						{
							// Draw our Box
							if (Settings::GetInstance()->bESPBox)
							{
								//if (pEntity->GetTeam() == 0)
								//{
									Renderer::GetInstance()->DrawBox(ImVec2(Position.x, Position.y), ImVec2(HeadPosition.x, HeadPosition.y), 0xFF352CFF);
							//	}
							//	else
								//{
							//		Renderer::GetInstance()->DrawBox(ImVec2(Position.x, Position.y), ImVec2(HeadPosition.x, HeadPosition.y), 0xFFff8d3d);
							//	}			
							}

							// Draw our Head
							if (Settings::GetInstance()->bESPHead)
							{
								Renderer::GetInstance()->DrawCircleScale(ImVec2(HeadPosition.x, HeadPosition.y), 5.f, 0xFFff8d3d, ImVec2(Position.x, Position.y), ImVec2(HeadPosition.x, HeadPosition.y));
							}

							// Draw our Distance
							if (Settings::GetInstance()->bESPDistance)
							{
								Renderer::GetInstance()->DrawOutlinedText(Renderer::GetInstance()->m_pDefault, Helpers::VariableText("Distance: %.1fm", distance), ImVec2(Position.x, Position.y + 5), 12.f, 0xFFFFFFFF, true);
							}

							// Draw our Health
							if (Settings::GetInstance()->bESPHealth)
							{
								Renderer::GetInstance()->DrawHealth(ImVec2(Position.x, Position.y), ImVec2(HeadPosition.x, HeadPosition.y), Health);
							}

							// Draw SnapLines
							if (Settings::GetInstance()->bESPSnapline)
							{
								Renderer::GetInstance()->DrawLine(ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y), ImVec2(Position.x, Position.y), 0xFFff8d3d);
							}

							// Draw our Name
							if (Settings::GetInstance()->bESPName)
							{
								// Calculations so that our name is at the correct position
								float posoffset = Position.y - HeadPosition.y;
								float posoffset2 = Position.y - posoffset - 15;
							//	Renderer::GetInstance()->DrawOutlinedText(Renderer::GetInstance()->m_pDefault, pEntity->GetName(), ImVec2(Position.x, posoffset2), 12.f, 0xFFFFFFFF, true);
							}

							// Draw Debug information
							if (Settings::GetInstance()->bVisualsDebugInfo)
							{
								Engine::Entity* pLocal = pGameManager->GetLocalPlayer();
								Renderer::GetInstance()->DrawOutlinedText(Renderer::GetInstance()->m_pDefault, "LocalPlayer Health: " + pLocal->GetHealth(), ImVec2(20, 20), 26.f, 0xFF00CE11, false);
							}			
						}
					}
				}
			}
		}
	}
}

void Visuals::DrawVisuals()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	auto pGameManager = Engine::GameManager::GetInstance();

	// Draw Crosshair
	if (Settings::GetInstance()->bVisualsCrosshair)
	{
		if (pGameManager->IsInGame())
		{
			Renderer::GetInstance()->DrawLine(ImVec2(io.DisplaySize.x / 2 - 15, io.DisplaySize.y / 2), ImVec2(io.DisplaySize.x / 2 - 5, io.DisplaySize.y / 2), 0xFF00FF2A, 3.f);
			Renderer::GetInstance()->DrawLine(ImVec2(io.DisplaySize.x / 2 + 16, io.DisplaySize.y / 2), ImVec2(io.DisplaySize.x / 2 + 6, io.DisplaySize.y / 2), 0xFF00FF2A, 3.f);
			Renderer::GetInstance()->DrawLine(ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y / 2 - 15), ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y / 2 - 5), 0xFF00FF2A, 3.f);
			Renderer::GetInstance()->DrawLine(ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y / 2 + 16), ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y / 2 + 6), 0xFF00FF2A, 3.f);
		}	
	}

	// Draw FPS
	if (Settings::GetInstance()->bVisualsFPS)
	{
		Renderer::GetInstance()->DrawOutlinedText(Renderer::GetInstance()->m_pDefault, Helpers::VariableText("%.1f", io.Framerate), ImVec2(20, 20), 26.f, 0xFF00CE11, false);
	}
}

Visuals* Visuals::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new Visuals();

	return m_pInstance;
}