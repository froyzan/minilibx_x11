/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:27:36 by psafflow          #+#    #+#             */
/*   Updated: 2020/05/14 20:14:43 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last_ptr;

	last_ptr = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			last_ptr = (char *)s;
		}
		s++;
	}
	if (last_ptr)
	{
		return (last_ptr);
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (0);
}
