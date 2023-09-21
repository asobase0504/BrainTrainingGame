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
// �R���X�g���N�^
//--------------------------------------------------
CLargestNumber::CLargestNumber() : m_isLargest(false)
{
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
CLargestNumber::~CLargestNumber()
{
}

//--------------------------------------------------
// ������
//--------------------------------------------------
HRESULT CLargestNumber::Init()
{
	CRememberObject::Init();

	return S_OK;
}

//--------------------------------------------------
// �I��
//--------------------------------------------------
void CLargestNumber::Uninit()
{
	CRememberObject::Uninit();
}

//--------------------------------------------------
// �X�V
//--------------------------------------------------
void CLargestNumber::Update()
{
	CRememberObject::Update();
}

//--------------------------------------------------
// �`��
//--------------------------------------------------
void CLargestNumber::Draw()
{
	CRememberObject::Draw();
}

//--------------------------------------------------
// ����
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
