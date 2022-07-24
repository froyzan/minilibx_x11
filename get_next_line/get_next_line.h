/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 20:03:43 by psafflow          #+#    #+#             */
/*   Updated: 2020/06/20 21:43:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	strl(char *s, int gnl);
int		chr(char c, char *str);
char	*strj(char *s1, char *s2);
char	*subs(char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		get_next_line(int fd, char **line);

#endif
