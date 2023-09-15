//==================================================
// time.h
// Author: Buriya Kota
//==================================================
#ifndef _TIMER_H_
#define _TIMER_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object.h"

//**************************************************
// �O���O���@���Ԃ�NG�@�|�C���^�����Ȃ�OK
//**************************************************
class CNumber;

//**************************************************
// �N���X
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
	// Number�^�̔z��
	CNumber *m_pNumber[NUM_TIME];
	// ����
	int m_nTime;
	// �t���[���J�E���g
	int m_nCounter;
	// �^�C�}�[���~�߂�
	bool m_bIsStop;
	// �t���[��
	int m_nFrame;
	// �t���[��
	int m_nSceneFrame;
};

#endif // _TIMER_H_