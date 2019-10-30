#pragma once
#include <memory>
#include "RootSignatureManager.h"
class RootSignatureHelper
{

public:
	static std::shared_ptr<RootSignatureHelper> GetInstance();
	void InitDescriptorRange(D3D12_DESCRIPTOR_RANGE_TYPE Type, UINT Register, UINT Count,
	                         D3D12_SHADER_VISIBILITY Visibility = D3D12_SHADER_VISIBILITY_ALL);
	void Init(UINT count);
private:
	RootSignatureHelper() = default;
	~RootSignatureHelper() = default;
	int rangeCount = 0;
	std::shared_ptr<RootSignatureManager> rootSignatureManager;
	static std::shared_ptr<RootSignatureHelper> instance;
};
