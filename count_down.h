//==================================================
// time.h
// Author: Buriya Kota
//==================================================
#ifndef _COUNT_DOWN_H_
#define _COUNT_DOWN_H_

//**************************************************
// インクルード
//**************************************************
#include "timer.h"

//**************************************************
// クラス
//**************************************************
class CCountDown : public CTimer
{
public:
	explicit CCountDown();
	~CCountDown() override;

	HRESULT Init() override;
	void Update() override;

	static CCountDown* Create();
private:
	int m_fream;
};

#endif // _TIMER_H_