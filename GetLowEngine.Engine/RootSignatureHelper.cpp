#include "pch.h"
#include "RootSignatureHelper.h"
#include "Common.h"

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


void RootSignatureHelper::InitDescriptorRange(D3D12_DESCRIPTOR_RANGE_TYPE Type, UINT Register, UINT Count,
	D3D12_SHADER_VISIBILITY Visibility)
{
	auto parameter = std::make_shared<RootParameter>();
	parameter->InitAsDescriptorRange(Type, Register, Count, Visibility);
	m_params.push_back(parameter);
}

void RootSignatureHelper::Init()
{
	rootSignatureManager = std::make_shared<RootSignatureManager>();
	const auto dv = Common::GetInstance()->GetDeviceResources();
	rootSignatureManager->AddSignature(dv, m_params.size(), 1);
	for (auto & param : m_params)
	{
		rootSignatureManager->operator[](0)->AddNewParameter(param);
	}
}
