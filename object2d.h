//=========================================
// 
// オブジェクトクラス
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
	// 構造体定義
	//*****************************************************************************
	// 頂点データ
	struct VERTEX_2D
	{
		D3DXVECTOR3 pos;
		float rhw;
		D3DCOLOR col;
		D3DXVECTOR2 tex;
	};

	// 頂点フォーマット
	static const DWORD FVF_VERTEX_2D = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

public:	// 静的関数
	static CObject2D* Create(int inPriority = 3);

public:
	CObject2D(int inPriority = 3);
	~CObject2D() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	// 中心座標
	void SetAnchor(Anchor inAnvhor) { m_anchor = inAnvhor; }

	// 位置
	void SetPos(const D3DXVECTOR3& inPos) override;
	void AddPos(const D3DXVECTOR3& move) { SetPos(m_pos + move); }

	void SetRot(const float inRot);
	void AddRot(const float inRot) { SetRot(inRot + m_rotY); }

	// 多きさ
	void SetSize(const D3DXVECTOR2& inSize);
	const D3DXVECTOR2 GetSize() { return m_size; }

	// 動き
	void SetMove(const D3DXVECTOR3& inMove);
	const D3DXVECTOR3 GetMove() { return m_move; }

	// アニメーション
	void SetTexture(std::string inTex) { m_texture = inTex; }	// テクスチャの設定
	void AnimTexture(int num, int texMax);

	// 色
	void SetColor(const D3DXCOLOR& inColor);
	const D3DXCOLOR GetColor() { return m_col; }
	void SetColorAlpha(const float inAlpha);
	void AddColorAlpha(const float inAlpha) { SetColorAlpha(m_col.a + inAlpha); }
	float GetColorAlpha() { return m_col.a; }

private:
	void Vtx();
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	// VtxBuff
	Anchor m_anchor;	// アンカーの設定
	std::string m_texture;	// テクスチャ
	float m_rotY;			// 回転
	float m_fLength;		// 長さ
	float m_fAngle;		// 角度


protected:
	D3DXVECTOR2 m_size;	// 大きさ
	D3DXVECTOR3 m_move;	// 動き
	D3DXCOLOR m_col;	// 色
};

#endif // !_OBJECT2D_H_
