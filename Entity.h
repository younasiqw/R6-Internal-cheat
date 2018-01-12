/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#pragma once

#include "Vector3.h"
#include "stdafx.h"

namespace Engine
{
	class Entity
	{
		public:
			Vector3& GetPosition();
			Vector3& GetNeck();
			Vector3& GetHead();
			INT8 GetTeam();
			INT8 GetHealth();
			std::string GetName();
    };
}
