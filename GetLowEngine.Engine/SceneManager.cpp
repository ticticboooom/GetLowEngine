#include "pch.h"
#include "SceneManager.h"
#include "PSOManager.h"
#include "RootSignatureHelper.h"
#include "CommandListManager.h"
#include "DirectXHelper.h"
#include "DescriptorHeapManager.h"

std::shared_ptr<SceneManager> SceneManager::instance = nullptr;

std::shared_ptr<SceneManager> SceneManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = std::make_shared<SceneManager>();
	}
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
	auto sig = CreateRootSignatures(DX::DeviceResources::GetInstance());
	RootSignatureHelper::GetInstance()->AddSignatureManager(sig);
	(*sig)[0]->Finalize(L"Root Signature",
		D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT |
		D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS |
		D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS |
		D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS);
 }

void SceneManager::Init()
{

	static const D3D12_INPUT_ELEMENT_DESC inputLayout[] =
	{
		{ "POSITION",	0,	DXGI_FORMAT_R32G32B32_FLOAT,	0, 0,	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD",	0,	DXGI_FORMAT_R32G32_FLOAT,		0, 12,	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
	{ "NORMAL",		0,	DXGI_FORMAT_R32G32B32_FLOAT,	0, 20,	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD",	1,	DXGI_FORMAT_R32G32B32A32_FLOAT,	0, 32,	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD",	2,	DXGI_FORMAT_R32G32B32A32_FLOAT,	0, 48,	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD",	3,	DXGI_FORMAT_R32G32B32A32_FLOAT,	0, 64,	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD",	4,	DXGI_FORMAT_R32G32B32A32_FLOAT,	0, 80,	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD",	5,	DXGI_FORMAT_R32_SINT,			0, 96,	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
	};
	psoManager = std::make_shared<PSOManager>(DX::DeviceResources::GetInstance());
	psoManager->SetInputLayout({ inputLayout, _countof(inputLayout) });
	psoManager->SetSignature((*RootSignatureHelper::GetInstance()->GetRootSignatureManager())[0]->GetSignature());
	psoManager->SetPrimitiveTopologyType(D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE);
	psoManager->SetNumRenderTargets(1);
	psoManager->SetVS(currentScene->GetVertexShader());
	psoManager->SetPS(currentScene->GetPixelShader());
	psoManager->SetRTVFormats(DX::DeviceResources::GetInstance()->GetBackBufferFormat(), 0);
	psoManager->SetDSVFormat(DX::DeviceResources::GetInstance()->GetDepthBufferFormat());
	psoManager->Finalise();

	CommandListManager::Create(DX::DeviceResources::GetInstance(), psoManager->GetState(), D3D12_COMMAND_LIST_TYPE_DIRECT);

	currentScene->Init();
	CommandListManager::GetInstance()->CloseAndExcecute();
	DX::DeviceResources::GetInstance()->WaitForGpu();
}

void SceneManager::Update()
{
	DX::DeviceResources::GetInstance()->WaitForGpu();
	ThrowIfFailed(DX::DeviceResources::GetInstance()->GetCommandAllocator()->Reset());
	ThrowIfFailed(CommandListManager::GetInstance()->Reset(DX::DeviceResources::GetInstance()->GetCommandAllocator(), psoManager->GetState()));

	currentScene->Update();

	CommandListManager::GetInstance()->CloseAndExcecute();
	DX::DeviceResources::GetInstance()->WaitForGpu();
}

void SceneManager::Render()
{
	DX::DeviceResources::GetInstance()->WaitForGpu();
	ThrowIfFailed(DX::DeviceResources::GetInstance()->GetCommandAllocator()->Reset());
	ThrowIfFailed(CommandListManager::GetInstance()->Reset(DX::DeviceResources::GetInstance()->GetCommandAllocator(), psoManager->GetState()));

	CommandListManager::GetInstance()->SetGraphicsRootSignature((*RootSignatureHelper::GetInstance()->GetRootSignatureManager())[0]->GetSignature());
	//ID3D12DescriptorHeap* ppHeaps[] = { DescriptorHeapManager::GetInstance()->Get() };
	//CommandListManager::GetInstance()->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

	D3D12_VIEWPORT viewport = DX::DeviceResources::GetInstance()->GetScreenViewport();

	CommandListManager::GetInstance()->SetViewports(1, &viewport);
	CommandListManager::GetInstance()->SetScissorRects(1, &m_scissorRect);

	CommandListManager::GetInstance()->CreateResourceBarrier(D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);

	CommandListManager::GetInstance()->ClearSetRenderTargets();

	CommandListManager::GetInstance()->CreateResourceBarrier(D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);

	currentScene->Render();

	CommandListManager::GetInstance()->CloseAndExcecute();
	DX::DeviceResources::GetInstance()->WaitForGpu();
}

void SceneManager::OnWindowSizeChanged()
{
	currentScene->OnWindowSizeChanged();
}

void SceneManager::OnSuspending()
{
	currentScene->OnSuspending();
}

void SceneManager::OnResuming()
{
	currentScene->OnResuming();
}

void SceneManager::OnDeviceRemoved()
{
	currentScene->OnDeviceRemoved();
}

std::shared_ptr<RootSignatureManager> SceneManager::CreateRootSignatures(
	const std::shared_ptr<DX::DeviceResources>& deviceResources) const
{
	std::shared_ptr<RootSignatureManager> signatureManager = std::make_shared<RootSignatureManager>();
	signatureManager->AddSignature(deviceResources, 0, 1);
	D3D12_SAMPLER_DESC sampler;
	sampler.Filter = D3D12_FILTER_MIN_MAG_MIP_POINT;
	sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
	sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
	sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
	sampler.MipLODBias = 0;
	sampler.MaxAnisotropy = 0;
	sampler.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
	sampler.MinLOD = 0.0f;
	sampler.MaxLOD = D3D12_FLOAT32_MAX;
	(*signatureManager)[0]->InitStaticSampler(0, sampler, D3D12_SHADER_VISIBILITY_PIXEL);
	return signatureManager;
}