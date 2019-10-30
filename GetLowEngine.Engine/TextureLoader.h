#pragma once
#include "pch.h"
/**
 * @brief loads a texture from a WIC compatable file
 * 
 */
class TextureLoader
{
public:
	 TextureLoader();
	 ~TextureLoader();	
	 int LoadImageDataFromFile(BYTE** imageData, D3D12_RESOURCE_DESC& resourceDescription, LPCWSTR filename,
	                          int& bytesPerRow);
private:
	DXGI_FORMAT GetDXGIFormatFromWICFormat(WICPixelFormatGUID& wicFormatGUID);
	WICPixelFormatGUID GetConvertToWICFormat(WICPixelFormatGUID& wicFormatGUID);
	int GetDXGIFormatBitsPerPixel(DXGI_FORMAT& dxgiFormat);
};
