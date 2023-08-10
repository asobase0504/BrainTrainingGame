//=========================================
// 
// 動いてる物体クラス
// Author YudaKaito
// 
//=========================================
#ifndef _MOVE_OBJECT_H_
#define _MOVE_OBJECT_H_

#include "../object2d.h"
#include "../minigame_moveobject.h"

//-----------------------------------------
// 前方宣言
//-----------------------------------------

//-----------------------------------------
// アプリケーションクラス
//-----------------------------------------
class CMoveObject : public CObject2D
{
private: // 列挙型

public:	// メンバー関数
	CMoveObject();
	virtual ~CMoveObject() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;

	// 更新処理
	virtual void Update() override;

	static CMoveObject* Create(CMiniGameMoveObject::ELevel* level, const int index, const D3DXVECTOR3& inPos);

	int ClikEvent() { return m_textureIndex; }

private: // 動的プライベート関数

private: // 動的メンバー変数
	CMiniGameMoveObject::ELevel* m_level;
	int m_textureIndex;	// 見た目の番号
	D3DXVECTOR3 m_move;
};

#endif // !_GAME_H_
