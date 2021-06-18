#pragma once
#include "pch.h"
#include "DirectXHelper.h"
/**
 * @brief sets the paths up with the correct value to use later
 * 
 */
class PathManager
{
public:
	PathManager();
	 ~PathManager();
	 const wchar_t* GetAssetPath() { return AssetPath->c_str(); };
	 const char* GetAssetPathStr()  { return AssetPathStr->c_str(); };
private:
	std::shared_ptr<std::wstring> AssetPath; /// the wstring asset path
	std::shared_ptr<std::string> AssetPathStr; /// the string asset path
};




