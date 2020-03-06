#pragma once
#include "VectorBase.h"

template<typename T>
class Vec2 : public VectorBase<T>
{
public:
	Vec2<T>()
	{};
private:
	T x;
	T y;
};

