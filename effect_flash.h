//==================================================
// effect_flash.h
// Author: Koduns Hirohito
//==================================================
#ifndef _EFFECT_FLASH_H_
#define _EFFECT_FLASH_H_

//**************************************************
// インクルード
//**************************************************
#include "object2d.h"

//**************************************************
// クラス
//**************************************************
class CEffectFlash : public CObject2D
{
public:
	static const int MAX_SIZE;							//最大サイズ
	static const float MIN_SIZE;							//最低サイズ
	static const int MAX_SIZE_INCREASE;					//サイズの最大増加量
	static const float MIN_SIZE_INCREASE;					//サイズの最低増加量
	static const int MAX_TRANSPARENCY_DECREASE_QUANTITY;	//透明度の減少量の最大
	static const float MIN_TRANSPARENCY_DECREASE_QUANTITY;	//透明度の減少量の最低
	static const int MAX_MOVING_LENGTH;					//移動量の最大
	static const float MIN_MOVING_LENGTH;					//移動量の最低

public:
	explicit CEffectFlash();
	~CEffectFlash() override;

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit() override;
	void Update() override;

	static CEffectFlash* Create(D3DXVECTOR3 pos);

private:
	float m_fSizeIncrease;
	float m_fTransparency;
};

#endif // _EFFECT_RING_H_