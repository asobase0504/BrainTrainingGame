//=========================================
// 
// ゲーム内クラス
// Author BuriyaKota
// 
//=========================================
#ifndef _MINI_GAME_REMEMBER_BEFORE_H_
#define _MINI_GAME_REMEMBER_BEFORE_H_

#include "game.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CPause;
class CCamera;
class CObject2D;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CMiniGameRememberBefore : public CGame
{
public:	// メンバー関数
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
