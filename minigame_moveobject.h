//=========================================
// 
// ゲーム内クラス
// Author BuriyaKota
// 
//=========================================
#ifndef _MINI_GAME_MOVEOBJECT_H_
#define _MINI_GAME_MOVEOBJECT_H_

#include "mode.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CMoveObject;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CMiniGameMoveObject : public CMode
{
public:	// 列挙型
	enum class ELevel
	{
		LEVEL_1 = 0,
		LEVEL_2,
		LEVEL_3,
	};

public:	// メンバー関数
	CMiniGameMoveObject();
	~CMiniGameMoveObject() override;

	HRESULT Init() override;
	void Uninit() override;

	// 更新処理
	void Update() override;

	void Draw() override;

private:

private:
	ELevel m_level;
	std::vector<CMoveObject*> m_popObject;
};

#endif // !_MINI_GAME_NUMBER25_H_
