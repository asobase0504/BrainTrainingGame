//==================================================
// number.h
// Author: YudaKaito
//==================================================
#ifndef _MODE_GUIDANCE_ITEM_H_
#define _MODE_GUIDANCE_ITEM_H_

//**************************************************
// インクルード
//**************************************************
#include "click_item.h"
#include "mode.h"

//**************************************************
// クラス
//**************************************************
class CModeGuidanceItem : public CClickItem
{
public:
	explicit CModeGuidanceItem();
	~CModeGuidanceItem();

	HRESULT Init() override;
	void Update();

	static CModeGuidanceItem* Create(const D3DXVECTOR3& pos, CMode::MODE_TYPE type);

	void ClickEvent();

private:
	CMode::MODE_TYPE m_type;
	int m_delayTime;
	bool m_isSelect;
};


#endif	// _NUMBER_H_