//==================================================
// effect_ring.h
// Author: Koduns Hirohito
//==================================================
#ifndef _EFFECT_RING_H_
#define _EFFECT_RING_H_

//**************************************************
// インクルード
//**************************************************
#include "object2d.h"

//**************************************************
// クラス
//**************************************************
class CEffectRing : public CObject2D
{
public:
	static const float INITIAL_SIZE;					//初期サイズ
	static const float SIZE_INCREASE;					//サイズの増加量
	static const float TRANSPARENCY_DECREASE_QUANTITY;	//透明度の減少量
	static const int  FLASH_COUNT;						//フラッシュエフェクトの個数
	
public:
	explicit CEffectRing();
	~CEffectRing() override;

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit() override;
	void Update() override;

	static CEffectRing* Create(D3DXVECTOR3 pos);

private:
	
};

#endif // _EFFECT_RING_H_