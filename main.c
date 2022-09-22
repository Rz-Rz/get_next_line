#include <fcntl.h>
#include "get_next_line_bonus.h"
#include <stdio.h>



int main ()
{
	// Use the get next line function using multiple fd. Iterate though each fd and see if the function keeps getting the good lines. Each time print the strings returned by the function.
		int fd;
		int fd2;
		int fd3;
		int i = 0;
		char *str; 
		char *str2; 
		char *str3; 
		fd = open("tests/lorem", O_RDONLY);
		fd2 = open("tests/simple", O_RDONLY);
		fd3 = open("tests/bible.txt", O_RDONLY);
		printf("fd: %d\n", fd);
		printf("fd: %d\n", fd2);
		printf("fd: %d\n", fd3);
		str = get_next_line(fd);
		str2 = get_next_line(fd2);
		str3 = get_next_line(fd3);
		while (str || str2 || str3)
		{
			if (str)
			{
				printf("%s\n", str);
				free(str);
			}
			if (str2)
			{
				printf("%s\n", str2);
				free(str2);
			}
			if (str3)
			{
				printf("%s\n", str3);
				free(str3);
			}
			str = get_next_line(fd);
			str2 = get_next_line(fd2);
			str3 = get_next_line(fd3);
			i++;
			/* if (i== 20) */
			/* 	break; */
		}
		char *line;

		/* fd = open("tests/lorem", O_RDONLY); */
		/* while(1) */
		/* { */
		/* 		line = get_next_line(fd); */
		/* 		if (!line) */
		/* 				break; */
		/* 		printf("%s", line); */
		/* 		free(line); */
		/* } */
		return 0;
}

