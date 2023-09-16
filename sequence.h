//==================================================
// time.h
// Author: Buriya Kota
//==================================================
#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

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
class CSequence : public CObject
{
private:
	static const int NUM_DIGIT = 3;
public:
public:
	explicit CSequence();
	~CSequence() override;

	HRESULT Init() override;
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void Uninit() override;
	void Update() override;
	void Draw() override {}

	void SetPos(D3DXVECTOR3 pos, D3DXVECTOR2 size);

	void SetNumber(int inNumber);
	int GetNumber() { return m_number; }

	static CSequence* Create(D3DXVECTOR3 pos, D3DXVECTOR2 size);

private:
	// Number型の配列
	std::vector<CNumber*> m_pNumber;
	// 時間
	int m_number;
};

#endif // _TIMER_H_