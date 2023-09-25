#include "mode_guidance_item.h"
#include "input.h"
#include "application.h"
#include "fade.h"
#include "rule_item.h"
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
	D3DXVECTOR2 size(652.0f * 0.45f, 317.0f * 0.45f);
	SetTexture("TEXT_START");
	SetSize(size);

	return S_OK;
}

void CModeGuidanceItem::Update()
{
	float mul = 1.0f + (sinf((GetTick() * 0.005f) * (D3DX_PI * 2.0f)) + 1.0f) * 0.5f * 0.025f;
	D3DXVECTOR2 size(652.0f * 0.35f, 317.0f * 0.35f);
	SetSize(size * mul);

	CClickItem::Update();
}

CModeGuidanceItem * CModeGuidanceItem::Create(const D3DXVECTOR3 & pos, CMode::MODE_TYPE type)
{
	CModeGuidanceItem* item = new CModeGuidanceItem;

	assert(item != nullptr);

	item->Init();
	item->SetPos(pos);
	item->m_type = type;
	item->CreateIcon();

	return item;
}

void CModeGuidanceItem::SetModeTexture(std::string inTexIcon, std::string inTexExpo)
{
	m_icon->SetTexture(inTexIcon);
	m_expo->SetTexture(inTexExpo);
}

void CModeGuidanceItem::ClickEvent()
{
	CRuleItem::Create(m_type);
}

void CModeGuidanceItem::CreateIcon()
{
	D3DXVECTOR3 pos;

	{
		pos = m_pos;
		pos.x -= 70.0f;
		pos.y -= 40.0f;
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_1);
		object->SetPos(pos);
		D3DXVECTOR2 size(460.0f, 220.0f);
		object->SetSize(size);
		object->SetTexture("GAME_BG");
	}

	{
		pos = m_pos;
		pos.x -= 200.0f;
		pos.y -= 40.0f;
		m_icon = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_1);
		m_icon->SetPos(pos);
		D3DXVECTOR2 size(140.0f, 140.0f);
		m_icon->SetSize(size);
	}

	{
		pos = m_pos;
		pos.x -= 70.0f;
		pos.y -= 140.0f;
		m_expo = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_1);
		m_expo->SetPos(pos);
		D3DXVECTOR2 size(1292.0f * 0.24f, 252.0f * 0.24f);
		m_expo->SetSize(size);
	}
}

