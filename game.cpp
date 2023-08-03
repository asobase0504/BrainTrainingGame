//=============================================================================
// 
// �A�v���P�[�V�����N���X
// Author YudaKaito
// 
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "game.h"
#include "pause.h"
#include "input.h"
#include <assert.h>
#include "application.h"
#include "file.h"
#include "headcount.h"
#include "bus.h"
#include "camera_game.h"
#include "station.h"
#include "station_goal.h"

//-----------------------------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------------------------
CGame::CGame() :
	m_pause(nullptr)
{
}

//-----------------------------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------------------------
CGame::~CGame()
{
	assert(m_pause == nullptr);
}

//-----------------------------------------------------------------------------
// ������
//-----------------------------------------------------------------------------
HRESULT CGame::Init()
{
	m_count = 0;

	// �w�i�̐ݒ�
	{
		CObject3D* bg = CObject3D::Create(0);
		bg->SetSize(CApplication::GetInstance()->GetScreenSize() * 2.0f);
		D3DXVECTOR3 pos(CApplication::GetInstance()->CENTER_X, CApplication::GetInstance()->CENTER_Y, 0.0f);	// �ʒu�̎擾
		bg->SetTexture("BG");
		bg->SetPos(pos);
		bg->SetColor(CApplication::GetInstance()->GetColor(2));
	}

	CBus* bus = new CBus;
	//�t�@�C���ǂݍ���
	CHeadCount::Load();

	bus->Init();
	bus->SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	CStation* prevStation;

	{
		CStation* station = new CStation;
		station->Init();
		station->SetPos(D3DXVECTOR3(-200.0f, -20.0f, 0.0f));
		bus->Departure(station);
		prevStation = station;
	}

	for (int i = 0; i < 10; i++)
	{
		CStation* station = new CStation;
		station->Init();
		station->SetPos(D3DXVECTOR3(-200.0f + -100.0f * (i + 1), -20.0f, 0.0f));
		prevStation->AttachNextStation(station);
		prevStation = station;
	}

	CStation* goal = new CStationGoal;
	goal->Init();
	goal->SetPos(D3DXVECTOR3(-200.0f + -100.0f * 11, -20.0f, 0.0f));
	prevStation->AttachNextStation(goal);

	m_camera = CCameraGame::Create(bus);

	return S_OK;
}

//-----------------------------------------------------------------------------
// �I��
//-----------------------------------------------------------------------------
void CGame::Uninit()
{
	if (m_pause != nullptr)
	{
		m_pause->Uninit();
		delete m_pause;
		m_pause = nullptr;
	}

	if (m_camera != nullptr)
	{
		m_camera->Uninit();
		delete m_camera;
		m_camera = nullptr;
	}
}

//-----------------------------------------------------------------------------
// �X�V
//-----------------------------------------------------------------------------
void CGame::Update()
{
	m_camera->Update();

	if (CInput::GetKey()->Trigger(DIK_LEFT))
	{
		m_count++;
	}
	if (CInput::GetKey()->Trigger(DIK_RIGHT))
	{
		m_count--;
	}
}

//-----------------------------------------------------------------------------
// �`��
//-----------------------------------------------------------------------------
void CGame::Draw()
{
	m_camera->Set();
}
