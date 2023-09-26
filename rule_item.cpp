#include "rule_item.h"
#include "click_item.h"
#include "application.h"
#include "fade.h"
#include "select_mode.h"

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
		m_start->SetEventTick([this, size]()
		{
			float mul = 1.0f + (sinf((m_start->GetTick() * 0.015f) * (D3DX_PI * 2.0f)) + 1.0f) * 0.5f * 0.1f;
			m_start->SetSize(size * mul);
		});
		m_start->SetTexture("TEXT_START");
	}

	{
		m_BG = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_UI);
		D3DXVECTOR3 pos(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f);
		m_BG->SetPos(pos);
		D3DXVECTOR2 size(D3DXVECTOR2(CApplication::CENTER_X * 2.0f, CApplication::CENTER_Y * 2.0f));
		m_BG->SetSize(size);
		m_BG->SetColor(D3DXCOLOR(0.0f,0.0f,0.0f,0.45f));
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
			m_mode->OnClick();
			this->Uninit();
		});
		m_back->SetTexture("BACK_BUTTON");
	}
	return S_OK;
}

void CRuleItem::Uninit()
{
	CObject2D::Uninit();

	if (m_BG != nullptr)
	{
		m_BG->Uninit();
		m_BG = nullptr;
	}
	if (m_start != nullptr)
	{
		m_start->Uninit();
		m_start = nullptr;
	}
	if (m_back != nullptr)
	{
		m_back->Uninit();
		m_back = nullptr;
	}
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
