/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:27:36 by psafflow          #+#    #+#             */
/*   Updated: 2020/02/22 17:44:36 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_dlina(char const *s1, char const *s2)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (s1 != NULL)
	{
		while (s1[a] != '\0')
			a++;
	}
	if (s2 != NULL)
	{
		while (s2[b] != '\0')
			b++;
	}
	return (a + b);
}

static void		ft_vstavka(char const *s1, char const *s2, char *stroka)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
			stroka[j++] = s1[i++];
	}
	if (s2 != NULL)
	{
		i = 0;
		while (s2[i] != '\0')
			stroka[j++] = s2[i++];
	}
	stroka[j] = '\0';
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*stroka;

	stroka = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 != NULL || s2 != NULL)
	{
		if (!(stroka = (char*)malloc(sizeof(char) * (ft_dlina(s1, s2)) + 1)))
			return (NULL);
		ft_vstavka(s1, s2, stroka);
	}
	return (stroka);
}
