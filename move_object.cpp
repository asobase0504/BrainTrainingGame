#include "move_object.h"

CMoveObject::CMoveObject()
{
}

CMoveObject::~CMoveObject()
{
}

HRESULT CMoveObject::Init()
{
	return E_NOTIMPL;
}

void CMoveObject::Uninit()
{
}

void CMoveObject::Update()
{
	AddPos(m_move);
}

CMoveObject * CMoveObject::Create(CMiniGameMoveObject::ELevel * level, const int index, const D3DXVECTOR3 & inPos)
{
	CMoveObject* object = new CMoveObject;
	object->SetPos(inPos);
	object->m_level = level;
	return nullptr;
}
