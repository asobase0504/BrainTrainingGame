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
class CTarget : public CObject2D
{
public:

	//メンバ関数
	CTarget();
	~CTarget();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void SetTiming(const int nTiming) { m_nTiming = nTiming; } //出現する時間の設定
	void SetIndex(const int nIndex) { m_nIndex = nIndex; } //出現する順番の設定

	//静的メンバ変数宣言
	static void SetTime(int nTime) { m_nTime = nTime; }

private:

	//メンバ変数
	int m_nTiming; //出現する時間
	int m_nIndex; //出現する順番

	//静的メンバ変数
	static int m_nTime; //経過時間

};

#endif
