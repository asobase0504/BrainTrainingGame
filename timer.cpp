//==================================================
// timer.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "application.h"
#include "game.h"

#include "timer.h"
#include "number.h"

//**************************************************
// �ÓI�����o�ϐ�
//**************************************************

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
CTimer::CTimer(int nPriority) : CObject(nPriority)
{
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
CTimer::~CTimer()
{
}

//--------------------------------------------------
// ������
//--------------------------------------------------
HRESULT CTimer::Init()
{
	return S_OK;
}

//--------------------------------------------------
// �������@�I�[�o�[���[�h
//--------------------------------------------------
HRESULT CTimer::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	m_nTime = 0;
	m_bIsStop = false;
	m_nFrame = 0;
	m_nSceneFrame = 0;
	m_nCounter = 0;

	for (int nCnt = 0; nCnt < NUM_TIME; nCnt++)
	{
		m_pNumber[nCnt] = CNumber::Create(D3DXVECTOR3(size.x * nCnt + pos.x, pos.y, 0.0f), size);
		m_pNumber[nCnt]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		m_pNumber[nCnt]->SetTexture("TIME_NUMBER");
	}

	return S_OK;
}

//--------------------------------------------------
// �I��
//--------------------------------------------------
void CTimer::Uninit()
{
	for (int nCnt = 0; nCnt < NUM_TIME; nCnt++)
	{
		if (m_pNumber[nCnt] == nullptr)
		{
			continue;
		}

		m_pNumber[nCnt]->Release();
	}

	CObject::Release();
}

//--------------------------------------------------
// �X�V
//--------------------------------------------------
void CTimer::Update()
{
	if (!m_bIsStop)
	{
		//�t���[���J�E���^�[
		m_nCounter++;

		if (m_nCounter >= 60)
		{
			AddTimer(1);

			m_nCounter = 0;
		}
	}
}

//--------------------------------------------------
// �ʒu�̐ݒ�Ƒ傫���̐ݒ�
//--------------------------------------------------
void CTimer::SetPos(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	for (int nCnt = 0; nCnt < NUM_TIME; nCnt++)
	{
		m_pNumber[nCnt]->SetPos(D3DXVECTOR3(size.x * nCnt + pos.x, pos.y, 0.0f));
	}
}

//--------------------------------------------------
// �^�C���̐ݒ�
//--------------------------------------------------
void CTimer::SetTimer(int nTime)
{
	m_nTime = nTime;

	int aPosTexU[3];		//�e���̐������i�[

	{
		int timer = m_nTime;
		for (int i = 2; i >= 0; --i)
		{
			aPosTexU[i] = timer % 10;
			timer /= 10;
		}
	}

	// �e�N�X�`�����W�̐ݒ�
	for (int nCnt = 0; nCnt < NUM_TIME; nCnt++)
	{
		m_pNumber[nCnt]->AnimTexture(aPosTexU[nCnt], 10);
	}
}

//--------------------------------------------------
// ����
//--------------------------------------------------
CTimer *CTimer::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CTimer *pTimer;
	pTimer = new CTimer;

	if (pTimer != nullptr)
	{
		pTimer->Init(pos, size);
	}
	else
	{
		assert(false);
	}

	return pTimer;
}
