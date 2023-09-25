//==========================================
//
//  押すやつ(target.cpp)
//  Author : Tomoya Kanazaki
//
//==========================================
#include "target.h"
#include "debug_proc.h"
#include "minigame_comeout.h"

//==========================================
//  静的メンバ変数宣言
//==========================================
int CTarget::m_nTime = 0;
int CTarget::m_nNext = 0;

//==========================================
//  コンストラクタ
//==========================================
CTarget::CTarget() : m_tex{
	"ANIMAL1", "ANIMAL2", "ANIMAL3", "ANIMAL4", "ANIMAL5", "ANIMAL6", "ANIMAL7", "ANIMAL8", "ANIMAL9", "ANIMAL10",
	"ANIMAL11", "ANIMAL12", "ANIMAL13", "ANIMAL14", "ANIMAL15", "ANIMAL16", "ANIMAL17", "ANIMAL18", "ANIMAL19", "ANIMAL20",
	"ANIMAL21", "ANIMAL22", "ANIMAL23", "ANIMAL24", "ANIMAL25", "ANIMAL26", "ANIMAL27",
}
{
	m_bClick = false;
	m_bMiss = false;
}

//==========================================
//  デストラクタ
//==========================================
CTarget::~CTarget()
{

}

//==========================================
//  初期化処理
//==========================================
HRESULT CTarget::Init()
{
#define ARRAY_LENGTH(a) (sizeof(a)/sizeof((a)[0])) 
	static_assert(ARRAY_LENGTH(m_tex) == TEXTURE_MAX, "baka");
	SetTexture(m_tex[rand() % TEXTURE_MAX]);
	m_nNext = 0;
	HRESULT hResult = CClickItem::Init();
	SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	return hResult;
}

//==========================================
//  終了処理
//==========================================
void CTarget::Uninit()
{
	CClickItem::Uninit();
}

//==========================================
//  更新処理
//==========================================
void CTarget::Update()
{
	if (!m_bClick)
	{
		if (m_nTime < m_nTiming)
		{
			SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		}
		else
		{
			SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		}

		if (CMiniGameComeOut::GetClick())
		{
			if (IsClick())
			{
				if (m_nNext == m_nIndex)
				{
					m_nNext++;
					m_bClick = true;
					SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
				}
				else
				{
					m_bMiss = true;
				}
			}
		}
	}

	CDebugProc::Print("インデックス : %d\n", m_nIndex);
	CDebugProc::Print("m_bClick : %d\n", m_bClick);

	CClickItem::Update();
}

//==========================================
//  描画処理
//==========================================
void CTarget::Draw()
{
	CClickItem::Draw();
}
