//==================================================
// number.cpp
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
	CObject2D::Init();

	return S_OK;
}

//--------------------------------------------------
// 終了
//--------------------------------------------------
void CRememberObject::Uninit()
{
	CObject2D::Uninit();
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CRememberObject::Update()
{
	CObject2D::Update();
}

//--------------------------------------------------
// 生成
//--------------------------------------------------
CRememberObject *CRememberObject::Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size)
{
	CRememberObject *pRememberObject;
	pRememberObject = new CRememberObject;

	if (pRememberObject != nullptr)
	{
		pRememberObject->Init();
		pRememberObject->SetPos(pos);
		pRememberObject->SetSize(size);
	}
	else
	{
		assert(false);
	}

	return pRememberObject;
}
