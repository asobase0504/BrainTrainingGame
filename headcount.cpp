//==========================================
//
//  �l���Ǘ��N���X(headcount.cpp)
//  Author : Tomoya Kanazaki
//
//==========================================
#include "headcount.h"
#include <stdio.h>
#include <d3dx9.h>
#include "error_warning.h"

//==========================================
//  �ÓI�����o�ϐ��錾
//==========================================
CHeadCount::FileData CHeadCount::ms_FileData = { 0, 0, 0, 0, 0, 0 };
const char CHeadCount::msc_sDebugPass[128] = "data\\LevelData.txt"; //�f�o�b�O�p�̃e�L�X�g�t�@�C��
const char CHeadCount::msc_sReleaseFile[128] = "data\\LevelData.bin"; //�����[�X�p�̃o�C�i���[�t�@�C��

//==========================================
//  �R���X�g���N�^
//==========================================
CHeadCount::CHeadCount()
{
	m_nHeadCount = 0;
}

//==========================================
//  �f�X�g���N�^
//==========================================
CHeadCount::~CHeadCount()
{

}

//==========================================
//  ����������
//==========================================
void CHeadCount::Init(void)
{
	//�����l��ݒ肷��
	m_nHeadCount = (rand() % ms_FileData.nDefMax) + ms_FileData.nDefMin;
}

//==========================================
//  �I������
//==========================================
void CHeadCount::Uninit(void)
{
	//���g�̃��������J������
	delete this;
}

//==========================================
//  �l�����Z����
//==========================================
int CHeadCount::Add(void)
{
	//���Z����l�������߂�
	int nAddNum = (rand() % ms_FileData.nAddMax) + ms_FileData.nAddMin;

	//���Z�O�̐l����ۑ�����
	m_nOldHeadCount = m_nHeadCount;

	//�l�������Z����
	m_nHeadCount += nAddNum;

	//���Z�����l��Ԃ�
	return nAddNum;
}

//==========================================
//  �l�����Z����
//==========================================
int CHeadCount::Sab(void)
{
	//���[�J���ϐ��錾
	int nSabNum = 0;

	if (m_nHeadCount <= 0) //����ȏ㌸��Ȃ�
	{
		while (1)//�������[�v
		{
			//���Z����l�������߂�
			nSabNum = (rand() % ms_FileData.nSabMax) + ms_FileData.nSabMin;

			//���ɑ��݂��Ă���l����菭�Ȃ��ꍇ�����o��
			if (m_nOldHeadCount >= nSabNum)
			{
				break;
			}
		}

		//�l�������Z����
		m_nHeadCount -= nSabNum;
	}

	//���Z�����l��Ԃ�
	return nSabNum;
}

//==========================================
//  ��������
//==========================================
CHeadCount *CHeadCount::Create(void)
{
	//���[�J���ϐ��錾
	CHeadCount *pHeadCount = NULL;

	//���������m��
	pHeadCount = new CHeadCount;

	//������
	pHeadCount->Init();

	//�ϐ���Ԃ�
	return pHeadCount;
}

//==========================================
//  �ǂݍ��ݏ���
//==========================================
void CHeadCount::Load(void)
{
	//���[�J���ϐ��錾
	FILE *pFile = NULL;

#ifdef _DEBUG //�f�o�b�O�r���h���̏���

	//��������擾����ϐ�
	char aString[128];

	//�e�L�X�g�t�@�C�����J��
	pFile = fopen(&msc_sDebugPass[0], "r");

	if (pFile != NULL)
	{
		//�I������p�ϐ�
		int nEnd = 0;

		//�ǂݍ��݃��[�v
		do
		{
			//�t�@�C�����當�����ǂݍ���
			nEnd = fscanf(pFile, "%s", &aString[0]);

			//�ǂݍ��܂ꂽ�����񂩂番��
			if (strcmp(&aString[0], "DefMax") == 0)
			{
				fscanf(pFile, "%s", &aString[0]); // =
				fscanf(pFile, "%d", &ms_FileData.nDefMax); //�����l�̍ő�l���擾
			}
			if (strcmp(&aString[0], "DefMin") == 0)
			{
				fscanf(pFile, "%s", &aString[0]); // =
				fscanf(pFile, "%d", &ms_FileData.nDefMin); //�����l�̍ŏ��l���擾
			}
			if (strcmp(&aString[0], "AddMax") == 0)
			{
				fscanf(pFile, "%s", &aString[0]); // =
				fscanf(pFile, "%d", &ms_FileData.nAddMax); //���Z�����l�̍ő�l���擾
			}
			if (strcmp(&aString[0], "AddMin") == 0)
			{
				fscanf(pFile, "%s", &aString[0]); // =
				fscanf(pFile, "%d", &ms_FileData.nAddMin); //���Z�����l�̍ŏ��l���擾
			}
			if (strcmp(&aString[0], "SadMax") == 0)
			{
				fscanf(pFile, "%s", &aString[0]); // =
				fscanf(pFile, "%d", &ms_FileData.nSabMax); //���Z�����l�̍ő�l���擾
			}
			if (strcmp(&aString[0], "SadMin") == 0)
			{
				fscanf(pFile, "%s", &aString[0]); // =
				fscanf(pFile, "%d", &ms_FileData.nSabMin); //���Z�����l�̍ŏ��l���擾
			}

		} while (nEnd != EOF); //�ǂݍ��񂾕�����[ EOF ]�ł͂Ȃ��ꍇ���[�v

		// �t�@�C�������
		fclose(pFile);

		//�o�C�i���[�t�@�C�����J��
		pFile = fopen(&msc_sReleaseFile[0], "wb");

		if (pFile != NULL)
		{
			//�����o��
			fwrite(&ms_FileData, sizeof(FileData), 1, pFile);

			//�t�@�C�������
			fclose(pFile);
		}
		else
		{
			//�G���[�\��
			ErrorWarningStatement();
		}
	}
	else
	{
		//�G���[�\��
		ErrorWarningStatement();
	}

#else //�����[�X�r���h���̏���

	//�o�C�i���[�t�@�C�����J��
	pFile = fopen(&msc_sReleaseFile[0], "rb");

	if (pFile != NULL)
	{
		//�ǂݍ���
		fread(&ms_FileData, sizeof(FileData), 1, pFile);

		//�t�@�C�������
		fclose(pFile);
	}
	else
	{
		//�G���[�\��
		ErrorWarningStatement();
	}

#endif

}
