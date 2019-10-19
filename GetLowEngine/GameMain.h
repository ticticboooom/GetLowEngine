#pragma once
#include <memory>
#include "DeviceResources.h"

class GameMain
{
public:
	GameMain() = default;
	virtual ~GameMain() = default;
	virtual void CreateRenderers(const std::shared_ptr<DX::DeviceResources>& deviceResources) = 0;
	virtual void Update() = 0;
	virtual bool Render() = 0;
	virtual void OnKeyDown(UINT key) = 0;
	virtual void OnKeyUp(UINT key) = 0;
	virtual void OnMouseMoved(float x, float y)= 0;

	virtual void OnWindowSizeChanged() = 0;
	virtual void OnSuspending() = 0;
	virtual void OnResuming() = 0;
	virtual void OnDeviceRemoved() = 0;
};

