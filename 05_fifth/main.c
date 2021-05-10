#include <unistd.h>

static void	check_all_directions(char arr[][10], int num, int x, int y)
{
	const int	directx[] = { 0, 1, -1, 0 }; // 세로
	const int	directy[] = { -1, 0, 0, 1 }; // 가로
	int			i;
	int			nextx;
	int			nexty;

	i = 0;
	while (i < 4)
	{
		nextx = directx[i] + x;
		nexty = directy[i] + y;
		if ((nextx < 0 || nextx >= 10) ||
			(nexty < 0 || nexty >= 10))
			return ;
		if (arr[nextx][nexty] == num ||
			arr[nextx][nexty] == num + 1)
			i++;
		else
			return ;
	}
	arr[x][y] = num + 1;
}

int main(void)
{
	int num, x, y, width, height, limit;
	width = 10; height = 10;
	char pos[10][10] =
		{
			{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}, // 1
			{'0', '0', '0', '0', '1', '0', '0', '0', '0', '0'}, // 2
			{'0', '0', '0', '1', '1', '1', '0', '0', '0', '0'}, // 3
			{'0', '1', '1', '1', '1', '1', '1', '0', '0', '0'}, // 4
			{'0', '1', '1', '1', '1', '1', '1', '1', '1', '0'}, // 5
			{'0', '1', '1', '1', '1', '1', '1', '1', '1', '0'}, // 6
			{'0', '0', '1', '1', '1', '1', '1', '1', '0', '0'}, // 7
			{'0', '0', '0', '1', '1', '1', '1', '0', '0', '0'}, // 8
			{'0', '0', '0', '0', '1', '0', '0', '0', '0', '0'}, // 9
			{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'} // 10
		};
	/* while 문 탈출 조건 계산 */
	if (width >= height)
		limit = height / 2 + '0';
	else
		limit = width / 2 + '0';
	num = 1 + '0';
	while (num < limit)
	{
		x = 0; // 세로
		while (x < 10)
		{
			y = 0; // 가로
			while (y < 10)
			{
				check_all_directions(pos, num, x, y);
				y++;
			}
			x++;
		}
		num++;
	}

	x = 0;
	while (x < 10)
	{
		write(1, pos[x], 10);
		write(1, "\n", 1);
		x++;
	}
	return (0);
}