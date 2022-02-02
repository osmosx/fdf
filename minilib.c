/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:22:14 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/01 13:22:25 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error(char *error)
{
	perror(error);
	exit(0);
}

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

int	hex_to_dec(char *hex, long long decimal)
{
	long long	base;
	int			i;

	base = 1;
	i = ft_strlen(hex);
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			decimal += (hex[i] - 48) * base;
			base *= 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimal += (hex[i] - 55) * base;
			base *= 16;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			decimal += (hex[i] - 87) * base;
			base *= 16;
		}
		i--;
	}
	return (decimal);
}
