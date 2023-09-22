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
// 定数
//**************************************************
const float CReflectionObject::SPEED = 4.0f;
const float CReflectionObject::X_MIN = CApplication::CENTER_X - (CApplication::CENTER_Y * 1.0f * 0.5f);
const float CReflectionObject::X_MAX = CApplication::CENTER_X + (CApplication::CENTER_Y * 1.0f * 0.5f);
const float CReflectionObject::Y_MIN = CApplication::CENTER_Y - (CApplication::CENTER_Y * 1.0f * 0.5f);
const float CReflectionObject::Y_MAX = CApplication::CENTER_Y + (CApplication::CENTER_Y * 1.0f * 0.5f);

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CReflectionObject::CReflectionObject() : m_rotY(0.0f)
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CReflectionObject::~CReflectionObject()
{
}

//--------------------------------------------------
// 初期化
//--------------------------------------------------
HRESULT CReflectionObject::Init()
{
	CRememberObject::Init();

	Reset();

	return S_OK;
}

//--------------------------------------------------
// 終了
//--------------------------------------------------
void CReflectionObject::Uninit()
{
	CRememberObject::Uninit();
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CReflectionObject::Update()
{
	CRememberObject::Update();

	Reflection_();

	Rotate_();
}

//--------------------------------------------------
// 描画
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
// 生成
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
// 反射
//--------------------------------------------------
void CReflectionObject::Reflection_()
{
	D3DXVECTOR3 pos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR2 size(0.0f, 0.0f);
	D3DXVECTOR3 move(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 nor(0.0f, 0.0f, 0.0f);

	pos = GetPos();
	size = GetSize();
	{// 押し戻し
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
		// 反射
		D3DXVECTOR3 refrectVector = CalcReflectVector(move, nor);
		SetMove(refrectVector * m_spead);
	}
}

//--------------------------------------------------
// 反射
//--------------------------------------------------
void CReflectionObject::Rotate_()
{
	AddRot(m_rotY);
}
