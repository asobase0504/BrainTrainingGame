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
m_nLargestNumber(0)
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
				CCorrection::Create(m_pDisplayObject[nCntNumber]->GetIsLargest());

				for (int j = 0; j < MAX_NUMBER + 1; j++)
				{
					m_isUsedNumber[j] = false;
				}

				for (int j = 0; j < DISPLAY_NUMBER; j++)
				{
					m_pDisplayObject[j]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
					m_pDisplayObject[j]->SetIsLargest(false);
				}

				m_nLargestNumber = 0;

				NumberLottery_();
				WhichiNumberLargest_();
			});

		}
	}
	NumberLottery_();
	WhichiNumberLargest_();

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
	if (CInput::GetKey()->Trigger(DIK_RETURN))
	{
		for (int i = 0; i < MAX_NUMBER + 1; i++)
		{
			m_isUsedNumber[i] = false;
		}

		for (int i = 0; i < DISPLAY_NUMBER; i++)
		{
			m_pDisplayObject[i]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			m_pDisplayObject[i]->SetIsLargest(false);
		}

		m_nLargestNumber = 0;

		NumberLottery_();
		WhichiNumberLargest_();
	}
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
void CLargeNumberSystem::WhichiNumberLargest_()
{
	for (int i = 0; i < DISPLAY_NUMBER; i++)
	{
		if (m_nLargestNumber < m_pDisplayObject[i]->GetMyNumber())
		{
			m_nLargestNumber = m_pDisplayObject[i]->GetMyNumber();
		}
	}

	for (int i = 0; i < DISPLAY_NUMBER; i++)
	{
		if (m_nLargestNumber == m_pDisplayObject[i]->GetMyNumber())
		{
			m_pDisplayObject[i]->SetIsLargest(true);
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
