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

int ft_is_printable(char c)
{
	if (c < 32 || 126 < c)
		return (0);
	return (1);
}

int		ft_is_numeric(char c)
{
	if (c < '0' || '9' < c)
		return (0);
	return (1);
}


int file_path_check(char *file_path)
{
	int fd;

	fd = open(file_path, 0);
	if (fd < 0)//음수가 나오는 경우 파일이 올바르지 않은거임.
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int first_line_validation_check(char *file_path)
{
	int fd;
	char buffer;
	int line_len;
	int r;

	buffer = '\0';
	fd = open(file_path, 0);
	line_len = -1; //buffer 를 읽고 증가시키기 떄문에
	while (buffer != '\n') //개행 나타날때까지 읽음.
	{
		r = read(fd, &buffer, 1);
		line_len++;
		if ((r == 0 || !ft_is_printable(buffer)) && buffer != '\n')
		{//개행 없이 파일 읽는게 끝날경우. 또는 출력 불가능한 문자가 있으면 잘못된 파일임. 널도 나올 수 있으므로 패스
			close(fd);
			return (1);
		}
	}
	close(fd);
	if (line_len < 4) //길이가 작으면 올바르지 않은 형식임. 최소 1.xo  널문자 제외 4개
		return (1);
	return (0);
}

int first_line_duplication_check(char *file_path)
{
	t_map_info map_info;
	int fd;
	char buffer[BUF_SIZE];
	int line_len;

	fd = open(file_path, 0);
	read(fd, buffer, BUF_SIZE); // 버퍼 사이즈 만큼 읽는다. 어처피 첫째줄이 512가 넘어갈리가 없다.
	close(fd);
	line_len = 0;
	while (buffer[line_len] != '\n')//널문자 제외 4개...
		line_len++;
	map_info.square_char = buffer[line_len - 1];
	map_info.obstacle_char = buffer[line_len - 2];
	map_info.empty_char = buffer[line_len - 3];
	if (map_info.square_char == map_info.obstacle_char)
		return (1);
	if (map_info.obstacle_char == map_info.empty_char)
		return (1);
	if (map_info.empty_char == map_info.square_char)
		return (1);
	return (0);
}

int char_vaildate(char *file_path)
{
	t_map_info map_info;
	int fd;
	char buffer;

	buffer = '\0';
	map_info = map_info_init(file_path);//행과 캐릭터등 기본 맵 검증이 되었으므로 호출가능
	fd = open(file_path, 0);
	while (buffer != '\n') //이미 검증이 되었으므로 사용가능
		read(fd, &buffer, 1);
	while (read(fd, &buffer, 1)) //파일을 끝까지 읽음
	{
		if (buffer != map_info.obstacle_char && // square_char 는 존재해선 안됨.
				buffer != map_info.empty_char &&
				buffer != '\n')
		{
			close(fd);
			return (1);
		}
	}
	close(fd);
}

int first_line_chek_number(char *file_path)
{
	int fd;
	char buffer[BUF_SIZE];
	int line_len;
	int i;

	i = 0;
	fd = open(file_path, 0);
	read(fd, buffer, BUF_SIZE); // 버퍼 사이즈 만큼 읽는다. 어처피 첫째줄이 512가 넘어갈리가 없다.
	line_len = 0;
	while (buffer[line_len] != '\n')
		line_len++;
	while (i <= line_len - 4)
	{
		if (!ft_is_numeric(buffer[i]))
		{
			close(fd);
			return (1);
		}
		i++;
	}
	close(fd);
	return (0);
}

int same_line(char *file_path)
{
	int fd;
	char buffer;
	int r;
	int x_len;

	buffer = '\0';
	while (buffer != '\n')
		read(fd, &buffer, 1);
	x_len = 0;
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
		{
			x_len = 0;
		}
		x_len ++;
		read(fd, &buffer, 1);
	}
	fd = open(file_path, 0);
}

int minimal_size_check(char *file_path)
{
	int fd;
	char buffer;
	int r;

	buffer = '\0';
	fd = open(file_path, 0);
	while (buffer != '\n')
		read(fd, &buffer, 1);
	r = read(fd, &buffer, 1);
	if (r == 0)
		return (1);
	return (0);
}

int check(char *file_path)
{
	if (file_path_check(file_path) == 1)
	{
		printf("파일 오류");
		return (1);
		//올바른 파일경로인지, 체크.
	}
	if (first_line_validation_check(file_path) == 1)
	{
		printf("첫번째 라인 유효성 체크에서 에러");
		return (1);
		//첫 번째 행에 어떤 문자가 없거나, 한줄만 존재하거나,
	}
	if (first_line_duplication_check(file_path) == 1)
	{
		printf("첫번쨰 라인 중복문자에서 에러");
		return (1);//두 개의 문자(빈 문자, 차 있는 문자, 장애물 문자)가 동일한 경우
	}
	if (first_line_chek_number(file_path) == 1)
	{
		printf("첫번쨰 라인의 숫자 에러");
		return (1);
		//첫번째 라인의 앞의 두자리가 숫자인가?
	}
//	if (same_line(file_path) == 1)
//	{
//		printf("모든 행이 같은 수인지");
//		return (1);
//		// 두번쨰 부터 끝까지 모든 행의 길이가 같아야함. 끝에 줄바꿈이 있는지 체크
//	}
	if (minimal_size_check(file_path) == 1)
	{
		printf("최소 한 개의 케이스에 최소한 한 개의 행 에러");
		return (1);
		// 지도는 최소 한 개의 케이스에 최소한 한 개의 행이 있어야 합니다.
	}
	if (char_vaildate(file_path) == 1)
	{
		printf("맵에 전혀다른 캐릭터가 나오면 에러");
		return (1);
		// 지도는 빈문자와 장애물 문자로만 구성되어 있음. => 그렇지 않으면 오류.
	}
	return (0);
}