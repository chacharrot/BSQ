/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:57:16 by scha              #+#    #+#             */
/*   Updated: 2020/11/05 06:48:34 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		same_line_and_char_validation(char *reads)
{
	unsigned int	i;
	int				line_len;
	int				y_count;
	t_map_info		map_info;
	char			c;

	line_len = 0;
	while (reads[line_len] != '\n')
		line_len++;
	i = line_len + 1;
	map_info = map_info_init(reads);
	line_len = 0;
	y_count = 0;
	while (reads[i])
	{
		c = reads[i];
		line_len++;
		if (reads[i] != map_info.obstacle_char &&
			reads[i] != map_info.empty_char && reads[i] != '\n')
			return (1);
		if (reads[i] == '\n')
		{
			if (line_len - 1 != map_info.x_size)
				return (1);
			line_len = 0;
			y_count++;
		}
		i++;
		if (map_info.y_size == y_count)
			break ;
	}
	if (map_info.y_size != y_count || reads[i] != '\0')
		return (1);
	return (0);
}

int		check(char *reads)
{
	if (first_line_len_check(reads) == 1)
	{
		printf("첫번째 라인 유효성 체크에서 에러");
		return (1);
	}
	if (first_line_duplication_check(reads) == 1)
	{
		printf("첫번쨰 라인 중복문자에서 에러");
		return (1);
	}
	if (first_line_chek_number(reads) == 1)
	{
		printf("첫번쨰 라인의 숫자 에러");
		return (1);
	}
	if (minimal_size_check(reads) == 1)
	{
		printf("최소 한 개의 케이스에 최소한 한 개의 행 에러");
		return (1);
	}
	if (same_line_and_char_validation(reads) == 1)
	{
		printf("모든 행과 열이 같은 수인지");
		return (1);
	}
	return (0);
}
