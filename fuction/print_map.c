/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychoi <ychoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 00:53:41 by scha              #+#    #+#             */
/*   Updated: 2020/11/03 03:38:11 by ychoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	solve_map(int **map, t_answer_square solve, t_map_info originmap)
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
			map[i][j] = originmap.square_char;// x가 들어감.
			j++;
		}
		i++;
	}
	print_map(map, originmap);
}

void	print_map(int **map, t_map_info originmap)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i <= originmap.y_size)
	{
		while (j <= originmap.x_size)
		{
			if (map[i][j] == 0) // 벽일때
				ft_putchar(originmap.obstacle_char);
			if (map[i][j] == 1) // 비어 있을떄
				ft_putchar(originmap.empty_char);
			else//채워진 곳. 정사각형
				ft_putchar(originmap.square_char);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
