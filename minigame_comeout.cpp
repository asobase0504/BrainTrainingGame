//==========================================
//
//  出た順に押す(minigame_comeout.cpp)
//  Author : Tomoya Kanazaki
//
//==========================================
#include "minigame_comeout.h"
#include "input.h"
#include "debug_proc.h"
#include "application.h"
#include "target.h"

//==========================================
//  静的メンバ変数宣言
//==========================================
bool CMiniGameComeOut::m_bClick = false;

//==========================================
//  コンストラクタ
//==========================================
CMiniGameComeOut::CMiniGameComeOut()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_size = D3DXVECTOR2(0.0f, 0.0f);
	m_alignment = D3DXVECTOR2(0.0f, 0.0f);
	m_pPos = NULL;
	m_nNumData = 0;
	m_nInterval = 0;
	m_nTime = 0;
	m_nPopTime = 0;
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
	//経過時間をリセット
	m_nTime = 0;
	m_bClick = false;

	//データを読み込み
	Load();

	//画面の中心を取得する
	m_pos = D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f);

	//ポリゴン数を設定
	m_nNumData = (int)(m_alignment.x * m_alignment.y);

	//ポリゴン数分のメモリを確保
	m_pUse = new bool[m_nNumData];
	for (int nCnt = 0; nCnt < m_nNumData; nCnt++)
	{
		m_pUse[nCnt] = false;
	}

	//座標を設定
	if (m_pPos == NULL)
	{
		//メモリを確保
		m_pPos = new D3DXVECTOR3[m_nNumData];

		//ポリゴン同士の間隔を算出
		D3DXVECTOR2 space = D3DXVECTOR2(m_size.x + m_size.x * 0.2f, m_size.y + m_size.y * 0.2f);

		//座標を計算
		for (int nCntU = 0; nCntU < m_alignment.x; nCntU++)
		{
			for (int nCntV = 0; nCntV < m_alignment.y; nCntV++)
			{
				m_pPos[nCntU + (nCntV * (int)m_alignment.x)] = D3DXVECTOR3
				(
					m_pos.x - (space.x * m_alignment.x) * 0.5f + (space.x * 0.5f + space.x * nCntU),
					m_pos.y - (space.x * m_alignment.x) * 0.5f + (space.y * 0.5f + space.y * nCntV),
					0.0f
				);
			}
		}
	}

	//ターゲットを生成をする
	for (int nCnt = 0; nCnt < m_nNumData; nCnt++)
	{
		//生成,初期化
		m_pTarget.push_back(new CTarget);
		m_pTarget[nCnt]->Init();

		//生成タイミングの設定
		while (1)
		{
			//生成順の乱数を取得
			int nIndex = rand() % m_nNumData;

			//インデックスが使用されていない場合
			if (!m_pUse[nIndex])
			{
				m_pTarget[nCnt]->SetTiming(m_nInterval * (nIndex + 1));
				m_pTarget[nCnt]->SetIndex(nIndex);
				m_pUse[nIndex] = true;

				if (m_nPopTime < m_nInterval * (nIndex + 1))
				{
					m_nPopTime = m_nInterval * (nIndex + 1);
				}
				break;
			}
		}

		//大きさの設定
		m_pTarget[nCnt]->SetSize(m_size);

		//座標の設定
		m_pTarget[nCnt]->SetPos(m_pPos[nCnt]);
	}

	return S_OK;
}

//==========================================
//  終了処理
//==========================================
void CMiniGameComeOut::Uninit()
{
	delete[] m_pUse;
	m_pUse = NULL;
	delete[] m_pPos;
	m_pPos = NULL;
}

//==========================================
//  更新処理
//==========================================
void CMiniGameComeOut::Update()
{
	//経過時間を更新
	m_nTime++;
	CTarget::SetTime(m_nTime);

	//クリックが可能になる時間
	if (!m_bClick)
	{
		if (m_nTime >= m_nPopTime)
		{
			m_bClick = true;
		}
	}

	//クリアフラグ
	if (CTarget::GetNext() == m_nNumData)
	{
		CDebugProc::Print("クリア\n");
	}

	//デバッグ表示
	CDebugProc::Print("出た順に押すモード\n");
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

			//出現間隔の取得
			if (strcmp(&aStr[0], "INTERVAL") == 0)
			{
				fscanf(pFile, "%d", &m_nInterval); //生成間隔
			}

			//ポリゴンサイズの取得
			if (strcmp(&aStr[0], "SIZE") == 0)
			{
				fscanf(pFile, "%f", &m_size.x); //横幅
				fscanf(pFile, "%f", &m_size.y); //縦幅
			}

			//分割数の取得
			if (strcmp(&aStr[0], "ALIGNMENT") == 0)
			{
				fscanf(pFile, "%f", &m_alignment.x); //横分割数
				fscanf(pFile, "%f", &m_alignment.y); //縦分割数
			}

		} while (nEnd != EOF); //読み込んだ文字列が[ EOF ]ではない場合ループ

		//ファイルを閉じる
		fclose(pFile);
	}
}
