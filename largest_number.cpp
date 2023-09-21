//==================================================
// same_as_shadow_system.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "largest_number.h"

#include "utility.h"

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CLargestNumber::CLargestNumber() : m_isLargest(false)
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CLargestNumber::~CLargestNumber()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CLargestNumber::Init()
{
	CRememberObject::Init();

	return S_OK;
}

//--------------------------------------------------
// 終了
//--------------------------------------------------
void CLargestNumber::Uninit()
{
	CRememberObject::Uninit();
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CLargestNumber::Update()
{
	CRememberObject::Update();
}

//--------------------------------------------------
// 描画
//--------------------------------------------------
void CLargestNumber::Draw()
{
	CRememberObject::Draw();
}

//--------------------------------------------------
// 生成
//--------------------------------------------------
CLargestNumber *CLargestNumber::Create(const D3DXVECTOR3 & inPos, const D3DXVECTOR2 & inSize)
{
	CLargestNumber *pLargestNumber;
	pLargestNumber = new CLargestNumber;

	if (pLargestNumber != nullptr)
	{
		pLargestNumber->Init();
		pLargestNumber->SetPos(inPos);
		pLargestNumber->SetSize(inSize);
	}
	else
	{
		assert(false);
	}

	return pLargestNumber;
}
