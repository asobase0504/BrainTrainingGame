//============================
//
// �t�@�C���ݒ�w�b�^�[
// Author:hamada ryuuga
//
//============================
#ifndef _FILE_H_	// ���̃}�N����`������ĂȂ�������
#define _FILE_H_	// ��d�C���N���[�h�h�~�̃}�N����`

#include "block.h"
#include "nlohmann/json.hpp"

//=====================================
// �v���g�^�C�v�錾
//=====================================
nlohmann::json LoadJsonStage(const wchar_t* cUrl);
nlohmann::json LoadJson(const char* cUrl);
nlohmann::json LoadJson(std::string cUrl);
void SaveJson(nlohmann::json inJson, const std::string cUrl);

#endif
