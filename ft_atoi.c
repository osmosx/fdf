#include "fdf.h"

void	ft_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free (arr);
}

void	ft_bzero(void *str, size_t n)
{
	char	*tmp;
	size_t	i;

	if (!n)
		return ;
	tmp = str;
	i = 0;
	while (i < n)
		*(tmp + i++) = 0;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	negativ;
	int	number;

	negativ = 1;
	number = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') || (str[i]
			== '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str [i] == '-')
			negativ = -negativ;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10;
		number = number + (str[i] - '0');
		i++;
	}
	return (number * negativ);
}

