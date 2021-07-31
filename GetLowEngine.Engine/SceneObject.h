#pragma once
#include "GameMain.h"
#include <memory>
#include <vector>
#include "Component.h"

class SceneObject : GameMain
{
public:
	SceneObject();
	~SceneObject();
	void CreateRenderers() override;
	void Init() override;
	void Update() override;
	void Render() override;
	void OnWindowSizeChanged() override;
	void OnSuspending() override;
	void OnResuming() override;
	void OnDeviceRemoved() override;
protected:
	void AddComponent(std::shared_ptr<Component> comp) const { m_components->push_back(comp); };
	std::shared_ptr<std::vector<std::shared_ptr<Component>>> m_components = std::make_shared<std::vector<std::shared_ptr<Component>>>();
};

