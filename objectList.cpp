//=============================================================================
//
// �}�l�[�W���[
// Author : Yuda Kaito
//
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "ObjectList.h"
#include "Object.h"
#include "renderer.h"
#include <assert.h>

//-----------------------------------------------------------------------------
// �ÓI�����o�[�ϐ��̐錾
//-----------------------------------------------------------------------------
CObjectList* CObjectList::instance = nullptr;

//=============================================================================
// �R���X�g���N�^
// Author : Yuda Kaito
//=============================================================================
CObjectList::CObjectList() :
	m_priorityNumber(0),
	m_isPouseStop(false)
{
	m_list.clear();
}

//=============================================================================
// �f�X�g���N�^
// Author : Yuda Kaito
//=============================================================================
CObjectList::~CObjectList()
{
}

//=============================================================================
// ������
// Author : Yuda Kaito
//=============================================================================
HRESULT CObjectList::Init()
{
	return S_OK;
}

//=============================================================================
// �S�Ẵ^�X�N�ɏ������s��
// Author : Yuda Kaito
//=============================================================================
void CObjectList::AllProcess(std::function<void(CObject*)> func)
{
	for (int i = 0; i <= m_priorityNumber; i++)
	{
		PriorityProcess(i, func);
	}
}

//=============================================================================
// �w�肳�ꂽpriority�ɂ���^�X�N�S�Ă̏������s��
// Author : Yuda Kaito
//=============================================================================
void CObjectList::PriorityProcess(int cnt, std::function<void(CObject*)> func)
{
	if (m_list.count(cnt) == 0)
	{
		return;
	}

	int objectCnt = 0;

	CObject* now = m_list.at(cnt).top;

	while (now != nullptr)
	{
		CObject* next = now->GetNext();

		func(now);
		objectCnt++;

		now = next;
	}
}

//=============================================================================
// �I��
// Author : Yuda Kaito
//=============================================================================
void CObjectList::Uninit()
{
	AllProcess([](CObject* object)
	{
		object->Release();
	});

	DeleteObject();	// �^�X�N���X�g�̍폜

	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

//=============================================================================
// �X�V
// Author : Yuda Kaito
//=============================================================================
void CObjectList::Update()
{
	AllProcess([this](CObject* object)
	{
		if (!object->IsRelease())
		{
			if (!m_isPouseStop || object->IsActivityAtPouse())
			{
				object->Update();
			}
		}
	});

	DeleteObject();	// �^�X�N���X�g�̍폜
}

//=============================================================================
// �`��
// Author : Yuda Kaito
//=============================================================================
void CObjectList::Draw()
{
	AllProcess([](CObject* object)
	{
		if (!object->IsRelease())
		{
			object->Draw();
		}
	});
}

//=============================================================================
// �������Ă���^�X�N�̔j��
// Author : Yuda Kaito
//=============================================================================
void CObjectList::AllRelease()
{
	AllProcess([](CObject* object)
	{
		object->Release();
	});

	DeleteObject();	// �^�X�N���X�g�̍폜
}

//=============================================================================
// ��΂Ƀ^�X�N��j��
// Author : Yuda Kaito
//=============================================================================
void CObjectList::AbsolutelyRelease()
{
	AllProcess([](CObject* object) {object->Release(); });
}

//=============================================================================
// �w�肵��priority�̃^�X�N��j��
// Author : Yuda Kaito
//=============================================================================
void CObjectList::PriorityRelease(const EPriority inPriotity)
{
	if (m_list.count(inPriotity) == 0)
	{
		return;
	}

	CObject* now = m_list.at(inPriotity).top;

	while (now != nullptr)
	{
		now->Release();
		now = now->GetNext();
	}
}

//=============================================================================
// ���X�g�̍Ō�Ƀ^�X�N������
// Author : Yuda Kaito
//=============================================================================
void CObjectList::SetPushCurrent(CObject * inObject, int inPriority)
{
	if (m_list.count(inPriority) == 0)
	{
		SList inList;
		inList.top = nullptr;
		inList.current = nullptr;
		m_list.insert(std::make_pair(inPriority, inList));

		if (m_priorityNumber < inPriority)
		{
			m_priorityNumber = inPriority;
		}
	}

	SList* list = &m_list.at(inPriority);

	if (list->current == nullptr && list->top == nullptr)
	{
		list->top = inObject;
		list->current = inObject;
	}
	else
	{
		CObject* current = list->current;		// �O�񖖔�
		list->current = inObject;				// �V�K����
		list->current->SetPrev(current);	// �V�K�����̑O�ɑO�񖖔���ݒ�
		current->SetNext(list->current);	// �O�񖖔��̌�ɐV�K������ݒ�
	}
}

//=============================================================================
// ���X�g�̍ŏ��Ƀ^�X�N������
// Author : Yuda Kaito
//=============================================================================
void CObjectList::SetPushTop(CObject * inObject, int inPriority)
{
	if (m_list.count(inPriority) == 0)
	{
		SList inList;
		m_list.insert(std::make_pair(inPriority, inList));
		m_list.at(inPriority).top = nullptr;
		m_list.at(inPriority).current = nullptr;

		if (m_priorityNumber < inPriority)
		{
			m_priorityNumber = inPriority;
		}
	}

	if (m_list.at(inPriority).current == nullptr && m_list.at(inPriority).top == nullptr)
	{
		m_list.at(inPriority).top = inObject;
		m_list.at(inPriority).current = inObject;
	}
	else
	{
		CObject* top = m_list.at(inPriority).top;		// �O��擪
		m_list.at(inPriority).top = inObject;			// �V�K�擪
		m_list.at(inPriority).top->SetNext(top);	// �V�K�擪�̎��ɑO��擪��ݒ�
		top->SetPrev(m_list.at(inPriority).top);	// �V�K�擪�̌�ɐV�K�擪��ݒ�
	}
}

//=============================================================================
// �Q�Ƃ����^�X�N�̎��Ƀ^�X�N������
// Author : Yuda Kaito
//=============================================================================
void CObjectList::SetNextObject(CObject* inReference, CObject* inObject)
{
	if (inReference == nullptr)
	{
		SetPushCurrent(inObject, 0);
		return;
	}

	CObject* currentNext = inReference->GetNext();	// next�̕ۑ�

	if (currentNext != nullptr)
	{
		inObject->SetNext(currentNext);
		inObject->SetPrev(inReference);
		inReference->SetNext(inObject);
		currentNext->SetPrev(inObject);
	}
	else
	{
		m_list.at((int)inReference->GetPriority()).current = inObject;
		inObject->SetNext(nullptr);
		inObject->SetPrev(inReference);
		inReference->SetNext(inObject);
	}
}

//=============================================================================
// �Q�Ƃ����^�X�N�̑O�Ƀ^�X�N������
// Author : Yuda Kaito
//=============================================================================
void CObjectList::SetPrevObject(CObject* inReference, CObject* inObject)
{
	if (inReference == nullptr)
	{
		SetPushCurrent(inObject);
		return;
	}

	CObject* currentPrev = inReference->GetPrev();	// next�̕ۑ�

	if (currentPrev != nullptr)
	{
		inObject->SetNext(inReference);
		inObject->SetPrev(currentPrev);
		currentPrev->SetNext(inObject);
		inReference->SetPrev(inObject);
	}
	else
	{
		m_list.at((int)inReference->GetPriority()).top = inObject;
		inObject->SetNext(inReference);
		inObject->SetPrev(nullptr);
		inReference->SetPrev(inObject);
	}

}

//=============================================================================
// �^�X�N�̖������Ƃ̌���(Top�����猟�����Č��������擪��Ԃ�)
// Author : Yuda Kaito
//=============================================================================
CObject * CObjectList::SearchRoleTop(int inRole, int inPriority)
{
	if (m_list.count(inPriority) == 0)
	{
		// ������̃��X�g���Ȃ������ꍇ
		assert(false);
		return nullptr;
	}

	CObject* now = m_list.at(inPriority).top;

	while (now != nullptr)
	{
		CObject* next = now->GetNext();
		//if (now->GetRole() == inRole)
		{
			return now;
		}
		//now = next;
	}
	return nullptr;
}

//=============================================================================
// �^�X�N�̖������Ƃ̌���(Current�����猟�����Č��������擪��Ԃ�)
// Author : Yuda Kaito
//=============================================================================
CObject * CObjectList::SearchRoleCurrent(int inRole, int inPriority)
{
	if (m_list.count(inPriority) == 0)
	{
		// ������̃��X�g���Ȃ������ꍇ
		assert(false);
		return nullptr;
	}

	CObject* now = m_list.at(inPriority).current;

	while (now != nullptr)
	{
		CObject* prev = now->GetPrev();
		//if (now->GetRole() == inRole)
		{
			return now;
		}
		//now = prev;
	}
	return nullptr;
}

//=============================================================================
// �󂯂Ƃ����^�X�N�Ɠ��������̃^�X�N������(Next�����猟��)
// Author : Yuda Kaito
//=============================================================================
CObject * CObjectList::SearchSameRoleNext(CObject* inObject)
{
	CObject* now = inObject->GetNext();
	//CObject::ERole role = inObject->GetRole();

	while (now != nullptr)
	{
		CObject* next = now->GetNext();
		//if (now->GetRole() == role)
		{
			return now;
		}
		//now = next;
	}
	return nullptr;
}

//=============================================================================
// �󂯂Ƃ����^�X�N�Ɠ��������̃^�X�N������(Prev�����猟��)
// Author : Yuda Kaito
//=============================================================================
CObject * CObjectList::SearchSameRolePrev(CObject * inObject)
{
	CObject* now = inObject;
	//CObject::ERole role = inObject->GetRole();

	while (now != nullptr)
	{
		CObject* prev = now->GetPrev();
		//if (now->GetRole() == role)
		{
			return now;
		}
		//now = prev;
	}
	return nullptr;
}

//=============================================================================
// �|�[�Y���ɍX�V���~�߂�object�̍X�V���~�߂�
// Author : Yuda Kaito
//=============================================================================
void CObjectList::Pause(bool isPause)
{
	m_isPouseStop = isPause;
}

//=============================================================================
// �^�X�N�̍폜
// Author : Yuda Kaito
//=============================================================================
void CObjectList::DeleteObject()
{
	for (int i = 0; i <= m_priorityNumber; i++)
	{
		// �폜
		auto Delete = [i, this](CObject* tack)
		{
			CObject* next = tack->GetNext();
			CObject* prev = tack->GetPrev();

			if (!tack->IsRelease())
			{
				return;
			}

			// �O��̏�Ԃ��擾
			bool isNextNullptr = (next == nullptr);
			bool isPrevNullptr = (prev == nullptr);

			if (!isNextNullptr && !isPrevNullptr)
			{ // �O��Ƀ^�X�N�������Ă���ꍇ
				next->SetPrev(prev);
				prev->SetNext(next);
			}
			else if (!isNextNullptr && isPrevNullptr)
			{ // ��̂݃^�X�N�������Ă���ꍇ
				m_list.at(i).top = next;
				next->SetPrev(nullptr);
			}
			else if (isNextNullptr && !isPrevNullptr)
			{ // �O�̂݃^�X�N�������Ă���ꍇ
				m_list.at(i).current = prev;
				prev->SetNext(nullptr);
			}
			else
			{ // �O��Ƀ^�X�N�������Ă��Ȃ��ꍇ
				m_list.at(i).current = nullptr;
				m_list.at(i).top = nullptr;
				m_list.erase(i);
			}

			tack->Uninit();	// �I��
			delete tack;	// �폜
		};

		// priority�̑S�Ă�Tack�Ɉ����̊֐����s��
		PriorityProcess(i, Delete);
	}
}
