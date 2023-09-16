//=========================================
// 
// ポーズ中クラス
// Author YudaKaito
// 
//=========================================
#ifndef _PAUSE_H_
#define _PAUSE_H_

#include "object2d.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CClickItem;

//-----------------------------------------
// メニュークラス
//-----------------------------------------
class CPause : public CObject2D
{
public: // 列挙型
public:	// パブリック関数
	CPause();
	~CPause();

	HRESULT Init();
	void Uninit();
	
	static CPause* Create();

private: // プライベート関数
private: // メンバー変数
	CObject2D* m_bg;
	CClickItem* m_back;
	CClickItem* m_retry;
	CClickItem* m_end;
};
#endif // !_PAUSE_H_
