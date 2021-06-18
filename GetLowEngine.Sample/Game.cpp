#include "stdafx.h"
#include "Game.h"

#include "../GetLowEngine.Engine/App.h"
#include "../GetLowEngine.Engine/SceneManager.h"
#include "GameScene.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{

	SceneManager::GetInstance()->AddScene("game", std::make_shared<GameScene>());
	SceneManager::GetInstance()->SetScene("game");
	auto app = std::make_unique<App>();
	return app->Run(hInstance, nCmdShow);
}
