/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 13:43:34 by psafflow          #+#    #+#             */
/*   Updated: 2020/05/18 22:02:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	if (!(d = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (s[j] != '\0')
	{
		d[j] = s[j];
		j++;
	}
	d[j] = '\0';
	return (d);
}
