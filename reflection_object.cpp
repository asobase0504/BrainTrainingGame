//==================================================
// remember_object.cpp
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
const float CReflectionObject::SPEED = 10.0f;

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
CReflectionObject::CReflectionObject()
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
	CClickItem::Init();

	return S_OK;
}

//--------------------------------------------------
// 終了
//--------------------------------------------------
void CReflectionObject::Uninit()
{
	CClickItem::Uninit();
}

//--------------------------------------------------
// 更新
//--------------------------------------------------
void CReflectionObject::Update()
{
	CClickItem::Update();

	Reflection_();
}

//--------------------------------------------------
// 描画
//--------------------------------------------------
void CReflectionObject::Draw()
{
	CClickItem::Draw();
}

//--------------------------------------------------
// 生成
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
		if (pos.x < 0.0f + size.x * 0.5f)
		{
			pos.x = 0.0f + size.x * 0.5f;
			nor.x = 1.0f;
		}
		if (pos.x > CApplication::SCREEN_WIDTH - size.x * 0.5f)
		{
			pos.x = CApplication::SCREEN_WIDTH - size.x * 0.5f;
			nor.x = -1.0f;
		}
		if (pos.y < 0.0f + size.y * 0.5f)
		{
			pos.y = 0.0f + size.y * 0.5f;
			nor.y = 1.0f;
		}
		if (pos.y > CApplication::SCREEN_HEIGHT - size.y * 0.5f)
		{
			pos.y = CApplication::SCREEN_HEIGHT - size.y * 0.5f;
			nor.y = -1.0f;
		}

		move = GetMove();
		// 反射
		D3DXVECTOR3 refrectVector = CalcReflectVector(move, nor);
		SetMove(refrectVector * SPEED);
	}
}
