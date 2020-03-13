#pragma once
#include <memory>
#include "DeviceResources.h"

class GameMain
{
public:
	GameMain() = default;
	virtual ~GameMain() = default;
	virtual void CreateRenderers() = 0;
	virtual void Init() = 0;
	virtual void Update();
	virtual void Render();

	virtual void OnWindowSizeChanged();
	virtual void OnSuspending();
	virtual void OnResuming();
	virtual void OnDeviceRemoved();
};

