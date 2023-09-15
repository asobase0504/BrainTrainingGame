//==========================================
//
//  �o�����ɉ���(minigame_comeout.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _MINIGAME_COMEOUT_H_
#define _MINIGAME_COMEOUT_H_
#include "mode.h"

//==========================================
//  �O���錾
//==========================================
class CTarget;

//==========================================
//  �N���X��`
//==========================================
class CMiniGameComeOut : public CMode
{
public:

	//�����o�֐�
	CMiniGameComeOut();
	~CMiniGameComeOut();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

private:

	//�����o�֐�
	void Load(void);

	//�����o�ϐ�
	CTarget *m_pTarget;
	int m_nNumData; //�o�Ă��鐔

};

#endif
