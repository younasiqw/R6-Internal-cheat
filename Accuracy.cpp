#include "Accuracy.h"

Accuracy* Accuracy::m_pInstance;

Accuracy::Accuracy()
{
	m_hTriggerThread = CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(DoTrigger), NULL, NULL, NULL);
}

Accuracy::~Accuracy()
{
	TerminateThread(m_hTriggerThread, 0);
}

void Accuracy::AccuracyMain()
{
	// Do our Nospread
	if (Settings::GetInstance()->bAccuracyNoSpread)
	{
		Accuracy::DoNoSpread();
	}

	// Do our Norecoil
	if (Settings::GetInstance()->bAccuracyNoRecoil)
	{
		Accuracy::DoNoRecoil();
	}

	//	if (Settings::GetInstance()->bAccuracyAimbot && (GetAsyncKeyState(VK_SHIFT) & 0x8000))
	//	{
	//		Accuracy::DoAimbot();
	//	}
}

float GetDistance(float Xx, float Yy, float xX, float yY)
{
	return sqrt((yY - Yy) * (yY - Yy) + (xX - Xx) * (xX - Xx));
}

void Accuracy::DoTrigger()
{
	while (Settings::GetInstance()->bAccuracyTrigger)
	{
		auto pGameManager = Engine::GameManager::GetInstance();

		if (pGameManager->IsInCross() == 1)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
			mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
		}
	}
}

void Accuracy::DoAimbot()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	auto pGameManager = Engine::GameManager::GetInstance();
	auto pCamera = Engine::GameRenderer::GetInstance()->GetCamera();

	float BestDist = 100;
	int BestTarget = -1;
	if (pGameManager->IsInGame())
	{
		for (uint64_t i = 0; i < pGameManager->GetEntities().GetSize(); i++)
		{
			Engine::Entity* pEntity = pGameManager->GetEntities()[i];

			if (pEntity->GetHealth() > 0)
			{
				Engine::Vector3 HeadPosition = pCamera->WorldToScreen(pEntity->GetHead());

				float FaggotDist = GetDistance(HeadPosition.x, HeadPosition.y, io.DisplaySize.x / 2, io.DisplaySize.y / 2);

				if (FaggotDist < BestDist)
				{
					BestDist = FaggotDist;
					BestTarget = i;
				}

				if (BestTarget != -1)
				{
					if (i == pGameManager->GetEntities().GetSize() - 1)
					{
						Engine::Entity* pEnt = pGameManager->GetEntities()[BestTarget];
						Engine::Vector3 HeadPosition = pCamera->WorldToScreen(pEnt->GetHead());

						double DistX = (double)HeadPosition.x - io.DisplaySize.x / 2;
						double DistY = (double)HeadPosition.y - io.DisplaySize.y / 2;

						DistX /= pGameManager->GetSensX() / 5 * 1.2;
						DistY /= pGameManager->GetSensY() / 5 * 1.2;

						//if aimkey is pressed
						mouse_event(MOUSEEVENTF_MOVE, (DWORD)DistX, (DWORD)DistY, NULL, NULL); //doaim, move mouse to x & y
					}
				}
			}
		}
	}
}

void Accuracy::DrawAimFOV()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	if (Settings::GetInstance()->bAccuracyAimShowFOV)
	{
		Renderer::GetInstance()->DrawCircle(ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y / 2), Settings::GetInstance()->fAimFov * 11, 0xFFff8d3d);
	}
}

void Accuracy::DoNoSpread()
{
	auto pGameManager = Engine::GameManager::GetInstance();
	if (pGameManager)
	{
		for (uint64_t i = 0; i < pGameManager->GetEntities().GetSize(); i++)
		{
			pGameManager->GetSpread(i) = Settings::GetInstance()->fSpread;
		}
	}
}

void Accuracy::DoNoRecoil()
{
	auto pGameManager = Engine::GameManager::GetInstance();
	if (pGameManager)
	{
		for (uint64_t i = 0; i < pGameManager->GetEntities().GetSize(); i++)
		{
			pGameManager->GetRecoil(i) = Settings::GetInstance()->fSpread;
		}
	}
}

Accuracy* Accuracy::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new Accuracy();

	return m_pInstance;
}