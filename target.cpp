//==========================================
//
//  �������(target.cpp)
//  Author : Tomoya Kanazaki
//
//==========================================
#include "target.h"
#include "debug_proc.h"
#include "minigame_comeout.h"

//==========================================
//  �ÓI�����o�ϐ��錾
//==========================================
int CTarget::m_nTime = 0;
int CTarget::m_nNext = 0;

//==========================================
//  �R���X�g���N�^
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
//  �f�X�g���N�^
//==========================================
CTarget::~CTarget()
{

}

//==========================================
//  ����������
//==========================================
HRESULT CTarget::Init()
{
#define ARRAY_LENGTH(a) (sizeof(a)/sizeof((a)[0])) 
	static_assert(ARRAY_LENGTH(m_tex) == TEXTURE_MAX, "baka");
	SetTexture(m_tex[rand() % TEXTURE_MAX]);
	m_nNext = 0;
	HRESULT hResult = CClickItem::Init();

	m_BG = CObject2D::Create(CTaskGroup::LEVEL_2D_2);
	m_BG->SetPos(m_pos);
	m_BG->SetSize(m_size * 1.5f);
	m_BG->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	m_BG->SetTexture("DECO_TAG");
	
	SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));

	return hResult;
}

//==========================================
//  �I������
//==========================================
void CTarget::Uninit()
{
	CClickItem::Uninit();
}

//==========================================
//  �X�V����
//==========================================
void CTarget::Update()
{
	if (!m_bClick)
	{
		if (m_nTime < m_nTiming)
		{
			SetColorAlpha(0.0f);
		}
		else
		{
			SetColorAlpha(1.0f);
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

	CDebugProc::Print("�C���f�b�N�X : %d\n", m_nIndex);
	CDebugProc::Print("m_bClick : %d\n", m_bClick);

	CClickItem::Update();
}

//==========================================
//  �`�揈��
//==========================================
void CTarget::Draw()
{
	CClickItem::Draw();
}

//==========================================
//  ���Z�b�g���̏I��
//==========================================
void CTarget::UninitReset()
{
	Uninit();

	if (m_BG != nullptr)
	{
		m_BG->Uninit();
		m_BG = nullptr;
	}
}

//==========================================
//  �ʒu�ݒ�
//==========================================
void CTarget::SetPos(const D3DXVECTOR3 & inPos)
{
	CClickItem::SetPos(inPos);
	m_BG->SetPos(inPos);
}

//==========================================
//  �傫���ݒ�
//==========================================
void CTarget::SetSize(const D3DXVECTOR2 & inSize)
{
	CClickItem::SetSize(inSize);
	m_BG->SetSize(inSize * 1.5f);
}

//==========================================
//  ���l�ݒ�
//==========================================
void CTarget::SetColorAlpha(const float inAlpha)
{
	CClickItem::SetColorAlpha(inAlpha);
	m_BG->SetColorAlpha(inAlpha);
}
