//==================================================
// score
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "application.h"

#include "sequence.h"
#include "number.h"

//**************************************************
// 静的メンバ変数
//**************************************************

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CSequence::CSequence() : CObject(CTaskGroup::LEVEL_SYSTEM)
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CSequence::~CSequence()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CSequence::Init()
{
	return S_OK;
}

//--------------------------------------------------
// 初期化　オーバーロード
//--------------------------------------------------
HRESULT CSequence::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size,const int digit)
{
	m_digit = digit;
	m_pNumber.resize(m_digit);

	for (int nCnt = 0; nCnt < m_digit; nCnt++)
	{
		m_pNumber[nCnt] = CNumber::Create(D3DXVECTOR3(size.x * nCnt + pos.x, pos.y, 0.0f), size);
		m_pNumber[nCnt]->SetColor(D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
		m_pNumber[nCnt]->SetTexture("TIME_NUMBER");
	}

	return S_OK;
}

//--------------------------------------------------
// 終了
//--------------------------------------------------
void CSequence::Uninit()
{
	for (int nCnt = 0; nCnt < m_digit; nCnt++)
	{
		if (m_pNumber[nCnt] == nullptr)
		{
			continue;
		}

		m_pNumber[nCnt]->Release();
		m_pNumber[nCnt] = nullptr;
	}

	CObject::Release();
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CSequence::Update()
{
}

//--------------------------------------------------
// 位置の設定と大きさの設定
//--------------------------------------------------
void CSequence::SetPos(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	for (int nCnt = 0; nCnt < m_digit; nCnt++)
	{
		m_pNumber[nCnt]->SetPos(D3DXVECTOR3(size.x * nCnt + pos.x, pos.y, 0.0f));
	}
}

void CSequence::SetNumber(int inNumber)
{
	m_number = inNumber;

	std::vector<int> aPosTexU;		//各桁の数字を格納
	aPosTexU.resize(m_digit);

	{
		int timer = inNumber;
		for (int i = m_digit-1; i >= 0; --i)
		{
			aPosTexU[i] = timer % 10;
			timer /= 10;
		}
	}

	// テクスチャ座標の設定
	for (int nCnt = 0; nCnt < m_digit; nCnt++)
	{
		m_pNumber[nCnt]->AnimTexture(aPosTexU[nCnt], 10);
	}
}

//--------------------------------------------------
// 生成
//--------------------------------------------------
CSequence *CSequence::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size, int digit)
{
	CSequence *pTimer;
	pTimer = new CSequence;

	assert(pTimer != nullptr);

	pTimer->Init(pos, size, digit);

	return pTimer;
}
