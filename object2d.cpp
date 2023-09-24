//=========================================
// 
// オブジェクトクラス
// Author YudaKaito
// 
//=========================================
#include "object2d.h"
#include "application.h"
#include "renderer.h"
#include "texture.h"
#include <assert.h>

//=============================================================================
// コンストラクタ
//=============================================================================
CObject2D::CObject2D(int inPriority) :
	CObject(inPriority),
	m_pVtxBuff(nullptr),
	m_texture("\0"),
	m_rotY(0.0f),
	m_fLength(0.0f),
	m_fAngle(0.0f),
	m_anchor(CENTER),
	m_move(0.0f, 0.0f, 0.0f),
	m_col(1.0f, 1.0f, 1.0f,1.0f)
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CObject2D::~CObject2D()
{
}

//=============================================================================
// ポリゴンの初期化
//=============================================================================
HRESULT CObject2D::Init()
{
	// 頂点バッファの生成
	CApplication::GetInstance()->GetRenderer()->GetDevice()->CreateVertexBuffer(
		sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D *pVtx = NULL;		// 頂点情報へのポインタ

	m_fLength = sqrtf(m_size.x * m_size.x + m_size.y * m_size.y) * 0.5f;
	m_fAngle = atan2f(m_size.x, m_size.y);

	// 頂点情報をロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos.x = CApplication::GetInstance()->CENTER_X + sinf(m_rotY + m_fAngle + -D3DX_PI) * m_fLength;
	pVtx[0].pos.y = CApplication::GetInstance()->CENTER_Y + cosf(m_rotY + m_fAngle + -D3DX_PI) * m_fLength;
	pVtx[0].pos.z = 0.0f;

	pVtx[1].pos.x = CApplication::GetInstance()->CENTER_X + sinf(m_rotY + -m_fAngle + D3DX_PI) * m_fLength;
	pVtx[1].pos.y = CApplication::GetInstance()->CENTER_Y + cosf(m_rotY + -m_fAngle + D3DX_PI) * m_fLength;
	pVtx[1].pos.z = 0.0f;

	pVtx[2].pos.x = CApplication::GetInstance()->CENTER_X + sinf(m_rotY + m_fAngle * -1.0f) * m_fLength;
	pVtx[2].pos.y = CApplication::GetInstance()->CENTER_Y + cosf(m_rotY + m_fAngle * -1.0f) * m_fLength;
	pVtx[2].pos.z = 0.0f;

	pVtx[3].pos.x = CApplication::GetInstance()->CENTER_X + sinf(m_rotY + m_fAngle) * m_fLength;
	pVtx[3].pos.y = CApplication::GetInstance()->CENTER_Y + cosf(m_rotY + m_fAngle) * m_fLength;
	pVtx[3].pos.z = 0.0f;

	// texの設定
	pVtx[0].tex = D3DXVECTOR2(0.0f,0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f,0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f,1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f,1.0f);

	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	// 頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}

//=============================================================================
// ポリゴンの終了
//=============================================================================
void CObject2D::Uninit()
{
	CObject::Release();

	// 頂点バッファの破壊
	if (m_pVtxBuff != nullptr)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = nullptr;
	}
}

//=============================================================================
// ポリゴンの更新
//=============================================================================
void CObject2D::Update()
{
	AddPos(m_move);
}

//=============================================================================
// ポリゴンの描画
//=============================================================================
void CObject2D::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();

	// 頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	LPDIRECT3DTEXTURE9 texture = CApplication::GetInstance()->GetTextureClass()->GetTexture(m_texture);

	// テクスチャの設定
	pDevice->SetTexture(0, texture);

	// ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	// テクスチャの破棄
	pDevice->SetTexture(0, NULL);
}

//=============================================================================
// 位置の設定
//=============================================================================
void CObject2D::SetPos(const D3DXVECTOR3 & inPos)
{
	CObject::SetPos(inPos);
	Vtx();
}

void CObject2D::SetRot(const float inRot)
{
	m_rotY = inRot;
	Vtx();
}

//=============================================================================
// 大きさの設定
//=============================================================================
void CObject2D::SetSize(const D3DXVECTOR2 & inSize)
{
	m_size = inSize;

	m_fLength = sqrtf(m_size.x * m_size.x + m_size.y * m_size.y) * 0.5f;
	m_fAngle = atan2f(m_size.x, m_size.y);

	SetPos(m_pos);
}

//=============================================================================
// 動きの設定
//=============================================================================
void CObject2D::SetMove(const D3DXVECTOR3 & inMove)
{
	m_move = inMove;
}

//=============================================================================
// 色の設定
//=============================================================================
void CObject2D::SetColor(const D3DXCOLOR & inColor)
{
	m_col = inColor;

	VERTEX_2D *pVtx = NULL;		// 頂点情報へのポインタ

	// 頂点情報をロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点カラーの設定
	pVtx[0].col = inColor;
	pVtx[1].col = inColor;
	pVtx[2].col = inColor;
	pVtx[3].col = inColor;

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//=============================================================================
// 透明色のみの設定
//=============================================================================
void CObject2D::SetColorAlpha(const float inAlpha)
{
	m_col.a = inAlpha;

	VERTEX_2D *pVtx = NULL;		// 頂点情報へのポインタ

	// 頂点情報をロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点カラーの設定
	pVtx[0].col = m_col;
	pVtx[1].col = m_col;
	pVtx[2].col = m_col;
	pVtx[3].col = m_col;

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

void CObject2D::Vtx()
{
	D3DXVECTOR3 pos = m_pos;

	if (m_parent != nullptr)
	{
		pos += m_parent->GetPos();
	}

	D3DXMATRIX mtx, mtxTrans;

	// 回転の反映
	D3DXMatrixRotationZ(&mtx, -m_rotY);

	// 位置の反映
	D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, 0.0f);
	D3DXMatrixMultiply(&mtx, &mtx, &mtxTrans);

	D3DXVECTOR3 pVtxpos[4];

	float fHalfWidth = m_size.x * 0.5f;
	float fHalfHeight = m_size.y * 0.5f;

	pVtxpos[0] = D3DXVECTOR3(-fHalfWidth, -fHalfHeight, 0.0f);
	pVtxpos[1] = D3DXVECTOR3(+fHalfWidth, -fHalfHeight, 0.0f);
	pVtxpos[2] = D3DXVECTOR3(-fHalfWidth, +fHalfHeight, 0.0f);
	pVtxpos[3] = D3DXVECTOR3(+fHalfWidth, +fHalfHeight, 0.0f);

	VERTEX_2D *pVtx = NULL;		// 頂点情報へのポインタ

	// 頂点情報をロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int i = 0; i < 4; i++)
	{
		D3DXVec3TransformCoord(&pVtx[i].pos, &pVtxpos[i], &mtx);
	}

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//=============================================================================
// テクスチャのアニメーション
//=============================================================================
void CObject2D::AnimTexture(int num, int texMax)
{
	VERTEX_2D *pVtx;			// 頂点情報へのポインタ

	float nDivisionRate = 1.0f / texMax;

	// 頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].tex = D3DXVECTOR2(num * nDivisionRate, 0.0f);
	pVtx[1].tex = D3DXVECTOR2((num + 1) * nDivisionRate, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(num * nDivisionRate, 1.0f);
	pVtx[3].tex = D3DXVECTOR2((num + 1) * nDivisionRate, 1.0f);

	// 頂点バッファをアンロック
	m_pVtxBuff->Unlock();
}

//=============================================================================
// ポリゴンクラスの作成
//=============================================================================
CObject2D* CObject2D::Create(int inPriority)
{
	CObject2D* objectCreate = new CObject2D(inPriority);

	if ((objectCreate == nullptr) || FAILED(objectCreate->Init()))
	{
		assert(false);
	}

	return objectCreate;
}
