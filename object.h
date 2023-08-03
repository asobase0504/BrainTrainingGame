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

class CObject
{
public:	// 定数

public:	// 静的関数

public:
	CObject(int priority = CObjectList::LEVEL_SYSTEM);
	virtual ~CObject();

	virtual HRESULT Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() {};

	// Setter
	void SetIsDeleted(bool inDeleted) { m_isDeleted = inDeleted; }		// 死亡状態を設定
	virtual void SetPos(const D3DXVECTOR3& inPos);	// 位置の設定

	// Getter
	const D3DXVECTOR3& GetPos() { return m_pos; }	// 位置の取得
	const bool GetIsDeleted() { return m_isDeleted; }
	int GetPriority() { return m_assignmentPriority; }

	/* リスト構造 */
	void SetPrev(CObject* inTask) { m_prev = inTask; }
	CObject* GetPrev() { return m_prev; }
	void SetNext(CObject* inTask) { m_next = inTask; }
	CObject* GetNext() { return m_next; }

	/* 削除フラグ */
	void Release() { m_isDeleted = true; }
	bool IsRelease() { return m_isDeleted; }

	/* ポーズ中の状態 */
	void AttachActivityAtPouse() { m_isActivityAtPouse = true; }
	bool IsActivityAtPouse() { return m_isActivityAtPouse; }

	/* 親子関係 */
	CObject* AttachParent(CObject* inParent) { inParent->AttachChildren(this); return inParent; }
	void AttachChildren(CObject* inChild) { m_children.push_back(inChild); inChild->m_parent = this; }

private:
	int m_assignmentPriority;	// 所属しているプライオリティ

	CObject* m_prev;	// 前のオブジェクト
	CObject* m_next;	// 次のオブジェクト

	bool m_isActivityAtPouse;	// ポーズ中も更新できるか
	bool m_shouldInvisible;		// 停止中に描画も止めるべきか

	bool m_isDeleted;	// 削除フラグ

protected:
	CObject* m_parent;
	std::vector<CObject*> m_children;
	D3DXVECTOR3 m_pos;	// 位置
};

#endif // !_RENDERER_H_
