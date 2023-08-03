#include "bus.h"
#include "object3d.h"
#include "station.h"

CBus::CBus() :
	CObject3D(CObjectList::LEVEL_3D_1),
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
}

void CBus::Departure(CStation* inStation)
{
	m_nextStation = inStation;
	m_nextStation->SetBus(this);
	m_isArrival = false;
	m_state = CBus::State::MOVE;
}
