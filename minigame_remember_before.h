//=========================================
// 
// �Q�[�����N���X
// Author BuriyaKota
// 
//=========================================
#ifndef _MINI_GAME_REMEMBER_BEFORE_H_
#define _MINI_GAME_REMEMBER_BEFORE_H_

#include "game.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CPause;
class CCamera;
class CObject2D;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CMiniGameRememberBefore : public CGame
{
public:	// �����o�[�֐�
	CMiniGameRememberBefore();
	~CMiniGameRememberBefore() override;

	HRESULT Init() override;

	void GameStart() override;

	void Uninit() override;
	void Update() override;
	void Draw() override;

private:

};

#endif // !_MINI_GAME_REMEMBER_BEFORE_H_
