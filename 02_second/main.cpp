#include "Calc.hpp"

void print(int num)
{
	std::cout << std::to_string(num) << std::endl;
}

int        main(void)
{
	Calc calculator(0);

	int result = calculator.add(4).add(5).substract(3).out();
	print(result);
}