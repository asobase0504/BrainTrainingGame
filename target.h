//==========================================
//
//  �������(target.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _TARGET_H_
#define _TARGET_H_
#include "object2d.h"

//==========================================
//  �N���X��`
//==========================================
class CTarget : public CObject2D
{
public:

	//�����o�֐�
	CTarget();
	~CTarget();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void SetTiming(const int nTiming) { m_nTiming = nTiming; } //�o�����鎞�Ԃ̐ݒ�
	void SetIndex(const int nIndex) { m_nIndex = nIndex; } //�o�����鏇�Ԃ̐ݒ�

	//�ÓI�����o�ϐ��錾
	static void SetTime(int nTime) { m_nTime = nTime; }

private:

	//�����o�ϐ�
	int m_nTiming; //�o�����鎞��
	int m_nIndex; //�o�����鏇��

	//�ÓI�����o�ϐ�
	static int m_nTime; //�o�ߎ���

};

#endif
