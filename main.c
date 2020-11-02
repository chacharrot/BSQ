/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychoi <ychoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:45:51 by ychoi             #+#    #+#             */
/*   Updated: 2020/11/03 06:06:37 by ychoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include <fcntl.h>

//int map_check()
//{
	//첫번쨰 행을 읽어야함. 5.ox 5행 빈문자: . / 장애물: o / 차 있는 문자 : x


	//지도는 빈문자와 장애물 문자로만 구성되어 있음. => 그렇지 않으면 오류.


	//모든 행의 길이가 같아야함.


	//행의 양쪽 끝에는 각각 줄바꿈이 있어야 합니다.
	//모든 행을 돌면서 길이가 같은지 체크. && 끝에 줄바꿈이 있는지 체크

	//최소 한 개의 상자에 최소한 한 개의 행이 있어야 합니다.
	//1개의 상자가

//}

int **map_alloc(t_map_info map_info)//지도의 사이즈를 초기화
{
	int **map;
	int i;
	int x;
	int y;

	map = (int **)malloc(sizeof(int*) * map_info.y_size + 1);
	i = 0;
	while (i < map_info.y_size + 1)
	{
		map[i] = (int *)malloc(sizeof(int) * map_info.x_size + 1);
		i++;
	}
	return map;
}

void map_init_value(int **map, t_map_info map_info, char *file_path)
{
	int x;
	int y;
	int fd;
	char buffer;

	fd = open(file_path, 0); //5사이즈.
	x = 0;
	while (x < map_info.x_size) // x값 초기화cat
		map[0][x] = 0;
	y = 0;
	while (y < map_info.y_size)
		map[y][0] = 0;
	x = 1;
	y = 1;
	printf("sdgsd");
	while(read(fd, &buffer, 1) && buffer != '\n')
		;
	while (y <= map_info.y_size)
	{
		x = 1;
		while(read(fd, &buffer, 1) && buffer != '\n') //첫째줄만 읽어옴.
		{
			if (buffer == map_info.empty_char) //1
				map[y][x] = 1;//값을 넣어줌.
			else if (buffer == map_info.obstacle_char)
				map[y][x] = 0;
			x++;
		}
		y++;
	}
	close(fd);
}

void	free_map(int **map)
{
	//y = 0;
	//while (map[y])
	//	free(map[y++]);
	//free(map);
}

t_map_info map_info_init(char *file_path)
{
	t_map_info map_info;
	int fd;
	char buffer;
	int x_len;

	fd = open(file_path, 0); //5사이즈.
	read(fd, &buffer, 1);
	map_info.y_size = buffer - '0';
	read(fd, &buffer, 1);
	map_info.empty_char = buffer;
	read(fd, &buffer, 1);
	map_info.obstacle_char = buffer;
	read(fd, &buffer, 1);
	map_info.square_char = buffer;
	read(fd, &buffer, 1);//개행까지 읽고
	x_len = 0;
	while(read(fd, &buffer, 1) && buffer != '\n') //첫째줄만 읽어옴.
		x_len++;
	map_info.x_size = x_len;
	close(fd); //파일 닫기.
	return map_info;
}

int main(int argc, char *argv[])
{
	int i;
	char *file_path;
	int **map;
	t_map_info map_info;
	t_solve solve;

	//전달된 인자가 없는 경우에는 프로그램은 표준 입력을 바탕으로 읽을 수 있어야 합니다.??
	if (argc == 1)
	{
		//표준 입력을 바탕으로 읽어야 함.
	}
	i = 1;
	while (i < argc) //여러 파일들이 들어옴.. file1, file2, file3
	{
		file_path = argv[i];
		printf("%s", file_path);
		//ft_putstr(argv[i]);
		//ft_putchar('\n');

		//if (map_check())
		//{
		//	write(1, "MapError" ,9);
		//	//인자에 대해 지도 정의
		//	//지도 오류를 표시하고 다음 줄바꿈이 되고, 다음 인자를 받아야 함.
		//}

		map_info = map_info_init(file_path); //지도의 대한 기본 정보를 가져옴.
		map = map_alloc(map_info); //맵의 사이즈만큼 배열을 동적으로 할당.
		map_init_value(map, map_info, file_path); //값을 초기화
		printf("mapinfo\n empty_char: %c\nobstacle_char: %c\n square_char: %c\n x_size: %d\n y_size: %d\n ", map_info.empty_char, map_info.obstacle_char, map_info.square_char, map_info.x_size, map_info.y_size);
		solve = mappuls(map);//맵의 정답을 찾음.
		solve_map(map, solve, map_info);
		//map_free(); //맵을 삭제해줌.
		i++;
	}
	return (0);
}
