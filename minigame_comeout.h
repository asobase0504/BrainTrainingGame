//==========================================
//
//  出た順に押す(minigame_comeout.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _MINIGAME_COMEOUT_H_
#define _MINIGAME_COMEOUT_H_
#include "game.h"

//==========================================
//  前方宣言
//==========================================
class CTarget;
class CObject2D;

//==========================================
//  クラス定義
//==========================================
class CMiniGameComeOut : public CGame
{
public:

	//メンバ関数
	CMiniGameComeOut();
	~CMiniGameComeOut();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void GameStart();

	//静的メンバ関数
	static bool GetClick() { return m_bClick; }

private:

	//メンバ関数
	void Load(void);
	void Set(void);
	void Reset(void);

	//メンバ変数
	std::vector<CTarget*> m_pTarget;
	D3DXVECTOR3 m_pos;
	D3DXVECTOR2 m_size;
	D3DXVECTOR2 m_alignment;
	D3DXVECTOR3 *m_pPos;
	int m_nNumData; //出てくる数
	int m_nInterval; //出てくる間隔
	int m_nTime; //経過時間
	int m_nPopTime; //生成が完了する時間
	int m_nSpeed; //時間の計測
	int m_nNext; //次のターゲット
	bool *m_pUse; //使用フラグ

	//静的メンバ変数
	static bool m_bClick; //クリック可能状態

	CObject2D* m_BG;
};

#endif
