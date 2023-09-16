//=========================================
// 
// ゲーム内クラス
// Author BuriyaKota
// 
//=========================================
#ifndef _MINI_GAME_NUMBER25_H_
#define _MINI_GAME_NUMBER25_H_

#include "game.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CPause;
class CCamera;
class CObject2D;
class CTimer;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CMiniGameNumber25 : public CGame
{
public:
	static const int X_LINE = 5;
	static const int Y_LINE = 5;
	static const int TOTAL_NUM = X_LINE * Y_LINE;

public:	// メンバー関数
	CMiniGameNumber25();
	~CMiniGameNumber25() override;

	HRESULT Init() override;
	void Uninit() override;

	void GameStart() override;

	// 更新処理
	void Update() override;

	void Draw() override;

	void Shuffle();
	void DrawTime();
	void Touch(float nPosX, float nPosY);

private:

private:
	CObject2D* m_pObject2D[25];
	CTimer *m_pTimer;
	// ゲーム開始時刻
	DWORD m_dwGameStartTime;
	// ゲーム経過時間
	DWORD m_dwGameTime;

	// 終了フラグ
	bool m_isEndGame;
	// 次にタッチする数
	int m_nTouchCount;
};

#endif // !_MINI_GAME_NUMBER25_H_
