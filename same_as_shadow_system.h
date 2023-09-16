//==================================================
// same_as_shadow_system.h
// Author: Buriya Kota
//==================================================
#ifndef _SAME_AS_SHADOW_SYSTEM_H_
#define _SAME_AS_SHADOW_SYSTEM_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object.h"

//**************************************************
// �O���O���@���Ԃ�NG�@�|�C���^�����Ȃ�OK
//**************************************************
class CObject2D;
class CRememberObject;

//**************************************************
// �N���X
//**************************************************
class CSameAsShadowSystem : public CObject
{
public:

public:
	explicit CSameAsShadowSystem(int nPriority = CTaskGroup::LEVEL_2D_1);
	~CSameAsShadowSystem();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CSameAsShadowSystem *Create();

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
	// �e�̃I�u�W�F�N�g
	std::vector <CRememberObject*> m_pShadowObject;
	// �I����
	std::vector <CRememberObject*> m_pSelectObject;

	// �e�N�X�`��
	std::string m_tex[TEXTURE_MAX];

};

#endif	// _SAME_AS_SHADOW_SYSTEM_H_