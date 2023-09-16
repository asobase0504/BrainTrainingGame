//==================================================
// リザルト画面の生成
// Author: YudaKaito
//==================================================
#ifndef _CORRECTION_H_
#define _CORRECTION_H_

//**************************************************
// インクルード
//**************************************************
#include "object2D.h"

//**************************************************
// クラス
//**************************************************
class CCorrection : public CObject2D
{
public:
	explicit CCorrection();
	~CCorrection();

	HRESULT Init() override;
	void Update() override;

	static CCorrection *Create(bool isCorrect);

private:
	void SetCorrect(bool isCorrect);
private:
	bool m_isCorrect;

	int m_releaseTime;
};


#endif	// _NUMBER_H_