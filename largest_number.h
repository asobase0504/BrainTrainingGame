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
class CSequence;

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
	HRESULT Init(const D3DXVECTOR3& inPos);
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CLargestNumber *Create(const D3DXVECTOR3& inPos, const D3DXVECTOR2& inSize);

	void SetIsMax(bool inIsMax) { m_isMax = inIsMax; }
	bool GetIsMax() { return m_isMax; }

	void SetIsMin(bool inIsMin) { m_isMin = inIsMin; }
	bool GetIsMin() { return m_isMin; }

	void SetSequence(int inSequence);

private:
	CSequence *m_pSequence;
	bool m_isMax;
	bool m_isMin;
};


#endif	// _REFLECTION_OBJECT_H_