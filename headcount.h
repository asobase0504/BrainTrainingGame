//==========================================
//
//  �l���Ǘ��N���X(headcount.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _HEADCOUNT_H_
#define _HEADCOUNT_H_

//==========================================
//  �N���X��`
//==========================================
class CHeadCount
{
public:
	CHeadCount(); //�R���X�g���N�^
	~CHeadCount(); //�f�X�g���N�^

	//�����o�֐�
	void Init(void); //����������
	void Uninit(void); //�I������
	int Add(void); //�l�����Z����
	int Sab(void); //�l�����Z����
	int GetNum(void) { return m_nHeadCount; } //�l���擾����

	//�ÓI�����o�֐�
	static CHeadCount *Create(void); //��������
	static void Load(void); //�O���t�@�C���̓ǂݍ���

private:

	//�O���t�@�C�����ۑ��p�̍\����
	struct FileData
	{
		int nDefMax; //�����l�̍ő�l
		int nDefMin; //�����l�̍ŏ��l
		int nAddMax; //���Z�����l�̍ő�l
		int nAddMin; //���Z�����l�̍ŏ��l
		int nSabMax; //���Z�����l�̍ő�l
		int nSabMin; //���Z�����l�̍ŏ��l
	};

	//�����o�ϐ�
	int m_nHeadCount; //���݂̐l��
	int m_nOldHeadCount; //�O��̐l��

	//�ÓI�����o�ϐ�
	static FileData ms_FileData; //�O���t�@�C������ǂݍ��񂾏��
	static const char msc_sDebugPass[128]; //�ǂݍ��ރt�@�C���̃p�X
	static const char msc_sReleaseFile[128]; //�ǂݍ��ރt�@�C���̃p�X

};

#endif
