//=========================================
// 
// �V�ԃ��[�h��I������V�[���N���X
// Author YudaKaito
// 
//=========================================
#ifndef _SELECT_MODE_H_
#define _SELECT_MODE_H_

#include "mode.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CModeGuidanceItem;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CSelectMode : public CMode
{
public:	// �����o�[�֐�
	CSelectMode();
	~CSelectMode() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

private: // ���I�����o�[�ϐ�
	std::vector<CModeGuidanceItem*> m_itemModeGuidance;
};

#endif // !_TITLE_H_
