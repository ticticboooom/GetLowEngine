// GetLowEngine.RollingDevSample.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Main.h"

#include <memory>

#include "../../../GetLowEngine.Engine/App.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	auto app = std::make_unique<App>();
	app->SetScene(std::make_shared<Scene>());
	return app->Run(hInstance, nCmdShow);
}
