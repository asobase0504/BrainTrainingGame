//=============================================================================
//
// フェード設定
// Author : Hamada Ryuuga
//
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <assert.h>
#include "fade.h"

CFade* CFade::m_instance = nullptr;

//=============================================================================
// コンストラクタ
//=============================================================================
CFade::CFade() : CObject2D(CTaskGroup::LEVEL_FADE)
{
}

CFade* CFade::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new CFade;
		m_instance->Init();
	}

	return m_instance;
}

//=============================================================================
// デストラクタ
//=============================================================================
CFade::~CFade()
{
}

//=============================================================================
// 初期化
//=============================================================================
HRESULT CFade::Init()
{
	CObject2D::Init();
	AttachProtect();
	m_fadeSp = 0.07f;
	m_fadeSet = 0.0f;
	m_nextMode = CMode::MODE_TYPE::TITLE;
	SetPos(D3DXVECTOR3(CApplication::SCREEN_WIDTH * 0.5f, CApplication::SCREEN_HEIGHT * 0.5f, 0.0f));
	SetSize(D3DXVECTOR2((float)CApplication::SCREEN_WIDTH, (float)CApplication::SCREEN_HEIGHT));
	SetPauseUpdate(true);
	SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));
	m_fade = FADENON;
	return S_OK;
}

//=============================================================================
// 終了
//=============================================================================
void CFade::Uninit()
{
	CObject2D::Uninit();
}

//=============================================================================
// 更新
//=============================================================================
void CFade::Update()
{
	CObject2D::Update();

	if (m_fade == FADENON)
	{
		return;
	}

	// 現在のモーション番号の保管
	if (m_fade == FADEOUT)
	{
		AddColorAlpha(-m_fadeSp);
	}

	if (m_fade == FADEIN)
	{
		AddColorAlpha(m_fadeSp);
	}

	if (GetColorAlpha() >= 1.0f)
	{
		m_fade = FADEOUT;
		SetColorAlpha(1.0f);
		CApplication::GetInstance()->SetMode(m_nextMode);

	}
	else if (GetColorAlpha() <= 0.0f)
	{
		m_fade = FADENON;
		SetColorAlpha(0.0f);
	}
}

//=============================================================================
// 次のモードに移行
//=============================================================================
void CFade::NextMode(CMode::MODE_TYPE nextMode)
{
	if (m_fade != FADENON)
	{
		return;
	}

	/* ↓フェードを移行する場合↓ */

	Init();
	m_nextMode = nextMode;
	SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR2((float)CApplication::SCREEN_WIDTH, (float)CApplication::SCREEN_HEIGHT));
	m_fade = FADEIN;
}
