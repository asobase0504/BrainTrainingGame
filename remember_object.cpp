//==================================================
// remember_object.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "remember_object.h"

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
CRememberObject::CRememberObject() : m_myNumber(0)
{
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
CRememberObject::~CRememberObject()
{
}

//--------------------------------------------------
// ������
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
// �I��
//--------------------------------------------------
void CRememberObject::Uninit()
{
	CClickItem::Uninit();
}

//--------------------------------------------------
// �X�V
//--------------------------------------------------
void CRememberObject::Update()
{
	CClickItem::Update();
}

//--------------------------------------------------
// �`��
//--------------------------------------------------
void CRememberObject::Draw()
{
	CClickItem::Draw();
}

//--------------------------------------------------
// ����
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
