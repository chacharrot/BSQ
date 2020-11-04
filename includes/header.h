/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 04:32:03 by ychoi             #+#    #+#             */
/*   Updated: 2020/11/05 07:20:04 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUF_SIZE 1024

typedef	struct		s_solve
{
	int				x;
	int				y;
	int				size;
}					t_solve;

typedef struct		s_map_info
{
	int				x_size;
	int				y_size;
	char			empty_char;
	char			obstacle_char;
	char			square_char;
	int				start_xy;
}					t_map_info;

void				map_zero_padding(char **map, t_map_info map_info);
void				map_init_value(char *reads, char **map,
										t_map_info map_info);
struct s_map_info	map_info_init(char *reads);
int					main(int argc, char *argv[]);

int					same_line_and_char_validation(char *reads);
int					check(char *reads);

int					first_line_len_check(char *read);
int					first_line_duplication_check(char *reads);
int					first_line_chek_number(char *reads);
int					minimal_size_check(char *reads);

int					ft_is_numeric(char c);
int					ft_is_printable(char c);

int					ft_n_atoi(char *str, int end);
void				ft_putchar(char c);

char				ft_min(char a, char b);
void				insert_solve(t_solve *solve, int size, int row, int col);
struct s_solve		map_plus(char **map, t_map_info map_info);

void				free_map(char **map, t_map_info map_info);
void				free_reads(char *reads);
char				**map_alloc(t_map_info map_info);
char				*file_read_memory(char *file_path);

void				solve_map(char **map, t_solve solve, t_map_info map_info);
void				print_map(char **map, t_map_info map_info);

int					ft_argc_main(char *reads);
int					ft_read_input(void);

#endif
