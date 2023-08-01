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

class CObject
{
public:	// 列挙型
	// CObjectクラスの派生先
	enum class TYPE
	{
		CHARACTER = 0,
		BULLET,
		BLOCK,
		NONE
	};

public:	// 定数

public:	// 静的関数

public:
	CObject(TYPE type,int priority = 3);
	virtual ~CObject();

	virtual HRESULT Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	// Setter
	void SetIsDeleted(bool inDeleted) { m_isDeleted = inDeleted; }		// 死亡状態を設定
	void SetShouldStopAlsoUpdate() { m_shouldStopAlsoUpdate = true; }
	virtual void SetPos(const D3DXVECTOR3& inPos) { m_pos = inPos; }	// 位置の設定

	// Getter
	const D3DXVECTOR3& GetPos() { return m_pos; }	// 位置の取得
	const TYPE GetType() { return m_type; }
	const bool GetIsDeleted() { return m_isDeleted; }

	/* リスト構造 */
	void SetPrev(CObject* inTask) { m_prev = inTask; }
	CObject* GetPrev() { return m_prev; }
	void SetNext(CObject* inTask) { m_next = inTask; }
	CObject* GetNext() { return m_next; }

	/* 削除フラグ */
	void Release() { m_isDeleted = true; }
	bool IsRelease() { return m_isDeleted; }

	bool IsActivityAtPouse() { return m_isActivityAtPouse; }
	int GetPriority() { return m_assignmentPriority; }
private:

private:
	bool m_shouldStopAlsoUpdate;	// 停止中も更新すべきか
	bool m_shouldInvisible;		// 停止中に描画も止めるべきか

	CObject* m_prev;	// 前のオブジェクト
	CObject* m_next;	// 次のオブジェクト

	int m_assignmentPriority;
	bool m_isActivityAtPouse;
protected:
	D3DXVECTOR3 m_pos;	// 位置
	bool m_isDeleted;	// 削除フラグ
	TYPE m_type;		// 種類
};

#endif // !_RENDERER_H_
