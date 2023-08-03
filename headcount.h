//==========================================
//
//  人数管理クラス(headcount.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _HEADCOUNT_H_
#define _HEADCOUNT_H_

//==========================================
//  クラス定義
//==========================================
class CHeadCount
{
public:
	CHeadCount(); //コンストラクタ
	~CHeadCount(); //デストラクタ

	//メンバ関数
	void Init(void); //初期化処理
	void Uninit(void); //終了処理
	int Add(void); //人数加算処理
	int Sab(void); //人数減算処理
	int GetNum(void) { return m_nHeadCount; } //人数取得処理

	//静的メンバ関数
	static CHeadCount *Create(void); //生成処理
	static void Load(void); //外部ファイルの読み込み

private:

	//外部ファイル情報保存用の構造体
	struct FileData
	{
		int nDefMax; //初期値の最大値
		int nDefMin; //初期値の最小値
		int nAddMax; //加算される値の最大値
		int nAddMin; //加算される値の最小値
		int nSabMax; //減算される値の最大値
		int nSabMin; //減算される値の最小値
	};

	//メンバ変数
	int m_nHeadCount; //現在の人数
	int m_nOldHeadCount; //前回の人数

	//静的メンバ変数
	static FileData ms_FileData; //外部ファイルから読み込んだ情報
	static const char msc_sDebugPass[128]; //読み込むファイルのパス
	static const char msc_sReleaseFile[128]; //読み込むファイルのパス

};

#endif
