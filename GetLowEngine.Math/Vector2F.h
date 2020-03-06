#pragma once
#include "Vector2Base.h"

class Vector2F : public Vector2Base<float>
{
public:
	Vector2F(float x, float y) : Vector2Base<float>(x, y) {  }
	Vector2F() : Vector2Base<float>() {  }
	Vector2F& operator=(Vector2Base<float>& base) const
	{
		auto val = Vector2F(base.x, base.y);
		return val;
	}
};

