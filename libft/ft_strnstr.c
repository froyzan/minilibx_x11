#include "libft.h"

char	*ft_strnstr(const char *big, char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0' || little == NULL)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j])
			{
				if (!little[j + 1] && (i + j) < len)
				{
					return ((char *)big + i);
				}
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
