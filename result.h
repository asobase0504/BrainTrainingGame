//==================================================
// リザルト画面の生成
// Author: YudaKaito
//==================================================
#ifndef _RESULT_H_
#define _RESULT_H_

//**************************************************
// インクルード
//**************************************************
#include "object2D.h"

//**************************************************
// 前方前言　実態はNG　ポインタだけならOK
//**************************************************
class CClickItem;

//**************************************************
// クラス
//**************************************************
class CResult : public CObject2D
{
public:
	explicit CResult();
	~CResult();

	HRESULT Init() override;
	void Update() override;

	static CResult *Create();

private:
	CClickItem* m_nextClickItem;
	CClickItem* m_retryClickItem;
	CClickItem* m_backClickItem;
};


#endif	// _NUMBER_H_