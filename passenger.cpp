#include "passenger.h"

CPassenger::CPassenger()
{
}

CPassenger::~CPassenger()
{
}

CPassenger * CPassenger::Create(const D3DXVECTOR3 inPos)
{
	CPassenger* passenger = new CPassenger;

	assert(passenger != nullptr);

	passenger->Init();
	passenger->SetPos(inPos);

	return passenger;
}

HRESULT CPassenger::Init()
{
	CObject3D::Init();

	SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	SetSize(D3DXVECTOR2(1857.0f * 0.015f, 3179.0f * 0.015f));
	SetTexture("HUMAN");
	m_state = State::STOP;

	return S_OK;
}

void CPassenger::Uninit()
{
}

void CPassenger::Update()
{
	switch (m_state)
	{
	case State::STOP:
		break;
	case State::GETOFF:
		AddPos(D3DXVECTOR3(-1.0f, -0.1f, 0.0f));
		break;
	case State::GETIN:
		AddPos(D3DXVECTOR3(0.0f,1.5f,0.0f));
		if (m_pos.y >= -50.0f)
		{
			AddSize(D3DXVECTOR2(-1857.0f * 0.0005f, -3179.0f * 0.0005f));
		}
		if (GetSize().x <= 0.0f)
		{
			Release();
		}
		break;
	default:
		break;
	}
}
