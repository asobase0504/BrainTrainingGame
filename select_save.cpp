//=============================================================================
// 
// �A�v���P�[�V�����N���X
// Author YudaKaito
// 
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "select_save.h"
#include <assert.h>

#include "application.h"
#include "mode_guidance_item.h"
#include "save_guidance_item.h"
#include "utility.h"

//-----------------------------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------------------------
CSelectSave::CSelectSave() :
	m_isSelectSaveData(false)
{
}

//-----------------------------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------------------------
CSelectSave::~CSelectSave()
{
}

//-----------------------------------------------------------------------------
// ������
//-----------------------------------------------------------------------------
HRESULT CSelectSave::Init()
{
	CModeGuidanceItem::Create(D3DXVECTOR3(350.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_MOVEOBJECT);
	CModeGuidanceItem::Create(D3DXVECTOR3(500.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_NUMBER25);
	CModeGuidanceItem::Create(D3DXVECTOR3(650.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_BUS);
	CModeGuidanceItem::Create(D3DXVECTOR3(800.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_REMEMBER_BEFORE);

	m_itemSaveGuidance.resize(15);

	float xPos = 100.0f;

	for (int i = 0; i < 15; i++)
	{
		m_itemSaveGuidance[i] = CSaveGuidanceItem::Create(D3DXVECTOR3(xPos + (147.0f * 0.5f * i), CApplication::CENTER_Y, 0.0f), "aaaaa");

		//Debug�p
		m_itemSaveGuidance[i]->SetColor(D3DXCOLOR(FloatRandom(1.0f, 0.0f), FloatRandom(1.0f, 0.0f), FloatRandom(1.0f, 0.0f), 1.0f));
	}

	return S_OK;
}

//-----------------------------------------------------------------------------
// �I��
//-----------------------------------------------------------------------------
void CSelectSave::Uninit()
{
}

//-----------------------------------------------------------------------------
// �X�V
//-----------------------------------------------------------------------------
void CSelectSave::Update()
{
	if (!m_isSelectSaveData)
	{
		for (int i = 0; i < 15; i++)
		{
			if (m_itemSaveGuidance[i]->IsSelect())
			{
				m_isSelectSaveData = true;
			}
		}
	}
}