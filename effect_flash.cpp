//=========================================
// 
// effect_flash.h
// Author Koduns Hirohito
// 
//=========================================
#include "effect_flash.h"
#include "texture.h"
#include <assert.h>

//=============================================================================
// �ÓI�}�N��
//=============================================================================
const int CEffectFlash::MAX_SIZE = 2000;									//�ő�T�C�Y
const float CEffectFlash::MIN_SIZE = 20.0f;									//�Œ�T�C�Y
const int CEffectFlash::MAX_SIZE_INCREASE = 400;							//�T�C�Y�̍ő呝����
const float CEffectFlash::MIN_SIZE_INCREASE = 1.0f;							//�T�C�Y�̍Œᑝ����
const int CEffectFlash::MAX_TRANSPARENCY_DECREASE_QUANTITY = 5;				//�����x�̌����ʂ̍ő�
const float CEffectFlash::MIN_TRANSPARENCY_DECREASE_QUANTITY = 0.05f;		//�����x�̌����ʂ̍Œ�
const int CEffectFlash::MAX_MOVING_LENGTH = 500;							//�ړ��ʂ̍ő�
const float CEffectFlash::MIN_MOVING_LENGTH = 1.0f;							//�ړ��ʂ̍Œ�

//int��100���v�Z������

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CEffectFlash::CEffectFlash() : CObject2D(CTaskGroup::LEVEL_2D_UI_EFFECT)
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CEffectFlash::~CEffectFlash()
{
}

//=============================================================================
// ������
//=============================================================================
HRESULT CEffectFlash::Init(D3DXVECTOR3 pos)
{
	//�e�N���X�̏�����
	if (FAILED(CObject2D::Init()))
	{
		assert(false);
	}

	//�|�[�Y���X�V
	SetPauseUpdate(true);

	//�e�N�X�`���̐ݒ�
	SetTexture("FLASH");

	//�T�C�Y
	float fSize = MIN_SIZE + rand() % MAX_SIZE * 0.01f;
	//�T�C�Y�̑�����
	m_fSizeIncrease = MIN_SIZE_INCREASE + rand() % MAX_SIZE_INCREASE * 0.01f;
	//�����x
	m_fTransparency = MIN_TRANSPARENCY_DECREASE_QUANTITY + rand() % MAX_TRANSPARENCY_DECREASE_QUANTITY * 0.01f;
	//����
	float fLength = MIN_MOVING_LENGTH + rand() % MAX_MOVING_LENGTH * 0.01f;
	//�ړ���
	int nRot = rand() % 360;
	D3DXVECTOR3 Move = {};
	Move.x = sinf(D3DXToRadian(nRot));
	Move.y = cosf(D3DXToRadian(nRot));
	Move.z = 0.0f;
	D3DXVec3Normalize(&Move,&Move);
	//�J���[
	D3DXCOLOR Color = {};
	Color.r = rand() % 10 * 0.1f;
	Color.g = rand() % 10 * 0.1f;
	Color.b = rand() % 10 * 0.1f;
	Color.a = 1.0f;

	//�T�C�Y
	SetSize(D3DXVECTOR2(fSize, fSize));

	//�ʒu
	SetPos(pos);

	//�ړ�
	SetMove(Move * fLength);

	//�F
	SetColor(Color);

	return S_OK;
}

//=============================================================================
// �I��
//=============================================================================
void CEffectFlash::Uninit()
{
	CObject2D::Uninit();
}

//=============================================================================
// �X�V
//=============================================================================
void CEffectFlash::Update()
{
	//�T�C�Y�̑���
	AddSize(D3DXVECTOR2(m_fSizeIncrease, m_fSizeIncrease));

	//�A���t�@�l��������
	AddColorAlpha(-m_fTransparency);

	//�e�N���X
	CObject2D::Update();

	//���S�ɓ����ɂȂ�Ɖ������
	if (GetColor().a <= 0.0f)
	{
		CEffectFlash::Uninit();
	}
}

//=============================================================================
// �N���X�̍쐬
//=============================================================================
CEffectFlash* CEffectFlash::Create(D3DXVECTOR3 pos)
{
	CEffectFlash* objectCreate = new CEffectFlash();

	if ((objectCreate == nullptr) || FAILED(objectCreate->Init(pos)))
	{
		assert(false);
	}

	return objectCreate;
}
