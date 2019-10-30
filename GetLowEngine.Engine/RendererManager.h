#pragma once
#include "GameMain.h"
#include "Renderer.h"
#include <vector>


class RendererManager : public GameMain
{
public:
	RendererManager();
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
	void AddRenderer(std::shared_ptr<Renderer> renderer);

protected:
	std::shared_ptr<std::vector<std::shared_ptr<Renderer>>> renderers;
};

