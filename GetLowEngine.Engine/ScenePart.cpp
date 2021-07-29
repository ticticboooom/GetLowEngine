#include "pch.h"
#include "ScenePart.h"



ScenePart::ScenePart()
= default;

ScenePart::~ScenePart()
= default;

void ScenePart::CreateRenderers()
{
}

void ScenePart::Init()
{
}

void ScenePart::Update()
{
}

void ScenePart::Render()
{
}

void ScenePart::OnWindowSizeChanged()
{
}

void ScenePart::OnSuspending()
{
}

void ScenePart::OnResuming()
{
}

void ScenePart::OnDeviceRemoved()
{
}

void ScenePart::AddObject(SceneObject obj)
{
	sceneObjects->push_back(obj);
}
