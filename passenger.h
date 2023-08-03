//=========================================
// 
// �l�ԑS�ʃN���X
// Author YudaKaito
// 
//=========================================
#ifndef _PASSENGER_H_
#define _PASSENGER_H_

#include "object3d.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CPassenger : public CObject3D
{
private: // �񋓌^

	enum class State
	{
		STOP = 0,
		GETOFF,
		GETIN
	};

public:	// �����o�[�֐�
	CPassenger();
	virtual ~CPassenger() override;

	static CPassenger* Create(const D3DXVECTOR3 inPos);
public:	// �����o�[�֐�
	virtual HRESULT Init() override;
	virtual void Uninit() override;

	// �X�V����
	virtual void Update() override;

	void GetIn() { m_state = State::GETIN; }
	void GetOff() { m_state = State::GETOFF; }

private: // ���I�v���C�x�[�g�֐�

private: // ���I�����o�[�ϐ�

	State m_state;		// ���
};

#endif // !_GAME_H_
