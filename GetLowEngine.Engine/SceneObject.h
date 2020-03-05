#pragma once
#include "GameMain.h"

class SceneObject : GameMain
{
	SceneObject();
	~SceneObject();
	void CreateRenderers(const std::shared_ptr<DX::DeviceResources>& deviceResources) override;
	void Init() override;
	void Update() override;
	void Render() override;
	void OnKeyDown(UINT key) override;
	void OnKeyUp(UINT key) override;
	void OnMouseMoved(float x, float y) override;
	void OnWindowSizeChanged() override;
	void OnSuspending() override;
	void OnResuming() override;
	void OnDeviceRemoved() override;
};

