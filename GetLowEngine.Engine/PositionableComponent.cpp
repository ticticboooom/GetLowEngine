#include "pch.h"
#include "PositionableComponent.h"
#include "DescriptorHeapManager.h"
#include "RootSignatureHelper.h"


PositionableComponent::PositionableComponent() : Component()
{
	m_transform = std::make_shared<Transform>();
	m_mvpManager = std::make_shared<ModelViewProjectionManager>();
	m_projection = XMFLOAT4X4{};
	m_view = XMFLOAT4X4{};
}

void PositionableComponent::CreateRenderers()
{
	m_mvpRootSigIndex = RootSignatureHelper::GetInstance()->InitDescriptorRange(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 0, 1, D3D12_SHADER_VISIBILITY_VERTEX);
}

void PositionableComponent::Init()
{
	auto cbvDescriptorSize = DescriptorHeapManager::GetInstance()->GetDescriptorSize();
	m_mvpConstantBufferManager = std::make_unique<ConstantBufferManager<ModelViewProjectionConstantBuffer>>(1, m_mvpConstantBufferManager->GetAlignedSize(), DX::DeviceResources::GetInstance(), CommandListManager::GetInstance());
	m_mvpDescHeapIndex = DescriptorHeapManager::GetInstance()->GetAndIncrement();
	m_mvpConstantBufferManager->CreateBufferDesc(m_mvpConstantBufferManager->GetAlignedSize(), m_mvpDescHeapIndex, DescriptorHeapManager::GetInstance(), cbvDescriptorSize);
}

void PositionableComponent::Update()
{
	DirectX::XMVECTORF32 up = { 0.0f, 1.0f, 0.0f, 0.0f };
	XMStoreFloat4x4(&m_view, XMMatrixTranspose(XMMatrixLookAtRH(XMVectorSet(0, 1, 10, 0), XMVectorSet(0, 0, 0, 0), up.v)));

	m_mvpManager->SetMatrix(MATKEY_MODEL, XMMatrixTranspose(XMMatrixAffineTransformation(m_transform->scale, XMVectorSet(0, 0, 0, 0), m_transform->rotationQuat, m_transform->position)));
	m_mvpManager->SetMatrix(MATKEY_VIEW, XMLoadFloat4x4(&m_view));
	m_mvpManager->SetMatrix(MATKEY_PROJECTION, XMLoadFloat4x4(&m_projection));

	auto cbvData = m_mvpManager->GetCbvData();
	UINT8* destination = m_mvpConstantBufferManager->GetMappedData();
	std::memcpy(destination, &cbvData, sizeof(cbvData));
}

void PositionableComponent::Render()
{
	DescriptorHeapManager::GetInstance()->Render(1, new UINT[1]{ m_mvpRootSigIndex }, new UINT[1]{ m_mvpDescHeapIndex }, CommandListManager::GetInstance());
}

void PositionableComponent::OnWindowSizeChanged()
{
	// Gets thye inner window (output size) form \class DeviceResources
	const auto outputSize = DX::DeviceResources::GetInstance()->GetOutputSize();
	// Gets aspect ratio from output size
	const float aspectRatio = outputSize.x / outputSize.y;
	// Creates the Field of View for the perspective
	float fovAngleY = 70.0f * DirectX::XM_PI / 180.0f;

	// Gets the viewport structure from \class Device Resources
	const auto viewport = DX::DeviceResources::GetInstance()->GetScreenViewport();
	// Sets \property m_scissorRect with the viewport width and height
	m_scissorRect = { 0, 0, static_cast<LONG>(viewport.Width), static_cast<LONG>(viewport.Height) };
	// Checks the aspect ratio to see if the FOV angle needs to be changed
	if (aspectRatio < 1.0f)
	{
		fovAngleY *= 2.0f;
	}
	// Sets the perspective matrix using the \var fovAngleY \var aspectRatio and the constant vlaues which represent the Z Cut off (near then far)
	const auto perspectiveMatrix = DirectX::XMMatrixPerspectiveFovRH(
		fovAngleY,
		aspectRatio,
		0.01f,
		10000.0f
	);

	// Screen orientation
	static const DirectX::XMFLOAT4X4 Rotation0(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	// Turns into an XMMATRIX
	const auto orientationMatrix = XMLoadFloat4x4(&Rotation0);

	// Sets the perspective matrix in the \class ModelViewProjectionManager
	XMStoreFloat4x4(&m_projection, XMMatrixTranspose(perspectiveMatrix * orientationMatrix));
}
