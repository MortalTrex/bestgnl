#include "get_next_line.h"

int	ft_strlen (char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
char	*ft_strjoin(char *s1, char *s2)
{
	char	*fusion;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	fusion = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!fusion)
		return (NULL);
	while (s1[++i])
		fusion[i] = s1[i];
	while (s2[++j])
		fusion[i + j] = s2[j];
	fusion[i + j] = 0;
	free(s1);
	return (fusion);
}
*/
char *ft_strjoin(char *s1, char *s2)
{
    char *fusion;
    int i;
    int j;

    i = -1;
    j = -1;
    if (!s1)
    {
        s1 = malloc(sizeof(char));
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }
    if (!s2)
        return (NULL);
    fusion = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!fusion)
        return (NULL);
    while (s1[++i])
        fusion[i] = s1[i];
    while (s2[++j])
        fusion[i + j] = s2[j];
    fusion[i + j] = '\0';
    return (fusion);
}

bool ft_strchr (const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return(false);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (true);
		i++;
	}
	return (false);
}

/*
int	main()
{
	printf("%s", ft_strjoin("Salut", "Ouioui"));
}
*/
