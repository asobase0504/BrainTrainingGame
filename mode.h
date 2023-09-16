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
		TITLE = 0,					// Title���S�Ȃǂ��o���̂�
		SERECT_SAVE,				// �Z�[�u�f�[�^�̑I�����s�Ȃ��V�[��
		SERECT_MODE,				// �Q�[�����[�h�̑I�����s�Ȃ��V�[��
		LOGIN,						// �����A���߂Ẵ��O�C���������ꍇ
		EXIT_SAVE,					// ���݂̃Z�[�u�f�[�^�ŗV�Ԃ��Ƃ��I����
		MINIGAME_BUS,				// �o�X�̏��~��
		MINIGAME_NUMBER25,			// �i���o�[25
		MINIGAME_BOX,				// �͂��̐��𐔂���
		MINIGAME_CALCULATION,		// �t���b�V���ÎZ
		MINIGAME_CUPSHUFFLE,		// �J�b�v�V���b�t��
		MINIGAME_MOVEOBJECT,		// ������镨�̂̐�
		MINIGAME_TROLLEY,			// �g���b�R
		MINIGAME_REMEMBER_BEFORE,	// �ЂƂO���o����
		MINIGAME_COLORTEXT,			// �F����
		MINIGAME_COMEOUT,			// �o�����Ԃɉ���
		MINIGAME_SHADOW,			// �����Ɠ������̂͂ǂ�
		MINIGAME_ADD,				// ���킹����
		GAME,
		CUSTUM,
		RESULT,
		MAX
	};
public:	// �����o�[�֐�
	CMode();
	virtual ~CMode();

	virtual HRESULT Init() = 0;
	virtual void Uninit() {};
	virtual void Update() {};
	virtual void Draw() {};

private: // ���I�����o�[�ϐ�
};

#endif // !_GAME_H_
