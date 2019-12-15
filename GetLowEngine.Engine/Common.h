#pragma once
#include <memory>
#include "DeviceResources.h"
#include "RootSignatureHelper.h"
#include "DescriptorHeapManager.h"

class Common
{
public:
	static std::shared_ptr<Common> GetInstance();
	std::shared_ptr<DX::DeviceResources> GetDeviceResources() const { return this->m_DeviceResources; };
	std::shared_ptr<RootSignatureHelper> GetRootSignatureHelper() const { return this->m_RootSignatureHelper; };
	std::shared_ptr<DescriptorHeapManager> GetDescriptorHeapManager() const { return this->m_DescriptorHeapManager; };
	std::shared_ptr<CommandListManager> GetCommandListManager() const { return this->m_CommandListManager; };
	void SetDeviceResource(std::shared_ptr<DX::DeviceResources> dr) { this->m_DeviceResources = dr; };
	void InitRootSignatureHelper();
	void InitDescriptorHeapManager();
private:
	static std::shared_ptr<Common> instance;
	std::shared_ptr<DX::DeviceResources> m_DeviceResources;
	std::shared_ptr<RootSignatureHelper> m_RootSignatureHelper;
	std::shared_ptr<DescriptorHeapManager> m_DescriptorHeapManager;
	std::shared_ptr<CommandListManager> m_CommandListManager;
	static void Init();
};

