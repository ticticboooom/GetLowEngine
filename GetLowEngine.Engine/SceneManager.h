#pragma once
#include <map>

#include "Scene.h"

class SceneManager : public GameMain
{
public:
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
private:
	static std::shared_ptr<SceneManager> instance;
	std::shared_ptr<Scene> currentScene;
	std::map<std::string, std::shared_ptr<Scene>>& scenes;
};

