//==================================================
// remember_system.h
// Author: Buriya Kota
//==================================================
#ifndef _REMMBER_SYSTEM_H_
#define _REMMBER_SYSTEM_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object.h"

//**************************************************
// �O���O���@���Ԃ�NG�@�|�C���^�����Ȃ�OK
//**************************************************
class CObject2D;

//**************************************************
// �萔��`
//**************************************************
class CRememberObject;

//**************************************************
// �\���̒�`
//**************************************************

//**************************************************
// �N���X
//**************************************************
class CRememberSystem : public CObject
{
public:
	explicit CRememberSystem(int nPriority = CTaskGroup::LEVEL_2D_1);
	~CRememberSystem();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CRememberSystem *Create();

private:
	enum TEXTURE
	{// �g�p���Ă���e�N�X�`��
		TEXTURE_WINTER = 0,
		TEXTURE_SUN_FLOWER,
		TEXTURE_MOUNTAIN,
		TEXTURE_GORYOKAKU,
		TEXTURE_GAME,
		TEXTURE_FLOWER_GARD,
		TEXTURE_DUCK,
		TEXTURE_DOG,
		TEXTURE_CLOUD,
		TEXTURE_CASTLE,
		TEXTURE_MAX
	};

private:
	// �I�u�W�F�N�g2D�̔�
	CRememberObject *m_pRememberObject[TEXTURE_MAX];

};


#endif	// _REMMBER_SYSTEM_H_