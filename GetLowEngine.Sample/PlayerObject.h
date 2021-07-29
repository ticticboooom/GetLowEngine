#pragma once
#include "../GetLowEngine.Engine/SceneObject.h"
class PlayerObject : public SceneObject
{
	void CreateRenderers() override;
	void Init() override;
};

