//=========================================
// 
// アプリケーションクラス
// Author YudaKaito
// 
//=========================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "application.h"
#include <assert.h>
#include "input.h"
#include "renderer.h"
#include "theme_color.h"
#include "texture.h"
#include "object2d.h"
#include "sound.h"
#include "objectList.h"
#include "fade.h"
#include "save.h"

// モード
#include "title.h"
#include "select_mode.h"
#include "select_save.h"
#include "minigame_number25.h"
#include "minigame_bus.h"
#include "minigame_moveobject.h"
#include "minigame_remember_before.h"
#include "minigame_comeout.h"
#include "result.h"
#include "minigame_same_as_shadow.h"
#include "minigame_large_number.h"

using namespace std;

//-----------------------------------------------------------------------------
// 静的メンバー変数の初期化
//-----------------------------------------------------------------------------
CApplication* CApplication::application = nullptr;
const int CApplication::SCREEN_WIDTH(1280);
const int CApplication::SCREEN_HEIGHT(720);
const float CApplication::CENTER_X(SCREEN_WIDTH * 0.5f);
const float CApplication::CENTER_Y(SCREEN_HEIGHT * 0.5f);
const float CApplication::FLOAT_SCREEN_WIDTH((float)SCREEN_WIDTH);
const float CApplication::FLOAT_SCREEN_HEIGHT((float)SCREEN_HEIGHT);

//-----------------------------------------------------------------------------
// シングルトンでのインスタンスの取得
//-----------------------------------------------------------------------------
CApplication* CApplication::GetInstance()
{
	if (application == nullptr)
	{
		application = new CApplication;
	}

	return application;
}

//-----------------------------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------------------------
CApplication::CApplication() :
	mode(nullptr),
	renderer(nullptr),
	input(nullptr),
	texture(nullptr),
	m_isEnd(false),
	m_modeType(CMode::MODE_TYPE::TITLE)
{
}

//-----------------------------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------------------------
CApplication::~CApplication()
{
	assert(mode == nullptr);
	assert(renderer == nullptr);
	assert(input == nullptr);
	assert(texture == nullptr);
}

//-----------------------------------------------------------------------------
// 初期化
//-----------------------------------------------------------------------------
HRESULT CApplication::Init(HWND hWnd, HINSTANCE hInstance)
{
	// 入力処理
	input = CInput::Create();
	if (FAILED(input->Init(hInstance, hWnd,D3DXVECTOR2(FLOAT_SCREEN_WIDTH, FLOAT_SCREEN_HEIGHT))))
	{
		return E_FAIL;
	}

	// レンダリングクラス
	renderer = new CRenderer;
	if (FAILED(renderer->Init(hWnd, false)))
	{
		return E_FAIL;
	}

	// テクスチャ
	texture = new CTexture;
	texture->LoadAll();

	// サウンドクラス
	sound = new CSound;
	if (FAILED(sound->Init(hWnd)))
	{
		return E_FAIL;
	}

	// ゲームモード
	SetMode(CMode::MODE_TYPE::TITLE);

	return S_OK;
}

//-----------------------------------------------------------------------------
// 終了
//-----------------------------------------------------------------------------
void CApplication::Uninit()
{
	// オブジェクト全体の解放
	CTaskGroup::GetInstance()->Uninit();

	// ゲームのクリア
	if (mode != nullptr)
	{
		mode->Uninit();

		delete mode;
		mode = nullptr;
	}

	// サウンドの解放
	if (sound != nullptr)
	{
		sound->Uninit();
		delete sound;
		sound = nullptr;
	}

	// テクスチャの解放
	texture->UnloadAll();
	if (texture != nullptr)
	{
		delete texture;
		texture = nullptr;
	}

	// 入力処理の解放
	if (input != nullptr)
	{
		input->Uninit();
		input = nullptr;
	}

	// レンダラーの解放
	if (renderer != nullptr)
	{
		renderer->Uninit();

		delete renderer;
		renderer = nullptr;
	}

	// アプリケーションの解放
	if (application != nullptr)
	{
		delete application;
		application = nullptr;
	}
	assert(application == nullptr);
}

//-----------------------------------------------------------------------------
// 更新
//-----------------------------------------------------------------------------
void CApplication::Update()
{
	input->Update();
	renderer->Update();
	mode->Update();
}

//-----------------------------------------------------------------------------
// 描画
//-----------------------------------------------------------------------------
void CApplication::Draw()
{
	renderer->Draw();
}

//-----------------------------------------------------------------------------
// モードの設定
//-----------------------------------------------------------------------------
void CApplication::SetMode(CMode::MODE_TYPE inType)
{
	m_modeType = inType;

	if (mode != nullptr)
	{
		CTaskGroup::GetInstance()->AllRelease();
		CTaskGroup::GetInstance()->Pause(false);
		mode->Uninit();
		delete mode;
		mode = nullptr;
	}

	switch (inType)
	{
	case CMode::MODE_TYPE::TITLE:
		mode = new CTitle;
		break;
	case CMode::MODE_TYPE::SERECT_SAVE:
		mode = new CSelectSave;
		break;
	case CMode::MODE_TYPE::SERECT_MODE:
		mode = new CSelectMode;
		break;
	case CMode::MODE_TYPE::LOGIN:
		mode = new CTitle;
		break;
	case CMode::MODE_TYPE::EXIT_SAVE:
		mode = new CTitle;
		break;
	case CMode::MODE_TYPE::MINIGAME_BUS:
		mode = new CMiniGameBus;
		break;
	case CMode::MODE_TYPE::MINIGAME_NUMBER25:
		mode = new CMiniGameNumber25;
		break;
	case CMode::MODE_TYPE::MINIGAME_BOX:
//		mode = new CTitle;
		break;
	case CMode::MODE_TYPE::MINIGAME_CALCULATION:
//		mode = new CTitle;
		break;
	case CMode::MODE_TYPE::MINIGAME_CUPSHUFFLE:
//		mode = new CTitle;
		break;
	case CMode::MODE_TYPE::MINIGAME_MOVEOBJECT:
		mode = new CMiniGameMoveObject;
		break;
	case CMode::MODE_TYPE::MINIGAME_TROLLEY:
//		mode = new CTitle;
		break;
	case CMode::MODE_TYPE::MINIGAME_REMEMBER_BEFORE:
		mode = new CMiniGameRememberBefore;
		break;
	case CMode::MODE_TYPE::MINIGAME_COLORTEXT:
//		mode = new CTitle;
		break;
	case CMode::MODE_TYPE::MINIGAME_COMEOUT:
		mode = new CMiniGameComeOut;
		break;
	case CMode::MODE_TYPE::MINIGAME_SHADOW:
		mode = new CMiniGameSameAsShadow;
		break;
	case CMode::MODE_TYPE::MINIGAME_LARGE_NUMBER:
		mode = new CMiniGameLargeNumber;
		break;
	case CMode::MODE_TYPE::MINIGAME_ADD:
//		mode = new CTitle;
		break;
	case CMode::MODE_TYPE::CUSTUM:
//		mode = new CTitle;
		break;
	case CMode::MODE_TYPE::RESULT:
		mode = new CResult;
		break;
	case CMode::MODE_TYPE::MAX:
		break;
	default:
		break;
	}

	GetSound()->Stop();

	//書き出し先を設定
	CSave::SaveMode(inType);

	if (FAILED(mode->Init()))
	{
		assert(false);
	}
}
