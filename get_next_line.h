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
char *read_line(char *buffer);
int	ft_strlen (char *str);
char	*ft_strjoin (char *s1, char *s2);
bool ft_strchr (const char *str, int c);

#endif
