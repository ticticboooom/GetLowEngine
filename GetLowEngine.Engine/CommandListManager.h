#pragma once
#include "pch.h"
#include "DeviceResources.h"
#include <memory>
#include <wrl/client.h>


/**
 * @brief A command list is what commands (things for the GPU to do) are sent to and executed through
 *
 */
class CommandListManager
{
public:
	CommandListManager(std::shared_ptr<DX::DeviceResources> deviceResources, ID3D12PipelineState* pipelineState, D3D12_COMMAND_LIST_TYPE type);
	~CommandListManager();
	static void Create(std::shared_ptr<DX::DeviceResources> deviceResources, ID3D12PipelineState* pipelineState, D3D12_COMMAND_LIST_TYPE type);
	ID3D12GraphicsCommandList* Get();
	static std::shared_ptr<CommandListManager> GetInstance();
	void UpdateSubresource(ID3D12Resource* resource, ID3D12Resource* resourceUpload, D3D12_SUBRESOURCE_DATA* desc);
	void CreateResourceBarrier(int numBarriers, CD3DX12_RESOURCE_BARRIER* resource);
	void CloseAndExcecute();
	void SetVertexBuffers(UINT StartSlot, UINT Count, const D3D12_VERTEX_BUFFER_VIEW VBViews[]);
	void SetIndexBuffer(const D3D12_INDEX_BUFFER_VIEW* VBView);
	void SetPrimitiveTopology(enum D3D_PRIMITIVE_TOPOLOGY topology);
	void DrawInstanced(UINT VertexCountPerInstance, UINT InstanceCount,
		UINT StartVertexLocation, UINT StartInstanceLocation);
	void DrawIndexedInstanced(UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation,
		UINT StartIndexLocation, UINT StartInstanceLocation);
	void SetScissorRects(int numRects, D3D12_RECT* rect);
	void SetViewports(int numViewports, D3D12_VIEWPORT* viewport);
	void SetGraphicsRootDescriptorTable(int rootParameterIndex, const CD3DX12_GPU_DESCRIPTOR_HANDLE& handle);
	void SetDescriptorHeaps(UINT numDescriptors, ID3D12DescriptorHeap* const* ppHeaps);
	void SetGraphicsRootSignature(Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature);
	HRESULT Reset(ID3D12CommandAllocator* commandAllocator, Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState);

	void ClearSetRenderTargets();
	void CreateResourceBarrier(D3D12_RESOURCE_STATES stateBefore, D3D12_RESOURCE_STATES stateAfter);
private:
	void SetRenderTargets(UINT NumRTVs, const D3D12_CPU_DESCRIPTOR_HANDLE RTVs[], D3D12_CPU_DESCRIPTOR_HANDLE DSV);
	void ClearRenderTargetView(const D3D12_CPU_DESCRIPTOR_HANDLE& render_target_view, DirectX::XMVECTORF32 clearColor);
	void ClearDepthStencilView(const D3D12_CPU_DESCRIPTOR_HANDLE& depth_stencil_view, enum D3D12_CLEAR_FLAGS d3_d12_clear_flags, int depth, int stencil, int rects, D3D12_RECT* pRects);
	
	static std::shared_ptr<CommandListManager> instance;
	std::shared_ptr<DX::DeviceResources> m_deviceResources;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> m_commandList; /// command list
};
