﻿#include "pch.h"
#include "VertexBufferManager.h"

/**
 * @brief Construct a new Vertex Buffer Manager:: Vertex Buffer Manager object
 * 	Vertices make up the shapes that are visible inside the 3d render space
 * @param vertices the vertex vector thjat will become the resource
 * @param deviceResources 
 * @param commandListManager 
 */
VertexBufferManager::VertexBufferManager(std::shared_ptr<std::vector<VertexTexCoordNormal>> vertices, const std::shared_ptr<DX::DeviceResources> deviceResources,
	const std::shared_ptr<CommandListManager> commandListManager) :
	BufferManagerBase(vertices->size() * sizeof VertexTexCoordNormal,
		reinterpret_cast<BYTE*>(vertices->data()),
		D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER,
		deviceResources,
		commandListManager),
	m_vertices(vertices)
{
	m_verticesSize = m_vertices->size();
}
/**
 * @brief Destroy the Vertex Buffer Manager:: Vertex Buffer Manager object
 * 
 */
VertexBufferManager::~VertexBufferManager()
{
	m_vertices->clear();
}
/**
 * @brief get the vertex buffer view from the vertex buffer
 * 
 * @return D3D12_VERTEX_BUFFER_VIEW the vertex buffer view
 */
D3D12_VERTEX_BUFFER_VIEW VertexBufferManager::CreateVertexBufferView() const
{
	auto buffer = GetResource();
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView;
	vertexBufferView.BufferLocation = buffer->GetGPUVirtualAddress();
	vertexBufferView.StrideInBytes = sizeof(VertexTexCoordNormal);
	vertexBufferView.SizeInBytes = sizeof(VertexTexCoordNormal) * m_verticesSize;

	return vertexBufferView;
}
