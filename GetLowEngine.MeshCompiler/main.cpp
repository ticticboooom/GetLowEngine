#include <iostream>
#include <fstream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "MeshLoader.h"
#include "BinaryModelSaver.h"
int main(int argc, char* argv[])
{
	if (argc < 3) {
		return 1;
	}

	MeshLoader loader;
	auto loaded = loader.LoadFromFile(std::string(argv[1]));

	auto saver = BinaryMeshSaver(loaded);
	saver.save(std::string(argv[2]));
	return 0;
}
