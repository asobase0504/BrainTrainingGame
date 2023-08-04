//==================================================
// number.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include <assert.h>

#include "number.h"

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CNumber::CNumber(int nPriority /* =4 */) : CObject2D(nPriority)
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CNumber::~CNumber()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CNumber::Init()
{
	CObject2D::Init();

	return S_OK;
}

//--------------------------------------------------
// 生成
//--------------------------------------------------
CNumber* CNumber::Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size)
{
	CNumber *pNumber;
	pNumber = new CNumber;

	if (pNumber != nullptr)
	{
		pNumber->Init();
		pNumber->SetPos(pos);
		pNumber->SetSize(size);
	}
	else
	{
		assert(false);
	}

	return pNumber;
}
