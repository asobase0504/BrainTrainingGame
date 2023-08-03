//==========================================
//
//  人数管理クラス(headcount.cpp)
//  Author : Tomoya Kanazaki
//
//==========================================
#include "headcount.h"
#include <stdio.h>
#include <d3dx9.h>
#include "error_warning.h"

//==========================================
//  静的メンバ変数宣言
//==========================================
CHeadCount::FileData CHeadCount::ms_FileData = { 0, 0, 0, 0, 0, 0 };
const char CHeadCount::msc_sDebugPass[128] = "data\\LevelData.txt"; //デバッグ用のテキストファイル
const char CHeadCount::msc_sReleaseFile[128] = "data\\LevelData.bin"; //リリース用のバイナリーファイル

//==========================================
//  コンストラクタ
//==========================================
CHeadCount::CHeadCount()
{
	m_nHeadCount = 0;
}

//==========================================
//  デストラクタ
//==========================================
CHeadCount::~CHeadCount()
{

}

//==========================================
//  初期化処理
//==========================================
void CHeadCount::Init(void)
{
	//初期値を設定する
	m_nHeadCount = (rand() % ms_FileData.nDefMax) + ms_FileData.nDefMin;
}

//==========================================
//  終了処理
//==========================================
void CHeadCount::Uninit(void)
{
	//自身のメモリを開放する
	delete this;
}

//==========================================
//  人数加算処理
//==========================================
int CHeadCount::Add(void)
{
	//加算する人数を決める
	int nAddNum = (rand() % ms_FileData.nAddMax) + ms_FileData.nAddMin;

	//加算前の人数を保存する
	m_nOldHeadCount = m_nHeadCount;

	//人数を加算する
	m_nHeadCount += nAddNum;

	//加算した値を返す
	return nAddNum;
}

//==========================================
//  人数減算処理
//==========================================
int CHeadCount::Sab(void)
{
	//ローカル変数宣言
	int nSabNum = 0;

	if (m_nHeadCount <= 0) //これ以上減らない
	{
		while (1)//無限ループ
		{
			//減算する人数を決める
			nSabNum = (rand() % ms_FileData.nSabMax) + ms_FileData.nSabMin;

			//既に存在している人数より少ない場合抜け出す
			if (m_nOldHeadCount >= nSabNum)
			{
				break;
			}
		}

		//人数を減算する
		m_nHeadCount -= nSabNum;
	}

	//減算した値を返す
	return nSabNum;
}

//==========================================
//  生成処理
//==========================================
CHeadCount *CHeadCount::Create(void)
{
	//ローカル変数宣言
	CHeadCount *pHeadCount = NULL;

	//メモリを確保
	pHeadCount = new CHeadCount;

	//初期化
	pHeadCount->Init();

	//変数を返す
	return pHeadCount;
}

//==========================================
//  読み込み処理
//==========================================
void CHeadCount::Load(void)
{
	//ローカル変数宣言
	FILE *pFile = NULL;

#ifdef _DEBUG //デバッグビルド時の処理

	//文字列を取得する変数
	char aString[128];

	//テキストファイルを開く
	pFile = fopen(&msc_sDebugPass[0], "r");

	if (pFile != NULL)
	{
		//終了判定用変数
		int nEnd = 0;

		//読み込みループ
		do
		{
			//ファイルから文字列を読み込む
			nEnd = fscanf(pFile, "%s", &aString[0]);

			//読み込まれた文字列から分岐
			if (strcmp(&aString[0], "DefMax") == 0)
			{
				fscanf(pFile, "%s", &aString[0]); // =
				fscanf(pFile, "%d", &ms_FileData.nDefMax); //初期値の最大値を取得
			}
			if (strcmp(&aString[0], "DefMin") == 0)
			{
				fscanf(pFile, "%s", &aString[0]); // =
				fscanf(pFile, "%d", &ms_FileData.nDefMin); //初期値の最小値を取得
			}
			if (strcmp(&aString[0], "AddMax") == 0)
			{
				fscanf(pFile, "%s", &aString[0]); // =
				fscanf(pFile, "%d", &ms_FileData.nAddMax); //加算される値の最大値を取得
			}
			if (strcmp(&aString[0], "AddMin") == 0)
			{
				fscanf(pFile, "%s", &aString[0]); // =
				fscanf(pFile, "%d", &ms_FileData.nAddMin); //加算される値の最小値を取得
			}
			if (strcmp(&aString[0], "SadMax") == 0)
			{
				fscanf(pFile, "%s", &aString[0]); // =
				fscanf(pFile, "%d", &ms_FileData.nSabMax); //減算される値の最大値を取得
			}
			if (strcmp(&aString[0], "SadMin") == 0)
			{
				fscanf(pFile, "%s", &aString[0]); // =
				fscanf(pFile, "%d", &ms_FileData.nSabMin); //減算される値の最小値を取得
			}

		} while (nEnd != EOF); //読み込んだ文字列が[ EOF ]ではない場合ループ

		// ファイルを閉じる
		fclose(pFile);

		//バイナリーファイルを開く
		pFile = fopen(&msc_sReleaseFile[0], "wb");

		if (pFile != NULL)
		{
			//書き出し
			fwrite(&ms_FileData, sizeof(FileData), 1, pFile);

			//ファイルを閉じる
			fclose(pFile);
		}
		else
		{
			//エラー表示
			ErrorWarningStatement();
		}
	}
	else
	{
		//エラー表示
		ErrorWarningStatement();
	}

#else //リリースビルド時の処理

	//バイナリーファイルを開く
	pFile = fopen(&msc_sReleaseFile[0], "rb");

	if (pFile != NULL)
	{
		//読み込み
		fread(&ms_FileData, sizeof(FileData), 1, pFile);

		//ファイルを閉じる
		fclose(pFile);
	}
	else
	{
		//エラー表示
		ErrorWarningStatement();
	}

#endif

}
