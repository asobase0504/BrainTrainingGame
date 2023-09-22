//==================================================
// reflection_object.cpp
// Author: Buriya Kota
//==================================================

//**************************************************
// include
//**************************************************
#include "reflection_object.h"

#include "application.h"
#include "utility.h"

//**************************************************
// �萔
//**************************************************
const float CReflectionObject::SPEED = 4.0f;
const float CReflectionObject::X_MIN = CApplication::CENTER_X - (CApplication::CENTER_Y * 1.0f * 0.5f);
const float CReflectionObject::X_MAX = CApplication::CENTER_X + (CApplication::CENTER_Y * 1.0f * 0.5f);
const float CReflectionObject::Y_MIN = CApplication::CENTER_Y - (CApplication::CENTER_Y * 1.0f * 0.5f);
const float CReflectionObject::Y_MAX = CApplication::CENTER_Y + (CApplication::CENTER_Y * 1.0f * 0.5f);

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
CReflectionObject::CReflectionObject() : m_rotY(0.0f)
{
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
CReflectionObject::~CReflectionObject()
{
}

//--------------------------------------------------
// ������
//--------------------------------------------------
HRESULT CReflectionObject::Init()
{
	CRememberObject::Init();

	Reset();

	return S_OK;
}

//--------------------------------------------------
// �I��
//--------------------------------------------------
void CReflectionObject::Uninit()
{
	CRememberObject::Uninit();
}

//--------------------------------------------------
// �X�V
//--------------------------------------------------
void CReflectionObject::Update()
{
	CRememberObject::Update();

	Reflection_();

	Rotate_();
}

//--------------------------------------------------
// �`��
//--------------------------------------------------
void CReflectionObject::Draw()
{
	CRememberObject::Draw();
}

void CReflectionObject::Reset()
{
	m_rotY = FloatRandom(0.05f, -0.05f);
	m_spead = FloatRandom(6.0f, 2.0f);
}

//--------------------------------------------------
// ����
//--------------------------------------------------
CReflectionObject *CReflectionObject::Create(const D3DXVECTOR3& inPos, const D3DXVECTOR2& inSize, int inMyNumber)
{
	CReflectionObject *pReflectionObject;
	pReflectionObject = new CReflectionObject;

	assert(pReflectionObject != nullptr);

	pReflectionObject->Init();
	pReflectionObject->SetPos(inPos);
	pReflectionObject->SetSize(inSize);
	pReflectionObject->SetMyNumber(inMyNumber);

	return pReflectionObject;
}

//--------------------------------------------------
// ����
//--------------------------------------------------
void CReflectionObject::Reflection_()
{
	D3DXVECTOR3 pos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR2 size(0.0f, 0.0f);
	D3DXVECTOR3 move(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 nor(0.0f, 0.0f, 0.0f);

	pos = GetPos();
	size = GetSize();
	{// �����߂�
		if (pos.x < X_MIN + size.x * 0.5f)
		{
			pos.x = X_MIN + size.x * 0.5f;
			nor.x = 1.0f;
		}
		if (pos.x > X_MAX - size.x * 0.5f)
		{
			pos.x = X_MAX - size.x * 0.5f;
			nor.x = -1.0f;
		}
		if (pos.y < Y_MIN + size.y * 0.5f)
		{
			pos.y = Y_MIN + size.y * 0.5f;
			nor.y = 1.0f;
		}
		if (pos.y > Y_MAX - size.y * 0.5f)
		{
			pos.y = Y_MAX - size.y * 0.5f;
			nor.y = -1.0f;
		}

		move = GetMove();
		// ����
		D3DXVECTOR3 refrectVector = CalcReflectVector(move, nor);
		SetMove(refrectVector * m_spead);
	}
}

//--------------------------------------------------
// ����
//--------------------------------------------------
void CReflectionObject::Rotate_()
{
	AddRot(m_rotY);
}
