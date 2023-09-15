//=========================================
// 
// タイトル内クラス
// Author YudaKaito
// 
//=========================================
#ifndef _SELECT_SAVE_H_
#define _SELECT_SAVE_H_

#include "mode.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CSaveGuidanceItem;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CSelectSave : public CMode
{
public:	// メンバー関数
	CSelectSave();
	~CSelectSave() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

private: // 動的メンバー変数
	std::vector<CSaveGuidanceItem*> m_itemSaveGuidance;

	bool m_isSelectSaveData;	// セーブデータが選択済みか否か
};

#endif // !_TITLE_H_
