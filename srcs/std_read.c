/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 06:59:28 by scha              #+#    #+#             */
/*   Updated: 2020/11/05 07:00:53 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_argc_main(char *reads)
{
	char			**map;
	t_map_info		map_info;
	t_solve			solve;

	if (reads == 0 || check(reads))
	{
		write(2, "map error\n", 10);
		return (0);
	}
	map_info = map_info_init(reads);
	map = map_alloc(map_info);
	map_init_value(reads, map, map_info);
	solve = map_plus(map, map_info);
	solve_map(map, solve, map_info);
	free_map(map, map_info);
	free_reads(reads);
	return (1);
}

int		ft_read_input(void)
{
	char	*str;
	char	c;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char *));
	while (read(0, &c, 1) > 0)
	{
		str[i] = (char)malloc(sizeof(char));
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	ft_argc_main(str);
	return (1);
}
