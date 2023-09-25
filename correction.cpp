#include "correction.h"
#include "application.h"
#include "correction.h"
#include "sound.h"

CCorrection::CCorrection() : CObject2D(CTaskGroup::EPriority::LEVEL_2D_UI_2)
{
}

CCorrection::~CCorrection()
{
}

HRESULT CCorrection::Init()
{
	CObject2D::Init();
	SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y,0.0f));
	SetSize(D3DXVECTOR2(300.0f,300.0f));
	m_releaseTime = 20;
	return E_NOTIMPL;
}

void CCorrection::Update()
{
	m_releaseTime--;

	if (m_releaseTime <= 0)
	{
		Release();
	}
}

CCorrection * CCorrection::Create(bool isCorrect)
{
	CCorrection* object = new CCorrection;

	assert(object != nullptr);

	object->Init();
	object->SetCorrect(isCorrect);

	return object;
}

void CCorrection::SetCorrect(bool isCorrect)
{
	if (isCorrect)
	{
		SetTexture("TRUE");
		CApplication::GetInstance()->GetSound()->Play(CSound::ELabel::LABEL_SE_TRUE);
	}
	else
	{
		SetTexture("FALSE");
		CApplication::GetInstance()->GetSound()->Play(CSound::ELabel::LABEL_SE_FALSE);
	}
}
