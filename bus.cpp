#include "bus.h"
#include "object3d.h"
#include "station.h"
#include "passenger.h"
#include "utility.h"

CBus::CBus() :
	CObject3D(CTaskGroup::LEVEL_3D_1),
	m_passenger(0),
	m_isArrival(false)
{
}

CBus::~CBus()
{
}

HRESULT CBus::Init()
{
	CObject3D::Init();

	SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f,1.0f));
	SetSize(D3DXVECTOR2(1466.f * 0.1f, 588.f * 0.1f));
	SetTexture("BUS");

	return S_OK;
}

void CBus::Uninit()
{
}

void CBus::Update()
{
	CDebugProc::Print("POS %f\n", m_nextStation->GetPos().x);

	if (m_state == State::MOVE && !m_isArrival)
	{
		AddPos(D3DXVECTOR3(-3.0f, 0.0f, 0.0f));

		if (m_nextStation->GetPos().x >= m_pos.x)
		{
			CDebugProc::Print("---STOP---\n");
			m_state = State::STOP;
			m_isArrival = true;
		}
	}

	CDebugProc::Print("State : %s\n", m_state == State::MOVE ? "MOVE" : "STOP");
	CDebugProc::Print("Arrival : %s\n", m_isArrival ? "TRUE" : "FALSE");
	CDebugProc::Print("passenger : %d\n", m_passenger);
	CDebugProc::Print("nextGetOff : %d\n", m_nextGetOff);
}

void CBus::Departure(CStation* inStation)
{
	m_nextStation = inStation;
	m_nextStation->SetBus(this);
	m_isArrival = false;
	m_nextGetOff = IntRandom(m_passenger,0);
	m_state = CBus::State::MOVE;
}

void CBus::GetOff()
{
	if (m_nextGetOff == 0)
	{
		return;
	}

	static int timer = 0;
	int count = 180 / m_nextGetOff;

	timer++;

	if (timer % count == 0)
	{
		D3DXVECTOR3 pos(m_pos);
		pos.y -= 30.0f;
		pos.x -= 50.0f;
		CPassenger* passenger = CPassenger::Create(pos);
		passenger->GetOff();
		m_passenger--;
	}
}
