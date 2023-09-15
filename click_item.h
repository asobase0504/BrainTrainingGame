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
	explicit CClickItem();
	~CClickItem();

	HRESULT Init() override;
	void Update() override;

	virtual void ClickEvent() { m_event(); }

	bool IsClick() { return m_isClick; }

	void SetEvent(std::function<void(void)> infunc) { m_event = infunc; }
private:
	bool m_isClick;
	std::function<void(void)> m_event;
};
#endif	// _NUMBER_H_