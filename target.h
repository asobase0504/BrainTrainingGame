//==========================================
//
//  押すやつ(target.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _TARGET_H_
#define _TARGET_H_
#include "click_item.h"

//==========================================
//  クラス定義
//==========================================
class CTarget : public CClickItem
{
public:

	//メンバ関数
	CTarget();
	~CTarget();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void ClickEvent() {}

	void SetTiming(const int nTiming) { m_nTiming = nTiming; } //出現する時間の設定
	void SetIndex(const int nIndex) { m_nIndex = nIndex; } //出現する順番の設定

	//静的メンバ変数宣言
	static void SetTime(int nTime) { m_nTime = nTime; }
	static int GetNext(void) { return m_nNext; }

private:

	//メンバ変数
	int m_nTiming; //出現する時間
	int m_nIndex; //出現する順番
	bool m_bClick; //クリックされたフラグ

	//静的メンバ変数
	static int m_nTime; //経過時間
	static int m_nNext; //次に押すインデックス

};

#endif
