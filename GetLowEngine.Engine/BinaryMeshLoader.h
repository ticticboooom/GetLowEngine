#pragma once
#include "Structures.h"
class BinaryMeshLoader
{
public:
	BinaryMeshLoader(std::string filPath, bool hasAnims);
	std::shared_ptr<VerticesIndicesFromBin> GetFinalData() const { return m_finalData; };
private:
	std::shared_ptr<VerticesIndicesFromBin> m_finalData;
};