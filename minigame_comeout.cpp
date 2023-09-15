//==========================================
//
//  �o�����ɉ���(minigame_comeout.cpp)
//  Author : Tomoya Kanazaki
//
//==========================================
#include "minigame_comeout.h"
#include "debug_proc.h"
#include "application.h"
#include "target.h"

//==========================================
//  �R���X�g���N�^
//==========================================
CMiniGameComeOut::CMiniGameComeOut()
{
	m_pTarget = NULL;
	m_nNumData = 0;
}

//==========================================
//  �f�X�g���N�^
//==========================================
CMiniGameComeOut::~CMiniGameComeOut()
{

}

//==========================================
//  ����������
//==========================================
HRESULT CMiniGameComeOut::Init()
{
	//�f�[�^��ǂݍ���
	Load();

	return S_OK;
}

//==========================================
//  �I������
//==========================================
void CMiniGameComeOut::Uninit()
{
	//��������폜
	//if (m_pTarget != NULL)
	//{
	//	delete[] m_pTarget;
	//	m_pTarget = NULL;
	//}
}

//==========================================
//  �X�V����
//==========================================
void CMiniGameComeOut::Update()
{
	//�f�o�b�O�\��
	CDebugProc::Print("�o�����ɉ������[�h����[�[�[��\n");
	CDebugProc::Print("�o�����鐔 : %d\n", m_nNumData);
}

//==========================================
//  �`�揈��
//==========================================
void CMiniGameComeOut::Draw()
{

}

//==========================================
//  �ǂݍ��ݏ���
//==========================================
void CMiniGameComeOut::Load(void)
{
	//���[�J���ϐ��錾
	FILE *pFile; //�t�@�C����
	char aStr[256]; //�s�v�ȕ�����̋L�^�p
	int nEnd; //�I���t���O

	//�t�@�C����ǂݎ���p�ŊJ��
	pFile = fopen("data\\FILE\\ComeOut.txt", "r");

	//NULL�`�F�b�N
	if (pFile != NULL)
	{
		do
		{
			//�t�@�C�����當�����ǂݍ���
			nEnd = fscanf(pFile, "%s", &aStr[0]);

			//�f�[�^���̎擾
			if (strcmp(&aStr[0], "NUMDATA") == 0)
			{
				fscanf(pFile, "%s", &aStr[0]); // =
				fscanf(pFile, "%d", &m_nNumData); //�f�[�^��
			}

		} while (nEnd != EOF); //�ǂݍ��񂾕�����[ EOF ]�ł͂Ȃ��ꍇ���[�v

		//�t�@�C�������
		fclose(pFile);
	}
}
