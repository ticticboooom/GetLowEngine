#include "pch.h"
#include "Keyboard.h"

std::shared_ptr<Keyboard> Keyboard::GetInstance()
{
	if (instance == nullptr)
	{
		instance = std::make_shared<Keyboard>();
	}
	return instance;
}

void Keyboard::SetPressed(UINT key)
{
	pressed = key;
}

void Keyboard::SetHeld(UINT key)
{
	held = key;
}

void Keyboard::SetReleased(UINT key)
{
	released = key;
}
