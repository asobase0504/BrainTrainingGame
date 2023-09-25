//==================================================
// same_as_shadow_system.cpp
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
#include "game.h"

#include "correction.h"

//**************************************************
// 定数
//**************************************************
const int CSameAsShadowSystem::MAX_SHADOW = 4;
const int CSameAsShadowSystem::MAX_CHOICES = 6;
const int CSameAsShadowSystem::MAX_ANSWER = 4;

//--------------------------------------------------
// コンストラクタ
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
// デストラクタ
//--------------------------------------------------
CSameAsShadowSystem::~CSameAsShadowSystem()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CSameAsShadowSystem::Init()
{
#define ARRAY_LENGTH(a) (sizeof(a)/sizeof((a)[0])) 
	static_assert(ARRAY_LENGTH(m_tex) == TEXTURE_MAX, "baka");

	m_pShadowObject.resize(MAX_SHADOW);
	m_pSelectObject.resize(MAX_CHOICES);
	m_nAnswerNumber.resize(MAX_SHADOW);
	m_isAnswerNumber.resize(MAX_CHOICES);

	{// シルエット
		for (int i = 0; i < MAX_SHADOW; i++)
		{
			m_pShadowObject[i] = CReflectionObject::Create(
				D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f),
				D3DXVECTOR2(100.0f, 100.0f), 0);
			m_pShadowObject[i]->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
			m_pShadowObject[i]->SetMove(D3DXVECTOR3(FloatRandom(12.0f, -12.0f), FloatRandom(12.0f, -12.0f), 0.0f));
			m_pShadowObject[i]->SetEvent([]() {});
		}
	}

	InitCreateAnswer_();
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

	for (int i = 0; i < m_pShadowObject.size(); i++)
	{
		m_pShadowObject[i]->Reset();
	}

	return S_OK;
}

//--------------------------------------------------
// 終了
//--------------------------------------------------
void CSameAsShadowSystem::Uninit()
{
}

//--------------------------------------------------
// 更新
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

			for (int i = 0; i < m_pShadowObject.size(); i++)
			{
				m_pShadowObject[i]->Reset();
			}

			for (int i = 0; i < MAX_CHOICES; i++)
			{
				// ポリゴンのカラー変更
				m_pSelectObject[i]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			}
			m_isChange = false;
			m_changeLag = 0;
			m_nCountAnswer = 0;
		}
	}
}

//--------------------------------------------------
// 描画
//--------------------------------------------------
void CSameAsShadowSystem::Draw()
{
}

//--------------------------------------------------
// 生成
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
// 回答欄の生成
//--------------------------------------------------
void CSameAsShadowSystem::InitCreateAnswer_()
{
	for (int i = 0; i < MAX_CHOICES; i++)
	{// 選択肢

		D3DXVECTOR3 pos;
		pos.x = CApplication::CENTER_X - ((float)MAX_CHOICES * 0.5f * 0.5f) * 120.0f + (i % (int)(MAX_CHOICES * 0.5f)) * 120.0f + 50.0f;
		pos.y = CApplication::SCREEN_HEIGHT - 200.0f + (int)(i / (MAX_CHOICES * 0.5f)) * 100.0f;
		pos.z = 0.0f;
		D3DXVECTOR2 size(80.0f, 80.0f);

		{
			CObject2D* object = CObject2D::Create();
			object->SetPos(pos);
			object->SetSize(size * 1.2f);
			object->SetTexture("DECO_TAG");
		}

		m_pSelectObject[i] = CRememberObject::Create(pos, size, 0);
		m_pSelectObject[i]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		m_pSelectObject[i]->SetEvent([this, i]()
		{
			bool isClickColor = m_pSelectObject[i]->GetColor().r < 1.0f;

			if (isClickColor || m_isChange)
			{
				return;
			}

			m_nCountAnswer++;

			int answerMyNumber = m_pSelectObject[i]->GetMyNumber();
			bool isAnswer = false;

			for (int j = 0; j < MAX_SHADOW; j++)
			{// 正誤判定
				int shadowNumber = m_pShadowObject[j]->GetMyNumber();

				if (answerMyNumber == shadowNumber)
				{
					isAnswer = true;
				}
			}

			CCorrection::Create(isAnswer);

			m_pSelectObject[i]->SetColor(D3DXCOLOR(0.45f, 0.45f, 0.45f,1.0f));

			m_game->AddScore(isAnswer ? 4 : -7);

			if (!isAnswer || m_nCountAnswer == MAX_ANSWER)
			{
				m_isChange = true;
			}
		});
	}
}

//--------------------------------------------------
// 影のオブジェクト
//--------------------------------------------------
void CSameAsShadowSystem::Shadow_()
{
	// 抽選
	int number = 0;
	number = IntRandom(TEXTURE_MAX - 1, 0);

	for (int i = 0; i < MAX_SHADOW; i++)
	{
		while (m_isUsedNumber[number])
		{// 画像の抽選
			number = IntRandom(TEXTURE_MAX - 1, 0);
		}

		m_pShadowObject[i]->SetMyNumber(number);
		m_pShadowObject[i]->SetTexture(m_tex[number]);
		m_pShadowObject[i]->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f));
		m_pShadowObject[i]->SetMove(D3DXVECTOR3(FloatRandom(15.0f,-15.0f), FloatRandom(15.0f, -15.0f),0.0f));
		m_nAnswerNumber[i] = number;

		m_isUsedNumber[number] = true;
	}
}

//--------------------------------------------------
// 選択肢
//--------------------------------------------------
void CSameAsShadowSystem::Choices_()
{
	// 3つをこたえにする
	int answer[MAX_SHADOW] = { 0,0,0 };
	int answerNumber = 0;

	// 一番最初をランダムにする
	answerNumber = IntRandom(MAX_CHOICES - 1, 0);

	for (int j = 0; j < MAX_SHADOW; j++)
	{
		while (m_isAnswerNumber[answerNumber])
		{// 五つのうちどの三つをこたえにするか
			answerNumber = IntRandom(MAX_CHOICES - 1, 0);
		}
		answer[j] = answerNumber;
		// 選択肢に選ばれた奴を使用済みにする
		m_isAnswerNumber[answerNumber] = true;
	}

	// 抽選
	int number = 0;
	number = IntRandom(TEXTURE_MAX - 1, 0);

	int j = 0;

	for (int i = 0; i < MAX_CHOICES; i++)
	{
		bool isAnswer = false;

		for (j = 0; j < MAX_SHADOW; j++)
		{
			if (answer[j] == i)
			{// 答えと一緒にする
				m_pSelectObject[i]->SetMyNumber(m_nAnswerNumber[j]);
				m_pSelectObject[i]->SetTexture(m_tex[m_nAnswerNumber[j]]);
				m_isUsedNumber[m_nAnswerNumber[j]] = true;
				isAnswer = true;
			}
		}

		if(!isAnswer)
		{// それ以外（ダミー）
			while (m_isUsedNumber[number])
			{// 画像の抽選
				number = IntRandom(TEXTURE_MAX - 1, 0);
			}

			m_pSelectObject[i]->SetMyNumber(number);
			m_pSelectObject[i]->SetTexture(m_tex[number]);

			m_isUsedNumber[number] = true;
		}
	}
}
