#include "fdf.h"

void	ft_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free (arr);
}

