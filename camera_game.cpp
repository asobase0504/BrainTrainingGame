//=============================================================================
//
// ゲームモード時使用するカメラ
// Author : Yuda Kaito
//
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "camera_game.h"
#include "bus.h"

//-----------------------------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------------------------
CCameraGame::CCameraGame() : m_bus(nullptr)
{
}

//-----------------------------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------------------------
CCameraGame::~CCameraGame()
{
}

//-----------------------------------------------------------------------------
// 生成
//-----------------------------------------------------------------------------
CCameraGame* CCameraGame::Create(CBus * inBus)
{
	CCameraGame* camera = new CCameraGame;

	assert(camera != nullptr);

	camera->Init();
	camera->m_bus = inBus;

	return camera;
}

//-----------------------------------------------------------------------------
// 初期化
//-----------------------------------------------------------------------------
HRESULT CCameraGame::Init()
{
	CCamera::Init();
	m_posV = D3DXVECTOR3(0.0f, 0.0f, -500.0f);
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	return S_OK;
}

//-----------------------------------------------------------------------------
// 更新
//-----------------------------------------------------------------------------
void CCameraGame::Update()
{
	D3DXVECTOR3 pos = m_bus->GetPos();
	m_posV = pos + D3DXVECTOR3(0.0f, 0.0f, -500.0f);
	m_posR = pos;
}
