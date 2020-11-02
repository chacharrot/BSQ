#include <unistd.h>
#include <stdio.h>

void	display(char *filename)
{
	int		file;
	char	character;

	file = open(filename, 0);
	if (file < 0)
		return ;
	while (read(file, &character, 1))
		write(1, &character, 1);
	close(file);
}
int		main(int argc, char *argv[])
{
	display("a");
	return (0);
}
