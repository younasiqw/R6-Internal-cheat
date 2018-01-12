#pragma once
#define WIN32_LEAN_AND_MEAN

#include "targetver.h"
#include <windows.h>
#include "Detours\include\detours.h"
#include <d3d11.h>
#include <d3dcompiler.h>
#include <iostream>

#include "ImGui\imgui.h"
#include "ImGui\imgui_internal.h"
#include "ImGui\imgui_impl_dx11.h"
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include "CCheat.h"
#include "Helpers.h"
#include "Hooks.h"
#include "Renderer.h"
#include "UserInterface.h"
#include "Input.h"
#include "XorStr.h"
