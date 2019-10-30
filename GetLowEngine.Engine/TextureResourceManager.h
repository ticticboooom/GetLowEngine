#pragma once
#include "pch.h"
#include "DeviceResources.h"
#include "CommandListManager.h"
#include "ResourceManager.h"
/**
 * @brief Creates the resource for putting the texture onto the graphics card
 * 
 */
class TextureResourceManager
{
public:
	 TextureResourceManager(std::wstring fileName, std::shared_ptr<DX::DeviceResources> deviceResources,
		std::shared_ptr<CommandListManager> commandListManager);
	 ~TextureResourceManager();
	 void CreateSRVFromTextureResource(Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvHeap, const UINT srvHeapSize,
	                                  const int descriptorSlot) const;
private:
	struct LoadedData
	{
		BYTE* textureData;
		int imageBytesPerRow;
	};
	LoadedData LoadTextureFromFile(std::wstring fileName);
	std::shared_ptr<DX::DeviceResources> m_deviceResources;
	D3D12_RESOURCE_DESC m_textureDesc; /// descriptor of texture
	std::unique_ptr<ResourceManager> m_resourceManager; /// resource manager for texture
};
