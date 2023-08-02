#include "bus.h"
#include "object3d.h"

CBus::CBus() :
	CObject3D(CObjectList::LEVEL_3D_1),
	m_passenger(0)
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

	return S_OK;
}

void CBus::Uninit()
{
}

void CBus::Update()
{

}
