/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 19:54:37 by psafflow          #+#    #+#             */
/*   Updated: 2020/09/22 21:43:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		prepare_new_ray(t_params *p, t_frame *f, int x)
{
	ft_memset(f, 0, sizeof(t_frame));
	f->camerax = 2 * x / (double)p->w - 1;
	f->raydir.x = p->dir.x + p->plane.x * f->camerax;
	f->raydir.y = p->dir.y + p->plane.y * f->camerax;
	f->mapx = p->pos.x < 0 ? (-1) + (int)p->pos.x : (int)p->pos.x;
	f->mapy = p->pos.y < 0 ? (-1) + (int)p->pos.y : (int)p->pos.y;
	f->deltadistx = fabs(1 / f->raydir.x);
	f->deltadisty = fabs(1 / f->raydir.y);
	get_step_and_sidedist(p, f);
}

static void	get_next_square(t_params *params, t_frame *f)
{
	if (f->sidedistx < f->sidedisty)
	{
		f->sidedistx += f->deltadistx;
		f->mapx += f->stepx;
		f->side = 0;
	}
	else
	{
		f->sidedisty += f->deltadisty;
		f->mapy += f->stepy;
		f->side = 1;
	}
	if (((f->mapx < 0 && f->stepx < 0) || (f->mapy < 0 && f->stepy < 0) ||
		((f->mapx >= params->map.size.x) && f->stepx >= 0) ||
		((f->mapy >= params->map.size.y) && f->stepy >= 0)))
	{
		f->hit = 1;
	}
	else if (f->mapx >= 0 && f->mapy >= 0 && f->mapx < params->map.size.x &&
	f->mapy < params->map.size.y)
		f->raytex = params->map.tab[f->mapy][f->mapx];
}

void		perform_analysis(t_params *params, t_frame *f)
{
	while (f->hit == 0)
	{
		get_next_square(params, f);
		if (f->raytex != '0')
		{
			if (f->raytex == '1' || f->raytex == '2')
				f->hit = 1;
		}
	}
}

void		get_step_and_sidedist(t_params *params, t_frame *f)
{
	if (f->raydir.x < 0)
	{
		f->stepx = -1;
		f->sidedistx = (params->pos.x - f->mapx) * f->deltadistx;
	}
	else
	{
		f->stepx = 1;
		f->sidedistx = (f->mapx + 1.0 - params->pos.x) * f->deltadistx;
	}
	if (f->raydir.y < 0)
	{
		f->stepy = -1;
		f->sidedisty = (params->pos.y - f->mapy) * f->deltadisty;
	}
	else
	{
		f->stepy = 1;
		f->sidedisty = (f->mapy + 1.0 - params->pos.y) * f->deltadisty;
	}
}

void		get_wall_data(t_params *params, t_frame *f, int x)
{
	if (f->side == 0)
		f->perpwalldist = (f->mapx - params->pos.x +
			(1 - f->stepx) / 2) / f->raydir.x;
	else if (f->side == 1)
		f->perpwalldist = (f->mapy - params->pos.y +
			(1 - f->stepy) / 2) / f->raydir.y;
	params->zbuffer[x] = (double)f->perpwalldist;
	f->lineheight = (int)(params->h / f->perpwalldist);
	f->drawstart = (int)(-f->lineheight / 2 + params->h / 2);
	f->drawstart = f->drawstart < 0 ? 0 : f->drawstart;
	f->drawstart = (f->drawstart > params->h) ? params->h : f->drawstart;
	f->drawend = (f->lineheight / 2 + params->h / 2);
	f->drawend = (f->drawend > params->h) ? params->h : f->drawend;
	f->drawend = (f->drawend < 0) ? 0 : f->drawend;
	if (f->side == 0)
		f->wallx = params->pos.y + f->perpwalldist * f->raydir.y;
	else if (f->side <= 2)
		f->wallx = params->pos.x + f->perpwalldist * f->raydir.x;
	f->wallx -= (int)f->wallx;
}
