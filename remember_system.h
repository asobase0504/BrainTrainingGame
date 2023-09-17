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
class CRememberObject;

//**************************************************
// クラス
//**************************************************
class CRememberSystem : public CObject
{
public:
	static const int X_LINE;
	static const int Y_LINE;
	static const int MAX_ANSWER;

public:
	explicit CRememberSystem(int nPriority = CTaskGroup::LEVEL_2D_1);
	~CRememberSystem();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CRememberSystem *Create();

private:
	void InitCreateAnswer_();
	void DisplayRemember_();
	void Choices_();

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
	// 覚えるもの
	CRememberObject *m_pRememberObject;
	// アンサー
	std::vector<CRememberObject*> m_pAnswerObject;
	// テクスチャ
	std::string m_tex[TEXTURE_MAX];
	// この番号を使用したかどうか
	bool m_isUsedNumber[TEXTURE_MAX];
	// 答え
	int m_nAnswer;
	// 一個前のやつ
	int m_nBeforeNumber;

	bool m_isChange;
	int m_changeLag;
};

#endif	// _REMMBER_SYSTEM_H_