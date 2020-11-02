/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapplus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychoi <ychoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:46:14 by scha              #+#    #+#             */
/*   Updated: 2020/11/03 05:47:44 by ychoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_min(int a, int b)
{
	return (a >= b ? b : a);
}

int		ft_max(int a, int b)
{
	return (a >= b ? a : b);
}

void	insert_solve(t_solve *solve, int size, int row, int col)
{
	solve->x = row;
	solve->y = col;
	solve->size = size;
}

t_solve	mappuls(int **map, t_map_info map_info)
{
	int		i;
	int		j;
	int		temp;
	t_solve	solve;

	solve.size = 0; //최대 크기를 0으로 초기화. 0은 정답이 없음을 의미
	i = 1;
	while (i <= map_info.y_size)
	{
		j = 1;
		while (j <= map_info.x_size)
		{
			if (map[i][j] != 0)
			{
				temp = ft_min(map[i][j - 1], map[i - 1][j]);
				map[i][j] = ft_min(map[i - 1][j - 1], temp) + 1;
				if (map[i][j] > solve.size)
					insert_solve(&solve, map[i][j], j, i);
			}
			j++;
		}
		i++;
	}
	return (solve);
}
