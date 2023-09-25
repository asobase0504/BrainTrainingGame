//==================================================
// large_number_system.h
// Author: Buriya Kota
//==================================================
#ifndef _LARGE_NUMBER_SYSTEM_H_
#define _LARGE_NUMBER_SYSTEM_H_

//**************************************************
// インクルード
//**************************************************
#include "object.h"

//**************************************************
// 前方前言　実態はNG　ポインタだけならOK
//**************************************************
class CLargestNumber;

//**************************************************
// クラス
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

	bool GetMode() { return m_mode; } // trueは最大 falseは最小

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
	// 最大の数を保存
	int m_nMaxNumber;
	// 最小の値を保存
	int m_nMinNumber;
	// 最大か最小か
	int m_minOrMax;
	// モード
	bool m_mode;
};

#endif	// _LARGE_NUMBER_SYSTEM_H_