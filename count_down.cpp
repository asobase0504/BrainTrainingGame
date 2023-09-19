#include "count_down.h"
#include "application.h"

CCountDown::CCountDown()
{
}

CCountDown::~CCountDown()
{
}

HRESULT CCountDown::Init()
{
	m_fream = 0;
	CSequence::Init(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f), D3DXVECTOR2(100.0f, 200.0f), 1);
	SetTimer(3);
	SetColor(D3DXCOLOR(1.0f,1.0f,0.0f,1.0f));
	return E_NOTIMPL;
}

void CCountDown::Update()
{
	m_fream++;
	CTimer::Update();

	//AddPos(D3DXVECTOR3(0.0f, cosf(m_fream / 15.0f) * 1.0f, 0.0f));
	AddSize(D3DXVECTOR2(cosf(m_fream / 15.0f) * 1.5f, cosf(m_fream / 15.0f) * 1.5f));
}

CCountDown* CCountDown::Create()
{
	CCountDown* countDown = new CCountDown;

	assert(countDown != nullptr);

	countDown->Init();

	return countDown;
}
