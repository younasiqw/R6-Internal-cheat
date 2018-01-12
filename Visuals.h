#pragma once
#include "stdafx.h"
#include "Entity.h"
#include "GameManager.h"
#include "GameRenderer.h"
#include "Settings.h"
#include "Renderer.h"

class Visuals
{
public:
	void DrawESP();
	void DrawVisuals();
	void VisualsMain();

	static Visuals* GetInstance();

private:
	Visuals();
	~Visuals();

	static Visuals* m_pInstance;
};