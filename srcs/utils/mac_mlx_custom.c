/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_mlx_custom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 19:54:37 by psafflow          #+#    #+#             */
/*   Updated: 2020/10/22 21:43:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		getcolor(t_color color)
{
	int result;

	result = (color.r << 16);
	result += (color.g << 8);
	result += color.b;
	return (result);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int		getpixelcolor(t_image *img, int x, int y)
{
	if (!img->width || !img->height)
		return (0);
	x = abs(x);
	y = abs(y);
	if (x > img->width || y > img->height || x < 0 || y < 0)
		return (0);
	return (*(int*)(img->addr + ((x + (y * img->width)) * (img->bpp / 8))));
}

int		getwallpixelcolor(t_params *p, t_image *img, t_frame *f, t_wall *w)
{
	int x;
	int y;

	if (!img->width || !img->height)
	{
		if (f->drawstart > (p->h / 2))
			return (getcolor(p->floor));
		else
			return (getcolor(p->ceil));
	}
	x = abs(w->tex_y);
	y = abs(w->tex_x);
	if (x > img->width || y > img->height || x < 0 || y < 0)
		return (0);
	return (*(int*)(img->addr + ((x + (y * img->width)) * (img->bpp / 8))));
}

void	put_sprite_to_img(t_params *p, t_spr_cast *s, int x, int y)
{
	int		col;
	int		d;
	char	*adr;

	while (y < s->curr->drawendy)
	{
		if (!(ft_bufferstate(p, x, y)))
		{
			d = y * 256 - p->h * 128 + s->curr->spriteheight * 128;
			s->tex.y = ((d * s->img->height) / s->curr->spriteheight) / 256;
			col = getpixelcolor(s->img, s->tex.y, s->tex.x);
			if (!(col == (int)0x00FF00))
			{
				my_mlx_pixel_put(&p->img, x, y, col);
				adr = p->spritebuffer + ((y * p->w + x));
				*(char*)adr = 1;
			}
		}
		y++;
	}
}
