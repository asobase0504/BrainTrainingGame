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
class CCountDown;
class CSequence;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CGame : public CMode
{
protected:
	enum EState
	{
		COUNT_DOWN,
		GAME_NOW
	};
public:	// メンバー関数
	CGame();
	virtual ~CGame() override;

	virtual HRESULT Init() override;
	virtual void GameStart();
	virtual void Uninit() override;

	// 更新処理
	virtual void Update() override;

	void AddScore(const int inScore);

	int GetLevel() { return m_level; }
	int LevelUp() { return m_level++; }
	int LevelDown() { return m_level--; }

protected:

	EState GetState() { return m_state; }

private: // 動的メンバー変数
	CSequence* m_scoreUI;	// 得点の表示
	int m_score;		// 得点

	EState m_state;		// 状態
	CCountDown* m_countDown;	// カウントダウン

	CTimer* m_timer;

	bool m_isResult;

	int m_level;
};

#endif // !_GAME_H_
