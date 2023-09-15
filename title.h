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

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CTitle : public CMode
{
public: // �񋓌^
public:	// �����o�[�֐�
	CTitle();
	~CTitle() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

private: // ���I�����o�[�ϐ�
	MODE_TYPE m_status;
};

#endif // !_TITLE_H_
