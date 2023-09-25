//==================================================
// time.h
// Author: Buriya Kota
//==================================================
#ifndef _TIMER_H_
#define _TIMER_H_

//**************************************************
// インクルード
//**************************************************
#include "sequence.h"

//**************************************************
// 前方前言　実態はNG　ポインタだけならOK
//**************************************************
class CNumber;

//**************************************************
// クラス
//**************************************************
class CTimer : public CSequence
{
public:
	explicit CTimer();
	~CTimer() override;

	HRESULT Init() override;
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void Update() override;

	void SetTimer(int nValue) { SetNumber(nValue); }
	int GetTimer() { return GetNumber(); }
	void AddTimer(int nValue) { SetNumber(GetNumber() + nValue); }
	void StopTimer(bool stop) { m_bIsStop = stop; }
	bool isStop() { return m_bIsStop; }

	static CTimer *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size);

private:
	// フレームカウント
	int m_nCounter;
	// タイマーを止める
	bool m_bIsStop;
};

#endif // _TIMER_H_