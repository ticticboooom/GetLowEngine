#pragma once
#include <type_traits>

#include "VectorBase.h"

template<typename T>
class Vector2Base : public VectorBase<T>
{
public:
	Vector2Base<T>();
	Vector2Base<T>(T x, T y);;
	T x;
	T y;

	Vector2Base<T>& operator-(Vector2Base<T> v0);

	Vector2Base<T>& operator+(Vector2Base<T> v0);

	Vector2Base<T>& operator*(Vector2Base<T> v0);

	Vector2Base<T>& operator/(Vector2Base<T> v0);

	void operator-=(Vector2Base<T> v0);

	void operator+=(Vector2Base<T> v0);

	void operator*=(Vector2Base<T> v0);

	void operator/=(Vector2Base<T> v0);
};

template <typename T>
Vector2Base<T>::Vector2Base(): VectorBase<T>()
{
}

template <typename T>
Vector2Base<T>::Vector2Base(T x, T y): VectorBase<T>()
{
	this->x = x;
	this->y = y;
}

template <typename T>
Vector2Base<T>& Vector2Base<T>::operator-(Vector2Base<T> v0)
{
	Vector2Base<T> result = Vector2Base<T>();
	result.x = this->x - v0.x;
	result.y = this->y - v0.y;
	return result;
}

template <typename T>
Vector2Base<T>& Vector2Base<T>::operator+(Vector2Base<T> v0)
{
	Vector2Base<T> result = Vector2Base<T>();
	result.x = this->x + v0.x;
	result.y = this->y + v0.y;
	return result;
}

template <typename T>
Vector2Base<T>& Vector2Base<T>::operator*(Vector2Base<T> v0)
{
	Vector2Base<T> result = Vector2Base<T>();
	result.x = this->x * v0.x;
	result.y = this->y * v0.y;
	return result;
}

template <typename T>
Vector2Base<T>& Vector2Base<T>::operator/(Vector2Base<T> v0)
{
	Vector2Base<T> result = Vector2Base<T>();
	result.x = this->x / v0.x;
	result.y = this->y / v0.y;
	return result;
}

template <typename T>
void Vector2Base<T>::operator-=(Vector2Base<T> v0)
{
	this->x -= v0.x;
	this->y -= v0.y;
}

template <typename T>
void Vector2Base<T>::operator+=(Vector2Base<T> v0)
{
	this->x += v0.x;
	this->y += v0.y;
}

template <typename T>
void Vector2Base<T>::operator*=(Vector2Base<T> v0)
{
	this->x *= v0.x;
	this->y *= v0.y;
}

template <typename T>
void Vector2Base<T>::operator/=(Vector2Base<T> v0)
{
	this->x /= v0.x;
	this->y /= v0.y;
}
