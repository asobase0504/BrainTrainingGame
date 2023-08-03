#include "station.h"
#include "bus.h"
#include "utility.h"
#include "passenger.h"
#include <vector>

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
	m_waitTime = 180;

	return S_OK;
}

void CStation::Uninit()
{
}

void CStation::CreatePassenger()
{
	int count = IntRandom(5, 1);
	for (int i = 0; i < count; i++)
	{
		CPassenger* passenger = CPassenger::Create(D3DXVECTOR3(m_pos.x + 30.0f , m_pos.y - 60.0f - 60.0f * i, m_pos.z));
		m_passengerList.push_back(passenger);
	}
}

void CStation::Update()
{
	if (m_bus != nullptr && !m_IsPassed)
	{
		// ìûíÖ
		if (m_bus->IsArrival())
		{
			int size = m_passengerList.size();
			for (int i = 0; i < size; i++)
			{
				m_passengerList[i]->GetIn();
			}

			// ç~é‘
			m_bus->GetOff();

			// èoî≠
			m_waitTime--;
			if (m_waitTime <= 0)
			{
				m_bus->GetOn(size);
				m_waitTime = 120;
				m_bus->Departure(m_nextStation);
				m_bus = nullptr;
				m_IsPassed = true;
			}
		}
	}
}
