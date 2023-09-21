#include "mode_guidance_item.h"
#include "input.h"
#include "application.h"
#include "fade.h"
#include <locale>

CModeGuidanceItem::CModeGuidanceItem()
{
}

CModeGuidanceItem::~CModeGuidanceItem()
{
}

HRESULT CModeGuidanceItem::Init()
{
	CObject2D::Init();
	SetSize(D3DXVECTOR2(140.0f,140.0f));
	return S_OK;
}

void CModeGuidanceItem::Update()
{
	CClickItem::Update();
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

void CModeGuidanceItem::ClickEvent()
{
	CFade::GetInstance()->NextMode(m_type);
}

