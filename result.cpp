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
// コンストラクタ
//--------------------------------------------------
CResult::CResult() : CObject2D(CTaskGroup::LEVEL_2D_UI)
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CResult::~CResult()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CResult::Init()
{
	CObject2D::Init();

	SetSize(D3DXVECTOR2(CApplication::CENTER_X, (float)CApplication::SCREEN_HEIGHT));
	SetPos(D3DXVECTOR3(CApplication::CENTER_X + CApplication::CENTER_X * 0.5f, CApplication::CENTER_Y, 0.0f));

	return S_OK;
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CResult::Update()
{
}

//--------------------------------------------------
// 生成
//--------------------------------------------------
CResult* CResult::Create()
{
	CResult* pResult = new CResult;

	assert(pResult != nullptr);

	pResult->Init();

	return pResult;
}
