#pragma once
#include "pch.h"
#include <memory>
#include <vector>
#include <DirectXMath.h>
#include <string>

struct AnimFrameBone
{
	std::string name;
	DirectX::XMFLOAT4X4 MATRIX;
	int index;
};
struct AnimTransforms {
	DirectX::XMVECTOR pos;
	DirectX::XMVECTOR rot;
	DirectX::XMVECTOR scale;
};
struct AnimBone
{
	std::string name;
	std::vector<DirectX::XMMATRIX> transforms;
	std::vector<float> times;
	std::vector<DirectX::XMMATRIX> mappedTransforms;
	std::vector<DirectX::XMMATRIX> finalTransforms = std::vector<DirectX::XMMATRIX>();
	DirectX::XMMATRIX offsetMatrix;
	DirectX::XMMATRIX mtrans;
	DirectX::XMMATRIX toRoot;
};
struct assimpVertexWeight {
	unsigned int mVertexId;
	float mWeight;
};
struct assimpBone {
	std::string mName;
	unsigned int mNumWeights;
	std::vector<assimpVertexWeight> mWeights;
};
struct Animation
{
	std::vector<AnimBone> bonesWithKeys;
	uint32_t frameCount;
	std::vector<assimpBone> bones;
	int numBones;
};
struct Bone
{
	uint32_t boneIndex;
	float weight;
};
struct VertexTexCoordNormalBones
{
	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT2 texCoord;
	DirectX::XMFLOAT3 normal;
	std::vector<Bone> bones;
};
struct VertexTexCoordNormal
{
	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT2 texCoord;
	DirectX::XMFLOAT3 normal;
	DirectX::XMFLOAT4 weights1;
	DirectX::XMFLOAT4 weights2;
	DirectX::XMFLOAT4 bones1;
	DirectX::XMFLOAT4 bones2;
	int isAnimated;
};

struct PrimitiveVertex {
	float x, y, z;
};

struct AnimationForExport {
	std::vector<std::vector<std::vector<DirectX::XMMATRIX>>> perBoneAnims;
};

struct MeshData {
	std::shared_ptr<std::vector<VertexTexCoordNormal>> vertices;
	std::shared_ptr<std::vector<unsigned long>> indices;
	std::shared_ptr<AnimationForExport> animations;
};

struct VerticesIndicesFromBin
{
	std::shared_ptr<std::vector<VertexTexCoordNormal>> vertices;
	std::shared_ptr<std::vector<unsigned long>> indices;
	std::shared_ptr<std::vector<std::vector<std::vector<XMMATRIX>>>> animations;
};

struct ShaderData
{
	byte* shader;
	uint32_t size;
};

struct ModelViewProjectionConstantBuffer
{
	DirectX::XMFLOAT4X4 model;
	DirectX::XMFLOAT4X4 view;
	DirectX::XMFLOAT4X4 projection;
};

struct HeightMapInfo {        // Heightmap structure
	int terrainWidth;        // Width of heightmap
	int terrainHeight;        // Height (Length) of heightmap
	DirectX::XMFLOAT3* heightMap;    // Array to store terrain's vertex positions
};

struct Transform {
	XMVECTOR position;
	XMVECTOR rotationQuat;
	XMVECTOR scale;
	Transform() {
		position = XMVectorSet(0, 0, 0, 1);
		rotationQuat = XMQuaternionIdentity();
		scale = XMVectorSet(1, 1, 1, 1);
	}
};

