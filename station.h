//=========================================
// 
// 駅全般クラス
// Author YudaKaito
// 
//=========================================
#ifndef _STATION_H_
#define _STATION_H_

#include "object3d.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CBus;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CStation : public CObject3D
{
private: // 列挙型

public:	// メンバー関数
	CStation();
	virtual ~CStation() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;

	// 更新処理
	virtual void Update() override;

	void Departure(CStation* inStation);	// 出発
	void Arrival();							// 到着
	void GetOff();							// 降車
	void GetOn(int inNumber);				// 乗車

	void SetBus(CBus* inBus) { m_bus = inBus; }

	void AttachNextStation(CStation* inStation) { m_nextStation = inStation; }

private: // 動的プライベート関数

private: // 動的メンバー変数

	CStation* m_nextStation;
	CBus* m_bus;

	int m_passenger;	// 乗客
	int m_waitTime;

	bool m_IsPassed;
};

#endif // !_GAME_H_
