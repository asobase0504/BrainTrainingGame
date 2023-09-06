//=========================================
// 
// �Q�[�����N���X
// Author BuriyaKota
// 
//=========================================
#ifndef _MINI_GAME_REMEMBER_BEFORE_H_
#define _MINI_GAME_REMEMBER_BEFORE_H_

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
class CMiniGameRememberBefore : public CMode
{
public:
	static const int MAX_TEXTURE = 10;

public:	// �����o�[�֐�
	CMiniGameRememberBefore();
	~CMiniGameRememberBefore() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

private:
	CObject2D* m_pObject2D[MAX_TEXTURE];

};

#endif // !_MINI_GAME_REMEMBER_BEFORE_H_
