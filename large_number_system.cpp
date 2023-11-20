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

#include "game.h"

//**************************************************
// �萔��`
//**************************************************
int CLargeNumberSystem::X_LINE = 3;
int CLargeNumberSystem::Y_LINE = 3;
int CLargeNumberSystem::DISPLAY_NUMBER = X_LINE * Y_LINE;
const int CLargeNumberSystem::MAX_NUMBER = 99;
const int CLargeNumberSystem::TRUE_FLAME = 10;
const int CLargeNumberSystem::FALSE_FLAME = 30;

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
CLargeNumberSystem::CLargeNumberSystem(int nPriority) : CObject(nPriority),
m_nMaxNumber(0), m_nMinNumber(999), m_minOrMax(0), m_mode(false), m_rug(0), m_isTrue(false), m_frame(0)
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
	m_oldLevel = 0;
	m_correct = 0;

	Reset_();
	m_isUsedNumber.resize(MAX_NUMBER + 1);

	m_minOrMax = IntRandom(6, 1);

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
CLargeNumberSystem *CLargeNumberSystem::Create(CGame* inGame)
{
	CLargeNumberSystem *pLargeNumberSystem;
	pLargeNumberSystem = new CLargeNumberSystem;

	if (pLargeNumberSystem != nullptr)
	{
		pLargeNumberSystem->m_game = inGame;
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
		}
	}
}

//--------------------------------------------------
// ���̒��I
//--------------------------------------------------
void CLargeNumberSystem::NumberLottery_()
{
	int myNumber = 0;
	myNumber = IntRandom(MAX_NUMBER, 10);

	for (int i = 0; i < DISPLAY_NUMBER; i++)
	{
		while (m_isUsedNumber[myNumber])
		{
			myNumber = IntRandom(MAX_NUMBER, 10);
		}

		m_isUsedNumber[myNumber] = true;

		m_pDisplayObject[i]->SetMyNumber(myNumber);
		m_pDisplayObject[i]->SetSequence(myNumber);
		m_pDisplayObject[i]->Reset();
	}
}

//--------------------------------------------------
// ���[�h�̕���
//--------------------------------------------------
void CLargeNumberSystem::SetMode()
{
	Reset_();

	if (m_minOrMax % 2 == 0)
	{// �ő�
		NumberLottery_();
		WhichiNumberMax_();
		m_mode = true;

		for (int nCntY = 0; nCntY < Y_LINE; nCntY++)
		{
			for (int nCntX = 0; nCntX < X_LINE; nCntX++)
			{
				int nCntNumber = nCntY * X_LINE + nCntX;
				m_pDisplayObject[nCntNumber]->SetColor(D3DXCOLOR(1.0f, 0.75f, 0.75f, 1.0f));
			}
		}
	}
	else if (m_minOrMax % 2 != 0)
	{// �ŏ�
		NumberLottery_();
		WhichiNumberMin_();
		m_mode = false;

		for (int nCntY = 0; nCntY < Y_LINE; nCntY++)
		{
			for (int nCntX = 0; nCntX < X_LINE; nCntX++)
			{
				int nCntNumber = nCntY * X_LINE + nCntX;
				m_pDisplayObject[nCntNumber]->SetColor(D3DXCOLOR(0.75f, 0.75f, 1.0f, 1.0f));
			}
		}
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
		m_pDisplayObject[j]->SetColorAlpha(1.0f);
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
	bool answer = false;
	if (m_mode)
	{// �ő�
		if (m_pDisplayObject[inNumber]->GetIsMax())
		{// �������Ȃ�
			for (int i = 0; i < DISPLAY_NUMBER; i++)
			{
				if (m_pDisplayObject[i]->GetIsMin())
				{
					continue;
				}

				m_pDisplayObject[i]->SetColorAlpha(0.3f);
			}
		}
		else
		{
			for (int i = 0; i < DISPLAY_NUMBER; i++)
			{
				if (m_pDisplayObject[i]->GetIsMax())
				{
					continue;
				}

				m_pDisplayObject[i]->SetColorAlpha(0.3f);
			}
		}

		answer = m_pDisplayObject[inNumber]->GetIsMax();
		CCorrection::Create(answer);

		m_game->AddScore(answer ? 10 : -5);
	}
	else
	{// �ŏ�
		if (m_pDisplayObject[inNumber]->GetIsMin())
		{// �������Ȃ�
			for (int i = 0; i < DISPLAY_NUMBER; i++)
			{
				if (m_pDisplayObject[i]->GetIsMin())
				{
					continue;
				}

				m_pDisplayObject[i]->SetColorAlpha(0.3f);
			}
		}
		else
		{
			for (int i = 0; i < DISPLAY_NUMBER; i++)
			{
				if (m_pDisplayObject[i]->GetIsMin())
				{
					continue;
				}

				m_pDisplayObject[i]->SetColorAlpha(0.3f);
			}
		}

		answer = m_pDisplayObject[inNumber]->GetIsMin();
		CCorrection::Create(answer);
		m_game->AddScore(answer ? 10 : -5);
	}

	answer ? m_correct++ : m_correct--;

	if (m_correct >= m_nextNeedCorrect)
	{
		m_game->LevelUp();
		m_correct = 0;
	}

	if (m_correct < 0)
	{
		m_game->LevelDown();
		m_correct = 0;
	}
}

void CLargeNumberSystem::Reset_()
{
	int nowLevel = m_game->GetLevel();

	if (m_oldLevel == nowLevel)
	{
		return;
	}

	switch (nowLevel)
	{
	case 1:
		X_LINE = 2;
		Y_LINE = 1;
		m_nextNeedCorrect = 1;
		break;
	case 2:
		X_LINE = 2;
		Y_LINE = 2;
		m_nextNeedCorrect = 2;
		break;
	case 3:
		X_LINE = 3;
		Y_LINE = 2;
		m_nextNeedCorrect = 2;
		break;
	case 4:
		X_LINE = 3;
		Y_LINE = 3;
		break;
	default:
		break;
	}

	DISPLAY_NUMBER = X_LINE * Y_LINE;

	float size = 130.0f;
	float space = 60.0f;

	// ����
	for (CLargestNumber* obj : m_pDisplayObject)
	{
		if (obj == nullptr)
		{
			continue;
		}

		obj->UninitReset();
		obj = nullptr;
	}
	m_pDisplayObject.clear();

	m_pDisplayObject.resize(DISPLAY_NUMBER);

	for (int nCntY = 0; nCntY < Y_LINE; nCntY++)
	{
		for (int nCntX = 0; nCntX < X_LINE; nCntX++)
		{
			int nCntNumber = nCntY * X_LINE + nCntX;

			float shiftX = (CApplication::SCREEN_WIDTH * 0.5f) - ((size + space) * (X_LINE - 1) * 0.5f);
			float shiftY = (CApplication::SCREEN_HEIGHT * 0.5f) - ((size + space) * (Y_LINE - 1) * 0.5f);

			float posX = (size + space) * nCntX;
			float posY = (size + space) * nCntY;

			m_pDisplayObject[nCntNumber] = CLargestNumber::Create(D3DXVECTOR3(
				posX + shiftX,
				posY + shiftY, 0.0f),
				D3DXVECTOR2(size, size));
			m_pDisplayObject[nCntNumber]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			m_pDisplayObject[nCntNumber]->SetTexture("DECO_TAG");

			m_pDisplayObject[nCntNumber]->SetEvent([this, nCntNumber]()
			{// �N���b�N�����Ƃ��ɔ�������i���j
				if (!m_isTrue)
				{
					if (m_mode)
					{// �ő�
						m_isAnswer = m_pDisplayObject[nCntNumber]->GetIsMax();
					}
					else
					{// �ŏ�
						m_isAnswer = m_pDisplayObject[nCntNumber]->GetIsMin();
					}

					CorrectAnswer_(nCntNumber);
					m_isTrue = true;
				}
			});

			m_pDisplayObject[nCntNumber]->SetEventTick([this, nCntNumber]()
			{// �N���b�N�����Ƃ��ɔ�������i���t���[���j
				if (!m_isTrue)
				{
					return;
				}

				if (nCntNumber == 0)
				{
					m_rug++;
				}

				m_frame = m_isAnswer ? TRUE_FLAME : FALSE_FLAME;

				if (m_rug > m_frame)
				{
					// �����������Ď��̖���
					InitCreateAnswer_();
					SetMode();

					m_rug = 0;
					m_isTrue = false;
					m_isAnswer = false;
				}
			});
		}
	}

}
