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
class CPause;
class CCamera;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CGame : public CMode
{
public:	// メンバー関数
	CGame();
	~CGame() override;

	HRESULT Init() override;
	void Uninit() override;

	// 更新処理
	void Update() override;

	void Draw() override;

private: // 動的プライベート関数

private: // 動的メンバー変数

	CPause* m_pause;
	CCamera* m_camera;

	int m_count;
};

#endif // !_GAME_H_
