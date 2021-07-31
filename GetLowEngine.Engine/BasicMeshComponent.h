#pragma once
#include "Component.h"
#include "Structures.h"
#include "VertexBufferManager.h"
#include "IndexBufferManager.h"

class BasicMeshComponent : public Component
{
public:
	BasicMeshComponent(std::string filename, std::wstring texturePath, bool isAnimated);

	void CreateRenderers() override;
	void Init() override;
	void Render() override;

protected:
	std::string m_filename;
	std::wstring m_texturePath;
	bool m_isAnimated;
	UINT m_indexCount;
	std::shared_ptr<VerticesIndicesFromBin> m_meshData;
	UINT m_textureDescHeapIndex;
	UINT m_textureRootSigIndex;
	D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;
	std::unique_ptr<VertexBufferManager> m_vertexBufferManager;
	D3D12_INDEX_BUFFER_VIEW m_indexBufferView;
	std::unique_ptr<IndexBufferManager> m_indexBufferManager;
};

