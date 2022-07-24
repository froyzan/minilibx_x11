/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 19:54:37 by psafflow          #+#    #+#             */
/*   Updated: 2020/09/22 21:43:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		fix_map(char **a, t_icoord size, int i, int j)
{
	char	*tmp;

	while (i < size.y)
	{
		if ((int)ft_strlen(a[i]) != size.x)
		{
			if (!(tmp = malloc(sizeof(char *) * (size.x + 1))))
				return (parse_error("Map allocation error."));
			ft_memset(tmp, '0', size.x);
			ft_memcpy(tmp, a[i], ft_strlen(a[i]));
			free(a[i]);
			a[i] = tmp;
		}
		j = 0;
		while (j < size.x)
		{
			if (a[i][j] == ' ')
				a[i][j] = '0';
			j++;
		}
		i++;
	}
	return (1);
}

static int		duplicate_map(t_map *map, t_icoord size)
{
	int	i;

	map->tmp = map->tab;
	if (!(map->tab = malloc(sizeof(char *) * size.y)))
		return (parse_error("Map allocation error."));
	i = 0;
	while (i < size.y)
	{
		if (!(map->tab[i] = malloc(sizeof(char *) * (size.x + 1))))
		{
			while (--i >= 0)
				free(map->tab[i]);
			return (parse_error("Map allocation error."));
		}
		ft_memcpy(map->tab[i], map->tmp[i], size.x + 1);
		i++;
	}
	return (1);
}

static void		make_buffers(t_params *tmp)
{
	if (!(tmp->spritebuffer = malloc(tmp->w * tmp->h)))
		exit_msg(tmp, "Buffer allocation error.");
	ft_memset(tmp->spritebuffer, 0, (tmp->w * tmp->h));
	if (!(tmp->zbuffer = malloc(sizeof(double) * tmp->w)))
	{
		free(tmp->spritebuffer);
		exit_msg(tmp, "Buffer allocation error.");
	}
	ft_memset(tmp->zbuffer, 0, sizeof(double) * tmp->w);
	tmp->parser |= PARSER_BUF;
}

static void		init_game(t_params *params)
{
	params->mapwidth = &params->map.size.x;
	params->mapheight = &params->map.size.y;
	params->shadecol.r = 1.0;
	params->shadecol.g = 1.0;
	params->shadecol.b = 1.0;
	params->shadedist = 2;
	if (!(params->cosr) && !(params->sinr))
	{
		params->cosr = cos(0.01);
		params->cosmr = cos(-0.01);
		params->sinr = sin(0.01);
		params->sinmr = sin(-0.01);
	}
}

void			prepare_map(t_params *tmp)
{
	if (!(tmp->map.start.x) && !(tmp->map.start.y))
		exit_msg(tmp, "No player start point.");
	if (!(fix_map(tmp->map.tab, tmp->map.size, 0, 0)))
		exit_free(tmp, 1);
	duplicate_map(&tmp->map, tmp->map.size);
	flood_fill(tmp, tmp->map.start.x, tmp->map.start.y);
	free_tab(tmp->map.tmp, tmp->map.size.y);
	count_sprites(&tmp->map);
	if (!(build_sprite_tables(&tmp->map, tmp)))
		exit_free(tmp, 1);
	fill_sprite_table(&tmp->map);
	make_buffers(tmp);
	init_game(tmp);
	init_player(tmp);
}
