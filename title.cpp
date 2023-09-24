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
#include "click_item.h"

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
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f));
		object->SetSize(D3DXVECTOR2(CApplication::CENTER_X * 2.0f, CApplication::CENTER_Y * 2.0f));
		object->SetTexture("BOOK_BG");
	}

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X + 500.0f, CApplication::CENTER_Y + 400, 0.0f));
		object->SetRot(0.8f);
		D3DXVECTOR2 size(354.0f * 0.25f, 2774.0f * 0.25f);
		object->SetSize(size);
		object->SetTexture("DECO_PEN_GREEN");
	}

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(20.0f, CApplication::CENTER_Y + 400, 0.0f));
		object->SetRot(D3DX_PI * -1.25f);
		D3DXVECTOR2 size(354.0f * 0.25f, 2774.0f * 0.25f);
		object->SetSize(size);
		object->SetTexture("DECO_PEN_RED");
	}

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X + 500.0f, CApplication::CENTER_Y - 300.0f, 0.0f));
		object->SetRot(0.8f);
		D3DXVECTOR2 size(652.0f * 0.45f, 317.0f * 0.45f);
		object->SetSize(size);
		object->SetColor(D3DXCOLOR(1.0f,1.0f,0.0f,1.0f));
		object->SetTexture("DECO_TAG");
	}
	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X + 500.0f, CApplication::CENTER_Y - 300.0f, 0.0f));
		object->SetRot(0.8f);
		D3DXVECTOR2 size(652.0f * 0.45f, 317.0f * 0.45f);
		object->SetSize(size);
		object->SetColor(D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
		object->SetTexture("DECO_TAG");
	}
	//{
	//	CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
	//	object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f));
	//	D3DXVECTOR2 size(354.0f * 0.15f, 2774.0f * 0.15f);
	//	object->SetSize(size);
	//	object->SetTexture("DECO_PEN_RED");
	//}

	{
		D3DXVECTOR3 pos(CApplication::CENTER_X + 250.0f, CApplication::CENTER_Y, 0.0f);
		D3DXVECTOR2 size(652.0f * 0.7f, 317.0f * 0.7f);
		CClickItem* object = CClickItem::Create(pos,size);
		object->SetTexture("TEXT_START");
		object->SetEvent([object]()
		{
			CFade::GetInstance()->NextMode(CMode::MODE_TYPE::SERECT_SAVE);
			object->SetColor(D3DXCOLOR(0.45f,0.45f,0.45f,1.0f));
		});
	}

	{
		CObject2D* object = CObject2D::Create();
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X - 240.0f, CApplication::CENTER_Y - 50.0f, 0.0f));
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
	if (CInput::GetKey()->Trigger(DIK_RETURN))
	{
		CFade::GetInstance()->NextMode(CMode::MODE_TYPE::SERECT_SAVE);
	}
}
