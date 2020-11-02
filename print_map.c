/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychoi <ychoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 00:53:41 by scha              #+#    #+#             */
/*   Updated: 2020/11/03 05:45:37 by ychoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	solve_map(int **map, t_solve solve, t_map_info map_info)
{
	int i;
	int j;

	i = solve.y - solve.size + 1;
	j = solve.x - solve.size + 1;
	while (i <= solve.y)//m
	{
		j = solve.x - solve.size + 1;
		while (j <= solve.x)
		{
			map[i][j] = map_info.square_char;// x가 들어감.
			j++;
		}
		i++;
	}
	print_map(map, map_info);
}

void	print_map(int **map, t_map_info map_info)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i <= map_info.y_size)
	{
		while (j <= map_info.x_size)
		{
			if (map[i][j] == 0) // 벽일때
				ft_putchar(map_info.obstacle_char);
			if (map[i][j] == 1) // 비어 있을떄
				ft_putchar(map_info.empty_char);
			else//채워진 곳. 정사각형
				ft_putchar(map_info.square_char);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}