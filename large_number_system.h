//==================================================
// large_number_system.h
// Author: Buriya Kota
//==================================================
#ifndef _LARGE_NUMBER_SYSTEM_H_
#define _LARGE_NUMBER_SYSTEM_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object.h"

//**************************************************
// �O���O���@���Ԃ�NG�@�|�C���^�����Ȃ�OK
//**************************************************
class CLargestNumber;
class CGame;

//**************************************************
// �N���X
//**************************************************
class CLargeNumberSystem : public CObject
{
public:
	static int DISPLAY_NUMBER;
	static int X_LINE;
	static int Y_LINE;
	static const int MAX_NUMBER;
	static const int TRUE_FLAME;
	static const int FALSE_FLAME;

public:
	explicit CLargeNumberSystem(int nPriority = CTaskGroup::LEVEL_2D_1);
	~CLargeNumberSystem();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CLargeNumberSystem *Create(CGame* inGame);

	bool GetMode() { return m_mode; } // true�͍ő� false�͍ŏ�

private:
	void WhichiNumberMax_();
	void WhichiNumberMin_();
	void NumberLottery_();
	void SetMode();
	void InitCreateAnswer_();
	void CorrectAnswer_(int inNumber);
	void Reset_();

private:
	std::vector<CLargestNumber*> m_pDisplayObject;
	std::vector<bool> m_isUsedNumber;

	CGame* m_game;

	// �ő�̐���ۑ�
	int m_nMaxNumber;
	// �ŏ��̒l��ۑ�
	int m_nMinNumber;
	// �ő傩�ŏ���
	int m_minOrMax;
	// ���[�h
	bool m_mode;
	// �^�C�����O
	int m_rug;
	// �t���[��
	int m_frame;
	// 
	bool m_isTrue;
	// 
	bool m_isAnswer;

	// �O��̃��x��
	int m_oldLevel;

	// ����
	int m_correct;			// ����̃��x���̐���
	int m_nextNeedCorrect;	// ���̃��x���ɂ������߂̐���
};

#endif	// _LARGE_NUMBER_SYSTEM_H_