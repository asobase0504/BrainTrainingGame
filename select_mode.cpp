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
	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f));
		object->SetSize(D3DXVECTOR2(CApplication::CENTER_X * 2.0f, CApplication::CENTER_Y * 2.0f));
		object->SetTexture("GREEN_BG");
	}

	CModeGuidanceItem* object;
	object = CModeGuidanceItem::Create(D3DXVECTOR3(100.0f, 100.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_NUMBER25);
	object = CModeGuidanceItem::Create(D3DXVECTOR3(250.0f, 100.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_REMEMBER_BEFORE);
	object->SetTexture("GAME_ICON_REMENBER");
	object = CModeGuidanceItem::Create(D3DXVECTOR3(400.0f, 100.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_COMEOUT);
	object = CModeGuidanceItem::Create(D3DXVECTOR3(550.0f, 100.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_SHADOW);
	object->SetTexture("GAME_ICON_SHADOW");
	object = CModeGuidanceItem::Create(D3DXVECTOR3(700.0f, 100.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_LARGE_NUMBER);

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
