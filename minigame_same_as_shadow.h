//=========================================
// 
// ゲーム内クラス
// Author BuriyaKota
// 
//=========================================
#ifndef _MINI_GAME_SAME_AS_SHADOW_H_
#define _MINI_GAME_SAME_AS_SHADOW_H_

#include "game.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CObject2D;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CMiniGameSameAsShadow : public CGame
{
public:	// メンバー関数
	CMiniGameSameAsShadow();
	~CMiniGameSameAsShadow() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

private:

};

#endif // !_MINI_GAME_SAME_AS_SHADOW_H_
