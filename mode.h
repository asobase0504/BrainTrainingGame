//=========================================
// 
// モードクラス
// Author YudaKaito
// 
//=========================================
#ifndef _MODE_H_
#define _MODE_H_

#include <d3dx9.h>

//-----------------------------------------
// モードクラス
//-----------------------------------------
class CMode
{
public:
	enum class MODE_TYPE
	{
		TITLE = 0,
		GAME,
		MINIGAME_BUS,			// バスの乗り降り
		MINIGAME_NUMBER25,		// ナンバー25
		MINIGAME_BOX,			// はこの数を数える
		MINIGAME_CALCULATION,	// フラッシュ暗算
		MINIGAME_CUPSHUFFLE,	// カップシャッフル
		MINIGAME_MOVEOBJECT,	// 動き回る物体の数
		MINIGAME_TROLLEY,		// トロッコ
		MINIGAME_REMEMBER_BEFORE,			// ひとつ前を覚えて
		MINIGAME_COLORTEXT,		// 色分別
		MINIGAME_COMEOUT,		// 出た順番に押す
		MINIGAME_SHADOW,		// かげと同じものはどれ
		MINIGAME_ADD,			// あわせた数
		CUSTUM,
		RESULT,
		MAX
	};
public:	// メンバー関数
	CMode();
	virtual ~CMode();

	virtual HRESULT Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() {};

private: // 動的メンバー変数
};

#endif // !_GAME_H_
