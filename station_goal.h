//=========================================
// 
// �w�S�ʃN���X
// Author YudaKaito
// 
//=========================================
#ifndef _STATION_GOAL_H_
#define _STATION_GOAL_H_

#include "station.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CBus;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CStationGoal : public CStation
{
private: // �񋓌^

public:	// �����o�[�֐�
	CStationGoal();
	virtual ~CStationGoal() override;

	// �X�V����
	virtual void Update() override;

private: // ���I�v���C�x�[�g�֐�

private: // ���I�����o�[�ϐ�

};

#endif // !_GAME_H_
