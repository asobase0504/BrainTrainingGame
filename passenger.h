//=========================================
// 
// 人間全般クラス
// Author YudaKaito
// 
//=========================================
#ifndef _PASSENGER_H_
#define _PASSENGER_H_

#include "object3d.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CPassenger : public CObject3D
{
private: // 列挙型

	enum class State
	{
		STOP = 0,
		GETOFF,
		GETIN
	};

public:	// メンバー関数
	CPassenger();
	virtual ~CPassenger() override;

	static CPassenger* Create(const D3DXVECTOR3 inPos);
public:	// メンバー関数
	virtual HRESULT Init() override;
	virtual void Uninit() override;

	// 更新処理
	virtual void Update() override;

	void GetIn() { m_state = State::GETIN; }
	void GetOff() { m_state = State::GETOFF; }

private: // 動的プライベート関数

private: // 動的メンバー変数

	State m_state;		// 状態
};

#endif // !_GAME_H_
