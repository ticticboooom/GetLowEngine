#include "pch.h"
#include "SceneObject.h"

SceneObject::SceneObject()
{	
}

SceneObject::~SceneObject()
{
}

void SceneObject::CreateRenderers()
{
	for (auto c : *m_components) {
		c->CreateRenderers();
	}
}

void SceneObject::Init()
{
	for (auto c : *m_components) {
		c->Init();
	}
}

void SceneObject::Update()
{
	for (auto c : *m_components) {
		c->Update();
	}
}

void SceneObject::Render()
{
	for (auto c : *m_components) {
		c->Render();
	}
}

void SceneObject::OnWindowSizeChanged()
{
	for (auto c : *m_components) {
		c->OnWindowSizeChanged();
	}
}

void SceneObject::OnSuspending()
{
	for (auto c : *m_components) {
		c->OnSuspending();
	}
}

void SceneObject::OnResuming()
{
	for (auto c : *m_components) {
		c->OnResuming();
	}
}

void SceneObject::OnDeviceRemoved()
{
	for (auto c : *m_components) {
		c->OnDeviceRemoved();
	}
}
