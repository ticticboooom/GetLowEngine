#include "pch.h"
#include <memory>
#include <apiquery2.h>
#include "../GetLowEngine.Engine/App.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	auto app = std::make_unique<App>();
	return app->Run(hInstance, nCmdShow);
	
}
