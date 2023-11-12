//**************************************************
// 
// texture.cpp
// Author  : katsuki mizuki
// Author  : Yuda Kaito
// 
//**************************************************

//==================================================
// �C���N���[�h
//==================================================
#include "application.h"
#include "renderer.h"
#include "texture.h"
#include "file.h"

#include <assert.h>

#include <locale>
#include <codecvt>

//--------------------------------------------------
// �f�t�H���g�R���X�g���N�^
//--------------------------------------------------
CTexture::CTexture()
{
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
CTexture::~CTexture()
{
}

//--------------------------------------------------
// �S�Ă̓ǂݍ���
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
// �ǂݍ���
//--------------------------------------------------
void CTexture::Load(std::string inKey, std::string inFileName)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	LPDIRECT3DTEXTURE9 texture = nullptr;
	std::string fileName = inFileName;

	// �e�N�X�`���̓ǂݍ���
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
// �ǂݍ���
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
		&texture);	// �e�N�X�`���̓ǂݍ���

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
// �S�Ẳ��
//--------------------------------------------------
void CTexture::UnloadAll(void)
{
	m_texture.clear();
}

//--------------------------------------------------
// ���
//--------------------------------------------------
void CTexture::Unload(std::string inKey)
{
	m_texture.erase(inKey);
}

//--------------------------------------------------
// �擾
//--------------------------------------------------
LPDIRECT3DTEXTURE9 CTexture::GetTexture(std::string inKey)
{
	// Key�����݂��邩�ۂ��B
	if (!ExistsKey(inKey))
	{
		if (!ExistsKeyPath(inKey))
		{
			// Key���Ȃ������ꍇ
			return nullptr;
		}

		Load(inKey,m_texturePath[inKey]);
	}

	/* ��Key���������ꍇ�� */

	return m_texture[inKey];
}
