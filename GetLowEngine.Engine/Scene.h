#pragma once
#include "GameMain.h"
#include "ScenePart.h"
#include <vector>


class Scene : public GameMain
{
public:
	Scene();
	void CreateRenderers() override;
	void Init() override;
	void Update() override;
	void Render() override;
	void OnWindowSizeChanged() override;
	void OnSuspending() override;
	void OnResuming() override;
	void OnDeviceRemoved() override;
	void AddRenderer(std::shared_ptr<ScenePart> renderer);
	CD3DX12_SHADER_BYTECODE GetVertexShader();
	CD3DX12_SHADER_BYTECODE GetPixelShader();

protected:
	std::shared_ptr<std::vector<std::shared_ptr<ScenePart>>> renderers;

private:
	std::unique_ptr<std::wstring> assetPath;
};

