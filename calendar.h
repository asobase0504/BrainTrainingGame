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
#include <array>

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

	// その日程のオブジェクトの取得
	CObject2D* GetDayObject(int inDay) { return m_tag[m_dayTag[inDay]]; }

private:
	CSequence* m_day[49];
	CObject2D* m_tag[49];
	CObject2D* m_stanp[49];
	std::array<int, 31> m_dayTag;
};


#endif	// _NUMBER_H_