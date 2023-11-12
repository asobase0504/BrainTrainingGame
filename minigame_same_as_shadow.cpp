//=============================================================================
// 
// �~�j�Q�[���F�����Ɠ������̂͂ǂ�
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
// �R���X�g���N�^
//-----------------------------------------------------------------------------
CMiniGameSameAsShadow::CMiniGameSameAsShadow()
{
}

//-----------------------------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------------------------
CMiniGameSameAsShadow::~CMiniGameSameAsShadow()
{
}

//-----------------------------------------------------------------------------
// ������
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
// �Q�[���J�n
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
// �I��
//-----------------------------------------------------------------------------
void CMiniGameSameAsShadow::Uninit()
{
}

//-----------------------------------------------------------------------------
// �X�V
//-----------------------------------------------------------------------------
void CMiniGameSameAsShadow::Update()
{
	CGame::Update();
}

//-----------------------------------------------------------------------------
// �`��
//-----------------------------------------------------------------------------
void CMiniGameSameAsShadow::Draw()
{
}
