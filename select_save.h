//=========================================
// 
// �^�C�g�����N���X
// Author YudaKaito
// 
//=========================================
#ifndef _SELECT_SAVE_H_
#define _SELECT_SAVE_H_

#include "mode.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CSaveGuidanceItem;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CSelectSave : public CMode
{
public:	// �����o�[�֐�
	CSelectSave();
	~CSelectSave() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

private: // ���I�����o�[�ϐ�
	std::vector<CSaveGuidanceItem*> m_itemSaveGuidance;

	bool m_isSelectSaveData;	// �Z�[�u�f�[�^���I���ς݂��ۂ�
};

#endif // !_TITLE_H_
