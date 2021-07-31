#pragma once
#include "Component.h"
#include "Structures.h"
#include "ConstantBufferManager.h"
#include "ModelViewProjectionManager.h"
#include "Structures.h"

class PositionableComponent : public Component
{
public:
	PositionableComponent();
	void CreateRenderers() override;
	void Init() override;
	void Update() override;
	void Render() override;
	void OnWindowSizeChanged() override;
	std::shared_ptr<Transform> m_transform;
	XMFLOAT4X4 m_projection;
	XMFLOAT4X4 m_view;
protected:
	UINT m_mvpDescHeapIndex; /// heap index
	UINT m_mvpRootSigIndex; /// root signature index
	D3D12_RECT m_scissorRect;
	std::shared_ptr<ModelViewProjectionManager> m_mvpManager;
	std::unique_ptr<ConstantBufferManager<ModelViewProjectionConstantBuffer>> m_mvpConstantBufferManager;
};

