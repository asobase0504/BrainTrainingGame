//=========================================
// 
// �Q�[�����N���X
// Author YudaKaito
// 
//=========================================
#ifndef _GAME_H_
#define _GAME_H_

#include "mode.h"
#include <d3dx9.h>
#include <vector>

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CTimer;
class CCountDown;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CGame : public CMode
{
protected:
	enum EState
	{
		COUNT_DOWN,
		GAME_NOW
	};
public:	// �����o�[�֐�
	CGame();
	virtual ~CGame() override;

	virtual HRESULT Init() override;
	virtual void GameStart();
	virtual void Uninit() override;

	// �X�V����
	virtual void Update() override;

protected:

	EState GetState() { return m_state; }

private: // ���I�����o�[�ϐ�
	int m_score;		// ���_
	EState m_state;		// ���
	CCountDown* m_countDown;	// �J�E���g�_�E��

	CTimer* m_timer;

	bool m_isResult;
};

#endif // !_GAME_H_
