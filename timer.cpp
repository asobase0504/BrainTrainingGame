//==================================================
// timer.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "application.h"
#include "game.h"

#include "timer.h"
#include "number.h"

//**************************************************
// 静的メンバ変数
//**************************************************

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CTimer::CTimer() : 
	m_nCounter(0),
	m_bIsStop(false)
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CTimer::~CTimer()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CTimer::Init()
{
	CSequence::Init();
	m_bIsStop = false;
	return S_OK;
}

//--------------------------------------------------
// 初期化　オーバーロード
//--------------------------------------------------
HRESULT CTimer::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CSequence::Init(pos, size,2);
	m_bIsStop = false;
	SetColor(D3DXCOLOR(0.0f,0.0f,0.0f,1.0f));
	return S_OK;
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CTimer::Update()
{
	CSequence::Update();

	if (m_bIsStop)
	{
		return;
	}

	//フレームカウンター
	m_nCounter++;

	if (m_nCounter >= 60)
	{
		AddTimer(-1);

		m_nCounter = 0;
	}

	if (GetNumber() <= 0)
	{
		m_bIsStop = true;
		SetTimer(0);
	}
}

//--------------------------------------------------
// 生成
//--------------------------------------------------
CTimer *CTimer::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CTimer *pTimer;
	pTimer = new CTimer;

	if (pTimer != nullptr)
	{
		pTimer->Init(pos, size);
	}
	else
	{
		assert(false);
	}

	return pTimer;
}
