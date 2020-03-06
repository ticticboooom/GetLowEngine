#pragma once
#include "pch.h"

#include "../GetLowEngine.Math/Vector2F.h"
#include "../GetLowEngine.Math/Vector2I.h"

class Mouse
{
public:
	static std::shared_ptr<Mouse> GetInstance();
	Vector2I& GetMouseDeltaPosition() const;
	Vector2I& GetMousePosition() const;
	void SetMousePosition(Vector2I& position) const;
	void SetMouseDeltaPosition(Vector2I& delta) const;
private:
	static std::shared_ptr<Mouse> instance;
	Vector2I& pos;
	Vector2I& delta;
};

