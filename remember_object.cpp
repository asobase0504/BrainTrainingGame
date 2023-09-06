//==================================================
// number.cpp
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
	std::string tex[] =
	{
		"PLAYER",
		"HUMAN",
		"STATION"
	};
#define ARRAY_LENGTH(a) (sizeof(a)/sizeof((a)[0])) 
	static_assert(ARRAY_LENGTH(tex) == TEXTURE_MAX, "baka");

	for (int nCntTexture = 0; nCntTexture < TEXTURE_MAX; nCntTexture++)
	{
		// �e�N�X�`��
		m_pObject2D[nCntTexture] = CObject2D::Create();
		m_pObject2D[nCntTexture]->SetSize(D3DXVECTOR2(300.0f, 150.0f));
		m_pObject2D[nCntTexture]->SetTexture(tex[nCntTexture]);
	}

	CObject2D::Init();

	return S_OK;
}

//--------------------------------------------------
// �I��
//--------------------------------------------------
void CRememberObject::Uninit()
{
	CObject2D::Uninit();
}

//--------------------------------------------------
// �X�V
//--------------------------------------------------
void CRememberObject::Update()
{
	CObject2D::Update();
}

//--------------------------------------------------
// ����
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
