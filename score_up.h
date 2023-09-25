//==================================================
// score_up.h
// Author: Buriya Kota
//==================================================
#ifndef _SCORE_UP_H_
#define _SCORE_UP_H_

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
class CScoreUp : public CSequence
{
public:
	explicit CScoreUp();
	~CScoreUp() override;

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void Update() override;

	static CScoreUp *Create(D3DXVECTOR3 pos,int inScore);

private:
	// フレームカウント
	int m_nCounter;
};

#endif // _TIMER_H_