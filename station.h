//=========================================
// 
// �w�S�ʃN���X
// Author YudaKaito
// 
//=========================================
#ifndef _STATION_H_
#define _STATION_H_

#include "object3d.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CBus;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CStation : public CObject3D
{
private: // �񋓌^

public:	// �����o�[�֐�
	CStation();
	virtual ~CStation() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;

	// �X�V����
	virtual void Update() override;

	void Departure(CStation* inStation);	// �o��
	void Arrival();							// ����
	void GetOff();							// �~��
	void GetOn(int inNumber);				// ���

	void SetBus(CBus* inBus) { m_bus = inBus; }

	void AttachNextStation(CStation* inStation) { m_nextStation = inStation; }

private: // ���I�v���C�x�[�g�֐�

private: // ���I�����o�[�ϐ�

	CStation* m_nextStation;
	CBus* m_bus;

	int m_passenger;	// ��q
	int m_waitTime;

	bool m_IsPassed;
};

#endif // !_GAME_H_
