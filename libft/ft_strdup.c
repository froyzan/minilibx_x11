#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	if (!(d = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (s[j] != '\0')
	{
		d[j] = s[j];
		j++;
	}
	d[j] = '\0';
	return (d);
}
