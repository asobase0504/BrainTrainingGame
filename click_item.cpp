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
CClickItem::CClickItem() : CObject2D(CTaskGroup::LEVEL_2D_UI)
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CClickItem::~CClickItem()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CClickItem::Init()
{
	CObject2D::Init();

	return S_OK;
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CClickItem::Update()
{
	CInput* input = CInput::GetKey();

	if (input->Trigger(MOUSE_KEY::MOUSE_INPUT_LEFT))
	{
		D3DXVECTOR3 mousePos = input->GetMouseCursor();
		if (mousePos.x < m_pos.x + m_size.x * 0.5f && mousePos.x > m_pos.x - m_size.x * 0.5f)
		{
			if (mousePos.y < m_pos.y + m_size.y * 0.5f && mousePos.y > m_pos.y - m_size.y * 0.5f)
			{
				ClickEvent();
			}
		}
	}
}
