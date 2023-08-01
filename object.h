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

class CObject
{
public:	// �񋓌^
	// CObject�N���X�̔h����
	enum class TYPE
	{
		CHARACTER = 0,
		BULLET,
		BLOCK,
		NONE
	};

public:	// �萔

public:	// �ÓI�֐�

public:
	CObject(TYPE type,int priority = 3);
	virtual ~CObject();

	virtual HRESULT Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	// Setter
	void SetIsDeleted(bool inDeleted) { m_isDeleted = inDeleted; }		// ���S��Ԃ�ݒ�
	void SetShouldStopAlsoUpdate() { m_shouldStopAlsoUpdate = true; }
	virtual void SetPos(const D3DXVECTOR3& inPos) { m_pos = inPos; }	// �ʒu�̐ݒ�

	// Getter
	const D3DXVECTOR3& GetPos() { return m_pos; }	// �ʒu�̎擾
	const TYPE GetType() { return m_type; }
	const bool GetIsDeleted() { return m_isDeleted; }

	/* ���X�g�\�� */
	void SetPrev(CObject* inTask) { m_prev = inTask; }
	CObject* GetPrev() { return m_prev; }
	void SetNext(CObject* inTask) { m_next = inTask; }
	CObject* GetNext() { return m_next; }

	/* �폜�t���O */
	void Release() { m_isDeleted = true; }
	bool IsRelease() { return m_isDeleted; }

	bool IsActivityAtPouse() { return m_isActivityAtPouse; }
	int GetPriority() { return m_assignmentPriority; }
private:

private:
	bool m_shouldStopAlsoUpdate;	// ��~�����X�V���ׂ���
	bool m_shouldInvisible;		// ��~���ɕ`����~�߂�ׂ���

	CObject* m_prev;	// �O�̃I�u�W�F�N�g
	CObject* m_next;	// ���̃I�u�W�F�N�g

	int m_assignmentPriority;
	bool m_isActivityAtPouse;
protected:
	D3DXVECTOR3 m_pos;	// �ʒu
	bool m_isDeleted;	// �폜�t���O
	TYPE m_type;		// ���
};

#endif // !_RENDERER_H_
