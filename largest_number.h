//==================================================
// largest_number.h
// Author: Buriya Kota
//==================================================
#ifndef _LARGEST_NUMBER_H_
#define _LARGEST_NUMBER_H_

//**************************************************
// インクルード
//**************************************************
#include "remember_object.h"

//**************************************************
// 前方前言　実態はNG　ポインタだけならOK
//**************************************************
class CSequence;

//**************************************************
// 定数定義
//**************************************************

//**************************************************
// 構造体定義
//**************************************************

//**************************************************
// クラス
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

	void SetIsLargest(bool inIsLargest) { m_isLargest = inIsLargest; }
	bool GetIsLargest() { return m_isLargest; }

	void SetSequence(int inSequence);

private:
	CSequence *m_pSequence;
	bool m_isLargest;
};


#endif	// _REFLECTION_OBJECT_H_