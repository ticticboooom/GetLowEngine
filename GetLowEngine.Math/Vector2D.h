#pragma once
#include "Vector2Base.h"

class Vector2D : public Vector2Base<double>
{
public:
	Vector2D(double x, double y) : Vector2Base<double>(x, y) {  }
	Vector2D() : Vector2Base<double>() {  }
	Vector2D& operator=(Vector2Base<double>& base) const
	{
		auto val = Vector2D(base.x, base.y);
		return val;
	}
};
