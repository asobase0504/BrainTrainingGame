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
CObject::CObject(TYPE type, int priority) :
	m_pos(D3DXVECTOR3(0.0f,0.0f,0.0f)),
	m_prev(nullptr),
	m_next(nullptr),
	m_isDeleted(false),
	m_shouldStopAlsoUpdate(false)
{
	m_type = type;

	CObjectList* taskGroup = CObjectList::GetInstance();

	taskGroup->SetPushCurrent(this, priority);
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CObject::~CObject()
{
}
