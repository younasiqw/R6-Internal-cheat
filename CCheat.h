#pragma once
#include "stdafx.h"

namespace CCheat
{
	//Variables
	extern ID3D11Device *pDevice;
	extern ID3D11DeviceContext *pContext;
	extern IDXGISwapChain* pSwapChain;
	extern ID3D11RenderTargetView* pRenderTargetView;

	//Functions
	void Initialise();
	void Release();
	void GetResolution(UINT horizontal, UINT vertical);
}