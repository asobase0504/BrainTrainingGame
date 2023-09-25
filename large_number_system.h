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

private:
	void WhichiNumberLargest_();
	void NumberLottery_();

private:
	std::vector<CLargestNumber*> m_pDisplayObject;
	std::vector<bool> m_isUsedNumber;
	// 最大の数を保存
	int m_nLargestNumber;
};

#endif	// _LARGE_NUMBER_SYSTEM_H_