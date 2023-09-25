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
	bool GetMiss(void) { return m_bMiss; } //�o�����鏇�Ԃ̐ݒ�

	//�ÓI�����o�ϐ��錾
	static void SetTime(int nTime) { m_nTime = nTime; }
	static int GetNext(void) { return m_nNext; }

private:

	enum TEXTURE
	{// �g�p���Ă���e�N�X�`��
		TEXTURE_ANIMAL1 = 0,
		TEXTURE_ANIMAL2,
		TEXTURE_ANIMAL3,
		TEXTURE_ANIMAL4,
		TEXTURE_ANIMAL5,
		TEXTURE_ANIMAL6,
		TEXTURE_ANIMAL7,
		TEXTURE_ANIMAL8,
		TEXTURE_ANIMAL9,
		TEXTURE_ANIMAL10,
		TEXTURE_ANIMAL11,
		TEXTURE_ANIMAL12,
		TEXTURE_ANIMAL13,
		TEXTURE_ANIMAL14,
		TEXTURE_ANIMAL15,
		TEXTURE_ANIMAL16,
		TEXTURE_ANIMAL17,
		TEXTURE_ANIMAL18,
		TEXTURE_ANIMAL19,
		TEXTURE_ANIMAL20,
		TEXTURE_ANIMAL21,
		TEXTURE_ANIMAL22,
		TEXTURE_ANIMAL23,
		TEXTURE_ANIMAL24,
		TEXTURE_ANIMAL25,
		TEXTURE_ANIMAL26,
		TEXTURE_ANIMAL27,
		TEXTURE_MAX
	};

	//�����o�ϐ�
	int m_nTiming; //�o�����鎞��
	int m_nIndex; //�o�����鏇��
	bool m_bClick; //�N���b�N���ꂽ�t���O
	bool m_bMiss; //�~�X

	// �e�N�X�`��
	std::string m_tex[TEXTURE_MAX];


	//�ÓI�����o�ϐ�
	static int m_nTime; //�o�ߎ���
	static int m_nNext; //���ɉ����C���f�b�N�X

};

#endif
