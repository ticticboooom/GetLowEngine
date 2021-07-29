#pragma once
#include "../GetLowEngine.Engine/Structures.h"
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/matrix4x4.h>
#include <assimp/scene.h>

class MeshLoader
{
public:
	MeshData LoadFromFile(std::string path);
	void LoadAnimations(const aiScene* scene);
	void ReadBoneHierarchy(const aiScene* scene);
	void LoadBones(const aiScene* scene, const int i);
	void CreateFinalVertices();
	void FinaliseAnimations();
	std::shared_ptr<std::vector<unsigned long>> loadIndices(const aiScene* scene, const int i);
	std::shared_ptr<std::vector<VertexTexCoordNormalBones>> loadVertices(const aiScene* scene, const int i);
	int FindBoneWithKeys(std::vector<AnimBone> bones, std::string name);
	std::vector<AnimBone> FillTimes(aiNode* node, std::vector<AnimBone> list, uint32_t animI);
	std::vector<AnimBone> FillMissingMappedTransforms(aiNode* node, std::vector<AnimBone> list, uint32_t animI);
	std::vector<AnimBone> GetNodes(aiNode* node, std::vector<AnimBone> list, uint32_t animI);
	uint32_t GetNextNoneIdentity(std::vector<DirectX::XMMATRIX> list, uint32_t current);
	DirectX::XMMATRIX InterpMatrix(DirectX::XMMATRIX m0, DirectX::XMMATRIX m1, float f);
	DirectX::XMMATRIX aiToXmmatrix(aiMatrix4x4 mat);
private:
	std::shared_ptr<std::vector<VertexTexCoordNormalBones>> m_vertices;
	std::shared_ptr<std::vector<VertexTexCoordNormal>> m_finalVertices;
	std::shared_ptr<std::vector<unsigned long>> m_indices;
	std::vector<Animation> m_animations;
	std::shared_ptr<AnimationForExport> m_finalAnimations;
	std::vector<uint32_t> m_maxFrameCountPerAnim;
};