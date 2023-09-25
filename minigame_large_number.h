//=========================================
// 
// �Q�[�����N���X
// Author BuriyaKota
// 
//=========================================
#ifndef _MINI_GAME_LARGE_NUMBER_H_
#define _MINI_GAME_LARGE_NUMBER_H_

#include "game.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CObject2D;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CMiniGameLargeNumber : public CGame
{
public:	// �����o�[�֐�
	CMiniGameLargeNumber();
	~CMiniGameLargeNumber() override;

	void GameStart() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

private:

};

#endif // !_MINI_GAME_LARGE_NUMBER_H_
