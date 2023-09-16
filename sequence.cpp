//==================================================
// score
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "application.h"

#include "sequence.h"
#include "number.h"

//**************************************************
// �ÓI�����o�ϐ�
//**************************************************

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
CSequence::CSequence(int nPriority) : CObject(CTaskGroup::LEVEL_3D_UI)
{
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
CSequence::~CSequence()
{
}

//--------------------------------------------------
// ������
//--------------------------------------------------
HRESULT CSequence::Init()
{
	return S_OK;
}

//--------------------------------------------------
// �������@�I�[�o�[���[�h
//--------------------------------------------------
HRESULT CSequence::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	m_pNumber.resize(3);

	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		m_pNumber[nCnt] = CNumber::Create(D3DXVECTOR3(size.x * nCnt + pos.x, pos.y, 0.0f), size);
		m_pNumber[nCnt]->SetColor(D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
		m_pNumber[nCnt]->SetTexture("TIME_NUMBER");
	}

	return S_OK;
}

//--------------------------------------------------
// �I��
//--------------------------------------------------
void CSequence::Uninit()
{
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		if (m_pNumber[nCnt] == nullptr)
		{
			continue;
		}

		m_pNumber[nCnt]->Release();
		m_pNumber[nCnt] = nullptr;
	}

	CObject::Release();
}

//--------------------------------------------------
// �X�V
//--------------------------------------------------
void CSequence::Update()
{
}

//--------------------------------------------------
// �ʒu�̐ݒ�Ƒ傫���̐ݒ�
//--------------------------------------------------
void CSequence::SetPos(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		m_pNumber[nCnt]->SetPos(D3DXVECTOR3(size.x * nCnt + pos.x, pos.y, 0.0f));
	}
}

void CSequence::SetNumber(int inNumber)
{
	m_number = inNumber;

	int aPosTexU[3];		//�e���̐������i�[

	{
		int timer = inNumber;
		for (int i = 2; i >= 0; --i)
		{
			aPosTexU[i] = timer % 10;
			timer /= 10;
		}
	}

	// �e�N�X�`�����W�̐ݒ�
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		m_pNumber[nCnt]->AnimTexture(aPosTexU[nCnt], 10);
	}
}

//--------------------------------------------------
// ����
//--------------------------------------------------
CSequence *CSequence::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CSequence *pTimer;
	pTimer = new CSequence;

	assert(pTimer != nullptr);

	pTimer->Init(pos, size);

	return pTimer;
}
