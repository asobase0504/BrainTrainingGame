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
#include "sound.h"

// Object系統
#include "object2d.h"
#include "click_item.h"


#include "calendar.h"
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
	CApplication::GetInstance()->GetSound()->Play(CSound::LABEL_BGM_TITLE);

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
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X + 460.0f, CApplication::CENTER_Y - 290.0f, 0.0f));
		object->SetRot(0.9f);
		D3DXVECTOR2 size(652.0f * 0.45f, 317.0f * 0.45f);
		object->SetSize(size);
		object->SetColor(D3DXCOLOR(1.0f, 0.75f, 0.75f, 1.0f));
		object->SetTexture("DECO_TAG");
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
		D3DXVECTOR3 pos(CApplication::CENTER_X + 250.0f, CApplication::CENTER_Y - 100.0f, 0.0f);
		D3DXVECTOR2 size(652.0f * 0.5f, 317.0f * 0.5f);
		CClickItem* object = CClickItem::Create(pos,size);
		object->SetTexture("TEXT_START");
		object->SetColor(D3DXCOLOR(1.0f, 1.0f, 0.7f, 1.0f));
		object->SetEvent([object]()
		{
			CFade::GetInstance()->NextMode(CMode::MODE_TYPE::SERECT_MODE);
			object->SetColor(D3DXCOLOR(0.45f,0.45f,0.45f,1.0f));
		});
		object->SetEventTick([object, size]()
		{
			float mul = 1.0f + (sinf((object->GetTick() * 0.005f) * (D3DX_PI * 2.0f)) + 1.0f) * 0.5f * 0.05f;
			object->SetSize(size * mul);
		});
	}

	{
		D3DXVECTOR3 pos(CApplication::CENTER_X + 250.0f, CApplication::CENTER_Y + 75.0f, 0.0f);
		D3DXVECTOR2 size(652.0f * 0.4f, 317.0f * 0.4f);
		CClickItem* object = CClickItem::Create(pos, size);
		object->SetTexture("TEXT_END_GAME");
		object->SetColor(D3DXCOLOR(1.0f,0.7f,0.7f,1.0f));
		object->SetEvent([object]()
		{
			// ここに終わる処理書いて
			object->SetColor(D3DXCOLOR(0.45f, 0.45f, 0.45f, 1.0f));
		});
		object->SetEventTick([object, size]()
		{
			float mul = 1.0f + (sinf((object->GetTick() * 0.005f) * (D3DX_PI * 2.0f)) + 1.0f) * 0.5f * 0.05f;
			object->SetSize(size * mul);
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
		CFade::GetInstance()->NextMode(CMode::MODE_TYPE::SERECT_MODE);
	}
}
