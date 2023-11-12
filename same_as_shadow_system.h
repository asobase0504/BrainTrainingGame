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
class CReflectionObject;
class CRememberObject;
class CGame;

//**************************************************
// クラス
//**************************************************
class CSameAsShadowSystem : public CObject
{
public:
	static int MAX_SHADOW;
	static int MAX_CHOICES;
public:
	explicit CSameAsShadowSystem(int nPriority = CTaskGroup::LEVEL_2D_1);
	~CSameAsShadowSystem();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CSameAsShadowSystem *Create(CGame* inMode);

	void SetGameMode() {  }

private:	
	void InitCreateAnswer_();
	void Shadow_();
	void Choices_();
	void AdjustLevel_();

private:
	enum TEXTURE
	{// 使用しているテクスチャ
		TEXTURE_ANIMAL1 = 0,
		TEXTURE_ANIMAL2,
		TEXTURE_ANIMAL3,
		TEXTURE_ANIMAL4,
		TEXTURE_ANIMAL5,
		TEXTURE_ANIMAL6,
		TEXTURE_ANIMAL7,
		TEXTURE_ANIMAL8,
		TEXTURE_ANIMAL9,
		TEXTURE_ANIMAL10,
		TEXTURE_ANIMAL11,
		TEXTURE_ANIMAL12,
		TEXTURE_ANIMAL13,
		TEXTURE_ANIMAL14,
		TEXTURE_ANIMAL15,
		TEXTURE_ANIMAL16,
		TEXTURE_ANIMAL17,
		TEXTURE_ANIMAL18,
		TEXTURE_ANIMAL19,
		TEXTURE_ANIMAL20,
		TEXTURE_ANIMAL21,
		TEXTURE_ANIMAL22,
		TEXTURE_ANIMAL23,
		TEXTURE_ANIMAL24,
		TEXTURE_ANIMAL25,
		TEXTURE_ANIMAL26,
		TEXTURE_ANIMAL27,
		TEXTURE_MAX
	};

private:
	CGame* m_game;

	// 影のオブジェクト
	std::vector<CReflectionObject*> m_pShadowObject;
	// 選択肢
	std::vector<CRememberObject*> m_pSelectObject;
	// テクスチャ
	std::string m_tex[TEXTURE_MAX];
	// この番号を使用したかどうか
	bool m_isUsedNumber[TEXTURE_MAX];
	// 何番目を答えにしたか
	std::vector<bool> m_isAnswerNumber;
	// 答え
	std::vector<int> m_nAnswerNumber;

	bool m_isChange;
	int m_changeLag;
	int m_nCountAnswer;

	int m_oldLevel;

	int m_correct;
	int m_nextNeedCorrect;
};

#endif	// _SAME_AS_SHADOW_SYSTEM_H_