//=============================================================================
// 
// �A�v���P�[�V�����N���X
// Author YudaKaito
// 
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "title.h"
#include <assert.h>

#include "application.h"
#include "mode_guidance_item.h"
#include "save_guidance_item.h"
#include "utility.h"

//-----------------------------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------------------------
CTitle::CTitle() : 
	m_status(CMode::MODE_TYPE::TITLE)
{
}

//-----------------------------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------------------------
CTitle::~CTitle()
{
}

//-----------------------------------------------------------------------------
// ������
//-----------------------------------------------------------------------------
HRESULT CTitle::Init()
{
	CModeGuidanceItem::Create(D3DXVECTOR3(350.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_MOVEOBJECT);
	CModeGuidanceItem::Create(D3DXVECTOR3(500.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_NUMBER25);
	CModeGuidanceItem::Create(D3DXVECTOR3(650.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_BUS);
	CModeGuidanceItem::Create(D3DXVECTOR3(800.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_REMEMBER_BEFORE);

	CSaveGuidanceItem* item;
	float xPos = 100.0f;
	for (int i = 0; i < 15;i++)
	{
		item = CSaveGuidanceItem::Create(D3DXVECTOR3(xPos + (147.0f * 0.5f * i), 200.0f, 0.0f), "aaaaa");
		item->SetColor(D3DXCOLOR(FloatRandom(1.0f, 0.0f), FloatRandom(1.0f, 0.0f), FloatRandom(1.0f,0.0f), 1.0f));
	}
	return S_OK;
}

//-----------------------------------------------------------------------------
// �I��
//-----------------------------------------------------------------------------
void CTitle::Uninit()
{
}

//-----------------------------------------------------------------------------
// �X�V
//-----------------------------------------------------------------------------
void CTitle::Update()
{
}

