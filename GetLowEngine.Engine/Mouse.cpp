#include "pch.h"
#include "Mouse.h"
std::shared_ptr<Mouse> Mouse::instance = nullptr;
std::shared_ptr<Mouse> Mouse::GetInstance()
{
	if (instance == nullptr)
	{
		instance = std::make_shared<Mouse>();
	}
	return instance;
}

Vector2I& Mouse::GetMouseDeltaPosition() const
{
	return delta;
}

Vector2I& Mouse::GetMousePosition() const
{
	return pos;
}

void Mouse::SetMousePosition(Vector2I& position) const
{
	pos = position;
}

void Mouse::SetMouseDeltaPosition(Vector2I& delta) const
{
	this->delta = delta;
}
