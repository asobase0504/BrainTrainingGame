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
CSequence::CSequence() : CObject(CTaskGroup::LEVEL_SYSTEM)
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
HRESULT CSequence::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size,const int digit)
{
	m_digit = digit;
	m_pNumber.resize(m_digit);

	for (int nCnt = 0; nCnt < m_digit; nCnt++)
	{
		m_pNumber[nCnt] = CNumber::Create(D3DXVECTOR3(size.x * nCnt + pos.x, pos.y, 0.0f), size);
		m_pNumber[nCnt]->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
		m_pNumber[nCnt]->SetTexture("TIME_NUMBER");
	}

	SetPos(pos);

	return S_OK;
}

//--------------------------------------------------
// �I��
//--------------------------------------------------
void CSequence::Uninit()
{
	for (int nCnt = 0; nCnt < m_digit; nCnt++)
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
void CSequence::SetPos(const D3DXVECTOR3& inPos)
{
	CObject::SetPos(inPos);

	for (int nCnt = 0; nCnt < m_digit; nCnt++)
	{
		m_pNumber[nCnt]->SetPos(D3DXVECTOR3(m_pNumber[nCnt]->GetSize().x * ((float)nCnt - (m_digit - 1) * 0.5f) + inPos.x, inPos.y, 0.0f));
	}
}

void CSequence::SetColor(const D3DXCOLOR & inColor)
{
	for (int nCnt = 0; nCnt < m_digit; nCnt++)
	{
		m_pNumber[nCnt]->SetColor(inColor);
	}
}

void CSequence::AddColor(const D3DXCOLOR & inColor)
{
	for (int nCnt = 0; nCnt < m_digit; nCnt++)
	{
		m_pNumber[nCnt]->SetColor(inColor + m_pNumber[nCnt]->GetColor());
	}
}

void CSequence::SetColorAlpha(const float & inAlpha)
{
	for (int nCnt = 0; nCnt < m_digit; nCnt++)
	{
		m_pNumber[nCnt]->SetColorAlpha(inAlpha);
	}
}

void CSequence::SetSize(const D3DXVECTOR2 & inSize)
{
	for (int nCnt = 0; nCnt < m_digit; nCnt++)
	{
		m_pNumber[nCnt]->SetSize(inSize);
	}
	SetPos(m_pos);
}

void CSequence::AddSize(const D3DXVECTOR2 & inSize)
{
	for (int nCnt = 0; nCnt < m_digit; nCnt++)
	{
		m_pNumber[nCnt]->AddSize(inSize);
	}
}

void CSequence::SetNumber(int inNumber)
{
	m_number = inNumber;

	std::vector<int> aPosTexU;		//�e���̐������i�[
	aPosTexU.resize(m_digit);

	{
		int timer = inNumber;
		for (int i = m_digit-1; i >= 0; --i)
		{
			aPosTexU[i] = timer % 10;
			timer /= 10;
		}
	}

	// �e�N�X�`�����W�̐ݒ�
	for (int nCnt = 0; nCnt < m_digit; nCnt++)
	{
		m_pNumber[nCnt]->AnimTexture(aPosTexU[nCnt], 10);
	}
}

//--------------------------------------------------
// ����
//--------------------------------------------------
CSequence *CSequence::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size, int digit)
{
	CSequence *pTimer;
	pTimer = new CSequence;

	assert(pTimer != nullptr);

	pTimer->Init(pos, size, digit);

	return pTimer;
}
