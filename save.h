//==========================================
//
//  セーブ(save.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _SAVE_H_
#define _SAVE_H_
#include "mode.h"

//==========================================
//  ネームスペース定義
//==========================================
class CSave
{
public:

	//静的メンバ関数
	static void SaveMode(CMode::MODE_TYPE mode); //書き出し先を設定
	static void SaveScore(const int nScore); //スコアを書き出し

private:

	//メンバ変数
	static CMode::MODE_TYPE m_modeSave;
	static int m_aScore[(int)CMode::MODE_TYPE::MAX];
	static const char msc_sRankingPass[128];

};

#endif
