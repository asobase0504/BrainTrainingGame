//=========================================
// 
// �Q�[�����N���X
// Author YudaKaito
// 
//=========================================
#ifndef _MINI_GAME_H_
#define _MINI_GAME_H_

#include "game.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CCamera;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CMiniGameBus : public CGame
{
public:	// �����o�[�֐�
	CMiniGameBus();
	~CMiniGameBus() override;

	HRESULT Init() override;
	void Uninit() override;

	// �X�V����
	void Update() override;

	void Draw() override;

private: // ���I�v���C�x�[�g�֐�

private: // ���I�����o�[�ϐ�

	CCamera* m_camera;

	int m_count;
};

#endif // !_GAME_H_
