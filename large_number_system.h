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

//**************************************************
// �N���X
//**************************************************
class CLargeNumberSystem : public CObject
{
public:
	static const int DISPLAY_NUMBER;
	static const int X_LINE;
	static const int Y_LINE;
	static const int MAX_NUMBER;

public:
	explicit CLargeNumberSystem(int nPriority = CTaskGroup::LEVEL_2D_1);
	~CLargeNumberSystem();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CLargeNumberSystem *Create();

	bool GetMode() { return m_mode; } // true�͍ő� false�͍ŏ�

private:
	void WhichiNumberMax_();
	void WhichiNumberMin_();
	void NumberLottery_();
	void SetMode();
	void InitCreateAnswer_();
	void CorrectAnswer_(int inNumber);

private:
	std::vector<CLargestNumber*> m_pDisplayObject;
	std::vector<bool> m_isUsedNumber;
	// �ő�̐���ۑ�
	int m_nMaxNumber;
	// �ŏ��̒l��ۑ�
	int m_nMinNumber;
	// �ő傩�ŏ���
	int m_minOrMax;
	// ���[�h
	bool m_mode;
};

#endif	// _LARGE_NUMBER_SYSTEM_H_