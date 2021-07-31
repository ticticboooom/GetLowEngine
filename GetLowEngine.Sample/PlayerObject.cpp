#include "stdafx.h"
#include "PlayerObject.h"
#include "../GetLowEngine.Engine/BasicMeshComponent.h"
#include "../GetLowEngine.Engine/PathManager.h"
#include "../GetLowEngine.Engine/PositionableComponent.h"


PlayerObject::PlayerObject()
{
	auto pos = std::make_shared<PositionableComponent>();
	AddComponent(pos);
	auto manager = PathManager();
	AddComponent(std::make_shared<BasicMeshComponent>(
		manager.GetAssetPathStr() + std::string("Character.glem"),
		manager.GetAssetPath() + std::wstring(L"Character.png"),
		false));
	pos->m_transform->position = XMVectorSet(0, 0, -10, 1);
}