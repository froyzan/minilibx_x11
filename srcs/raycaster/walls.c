/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 19:54:37 by psafflow          #+#    #+#             */
/*   Updated: 2020/09/22 21:43:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_image	*get_wall_tex(t_params *params, t_frame *f)
{
	if (f->raytex == '1')
	{
		if (f->side == 0 && f->raydir.x < 0)
			return (&params->west);
		else if (f->side == 0)
			return (&params->east);
		if (f->side == 1 && f->raydir.y < 0)
			return (&params->north);
		else
			return (&params->south);
	}
	else
	{
		return (&params->walltex);
	}
}

void			get_wall_values(t_wall *w, t_image *img, t_frame *f,
				t_params *params)
{
	w->step = 1.0 * img->width / f->lineheight;
	w->texpos = (f->drawstart - params->h / 2 + f->lineheight / 2) * w->step;
	w->tex_x = (int)(f->wallx * (double)img->width);
	if (f->side == 0 && f->raydir.x > 0)
		w->tex_x = img->width - w->tex_x - 1;
	if (f->side == 1 && f->raydir.y < 0)
		w->tex_x = img->width - w->tex_x - 1;
}

void			draw_wall(t_params *params, int x, t_frame *f)
{
	t_image	*img;
	t_wall	w;

	img = get_wall_tex(params, f);
	get_wall_values(&w, img, f, params);
	while (f->drawstart <= f->drawend)
	{
		if (ft_bufferstate(params, x, f->drawstart))
		{
			w.texpos += w.step;
			f->drawstart++;
			continue;
		}
		w.tex_y = (int)w.texpos;
		w.color = getwallpixelcolor(params, img, f, &w);
		w.texpos += w.step;
		my_mlx_pixel_put(&params->img, x, f->drawstart++, w.color);
	}
}
