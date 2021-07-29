#pragma once
#include "Component.h"
#include "SceneObject.h"

class ScenePart : public Component
{
public:
	ScenePart();
	~ScenePart() override;
	void CreateRenderers() override;
	void Init() override;
	void Update() override;
	void Render() override;
	void OnWindowSizeChanged() override;
	void OnSuspending() override;
	void OnResuming() override;
	void OnDeviceRemoved() override;
private:
	std::shared_ptr<std::vector<SceneObject>> sceneObjects = std::make_shared<std::vector<SceneObject>>();
protected:
	void AddObject(SceneObject obj);
};