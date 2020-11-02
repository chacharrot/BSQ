/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychoi <ychoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 04:32:03 by ychoi             #+#    #+#             */
/*   Updated: 2020/11/03 05:59:05 by ychoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>

typedef	struct	s_solve
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	size;
}				t_solve;

typedef struct	s_map_info
{
	unsigned int	x_size; //
	unsigned int	y_size; // row
	char			empty_char; //비어있는 캐릭터, 1
	char			obstacle_char; // 장애물. 0
	char			square_char;// 표시할거
}				t_map_info;

int		ft_min(int a, int b);
int		ft_max(int a, int b);

t_solve	mappuls(int **map);
void	solve_map(int **map, t_solve solve, t_map_info map_info);
void	print_map(int **map, t_map_info map_info);

void	ft_putchar(char c);
#endif
