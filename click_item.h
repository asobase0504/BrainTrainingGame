//==================================================
// リザルト画面の生成
// Author: YudaKaito
//==================================================
#ifndef _CLICK_ITEM_H_
#define _CLICK_ITEM_H_

//**************************************************
// インクルード
//**************************************************
#include "object2D.h"
#include <functional>

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
class CClickItem : public CObject2D
{
public:
	explicit CClickItem();
	~CClickItem();

	HRESULT Init() override;
	void Update() override;

	virtual void ClickEvent() { m_event(); }

	bool IsClick() { return m_isClick; }

	void SetEvent(std::function<void(void)> infunc) { m_event = infunc; }
private:
	bool m_isClick;
	std::function<void(void)> m_event;
};
#endif	// _NUMBER_H_