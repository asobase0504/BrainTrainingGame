//==================================================
// reflection_object.h
// Author: Buriya Kota
//==================================================
#ifndef _REFLECTION_OBJECT_H_
#define _REFLECTION_OBJECT_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "remember_object.h"

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
class CReflectionObject : public CRememberObject
{
public:
	static const float SPEED;
	static const float X_MIN;
	static const float X_MAX;
	static const float Y_MIN;
	static const float Y_MAX;

public:
	explicit CReflectionObject();
	~CReflectionObject();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void Reset();

	static CReflectionObject *Create(const D3DXVECTOR3& inPos, const D3DXVECTOR2& inSize, int inMyNumber);

private:
	void Reflection_();
	void Rotate_();

private:
	float m_rotY;
	float m_spead;
};


#endif	// _REFLECTION_OBJECT_H_