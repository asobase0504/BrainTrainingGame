//==================================================
// largest_number.h
// Author: Buriya Kota
//==================================================
#ifndef _LARGEST_NUMBER_H_
#define _LARGEST_NUMBER_H_

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
class CLargestNumber : public CRememberObject
{
public:
	explicit CLargestNumber();
	~CLargestNumber();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CLargestNumber *Create(const D3DXVECTOR3& inPos, const D3DXVECTOR2& inSize);

	void SetIsLargest(bool inIsLargest) { m_isLargest = inIsLargest; }
	bool GetIsLargest() { return m_isLargest; }

private:
	bool m_isLargest;
};


#endif	// _REFLECTION_OBJECT_H_