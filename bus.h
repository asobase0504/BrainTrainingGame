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

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CBus : public CObject3D
{
public:	// �����o�[�֐�
	CBus();
	virtual ~CBus() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;

	// �X�V����
	virtual void Update() override;

private: // ���I�v���C�x�[�g�֐�

private: // ���I�����o�[�ϐ�

	int m_passenger;			// ��q
};

#endif // !_GAME_H_
