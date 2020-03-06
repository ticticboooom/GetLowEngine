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
	Mouse() = default;
private:
	static std::shared_ptr<Mouse> instance;
	Vector2I sPos = Vector2I(0, 0);
	Vector2I& pos = sPos;
	Vector2I& delta = sPos;
};

