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
#include <array>

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

	// ���̓����̃I�u�W�F�N�g�̎擾
	CObject2D* GetDayObject(int inDay) { return m_tag[m_dayTag[inDay]]; }

private:
	CSequence* m_day[49];
	CObject2D* m_tag[49];
	CObject2D* m_stanp[49];
	std::array<int, 31> m_dayTag;
};


#endif	// _NUMBER_H_