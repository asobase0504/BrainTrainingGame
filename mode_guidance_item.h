//==================================================
// number.h
// Author: YudaKaito
//==================================================
#ifndef _MODE_GUIDANCE_ITEM_H_
#define _MODE_GUIDANCE_ITEM_H_

class CObject2D;
class CSequence;

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

	void SetModeTexture(std::string inTexIcon, std::string inTexExpo);

	void ClickEvent();

private:
	void CreateIcon();
private:
	CObject2D* m_icon;
	CObject2D* m_expo;
	CSequence* m_score;
	CMode::MODE_TYPE m_type;
	int m_delayTime;
	bool m_isSelect;
};


#endif	// _NUMBER_H_