#include "station.h"
#include "bus.h"

CStation::CStation() : 
	m_bus(nullptr),
	m_IsPassed(false)
{
}

CStation::~CStation()
{
}

HRESULT CStation::Init()
{
	CObject3D::Init();

	SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	SetSize(D3DXVECTOR2(780.f * 0.025f, 2762.f * 0.025f));
	SetTexture("STATION");
	m_waitTime = 60;

	return S_OK;
}

void CStation::Uninit()
{
}

void CStation::Update()
{
	if (m_bus != nullptr && !m_IsPassed)
	{
		if (m_bus->IsArrival())
		{
			m_waitTime--;
			if (m_waitTime <= 0)
			{
				m_waitTime = 60;
				m_bus->Departure(m_nextStation);
				m_bus = nullptr;
				m_IsPassed = true;
			}
		}
	}
}
