//=============================================================================
// 
// アプリケーションクラス
// Author YudaKaito
// 
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "title.h"
#include <assert.h>

#include "application.h"
#include "mode_guidance_item.h"
#include "input.h"

//-----------------------------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------------------------
CTitle::CTitle() : 
	m_status(CMode::MODE_TYPE::TITLE)
{
}

//-----------------------------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------------------------
CTitle::~CTitle()
{
}

//-----------------------------------------------------------------------------
// 初期化
//-----------------------------------------------------------------------------
HRESULT CTitle::Init()
{
	CModeGuidanceItem::Create(D3DXVECTOR3(350.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_MOVEOBJECT);
	CModeGuidanceItem::Create(D3DXVECTOR3(500.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_NUMBER25);
	CModeGuidanceItem::Create(D3DXVECTOR3(650.0f, 500.0f, 0.0f), CMode::MODE_TYPE::MINIGAME_BUS);
	return S_OK;
}

//-----------------------------------------------------------------------------
// 終了
//-----------------------------------------------------------------------------
void CTitle::Uninit()
{
}

//-----------------------------------------------------------------------------
// 更新
//-----------------------------------------------------------------------------
void CTitle::Update()
{
}

