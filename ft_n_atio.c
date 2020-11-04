#include "header.h"

int				ft_n_atoi(char *str, int end)// 0부터 ~ end까지 int 값을 반환함.
{
	int num; // 0 ~ 1 . 0 과 1 을 가지고 atoi 함수를 만들어야함.

	num = 0;// size 까지 .. 0
	while (*str != '\0' && 0 <= end)
	{
		num = num * 10 + (*str - '0');
		str++;
		end--;
	}
	return num;
}