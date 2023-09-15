//==================================================
// time.h
// Author: Buriya Kota
//==================================================
#ifndef _TIMER_H_
#define _TIMER_H_

//**************************************************
// インクルード
//**************************************************
#include "object.h"

//**************************************************
// 前方前言　実態はNG　ポインタだけならOK
//**************************************************
class CNumber;

//**************************************************
// クラス
//**************************************************
class CTimer : public CObject
{
public:
	static const int NUM_TIME = 3;
public:
	explicit CTimer(int nPriority = CTaskGroup::LEVEL_2D_1);
	~CTimer() override;

	HRESULT Init() override;
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void Uninit() override;
	void Update() override;
	void Draw() override {}

	void SetPos(D3DXVECTOR3 pos, D3DXVECTOR2 size);

	void SetTimer(int nTime);
	void AddTimer(int nValue) { SetTimer(m_nTime + nValue); }
	void StopTimer(bool stop) { m_bIsStop = stop; }
	int GetTimer() { return m_nTime; }

	static CTimer *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size);

private:
	// Number型の配列
	CNumber *m_pNumber[NUM_TIME];
	// 時間
	int m_nTime;
	// フレームカウント
	int m_nCounter;
	// タイマーを止める
	bool m_bIsStop;
	// フレーム
	int m_nFrame;
	// フレーム
	int m_nSceneFrame;
};

#endif // _TIMER_H_