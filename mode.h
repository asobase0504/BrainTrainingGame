//=========================================
// 
// ���[�h�N���X
// Author YudaKaito
// 
//=========================================
#ifndef _MODE_H_
#define _MODE_H_

#include <d3dx9.h>

//-----------------------------------------
// ���[�h�N���X
//-----------------------------------------
class CMode
{
public:
	enum class MODE_TYPE
	{
		TITLE = 0,
		GAME,
		MINIGAME_BUS,			// �o�X�̏��~��
		MINIGAME_NUMBER25,		// �i���o�[25
		MINIGAME_BOX,			// �͂��̐��𐔂���
		MINIGAME_CALCULATION,	// �t���b�V���ÎZ
		MINIGAME_CUPSHUFFLE,	// �J�b�v�V���b�t��
		MINIGAME_MOVEOBJECT,	// ������镨�̂̐�
		MINIGAME_TROLLEY,		// �g���b�R
		MINIGAME_REMEMBER_BEFORE,			// �ЂƂO���o����
		MINIGAME_COLORTEXT,		// �F����
		MINIGAME_COMEOUT,		// �o�����Ԃɉ���
		MINIGAME_SHADOW,		// �����Ɠ������̂͂ǂ�
		MINIGAME_ADD,			// ���킹����
		CUSTUM,
		RESULT,
		MAX
	};
public:	// �����o�[�֐�
	CMode();
	virtual ~CMode();

	virtual HRESULT Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() {};

private: // ���I�����o�[�ϐ�
};

#endif // !_GAME_H_
