#include "pch.h"
#include "Common.h"

std::shared_ptr<Common> Common::instance;

std::shared_ptr<Common> Common::GetInstance()
{
	if (instance == nullptr)
	{
		Init();
	}
	return instance;
}

void Common::InitRootSignatureHelper()
{
	this->m_RootSignatureHelper = RootSignatureHelper::GetInstance();	
}

void Common::InitDescriptorHeapManager()
{
	this->m_DescriptorHeapManager = std::make_shared<DescriptorHeapManager>(
		RootSignatureHelper::GetInstance()->GetParameterCount(), 
		D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, 
		D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE,
		m_DeviceResources);
}

void Common::Init()
{
	instance = std::make_shared<Common>();
	instance->InitRootSignatureHelper();
}
