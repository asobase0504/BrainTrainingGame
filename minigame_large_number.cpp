//=============================================================================
// 
// ミニゲーム：数が大きい奴を押す
// Author BuriyaKota
// 
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "minigame_large_number.h"
#include "large_number_system.h"
#include "application.h"
#include "object2d.h"

//-----------------------------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------------------------
CMiniGameLargeNumber::CMiniGameLargeNumber()
{
}

//-----------------------------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------------------------
CMiniGameLargeNumber::~CMiniGameLargeNumber()
{
}

//-----------------------------------------------------------------------------
// 初期化
//-----------------------------------------------------------------------------
HRESULT CMiniGameLargeNumber::Init()
{
	CGame::Init();

	{
		m_expo = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		m_expo->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y - 300.0f, 0.0f));
		D3DXVECTOR2 size(1292.0f * 0.4f, 252.0f * 0.4f);
		m_expo->SetSize(size);
		m_expo->SetTexture("TEXT_EXPO_LARGE_MAX");
	}
	return S_OK;
}

//-----------------------------------------------------------------------------
// ゲーム開始
//-----------------------------------------------------------------------------
void CMiniGameLargeNumber::GameStart()
{
	CGame::GameStart();

	m_system = CLargeNumberSystem::Create(this);
}

//-----------------------------------------------------------------------------
// 終了
//-----------------------------------------------------------------------------
void CMiniGameLargeNumber::Uninit()
{
}

//-----------------------------------------------------------------------------
// 更新
//-----------------------------------------------------------------------------
void CMiniGameLargeNumber::Update()
{
	CGame::Update();

	if (GetState() == COUNT_DOWN)
	{
		static bool change = true;

		m_time++;

		if (m_time % 30 == 0)
		{
			change = !change;
			m_expo->SetTexture(change ? "TEXT_EXPO_LARGE_MAX" : "TEXT_EXPO_LARGE_MIN");
		}
		return;
	}
	
	if (m_system->GetMode())
	{
		m_expo->SetTexture("TEXT_EXPO_LARGE_MAX");
	}
	else
	{
		m_expo->SetTexture("TEXT_EXPO_LARGE_MIN");
	}
}

//-----------------------------------------------------------------------------
// 描画
//-----------------------------------------------------------------------------
void CMiniGameLargeNumber::Draw()
{
}
