#include "../../includes/cub3d.h"

void		get_sprite_dist(t_params *p)
{
	int		i;
	t_coord	delta;

	i = 0;
	while (i < p->map.n_sprite)
	{
		delta.x = p->pos.x - p->map.sprite[i].x;
		delta.y = p->pos.y - p->map.sprite[i].y;
		p->map.s_order[i] = i;
		p->map.s_dist[i] = sqrt(delta.x * delta.x + delta.y * delta.y);
		i++;
	}
}

static void	get_sprite_draw_limits(t_params *p, t_sprite *this)
{
	this->drawstartx = -this->spritewidth / 2 + this->spritescreenx;
	this->drawendx = this->spritewidth / 2 + this->spritescreenx;
	this->drawstarty = -this->spriteheight / 2 + p->h / 2;
	this->drawendy = this->spriteheight / 2 + p->h / 2;
	if (this->drawstartx < 0)
		this->drawstartx = 0;
	if (this->drawendx >= p->w)
		this->drawendx = p->w;
	if (this->drawstarty < 0)
		this->drawstarty = 0;
	if (this->drawendy >= p->h)
		this->drawendy = p->h;
}

void		get_sprite_pos(t_params *p)
{
	t_sprite	*this;
	double		invdet;
	int			i;

	i = 0;
	while (i < p->map.n_sprite)
	{
		this = &p->map.sprite[p->map.s_order[i]];
		if (p->map.s_dist[i] < p->shadedist * 50)
		{
			this->spritex = this->x - p->pos.x;
			this->spritey = this->y - p->pos.y;
			invdet = 1.0 / (p->plane.x * p->dir.y - p->dir.x * p->plane.y);
			this->transformx = invdet * (p->dir.y * this->spritex - p->dir.x *
				this->spritey);
			this->transformy = invdet * (-p->plane.y * this->spritex +
				p->plane.x * this->spritey);
			this->spritescreenx = (int)((p->w / 2) *
				(1 + this->transformx / this->transformy));
			this->spritewidth = abs((int)(p->h / (this->transformy)));
			this->spriteheight = abs((int)(p->h / (this->transformy)));
			get_sprite_draw_limits(p, this);
		}
		i++;
	}
}

void		draw_sprite(t_params *p, t_frame *f, int x)
{
	draw_sprite_bis(p, x);
	if (f->drawend < p->h)
		checkline_floor(p, x, f->drawend, p->h);
	if (f->drawstart > 0)
		checkline_ceil(p, x, 0, f->drawstart);
	draw_wall(p, x, f);
}

void		draw_sprite_bis(t_params *p, int x)
{
	t_spr_cast	s;
	int			i;

	i = 0;
	while (i < p->map.n_sprite)
	{
		s.curr = &p->map.sprite[p->map.s_order[i]];
		if (((s.dist = p->map.s_dist[i]) < p->shadedist * 50) &&
			(x >= s.curr->drawstartx && x < s.curr->drawendx) &&
			(s.curr->transformy > 0.03 && s.curr->transformy < p->zbuffer[x]))
		{
			s.img = &p->sprite;
			s.tex.x = (int)(256 * (x - (-s.curr->spritewidth / 2 +
			s.curr->spritescreenx)) * s.img->width / s.curr->spritewidth) / 256;
			put_sprite_to_img(p, &s, x, s.curr->drawstarty);
		}
		i++;
	}
}
