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

int file_path_check(char *file_path)
{
	int fd;

	fd = open(file_path, 0);
	if (fd < 0)//음수가 나오는 경우 파일이 올바르지 않은거임.
		return (1);
	close(fd);
	return (0);
}

int first_line_check(char *file_path)
{
	int fd;
	char buffer;
	int line_len;

	line_len = 0;
	fd = open(file_path, 0);
	while(read(fd, &buffer, 1) && buffer != '\n') //첫째줄만 읽어옴.
		line_len++;
}

int char_vaildate()
{

}

int same_line()
{

}

int minimal_size_check()
{

}

int check(char *file_path)
{
	if (file_path_check(file_path) == 1)
	{
		return (1);
		//올바른 파일경로인지, 체크.
	}
	if (first_line_check(file_path))
	{
		//첫 번째 행에 어떤 문자가 없거나 두 개의 문자(빈 문자, 차 있는 문자, 장애물 문자)가 동일한 경우 지도는 유효하지 않습니다
	}
	if (char_vaildate())
	{
		// 지도는 빈문자와 장애물 문자로만 구성되어 있음. => 그렇지 않으면 오류.
	}
	if (same_line())
	{
		// 두번쨰 부터 끝까지 모든 행의 길이가 같아야함. 끝에 줄바꿈이 있는지 체크
	}
	if (minimal_size_check())
	{
		// 지도는 최소 한 개의 케이스에 최소한 한 개의 행이 있어야 합니다.
	}
	return (0);
}