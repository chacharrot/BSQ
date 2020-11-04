/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_plus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:46:14 by scha              #+#    #+#             */
/*   Updated: 2020/11/05 06:51:40 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char			ft_min(char a, char b)
{
	return (a >= b ? b : a);
}

void			insert_solve(t_solve *solve, int size, int row, int col)
{
	solve->x = row;
	solve->y = col;
	solve->size = size;
}

struct	s_solve	map_plus(char **map, t_map_info map_info)
{
	int		i;
	int		j;
	char	temp;
	t_solve	solve;

	solve.size = 0;
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
