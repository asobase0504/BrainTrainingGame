//==================================================
// reflection_object.h
// Author: Buriya Kota
//==================================================
#ifndef _REFLECTION_OBJECT_H_
#define _REFLECTION_OBJECT_H_

//**************************************************
// インクルード
//**************************************************
#include "remember_object.h"

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
class CReflectionObject : public CRememberObject
{
public:
	static const float SPEED;

public:
	explicit CReflectionObject();
	~CReflectionObject();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CReflectionObject *Create(const D3DXVECTOR3& inPos, const D3DXVECTOR2& inSize, int inMyNumber);

private:
	void Reflection_();

private:
};


#endif	// _REFLECTION_OBJECT_H_