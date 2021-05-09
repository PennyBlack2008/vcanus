#include "Calc.hpp"

Calc::Calc(const int& value)
	: mValue(value)
{
}

Calc&	Calc::add(int value)
{
	mValue += value;
	return *this;
}

Calc&	Calc::substract(int value)
{
	mValue -= value;
	return *this;
}

Calc&	Calc::mul(int value)
{
	mValue *= value;
	return *this;
}

int		Calc::out(void)
{
	return (mValue);
}