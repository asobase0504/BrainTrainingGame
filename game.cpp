//=============================================================================
// 
// アプリケーションクラス
// Author YudaKaito
// 
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "game.h"
#include "application.h"
#include "input.h"

#include "count_down.h"
#include "click_item.h"

#include "pause.h"
#include "timer.h"
#include "result.h"
#include "fade.h"

//-----------------------------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------------------------
CGame::CGame() : m_state(COUNT_DOWN)
{
}

//-----------------------------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------------------------
CGame::~CGame()
{
}

//-----------------------------------------------------------------------------
// 初期化
//-----------------------------------------------------------------------------
HRESULT CGame::Init()
{
	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f));
		object->SetSize(D3DXVECTOR2(CApplication::CENTER_X * 2.0f, CApplication::CENTER_Y * 2.0f));
		object->SetTexture("GREEN_BG");
	}

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f));
		object->SetSize(D3DXVECTOR2(CApplication::CENTER_Y * 1.5f, CApplication::CENTER_Y * 1.5f));
		object->SetTexture("BLOCK_BG");
	}

	m_countDown = CCountDown::Create();

	m_isResult = false;

	return S_OK;
}

//-----------------------------------------------------------------------------
// ゲームの開始
//-----------------------------------------------------------------------------
void CGame::GameStart()
{
	m_timer = CTimer::Create(D3DXVECTOR3(100.0f, 100.0f, 0.0f), D3DXVECTOR2(30.0f, 100.0f));
	m_timer->SetTimer(60);

	{
		D3DXVECTOR3 pos((float)CApplication::SCREEN_WIDTH - 60.0f, 60.0f, 0.0f);
		CClickItem* pauseItem = CClickItem::Create(pos,D3DXVECTOR2(75.0f,75.0));
		pauseItem->SetEvent([]()
		{
			CPause::Create();
		});
	}
}

//-----------------------------------------------------------------------------
// 終了
//-----------------------------------------------------------------------------
void CGame::Uninit()
{
	CMode::Uninit();
}

//-----------------------------------------------------------------------------
// 更新
//-----------------------------------------------------------------------------
void CGame::Update()
{
	if (m_countDown != nullptr)
	{
		if (m_countDown->GetTimer() <= 0)
		{
			m_countDown->Release();
			m_countDown = nullptr;
			m_state = GAME_NOW;
			GameStart();
		}
		return;
	}

	if (CInput::GetKey()->Trigger(DIK_P))
	{
		CPause::Create();
	}

	if (m_timer->GetTimer() <= 0 && !m_isResult)
	{
		m_isResult = true;
		m_timer->StopTimer(true);
		CResult::SetPlayMode(CApplication::GetInstance()->GetModeType());
		CFade::GetInstance()->NextMode(CMode::MODE_TYPE::RESULT);
	}
}
