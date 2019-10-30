#include "pch.h"
#include "RootSignatureHelper.h"

std::shared_ptr<RootSignatureHelper> RootSignatureHelper::GetInstance()
{
	if (instance == nullptr)
	{
		instance = std::make_shared<RootSignatureHelper>();
	}
}


void RootSignatureHelper::InitDescriptorRange(D3D12_DESCRIPTOR_RANGE_TYPE Type, UINT Register, UINT Count,
	D3D12_SHADER_VISIBILITY Visibility)
{
	auto parameter = std::make_shared<RootParameter>();
	parameter->InitAsDescriptorRange(Type, Register, Count, Visibility);
	instance->rootSignatureManager->operator[](0)->AddNewParameter(parameter);
}

void RootSignatureHelper::Init(UINT count)
{
	std::shared_ptr<RootSignatureManager> signatureManager = std::make_shared<RootSignatureManager>();
	signatureManager->AddSignature();
}
