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

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CGame : public CMode
{
public:	// �����o�[�֐�
	CGame();
	~CGame() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;

	// �X�V����
	virtual void Update() override;

private: // ���I�v���C�x�[�g�֐�

private: // ���I�����o�[�ϐ�
	int m_score;		// ���_
	CTimer* m_timer;
};

#endif // !_GAME_H_
