//==========================================
//
//  �Z�[�u(save.cpp)
//  Author : Tomoya Kanazaki
//
//==========================================
#include "save.h"

//==========================================
//  �ÓI�����o�ϐ��錾
//==========================================
CMode::MODE_TYPE CSave::m_modeSave = CMode::MODE_TYPE::EXIT_SAVE;
int CSave::m_aScore[(int)CMode::MODE_TYPE::MAX] = {};
const char CSave::msc_sRankingPass[128] = "data\\FILE\\RankingData.bin";

//==========================================
//  �����o����̐ݒ�
//==========================================
void CSave::SaveMode(CMode::MODE_TYPE mode)
{
	m_modeSave = mode;
}

//==========================================
//  �X�R�A�������o��
//==========================================
void CSave::SaveScore(const int nScore)
{
	//���[�J���ϐ��錾
	FILE *pFile = NULL;

	//�o�C�i���[�t�@�C�����J��
	pFile = fopen(&msc_sRankingPass[0], "rb");

	if (pFile != NULL)
	{
		//�ǂݍ���
		fread(&m_aScore[0], sizeof(int), (int)CMode::MODE_TYPE::MAX, pFile);

		//�t�@�C�������
		fclose(pFile);
	}

	//�X�R�A��ۑ�
	if (m_aScore[(int)m_modeSave] < nScore)
	{
		//�X�R�A���㏑��
		m_aScore[(int)m_modeSave] = nScore;

		//�o�C�i���[�t�@�C�����J��
		pFile = fopen(&msc_sRankingPass[0], "wb");

		if (pFile != NULL)
		{
			//�����o��
			fwrite(&m_aScore[0], sizeof(int), (int)CMode::MODE_TYPE::MAX, pFile);

			//�t�@�C�������
			fclose(pFile);
		}
	}
}
