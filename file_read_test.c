//#include <unistd.h>
//#include <stdio.h>
//#include <fcntl.h>

////void	display(char *filename)
////{
////	int		file;
////	char	character;

////	file = open(filename, 0); //  // 파일 디스크팁터 반환 0, 1, 2 표준 입력. 표준 출력, 표준 에러.  오픈ㅇ르 하게 되면 3
////	if (file < 0)
////	{
////		printf("%d", file);
////		printf("파일 열기 에러");
////		return ;
////	}

////	while (read(file, &character, 1))
////		write(1, &character, 1);
////	close(file);
////}

//void	display(char *filename)
//{
//	int		file;
//	char	buffer;
//	int r;

//	buffer = '\0';
//	file = open(filename, 0);
//	if (file < 0)
//	{
//		printf("%d", file); // 파일이 올바르지 않을경우 -1
//		printf("파일 열기 에러");
//		return ;
//	}

//	while(read(file, &buffer, 1) && buffer != '\n')
//	{
//		ft_putchar(buffer);
//	}

//	printf("\nfile 의 값: %d, buffer 의 값: %c\n",file, buffer);
//	close(file);
//}

//int		main(int argc, char *argv[])
//{
//	display("a");
//	return (0);
//}
