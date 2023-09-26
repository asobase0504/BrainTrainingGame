//=========================================
// 
// effect_flash.h
// Author Koduns Hirohito
// 
//=========================================
#include "effect_flash.h"
#include "texture.h"
#include <assert.h>

//=============================================================================
// 静的マクロ
//=============================================================================
const int CEffectFlash::MAX_SIZE = 2000;									//最大サイズ
const float CEffectFlash::MIN_SIZE = 20.0f;									//最低サイズ
const int CEffectFlash::MAX_SIZE_INCREASE = 400;							//サイズの最大増加量
const float CEffectFlash::MIN_SIZE_INCREASE = 1.0f;							//サイズの最低増加量
const int CEffectFlash::MAX_TRANSPARENCY_DECREASE_QUANTITY = 5;				//透明度の減少量の最大
const float CEffectFlash::MIN_TRANSPARENCY_DECREASE_QUANTITY = 0.05f;		//透明度の減少量の最低
const int CEffectFlash::MAX_MOVING_LENGTH = 500;							//移動量の最大
const float CEffectFlash::MIN_MOVING_LENGTH = 1.0f;							//移動量の最低

//intは100割計算をする

//=============================================================================
// コンストラクタ
//=============================================================================
CEffectFlash::CEffectFlash() : CObject2D(CTaskGroup::LEVEL_2D_UI_EFFECT)
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CEffectFlash::~CEffectFlash()
{
}

//=============================================================================
// 初期化
//=============================================================================
HRESULT CEffectFlash::Init(D3DXVECTOR3 pos)
{
	//親クラスの初期化
	if (FAILED(CObject2D::Init()))
	{
		assert(false);
	}

	//ポーズ中更新
	SetPauseUpdate(true);

	//テクスチャの設定
	SetTexture("FLASH");

	//サイズ
	float fSize = MIN_SIZE + rand() % MAX_SIZE * 0.01f;
	//サイズの増加量
	m_fSizeIncrease = MIN_SIZE_INCREASE + rand() % MAX_SIZE_INCREASE * 0.01f;
	//透明度
	m_fTransparency = MIN_TRANSPARENCY_DECREASE_QUANTITY + rand() % MAX_TRANSPARENCY_DECREASE_QUANTITY * 0.01f;
	//長さ
	float fLength = MIN_MOVING_LENGTH + rand() % MAX_MOVING_LENGTH * 0.01f;
	//移動量
	int nRot = rand() % 360;
	D3DXVECTOR3 Move = {};
	Move.x = sinf(D3DXToRadian(nRot));
	Move.y = cosf(D3DXToRadian(nRot));
	Move.z = 0.0f;
	D3DXVec3Normalize(&Move,&Move);
	//カラー
	D3DXCOLOR Color = {};
	Color.r = rand() % 10 * 0.1f;
	Color.g = rand() % 10 * 0.1f;
	Color.b = rand() % 10 * 0.1f;
	Color.a = 1.0f;

	//サイズ
	SetSize(D3DXVECTOR2(fSize, fSize));

	//位置
	SetPos(pos);

	//移動
	SetMove(Move * fLength);

	//色
	SetColor(Color);

	return S_OK;
}

//=============================================================================
// 終了
//=============================================================================
void CEffectFlash::Uninit()
{
	CObject2D::Uninit();
}

//=============================================================================
// 更新
//=============================================================================
void CEffectFlash::Update()
{
	//サイズの増加
	AddSize(D3DXVECTOR2(m_fSizeIncrease, m_fSizeIncrease));

	//アルファ値を下げる
	AddColorAlpha(-m_fTransparency);

	//親クラス
	CObject2D::Update();

	//完全に透明になると解放する
	if (GetColor().a <= 0.0f)
	{
		CEffectFlash::Uninit();
	}
}

//=============================================================================
// クラスの作成
//=============================================================================
CEffectFlash* CEffectFlash::Create(D3DXVECTOR3 pos)
{
	CEffectFlash* objectCreate = new CEffectFlash();

	if ((objectCreate == nullptr) || FAILED(objectCreate->Init(pos)))
	{
		assert(false);
	}

	return objectCreate;
}
