//=========================================
// 
// 遊ぶモードを選択するシーンクラス
// Author YudaKaito
// 
//=========================================
#ifndef _SELECT_MODE_H_
#define _SELECT_MODE_H_

#include "mode.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CModeGuidanceItem;
class CSequence;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CSelectMode : public CMode
{
public:	// メンバー関数
	CSelectMode();
	~CSelectMode() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

private: // 動的メンバー変数
	std::vector<CModeGuidanceItem*> m_itemModeGuidance;

	CSequence *m_pHiScore[4]; //ハイスコアの表示

};

#endif // !_TITLE_H_
