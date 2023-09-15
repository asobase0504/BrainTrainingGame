//==========================================
//
//  押すやつ(target.cpp)
//  Author : Tomoya Kanazaki
//
//==========================================
#include "target.h"
#include "debug_proc.h"

//==========================================
//  コンストラクタ
//==========================================
CTarget::CTarget()
{
	m_nID = -1;
}

//==========================================
//  デストラクタ
//==========================================
CTarget::~CTarget()
{

}

//==========================================
//  初期化処理
//==========================================
HRESULT CTarget::Init()
{
	return CObject2D::Init();
}

//==========================================
//  終了処理
//==========================================
void CTarget::Uninit()
{
	CObject2D::Uninit();
}

//==========================================
//  更新処理
//==========================================
void CTarget::Update()
{
	CDebugProc::Print("押すやついるよん\n");
	CObject2D::Update();
}

//==========================================
//  描画処理
//==========================================
void CTarget::Draw()
{
	CObject2D::Draw();
}
