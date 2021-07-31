#include "pch.h"
#include "TextureManager.h"
#include "TextureResourceLoader.h"
#include <string>
#include "DescriptorHeapManager.h"
std::shared_ptr<TextureManager> TextureManager::instance = std::make_shared<TextureManager>();

TextureManager::TextureManager()
{
	m_SRVSlot = 0;
}

std::shared_ptr<TextureManager> TextureManager::GetInstance()
{
	return instance;
}

int TextureManager::CreateSRVFromTextureFile(std::wstring texturePath)
{
	auto loader = TextureResourceLoader(texturePath.c_str(), DX::DeviceResources::GetInstance(), CommandListManager::GetInstance());
	int index = DescriptorHeapManager::GetInstance()->GetAndIncrement();
	loader.CreateSRVFromTextureResource(DescriptorHeapManager::GetInstance()->Get(), DescriptorHeapManager::GetInstance()->GetDescriptorSize(), index);
	return index;
}
