#pragma once
#include "Structures.h"

class ShaderLoader
{
public:
	static Structures::ShaderData GetShaderFromFile(const wchar_t*  fileName);
};
