//==================================================
// number.h
// Author: YudaKaito
//==================================================
#ifndef _RULE_ITEM_H_
#define _RULE_ITEM_H_

class CClickItem;
class CSelectMode;

//**************************************************
// インクルード
//**************************************************
#include "object2D.h"
#include "mode.h"

//**************************************************
// クラス
//**************************************************
class CRuleItem : public CObject2D
{
public:
	explicit CRuleItem();
	~CRuleItem();

	HRESULT Init() override;
	void Uninit();
	void Update();

	static CRuleItem* Create(CMode::MODE_TYPE type);
	void SetMode(CSelectMode* inMode) { m_mode = inMode; }
private:
	void SetRuleTexture();
private:
	CSelectMode* m_mode;
	CClickItem* m_start;
	CClickItem* m_back;
	CObject2D* m_BG;
	CMode::MODE_TYPE m_type;
};


#endif	// _NUMBER_H_