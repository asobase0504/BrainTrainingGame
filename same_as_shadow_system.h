//==================================================
// same_as_shadow_system.h
// Author: Buriya Kota
//==================================================
#ifndef _SAME_AS_SHADOW_SYSTEM_H_
#define _SAME_AS_SHADOW_SYSTEM_H_

//**************************************************
// インクルード
//**************************************************
#include "object.h"

//**************************************************
// 前方前言　実態はNG　ポインタだけならOK
//**************************************************
class CObject2D;
class CRememberObject;

//**************************************************
// クラス
//**************************************************
class CSameAsShadowSystem : public CObject
{
public:

public:
	explicit CSameAsShadowSystem(int nPriority = CTaskGroup::LEVEL_2D_1);
	~CSameAsShadowSystem();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CSameAsShadowSystem *Create();

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
	// 影のオブジェクト
	std::vector <CRememberObject*> m_pShadowObject;
	// 選択肢
	std::vector <CRememberObject*> m_pSelectObject;

	// テクスチャ
	std::string m_tex[TEXTURE_MAX];

};

#endif	// _SAME_AS_SHADOW_SYSTEM_H_