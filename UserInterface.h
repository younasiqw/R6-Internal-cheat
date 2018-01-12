/**
* Overlord Project
* Copyright (C) 2016-2017 RangeMachine
*/

#pragma once

#include "stdafx.h"

class UserInterface
{
public:
	void SetStyle();
	void Render();

	bool rage;
	bool legit;
	bool visuals;
	bool misc;
	bool skins;
	bool colors;
	int MenuTab;
	int RageSubTab;
	int VisSubTab;
	int LegitSubTab;
	int curLil;
	int curR;
	int curG;
	int curB;

	static UserInterface* GetInstance();

private:
	void TextColor(bool active);
	void DefineTab();
	void BtnNormal();
	void BtnActive();
	void DrawAccuracyTab();
	void DrawLegitTab();
	void DrawVisualsTab();
	void DrawMiscTab();
	void DrawColorsTab();
	UserInterface();
	~UserInterface();

	static UserInterface* m_pInstance;
};