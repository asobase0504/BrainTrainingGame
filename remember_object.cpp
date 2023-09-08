//==================================================
// remember_object.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "remember_object.h"

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CRememberObject::CRememberObject(int nPriority) : CObject2D(nPriority)
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CRememberObject::~CRememberObject()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CRememberObject::Init()
{
	return S_OK;
}

//--------------------------------------------------
// 終了
//--------------------------------------------------
void CRememberObject::Uninit()
{
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CRememberObject::Update()
{
}

//--------------------------------------------------
// 描画
//--------------------------------------------------
void CRememberObject::Draw()
{
}

//--------------------------------------------------
// 生成
//--------------------------------------------------
CRememberObject *CRememberObject::Create(int inMyNumber)
{
	CRememberObject *pRememberObject;
	pRememberObject = new CRememberObject;

	if (pRememberObject != nullptr)
	{
		pRememberObject->Init();
		pRememberObject->SetMyNumber(inMyNumber);
	}
	else
	{
		assert(false);
	}

	return pRememberObject;
}
