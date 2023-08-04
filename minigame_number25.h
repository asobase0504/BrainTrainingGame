//=========================================
// 
// �Q�[�����N���X
// Author BuriyaKota
// 
//=========================================
#ifndef _MINI_GAME_NUMBER25_H_
#define _MINI_GAME_NUMBER25_H_

#include "mode.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CPause;
class CCamera;
class CObject2D;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CMiniGameNumber25 : public CMode
{
public:	// �����o�[�֐�
	CMiniGameNumber25();
	~CMiniGameNumber25() override;

	HRESULT Init() override;
	void Uninit() override;

	// �X�V����
	void Update() override;

	void Draw() override;

	void Shuffle();
	void DrawTime();
	void Touch(float nPosX, float nPosY);

private:

private:
	CObject2D* m_pObject2D[25];
	// �Q�[���J�n����
	DWORD m_dwGameStartTime;
	// �Q�[���o�ߎ���
	DWORD m_dwGameTime;

	// �I���t���O
	bool m_isEndGame;
	// ���Ƀ^�b�`���鐔
	int m_nTouchCount;
};

#endif // !_MINI_GAME_NUMBER25_H_
