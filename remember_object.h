//==================================================
// remember_object.h
// Author: Buriya Kota
//==================================================
#ifndef _REMMBER_OBJECT_H_
#define _REMMBER_OBJECT_H_

//**************************************************
// インクルード
//**************************************************
#include "object2D.h"

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
private:
	enum TEXTURE
	{// 使用しているテクスチャ
		TEXTURE_0 = 0,
		TEXTURE_1,
		TEXTURE_2,
		TEXTURE_MAX
	};

public:
	explicit CRememberObject(int nPriority = CObjectList::LEVEL_2D_1);
	~CRememberObject();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override {}

	static CRememberObject *Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, TEXTURE tex);

private:
	// オブジェクト2Dの箱
	CObject2D *m_pObject2D[TEXTURE_MAX];

};


#endif	// _REMMBER_OBJECT_H_