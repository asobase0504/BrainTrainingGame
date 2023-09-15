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

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CTitle : public CMode
{
public: // 列挙型
public:	// メンバー関数
	CTitle();
	~CTitle() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

private: // 動的メンバー変数
	MODE_TYPE m_status;
};

#endif // !_TITLE_H_
