int	ft_atoi(const char *nptr)
{
	int	number;
	int	sign;
	int i;

	number = 0;
	sign = 1;
	i = 1;
	while (*nptr != '\0' && ((*nptr >= 9 && *nptr <= 13) || *nptr == 32))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr != '\0' && (*nptr >= '0' && *nptr <= '9'))
	{
		if (number != 0 && i++ > 10)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		number = number * 10 + (*nptr - 48);
		nptr++;
	}
	return (number * sign);
}
