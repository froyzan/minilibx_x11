#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*massiv;

	i = 0;
	if (!(massiv = malloc(nmemb * size)))
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)massiv)[i] = 0;
		i++;
	}
	return (massiv);
}
