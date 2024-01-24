#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_createtmp(int fd, char *buffer)
{
	char	*tmp;
	int		cursor;

	tmp = NULL;
	//ASSEMBLE LE BUFFER AU TEMPORAIRE
	while (ft_strchr(buffer, '\n') == false)
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
		buffer[cursor] == '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	printf("buffer actuel :%s", buffer);
	return (tmp);
}

char *ft_assembleline(char *tmp)
{
	char *line;
	int	i;
	//CALCUL DE LA TAILLE DE LINE
	while (tmp[i] != '\n' || tmp[i])
		i++;
	line = malloc (sizeof(char) * i + 1);
	//INSERE CHAQUE CARACTERE DANS LINE
	while (tmp[i] != '\n' || tmp[i])
	{
		tmp[i] = buffer[i];
		i++;
	}
	return(line);
}

char	*get_next_line(int fd)
{
	char				*tmp;
	static char		buffer[BUFFER_SIZE + 1];
	char				*line;
	
	tmp = ft_createtmp(fd, buffer);
	free(tmp);
	line = ft_assembleline(tmp);
	return (line);
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
