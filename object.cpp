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
CObject::CObject(int priority) :
	m_assignmentPriority(priority),
	m_pos(D3DXVECTOR3(0.0f,0.0f,0.0f)),
	m_prev(nullptr),
	m_next(nullptr),
	m_isDeleted(false),
	m_isActivityAtPouse(false),
	m_shouldInvisible(false),
	m_parent(nullptr)
{
	m_children.clear();


	CObjectList* taskGroup = CObjectList::GetInstance();

	taskGroup->SetPushCurrent(this, priority);
}

//----------------------------------------
// �f�X�g���N�^
//----------------------------------------
CObject::~CObject()
{
}


//----------------------------------------
// �f�X�g���N�^
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
