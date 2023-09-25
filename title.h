//=========================================
// 
// タイトル内クラス
// Author YudaKaito
// 
//=========================================
#ifndef _TITLE_H_
#define _TITLE_H_

#include "mode.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CMenu;
class CSaveGuidanceItem;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CTitle : public CMode
{
public:	// メンバー関数
	CTitle();
	~CTitle() override;

	HRESULT Init() override;
	void Update() override;

private: // 動的メンバー変数
};

#endif // !_TITLE_H_
