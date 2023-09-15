//==================================================
// 
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "result.h"
#include "application.h"

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
CResult::CResult() : CObject2D(CTaskGroup::LEVEL_2D_UI)
{
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
CResult::~CResult()
{
}

//--------------------------------------------------
// ������
//--------------------------------------------------
HRESULT CResult::Init()
{
	CObject2D::Init();

	SetSize(D3DXVECTOR2(CApplication::CENTER_X, (float)CApplication::SCREEN_HEIGHT));
	SetPos(D3DXVECTOR3(CApplication::CENTER_X + CApplication::CENTER_X * 0.5f, CApplication::CENTER_Y, 0.0f));

	return S_OK;
}

//--------------------------------------------------
// �X�V
//--------------------------------------------------
void CResult::Update()
{
}

//--------------------------------------------------
// ����
//--------------------------------------------------
CResult* CResult::Create()
{
	CResult* pResult = new CResult;

	assert(pResult != nullptr);

	pResult->Init();

	return pResult;
}
