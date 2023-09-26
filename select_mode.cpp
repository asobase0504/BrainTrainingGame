//=============================================================================
// 
// アプリケーションクラス
// Author YudaKaito
// 
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "select_mode.h"
#include "application.h"
#include "utility.h"
#include "sound.h"

#include "result.h"
#include "mode_guidance_item.h"
#include "sequence.h"
#include "save.h"
#include "fade.h"

//-----------------------------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------------------------
CSelectMode::CSelectMode()
{
	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		m_pHiScore[nCnt] = NULL;
	}
}

//-----------------------------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------------------------
CSelectMode::~CSelectMode()
{
}

//-----------------------------------------------------------------------------
// 初期化
//-----------------------------------------------------------------------------
HRESULT CSelectMode::Init()
{
	CApplication::GetInstance()->GetSound()->Play(CSound::LABEL_BGM_TITLE);

	{
		D3DXVECTOR3 pos(70.0f, 60.0f, 0.0f);
		CClickItem* item = CClickItem::Create(pos, D3DXVECTOR2(100.0f, 100.0f));
		item->SetTexture("TITLE_BUTTON");
		item->SetEvent([]()
		{
			CFade::GetInstance()->NextMode(CMode::MODE_TYPE::TITLE);
		});
	}

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f));
		object->SetSize(D3DXVECTOR2(CApplication::CENTER_X * 2.0f, CApplication::CENTER_Y * 2.0f));
		object->SetTexture("GREEN_BG");
	}

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y + 20.0f, 0.0f));
		object->SetSize(D3DXVECTOR2(587.0f * 1.6f, 419.0f * 1.6f));
		object->SetColorAlpha(0.25f);
		object->SetTexture("TITLE_LOGO");
	}

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, 70.0f, 0.0f));
		D3DXVECTOR2 size(1292.0f * 0.5f, 252.0f * 0.5f);
		object->SetSize(size);
		object->SetTexture("TEXT_EXPO");
	}

	// 前回
	m_remenber = CModeGuidanceItem::Create(D3DXVECTOR3(425.0f, 320.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_REMEMBER_BEFORE);
	m_remenber->SetModeTexture("GAME_ICON_REMENBER", "TEXT_EXPO_REMEMBER");
	m_remenber->SetMode(this);
	{
		CObject2D* item = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_UI);
		item->SetPos(D3DXVECTOR3(345.0f, 240.0f, 0.0f));
		item->SetSize(D3DXVECTOR2(120.0f * 0.6f, 105.0f * 0.6f));
		item->SetTexture("HI_SCORE");
	}

	m_pHiScore[0] = CSequence::Create(D3DXVECTOR3(425.0f, 240.0f, 0.0f), D3DXVECTOR2(30.0f, 80.0f), 3);
	m_pHiScore[0]->SetNumber(CSave::GetHiScore(CMode::MODE_TYPE::MINIGAME_REMEMBER_BEFORE));
	m_pHiScore[0]->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	
	// 影
	m_shadow = CModeGuidanceItem::Create(D3DXVECTOR3(975.0f, 320.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_SHADOW);
	m_shadow->SetModeTexture("GAME_ICON_SHADOW", "TEXT_EXPO_SHADOW");
	m_shadow->SetMode(this);
	{
		CObject2D* item = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_UI);
		item->SetPos(D3DXVECTOR3(895.0f, 240.0f, 0.0f));
		item->SetSize(D3DXVECTOR2(120.0f * 0.6f, 105.0f * 0.6f));
		item->SetTexture("HI_SCORE");
	}
	m_pHiScore[1] = CSequence::Create(D3DXVECTOR3(975.0f, 240.0f, 0.0f), D3DXVECTOR2(30.0f, 80.0f), 3);
	m_pHiScore[1]->SetNumber(CSave::GetHiScore(CMode::MODE_TYPE::MINIGAME_SHADOW));
	m_pHiScore[1]->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	// 出た順
	m_comeout = CModeGuidanceItem::Create(D3DXVECTOR3(425.0f, 600.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_COMEOUT);
	m_comeout->SetModeTexture("GAME_ICON_COMEOUT", "TEXT_EXPO_COMEOUT");
	m_comeout->SetMode(this);
	{
		CObject2D* item = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_UI);
		item->SetPos(D3DXVECTOR3(345.0f, 520.0f, 0.0f));
		item->SetSize(D3DXVECTOR2(120.0f * 0.6f, 105.0f * 0.6f));
		item->SetTexture("HI_SCORE");
	}
	m_pHiScore[2] = CSequence::Create(D3DXVECTOR3(425.0f, 520.0f, 0.0f), D3DXVECTOR2(30.0f, 80.0f), 3);
	m_pHiScore[2]->SetNumber(CSave::GetHiScore(CMode::MODE_TYPE::MINIGAME_COMEOUT));
	m_pHiScore[2]->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	// 大きい数
	m_large = CModeGuidanceItem::Create(D3DXVECTOR3(975.0f, 600.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_LARGE_NUMBER);
	m_large->SetModeTexture("GAME_ICON_LARGE", "TEXT_EXPO_LARGE");
	m_large->SetMode(this);
	{
		CObject2D* item = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_UI);
		item->SetPos(D3DXVECTOR3(895.0f, 520.0f, 0.0f));
		item->SetSize(D3DXVECTOR2(120.0f * 0.6f, 105.0f * 0.6f));
		item->SetTexture("HI_SCORE");
	}
	m_pHiScore[3] = CSequence::Create(D3DXVECTOR3(975.0f, 520.0f, 0.0f), D3DXVECTOR2(30.0f, 80.0f), 3);
	m_pHiScore[3]->SetNumber(CSave::GetHiScore(CMode::MODE_TYPE::MINIGAME_LARGE_NUMBER));
	m_pHiScore[3]->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	return S_OK;
}

//-----------------------------------------------------------------------------
// 終了
//-----------------------------------------------------------------------------
void CSelectMode::Uninit()
{
}

//-----------------------------------------------------------------------------
// 更新
//-----------------------------------------------------------------------------
void CSelectMode::Update()
{
}

void CSelectMode::OffClick()
{
	m_remenber->OffClickEvent();
	m_shadow->OffClickEvent();
	m_comeout->OffClickEvent();
	m_large->OffClickEvent();
}

void CSelectMode::OnClick()
{
	m_remenber->OnClickEvent();
	m_shadow->OnClickEvent();
	m_comeout->OnClickEvent();
	m_large->OnClickEvent();
}
