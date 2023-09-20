//==================================================
// remember_system.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "same_as_shadow_system.h"

#include "application.h"
#include "input.h"
#include "reflection_object.h"
#include "utility.h"

#include "correction.h"

//**************************************************
// �萔
//**************************************************
const int CSameAsShadowSystem::MAX_SHADOW = 3;
const int CSameAsShadowSystem::MAX_CHOICES = 5;
const int CSameAsShadowSystem::MAX_ANSWER = 3;

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
CSameAsShadowSystem::CSameAsShadowSystem(int nPriority) : CObject(nPriority), m_isChange(false),
m_changeLag(0), m_nCountAnswer(0),
m_tex{
	"ANIMAL1", "ANIMAL2", "ANIMAL3", "ANIMAL4", "ANIMAL5", "ANIMAL6", "ANIMAL7", "ANIMAL8", "ANIMAL9", "ANIMAL10",
	"ANIMAL11", "ANIMAL12", "ANIMAL13", "ANIMAL14", "ANIMAL15", "ANIMAL16", "ANIMAL17", "ANIMAL18", "ANIMAL19", "ANIMAL20",
	"ANIMAL21", "ANIMAL22", "ANIMAL23", "ANIMAL24", "ANIMAL25", "ANIMAL26", "ANIMAL27",
}
{
	m_pShadowObject.clear();
	m_pSelectObject.clear();
	m_nAnswerNumber.clear();
	m_isAnswerNumber.clear();

	for (int i = 0; i < TEXTURE_MAX; i++)
	{
		m_isUsedNumber[i] = false;
	}
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
CSameAsShadowSystem::~CSameAsShadowSystem()
{
}

//--------------------------------------------------
// ������
//--------------------------------------------------
HRESULT CSameAsShadowSystem::Init()
{
#define ARRAY_LENGTH(a) (sizeof(a)/sizeof((a)[0])) 
	static_assert(ARRAY_LENGTH(m_tex) == TEXTURE_MAX, "baka");

	m_pShadowObject.resize(MAX_SHADOW);
	m_pSelectObject.resize(MAX_CHOICES);
	m_nAnswerNumber.resize(MAX_SHADOW);
	m_isAnswerNumber.resize(MAX_CHOICES);

	D3DXVECTOR3 move(10.0f, 10.0f, 0.0f);

	{// �V���G�b�g
		for (int i = 0; i < MAX_SHADOW; i++)
		{
			m_pShadowObject[i] = CReflectionObject::Create(
				D3DXVECTOR3(CApplication::SCREEN_WIDTH * 0.5f + 100.0f * i, CApplication::SCREEN_HEIGHT * 0.5f, 0.0f),
				D3DXVECTOR2(100.0f, 100.0f), 0);
			m_pShadowObject[i]->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
			m_pShadowObject[i]->SetMove(move);
			m_pShadowObject[i]->SetEvent([]() {});
		}
	}

	CClickItem* initCluck = CClickItem::Create(D3DXVECTOR3(CApplication::CENTER_X, 400.0f, 0.0f), D3DXVECTOR2(500.0f, 250.0f));
	initCluck->SetEvent([this, initCluck]()
	{
		m_isChange = true;
		initCluck->Uninit();
		InitCreateAnswer_();
	});

	return S_OK;
}

//--------------------------------------------------
// �I��
//--------------------------------------------------
void CSameAsShadowSystem::Uninit()
{
}

//--------------------------------------------------
// �X�V
//--------------------------------------------------
void CSameAsShadowSystem::Update()
{
	if (m_isChange)
	{
		m_changeLag++;
		if (m_changeLag >= 25)
		{
			Shadow_();
			Choices_();

			for (int i = 0; i < TEXTURE_MAX; i++)
			{
				m_isUsedNumber[i] = false;
			}

			for (int i = 0; i < m_isAnswerNumber.size(); i++)
			{
				m_isAnswerNumber[i] = false;
			}

			for (int i = 0; i < MAX_CHOICES; i++)
			{
				// �|���S���̃J���[�ύX
				m_pSelectObject[i]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			}
			m_isChange = false;
			m_changeLag = 0;
			m_nCountAnswer = 0;
		}
	}
}

//--------------------------------------------------
// �`��
//--------------------------------------------------
void CSameAsShadowSystem::Draw()
{
}

//--------------------------------------------------
// ����
//--------------------------------------------------
CSameAsShadowSystem *CSameAsShadowSystem::Create()
{
	CSameAsShadowSystem *pSameAsShadowSystem;
	pSameAsShadowSystem = new CSameAsShadowSystem;

	if (pSameAsShadowSystem != nullptr)
	{
		pSameAsShadowSystem->Init();
	}
	else
	{
		assert(false);
	}

	return pSameAsShadowSystem;
}

//--------------------------------------------------
// �񓚗��̐���
//--------------------------------------------------
void CSameAsShadowSystem::InitCreateAnswer_()
{
	for (int i = 0; i < MAX_CHOICES; i++)
	{// �I����
		m_pSelectObject[i] = CRememberObject::Create(
			D3DXVECTOR3(CApplication::SCREEN_WIDTH * 0.25f + 100.0f * i, CApplication::SCREEN_HEIGHT - 100.0f, 0.0f),
			D3DXVECTOR2(100.0f, 100.0f), 0);
		m_pSelectObject[i]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		m_pSelectObject[i]->SetEvent([this, i]()
		{
			m_nCountAnswer++;
			if (m_isChange)
			{
				return;
			}

			int answerMyNumber = m_pSelectObject[i]->GetMyNumber();

			for (int j = 0; j < MAX_SHADOW; j++)
			{// ���딻��
				int shadowNumber = m_pShadowObject[j]->GetMyNumber();

				if (answerMyNumber == shadowNumber)
				{
					CCorrection::Create(true);
				}
				else
				{
					CCorrection::Create(false);
				}
			}

			if (m_nCountAnswer == MAX_ANSWER)
			{// �񓚐�������ɒB������
				m_isChange = true;
			}
		});
	}
}

//--------------------------------------------------
// �e�̃I�u�W�F�N�g
//--------------------------------------------------
void CSameAsShadowSystem::Shadow_()
{
	// ���I
	int number = 0;
	number = IntRandom(TEXTURE_MAX - 1, 0);

	for (int i = 0; i < MAX_SHADOW; i++)
	{
		while (m_isUsedNumber[number])
		{// �摜�̒��I
			number = IntRandom(TEXTURE_MAX - 1, 0);
		}

		m_pShadowObject[i]->SetMyNumber(number);
		m_pShadowObject[i]->SetTexture(m_tex[number]);
		m_nAnswerNumber[i] = number;

		m_isUsedNumber[number] = true;
	}
}

//--------------------------------------------------
// �I����
//--------------------------------------------------
void CSameAsShadowSystem::Choices_()
{
	// 3���������ɂ���
	int answer[MAX_SHADOW] = { 0,0,0 };
	int answerNumber = 0;

	// ��ԍŏ��������_���ɂ���
	answerNumber = IntRandom(MAX_CHOICES - 1, 0);

	for (int j = 0; j < MAX_SHADOW; j++)
	{
		while (m_isAnswerNumber[answerNumber])
		{// �܂̂����ǂ̎O���������ɂ��邩
			answerNumber = IntRandom(MAX_CHOICES - 1, 0);
		}
		answer[j] = answerNumber;
		// �I�����ɑI�΂ꂽ�z���g�p�ς݂ɂ���
		m_isAnswerNumber[answerNumber] = true;
	}

	// ���I
	int number = 0;
	number = IntRandom(TEXTURE_MAX - 1, 0);

	int j = 0;

	for (int i = 0; i < MAX_CHOICES; i++)
	{
		bool isAnswer = false;

		for (j = 0; j < MAX_SHADOW; j++)
		{
			if (answer[j] == i)
			{// �����ƈꏏ�ɂ���
				m_pSelectObject[i]->SetMyNumber(m_nAnswerNumber[j]);
				m_pSelectObject[i]->SetTexture(m_tex[m_nAnswerNumber[j]]);
				m_isUsedNumber[m_nAnswerNumber[j]] = true;
				isAnswer = true;
			}
		}

		if(!isAnswer)
		{// ����ȊO�i�_�~�[�j
			while (m_isUsedNumber[number])
			{// �摜�̒��I
				number = IntRandom(TEXTURE_MAX - 1, 0);
			}

			m_pSelectObject[i]->SetMyNumber(number);
			m_pSelectObject[i]->SetTexture(m_tex[number]);

			m_isUsedNumber[number] = true;
		}
	}
}
