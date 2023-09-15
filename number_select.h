//==================================================
// �����̓���
// Author: YudaKaito
//==================================================
#ifndef _NUMBER_SELECT_H_
#define _NUMBER_SELECT_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object2D.h"

//**************************************************
// �O���O���@���Ԃ�NG�@�|�C���^�����Ȃ�OK
//**************************************************
class CClickItem;
class CSequence;

//**************************************************
// �N���X
//**************************************************
class CNumberSelect : public CObject2D
{
public:
	explicit CNumberSelect();
	~CNumberSelect();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	static CNumberSelect *Create();

	int GetNumber();

	bool IsReturn() { return m_isReturn; }

private:
	CClickItem* m_numberClickItem[10];
	CClickItem* m_returnClickItem;
	CClickItem* m_backClickItem;
	CSequence* m_sequence;
	int m_number;
	bool m_isReturn;
};


#endif	// _NUMBER_H_