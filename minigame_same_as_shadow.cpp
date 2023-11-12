//=============================================================================
// 
// ミニゲーム：かげと同じものはどれ
// Author BuriyaKota
// 
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "minigame_same_as_shadow.h"

#include "same_as_shadow_system.h"
#include "object2d.h"
#include "application.h"

//-----------------------------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------------------------
CMiniGameSameAsShadow::CMiniGameSameAsShadow()
{
}

//-----------------------------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------------------------
CMiniGameSameAsShadow::~CMiniGameSameAsShadow()
{
}

//-----------------------------------------------------------------------------
// 初期化
//-----------------------------------------------------------------------------
HRESULT CMiniGameSameAsShadow::Init()
{
	CGame::Init();

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y - 300.0f, 0.0f));
		D3DXVECTOR2 size(1292.0f * 0.4f, 252.0f * 0.4f);
		object->SetSize(size);
		object->SetTexture("TEXT_EXPO_SHADOW");
	}

	return S_OK;
}

//-----------------------------------------------------------------------------
// ゲーム開始
//-----------------------------------------------------------------------------
void CMiniGameSameAsShadow::GameStart()
{
	CGame::GameStart();

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y - 70.0f, 0.0f));
		object->SetSize(D3DXVECTOR2(CApplication::CENTER_Y * 1.1f, CApplication::CENTER_Y * 0.9f));
		object->SetColor(D3DXCOLOR(0.0f,0.45f,0.0f,1.0f));
		object->SetTexture("BLOCK_BG");
	}

	CSameAsShadowSystem::Create(this);
}

//-----------------------------------------------------------------------------
// 終了
//-----------------------------------------------------------------------------
void CMiniGameSameAsShadow::Uninit()
{
}

//-----------------------------------------------------------------------------
// 更新
//-----------------------------------------------------------------------------
void CMiniGameSameAsShadow::Update()
{
	CGame::Update();
}

//-----------------------------------------------------------------------------
// 描画
//-----------------------------------------------------------------------------
void CMiniGameSameAsShadow::Draw()
{
}
