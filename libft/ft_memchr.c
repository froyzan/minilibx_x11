#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	symbol;

	i = 0;
	ptr = (unsigned char*)s;
	symbol = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == symbol)
		{
			return (((void*)s + i));
		}
		i++;
	}
	return (NULL);
}
