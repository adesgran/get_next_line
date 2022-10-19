[![Linux](https://svgshare.com/i/Zhy.svg)](https://svgshare.com/i/Zhy.svg)

# get_next_line
> Project for 42 school

## Description
> C function wich read an open stream line by line

> get_next_line_bonus allow to read alternaly multiple files

## Uses
> main.c :
>```
> 1  #include <fcntl.h>
> 2  #include <unistd.h>
> 3  #include "get_next_line.h"
> 4
> 5  int main (void)
> 6  {
> 7  	int fd = open("MyFilename.txt");
> 8		char \*line;
> 9 	while (line = get_next_line(fd))
> 10	printf("%s\n", line);
> 11 	close(fd);
> 12 	return (1);
> 13 }
>```
