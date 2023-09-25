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
class CLargeNumberSystem;

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
	CLargeNumberSystem* m_system;
	CObject2D* m_expo;

	int m_time;
};

#endif // !_MINI_GAME_LARGE_NUMBER_H_
