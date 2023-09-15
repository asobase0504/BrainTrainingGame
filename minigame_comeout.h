//==========================================
//
//  出た順に押す(minigame_comeout.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _MINIGAME_COMEOUT_H_
#define _MINIGAME_COMEOUT_H_
#include "mode.h"

//==========================================
//  前方宣言
//==========================================
class CTarget;

//==========================================
//  クラス定義
//==========================================
class CMiniGameComeOut : public CMode
{
public:

	//メンバ関数
	CMiniGameComeOut();
	~CMiniGameComeOut();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

private:

	//メンバ関数
	void Load(void);

	//メンバ変数
	CTarget *m_pTarget;
	int m_nNumData; //出てくる数

};

#endif
