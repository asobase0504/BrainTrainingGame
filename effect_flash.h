//==================================================
// effect_flash.h
// Author: Koduns Hirohito
//==================================================
#ifndef _EFFECT_FLASH_H_
#define _EFFECT_FLASH_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object2d.h"

//**************************************************
// �N���X
//**************************************************
class CEffectFlash : public CObject2D
{
public:
	static const int MAX_SIZE;							//�ő�T�C�Y
	static const float MIN_SIZE;							//�Œ�T�C�Y
	static const int MAX_SIZE_INCREASE;					//�T�C�Y�̍ő呝����
	static const float MIN_SIZE_INCREASE;					//�T�C�Y�̍Œᑝ����
	static const int MAX_TRANSPARENCY_DECREASE_QUANTITY;	//�����x�̌����ʂ̍ő�
	static const float MIN_TRANSPARENCY_DECREASE_QUANTITY;	//�����x�̌����ʂ̍Œ�
	static const int MAX_MOVING_LENGTH;					//�ړ��ʂ̍ő�
	static const float MIN_MOVING_LENGTH;					//�ړ��ʂ̍Œ�

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