// GetLowEngine.RollingDevSample.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Main.h"

#include <memory>

#include "../../../GetLowEngine.Engine/App.h"
#include "../../../GetLowEngine.Engine/SceneManager.h"
#include "GameScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{

	SceneManager::GetInstance()->AddScene("game", std::make_shared<GameScene>());
	
	auto app = std::make_unique<App>();
	return app->Run(hInstance, nCmdShow);
}
