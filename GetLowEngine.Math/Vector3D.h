#pragma once
#include "Vector3Base.h"

class Vector3D : public Vector3Base<double>
{
public:
	Vector3D() : Vector3Base<double>() {};
	Vector3D(double x, double y, double z) : Vector3Base<double>(x, y, z) {};
	Vector3D(double x, double y) : Vector3Base<double>(x, y) {};
	Vector3D& operator=(Vector3Base<double>& base) const
	{
		auto val = Vector3D(base.x, base.y, base.z);
		return val;
	}
};