#include <iostream>

class Calc
{
public:
	Calc(const int& value);

	Calc&	add(int value);
	Calc&	substract(int value);
	Calc&	mul(int value);
	int		out(void);
private:
	int		mValue;
};
