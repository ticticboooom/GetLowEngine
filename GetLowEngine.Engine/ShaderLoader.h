#pragma once
#include "Structures.h"

class ShaderLoader
{
public:
	static ShaderData GetShaderFromFile(const wchar_t*  fileName);
};
