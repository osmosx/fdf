#include "fdf.h"

static size_t	ft_words_count(char const *s, char c)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] == c)
			continue ;
		words++;
		while (s[i] != c)
			if (s[i++] == '\0')
				return (words);
	}
	return (words);
}

static size_t	ft_words_len(const char *s, char sep)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != sep)
		i++;
	return (i);
}

static char	**free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free (arr);
	return (NULL);
}

static char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substr = (char *) malloc ((len + 1));
	if (substr == NULL)
		return (NULL);
	if (start >= ft_strlen (s))
	{
		substr[i] = '\0';
		return (substr);
	}
	while (len != 0 && s[start] != '\0')
	{
		substr[i++] = s[start++];
		len--;
	}
	substr[i] = '\0';
	return (substr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	arr = malloc((ft_words_count(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i++] == c)
			continue ;
		--i;
		arr[j] = ft_substr(s, i, ft_words_len(&s[i], c));
		if (arr[j++] == NULL)
			return (free_arr(arr));
		i += ft_words_len(&s[i], c);
	}
	arr[j] = 0;
	return (arr);
}

