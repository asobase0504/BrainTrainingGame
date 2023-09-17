//=========================================
// 
// �I�u�W�F�N�g�N���X
// Author YudaKaito
// 
//=========================================
#ifndef _OBJECT2D_H_
#define _OBJECT2D_H_

#include "object.h"
#include "texture.h"
#include <string>

class CObject2D : public CObject
{
public:

	enum Anchor
	{
		TOP_LEFT = 0,
		TOP,
		TOP_RIGHT,
		LEFT,
		CENTER,
		RIGHT,
		DOWN_LEFT,
		DOWN,
		DOWN_RIGHT,
		MAX
	};

	//*****************************************************************************
	// �\���̒�`
	//*****************************************************************************
	// ���_�f�[�^
	struct VERTEX_2D
	{
		D3DXVECTOR3 pos;
		float rhw;
		D3DCOLOR col;
		D3DXVECTOR2 tex;
	};

	// ���_�t�H�[�}�b�g
	static const DWORD FVF_VERTEX_2D = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

public:	// �ÓI�֐�
	static CObject2D* Create(int inPriority = 3);

public:
	CObject2D(int inPriority = 3);
	~CObject2D() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	// ���S���W
	void SetAnchor(Anchor inAnvhor) { m_anchor = inAnvhor; }

	// �ʒu
	void SetPos(const D3DXVECTOR3& inPos) override;
	void AddPos(const D3DXVECTOR3& move) { SetPos(m_pos + move); }

	void SetRot(const float inRot);
	void AddRot(const float inRot) { SetRot(inRot + m_rotY); }

	// ������
	void SetSize(const D3DXVECTOR2& inSize);
	const D3DXVECTOR2 GetSize() { return m_size; }

	// ����
	void SetMove(const D3DXVECTOR3& inMove);
	const D3DXVECTOR3 GetMove() { return m_move; }

	// �A�j���[�V����
	void SetTexture(std::string inTex) { m_texture = inTex; }	// �e�N�X�`���̐ݒ�
	void AnimTexture(int num, int texMax);

	// �F
	void SetColor(const D3DXCOLOR& inColor);
	const D3DXCOLOR GetColor() { return m_col; }
	void SetColorAlpha(const float inAlpha);
	void AddColorAlpha(const float inAlpha) { SetColorAlpha(m_col.a + inAlpha); }
	float GetColorAlpha() { return m_col.a; }

private:
	void Vtx();
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	// VtxBuff
	Anchor m_anchor;	// �A���J�[�̐ݒ�
	std::string m_texture;	// �e�N�X�`��
	float m_rotY;			// ��]
	float m_fLength;		// ����
	float m_fAngle;		// �p�x


protected:
	D3DXVECTOR2 m_size;	// �傫��
	D3DXVECTOR3 m_move;	// ����
	D3DXCOLOR m_col;	// �F
};

#endif // !_OBJECT2D_H_
