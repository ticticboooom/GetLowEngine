#include "pch.h"
#include "BasicMeshComponent.h"
#include "RootSignatureHelper.h"
#include "TextureManager.h"
#include "PathManager.h"
#include "BinaryMeshLoader.h"
#include "DescriptorHeapManager.h"


BasicMeshComponent::BasicMeshComponent(std::string filename, std::wstring texturePath, bool isAnimated) : Component()
{
	auto modelLoader = std::make_unique<BinaryMeshLoader>(filename.c_str(), isAnimated);
	m_meshData = modelLoader->GetFinalData();
	m_filename = filename; 
	m_isAnimated = isAnimated;
	m_texturePath = texturePath;
	m_indexCount = m_meshData->indices->size();
}

void BasicMeshComponent::CreateRenderers()
{
	m_textureRootSigIndex = RootSignatureHelper::GetInstance()->InitDescriptorRange(D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 0, 1, D3D12_SHADER_VISIBILITY_PIXEL);
}

void BasicMeshComponent::Init()
{
	auto pathManager = PathManager();
	m_textureDescHeapIndex = TextureManager::GetInstance()->CreateSRVFromTextureFile(m_texturePath);

	auto inds = std::make_shared<std::vector<unsigned int>>(m_meshData->indices->begin(), m_meshData->indices->end());
	m_vertexBufferManager = std::make_unique<VertexBufferManager>(m_meshData->vertices, DX::DeviceResources::GetInstance(), CommandListManager::GetInstance());
	m_indexBufferManager = std::make_unique<IndexBufferManager>(inds, DX::DeviceResources::GetInstance(), CommandListManager::GetInstance());

	m_meshData->indices->clear();
	m_meshData->vertices->clear();
	inds->clear();

	m_vertexBufferView = m_vertexBufferManager->CreateVertexBufferView();
	m_indexBufferView = m_indexBufferManager->CreateIndexBufferView();
}

void BasicMeshComponent::Render()
{
	DescriptorHeapManager::GetInstance()->Render(1, new UINT[1]{ m_textureRootSigIndex }, new UINT[1]{ m_textureDescHeapIndex }, CommandListManager::GetInstance());

	CommandListManager::GetInstance()->CreateResourceBarrier(D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
	CommandListManager::GetInstance()->SetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	CommandListManager::GetInstance()->SetVertexBuffers(0, 1, &m_vertexBufferView);
	CommandListManager::GetInstance()->SetIndexBuffer(&m_indexBufferView);
	CommandListManager::GetInstance()->DrawIndexedInstanced(m_indexCount, 1, 0, 0, 0);
	CommandListManager::GetInstance()->CreateResourceBarrier(D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
}
