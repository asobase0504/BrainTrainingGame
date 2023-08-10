//=============================================================================
//
// object3d
// AUthor : Yuda Kaito
//
//=============================================================================
#ifndef _3DPOLYGON_H_	// ���̃}�N����`������ĂȂ�������
#define _3DPOLYGON_H_	// ��d�C���N���[�h�h�~�̃}�N����`

//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "object.h"
#include "objectList.h"

//-----------------------------------------------------------------------------
// �}�N���錾
//-----------------------------------------------------------------------------

//=============================================================================
// 3D�|���S���N���X
//=============================================================================
class  CObject3D : public CObject
{
public:
	static const DWORD FVF_VERTEX_3D = (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	//���_���u3D�v�̍\���̂��`
	struct VERTEX_3D
	{
		D3DXVECTOR3 pos;	// ���_���W
		D3DXVECTOR3 nor;	// �x�N�g��
		D3DCOLOR col;		// �J���[
		D3DXVECTOR2 tex;	// �e�N�X�`��
	};

protected:
	//polygon�̊�T�C�Y
	static const D3DXVECTOR3 m_Vtx[4];

public:

	static CObject3D *Create(int priority = CObjectList::LEVEL_DEBUG);

	CObject3D(int priority = CObjectList::LEVEL_DEBUG);
	~CObject3D() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	// �ʒu
	void SetPos(const D3DXVECTOR3& inPos) override;

	void SetRot(const D3DXVECTOR3& inRot);
	const D3DXVECTOR3& GetRot() const { return m_rot; }
	void SetSize(const D3DXVECTOR2& inSize);
	void AddSize(const D3DXVECTOR2& inSize) { SetSize((D3DXVECTOR2)m_size + inSize); }
	const D3DXVECTOR2& GetSize() const { return (D3DXVECTOR2)m_size; }

	void SetColor(const D3DXCOLOR& inColor);
	void SetTexture(std::string inTex) { m_texture = inTex; }	// �e�N�X�`���̐ݒ�

	LPDIRECT3DVERTEXBUFFER9 GetVtx() { return m_pVtxBuff; }	// ���_�o�b�t�@�̎擾
	const D3DXVECTOR3& GetNormal() const { return m_Normal; }

private:
	D3DXMATRIX* GiftMtx(D3DXMATRIX * pOut, const D3DXVECTOR3& inPos, const D3DXVECTOR3& inRot);

protected:
	LPDIRECT3DVERTEXBUFFER9	m_pVtxBuff;	// ���_�o�b�t�@
	D3DXMATRIX m_mtxWorld;				// ���[���h�}�g���b�N�X
private:
	std::string m_texture;	// �e�N�X�`��
	D3DXVECTOR3 m_Normal;

	D3DXCOLOR m_color;
	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_size;
};
#endif
