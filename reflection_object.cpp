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
const float CReflectionObject::SPEED = 10.0f;
const float CReflectionObject::X_MIN = 0.0f;
const float CReflectionObject::X_MAX = (float)CApplication::SCREEN_WIDTH;
const float CReflectionObject::Y_MIN = 0.0f;
const float CReflectionObject::Y_MAX = (float)CApplication::SCREEN_HEIGHT;

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
CReflectionObject::CReflectionObject()
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
	CClickItem::Init();

	return S_OK;
}

//--------------------------------------------------
// �I��
//--------------------------------------------------
void CReflectionObject::Uninit()
{
	CClickItem::Uninit();
}

//--------------------------------------------------
// �X�V
//--------------------------------------------------
void CReflectionObject::Update()
{
	CClickItem::Update();

	Reflection_();

	Rotate_();
}

//--------------------------------------------------
// �`��
//--------------------------------------------------
void CReflectionObject::Draw()
{
	CClickItem::Draw();
}

//--------------------------------------------------
// ����
//--------------------------------------------------
CReflectionObject *CReflectionObject::Create(const D3DXVECTOR3& inPos, const D3DXVECTOR2& inSize, int inMyNumber)
{
	CReflectionObject *pReflectionObject;
	pReflectionObject = new CReflectionObject;

	if (pReflectionObject != nullptr)
	{
		pReflectionObject->Init();
		pReflectionObject->SetPos(inPos);
		pReflectionObject->SetSize(inSize);
		pReflectionObject->SetMyNumber(inMyNumber);
	}
	else
	{
		assert(false);
	}

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
		SetMove(refrectVector * SPEED);
	}
}

//--------------------------------------------------
// ����
//--------------------------------------------------
void CReflectionObject::Rotate_()
{
	AddRot(0.05f);
}
