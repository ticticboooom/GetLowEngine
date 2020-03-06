#pragma once
#include "Vector3Base.h"

class Vector3I : public Vector3Base<int>
{
	Vector3I() : Vector3Base<int>() {};
	Vector3I(int x, int y, int z) : Vector3Base<int>(x, y, z) {};
	Vector3I(int x, int y) : Vector3Base<int>(x, y) {};
	Vector3I& operator=(Vector3Base<int>& base) const
	{
		auto val = Vector3I(base.x, base.y, base.z);
		return val;
	}
};
