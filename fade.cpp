//=============================================================================
//
// �t�F�[�h�ݒ�
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
// �R���X�g���N�^
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
// �f�X�g���N�^
//=============================================================================
CFade::~CFade()
{
}

//=============================================================================
// ������
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
// �I��
//=============================================================================
void CFade::Uninit()
{
	CObject2D::Uninit();
}

//=============================================================================
// �X�V
//=============================================================================
void CFade::Update()
{
	CObject2D::Update();

	if (m_fade == FADENON)
	{
		return;
	}

	// ���݂̃��[�V�����ԍ��̕ۊ�
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
// ���̃��[�h�Ɉڍs
//=============================================================================
void CFade::NextMode(CMode::MODE_TYPE nextMode)
{
	if (m_fade != FADENON)
	{
		return;
	}

	/* ���t�F�[�h���ڍs����ꍇ�� */

	Init();
	m_nextMode = nextMode;
	SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));
	SetSize(D3DXVECTOR2((float)CApplication::SCREEN_WIDTH, (float)CApplication::SCREEN_HEIGHT));
	m_fade = FADEIN;
}
