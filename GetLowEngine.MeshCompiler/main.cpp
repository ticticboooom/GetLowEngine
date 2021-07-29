#include <iostream>
#include <fstream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "MeshLoader.h"

int main(int argc, char* argv[])
{
	if (argc < 2) {
		return 1;
	}

	MeshLoader loader;
	auto loaded = loader.LoadFromFile(std::string(argv[0]));



}
