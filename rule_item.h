//==================================================
// number.h
// Author: YudaKaito
//==================================================
#ifndef _RULE_ITEM_H_
#define _RULE_ITEM_H_

class CClickItem;

//**************************************************
// �C���N���[�h
//**************************************************
#include "object2D.h"
#include "mode.h"

//**************************************************
// �N���X
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