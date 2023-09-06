//==================================================
// remember_object.h
// Author: Buriya Kota
//==================================================
#ifndef _REMMBER_OBJECT_H_
#define _REMMBER_OBJECT_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object2D.h"

//**************************************************
// �O���O���@���Ԃ�NG�@�|�C���^�����Ȃ�OK
//**************************************************

//**************************************************
// �萔��`
//**************************************************

//**************************************************
// �\���̒�`
//**************************************************

//**************************************************
// �N���X
//**************************************************
class CRememberObject : public CObject2D
{
private:
	enum TEXTURE
	{// �g�p���Ă���e�N�X�`��
		TEXTURE_0 = 0,
		TEXTURE_1,
		TEXTURE_2,
		TEXTURE_MAX
	};

public:
	explicit CRememberObject(int nPriority = CObjectList::LEVEL_2D_1);
	~CRememberObject();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override {}

	static CRememberObject *Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, TEXTURE tex);

private:
	// �I�u�W�F�N�g2D�̔�
	CObject2D *m_pObject2D[TEXTURE_MAX];

};


#endif	// _REMMBER_OBJECT_H_