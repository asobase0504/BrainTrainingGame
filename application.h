//=========================================
// 
// アプリケーションクラス
// Author YudaKaito
// 
//=========================================
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "mode.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------
class CRenderer;
class CDirectInput;
class CTexture;
class CMode;
class CThemeColor;
class CInput;
class CSound;

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CApplication
{
public: // 定数
	static const int SCREEN_WIDTH;			// スクリーンの幅
	static const int SCREEN_HEIGHT;			// スクリーンの高さ
	static const float CENTER_X;			// スクリーン中心座標のX座標
	static const float CENTER_Y;			// スクリーン中心座標のY座標
	static const float FLOAT_SCREEN_WIDTH;	// スクリーンの幅(float版)
	static const float FLOAT_SCREEN_HEIGHT;	// スクリーンの高さ(float版)

public: // 静的メンバー変数
	static CApplication* application;
public: // 静的関数
	static CApplication* GetInstance();

private: // シングルトン
	CApplication();
public:	// メンバー関数
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
	D3DXVECTOR2 GetScreenSize() { return D3DXVECTOR2((float)SCREEN_WIDTH, (float)SCREEN_HEIGHT); }
	D3DXVECTOR2 GetScreenCenter() { return D3DXVECTOR2(CENTER_X, CENTER_Y); }

	// Setter
	void SetMode(CMode::MODE_TYPE inType);

	// 終了するかどうか
	void SetIsEnd(bool inEnd) { m_isEnd = inEnd; }
	bool GetIsEnd() { return m_isEnd; }

private: // 動的メンバー変数
	CMode* mode;
	CMode::MODE_TYPE m_modeType;
	CInput* input;
	CRenderer* renderer;
	CTexture* texture;
	CSound* sound;
	bool m_isEnd;
};

#endif // !_APPLICATION_H_
