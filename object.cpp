//=========================================
// 
// �I�u�W�F�N�g�N���X
// Author YudaKaito
// 
//=========================================
#include "object.h"
#include "renderer.h"
#include "objectList.h"

//=========================================
// �ÓI�����o�[�ϐ��̐錾
//=========================================

//----------------------------------------
// �R���X�g���N�^
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
// �f�X�g���N�^
//----------------------------------------
CObject::~CObject()
{
}
