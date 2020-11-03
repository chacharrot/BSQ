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
#include <stdio.h> //지워야함
#include <fcntl.h>
#include <stdlib.h>

#define BUF_SIZE 1024

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

t_solve	mappuls(int **map, t_map_info map_info);
void	solve_map(int **map, t_solve solve, t_map_info map_info);
void	print_map(int **map, t_map_info map_info);
t_map_info map_info_init(char *file_path);

void	ft_putchar(char c);
int check(char *file_path);

void print_int(int **map, t_map_info map_info);//지워야함.

#endif
