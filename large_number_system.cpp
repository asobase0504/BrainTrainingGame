//==================================================
// large_number_system.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "large_number_system.h"

#include "application.h"
#include "input.h"
#include "utility.h"

#include "correction.h"
#include "largest_number.h"

//**************************************************
// �萔��`
//**************************************************
const int CLargeNumberSystem::X_LINE = 2;
const int CLargeNumberSystem::Y_LINE = 3;
const int CLargeNumberSystem::DISPLAY_NUMBER = X_LINE * Y_LINE;
const int CLargeNumberSystem::MAX_NUMBER = 99;

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
CLargeNumberSystem::CLargeNumberSystem(int nPriority) : CObject(nPriority),
m_nMaxNumber(0), m_nMinNumber(999), m_minOrMax(0), m_mode(false)
{
	m_pDisplayObject.clear();
	m_isUsedNumber.clear();
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
CLargeNumberSystem::~CLargeNumberSystem()
{
}

//--------------------------------------------------
// ������
//--------------------------------------------------
HRESULT CLargeNumberSystem::Init()
{
	m_pDisplayObject.resize(DISPLAY_NUMBER);
	m_isUsedNumber.resize(MAX_NUMBER + 1);

	m_minOrMax = IntRandom(6, 1);

	for (int nCntY = 0; nCntY < Y_LINE; nCntY++)
	{
		for (int nCntX = 0; nCntX < X_LINE; nCntX++)
		{
			int nCntNumber = nCntY * X_LINE + nCntX;
			m_pDisplayObject[nCntNumber] = CLargestNumber::Create(
				D3DXVECTOR3(CApplication::SCREEN_WIDTH * 0.25f + 120.0f * nCntNumber,
					CApplication::SCREEN_HEIGHT * 0.5f, 0.0f),
				D3DXVECTOR2(100.0f, 100.0f));
			m_pDisplayObject[nCntNumber]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			m_pDisplayObject[nCntNumber]->SetTexture("DECO_TAG");
			m_pDisplayObject[nCntNumber]->SetEvent([this, nCntNumber]()
			{
				CorrectAnswer_(nCntNumber);
				InitCreateAnswer_();
				SetMode();
			});
		}
	}
	SetMode();

	return S_OK;
}

//--------------------------------------------------
// �I��
//--------------------------------------------------
void CLargeNumberSystem::Uninit()
{
}

//--------------------------------------------------
// �X�V
//--------------------------------------------------
void CLargeNumberSystem::Update()
{
}

//--------------------------------------------------
// �`��
//--------------------------------------------------
void CLargeNumberSystem::Draw()
{
}

//--------------------------------------------------
// ����
//--------------------------------------------------
CLargeNumberSystem *CLargeNumberSystem::Create()
{
	CLargeNumberSystem *pLargeNumberSystem;
	pLargeNumberSystem = new CLargeNumberSystem;

	if (pLargeNumberSystem != nullptr)
	{
		pLargeNumberSystem->Init();
	}
	else
	{
		assert(false);
	}

	return pLargeNumberSystem;
}

//--------------------------------------------------
// �ǂꂪ�傫������
//--------------------------------------------------
void CLargeNumberSystem::WhichiNumberMax_()
{
	for (int i = 0; i < DISPLAY_NUMBER; i++)
	{
		if (m_nMaxNumber < m_pDisplayObject[i]->GetMyNumber())
		{
			m_nMaxNumber = m_pDisplayObject[i]->GetMyNumber();
		}
	}

	for (int i = 0; i < DISPLAY_NUMBER; i++)
	{
		if (m_nMaxNumber == m_pDisplayObject[i]->GetMyNumber())
		{
			m_pDisplayObject[i]->SetIsMax(true);
			m_pDisplayObject[i]->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
		}
	}
}

//--------------------------------------------------
// ���̒��I
//--------------------------------------------------
void CLargeNumberSystem::WhichiNumberMin_()
{
	for (int i = 0; i < DISPLAY_NUMBER; i++)
	{
		if (m_nMinNumber > m_pDisplayObject[i]->GetMyNumber())
		{
			m_nMinNumber = m_pDisplayObject[i]->GetMyNumber();
		}
	}

	for (int i = 0; i < DISPLAY_NUMBER; i++)
	{
		if (m_nMinNumber == m_pDisplayObject[i]->GetMyNumber())
		{
			m_pDisplayObject[i]->SetIsMin(true);
			m_pDisplayObject[i]->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
		}
	}
}

//--------------------------------------------------
// ���̒��I
//--------------------------------------------------
void CLargeNumberSystem::NumberLottery_()
{
	int myNumber = 0;
	myNumber = IntRandom(MAX_NUMBER, 1);

	for (int i = 0; i < DISPLAY_NUMBER; i++)
	{
		while (m_isUsedNumber[myNumber])
		{
			myNumber = IntRandom(MAX_NUMBER, 1);
		}

		m_isUsedNumber[myNumber] = true;

		m_pDisplayObject[i]->SetMyNumber(myNumber);
		m_pDisplayObject[i]->SetSequence(myNumber);
	}
}

//--------------------------------------------------
// ���[�h�̕���
//--------------------------------------------------
void CLargeNumberSystem::SetMode()
{
	if (m_minOrMax % 2 == 0)
	{// �ő�
		NumberLottery_();
		WhichiNumberMax_();
		m_mode = true;
	}
	else if (m_minOrMax % 2 != 0)
	{// �ŏ�
		NumberLottery_();
		WhichiNumberMin_();
		m_mode = false;
	}
}

//--------------------------------------------------
// �����̏�����
//--------------------------------------------------
void CLargeNumberSystem::InitCreateAnswer_()
{
	for (int j = 0; j < MAX_NUMBER + 1; j++)
	{
		m_isUsedNumber[j] = false;
	}

	for (int j = 0; j < DISPLAY_NUMBER; j++)
	{
		m_pDisplayObject[j]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		m_pDisplayObject[j]->SetIsMax(false);
		m_pDisplayObject[j]->SetIsMin(false);
	}

	m_nMaxNumber = 0;
	m_nMinNumber = 999;
	m_minOrMax = IntRandom(6, 1);
}

//--------------------------------------------------
// ���������������ǂ���
//--------------------------------------------------
void CLargeNumberSystem::CorrectAnswer_(int inNumber)
{
	if (m_mode)
	{// �ő�
		CCorrection::Create(m_pDisplayObject[inNumber]->GetIsMax());
	}
	else
	{// �ŏ�
		CCorrection::Create(m_pDisplayObject[inNumber]->GetIsMin());
	}
}
