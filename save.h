//==========================================
//
//  �Z�[�u(save.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _SAVE_H_
#define _SAVE_H_
#include "mode.h"

//==========================================
//  �l�[���X�y�[�X��`
//==========================================
class CSave
{
public:

	//�ÓI�����o�֐�
	static void SaveMode(CMode::MODE_TYPE mode); //�����o�����ݒ�
	static void SaveScore(const int nScore); //�X�R�A�������o��

private:

	//�����o�ϐ�
	static CMode::MODE_TYPE m_modeSave;
	static int m_aScore[(int)CMode::MODE_TYPE::MAX];
	static const char msc_sRankingPass[128];

};

#endif
