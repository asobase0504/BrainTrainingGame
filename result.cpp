//==================================================
// 
// Author: Yuda Kaito
//==================================================

//**************************************************
// include
//**************************************************
#include "result.h"
#include "application.h"
#include "click_item.h"
#include "fade.h"
#include "sequence.h"

//--------------------------------------------------
// 静的変数
//--------------------------------------------------
CMode::MODE_TYPE CResult::m_playMode(CMode::MODE_TYPE::TITLE);
int CResult::m_score(0);

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CResult::CResult()
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CResult::~CResult()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CResult::Init()
{
	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f));
		object->SetSize(D3DXVECTOR2(CApplication::CENTER_X * 2.0f, CApplication::CENTER_Y * 2.0f));
		object->SetTexture("GREEN_BG");
	}

	m_nextClickItem = new CClickItem;
	m_nextClickItem->Init();
	m_nextClickItem->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y + 200.0f, 0.0f));
	m_nextClickItem->SetSize(D3DXVECTOR2(300.0f, 100.0f));
	m_nextClickItem->SetColor(D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
	m_nextClickItem->SetEvent([this]()
	{
		m_nextClickItem->Uninit();

		m_retryClickItem = new CClickItem;
		m_retryClickItem->Init();
		m_retryClickItem->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y + 100.0f, 0.0f));
		m_retryClickItem->SetSize(D3DXVECTOR2(300.0f, 100.0f));
		m_retryClickItem->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
		m_retryClickItem->SetEvent([]()
		{
			CFade::GetInstance()->NextMode(m_playMode);
		});

		m_backClickItem = new CClickItem;
		m_backClickItem->Init();
		m_backClickItem->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y + 300.0f, 0.0f));
		m_backClickItem->SetSize(D3DXVECTOR2(300.0f, 100.0f));
		m_backClickItem->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
		m_backClickItem->SetEvent([]()
		{
			CFade::GetInstance()->NextMode(CMode::MODE_TYPE::SERECT_MODE);
		});
	});

	{
		CObject2D* object = CObject2D::Create();
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y - 175.0f, 0.0f));
		object->SetSize(D3DXVECTOR2(1920.0f * 0.25f, 357.0f * 0.25f));
		object->SetTexture("RESULT_SCORE");
	}

	D3DXVECTOR3 pos(CApplication::CENTER_X - 90.0f, CApplication::CENTER_Y, 0.0f);
	D3DXVECTOR2 size(90.0f, 280.0f);
	CSequence::Create(pos, size, 3)->SetNumber(m_score);

	return S_OK;
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CResult::Update()
{
}

//--------------------------------------------------
// 生成
//--------------------------------------------------
CResult* CResult::Create()
{
	CResult* pResult = new CResult;

	assert(pResult != nullptr);

	pResult->Init();

	return pResult;
}
