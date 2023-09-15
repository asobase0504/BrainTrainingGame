//=========================================
// 
// �A�v���P�[�V�����N���X
// Author YudaKaito
// 
//=========================================
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "mode.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CRenderer;
class CDirectInput;
class CTexture;
class CMode;
class CThemeColor;
class CInput;
class CSound;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CApplication
{
public: // �萔
	static const int SCREEN_WIDTH;		// �X�N���[���̕�
	static const int SCREEN_HEIGHT;		// �X�N���[���̍���
	static const float CENTER_X;		// �X�N���[�����S���W��X���W
	static const float CENTER_Y;		// �X�N���[�����S���W��Y���W

public: // �ÓI�����o�[�ϐ�
	static CApplication* application;
public: // �ÓI�֐�
	static CApplication* GetInstance();

private: // �V���O���g��
	CApplication();
public:	// �����o�[�֐�
	~CApplication();

	HRESULT Init(HWND hWnd, HINSTANCE hInstance);
	void Uninit();
	void Update();
	void Draw();

	// Getter
	CRenderer* GetRenderer() { return renderer; }
	CTexture* GetTextureClass() { return texture; }
	CMode* GetMode() { return mode; }
	CMode::MODE_TYPE GetModeType() { return m_modeType; }
	CSound* GetSound() { return sound; }
	D3DXCOLOR GetColor(int inKey);
	int GetColorSize();
	D3DXVECTOR2 GetScreenSize() { return D3DXVECTOR2((float)SCREEN_WIDTH, (float)SCREEN_HEIGHT); }
	D3DXVECTOR2 GetScreenCenter() { return D3DXVECTOR2(CENTER_X, CENTER_Y); }

	// Setter
	void SetMode(CMode::MODE_TYPE inType);
	void SetThemeColor(int idx);

private: // ���I�����o�[�ϐ�
	CMode* mode;
	CMode::MODE_TYPE m_modeType;
	CInput* input;
	CRenderer* renderer;
	CTexture* texture;
	CThemeColor* color;
	CSound* sound;
};

#endif // !_APPLICATION_H_
