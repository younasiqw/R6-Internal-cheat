/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#include <windows.h>

#include "GameRenderer.h"
#include "Offsets.h"
#include "Memory.h"

namespace Engine
{
	Camera* GameRenderer::GetCamera()
	{
		if (!Memory::IsValidPtr<GameRenderer>(this))
			return nullptr;

		auto pGameRenderer = *Memory::Ptr<void**>(this, (OFFSET_GAMERENDERER_DEREF));

		auto pEngineLink = *Memory::Ptr<void**>(pGameRenderer, (OFFSET_GAMERENDERER_ENGINELINK));

		if (!Memory::IsValidPtr(pEngineLink))
			return nullptr;

		auto pEngine = *Memory::Ptr<void**>(pEngineLink, (OFFSET_ENGINELINK_ENGINE));

		if (!Memory::IsValidPtr(pEngine))
			return nullptr;

		return *Memory::Ptr<Camera**>(pEngine, (OFFSET_ENGINE_CAMERA));
	}

	GameRenderer* GameRenderer::GetInstance()
	{
		return *reinterpret_cast<GameRenderer**>(ADDRESS_GAMERENDERER + reinterpret_cast<uint64_t>(GetModuleHandle(NULL)));
	}
}