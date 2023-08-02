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

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CBus : public CObject3D
{
public:	// メンバー関数
	CBus();
	virtual ~CBus() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;

	// 更新処理
	virtual void Update() override;

private: // 動的プライベート関数

private: // 動的メンバー変数

	int m_passenger;			// 乗客
};

#endif // !_GAME_H_
