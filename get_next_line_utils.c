#include "get_next_line.h"

int	ft_strlen (char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin (char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc (sizeof (char) * (ft_strlen(s1) + ft_strlen(s2)));
	while(s1[j])
	{
		res[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while(s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
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
	printf("%s", ft_strchr("Salut", 'a'));
}
*/
