/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:57:16 by scha              #+#    #+#             */
/*   Updated: 2020/11/02 20:57:16 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int same_line_and_char_validation(char *reads)
{
	unsigned int i;
	int line_len;
	int y_count;
	t_map_info map_info;
	char c;

	line_len = 0;
	while (reads[line_len] != '\n')
		line_len++;
	i = line_len + 1; // 2번쨰 행의 첫번쨰 열부터 시작.
	map_info = map_info_init(reads);
	line_len = 0;
	y_count = 0;
	while (reads[i]) // 파일을 끝까지 읽음.
	{
		c = reads[i];
		line_len++;
		if (reads[i] != map_info.obstacle_char && // square_char 는 존재해선 안됨.
			reads[i] != map_info.empty_char && reads[i] != '\n')
			return (1);
		if (reads[i] == '\n') //개행이 나왔을 때, 열이 다르면 바로 리턴.
		{
			if (line_len - 1 != map_info.x_size)
				return (1);
			line_len = 0;
			y_count++;
		}
		i++;
		if (map_info.y_size == y_count)
			break;
	}
	if (map_info.y_size != y_count || reads[i] != '\0')
		return (1);
	return (0);
}

int check(char *reads)
{
	if (first_line_len_check(reads) == 1)
	{
		printf("첫번째 라인 유효성 체크에서 에러");
		return (1);
		//첫 번째 행에 어떤 문자가 없거나, 길이가 안되거나.
	}
	if (first_line_duplication_check(reads) == 1)
	{
		printf("첫번쨰 라인 중복문자에서 에러");
		return (1);//두 개의 문자(빈 문자, 차 있는 문자, 장애물 문자)가 동일한 경우
	}
	if (first_line_chek_number(reads) == 1)
	{
		printf("첫번쨰 라인의 숫자 에러");
		return (1);
		//첫번째 라인의 앞의 두자리가 숫자인가?
	}
	if (minimal_size_check(reads) == 1)
	{
		printf("최소 한 개의 케이스에 최소한 한 개의 행 에러");
		return (1);
		// 지도는 최소 한 개의 케이스에 최소한 한 개의 행이 있어야 합니다.
	}
	if (same_line_and_char_validation(reads) == 1)
	{
		printf("모든 행과 열이 같은 수인지");
		return (1);
		// 두번쨰 부터 끝까지 모든 행의 길이가 같아야함. 끝에 줄바꿈이 있는지 체크
		// 지도는 빈문자와 장애물 문자로만 구성되어 있음. => 그렇지 않으면 오류.
	}
	return (0);
}