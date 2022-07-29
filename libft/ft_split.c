#include "libft.h"

static int	numstring(char const *str, char c)
{
	size_t nb;
	size_t i;
	size_t dlina;

	dlina = ft_strlen(str);
	i = 0;
	nb = 0;
	if (!str)
		return (0);
	while (i < dlina)
	{
		if (str[i] != c && str[i] != '\0')
		{
			while (str[i] != c && i < dlina)
				i++;
			nb++;
		}
		i++;
	}
	return (nb);
}

static int	numchar(char const *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**o4istka(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static char	**filling(char const *s, char **dst, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1);
		if (dst[j] == NULL)
			return (o4istka((char const **)dst, j));
		while (s[i] != '\0' && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = NULL;
	return (dst);
}

char		**ft_split(char const *s, char c)
{
	char	**dst;
	int		l;

	if (s == NULL)
		return (NULL);
	l = numstring(s, c);
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (dst == NULL)
		return (NULL);
	return (filling(s, dst, c, l));
}
