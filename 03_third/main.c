#include <unistd.h>

void print(int result)
{
	if (result > 9)
		print(result / 10);
	write(1, &"0123456789"[result % 10], 1);
}

int factorial(int num)
{
	if (num == 1)
		return (1);
	return (num * factorial(num - 1));
}

int main(void)
{
	int result = factorial(4);
	print(result);
}
