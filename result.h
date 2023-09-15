//==================================================
// ���U���g��ʂ̐���
// Author: YudaKaito
//==================================================
#ifndef _RESULT_H_
#define _RESULT_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object2D.h"

//**************************************************
// �O���O���@���Ԃ�NG�@�|�C���^�����Ȃ�OK
//**************************************************
class CClickItem;

//**************************************************
// �N���X
//**************************************************
class CResult : public CObject2D
{
public:
	explicit CResult();
	~CResult();

	HRESULT Init() override;
	void Update() override;

	static CResult *Create();

private:
	CClickItem* m_nextClickItem;
	CClickItem* m_retryClickItem;
	CClickItem* m_backClickItem;
};


#endif	// _NUMBER_H_