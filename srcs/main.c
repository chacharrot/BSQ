/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:45:51 by ychoi             #+#    #+#             */
/*   Updated: 2020/11/05 08:14:43 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				map_zero_padding(char **map, t_map_info map_info)
{
	int x;
	int y;

	x = 0;
	while (x <= map_info.x_size)
		map[0][x++] = 0;
	y = 0;
	while (y <= map_info.y_size)
		map[y++][0] = 0;
}

void				map_init_value(char *reads, char **map, t_map_info map_info)
{
	int x;
	int y;
	int i;

	map_zero_padding(map, map_info);
	y = 1;
	i = map_info.start_xy;
	while (y <= map_info.y_size)
	{
		x = 1;
		while (reads[i] != '\n')
		{
			if (reads[i] == map_info.empty_char)
				map[y][x] = 1;
			else if (reads[i] == map_info.obstacle_char)
				map[y][x] = 0;
			x++;
			i++;
		}
		i++;
		y++;
	}
}

struct	s_map_info	map_info_init(char *reads)
{
	t_map_info	map_info;
	int			x_len;
	int			line_len;

	line_len = 0;
	while (reads[line_len] != '\n')
		line_len++;
	map_info.square_char = reads[line_len - 1];
	map_info.obstacle_char = reads[line_len - 2];
	map_info.empty_char = reads[line_len - 3];
	map_info.y_size = ft_n_atoi(reads, line_len - 4);
	x_len = line_len + 1;
	map_info.start_xy = x_len;
	while (reads[x_len] != '\n')
		x_len++;
	map_info.x_size = x_len - (line_len + 1);
	return (map_info);
}

int					main_while(char *reads)
{
	char		**map;
	t_map_info	map_info;
	t_solve		solve;

	map_info = map_info_init(reads);
	map = map_alloc(map_info);
	map_init_value(reads, map, map_info);
	solve = map_plus(map, map_info);
	solve_map(map, solve, map_info);
	free_map(map, map_info);
	free_reads(reads);
	return (0);
}

int					main(int argc, char *argv[])
{
	int			i;
	char		*reads;

	i = 1;
	if (argc == 1)
	{
		ft_read_input();
	}
	else
	{
		while (i < argc)
		{
			reads = file_read_memory(argv[i]);
			if (reads == 0 || check(reads))
				write(2, "map error\n", 10);
			else
			{
				main_while(reads);
				if (i < argc - 1)
					write(1, "\n", 1);
			}
			i++;
		}
	}
	return (0);
}
