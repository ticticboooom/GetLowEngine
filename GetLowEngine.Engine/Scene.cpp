#include "pch.h"
#include "Scene.h"

Scene::Scene()
= default;

void Scene::CreateRenderers()
{
	for (auto renderer : *renderers)
	{
		renderer->CreateRenderers();
	}
}

void Scene::Init()
{
	for (auto renderer : *renderers)
	{
		renderer->Init();
	}
}

void Scene::Update()
{
	for (auto renderer : *renderers)
	{
		renderer->Update();
	}
}

void Scene::Render()
{
	for (auto renderer : *renderers)
	{
		renderer->Render();
	}
}

void Scene::OnWindowSizeChanged()
{
	for (auto renderer : *renderers)
	{
		renderer->OnWindowSizeChanged();
	}
}

void Scene::OnSuspending()
{
	for (auto renderer : *renderers)
	{
		renderer->OnSuspending();
	}
}

void Scene::OnResuming()
{
	for (auto renderer : *renderers)
	{
		renderer->OnResuming();
	}
}

void Scene::OnDeviceRemoved()
{
	for (auto renderer : *renderers)
	{
		renderer->OnDeviceRemoved();
	}
}

void Scene::AddRenderer(std::shared_ptr<ScenePart> renderer)
{
	renderers->push_back(renderer);
}
