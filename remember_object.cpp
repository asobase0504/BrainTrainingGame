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
CRememberObject::CRememberObject(int nPriority) : CObject2D(nPriority)
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
	return S_OK;
}

//--------------------------------------------------
// �I��
//--------------------------------------------------
void CRememberObject::Uninit()
{
}

//--------------------------------------------------
// �X�V
//--------------------------------------------------
void CRememberObject::Update()
{
}

//--------------------------------------------------
// �`��
//--------------------------------------------------
void CRememberObject::Draw()
{
}

//--------------------------------------------------
// ����
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
