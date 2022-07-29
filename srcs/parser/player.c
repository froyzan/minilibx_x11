#include "../../includes/cub3d.h"

static void		set_player_dir(t_params *tmp, char c)
{
	if (c == 'N')
	{
		tmp->dir.y = -1;
		tmp->plane.x = (((double)tmp->w / (double)tmp->h) - 1.0);
	}
	else if (c == 'S')
	{
		tmp->dir.y = 1;
		tmp->plane.x = -(((double)tmp->w / (double)tmp->h) - 1.0);
	}
	else if (c == 'E')
	{
		tmp->dir.x = 1;
		tmp->plane.y = (((double)tmp->w / (double)tmp->h) - 1.0);
	}
	else if (c == 'W')
	{
		tmp->dir.x = -1;
		tmp->plane.y = -(((double)tmp->w / (double)tmp->h) - 1.0);
	}
	if (!(tmp->dir.x) && !(tmp->plane.x))
		tmp->plane.x = 0.5 * tmp->dir.y;
	if (!(tmp->dir.y) && !(tmp->plane.y))
		tmp->plane.y = 0.5 * tmp->dir.x;
}

void			init_player(t_params *tmp)
{
	char	c;

	c = tmp->map.tab[tmp->map.start.y][tmp->map.start.x];
	set_player_dir(tmp, c);
	if (tmp->plane.x > 0)
		tmp->plane.x = (tmp->plane.x < 0.5 ? 1 - tmp->plane.x : tmp->plane.x);
	if (tmp->plane.y > 0)
		tmp->plane.y = (tmp->plane.y < 0.5 ? 1 - tmp->plane.y : tmp->plane.y);
	tmp->map.tab[tmp->map.start.y][tmp->map.start.x] = '0';
	tmp->pos.x = 0.5 + tmp->map.start.x;
	tmp->pos.y = 0.5 + tmp->map.start.y;
	if (tmp->movespeed == 0)
		tmp->movespeed = 0.02;
}
