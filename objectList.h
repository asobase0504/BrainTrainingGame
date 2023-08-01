//=============================================================================
//
// �I�u�W�F�N�g�̏W�܂�
// Author : Yuda Kaito
//
//=============================================================================
#ifndef _OBJECT_LIST_H_			// ���̃}�N����`������ĂȂ�������
#define _OBJECT_LIST_H_			// ��d�C���N���[�h�h�~�̃}�N����`

//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include <Windows.h>
#include <unordered_map>
#include <functional>

//-----------------------------------------------------------------------------
// �O���錾
//-----------------------------------------------------------------------------
class CObject;

//=============================================================================
// �^�X�N�N���X
//=============================================================================
class CObjectList
{
public:
	// ���X�g�\����
	struct SList
	{
		CObject* top;
		CObject* current;
	};

	// �D�揇��
	enum EPriority
	{
		LEVEL_SYSTEM = 0,
		LEVEL_3D_1,
		LEVEL_2D_1,
		LEVEL_2D_2,
		LEVEL_2D_UI,
		LEVEL_FADE,
		LEVEL_DEBUG,
		LEVEL_DEBUG1,
		LEVEL_DEBUG3,
		LEVEL_MAX
	};

	// �ǉ����@
	enum EPushMethod
	{
		PUSH_CURRENT = 0,
		PUSH_TOP,
		PUSH_NEXT,
		PUSH_PREV
	};

private:
	static CObjectList* instance;
public:
	static CObjectList* GetInstance() { return instance != nullptr ? instance : instance = new CObjectList; }
private:
	CObjectList();
public:
	~CObjectList();

	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

	// Release
	void AllRelease();
	void AbsolutelyRelease();
	void PriorityRelease(const EPriority inPriotity);

	void AllProcess(std::function<void(CObject*)> func);
	void PriorityProcess(int cnt, std::function<void(CObject*)> func);

	// Setter
	void SetPushCurrent(CObject* inTask, int inPriority = 0);
	void SetPushTop(CObject* inTask, int inPriority = 0);
	void SetNextObject(CObject* inReference, CObject* inTask);
	void SetPrevObject(CObject* inReference, CObject* inTask);

	// Getter
	CObject* GetTop(int priority = 0) { return m_list.at(priority).top; }
	CObject* GetCurrent(int priority = 0) { return m_list.at(priority).current; }

	// ����
	CObject* SearchRoleTop(int inRole, int inPriority);
	CObject* SearchRoleCurrent(int inRole, int inPriority);
	CObject* SearchSameRoleNext(CObject* inTask);
	CObject* SearchSameRolePrev(CObject* inTask);

	/* �|�[�Y��Ԃɂ��� */
	void Pause(bool isPause);

private:
	void DeleteObject();

private:
	std::unordered_map<int, SList> m_list;	// ���X�g�ꗗ
	unsigned int m_createNumber;			// ���v������
	int m_priorityNumber;					// �`�揇��

	bool m_isPouseStop;
};
#endif
