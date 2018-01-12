/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#include <windows.h>

#include "GameManager.h"
#include "Offsets.h"
#include "Memory.h"
#include "Helpers.h"
#include "GameRenderer.h"

namespace Engine
{
	Array<Entity*> GameManager::GetEntities()
	{
		return *Memory::Ptr<Array<Entity*>*>(this, OFFSET_GAMEMANAGER_ENTITYLIST);
	}

	GameManager* GameManager::GetInstance()
	{
		return *reinterpret_cast<GameManager**>(ADDRESS_GAMEMANAGER + reinterpret_cast<uint64_t>(GetModuleHandle(NULL)));
	}

	bool GameManager::IsInGame()
	{
		auto pBase = *Memory::Ptr<void**>(this, 0x360);

		if (!Memory::IsValidPtr<void>(pBase))
			return false;

		auto pInstance = *Memory::Ptr<void**>(pBase, 0x2C0);

		if (!Memory::IsValidPtr<void>(pInstance))
			return false;

		auto pDank = *Memory::Ptr<void**>(pInstance, 0x290);

		if (!Memory::IsValidPtr<void>(pDank))
			return false;

		auto pMeme = *Memory::Ptr<void**>(pDank, 0x700);

		if (!Memory::IsValidPtr<void>(pMeme))
			return false;

		auto pInGame = *Memory::Ptr<void**>(pMeme, 0x3E8);

		if (Memory::IsValidPtr<void>(pInGame))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int GameManager::GetLocalTeam()
	{
		auto p0 = *Memory::Ptr<void**>(this, 0x638);


		auto p_1 = *Memory::Ptr<void**>(p0, 0x60);


		auto p1 = *Memory::Ptr<void**>(p_1, 0x8);


		auto p2 = *Memory::Ptr<void**>(p1, 0x0);


		auto p3 = *Memory::Ptr<void**>(p2, 0x120);

		if (!Memory::IsValidPtr<void>(p3))
			return 0;

		auto p4 = *Memory::Ptr<void**>(p3, 0x20);

		if (!Memory::IsValidPtr<void>(p4))
			return 0;
	}

	float& GameManager::GetSpread(int count)
	{
		float Error = 0.26f;

		auto p0 = *Memory::Ptr<void**>(this, 0xD0);

		auto p1 = *Memory::Ptr<void**>(p0, 0x8 * count);

		auto p2 = *Memory::Ptr<void**>(p1, 0x18);

		auto p3 = *Memory::Ptr<void**>(p2, 0xB8);

		auto p4 = *Memory::Ptr<void**>(p3, 0x38);

		auto p5 = *Memory::Ptr<void**>(p4, 0xF0);

		auto p6 = *Memory::Ptr<void**>(p5, 0x0);

		auto p7 = *Memory::Ptr<void**>(p6, 0x110);

		return *Memory::Ptr<float*>(p7, 0x2A0);
	}

	float& GameManager::GetRecoil(int count)
	{
		float Error = 0.26f;

		auto p0 = *Memory::Ptr<void**>(this, 0xD0);

		auto p1 = *Memory::Ptr<void**>(p0, 0x8 * count);

		auto p2 = *Memory::Ptr<void**>(p1, 0x18);

		auto p3 = *Memory::Ptr<void**>(p2, 0xB8);

		auto p4 = *Memory::Ptr<void**>(p3, 0x38);

		auto p5 = *Memory::Ptr<void**>(p4, 0xF0);

		auto p6 = *Memory::Ptr<void**>(p5, 0x0);

		auto p7 = *Memory::Ptr<void**>(p6, 0x110);

		return *Memory::Ptr<float*>(p7, 0x2D8);
	}

	int GameManager::IsInCross()
	{
		auto p0 = *Memory::Ptr<void**>(this, 0x2C0);

		if (!Memory::IsValidPtr<void>(p0))
			return 0;

		auto p_1 = *Memory::Ptr<void**>(p0, 0x370);

		if (!Memory::IsValidPtr<void>(p_1))
			return 0;

		auto p1 = *Memory::Ptr<void**>(p_1, 0x0);

		if (!Memory::IsValidPtr<void>(p1))
			return 0;

		auto p2 = *Memory::Ptr<void**>(p1, 0x670);

		if (!Memory::IsValidPtr<void>(p2))
			return 0;

		auto p3 = *Memory::Ptr<void**>(p2, 0x398);

		if (!Memory::IsValidPtr<void>(p3))
			return 0;

		return *Memory::Ptr<int*>(p3, 0x1C8);
	}

	int GameManager::GetSensX()
	{
		int Error = 0;

		auto p0 = *Memory::Ptr<void**>(this, 0x230);

		auto p1 = *Memory::Ptr<void**>(p0, 0x60);

		auto p2 = *Memory::Ptr<void**>(p1, 0x20);

		auto p3 = *Memory::Ptr<void**>(p2, 0x0);

		if (!Memory::IsValidPtr<void>(p3))
			return Error;

		return *Memory::Ptr<int*>(p3, 0x70);
	}

	int GameManager::GetSensY()
	{
		int Error = 0;

		auto p0 = *Memory::Ptr<void**>(this, 0x230);

		auto p1 = *Memory::Ptr<void**>(p0, 0x60);

		auto p2 = *Memory::Ptr<void**>(p1, 0x20);

		auto p3 = *Memory::Ptr<void**>(p2, 0x0);

		if (!Memory::IsValidPtr<void>(p3))
			return Error;

		return *Memory::Ptr<int*>(p3, 0x74);
	}

	Entity* GameManager::GetLocalPlayer()
	{
		Entity* pLocalPlayer = NULL;
		auto pGameManager = Engine::GameManager::GetInstance();
		auto pCamera = Engine::GameRenderer::GetInstance()->GetCamera();

		for (uint32_t i = 0; i < pGameManager->GetEntities().GetSize(); i++)
		{
			auto pEntity = pGameManager->GetEntities()[i];

			if (Memory::IsValidPtr<Entity>(pEntity))
			{
				if (pCamera->GetViewTranslation().Distance(pEntity->GetHead()) < 0.1f)
					pLocalPlayer = pEntity;
			}
		}

		return pLocalPlayer;
	}
}