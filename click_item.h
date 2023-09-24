//==================================================
// ���U���g��ʂ̐���
// Author: YudaKaito
//==================================================
#ifndef _CLICK_ITEM_H_
#define _CLICK_ITEM_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object2D.h"
#include <functional>

//**************************************************
// �O���O���@���Ԃ�NG�@�|�C���^�����Ȃ�OK
//**************************************************

//**************************************************
// �萔��`
//**************************************************

//**************************************************
// �\���̒�`
//**************************************************

//**************************************************
// �N���X
//**************************************************
class CClickItem : public CObject2D
{
public:
	explicit CClickItem(int priority = CTaskGroup::EPriority::LEVEL_2D_UI);
	~CClickItem();

	void Update() override;

	virtual void ClickEvent() { m_event(); }

	bool IsClick() { return m_isClick; }

	void SetEvent(std::function<void(void)> infunc) { m_event = infunc; }
	void SetEventTick(std::function<void(void)> infunc) { m_eventTick = infunc; }

	int GetTick() { return m_tick; }

	static CClickItem* Create(const D3DXVECTOR3& inPos, const D3DXVECTOR2& inSize,int priority = CTaskGroup::EPriority::LEVEL_2D_UI);
private:
	bool m_isClick;
	std::function<void(void)> m_event;
	std::function<void(void)> m_eventTick;
	int m_tick;
};
#endif	// _NUMBER_H_