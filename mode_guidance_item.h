//==================================================
// number.h
// Author: YudaKaito
//==================================================
#ifndef _MODE_GUIDANCE_ITEM_H_
#define _MODE_GUIDANCE_ITEM_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object2D.h"
#include "mode.h"

//**************************************************
// �N���X
//**************************************************
class CModeGuidanceItem : public CObject2D
{
public:
	explicit CModeGuidanceItem();
	~CModeGuidanceItem();

	HRESULT Init() override;
	void Update();

	static CModeGuidanceItem* Create(const D3DXVECTOR3& pos, CMode::MODE_TYPE type);

private:
	void Select();
private:
	CMode::MODE_TYPE m_type;
	int m_delayTime;
	bool m_isSelect;
};


#endif	// _NUMBER_H_