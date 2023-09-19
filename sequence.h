//==================================================
// time.h
// Author: Buriya Kota
//==================================================
#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

//**************************************************
// �C���N���[�h
//**************************************************
#include "object.h"

//**************************************************
// �O���O���@���Ԃ�NG�@�|�C���^�����Ȃ�OK
//**************************************************
class CNumber;

//**************************************************
// �N���X
//**************************************************
class CSequence : public CObject
{
private:
	static const int NUM_DIGIT = 3;
public:
public:
	explicit CSequence();
	~CSequence() override;

	HRESULT Init() override;
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size, const int digit);
	void Uninit() override;
	void Update() override;
	void Draw() override {}

	void SetPos(const D3DXVECTOR3& inPos) override;

	void SetColor(const D3DXCOLOR& inColor);

	void AddSize(const D3DXVECTOR2& inSize);

	void SetNumber(int inNumber);
	int GetNumber() { return m_number; }

	static CSequence* Create(D3DXVECTOR3 pos, D3DXVECTOR2 size,const int digit);

private:
	// Number�^�̔z��
	std::vector<CNumber*> m_pNumber;
	// ����
	int m_number;
	int m_digit;
};

#endif // _TIMER_H_