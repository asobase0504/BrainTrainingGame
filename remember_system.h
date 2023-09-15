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
class CRememberObject;

//**************************************************
// �N���X
//**************************************************
class CRememberSystem : public CObject
{
public:
	static const int X_LINE = 2;
	static const int Y_LINE = 2;
	static const int MAX_ANSWER = X_LINE + Y_LINE;
public:
	explicit CRememberSystem(int nPriority = CTaskGroup::LEVEL_2D_1);
	~CRememberSystem();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CRememberSystem *Create();

private:
	void Touch_(float nPosX, float nPosY);
	void DisplayRemember_();
	void Choices_();

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
	// �o�������
	CRememberObject *m_pRememberObject;
	// �A���T�[
	CRememberObject *m_pAnswerObject[MAX_ANSWER];
	// �e�N�X�`��
	std::string m_tex[TEXTURE_MAX];
	// ����
	int m_nAnswer;
};

#endif	// _REMMBER_SYSTEM_H_