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

	return S_OK;
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
