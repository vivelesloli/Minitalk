#include "minilibft.h"

static int	ft_sizeofint(int n)
{
	int				count;
	unsigned int	u_nb;

	u_nb = n;
	count = 0;
	if (n <= 0)
	{
		count++;
		u_nb = -n;
	}
	while (u_nb != 0)
	{
		u_nb = u_nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	u_nb;
	int				len_nb;

	u_nb = n;
	len_nb = ft_sizeofint(n);
	s = (char *)malloc(sizeof(char) * (len_nb + 1));
	if (s == NULL)
		return (NULL);
	if (n < 0)
		u_nb = -n;
	s[len_nb--] = '\0';
	while (len_nb >= 0)
	{
		s[len_nb] = u_nb % 10 + '0';
		u_nb = u_nb / 10;
		len_nb--;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}