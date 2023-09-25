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

#include "largest_number.h"

//**************************************************
// 定数定義
//**************************************************
const int CLargeNumberSystem::DISPLAY_NUMBER = 5;
const int CLargeNumberSystem::MAX_NUMBER = 99;

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CLargeNumberSystem::CLargeNumberSystem(int nPriority) : CObject(nPriority),
m_nLargestNumber(0)
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

	for (int i = 0; i < DISPLAY_NUMBER; i++)
	{
		m_pDisplayObject[i] = CLargestNumber::Create(
			D3DXVECTOR3(CApplication::SCREEN_WIDTH * 0.25f + 120.0f * i, CApplication::SCREEN_HEIGHT * 0.5f, 0.0f),
			D3DXVECTOR2(100.0f, 100.0f));
		m_pDisplayObject[i]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		m_pDisplayObject[i]->SetEvent([]() {});
	}
	NumberLottery_();
	WhichiNumberLargest_();

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
// 数の抽選
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
