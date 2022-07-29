#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pdest;
	unsigned char		*psrc;

	i = 0;
	pdest = (unsigned char*)dest;
	psrc = (unsigned char*)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}
