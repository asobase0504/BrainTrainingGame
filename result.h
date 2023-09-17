//==================================================
// リザルト画面の生成
// Author: YudaKaito
//==================================================
#ifndef _RESULT_H_
#define _RESULT_H_

//**************************************************
// インクルード
//**************************************************
#include "mode.h"

//**************************************************
// 前方前言　実態はNG　ポインタだけならOK
//**************************************************
class CClickItem;

//**************************************************
// クラス
//**************************************************
class CResult : public CMode
{
public:
	explicit CResult();
	~CResult() override;

	HRESULT Init() override;
	void Update() override;

	static CResult *Create();

	static void SetPlayMode(const CMode::MODE_TYPE& inMode) { m_playMode = inMode; }

private:
	CClickItem* m_nextClickItem;
	CClickItem* m_retryClickItem;
	CClickItem* m_backClickItem;

	static CMode::MODE_TYPE m_playMode;
};


#endif	// _NUMBER_H_