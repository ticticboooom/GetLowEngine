#include "pch.h"
#include "ScenePart.h"



ScenePart::ScenePart()
= default;

ScenePart::~ScenePart()
= default;

void ScenePart::CreateRenderers()
{
	for (auto c : *sceneObjects) {
		c.CreateRenderers();
	}
}

void ScenePart::Init()
{
	for (auto c : *sceneObjects) {
		c.Init();
	}
}

void ScenePart::Update()
{
	for (auto c : *sceneObjects) {
		c.Update();
	}
}

void ScenePart::Render()
{
	for (auto c : *sceneObjects) {
		c.Render();
	}
}

void ScenePart::OnWindowSizeChanged()
{
	for (auto c : *sceneObjects) {
		c.OnWindowSizeChanged();
	}
}

void ScenePart::OnSuspending()
{
	for (auto c : *sceneObjects) {
		c.OnSuspending();
	}
}

void ScenePart::OnResuming()
{
	for (auto c : *sceneObjects) {
		c.OnResuming();
	}
}

void ScenePart::OnDeviceRemoved()
{
	for (auto c : *sceneObjects) {
		c.OnDeviceRemoved();
	}
}

void ScenePart::AddObject(SceneObject obj)
{
	sceneObjects->push_back(obj);
}
