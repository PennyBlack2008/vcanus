#include <unistd.h>

void print(int result)
{
	if (result > 9)
		print(result / 10);
	write(1, &"0123456789"[result % 10], 1);
}

int factorial(int num)
{
	if (num > 30)
		return (-1);
	if (num == 1)
		return (1);
	return (num * factorial(num - 1));
}

/* 30! = 1409286144 이고, 31! 부터는 int 표현값을 넘어버리므로 예외처리 */
int main(void)
{
	int result = factorial(30);
	print(result);
}
