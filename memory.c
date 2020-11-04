#include "header.h"

void			free_map(char **map, t_map_info map_info)
{
	int i;

	i = 0;
	while (i < map_info.y_size + 1)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = 0;
}

void			free_reads(char *reads)
{
	free(reads);
	reads = 0;
}


char			**map_alloc(t_map_info map_info)//지도의 사이즈를 초기화
{
	char **map;
	int i;

	map = (char **)malloc(sizeof(char*) * map_info.y_size + 1);
	i = 0;
	while (i < map_info.y_size + 1)
	{
		map[i] = (char *)malloc(sizeof(char) * map_info.x_size + 1);
		i++;
	}
	return (map);
}


char *file_read_memory(char *file_path)
{
	char buffer[BUF_SIZE];
	int r;
	int fd;
	int count;
	char *reads;

	count = 1;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	else
	{
		while ((r = read(fd, buffer, BUF_SIZE))) //파일 끝날때까지 가로 개수 세기.
			count++;
		reads = (char *)malloc(sizeof(char) * (count * BUF_SIZE) + 1);
		if (reads == 0)
			return (0);
		fd = open(file_path, O_RDONLY);
		r = read(fd, reads, (count * BUF_SIZE));
		reads[r] = '\0';
		close(fd);
	}
	if (0 < r && reads[r - 1] != '\n')
		return (0);
	return (reads);
}