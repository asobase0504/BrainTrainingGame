//==================================================
// number.h
// Author: YudaKaito
//==================================================
#ifndef _RULE_ITEM_H_
#define _RULE_ITEM_H_

class CClickItem;

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
private:
	void SetRuleTexture();
private:
	CClickItem* m_start;
	CClickItem* m_back;
	CMode::MODE_TYPE m_type;
};


#endif	// _NUMBER_H_