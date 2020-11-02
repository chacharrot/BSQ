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

t_solve	mappuls(int **map)
{
	int		col;
	int		row;
	int		temp;
	t_solve	solve;

	solve.size = 0;
	col = 1;
	while (map[col][row])
	{
		row = 1;
		while (map[col][row])
		{
			if (map[col][row] != 0)
			{
				temp = ft_min(map[col][row - 1], map[col - 1][row]);
				map[row][col] = ft_min(map[col - 1][row - 1], temp) + 1;
				if (map[col][row] > solve.size)
					insert_solve(&solve, map[col][row], row, col);
			}
			row++;
		}
		col++;
	}
	return (solve);
}

