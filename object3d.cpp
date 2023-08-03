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
// 静的メンバ変数
//-----------------------------------------------------------------------------
const D3DXVECTOR3 CObject3D::m_Vtx[4] =
{
	D3DXVECTOR3(-1.0f, +1.0f, 0.0f),
	D3DXVECTOR3(+1.0f, +1.0f, 0.0f),
	D3DXVECTOR3(-1.0f, -1.0f, 0.0f),
	D3DXVECTOR3(+1.0f, -1.0f, 0.0f),
};

//=============================================================================
// コンストラクタ
//=============================================================================
CObject3D::CObject3D(int priority) :
	CObject(priority),
	m_rot(0.0f, 0.0f, 0.0f),
	m_size(0.0f, 0.0f, 0.0f),
	m_pVtxBuff(nullptr)
{

}

//=============================================================================
// デストラクタ
//=============================================================================
CObject3D::~CObject3D()
{
}

//=============================================================================
// ポリゴンの初期化
//=============================================================================
HRESULT CObject3D::Init()
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();	// デバイスの取得

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,	// 確保するバッファのサイズ
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,		//頂点フォーマット
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D* pVtx;	// 頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//rhwの設定
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

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}

//=============================================================================
// ポリゴンの終了
//=============================================================================
void CObject3D::Uninit()
{
	// 破棄
	if (m_pVtxBuff != nullptr)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = nullptr;
	}
	Release();
}

//=============================================================================
// ポリゴンの更新
//=============================================================================
void CObject3D::Update()
{
}

//=============================================================================
// ポリゴンの描画
//=============================================================================
void CObject3D::Draw()
{
	// デバイスへのポインタ
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();	// デバイスの取得

	// カリングの設定
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	// テクスチャステージステートの設定
	pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	// ワールド座標行列の設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	// 頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	// テクスチャの設定
	LPDIRECT3DTEXTURE9 texture = CApplication::GetInstance()->GetTextureClass()->GetTexture(m_texture);
	pDevice->SetTexture(0, texture);

	// ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	// ライトを有効
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	// テクスチャステージステートを元に戻す
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);

	// カリングを元に戻す
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	//デバイス設定の初期化
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	// Zテストの終了
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	// αテストの終了
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	pDevice->SetTexture(0, NULL);
}

//=============================================================================
// create関数
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
////セットテクスチャ(2d)
////---------------------------------------
//void CObject3D::SetTex(PositionVec4 Tex)
//{
//	VERTEX_3D *pVtx; //頂点へのポインタ
//
//	//頂点バッファをロックし頂点情報へのポインタを取得
//	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
//
//	//テクスチャの座標設定
//	pVtx[0].tex = D3DXVECTOR2(Tex.P0, Tex.P2);
//	pVtx[1].tex = D3DXVECTOR2(Tex.P1, Tex.P2);
//	pVtx[2].tex = D3DXVECTOR2(Tex.P0, Tex.P3);
//	pVtx[3].tex = D3DXVECTOR2(Tex.P1, Tex.P3);
//
//	//頂点バッファをアンロック
//	m_pVtxBuff->Unlock();
//}

//---------------------------------------
// 位置の設定
//---------------------------------------
void CObject3D::SetPos(const D3DXVECTOR3& inPos)
{
	CObject::SetPos(inPos);

	// マトリックスの計算
	GiftMtx(&m_mtxWorld, m_pos, m_rot);
}

//---------------------------------------
// 向きの設定
//---------------------------------------
void CObject3D::SetRot(const D3DXVECTOR3 & inRot)
{
	m_rot = inRot;
	//// 法線の変更
	//D3DXMATRIX mtx;
	//D3DXMatrixRotationYawPitchRoll(&mtx, inRot.y, inRot.x, inRot.z);
	//D3DXVec3TransformCoord(&m_Normal, &m_Normal, &mtx);
	//D3DXVec3Normalize(&m_Normal, &m_Normal);

	// マトリックスの計算
	GiftMtx(&m_mtxWorld, m_pos, m_rot);
}

//---------------------------------------
//セットサイズ
//---------------------------------------
void CObject3D::SetSize(const D3DXVECTOR2 &size)
{
	m_size.x = size.x;
	m_size.y = size.y;

	VERTEX_3D *pVtx;	// 頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//------------------------
	// 頂点情報の設定
	//------------------------
	for (int i = 0; i < 4; ++i)
	{
		pVtx[i].pos.x = m_Vtx[i].x * m_size.x;
		pVtx[i].pos.y = m_Vtx[i].y * m_size.y;
		pVtx[i].pos.z = m_Vtx[i].z * 0.0f;
	}

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//---------------------------------------
//頂点Collarの設定
//---------------------------------------
void CObject3D::SetColor(const D3DXCOLOR& Collar)
{
	m_color = Collar;

	VERTEX_3D *pVtx; //頂点へのポインタ

	//頂点バッファをロックし頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//テクスチャの座標設定
	//頂点カラーの設定
	pVtx[0].col = m_color;
	pVtx[1].col = m_color;
	pVtx[2].col = m_color;
	pVtx[3].col = m_color;

	//頂点バッファをアンロック
	m_pVtxBuff->Unlock();
}

//---------------------------------------------------------------------------
// マトリックスの計算
//---------------------------------------------------------------------------
D3DXMATRIX* CObject3D::GiftMtx(D3DXMATRIX * pOut, const D3DXVECTOR3& inPos, const D3DXVECTOR3& inRot)
{
	// 計算用マトリックス
	D3DXMATRIX mtxRot, mtxTrans;

	// ワールドマトリックスの初期化
	// 行列初期化関数(第1引数の行列を単位行列に初期化)
	D3DXMatrixIdentity(pOut);

	D3DXMatrixRotationYawPitchRoll(&mtxRot, inRot.y, inRot.x, inRot.z);
	// 行列掛け算関数(第2引数×第3引数第を１引数に格納)
	D3DXMatrixMultiply(pOut, pOut, &mtxRot);

	// 位置を反映
	// 行列移動関数(第１引数にX,Y,Z方向の移動行列を作成)
	D3DXMatrixTranslation(&mtxTrans, inPos.x, inPos.y, inPos.z);
	// 行列掛け算関数(第2引数×第3引数第を１引数に格納)
	D3DXMatrixMultiply(pOut, pOut, &mtxTrans);

	return pOut;
}
