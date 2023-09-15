//==========================================
//
//  出た順に押す(minigame_comeout.cpp)
//  Author : Tomoya Kanazaki
//
//==========================================
#include "minigame_comeout.h"
#include "debug_proc.h"
#include "application.h"
#include "target.h"

//==========================================
//  コンストラクタ
//==========================================
CMiniGameComeOut::CMiniGameComeOut()
{
	m_pTarget = NULL;
	m_nNumData = 0;
}

//==========================================
//  デストラクタ
//==========================================
CMiniGameComeOut::~CMiniGameComeOut()
{

}

//==========================================
//  初期化処理
//==========================================
HRESULT CMiniGameComeOut::Init()
{
	//データを読み込み
	Load();

	return S_OK;
}

//==========================================
//  終了処理
//==========================================
void CMiniGameComeOut::Uninit()
{
	//押すやつを削除
	//if (m_pTarget != NULL)
	//{
	//	delete[] m_pTarget;
	//	m_pTarget = NULL;
	//}
}

//==========================================
//  更新処理
//==========================================
void CMiniGameComeOut::Update()
{
	//デバッグ表示
	CDebugProc::Print("出た順に押すモードだよーーーん\n");
	CDebugProc::Print("出現する数 : %d\n", m_nNumData);
}

//==========================================
//  描画処理
//==========================================
void CMiniGameComeOut::Draw()
{

}

//==========================================
//  読み込み処理
//==========================================
void CMiniGameComeOut::Load(void)
{
	//ローカル変数宣言
	FILE *pFile; //ファイル名
	char aStr[256]; //不要な文字列の記録用
	int nEnd; //終了フラグ

	//ファイルを読み取り専用で開く
	pFile = fopen("data\\FILE\\ComeOut.txt", "r");

	//NULLチェック
	if (pFile != NULL)
	{
		do
		{
			//ファイルから文字列を読み込む
			nEnd = fscanf(pFile, "%s", &aStr[0]);

			//データ数の取得
			if (strcmp(&aStr[0], "NUMDATA") == 0)
			{
				fscanf(pFile, "%s", &aStr[0]); // =
				fscanf(pFile, "%d", &m_nNumData); //データ数
			}

		} while (nEnd != EOF); //読み込んだ文字列が[ EOF ]ではない場合ループ

		//ファイルを閉じる
		fclose(pFile);
	}
}
