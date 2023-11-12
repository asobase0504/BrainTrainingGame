//**************************************************
// 
// texture.cpp
// Author  : katsuki mizuki
// Author  : Yuda Kaito
// 
//**************************************************

//==================================================
// インクルード
//==================================================
#include "application.h"
#include "renderer.h"
#include "texture.h"
#include "file.h"

#include <assert.h>

#include <locale>
#include <codecvt>

//--------------------------------------------------
// デフォルトコンストラクタ
//--------------------------------------------------
CTexture::CTexture()
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CTexture::~CTexture()
{
}

//--------------------------------------------------
// 全ての読み込み
//--------------------------------------------------
void CTexture::LoadAll()
{
	nlohmann::json list = LoadJsonStage(L"data/FILE/texture.json");
	
	for (int i = 0; i < (int)list["TEXTURE"].size(); ++i)
	{
		m_texturePath[list["TEXTURE"].at(i)[0]] = list["TEXTURE"].at(i)[1];
	}
}

//--------------------------------------------------
// 読み込み
//--------------------------------------------------
void CTexture::Load(std::string inKey, std::string inFileName)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	LPDIRECT3DTEXTURE9 texture = nullptr;
	std::string fileName = inFileName;

	// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, &fileName.front(), &texture);

	if (!ExistsKey(inKey))
	{
		m_texture.insert(std::make_pair(inKey, texture));
	}
	else
	{
		m_texture[inKey] = texture;
	}
}

//--------------------------------------------------
// 読み込み
//--------------------------------------------------
void CTexture::Load(std::vector<std::string> inTexture)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	LPDIRECT3DTEXTURE9 texture = nullptr;

	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring fileName = converter.from_bytes(inTexture[1]);

	D3DXIMAGE_INFO imgInfo;
	D3DXGetImageInfoFromFileW(&fileName.front(), &imgInfo);
	D3DXCreateTextureFromFileExW(pDevice,
		&fileName.front(),
		imgInfo.Width,
		imgInfo.Height,
		1,
		0,
		imgInfo.Format,
		D3DPOOL_MANAGED,
		D3DX_FILTER_LINEAR,
		D3DX_FILTER_LINEAR,
		0xff,
		nullptr,
		nullptr,
		&texture);	// テクスチャの読み込み

	if (!ExistsKey(inTexture[0]))
	{
		m_texture.insert(std::make_pair(inTexture[0], texture));
	}
	else
	{
		m_texture[inTexture[0]] = texture;
	}
}

//--------------------------------------------------
// 全ての解放
//--------------------------------------------------
void CTexture::UnloadAll(void)
{
	m_texture.clear();
}

//--------------------------------------------------
// 解放
//--------------------------------------------------
void CTexture::Unload(std::string inKey)
{
	m_texture.erase(inKey);
}

//--------------------------------------------------
// 取得
//--------------------------------------------------
LPDIRECT3DTEXTURE9 CTexture::GetTexture(std::string inKey)
{
	// Keyが存在するか否か。
	if (!ExistsKey(inKey))
	{
		if (!ExistsKeyPath(inKey))
		{
			// Keyがなかった場合
			return nullptr;
		}

		Load(inKey,m_texturePath[inKey]);
	}

	/* ↓Keyがあった場合↓ */

	return m_texture[inKey];
}
