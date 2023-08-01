//=========================================
// 
// �Q�[�����N���X
// Author YudaKaito
// 
//=========================================
#ifndef _GAME_H_
#define _GAME_H_

#include "mode.h"
#include "file.h"
#include <d3dx9.h>
#include <vector>

//-----------------------------------------
// �O���錾
//-----------------------------------------

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CGame : public CMode
{
public:	// �����o�[�֐�
	CGame();
	~CGame() override;

	HRESULT Init() override;
	void Uninit() override;

	// �X�V����
	void Update() override;

	void Draw() override;

private: // ���I�v���C�x�[�g�֐�

private: // ���I�����o�[�ϐ�

	CPause* m_pause;
};

#endif // !_GAME_H_
