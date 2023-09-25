//=============================================================================
//
// メイン
// Author : YudaKaito
//
//=============================================================================

//*****************************************************************************
// include
//*****************************************************************************
#include <tchar.h> // _T
#include "application.h"
#include "input.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

//*****************************************************************************
// 定数定義
//*****************************************************************************
namespace
{
// ウインドウのクラス名
LPCTSTR CLASS_NAME = _T("AppClass");
// ウインドウのキャプション名
LPCTSTR WINDOW_NAME = _T("DOMINION");
}

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//*****************************************************************************
// グローバル変数
//*****************************************************************************
#ifdef _DEBUG
// FPSカウンタ
int g_nCountFPS;
#endif // _DEBUG

//=============================================================================
// メイン関数
//=============================================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WndProc,
		0,
		0,
		hInstance,
		NULL,
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		CLASS_NAME,
		NULL
	};

	// ウィンドウクラスの登録
	RegisterClassEx(&wcex);

	CApplication* application = CApplication::GetInstance();

	RECT rect = { 0, 0, application->SCREEN_WIDTH, application->SCREEN_HEIGHT };
	// 指定したクライアント領域を確保するために必要なウィンドウ座標を計算
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	// ウィンドウの作成
	HWND hWnd = CreateWindow(CLASS_NAME,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(rect.right - rect.left),
		(rect.bottom - rect.top),
		NULL,
		NULL,
		hInstance,
		NULL);

	//乱数の初期化
	srand((unsigned int)time(0));

	//タッチパネルの情報の受け取りの開始
	RegisterTouchWindow(hWnd, 0);

	if (FAILED(application->Init(hWnd, hInstance)))
	{
		return E_FAIL;
	}

	// 分解能を設定
	timeBeginPeriod(1);

	// フレームカウント初期化
	DWORD dwCurrentTime = 0;
	DWORD dwExecLastTime = timeGetTime();
#ifdef _DEBUG
	DWORD dwFrameCount = 0;
	DWORD dwFPSLastTime = dwExecLastTime;
#endif // _DEBUG

	// ウインドウの表示
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;

	// メッセージループ
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{ // PostQuitMessage()が呼ばれたらループ終了
				break;
			}
			else
			{
				// メッセージの翻訳とディスパッチ
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			dwCurrentTime = timeGetTime();	// 現在の時間を取得
#ifdef _DEBUG
			if ((dwCurrentTime - dwFPSLastTime) >= 500)
			{// 0.5秒ごとに実行
				// FPSを算出
				g_nCountFPS = dwFrameCount * 1000 / (dwCurrentTime - dwFPSLastTime);
				dwFPSLastTime = dwCurrentTime;	// 現在の時間を保存
				dwFrameCount = 0;
			}
#endif // _DEBUG

			if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))
			{ // 1/60秒経過
				// 現在の時間を保存
				dwExecLastTime = dwCurrentTime;

				// 更新処理
				application->Update();

				// 描画処理
				//CDebugProc::Print("FPS : %d\n",g_nCountFPS);
				application->Draw();

#ifdef _DEBUG
				dwFrameCount++;
#endif // _DEBUG
			}
		}
	}

	application->Uninit();

	// ウィンドウクラスの登録を解除
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	// 分解能を戻す
	timeEndPeriod(1);

	return (int)msg.wParam;
}

//=============================================================================
// ウインドウプロシージャ
//=============================================================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	UINT cInputs = NULL;
	CInput *pInput = nullptr;
	PTOUCHINPUT pInputs = nullptr;
	switch (uMsg)
	{
	case WM_CREATE:
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_TOUCH:
		cInputs = LOWORD(wParam);
		pInputs = new TOUCHINPUT[cInputs];
		if (nullptr != pInputs)
		{
			if (GetTouchInputInfo((HTOUCHINPUT)lParam,
				cInputs,
				pInputs,
				sizeof(TOUCHINPUT)))
			{
				// process pInputs
				if (!CloseTouchInputHandle((HTOUCHINPUT)lParam))
				{
					// error handling
				}

				//inputの情報取得
				pInput = CInput::GetKey();

				//情報の設定
				pInput->SetTouchData(pInputs, cInputs - 1);

			}
			else
			{
				// GetLastError() and error handling
			}
			delete[] pInputs;
		}
		else
		{
			// error handling, presumably out of memory
		}
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE: // [ESC]キーが押された
			// ウィンドウを破棄
			DestroyWindow(hWnd);
			break;
		}
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
