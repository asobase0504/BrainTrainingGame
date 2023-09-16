//=============================================================================
// 
// アプリケーションクラス
// Author YudaKaito
// 
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "select_save.h"
#include <assert.h>

#include "application.h"
#include "save_guidance_item.h"
#include "utility.h"

//-----------------------------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------------------------
CSelectSave::CSelectSave() :
	m_isSelectSaveData(false)
{
}

//-----------------------------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------------------------
CSelectSave::~CSelectSave()
{
}

//-----------------------------------------------------------------------------
// 初期化
//-----------------------------------------------------------------------------
HRESULT CSelectSave::Init()
{
	{
		CObject2D* object = CObject2D::Create();
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f));
		object->SetSize(D3DXVECTOR2(CApplication::CENTER_X * 2.0f, CApplication::CENTER_Y * 2.0f));
		object->SetTexture("GREEN_BG");
	}

	m_itemSaveGuidance.resize(15);

	float xPos = 100.0f;

	for (int i = 0; i < 15; i++)
	{
		m_itemSaveGuidance[i] = CSaveGuidanceItem::Create(D3DXVECTOR3(xPos + (147.0f * 0.5f * i), CApplication::CENTER_Y, 0.0f), "aaaaa");

		//Debug用
		m_itemSaveGuidance[i]->SetColor(D3DXCOLOR(FloatRandom(1.0f, 0.0f), FloatRandom(1.0f, 0.0f), FloatRandom(1.0f, 0.0f), 1.0f));
	}

	return S_OK;
}

//-----------------------------------------------------------------------------
// 終了
//-----------------------------------------------------------------------------
void CSelectSave::Uninit()
{
}

//-----------------------------------------------------------------------------
// 更新
//-----------------------------------------------------------------------------
void CSelectSave::Update()
{
	if (!m_isSelectSaveData)
	{
		for (int i = 0; i < 15; i++)
		{
			if (m_itemSaveGuidance[i]->IsSelect())
			{
				m_isSelectSaveData = true;
			}
		}
	}
}
