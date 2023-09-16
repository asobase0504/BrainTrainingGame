//==================================================
// ���U���g��ʂ̐���
// Author: YudaKaito
//==================================================
#ifndef _CALENDER_H_
#define _CALENDER_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object2D.h"

//**************************************************
// �O���O���@���Ԃ�NG�@�|�C���^�����Ȃ�OK
//**************************************************
class CSequence;

//**************************************************
// �N���X
//**************************************************
class CCalender : public CObject2D
{
public:
	explicit CCalender();
	~CCalender();

	HRESULT Init() override;
	void Update() override;

	static CCalender* Create();

private:
	CSequence* m_day[49];
};


#endif	// _NUMBER_H_