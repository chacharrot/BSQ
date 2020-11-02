/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapplus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:46:14 by scha              #+#    #+#             */
/*   Updated: 2020/11/03 00:44:07 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_min(int a, int b)
{
	return (a >= b ? b : a);
}

int				ft_max(int a, int b)
{
	return (a >= b ? a : b);
}

typedef struct  s_answer_square
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	size;
}			t_answer_square;

t_answer_square	mappuls(int **map)
{
	int	col;
	int	row;
	int temp;
	t_answer_square		solve;

	solve.size = 0;
	col = 1;
	row = 1;
	while (map[col][row])
	{
		row = 1;
		while (map[col][row])
		{
			if (map[col][row] == 0)
				row++;
			temp = ft_min(map[col][row - 1], map[col - 1][row]);
			map[row][col] = ft_min(map[col - 1][row - 1], temp) + 1;
			if (map[col][row] > solve.size)
			{
				slove.x = row;
				slove.y = col;
			}
			row++;
		}
		col++;
	}
	return (slove);
}
