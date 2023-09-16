//==================================================
// time.h
// Author: Buriya Kota
//==================================================
#ifndef _TIMER_H_
#define _TIMER_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "sequence.h"

//**************************************************
// �O���O���@���Ԃ�NG�@�|�C���^�����Ȃ�OK
//**************************************************
class CNumber;

//**************************************************
// �N���X
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
	// �t���[���J�E���g
	int m_nCounter;
	// �^�C�}�[���~�߂�
	bool m_bIsStop;
};

#endif // _TIMER_H_