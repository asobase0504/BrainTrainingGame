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
// 定数定義
//**************************************************
const int CLargeNumberSystem::X_LINE = 3;
const int CLargeNumberSystem::Y_LINE = 3;
const int CLargeNumberSystem::DISPLAY_NUMBER = X_LINE * Y_LINE;
const int CLargeNumberSystem::MAX_NUMBER = 99;
const int CLargeNumberSystem::TRUE_FLAME = 30;
const int CLargeNumberSystem::FALSE_FLAME = 60;

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CLargeNumberSystem::CLargeNumberSystem(int nPriority) : CObject(nPriority),
m_nMaxNumber(0), m_nMinNumber(999), m_minOrMax(0), m_mode(false), m_rug(0), m_isTrue(false), m_frame(0)
{
	m_pDisplayObject.clear();
	m_isUsedNumber.clear();
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CLargeNumberSystem::~CLargeNumberSystem()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CLargeNumberSystem::Init()
{
	m_pDisplayObject.resize(DISPLAY_NUMBER);
	m_isUsedNumber.resize(MAX_NUMBER + 1);

	m_minOrMax = IntRandom(6, 1);

	float size = 130.0f;
	float space = 60.0f;

	for (int nCntY = 0; nCntY < Y_LINE; nCntY++)
	{
		for (int nCntX = 0; nCntX < X_LINE; nCntX++)
		{
			int nCntNumber = nCntY * X_LINE + nCntX;

			float posX = ((CApplication::SCREEN_WIDTH * 0.5f) + (size + space) * nCntX + space * 0.5f);
			float posY = ((CApplication::SCREEN_HEIGHT * 0.5f) + (size + space) * nCntY + space * 0.5f);

			float shiftX = (size + space * X_LINE * 0.5f);
			float shiftY = (size + space * Y_LINE * 0.5f);

			m_pDisplayObject[nCntNumber] = CLargestNumber::Create(D3DXVECTOR3(
				posX - shiftX,
				posY - shiftY, 0.0f),
				D3DXVECTOR2(size, size));
			m_pDisplayObject[nCntNumber]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			m_pDisplayObject[nCntNumber]->SetTexture("DECO_TAG");

			m_pDisplayObject[nCntNumber]->SetEvent([this, nCntNumber]()
			{// クリックしたときに反応する（一回）	// TODO 連打したらずっとマイナスされる
				if (m_mode)
				{// 最大
					m_isAnswer = m_pDisplayObject[nCntNumber]->GetIsMax();
				}
				else
				{// 最小
					m_isAnswer = m_pDisplayObject[nCntNumber]->GetIsMin();
				}

				CorrectAnswer_(nCntNumber);
				m_isTrue = true;
			});

			m_pDisplayObject[nCntNumber]->SetEventTick([this, nCntNumber]()
			{// クリックしたときに反応する（毎フレーム）
				if (m_isTrue)
				{
					if (nCntNumber == 0)
					{
						m_rug++;
					}

					if (m_isAnswer)
					{// 正解したとき
						m_frame = TRUE_FLAME;
					}
					else if (!m_isAnswer)
					{// 間違えた時
						m_frame = FALSE_FLAME;
					}

					if (m_rug > m_frame)
					{
						InitCreateAnswer_();
						SetMode();

						m_rug = 0;
						m_isTrue = false;
						m_isAnswer = false;
					}
				}
			});
		}
	}
	SetMode();

	return S_OK;
}

//--------------------------------------------------
// 終了
//--------------------------------------------------
void CLargeNumberSystem::Uninit()
{
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CLargeNumberSystem::Update()
{
}

//--------------------------------------------------
// 描画
//--------------------------------------------------
void CLargeNumberSystem::Draw()
{
}

//--------------------------------------------------
// 生成
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
// どれが大きい数か
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
// 数の抽選
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
// 数の抽選
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
// モードの分岐
//--------------------------------------------------
void CLargeNumberSystem::SetMode()
{
	if (m_minOrMax % 2 == 0)
	{// 最大
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
	{// 最小
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
// 答えの初期化
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
// 答えが正しいかどうか
//--------------------------------------------------
void CLargeNumberSystem::CorrectAnswer_(int inNumber)
{
	if (m_mode)
	{// 最大
		if (m_pDisplayObject[inNumber]->GetIsMax())
		{// 何もしない
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

		CCorrection::Create(m_pDisplayObject[inNumber]->GetIsMax());

		m_game->AddScore(m_pDisplayObject[inNumber]->GetIsMax() ? 10 : -5);
	}
	else
	{// 最小
		if (m_pDisplayObject[inNumber]->GetIsMin())
		{// 何もしない
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

		CCorrection::Create(m_pDisplayObject[inNumber]->GetIsMin());
		m_game->AddScore(m_pDisplayObject[inNumber]->GetIsMin() ? 10 : -5);
	}
}
