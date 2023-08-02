//=============================================================================
//
// カメラ
// Author : Hamada Ryuuga
// Author : Yuda Kaito
//
//=============================================================================
#ifndef _CAMERA_H_
#define _CAMERA_H_

//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "renderer.h"

//=============================================================================
// カメラクラス
//=============================================================================
class CCamera
{
private:
	static const float VIEWING_ANGLE;	// 視野角
public:
	CCamera();
	~CCamera();

	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void Set();

	// Getter
	const D3DXMATRIX& GetMtxProje() { return m_MtxProject; }
	const D3DXMATRIX& GetMtxView() { return m_MtxView; }
	const D3DXVECTOR3& GetPos() { return m_posV; }

	const D3DXVECTOR3& VectorCombinedRot(const D3DXVECTOR3& inVector);

	// カメラを揺らす
	void Shake(float ShakeFrame, float Magnitude);

protected:
	D3DXVECTOR3 m_posV;			// 位置
	D3DXVECTOR3 m_posVDest;		// 目的地からの差
	D3DXVECTOR3 m_posR;			// 注視点
	D3DXVECTOR3 m_posRDest;		// 目的地からの差
	D3DXVECTOR3 m_vecU;			// ベクトル
	D3DXVECTOR3 m_rot;			// 位置回転
	D3DXMATRIX m_MtxProject;	// プロジェクションマトリックス
	D3DXMATRIX m_MtxView;		// ビューマトリックス
	int m_Type;

	/* 揺れ */
	float m_nCntFrame;	// 揺れるフレームカウント
	float m_Magnitude;	// 揺れ
};

#endif		// _CAMERA_H_
