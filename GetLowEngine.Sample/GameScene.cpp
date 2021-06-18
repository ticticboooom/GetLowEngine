#include "stdafx.h"
#include "GameScene.h"

#include "PlayerScenePart.h"

GameScene::GameScene() : Scene()
{
	AddRenderer(std::make_shared<PlayerScenePart>());
}

void GameScene::Init()
{
}
