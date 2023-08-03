//=============================================================================
//
// Object
// Author : Hamada Ryuuga
// AUthor : Yuda Kaito
//
//=============================================================================
//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "object3d.h"
#include "application.h"
#include "input.h"
#include "utility.h"
#include "renderer.h"
#include "texture.h"

//-----------------------------------------------------------------------------
// �ÓI�����o�ϐ�
//-----------------------------------------------------------------------------
const D3DXVECTOR3 CObject3D::m_Vtx[4] =
{
	D3DXVECTOR3(-1.0f, +1.0f, 0.0f),
	D3DXVECTOR3(+1.0f, +1.0f, 0.0f),
	D3DXVECTOR3(-1.0f, -1.0f, 0.0f),
	D3DXVECTOR3(+1.0f, -1.0f, 0.0f),
};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CObject3D::CObject3D(int priority) :
	CObject(priority),
	m_rot(0.0f, 0.0f, 0.0f),
	m_size(0.0f, 0.0f, 0.0f),
	m_pVtxBuff(nullptr)
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CObject3D::~CObject3D()
{
}

//=============================================================================
// �|���S���̏�����
//=============================================================================
HRESULT CObject3D::Init()
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();	// �f�o�C�X�̎擾

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,	// �m�ۂ���o�b�t�@�̃T�C�Y
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,		//���_�t�H�[�}�b�g
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D* pVtx;	// ���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//rhw�̐ݒ�
	//m_Normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	//pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	//pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	//pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	//pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

	m_Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//=============================================================================
// �|���S���̏I��
//=============================================================================
void CObject3D::Uninit()
{
	// �j��
	if (m_pVtxBuff != nullptr)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = nullptr;
	}
	Release();
}

//=============================================================================
// �|���S���̍X�V
//=============================================================================
void CObject3D::Update()
{
}

//=============================================================================
// �|���S���̕`��
//=============================================================================
void CObject3D::Draw()
{
	// �f�o�C�X�ւ̃|�C���^
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();	// �f�o�C�X�̎擾

	// �J�����O�̐ݒ�
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	// �e�N�X�`���X�e�[�W�X�e�[�g�̐ݒ�
	pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	// ���[���h���W�s��̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	// ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	// �e�N�X�`���̐ݒ�
	LPDIRECT3DTEXTURE9 texture = CApplication::GetInstance()->GetTextureClass()->GetTexture(m_texture);
	pDevice->SetTexture(0, texture);

	// �|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	// ���C�g��L��
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	// �e�N�X�`���X�e�[�W�X�e�[�g�����ɖ߂�
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);

	// �J�����O�����ɖ߂�
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	//�f�o�C�X�ݒ�̏�����
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	// Z�e�X�g�̏I��
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	// ���e�X�g�̏I��
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	pDevice->SetTexture(0, NULL);
}

//=============================================================================
// create�֐�
//=============================================================================
CObject3D *CObject3D::Create(int list)
{
	CObject3D * pObject = nullptr;
	pObject = new CObject3D(list);

	if (pObject != nullptr)
	{
		pObject->Init();
	}

	return pObject;
}

////---------------------------------------
////�Z�b�g�e�N�X�`��(2d)
////---------------------------------------
//void CObject3D::SetTex(PositionVec4 Tex)
//{
//	VERTEX_3D *pVtx; //���_�ւ̃|�C���^
//
//	//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
//	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
//
//	//�e�N�X�`���̍��W�ݒ�
//	pVtx[0].tex = D3DXVECTOR2(Tex.P0, Tex.P2);
//	pVtx[1].tex = D3DXVECTOR2(Tex.P1, Tex.P2);
//	pVtx[2].tex = D3DXVECTOR2(Tex.P0, Tex.P3);
//	pVtx[3].tex = D3DXVECTOR2(Tex.P1, Tex.P3);
//
//	//���_�o�b�t�@���A�����b�N
//	m_pVtxBuff->Unlock();
//}

//---------------------------------------
// �ʒu�̐ݒ�
//---------------------------------------
void CObject3D::SetPos(const D3DXVECTOR3& inPos)
{
	CObject::SetPos(inPos);

	// �}�g���b�N�X�̌v�Z
	GiftMtx(&m_mtxWorld, m_pos, m_rot);
}

//---------------------------------------
// �����̐ݒ�
//---------------------------------------
void CObject3D::SetRot(const D3DXVECTOR3 & inRot)
{
	m_rot = inRot;
	//// �@���̕ύX
	//D3DXMATRIX mtx;
	//D3DXMatrixRotationYawPitchRoll(&mtx, inRot.y, inRot.x, inRot.z);
	//D3DXVec3TransformCoord(&m_Normal, &m_Normal, &mtx);
	//D3DXVec3Normalize(&m_Normal, &m_Normal);

	// �}�g���b�N�X�̌v�Z
	GiftMtx(&m_mtxWorld, m_pos, m_rot);
}

//---------------------------------------
//�Z�b�g�T�C�Y
//---------------------------------------
void CObject3D::SetSize(const D3DXVECTOR2 &size)
{
	m_size.x = size.x;
	m_size.y = size.y;

	VERTEX_3D *pVtx;	// ���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//------------------------
	// ���_���̐ݒ�
	//------------------------
	for (int i = 0; i < 4; ++i)
	{
		pVtx[i].pos.x = m_Vtx[i].x * m_size.x;
		pVtx[i].pos.y = m_Vtx[i].y * m_size.y;
		pVtx[i].pos.z = m_Vtx[i].z * 0.0f;
	}

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//---------------------------------------
//���_Collar�̐ݒ�
//---------------------------------------
void CObject3D::SetColor(const D3DXCOLOR& Collar)
{
	m_color = Collar;

	VERTEX_3D *pVtx; //���_�ւ̃|�C���^

	//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�e�N�X�`���̍��W�ݒ�
	//���_�J���[�̐ݒ�
	pVtx[0].col = m_color;
	pVtx[1].col = m_color;
	pVtx[2].col = m_color;
	pVtx[3].col = m_color;

	//���_�o�b�t�@���A�����b�N
	m_pVtxBuff->Unlock();
}

//---------------------------------------------------------------------------
// �}�g���b�N�X�̌v�Z
//---------------------------------------------------------------------------
D3DXMATRIX* CObject3D::GiftMtx(D3DXMATRIX * pOut, const D3DXVECTOR3& inPos, const D3DXVECTOR3& inRot)
{
	// �v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

	// ���[���h�}�g���b�N�X�̏�����
	// �s�񏉊����֐�(��1�����̍s���P�ʍs��ɏ�����)
	D3DXMatrixIdentity(pOut);

	D3DXMatrixRotationYawPitchRoll(&mtxRot, inRot.y, inRot.x, inRot.z);
	// �s��|���Z�֐�(��2�����~��3��������P�����Ɋi�[)
	D3DXMatrixMultiply(pOut, pOut, &mtxRot);

	// �ʒu�𔽉f
	// �s��ړ��֐�(��P������X,Y,Z�����̈ړ��s����쐬)
	D3DXMatrixTranslation(&mtxTrans, inPos.x, inPos.y, inPos.z);
	// �s��|���Z�֐�(��2�����~��3��������P�����Ɋi�[)
	D3DXMatrixMultiply(pOut, pOut, &mtxTrans);

	return pOut;
}
