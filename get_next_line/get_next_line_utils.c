/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 19:58:14 by psafflow          #+#    #+#             */
/*   Updated: 2020/06/20 21:43:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strl(char *s, int gnl)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && gnl)
			return (i);
		i++;
	}
	return (i);
}

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

char	*strj(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (strl(s1, 0) + strl(s2, 0) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	str[i + j] = '\0';
	return (str);
}

char	*subs(char *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > strl(s, 0))
		return (NULL);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[start] && len)
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
