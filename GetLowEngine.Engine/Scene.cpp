#include "pch.h"
#include "Scene.h"

#include "PathManager.h"
#include "ShaderLoader.h"

Scene::Scene()
{
	renderers = std::make_shared<std::vector<std::shared_ptr<ScenePart>>>();
	auto pathManager = PathManager();
	assetPath = std::make_unique<std::wstring>(std::wstring(pathManager.GetAssetPath()));
	
	auto PSName = L"PlayerPixelShader.cso";

	auto PSPath = *assetPath + PSName;
}

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

CD3DX12_SHADER_BYTECODE Scene::GetVertexShader()
{
	auto VSName = L"PlayerVertexShader.cso";
	auto VSPath = *assetPath + VSName;
	auto vs = ShaderLoader::GetShaderFromFile(VSPath.c_str());
	return CD3DX12_SHADER_BYTECODE(vs.shader, vs.size);	
}

CD3DX12_SHADER_BYTECODE Scene::GetPixelShader()
{
	auto PSName = L"PlayerPixelShader.cso";
	auto PSPath = *assetPath + PSName;
	auto ps = ShaderLoader::GetShaderFromFile(PSPath.c_str());
	return CD3DX12_SHADER_BYTECODE(ps.shader, ps.size);
}
