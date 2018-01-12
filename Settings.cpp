/**
* Overlord Project
* Copyright (C) 2016-2017 RangeMachine
*/

#include "Settings.h"

#include "ImGui/imgui.h"

Settings* Settings::m_pInstance;

Settings::Settings()
{
	bool bESPEnabled = false;

	bool bESPBox = false;
	bool bESPHealth = false;
	bool bESPName = false;
	bool bESPDistance = false;
	bool bESPHead = false;
	bool bESPSnapline = false;

	bool bVisualsCrosshair = false;
	bool bVisualsFPS = false;

	bool bAccuracyNoSpread = false;
	float fSpread = 1.f;
	bool bAccuracyNoRecoil = false;
	float fRecoil = 1.f;
	bool bAccuracNoADSRecoil = false;

	bool Menu = false;
}

Settings::~Settings()
{
}

Settings* Settings::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new Settings();

	return m_pInstance;
}