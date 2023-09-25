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

//-----------------------------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------------------------
CSelectMode::CSelectMode()
{
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

	CModeGuidanceItem* object;
	object = CModeGuidanceItem::Create(D3DXVECTOR3(425.0f, 320.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_REMEMBER_BEFORE);
	object->SetModeTexture("GAME_ICON_REMENBER", "TEXT_EXPO_REMEMBER");
	object = CModeGuidanceItem::Create(D3DXVECTOR3(975.0f, 320.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_SHADOW);
	object->SetModeTexture("GAME_ICON_SHADOW", "TEXT_EXPO_SHADOW");
	object = CModeGuidanceItem::Create(D3DXVECTOR3(425.0f, 600.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_COMEOUT);
	object = CModeGuidanceItem::Create(D3DXVECTOR3(975.0f, 600.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_LARGE_NUMBER);
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
