/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 19:54:37 by psafflow          #+#    #+#             */
/*   Updated: 2020/06/20 21:43:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		chr(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str[i] == c)
		return (i);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char		*str;
	char			buf[BUFFER_SIZE + 1];
	int				n_byt;
	char			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (!str && !(str = ft_calloc(1, sizeof(char *))))
		return (-1);
	while ((chr('\n', str)) < 0 && (n_byt = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n_byt] = '\0';
		str = strj(str, buf);
	}
	*line = subs(str, 0, strl(str, 1));
	if ((chr('\n', str)) < 0)
	{
		free(str);
		str = NULL;
		return (0);
	}
	tmp = str;
	str = subs(str, chr('\n', str) + 1, strl(str, 0));
	free(tmp);
	return (1);
}
