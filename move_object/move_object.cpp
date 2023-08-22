#include "move_object.h"

CMoveObject::CMoveObject()
{
}

CMoveObject::~CMoveObject()
{
}

HRESULT CMoveObject::Init()
{
	CObject2D::Init();
	m_move = D3DXVECTOR3(1.0f,1.0f,0.0f);
	SetSize(D3DXVECTOR2(100.0f,100.0f));
	return E_NOTIMPL;
}

void CMoveObject::Uninit()
{
}

void CMoveObject::Update()
{
	AddPos(m_move);
	AddRot(0.01f);
	if (GetPos().x >= 700.0f)
	{
		m_move.x *= -1.0f;
	}
	
	if (GetPos().x <= 350.0f)
	{
		m_move.x *= -1.0f;
	}

	if (GetPos().y >= 700.0f)
	{
		m_move.y *= -1.0f;
	}

	if (GetPos().y <= 350.0f)
	{
		m_move.y *= -1.0f;
	}
}

CMoveObject * CMoveObject::Create(CMiniGameMoveObject::ELevel * level, const int index, const D3DXVECTOR3 & inPos)
{
	CMoveObject* object = new CMoveObject;
	object->Init();
	object->SetPos(inPos);
	object->m_level = level;
	return nullptr;
}
