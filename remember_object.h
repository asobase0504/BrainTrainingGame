//==================================================
// remember_system.h
// Author: Buriya Kota
//==================================================
#ifndef _REMMBER_OBJECT_H_
#define _REMMBER_OBJECT_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "click_item.h"

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
class CRememberObject : public CClickItem
{
public:
	explicit CRememberObject();
	~CRememberObject();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CRememberObject *Create(const D3DXVECTOR3& inPos, const D3DXVECTOR2& inSize, int inMyNumber);

	void SetMyNumber(int inMyNumber) { m_myNumber = inMyNumber; }
	int GetMyNumber() { return m_myNumber; }

private:
	// �����̔ԍ�
	int m_myNumber;
};


#endif	// _REMMBER_OBJECT_H_