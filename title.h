//=========================================
// 
// �^�C�g�����N���X
// Author YudaKaito
// 
//=========================================
#ifndef _TITLE_H_
#define _TITLE_H_

#include "mode.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CMenu;
class CSaveGuidanceItem;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CTitle : public CMode
{
public:	// �����o�[�֐�
	CTitle();
	~CTitle() override;

	HRESULT Init() override;
	void Update() override;

private: // ���I�����o�[�ϐ�
};

#endif // !_TITLE_H_
