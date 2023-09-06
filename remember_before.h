//=========================================
// 
// ゲーム内クラス
// Author BuriyaKota
// 
//=========================================
#ifndef _MINI_GAME_REMEMBER_BEFORE_H_
#define _MINI_GAME_REMEMBER_BEFORE_H_

#include "mode.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CPause;
class CCamera;
class CObject2D;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CMiniGameRememberBefore : public CMode
{
public:
	static const int MAX_TEXTURE = 10;

public:	// メンバー関数
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
