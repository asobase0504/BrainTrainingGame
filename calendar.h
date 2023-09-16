//==================================================
// リザルト画面の生成
// Author: YudaKaito
//==================================================
#ifndef _CALENDER_H_
#define _CALENDER_H_

//**************************************************
// インクルード
//**************************************************
#include "object2D.h"

//**************************************************
// 前方前言　実態はNG　ポインタだけならOK
//**************************************************
class CSequence;

//**************************************************
// クラス
//**************************************************
class CCalender : public CObject2D
{
public:
	explicit CCalender();
	~CCalender();

	HRESULT Init() override;
	void Update() override;

	static CCalender* Create();

private:
	CSequence* m_day[49];
};


#endif	// _NUMBER_H_