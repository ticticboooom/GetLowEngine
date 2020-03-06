#pragma once
#include "Vector3Base.h"

struct Vector3F : public Vector3Base<float>
{
public:
	Vector3F() : Vector3Base<float>() {  }
	Vector3F(float x, float y, float z) : Vector3Base<float>(x, y, z) {}
	Vector3F(float x, float y) : Vector3Base<float>(x, y) {}
	Vector3F& operator=(Vector3Base<float>& base) const
	{
		auto val = Vector3F(base.x, base.y, base.z);
		return val;
	}
}
	
};
