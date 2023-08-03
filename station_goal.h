//=========================================
// 
// 駅全般クラス
// Author YudaKaito
// 
//=========================================
#ifndef _STATION_GOAL_H_
#define _STATION_GOAL_H_

#include "station.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CBus;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CStationGoal : public CStation
{
private: // 列挙型

public:	// メンバー関数
	CStationGoal();
	virtual ~CStationGoal() override;

	// 更新処理
	virtual void Update() override;

private: // 動的プライベート関数

private: // 動的メンバー変数

};

#endif // !_GAME_H_
