//==================================================
// ���U���g��ʂ̐���
// Author: YudaKaito
//==================================================
#ifndef _CORRECTION_H_
#define _CORRECTION_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object2D.h"

//**************************************************
// �N���X
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