#include "BinaryModelSaver.h"
#include <fstream>
BinaryMeshSaver::BinaryMeshSaver(MeshData data)
{
	this->data = data;
}

void BinaryMeshSaver::save(std::string path)
{
	auto verticesCount= data.vertices->size();
	auto indicesCount = data.indices->size();
	auto animsCount = data.animations->perBoneAnims.size();
	auto boneCounts = std::vector<size_t>();
	auto frameCounts = std::vector<std::vector<size_t>>();

	for (auto bones : data.animations->perBoneAnims) {
		boneCounts.push_back(bones.size());
		auto perBoneFrameCounts = std::vector<size_t>();
		for (auto frames : bones) {
			perBoneFrameCounts.push_back(frames.size());
		}
		frameCounts.push_back(perBoneFrameCounts);
	}
	auto boneCountsCount = boneCounts.size();
	auto frameCountsCount = frameCounts.size();

	std::ofstream m_file(path, std::ios::binary | std::ios::out);
	m_file.write((const char*)&verticesCount, sizeof(size_t));
	m_file.write((const char*)&indicesCount, sizeof(size_t));
	m_file.write((const char*)&animsCount, sizeof(size_t));
	m_file.write((const char*)&boneCountsCount, sizeof(size_t));
	m_file.write((const char*)&frameCountsCount, sizeof(size_t));

	m_file.write(reinterpret_cast<char*>(boneCounts.data()), sizeof(size_t) * boneCounts.size());
	for (auto bone : frameCounts) {
		m_file.write(reinterpret_cast<char*>(bone.data()), sizeof(size_t) * bone.size());
	}

	m_file.write(reinterpret_cast<char*>(data.vertices->data()), sizeof(VertexTexCoordNormal) * data.vertices->size());

	m_file.write(reinterpret_cast<char*>(data.indices->data()), sizeof(unsigned long) * data.indices->size());

	for (auto bones : data.animations->perBoneAnims) {
		for (auto frames : bones) {
			auto newFrames = std::vector<XMFLOAT4X4>();
			for (auto frame : frames) {
				auto float4x4 = XMFLOAT4X4{};
				XMStoreFloat4x4(&float4x4, frame);
				newFrames.push_back(float4x4);
			}
			m_file.write(reinterpret_cast<char*>(newFrames.data()), newFrames.size() * sizeof(XMFLOAT4X4));
		}
	}
	m_file.close();
}
