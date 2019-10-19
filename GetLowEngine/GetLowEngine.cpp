#include "pch.h"
#include <memory>
#include "App.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	auto app = std::make_unique<App>();
	return app->Run(hInstance, nCmdShow);
}
