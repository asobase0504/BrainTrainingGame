//============================
//
// ファイル設定
// Author:hamada ryuuga
//
//============================
#include "file.h"
#include <fstream>

//============================
// 読込み
//============================
nlohmann::json LoadJsonStage(const wchar_t* cUrl)
{
	std::ifstream ifs(cUrl);

	if (ifs)
	{
		nlohmann::json list;	// リストの作成

		ifs >> list;
		return list;
	}

	/* ↓ファイルを開くのを失敗した場合↓ */

	return nullptr;
}

//=============================================================================
// 読込み
// Author : Yuda Kaito
//=============================================================================
nlohmann::json LoadJson(const char* cUrl)
{
	std::ifstream ifs(cUrl);

	if (ifs)
	{
		nlohmann::json list;	// リストの作成

		ifs >> list;
		return list;
	}

	/* ↓ファイルを開くのを失敗した場合↓ */

	return nullptr;
}

//=============================================================================
// 読込み
// Author : Yuda Kaito
//=============================================================================
nlohmann::json LoadJson(std::string cUrl)
{
	std::ifstream ifs(cUrl);

	if (ifs)
	{
		nlohmann::json list;	// リストの作成

		ifs >> list;
		return list;
	}

	/* ↓ファイルを開くのを失敗した場合↓ */

	return nullptr;
}

//=============================================================================
// Jsonファイルでの書込み
// Author : Hamada Ryuuga
// Author : Yuda Kaito
//=============================================================================
void SaveJson(nlohmann::json inJson, const std::string cUrl)
{
	auto jobj = inJson.dump();
	std::ofstream writing_file;
	const std::string pathToJSON = cUrl;
	writing_file.open(pathToJSON, std::ios::out);
	writing_file << jobj << std::endl;
	writing_file.close();
}
