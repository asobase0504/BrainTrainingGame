//=========================================
// 
// �Q�[�����N���X
// Author BuriyaKota
// 
//=========================================
#ifndef _MINI_GAME_SAME_AS_SHADOW_H_
#define _MINI_GAME_SAME_AS_SHADOW_H_

#include "game.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CObject2D;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CMiniGameSameAsShadow : public CGame
{
public:	// �����o�[�֐�
	CMiniGameSameAsShadow();
	~CMiniGameSameAsShadow() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

private:

};

#endif // !_MINI_GAME_SAME_AS_SHADOW_H_
