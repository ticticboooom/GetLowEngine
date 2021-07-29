﻿#include "pch.h"
#include "ShaderLoader.h"
#include <string>
#include "DirectXHelper.h"
/**
 * @brief load a shader
 * 
 * @param fileName path and filename of the shader, "*.cso" only
 * @return Structures::ShaderData the returned data
 */
ShaderData ShaderLoader::GetShaderFromFile(const wchar_t* fileName)
{
	ShaderData data;
	ReadDataFromFile(fileName, &data.shader, &data.size);
	return data;
}
