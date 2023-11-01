//==================================================
// same_as_shadow_system.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "largest_number.h"

#include "sequence.h"
#include "utility.h"

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CLargestNumber::CLargestNumber() : m_isMax(false), m_isMin(false) ,m_pSequence(nullptr), m_space(D3DXVECTOR2(0.0f,0.0f))
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CLargestNumber::~CLargestNumber()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CLargestNumber::Init()
{
	CRememberObject::Init();

	return S_OK;
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CLargestNumber::Init(const D3DXVECTOR3& inPos, const D3DXVECTOR2& inSize)
{
	CRememberObject::Init();

	m_pSequence = CSequence::Create(
		D3DXVECTOR3(inPos.x, inPos.y, 0.0f),
		D3DXVECTOR2(inSize.x * 0.35f, inSize.y * 0.45f), 2);

	return S_OK;
}

//--------------------------------------------------
// 終了
//--------------------------------------------------
void CLargestNumber::Uninit()
{
	CRememberObject::Uninit();
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CLargestNumber::Update()
{
	CRememberObject::Update();
}

//--------------------------------------------------
// 描画
//--------------------------------------------------
void CLargestNumber::Draw()
{
	CRememberObject::Draw();
}

//--------------------------------------------------
// 生成
//--------------------------------------------------
CLargestNumber *CLargestNumber::Create(const D3DXVECTOR3 & inPos, const D3DXVECTOR2 & inSize)
{
	CLargestNumber *pLargestNumber;
	pLargestNumber = new CLargestNumber;

	if (pLargestNumber != nullptr)
	{
		pLargestNumber->Init(inPos, inSize);
		pLargestNumber->SetPos(inPos);
		pLargestNumber->SetSize(inSize);
	}
	else
	{
		assert(false);
	}

	return pLargestNumber;
}

//--------------------------------------------------
// 数の設定
//--------------------------------------------------
void CLargestNumber::SetSequence(int inSequence)
{
	m_pSequence->SetNumber(inSequence);
}

void CLargestNumber::SetColorAlpha(const float& inAlpha)
{
	m_pSequence->SetColorAlpha(inAlpha);
}

//--------------------------------------------------
// リセット
//--------------------------------------------------
void CLargestNumber::Reset()
{
	float size = 0.0f;
	size = FloatRandom(170.0f, 80.0f);
	SetSize(D3DXVECTOR2(size, size));
	m_pSequence->SetSize(D3DXVECTOR2(size * 0.35f, size * 0.45f));
}
