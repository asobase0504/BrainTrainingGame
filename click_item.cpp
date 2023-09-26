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
#include "sound.h"

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CClickItem::CClickItem(int priority) : CObject2D(priority)
{
	m_eventTick = [](){};
	m_tick = 0;
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

	m_tick++;
	m_eventTick();

	m_isClick = false;

	CInput* input = CInput::GetKey();

	if (m_tick >= 5)
	{
		if (input->TriggerTouchClick(m_pos, D3DXVECTOR3(m_size.x, m_size.y, 0.0f) * 0.5f))
		{
			ClickEvent();
			m_isClick = true;
			CApplication::GetInstance()->GetSound()->Play(CSound::LABEL_SE_DECISION);
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
