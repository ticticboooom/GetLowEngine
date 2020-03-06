#pragma once
#include "VectorBase.h"

template<typename  T>
class Vector3Base : public VectorBase<T>
{
public:
	Vector3Base(): VectorBase<T>() {};
	Vector3Base(T x, T y, T z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector3Base(T x, T y)
	{
		this->x = x;
		this->y = y;
		this->z = 0;
	};
	
	T x;
	T y;
	T z;

	Vector3Base<T> operator-(Vector3Base<T> v0)
	{
		Vector3Base<T> result = Vector3Base<T>();
		result.x = this->x - v0.x;
		result.y = this->y - v0.y;
		result.z = this->z - v0.z;
		return result;
	}
	Vector3Base<T> operator+(Vector3Base<T> v0)
	{
		Vector3Base<T> result = Vector3Base<T>();
		result.x = this->x + v0.x;
		result.y = this->y + v0.y;
		result.z = this->z + v0.z;
		return result;
	}
	Vector3Base<T> operator*(Vector3Base<T> v0)
	{
		Vector3Base<T> result = Vector3Base<T>();
		result.x = this->x * v0.x;
		result.y = this->y * v0.y;
		result.z = this->z * v0.z;
		return result;
	}
	Vector3Base<T> operator/(Vector3Base<T> v0)
	{
		Vector3Base<T> result = Vector3Base<T>();
		result.x = this->x / v0.x;
		result.y = this->y / v0.y;
		result.z = this->z / v0.z;
		return result;
	}
};
