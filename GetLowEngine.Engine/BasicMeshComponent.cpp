#include "pch.h"
#include "BasicMeshComponent.h"
#include "RootSignatureHelper.h"
void BasicMeshComponent::Init()
{
	RootSignatureHelper::GetInstance()->InitDescriptorRange(D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 0, 1, D3D12_SHADER_VISIBILITY_PIXEL);
}
