#pragma once

template<typename T>
class VectorBase
{
public:
	VectorBase<T>()
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use none-arithmetic type with vectors");
	};
};