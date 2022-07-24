/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 13:27:36 by psafflow          #+#    #+#             */
/*   Updated: 2020/05/19 23:42:36 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_sttrcpy(char *dest, const char *src, size_t i, size_t n)
{
	unsigned int	c;

	c = 0;
	while (c < n)
	{
		dest[c] = src[i];
		i++;
		c++;
	}
	dest[n] = '\0';
	return (dest);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*stroka;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if ((stroka = ((char*)malloc(sizeof(char) * len + 1))))
	{
		stroka = ft_sttrcpy(stroka, s, start, len);
		return (stroka);
	}
	return (stroka);
}
