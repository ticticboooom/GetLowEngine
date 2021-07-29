#pragma once
#include <memory>
#include <vector>
#include "../GetLowEngine.Engine/Structures.h"
#include <assimp/scene.h>



struct VertexThreadParemeter {
	aiMesh* mesh;
	uint32_t vertexStart;
	uint32_t vertexEnd;
	std::vector<VertexTexCoordNormalBones> vertices;
};
