//==========================================
//
//  �o�����ɉ���(minigame_pressorder.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _PRESSORDER_H_
#define _PRESSORDER_H_
#include "mode.h"

//==========================================
//  �O���錾
//==========================================
class CTarget;

//==========================================
//  �N���X��`
//==========================================
class CMiniGamePressOrder : public CMode
{
public:

	//�����o�֐�
	CMiniGamePressOrder();
	~CMiniGamePressOrder() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	//�ÓI�����o�֐�
	static void Load(void); //�O���t�@�C���̓ǂݍ��ݏ���
	static void UnLoad(void); //�f�[�^�̔j��

private:

	//�ÓI�����o�֐�
	static CTarget *m_pTarget;

};

#endif
