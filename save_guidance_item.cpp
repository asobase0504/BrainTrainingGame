#include "save_guidance_item.h"
#include "input.h"
#include "application.h"
#include "fade.h"

CSaveGuidanceItem::CSaveGuidanceItem() :
	CObject2D(CTaskGroup::LEVEL_2D_UI),
	m_isSelect(false)
{
}

CSaveGuidanceItem::~CSaveGuidanceItem()
{
}

HRESULT CSaveGuidanceItem::Init()
{
	CObject2D::Init();
	SetSize(D3DXVECTOR2(147.0f * 0.5f, 706.0f * 0.5f));
	SetTexture("BOOK");
	return E_NOTIMPL;
}

void CSaveGuidanceItem::Update()
{
	CObject2D::Update();
	Select();
}

CSaveGuidanceItem * CSaveGuidanceItem::Create(const D3DXVECTOR3 & pos, std::string savePath)
{
	CSaveGuidanceItem* item = new CSaveGuidanceItem;

	assert(item != nullptr);

	item->Init();
	item->SetPos(pos);

	return item;
}

void CSaveGuidanceItem::Select()
{
	CInput* input = CInput::GetKey();

	if (input->Trigger(MOUSE_KEY::MOUSE_INPUT_LEFT))
	{
		D3DXVECTOR3 mousePos = input->GetMouseCursor();
		if (mousePos.x < m_pos.x + m_size.x * 0.5f && mousePos.x > m_pos.x - m_size.x * 0.5f)
		{
			if (mousePos.y < m_pos.y + m_size.y * 0.5f && mousePos.y > m_pos.y - m_size.y * 0.5f)
			{
				CFade::GetInstance()->NextMode(CMode::MODE_TYPE::SERECT_MODE);
				m_isSelect = true;
			}
		}
	}
}
