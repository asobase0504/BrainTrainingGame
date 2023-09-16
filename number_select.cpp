//==================================================
// 
// Author: YudaKaito
//==================================================

//**************************************************
// include
//**************************************************
#include "number_select.h"
#include "application.h"
#include "click_item.h"
#include "fade.h"
#include "sequence.h"

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CNumberSelect::CNumberSelect() : CObject2D(CTaskGroup::LEVEL_2D_UI)
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CNumberSelect::~CNumberSelect()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CNumberSelect::Init()
{
	m_number = 0;
	m_isReturn = false;
	CObject2D::Init();

	SetSize(D3DXVECTOR2(CApplication::CENTER_X, (float)CApplication::SCREEN_HEIGHT));
	SetPos(D3DXVECTOR3(CApplication::CENTER_X + CApplication::CENTER_X * 0.5f, CApplication::CENTER_Y, 0.0f));

	for (int i = 1; i < 10; i++)
	{
		int cnt = i -1;
		m_numberClickItem[i] = new CClickItem;
		m_numberClickItem[i]->Init();
		m_numberClickItem[i]->SetPos(D3DXVECTOR3(CApplication::CENTER_X + CApplication::CENTER_X * 0.5f + ((cnt % 3) * 110.0f - 110.0f), CApplication::CENTER_Y + 200.0f - ((cnt / 3) * 110.0f + 110.0f), 0.0f));
		m_numberClickItem[i]->SetSize(D3DXVECTOR2(100.0f, 100.0f));
		m_numberClickItem[i]->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
		m_numberClickItem[i]->SetEvent([this,i]()
		{
			if (m_isReturn)
			{
				return;
			}
			if (m_number * 0.01f > 1)
			{
				return;
			}

			m_number *= 10;
			m_number += i;
		});
	}

	{
		D3DXVECTOR3 pos = m_numberClickItem[2]->GetPos();
		pos.y += 110.0f;
		//pos.x -= 110.0f;
		m_numberClickItem[0] = new CClickItem;
		m_numberClickItem[0]->Init();
		m_numberClickItem[0]->SetPos(pos);
		m_numberClickItem[0]->SetSize(D3DXVECTOR2(100.0f, 100.0f));
		m_numberClickItem[0]->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
		m_numberClickItem[0]->SetEvent([this]()
		{
			if (m_isReturn)
			{
				return;
			}
			if (m_number * 0.01f > 1)
			{
				return;
			}

			m_number *= 10;
		});
	}

	{
		D3DXVECTOR3 pos = m_numberClickItem[3]->GetPos();
		pos.y += 110.0f;
		m_backClickItem = new CClickItem;
		m_backClickItem->Init();
		m_backClickItem->SetPos(pos);
		m_backClickItem->SetSize(D3DXVECTOR2(100.0f, 100.0f));
		m_backClickItem->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
		m_backClickItem->SetEvent([this]()
		{
			if (m_isReturn)
			{
				return;
			}
			m_number /= 10;
		});
	}

	{
		D3DXVECTOR3 pos = m_numberClickItem[0]->GetPos();
		pos.y += 110.0f;
		m_returnClickItem = new CClickItem;
		m_returnClickItem->Init();
		m_returnClickItem->SetPos(pos);
		m_returnClickItem->SetSize(D3DXVECTOR2(320.0f, 80.0f));
		m_returnClickItem->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
		m_returnClickItem->SetEvent([this]()
		{
			if (m_isReturn)
			{
				return;
			}
			m_isReturn = true;
		});
	}

	m_sequence = CSequence::Create(D3DXVECTOR3(CApplication::CENTER_X + CApplication::CENTER_X * 0.5f - 80.0f, 100.0f, 0.0f), D3DXVECTOR2(80.0f, 80.0f));
	m_sequence->SetNumber(0);

	return S_OK;
}

//--------------------------------------------------
// 終了
//--------------------------------------------------
void CNumberSelect::Uninit()
{
	for (int i = 0; i < 10; i++)
	{
		m_numberClickItem[i]->Uninit();
	}
	m_returnClickItem->Uninit();
	m_backClickItem->Uninit();
	m_sequence->Uninit();

	CObject2D::Uninit();
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CNumberSelect::Update()
{
	CDebugProc::Print("number : %d\n", m_number);
	m_sequence->SetNumber(m_number);
}

//--------------------------------------------------
// 生成
//--------------------------------------------------
CNumberSelect* CNumberSelect::Create()
{
	CNumberSelect* pResult = new CNumberSelect;

	assert(pResult != nullptr);

	pResult->Init();

	return pResult;
}

//--------------------------------------------------
// 番号の取得
//--------------------------------------------------
int CNumberSelect::GetNumber()
{
	return m_number;
}
