//==================================================
// number.h
// Author: Buriya Kota
//==================================================
#ifndef _NUMBER_H_
#define _NUMBER_H_

//**************************************************
// インクルード
//**************************************************
#include "object2D.h"

//**************************************************
// 前方前言　実態はNG　ポインタだけならOK
//**************************************************

//**************************************************
// 定数定義
//**************************************************

//**************************************************
// 構造体定義
//**************************************************

//**************************************************
// クラス
//**************************************************
class CNumber : public CObject2D
{
public:
	explicit CNumber();
	~CNumber();

	HRESULT Init() override;

	static CNumber *Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size);

private:

};


#endif	// _NUMBER_H_