/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#pragma  once

#include "Vector3.h"

namespace Engine
{
	class Camera
	{
		public:
			Vector3& GetViewRight();
			Vector3& GetViewUp();
			Vector3& GetViewForward();
			Vector3& GetViewTranslation();
			float GetViewFovX();
			float GetViewFovY();

			Vector3 WorldToScreen(Vector3& position);
	};

	class CCamera
	{
	public:
		char pad_0000[368]; //0x0000
		Engine::Vector3 ViewRight; //0x0170
		char pad_017C[8]; //0x017C
		Engine::Vector3 ViewUp; //0x0184
		char pad_0190[8]; //0x0190
		Engine::Vector3 ViewForward; //0x0198
		char pad_01A4[8]; //0x01A4
		Engine::Vector3 ViewTranslation; //0x01AC
		char pad_01B8[8]; //0x01B8
		float ViewFovX; //0x01C0
		char pad_01C4[16]; //0x01C4
		float ViewFovY; //0x01D4
		char pad_01D8[152]; //0x01D8
	}; //Size: 0x0270
}