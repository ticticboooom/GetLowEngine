#pragma once
#include <map>
#include "PSOManager.h"
#include "RootSignatureManager.h"
#include "Scene.h"

class SceneManager : public GameMain
{
public:
	SceneManager() {}
	static std::shared_ptr<SceneManager> GetInstance();
	void AddScene(std::string key, std::shared_ptr<Scene> scene);
	void SetScene(std::string name);
	void CreateRenderers() override;
	void Init() override;
	void Update() override;
	void Render() override;

	void OnWindowSizeChanged() override;
	void OnSuspending() override;
	void OnResuming() override;
	void OnDeviceRemoved() override;
	std::shared_ptr<RootSignatureManager> CreateRootSignatures(
		const std::shared_ptr<DX::DeviceResources>& deviceResources) const;
private:
	std::shared_ptr<PSOManager> psoManager;
	static std::shared_ptr<SceneManager> instance;
	std::shared_ptr<Scene> currentScene;
	std::map<std::string, std::shared_ptr<Scene>> scenes;
	D3D12_RECT m_scissorRect;
};

