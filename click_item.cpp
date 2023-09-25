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
