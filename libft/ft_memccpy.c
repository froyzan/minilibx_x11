/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 15:36:34 by psafflow          #+#    #+#             */
/*   Updated: 2020/05/14 18:09:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*pdest;
	unsigned char	*psrc;
	unsigned char	symbol;

	i = 0;
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	symbol = (unsigned char)c;
	while (i < n)
	{
		if ((pdest[i] = psrc[i]) == symbol)
		{
			return (dest + i + 1);
		}
		i++;
	}
	return (0);
}
