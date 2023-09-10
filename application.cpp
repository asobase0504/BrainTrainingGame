//=========================================
// 
// �A�v���P�[�V�����N���X
// Author YudaKaito
// 
//=========================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "application.h"
#include <assert.h>
#include "input.h"
#include "renderer.h"
#include "theme_color.h"
#include "texture.h"
#include "object2d.h"
#include "sound.h"
#include "objectList.h"
#include "fade.h"

// ���[�h
#include "title.h"
#include "game.h"
#include "minigame_number25.h"
#include "minigame_bus.h"
#include "minigame_moveobject.h"
#include "minigame_remember_before.h"

using namespace std;

//-----------------------------------------------------------------------------
// �ÓI�����o�[�ϐ��̏�����
//-----------------------------------------------------------------------------
CApplication* CApplication::application = nullptr;
const int CApplication::SCREEN_WIDTH(1280);
const int CApplication::SCREEN_HEIGHT(720);
const float CApplication::CENTER_X(SCREEN_WIDTH * 0.5f);
const float CApplication::CENTER_Y(SCREEN_HEIGHT * 0.5f);

//-----------------------------------------------------------------------------
// �V���O���g���ł̃C���X�^���X�̎擾
//-----------------------------------------------------------------------------
CApplication* CApplication::GetInstance()
{
	if (application == nullptr)
	{
		application = new CApplication;
	}

	return application;
}

//-----------------------------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------------------------
CApplication::CApplication() :
	mode(nullptr),
	renderer(nullptr),
	input(nullptr),
	texture(nullptr),
	color(nullptr)
{
}

//-----------------------------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------------------------
CApplication::~CApplication()
{
	assert(mode == nullptr);
	assert(renderer == nullptr);
	assert(input == nullptr);
	assert(texture == nullptr);
	assert(color == nullptr);
}

//-----------------------------------------------------------------------------
// ������
//-----------------------------------------------------------------------------
HRESULT CApplication::Init(HWND hWnd, HINSTANCE hInstance)
{
	// ���͏���
	input = CInput::Create();
	if (FAILED(input->Init(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	// �����_�����O�N���X
	renderer = new CRenderer;
	if (FAILED(renderer->Init(hWnd, true)))
	{
		return E_FAIL;
	}

	// �e�N�X�`��
	texture = new CTexture;
	texture->LoadAll();

	// �F�Ǘ��N���X
	color = new CThemeColor;
	if (FAILED(color->Init()))
	{
		return E_FAIL;
	}

	// �T�E���h�N���X
	sound = new CSound;
	if (FAILED(sound->Init(hWnd)))
	{
		return E_FAIL;
	}

	// �Q�[�����[�h
	SetMode(CMode::MODE_TYPE::TITLE);

	return S_OK;
}

//-----------------------------------------------------------------------------
// �I��
//-----------------------------------------------------------------------------
void CApplication::Uninit()
{
	// �I�u�W�F�N�g�S�̂̉��
	CTaskGroup::GetInstance()->Uninit();

	// �Q�[���̃N���A
	if (mode != nullptr)
	{
		mode->Uninit();

		delete mode;
		mode = nullptr;
	}

	// �T�E���h�̉��
	if (sound != nullptr)
	{
		sound->Uninit();
		delete sound;
		sound = nullptr;
	}

	// �e�N�X�`���̉��
	texture->UnloadAll();
	if (texture != nullptr)
	{
		delete texture;
		texture = nullptr;
	}

	// �F�Ǘ��̉��
	if (color != nullptr)
	{
		delete color;
		color = nullptr;
	}

	// ���͏����̉��
	if (input != nullptr)
	{
		input->Uninit();
		input = nullptr;
	}

	// �����_���[�̉��
	if (renderer != nullptr)
	{
		renderer->Uninit();

		delete renderer;
		renderer = nullptr;
	}

	// �A�v���P�[�V�����̉��
	if (application != nullptr)
	{
		delete application;
		application = nullptr;
	}
	assert(application == nullptr);
}

//-----------------------------------------------------------------------------
// �X�V
//-----------------------------------------------------------------------------
void CApplication::Update()
{
	input->Update();
	renderer->Update();
	mode->Update();
}

//-----------------------------------------------------------------------------
// �`��
//-----------------------------------------------------------------------------
void CApplication::Draw()
{
	renderer->Draw();
}

//-----------------------------------------------------------------------------
// �F�̎擾
//-----------------------------------------------------------------------------
D3DXCOLOR CApplication::GetColor(int inKey)
{
	return color->GetColor(inKey);
}

int CApplication::GetColorSize()
{
	return color->GetSize();
}

//-----------------------------------------------------------------------------
// ���[�h�̐ݒ�
//-----------------------------------------------------------------------------
void CApplication::SetMode(CMode::MODE_TYPE inType)
{
	if (mode != nullptr)
	{
		CTaskGroup::GetInstance()->AllRelease();
		mode->Uninit();
		delete mode;
		mode = nullptr;
	}

	switch (inType)
	{
	case CMode::MODE_TYPE::TITLE:
		mode = new CTitle;
		break;
	case CMode::MODE_TYPE::MINIGAME_BUS:
		mode = new CMiniGameBus;
		break;
	case CMode::MODE_TYPE::MINIGAME_MOVEOBJECT:
		mode = new CMiniGameMoveObject;
		break;
	case CMode::MODE_TYPE::MINIGAME_NUMBER25:
		mode = new CMiniGameNumber25;
		break;
	case CMode::MODE_TYPE::MINIGAME_REMEMBER_BEFORE:
		mode = new CMiniGameRememberBefore;
		break;	
	case CMode::MODE_TYPE::GAME:
		mode = new CGame;
		break;
	default:
		break;
	}

	if (FAILED(mode->Init()))
	{
		assert(false);
	}
}

//-----------------------------------------------------------------------------
// �e�[�}�J���[�̐ݒ�
//-----------------------------------------------------------------------------
void CApplication::SetThemeColor(int idx)
{
	color->SetTheme(idx);	// �e�[�}�F�̐ݒ�
}
