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
	HRESULT Init(const D3DXVECTOR3& inPos, const D3DXVECTOR2& inSize);
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CLargestNumber *Create(const D3DXVECTOR3& inPos, const D3DXVECTOR2& inSize);

	void SetIsMax(bool inIsMax) { m_isMax = inIsMax; }
	bool GetIsMax() { return m_isMax; }

	void SetIsMin(bool inIsMin) { m_isMin = inIsMin; }
	bool GetIsMin() { return m_isMin; }

	void SetSequence(int inSequence);

	void SetColorAlpha(const float& inAlpha);

	void Reset();

private:
	CSequence *m_pSequence;
	bool m_isMax;
	bool m_isMin;
	D3DXVECTOR2 m_space;
};


#endif	// _REFLECTION_OBJECT_H_