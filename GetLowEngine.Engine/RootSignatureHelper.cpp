#include "pch.h"
#include "RootSignatureHelper.h"

std::shared_ptr<RootSignatureHelper> RootSignatureHelper::instance = nullptr;

std::shared_ptr<RootSignatureHelper> RootSignatureHelper::GetInstance()
{
	if (instance == nullptr)
	{
		instance = std::make_shared<RootSignatureHelper>();
		instance->m_params = std::vector<std::shared_ptr<RootParameter>>();
	}
	return instance;
}


size_t RootSignatureHelper::InitDescriptorRange(D3D12_DESCRIPTOR_RANGE_TYPE Type, UINT Register, UINT Count,
	D3D12_SHADER_VISIBILITY Visibility)
{
	auto parameter = std::make_shared<RootParameter>();
	parameter->InitAsDescriptorRange(Type, Register, Count, Visibility);
	m_params.push_back(parameter);
	return m_params.size() - 1;
}

void RootSignatureHelper::Init()
{
	rootSignatureManager = std::make_shared<RootSignatureManager>();
	rootSignatureManager->AddSignature(DX::DeviceResources::GetInstance(), 0, 1);
	const auto dv = DX::DeviceResources::GetInstance();
	rootSignatureManager->AddSignature(dv, m_params.size(), 1);
	D3D12_SAMPLER_DESC sampler;
	sampler.Filter = D3D12_FILTER_MIN_MAG_MIP_POINT;
	sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
	sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
	sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
	sampler.MipLODBias = 0;
	sampler.MaxAnisotropy = 0;
	sampler.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
	sampler.MinLOD = 0.0f;
	sampler.MaxLOD = D3D12_FLOAT32_MAX;
	(*rootSignatureManager)[0]->InitStaticSampler(0, sampler, D3D12_SHADER_VISIBILITY_PIXEL);
	for (auto& param : m_params)
	{
		rootSignatureManager->operator[](0)->AddNewParameter(param);
	}
}


void RootSignatureHelper::AddSignatureManager(std::shared_ptr<RootSignatureManager> manager)
{
	this->rootSignatureManager = manager;
}