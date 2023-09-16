//=============================================================================
// 
// �A�v���P�[�V�����N���X
// Author YudaKaito
// 
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "minigame_bus.h"
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
CMiniGameBus::CMiniGameBus()
{
}

//-----------------------------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------------------------
CMiniGameBus::~CMiniGameBus()
{
}

//-----------------------------------------------------------------------------
// ������
//-----------------------------------------------------------------------------
HRESULT CMiniGameBus::Init()
{
	CGame::Init();

	m_count = 0;

	// �w�i�̐ݒ�
	{
		CObject3D* bg = CObject3D::Create(0);
		bg->SetSize(CApplication::GetInstance()->GetScreenSize() * 10.0f);
		D3DXVECTOR3 pos(CApplication::GetInstance()->CENTER_X, CApplication::GetInstance()->CENTER_Y, 0.0f);	// �ʒu�̎擾
		bg->SetTexture("BG");
		bg->SetPos(pos);
		bg->SetColor(D3DXCOLOR(0.25f,0.34f,0.45f,1.0f));
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
		station->CreatePassenger();
		bus->Departure(station);
		prevStation = station;
	}

	for (int i = 0; i < 5; i++)
	{
		CStation* station = new CStation;
		station->Init();
		station->SetPos(D3DXVECTOR3(-200.0f + -900.0f * (i + 1), -20.0f, 0.0f));
		station->CreatePassenger();
		prevStation->AttachNextStation(station);
		prevStation = station;
	}

	CStation* goal = new CStationGoal;
	goal->Init();
	goal->SetPos(D3DXVECTOR3(-200.0f + -900.0f * 6, -20.0f, 0.0f));
	prevStation->AttachNextStation(goal);

	m_camera = CCameraGame::Create(bus);

	return S_OK;
}

//-----------------------------------------------------------------------------
// �I��
//-----------------------------------------------------------------------------
void CMiniGameBus::Uninit()
{
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
void CMiniGameBus::Update()
{
	CGame::Update();
	m_camera->Update();
}

//-----------------------------------------------------------------------------
// �`��
//-----------------------------------------------------------------------------
void CMiniGameBus::Draw()
{
	m_camera->Set();
}
