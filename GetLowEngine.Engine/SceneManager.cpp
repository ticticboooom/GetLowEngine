#include "pch.h"
#include "SceneManager.h"

std::shared_ptr<SceneManager> SceneManager::instance = nullptr;

std::shared_ptr<SceneManager> SceneManager::GetInstance()
{
	return instance;
}

void SceneManager::AddScene(std::string key, std::shared_ptr<Scene> scene)
{
	if (scenes.find(key) != scenes.end())
	{
		throw std::exception((key + ": key already exists in scenes").c_str());
	}
	scenes[key] = scene;
}

void SceneManager::SetScene(std::string name)
{
	currentScene = scenes[name];
}

void SceneManager::CreateRenderers()
{
	currentScene->CreateRenderers();
}

void SceneManager::Init()
{
	currentScene->CreateRenderers();
}

void SceneManager::Update()
{
	currentScene->CreateRenderers();
}

void SceneManager::Render()
{
	currentScene->CreateRenderers();
}

void SceneManager::OnWindowSizeChanged()
{
	currentScene->CreateRenderers();
}

void SceneManager::OnSuspending()
{
	currentScene->CreateRenderers();
}

void SceneManager::OnResuming()
{
	currentScene->CreateRenderers();
}

void SceneManager::OnDeviceRemoved()
{
	currentScene->CreateRenderers();
}
