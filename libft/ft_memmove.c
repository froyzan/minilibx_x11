#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	pdest = (unsigned char*)dest;
	psrc = (unsigned char*)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (psrc > pdest)
	{
		while (n--)
			*pdest++ = *psrc++;
	}
	else
	{
		while (n--)
			pdest[n] = psrc[n];
	}
	return (dest);
}
