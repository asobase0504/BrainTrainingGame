//==========================================
//
//  出た順に押す(minigame_pressorder.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _PRESSORDER_H_
#define _PRESSORDER_H_
#include "mode.h"

//==========================================
//  前方宣言
//==========================================
class CTarget;

//==========================================
//  クラス定義
//==========================================
class CMiniGamePressOrder : public CMode
{
public:

	//メンバ関数
	CMiniGamePressOrder();
	~CMiniGamePressOrder() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	//静的メンバ関数
	static void Load(void); //外部ファイルの読み込み処理
	static void UnLoad(void); //データの破棄

private:

	//静的メンバ関数
	static CTarget *m_pTarget;

};

#endif
