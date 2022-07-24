/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 20:31:34 by psafflow          #+#    #+#             */
/*   Updated: 2020/05/14 18:09:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	dlina;
	char	*newstring;

	dlina = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	dlina = ft_strlen(s1);
	while (dlina && ft_strchr(set, s1[dlina]))
		dlina--;
	newstring = ft_substr((char*)s1, 0, dlina + 1);
	return (newstring);
}
