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
	bool GetMiss(void) { return m_bMiss; } //出現する順番の設定

	//静的メンバ変数宣言
	static void SetTime(int nTime) { m_nTime = nTime; }
	static int GetNext(void) { return m_nNext; }

private:

	enum TEXTURE
	{// 使用しているテクスチャ
		TEXTURE_ANIMAL1 = 0,
		TEXTURE_ANIMAL2,
		TEXTURE_ANIMAL3,
		TEXTURE_ANIMAL4,
		TEXTURE_ANIMAL5,
		TEXTURE_ANIMAL6,
		TEXTURE_ANIMAL7,
		TEXTURE_ANIMAL8,
		TEXTURE_ANIMAL9,
		TEXTURE_ANIMAL10,
		TEXTURE_ANIMAL11,
		TEXTURE_ANIMAL12,
		TEXTURE_ANIMAL13,
		TEXTURE_ANIMAL14,
		TEXTURE_ANIMAL15,
		TEXTURE_ANIMAL16,
		TEXTURE_ANIMAL17,
		TEXTURE_ANIMAL18,
		TEXTURE_ANIMAL19,
		TEXTURE_ANIMAL20,
		TEXTURE_ANIMAL21,
		TEXTURE_ANIMAL22,
		TEXTURE_ANIMAL23,
		TEXTURE_ANIMAL24,
		TEXTURE_ANIMAL25,
		TEXTURE_ANIMAL26,
		TEXTURE_ANIMAL27,
		TEXTURE_MAX
	};

	//メンバ変数
	int m_nTiming; //出現する時間
	int m_nIndex; //出現する順番
	bool m_bClick; //クリックされたフラグ
	bool m_bMiss; //ミス

	// テクスチャ
	std::string m_tex[TEXTURE_MAX];


	//静的メンバ変数
	static int m_nTime; //経過時間
	static int m_nNext; //次に押すインデックス

};

#endif
