#pragma once
#include <memory>
#include "GameMain.h"
#include "DeviceResources.h"

class App
{
public:
	App();
	~App();
	int Run(HINSTANCE hInstance, int nCmdShow);

protected:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	std::shared_ptr<DX::DeviceResources> GetDeviceResources();

private:
	HWND m_hwnd;
	std::unique_ptr<GameMain> m_main;
	std::shared_ptr<DX::DeviceResources> m_deviceResources;
};