#include "save_guidance_item.h"
#include "input.h"
#include "application.h"
#include "fade.h"

CSaveGuidanceItem::CSaveGuidanceItem() :
	m_isSelect(false)
{
}

CSaveGuidanceItem::~CSaveGuidanceItem()
{
}

HRESULT CSaveGuidanceItem::Init()
{
	CClickItem::Init();
	SetSize(D3DXVECTOR2(147.0f * 0.5f, 706.0f * 0.5f));
	SetTexture("BOOK");
	return E_NOTIMPL;
}

void CSaveGuidanceItem::Update()
{
	CClickItem::Update();
}

CSaveGuidanceItem * CSaveGuidanceItem::Create(const D3DXVECTOR3 & pos, std::string savePath)
{
	CSaveGuidanceItem* item = new CSaveGuidanceItem;

	assert(item != nullptr);

	item->Init();
	item->SetPos(pos);

	return item;
}

void CSaveGuidanceItem::ClickEvent()
{
	CFade::GetInstance()->NextMode(CMode::MODE_TYPE::SERECT_MODE);
	m_isSelect = true;
}
