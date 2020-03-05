#pragma once
#include <memory>
#include "GameMain.h"
#include "DeviceResources.h"
#include "Scene.h"

class App
{
public:
	App();
	~App();
	void SetScene(std::shared_ptr<Scene> rendererManager);
	int Run(HINSTANCE hInstance, int nCmdShow);
	std::shared_ptr<Scene> GetRenderer() const { return m_scene; }
protected:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	std::shared_ptr<DX::DeviceResources> GetDeviceResources();
	void ToggleFullscreen();
	static RECT m_windowRect;
	static const LONG c_windowStyle = WS_OVERLAPPEDWINDOW;
private:
	bool m_fullscreenMode;
	bool m_cursorVisible;
	HWND m_hwnd;
	bool isInitialised;
	std::shared_ptr<Scene> m_scene;
	std::shared_ptr<DX::DeviceResources> m_deviceResources;
};
