//=========================================
// 
// �Q�[�����N���X
// Author BuriyaKota
// 
//=========================================
#ifndef _MINI_GAME_MOVEOBJECT_H_
#define _MINI_GAME_MOVEOBJECT_H_

#include "mode.h"

//-----------------------------------------
// �O���錾
//-----------------------------------------
class CMoveObject;

//-----------------------------------------
// �A�v���P�[�V�����N���X
//-----------------------------------------
class CMiniGameMoveObject : public CMode
{
public:	// �񋓌^
	enum class ELevel
	{
		LEVEL_1 = 0,
		LEVEL_2,
		LEVEL_3,
	};

public:	// �����o�[�֐�
	CMiniGameMoveObject();
	~CMiniGameMoveObject() override;

	HRESULT Init() override;
	void Uninit() override;

	// �X�V����
	void Update() override;

	void Draw() override;

private:

private:
	ELevel m_level;
	std::vector<CMoveObject*> m_popObject;
};

#endif // !_MINI_GAME_NUMBER25_H_
