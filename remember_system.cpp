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
#include "correction.h"

//**************************************************
// �萔
//**************************************************
const int CRememberSystem::X_LINE = 2;
const int CRememberSystem::Y_LINE = 2;
const int CRememberSystem::MAX_ANSWER = X_LINE * Y_LINE;

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
CRememberSystem::CRememberSystem(int nPriority) : CObject(nPriority),
m_nAnswer(0), m_nBeforeNumber(0),
m_tex{
	"WINTER",
	"SUN_FLOWER",
	"MOUNTAIN",
	"GORYOKAKU",
	"GAME",
	"FLOWER_GARDEN",
	"DUCK",
	"DOG",
	"CLOUD",
	"CASTLE", }
{
	m_pAnswerObject.clear();

	m_pRememberObject = nullptr;

	for (int i = 0; i < TEXTURE_MAX; i++)
	{
		m_isUsedNumber[i] = false;
	}
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

	// �z��T�C�Y�̐ݒ�
	m_pAnswerObject.resize(MAX_ANSWER);

	m_nAnswer = IntRandom(TEXTURE_MAX - 1, 0);
	m_changeLag = 0;
	m_isChange = false;

	// �o������ ��񂾂�����
	m_pRememberObject = CRememberObject::Create(
		D3DXVECTOR3((float)CApplication::SCREEN_WIDTH * 0.5f, 150.0f, 0.0f),
		D3DXVECTOR2(300.0f, 200.0f), m_nAnswer);
	m_pRememberObject->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	m_pRememberObject->SetTexture(m_tex[m_nAnswer]);
	m_pRememberObject->SetEvent([]() {});

	CClickItem* initCluck = CClickItem::Create(D3DXVECTOR3(CApplication::CENTER_X, 400.0f, 0.0f), D3DXVECTOR2(500.0f, 250.0f));
	initCluck->SetEvent([this, initCluck]()
	{
		m_isChange = true;
		initCluck->Uninit();

		for (int nCntY = 0; nCntY < Y_LINE; nCntY++)
		{
			for (int nCntX = 0; nCntX < X_LINE; nCntX++)
			{
				int nCntNumber = nCntY * Y_LINE + nCntX;

				// ����
				m_pAnswerObject[nCntNumber] = CRememberObject::Create(
					D3DXVECTOR3(400.0f + 450.0f * nCntX, 370.0f + 250.0f * nCntY, 0.0f),
					D3DXVECTOR2(300.0f, 200.0f), nCntNumber);
				m_pAnswerObject[nCntNumber]->SetTexture(m_tex[nCntNumber]);
				m_pAnswerObject[nCntNumber]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
				m_pAnswerObject[nCntNumber]->SetEvent([this, nCntNumber]()
				{
					if (m_isChange)
					{
						return;
					}
					m_isChange = true;

					int answerMyNumber = m_pAnswerObject[nCntNumber]->GetMyNumber();
					if (answerMyNumber == m_nBeforeNumber)
					{
						CCorrection::Create(true);
					}
					else
					{
						CCorrection::Create(false);
					}
				});
			}
		}
	});

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
	if (m_isChange)
	{
		m_changeLag++;
		if (m_changeLag >= 25)
		{
			DisplayRemember_();
			Choices_();

			for (int i = 0; i < TEXTURE_MAX; i++)
			{
				m_isUsedNumber[i] = false;
			}

			for (int i = 0; i < MAX_ANSWER; i++)
			{
				// �|���S���̃J���[�ύX
				m_pAnswerObject[i]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			}
			m_isChange = false;
			m_changeLag = 0;
		}
	}
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
// �����̕\��
//--------------------------------------------------
void CRememberSystem::DisplayRemember_()
{
	m_nBeforeNumber = m_pRememberObject->GetMyNumber();

	m_nAnswer = IntRandom(TEXTURE_MAX - 1, 0);

	m_pRememberObject->SetMyNumber(m_nAnswer);
	m_pRememberObject->SetTexture(m_tex[m_nAnswer]);
}

//--------------------------------------------------
// �I����
//--------------------------------------------------
void CRememberSystem::Choices_()
{
	// ����������ɂ���
	int answer = 0;
	answer = IntRandom(MAX_ANSWER - 1, 0);

	m_isUsedNumber[m_nBeforeNumber] = true;

	// ���I
	int number = 0;
	number = IntRandom(TEXTURE_MAX - 1, 0);

	for (int i = 0; i < MAX_ANSWER; i++)
	{
		if (answer == i)
		{// �����ƈꏏ�ɂ���
			m_pAnswerObject[i]->SetMyNumber(m_nBeforeNumber);
			m_pAnswerObject[i]->SetTexture(m_tex[m_nBeforeNumber]);
		}
		else
		{// ����ȊO�i�_�~�[�j
			while (m_isUsedNumber[number])
			{// �摜�̒��I
				number = IntRandom(TEXTURE_MAX - 1, 0);
			}

			m_pAnswerObject[i]->SetMyNumber(number);
			m_pAnswerObject[i]->SetTexture(m_tex[number]);

			m_isUsedNumber[number] = true;
		}
	}
}
