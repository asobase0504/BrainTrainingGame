//****************************************************************
//
// precompile
// Author : Yuda Kaito
// Author : Katsuki Mizuki
// Author : Hamada Ryuuga
//
//****************************************************************
#ifndef PRECOMPILE_H_	// このマクロ定義がされてなかったら
#define PRECOMPILE_H_	// 二重インクルード防止のマクロ定義

// メモリーリークのチェック
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define CHECK_MEM_LEAK
#endif // _DEBUG:

// 普段使用禁止
#ifdef CHECK_MEM_LEAK
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
//#define new new
#endif // CHECK_MEM_LEAK

// ライブラリのリンク
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"winmm.lib")

// 基本
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <assert.h>
#include <tchar.h>
#include <Shlwapi.h>
#include <locale.h>

// STL
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <functional>
#include <chrono>
#include <string>

#pragma push_macro("new")
#undef new

// DirectX9
#include <d3dx9.h>

#pragma pop_macro("new")

// Input
#define	 DIRECTINPUT_VERSION (0x0800)
#include <dinput.h>
#include <xinput.h>

// Json
#include "nlohmann/json.hpp"

// Debug
#include "debug_proc.h"

#endif
