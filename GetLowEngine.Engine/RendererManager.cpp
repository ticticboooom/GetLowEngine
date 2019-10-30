#include "pch.h"
#include "RendererManager.h"

class Renderer;
RendererManager::RendererManager()
= default;

void RendererManager::CreateRenderers(const std::shared_ptr<DX::DeviceResources>& deviceResources)
{
	for (auto renderer : *renderers)
	{
		renderer->CreateRenderers(deviceResources);
	}
}

void RendererManager::Init()
{
	for (auto renderer : *renderers)
	{
		renderer->Init();
	}
}

void RendererManager::Update()
{
	for (auto renderer : *renderers)
	{
		renderer->Update();
	}
}

void RendererManager::Render()
{
	for (auto renderer : *renderers)
	{
		renderer->Render();
	}
}

void RendererManager::OnKeyDown(UINT key)
{
	for (auto renderer : *renderers)
	{
		renderer->OnKeyDown(key);
	}
}

void RendererManager::OnKeyUp(UINT key)
{
	for (auto renderer : *renderers)
	{
		renderer->OnKeyDown(key);
	}
}

void RendererManager::OnMouseMoved(float x, float y)
{
	for (auto renderer : *renderers)
	{
		renderer->OnMouseMoved(x, y);
	}
}

void RendererManager::OnWindowSizeChanged()
{
	for (auto renderer : *renderers)
	{
		renderer->OnWindowSizeChanged();
	}
}

void RendererManager::OnSuspending()
{
	for (auto renderer : *renderers)
	{
		renderer->OnSuspending();
	}
}

void RendererManager::OnResuming()
{
	for (auto renderer : *renderers)
	{
		renderer->OnResuming();
	}
}

void RendererManager::OnDeviceRemoved()
{
	for (auto renderer : *renderers)
	{
		renderer->OnDeviceRemoved();
	}
}

void RendererManager::AddRenderer(std::shared_ptr<Renderer> renderer)
{
	renderers->push_back(renderer);
}
