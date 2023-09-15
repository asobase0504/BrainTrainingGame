//==================================================
// 数字の入力
// Author: YudaKaito
//==================================================
#ifndef _NUMBER_SELECT_H_
#define _NUMBER_SELECT_H_

//**************************************************
// インクルード
//**************************************************
#include "object2D.h"

//**************************************************
// 前方前言　実態はNG　ポインタだけならOK
//**************************************************
class CClickItem;
class CSequence;

//**************************************************
// クラス
//**************************************************
class CNumberSelect : public CObject2D
{
public:
	explicit CNumberSelect();
	~CNumberSelect();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	static CNumberSelect *Create();

	int GetNumber();

	bool IsReturn() { return m_isReturn; }

private:
	CClickItem* m_numberClickItem[10];
	CClickItem* m_returnClickItem;
	CClickItem* m_backClickItem;
	CSequence* m_sequence;
	int m_number;
	bool m_isReturn;
};


#endif	// _NUMBER_H_