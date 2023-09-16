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
	CSequence::Init(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f), D3DXVECTOR2(100.0f, 200.0f), 2);
	SetTimer(3);
	return E_NOTIMPL;
}

void CCountDown::Update()
{
	CTimer::Update();
}

CCountDown * CCountDown::Create()
{
	CCountDown* countDown = new CCountDown;

	assert(countDown != nullptr);

	countDown->Init();

	return countDown;
}
