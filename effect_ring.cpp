//=========================================
// 
// effect_ring.h
// Author Koduns Hirohito
// 
//=========================================
#include "effect_ring.h"
#include "texture.h"
#include <assert.h>
#include "effect_flash.h"

//=============================================================================
// 静的マクロ
//=============================================================================
const float CEffectRing::INITIAL_SIZE = 20.0f;
const float CEffectRing::SIZE_INCREASE = 2.0f;
const float CEffectRing::TRANSPARENCY_DECREASE_QUANTITY = 0.04f;
const int  CEffectRing::FLASH_COUNT = 2;						//フラッシュエフェクトの個数

//=============================================================================
// コンストラクタ
//=============================================================================
CEffectRing::CEffectRing() : CObject2D(CTaskGroup::LEVEL_2D_UI_EFFECT)
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CEffectRing::~CEffectRing()
{
}

//=============================================================================
// 初期化
//=============================================================================
HRESULT CEffectRing::Init(D3DXVECTOR3 pos)
{
	//親クラスの初期化
	if (FAILED(CObject2D::Init()))
	{
		assert(false);
	}

	//ポーズ中更新
	SetPauseUpdate(true);

	//テクスチャの設定
	SetTexture("RING");

	//サイズ
	SetSize(D3DXVECTOR2(INITIAL_SIZE, INITIAL_SIZE));

	//位置
	SetPos(pos);

	return S_OK;
}

//=============================================================================
// 終了
//=============================================================================
void CEffectRing::Uninit()
{
	CObject2D::Uninit();
}

//=============================================================================
// 更新
//=============================================================================
void CEffectRing::Update()
{
	//サイズの増加
	AddSize(D3DXVECTOR2(SIZE_INCREASE, SIZE_INCREASE));

	//アルファ値を下げる
	AddColorAlpha(-TRANSPARENCY_DECREASE_QUANTITY);

	//親クラス
	CObject2D::Update();

	//完全に透明になると解放する
	if (GetColor().a <= 0.0f)
	{
		CEffectRing::Uninit();
	}
}

//=============================================================================
// クラスの作成
//=============================================================================
CEffectRing* CEffectRing::Create(D3DXVECTOR3 pos)
{
	CEffectRing* objectCreate = new CEffectRing();

	if ((objectCreate == nullptr) || FAILED(objectCreate->Init(pos)))
	{
		assert(false);
	}

	//追加エフェクト
	int nCntMax = rand() % FLASH_COUNT + 3;
	for (int i = 0; i < nCntMax; i++)
	{
		CEffectFlash::Create(pos);
	}
	
	return objectCreate;
}
