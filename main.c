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

#include "header.h"



int **map_alloc(t_map_info map_info)//지도의 사이즈를 초기화
{
	int **map;
	int i;

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
	while (x <= map_info.x_size) // x값 초기화
		map[0][x++] = 0;
	y = 0;
	while (y <= map_info.y_size) // y값 초기화
		map[y++][0] = 0;
	y = 1;
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

void	free_map(int **map, t_map_info map_info)
{
	int i;

	i = 0;
	while (i < map_info.y_size + 1)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

unsigned int ft_n_atoi(char *str, int end)// 0부터 ~ end까지 int 값을 반환함.
{
	unsigned int num; // 0 ~ 1 . 0 과 1 을 가지고 atoi 함수를 만들어야함.

	num = 0;// size 까지 .. 0
	while (*str != '\0' && 0 <= end)
	{
		num = num * 10 + (*str - '0');
		str++;
		end--;
	}
	return num;
}

t_map_info map_info_init(char *file_path)
{
	t_map_info map_info;
	int fd;
	char buffer[BUF_SIZE];
	int x_len;
	int line_len;

	fd = open(file_path, 0);
	read(fd, buffer, BUF_SIZE); // 버퍼 사이즈 만큼 읽는다. 어처피 첫째줄이 512가 넘어갈리가 없다.
	line_len = 0;
	while (buffer[line_len] != '\n')
		line_len++;
	map_info.square_char = buffer[line_len - 1];
	map_info.obstacle_char = buffer[line_len - 2];
	map_info.empty_char = buffer[line_len - 3];
	map_info.y_size = ft_n_atoi(buffer, line_len - 4); //0부터 line_len - 4까지. 즉 0 1
	x_len = line_len + 1; //두번쨰 라인 수 세기
	while(buffer[x_len] != '\n') //첫째줄만 읽어옴.
		x_len++;
	map_info.x_size = x_len - (line_len + 1);
	close(fd); //파일 닫기.
	return map_info;
}

void print_int(int **map, t_map_info map_info)
{
	int j;
	int i;

	for (i = 0; i <= map_info.y_size; i++) {
		for (j = 0; j <= map_info.x_size; j++) {
			printf("%3d", map[i][j]);
		}
		printf("\n");
	}
}

char	*read_input(void)
{
	int		i;
	int r;
	char buffer;

	r = 1;
	while (r)
	{
		r = read(0, &buffer, 1);
	}
}

int main(int argc, char *argv[])
{
	int i;
	char *file_path;
	int **map;
	int r;
	t_map_info map_info;
	t_solve solve;

	//전달된 인자가 없는 경우(파일)에는 프로그램은 표준 입력을 바탕으로 (파일)을 읽을 수 있어야 합니다.??
//	if (argc == 1)
//	{
//		read_input();
//		//표준 입력을 바탕으로 읽어야 함.
//	}
	i = 1;
	while (i < argc) //여러 파일들이 들어옴.. file1, file2, file3
	{
		file_path = argv[i];
		printf("%s\n", file_path);
		//ft_putstr(argv[i]);
		//ft_putchar('\n');

		if (check(file_path))
		{
			write(2, "map error\n" ,10);
			//인자에 대해 지도 정의
			//지도 오류를 표시하고 다음 줄바꿈이 되고, 다음 인자를 받아야 함.
		}
		map_info = map_info_init(file_path); //지도의 대한 기본 정보를 가져옴.
		map = map_alloc(map_info); //맵의 사이즈만큼 배열을 동적으로 할당.
		map_init_value(map, map_info, file_path); //값을 초기화
		print_int(map, map_info);
		print_map(map, map_info);
//		printf("mapinfo\n empty_char: %c\nobstacle_char: %c\n square_char: %c\n x_size: %d\n y_size: %d\n ", map_info.empty_char, map_info.obstacle_char, map_info.square_char, map_info.x_size, map_info.y_size);
		solve = mappuls(map, map_info);//맵의 정답을 찾음.
		solve_map(map, solve, map_info);
		//map_free(); //맵을 삭제해줌.
		free_map(map, map_info);
		i++; // 다음 문자열을 접근함.
	}
	return (0);
}
