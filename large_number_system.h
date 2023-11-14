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
class CGame;

//**************************************************
// クラス
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

	bool GetMode() { return m_mode; } // trueは最大 falseは最小

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

	// 最大の数を保存
	int m_nMaxNumber;
	// 最小の値を保存
	int m_nMinNumber;
	// 最大か最小か
	int m_minOrMax;
	// モード
	bool m_mode;
	// タイムラグ
	int m_rug;
	// フレーム
	int m_frame;
	// 
	bool m_isTrue;
	// 
	bool m_isAnswer;

	// 前回のレベル
	int m_oldLevel;

	// 正解
	int m_correct;			// 今回のレベルの正解数
	int m_nextNeedCorrect;	// 次のレベルにいくための正解数
};

#endif	// _LARGE_NUMBER_SYSTEM_H_