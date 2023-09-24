//==================================================
// large_number_system.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "large_number_system.h"

#include "application.h"
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
CLargeNumberSystem::CLargeNumberSystem(int nPriority) : CObject(nPriority)
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
	m_isUsedNumber.resize(MAX_NUMBER);

	int myNumber = 0;
	myNumber = IntRandom(MAX_NUMBER, 1);

	for (int i = 0; i < DISPLAY_NUMBER; i++)
	{
		m_pDisplayObject[i] = CLargestNumber::Create(
			D3DXVECTOR3(CApplication::SCREEN_WIDTH * 0.25f + 120.0f * i, CApplication::SCREEN_HEIGHT * 0.5f, 0.0f),
			D3DXVECTOR2(100.0f, 100.0f));
		m_pDisplayObject[i]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

		while (m_isUsedNumber[myNumber])
		{
			myNumber = IntRandom(MAX_NUMBER, 1);
		}

		m_isUsedNumber[myNumber] = true;

		m_pDisplayObject[i]->SetMyNumber(myNumber);
		m_pDisplayObject[i]->SetEvent([]() {});
	}

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
	// 一時的に保存する変数
	int nCheck = 0;
	for (int i = 0; i < DISPLAY_NUMBER - 1; i++)
	{
		int number1 = m_pDisplayObject[i]->GetMyNumber();
		for (int j = j + 1; j < DISPLAY_NUMBER; j++)
		{
			int number2 = m_pDisplayObject[j]->GetMyNumber();
			// 二つのデータを比較する
			if (number1 <= number2)
			{
				//変数を一時格納
				nCheck = number2;

				//比較した数値を入れる
				number2 = number1;
				number1 = nCheck;
			}
		}

		int a = 0;
	}
}
