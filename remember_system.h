//==================================================
// remember_system.h
// Author: Buriya Kota
//==================================================
#ifndef _REMMBER_SYSTEM_H_
#define _REMMBER_SYSTEM_H_

//**************************************************
// インクルード
//**************************************************
#include "object.h"

//**************************************************
// 前方前言　実態はNG　ポインタだけならOK
//**************************************************
class CObject2D;

//**************************************************
// 定数定義
//**************************************************
class CRememberObject;

//**************************************************
// 構造体定義
//**************************************************

//**************************************************
// クラス
//**************************************************
class CRememberSystem : public CObject
{
public:
	explicit CRememberSystem(int nPriority = CTaskGroup::LEVEL_2D_1);
	~CRememberSystem();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CRememberSystem *Create();

private:
	enum TEXTURE
	{// 使用しているテクスチャ
		TEXTURE_WINTER = 0,
		TEXTURE_SUN_FLOWER,
		TEXTURE_MOUNTAIN,
		TEXTURE_GORYOKAKU,
		TEXTURE_GAME,
		TEXTURE_FLOWER_GARD,
		TEXTURE_DUCK,
		TEXTURE_DOG,
		TEXTURE_CLOUD,
		TEXTURE_CASTLE,
		TEXTURE_MAX
	};

private:
	// オブジェクト2Dの箱
	CRememberObject *m_pRememberObject[TEXTURE_MAX];

};


#endif	// _REMMBER_SYSTEM_H_