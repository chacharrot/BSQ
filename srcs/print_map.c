/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 00:53:41 by scha              #+#    #+#             */
/*   Updated: 2020/11/05 06:57:12 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	solve_map(char **map, t_solve solve, t_map_info map_info)
{
	int i;
	int j;

	i = solve.y - solve.size + 1;
	while (i <= solve.y)
	{
		j = solve.x - solve.size + 1;
		while (j <= solve.x)
		{
			map[i][j] = map_info.square_char;
			j++;
		}
		i++;
	}
	print_map(map, map_info);
}

void	print_map(char **map, t_map_info map_info)
{
	int i;
	int j;

	i = 1;
	while (i <= map_info.y_size)
	{
		j = 1;
		while (j <= map_info.x_size)
		{
			if (map[i][j] == 0)
				ft_putchar(map_info.obstacle_char);
			else if (map[i][j] == map_info.square_char)
				ft_putchar(map_info.square_char);
			else
				ft_putchar(map_info.empty_char);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
