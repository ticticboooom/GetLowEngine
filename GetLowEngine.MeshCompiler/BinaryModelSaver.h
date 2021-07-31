#pragma once
#include "../GetLowEngine.Engine/Structures.h"
class BinaryMeshSaver
{
public:
	BinaryMeshSaver(MeshData data);
	void save(std::string path);
private:
	MeshData data;
};

