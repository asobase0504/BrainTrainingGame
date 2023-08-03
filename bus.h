//=========================================
// 
// バス全般クラス
// Author YudaKaito
// 
//=========================================
#ifndef _BUS_H_
#define _BUS_H_

#include "object3d.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CStation;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CBus : public CObject3D
{
private: // 列挙型

	enum class State
	{
		MOVE,
		STOP
	};

public:	// メンバー関数
	CBus();
	virtual ~CBus() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;

	// 更新処理
	virtual void Update() override;

	bool IsArrival() { return m_isArrival; }

	void Departure(CStation* inStation);	// 出発
	void Arrival();							// 到着
	void GetOff();							// 降車
	void GetOn(int inNumber) { m_passenger += inNumber; }				// 乗車

private: // 動的プライベート関数

private: // 動的メンバー変数

	CStation* m_nextStation;
	State m_state;		// 状態
	int m_passenger;	// 乗客
	int m_nextGetOff;	// 次降りる人
	bool m_isArrival;	// 到着したか
};

#endif // !_GAME_H_
