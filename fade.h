//=============================================================================
//
// �t�F�[�h
// Author : Hamada Ryuuga
//
//=============================================================================
#ifndef _FADE_H_
#define _FADE_H_

//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "application.h"
#include "renderer.h"
#include "object2d.h"
#include "mode.h"

//-----------------------------------------------------------------------------
// �O���錾
//-----------------------------------------------------------------------------
class  CMotion;

//=============================================================================
// �t�F�[�h�N���X
//=============================================================================
class CFade : public CObject2D
{

private:
	static CFade* m_instance;
	CFade();
public:
	static CFade* GetInstance();
	~CFade();

	//���(���[�h)�̎��
	enum FADE
	{
		FADEIN = 0,
		FADEOUT,
		FADENON,
		FADEMAX
	};

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	void CFade::NextMode(CMode::MODE_TYPE nextMode);
	FADE* GetFade() { return& m_fade; }

private:
	float m_fadeSp;
	float m_fadeSet;
	bool m_bake;
	CMode::MODE_TYPE m_nextMode;
	FADE m_fade;
};
#endif