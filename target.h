//==========================================
//
//  押すやつ(target.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _TARGET_H_
#define _TARGET_H_
#include "object2d.h"

//==========================================
//  クラス定義
//==========================================
class CTarget : CObject2D
{
public:

	//メンバ関数
	CTarget();
	~CTarget();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	//静的メンバ関数
	static CTarget *Create(D3DXVECTOR3 pos, int nID);

private:

	//メンバ変数
	int m_nID;

};

#endif
