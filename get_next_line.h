#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (1 * 1024 * 1024)
# endif

char *get_next_line(int fd);
int	ft_strlen (char *str);
bool ft_strchr (const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

char	*ft_assembleline(char *tmp);
char *ft_createtmp(int fd, static char *buffer, char *tmp);
void	clean_static(char *buffer);


#endif
