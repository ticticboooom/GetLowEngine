#pragma once
#include <memory>
#include "DeviceResources.h"
#include "RootSignatureHelper.h"
class Common
{
public:
	static std::shared_ptr<Common> GetInstance();
private:
	std::shared_ptr<Common> instance;
	std::shared_ptr<DX::DeviceResources> DeviceResources;
	std::shared_ptr<RootSignatureHelper> RootSignatureHelper;
	
};
