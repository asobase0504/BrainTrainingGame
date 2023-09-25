//==================================================
// same_as_shadow_system.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "largest_number.h"

#include "sequence.h"
#include "utility.h"

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
CLargestNumber::CLargestNumber() : m_isLargest(false),m_pSequence(nullptr)
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
// ������
//--------------------------------------------------
HRESULT CLargestNumber::Init(const D3DXVECTOR3& inPos)
{
	CRememberObject::Init();

	m_pSequence = CSequence::Create(
		D3DXVECTOR3(inPos.x - 20.0f, inPos.y, inPos.z), 
		D3DXVECTOR2(50.0f,50.0f), 2);

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
		pLargestNumber->Init(inPos);
		pLargestNumber->SetPos(inPos);
		pLargestNumber->SetSize(inSize);
	}
	else
	{
		assert(false);
	}

	return pLargestNumber;
}

//--------------------------------------------------
// ���̐ݒ�
//--------------------------------------------------
void CLargestNumber::SetSequence(int inSequence)
{
	m_pSequence->SetNumber(inSequence);
}
