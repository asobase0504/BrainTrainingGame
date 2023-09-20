//==================================================
// score_up.h
// Author: Buriya Kota
//==================================================
#ifndef _SCORE_UP_H_
#define _SCORE_UP_H_

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
class CScoreUp : public CSequence
{
public:
	explicit CScoreUp();
	~CScoreUp() override;

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void Update() override;

	static CScoreUp *Create(D3DXVECTOR3 pos,int inScore);

private:
	// �t���[���J�E���g
	int m_nCounter;
};

#endif // _TIMER_H_