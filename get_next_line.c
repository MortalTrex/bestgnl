/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:21:42 by rbalazs           #+#    #+#             */
/*   Updated: 2024/01/29 18:53:54 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_createtmp(int fd, char *buffer, char *tmp)
{
	int		cursor;
	char	*new_tmp;

	cursor = read(fd, buffer, BUFFER_SIZE);
	if (cursor <= 0)
	{
		if (cursor == 0 && tmp != NULL && *tmp != '\0')
			return (tmp);
		return (free(tmp), NULL);
	}
	buffer[cursor] = '\0';
	new_tmp = ft_strjoin(tmp, buffer);
	if (!new_tmp)
		return (free(tmp), NULL);
	if (ft_ischr(new_tmp, '\n') == true)
		return (new_tmp);
	return (ft_createtmp(fd, buffer, new_tmp));
}

char	*ft_assembleline(char *tmp)
{
	char	*line;
	int		i;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*buffer;
	char		*line;
	char		*new_tmp;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	tmp = ft_createtmp(fd, buffer, tmp);
	free(buffer);
	if (!tmp)
		return (NULL);
	line = ft_assembleline(tmp);
	new_tmp = ft_strdup(tmp + ft_strlen(line));
	free(tmp);
	tmp = new_tmp;
	return (line);
}

/*
int main() 
{
    int fd = open("test.md", O_RDONLY);
    if (fd == -1) 
  	{
        perror("Error opening file");
        return 1;
    }
    char *line;
    int i = 0;
  	line = get_next_line(fd);
  	free(line);
  	while (line)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        printf("%s", line);
        free(line);
        i++;
    }
    close(fd);
    return 0;
}
*/
