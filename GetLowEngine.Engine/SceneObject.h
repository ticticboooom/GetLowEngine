#pragma once
#include "GameMain.h"

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
};

