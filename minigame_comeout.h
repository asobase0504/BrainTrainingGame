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

};

#endif
