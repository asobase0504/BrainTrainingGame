//=========================================
// 
// ゲーム内クラス
// Author YudaKaito
// 
//=========================================
#ifndef _GAME_H_
#define _GAME_H_

#include "mode.h"
#include <d3dx9.h>
#include <vector>

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CTimer;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CGame : public CMode
{
public:	// メンバー関数
	CGame();
	~CGame() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;

	// 更新処理
	virtual void Update() override;

private: // 動的プライベート関数

private: // 動的メンバー変数
	int m_score;		// 得点
	CTimer* m_timer;
};

#endif // !_GAME_H_
