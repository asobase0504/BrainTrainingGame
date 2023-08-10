//=============================================================================
//
// object3d
// AUthor : Yuda Kaito
//
//=============================================================================
#ifndef _3DPOLYGON_H_	// このマクロ定義がされてなかったら
#define _3DPOLYGON_H_	// 二重インクルード防止のマクロ定義

//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "object.h"
#include "objectList.h"

//-----------------------------------------------------------------------------
// マクロ宣言
//-----------------------------------------------------------------------------

//=============================================================================
// 3Dポリゴンクラス
//=============================================================================
class  CObject3D : public CObject
{
public:
	static const DWORD FVF_VERTEX_3D = (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	//頂点情報「3D」の構造体を定義
	struct VERTEX_3D
	{
		D3DXVECTOR3 pos;	// 頂点座標
		D3DXVECTOR3 nor;	// ベクトル
		D3DCOLOR col;		// カラー
		D3DXVECTOR2 tex;	// テクスチャ
	};

protected:
	//polygonの基準サイズ
	static const D3DXVECTOR3 m_Vtx[4];

public:

	static CObject3D *Create(int priority = CObjectList::LEVEL_DEBUG);

	CObject3D(int priority = CObjectList::LEVEL_DEBUG);
	~CObject3D() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	// 位置
	void SetPos(const D3DXVECTOR3& inPos) override;

	void SetRot(const D3DXVECTOR3& inRot);
	const D3DXVECTOR3& GetRot() const { return m_rot; }
	void SetSize(const D3DXVECTOR2& inSize);
	void AddSize(const D3DXVECTOR2& inSize) { SetSize((D3DXVECTOR2)m_size + inSize); }
	const D3DXVECTOR2& GetSize() const { return (D3DXVECTOR2)m_size; }

	void SetColor(const D3DXCOLOR& inColor);
	void SetTexture(std::string inTex) { m_texture = inTex; }	// テクスチャの設定

	LPDIRECT3DVERTEXBUFFER9 GetVtx() { return m_pVtxBuff; }	// 頂点バッファの取得
	const D3DXVECTOR3& GetNormal() const { return m_Normal; }

private:
	D3DXMATRIX* GiftMtx(D3DXMATRIX * pOut, const D3DXVECTOR3& inPos, const D3DXVECTOR3& inRot);

protected:
	LPDIRECT3DVERTEXBUFFER9	m_pVtxBuff;	// 頂点バッファ
	D3DXMATRIX m_mtxWorld;				// ワールドマトリックス
private:
	std::string m_texture;	// テクスチャ
	D3DXVECTOR3 m_Normal;

	D3DXCOLOR m_color;
	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_size;
};
#endif
