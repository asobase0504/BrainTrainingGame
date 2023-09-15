//==================================================
// remember_system.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "remember_system.h"

#include "application.h"
#include "utility.h"
#include "input.h"
#include "object2d.h"

#include "remember_object.h"

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
CRememberSystem::CRememberSystem(int nPriority) : CObject(nPriority),
m_nAnswer(0),
m_tex{
	"WINTER",
	"SUN_FLOWER",
	"MOUNTAIN",
	"GORYOKAKU",
	"GAME",
	"FLOWER_GARD",
	"DUCK",
	"DOG",
	"CLOUD",
	"CASTLE", }
{
	for (int i = 0; i < MAX_ANSWER; i++)
	{
		m_pAnswerObject[i] = nullptr;
	}

	m_pRememberObject = nullptr;
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
CRememberSystem::~CRememberSystem()
{
}

//--------------------------------------------------
// ������
//--------------------------------------------------
HRESULT CRememberSystem::Init()
{
#define ARRAY_LENGTH(a) (sizeof(a)/sizeof((a)[0])) 
	static_assert(ARRAY_LENGTH(m_tex) == TEXTURE_MAX, "baka");

	DisplayRemember_();

	// ����
	m_pAnswerObject[0] = CRememberObject::Create(
		D3DXVECTOR3((float)CApplication::SCREEN_WIDTH * 0.25f, 600.0f, 0.0f),
		D3DXVECTOR2(300.0f, 200.0f),
		0);
	m_pAnswerObject[0]->SetTexture(m_tex[0]);
	m_pAnswerObject[0]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	// �_�~�[
	m_pAnswerObject[1] = CRememberObject::Create(
		D3DXVECTOR3((float)CApplication::SCREEN_WIDTH * 0.75f, 600.0f, 0.0f),
		D3DXVECTOR2(300.0f, 200.0f),
		1);
	m_pAnswerObject[1]->SetTexture(m_tex[1]);
	m_pAnswerObject[1]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	return S_OK;
}

//--------------------------------------------------
// �I��
//--------------------------------------------------
void CRememberSystem::Uninit()
{
}

//--------------------------------------------------
// �X�V
//--------------------------------------------------
void CRememberSystem::Update()
{
	// �C���v�b�g
	CInput *input = CInput::GetKey();
	D3DXVECTOR3 mousePos = input->GetMouseCursor();

	Touch_(mousePos.x, mousePos.y);
}

//--------------------------------------------------
// �`��
//--------------------------------------------------
void CRememberSystem::Draw()
{
}

//--------------------------------------------------
// ����
//--------------------------------------------------
CRememberSystem *CRememberSystem::Create()
{
	CRememberSystem *pRememberSystem;
	pRememberSystem = new CRememberSystem;

	if (pRememberSystem != nullptr)
	{
		pRememberSystem->Init();
	}
	else
	{
		assert(false);
	}

	return pRememberSystem;
}

//--------------------------------------------------
// �^�b�`
//--------------------------------------------------
void CRememberSystem::Touch_(float nPosX, float nPosY)
{
	// �C���v�b�g
	CInput *input = CInput::GetKey();

	for (int nCntNumber = 0; nCntNumber < 2; nCntNumber++)
	{
		D3DXVECTOR3 pos = m_pAnswerObject[nCntNumber]->GetPos();
		D3DXVECTOR3 size = m_pAnswerObject[nCntNumber]->GetSize();

		int answerMyNumber = m_pAnswerObject[nCntNumber]->GetMyNumber();
		int rememberMyNumber = m_pRememberObject->GetMyNumber();

		//	�^�b�`���W���|���S���̒���������
		if (input->Trigger(MOUSE_INPUT_LEFT) &&
			pos.x + size.x >= nPosX &&
			pos.x - size.x <= nPosX &&
			pos.y - size.y <= nPosY &&
			pos.y + size.y >= nPosY &&
			answerMyNumber == rememberMyNumber)
		{
			// �|���S���̃J���[�ύX
			m_pAnswerObject[nCntNumber]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		}
	}
}

//--------------------------------------------------
// �I����
//--------------------------------------------------
void CRememberSystem::DisplayRemember_()
{
	m_nAnswer = IntRandom(TEXTURE_MAX - 1, 0);
	// �o������
	m_pRememberObject = CRememberObject::Create(
		D3DXVECTOR3((float)CApplication::SCREEN_WIDTH * 0.5f, 200.0f, 0.0f),
		D3DXVECTOR2(300.0f, 200.0f),
		m_nAnswer);
	m_pRememberObject->SetTexture(m_tex[m_nAnswer]);
	m_pRememberObject->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
}

//--------------------------------------------------
// �����̕\��
//--------------------------------------------------
void CRememberSystem::Choices_()
{
}
