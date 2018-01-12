#include "stdafx.h"
#include "Settings.h"

ID3D11Device *CCheat::pDevice = NULL;
ID3D11DeviceContext *CCheat::pContext = NULL;
IDXGISwapChain* CCheat::pSwapChain = NULL;
ID3D11RenderTargetView* CCheat::pRenderTargetView = NULL;

void CCheat::Initialise()
{
	AllocConsole();
	freopen("CON", "w", stdout);
	SetConsoleTitleA("Project Frost");

	Helpers::Log("Cheat Initialised");
	Helpers::Log("Cheat created by SMBB & lordchanka");

	D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

	HWND hWindow = FindWindowA(NULL, "Rainbow Six");

#pragma region Initialise DXGI_SWAP_CHAIN_DESC
	DXGI_SWAP_CHAIN_DESC scd;
	ZeroMemory(&scd, sizeof(scd));

	scd.BufferCount = 1;
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // sets color formatting, we are using RGBA
	scd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	scd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // says what we are doing with the buffer
	scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; // msdn explains better than i can: https://msdn.microsoft.com/en-us/library/windows/desktop/bb173076(v=vs.85).aspx
	scd.OutputWindow = hWindow; // our gamewindow, obviously
	scd.SampleDesc.Count = 1; // Set to 1 to disable multisampling
	scd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD; // D3D related stuff, cant really describe what it does
	scd.Windowed = ((GetWindowLongPtr(hWindow, GWL_STYLE) & WS_POPUP) != 0) ? false : true; // check if our game is windowed
	scd.BufferDesc.Width = 1920; // temporary width
	scd.BufferDesc.Height = 1080; // temporary height
	scd.BufferDesc.RefreshRate.Numerator = 144; // refreshrate in Hz
	scd.BufferDesc.RefreshRate.Denominator = 1; // no clue, lol
#pragma endregion

	if (FAILED(D3D11CreateDeviceAndSwapChain(
		NULL, D3D_DRIVER_TYPE_HARDWARE, NULL,
		NULL, &featureLevel, 1, D3D11_SDK_VERSION,
		&scd, &CCheat::pSwapChain,
		&CCheat::pDevice, NULL, &CCheat::pContext
	)))
	{
		Helpers::LogError("D3D11CreateDevice");
		return;
	}

	// GET VTABLE POINTERS
	DWORD_PTR*  pSwapChainVT = reinterpret_cast<DWORD_PTR*>(CCheat::pSwapChain);
	DWORD_PTR*  pDeviceVT = reinterpret_cast<DWORD_PTR*>(CCheat::pDevice);
	DWORD_PTR*  pContextVT = reinterpret_cast<DWORD_PTR*>(CCheat::pContext);

	pSwapChainVT = reinterpret_cast<DWORD_PTR*>(pSwapChainVT[0]);
	pDeviceVT = reinterpret_cast<DWORD_PTR*>(pDeviceVT[0]);
	pContextVT = reinterpret_cast<DWORD_PTR*>(pContextVT[0]);

	Helpers::LogAddress("pSwapChainVT", reinterpret_cast<int64_t>(pSwapChainVT));
	Helpers::LogAddress("pDeviceVT", reinterpret_cast<int64_t>(pDeviceVT));
	Helpers::LogAddress("pContextVT", reinterpret_cast<int64_t>(pContextVT));

	Helpers::LogAddress("D3D11SWAPCHAIN", pSwapChainVT[8]);
	Helpers::LogAddress("D3D11CONTEXT", pContextVT[12]);
	Helpers::LogAddress("D3D11DEVICE", pDeviceVT[24]);

	// SET MISC FUNCTIONS
	Renderer::GetInstance()->Initialize();
	UserInterface::GetInstance()->SetStyle();
	Input::GetInstance()->StartThread();

	// GET FUNCTIONS
	Hooks::oPresent = reinterpret_cast<tD3D11Present>(pSwapChainVT[8]/*D3D11PRESENT*/);

	// LETS HOOK IT
	Helpers::HookFunction(reinterpret_cast<PVOID*>(&Hooks::oPresent), Hooks::hkD3D11Present);
}

void CCheat::Release()
{
	// RELEASE CONSOLE
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	FreeConsole();

	// KILL STILL RUNNING TREADS
	Input::GetInstance()->StopThread();

	// UNHOOK THE FUNCTIONS
	Helpers::UnhookFunction(reinterpret_cast<PVOID*>(&Hooks::oPresent), Hooks::hkD3D11Present);
}

void CCheat::GetResolution(UINT horizontal, UINT vertical)
{
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = FindWindowA(NULL, "Rainbow Six");
	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal = desktop.right;
	vertical = desktop.bottom;
}

