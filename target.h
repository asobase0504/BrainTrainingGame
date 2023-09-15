//==========================================
//
//  �������(target.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _TARGET_H_
#define _TARGET_H_
#include "object2d.h"

//==========================================
//  �N���X��`
//==========================================
class CTarget : CObject2D
{
public:

	//�����o�֐�
	CTarget();
	~CTarget();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

private:

	//�����o�ϐ�
	int m_nID;

};

#endif