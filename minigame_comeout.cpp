//==========================================
//
//  �o�����ɉ���(minigame_comeout.cpp)
//  Author : Tomoya Kanazaki
//
//==========================================
#include "minigame_comeout.h"
#include "input.h"
#include "debug_proc.h"
#include "application.h"
#include "target.h"

//==========================================
//  �ÓI�����o�ϐ��錾
//==========================================
bool CMiniGameComeOut::m_bClick = false;

//==========================================
//  �R���X�g���N�^
//==========================================
CMiniGameComeOut::CMiniGameComeOut()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_size = D3DXVECTOR2(0.0f, 0.0f);
	m_alignment = D3DXVECTOR2(0.0f, 0.0f);
	m_pPos = NULL;
	m_nNumData = 0;
	m_nInterval = 0;
	m_nTime = 0;
	m_nPopTime = 0;
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
	//�o�ߎ��Ԃ����Z�b�g
	m_nTime = 0;
	m_bClick = false;

	//�f�[�^��ǂݍ���
	Load();

	//��ʂ̒��S���擾����
	m_pos = D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f);

	//�|���S������ݒ�
	m_nNumData = (int)(m_alignment.x * m_alignment.y);

	//�|���S�������̃��������m��
	m_pUse = new bool[m_nNumData];
	for (int nCnt = 0; nCnt < m_nNumData; nCnt++)
	{
		m_pUse[nCnt] = false;
	}

	//���W��ݒ�
	if (m_pPos == NULL)
	{
		//���������m��
		m_pPos = new D3DXVECTOR3[m_nNumData];

		//�|���S�����m�̊Ԋu���Z�o
		D3DXVECTOR2 space = D3DXVECTOR2(m_size.x + m_size.x * 0.2f, m_size.y + m_size.y * 0.2f);

		//���W���v�Z
		for (int nCntU = 0; nCntU < m_alignment.x; nCntU++)
		{
			for (int nCntV = 0; nCntV < m_alignment.y; nCntV++)
			{
				m_pPos[nCntU + (nCntV * (int)m_alignment.x)] = D3DXVECTOR3
				(
					m_pos.x - (space.x * m_alignment.x) * 0.5f + (space.x * 0.5f + space.x * nCntU),
					m_pos.y - (space.x * m_alignment.x) * 0.5f + (space.y * 0.5f + space.y * nCntV),
					0.0f
				);
			}
		}
	}

	//�^�[�Q�b�g�𐶐�������
	for (int nCnt = 0; nCnt < m_nNumData; nCnt++)
	{
		//����,������
		m_pTarget.push_back(new CTarget);
		m_pTarget[nCnt]->Init();

		//�����^�C�~���O�̐ݒ�
		while (1)
		{
			//�������̗������擾
			int nIndex = rand() % m_nNumData;

			//�C���f�b�N�X���g�p����Ă��Ȃ��ꍇ
			if (!m_pUse[nIndex])
			{
				m_pTarget[nCnt]->SetTiming(m_nInterval * (nIndex + 1));
				m_pTarget[nCnt]->SetIndex(nIndex);
				m_pUse[nIndex] = true;

				if (m_nPopTime < m_nInterval * (nIndex + 1))
				{
					m_nPopTime = m_nInterval * (nIndex + 1);
				}
				break;
			}
		}

		//�傫���̐ݒ�
		m_pTarget[nCnt]->SetSize(m_size);

		//���W�̐ݒ�
		m_pTarget[nCnt]->SetPos(m_pPos[nCnt]);
	}

	return S_OK;
}

//==========================================
//  �I������
//==========================================
void CMiniGameComeOut::Uninit()
{
	delete[] m_pUse;
	m_pUse = NULL;
	delete[] m_pPos;
	m_pPos = NULL;
}

//==========================================
//  �X�V����
//==========================================
void CMiniGameComeOut::Update()
{
	//�o�ߎ��Ԃ��X�V
	m_nTime++;
	CTarget::SetTime(m_nTime);

	//�N���b�N���\�ɂȂ鎞��
	if (!m_bClick)
	{
		if (m_nTime >= m_nPopTime)
		{
			m_bClick = true;
		}
	}

	//�N���A�t���O
	if (CTarget::GetNext() == m_nNumData)
	{
		CDebugProc::Print("�N���A\n");
	}

	//�f�o�b�O�\��
	CDebugProc::Print("�o�����ɉ������[�h\n");
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

			//�o���Ԋu�̎擾
			if (strcmp(&aStr[0], "INTERVAL") == 0)
			{
				fscanf(pFile, "%d", &m_nInterval); //�����Ԋu
			}

			//�|���S���T�C�Y�̎擾
			if (strcmp(&aStr[0], "SIZE") == 0)
			{
				fscanf(pFile, "%f", &m_size.x); //����
				fscanf(pFile, "%f", &m_size.y); //�c��
			}

			//�������̎擾
			if (strcmp(&aStr[0], "ALIGNMENT") == 0)
			{
				fscanf(pFile, "%f", &m_alignment.x); //��������
				fscanf(pFile, "%f", &m_alignment.y); //�c������
			}

		} while (nEnd != EOF); //�ǂݍ��񂾕�����[ EOF ]�ł͂Ȃ��ꍇ���[�v

		//�t�@�C�������
		fclose(pFile);
	}
}
