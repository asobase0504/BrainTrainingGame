//==========================================
//
//  �������(target.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _TARGET_H_
#define _TARGET_H_
#include "click_item.h"

//==========================================
//  �N���X��`
//==========================================
class CTarget : public CClickItem
{
public:

	//�����o�֐�
	CTarget();
	~CTarget();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void ClickEvent() {}

	void SetTiming(const int nTiming) { m_nTiming = nTiming; } //�o�����鎞�Ԃ̐ݒ�
	void SetIndex(const int nIndex) { m_nIndex = nIndex; } //�o�����鏇�Ԃ̐ݒ�

	//�ÓI�����o�ϐ��錾
	static void SetTime(int nTime) { m_nTime = nTime; }
	static int GetNext(void) { return m_nNext; }

private:

	//�����o�ϐ�
	int m_nTiming; //�o�����鎞��
	int m_nIndex; //�o�����鏇��
	bool m_bClick; //�N���b�N���ꂽ�t���O

	//�ÓI�����o�ϐ�
	static int m_nTime; //�o�ߎ���
	static int m_nNext; //���ɉ����C���f�b�N�X

};

#endif
