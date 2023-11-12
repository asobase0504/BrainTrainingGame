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
#include "sequence.h"
#include "score_up.h"
#include "sound.h"
#include "save.h"

//-----------------------------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------------------------
CGame::CGame() : 
	m_state(COUNT_DOWN),
	m_score(0),
	m_level(0)
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
	m_level = 1;

	CApplication::GetInstance()->GetSound()->Play(CSound::LABEL_BGM_GAME);

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f));
		object->SetSize(D3DXVECTOR2(CApplication::CENTER_X * 2.0f, CApplication::CENTER_Y * 2.0f));
		object->SetTexture("GREEN_BG");
	}

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y * 1.05f, 0.0f));
		object->SetSize(D3DXVECTOR2(CApplication::CENTER_Y * 2.0f, CApplication::CENTER_Y * 1.9f));
		object->SetTexture("GAME_BG");
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
	{
		CObject2D* object = CObject2D::Create();
		object->SetPos(D3DXVECTOR3(60.0f, 90.0f, 0.0f));
		object->SetSize(D3DXVECTOR2(100.0f,100.0f));
		object->SetTexture("CLOCK");
	}
	m_timer = CTimer::Create(D3DXVECTOR3(160.0f, 95.0f, 0.0f), D3DXVECTOR2(45.0f, 140.0f));
	m_timer->SetTimer(60);

	{
		D3DXVECTOR3 pos((float)CApplication::SCREEN_WIDTH - 70.0f, 60.0f, 0.0f);
		CClickItem* pauseItem = CClickItem::Create(pos,D3DXVECTOR2(100.0f,100.0f));
		pauseItem->SetTexture("STOP_BUTTON");
		pauseItem->SetEvent([]()
		{
			CPause::Create();
		});
	}

	{
		m_scoreUI = CSequence::Create(D3DXVECTOR3(140.0f, 210.0f, 0.0f), D3DXVECTOR2(40.0f, 120.0f),3);
		m_scoreUI->SetNumber(m_score);
		m_scoreUI->SetColor(D3DXCOLOR(1.0f,1.0f,1.0f,1.0f));
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
		CResult::SetScore(m_score);

		//スコアを書き出し
		CSave::SaveScore(m_score);

		CFade::GetInstance()->NextMode(CMode::MODE_TYPE::RESULT);
	}
}

void CGame::AddScore(const int inScore)
{
	int addScore = inScore;
	m_score += inScore;
	m_scoreUI->AddNumber(inScore);

	if (m_score <= 0)
	{
		addScore = (m_score - inScore) * -1.0f;
		m_score = 0;
		m_scoreUI->SetNumber(0);
	}

	D3DXVECTOR3 pos(m_scoreUI->GetPos());
	pos.y -= 40.0f;
	pos.x += 25.0f;
	CScoreUp::Create(pos, addScore);
}
