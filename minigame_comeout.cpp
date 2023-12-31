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
	m_pUse = NULL;
	m_pPos = NULL;
	m_nNumData = 0;
	m_nInterval = 0;
	m_nTime = 0;
	m_nPopTime = 0;
	m_nSpeed = 0;
	m_nNext = 0;

	m_correct = 0;
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
	CGame::Init();

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y - 300.0f, 0.0f));
		D3DXVECTOR2 size(1292.0f * 0.4f, 252.0f * 0.4f);
		object->SetSize(size);
		object->SetTexture("TEXT_EXPO_COMEOUT");
	}


	//経過時間をリセット
	m_nTime = 0;
	m_nSpeed = 0;
	m_bClick = false;

	//データを読み込み
	Load();

	return S_OK;
}

//==========================================
//  終了処理
//==========================================
void CMiniGameComeOut::Uninit()
{
	CGame::Uninit();
	if (m_pUse != NULL)
	{
		delete[] m_pUse;
		m_pUse = NULL;
	}
	if (m_pPos != NULL)
	{
		delete[] m_pPos;
		m_pPos = NULL;
	}
}

//==========================================
//  更新処理
//==========================================
void CMiniGameComeOut::Update()
{
	CGame::Update();

	if (GetState() == COUNT_DOWN)
	{
		return;
	}

	//経過時間を更新
	m_nTime++;
	CTarget::SetTime(m_nTime);

	//クリックが可能になる時間
	if (!m_bClick)
	{
		if (m_nTime >= m_nPopTime)
		{
			m_BG->SetColor(D3DXCOLOR(0.4f, 0.85f, 0.4f, 1.0f));
			m_bClick = true;
		}
	}

	// 成功
	if (CTarget::GetNext() == m_nNumData)
	{
		m_correct++;
		if (m_correct >= m_nextNeedCorrect && GetLevel() <= 5)
		{
			m_correct = 0;
			LevelUp();
		}
		Reset();
	}
	
	// 失敗
	bool bMiss = false;
	for (int nCnt = 0; nCnt < m_nNumData; nCnt++)
	{
		bMiss = m_pTarget[nCnt]->GetMiss();
		if (bMiss)
		{
			m_correct--;
			if (m_correct < 0)
			{
				LevelDown();
			}

			Reset();
			break;
		}
	}

	//前回のターゲットから更新されていたらスコアを加算
	int nNext = CTarget::GetNext(); //今回のターゲット
	if (m_nNext != nNext && !bMiss)
	{
		AddScore(3 * (m_nNext + 1));
	}

	//次のターゲットを保存
	m_nNext = nNext;
}

//==========================================
//  描画処理
//==========================================
void CMiniGameComeOut::Draw()
{

}

void CMiniGameComeOut::GameStart()
{
	CGame::GameStart();

	m_BG = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
	m_BG->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f));
	m_BG->SetSize(D3DXVECTOR2(CApplication::CENTER_Y * 1.1f, CApplication::CENTER_Y * 1.1f));
	m_BG->SetTexture("BLOCK_BG");

	//画面の中心を取得する
	m_pos = D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f);

	//ポリゴン数を設定
	m_nNumData = (int)(m_alignment.x * m_alignment.y);

	Set();
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

//==========================================
//  設定
//==========================================
void CMiniGameComeOut::Set(void)
{
	m_BG->SetColor(D3DXCOLOR(0.9f, 0.7f, 0.0f, 1.0f));

	int nowLevel = GetLevel();

	switch (nowLevel)
	{
	case 1:
		m_nNumData = 2;
		m_alignment.x = 2;
		m_alignment.y = 1;
		m_size = D3DXVECTOR2(120.0f, 120.0f);
		m_nextNeedCorrect = 1;
		break;
	case 2:
		m_nNumData = 4;
		m_alignment.x = 2;
		m_alignment.y = 2;
		m_size = D3DXVECTOR2(120.0f, 120.0f);
		m_nextNeedCorrect = 2;
		break;
	case 3:
		m_nNumData = 6;
		m_alignment.x = 3;
		m_alignment.y = 2;
		m_size = D3DXVECTOR2(80.0f, 80.0f);
		m_nextNeedCorrect = 4;
		break;
	case 4:
		m_nNumData = 9;
		m_alignment.x = 3;
		m_alignment.y = 3;
		m_size = D3DXVECTOR2(80.0f, 80.0f);
		m_nextNeedCorrect = 6;
		break;
	case 5:
		m_nNumData = 12;
		m_alignment.x = 4;
		m_alignment.y = 3;
		m_size = D3DXVECTOR2(20.0f, 20.0f);
		break;
	default:
		break;
	}

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
		D3DXVECTOR2 space = D3DXVECTOR2(m_size.x + m_size.x * 0.45f, m_size.y + m_size.y * 0.45f);

		//座標を計算
		for (int nCntU = 0; nCntU < m_alignment.x; nCntU++)
		{
			for (int nCntV = 0; nCntV < m_alignment.y; nCntV++)
			{
				m_pPos[nCntU + (nCntV * (int)m_alignment.x)] = D3DXVECTOR3
				(
					m_pos.x - (space.x * m_alignment.x) * 0.5f + (space.x * 0.5f + space.x * nCntU),
					m_pos.y - (space.y * m_alignment.y) * 0.5f + (space.y * 0.5f + space.y * nCntV),
					0.0f
				);
			}
		}
	}

	m_pTarget.resize(m_nNumData);
	//ターゲットを生成をする
	for (int nCnt = 0; nCnt < m_nNumData; nCnt++)
	{
		m_pTarget[nCnt] = new CTarget;
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

				break;
			}
		}

		//大きさの設定
		m_pTarget[nCnt]->SetSize(m_size);

		//座標の設定
		m_pTarget[nCnt]->SetPos(m_pPos[nCnt]);
	}

	m_nPopTime = m_nInterval * m_nNumData + 5;
}

//==========================================
//  再設定
//==========================================
void CMiniGameComeOut::Reset(void)
{
	if (m_pUse != nullptr)
	{
		delete[] m_pUse;
		m_pUse = nullptr;
	}
	if (m_pPos != nullptr)
	{
		delete[] m_pPos;
		m_pPos = nullptr;
	}
	for (int nCnt = 0; nCnt < m_nNumData; nCnt++)
	{
		m_pTarget[nCnt]->UninitReset();
		m_pTarget[nCnt] = nullptr;
	}
	m_pTarget.clear();

	m_nTime = 0;
	CTarget::SetTime(m_nTime);
	m_nSpeed = 0;
	m_bClick = false;
	Set();
}
