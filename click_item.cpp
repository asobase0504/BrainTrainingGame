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
// コンストラクタ
//--------------------------------------------------
CClickItem::CClickItem(int priority) : CObject2D(priority)
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CClickItem::~CClickItem()
{
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CClickItem::Update()
{
	CObject2D::Update();

	m_isClick = false;

	CInput* input = CInput::GetKey();

	if (input->Trigger(MOUSE_KEY::MOUSE_INPUT_LEFT))
	{
		D3DXVECTOR3 mousePos = input->GetMouseCursor();
		if (mousePos.x < m_pos.x + m_size.x * 0.5f && mousePos.x > m_pos.x - m_size.x * 0.5f)
		{
			if (mousePos.y < m_pos.y + m_size.y * 0.5f && mousePos.y > m_pos.y - m_size.y * 0.5f)
			{
				ClickEvent();
				m_isClick = true;
			}
		}
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
