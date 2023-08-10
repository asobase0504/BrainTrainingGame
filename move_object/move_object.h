//=========================================
// 
// �����Ă镨�̃N���X
// Author YudaKaito
// 
//=========================================
#ifndef _MOVE_OBJECT_H_
#define _MOVE_OBJECT_H_

#include "../object2d.h"
#include "../minigame_moveobject.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CMoveObject : public CObject2D
{
private: // �񋓌^

public:	// �����o�[�֐�
	CMoveObject();
	virtual ~CMoveObject() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;

	// �X�V����
	virtual void Update() override;

	static CMoveObject* Create(CMiniGameMoveObject::ELevel* level, const int index, const D3DXVECTOR3& inPos);

	int ClikEvent() { return m_textureIndex; }

private: // ���I�v���C�x�[�g�֐�

private: // ���I�����o�[�ϐ�
	CMiniGameMoveObject::ELevel* m_level;
	int m_textureIndex;	// �����ڂ̔ԍ�
	D3DXVECTOR3 m_move;
};

#endif // !_GAME_H_
