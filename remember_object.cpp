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
CRememberObject::CRememberObject() : m_myNumber(0)
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
	CClickItem::Init();
	m_BG = nullptr;
	return S_OK;
}

void CRememberObject::UninitReset()
{
	Uninit();

	if (m_BG != nullptr)
	{
		m_BG->Uninit();
		m_BG = nullptr;
	}
}

//--------------------------------------------------
// 終了
//--------------------------------------------------
void CRememberObject::Uninit()
{
	CClickItem::Uninit();
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CRememberObject::Update()
{
	CClickItem::Update();
}

//--------------------------------------------------
// 描画
//--------------------------------------------------
void CRememberObject::Draw()
{
	CClickItem::Draw();
}

//--------------------------------------------------
// 生成
//--------------------------------------------------
CRememberObject *CRememberObject::Create(const D3DXVECTOR3& inPos, const D3DXVECTOR2& inSize, int inMyNumber)
{
	CRememberObject *pRememberObject;
	pRememberObject = new CRememberObject;

	if (pRememberObject != nullptr)
	{
		pRememberObject->Init();
		pRememberObject->SetPos(inPos);
		pRememberObject->SetSize(inSize);
		pRememberObject->SetMyNumber(inMyNumber);
	}
	else
	{
		assert(false);
	}

	return pRememberObject;
}

void CRememberObject::SetPos(const D3DXVECTOR3 & inPos)
{
	CClickItem::SetPos(inPos);
	if (m_BG != nullptr)
	{
		m_BG->SetPos(inPos);
	}
}

void CRememberObject::SetSize(const D3DXVECTOR2 & inSize)
{
	CClickItem::SetSize(inSize);
	if (m_BG != nullptr)
	{
		m_BG->SetSize(inSize);
	}
}

void CRememberObject::CreateBG()
{
	m_BG = CObject2D::Create();
	m_BG->SetTexture("DECO_TAG");
}
