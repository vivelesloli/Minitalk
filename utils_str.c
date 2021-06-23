#include "../minitalk.h"

int	ft_strcat(char **str, char c)
{
	int		i;
	int		size;
	char	*new_str;

	size = ft_strlen(*str);
	i = 0;
	new_str = malloc(sizeof(char) * (size + 2));
	if (!new_str)
		return (0);
	while ((*str)[i])
	{
		new_str[i] = (*str)[i];
		i++;
	}
	new_str[i++] = c;
	new_str[i] = 0;
	if (*str)
		free(*str);
	*str = new_str;
	return (1);
}

int	join_str(char **str, char c)
{
	char	*new_str;

	if (!*str)
	{
		new_str = malloc(sizeof(char) * 2);
		if (!new_str)
			return (0);
		new_str[0] = c;
		new_str[1] = '\0';
		*str = new_str;
		return (1);
	}
	else
	{
		if (!ft_strcat(str, c))
			return (0);
		return (1);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
