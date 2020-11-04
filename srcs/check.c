/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:57:16 by scha              #+#    #+#             */
/*   Updated: 2020/11/05 08:09:32 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		if_map_info_check(char *reads, int i, t_map_info map_info)
{
	if (reads[i] != map_info.obstacle_char &&
		reads[i] != map_info.empty_char && reads[i] != '\n')
		return (1);
	return (0);
}

int		same_line_and_char_validation(char *reads, t_map_info map_info)
{
	int				i;
	int				line_len;

	g_y_count = 0;
	i = map_info.start_xy;
	line_len = 0;
	while (reads[i])
	{
		line_len++;
		if (if_map_info_check(reads, i, map_info) == 1)
			return (1);
		if (reads[i] == '\n')
		{
			if (line_len - 1 != map_info.x_size)
				return (1);
			line_len = 0;
			g_y_count++;
		}
		i++;
		if (map_info.y_size == g_y_count)
			break ;
	}
	if (map_info.y_size != g_y_count || reads[i] != '\0')
		return (1);
	return (0);
}

int		check(char *reads)
{
	t_map_info		map_info;

	if (first_line_len_check(reads) == 1)
		return (1);
	if (first_line_duplication_check(reads) == 1)
		return (1);
	if (first_line_chek_number(reads) == 1)
		return (1);
	if (minimal_size_check(reads) == 1)
		return (1);
	map_info = map_info_init(reads);
	if (same_line_and_char_validation(reads, map_info) == 1)
		return (1);
	return (0);
}
