#include "get_next_line.h"
#include <stdio.h>

int main (void)
{
	int		fd;
	char	*line;

	fd = open("textfile.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	if (line)
		free (line);
	line = get_next_line(fd);
	printf("%s\n", line);
	if (line)
		free (line);
	line = get_next_line(fd);
	printf("%s\n", line);
	if (line)
		free (line);
	system("leaks -q a.out");
}