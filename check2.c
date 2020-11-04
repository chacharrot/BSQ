
#include "header.h"

int		first_line_len_check(char *read)
{
	int i;

	i = 0;
	while (read[i] && read[i] != '\n')
	{
		if(!ft_is_printable(read[i]) && read[i] != '\n')
		{//출력 불가능한 문자가 있으면 잘못된 파일임. 널도 안댐
			return (1);
		}
		i++;
	}
	if (i < 4)
		return (1);
	return (0);
}

int		first_line_duplication_check(char *reads)
{
	int line_len;
	t_map_info map_info;

	line_len = 0;
	while (reads[line_len] != '\n')//널문자 제외 4개...
		line_len++;
	map_info.square_char = reads[line_len - 1];
	map_info.obstacle_char = reads[line_len - 2];
	map_info.empty_char = reads[line_len - 3];
	if (map_info.square_char == map_info.obstacle_char)
		return (1);
	if (map_info.obstacle_char == map_info.empty_char)
		return (1);
	if (map_info.empty_char == map_info.square_char)
		return (1);
	return (0);
}

int		first_line_chek_number(char *reads)
{
	int i;
	int line_len;

	line_len = 0;
	while (reads[line_len] != '\n')//널문자 제외 4개...
		line_len++;
	i = 0;
	while (i <= line_len - 4)
	{
		if (!ft_is_numeric(reads[i]))
			return (1);
		i++;
	}
	return (0);
}

int		minimal_size_check(char *reads)
{
	int i;

	i = 0;
	while (reads[i] != '\n')
		i++;
	if (!ft_is_printable(reads[i + 1])) //첫번쨰가 프린트 가능한게 있지 않다면 잘못된 지도.
		return (1);
	return (0);
}
