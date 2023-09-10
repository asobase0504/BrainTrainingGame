#include "mode_guidance_item.h"
#include "input.h"
#include "application.h"
#include "fade.h"

CModeGuidanceItem::CModeGuidanceItem() : CObject2D(CTaskGroup::LEVEL_2D_UI)
{
}

CModeGuidanceItem::~CModeGuidanceItem()
{
}

HRESULT CModeGuidanceItem::Init()
{
	CObject2D::Init();
	SetSize(D3DXVECTOR2(100.0f,100.0f));

	return E_NOTIMPL;
}

void CModeGuidanceItem::Update()
{
	CObject2D::Update();
	Select();
}

CModeGuidanceItem * CModeGuidanceItem::Create(const D3DXVECTOR3 & pos, CMode::MODE_TYPE type)
{
	CModeGuidanceItem* item = new CModeGuidanceItem;

	assert(item != nullptr);

	item->Init();
	item->SetPos(pos);
	item->m_type = type;

	return item;
}

void CModeGuidanceItem::Select()
{
	CInput* input = CInput::GetKey();

	if (input->Trigger(MOUSE_KEY::MOUSE_INPUT_LEFT))
	{
		D3DXVECTOR3 mousePos = input->GetMouseCursor();
		if (mousePos.x < m_pos.x + 40.0f && mousePos.x > m_pos.x - 40.0f)
		{
			if (mousePos.y < m_pos.y + 40.0f && mousePos.y > m_pos.y - 40.0f)
			{
				CFade::GetInstance()->NextMode(m_type);
			}
		}
	}
}
