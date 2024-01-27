#include "get_next_line.h"

char *ft_createtmp(int fd, char *buffer, char *tmp)
{
	int	cursor;
	//int	i = 0;

	cursor = read(fd, buffer, BUFFER_SIZE);
	buffer[cursor] = '\0';
	tmp = ft_strjoin(tmp, buffer);
	if (ft_strchr(tmp, '\n'))
		return (tmp);
	return ft_createtmp(fd, buffer, tmp);
	//if (!tmp)
		//return (NULL);
	//return (tmp);
}



char	*ft_assembleline(char *tmp)
{
	char	*line;
	int	i;

	i = 0;
	//CALCUL DE LA TAILLE DE LINE
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (tmp[i] == '\n')
		i++;
	//line = ft_substr(tmp, 0, i);
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	//INSERE CHAQUE CARACTERE DANS LINE
	i = 0;
	//int j = 0;
	while (tmp[i] != '\n' && tmp[i])
	//while(j <= i)
	{
		line[i] = tmp[i];
		//free(tmp[i]);
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}


char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char				*tmp;
	char				*line;
	
	tmp = ft_createtmp(fd, buffer, tmp);
	if (!tmp)
		return (NULL);
	//char *line = ft_extract_line(tmp);
	//printf("\nLE TMP VAUT : %s\n", tmp);
	line = ft_assembleline(tmp);
	tmp += ft_strlen(line);
	//free(tmp);
	return (line);
}

int main()
{
    int	fd = open("test.md", O_RDONLY); 
    char *res;
  	int	i = 0;

    while (i < 40)
    {
			res = get_next_line(fd);
			//printf("La ligne %d est: %s", i, res);
			printf("%s", res);
			free(res);
			i++;
    }
    close(fd);
}
