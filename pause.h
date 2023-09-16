//=========================================
// 
// �|�[�Y���N���X
// Author YudaKaito
// 
//=========================================
#ifndef _PAUSE_H_
#define _PAUSE_H_

#include "object2d.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CClickItem;

//-----------------------------------------
// ���j���[�N���X
//-----------------------------------------
class CPause : public CObject2D
{
public: // �񋓌^
public:	// �p�u���b�N�֐�
	CPause();
	~CPause();

	HRESULT Init();
	void Uninit();
	
	static CPause* Create();

private: // �v���C�x�[�g�֐�
private: // �����o�[�ϐ�
	CObject2D* m_bg;
	CClickItem* m_back;
	CClickItem* m_retry;
	CClickItem* m_end;
};
#endif // !_PAUSE_H_
