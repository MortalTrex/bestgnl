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

static char	*ft_createtmp(int fd, char *tmp, t_data data)
{
	int		cursor;
	char	*new_tmp;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * data.buffer_size + 1);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	cursor = read(fd, buffer, data.buffer_size);
	if (cursor <= 0)
	{
		if (cursor == 0 && tmp != NULL && *tmp != '\0')
			return (free(buffer), tmp);
		return (free(tmp), free(buffer), NULL);
	}
	buffer[cursor] = '\0';
	new_tmp = ft_strjoin(tmp, buffer);
	if (!new_tmp)
		return (free(tmp), free(buffer), NULL);
	free(buffer);
	if (ft_strchr(new_tmp, '\n'))
		return (new_tmp);
	return (ft_createtmp(fd, new_tmp, data));
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
	t_data		data;
	static char	*tmp = NULL;
	char		*line;
	char		*new_tmp;

	data.buffer_size = BUFFER_SIZE;
	if (data.buffer_size >= 1000)
		data.buffer_size = 10;
	if (fd < 0 || data.buffer_size <= 0)
	{
		return (NULL);
	}
	tmp = ft_createtmp(fd, tmp, data);
	if (!tmp)
		return (NULL);
	line = ft_assembleline(tmp);
	new_tmp = strdup(tmp + ft_strlen(line));
	return (free(tmp), tmp = new_tmp, line);
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
