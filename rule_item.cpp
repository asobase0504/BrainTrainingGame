#include "rule_item.h"
#include "click_item.h"
#include "application.h"
#include "fade.h"

CRuleItem::CRuleItem() : CObject2D(CTaskGroup::EPriority::LEVEL_2D_UI_2)
{
}

CRuleItem::~CRuleItem()
{
}

HRESULT CRuleItem::Init()
{
	CObject2D::Init();
	{
		D3DXVECTOR3 pos(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f);
		SetPos(pos);
		D3DXVECTOR2 size(CApplication::SCREEN_WIDTH * 0.75f, CApplication::SCREEN_HEIGHT * 0.75f);
		SetSize(size);
	}

	{
		D3DXVECTOR2 size(D3DXVECTOR2(652.0f, 317.0f));
		size *= 0.35f;
		D3DXVECTOR3 pos(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f);
		pos.x += CApplication::SCREEN_WIDTH * 0.75f * 0.5f - size.x * 0.5f - 20.0f;
		pos.y += CApplication::SCREEN_HEIGHT * 0.75f * 0.5f - size.y * 0.5f - 20.0f;
		m_start = CClickItem::Create(pos, size, CTaskGroup::EPriority::LEVEL_PAUSE);
		m_start->SetEvent([this]()
		{
			CFade::GetInstance()->NextMode(m_type);
		});
		m_start->SetTexture("TEXT_START");
	}

	{
		D3DXVECTOR2 size(D3DXVECTOR2(200.0f, 200.0f));
		size *= 0.35f;
		D3DXVECTOR3 pos(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f);
		pos.x += CApplication::SCREEN_WIDTH * 0.75f * 0.5f - size.x * 0.5f - 20.0f;
		pos.y -= CApplication::SCREEN_HEIGHT * 0.75f * 0.5f - size.y * 0.5f - 20.0f;
		m_back = CClickItem::Create(pos, size, CTaskGroup::EPriority::LEVEL_PAUSE);
		m_back->SetEvent([this]()
		{
			this->Uninit();
		});
		m_back->SetTexture("BACK_BUTTON");
	}
	return S_OK;
}

void CRuleItem::Uninit()
{
	CObject2D::Uninit();

	m_start->Uninit();
	m_back->Uninit();
}

void CRuleItem::Update()
{
	CObject2D::Update();
}

CRuleItem * CRuleItem::Create(CMode::MODE_TYPE type)
{
	CRuleItem* item = new CRuleItem;

	assert(item != nullptr);

	item->Init();
	item->m_type = type;
	item->SetRuleTexture();

	return item;
}

void CRuleItem::SetRuleTexture()
{
	std::string path;
	switch (m_type)
	{
	case CMode::MODE_TYPE::MINIGAME_REMEMBER_BEFORE:
		path = "TUTORIAL_00";
		break;
	case CMode::MODE_TYPE::MINIGAME_COMEOUT:
		path = "TUTORIAL_02";
		break;
	case CMode::MODE_TYPE::MINIGAME_SHADOW:
		path = "TUTORIAL_01";
		break;
	case CMode::MODE_TYPE::MINIGAME_LARGE_NUMBER:
		path = "TUTORIAL_03";
		break;
	default:
		path = "TEST";
		assert(false);
		break;
	}

	SetTexture(path);
}
