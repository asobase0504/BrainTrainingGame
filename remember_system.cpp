//==================================================
// remember_system.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "remember_system.h"

#include "application.h"
#include "input.h"
#include "object2d.h"

#include "remember_object.h"

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CRememberSystem::CRememberSystem(int nPriority) : CObject(nPriority)
{
}
//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CRememberSystem::~CRememberSystem()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CRememberSystem::Init()
{
	std::string tex[] =
	{
		"WINTER",
		"SUN_FLOWER",
		"MOUNTAIN",
		"GORYOKAKU",
		"GAME", 
		"FLOWER_GARD",
		"DUCK",
		"DOG",
		"CLOUD",
		"CASTLE",
	};

#define ARRAY_LENGTH(a) (sizeof(a)/sizeof((a)[0])) 
	static_assert(ARRAY_LENGTH(tex) == TEXTURE_MAX, "baka");

	for (int nCntTexture = 0; nCntTexture < TEXTURE_MAX; nCntTexture++)
	{
		// テクスチャ
		m_pRememberObject[nCntTexture] = CRememberObject::Create(nCntTexture);
		m_pRememberObject[nCntTexture]->SetPos(D3DXVECTOR3((float)CApplication::SCREEN_WIDTH * (0.5f + nCntTexture), (float)CApplication::SCREEN_HEIGHT * 0.5f, 0.0f));
		m_pRememberObject[nCntTexture]->SetSize(D3DXVECTOR2(300.0f, (float)200.0f));
		m_pRememberObject[nCntTexture]->SetTexture(tex[nCntTexture]);
		m_pRememberObject[nCntTexture]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}

	return S_OK;
}

//--------------------------------------------------
// 終了
//--------------------------------------------------
void CRememberSystem::Uninit()
{
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CRememberSystem::Update()
{

}

//--------------------------------------------------
// 描画
//--------------------------------------------------
void CRememberSystem::Draw()
{
}

//--------------------------------------------------
// 生成
//--------------------------------------------------
CRememberSystem *CRememberSystem::Create()
{
	CRememberSystem *pRememberSystem;
	pRememberSystem = new CRememberSystem;

	if (pRememberSystem != nullptr)
	{
		pRememberSystem->Init();
	}
	else
	{
		assert(false);
	}

	return pRememberSystem;
}
