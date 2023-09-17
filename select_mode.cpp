//=============================================================================
// 
// �A�v���P�[�V�����N���X
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
// �R���X�g���N�^
//-----------------------------------------------------------------------------
CSelectMode::CSelectMode()
{
}

//-----------------------------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------------------------
CSelectMode::~CSelectMode()
{
}

//-----------------------------------------------------------------------------
// ������
//-----------------------------------------------------------------------------
HRESULT CSelectMode::Init()
{
	CModeGuidanceItem::Create(D3DXVECTOR3(350.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_MOVEOBJECT);
	CModeGuidanceItem::Create(D3DXVECTOR3(500.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_NUMBER25);
	CModeGuidanceItem::Create(D3DXVECTOR3(650.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_BUS);
	CModeGuidanceItem::Create(D3DXVECTOR3(800.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_REMEMBER_BEFORE);
	CModeGuidanceItem::Create(D3DXVECTOR3(350.0f, 350.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_COMEOUT);
	CModeGuidanceItem::Create(D3DXVECTOR3(500.0f, 350.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_SHADOW);

	return S_OK;
}

//-----------------------------------------------------------------------------
// �I��
//-----------------------------------------------------------------------------
void CSelectMode::Uninit()
{
}

//-----------------------------------------------------------------------------
// �X�V
//-----------------------------------------------------------------------------
void CSelectMode::Update()
{
}
