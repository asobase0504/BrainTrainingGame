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

#include "game.h"

//**************************************************
// 定数
//**************************************************
const int CRememberSystem::X_LINE = 2;
const int CRememberSystem::Y_LINE = 2;
const int CRememberSystem::MAX_ANSWER = X_LINE * Y_LINE;

//--------------------------------------------------
// コンストラクタ
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
// デストラクタ
//--------------------------------------------------
CRememberSystem::~CRememberSystem()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CRememberSystem::Init()
{
#define ARRAY_LENGTH(a) (sizeof(a)/sizeof((a)[0])) 
	static_assert(ARRAY_LENGTH(m_tex) == TEXTURE_MAX, "baka");

	// 配列サイズの設定
	m_pAnswerObject.resize(MAX_ANSWER);

	m_nAnswer = IntRandom(TEXTURE_MAX - 1, 0);
	m_changeLag = 0;
	m_isChange = false;

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_UI_2);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X + 20.0f , 130.0f, 0.0f));
		object->SetSize(D3DXVECTOR2(50.0f * 0.5f, 63.0f * 0.5f));
		object->SetTexture("DECO_PIN");
	}

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_UI);
		object->SetPos(D3DXVECTOR3((float)CApplication::SCREEN_WIDTH * 0.5f, 230.0f, 0.0f));
		object->SetSize(D3DXVECTOR2(320.0f, 220.0f));
		object->SetColor(D3DXCOLOR(0.16f,0.24f,0.22f,1.0f));
	}

	// 覚えるやつ 一回だけつくる
	m_pRememberObject = CRememberObject::Create(
		D3DXVECTOR3((float)CApplication::SCREEN_WIDTH * 0.5f, 230.0f, 0.0f),
		D3DXVECTOR2(300.0f, 200.0f), m_nAnswer);
	m_pRememberObject->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	m_pRememberObject->SetTexture(m_tex[m_nAnswer]);
	m_pRememberObject->SetEvent([]() {});

	CClickItem* initClick = CClickItem::Create(D3DXVECTOR3(CApplication::CENTER_X, 500.0f, 0.0f), D3DXVECTOR2(652.0f * 0.5f, 219.0f * 0.5f));
	initClick->SetTexture("TEXT_CHACK");
	initClick->SetEvent([this, initClick]()
	{
		initClick->Uninit();
		FirstCreate_();
	});

	return S_OK;
}

//--------------------------------------------------
// 終了
//--------------------------------------------------
void CRememberSystem::Uninit()
{
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CRememberSystem::Update()
{
	if (!m_isChange)
	{
		return;
	}

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
			// ポリゴンのカラー変更
			m_pAnswerObject[i]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		}
		m_isChange = false;
		m_changeLag = 0;
	}
}

//--------------------------------------------------
// 描画
//--------------------------------------------------
void CRememberSystem::Draw()
{
}

//--------------------------------------------------
// 生成
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
// 回答欄の生成
//--------------------------------------------------
void CRememberSystem::InitCreateAnswer_()
{
	for (int nCntY = 0; nCntY < Y_LINE; nCntY++)
	{
		for (int nCntX = 0; nCntX < X_LINE; nCntX++)
		{
			int nCntNumber = nCntY * Y_LINE + nCntX;

			// 答え
			D3DXVECTOR2 size(180.0f, 120.0f);

			float xInterval = size.x + 40.0f;
			float yInterval = size.y + 30.0f;

			D3DXVECTOR3 pos;
			pos.x = CApplication::CENTER_X - ((float)(X_LINE - 1) * 0.5f) * xInterval + nCntX * xInterval;
			pos.y = CApplication::CENTER_Y + 165.0f - ((float)(Y_LINE - 1) * 0.5f) * yInterval + nCntY * yInterval;
			pos.z = 0.0f;

			{
				CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_UI_2);
				object->SetPos(D3DXVECTOR3(pos.x, pos.y - size.y * 0.5f, 0.0f));
				object->SetSize(D3DXVECTOR2(50.0f * 0.5f, 63.0f * 0.5f));
				object->SetTexture("DECO_PIN");
			}

			m_pAnswerObject[nCntNumber] = CRememberObject::Create(pos, size, nCntNumber);
			m_pAnswerObject[nCntNumber]->SetTexture(m_tex[nCntNumber]);
			m_pAnswerObject[nCntNumber]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
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
					m_game->AddScore(7);
				}
				else
				{
					CCorrection::Create(false);
					m_game->AddScore(-15);
				}
			});
		}
	}
}

//--------------------------------------------------
// 答えの表示
//--------------------------------------------------
void CRememberSystem::DisplayRemember_()
{
	m_nBeforeNumber = m_pRememberObject->GetMyNumber();

	m_nAnswer = IntRandom(TEXTURE_MAX - 1, 0);

	m_pRememberObject->SetMyNumber(m_nAnswer);
	m_pRememberObject->SetTexture(m_tex[m_nAnswer]);
}

//--------------------------------------------------
// 選択肢
//--------------------------------------------------
void CRememberSystem::Choices_()
{
	// 一つをこたえにする
	int answer = 0;
	answer = IntRandom(MAX_ANSWER - 1, 0);

	m_isUsedNumber[m_nBeforeNumber] = true;

	// 抽選
	int number = 0;
	number = IntRandom(TEXTURE_MAX - 1, 0);

	for (int i = 0; i < MAX_ANSWER; i++)
	{
		if (answer == i)
		{// 答えと一緒にする
			m_pAnswerObject[i]->SetMyNumber(m_nBeforeNumber);
			m_pAnswerObject[i]->SetTexture(m_tex[m_nBeforeNumber]);
		}
		else
		{// それ以外（ダミー）
			while (m_isUsedNumber[number])
			{// 画像の抽選
				number = IntRandom(TEXTURE_MAX - 1, 0);
			}

			m_pAnswerObject[i]->SetMyNumber(number);
			m_pAnswerObject[i]->SetTexture(m_tex[number]);

			m_isUsedNumber[number] = true;
		}
	}
}

//--------------------------------------------------
// 初回作成
//--------------------------------------------------
void CRememberSystem::FirstCreate_()
{
	DisplayRemember_();

	// 一つをこたえにする
	int answer = 0;
	answer = IntRandom(1, 0);

	m_isUsedNumber[m_nBeforeNumber] = true;

	// 抽選
	int number = 0;
	number = IntRandom(TEXTURE_MAX - 1, 0);

	for (int nCntY = 0; nCntY < 1; nCntY++)
	{
		for (int nCntX = 0; nCntX < 2; nCntX++)
		{
			int nCntNumber = nCntY * Y_LINE + nCntX;

			// 答え
			D3DXVECTOR2 size(180.0f, 120.0f);

			float xInterval = size.x + 40.0f;
			float yInterval = size.y + 30.0f;

			D3DXVECTOR3 pos;
			pos.x = CApplication::CENTER_X - ((float)(X_LINE - 1) * 0.5f) * xInterval + nCntX * xInterval;
			pos.y = CApplication::CENTER_Y + 165.0f + (size.y + 30.0f) * 0.5f - ((float)(Y_LINE - 1) * 0.5f) * yInterval + nCntY * yInterval;
			pos.z = 0.0f;

			CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_UI_2);
			object->SetPos(D3DXVECTOR3(pos.x, pos.y - size.y * 0.5f, 0.0f));
			object->SetSize(D3DXVECTOR2(50.0f * 0.5f, 63.0f * 0.5f));
			object->SetTexture("DECO_PIN");

			CRememberObject* pAnswerObject = CRememberObject::Create(pos, size, nCntNumber);
			pAnswerObject->SetTexture(m_tex[nCntNumber]);
			pAnswerObject->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			pAnswerObject->SetEvent([this, nCntNumber, object, pAnswerObject]()
			{
				if (m_isChange)
				{
					return;
				}
				m_isChange = true;

				int answerMyNumber = pAnswerObject->GetMyNumber();
				if (answerMyNumber == m_nBeforeNumber)
				{
					CCorrection::Create(true);
					m_game->AddScore(7);
				}
				else
				{
					CCorrection::Create(false);
				}

				object->Uninit();
				pAnswerObject->Uninit();
				InitCreateAnswer_();
			});

			if (answer == nCntNumber)
			{// 答えと一緒にする
				pAnswerObject->SetMyNumber(m_nBeforeNumber);
				pAnswerObject->SetTexture(m_tex[m_nBeforeNumber]);
			}
			else
			{// それ以外（ダミー）
				while (m_isUsedNumber[number])
				{// 画像の抽選
					number = IntRandom(TEXTURE_MAX - 1, 0);
				}

				pAnswerObject->SetMyNumber(number);
				pAnswerObject->SetTexture(m_tex[number]);

				m_isUsedNumber[number] = true;
			}

		}
	}
}
