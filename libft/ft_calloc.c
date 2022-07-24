/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 13:43:34 by psafflow          #+#    #+#             */
/*   Updated: 2020/05/17 22:02:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
