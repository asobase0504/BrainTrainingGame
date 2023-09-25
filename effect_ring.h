//==================================================
// effect_ring.h
// Author: Buriya Kota
//==================================================
#ifndef _EFFECT_RING_H_
#define _EFFECT_RING_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object2d.h"

//**************************************************
// �N���X
//**************************************************
class CEffectRing : public CObject2D
{
public:
	static const float INITIAL_SIZE;					//�����T�C�Y
	static const float SIZE_INCREASE;					//�T�C�Y�̑�����
	static const float TRANSPARENCY_DECREASE_QUANTITY;	//�����x�̌�����
	
public:
	explicit CEffectRing();
	~CEffectRing() override;

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit() override;
	void Update() override;

	static CEffectRing* Create(D3DXVECTOR3 pos);

private:
	
};

#endif // _TIMER_H_