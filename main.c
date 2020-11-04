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


void	map_zero_padding(char **map, t_map_info map_info)
{
	int x;
	int y;
	x = 0;
	while (x <= map_info.x_size) // x값 초기화
		map[0][x++] = 0;
	y = 0;
	while (y <= map_info.y_size) // y값 초기화
		map[y++][0] = 0;
}

void	map_init_value(char *reads, char **map, t_map_info map_info)
{
	int x;
	int y;
	int i;

	map_zero_padding(map, map_info);
	y = 1;
	i = map_info.start_xy; // 2번쨰 행의 첫번쨰 열부터 시작.
	while (y <= map_info.y_size)
	{
		x = 1;
		while(reads[i] != '\n') //첫째줄만 읽어옴.
		{
			if (reads[i] == map_info.empty_char) //1
				map[y][x] = 1;//값을 넣어줌.
			else if (reads[i] == map_info.obstacle_char)
				map[y][x] = 0;
			x++;
			i++;
		}
		i++;
		y++;
	}
}

struct s_map_info map_info_init(char *reads)
{
	t_map_info map_info;
	int x_len;
	int line_len;

	line_len = 0;
	while (reads[line_len] != '\n')
		line_len++;
	map_info.square_char = reads[line_len - 1];
	map_info.obstacle_char = reads[line_len - 2];
	map_info.empty_char = reads[line_len - 3];
	map_info.y_size = ft_n_atoi(reads, line_len - 4);
	x_len = line_len + 1; //두번쨰 라인 수 세기
	map_info.start_xy = x_len;
	while(reads[x_len] != '\n')//첫째줄만 읽어옴.
		x_len++;
	map_info.x_size = x_len - (line_len + 1);
	return map_info;
}




int main(int argc, char *argv[])
{
	int i;
	char *file_path;
	char *reads; //모든 파일들
	char **map;
	t_map_info map_info;
	t_solve solve;

	//전달된 인자가 없는 경우(파일)에는 프로그램은 표준 입력을 바탕으로 (파일)을 읽을 수 있어야 합니다.??
//	if (argc == 1)
//	{
//		read_input();
//		//표준 입력을 바탕으로 읽어야 함. 전부다 읽으면됨. 그리고 나머지는 아래에서 처리하면 댐.
//	}
	i = 1;
	while (i < argc) //여러 파일들이 들어옴.. file1, file2, file3
	{
		file_path = argv[i];
		// 모든 파일들을 다 읽어오는 로직이 필요. => MN만큼 공간을 차지하게 됨.
		reads = file_read_memory(file_path);
		if(reads == 0)
		{
			write(2, "map error\n" ,10);
			i++;//아무 파일을 읽지 못했다면 리턴.
			continue;
		}
		if (check(reads))
		{
			write(2, "map error\n" ,10);
			//인자에 대해 지도 정의
			//지도 오류를 표시하고 다음 줄바꿈이 되고, 다음 인자를 받아야 함.
		}

		//예외 처리가 통과가 되었으면 first_line 을 나누는 방법. 1
		//그대로 사용한다 2.

		map_info = map_info_init(reads); //지도의 대한 기본 정보를 가져옴.
		map = map_alloc(map_info); //맵의 사이즈만큼 배열을 동적으로 할당.
		map_init_value(reads, map, map_info); //값을 초기화
		solve = map_plus(map, map_info);//맵의 정답을 찾음.
//		print_int(map, map_info);//지워야함.
		solve_map(map, solve, map_info);
		//map_free(); //맵을 삭제해줌.
		free_map(map, map_info);
		free_reads(reads);
		i++; // 다음 문자열을 접근함.
	}
	return (0);
}
