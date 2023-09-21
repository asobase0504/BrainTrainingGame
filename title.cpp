//=============================================================================
// 
// アプリケーションクラス
// Author YudaKaito
// 
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "title.h"
#include "application.h"
#include "utility.h"
#include "input.h"
#include "fade.h"

// Object系統
#include "object2d.h"

//-----------------------------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------------------------
CTitle::CTitle()
{
}

//-----------------------------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------------------------
CTitle::~CTitle()
{
}

//-----------------------------------------------------------------------------
// 初期化
//-----------------------------------------------------------------------------
HRESULT CTitle::Init()
{
	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f));
		object->SetSize(D3DXVECTOR2(CApplication::CENTER_X * 2.0f, CApplication::CENTER_Y * 2.0f));
		object->SetTexture("GREEN_BG");
	}

	{
		CObject2D* object = CObject2D::Create();
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y - 100.0f, 0.0f));
		object->SetSize(D3DXVECTOR2(587.0f * 1.2f, 419.0f * 1.2f));
		object->SetTexture("TITLE_LOGO");
	}

	return S_OK;
}

//-----------------------------------------------------------------------------
// 更新
//-----------------------------------------------------------------------------
void CTitle::Update()
{
	if (CInput::GetKey()->Trigger(DIK_RETURN) || CInput::GetKey()->Trigger(MOUSE_KEY::MOUSE_INPUT_LEFT))
	{
		CFade::GetInstance()->NextMode(CMode::MODE_TYPE::SERECT_SAVE);
	}
}
