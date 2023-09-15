//=========================================
// 
// オブジェクトクラス
// Author YudaKaito
// 
//=========================================
#include "object.h"
#include "renderer.h"
#include "objectList.h"

//=========================================
// 静的メンバー変数の宣言
//=========================================

//----------------------------------------
// コンストラクタ
//----------------------------------------
CObject::CObject(int priority) :
	CTask((CTaskGroup::EPriority)priority),
	m_pos(D3DXVECTOR3(0.0f,0.0f,0.0f)),
	m_parent(nullptr)
{
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CObject::~CObject()
{
}


//----------------------------------------
// デストラクタ
//----------------------------------------
void CObject::SetPos(const D3DXVECTOR3& inPos)
{
	m_pos = inPos;

	int childrenCount = m_children.size();

	for (int i = 0; i < childrenCount; i++)
	{
		m_children[i]->SetPos(m_children[i]->GetPos());
	}
}
