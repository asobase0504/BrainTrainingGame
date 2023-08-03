//=============================================================================
// 
// �A�v���P�[�V�����N���X
// Author BuriyaKota
// 
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "minigame_number25.h"

#include "object2d.h"

//-----------------------------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------------------------
CMiniGameNumber25::CMiniGameNumber25()
{
	for (int i = 0; i < 25; i++)
	{
		m_pObject2D[i] = nullptr;
	}

	// �Q�[���J�n����
	m_dwGameStartTime = 0;
	// �Q�[���o�ߎ���
	m_dwGameTime = 0;

	// �I���t���O
	m_isEndGame = false;
	// ���Ƀ^�b�`���鐔
	m_nTouchCount = 0;

}

//-----------------------------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------------------------
CMiniGameNumber25::~CMiniGameNumber25()
{
}

//-----------------------------------------------------------------------------
// ������
//-----------------------------------------------------------------------------
HRESULT CMiniGameNumber25::Init()
{
	m_dwGameStartTime = timeGetTime();

	for (int nCntY = 0; nCntY < 5; nCntY++)
	{
		for (int nCntX = 0; nCntX < 5; nCntX++)
		{
			int nCntNumber = nCntY * 5 + nCntX;
			m_pObject2D[nCntNumber] = CObject2D::Create();
			m_pObject2D[nCntNumber]->SetPos(D3DXVECTOR3(400.0f + 120.0f * nCntX, 120.0f + 120.0f * nCntY, 0.0f));
			m_pObject2D[nCntNumber]->SetSize(D3DXVECTOR2(50.0f, 50.0f));
			m_pObject2D[nCntNumber]->SetTexture("NUMBER25");
			m_pObject2D[nCntNumber]->AnimTexture(nCntNumber, 25);
		}
	}

	Shuffle();

	return S_OK;
}

//-----------------------------------------------------------------------------
// �I��
//-----------------------------------------------------------------------------
void CMiniGameNumber25::Uninit()
{
}

//-----------------------------------------------------------------------------
// �X�V
//-----------------------------------------------------------------------------
void CMiniGameNumber25::Update()
{
	// �Q�[���o�ߎ��ԁ@���@���ݎ����@�[�@�Q�[���J�n����
	if (!m_isEndGame)
	{
		// �o�ߎ��Ԃ̍X�V
		m_dwGameTime = timeGetTime() - m_dwGameStartTime;
	}
}

//-----------------------------------------------------------------------------
// �`��
//-----------------------------------------------------------------------------
void CMiniGameNumber25::Draw()
{
}

//-----------------------------------------------------------------------------
// �V���b�t��
//-----------------------------------------------------------------------------
void CMiniGameNumber25::Shuffle()
{
	D3DXVECTOR3 pos;
	for (int nCnt = 25 - 1; nCnt > 0; nCnt--)
	{
		int nShuffle = rand() % nCnt;

		// ����ւ��ʒu��rand()�Ō��߂�
		// �ۑ�
		pos = m_pObject2D[nCnt]->GetPos();

		m_pObject2D[nCnt]->SetPos(m_pObject2D[nShuffle]->GetPos());
		m_pObject2D[nShuffle]->SetPos(pos);
	}
}

//==================================================
// �}�E�X�̃^�b�`����
//==================================================
void CMiniGameNumber25::Touch(float nPosX, float nPosY)
{
	if (!m_isEndGame)
	{// ���ׂẴ|���S���̃^�b�`���W����
		for (int nCntNumber = 0; nCntNumber < 25; nCntNumber++)
		{
			D3DXVECTOR3 pos = m_pObject2D[nCntNumber]->GetPos();
			D3DXVECTOR3 size = m_pObject2D[nCntNumber]->GetSize();
			//	�^�b�`���W���|���S���̒���������
			if (nCntNumber == m_nTouchCount &&
				pos.x + size.x >= nPosX
				&& pos.x - size.x <= nPosX
				&& pos.y - size.y <= nPosY
				&& pos.y + size.y >= nPosY)
			{
				// �|���S���̃J���[�ύX
				m_pObject2D[nCntNumber]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
				m_nTouchCount++;

				if (m_nTouchCount >= 25)
				{
					m_isEndGame = true;
				}
			}
		}
	}
	else
	{
		m_isEndGame = false;

		m_dwGameStartTime = timeGetTime();
		m_dwGameTime = 0;
		m_nTouchCount = 0;

		Shuffle();

		for (int nCntNumber = 0; nCntNumber < 25; nCntNumber++)
		{
			m_pObject2D[nCntNumber]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		}
	}
}
