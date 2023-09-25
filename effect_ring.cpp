//=========================================
// 
// �I�u�W�F�N�g�N���X
// Author YudaKaito
// 
//=========================================
#include "effect_ring.h"
#include "texture.h"
#include <assert.h>

//=============================================================================
// �ÓI�}�N��
//=============================================================================
const float CEffectRing::INITIAL_SIZE = 20.0f;
const float CEffectRing::SIZE_INCREASE = 2.0f;
const float CEffectRing::TRANSPARENCY_DECREASE_QUANTITY = 0.04f;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CEffectRing::CEffectRing() : CObject2D(CTaskGroup::LEVEL_2D_UI_EFFECT)
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CEffectRing::~CEffectRing()
{
}

//=============================================================================
// ������
//=============================================================================
HRESULT CEffectRing::Init(D3DXVECTOR3 pos)
{
	//�e�N���X�̏�����
	if (FAILED(CObject2D::Init()))
	{
		assert(false);
	}

	//�|�[�Y���X�V
	SetPauseUpdate(true);

	//�e�N�X�`���̐ݒ�
	SetTexture("RING");

	//�T�C�Y
	SetSize(D3DXVECTOR2(INITIAL_SIZE, INITIAL_SIZE));

	//�ʒu
	SetPos(pos);

	return S_OK;
}

//=============================================================================
// �I��
//=============================================================================
void CEffectRing::Uninit()
{
	CObject2D::Uninit();
}

//=============================================================================
// �X�V
//=============================================================================
void CEffectRing::Update()
{
	//�T�C�Y�̑���
	AddSize(D3DXVECTOR2(SIZE_INCREASE, SIZE_INCREASE));

	//�A���t�@�l��������
	AddColorAlpha(-TRANSPARENCY_DECREASE_QUANTITY);

	//�e�N���X
	CObject2D::Update();

	//���S�ɓ����ɂȂ�Ɖ������
	if (GetColor().a <= 0.0f)
	{
		CEffectRing::Uninit();
	}
}

//=============================================================================
// �N���X�̍쐬
//=============================================================================
CEffectRing* CEffectRing::Create(D3DXVECTOR3 pos)
{
	CEffectRing* objectCreate = new CEffectRing();

	if ((objectCreate == nullptr) || FAILED(objectCreate->Init(pos)))
	{
		assert(false);
	}

	return objectCreate;
}
