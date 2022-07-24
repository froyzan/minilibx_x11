/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 13:43:34 by psafflow          #+#    #+#             */
/*   Updated: 2020/05/28 21:43:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
