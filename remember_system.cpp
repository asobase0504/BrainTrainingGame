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
		m_pRememberObject[nCntTexture] = CRememberObject::Create(
			D3DXVECTOR3((float)CApplication::SCREEN_WIDTH * (0.5f + nCntTexture), (float)CApplication::SCREEN_HEIGHT * 0.5f, 0.0f),
			D3DXVECTOR2(300.0f, 200.0f),
			nCntTexture);
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
	// インプット
	CInput *input = CInput::GetKey();
	D3DXVECTOR3 mousePos = input->GetMouseCursor();

	Touch_(mousePos.x, mousePos.y);
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

//--------------------------------------------------
// タッチ
//--------------------------------------------------
void CRememberSystem::Touch_(float nPosX, float nPosY)
{
	// インプット
	CInput *input = CInput::GetKey();

	for (int nCntNumber = 0; nCntNumber < TEXTURE_MAX; nCntNumber++)
	{
		D3DXVECTOR3 pos = m_pRememberObject[nCntNumber]->GetPos();
		D3DXVECTOR3 size = m_pRememberObject[nCntNumber]->GetSize();
		//	タッチ座標がポリゴンの中だったら
		if (input->Trigger(MOUSE_INPUT_LEFT)
			&& pos.x + size.x >= nPosX
			&& pos.x - size.x <= nPosX
			&& pos.y - size.y <= nPosY
			&& pos.y + size.y >= nPosY)
		{
			// ポリゴンのカラー変更
			m_pRememberObject[nCntNumber]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		}
	}
}
