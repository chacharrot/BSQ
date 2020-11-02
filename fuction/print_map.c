/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 00:53:41 by scha              #+#    #+#             */
/*   Updated: 2020/11/03 03:11:52 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	return_map(int **map, t_answer_square solve, t_map_info originmap)
{
	int i;
	int j;

	i = 1;
	while (i <= originmap.y_size)
	{
		j = 1;
		while (j <= originmap.x_size)
		{
			if (map[i][j] == 0)
				map[i][j] == originmap.obstacle_char;
			else
				map[i][j] == originmap.empty_char;
			j++;
		}
		i++;
	}
}

int		**solve_map(int **map, t_answer_square solve, t_map_info originmap)
{
	int i;
	int j;

	i = 0;
	while (solve.y - i++ && i < size)
	{
		j = 0;
		while (solve.x - j && j < size)
			map[solve.y - i][solve.x - j++] = square_char;
	}
	return (map);
}

void	print_map(**map,t_map_info originmap)
{
	int i;
	int j;
	
	i = 1;
	j = 1;
	while(i <= originmap.y_size)
		{
			while (j <= originmap.x_size)
			{
				write(1, map[i][j++],1);
			}
			write(1, "\n", 1);
			i++;
		}
}
