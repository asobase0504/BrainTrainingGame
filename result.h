//==================================================
// ���U���g��ʂ̐���
// Author: YudaKaito
//==================================================
#ifndef _RESULT_H_
#define _RESULT_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "mode.h"

//**************************************************
// �O���O���@���Ԃ�NG�@�|�C���^�����Ȃ�OK
//**************************************************
class CClickItem;

//**************************************************
// �N���X
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