#include "stdafx.h"
#include "PlayerScenePart.h"
#include "PlayerObject.h"

PlayerScenePart::PlayerScenePart() : ScenePart()
{
	AddObject(PlayerObject());
}

