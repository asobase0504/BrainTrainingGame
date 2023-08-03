//=========================================
// 
// �o�X�S�ʃN���X
// Author YudaKaito
// 
//=========================================
#ifndef _BUS_H_
#define _BUS_H_

#include "object3d.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CStation;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CBus : public CObject3D
{
private: // �񋓌^

	enum class State
	{
		MOVE,
		STOP
	};

public:	// �����o�[�֐�
	CBus();
	virtual ~CBus() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;

	// �X�V����
	virtual void Update() override;

	bool IsArrival() { return m_isArrival; }

	void Departure(CStation* inStation);	// �o��
	void Arrival();							// ����
	void GetOff();							// �~��
	void GetOn(int inNumber) { m_passenger += inNumber; }				// ���

private: // ���I�v���C�x�[�g�֐�

private: // ���I�����o�[�ϐ�

	CStation* m_nextStation;
	State m_state;		// ���
	int m_passenger;	// ��q
	int m_nextGetOff;	// ���~���l
	bool m_isArrival;	// ����������
};

#endif // !_GAME_H_
