﻿#pragma once
#include "pch.h"
#include "DeviceResources.h"
#include <memory>
#include "CommandListManager.h"

/**
 * @brief  the descriptor heap stores the descriptors of the resources used in heap which is used to get the resourc on rendering along with the root signature to give the GPU resources to render
 *
 */
class DescriptorHeapManager
{
public:
	static std::shared_ptr<DescriptorHeapManager> GetInstance() { return instance; };
	static void Create(const int numDescriptors, D3D12_DESCRIPTOR_HEAP_TYPE type, D3D12_DESCRIPTOR_HEAP_FLAGS flags);
	DescriptorHeapManager(const int numDescriptors, D3D12_DESCRIPTOR_HEAP_TYPE type, D3D12_DESCRIPTOR_HEAP_FLAGS flags);
	~DescriptorHeapManager();
	void Render(UINT count, UINT* rootSigIndex, UINT* heapIndex, std::shared_ptr<CommandListManager> commandListManager);
	UINT GetDescriptorSize() const { return DX::DeviceResources::GetInstance()->GetD3DDevice()->GetDescriptorHandleIncrementSize(m_type); };

	D3D12_CPU_DESCRIPTOR_HANDLE GetCPUDescriptorHandleForHeapStart() const { return m_heap.Get()->GetCPUDescriptorHandleForHeapStart(); };
	D3D12_GPU_DESCRIPTOR_HANDLE GetGPUDescriptorHandleForHeapStart() const { return m_heap.Get()->GetGPUDescriptorHandleForHeapStart(); };
	ID3D12DescriptorHeap* Get() const { return m_heap.Get(); };
	int GetAndIncrement();
private:
	static std::shared_ptr<DescriptorHeapManager> instance;
	D3D12_DESCRIPTOR_HEAP_DESC m_desc; /// The descriptor for the heap
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_heap; /// the heap itself
	D3D12_DESCRIPTOR_HEAP_TYPE m_type; /// the type of the descriptor heap
	int index = 0;
};
