//============================
//
// ファイル設定ヘッター
// Author:hamada ryuuga
//
//============================
#ifndef _FILE_H_	// このマクロ定義がされてなかったら
#define _FILE_H_	// 二重インクルード防止のマクロ定義

#include "block.h"
#include "nlohmann/json.hpp"

//=====================================
// プロトタイプ宣言
//=====================================
nlohmann::json LoadJsonStage(const wchar_t* cUrl);
nlohmann::json LoadJson(const char* cUrl);
nlohmann::json LoadJson(std::string cUrl);
void SaveJson(nlohmann::json inJson, const std::string cUrl);

#endif
