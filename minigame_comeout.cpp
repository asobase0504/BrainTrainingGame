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
	m_pUse = NULL;
	m_pPos = NULL;
	m_nNumData = 0;
	m_nInterval = 0;
	m_nTime = 0;
	m_nPopTime = 0;
	m_nSpeed = 0;
	m_nNext = 0;

	m_correct = 0;
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
	CGame::Init();

	{
		CObject2D* object = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
		object->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y - 300.0f, 0.0f));
		D3DXVECTOR2 size(1292.0f * 0.4f, 252.0f * 0.4f);
		object->SetSize(size);
		object->SetTexture("TEXT_EXPO_COMEOUT");
	}


	//�o�ߎ��Ԃ����Z�b�g
	m_nTime = 0;
	m_nSpeed = 0;
	m_bClick = false;

	//�f�[�^��ǂݍ���
	Load();

	return S_OK;
}

//==========================================
//  �I������
//==========================================
void CMiniGameComeOut::Uninit()
{
	CGame::Uninit();
	if (m_pUse != NULL)
	{
		delete[] m_pUse;
		m_pUse = NULL;
	}
	if (m_pPos != NULL)
	{
		delete[] m_pPos;
		m_pPos = NULL;
	}
}

//==========================================
//  �X�V����
//==========================================
void CMiniGameComeOut::Update()
{
	CGame::Update();

	if (GetState() == COUNT_DOWN)
	{
		return;
	}

	//�o�ߎ��Ԃ��X�V
	m_nTime++;
	CTarget::SetTime(m_nTime);

	//�N���b�N���\�ɂȂ鎞��
	if (!m_bClick)
	{
		if (m_nTime >= m_nPopTime)
		{
			m_BG->SetColor(D3DXCOLOR(0.4f, 0.85f, 0.4f, 1.0f));
			m_bClick = true;
		}
	}

	// ����
	if (CTarget::GetNext() == m_nNumData)
	{
		m_correct++;
		if (m_correct >= m_nextNeedCorrect)
		{
			m_correct = 0;
			LevelUp();
		}
		Reset();
	}
	
	// ���s
	bool bMiss = false;
	for (int nCnt = 0; nCnt < m_nNumData; nCnt++)
	{
		bMiss = m_pTarget[nCnt]->GetMiss();
		if (bMiss)
		{
			m_correct--;
			if (m_correct < 0)
			{
				LevelDown();
			}

			Reset();
			break;
		}
	}

	//�O��̃^�[�Q�b�g����X�V����Ă�����X�R�A�����Z
	int nNext = CTarget::GetNext(); //����̃^�[�Q�b�g
	if (m_nNext != nNext && !bMiss)
	{
		AddScore(3 * (m_nNext + 1));
	}

	//���̃^�[�Q�b�g��ۑ�
	m_nNext = nNext;
}

//==========================================
//  �`�揈��
//==========================================
void CMiniGameComeOut::Draw()
{

}

void CMiniGameComeOut::GameStart()
{
	CGame::GameStart();

	m_BG = CObject2D::Create(CTaskGroup::EPriority::LEVEL_2D_BG);
	m_BG->SetPos(D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f));
	m_BG->SetSize(D3DXVECTOR2(CApplication::CENTER_Y * 1.1f, CApplication::CENTER_Y * 1.1f));
	m_BG->SetTexture("BLOCK_BG");

	//��ʂ̒��S���擾����
	m_pos = D3DXVECTOR3(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f);

	//�|���S������ݒ�
	m_nNumData = (int)(m_alignment.x * m_alignment.y);

	Set();
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

//==========================================
//  �ݒ�
//==========================================
void CMiniGameComeOut::Set(void)
{
	m_BG->SetColor(D3DXCOLOR(0.9f, 0.7f, 0.0f, 1.0f));

	int nowLevel = GetLevel();

	switch (nowLevel)
	{
	case 1:
		m_nNumData = 2;
		m_alignment.x = 2;
		m_alignment.y = 1;
		m_size = D3DXVECTOR2(120.0f, 120.0f);
		m_nextNeedCorrect = 1;
		break;
	case 2:
		m_nNumData = 4;
		m_alignment.x = 2;
		m_alignment.y = 2;
		m_size = D3DXVECTOR2(120.0f, 120.0f);
		m_nextNeedCorrect = 2;
		break;
	case 3:
		m_nNumData = 6;
		m_alignment.x = 3;
		m_alignment.y = 2;
		m_size = D3DXVECTOR2(80.0f, 80.0f);
		m_nextNeedCorrect = 4;
		break;
	case 4:
		m_nNumData = 9;
		m_alignment.x = 3;
		m_alignment.y = 3;
		m_size = D3DXVECTOR2(80.0f, 80.0f);
		m_nextNeedCorrect = 6;
		break;
	case 5:
		m_nNumData = 12;
		m_alignment.x = 4;
		m_alignment.y = 3;
		m_size = D3DXVECTOR2(20.0f, 20.0f);
		break;
	default:
		break;
	}

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
		D3DXVECTOR2 space = D3DXVECTOR2(m_size.x + m_size.x * 0.45f, m_size.y + m_size.y * 0.45f);

		//���W���v�Z
		for (int nCntU = 0; nCntU < m_alignment.x; nCntU++)
		{
			for (int nCntV = 0; nCntV < m_alignment.y; nCntV++)
			{
				m_pPos[nCntU + (nCntV * (int)m_alignment.x)] = D3DXVECTOR3
				(
					m_pos.x - (space.x * m_alignment.x) * 0.5f + (space.x * 0.5f + space.x * nCntU),
					m_pos.y - (space.y * m_alignment.y) * 0.5f + (space.y * 0.5f + space.y * nCntV),
					0.0f
				);
			}
		}
	}

	m_pTarget.resize(m_nNumData);
	//�^�[�Q�b�g�𐶐�������
	for (int nCnt = 0; nCnt < m_nNumData; nCnt++)
	{
		m_pTarget[nCnt] = new CTarget;
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

				break;
			}
		}

		//�傫���̐ݒ�
		m_pTarget[nCnt]->SetSize(m_size);

		//���W�̐ݒ�
		m_pTarget[nCnt]->SetPos(m_pPos[nCnt]);
	}

	m_nPopTime = m_nInterval * m_nNumData + 5;
}

//==========================================
//  �Đݒ�
//==========================================
void CMiniGameComeOut::Reset(void)
{
	if (m_pUse != nullptr)
	{
		delete[] m_pUse;
		m_pUse = nullptr;
	}
	if (m_pPos != nullptr)
	{
		delete[] m_pPos;
		m_pPos = nullptr;
	}
	for (int nCnt = 0; nCnt < m_nNumData; nCnt++)
	{
		m_pTarget[nCnt]->UninitReset();
		m_pTarget[nCnt] = nullptr;
	}
	m_pTarget.clear();

	m_nTime = 0;
	CTarget::SetTime(m_nTime);
	m_nSpeed = 0;
	m_bClick = false;
	Set();
}
