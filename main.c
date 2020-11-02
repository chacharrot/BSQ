/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychoi <ychoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:45:51 by ychoi             #+#    #+#             */
/*   Updated: 2020/11/02 23:17:48 by ychoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct  s_answer_square
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	size;
}			t_answer_square;

typedef struct  s_map_info
{
	unsigned int	x_size; //
	unsigned int	y_size; // row
	char	empty_char;
	char	obstacle_char;
}			t_map_info;




int map_check()
{
	//첫번쨰 행을 읽어야함. 5.ox 5행 빈문자: . / 장애물: o / 차 있는 문자 : x


	//지도는 빈문자와 장애물 문자로만 구성되어 있음. => 그렇지 않으면 오류.


	//모든 행의 길이가 같아야함.


	//행의 양쪽 끝에는 각각 줄바꿈이 있어야 합니다.
	//모든 행을 돌면서 길이가 같은지 체크. && 끝에 줄바꿈이 있는지 체크

	//최소 한 개의 상자에 최소한 한 개의 행이 있어야 합니다.
	//1개의 상자가
}


void print_map(char map)
{
	//지도를 그릴 함수.
}

int map_init()
{
	int **dp_map;

	dp_map = (int **)malloc(sizeof(int*) * s_map_info -> y_size + 1);
	dp_map = (int *)malloc(sizeof(int) * s_map_info -> x_size + 1);

	return
}

int main(int argc, char *argv[])
{
	int i;
	//전달된 인자가 없는 경우에는 프로그램은 표준 입력을 바탕으로 읽을 수 있어야 합니다.??
	if (argc == 1)
	{
		//표준 입력을 바탕으로 읽어야 함.
	}

	i = 1;
	while (i < argc) //여러 파일들이 들어옴.. file1, file2, file3
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');

		if (map_check())
		{
			write(1, "MapError" ,9);
			//인자에 대해 지도 정의
			//지도 오류를 표시하고 다음 줄바꿈이 되고, 다음 인자를 받아야 함.
		}

		// free_malloc
		i++;
	}
}
