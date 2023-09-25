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
CTarget::CTarget()
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
	m_nNext = 0;
	return CClickItem::Init();
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
			SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));
		}
		else
		{
			SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
		}

		if (CMiniGameComeOut::GetClick())
		{
			if (IsClick())
			{
				if (m_nNext == m_nIndex)
				{
					m_nNext++;
					m_bClick = true;
					SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
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
