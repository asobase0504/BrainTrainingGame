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

};

#endif
