//==================================================
// number.h
// Author: YudaKaito
//==================================================
#ifndef _SAVE_GUIDANCE_ITEM_H_
#define _SAVE_GUIDANCE_ITEM_H_

//**************************************************
// インクルード
//**************************************************
#include "object2D.h"
#include "mode.h"

//**************************************************
// クラス
//**************************************************
class CSaveGuidanceItem : public CObject2D
{
public:
	explicit CSaveGuidanceItem();
	~CSaveGuidanceItem();

	HRESULT Init() override;
	void Update();

	bool IsSelect() { return m_isSelect; }

	static CSaveGuidanceItem* Create(const D3DXVECTOR3& pos, std::string savePath);

private:
	void Select();
private:
	CMode::MODE_TYPE m_type;
	int m_delayTime;
	bool m_isSelect;
};


#endif	// _NUMBER_H_