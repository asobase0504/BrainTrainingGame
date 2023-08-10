//=========================================
// 
// �I�u�W�F�N�g�N���X
// Author YudaKaito
// 
//=========================================
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <d3dx9.h>
#include <list>
#include <vector>
#include "objectList.h"

class CObject
{
public:	// �萔

public:	// �ÓI�֐�

public:
	CObject(int priority = CObjectList::LEVEL_SYSTEM);
	virtual ~CObject();

	virtual HRESULT Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() {};

	int GetPriority() { return m_assignmentPriority; }

	/* �ʒu */
	virtual void SetPos(const D3DXVECTOR3& inPos);	// �ʒu�̐ݒ�
	virtual void AddPos(const D3DXVECTOR3& inPos) { SetPos(m_pos + inPos); }	// �ʒu�̐ݒ�
	const D3DXVECTOR3& GetPos() { return m_pos; }	// �ʒu�̎擾

	/* ���X�g�\�� */
	void SetPrev(CObject* inTask) { m_prev = inTask; }
	CObject* GetPrev() { return m_prev; }
	void SetNext(CObject* inTask) { m_next = inTask; }
	CObject* GetNext() { return m_next; }

	/* �폜�t���O */
	void SetIsDeleted(bool inDeleted) { m_isDeleted = inDeleted; }		// ���S��Ԃ�ݒ�
	void Release() { m_isDeleted = true; }
	const bool GetIsDeleted() { return m_isDeleted; }
	const bool IsRelease() { return m_isDeleted; }

	/* �|�[�Y���̏�� */
	void AttachActivityAtPouse() { m_isActivityAtPouse = true; }
	bool IsActivityAtPouse() { return m_isActivityAtPouse; }

	/* �e�q�֌W */
	CObject* AttachParent(CObject* inParent) { inParent->AttachChildren(this); return inParent; }
	void AttachChildren(CObject* inChild) { m_children.push_back(inChild); inChild->m_parent = this; }

private:
	int m_assignmentPriority;	// �������Ă���v���C�I���e�B

	CObject* m_prev;	// �O�̃I�u�W�F�N�g
	CObject* m_next;	// ���̃I�u�W�F�N�g

	bool m_isActivityAtPouse;	// �|�[�Y�����X�V�ł��邩
	bool m_shouldInvisible;		// ��~���ɕ`����~�߂�ׂ���

	bool m_isDeleted;	// �폜�t���O

protected:
	CObject* m_parent;
	std::vector<CObject*> m_children;
	D3DXVECTOR3 m_pos;	// �ʒu
};

#endif // !_RENDERER_H_
