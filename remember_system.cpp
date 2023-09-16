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

	// 覚えるやつ 一回だけつくる
	m_pRememberObject = CRememberObject::Create(
		D3DXVECTOR3((float)CApplication::SCREEN_WIDTH * 0.5f, 150.0f, 0.0f),
		D3DXVECTOR2(300.0f, 200.0f), m_nAnswer);
	m_pRememberObject->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	m_pRememberObject->SetTexture(m_tex[m_nAnswer]);

	for (int nCntY = 0; nCntY < Y_LINE; nCntY++)
	{
		for (int nCntX = 0; nCntX < X_LINE; nCntX++)
		{
			int nCntNumber = nCntY * Y_LINE + nCntX;

			// 答え
			m_pAnswerObject[nCntNumber] = CRememberObject::Create(
				D3DXVECTOR3(400.0f + 450.0f * nCntX, 370.0f + 250.0f * nCntY, 0.0f),
				D3DXVECTOR2(300.0f, 200.0f), nCntNumber);
			m_pAnswerObject[nCntNumber]->SetTexture(m_tex[nCntNumber]);
			m_pAnswerObject[nCntNumber]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		}
	}

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
	D3DXVECTOR3 mousePos = CInput::GetKey()->GetMouseCursor();
	Touch_(mousePos.x, mousePos.y);

	if (CInput::GetKey()->Trigger(DIK_RETURN))
	{
		DisplayRemember_();

		for (int i = 0; i < TEXTURE_MAX; i++)
		{
			m_isUsedNumber[i] = false;
		}
	}

	if (CInput::GetKey()->Trigger(MOUSE_KEY::MOUSE_INPUT_RIGHT))
	{
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
// タッチ
//--------------------------------------------------
void CRememberSystem::Touch_(float nPosX, float nPosY)
{
	/*int answerMyNumber = m_pAnswerObject[0]->GetMyNumber();
	int rememberMyNumber = m_pRememberObject->GetMyNumber();

	m_pAnswerObject[0]->SetEvent([this, answerMyNumber, rememberMyNumber](){
		if (answerMyNumber == rememberMyNumber)
		{
			m_pAnswerObject[0]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		}
	});*/

	for (int nCntNumber = 0; nCntNumber < MAX_ANSWER; nCntNumber++)
	{
		D3DXVECTOR3 pos = m_pAnswerObject[nCntNumber]->GetPos();
		D3DXVECTOR3 size = m_pAnswerObject[nCntNumber]->GetSize();

		int answerMyNumber = m_pAnswerObject[nCntNumber]->GetMyNumber();

		//	タッチ座標がポリゴンの中だったら
		if (CInput::GetKey()->Trigger(MOUSE_INPUT_LEFT) &&
			pos.x + size.x >= nPosX &&
			pos.x - size.x <= nPosX &&
			pos.y - size.y <= nPosY &&
			pos.y + size.y >= nPosY &&
			answerMyNumber == m_nBeforeNumber)
		{
			// ポリゴンのカラー変更
			m_pAnswerObject[nCntNumber]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
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
