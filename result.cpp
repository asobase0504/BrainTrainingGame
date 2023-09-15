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

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CResult::CResult() : CObject2D(CTaskGroup::LEVEL_2D_UI)
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
	CObject2D::Init();

	SetSize(D3DXVECTOR2(CApplication::CENTER_X, (float)CApplication::SCREEN_HEIGHT));
	SetPos(D3DXVECTOR3(CApplication::CENTER_X + CApplication::CENTER_X * 0.5f, CApplication::CENTER_Y, 0.0f));

	m_nextClickItem = new CClickItem;
	m_nextClickItem->Init();
	m_nextClickItem->SetPos(D3DXVECTOR3(CApplication::CENTER_X + CApplication::CENTER_X * 0.5f, CApplication::CENTER_Y + 200.0f, 0.0f));
	m_nextClickItem->SetSize(D3DXVECTOR2(300.0f, 100.0f));
	m_nextClickItem->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
	m_nextClickItem->SetEvent([this]()
	{
		m_nextClickItem->Uninit();

		m_retryClickItem = new CClickItem;
		m_retryClickItem->Init();
		m_retryClickItem->SetPos(D3DXVECTOR3(CApplication::CENTER_X + CApplication::CENTER_X * 0.5f, CApplication::CENTER_Y + 100.0f, 0.0f));
		m_retryClickItem->SetSize(D3DXVECTOR2(300.0f, 100.0f));
		m_retryClickItem->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
		m_retryClickItem->SetEvent([]()
		{
			CFade::GetInstance()->NextMode(CApplication::GetInstance()->GetModeType());
		});

		m_backClickItem = new CClickItem;
		m_backClickItem->Init();
		m_backClickItem->SetPos(D3DXVECTOR3(CApplication::CENTER_X + CApplication::CENTER_X * 0.5f, CApplication::CENTER_Y + 300.0f, 0.0f));
		m_backClickItem->SetSize(D3DXVECTOR2(300.0f, 100.0f));
		m_backClickItem->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
		m_backClickItem->SetEvent([]()
		{
			CFade::GetInstance()->NextMode(CMode::MODE_TYPE::SERECT_MODE);
		});
	});

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
