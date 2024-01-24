#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char *ft_createtmp(int	fd, char *buffer)
{
	char *tmp;
	int		cursor;
	int		i;

	cursor = read(fd, buffer, BUFFER_SIZE);

	while (buffer[i] != '\n')
	{
		tmp[i] = buffer[i];
		i++;
	}
	buffer[cursor] = '\0';
	return(tmp);
}

/*
char *ft_assembleline(char *tmp)
{
	return(line);
}
*/

char	*get_next_line(int fd)
{
	char				*tmp;
	//char				*line;
	static char	buffer[BUFFER_SIZE + 1];

	//cursor = read(fd, buffer, BUFFER_SIZE);
	tmp = ft_createtmp(fd, buffer);
	//buffer[cursor] = '\0';
	//free(tmp);
	//line = ft_assembleline(tmp);
	return (tmp);
}

int main()
{
    int fd;
    char *dest;
  	int	i = 0;

    fd = open("test.md", O_RDONLY); 
    dest = get_next_line(fd);
    while (i < 2)
    {
			printf("%s", dest);
			free(dest);
			dest = get_next_line(fd);
			i++;
    }
    close(fd);
    return 0;
}
