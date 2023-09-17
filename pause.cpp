#include "pause.h"
#include "application.h"
#include "click_item.h"
#include "fade.h"

//-----------------------------------------
// コンストラクタ
//-----------------------------------------
CPause::CPause() : CObject2D(CTaskGroup::EPriority::LEVEL_PAUSE)
{
}

//-----------------------------------------
// デストラクタ
//-----------------------------------------
CPause::~CPause()
{
}

//-----------------------------------------
// 初期化
//-----------------------------------------
HRESULT CPause::Init()
{
	CTaskGroup::GetInstance()->Pause(true);

	{
		CObject2D::Init();
		SetSize(CApplication::GetInstance()->GetScreenSize());
		D3DXVECTOR3 pos(CApplication::GetInstance()->CENTER_X, CApplication::GetInstance()->CENTER_Y, 0.0f);	// 位置の取得
		SetTexture("BG");
		SetPos(pos);
		SetColorAlpha(0.85f);
	}
	{
		D3DXVECTOR3 pos(CApplication::CENTER_X + CApplication::CENTER_X * 0.5f, CApplication::CENTER_Y, 0.0f);
		D3DXVECTOR2 size(D3DXVECTOR2(300.0f, 100.0f));
		m_back = CClickItem::Create(pos, size, CTaskGroup::EPriority::LEVEL_PAUSE);
		m_back->PauseOff();
		m_back->SetEvent([this]() {Uninit(); });
		pos.y += 110.0f;
		m_retry = CClickItem::Create(pos, size, CTaskGroup::EPriority::LEVEL_PAUSE);
		m_retry->PauseOff();
		m_retry->SetEvent([this]() { CFade::GetInstance()->NextMode(CApplication::GetInstance()->GetModeType()); });
		pos.y += 110.0f;
		m_end = CClickItem::Create(pos, size, CTaskGroup::EPriority::LEVEL_PAUSE);
		m_end->PauseOff();
		m_end->SetEvent([this]() { CFade::GetInstance()->NextMode(CMode::MODE_TYPE::SERECT_MODE); });
	}
	return S_OK;
}

//-----------------------------------------
// 終了
//-----------------------------------------
void CPause::Uninit()
{
	m_back->Uninit();
	m_retry->Uninit();
	m_end->Uninit();

	CTaskGroup::GetInstance()->Pause(false);
	CObject2D::Uninit();
}

CPause* CPause::Create()
{
	CPause* pause = new CPause;

	assert(pause != nullptr);

	pause->Init();

	return pause;
}
