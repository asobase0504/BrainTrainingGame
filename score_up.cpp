#include "score_up.h"

CScoreUp::CScoreUp()
{
}

CScoreUp::~CScoreUp()
{
}

HRESULT CScoreUp::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CSequence::Init(pos, size, 3);
	m_nCounter = 0;
	return S_OK;
}

void CScoreUp::Update()
{
	CSequence::Update();

	AddPos(D3DXVECTOR3(0.0f,1.0f,0.0f));
	AddColor(D3DXCOLOR(0.0f,0.0f,0.0f,-0.055f));

	//フレームカウンター
	m_nCounter++;

	if (m_nCounter >= 60)
	{
		Release();
	}
}

CScoreUp * CScoreUp::Create(D3DXVECTOR3 pos, int inScore)
{
	CScoreUp *score = new CScoreUp;

	assert(score != nullptr);

	score->Init(pos, D3DXVECTOR2(30.0f,100.0f));

	if (inScore > 0)
	{
		score->SetNumber(inScore);
		score->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
	}
	else
	{
		score->SetNumber(inScore * -1.0f);
		score->SetColor(D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f));
	}
	return score;
}
