//==========================================
//
//  セーブ(save.cpp)
//  Author : Tomoya Kanazaki
//
//==========================================
#include "save.h"

//==========================================
//  静的メンバ変数宣言
//==========================================
CMode::MODE_TYPE CSave::m_modeSave = CMode::MODE_TYPE::EXIT_SAVE;
int CSave::m_aScore[(int)CMode::MODE_TYPE::MAX] = {};
const char CSave::msc_sRankingPass[128] = "data\\FILE\\RankingData.bin";

//==========================================
//  書き出し先の設定
//==========================================
void CSave::SaveMode(CMode::MODE_TYPE mode)
{
	m_modeSave = mode;
}

//==========================================
//  スコアを書き出し
//==========================================
void CSave::SaveScore(const int nScore)
{
	//ローカル変数宣言
	FILE *pFile = NULL;

	//バイナリーファイルを開く
	pFile = fopen(&msc_sRankingPass[0], "rb");

	if (pFile != NULL)
	{
		//読み込み
		fread(&m_aScore[0], sizeof(int), (int)CMode::MODE_TYPE::MAX, pFile);

		//ファイルを閉じる
		fclose(pFile);
	}

	//スコアを保存
	if (m_aScore[(int)m_modeSave] < nScore)
	{
		//スコアを上書き
		m_aScore[(int)m_modeSave] = nScore;

		//バイナリーファイルを開く
		pFile = fopen(&msc_sRankingPass[0], "wb");

		if (pFile != NULL)
		{
			//書き出し
			fwrite(&m_aScore[0], sizeof(int), (int)CMode::MODE_TYPE::MAX, pFile);

			//ファイルを閉じる
			fclose(pFile);
		}
	}
}
