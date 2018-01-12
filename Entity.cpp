/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#include "Entity.h"
#include "Offsets.h"
#include "Memory.h"

namespace Engine
{
	Vector3& Entity::GetPosition()
	{
		if (!Memory::IsValidPtr<Entity>(this))
			return *(new Vector3());

		return *Memory::Ptr<Vector3*>(this, OFFSET_ENTITY_POSITION);
	}

	Vector3& Entity::GetNeck()
	{
		if (!Memory::IsValidPtr<Entity>(this))
			return *(new Vector3());

		return *Memory::Ptr<Vector3*>(this, OFFSET_ENTITY_NECK);
	}

	Vector3& Entity::GetHead()
	{
		if (!Memory::IsValidPtr<Entity>(this))
			return *(new Vector3());

		return *Memory::Ptr<Vector3*>(this, OFFSET_ENTITY_HEAD);
	}

	INT8 Entity::GetHealth()
	{
		if (!Memory::IsValidPtr<Entity>(this))
			return 0.0f;

		auto pEntityInfo = *Memory::Ptr<void**>(this, OFFSET_ENTITY_ENTITYINFO);

		auto pMainComponent = *Memory::Ptr<void**>(pEntityInfo, OFFSET_ENTITYINFO_MAINCOMPONENT);

		auto pChildComponent = *Memory::Ptr<void**>(pMainComponent, OFFSET_MAINCOMPONENT_CHILDCOMPONENT);

		return *Memory::Ptr<INT8*>(pChildComponent, OFFSET_CHILDCOMPONENT_HEALTH);
	}

	INT8 Entity::GetTeam()
	{
		if (!Memory::IsValidPtr<Entity>(this))
			return 0;

		auto pEntityInfo = *Memory::Ptr<void**>(this, 0x270);

		auto pMainComponent = *Memory::Ptr<void**>(pEntityInfo, 0x0);

		return *Memory::Ptr<INT8*>(pMainComponent, 0x140);
	}

	std::string Entity::GetName()
	{
		auto pPlayerInfo = *Memory::Ptr<void**>(this, OFFSET_ENTITY_PLAYERINFO);

		auto pPlayerInfoDeref = *Memory::Ptr<void**>(pPlayerInfo, OFFSET_PLAYERINFO_MAINCOMPONENT);

		auto pName = *Memory::Ptr<char**>(pPlayerInfoDeref, OFFSET_PLAYERINFO_NAME);

		Helpers::Log(pName);

		return "Nigga";
	}
}