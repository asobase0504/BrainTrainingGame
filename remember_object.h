//==================================================
// remember_system.h
// Author: Buriya Kota
//==================================================
#ifndef _REMMBER_OBJECT_H_
#define _REMMBER_OBJECT_H_

//**************************************************
// インクルード
//**************************************************
#include "object2d.h"

//**************************************************
// 前方前言　実態はNG　ポインタだけならOK
//**************************************************

//**************************************************
// 定数定義
//**************************************************

//**************************************************
// 構造体定義
//**************************************************

//**************************************************
// クラス
//**************************************************
class CRememberObject : public CObject2D
{
public:
	explicit CRememberObject(int nPriority = CTaskGroup::LEVEL_2D_1);
	~CRememberObject();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CRememberObject *Create(const D3DXVECTOR3& inPos, const D3DXVECTOR2& inSize, int inMyNumber);

	void SetMyNumber(int inMyNumber) { m_myNumber = inMyNumber; }
	int GetMyNumber() { return m_myNumber; }

private:
	// 自分の番号
	int m_myNumber;

};


#endif	// _REMMBER_OBJECT_H_