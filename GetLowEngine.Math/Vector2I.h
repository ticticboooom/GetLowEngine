#pragma once
#include "Vector2Base.h"

class Vector2I : public Vector2Base<int>
{
public:
	Vector2I(int x, int y) : Vector2Base<int>(x, y) {  }
	Vector2I(): Vector2Base<int>() {  }
	Vector2I& operator=(Vector2Base<int>& base) const
	{
		auto val = Vector2I(base.x, base.y);
		return val;
	}
};
