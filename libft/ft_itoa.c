#include "libft.h"

static int	count_len(int nbr)
{
	int				count;
	unsigned int	number;

	count = 0;
	number = nbr;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		number *= -1;
		count++;
	}
	while (number)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				sign;
	unsigned int	unbr;

	sign = 0;
	unbr = n;
	len = count_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		sign = 1;
		str[0] = '-';
		unbr *= -1;
	}
	while (len >= (sign ? 1 : 0))
	{
		str[len--] = unbr % 10 + '0';
		unbr = unbr / 10;
	}
	return (str);
}
