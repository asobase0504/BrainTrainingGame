//==========================================
//
//  �o�����ɉ���(minigame_comeout.h)
//  Author : Tomoya Kanazaki
//
//==========================================
#ifndef _MINIGAME_COMEOUT_H_
#define _MINIGAME_COMEOUT_H_
#include "game.h"

//==========================================
//  �O���錾
//==========================================
class CTarget;
class CObject2D;

//==========================================
//  �N���X��`
//==========================================
class CMiniGameComeOut : public CGame
{
public:

	//�����o�֐�
	CMiniGameComeOut();
	~CMiniGameComeOut();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void GameStart();

	//�ÓI�����o�֐�
	static bool GetClick() { return m_bClick; }

private:

	//�����o�֐�
	void Load(void);
	void Set(void);
	void Reset(void);

	//�����o�ϐ�
	std::vector<CTarget*> m_pTarget;
	D3DXVECTOR3 m_pos;
	D3DXVECTOR2 m_size;
	D3DXVECTOR2 m_alignment;
	D3DXVECTOR3 *m_pPos;
	int m_nNumData; //�o�Ă��鐔
	int m_nInterval; //�o�Ă���Ԋu
	int m_nTime; //�o�ߎ���
	int m_nPopTime; //�������������鎞��
	int m_nSpeed; //���Ԃ̌v��
	int m_nNext; //���̃^�[�Q�b�g
	bool *m_pUse; //�g�p�t���O

	//�ÓI�����o�ϐ�
	static bool m_bClick; //�N���b�N�\���

	CObject2D* m_BG;
};

#endif
