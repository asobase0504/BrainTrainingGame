//==================================================
// 
// Author: Yuda Kaito
//==================================================

//**************************************************
// include
//**************************************************
#include "click_item.h"
#include "application.h"
#include "input.h"

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
CClickItem::CClickItem(int priority) : CObject2D(priority)
{
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
CClickItem::~CClickItem()
{
}

//--------------------------------------------------
// ������
//--------------------------------------------------
HRESULT CClickItem::Init()
{
	CObject2D::Init();

	return S_OK;
}

//--------------------------------------------------
// �X�V
//--------------------------------------------------
void CClickItem::Update()
{
	CObject2D::Update();

	m_isClick = false;

	CInput* input = CInput::GetKey();

	if (input->TriggerTouchClick(m_pos, D3DXVECTOR3(m_size.x, m_size.y, 0.0f) * 0.5f))
	{
		ClickEvent();
		m_isClick = true;
	}
}

CClickItem * CClickItem::Create(const D3DXVECTOR3 & inPos, const D3DXVECTOR2 & inSize, int priority)
{
	CClickItem* item = new CClickItem(priority);

	assert(item != nullptr);

	item->Init();
	item->SetPos(inPos);
	item->SetSize(inSize);

	return item;
}
