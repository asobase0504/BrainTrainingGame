//=========================================
// 
// オブジェクトクラス
// Author YudaKaito
// 
//=========================================
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <d3dx9.h>
#include <list>
#include <vector>
#include "objectList.h"

#include "task.h"

class CObject : public CTask
{
public:	// 定数

public:	// 静的関数

public:
	CObject(int priority = CTaskGroup::LEVEL_SYSTEM);
	virtual ~CObject();

	virtual HRESULT Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() {};

	/* 位置 */
	virtual void SetPos(const D3DXVECTOR3& inPos);	// 位置の設定
	virtual void AddPos(const D3DXVECTOR3& inPos) { SetPos(m_pos + inPos); }	// 位置の設定
	const D3DXVECTOR3& GetPos() { return m_pos; }	// 位置の取得

	/* 親子関係 */
	CObject* AttachParent(CObject* inParent) { inParent->AttachChildren(this); return inParent; }
	void AttachChildren(CObject* inChild) { m_children.push_back(inChild); inChild->m_parent = this; }

private:
	CObject* m_prev;	// 前のオブジェクト
	CObject* m_next;	// 次のオブジェクト

	bool m_isActivityAtPause;	// ポーズ中も更新できるか
	bool m_shouldInvisible;		// 停止中に描画も止めるべきか

	bool m_isDeleted;	// 削除フラグ

protected:
	CObject* m_parent;
	std::vector<CObject*> m_children;
	D3DXVECTOR3 m_pos;	// 位置
};

#endif // !_RENDERER_H_
